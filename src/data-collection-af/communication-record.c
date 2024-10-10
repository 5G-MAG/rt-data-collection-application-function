/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "communication-record.h"
#include "regexpr.h"
#include "utilities.h"

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

/* Local functions */

typedef struct data_collection_model_communication_record_s data_collection_model_communication_record_t;

static void *communication_record_parse(const data_collection_reporting_session_t *session, cJSON *json, char **error_return, char **error_class, char **error_param);
static void *communication_record_clone(const void *to_copy);
static void communication_record_free(void *report);
static cJSON *communication_record_json(const void *report);
static struct timespec *communication_record_timestamp(const void *report);
static char *communication_record_make_tag(const void *report);
static char *communication_record_serialise(const void *report);
static ogs_list_t *communication_records_apply_aggregation_function(const char *function_name, const ogs_list_t *records);
static void *communication_record_proportional_data(const void *record, const struct timespec *start, const struct timespec *end);
static struct timespec *communication_record_sample_start(const void *record);
static struct timespec *communication_record_sample_stop(const void *record);
static struct timespec *aggregate_time_interval_start_get(struct timespec *start_time, data_collection_model_communication_record_t *communication_record);
static struct timespec *aggregate_time_interval_stop_get(struct timespec *stop_time, data_collection_model_communication_record_t *communication_record);
static data_collection_data_report_record_t *generate_aggregate_communication_collection_record(struct timespec *start_time, struct timespec *stop_time, int64_t uplink_volume, int64_t downlink_volume, const char *external_application_id);
static data_collection_data_report_record_t *generate_aggregate_communication_record(char *start_time, char *stop_time, int64_t uplink_volume, int64_t downlink_volume, const char *external_application_id);
static const char *communication_record_sample_start_time(const data_collection_model_communication_record_t *record);
static const char *communication_record_sample_stop_time(const data_collection_model_communication_record_t *record);
const char *get_communication_record_start_time(int64_t *input_uplink_array, int64_t *input_downlink_array, char **record_start_time, size_t number_of_records, int64_t aggregated_uplink_result, int64_t aggregated_downlink_result);
static long int get_nsec_from_time_str(const char *time_str);
static int timespec_compare(struct timespec *ts1, struct timespec *ts2);
static struct timespec *populate_start_time_spec_from_communication_record(const data_collection_model_communication_record_t *communication_record);
static struct timespec *populate_stop_time_spec_from_communication_record(const data_collection_model_communication_record_t *communication_record);

/* data structures */

static const char * const comm_record_aggregations[] = {
    "NONE", "MEAN", "MIN", "MAX", "SUM", NULL
};

const data_collection_data_report_handler_t communication_record_data_report_type = {
    .type_name = "CommunicationRecord",
    .data_report_property = DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION,
    .data_domain = "COMMUNICATION",
    .event_type = "UE_COMM",
    .applicable_aggregations = comm_record_aggregations,
    .parse_report_data = communication_record_parse,
    .clone_report_data = communication_record_clone,
    .free_report_data = communication_record_free,
    .json_for_report_data = communication_record_json,
    .timestamp_for_report_data = communication_record_timestamp,
    .tag_for_report_data = communication_record_make_tag,
    .serialise_report_data = communication_record_serialise,
    .apply_aggregation = communication_records_apply_aggregation_function,
    .proportion_record = communication_record_proportional_data,
    .sample_start = communication_record_sample_start,
    .sample_end = communication_record_sample_stop
};

/* Communication Report handling */
static void *communication_record_parse(const data_collection_reporting_session_t *session, cJSON *json, char **error_return, char **error_class, char **error_param)
{
    ogs_info("PARSE: Example Consumption Report handling");
    {
        char *txt = cJSON_Print(json);
        ogs_debug("Parsed JSON: %s", txt);
        cJSON_free(txt);
    }

    if (error_return) *error_return = NULL;
    if (error_class) *error_class = NULL;
    if (error_param) *error_param = NULL;

    return data_collection_model_communication_record_fromJSON(json, true, error_return, error_class, error_param);
}

static void *communication_record_clone(const void *to_copy)
{
   
    const data_collection_model_communication_record_t *existing_report = (const data_collection_model_communication_record_t*)to_copy;
    return (void*)existing_report;

}

