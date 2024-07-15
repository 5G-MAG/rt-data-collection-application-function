/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "hash.h"

#include "data-reporting-configuration.h"
#include "data-collection-sp/data-collection.h"

/***** Private function prototypes *****/

static void __reporting_configuration_new_uuid(data_collection_reporting_configuration_t *config);
static void __reporting_configuration_update_cache_params(data_collection_reporting_configuration_t *config);

/***** Enumerations *****/

/***** Data Types *****/

typedef struct data_collection_reporting_configuration_s {
    ogs_lnode_t node; // Allow these to be listed in an ogs_list_t
    data_collection_model_data_reporting_configuration_t *model;
    data_collection_reporting_provisioning_session_t *parent;
    ogs_time_t last_modified;
    char *etag;
} data_collection_reporting_configuration_t;

/***** Library function API *****/

/**** Data Reporting Configuration ****/

/** Create a new, empty configuration
 *
 * @return a new reporting configuration object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *data_collection_reporting_configuration_create()
{
    data_collection_reporting_configuration_t *ret = ogs_calloc(1, sizeof(*ret));
    ret->model = data_collection_model_data_reporting_configuration_create();
    __reporting_configuration_new_uuid(ret);
    __reporting_configuration_update_cache_params(ret);
    return ret;
}

/** Create a new reporting configuration object from a TS 26.532 DataReportingConfiguration object
 *
 * This will take ownership of the @a configuration object.
 *
 * @param configuration A TS 26.532 DataReportingConfiguration object to convert to a reporting configuration object.
 * @return a new reporting configuration object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *data_collection_reporting_configuration_create_from_model(data_collection_model_data_reporting_configuration_t *configuration)
{
    data_collection_reporting_configuration_t *ret = ogs_calloc(1, sizeof(*ret));
    ret->model = configuration;
    if (!data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(ret->model))
        __reporting_configuration_new_uuid(ret);
    __reporting_configuration_update_cache_params(ret);
    return ret;
}

/** Get the TS 26.532 DataReportingConfiguration object represented by this configuration
 *
 * @param config The configuration to derive the TS 26.532 DataReportingConfiguration object from.
 * @return A read-only TS 26.532 DataReportingConfiguration object.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_configuration_t *data_collection_reporting_configuration_model(const data_collection_reporting_configuration_t *config)
{
    if (!config) return NULL;
    return config->model;
}

/** Create a new reporting configuration object from TS 26.532 DataReportingConfiguration JSON request representation
 *
 * Parses the JSON into a new reporting configuration object and returns the object. If a parsing error occurs then `NULL` is
 * returned and the `char*` pointers referenced by @a err_return, @a err_class and @a err_param will be set to either a new nul
 * terminated string or `NULL` to indicate where the error occurred. It is up to the caller to use `ogs_free()` to free the three
 * error strings if they have been set due to a parsing error.
 *
 * @param json The JSON tree to parse.
 * @param base An existing reporting configuration object to copy read-only fields from or `NULL`.
 * @param err_return Filled in on error with a human readable error string.
 * @param err_class Filled in on error with the classname of the class that generated the parsing error.
 * @param err_param Filled in on error with the parameter name of the parameter that caused the parsing error.
 * @return A new reporting configuration object filled in from the JSON or `NULL` if there was a parsing error.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *data_collection_reporting_configuration_parse_from_json(cJSON *json, data_collection_reporting_configuration_t *base, char **err_return, char **err_class, char **err_param)
{
    data_collection_reporting_configuration_t *ret = ogs_calloc(1, sizeof(*ret));

    /* Parse model */
    ret->model = data_collection_model_data_reporting_configuration_fromJSON(json, true, err_return, err_class, err_param);
    if (!ret->model) {
        ogs_free(ret);
        return NULL;
    }
    
    if (base) {
        /* Copy read-only fields */
        data_collection_model_data_reporting_configuration_set_data_reporting_configuration_id(ret->model, data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(base->model));
    } else {
        /* need a new id */
        __reporting_configuration_new_uuid(ret);
    }

    __reporting_configuration_update_cache_params(ret);

    return ret;
}

