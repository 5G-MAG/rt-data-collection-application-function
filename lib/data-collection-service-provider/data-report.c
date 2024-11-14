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

typedef struct aggregation_data_set_key_s {
    const data_collection_data_report_handler_t *handler;
    char function_name[];
} aggregation_data_set_key_t;

typedef struct aggregation_data_set_s {
    ogs_list_t data_samples; /* list of data_collection_data_report_record_t */
    aggregation_data_set_key_t key;
} aggregation_data_set_t;

typedef struct bucketed_data_worksheet_s {
    data_collection_bucketed_data_t bucket;
    ogs_hash_t *aggregation_data; /* map of function_name,data_collection_data_report_handler_t* => *aggregation_data_set_t */
} bucketed_data_worksheet_t;

typedef struct report_find_result_s {
    ogs_list_t buckets;        /* Type: bucketed_data_worksheet_t */
    ogs_list_t time_infos;     /* Type: data_collection_lnode_t with object type data_collection_bucket_time_info_t */
    ogs_list_t identity_infos; /* Type: data_collection_lnode_t with object type data_collection_bucket_identity_info_t */
    ogs_list_t location_infos; /* Type: data_collection_lnode_t with object type data_collection_bucket_location_info_t */
} report_find_result_t;

/********* Private function prototypes *********/

static void __suppress_unused_variable(const void *var);
static int __data_collection_report_destroy_expired(ogs_list_t *data_reports);
static data_collection_data_report_property_e __data_report_handler_report_property(const data_collection_data_report_handler_t *handler);
static data_collection_data_report_property_e __data_domain_to_data_report_property(const char *data_domain);

static data_collection_data_report_property_e __get_report_properties(data_collection_model_data_report_t *report, ogs_list_t *data_reports);
static void __populate_communication_records (data_collection_model_data_report_t *report, ogs_list_t *data_reports);
static int __free_local_data_report_records(ogs_list_t *data_report_records);

static bucketed_data_worksheet_t *__results_find_worksheet(report_find_result_t *result, const data_collection_bucket_time_info_t *time_info, const data_collection_bucket_identity_info_t *id_info, const data_collection_bucket_location_info_t *locn_info, const data_collection_data_report_handler_t *handler);

static bucketed_data_worksheet_t* __bucketed_data_worksheet_new(const data_collection_data_report_handler_t *handler,
                                                                const data_collection_bucket_time_info_t *time_info,
                                                                const data_collection_bucket_identity_info_t *identity_info,
                                                                const data_collection_bucket_location_info_t *location_info);
static void __bucketed_data_worksheet_free(bucketed_data_worksheet_t *worksheet);
static bool __bucketed_data_worksheet_add_data_set(bucketed_data_worksheet_t *worksheet, aggregation_data_set_t *data_set);
static aggregation_data_set_t* __bucketed_data_worksheet_get_data_set(bucketed_data_worksheet_t *worksheet, const data_collection_data_report_handler_t *handler, const char *fn);

static aggregation_data_set_t* __aggregation_data_set_new(const data_collection_data_report_handler_t *handler, const char *fn);
static size_t __aggregation_data_set_size(const char *fn);
static void __aggregation_data_set_free(aggregation_data_set_t *data_set);

static aggregation_data_set_key_t *__aggregation_data_set_key_new(const data_collection_data_report_handler_t *handler, const char *fn);
static aggregation_data_set_key_t *__aggregation_data_set_key_init(aggregation_data_set_key_t *key, const data_collection_data_report_handler_t *handler, const char *fn);
static size_t __aggregation_data_set_key_size(const char *fn);
static void __aggregation_data_set_key_free(aggregation_data_set_key_t *);

//static void __bucket_identity_info_free(data_collection_bucket_identity_info_t *id_info);
//static void __bucket_location_info_free(data_collection_bucket_location_info_t *locn_info);

/** Add an lnode to a unique list (set).
 *
 * This will check the list for an equivalent object to the one referred to in \a new_node. If a match is found the existing
 * lnode from the set is returned and \a new_node is freed. If no match is found then \a new_node is added to the set and
 * returned.
 *
 * @param set The set (unique list) to add the lnode to.
 * @param new_node The lnode reference for the object to add to the set.
 * @param compare A function that can compare two objects of the type pointed to by lnode.
 *
 * @return The existing lnode in \a set that matches the object in \a new_node or \a new node if its object is unique.
 */
static data_collection_lnode_t *__set_add_lnode(ogs_list_t *set, data_collection_lnode_t *new_node, bool(*compare)(const void*, const void*));

/** Compare data_collection_bucket_time_info_t objects.
 *
 * This is suitable for use with __set_add_lnode(). Will handle NULL objects too.
 *
 * @param a The first bucket time info object to check.
 * @param b The second bucket time info object to check.
 *
 * @return `true` if a == b, or `false` otherwise.
 */
static bool __cmp_time_info(const data_collection_bucket_time_info_t *a, const data_collection_bucket_time_info_t *b);

/** Compare data_collection_bucket_identity_info_t objects.
 *
 * This is suitable for use with __set_add_lnode(). Will handle NULL objects too.
 *
 * @param a The first bucket identity info object to check.
 * @param b The second bucket identity info object to check.
 *
 * @return `true` if a == b, or `false` otherwise.
 */
static bool __cmp_id_info(const data_collection_bucket_identity_info_t *a, const data_collection_bucket_identity_info_t *b);

/** Compare data_collection_bucket_location_info_t objects.
 *
 * This is suitable for use with __set_add_lnode(). Will handle NULL objects too.
 *
 * @param a The first bucket location info object to check.
 * @param b The second bucket location info object to check.
 *
 * @return `true` if a == b, or `false` otherwise.
 */
static bool __cmp_locn_info(const data_collection_bucket_location_info_t *a, const data_collection_bucket_location_info_t *b);

/** Free a data_collection_bucket_time_info_t
 *
 * @param time_info The bucket time info object to free.
 */
static void __bucket_time_info_free(data_collection_bucket_time_info_t *time_info);