static void communication_record_free(void *report)
{
    if (report) data_collection_model_communication_record_free((data_collection_model_communication_record_t *)report);
        //ogs_free(report);
}

static cJSON *communication_record_json(const void *report)
{
    cJSON *report_json = NULL;
    data_collection_model_communication_record_t *communication_record = (data_collection_model_communication_record_t *)report;

    if(!communication_record) return NULL;

    report_json = data_collection_model_communication_record_toJSON(communication_record, false);
    return report_json;

}

static struct timespec *communication_record_timestamp(const void *report)
{
    static struct timespec ts;
    const char *timestamp;
    data_collection_model_communication_record_t *communication_report = (data_collection_model_communication_record_t *)report;

    timestamp = data_collection_model_communication_record_get_timestamp(communication_report);

    ts.tv_sec = str_to_rfc3339_time(timestamp);
    ts.tv_nsec = get_nsec_from_time_str(timestamp);

    return &ts;
}

static struct timespec *communication_record_sample_start(const void *record)
{

    static struct timespec ts;
    const char *start_time;
    const data_collection_model_time_window_t* time_window;
    const data_collection_model_communication_record_t *communication_record =
                                                                (const data_collection_model_communication_record_t *)record;
    time_window = data_collection_model_communication_record_get_time_interval(communication_record);
    start_time = data_collection_model_time_window_get_start_time(time_window);
    ts.tv_sec = str_to_rfc3339_time(start_time);
    ts.tv_nsec = get_nsec_from_time_str(start_time);

    return &ts;

}

static const char *communication_record_sample_start_time(const data_collection_model_communication_record_t *record)
{
    const char *start_time;
    const data_collection_model_time_window_t* time_window;
    time_window = data_collection_model_communication_record_get_time_interval(record);
    start_time = data_collection_model_time_window_get_start_time(time_window);
    return start_time;
}

static const char *communication_record_sample_stop_time(const data_collection_model_communication_record_t *record){
    const char *stop_time;
    const data_collection_model_time_window_t* time_window;
    time_window = data_collection_model_communication_record_get_time_interval(record);
    stop_time = data_collection_model_time_window_get_stop_time(time_window);
    return stop_time;
}

static struct timespec *communication_record_sample_stop(const void *record){
    static struct timespec ts;
    const char *stop_time;
    const data_collection_model_time_window_t* time_window;
    const data_collection_model_communication_record_t *communication_record =
                                                                (const data_collection_model_communication_record_t *)record;
    time_window = data_collection_model_communication_record_get_time_interval(communication_record);
    stop_time = data_collection_model_time_window_get_stop_time(time_window);
    ts.tv_sec = str_to_rfc3339_time(stop_time);
    ts.tv_nsec = get_nsec_from_time_str(stop_time);
    
    return &ts;
}

static char *communication_record_make_tag(const void *report)
{
    cJSON *report_json;
    char *data_report_to_hash;
    char *data_report_hashed = NULL;
    const data_collection_model_communication_record_t *communication_record =
                                                                (const data_collection_model_communication_record_t*)report;

    report_json = data_collection_model_communication_record_toJSON(communication_record, false);
    if (!report_json) return NULL;

    data_report_to_hash = cJSON_Print(report_json);
    cJSON_Delete(report_json);

    data_report_hashed = calculate_hash(data_report_to_hash);
    cJSON_free(data_report_to_hash);

    return data_report_hashed;
}

static char *communication_record_serialise(const void *report)
{
    const data_collection_model_communication_record_t *existing_report =
                                                                 (const data_collection_model_communication_record_t*)report;
    char *comm_rec_json_str;
    cJSON *json;

    json = data_collection_model_communication_record_toJSON(existing_report, false);
    if (!json) return NULL;

    comm_rec_json_str = cJSON_Print(json);
    cJSON_Delete(json);

    return comm_rec_json_str;
}

