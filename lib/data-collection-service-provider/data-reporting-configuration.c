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

#include "openapi/model/dc_api_data_reporting_configuration.h"

#include "context.h"
#include "data-reporting-provisioning.h"
#include "data-sampling-rule-internal.h"
#include "data-reporting-rule-internal.h"
#include "data-reporting-condition-internal.h"
#include "data-access-profile-internal.h"
#include "hash.h"
#include "utilities.h"
#include "ref-count.h"
#include "wrap-openapi-macros.h"

#include "data-reporting-configuration.h"

#ifdef __cplusplus
extern "C" {
#endif

/******* Local macros ********/

/******* Local prototypes ********/

_DC_REFLNODE_TYPE(data_sampling_rule);
_DC_REFLNODE_TYPE(data_reporting_rule);
_DC_REFLNODE_TYPE(data_reporting_condition);
_DC_REFLNODE_TYPE(data_access_profile);

static void __restamp_configuration(data_collection_reporting_configuration_t *configuration);

/******* Private structures ********/

typedef struct data_collection_reporting_configuration_s {
    ogs_lnode_t                                       node;
    data_collection_reporting_provisioning_session_t *parent;
    ogs_time_t                                        last_modified;
    char                                             *etag;
    dc_api_data_reporting_configuration_t            *configuration;
    /* register of imported openapi object references (to track configuration sub-objects deletion) */
    _DC_REFLNODE_LIST_FIELD(data_sampling_rule);
    _DC_REFLNODE_LIST_FIELD(data_reporting_condition);
    _DC_REFLNODE_LIST_FIELD(data_reporting_rule);
    _DC_REFLNODE_LIST_FIELD(data_access_profile);
} data_collection_reporting_configuration_t;

/******* Library API ********/

/** Create a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_create(data_collection_reporting_provisioning_session_t *session,
                                               data_collection_client_type_e client_type,
                                               char *authorization_url,
                                               _DC_REFDTYPE_LIST_PARAM(data_sampling_rule),
                                               _DC_REFDTYPE_LIST_PARAM(data_reporting_condition),
                                               _DC_REFDTYPE_LIST_PARAM(data_reporting_rule),
                                               _DC_REFDTYPE_LIST_PARAM(data_access_profile))
{
    data_collection_reporting_configuration_t *ret;
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];

    ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    OpenAPI_list_t *daps = NULL, *drcs = NULL, *drrs = NULL, *dsrs = NULL;

    _DC_REFLNODE_IMPORT(data_sampling_rule, dsrs, ret);
    _DC_REFLNODE_IMPORT(data_reporting_condition, drcs, ret);
    _DC_REFLNODE_IMPORT(data_reporting_rule, drrs, ret);
    _DC_REFLNODE_IMPORT(data_access_profile, daps, ret);

    ret->last_modified = ogs_time_now();

    ret->configuration = dc_api_data_reporting_configuration_create(
            authorization_url,
            daps /*data_access_profiles*/,
            (dc_api_data_collection_client_type_e)client_type,
            drcs /*data_reporting_conditions*/,
            data_collection_strdup(id),
            drrs /*data_reporting_rules*/,
            dsrs /*data_sampling_rules*/
            );
    ogs_assert(ret->configuration);
    
    __restamp_configuration(ret);

    if (session) {
        ret->parent = session;
        data_collection_reporting_provisioning_session_add_configuration(session, ret);
    }

    return ret;
}

/** Parse a Data Collection Reporting Provisioning Configuration from request JSON */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_parse_from_json(cJSON *json, const data_collection_reporting_configuration_t *base,
                                                        const char **error_return)
{
    data_collection_reporting_configuration_t *ret;

    ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ret->configuration = dc_api_data_reporting_configuration_parseRequestFromJSON(json, error_return);
    if (ret->configuration) {
        if (base) {
            /* Copy over Read-only fields from the base */
            ret->configuration->data_reporting_configuration_id =
                            data_collection_strdup(base->configuration->data_reporting_configuration_id);
        } else {
            /* Create new read-only fields */
            ogs_uuid_t uuid;
            char id[OGS_UUID_FORMATTED_LENGTH + 1];

            ogs_uuid_get(&uuid);
            ogs_uuid_format(id, &uuid);
            ret->configuration->data_reporting_configuration_id = data_collection_strdup(id);
        }
        __restamp_configuration(ret);
    } else {
        ogs_free(ret);
        ret = NULL;
    }

    return ret;
}

