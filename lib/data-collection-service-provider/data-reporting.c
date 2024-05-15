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
#include "data-reporting.h"
#include "data-reporting-session-cache.h"

static char *calculate_data_reporting_session_hash(dc_api_data_reporting_session_t *data_reporting_session);
static void supported_domains_remove_all(data_domain_list_t *supported_domains);
static ogs_lnode_t *copy_data_domain_node(const ogs_lnode_t *to_copy);

/********* Library API functions *********/

DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_create(const char *external_app_id, const data_domain_list_t *supported_domains)
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

    ogs_hash_set(data_collection_self()->data_reporting_sessions, data_collection_reporting_session->data_reporting_session_id, OGS_HASH_KEY_STRING, data_collection_reporting_session);

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
    if (session->data_reporting_session) dc_api_data_reporting_session_free(session->data_reporting_session);
    ogs_free(session);
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_find(const char *session_id)
{
    return ogs_hash_get(data_collection_self()->data_reporting_sessions, session_id, OGS_HASH_KEY_STRING);
}

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_session_json(const data_collection_reporting_session_t *session)
{
    if (!session || !session->data_reporting_session) return NULL;
    return dc_api_data_reporting_session_convertResponseToJSON(session->data_reporting_session);
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

data_collection_reporting_session_t *data_reporting_session_populate(data_collection_reporting_session_t *data_collection_reporting_session, dc_api_data_reporting_session_t *data_reporting_session)
{
    OpenAPI_list_t* reporting_conditions;
    OpenAPI_list_t* reporting_rules;
    OpenAPI_list_t* sampling_rules;

    data_collection_reporting_session->data_reporting_session = data_reporting_session;
    data_collection_reporting_session->data_reporting_session->session_id = data_collection_strdup(data_collection_reporting_session->data_reporting_session_id);

    //Reporting conditions are provided through the provisioning session
    //For now create an empty list for reporting_conditions
    //TODO: Use Reporting conditions from provisioning session once it is implemented

    reporting_conditions = OpenAPI_list_create();
    ogs_assert(reporting_conditions);

    reporting_rules = OpenAPI_list_create();
    ogs_assert(reporting_rules);

    sampling_rules = OpenAPI_list_create();
    ogs_assert(sampling_rules);

    data_reporting_session->reporting_conditions = reporting_conditions;

    data_reporting_session->reporting_rules = reporting_rules;

    data_reporting_session->sampling_rules = sampling_rules;

    if(data_collection_reporting_session->data_reporting_session->valid_until) ogs_free(data_collection_reporting_session->data_reporting_session->valid_until);
    data_collection_reporting_session->data_reporting_session->valid_until = ogs_time_to_string(ogs_time_now() + ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));

    data_collection_reporting_session->hash = calculate_data_reporting_session_hash(data_collection_reporting_session->data_reporting_session);

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

static char *calculate_data_reporting_session_hash(dc_api_data_reporting_session_t *data_reporting_session)
{
    cJSON *data_reporting_sess;
    char *data_reporting_session_to_hash;
    char *data_reporting_session_hashed = NULL;

    data_reporting_sess = dc_api_data_reporting_session_convertResponseToJSON(data_reporting_session);
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