static ogs_list_t *communication_records_apply_aggregation_function(const char *function_name, const ogs_list_t *records)
{
    data_collection_data_report_record_t *data_report_record;
    data_collection_data_report_record_t *data_report_record_aggregated;
    struct timespec *aggregate_time_interval_start = NULL;
    struct timespec *aggregate_time_interval_stop= NULL;
    size_t number_of_records = ogs_list_count(records);
    int64_t *input_array_uplink;
    int64_t *input_array_downlink;
    char **record_start_time;
    char **record_stop_time;
    const char *external_application_id = NULL;

    input_array_uplink = ogs_calloc(number_of_records, sizeof(*input_array_uplink));
    input_array_downlink = ogs_calloc(number_of_records, sizeof(*input_array_downlink));
    record_start_time = ogs_calloc(number_of_records, sizeof(**record_start_time));
    record_stop_time = ogs_calloc(number_of_records, sizeof(**record_stop_time));
    data_collection_aggregate_result_t *uplink_aggregation_result;
    data_collection_aggregate_result_t *downlink_aggregation_result;
    data_collection_model_communication_record_t *communication_record;
    int i = 0;

    ogs_list_t *aggregation_results = NULL;

    aggregation_results = (ogs_list_t*) ogs_calloc(1,sizeof(*aggregation_results));
    ogs_assert(aggregation_results);
    ogs_list_init(aggregation_results);

    ogs_list_for_each(records, data_report_record) {
	
	data_collection_model_communication_record_t *communication_record = 
		(data_collection_model_communication_record_t *)data_collection_reporting_data_report_get(data_report_record);    
        if(!external_application_id) {
	    external_application_id = data_collection_strdup(data_collection_data_report_get_application_id(data_report_record));
	}
	aggregate_time_interval_start = aggregate_time_interval_start_get(aggregate_time_interval_start, communication_record);
	aggregate_time_interval_stop = aggregate_time_interval_stop_get(aggregate_time_interval_stop, communication_record);
	
	input_array_uplink[i] = data_collection_model_communication_record_get_uplink_volume(communication_record);
        input_array_downlink[i] = data_collection_model_communication_record_get_downlink_volume(communication_record);
        record_start_time[i] = data_collection_strdup(communication_record_sample_start_time(communication_record));
        record_stop_time[i] = data_collection_strdup(communication_record_sample_stop_time(communication_record));
        i++;
    }

    uplink_aggregation_result = data_collection_aggregation_function_int64(function_name, input_array_uplink, number_of_records);
    downlink_aggregation_result = data_collection_aggregation_function_int64(function_name, input_array_downlink, number_of_records);
    
    if(DATA_COLLECTION_AGGREGATION_RESULT_IS_VALUE(*uplink_aggregation_result)){
        data_report_record_aggregated = generate_aggregate_communication_collection_record(aggregate_time_interval_start, aggregate_time_interval_stop, DATA_COLLECTION_AGGREGATION_RESULT_INT64(*uplink_aggregation_result),  DATA_COLLECTION_AGGREGATION_RESULT_INT64(*downlink_aggregation_result), external_application_id); 	    
        ogs_list_add(aggregation_results, data_report_record_aggregated);
    } else if(DATA_COLLECTION_AGGREGATION_RESULT_IS_DOUBLE(*uplink_aggregation_result)){
        data_report_record_aggregated = generate_aggregate_communication_collection_record(aggregate_time_interval_start, aggregate_time_interval_stop, DATA_COLLECTION_AGGREGATION_RESULT_INT64(*uplink_aggregation_result),  DATA_COLLECTION_AGGREGATION_RESULT_INT64(*downlink_aggregation_result), external_application_id);
        ogs_list_add(aggregation_results, data_report_record_aggregated);
    } else if(DATA_COLLECTION_AGGREGATION_RESULT_IS_SIZE(*uplink_aggregation_result)){
        data_report_record_aggregated = generate_aggregate_communication_collection_record(aggregate_time_interval_start, aggregate_time_interval_stop, DATA_COLLECTION_AGGREGATION_RESULT_INT64(*uplink_aggregation_result),  DATA_COLLECTION_AGGREGATION_RESULT_INT64(*downlink_aggregation_result), external_application_id);
        ogs_list_add(aggregation_results, data_report_record_aggregated);
    } else if(DATA_COLLECTION_AGGREGATION_RESULT_IS_ARRAY(*uplink_aggregation_result)){
	int j;    
        int64_t *uplink_array = DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_PTR(*uplink_aggregation_result);
	int64_t *downlink_array = DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_PTR(*downlink_aggregation_result);


	if(DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_SIZE(*uplink_aggregation_result) != number_of_records){
	    ogs_debug("Number of records returned does not match the records sent for aggregation");
	}

	if(DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_SIZE(*uplink_aggregation_result) != DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_SIZE(*downlink_aggregation_result)){
	    ogs_debug("Uplink and Downlink aggregation results length do not match");
	}

	for(j=0; j < DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_SIZE(*uplink_aggregation_result); j++) {
            data_report_record_aggregated = generate_aggregate_communication_record(record_start_time[j], record_stop_time[j], uplink_array[j], downlink_array[j], external_application_id);
            //communication_record_aggregate_node = data_collection_model_communication_record_make_lnode(communication_record);
            ogs_list_add(aggregation_results, data_report_record_aggregated);
        }
    }
    
    ogs_free(input_array_uplink);
    ogs_free(input_array_downlink);

    for(i=0; i < number_of_records; i++) {
        ogs_free(record_start_time[i]);
        ogs_free(record_stop_time[i]);
    }

    if(record_start_time) ogs_free(record_start_time);
    if(record_stop_time) ogs_free(record_stop_time);

    data_collection_aggregation_function_result_free(uplink_aggregation_result);
    data_collection_aggregation_function_result_free(downlink_aggregation_result);
    
    if(aggregate_time_interval_start) ogs_free(aggregate_time_interval_start);
    if(aggregate_time_interval_stop) ogs_free(aggregate_time_interval_stop);

    return aggregation_results; 

}