/** Add a Data Collection Reporting Provisioning Configuration to a Data Collection Reporting Provisioning Session */
DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_reporting_configuration_set_session(data_collection_reporting_configuration_t *configuration,
                                                    data_collection_reporting_provisioning_session_t *session)
{
    if (!configuration) return false;
    if (configuration->parent == session) return true;

    if (configuration->parent) {
        /* remove from old session */
        data_collection_reporting_provisioning_session_remove_configuration(configuration->parent, configuration);
    }

    configuration->parent = session;

    if (session) {
        /* Add to session */
        data_collection_reporting_provisioning_session_add_configuration(session, configuration);
    }

    return true;
}

/** Get the Data Collection Reporting Provisioning Session a Data Collection Reporting Provisioning Configuration belongs to */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t *
data_collection_reporting_configuration_get_session(data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return NULL;
    return configuration->parent;
}

/** Replace a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_reporting_configuration_replace(data_collection_reporting_configuration_t *old_configuration,
                                                data_collection_reporting_configuration_t *new_configuration)
{
    if (!old_configuration) return false;
    if (!new_configuration) return false;
    if (!old_configuration->parent) return false;

    if (strcmp(old_configuration->configuration->data_reporting_configuration_id,
               new_configuration->configuration->data_reporting_configuration_id)) {
        // uuids must match
        return false;
    }

    if (new_configuration->parent) {
        // detach replacement from other parent
        data_collection_reporting_provisioning_session_remove_configuration(new_configuration->parent, new_configuration);
    }

    // Attach new config to old session
    new_configuration->parent = old_configuration->parent;
    data_collection_reporting_provisioning_session_replace_configuration(new_configuration->parent, new_configuration);

    // Detach old config from the session
    old_configuration->parent = NULL;

    return true;
}

/** Update a Data Collection Reporting Provisioning Configuration with new parameters */
DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_reporting_configuration_update(data_collection_reporting_configuration_t *old_configuration,
                                                data_collection_reporting_configuration_t *new_configuration)
{
    if (!old_configuration) return false;
    if (!new_configuration) return true; /* nothing to update, so we've already succeeded */

    /* Copy over read-only fields */
    if (new_configuration->configuration->data_reporting_configuration_id) {
        ogs_free(new_configuration->configuration->data_reporting_configuration_id);
    }
    new_configuration->configuration->data_reporting_configuration_id =
                    data_collection_strdup(old_configuration->configuration->data_reporting_configuration_id);

    // If new configuration is already attached to a different parent (Shouldn't be needed, but just incase)
    if (new_configuration->parent && new_configuration->parent != old_configuration->parent) {
        // Detach replacement from other parent
        data_collection_reporting_provisioning_session_remove_configuration(new_configuration->parent, new_configuration);
    }

    __restamp_configuration(new_configuration);

    new_configuration->parent = old_configuration->parent;
    data_collection_reporting_provisioning_session_replace_configuration(new_configuration->parent, new_configuration);
    old_configuration->parent = NULL;

    return true;
}

