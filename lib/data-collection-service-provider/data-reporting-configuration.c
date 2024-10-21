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
#include "utilities.h"
#include "data-reporting-configuration.h"
#include "data-report.h"
#include "data-collection-sp/data-collection.h"

/***** Private function prototypes *****/

static void __reporting_configuration_new_uuid(data_collection_reporting_configuration_t *config);
static void __reporting_configuration_update_cache_params(data_collection_reporting_configuration_t *config);
static void __provisioning_configuration_data_sampling_rules_add_context_ids(data_collection_model_data_reporting_configuration_t *data_reporting_configuration);
static void __provisioning_configuration_data_reporting_rules_add_context_ids(data_collection_model_data_reporting_configuration_t *data_reporting_configuration);
static void __provisioning_configuration_data_reporting_conditions_add_context_ids(data_collection_model_data_reporting_configuration_t *data_reporting_configuration);
static bool __check_for_location_and_user_restrictions(data_collection_model_data_reporting_configuration_t *data_reporting_configuration,  char **err_return, char **err_param, char **err_code);
static bool __data_report_handler_valid_aggregation_function(data_collection_reporting_provisioning_session_t *parent_session, data_collection_model_data_reporting_configuration_t *data_reporting_configuration, char **err_return, char **err_param, char **err_code);
static data_collection_lnode_t *__aggregation_function_make_lnode(char *aggregation_function);
static void  __aggregation_node_destroy(char *aggregation_function);

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
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *data_collection_reporting_configuration_parse_from_json(cJSON *json, data_collection_reporting_provisioning_session_t *parent_session, data_collection_reporting_configuration_t *base, char **err_return, char **err_class, char **err_param, char **err_code)
{
    data_collection_reporting_configuration_t *ret = ogs_calloc(1, sizeof(*ret));

    /* Parse model */
    ret->model = data_collection_model_data_reporting_configuration_fromJSON(json, true, err_return, err_class, err_param);
    if (!ret->model) {
        ogs_free(ret);
        return NULL;
    }

    if(__check_for_location_and_user_restrictions(ret->model, err_return, err_param, err_code)){
        data_collection_model_data_reporting_configuration_free(ret->model);
        ogs_free(ret);
        return NULL;
    }

    if(!__data_report_handler_valid_aggregation_function(parent_session, ret->model, err_return, err_param, err_code)){
        data_collection_model_data_reporting_configuration_free(ret->model);
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

    if(data_collection_model_data_reporting_configuration_has_data_sampling_rules(ret->model)) {
         __provisioning_configuration_data_sampling_rules_add_context_ids(ret->model);
    }

    if( data_collection_model_data_reporting_configuration_has_data_reporting_rules(ret->model)) {
        __provisioning_configuration_data_reporting_rules_add_context_ids(ret->model);
    }

    __provisioning_configuration_data_reporting_conditions_add_context_ids(ret->model);

    __reporting_configuration_update_cache_params(ret);

    if (parent_session) {
        data_collection_reporting_configuration_set_session(ret, parent_session);
    }

    //ogs_debug("data_collection_reporting_configuration_parse_from_json: created configuration %p (parent=%p)", ret, ret->parent);

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
    //ogs_debug("data_collection_reporting_configuration_destroy(%p)", configuration);
    if (!configuration) return;
    data_collection_reporting_configuration_set_session(configuration, NULL);
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
    //ogs_debug("data_collection_reporting_configuration_set_session(%p, %p)", config, parent_session);
    if (!config) return false;
    if (config->parent == parent_session) return true;
    if (config->parent) {
        /* detatch from existing parent */
        //ogs_debug("data_collection_reporting_configuration_set_session: configuration %p detach from %p", config, config->parent);
        data_collection_reporting_provisioning_session_remove_configuration(config->parent, config);
        config->parent = NULL;
    }
    if (parent_session) {
        /* attach to session */
        //ogs_debug("data_collection_reporting_configuration_set_session: configuration %p attach to %p", config, parent_session);
        if (data_collection_reporting_provisioning_session_add_configuration(parent_session, config) != OGS_OK) return false;
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

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_provisioning_configurations_aggregations_functions_get(const char *external_application_id, const char *event_type, ogs_list_t *aggregation_functions)
{
    ogs_hash_index_t *it;
    ogs_hash_t *data_reporting_provisioning_session = data_collection_self()->data_reporting_provisioning_sessions;
    data_collection_reporting_provisioning_session_t *session;
    for (it = ogs_hash_first(data_reporting_provisioning_session); it; it = ogs_hash_next(it)) {
        const char *key;
        int key_len;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&session));

        if(!strcmp(data_collection_reporting_provisioning_session_get_af_event_type(session), event_type) && !strcmp(data_collection_reporting_provisioning_session_get_external_application_id(session), external_application_id)) {

            ogs_hash_index_t *hit, *save_hit;
            const ogs_hash_t *configurations = data_collection_reporting_provisioning_session_get_configurations(session);
            data_collection_reporting_configuration_t *configuration;

            save_hit = hit = ogs_hash_index_make(configurations);
            for (hit = ogs_hash_next(hit); hit; hit = ogs_hash_next(hit)) {
                const char *ckey;
                int ckey_len;
		ogs_list_t *data_access_profiles;

	        data_access_profiles = (ogs_list_t*) ogs_calloc(1,sizeof(*data_access_profiles));
                ogs_assert(data_access_profiles);
                ogs_list_init(data_access_profiles);

                ogs_hash_this(hit, (const void **)&ckey, &ckey_len, (void**)(&configuration));
		data_access_profiles = data_collection_model_data_reporting_configuration_get_data_access_profiles(configuration->model);
		if(data_access_profiles) {
                    data_collection_lnode_t *data_access_profile_node;
                    ogs_list_for_each(data_access_profiles, data_access_profile_node) {
                        data_collection_model_data_access_profile_t *data_access_profile = data_access_profile_node->object;
			if(data_collection_model_data_access_profile_has_location_access_restrictions(data_access_profile)) {
			    ogs_debug("Filtering by location not implemented");
			}
			if(data_collection_model_data_access_profile_has_user_access_restrictions(data_access_profile)) {
			    ogs_debug("Filtering by user Ids not implemented");
			}
                        if(data_collection_model_data_access_profile_has_time_access_restrictions(data_access_profile)) {
                            const data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions;
                            ogs_list_t *aggregation_functions_time_access_restrictions;
			    //ogs_list_t *aggregation_functions;
                            data_collection_lnode_t *aggregation_function_node;
                            data_access_profile_time_access_restrictions =
                                data_collection_model_data_access_profile_get_time_access_restrictions(data_access_profile);
                            aggregation_functions_time_access_restrictions = data_collection_model_data_access_profile_time_access_restrictions_get_aggregation_functions(data_access_profile_time_access_restrictions);
                            ogs_list_for_each(aggregation_functions_time_access_restrictions, aggregation_function_node) {
                                data_collection_model_data_aggregation_function_type_t *aggregation_function = aggregation_function_node->object;
                                const char *aggregation_name = data_collection_model_data_aggregation_function_type_get_string(aggregation_function);
				if(aggregation_name) {
				    //data_collection_lnode_t *aggregation_function = data_collection_lnode_create(data_collection_strdup(aggregation_name), (void(*)(void*))ogs_free);
				    //data_collection_lnode_t *aggregation_function = data_collection_lnode_create(data_collection_strdup(aggregation_name), NULL);
				    data_collection_lnode_t *aggregation_function = __aggregation_function_make_lnode(data_collection_strdup(aggregation_name));
				    ogs_list_add(aggregation_functions, aggregation_function); 
	
				}	
		            }
			}
		    }
		}

	        if(data_access_profiles) ogs_free(data_access_profiles);
	    }
            ogs_free(save_hit);
	}
    }
    return aggregation_functions;
			

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

static bool __check_for_location_and_user_restrictions(data_collection_model_data_reporting_configuration_t *data_reporting_configuration,  char **err_return, char **err_param, char **err_code)
{
    ogs_list_t *data_access_profiles;

    data_access_profiles = data_collection_model_data_reporting_configuration_get_data_access_profiles(data_reporting_configuration);
    if(data_access_profiles) {
        data_collection_lnode_t *data_access_profile_node;
        ogs_list_for_each(data_access_profiles, data_access_profile_node) {
	    data_collection_model_data_access_profile_t *data_access_profile = data_access_profile_node->object;
            if(data_collection_model_data_access_profile_has_location_access_restrictions(data_access_profile)) {
	       if(err_return) *err_return = data_collection_strdup("Filtering on the field \"dataAccessProfiles.locationAccessRestrictions\" not implemented.");
               if(err_param) *err_param = data_collection_strdup("dataAccessProfiles.locationAccessRestrictions");
	       if(err_code) *err_code = data_collection_strdup("501");
               data_collection_list_free(data_access_profiles);
               return true;
	    }
	    if(data_collection_model_data_access_profile_has_user_access_restrictions(data_access_profile)) {

	       if(err_return) *err_return = data_collection_strdup("Filtering on the field \"dataAccessProfiles.userAccessRestrictions\" not implemented.");
               if(err_param) *err_param = data_collection_strdup("dataAccessProfiles.userAccessRestrictions");
	       if(err_code) *err_code = data_collection_strdup("501");
               data_collection_list_free(data_access_profiles);
               return true;
	    }
	}
        data_collection_list_free(data_access_profiles);
    }
    return false;

}

static bool __data_report_handler_valid_aggregation_function(data_collection_reporting_provisioning_session_t *parent_session, data_collection_model_data_reporting_configuration_t *data_reporting_configuration, char **err_return, char **err_param, char **err_code)
{

    const data_collection_data_report_handler_t *handler = NULL;
    ogs_list_t *data_access_profiles;
    handler = data_collection_reporting_provisioning_session_get_data_report_handler(parent_session);
    if (handler) {
	data_access_profiles = data_collection_model_data_reporting_configuration_get_data_access_profiles(data_reporting_configuration);
	if(data_access_profiles) {
            data_collection_lnode_t *data_access_profile_node;
            ogs_list_for_each(data_access_profiles, data_access_profile_node) {
                data_collection_model_data_access_profile_t *data_access_profile = data_access_profile_node->object;
                if(data_collection_model_data_access_profile_has_time_access_restrictions(data_access_profile)) {
	            const data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions;
		    ogs_list_t *aggregation_functions;
                    data_collection_lnode_t *aggregation_function_node;
		    data_access_profile_time_access_restrictions =
			    data_collection_model_data_access_profile_get_time_access_restrictions(data_access_profile);
                    aggregation_functions = data_collection_model_data_access_profile_time_access_restrictions_get_aggregation_functions(data_access_profile_time_access_restrictions);
                    ogs_list_for_each(aggregation_functions, aggregation_function_node) {
                        data_collection_model_data_aggregation_function_type_t *aggregation_function = aggregation_function_node->object;
		        const char *aggregation_name = data_collection_model_data_aggregation_function_type_get_string(aggregation_function);
			if(!data_report_handler_valid_aggregation_function(handler, aggregation_name)){
			    const char *event = data_collection_reporting_provisioning_session_get_af_event_type(parent_session);
			    if(err_return) *err_return = ogs_msprintf("Aggregation function '%s' is not appropriate for '%s' event type.", aggregation_name, event);
                            if(err_param) *err_param = data_collection_strdup("dataAccessProfiles.timeAccessRestrictions");
                            data_collection_list_free(aggregation_functions);
                            data_collection_list_free(data_access_profiles);
			    return false;
			}
		    }
                    data_collection_list_free(aggregation_functions);
		}
	    }
            data_collection_list_free(data_access_profiles);
	    return true;
	}
    }
    return false;
}


static void __provisioning_configuration_data_sampling_rules_add_context_ids(data_collection_model_data_reporting_configuration_t *data_reporting_configuration){

    ogs_list_t *configuration_sampling_rules;
    configuration_sampling_rules = data_collection_model_data_reporting_configuration_get_data_sampling_rules(data_reporting_configuration);
    if(configuration_sampling_rules) {
        data_collection_lnode_t *configuration_sampling_rule_node;
        const char *configuration_id;

        ogs_list_for_each(configuration_sampling_rules, configuration_sampling_rule_node) {
            data_collection_model_data_sampling_rule_t *config_sampling_rule = configuration_sampling_rule_node->object;

            configuration_id = data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(data_reporting_configuration);
            data_collection_model_data_sampling_rule_add_context_ids(config_sampling_rule, data_collection_strdup(configuration_id));
        }
        data_collection_list_free(configuration_sampling_rules);
    }
}

static void __provisioning_configuration_data_reporting_rules_add_context_ids(data_collection_model_data_reporting_configuration_t *data_reporting_configuration)
{
    ogs_list_t *configuration_reporting_rules;
    configuration_reporting_rules = data_collection_model_data_reporting_configuration_get_data_reporting_rules(data_reporting_configuration);
    if(configuration_reporting_rules) {
        data_collection_lnode_t *configuration_reporting_rule_node;
	const char *configuration_id;

	ogs_list_for_each(configuration_reporting_rules, configuration_reporting_rule_node) {
            data_collection_model_data_reporting_rule_t *config_reporting_rule = configuration_reporting_rule_node->object;

            configuration_id = data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(data_reporting_configuration);
	    data_collection_model_data_reporting_rule_add_context_ids(config_reporting_rule, data_collection_strdup(configuration_id));
        }
        data_collection_list_free(configuration_reporting_rules);
    }
}

static void __provisioning_configuration_data_reporting_conditions_add_context_ids(data_collection_model_data_reporting_configuration_t *data_reporting_configuration)
{
    ogs_list_t *configuration_reporting_conditions;
    configuration_reporting_conditions = data_collection_model_data_reporting_configuration_get_data_reporting_conditions(data_reporting_configuration);
    if (configuration_reporting_conditions) {
        data_collection_lnode_t *configuration_reporting_condition_node;
        const char *configuration_id;

        ogs_list_for_each(configuration_reporting_conditions, configuration_reporting_condition_node) {
            data_collection_model_data_reporting_condition_t *config_reporting_condition = configuration_reporting_condition_node->object;

            configuration_id = data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(data_reporting_configuration);
            data_collection_model_data_reporting_condition_add_context_ids(config_reporting_condition, data_collection_strdup(configuration_id));
        }
        data_collection_list_free(configuration_reporting_conditions);
    }
}

static data_collection_lnode_t *__aggregation_function_make_lnode(char *aggregation_function){
     return data_collection_lnode_create(aggregation_function, (void(*)(void*))__aggregation_node_destroy);
}

static void  __aggregation_node_destroy(char *aggregation_function){
    ogs_free(aggregation_function);
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
