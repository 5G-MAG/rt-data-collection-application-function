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

#include "context.h"
#include "data-reporting-configuration.h"

#include "data-reporting-provisioning.h"

#ifdef __cplusplus
extern "C" {
#endif

/******* Local prototypes ********/

static int _add_session_to_list(void *data, const void *key, int klen, const void *value);
static int _free_ogs_hash_entry(void *free_fn, const void *key, int klen, const void *value);

/******* Private structures ********/

typedef struct data_collection_reporting_provisioning_session_s {
    char *session_id;
    ogs_hash_t *configurations;
} data_collection_reporting_provisioning_session_t;

/******* Library API ********/

/** Create a new data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
data_collection_reporting_provisioning_session_create(/* TBD */)
{
    /* TODO: implement this */
    return NULL;
}

/** Destroy a data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_provisioning_session_destroy(
        data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return;

    ogs_hash_set(data_collection_self()->data_reporting_provisioning_sessions, session->session_id, OGS_HASH_KEY_STRING, NULL);

    if (session->session_id) {
        ogs_free(session->session_id);
        session->session_id = NULL;
    }

    if (session->configurations) {
        ogs_hash_do(_free_ogs_hash_entry, (void*)data_collection_reporting_configuration_destroy, session->configurations);
        ogs_hash_destroy(session->configurations);
        session->configurations = NULL;
    }

    ogs_free(session);
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
    return session->session_id;
}

/** Get the TS 26.532 DataReportingProvisioningSession JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_provisioning_session_json(
        const data_collection_reporting_provisioning_session_t *session)
{
    /* TODO: implement this */
    return NULL;
}

/** List the active Data Reporting Provisioning Sessions */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_provisioning_session_list()
{
    ogs_list_t *ret;

    ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ogs_hash_do(_add_session_to_list, ret, data_collection_self()->data_reporting_provisioning_sessions);

    return ret;
}

/******* Library internal functions ********/

/** Add a reporting configuration to the session */
int data_collection_reporting_provisioning_session_add_configuration(data_collection_reporting_provisioning_session_t *session,
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

    return OGS_OK;
}

/** Remove a reporting configuration to the session */
int data_collection_reporting_provisioning_session_remove_configuration(data_collection_reporting_provisioning_session_t *session,
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

    ogs_hash_set(session->configurations, config_id, OGS_HASH_KEY_STRING, NULL);

    return OGS_OK;
}

/** Get a reporting configuration by its id from the session */
data_collection_reporting_configuration_t *
data_collection_reporting_provisioning_session_get_configuration_by_id(data_collection_reporting_provisioning_session_t *session,
                                                                       const char *configuration_id)
{
    if (!session || !session->configurations) return NULL; // no session or session being deleted
    if (!configuration_id) return NULL; // must have an id to look up

    return ogs_hash_get(session->configurations, configuration_id, OGS_HASH_KEY_STRING);
}

/******* Local private functions ********/

static int _add_session_to_list(void *data, const void *key, int klen, const void *value)
{
    ogs_list_t *list = (ogs_list_t*)data;
    data_collection_reporting_session_lnode_t *node;

    node = ogs_calloc(1, sizeof(*node));
    ogs_assert(node);

    node->provisioning_session = (data_collection_reporting_provisioning_session_t*)value;
    ogs_list_add(list, node);

    return 1;
}

static int _free_ogs_hash_entry(void *free_fn, const void *key, int klen, const void *value)
{
    void (*value_free_fn)(void *) = (void(*)(void*))free_fn;
    value_free_fn((void*)value);

    return 1;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