/** Check if a time period is contained completely within a time window
 *
 * This will check if the period of time [\a start .. \a end) exists completely within the time window as specified by
 * \a time_info.
 *
 * @param time_info The time window to use for comparison.
 * @param start The inclusive start time of the period to check.
 * @param end The exclusive end time of the period to check.
 *
 * @return `true` if [\a start .. \a end) exists completely within \a time_info or `false` if any part of [\a start .. \a end)
 *         exists outside of \a time_info.
 */
static bool __bucket_time_info_contains(const data_collection_bucket_time_info_t *time_info, struct timespec *start, struct timespec *end);

/** Check if a time period overlaps with a time window
 *
 * This will check if the period of time [\a start .. \a end) overlaps in any way with the time window as specified by
 * \a time_info.
 *
 * @param time_info The time window to use for comparison.
 * @param start The inclusive start time of the period to check.
 * @param end The exclusive end time of the period to check.
 *
 * @return `true` if [\a start .. \a end) overlaps, either partially or completely with \a time_info, or `false` if
 *         [\a start .. \a end) exists completely outside of \a time_info.
 */
//static bool __bucket_time_info_overlaps(const data_collection_bucket_time_info_t *time_info, struct timespec *start, struct timespec *end);

static ogs_list_t *__data_report_record_access_profiles_allowed_for_event_subscription(
                                                      const data_collection_data_report_record_t *record,
                                                      const data_collection_event_subscription_t *event_subscription);
static ogs_list_t *__data_reporting_configuration_profiles_allowed_for_event_subscription_with_filters(
                                                      const data_collection_reporting_configuration_t *config,
                                                      const data_collection_event_subscription_t *event_subscription,
                                                      const char *external_app_id, const char *event_type);
static bool __data_access_profile_matches_event_subscription(const data_collection_model_data_access_profile_t *dap,
                                                             const data_collection_event_subscription_t *event_subscription,
                                                             const char *external_app_id, const char *event_type);
static int __add_buckets_for_record_using_data_access_profile(report_find_result_t *result,
                                                      data_collection_data_report_record_t *record,
                                                      const data_collection_model_data_access_profile_t *dap,
                                                      const data_collection_event_subscription_t *event_subscription);
static void __aggregate_worksheet_buckets(report_find_result_t *result);
static bool __list_find_any_str_match(const ogs_list_t *a, const ogs_list_t *b);

/******** Public API ********/

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_report(data_collection_reporting_session_t *session, const char *mime_type, const void *data, 
		size_t data_length, char **error_return, char **error_classname, char **error_parameter, const char **error_code) {
    cJSON *data_report;
    data_collection_model_data_report_t *report;
    int i = 0;
    data_collection_data_report_property_e found_property;
    ogs_list_t data_reports;
    char *external_application_id;
    bool expedite;

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

    expedite = data_collection_model_data_report_has_expedite(report);
    ogs_debug("Expedite in Data Report: %d", expedite);

    data_collection_model_data_report_free(report);

    const data_collection_data_report_handler_t * const *handlers = data_collection_self()->config.data_collection_configuration->data_report_handlers;
    
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
                    data_collection_data_report_record_new(session, handlers[i], parsed_data, external_application_id, expedite);
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

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_bucketed_data_list_free(ogs_list_t *buckets)
{
    if (ogs_unlikely(!buckets)) return;
  
    report_find_result_t *results = (report_find_result_t*)buckets;
    bucketed_data_worksheet_t *worksheet_safe_node, *worksheet;

    ogs_list_for_each_safe(&results->buckets, worksheet_safe_node, worksheet) {
        ogs_list_remove(&results->buckets, worksheet);
        __bucketed_data_worksheet_free(worksheet);
    }

    data_collection_list_clear(&results->time_infos);
    data_collection_list_clear(&results->identity_infos);
    data_collection_list_clear(&results->location_infos);

    ogs_free(buckets);
}

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_report_find(
                                                const data_collection_data_report_handler_t* const *report_handlers, 
                                		data_collection_event_subscription_t *event_subscription, bool omit_used)
{
    ogs_debug("Find reports: report_handlers=%p, event_subscription=%p, omit_used=%s", report_handlers, event_subscription, omit_used?"true":"false");
    ogs_assert(event_subscription);

    report_find_result_t *result = ogs_calloc(1,sizeof(*result));
    
    size_t i=0;
    for (i=0; report_handlers[i]; i++) {
        ogs_debug("Looking for %s (\"%s\") reports...", report_handlers[i]->type_name, report_handlers[i]->data_domain);
        data_report_hash_record_t *hash_record = (data_report_hash_record_t*)ogs_hash_get(data_collection_self()->data_reports, report_handlers+i, sizeof(*report_handlers));
        if (hash_record) {
            ogs_debug("Searching %i %s report records...", ogs_list_count(&hash_record->list), report_handlers[i]->type_name);
            data_collection_data_report_record_t *record;
            ogs_list_for_each(&hash_record->list, record) {
                if (omit_used && data_collection_data_report_record_used_by(record, event_subscription)) {
                    ogs_debug("Record already used!");
                    continue;
                }
                /* get the list of DataAccessProfiles, allowed by the report record, that also match up with the event subsc */
                ogs_list_t *allowed_data_access_profiles = __data_report_record_access_profiles_allowed_for_event_subscription(record, event_subscription);
                if (allowed_data_access_profiles) {
                    data_collection_lnode_t *node;
                    /* for each allowed DataAccessProfile, try to add buckets to the result for this record */
                    ogs_list_for_each(allowed_data_access_profiles, node) {
                        data_collection_model_data_access_profile_t *dap =
                                                                    (data_collection_model_data_access_profile_t*)node->object;
                        /* Add the result all the buckets it belongs in if event_subscription.eventSubs.eventFilters allow */
                        __add_buckets_for_record_using_data_access_profile(result, record, dap, event_subscription);
                    }
                } else {
                    ogs_debug("Record has no suitable DataAccessProfile matches for the AfEventExposureSubsc");
                }
                data_collection_list_free(allowed_data_access_profiles);
            }
        }
    }

    /* Apply the aggregation functions to the worksheets and add the results to the main result buckets record lists */
    __aggregate_worksheet_buckets(result);

    return &result->buckets;
#if 0
    const data_collection_data_report_handler_t *handler;
    

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
#endif
}

/******** Internal library API *********/

void data_report_event_subscriptions_remove_all(ogs_list_t *event_subscriptions)
{
    data_collection_list_free(event_subscriptions);
}

bool remove_expired_data_reports(ogs_hash_t *data_reports)
{
    if (!data_reports) return false;

    ogs_hash_index_t *it, *it_obj = ogs_hash_index_make(data_reports);

    ogs_debug("remove_expired_data_reports(%p) [%i types]", data_reports, ogs_hash_count(data_reports));
    for (it = ogs_hash_next(it_obj); it; it = ogs_hash_next(it)) {
        const data_collection_data_report_handler_t *key;
        int key_len;
        data_report_hash_record_t *data_hash_record;
	ogs_list_t *data_report;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&data_hash_record));
        data_report = &data_hash_record->list;
        ogs_debug("clear %p[%i]: %p", key, key_len, data_report);
	if (!__data_collection_report_destroy_expired(data_report)) {
            ogs_hash_set(data_reports, key, key_len, NULL);
            data_report_hash_record_free(data_hash_record);
        }
    }
    ogs_free(it_obj);
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

