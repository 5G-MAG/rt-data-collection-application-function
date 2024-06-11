/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "openapi/model/dc_api_data_report.h"
#include "openapi/model/dc_api_events_subs.h"
#include "openapi/model/dc_api_af_event.h"
#include "data-collection-sp/data-collection.h"
#include "data-collection-sp/data-reporting.h"
#include "context.h"
#include "hash.h"
#include "event-subscription.h"
#include "timer.h"
#include "utilities.h"
#include "data-reporting.h"
#include "data-report.h"
#include "data-report-store.h"
#include "data-reporting-configuration.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_report_s {
    ogs_lnode_t node;
    cJSON *data_report;
} data_report_t;
	
static data_collection_data_report_property_e get_report_properties(dc_api_data_report_t *report, ogs_list_t *data_reports);
static void populate_communication_records (dc_api_data_report_t *report, ogs_list_t *data_reports);
static data_collection_data_report_property_e __data_report_handler_report_property(const data_collection_data_report_handler_t *handler);
static data_collection_data_report_property_e __data_domain_to_data_report_property(const char *data_domain);

static data_collection_data_report_t *data_collection_report_create(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *handler, void *data_report);	
static bool data_report_del(ogs_hash_t *data_reports, const char *data_report_type);
static int free_ogs_hash_data_report(void *rec, const void *key, int klen, const void *value);
static data_collection_data_report_property_e get_report_properties(dc_api_data_report_t *report, ogs_list_t *data_reports);
static void populate_communication_records (dc_api_data_report_t *report, ogs_list_t *data_reports);
static cJSON *data_collection_report_json(data_collection_data_report_t *report, cJSON *data_report_json);
static void data_reports_timer_activate(void);
static  ogs_list_t *get_data_reports_allowed_for_event_subscription(const data_collection_data_report_handler_t* const *handlers, data_collection_event_subscription_t *event_subscription, bool omit_used);
static bool is_event_subscription_used(data_collection_data_report_t *data_report, data_collection_event_subscription_t *event_subscription);
static void data_collection_report_destroy_all(ogs_list_t *data_reports);
static int data_collection_report_destroy_expired(ogs_list_t *data_reports);
static char *check_for_user_ids(data_collection_af_events_subscription_t *events_subscription, data_collection_data_report_t *data_report, char *event_type);
static char *check_for_user_ids_from_reporting_provisioning_session_in_event_filter(OpenAPI_list_t *user_identifiers, data_collection_af_events_subscription_t *events_subscription);

int data_collection_reporting_report(data_collection_reporting_session_t *session, const char *mime_type, const void *data, 
		size_t data_length, const char **error_return, const char **error_code) {
    
    cJSON *data_report;
    dc_api_data_report_t *report;
    int i = 0;
    data_collection_data_report_property_e found_property;
    ogs_list_t data_reports;

    if (error_return) *error_return = NULL;
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
    
    report = dc_api_data_report_parseRequestFromJSON(data_report, error_return);
    
    ogs_list_init(&data_reports);
    found_property = get_report_properties(report, &data_reports);

    data_collection_data_report_handler_t **handlers = (data_collection_data_report_handler_t **)data_collection_self()->config.data_collection_configuration->data_report_handlers;
    
    if(!handlers[i]) {
        ogs_error("Report not understood");
        if (error_return) *error_return = "Report not understood";
        return OGS_ERROR;
    }

    for (i = 0; handlers[i]; i++) {
        if(__data_report_handler_report_property(handlers[i])  == found_property) {
            data_report_t *rep = NULL;
            ogs_list_for_each(&data_reports, rep) {
                void *parsed_data = handlers[i]->parse_report_data(session, rep->data_report /* cJSON * to the actual report */, error_return);
                if(parsed_data) {
		    data_collection_data_report_t *data_collection_data_report;	
                    data_collection_data_report = data_collection_report_create(session, handlers[i], parsed_data);
                } else {
                    ogs_error("Report not understood");
                    if (error_return) *error_return = "Report not understood";
                    return OGS_ERROR;
                }
            }

        }
    }


    cJSON_Delete(data_report);
    
    return OGS_OK;
}

int data_collection_reporting_report_used(data_collection_data_report_t *data_collection_report, data_collection_event_subscription_t *data_collection_event_subscription) {
 
    if(!ogs_list_first(&data_collection_report->usage)) ogs_list_init(&data_collection_report->usage);

    ogs_list_add(&data_collection_report->usage, data_collection_event_subscription);
    return 1;

}