/** Replace an existing configuration with a new configuration
 *
 * The new configuration will be attached to the same data reporting provisioning session as the original @a old configuration.
 * @param old The configuration to replace.
 * @param replace_with The new configuration to use instead.
 * @return `true` if the replacement was successful or `false` if there was an error.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_reporting_configuration_update(data_collection_reporting_configuration_t *old, data_collection_reporting_configuration_t *replace_with)
{
    if (!old) return false;
    if (!replace_with) return false;

    /* configurations must have the same ID */
    const char *old_config_id = data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(old->model);
    const char *new_config_id = data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(replace_with->model);
    if (!strcmp(old_config_id, new_config_id)) return false;

    /* move the model over */
    data_collection_model_data_reporting_configuration_move(old->model, replace_with->model);

    /* keep the parent */

    /* transfer HTTP metadata for model */
    old->last_modified = replace_with->last_modified;
    old->etag = replace_with->etag;

    data_collection_reporting_configuration_destroy(replace_with);

    return true;
}

/** Destroy a configuration
 *
 * This will remove the configuration from its parent data reporting provisioning session and free the configuration memory.
 *
 * @param configuration The configuration to destroy.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_configuration_destroy(data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return;
    if (configuration->parent) {
        data_collection_reporting_provisioning_session_remove_configuration(configuration->parent, configuration);
        configuration->parent = NULL;
    }
    data_collection_model_data_reporting_configuration_free(configuration->model);
    configuration->model = NULL;
    if (configuration->etag) {
        ogs_free(configuration->etag);
        configuration->etag = NULL;
    }
    ogs_free(configuration);
}

/** Set the parent data reporting provisioning session for a configuration
 *
 * This will detatch the configuration from its existing parent, if different from the @a parent_session, and attach it to
 * @a parent_session. Use a @a parent_session of `NULL` to detatch the configuration from all data reporting provisioning sessions.
 * This may fail if the configuration has an id matching an existing configuration in @a parent_session.
 *
 * @param config The configuration to change the parent for.
 * @param parent_session The data reporting provisioning session to set as parent, use `NULL` to detatch the configuration.
 * @return `true` if the configuration is attached to the parent, `false` if there was already another configuration withthe same
 *         id already attached to @a parent_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_reporting_configuration_set_session(data_collection_reporting_configuration_t *config, data_collection_reporting_provisioning_session_t *parent_session)
{
    if (!config) return false;
    if (config->parent == parent_session) return true;
    if (config->parent) {
        /* detatch from existing parent */
        data_collection_reporting_provisioning_session_remove_configuration(config->parent, config);
        config->parent = NULL;
    }
    if (parent_session) {
        /* attach to session */
        if (!data_collection_reporting_provisioning_session_add_configuration(parent_session, config)) return false;
        config->parent = parent_session;
    }
    return true;
}

/** Get the TS 26.532 DataReportingConfiguration JSON representation response for this configuration
 *
 * It is the callers responsibility to call `cJSON_Delete()` on the returned object.
 *
 * @param config The configuration to convert to a JSON response.
 * @return The cJSON tree representing a TS 26.532 DataReportingConfiguration response object.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_configuration_json(data_collection_reporting_configuration_t *config)
{
    if (!config) return NULL;
    return data_collection_model_data_reporting_configuration_toJSON(config->model, false);
}

/** Get reporting configuration id
 * @param config The configuration to return the id for.
 * @return The reporting configuration ID for this configuration.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_id(data_collection_reporting_configuration_t *config)
{
    if (!config) return NULL;

    return data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(config->model);
}

/** Get the date-time timestamp for the last modification of this configuration
 * @return The timestamp when this object was last modified.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_reporting_configuration_last_modified(data_collection_reporting_configuration_t *config)
{
    if (!config) return 0;

    return config->last_modified;
}

/** Get the instance id for the configuration
 *
 * This tag will change when the configuration is changed.
 *
 * @return An entity instance id tag suitable for an HTTP "ETag" header.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_etag(data_collection_reporting_configuration_t *config)
{
    if (!config) return NULL;

    return config->etag;
}

/*************** Private functions ******************/

static void __reporting_configuration_new_uuid(data_collection_reporting_configuration_t *config)
{
    if (!config) return;
    
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    data_collection_model_data_reporting_configuration_set_data_reporting_configuration_id(config->model, id);
}

static void __reporting_configuration_update_cache_params(data_collection_reporting_configuration_t *config)
{
    if (!config) return;

    cJSON *json = data_collection_model_data_reporting_configuration_toJSON(config->model, false);
    char *data = cJSON_Print(json);
    cJSON_Delete(json);
    config->last_modified = ogs_time_now();
    if (config->etag) ogs_free(config->etag);
    config->etag = calculate_hash(data);
    cJSON_free(data);
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
