/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "ogs-core.h"

#include "utilities.h"
#include "hash.h"
#include "timer.h"
#include "data-reporting-sampling-rules.h"
#include "data-reporting-rules.h"
#include "data-reporting-conditions.h"
#include "data-reporting.h"
#include "data-reporting-provisioning.h"
#include "data-reporting-session-cache.h"

static char *calculate_data_reporting_session_hash(data_collection_model_data_reporting_session_t *data_reporting_session);
static void supported_domains_remove_all(data_domain_list_t *supported_domains);
static ogs_lnode_t *copy_data_domain_node(const ogs_lnode_t *to_copy);
static void data_reporting_session_add_or_update_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *supported_domains, data_collection_reporting_client_type_e client_type);
static void data_reporting_session_add_or_update_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *supported_domains, data_collection_reporting_client_type_e client_type);
static void data_reporting_session_add_or_update_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *supported_domains, data_collection_reporting_client_type_e client_type);
//static data_collection_data_report_handler_t *data_report_handler_get(data_domain_list_t *supported_domains);
static data_collection_data_report_handler_t *get_matching_data_report_handler(const char *data_domain);

/********* Library API functions *********/

DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_create(const char *external_app_id, const data_domain_list_t *supported_domains, data_collection_reporting_client_type_e client_type)
{
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];
    data_collection_reporting_session_t *data_collection_reporting_session;

    ogs_info("In data_collection_reporting_session_create");

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    data_collection_reporting_session = ogs_calloc(1, sizeof(data_collection_reporting_session_t));
    ogs_assert(data_collection_reporting_session);

    data_collection_reporting_session->data_reporting_session_id = data_collection_strdup(id);

    data_collection_reporting_session->external_application_id = data_collection_strdup(external_app_id);

    data_collection_reporting_session->supported_domains =
                 (data_domain_list_t*)list_clone(supported_domains, copy_data_domain_node);

    data_collection_reporting_session->received = ogs_time_now();
    data_collection_reporting_session->client_type =  client_type;

    ogs_hash_set(data_collection_self()->data_reporting_sessions, data_collection_reporting_session->data_reporting_session_id, OGS_HASH_KEY_STRING, data_collection_reporting_session);

    data_collection_list_free(supported_domains);
    return data_collection_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_session_destroy(data_collection_reporting_session_t *session)
{
    ogs_assert(session);

    ogs_hash_set(data_collection_self()->data_reporting_sessions, session->data_reporting_session_id, OGS_HASH_KEY_STRING, NULL);
    data_reporting_session_cache_del(data_collection_self()->data_reporting_sessions_cache, session->data_reporting_session_id);

    if (session->external_application_id) ogs_free(session->external_application_id);
    if (session->data_reporting_session_id) ogs_free(session->data_reporting_session_id);
    if (session->supported_domains) {
        supported_domains_remove_all(session->supported_domains);
        ogs_free(session->supported_domains);
	session->supported_domains = NULL;
    }
    if (session->hash) ogs_free(session->hash);
    if (session->data_reporting_session) data_collection_model_data_reporting_session_free(session->data_reporting_session);
    ogs_free(session);
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_find(const char *session_id)
{
    return ogs_hash_get(data_collection_self()->data_reporting_sessions, session_id, OGS_HASH_KEY_STRING);
}

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_session_json(const data_collection_reporting_session_t *session)
{
    if (!session || !session->data_reporting_session) return NULL;
    return data_collection_model_data_reporting_session_toJSON(session->data_reporting_session, false);
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_session_get_id(const data_collection_reporting_session_t *session)
{
    return session->data_reporting_session_id;
}


DATA_COLLECTION_SVC_PRODUCER_API const struct timespec* data_collection_reporting_session_refresh(data_collection_reporting_session_t *session){

    static struct timespec ts;
    return &ts;
}

/********** Library internal functions ***********/

data_collection_reporting_session_t *data_reporting_session_populate(data_collection_reporting_session_t *data_collection_reporting_session, data_collection_model_data_reporting_session_t *data_reporting_session)
{
    ogs_list_t *supported_domains;

    data_collection_reporting_session->data_reporting_session = data_reporting_session;
    data_collection_model_data_reporting_session_set_session_id(data_collection_reporting_session->data_reporting_session, data_collection_reporting_session->data_reporting_session_id);
    supported_domains = data_collection_model_data_reporting_session_get_supported_domains(data_reporting_session);
    data_reporting_session_add_or_update_sampling_rules(data_reporting_session, supported_domains, data_collection_reporting_session->client_type);
    data_reporting_session_add_or_update_reporting_rules(data_reporting_session, supported_domains, data_collection_reporting_session->client_type);
    data_reporting_session_add_or_update_reporting_conditions(data_reporting_session, supported_domains, data_collection_reporting_session->client_type);

    //data_collection_model_data_reporting_session_set_valid_until(ogs_time_now() + ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age)); // Do not set valid_until, it messes with HTTP caching
    data_collection_reporting_session->hash = calculate_data_reporting_session_hash(data_collection_reporting_session->data_reporting_session);
    data_collection_list_free(supported_domains);

    return data_collection_reporting_session;
}



const data_reporting_session_cache_entry_t *data_collection_context_retrieve_reporting_session(const char *reporting_session_id)
{

    data_reporting_session_cache_entry_t *data_reporting_session_cache_entry = NULL;

    if (!data_collection_self()->data_reporting_sessions_cache) {
        data_collection_self()->data_reporting_sessions_cache = data_reporting_session_cache_new();
	if (!data_collection_self()->reporting_sessions_cache_timer) data_collection_self()->reporting_sessions_cache_timer = ogs_timer_add(ogs_app()->timer_mgr, dc_timer_reporting_session_cache, NULL);
        if (data_collection_self()->reporting_sessions_cache_timer) {
            ogs_timer_start(data_collection_self()->reporting_sessions_cache_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));
	}
    } else {
        data_reporting_session_cache_entry = data_reporting_session_cache_find(data_collection_self()->data_reporting_sessions_cache, reporting_session_id);
    }

    if (!data_reporting_session_cache_entry) {
        data_collection_reporting_session_t *data_collection_reporting_session = NULL;
        int rv =0;

        data_collection_reporting_session = data_collection_reporting_session_find(reporting_session_id);

        if (data_collection_reporting_session == NULL){
            ogs_error("Couldn't find the Data Reporting Session [%s]", reporting_session_id);
            return NULL;
        }

        rv = data_reporting_session_cache_add(data_collection_self()->data_reporting_sessions_cache, data_collection_reporting_session);
        if(!rv) {
            ogs_error("Failed to add the Data Reporting Session to the cache [%s]", reporting_session_id);
            return NULL;
        }

        data_reporting_session_cache_entry = data_reporting_session_cache_find(data_collection_self()->data_reporting_sessions_cache, reporting_session_id);
    } else {
        ogs_debug("Found existing data reporting session cache entry");
    }

    if (data_reporting_session_cache_entry == NULL){
       ogs_error("The Data Collection library does not have the reporting session [%s]", reporting_session_id);
    } else {
       data_reporting_session_cache_accessed(data_reporting_session_cache_entry);
    }

    return data_reporting_session_cache_entry;
}

void _reporting_session_add_sampling_rules(data_collection_reporting_session_t *data_reporting_session, const char *data_domain, const ogs_list_t *data_reporting_session_sampling_rules)
{
    data_collection_model_data_reporting_session_add_sampling_rules(data_reporting_session->data_reporting_session, data_domain, data_reporting_session_sampling_rules);
}

void _reporting_session_add_reporting_rules(data_collection_reporting_session_t *data_reporting_session, const char *data_domain, const ogs_list_t *data_reporting_session_reporting_rules)
{
    data_collection_model_data_reporting_session_add_reporting_rules(data_reporting_session->data_reporting_session, data_domain, data_reporting_session_reporting_rules);
}

void _reporting_session_add_reporting_conditions(data_collection_reporting_session_t *data_reporting_session, const char *data_domain, const ogs_list_t *data_reporting_session_reporting_conditions)
{
    data_collection_model_data_reporting_session_add_reporting_conditions(data_reporting_session->data_reporting_session, data_domain, data_reporting_session_reporting_conditions);
}


/*********** Local private functions ***************/

static void supported_domains_remove_all(data_domain_list_t *supported_domains)
{
    data_domain_node_t *supported_domain;
    data_domain_node_t *supported_domain_node;

    if (!supported_domains) return;

    ogs_list_for_each_safe(supported_domains, supported_domain_node, supported_domain) {
        ogs_list_remove(supported_domains, supported_domain);
        if (supported_domain->data_domain) ogs_free(supported_domain->data_domain);
        ogs_free(supported_domain);
    }
}

static void data_reporting_session_add_or_update_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *supported_domains, data_collection_reporting_client_type_e client_type)
{
    //data_domain_node_t *data_domain_node;
    data_collection_data_report_handler_t *handler = NULL;
    data_collection_lnode_t *node = NULL;

    ogs_list_for_each(supported_domains, node) {

	data_collection_model_data_domain_t *data_domain_object = node->object;
        const char *data_domain = data_collection_model_data_domain_get_string(data_domain_object);

        handler = get_matching_data_report_handler(data_domain);
	if(handler) {
	    ogs_list_t *data_reporting_session_sampling_rules_data_domain = NULL;
            const char *external_application_id;

	    external_application_id = data_collection_model_data_reporting_session_get_external_application_id(data_reporting_session);

	    data_reporting_session_sampling_rules_data_domain = data_collection_model_data_reporting_session_get_entry_sampling_rules(data_reporting_session, data_domain);

	    if(!data_reporting_session_sampling_rules_data_domain) {
                 data_reporting_session_sampling_rules_data_domain = (ogs_list_t*) ogs_malloc(sizeof(*data_reporting_session_sampling_rules_data_domain));
                 ogs_assert(data_reporting_session_sampling_rules_data_domain);
                 ogs_list_init(data_reporting_session_sampling_rules_data_domain);
	    }

	    data_collection_adjust_sampling_rules(data_reporting_session, data_reporting_session_sampling_rules_data_domain, external_application_id, handler->event_type, data_domain, client_type);
	    data_collection_model_data_reporting_session_add_sampling_rules(data_reporting_session, data_domain, data_reporting_session_sampling_rules_data_domain);
            data_collection_list_free(data_reporting_session_sampling_rules_data_domain);

            /*
	    ogs_list_t *data_reporting_provisioning_session_configurations;
	    data_reporting_configuration_sampling_rules = data_reporting_configuration_sampling_rules_get(data_collection_reporting_session->external_application_id, handler->event_type, data_collection_reporting_session->client_type);
	    */
	    /*
            data_collection_reporting_provisioning_session_t *provisioning_session;
	    provisioning_session = data_reporting_provisioning_session_get(data_collection_reporting_session->external_application_id, handler->event_type);
	    if(provisioning_session) {

	    }
            */
	}
    }

}


