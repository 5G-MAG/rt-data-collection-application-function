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
#include "data-reporting.h"

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

    data_collection_reporting_session->valid_until = data_collection_reporting_session->received + ogs_time_from_sec(
                  data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age);

    ogs_hash_set(data_collection_self()->data_reporting_sessions, data_collection_reporting_session->data_reporting_session_id, OGS_HASH_KEY_STRING, data_collection_reporting_session);

    return data_collection_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_session_destroy(data_collection_reporting_session_t *session)
{
    ogs_assert(session);

    ogs_hash_set(data_collection_self()->data_reporting_sessions, session->data_reporting_session_id, OGS_HASH_KEY_STRING, NULL);

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

/********** Library internal functions ***********/

data_collection_reporting_session_t *data_reporting_session_populate(data_collection_reporting_session_t *data_collection_reporting_session, dc_api_data_reporting_session_t *data_reporting_session)
{
    OpenAPI_list_t* reporting_conditions;
    char *valid_until;

    data_collection_reporting_session->data_reporting_session = data_reporting_session;
    data_collection_reporting_session->data_reporting_session->session_id = data_collection_strdup(data_collection_reporting_session->data_reporting_session_id);

    //Reporting conditions are provided through the provisioning session
    //For now create an empty list for reporting_conditions
    //TODO: Use Reporting conditions from provisioning session once it is implemented

    reporting_conditions = OpenAPI_list_create();
    ogs_assert(reporting_conditions);

    data_reporting_session->reporting_conditions = reporting_conditions;

    valid_until = ogs_sbi_gmtime_string(data_collection_reporting_session->valid_until);

    data_collection_reporting_session->data_reporting_session->valid_until = valid_until;

    data_collection_reporting_session->hash = calculate_data_reporting_session_hash(data_collection_reporting_session->data_reporting_session);

    return data_collection_reporting_session;
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