static void __suppress_unused_variable(const void *var)
{
}

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
    /* indicate if list is now empty or not */
    return !!ogs_list_first(data_reports);
}

static data_collection_data_report_property_e __get_report_properties(data_collection_model_data_report_t *report, ogs_list_t *data_reports)
{
    static const struct {
        bool (*property_fn)(const data_collection_model_data_report_t *report);
        data_collection_data_report_property_e property_enum;
    } properties[] = {
        {data_collection_model_data_report_has_application_specific_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC},
        {data_collection_model_data_report_has_communication_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION},
        {data_collection_model_data_report_has_location_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION},
        {data_collection_model_data_report_has_media_streaming_access_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS},
        {data_collection_model_data_report_has_performance_data_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE},
        {data_collection_model_data_report_has_service_experience_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE},
        {data_collection_model_data_report_has_trip_plan_records, DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN}
    };
    size_t i;

    for (i = 0; i < sizeof(properties)/sizeof(properties[0]); i++) {
        if (properties[i].property_fn(report)) {
	    if(properties[i].property_enum == DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION) __populate_communication_records(report, data_reports);	
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

static bucketed_data_worksheet_t *__results_find_worksheet(report_find_result_t *result,
                                                           const data_collection_bucket_time_info_t *time_info,
                                                           const data_collection_bucket_identity_info_t *id_info,
                                                           const data_collection_bucket_location_info_t *locn_info,
                                                           const data_collection_data_report_handler_t *handler)
{
    bucketed_data_worksheet_t *worksheet;

    ogs_list_for_each(&result->buckets, worksheet) {
        if (handler == worksheet->bucket.bucket_info.report_handler &&
            time_info == worksheet->bucket.bucket_info.time &&
            id_info == worksheet->bucket.bucket_info.identity &&
            locn_info == worksheet->bucket.bucket_info.location) return worksheet;
    }

    return NULL;
}

static bucketed_data_worksheet_t* __bucketed_data_worksheet_new(const data_collection_data_report_handler_t *handler,
                                                                const data_collection_bucket_time_info_t *time_info,
                                                                const data_collection_bucket_identity_info_t *identity_info,
                                                                const data_collection_bucket_location_info_t *location_info)
{
    bucketed_data_worksheet_t *worksheet = ogs_calloc(1, sizeof(*worksheet));
    if (ogs_likely(worksheet)) {
        worksheet->bucket.bucket_info.time = time_info;
        worksheet->bucket.bucket_info.identity = identity_info;
        worksheet->bucket.bucket_info.location = location_info;
        worksheet->bucket.bucket_info.report_handler = handler;
        worksheet->aggregation_data = ogs_hash_make();
    }
    return worksheet;
}

static void __bucketed_data_worksheet_free(bucketed_data_worksheet_t *worksheet)
{
    ogs_hash_index_t *idx;

    if (ogs_unlikely(!worksheet)) return;

    if (worksheet->bucket.data_samples) {
        data_collection_data_report_record_t *safe_node, *data_record;
        ogs_list_for_each_safe(worksheet->bucket.data_samples, safe_node, data_record) {
            ogs_list_remove(worksheet->bucket.data_samples, data_record);
            data_collection_data_report_record_destroy(data_record);
        }
        ogs_free(worksheet->bucket.data_samples);
        worksheet->bucket.data_samples = NULL;
    }

    if (worksheet->aggregation_data) {
        for (idx = ogs_hash_first(worksheet->aggregation_data); idx; idx = ogs_hash_next(idx)) {
            const aggregation_data_set_key_t *key;
            int key_size;
            aggregation_data_set_t *data_set;
            ogs_hash_this(idx, (const void**)&key, &key_size, (void**)&data_set);
            ogs_hash_set(worksheet->aggregation_data, key, key_size, NULL);
            __aggregation_data_set_free(data_set);
        }
        ogs_hash_destroy(worksheet->aggregation_data);
        worksheet->aggregation_data = NULL;
    }

    ogs_free(worksheet);
}

static bool __bucketed_data_worksheet_add_data_set(bucketed_data_worksheet_t *worksheet, aggregation_data_set_t *data_set)
{
    if (ogs_unlikely(!worksheet)) return false;

    ogs_hash_set(worksheet->aggregation_data, &data_set->key, __aggregation_data_set_key_size(data_set->key.function_name), data_set);

    return true;
}

static aggregation_data_set_t* __bucketed_data_worksheet_get_data_set(bucketed_data_worksheet_t *worksheet, const data_collection_data_report_handler_t *handler, const char *fn)
{
    aggregation_data_set_key_t *key;
    aggregation_data_set_t *data_set;

    if (!worksheet) return NULL;

    key = __aggregation_data_set_key_new(handler, fn);
    data_set = (aggregation_data_set_t*)ogs_hash_get(worksheet->aggregation_data, key, __aggregation_data_set_key_size(fn));
    __aggregation_data_set_key_free(key);

    return data_set;
}

/* aggregation_data_set_t */
static aggregation_data_set_t* __aggregation_data_set_new(const data_collection_data_report_handler_t *handler, const char *fn)
{
    aggregation_data_set_t *data_set = (aggregation_data_set_t*)ogs_malloc(__aggregation_data_set_size(fn));
    if (data_set) {
        __aggregation_data_set_key_init(&data_set->key, handler, fn);
        ogs_list_init(&data_set->data_samples);
    }
    return data_set;
}

static size_t __aggregation_data_set_size(const char *fn)
{
    return sizeof(aggregation_data_set_t) - sizeof(aggregation_data_set_key_t) + __aggregation_data_set_key_size(fn);
}

static void __aggregation_data_set_free(aggregation_data_set_t *data_set)
{
    data_collection_data_report_record_t *safe_node, *node;

    if (!data_set) return;

    ogs_list_for_each_safe(&data_set->data_samples, safe_node, node) {
        ogs_list_remove(&data_set->data_samples, node);
        data_collection_data_report_record_destroy(node);
    }

    ogs_free(data_set);
}

/* aggregation_data_set_key_t */
static aggregation_data_set_key_t *__aggregation_data_set_key_new(const data_collection_data_report_handler_t *handler, const char *fn)
{
    aggregation_data_set_key_t *key = (aggregation_data_set_key_t*)ogs_malloc(__aggregation_data_set_key_size(fn));
    return __aggregation_data_set_key_init(key, handler, fn);
}

static aggregation_data_set_key_t *__aggregation_data_set_key_init(aggregation_data_set_key_t *key, const data_collection_data_report_handler_t *handler, const char *fn)
{
    if (key) {
        key->handler = handler;
        strcpy(key->function_name, fn);
    }
    return key;
}

static size_t __aggregation_data_set_key_size(const char *fn)
{
    return sizeof(aggregation_data_set_key_t) + strlen(fn) + 1;
}

static void __aggregation_data_set_key_free(aggregation_data_set_key_t *key)
{
    ogs_free(key);
}

static void __bucket_time_info_free(data_collection_bucket_time_info_t *time_info)
{
    if (time_info) ogs_free(time_info);
}

#if 0
static void __bucket_identity_info_free(data_collection_bucket_identity_info_t *id_info)
{
    if (!id_info) return;
    if (id_info->user_id) ogs_free(id_info->user_id);
    if (id_info->group_id) ogs_free(id_info->group_id);
    ogs_free(id_info);
}

static void __bucket_location_info_free(data_collection_bucket_location_info_t *locn_info)
{
    if (!locn_info) return;
    if (locn_info->location) data_collection_model_geographic_area_free(locn_info->location);
    ogs_free(locn_info);
}
#endif

static ogs_list_t *__data_report_record_access_profiles_allowed_for_event_subscription(const data_collection_data_report_record_t *record, const data_collection_event_subscription_t *event_subscription)
{
    if (!record || !event_subscription) return NULL;

    ogs_list_t *ret = NULL;
    ogs_list_t *context_ids = data_collection_data_report_record_get_context_ids(record);

    data_collection_reporting_session_t *report_session = data_collection_data_report_record_get_session(record);
    const data_collection_data_report_handler_t *handler = data_collection_data_report_record_get_data_report_handler(record);

    /* loop through configurations for the data report record */
    data_collection_lnode_t *node;
    ogs_list_for_each(context_ids, node) {
        const char *context_id = (const char*)node->object;
        const data_collection_reporting_configuration_t *config =
                    (const data_collection_reporting_configuration_t*)ogs_hash_get(
                                data_collection_self()->data_reporting_configuration_contexts, context_id, OGS_HASH_KEY_STRING);
        if (config) {
            ogs_debug("Found configuration for context id \"%s\"", context_id);
            ogs_list_t *config_daps = __data_reporting_configuration_profiles_allowed_for_event_subscription_with_filters(config, event_subscription, report_session->external_application_id, handler->event_type);
            if (config_daps) {
                ogs_debug("Configuration \"%s\" has %i suitable DataAccessProfiles", context_id, ogs_list_count(config_daps));
                /* move DataAccessProfiles to result list */
                data_collection_lnode_t *safe_node, *cfg_dap_node;
                ogs_list_for_each_safe(config_daps, safe_node, cfg_dap_node) {
                    ogs_list_remove(config_daps, cfg_dap_node);
                    if (!ret) ret = (ogs_list_t*)ogs_calloc(1,sizeof(*ret));
                    ogs_list_add(ret, cfg_dap_node);
                }
                ogs_free(config_daps);
            }
        }
    }

    data_collection_list_free(context_ids);

    return ret;
}

static ogs_list_t *__data_reporting_configuration_profiles_allowed_for_event_subscription_with_filters(
                                                    const data_collection_reporting_configuration_t *config,
                                                    const data_collection_event_subscription_t *event_subscription,
                                                    const char *external_app_id, const char *event_type)
{
    ogs_list_t *daps = NULL;
    const data_collection_model_af_event_exposure_subsc_t *af_event_subsc =
                                                data_collection_event_subscription_get_af_event_exposure_subsc(event_subscription);
    const char *data_acc_prof_id = data_collection_model_af_event_exposure_subsc_get_data_acc_prof_id(af_event_subsc);
    const data_collection_model_data_reporting_configuration_t *drc = data_collection_reporting_configuration_model(config);
    ogs_list_t *config_daps = data_collection_model_data_reporting_configuration_get_data_access_profiles(drc);
    data_collection_lnode_t *safe_node, *cfg_dap_node;

    ogs_debug("Configuration \"%s\" has %i DataAccessProfiles", data_collection_model_data_reporting_configuration_get_data_reporting_configuration_id(drc), ogs_list_count(config_daps));

    ogs_list_for_each_safe(config_daps, safe_node, cfg_dap_node) {
        const data_collection_model_data_access_profile_t *cfg_dap =
                                                        (const data_collection_model_data_access_profile_t*)cfg_dap_node->object;
        ogs_debug("Checking DataAccessProfile \"%s\"...", data_collection_model_data_access_profile_get_data_access_profile_id(cfg_dap));

        if (data_acc_prof_id) {
            /* event subscription will only accept one specific DataAccessProfile so see if this configuration holds that one */
            const char *cfg_dap_id = data_collection_model_data_access_profile_get_data_access_profile_id(cfg_dap);
            if (cfg_dap_id && strcmp(cfg_dap_id, data_acc_prof_id)) continue;
            ogs_debug("Found specific DataAccessProfile \"%s\"", data_acc_prof_id);
        }

        if (__data_access_profile_matches_event_subscription(cfg_dap, event_subscription, external_app_id, event_type)) {
            ogs_list_remove(config_daps, cfg_dap_node);
            if (!daps) daps = (ogs_list_t*)ogs_calloc(1, sizeof(*daps));
            ogs_list_add(daps, cfg_dap_node);
        }

        if (data_acc_prof_id) break;
    }
    data_collection_list_free(config_daps);

    return daps;
}

static bool __data_access_profile_matches_event_subscription(const data_collection_model_data_access_profile_t *dap,
                                                             const data_collection_event_subscription_t *event_subscription,
                                                             const char *external_app_id, const char *event_type)
{
    /* event_subscription.af_event_exposure_subsc.dataAccProfId has already been checked by this point so doesn't need checking
     * again. */

    /* does the event_subscription client type match any of the dap.targetEventConsumerTypes? */
    data_collection_lnode_t *node;
    const char *subsc_client_type = data_collection_event_subscription_get_client_type(event_subscription);
    ogs_list_t *dap_event_consumer_types = data_collection_model_data_access_profile_get_target_event_consumer_types(dap);
    ogs_list_for_each(dap_event_consumer_types, node) {
        data_collection_model_event_consumer_type_t *dap_event_consumer_type =
                                                                    (data_collection_model_event_consumer_type_t*)node->object;
        const char *evt_consumer_type = data_collection_model_event_consumer_type_get_string(dap_event_consumer_type);
        ogs_debug("DAP event type \"%s\" == Subscription clientType \"%s\"?", evt_consumer_type, subsc_client_type);
        if (!strcmp(evt_consumer_type, subsc_client_type)) break;
    }
    data_collection_list_free(dap_event_consumer_types);
    if (!node) return false; /* no matching event consumer type in the dap */

    /* for each event_subscription.eventSubs[event==event_type].eventFilter[appIds is NULL or external_app_id in appIds] */
    const data_collection_model_af_event_exposure_subsc_t *af_event_subsc =
                                            data_collection_event_subscription_get_af_event_exposure_subsc(event_subscription);
    ogs_list_t *eventsSubs = data_collection_model_af_event_exposure_subsc_get_events_subs(af_event_subsc);
    ogs_list_for_each(eventsSubs, node) {
        data_collection_model_events_subs_t *event_subs = (data_collection_model_events_subs_t*)node->object;
        const data_collection_model_af_event_t *af_event = data_collection_model_events_subs_get_event(event_subs);
        if (strcmp(data_collection_model_af_event_get_string(af_event), event_type)) continue;
        ogs_debug("DAP has afEvent \"%s\"", event_type);
        const data_collection_model_event_filter_t *event_filter = data_collection_model_events_subs_get_event_filter(event_subs);
        if (data_collection_model_event_filter_has_app_ids(event_filter)) {
            data_collection_lnode_t *app_id_node;
            ogs_list_t *app_ids = data_collection_model_event_filter_get_app_ids(event_filter);
            ogs_debug("Screening on app Id \"%s\"", external_app_id);
            ogs_list_for_each(app_ids, app_id_node) {
                const char *app_id = (const char*)app_id_node->object;
                if (!strcmp(app_id, external_app_id)) break;
            }
            data_collection_list_free(app_ids);
            if (!app_id_node) continue;
            ogs_debug("App id in event filter");
        }
        if (data_collection_model_data_access_profile_has_user_access_restrictions(dap)) {
            const data_collection_model_data_access_profile_user_access_restrictions_t *uar =
                data_collection_model_data_access_profile_get_user_access_restrictions(dap);
            ogs_list_t *dap_user_ids = data_collection_model_data_access_profile_user_access_restrictions_get_user_ids(uar);
            ogs_list_t *dap_group_ids = data_collection_model_data_access_profile_user_access_restrictions_get_group_ids(uar);

            ogs_debug("Screening on user/group Id...");
            if (data_collection_model_event_filter_has_gpsis(event_filter) && ogs_list_first(dap_user_ids) != NULL) {
                /* if gpsis is set and dap.userAccessRestrictions is set, does any gpsis[] match any
                 *     dap.userAccessRestrictions.userIds[]? */
                ogs_list_t *event_user_ids = data_collection_model_event_filter_get_gpsis(event_filter);
                bool match_found = __list_find_any_str_match(dap_user_ids, event_user_ids);
                data_collection_list_free(event_user_ids);
                if (!match_found) {
                    data_collection_list_free(dap_user_ids);
                    data_collection_list_free(dap_group_ids);
                    continue;
                }
            } else if (data_collection_model_event_filter_has_supis(event_filter) && ogs_list_first(dap_user_ids) != NULL) {
                /* if supis is set and dap.userAccessRestrictions is set, does any supis[] match any
                 *     dap.locationAccessRestrictions.userAccessRestrictions.userIds[]? */
                ogs_list_t *event_user_ids = data_collection_model_event_filter_get_supis(event_filter);
                bool match_found = __list_find_any_str_match(dap_user_ids, event_user_ids);
                data_collection_list_free(event_user_ids);
                if (!match_found) {
                    data_collection_list_free(dap_user_ids);
                    data_collection_list_free(dap_group_ids);
                    continue;
                }
            } else if (data_collection_model_event_filter_has_exter_group_ids(event_filter) && ogs_list_first(dap_group_ids) != NULL) {
                /* if exterGroupIds is set and dap.userAccessRestrictions is set, does any exterGroupIds[] match any
                 *     dap.userAccessRestrictions.groupIds[]? */
                ogs_list_t *event_group_ids = data_collection_model_event_filter_get_exter_group_ids(event_filter);
                bool match_found = __list_find_any_str_match(dap_group_ids, event_group_ids);
                data_collection_list_free(event_group_ids);
                if (!match_found) {
                    data_collection_list_free(dap_user_ids);
                    data_collection_list_free(dap_group_ids);
                    continue;
                }
            } else if (data_collection_model_event_filter_has_inter_group_ids(event_filter) && ogs_list_first(dap_group_ids) != NULL) {
                /* if interGroupIds is set and dap.userAccessRestrictions is set, does any interGroupIds[] match any
                 *     dap.userAccessRestrictions.groupIds[]? */
                ogs_list_t *event_group_ids = data_collection_model_event_filter_get_inter_group_ids(event_filter);
                bool match_found = __list_find_any_str_match(dap_group_ids, event_group_ids);
                data_collection_list_free(event_group_ids);
                if (!match_found) {
                    data_collection_list_free(dap_user_ids);
                    data_collection_list_free(dap_group_ids);
                    continue;
                }
            }
            data_collection_list_free(dap_user_ids);
            data_collection_list_free(dap_group_ids);
        }
        /* eventsSubs match so finish here */
        break;
    }
    data_collection_list_free(eventsSubs);
    if (!node) return false; /* no matching event subs */
    ogs_debug("Found matching eventsSubs");

    /* if locArea is set and dap.locationAccessRestrictions is set, does locArea overlap any
     *     dap.locationAccessRestrictions.locationAreas[]? */
    /* TODO: When we've implemented location matching then add these filters in */

    return true;
}

static bool __list_find_any_str_match(const ogs_list_t *a, const ogs_list_t *b) {
    data_collection_lnode_t *a_node;
    ogs_list_for_each(a, a_node) {
        data_collection_lnode_t *b_node;
        const char *a_str = (const char*)a_node->object;
        ogs_list_for_each(b, b_node) {
            const char *b_str = (const char*)b_node->object;
            if (!strcmp(a_str, b_str)) break;
        }
        if (b_node) break;
    }
    return  !!a_node;
}

static int __add_buckets_for_record_using_data_access_profile(report_find_result_t *result, data_collection_data_report_record_t *record, const data_collection_model_data_access_profile_t *dap, const data_collection_event_subscription_t *event_subscription)
{
    int buckets_updated = 0;
    data_collection_lnode_t *node;
    ogs_list_t record_time_axis;
    ogs_list_t record_id_axis;
    ogs_list_t record_locn_axis;

    const data_collection_data_report_handler_t *handler = data_collection_data_report_record_get_data_report_handler(record);
    const void *sample = data_collection_data_report_record_get_data_sample(record);

    struct timespec *record_start = handler->sample_start(sample);
    struct timespec *record_end = handler->sample_end(sample);
    struct timespec midpoint = {0,0};

    if (record_start) {
        if (record_end) {
            time_t sec_double = (record_start->tv_sec + record_end->tv_sec);
            long int nsec_double = (record_start->tv_nsec + record_end->tv_nsec);
            if (nsec_double >= 1000000000) {
                sec_double += 1;
                nsec_double -= 1000000000;
            }
            midpoint.tv_sec = sec_double/2;
            midpoint.tv_nsec = nsec_double/2;
            if (sec_double&1) midpoint.tv_nsec += 500000000;
            if (midpoint.tv_nsec >= 1000000000) {
                midpoint.tv_sec += 1;
                midpoint.tv_nsec -= 1000000000;
            }
        } else {
            memcpy(&midpoint, record_start, sizeof(midpoint));
        }
    }

    const data_collection_model_data_access_profile_time_access_restrictions_t *tar = NULL;
    const data_collection_model_data_access_profile_user_access_restrictions_t *uar = NULL;
    const data_collection_model_data_access_profile_location_access_restrictions_t *lar = NULL;

    ogs_list_init(&record_time_axis);
    ogs_list_init(&record_id_axis);
    ogs_list_init(&record_locn_axis);

    /* calculate which buckets on each axis the data record would fall into, according to the DataAccessProfile, but
     * exclude any that would be filtered by the event subscription. */
    if (data_collection_model_data_access_profile_has_time_access_restrictions(dap)) {
        if (record_start) {
            /* buckets on time axis based on the time access restrictions */
            tar = data_collection_model_data_access_profile_get_time_access_restrictions(dap);

            /* calculate all overlapping buckets for [record_start, record_end) if record_end is not NULL or the bucket containing
             * record_start if record_end is NULL */
            int period_secs = data_collection_model_data_access_profile_time_access_restrictions_get_duration(tar);
            struct timespec buckets_start = {(time_t)(record_start->tv_sec / period_secs) * period_secs, 0};
            struct timespec buckets_end = {0,0};

            if (record_end) {
                buckets_end.tv_sec = (time_t)((time_t)(record_end->tv_sec + period_secs - 1) / period_secs) * period_secs;
            } else {
                buckets_end.tv_sec = (time_t)((time_t)(record_start->tv_sec + period_secs - 1) / period_secs) * period_secs;
            }

            /* add a time axis entry for every `period_secs` starting from `buckets_start` and upto (but not including) `buckets_end` */
            struct timespec bucket_time = buckets_start;
            while (bucket_time.tv_sec < buckets_end.tv_sec) {
                data_collection_bucket_time_info_t *ti = ogs_malloc(sizeof(*ti));
                ti->start = bucket_time;
                bucket_time.tv_sec += period_secs;
                ti->end = bucket_time;
                data_collection_lnode_t *ti_node = __set_add_lnode(&result->time_infos, data_collection_lnode_create(ti, (void(*)(void*))__bucket_time_info_free), (bool(*)(const void*, const void*))__cmp_time_info);
                __set_add_lnode(&record_time_axis, data_collection_lnode_copy(ti_node), (bool(*)(const void*, const void*))__cmp_time_info);
            }
        }
    } else {
        /* no time restrictions so the time axis has one entry based on the record period */
        data_collection_bucket_time_info_t *ti = NULL;
        if (record_start) {
            /* if the sample has a start time then use that start/end for the time axis entry */
            ti = ogs_malloc(sizeof(*ti));
            memcpy(&ti->start, record_start, sizeof(*record_start));
            memcpy(&ti->end, (record_end)?record_end:record_start, sizeof(*record_start));
        } /* else note we have no time axis by using a NULL entry */
        data_collection_lnode_t *ti_node = __set_add_lnode(&result->time_infos, data_collection_lnode_create(ti, (void(*)(void*))__bucket_time_info_free), (bool(*)(const void*, const void*))__cmp_time_info);
        __set_add_lnode(&record_time_axis, data_collection_lnode_copy(ti_node), (bool(*)(const void*, const void*))__cmp_time_info);
    }
    
    if (data_collection_model_data_access_profile_has_user_access_restrictions(dap)) {
        /* buckets for user/group ids for the DataAccessProfile will allow that will not be filtered by the event_subscription */
        uar = data_collection_model_data_access_profile_get_user_access_restrictions(dap);
        /* TODO: fill this out when we have user/group id lookup for UE, for now just use NULL */
        data_collection_lnode_t *ii_node = __set_add_lnode(&result->identity_infos, data_collection_lnode_create_ref(NULL), (bool(*)(const void*, const void*))__cmp_id_info);
        __set_add_lnode(&record_id_axis, data_collection_lnode_copy(ii_node), (bool(*)(const void*, const void*))__cmp_id_info);
    } else {
        /* no restrictions on user/group from the DataAccessProfile, so no user/group bucketing, just add a NULL entry */
        /* TODO: when we have user/group id lookup for UE, throw this result away if it would be filtered out by the event_subscription */
        data_collection_lnode_t *ii_node = __set_add_lnode(&result->identity_infos, data_collection_lnode_create_ref(NULL), (bool(*)(const void*, const void*))__cmp_id_info);
        __set_add_lnode(&record_id_axis, data_collection_lnode_copy(ii_node), (bool(*)(const void*, const void*))__cmp_id_info);
    }

    if (data_collection_model_data_access_profile_has_location_access_restrictions(dap)) {
        /* buckets for locations given in the DataAccessProfile that match the record and that will not be filtered by the
         * event_subscription */
        lar = data_collection_model_data_access_profile_get_location_access_restrictions(dap);
        /* TODO: fill this out when we have location comparing, for now just use NULL */
        data_collection_lnode_t *li_node = __set_add_lnode(&result->location_infos, data_collection_lnode_create_ref(NULL), (bool(*)(const void*, const void*))__cmp_locn_info);
        __set_add_lnode(&record_locn_axis, data_collection_lnode_copy(li_node), (bool(*)(const void*, const void*))__cmp_locn_info);
    } else {
        /* no restrictions on location from this DataAccessProfile so no location bucketing */
        /* TODO: when we have location comparing, throw this result away if it would be filtered out by the event_subscription */
        data_collection_lnode_t *li_node = __set_add_lnode(&result->location_infos, data_collection_lnode_create_ref(NULL), (bool(*)(const void*, const void*))__cmp_locn_info);
        __set_add_lnode(&record_locn_axis, data_collection_lnode_copy(li_node), (bool(*)(const void*, const void*))__cmp_locn_info);
    }

    /* this is just here to suppress a warning about unused variables that will become useful when this is expanded */
    __suppress_unused_variable(uar);
    __suppress_unused_variable(lar);

    /* now we have the axis value lists for each axis, we can add the data to the relevant buckets */
    data_collection_lnode_t *time_node;
    ogs_list_for_each(&record_time_axis, time_node) {
        data_collection_bucket_time_info_t *time_info = (data_collection_bucket_time_info_t*)time_node->object;
        data_collection_lnode_t *id_node;
        ogs_list_for_each(&record_id_axis, id_node) {
            data_collection_bucket_identity_info_t *id_info = (data_collection_bucket_identity_info_t*)id_node->object;
            data_collection_lnode_t *locn_node;
            ogs_list_for_each(&record_locn_axis, locn_node) {
                data_collection_bucket_location_info_t *locn_info = (data_collection_bucket_location_info_t*)locn_node->object;
                bucketed_data_worksheet_t *bucket = __results_find_worksheet(result, time_info, id_info, locn_info, handler);
                if (!bucket) {
                    bucket = __bucketed_data_worksheet_new(handler, time_info, id_info, locn_info);
                    buckets_updated++;
                    ogs_list_add(&result->buckets, bucket);
                }
                if (time_info) {
                    /* time window for bucket */
                    /* TODO: add location and identity aggregation functions */
                    ogs_list_t *aggregation_fns = data_collection_model_data_access_profile_time_access_restrictions_get_aggregation_functions(tar);
                    ogs_list_for_each(aggregation_fns, node) {
                        data_collection_data_report_record_t *to_add = NULL;
                        data_collection_model_data_aggregation_function_type_t *daf = node->object;
                        data_collection_model_data_aggregation_function_type_e daf_enum = data_collection_model_data_aggregation_function_type_get_enum(daf);
                        switch (daf_enum) {
                        case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_MEAN:
                        case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_SUM:
                            {
                                /* proportion the data record for the bucket */
                                void *to_add_sample = handler->proportion_record(sample, &time_info->start, &time_info->end);
                                to_add = data_collection_data_report_record_copy_new_result(record, to_add_sample);
                                ogs_debug("Created proportioned record %p (orig. %p) for aggregation \"%s\"", to_add, record, data_collection_model_data_aggregation_function_type_get_string(daf));
                            }
                            break;
                        default:
                            /* For all other aggregation functions we use record mid-point to assign the bucket */
                            if (__bucket_time_info_contains(time_info, &midpoint, NULL)) {
                                /* add record to worksheet for aggregation function */
                                to_add = data_collection_data_report_record_copy(record);
                                ogs_debug("Created reference record %p (orig. %p) for aggregation \"%s\"", to_add, record, data_collection_model_data_aggregation_function_type_get_string(daf));
                            }
                        }
                        if (to_add) {
                            const char *agg_fn_name = data_collection_model_data_aggregation_function_type_get_string(daf);
                            aggregation_data_set_t *agg_data = __bucketed_data_worksheet_get_data_set(bucket, handler, agg_fn_name);
                            if (!agg_data) {
                                agg_data = __aggregation_data_set_new(handler, agg_fn_name);
                                __bucketed_data_worksheet_add_data_set(bucket, agg_data);
                            }
                            ogs_list_add(&agg_data->data_samples, to_add);
                            ogs_debug("Added record %p to aggregation \"%s\"", to_add, agg_fn_name);
                            to_add = NULL;
                        }
                    }
                    data_collection_list_free(aggregation_fns);
                }
            }
        }
    }

    /* tidy up report axis lists */
    data_collection_lnode_t *save;
    ogs_list_t *erase_lists[] = {&record_time_axis, &record_id_axis, &record_locn_axis};
    int i;
    for (i=0; i<sizeof(erase_lists)/sizeof(erase_lists[0]); i++) {
        ogs_list_for_each_safe(erase_lists[i], save, node) {
            ogs_list_remove(erase_lists[i], node);
            data_collection_lnode_free(node);
        }
    }

    return buckets_updated;
}

static data_collection_lnode_t *__set_add_lnode(ogs_list_t *list, data_collection_lnode_t *new_val, bool(*cmp_fn)(const void *a, const void *b))
{
    bool found = false;
    data_collection_lnode_t *node;
    ogs_list_for_each(list, node) {
        if (cmp_fn(node->object, new_val->object)) {
            found = true;
            break;
        }
    }
    if (!found) {
        ogs_list_add(list, new_val);
        node = new_val;
    } else {
        data_collection_lnode_free(new_val);
    }
    return node;
}

static bool __cmp_time_info(const data_collection_bucket_time_info_t *a, const data_collection_bucket_time_info_t *b)
{
    if (a) {
        if (b) {
            if (a != b) {
                if (a->start.tv_sec != b->start.tv_sec) return false;
                if (a->start.tv_nsec != b->start.tv_nsec) return false;
                if (a->end.tv_sec != b->end.tv_sec) return false;
                if (a->end.tv_nsec != b->end.tv_nsec) return false;
            }
        } else {
            return false;
        }
    } else {
        if (b) return false;
    }
    return true;
}

static bool __cmp_id_info(const data_collection_bucket_identity_info_t *a, const data_collection_bucket_identity_info_t *b)
{
    if (a) {
        if (b) {
            if (a != b) {
                if (a->user_id) {
                    if (!b->user_id) return false;
                    if (strcmp(a->user_id, b->user_id)) return false;
                } else {
                    if (b->user_id) return false;
                }
                if (a->group_id) {
                    if (!b->group_id) return false;
                    if (strcmp(a->group_id, b->group_id)) return false;
                } else {
                    if (b->group_id) return false;
                }
            }
        } else {
            return false;
        }
    } else {
        if (b) return false;
    }
    return true;
}

static bool __cmp_locn_info(const data_collection_bucket_location_info_t *a, const data_collection_bucket_location_info_t *b)
{
    if (a) {
        if (b) {
            if (a != b) {
                if (!data_collection_model_geographic_area_is_equal_to(a->location, b->location)) return false;
            }
        } else {
            return false;
        }
    } else {
        if (b) return false;
    }
    return true;
}

static bool __bucket_time_info_contains(const data_collection_bucket_time_info_t *time_info, struct timespec *start, struct timespec *end)
{
    /* if no end point then period just respresented by a single point in time */
    if (!end) {
        return (start->tv_sec > time_info->start.tv_sec || (start->tv_sec == time_info->start.tv_sec && start->tv_nsec >= time_info->start.tv_nsec)) &&
               (start->tv_sec < time_info->end.tv_sec || (start->tv_sec == time_info->end.tv_sec && start->tv_nsec < time_info->end.tv_nsec));
    }

    return (start->tv_sec > time_info->start.tv_sec || (start->tv_sec == time_info->start.tv_sec && start->tv_nsec >= time_info->start.tv_nsec)) && (end->tv_sec < time_info->end.tv_sec || (end->tv_sec == time_info->end.tv_sec && end->tv_nsec <= time_info->end.tv_nsec));
}

#if 0
static bool __bucket_time_info_overlaps(const data_collection_bucket_time_info_t *time_info, struct timespec *start, struct timespec *end)
{
    /* if no end point then period just respresented by a single point in time */
    if (!end) {
        return (start->tv_sec > time_info->start.tv_sec || (start->tv_sec == time_info->start.tv_sec && start->tv_nsec >= time_info->start.tv_nsec)) &&
               (start->tv_sec < time_info->end.tv_sec || (start->tv_sec == time_info->end.tv_sec && start->tv_nsec < time_info->end.tv_nsec));
    }

    return (start->tv_sec < time_info->end.tv_sec || (start->tv_sec == time_info->end.tv_sec && start->tv_nsec < time_info->end.tv_nsec)) && (end->tv_sec > time_info->start.tv_sec || (end->tv_sec == time_info->start.tv_sec && end->tv_nsec > time_info->start.tv_nsec));
}
#endif

static void __aggregate_worksheet_buckets(report_find_result_t *result)
{
    /* loop through buckets applying aggregation functions to their data samples and posting the results into the main result list */
    bucketed_data_worksheet_t *worksheet;
    ogs_list_for_each(&result->buckets, worksheet) {
        ogs_hash_index_t *agg_data_index = ogs_hash_index_make(worksheet->aggregation_data);
        ogs_hash_index_t *it;
        for (it = ogs_hash_next(agg_data_index); it; it = ogs_hash_next(it)) {
            data_collection_data_report_record_t *report_record, *safe_record;
            aggregation_data_set_t *agg_data = (aggregation_data_set_t*)ogs_hash_this_val(it);
            ogs_list_t *agg_reports = agg_data->key.handler->apply_aggregation(agg_data->key.function_name, &agg_data->data_samples);
            ogs_list_for_each_safe(agg_reports, safe_record, report_record) {
                ogs_list_remove(agg_reports, report_record);
                if (!worksheet->bucket.data_samples) worksheet->bucket.data_samples = ogs_calloc(1, sizeof(*worksheet->bucket.data_samples));
                ogs_list_add(worksheet->bucket.data_samples, report_record);
            }
            ogs_free(agg_reports);
        }
        ogs_free(agg_data_index);
    }
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