static void data_reporting_session_add_or_update_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *supported_domains, data_collection_reporting_client_type_e client_type)
{
    //data_domain_node_t *data_domain_node;
    data_collection_data_report_handler_t *handler = NULL;
    data_collection_lnode_t *node = NULL;

    ogs_list_for_each(supported_domains, node) {
	data_collection_model_data_domain_t *data_domain_object = node->object;
        const char *data_domain = data_collection_model_data_domain_get_string(data_domain_object);
        handler = get_matching_data_report_handler(data_domain);
	if(handler) {
	    ogs_list_t *data_reporting_session_reporting_rules_data_domain = NULL;
            const char *external_application_id;

	    external_application_id = data_collection_model_data_reporting_session_get_external_application_id(data_reporting_session);

	    data_reporting_session_reporting_rules_data_domain = data_collection_model_data_reporting_session_get_entry_reporting_rules(data_reporting_session, data_domain);

	    if(!data_reporting_session_reporting_rules_data_domain) {
                 data_reporting_session_reporting_rules_data_domain = (ogs_list_t*)ogs_malloc(sizeof(*data_reporting_session_reporting_rules_data_domain));
                 ogs_assert(data_reporting_session_reporting_rules_data_domain);
                 ogs_list_init(data_reporting_session_reporting_rules_data_domain);
	    }

	    data_collection_adjust_reporting_rules(data_reporting_session, data_reporting_session_reporting_rules_data_domain, external_application_id, handler->event_type, data_domain, client_type);
	    data_collection_model_data_reporting_session_add_reporting_rules(data_reporting_session, data_domain, data_reporting_session_reporting_rules_data_domain);
            data_collection_list_free(data_reporting_session_reporting_rules_data_domain);
	}
    }

}