static void *communication_record_proportional_data(const void *record, const struct timespec *start, const struct timespec *end)
{
 return NULL;	
}


static struct timespec *populate_start_time_spec_from_communication_record(const data_collection_model_communication_record_t *communication_record)
{
    const char *time_str;
    struct timespec *time = ogs_calloc(1, sizeof(*time));
    data_collection_model_time_window_t* time_window;
    time_window = data_collection_model_communication_record_get_time_interval(communication_record);
    time_str = data_collection_model_time_window_get_start_time(time_window);
    time->tv_sec = str_to_rfc3339_time(time_str);
    time->tv_nsec = get_nsec_from_time_str(time_str);
    return time;


}
static struct timespec *populate_stop_time_spec_from_communication_record(const data_collection_model_communication_record_t *communication_record)
{
    const char *time_str;
    struct timespec *time = ogs_calloc(1, sizeof(*time));
    data_collection_model_time_window_t* time_window;
    time_window = data_collection_model_communication_record_get_time_interval(communication_record);
    time_str = data_collection_model_time_window_get_stop_time(time_window);
    time->tv_sec = str_to_rfc3339_time(time_str);
    time->tv_nsec = get_nsec_from_time_str(time_str);
    return time;


}


static struct timespec *aggregate_time_interval_start_get(struct timespec *start_time, data_collection_model_communication_record_t *communication_record){

     size_t rv = 0;
    struct timespec *communication_record_start_time;
    if(!start_time){
        start_time = populate_start_time_spec_from_communication_record(communication_record);
        return start_time;
    } else {
        communication_record_start_time = populate_start_time_spec_from_communication_record(communication_record);

        rv = timespec_compare(start_time, communication_record_start_time);
        if(rv == 1) {
            if(start_time) ogs_free(start_time);
             start_time = communication_record_start_time;
             return start_time;
        } else {
            if(rv == -1 || rv == 0) return start_time;
        }

    }
    if(start_time) ogs_free(start_time);
    start_time = populate_start_time_spec_from_communication_record(communication_record);
    return start_time;
}

static struct timespec *aggregate_time_interval_stop_get(struct timespec *stop_time, data_collection_model_communication_record_t *communication_record){
    size_t rv = 0;
    struct timespec *communication_record_stop_time;
    if(!stop_time){
        stop_time = populate_stop_time_spec_from_communication_record(communication_record);
        return stop_time;
    } else {

        communication_record_stop_time = populate_stop_time_spec_from_communication_record(communication_record);

        rv = timespec_compare(stop_time, communication_record_stop_time);
        if(rv == 1) {
            return stop_time;
        } else if(rv == -1 || rv == 0) {
             if(stop_time) ogs_free(stop_time);
             stop_time = communication_record_stop_time;
             return stop_time;

        }
    }
    if(stop_time) ogs_free(stop_time);
    stop_time = populate_stop_time_spec_from_communication_record(communication_record);
    return stop_time;

}

