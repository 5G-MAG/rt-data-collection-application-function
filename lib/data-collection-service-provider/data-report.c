/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "data-collection-sp/data-collection.h"

#include "context.h"
#include "hash.h"
#include "event-subscription.h"
#include "timer.h"
#include "utilities.h"
#include "data-reporting.h"
#include "data-report.h"
#include "data-report-record.h"
#include "data-report-store.h"
#include "data-reporting-provisioning.h"

#ifdef __cplusplus
extern "C" {
#endif

/********* Private data types *********/

typedef struct data_report_s {
    ogs_lnode_t node;
    cJSON *data_report;
} data_report_t;

typedef struct ue_user_id_s {
    ogs_lnode_t node;
    char *user_id;
} ue_user_id_t;

typedef struct data_report_hash_record_s{
    const data_collection_data_report_handler_t *handler;
    ogs_list_t list;
} data_report_hash_record_t;

typedef struct data_report_handler_aggregation_functions_s {
    const data_collection_data_report_handler_t *handler;	
    data_collection_data_report_record_t *data_record;
    ogs_list_t *aggregation_functions;
} data_report_handler_aggregation_functions_t;
	
/********* Private function prototypes *********/

static data_collection_data_report_property_e __data_report_handler_report_property(const data_collection_data_report_handler_t *handler);
static data_collection_data_report_property_e __data_domain_to_data_report_property(const char *data_domain);

static data_collection_data_report_property_e __get_report_properties(data_collection_model_data_report_t *report, ogs_list_t *data_reports);
static ogs_list_t *__get_data_reports_allowed_for_event_subscription(const data_collection_data_report_handler_t* const *handlers, data_collection_event_subscription_t *event_subscription, bool omit_used);
static int __data_collection_report_destroy_expired(ogs_list_t *data_reports);
static ogs_list_t *__apply_aggregation(ogs_list_t *data_reports);
static void __data_report_handler_aggregation_functions_remove(data_report_handler_aggregation_functions_t *aggregation_functions);
static void __populate_communication_records (data_collection_model_data_report_t *report, ogs_list_t *data_reports);
static int __free_local_data_report_records(ogs_list_t *data_report_records);

/******** Public API ********/

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_report(data_collection_reporting_session_t *session, const char *mime_type, const void *data, 
		size_t data_length, char **error_return, char **error_classname, char **error_parameter, const char **error_code) {
    cJSON *data_report;
    data_collection_model_data_report_t *report;
    int i = 0;
    data_collection_data_report_property_e found_property;
    ogs_list_t data_reports;
    char *external_application_id;

    if (error_return) *error_return = NULL;
    if (error_classname) *error_classname = NULL;
    if (error_parameter) *error_parameter = NULL;
    if (error_code) *error_code = NULL;

    if(strcmp(mime_type,"application/json")){
        if (error_return) *error_return = "MIME type is not JSON";
	if (error_code) *error_code = "415";
        return OGS_ERROR;
    }

    data_report = cJSON_Parse(data);

    if (!data_report) {
	ogs_debug("Unable to parse Data Reporting Session as JSON.");
	if (error_return) *error_return = "Unable to parse Data Reporting Session as JSON.";
	if (error_code) *error_code = "400";
	return OGS_ERROR;
    }

    {
        char *txt = cJSON_Print(data_report);
        ogs_debug("Parsed JSON: %s", txt);
        cJSON_free(txt);
    }

    cJSON *external_application_id_node = cJSON_GetObjectItemCaseSensitive(data_report, "externalApplicationId");
    if (external_application_id_node) {
        if (!cJSON_IsString(external_application_id_node)) {
            if (error_return) *error_return = dcaf_strdup("Field \"externalApplicationId\" is not a string");
            if (error_parameter) *error_parameter = dcaf_strdup("externalApplicationId");
            if (error_code) *error_code = "400";
            return OGS_ERROR;
        }
        external_application_id = data_collection_strdup(external_application_id_node->valuestring);
    }

    
    report = data_collection_model_data_report_fromJSON(data_report, true, error_return, error_classname, error_parameter);
    cJSON_Delete(data_report);
    if (!report) {
        ogs_error("%s: %s (%s)", error_classname?*error_classname:"<null>", error_return?*error_return:"<null>", error_parameter?*error_parameter:"<null>");
        if (error_code) *error_code = "400";
        return OGS_ERROR;
    }
    
    ogs_list_init(&data_reports);
    found_property = __get_report_properties(report, &data_reports);

    data_collection_model_data_report_free(report);

    data_collection_data_report_handler_t **handlers = (data_collection_data_report_handler_t **)data_collection_self()->config.data_collection_configuration->data_report_handlers;
    
    if (!handlers[i]) {
        ogs_error("Report not understood");
        if (error_return) *error_return = "Report not understood";
        return OGS_ERROR;
    }

    for (i = 0; handlers[i]; i++) {
        if(__data_report_handler_report_property(handlers[i])  == found_property) {
            data_report_t *rep;
            ogs_list_for_each(&data_reports, rep) {
                void *parsed_data = handlers[i]->parse_report_data(session, rep->data_report /* cJSON * to the actual report */, error_return, error_classname, error_parameter);
                if(parsed_data) {
                    data_collection_data_report_record_new(session, handlers[i], parsed_data, external_application_id);
                } else {
                    ogs_error("Report not understood at %s.%s: %s", error_classname?*error_classname:"<null>", error_parameter?*error_parameter:"<null>", error_return?*error_return:"<null>");
                    if (error_code) *error_code = "400";
                    return OGS_ERROR;
                }
            }

        }
    }
    if(external_application_id) ogs_free(external_application_id);
    //cJSON_Delete(external_application_id_node);
    __free_local_data_report_records(&data_reports);

    
    return OGS_OK;
}

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_report_find(const data_collection_data_report_handler_t* const *report_handlers, 
		data_collection_event_subscription_t *event_subscription, bool omit_used) {

    ogs_assert(event_subscription);
    ogs_list_t *data_reports_allowed = NULL;
    ogs_list_t *data_reports_aggregated = NULL;

    data_reports_allowed =  __get_data_reports_allowed_for_event_subscription(report_handlers, event_subscription, omit_used);
    if(!data_reports_allowed) return NULL;
    data_reports_aggregated = __apply_aggregation(data_reports_allowed);
    //return data_reports_allowed;
   if(!data_reports_aggregated) {
       return data_reports_allowed;
   } else {
       data_collection_data_report_record_t *data_rep = NULL, *data_report_node = NULL;
       ogs_list_for_each_safe(data_reports_allowed, data_rep, data_report_node) {
           ogs_list_remove(data_reports_allowed, data_report_node);
           if(data_report_node->external_application_id) ogs_free(data_report_node->external_application_id);
           /*
	   data_report_node->data_report_handler->free_report_data(data_report_node->data_report_record);
           data_report_node->data_report_record = NULL;
           */
           ogs_free(data_report_node);
        }
        ogs_free(data_reports_allowed);
   }

   return data_reports_aggregated;
}

/******** Internal library API *********/

void data_report_event_subscriptions_remove_all(ogs_list_t *event_subscriptions)
{
    data_collection_list_free(event_subscriptions);
}

bool remove_expired_data_reports(ogs_hash_t *data_reports)
{
    ogs_hash_index_t *it;

    if (!data_reports) return false;

    ogs_debug("remove_expired_data_reports(%p) [%i types]", data_reports, ogs_hash_count(data_reports));
    for (it = ogs_hash_first(data_reports); it; it = ogs_hash_next(it)) {
        const data_collection_data_report_handler_t *key;
        int key_len;
        data_report_hash_record_t *data_hash_record;
	ogs_list_t *data_report;
	int rv;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&data_hash_record));
        data_report = &data_hash_record->list;
        ogs_debug("clear %p[%i]: %p", key, key_len, data_report);
	rv = __data_collection_report_destroy_expired(data_report);
	if (!rv) {
            ogs_hash_set(data_reports, key, key_len, NULL);
            data_report_hash_record_free(data_hash_record);
        }
    }
    ogs_debug("Data Report types after removing the expired reports = %i", ogs_hash_count(data_reports));

    return true;
}

