/*
 * License: 5G-MAG Public License (v1.0)
 * Author: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "ogs-core.h"

#include "data-collection-sp/data-collection.h"

#include "context.h"
#include "hash.h"
#include "utilities.h"

#include "data-reporting.h"
#include "data-reporting-provisioning.h"

#ifdef __cplusplus
extern "C" {
#endif

/******* Local prototypes ********/

static int __add_session_to_list(void *data, const void *key, int klen, const void *value);
static void __restamp_session(data_collection_reporting_provisioning_session_t *session);
static void __reporting_provisioning_session_free(data_collection_reporting_provisioning_session_t *session);

/******* Private structures ********/

typedef struct data_collection_reporting_provisioning_session_s {
    ogs_lnode_t node; // Allow these to be listed in an ogs_list_t
    data_collection_model_data_reporting_provisioning_session_t *session;
    ogs_hash_t *configurations; // configurationId => data_collection_reporting_configuration_t
    ogs_time_t last_modified;
    char *etag;
} data_collection_reporting_provisioning_session_t;

typedef struct _free_ogs_hash_config_s {
    ogs_hash_t *hash;
    void (*free_fn)(void*);
} _free_ogs_hash_config_t;

/******* Library API ********/

/** Create a new data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
data_collection_reporting_provisioning_session_create(const char *asp_id, const char *external_application_id, const char *internal_application_id, const char *event_type)
{
    data_collection_reporting_provisioning_session_t *session = ogs_calloc(1, sizeof(*session));
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];

    ogs_assert(session);

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    session->session = data_collection_model_data_reporting_provisioning_session_create();
    data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id(session->session, id);
    if (asp_id)
        data_collection_model_data_reporting_provisioning_session_set_asp_id(session->session, asp_id);
    if (external_application_id)
        data_collection_model_data_reporting_provisioning_session_set_external_application_id(session->session, external_application_id);
    if (internal_application_id)
        data_collection_model_data_reporting_provisioning_session_set_internal_application_id(session->session, internal_application_id);
    if (event_type) {
        data_collection_model_af_event_t *evt_type = data_collection_model_af_event_create();
        data_collection_model_af_event_set_string(evt_type, event_type);
        data_collection_model_data_reporting_provisioning_session_set_event_id_move(session->session, evt_type);
    }

    __restamp_session(session);

    ogs_hash_set(data_collection_self()->data_reporting_provisioning_sessions,
                data_collection_model_data_reporting_provisioning_session_get_provisioning_session_id(session->session),
                OGS_HASH_KEY_STRING, session);

    return session;
}

/** Create a new data reporting provisioning session from JSON tree */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
data_collection_reporting_provisioning_session_parse_from_json(cJSON *json, const char **error_reason, const char **error_parameter)
{
    data_collection_reporting_provisioning_session_t *session = NULL;
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];
    char *error_classname;

    /* Try to interpret JSON */
    data_collection_model_data_reporting_provisioning_session_t *oa_session = data_collection_model_data_reporting_provisioning_session_fromJSON(json, true, (char**)error_reason, &error_classname, (char**)error_parameter);
    if (!oa_session) {
        if (error_parameter) *error_parameter = NULL; /* Until templates get "error_parameter" just NULL this */
        goto err;
    }

    session = ogs_calloc(1, sizeof(*session));
    ogs_assert(session);

    session->session = oa_session;
    oa_session = NULL;

    /* Initialise read-only parts */
    session->configurations = ogs_hash_make();

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id(session->session, id);

    __restamp_session(session);

    ogs_hash_set(data_collection_self()->data_reporting_provisioning_sessions,
                data_collection_model_data_reporting_provisioning_session_get_provisioning_session_id(session->session),
                OGS_HASH_KEY_STRING, session);

    return session;

err:
    if (oa_session) data_collection_model_data_reporting_provisioning_session_free(oa_session);
    if (session) {
        __reporting_provisioning_session_free(session);
    }
    return NULL;
}

