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

#include "openapi/model/dc_api_data_reporting_provisioning_session.h"
#include "openapi/model/dc_api_data_reporting_configuration.h"

#include "context.h"
#include "hash.h"
#include "utilities.h"
#include "data-reporting-configuration.h"

#include "data-reporting-provisioning.h"

#ifdef __cplusplus
extern "C" {
#endif

/******* Local prototypes ********/

static int _add_session_to_list(void *data, const void *key, int klen, const void *value);
static int _add_config_id_to_openapi_list(void *data, const void *key, int klen, const void *value);
static int _free_ogs_hash_entry(void *free_fn, const void *key, int klen, const void *value);
static void _restamp_session(data_collection_reporting_provisioning_session_t *session);

/******* Private structures ********/

typedef struct data_collection_reporting_provisioning_session_s {
    char *session_id;
    char *asp_id;
    char *external_application_id;
    char *internal_application_id;
    char *af_event_type;
    ogs_hash_t *configurations;
    ogs_time_t last_modified;
    char *etag;
} data_collection_reporting_provisioning_session_t;

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

    session->session_id = data_collection_strdup(id);
    if (asp_id) session->asp_id = data_collection_strdup(asp_id);
    if (external_application_id) session->external_application_id = data_collection_strdup(external_application_id);
    if (internal_application_id) session->internal_application_id = data_collection_strdup(internal_application_id);
    if (event_type) session->af_event_type = data_collection_strdup(event_type);
    session->configurations = ogs_hash_make();

    _restamp_session(session);

    ogs_hash_set(data_collection_self()->data_reporting_provisioning_sessions, session->session_id, OGS_HASH_KEY_STRING, session);

    return session;
}

/** Create a new data reporting provisioning session from JSON tree */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
data_collection_reporting_provisioning_session_parse_from_json(cJSON *json, const char **error_reason, const char **error_parameter)
{
    data_collection_reporting_provisioning_session_t *session;
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];

    /* Try to interpret JSON */
    dc_api_data_reporting_provisioning_session_t *oa_session = dc_api_data_reporting_provisioning_session_parseRequestFromJSON(
                                                                            json, error_reason);
    if (!oa_session) {
        if (error_parameter) *error_parameter = NULL; /* Until templates get "error_parameter" just NULL this */
        return NULL;
    }

    session = ogs_calloc(1, sizeof(*session));
    ogs_assert(session);

    session->asp_id = data_collection_strdup(oa_session->asp_id);
    session->external_application_id = data_collection_strdup(oa_session->external_application_id);
    session->internal_application_id = data_collection_strdup(oa_session->internal_application_id);

    /* Until templates can take general enum strings */
    cJSON *event_id_node = cJSON_GetObjectItemCaseSensitive(json, "eventId");
    if (event_id_node) {
        if (!cJSON_IsString(event_id_node)) {
            if (error_reason) *error_reason = "Field \"eventId\" is not an enumeration string";
            if (error_parameter) *error_parameter = "eventId";
            goto err;
        }
        session->af_event_type = data_collection_strdup(event_id_node->valuestring);
    }

    dc_api_data_reporting_provisioning_session_free(oa_session);

    /* Initialise read-only parts */
    session->configurations = ogs_hash_make();

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    session->session_id = ogs_strdup(id);

    _restamp_session(session);

    ogs_hash_set(data_collection_self()->data_reporting_provisioning_sessions, session->session_id, OGS_HASH_KEY_STRING, session);

    return session;