data_collection_reporting_client_type_e _report_client_type_from_ogs_server(ogs_sbi_server_t *server)
{
    size_t i;
    int data_report_server;

    static const struct {
        int server_ifc;
	data_collection_reporting_client_type_e client_type;
    } server_ifc_client_type[] = {{DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, DATA_COLLECTION_REPORTING_CLIENT_TYPE_DIRECT}, 
	    {DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING, DATA_COLLECTION_REPORTING_CLIENT_TYPE_INDIRECT},
	    {DATA_COLLECTION_SVR_AS_DATA_REPORTING, DATA_COLLECTION_REPORTING_CLIENT_TYPE_APPLICATION_SERVER}
    };

    data_report_server = data_collection_context_get_server_interface(server);
    for (i=0; i<sizeof(server_ifc_client_type)/sizeof(server_ifc_client_type[0]); i++) {
        if (server_ifc_client_type[i].server_ifc == data_report_server) return server_ifc_client_type[i].client_type;	    
    }
    return (data_collection_reporting_client_type_e)-1;
}

bool data_report_handler_valid_aggregation_function(const data_collection_data_report_handler_t *handler, const char *aggregation_name)
{
    int i =0; 
    char **handler_aggregations = (char **)handler->applicable_aggregations;
    
    if (!handler_aggregations[i]) {
        return false;
    }   

    for (i = 0; handler_aggregations[i]; i++) {
        if(!strcmp(handler_aggregations[i], aggregation_name)) return true;	    
    }
    return false;
}

