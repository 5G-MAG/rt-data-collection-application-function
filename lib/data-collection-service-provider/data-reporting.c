/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation
    
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "utilities.h"
#include "hash.h"
#include "data-reporting.h"

static char *calculate_data_reporting_session_hash(dc_api_data_reporting_session_t *data_reporting_session);
static void supported_domains_remove_all(data_domain_list_t *supported_domains);

data_collection_reporting_session_t *data_collection_reporting_session_create(const char *external_app_id, const data_domain_list_t *supported_domains)
{
    ogs_info("In data_collection_reporting_session_create");
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];
    ogs_time_t valid;
    char *valid_until;
    data_collection_reporting_session_t *data_collection_reporting_session;

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    data_collection_reporting_session = ogs_calloc(1, sizeof(data_collection_reporting_session_t));
    if(!data_collection_reporting_session)
        return NULL;	    

    data_collection_reporting_session->data_reporting_session_id = data_collection_strdup(id);

    data_collection_reporting_session->external_application_id = data_collection_strdup(external_app_id);

    data_collection_reporting_session->supported_domains = supported_domains;

    valid = ogs_time_now() + ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age);

    valid_until = ogs_msprintf("%ld", valid);

    data_collection_reporting_session->valid_until = data_collection_strdup(valid_until);

    data_collection_reporting_session->received = time(NULL);

    ogs_list_add(&data_collection_self()->data_reporting_sessions, data_collection_reporting_session);

    ogs_free(valid_until);
    
    return data_collection_reporting_session;
}

data_collection_reporting_session_t *data_reporting_session_populate(data_collection_reporting_session_t *data_collection_reporting_session, dc_api_data_reporting_session_t *data_reporting_session){

    OpenAPI_list_t* reporting_conditions;
    char *valid_until;

    data_collection_reporting_session->data_reporting_session = data_reporting_session;
    data_collection_reporting_session->data_reporting_session->session_id = data_collection_strdup(data_collection_reporting_session->data_reporting_session_id);

    //Reporting conditions are provided through the provisioning session
    //For now create an empty list for reporting_conditions
    //TO DO: Use Reporting conditions from provisioning session once it is implemented

    reporting_conditions = OpenAPI_list_create();
    ogs_assert(reporting_conditions);

   data_reporting_session->reporting_conditions = reporting_conditions;

   valid_until = epoch_to_datetime(data_collection_reporting_session->valid_until);

   data_collection_reporting_session->data_reporting_session->valid_until = data_collection_strdup(valid_until);

   data_collection_reporting_session->hash = calculate_data_reporting_session_hash(data_collection_reporting_session->data_reporting_session);

   return data_collection_reporting_session;

}

void data_collection_reporting_session_destroy(data_collection_reporting_session_t *session) {

    ogs_assert(session);
    if(session->external_application_id) ogs_free(session->external_application_id);
    if(session->data_reporting_session_id) ogs_free(session->data_reporting_session_id);
    if(session->supported_domains) {
        supported_domains_remove_all(session->supported_domains);
        ogs_free(session->supported_domains);
	session->supported_domains = NULL;
    }
    if(session->hash) ogs_free(session->hash);
    if(session->valid_until) ogs_free(session->valid_until);
    if(session->data_reporting_session)  dc_api_data_reporting_session_free(session->data_reporting_session);
    ogs_free(session);
    session = NULL;


}

data_collection_reporting_session_t *data_collection_reporting_session_find(const char *session_id){

    data_collection_reporting_session_t *session = NULL;
    ogs_list_for_each(&data_collection_self()->data_reporting_sessions, session)
    {
        if(!strcmp(session->data_reporting_session_id, session_id))
            break;
    }
    if(session)
        return session;

    return NULL;

}

cJSON *data_collection_reporting_session_json(const data_collection_reporting_session_t *session){
 
    if(!session || !session->data_reporting_session) return NULL; 	
    return dc_api_data_reporting_session_convertResponseToJSON(session->data_reporting_session);	
}

const char *data_collection_reporting_session_get_id(const data_collection_reporting_session_t *session){

    data_collection_reporting_session_t *data_reporting_session = NULL;
    ogs_list_for_each(&data_collection_self()->data_reporting_sessions, data_reporting_session)
    {
        if(data_reporting_session == session) break;	    

    }
    if(data_reporting_session)
        return (const char *)data_reporting_session->data_reporting_session_id;	    
    return NULL;
}



static void supported_domains_remove_all(data_domain_list_t *supported_domains){

    data_domain_node_t *supported_domain;
    data_domain_node_t *supported_domain_node = NULL;

    ogs_assert(supported_domains);
    ogs_list_for_each_safe(supported_domains, supported_domain_node, supported_domain) {
        ogs_list_remove(supported_domains, supported_domain);
        if(supported_domain->data_domain) ogs_free(supported_domain->data_domain);
//      if(supported_domain->node) ogs_free(supported_domain->node);
        ogs_free(supported_domain);

    }

}

static char *calculate_data_reporting_session_hash(dc_api_data_reporting_session_t *data_reporting_session)
{
    cJSON *data_reporting_sess = NULL;
    char *data_reporting_session_to_hash;
    char *data_reporting_session_hashed = NULL;
    data_reporting_sess = dc_api_data_reporting_session_convertResponseToJSON(data_reporting_session);
    data_reporting_session_to_hash = cJSON_Print(data_reporting_sess);
    cJSON_Delete(data_reporting_sess);
    data_reporting_session_hashed = calculate_hash(data_reporting_session_to_hash);
    cJSON_free(data_reporting_session_to_hash);
    return data_reporting_session_hashed;
}