/** Destroy a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API void
data_collection_reporting_configuration_destroy(data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return;

    if (configuration->parent) {
        data_collection_reporting_provisioning_session_t *session = configuration->parent;
        configuration->parent = NULL;
        data_collection_reporting_provisioning_session_remove_configuration(session, configuration);
    }

    _DC_REFLNODE_PREFREE(data_sampling_rule, configuration, configuration);
    _DC_REFLNODE_PREFREE(data_reporting_condition, configuration, configuration);
    _DC_REFLNODE_PREFREE(data_reporting_rule, configuration, configuration);
    _DC_REFLNODE_PREFREE(data_access_profile, configuration, configuration);

    if (configuration->configuration) {
        dc_api_data_reporting_configuration_free(configuration->configuration);
        configuration->configuration = NULL;
    }

    if (configuration->etag) {
        ogs_free(configuration->etag);
        configuration->etag = NULL;
    }

    ogs_free(configuration);
}

/** Find a Data Collection Reporting Provisioning Configuration by its Id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_find(data_collection_reporting_provisioning_session_t *session, const char *configuration_id)
{
    return data_collection_reporting_provisioning_session_get_configuration_by_id(session, configuration_id);
}

/** Set the auth URL */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_set_auth_url(data_collection_reporting_configuration_t *config, const char *auth_url)
{
    if (!config || !config->configuration) return OGS_ERROR;

    if (config->configuration->authorization_url) ogs_free(config->configuration->authorization_url);
    config->configuration->authorization_url = data_collection_strdup(auth_url);

    __restamp_configuration(config);

    return OGS_OK;
}

/** Add a sampling rule */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_add_sampling_rule(data_collection_reporting_configuration_t *config,
                                                          data_collection_data_sampling_rule_t *rule)
{
    if (!config || !config->configuration || !rule) return OGS_ERROR;

    _DC_REFLNODE_ADD(data_sampling_rule, config, configuration, rule);

    __restamp_configuration(config);

    return OGS_OK;
}

/** Remove a sampling rule */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_remove_sampling_rule(data_collection_reporting_configuration_t *config,
                                                             const data_collection_data_sampling_rule_t *rule)
{
    if (!config || !config->configuration || !rule) return OGS_ERROR;
    
    _DC_REFLNODE_REMOVE(data_sampling_rule, config, configuration, rule);
    
    __restamp_configuration(config);

    return OGS_OK;
}

/** Get a Data Collection Reporting Provisioning Configuration as JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *
data_collection_reporting_configuration_json(const data_collection_reporting_configuration_t *configuration)
{
    if (!configuration || !configuration->configuration) return NULL;

    return dc_api_data_reporting_configuration_convertResponseToJSON(configuration->configuration);
}

/** Get the Configuration Id for a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API const char *
data_collection_reporting_configuration_id(const data_collection_reporting_configuration_t *configuration)
{
    if (!configuration || !configuration->configuration) return NULL;
    return configuration->configuration->data_reporting_configuration_id;
}

/** Get the last modification time for a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t
data_collection_reporting_configuration_last_modified(const data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return 0;
    return configuration->last_modified;
}

/** Get the Entity Tag for a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API const char *
data_collection_reporting_configuration_etag(const data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return NULL;
    return configuration->etag;
}

/** Serialise a Data Collection Reporting Provisioning Configuration for debugging purposes */
DATA_COLLECTION_SVC_PRODUCER_API char *
data_collection_reporting_configuration_serialise(const data_collection_reporting_configuration_t *configuration)
{
    cJSON *json = data_collection_reporting_configuration_json(configuration);

    if (!json) return NULL;

    char *rc_obj = cJSON_Print(json);
    cJSON_Delete(json);

    char *ret = ogs_msprintf("DataCollectionReportingConfiguration [0x%p]: Parent = 0x%p, %s", configuration, configuration->parent, rc_obj);
    cJSON_free(rc_obj);

    return ret;
}

/******* Library protected functions ********/
void reporting_configuration_detach_session(data_collection_reporting_configuration_t *configuration)
{
    if (configuration) configuration->parent = NULL;
}

/******* Local private functions ********/

/** Recalculate the Etag and set the modification date-time */
static void __restamp_configuration(data_collection_reporting_configuration_t *configuration)
{
    cJSON *json = data_collection_reporting_configuration_json(configuration);
    char *obj_str = NULL;    

    if (json) {
        obj_str = cJSON_Print(json);
        cJSON_Delete(json);
    }
    
    configuration->last_modified = ogs_time_now();
    configuration->etag = obj_str?calculate_hash(obj_str):NULL;
    if (obj_str) cJSON_free(obj_str);
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