ogs_list_t *data_collection_reporting_report_find(const data_collection_data_report_handler_t* const *report_handlers, 
		data_collection_event_subscription_t *event_subscription, bool omit_used) {

    ogs_assert(event_subscription);
    ogs_list_t *data_reports_allowed = NULL;

    data_reports_allowed =  get_data_reports_allowed_for_event_subscription(report_handlers, event_subscription, omit_used);
    return data_reports_allowed;
}

void data_report_event_subscriptions_remove_all(ogs_list_t *event_subscriptions)
{
    data_collection_event_subscription_t *event_subscription = NULL;
    data_collection_event_subscription_t *event_subsc = NULL;

    if (!event_subscriptions) return;

    ogs_list_for_each_safe(event_subscriptions, event_subsc, event_subscription) {
        ogs_list_remove(event_subscriptions, event_subscription);
        ogs_free(event_subscription);
    }
}


int data_collection_reporting_report_expire(data_collection_data_report_t *data_collection_report) {

    if(!data_collection_report) return 0;
    data_collection_report->expired = true;
    return 1;
}

bool remove_expired_data_reports(ogs_hash_t *data_reports)
{
    ogs_hash_index_t *it;

    if (!data_reports) return false;

    ogs_debug("remove_expired_data_reports(%p) [%i entries]", data_reports, ogs_hash_count(data_reports));
    for (it = ogs_hash_first(data_reports); it; it = ogs_hash_next(it)) {
        const data_collection_data_report_handler_t *key;
        int key_len;
	ogs_list_t *data_report;
	int rv;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&data_report));
        ogs_debug("clear %p[%i]: %p", key, key_len, data_report);
	rv = data_collection_report_destroy_expired(data_report);
	if(!rv) ogs_hash_set(data_reports, key, key_len, NULL);
    }
    ogs_debug("Data Reports after removing the expired reports = %i", ogs_hash_count(data_reports));

    return true;
}

bool data_reports_clear(ogs_hash_t *data_reports)
{
    ogs_hash_index_t *it;

    if (!data_reports) return false;

    ogs_debug("data_reports_clear(%p) [%i entries]", data_reports, ogs_hash_count(data_reports));
    for (it = ogs_hash_first(data_reports); it; it = ogs_hash_next(it)) {
        const data_collection_data_report_handler_t *key;
        int key_len;
	ogs_list_t *data_report;
	int rv;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&data_report));
        ogs_debug("clear %p[%i]: %p", key, key_len, data_report);
	rv = data_collection_report_destroy_expired(data_report);
        if(!rv) ogs_hash_set(data_reports, key, key_len, NULL);
    }
    ogs_debug("Data Reports after removing the out of date reports = %i", ogs_hash_count(data_reports));

    return true;
}

static void data_collection_report_destroy_all(ogs_list_t *data_reports)
{
    data_collection_data_report_t *data_report = NULL;
    data_collection_data_report_t *data_report_node = NULL;

    if (!data_reports) return;

    ogs_list_for_each_safe(data_reports, data_report_node, data_report) {
        ogs_list_remove(data_reports, data_report);
	data_collection_report_destroy(data_report);
    }
    ogs_free(data_reports);
}

void data_collection_report_destroy(data_collection_data_report_t *report)
{
    ogs_assert(report);

    if (report->hash) {
        ogs_free(report->hash);
	report->hash = NULL;
    }
    if (report->data_report) {
	report->data_report_handler->free_report_data(report->data_report);    
	report->data_report = NULL;
    }
    if (ogs_list_first(&report->usage)) data_report_event_subscriptions_remove_all(&report->usage);
    ogs_free(report);
}

static int data_collection_report_destroy_expired(ogs_list_t *data_reports)
{
    data_collection_data_report_t *data_report = NULL;
    data_collection_data_report_t *data_report_node = NULL;
    const ogs_time_t current_time = ogs_time_now();

    if (!data_reports) return 0;

    ogs_list_for_each_safe(data_reports, data_report_node, data_report) {
	if(data_report->expired ||
	   (current_time >= data_report->last_used +  
	    ( 3 * ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age)))) {    
                ogs_list_remove(data_reports, data_report);
                data_collection_report_destroy(data_report);
	}
    }
    if(!ogs_list_first(data_reports)) { 
        ogs_free(data_reports);
	return 0;
    }
    return 1;
}