err:
    if (oa_session) dc_api_data_reporting_provisioning_session_free(oa_session);
    if (session) {
        if (session->asp_id) ogs_free(session->asp_id);
        if (session->external_application_id) ogs_free(session->external_application_id);
        if (session->internal_application_id) ogs_free(session->internal_application_id);
        if (session->af_event_type) ogs_free(session->af_event_type);
        if (session->configurations) ogs_hash_destroy(session->configurations);
        ogs_free(session);
    }
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

    if (session->asp_id) {
        ogs_free(session->asp_id);
        session->asp_id = NULL;
    }

    if (session->external_application_id) {
        ogs_free(session->external_application_id);
        session->external_application_id = NULL;
    }

    if (session->internal_application_id) {
        ogs_free(session->internal_application_id);
        session->internal_application_id = NULL;
    }

    if (session->af_event_type) {
        ogs_free(session->af_event_type);
        session->af_event_type = NULL;
    }

    if (session->configurations) {
        ogs_hash_do(_free_ogs_hash_entry, (void*)data_collection_reporting_configuration_destroy, session->configurations);
        ogs_hash_destroy(session->configurations);
        session->configurations = NULL;
    }

    if (session->etag) {
        ogs_free(session->etag);
        session->etag = NULL;
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


/** Get the external application id associated with the provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_external_application_id(
        const data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return NULL;
    return session->external_application_id;
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
    cJSON *json = NULL;
    OpenAPI_list_t *config_ids = NULL;

    if (session->configurations && ogs_hash_first(session->configurations) != NULL) {
        config_ids = OpenAPI_list_create();
        ogs_hash_do(_add_config_id_to_openapi_list, config_ids, session->configurations);
    }

    dc_api_data_reporting_provisioning_session_t *drps = dc_api_data_reporting_provisioning_session_create(
                session->asp_id, config_ids, dc_api_af_event_FromString(session->af_event_type), session->external_application_id,
                session->internal_application_id, session->session_id);

    json = dc_api_data_reporting_provisioning_session_convertResponseToJSON(drps);

    OpenAPI_clear_and_free_string_list(config_ids);
    ogs_free(drps);

    return json;
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

    _restamp_session(session);

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

    _restamp_session(session);

    return OGS_OK;
}

/** Replace a reporting configuration to the session */
int data_collection_reporting_provisioning_session_replace_configuration(data_collection_reporting_provisioning_session_t *session,
                                                                         data_collection_reporting_configuration_t *configuration)
{
    if (!session || !session->configurations) return OGS_ERROR; // no configuration to replace
    if (!configuration) return OGS_ERROR; // Configuration cannot be NULL

    const char *config_id = data_collection_reporting_configuration_id(configuration);
    data_collection_reporting_configuration_t *existing = ogs_hash_get(session->configurations, config_id, OGS_HASH_KEY_STRING);
    if (existing != configuration) {
        // only replace if different
        ogs_hash_set(session->configurations, config_id, OGS_HASH_KEY_STRING, configuration);
        if (existing) {
            // Destroy old config
            reporting_configuration_detach_session(existing);
            data_collection_reporting_configuration_destroy(existing);
        }
    }

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

char *data_collection_reporting_provisioning_session_get_af_event_type(data_collection_reporting_provisioning_session_t *session) {

    if(!session) return NULL;
    return session->af_event_type; 
}

char *data_collection_reporting_provisioning_session_get_external_application_id(data_collection_reporting_provisioning_session_t *session) {

    if(!session) return NULL;
    return session->external_application_id; 
}

ogs_hash_t *data_collection_reporting_provisioning_session_get_configurations(data_collection_reporting_provisioning_session_t *session) {

    if(!session || !session->configurations) return NULL;
    return session->configurations; 
}



#if 0
OpenAPI_list_t *data_collection_get_user_ids_from_reporting_provisioning_session(char *event_type, char *external_application_id, OpenAPI_list_t *user_identifiers) {

    ogs_hash_index_t *it;
    ogs_hash_t *data_reporting_provisioning_session = data_collection_self()->data_reporting_provisioning_sessions; 
    data_collection_reporting_provisioning_session_t *session;
    for (it = ogs_hash_first(data_reporting_provisioning_session); it; it = ogs_hash_next(it)) {
        const char *key;
        int key_len;

	ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&session));

        if(!strcmp(session->af_event_type, event_type) && !strcmp(session->external_application_id, external_application_id)) {
	    
            ogs_hash_index_t *hit;
	    ogs_hash_t *configurations = session->configurations;
	    data_collection_reporting_configuration_t *configuration;

            for (hit = ogs_hash_first(configurations); hit; hit = ogs_hash_next(hit)) {
                const char *ckey;
                int ckey_len;

	        ogs_hash_this(it, (const void **)&ckey, &ckey_len, (void**)(&configuration));
		if (configuration->configuration && configuration->configuration->data_access_profiles) {
		    OpenAPI_list_t *data_access_profiles = configuration->configuration->data_access_profiles;
		    OpenAPI_lnode_t *data_access_profile_node = NULL;
		    dc_api_data_access_profile_t *data_access_profile;
		    dc_api_data_access_profile_user_access_restrictions_t *user_access_restrictions;
		    OpenAPI_list_for_each(data_access_profiles, data_access_profile_node) {
			dc_api_data_access_profile_user_access_restrictions_t *user_access_restrictions;
		        OpenAPI_list_t *user_ids;
		        OpenAPI_lnode_t *user_id_node = NULL;
	
	                data_access_profile = (dc_api_data_access_profile_t *) data_access_profile_node->data;
			if(data_access_profile->user_access_restrictions && data_access_profile->user_access_restrictions->user_ids) {
                            OpenAPI_list_for_each(user_ids, user_id_node) {
			        OpenAPI_list_add(user_identifiers, user_id_node);
			    }			    
			}
    			//user_access_restrictions = data_access_profile->user_access_restrictions;			
		    }

		}
	    }

	}
    }
    return user_identifiers;
}
#endif

/******* Local private functions ********/

static int _add_session_to_list(void *data, const void *key, int klen, const void *value)
{
    ogs_list_t *list = (ogs_list_t*)data;
    data_collection_reporting_provisioning_session_t *node;

    node = ogs_malloc(sizeof(*node));
    ogs_assert(node);

    memcpy(node, value, sizeof(*node));
    ogs_list_add(list, node);

    return 1;
}

static int _add_config_id_to_openapi_list(void *data, const void *key, int klen, const void *value)
{
    OpenAPI_list_t *list = (OpenAPI_list_t*)data;

    OpenAPI_list_add(list, ogs_strdup(key));

    return 1;
}

static int _free_ogs_hash_entry(void *free_fn, const void *key, int klen, const void *value)
{
    void (*value_free_fn)(void *) = (void(*)(void*))free_fn;
    value_free_fn((void*)value);

    return 1;
}

static void _restamp_session(data_collection_reporting_provisioning_session_t *session)
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

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