void data_report_hash_record_free(data_report_hash_record_t *report_hash_record) {
    if(!report_hash_record) return;
    data_collection_report_remove(report_hash_record);
    ogs_free(report_hash_record);
}

int data_collection_report_remove(data_report_hash_record_t *report_hash_record)
{
    data_collection_data_report_record_t *data_report = NULL, *data_report_node = NULL;

    ogs_list_for_each_safe(&report_hash_record->list, data_report, data_report_node) {
        ogs_list_remove(&report_hash_record->list, data_report_node);
        data_collection_data_report_record_destroy(data_report_node);
    }
    return 1;
}

/******** Private functions ***********/

static int __data_collection_report_destroy_expired(ogs_list_t *data_reports)
{
    data_collection_data_report_record_t *data_report_next, *data_report;
    const ogs_time_t current_time = ogs_time_now();

    if (!data_reports) return 0;

    ogs_list_for_each_safe(data_reports, data_report_next, data_report) {
	if (data_report->expired || (current_time >= data_report->last_used +  
	                             (3*ogs_time_from_sec(
                 data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age
                                     )))) {    
            ogs_list_remove(data_reports, data_report);
            data_collection_data_report_record_destroy(data_report);
	}
    }
    /* free the list if empty 
    if(!ogs_list_first(data_reports)) { 
        ogs_free(data_reports);
	return 0;
    }
    */
    /* list still has entries */
    return 1;
}

static ogs_list_t *__get_data_reports_allowed_for_event_subscription(const data_collection_data_report_handler_t* const *handlers, data_collection_event_subscription_t *event_subscription, bool omit_used)
{
    size_t i;
    data_collection_data_report_record_t *data_report;
    const data_collection_data_report_handler_t **allowed_handlers = NULL;
    ogs_list_t *data_reports_allowed = NULL;
    ogs_list_t *events_subs = NULL;

    data_reports_allowed = (ogs_list_t*)ogs_calloc(1,sizeof(*data_reports_allowed));
    ogs_assert(data_reports_allowed);
    ogs_list_init(data_reports_allowed);

    const data_collection_model_af_event_exposure_subsc_t *af_event_subsc =
                data_collection_event_subscription_get_af_event_exposure_subsc(event_subscription);
    events_subs = data_collection_model_af_event_exposure_subsc_get_events_subs(af_event_subsc);

    if (!handlers) {
        //const data_collection_data_report_handler_t *drh;
        const data_collection_data_report_handler_t * const *registered_handlers = data_collection_self()->config.data_collection_configuration->data_report_handlers;
        size_t handlers_found = 0;

        for (i = 0; registered_handlers[i]; i++) {
            data_collection_lnode_t *node;
            const char *reg_event_type = registered_handlers[i]->event_type;

            ogs_list_for_each(events_subs, node) {
                const data_collection_model_events_subs_t *evt_subs = node->object;
                const data_collection_model_af_event_t *evt_type = data_collection_model_events_subs_get_event(evt_subs);
                if (!strcmp(data_collection_model_af_event_get_string(evt_type), reg_event_type)) {
                    /* found appropriate data handler */
                    allowed_handlers = ogs_realloc(allowed_handlers, sizeof(*allowed_handlers) * (handlers_found + 1));
                    allowed_handlers[handlers_found] = registered_handlers[i];
                    handlers_found++;
                    break;
                }
            }
        }
	
	allowed_handlers = ogs_realloc(allowed_handlers, sizeof(*allowed_handlers) * (handlers_found + 1));
        allowed_handlers[handlers_found] = NULL;

        handlers = allowed_handlers;
    }

    for (i = 0; handlers[i]; i++) {
        data_collection_lnode_t *node;
        const char *event_type = handlers[i]->event_type;
	data_report_hash_record_t *data_reports;

	data_reports = (data_report_hash_record_t *)ogs_hash_get(data_collection_self()->data_reports, handlers+i, sizeof(handlers[i]));
       
       	if(!data_reports || !ogs_list_first(&data_reports->list)) {
            if (events_subs) data_collection_list_free(events_subs);
            if (allowed_handlers) ogs_free(allowed_handlers);
	    if (data_reports_allowed) ogs_free(data_reports_allowed);
            return NULL;
        }

	ogs_list_for_each(&data_reports->list, data_report) {
            if(omit_used) {
                if(_data_report_record_is_event_subscription_used(data_report, event_subscription))
                    continue;
            }
            ogs_list_for_each(events_subs, node) {
                const data_collection_model_events_subs_t *evt_subs = node->object;
                const data_collection_model_af_event_t *evt_type = data_collection_model_events_subs_get_event(evt_subs);
                //TODO: Add extra filters
		if (!strcmp(data_collection_model_af_event_get_string(evt_type), event_type) /* && __check_for_user_ids(evt_subs, data_report, event_type)*/) {
                    data_collection_data_report_record_t *temp_report_record = data_collection_data_report_record_copy(data_report);
		    ogs_list_add(data_reports_allowed, temp_report_record);
                    break;
                }
            }
	}
    }
    if (events_subs) data_collection_list_free(events_subs);
    if (allowed_handlers) ogs_free(allowed_handlers);
    return data_reports_allowed;
}