static data_collection_data_report_t *data_collection_report_create(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *handler, void *data_report) {

    data_collection_data_report_t *report;
    cJSON *report_json;
    cJSON *data_report_json;
    
    ogs_list_t *data_reports = NULL;

    report = ogs_calloc(1, sizeof(data_collection_data_report_t));
    ogs_assert(report);

    report->data_report_handler = handler; //pointer to handler;
    report->generated = get_time_from_timespec(handler->timestamp_for_report_data(data_report)); // this function returns timespec so change to ogs_time_t;
    report->last_used = ogs_time_now();
    report->session = session;
    report->hash = handler->tag_for_report_data(data_report);
    report->data_report = data_report;
    report->file_path = data_collection_strdup(data_collection_self()->config.data_collection_dir);
    
    data_reports = (ogs_list_t *)ogs_hash_get(data_collection_self()->data_reports, &report->data_report_handler, sizeof(report->data_report_handler));
    if(!data_reports) {
        data_reports = (ogs_list_t*) ogs_calloc(1,sizeof(*data_reports));
        ogs_assert(data_reports);
        ogs_list_init(data_reports);
    }

    ogs_list_add(data_reports, report);

    ogs_hash_set(data_collection_self()->data_reports, &report->data_report_handler, sizeof(report->data_report_handler), data_reports);
    data_reports_timer_activate();

    data_report_json = handler->json_for_report_data(data_report);
    
    //dump to disk report data_collection_data_report_t stored to disk

    char *report_time = dc_strdup(get_current_time("%Y-%m-%dT%H:%M:%SZ"));
    char *body = cJSON_Print(data_report_json);

    data_collection_report_store(data_collection_strdup(session->data_reporting_session_id), data_collection_strdup(handler->data_domain), report_time, "json", body);
    cJSON_free(body);
    ogs_free(report_time);

    return report;
}

static ogs_list_t *get_data_reports_allowed_for_event_subscription(const data_collection_data_report_handler_t* const *handlers, data_collection_event_subscription_t *event_subscription, bool omit_used)
{
     size_t i;
     data_collection_data_report_t *data_report;
     const data_collection_data_report_handler_t **allowed_handlers = NULL;
     ogs_list_t *data_reports_allowed = NULL;

     data_reports_allowed = (ogs_list_t*) ogs_calloc(1,sizeof(*data_reports_allowed));
     ogs_assert(data_reports_allowed);
     ogs_list_init(data_reports_allowed);

     if (!handlers) {
        const data_collection_data_report_handler_t *drh;
        const data_collection_data_report_handler_t **registered_handlers = data_collection_self()->config.data_collection_configuration->data_report_handlers;
        size_t handlers_found = 0;
        data_collection_af_event_exposure_subscription_t *af_event_subsc = data_collection_event_subscription_get_af_event_exposure_subscription(event_subscription);

        for (i = 0; registered_handlers[i]; i++) {
            size_t j = data_collection_af_event_exposure_subscription_num_events_subs(af_event_subsc);
            const char *reg_event_type = registered_handlers[i]->event_type;

            for (j--; j >= 0; j--) {
		data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription = data_collection_event_subscription_get_af_event_exposure_subscription(event_subscription);    
                data_collection_af_events_subscription_t *events_subs = data_collection_af_event_exposure_subscription_get_events_subs(af_event_exposure_subscription, j);
                if (!strcmp(data_collection_af_events_subscription_get_event_type(events_subs), reg_event_type)) {
                    /* found appropriate data handler */
                    allowed_handlers = ogs_realloc(allowed_handlers, sizeof(*allowed_handlers) * (handlers_found + 1));
                    allowed_handlers[handlers_found] = registered_handlers[i];
                    handlers_found++;
                    break;
                }
            }
        }
        handlers = allowed_handlers;
    }

    data_collection_af_event_exposure_subscription_t *af_event_subsc = data_collection_event_subscription_get_af_event_exposure_subscription(event_subscription);
    for (i = 0; handlers[i]; i++) {
	size_t j = data_collection_af_event_exposure_subscription_num_events_subs(af_event_subsc);
        const char *event_type = handlers[i]->event_type;
	ogs_list_t *data_reports;

	data_reports = (ogs_list_t *)ogs_hash_get(data_collection_self()->data_reports, handlers[i], sizeof(handlers[i]));

	ogs_list_for_each(data_reports, data_report) {
            if(omit_used) {
                if(is_event_subscription_used(data_report, event_subscription))
                    continue;
            }
	    for (j--; j >= 0; j--) {
		data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription = data_collection_event_subscription_get_af_event_exposure_subscription(event_subscription);
    
                data_collection_af_events_subscription_t *events_subs = data_collection_af_event_exposure_subscription_get_events_subs(af_event_exposure_subscription, j);
                //TODO: Add extra filters
		if (!strcmp(data_collection_af_events_subscription_get_event_type(events_subs), event_type) /* && check_for_user_ids(events_subs, data_report, event_type)*/) {
                    ogs_list_add(data_reports_allowed, data_report);
                    break;
                }

            }

        }
    }
    if(allowed_handlers) ogs_free(allowed_handlers);
    return data_reports_allowed;
}