/** Destroy a data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_provisioning_session_destroy(
        data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return;

    ogs_hash_set(data_collection_self()->data_reporting_provisioning_sessions,
                data_collection_model_data_reporting_provisioning_session_get_provisioning_session_id(session->session),
                OGS_HASH_KEY_STRING, NULL);

    __reporting_provisioning_session_free(session);
}

/** Finding a Data Reporting Provisioning Session by Id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t *
data_collection_reporting_provisioning_session_find(const char *session_id)
{
    return ogs_hash_get(data_collection_self()->data_reporting_provisioning_sessions, session_id, OGS_HASH_KEY_STRING);
}

/** Get the Data Reporting Provisioning Session Id */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_id(
        const data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return NULL;
    return data_collection_model_data_reporting_provisioning_session_get_provisioning_session_id(session->session);
}


/** Get the external application id associated with the provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_external_application_id(
        const data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return NULL;
    return data_collection_model_data_reporting_provisioning_session_get_external_application_id(session->session);
}


/** Get the Data Reporting Provisioning Session last modified date-time */
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t
data_collection_reporting_provisioning_session_last_modified(const data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return 0;
    return session->last_modified;
}

/** Get the Data Reporting Provisioning Session entity instance tag */
DATA_COLLECTION_SVC_PRODUCER_API const char *
data_collection_reporting_provisioning_session_etag(const data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return NULL;
    return session->etag;
}

/** Get the TS 26.532 DataReportingProvisioningSession JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_provisioning_session_json(
        const data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return NULL;
    return data_collection_model_data_reporting_provisioning_session_toJSON(session->session, false);
}

/** List the active Data Reporting Provisioning Sessions */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_provisioning_session_list()
{
    ogs_list_t *ret;

    ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ogs_hash_do(__add_session_to_list, ret, data_collection_self()->data_reporting_provisioning_sessions);

    return ret;
}

/** Add a reporting configuration to the session */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_add_configuration(
                                                    data_collection_reporting_provisioning_session_t *session,
                                                    data_collection_reporting_configuration_t *configuration)
{
    if (!session) {
        ogs_error("data_collection_reporting_provisioning_session_add_configuration: passed NULL session");
        return OGS_ERROR;
    }

    if (!session->configurations) {
        ogs_error("data_collection_reporting_provisioning_session_add_configuration: session not initialised or being deleted");
        return OGS_ERROR;
    }

    if (!configuration) {
        ogs_error("data_collection_reporting_provisioning_session_add_configuration: passed NULL configuration");
        return OGS_ERROR;
    }

    const char *config_id = data_collection_reporting_configuration_id(configuration);
    if (ogs_hash_get(session->configurations, config_id, OGS_HASH_KEY_STRING)) {
        ogs_error("data_collection_reporting_provisioning_session_add_configuration: configuration %s already added", config_id);
        return OGS_ERROR;
    }

    ogs_hash_set(session->configurations, config_id, OGS_HASH_KEY_STRING, configuration);
    data_collection_model_data_reporting_provisioning_session_add_data_reporting_configuration_ids(session->session, data_collection_strdup(config_id));
    ogs_hash_set(data_collection_self()->data_reporting_configuration_contexts, config_id, OGS_HASH_KEY_STRING, configuration);

    __restamp_session(session);

    return OGS_OK;
}