static ogs_list_t *__apply_aggregation(ogs_list_t *data_records) {
    data_collection_data_report_record_t *data_record;
    data_report_handler_aggregation_functions_t *data_report_handler_aggregation_functions;
    data_report_handler_aggregation_functions_t *data_report_handler_aggregation;
    ogs_hash_t *handlers = ogs_hash_make();
    ogs_hash_index_t *it;
    ogs_list_t *data_records_aggregated = NULL;
    ogs_list_t *aggregation_functions = NULL;
    
    ogs_list_for_each(data_records, data_record) {
	const char *external_application_id;    
	const char *event_type = data_record->data_report_handler->event_type;

	data_collection_model_data_report_t *report = (data_collection_model_data_report_t *)data_record->data_report_record;
        external_application_id = data_collection_model_data_report_get_external_application_id(report);
	
	aggregation_functions = (ogs_list_t*) ogs_calloc(1,sizeof(*aggregation_functions));
        ogs_assert(aggregation_functions);
        ogs_list_init(aggregation_functions);

        data_collection_provisioning_configurations_aggregations_functions_get(external_application_id, event_type, data_record->context_ids, aggregation_functions);
        if(!ogs_list_first(aggregation_functions)) {
            data_collection_list_free(aggregation_functions);
            data_collection_hash_free(handlers, (void(*)(void*))__data_report_handler_aggregation_functions_remove);
            return NULL;
        }
        data_report_handler_aggregation_functions = ogs_calloc(1, sizeof(data_report_handler_aggregation_functions_t));
	ogs_assert(data_report_handler_aggregation_functions);
	data_report_handler_aggregation_functions->handler = data_record->data_report_handler;
        data_report_handler_aggregation_functions->data_record = data_record;
        data_report_handler_aggregation_functions->aggregation_functions = aggregation_functions;
	ogs_hash_set(handlers, &data_record->data_report_handler, sizeof(data_collection_data_report_handler_t*), data_report_handler_aggregation_functions);

    }

    {
        for (it = ogs_hash_first(handlers); it; it = ogs_hash_next(it)) {
            const char *key;
            int key_len;
	    data_collection_lnode_t *node;

            ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&data_report_handler_aggregation));
	    ogs_list_for_each(data_report_handler_aggregation->aggregation_functions, node) {
	        char *function_name = node->object;
		ogs_list_t *temp_data_records_aggregated = data_report_handler_aggregation->handler->apply_aggregation(function_name, data_records);
	        if(temp_data_records_aggregated) {
                    if( ogs_list_last(temp_data_records_aggregated)) {
                        if(ogs_list_last(data_records_aggregated)) {
                            data_records_aggregated->prev->next = temp_data_records_aggregated->next;
                            temp_data_records_aggregated->next->prev = data_records_aggregated->prev;
                        } else {
                            data_records_aggregated->next = temp_data_records_aggregated->next;
                        }
                        data_records_aggregated->prev = temp_data_records_aggregated->prev;
                    }
                    ogs_free(temp_data_records_aggregated);
                }

	    }
	}
	//data_collection_list_free(aggregation_functions);
	//aggregation_functions =  NULL;
	data_collection_hash_free(handlers, (void(*)(void*))__data_report_handler_aggregation_functions_remove);


	return data_records_aggregated;
    }
   /* 
    if(ogs_list_count(aggregation_functions)) {
       data_collection_lnode_t *node;	    
       ogs_list_for_each(aggregation_functions, node) {
           char *function_name = node->object;
	   handler->apply_aggregation(function_name, data_records);


       }	       
    }
    */

}