static char *check_for_user_ids(data_collection_af_events_subscription_t *events_subscription, data_collection_data_report_t *data_report, char *event_type) {

    OpenAPI_list_t *user_identifiers;
    char *external_application_id;
    char *user_ident;
    user_identifiers = OpenAPI_list_create();
    dc_api_data_report_t *report = (dc_api_data_report_t *)data_report->data_report;
    external_application_id = report->external_application_id;

    data_collection_get_user_ids_from_reporting_provisioning_session_configurations(event_type, external_application_id, user_identifiers);
    user_ident = check_for_user_ids_from_reporting_provisioning_session_in_event_filter(user_identifiers, events_subscription);
    return user_ident;
}

static char *check_for_user_ids_from_reporting_provisioning_session_in_event_filter(OpenAPI_list_t *user_identifiers, data_collection_af_events_subscription_t *events_subscription) {
    
    dc_api_event_filter_t *event_filter;
    char *user_id;
    char *gpsi;
    char *supi;
    event_filter = data_collection_event_exposure_subscription_get_filter(events_subscription);
    ogs_assert(event_filter);

    OpenAPI_lnode_t *user_id_node = NULL;
    OpenAPI_lnode_t *gpsi_node = NULL;
    OpenAPI_lnode_t *supi_node = NULL;

    OpenAPI_list_for_each(user_identifiers, user_id_node) {
        user_id = (char *)user_id_node->data;
	if(event_filter->gpsis) {
            OpenAPI_list_for_each(event_filter->gpsis, gpsi_node) {
	        gpsi = (char *)gpsi_node->data;
		if(!strcmp(user_id, gpsi)) return user_id;	
            }		

	}

	if(event_filter->supis) {
            OpenAPI_list_for_each(event_filter->supis, supi_node) {
	        supi = (char *)supi_node->data;
		if(!strcmp(user_id, supi)) return user_id;	
            }		

	}
	    
    }
    return NULL;
}

static bool is_event_subscription_used(data_collection_data_report_t *data_report, data_collection_event_subscription_t *event_subscription)
{

    if(ogs_list_first(&data_report->usage)) {
         data_collection_event_subscription_t *event_subsc = NULL;
         ogs_list_for_each(&data_report->usage, event_subsc) {
             if(event_subsc == event_subscription)
                 return 1;		  
         }
	 return 0;
    
    }
    return 1;
}

static data_collection_data_report_property_e get_report_properties(dc_api_data_report_t *report, ogs_list_t *data_reports)
{
    if (report->application_specific_records) {
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC;
    }
    if (report->communication_records) {
        populate_communication_records(report, data_reports);
        return  DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION;
    }
    if (report->location_records)
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION;
    if (report->media_streaming_access_records)
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS;
    if (report->performance_data_records)
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE;
    if (report->service_experience_records)
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE;
    if (report->trip_plan_records)
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN;
    return -1;

}


static void populate_communication_records (dc_api_data_report_t *report, ogs_list_t *data_reports) {

    OpenAPI_lnode_t *node = NULL;
    data_report_t *data_report;

    if (report->communication_records) {
        OpenAPI_list_for_each(report->communication_records, node) {
            cJSON *itemLocal = dc_api_communication_record_convertToJSON(node->data, true);
	    if (itemLocal == NULL) {
                ogs_error("dc_api_data_report_convertToJSON() failed [communication_records]");
                return;
            }

            data_report = ogs_calloc(1, sizeof(data_report_t));
            ogs_assert(data_report);
            data_report->data_report = itemLocal;
            ogs_list_add(data_reports, data_report);
        }
    }
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

static void data_reports_timer_activate(void) {

    if (!data_collection_self()->data_reports_timer) data_collection_self()->data_reports_timer = ogs_timer_add(ogs_app()->timer_mgr, dc_timer_data_reports_expire, NULL);
    if (data_collection_self()->data_reports_timer) {
         ogs_timer_start(data_collection_self()->data_reports_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));
    }
    if (!data_collection_self()->data_reports_clear_timer) data_collection_self()->data_reports_clear_timer = ogs_timer_add(ogs_app()->timer_mgr, dc_timer_data_reports_clear, NULL);     
    if (data_collection_self()->data_reports_clear_timer) {
         ogs_timer_start(data_collection_self()->data_reports_clear_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));
    }
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
