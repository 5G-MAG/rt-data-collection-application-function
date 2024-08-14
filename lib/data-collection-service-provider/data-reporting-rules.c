/*
 * License: 5G-MAG Public License (v1.0)
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

#include "data-reporting-rules.h"
#include "data-reporting.h"

#ifdef __cplusplus
extern "C" {
#endif

/******* Local prototypes ********/

static void __data_collection_adjust_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t *configurations, ogs_list_t *data_reporting_session_reporting_rules_data_domain, const char *data_domain, data_collection_reporting_client_type_e client_type);
static void __adjust_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *configuration_reporting_rules, const char *configuration_id, ogs_list_t *data_reporting_session_reporting_rules_data_domain, const char *data_domain);

/******* Private structures ********/

/******* Library API ********/

/******* Library internal functions ********/

void data_collection_adjust_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *data_reporting_session_reporting_rules_data_domain, const char *external_application_id, const char *event_type, const char *data_domain, data_collection_reporting_client_type_e client_type)
{
    ogs_hash_index_t *it;
    ogs_hash_t *data_reporting_provisioning_session = data_collection_self()->data_reporting_provisioning_sessions;
    data_collection_reporting_provisioning_session_t *session;
    for (it = ogs_hash_first(data_reporting_provisioning_session); it; it = ogs_hash_next(it)) {
        const char *key;
        int key_len;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&session));

	const char *external_app_id = data_collection_reporting_provisioning_session_external_application_id(session);

	const char *af_event_type = data_collection_reporting_provisioning_session_get_af_event_type(session);

        if(af_event_type && external_app_id && !strcmp(af_event_type, event_type) && !strcmp(external_app_id, external_application_id)) {
	    ogs_hash_t *configurations;
	    configurations = data_collection_reporting_provisioning_session_get_configurations(session);
	     __data_collection_adjust_reporting_rules(data_reporting_session, configurations, data_reporting_session_reporting_rules_data_domain, data_domain, client_type);
        }
    }

}


/******* Local private functions ********/

static void __data_collection_adjust_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t *configurations, ogs_list_t *data_reporting_session_reporting_rules_data_domain, const char *data_domain, data_collection_reporting_client_type_e client_type)
{

    ogs_hash_index_t *it;
    data_collection_reporting_configuration_t *configuration;
    for (it = ogs_hash_first(configurations); it; it = ogs_hash_next(it)) {
        const char *key;
        int key_len;
	data_collection_model_data_collection_client_type_t *configuration_client_type = NULL;
	data_collection_model_data_collection_client_type_e config_client_type;
	const char *configuration_id = NULL;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&configuration));
        const data_collection_model_data_reporting_configuration_t *data_report_config =
            data_collection_reporting_configuration_model(configuration);
	configuration_client_type = data_collection_model_data_reporting_configuration_get_data_collection_client_type(data_report_config);
        config_client_type =  data_collection_model_data_collection_client_type_get_enum(configuration_client_type);
	if(config_client_type == client_type) {
	    ogs_list_t *config_reporting_rules;	
	    config_reporting_rules = data_collection_model_data_reporting_configuration_get_data_reporting_rules(data_report_config);
            if(config_reporting_rules) {
		configuration_id = data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(data_report_config);
    
	        __adjust_reporting_rules(data_reporting_session, config_reporting_rules, configuration_id, data_reporting_session_reporting_rules_data_domain, data_domain);	    
                
	    }	    
	}
    }

}

static void __adjust_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *configuration_reporting_rules, const char *configuration_id, ogs_list_t *data_reporting_session_reporting_rules_data_domain, const char *data_domain)
{
    data_collection_lnode_t *configuration_reporting_rule_node;
    data_collection_lnode_t *data_reporting_session_reporting_rule_node;
    ogs_hash_index_t *it;

    ogs_list_for_each(configuration_reporting_rules, configuration_reporting_rule_node) {
        data_collection_lnode_t *data_reporting_session_reporting_rule;
        data_collection_model_data_reporting_rule_t *config_reporting_rule = configuration_reporting_rule_node->object;
	
        ogs_list_for_each(data_reporting_session_reporting_rules_data_domain, data_reporting_session_reporting_rule_node) {
	    data_collection_model_data_reporting_rule_t *data_reporting_session_reporting_rule = data_reporting_session_reporting_rule_node->object;    

	    if(data_collection_model_data_reporting_rule_is_equal_to(config_reporting_rule, data_reporting_session_reporting_rule)) {
	        data_collection_model_data_reporting_rule_add_context_ids(data_reporting_session_reporting_rule, data_collection_strdup(configuration_id));	    
	        	    
	    } else {
		data_collection_lnode_t *data_reporting_session_reporting_rule_node;
		data_collection_model_data_reporting_rule_add_context_ids(config_reporting_rule, data_collection_strdup(configuration_id));    
		data_reporting_session_reporting_rule_node = data_collection_model_data_reporting_rule_make_lnode(config_reporting_rule);
		ogs_list_add(data_reporting_session_reporting_rules_data_domain, data_reporting_session_reporting_rule_node);
		data_collection_reporting_session_add_reporting_rules(data_reporting_session, data_domain, data_reporting_session_reporting_rules_data_domain);
	    }
	}

    }
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