static void __data_report_handler_aggregation_functions_remove(data_report_handler_aggregation_functions_t *data_report_handler_aggregation_functions)
{
    if(data_report_handler_aggregation_functions->aggregation_functions)  data_collection_list_free(data_report_handler_aggregation_functions->aggregation_functions);
    if(data_report_handler_aggregation_functions) ogs_free(data_report_handler_aggregation_functions);
}

static data_collection_data_report_property_e __get_report_properties(data_collection_model_data_report_t *report, ogs_list_t *data_reports)
{
    ogs_list_t *ret = NULL;
    
    static const struct {
        ogs_list_t *(*property_fn)(const data_collection_model_data_report_t *report);
        data_collection_data_report_property_e property_enum;
    } properties[] = {
        {data_collection_model_data_report_get_application_specific_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC},
        {data_collection_model_data_report_get_communication_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION},
        {data_collection_model_data_report_get_location_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION},
        {data_collection_model_data_report_get_media_streaming_access_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS},
        {data_collection_model_data_report_get_performance_data_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE},
        {data_collection_model_data_report_get_service_experience_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE},
        {data_collection_model_data_report_get_trip_plan_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN}
    };
    size_t i;

    for (i = 0; i < sizeof(properties)/sizeof(properties[0]); i++) {
        ret = properties[i].property_fn(report);
        if (ret) {
	    if(properties[i].property_enum == DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION) __populate_communication_records(report, data_reports);	
	    data_collection_list_free(ret);
	    return properties[i].property_enum;
	}
    }

    return (data_collection_data_report_property_e)-1;
}

static void __populate_communication_records (data_collection_model_data_report_t *report, ogs_list_t *data_reports) {

    data_report_t *data_report;
    ogs_list_t *communication_list;
    data_collection_lnode_t *communication_record_node;

    if (data_collection_model_data_report_has_communication_records(report)) {
        communication_list = data_collection_model_data_report_get_communication_records(report);
        ogs_list_for_each(communication_list, communication_record_node) {
            cJSON *itemLocal = data_collection_model_data_report_toJSON(communication_record_node->object, true);
            if (itemLocal == NULL) {
                ogs_error("data_collection_model_data_report_toJSON() failed [communication_records]");
                return;
            }
            data_report = ogs_calloc(1, sizeof(data_report_t));
            ogs_assert(data_report);
            data_report->data_report = itemLocal;
            ogs_list_add(data_reports, data_report);

        }

    }
    data_collection_list_free(communication_list);
}

static data_collection_data_report_property_e __data_report_handler_report_property(const data_collection_data_report_handler_t *handler)
{
    if (handler->data_report_property) return handler->data_report_property;
    return __data_domain_to_data_report_property(handler->data_domain);
}

static data_collection_data_report_property_e __data_domain_to_data_report_property(const char *data_domain)
{
    SWITCH(data_domain)
    CASE("APPLICATION_SPECIFIC")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC;
    CASE("COMMUNICATION")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION;
    CASE("LOCATION")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION;
    CASE("MS_ACCESS_ACTIVITY")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS;
    CASE("PERFORMANCE")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE;
    CASE("SERVICE_EXPERIENCE")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE;
    CASE("PLANNED_TRIPS")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN;
    END
    return 0;
}

static int __free_local_data_report_records(ogs_list_t *data_report_records) {
    data_report_t *data_report = NULL, *data_report_node = NULL;
    ogs_list_for_each_safe(data_report_records, data_report, data_report_node) {
        ogs_list_remove(data_report_records, data_report_node);
        cJSON_Delete(data_report_node->data_report);
        ogs_free(data_report_node);
    }
    return 1;

}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