static void data_reporting_session_add_or_update_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *supported_domains, data_collection_reporting_client_type_e client_type)
{
    //data_domain_node_t *data_domain_node;
    data_collection_data_report_handler_t *handler = NULL;
    data_collection_lnode_t *node = NULL;

    ogs_list_for_each(supported_domains, node) {
        data_collection_model_data_domain_t *data_domain_object = node->object;
        const char *data_domain = data_collection_model_data_domain_get_string(data_domain_object);

        handler = get_matching_data_report_handler(data_domain);
        if(handler) {
            ogs_list_t *data_reporting_session_reporting_conditions_data_domain = NULL;
            const char *external_application_id;

            external_application_id = data_collection_model_data_reporting_session_get_external_application_id(data_reporting_session);

            data_reporting_session_reporting_conditions_data_domain = data_collection_model_data_reporting_session_get_entry_reporting_conditions(data_reporting_session, data_domain);

            if(!data_reporting_session_reporting_conditions_data_domain) {
                 data_reporting_session_reporting_conditions_data_domain = (ogs_list_t*)ogs_malloc(sizeof(*data_reporting_session_reporting_conditions_data_domain));
                 ogs_assert(data_reporting_session_reporting_conditions_data_domain);
                 ogs_list_init(data_reporting_session_reporting_conditions_data_domain);
            }

            data_collection_adjust_reporting_conditions(data_reporting_session, data_reporting_session_reporting_conditions_data_domain, external_application_id, handler->event_type, data_domain, client_type);
	    data_collection_model_data_reporting_session_add_reporting_conditions(data_reporting_session, data_domain, data_reporting_session_reporting_conditions_data_domain);
            data_collection_list_free(data_reporting_session_reporting_conditions_data_domain);
	}
    }
}