static data_collection_data_report_record_t *generate_aggregate_communication_collection_record(struct timespec *start_time, struct timespec *stop_time, int64_t uplink_volume, int64_t downlink_volume, const char *external_application_id)
{
    data_collection_model_time_window_t* time_window;
    char *time_start;
    char *time_stop;
    char *timestamp;
    data_collection_model_communication_record_t *communication_record;
    data_collection_data_report_record_t *data_report_record;
    
    time_start = ogs_time_to_string(get_time_from_timespec(start_time), "%Y-%m-%dT%H:%M:%SZ");
    time_stop = ogs_time_to_string(get_time_from_timespec(stop_time), "%Y-%m-%dT%H:%M:%SZ");

    //time_start = ogs_time_to_string(get_time_from_timespec(start_time));
    //time_stop = ogs_time_to_string(get_time_from_timespec(stop_time));
    timestamp = data_collection_strdup(get_current_time("%Y-%m-%dT%H:%M:%SZ"));

    time_window = data_collection_model_time_window_create();
    data_collection_model_time_window_set_start_time(time_window, time_start);
    data_collection_model_time_window_set_stop_time(time_window, time_stop);
 
    communication_record = data_collection_model_communication_record_create();
    data_collection_model_communication_record_set_timestamp(communication_record, timestamp);
    if(downlink_volume)
         data_collection_model_communication_record_set_downlink_volume(communication_record, downlink_volume);
    if(uplink_volume)
         data_collection_model_communication_record_set_uplink_volume(communication_record, uplink_volume);

    data_collection_model_communication_record_set_time_interval_move(communication_record, time_window);
    
    data_report_record = data_collection_aggregation_functions_report_create((void *)communication_record, external_application_id);
 
    return data_report_record; 
}

static data_collection_data_report_record_t *generate_aggregate_communication_record(char *start_time, char *stop_time, int64_t uplink_volume, int64_t downlink_volume, const char *external_application_id)
{
    data_collection_model_time_window_t* time_window;
    char *timestamp;
    data_collection_model_communication_record_t *communication_record;
    data_collection_data_report_record_t *data_report_record;

    timestamp = data_collection_strdup(get_current_time("%Y-%m-%dT%H:%M:%SZ"));

    time_window = data_collection_model_time_window_create();
    data_collection_model_time_window_set_start_time(time_window, start_time);
    data_collection_model_time_window_set_stop_time(time_window, stop_time);

    communication_record = data_collection_model_communication_record_create();
    data_collection_model_communication_record_set_timestamp(communication_record, timestamp);
    if(downlink_volume)
         data_collection_model_communication_record_set_downlink_volume(communication_record, downlink_volume);
    if(uplink_volume)
         data_collection_model_communication_record_set_uplink_volume(communication_record, uplink_volume);

    data_collection_model_communication_record_set_time_interval_move(communication_record, time_window);

    data_report_record = data_collection_aggregation_functions_report_create((void *)communication_record, external_application_id);


    return data_report_record;
}

static int timespec_compare(struct timespec *ts1, struct timespec *ts2)
{
    if(ts1->tv_sec == ts2->tv_sec && ts1->tv_nsec == ts2->tv_nsec)
    {
        return 0;
    } else if((ts1->tv_sec > ts2->tv_sec) || (ts1->tv_sec == ts2->tv_sec && ts1->tv_nsec > ts2->tv_nsec))
    {
        return 1;
    } else {
       return -1;
    }
}



static long int get_nsec_from_time_str(const char *time_str) {

    long int time_nsec = 0; 
    if(!time_nsec_check(time_str)) {
        ogs_error("Malformed time [%s]", time_str);
    } else {
        char *ns;
        char *time;
        char ms[] = "000000000";

        time = dcaf_strdup(time_str);
        strtok_r(time, ".", &ns);
        memcpy(ms, ns, max(9,strlen(ns)));

        time_nsec = ascii_to_long(ms);
        ogs_free(time);
    }
    return time_nsec;

}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