/** Remove a reporting configuration to the session */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_remove_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration)
{
    if (!session || !session->configurations) return OGS_OK; // nothing to delete the configuration from
    if (!configuration) return OGS_ERROR; // Configuration cannot be NULL

    const char *config_id = data_collection_reporting_configuration_id(configuration);
    data_collection_reporting_configuration_t *existing = ogs_hash_get(session->configurations, config_id, OGS_HASH_KEY_STRING);

    if (!existing) return OGS_OK; // no configuration with that ID so no need to delete

    if (existing != configuration) {
        ogs_error("data_collection_reporting_provisioning_session_remove_configuration: attempt to remove wrong configuration object");
        return OGS_ERROR;
    }

    data_collection_model_data_reporting_provisioning_session_remove_data_reporting_configuration_ids(session->session, config_id);
    ogs_hash_set(session->configurations, config_id, OGS_HASH_KEY_STRING, NULL);
    ogs_hash_set(data_collection_self()->data_reporting_configuration_contexts, config_id, OGS_HASH_KEY_STRING, NULL);

    __restamp_session(session);

    return OGS_OK;
}

/** Replace a reporting configuration to the session */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_replace_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration)
{
    if (!session || !session->configurations) return OGS_ERROR; // no configuration to replace
    if (!configuration) return OGS_ERROR; // Configuration cannot be NULL

    const char *config_id = data_collection_reporting_configuration_id(configuration);
    data_collection_reporting_configuration_t *existing = ogs_hash_get(session->configurations, config_id, OGS_HASH_KEY_STRING);
    if (existing != configuration) {
        data_collection_reporting_configuration_update(existing, configuration);
    }

    return OGS_OK;
}

/** Find a reporting configuration in the session by its id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_provisioning_session_get_configuration_by_id(data_collection_reporting_provisioning_session_t *session,
                                                                       const char *configuration_id)
{
    if (!session || !session->configurations) return NULL; // no session or session being deleted
    if (!configuration_id) return NULL; // must have an id to look up

    return ogs_hash_get(session->configurations, configuration_id, OGS_HASH_KEY_STRING);
}

/** Get the AfEvent type for a provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const char *
data_collection_reporting_provisioning_session_get_af_event_type(const data_collection_reporting_provisioning_session_t *session)
{

    if(!session) return NULL;
    return data_collection_model_af_event_get_string(
                data_collection_model_data_reporting_provisioning_session_get_event_id(session->session));
}

/** Get the external app id for a provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const char *
data_collection_reporting_provisioning_session_get_external_application_id(
                const data_collection_reporting_provisioning_session_t *session)
{

    if(!session) return NULL;
    return data_collection_model_data_reporting_provisioning_session_get_external_application_id(session->session);
}

/** Get the DataReportingConfiguration map for a provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const ogs_hash_t *
data_collection_reporting_provisioning_session_get_configurations(const data_collection_reporting_provisioning_session_t *session)
{

    if(!session || !session->configurations) return NULL;
    return session->configurations; 
}

/******* Library internal functions ********/

/******* Local private functions ********/

static int __add_session_to_list(void *data, const void *key, int klen, const void *value)
{
    ogs_list_t *list = (ogs_list_t*)data;
    /* add value without free function, this list does not own its objects */
    data_collection_lnode_t *node = data_collection_lnode_create_ref(value);
    ogs_list_add((ogs_list_t*)list, node);

    return 1;
}

static void __restamp_session(data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return;

    session->last_modified = ogs_time_now();

    if (session->etag) ogs_free(session->etag);
    cJSON *json = data_collection_reporting_provisioning_session_json(session);
    if (json) {
        char *objstr = cJSON_Print(json);
        if (objstr) {
            session->etag = calculate_hash(objstr);
            cJSON_free(objstr);
        } else {
            session->etag = NULL;
        }
    } else {
        session->etag = NULL;
    }
}

static void __reporting_provisioning_session_free(data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return;

    if (session->session) {
        data_collection_model_data_reporting_provisioning_session_free(session->session);
        session->session = NULL;
    }

    if (session->configurations) {
        data_collection_hash_free(session->configurations, (void(*)(void*))data_collection_reporting_configuration_destroy);
        session->configurations = NULL;
    }

    if (session->etag) {
        ogs_free(session->etag);
        session->etag = NULL;
    }

    ogs_free(session);
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