/*
static data_collection_data_report_handler_t *data_report_handler_get(data_domain_list_t *supported_domains){
    data_domain_node_t *data_domain_node;
    data_collection_data_report_handler_t *handler = NULL;

    ogs_list_for_each(data_collection_reporting_session->supported_domains, data_domain_node) {
        handler = get_matching_data_report_handler(data_domain_node->data_domain);
	if(handler) break;
    }
    return handler;

}
*/

static data_collection_data_report_handler_t *get_matching_data_report_handler(const char *data_domain) {

    data_collection_data_report_handler_t **handlers = (data_collection_data_report_handler_t **)data_collection_self()->config.data_collection_configuration->data_report_handlers;
    int i = 0;

    if(!handlers[i]) {
        ogs_error("No Data Report Handler");
        return NULL;
    }

    for (i = 0; handlers[i]; i++) {
        if(!strcmp(handlers[i]->data_domain, data_domain)) return handlers[i];
    }
    return NULL;

}

static char *calculate_data_reporting_session_hash(data_collection_model_data_reporting_session_t *data_reporting_session)
{
    cJSON *data_reporting_sess;
    char *data_reporting_session_to_hash;
    char *data_reporting_session_hashed = NULL;

    data_reporting_sess = data_collection_model_data_reporting_session_toJSON(data_reporting_session, false);
    if (!data_reporting_sess) return NULL;

    data_reporting_session_to_hash = cJSON_Print(data_reporting_sess);
    cJSON_Delete(data_reporting_sess);

    data_reporting_session_hashed = calculate_hash(data_reporting_session_to_hash);
    cJSON_free(data_reporting_session_to_hash);

    return data_reporting_session_hashed;
}

static ogs_lnode_t *copy_data_domain_node(const ogs_lnode_t *to_copy)
{
    const data_domain_node_t *existing_dd_node = (const data_domain_node_t*)to_copy;

    if (!existing_dd_node) return NULL;

    data_domain_node_t *new_dd_node = (data_domain_node_t*)ogs_calloc(1, sizeof(data_domain_node_t));
    ogs_assert(new_dd_node);

    new_dd_node->data_domain = data_collection_strdup(existing_dd_node->data_domain);

    return &new_dd_node->node;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
