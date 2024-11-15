/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include <inttypes.h>

#include "context.h"
#include "communication-record.h"
#include "utilities.h"

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#define PRIiTIMESPEC PRIi64 ".%09" PRIu64
#define PARiTIMESPEC(ts) (ts).tv_sec, (ts).tv_nsec

/* Local functions */

typedef struct data_collection_model_communication_record_s data_collection_model_communication_record_t;

static void *communication_record_parse(const data_collection_reporting_session_t *session, cJSON *json, char **error_return, char **error_class, char **error_param);
static void *communication_record_clone(const void *to_copy);
static void communication_record_free(void *report);
static cJSON *communication_record_json(const void *report);
static struct timespec *communication_record_timestamp(const void *report);
static char *communication_record_make_tag(const void *report);
static char *communication_record_serialise(const void *report);
static const char *communication_record_aggregation_name(const void *report);
static ogs_list_t *communication_records_apply_aggregation_function(const char *function_name, const ogs_list_t *records);
static void *communication_record_proportional_data(const void *record, const struct timespec *start, const struct timespec *end);
static struct timespec *communication_record_sample_start(const void *record);
static struct timespec *communication_record_sample_stop(const void *record);
static struct timespec *aggregate_time_interval_start_get(struct timespec *start_time, data_collection_model_communication_record_t *communication_record);
static struct timespec *aggregate_time_interval_stop_get(struct timespec *stop_time, data_collection_model_communication_record_t *communication_record);
static ogs_list_t *communication_record_context_ids_get(const void *report);

static data_collection_data_report_record_t *generate_aggregate_communication_record(const char *start_time, const char *stop_time, int64_t uplink_volume, int64_t downlink_volume, const ogs_list_t *original_data_report_records, const char *function_name);
static const char *communication_record_sample_start_time(const data_collection_model_communication_record_t *record);
static const char *communication_record_sample_stop_time(const data_collection_model_communication_record_t *record);
const char *get_communication_record_start_time(int64_t *input_uplink_array, int64_t *input_downlink_array, char **record_start_time, size_t number_of_records, int64_t aggregated_uplink_result, int64_t aggregated_downlink_result);
static void populate_times_from_communication_record(const data_collection_model_communication_record_t *comm_rec,
                                                     struct timespec *start_time, struct timespec *end_time);
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
    .aggregation_name = communication_record_aggregation_name,
    .context_ids = communication_record_context_ids_get,
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

    comm_record_and_aggregation_fname_t *record = ogs_calloc(1, sizeof(*record));

    record->record = data_collection_model_communication_record_fromJSON(json, true, error_return, error_class, error_param);

    return record;
}

static void *communication_record_clone(const void *to_copy)
{
    if (!to_copy) return NULL;

    const comm_record_and_aggregation_fname_t *rec_to_copy = (const comm_record_and_aggregation_fname_t*)to_copy;
    comm_record_and_aggregation_fname_t *record = ogs_calloc(1, sizeof(*record));
    record->record = data_collection_model_communication_record_create_copy(rec_to_copy->record);
    record->aggregation_fn_name = data_collection_strdup(rec_to_copy->aggregation_fn_name);
    
    return record;
}

static void communication_record_free(void *report)
{
    if (!report) return;

    comm_record_and_aggregation_fname_t *record = (comm_record_and_aggregation_fname_t*)report;

    if (record->record) data_collection_model_communication_record_free(record->record);
    if (record->aggregation_fn_name) ogs_free(record->aggregation_fn_name);

    ogs_free(record);
}

static cJSON *communication_record_json(const void *report)
{
    if (!report) return NULL;

    cJSON *report_json = NULL;
    const comm_record_and_aggregation_fname_t *record = (const comm_record_and_aggregation_fname_t*)report;

    if(!record->record) return NULL;

    report_json = data_collection_model_communication_record_toJSON(record->record, false);

    return report_json;
}

static struct timespec *communication_record_timestamp(const void *report)
{
    if (!report) return NULL;

    static struct timespec ts;
    const char *timestamp;
    const comm_record_and_aggregation_fname_t *record = (const comm_record_and_aggregation_fname_t*)report;
    
    timestamp = data_collection_model_communication_record_get_timestamp(record->record);

    str_to_rfc3339_time(timestamp, &ts);

    return &ts;
}

static struct timespec *communication_record_sample_start(const void *record)
{
    if (!record) return NULL;

    static struct timespec ts;
    const char *start_time;
    const data_collection_model_time_window_t* time_window;
    const comm_record_and_aggregation_fname_t *comm_record = (const comm_record_and_aggregation_fname_t*)record;
    time_window = data_collection_model_communication_record_get_time_interval(comm_record->record);
    start_time = data_collection_model_time_window_get_start_time(time_window);
    str_to_rfc3339_time(start_time, &ts);

    return &ts;

}

static const char *communication_record_sample_start_time(const data_collection_model_communication_record_t *record)
{
    if (!record) return NULL;

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
    const comm_record_and_aggregation_fname_t *comm_record = (const comm_record_and_aggregation_fname_t*)record;
    time_window = data_collection_model_communication_record_get_time_interval(comm_record->record);
    stop_time = data_collection_model_time_window_get_stop_time(time_window);
    str_to_rfc3339_time(stop_time, &ts);
    
    return &ts;
}

static char *communication_record_make_tag(const void *report)
{
    if (!report) return NULL;

    cJSON *report_json;
    char *data_report_to_hash;
    char *data_report_hashed = NULL;
    const comm_record_and_aggregation_fname_t *record = (const comm_record_and_aggregation_fname_t*)report;

    report_json = data_collection_model_communication_record_toJSON(record->record, false);
    if (!report_json) return NULL;

    data_report_to_hash = cJSON_Print(report_json);
    cJSON_Delete(report_json);

    data_report_hashed = calculate_hash(data_report_to_hash);
    cJSON_free(data_report_to_hash);

    return data_report_hashed;
}

static char *communication_record_serialise(const void *report)
{
    if (!report) return NULL;

    const comm_record_and_aggregation_fname_t *record = (const comm_record_and_aggregation_fname_t*)report;
    char *comm_rec_json_str;
    cJSON *json;

    json = data_collection_model_communication_record_toJSON(record->record, false);
    if (!json) return NULL;

    comm_rec_json_str = cJSON_Print(json);
    cJSON_Delete(json);

    return comm_rec_json_str;
}

static const char *communication_record_aggregation_name(const void *report)
{
    if (!report) return NULL;
    
    const comm_record_and_aggregation_fname_t *record = (const comm_record_and_aggregation_fname_t*)report;
    return record->aggregation_fn_name;
}

static ogs_list_t *communication_record_context_ids_get(const void *report)
{
    if (!report) return NULL;

    const comm_record_and_aggregation_fname_t *record = (const comm_record_and_aggregation_fname_t*)report;
    return data_collection_model_communication_record_get_context_ids(record->record);
}

static ogs_list_t *communication_records_apply_aggregation_function(const char *function_name, const ogs_list_t *records)
{
    data_collection_data_report_record_t *data_report_record = NULL;
    data_collection_data_report_record_t *data_report_record_aggregated = NULL;
    struct timespec *aggregate_time_interval_start = NULL;
    struct timespec *aggregate_time_interval_stop= NULL;
    size_t number_of_records = ogs_list_count(records);
    int64_t *input_array_uplink;
    int64_t *input_array_downlink;
    char **record_start_time;
    char **record_stop_time;

    input_array_uplink = ogs_calloc(number_of_records, sizeof(*input_array_uplink));
    input_array_downlink = ogs_calloc(number_of_records, sizeof(*input_array_downlink));
    record_start_time = ogs_calloc(number_of_records, sizeof(char **));
    record_stop_time = ogs_calloc(number_of_records, sizeof(char **));
    data_collection_aggregate_result_t *uplink_aggregation_result;
    data_collection_aggregate_result_t *downlink_aggregation_result;
    int i = 0, k = 0;

    ogs_list_t *aggregation_results = NULL;

    aggregation_results = (ogs_list_t*) ogs_calloc(1,sizeof(*aggregation_results));
    ogs_assert(aggregation_results);
    ogs_list_init(aggregation_results);

    ogs_list_for_each(records, data_report_record) {
	
        const comm_record_and_aggregation_fname_t *record = (const comm_record_and_aggregation_fname_t*)data_collection_data_report_record_get_data_sample(data_report_record);
	data_collection_model_communication_record_t *communication_record = record->record;
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
    
    data_collection_model_communication_record_t *new_sample = data_collection_model_communication_record_create();
    ogs_assert(new_sample);

    data_collection_model_communication_record_set_timestamp(new_sample, get_current_time("%Y-%m-%dT%H:%M:%SZ"));
    data_collection_model_time_window_t *new_sample_timewindow = data_collection_model_time_window_create();
    data_collection_model_time_window_set_start_time_move(new_sample_timewindow, ogs_time_to_string(get_time_from_timespec(aggregate_time_interval_start), "%Y-%m-%dT%H:%M:%SZ"));
    data_collection_model_time_window_set_stop_time_move(new_sample_timewindow, ogs_time_to_string(get_time_from_timespec(aggregate_time_interval_stop), "%Y-%m-%dT%H:%M:%SZ"));
    data_collection_model_communication_record_set_time_interval_move(new_sample, new_sample_timewindow);

    if(DATA_COLLECTION_AGGREGATION_RESULT_IS_VALUE(*uplink_aggregation_result)){
        data_collection_model_communication_record_set_uplink_volume(new_sample, DATA_COLLECTION_AGGREGATION_RESULT_INT64(*uplink_aggregation_result));
        data_collection_model_communication_record_set_downlink_volume(new_sample, DATA_COLLECTION_AGGREGATION_RESULT_INT64(*downlink_aggregation_result));
    } else if(DATA_COLLECTION_AGGREGATION_RESULT_IS_DOUBLE(*uplink_aggregation_result)){
        data_collection_model_communication_record_set_uplink_volume(new_sample, (int64_t)DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*uplink_aggregation_result));
        data_collection_model_communication_record_set_downlink_volume(new_sample, (int64_t)DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*downlink_aggregation_result));
    } else if(DATA_COLLECTION_AGGREGATION_RESULT_IS_SIZE(*uplink_aggregation_result)){
        data_collection_model_communication_record_set_uplink_volume(new_sample, (int64_t)DATA_COLLECTION_AGGREGATION_RESULT_SIZE(*uplink_aggregation_result));
        data_collection_model_communication_record_set_downlink_volume(new_sample, (int64_t)DATA_COLLECTION_AGGREGATION_RESULT_SIZE(*downlink_aggregation_result));
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
            data_report_record_aggregated = generate_aggregate_communication_record(record_start_time[j], record_stop_time[j], uplink_array[j], downlink_array[j], records, function_name);
            //communication_record_aggregate_node = data_collection_model_communication_record_make_lnode(communication_record);
            ogs_list_add(aggregation_results, data_report_record_aggregated);
        }
        /* records already added */
        data_collection_model_communication_record_free(new_sample);
        new_sample = NULL;
    }

    if (new_sample) {
        comm_record_and_aggregation_fname_t *record = ogs_calloc(1, sizeof(*record));
        record->record = new_sample;
        record->aggregation_fn_name = data_collection_strdup(function_name);
        data_report_record_aggregated = data_collection_data_report_record_create_aggregated(record, records);
        ogs_list_add(aggregation_results, data_report_record_aggregated);
    }

    for(k = 0; k < number_of_records; k++) {
        ogs_free((*(record_start_time + k)));
        ogs_free((*(record_stop_time + k)));
    }


    if (record_start_time) ogs_free(record_start_time);
    if (record_stop_time) ogs_free(record_stop_time);

    if (input_array_uplink) ogs_free(input_array_uplink);
    if (input_array_downlink) ogs_free(input_array_downlink);

    data_collection_aggregation_function_result_free(uplink_aggregation_result);
    data_collection_aggregation_function_result_free(downlink_aggregation_result);
    
    if (aggregate_time_interval_start) ogs_free(aggregate_time_interval_start);
    if (aggregate_time_interval_stop) ogs_free(aggregate_time_interval_stop);

    return aggregation_results; 

}

static void *communication_record_proportional_data(const void *record, const struct timespec *start, const struct timespec *end)
{
    /* if we have no record or no time window then we can't create a new proportioned record */
    if (!record || !start || !end) {
        ogs_warn("Attempt to proportion record without a record or without proper time window (record=%p, start=%p, end=%p)", record, start, end);
        return NULL;
    }

    /* if the time window is not a positive duration then we can't create a new proportioned record */
    if (start->tv_sec > end->tv_sec || (start->tv_sec == end->tv_sec && start->tv_nsec >= end->tv_nsec)) {
        ogs_warn("Attempt to proportion record with backwards time window, %" PRIiTIMESPEC " to %" PRIiTIMESPEC, PARiTIMESPEC(*start), PARiTIMESPEC(*end));
        return NULL;
    }

    /* return a CommunicationRecord that represents the proportion of _record_ that overlaps with [_start_ .. _end_) or NULL if
     * no overlap */
    const comm_record_and_aggregation_fname_t *sample_record = (const comm_record_and_aggregation_fname_t*)record;
    const data_collection_model_communication_record_t *comm_rec = sample_record->record;

    struct timespec rec_start;
    struct timespec rec_end;
    populate_times_from_communication_record(comm_rec, &rec_start, &rec_end);

    /* if no overlap between [rec_start .. rec_end) and [start .. end) then return NULL */
    if (rec_end.tv_sec < start->tv_sec || (rec_end.tv_sec == start->tv_sec && rec_end.tv_nsec <= start->tv_nsec) ||
        rec_start.tv_sec > end->tv_sec || (rec_start.tv_sec == end->tv_sec && rec_start.tv_nsec >= end->tv_nsec)) {
        ogs_debug("Record of [%" PRIiTIMESPEC "..%" PRIiTIMESPEC ") does not overlap [%" PRIiTIMESPEC "..%" PRIiTIMESPEC ")", PARiTIMESPEC(rec_start), PARiTIMESPEC(rec_end), PARiTIMESPEC(*start), PARiTIMESPEC(*end));
        return NULL;
    }

    /* calculate overlap period */
    struct timespec overlap_start;
    if (rec_start.tv_sec < start->tv_sec || (rec_start.tv_sec == start->tv_sec && rec_start.tv_nsec < start->tv_nsec)) {
        overlap_start = *start;
    } else {
        overlap_start = rec_start;
    }

    struct timespec overlap_end;
    if (rec_end.tv_sec > end->tv_sec || (rec_end.tv_sec == end->tv_sec && rec_end.tv_nsec > end->tv_nsec)) {
        overlap_end = *end;
    } else {
        overlap_end = rec_end;
    }

    ogs_debug("Record of [%" PRIiTIMESPEC "..%" PRIiTIMESPEC ") overlaps [%" PRIiTIMESPEC "..%" PRIiTIMESPEC ") at [%" PRIiTIMESPEC "..%" PRIiTIMESPEC ")", PARiTIMESPEC(rec_start), PARiTIMESPEC(rec_end), PARiTIMESPEC(*start), PARiTIMESPEC(*end), PARiTIMESPEC(overlap_start), PARiTIMESPEC(overlap_end));

    /* base the return value on the original CommunicationRecord */
    data_collection_model_communication_record_t *ret = data_collection_model_communication_record_create_copy(comm_rec);

    /* if [overlap_start .. overlap_end) != [rec_start .. rec_end) then calculate the proportion of [rec_start .. rec_end)
     * represented by [overlap_start .. overlap_end) and modify the return record accordingly. */
    if (overlap_start.tv_sec != rec_start.tv_sec || overlap_start.tv_nsec != rec_start.tv_nsec ||
        overlap_end.tv_sec != rec_end.tv_sec || overlap_end.tv_nsec != rec_end.tv_nsec) {
        /* store the new time window */
        data_collection_model_time_window_t *time_window = data_collection_model_time_window_create();
        data_collection_model_time_window_set_start_time_move(time_window, ogs_time_to_string(get_time_from_timespec(&overlap_start), "%Y-%m-%dT%H:%M:%SZ"));
        data_collection_model_time_window_set_stop_time_move(time_window, ogs_time_to_string(get_time_from_timespec(&overlap_end), "%Y-%m-%dT%H:%M:%SZ"));
        data_collection_model_communication_record_set_time_interval_move(ret, time_window);

        /* proportion the amount of downlink and uplink data */
        ogs_debug("overlap period = %" PRIi64 " ns", ((overlap_end.tv_sec - overlap_start.tv_sec) * 1000000000 + overlap_end.tv_nsec - overlap_start.tv_nsec));
        ogs_debug("record period = %" PRIi64 " ns", ((rec_end.tv_sec - rec_start.tv_sec) * 1000000000 + rec_end.tv_nsec - rec_start.tv_nsec));
        double proportion = ((overlap_end.tv_sec - overlap_start.tv_sec) * 1000000000.0 + overlap_end.tv_nsec - overlap_start.tv_nsec)/((rec_end.tv_sec - rec_start.tv_sec) * 1000000000.0 + rec_end.tv_nsec - rec_start.tv_nsec);
        ogs_debug("Proportion multiplier = %f", proportion); 
        data_collection_model_communication_record_set_downlink_volume(ret, (int64_t)(data_collection_model_communication_record_get_downlink_volume(ret)*proportion));
        data_collection_model_communication_record_set_uplink_volume(ret, (int64_t)(data_collection_model_communication_record_get_uplink_volume(ret)*proportion));
    }

    comm_record_and_aggregation_fname_t *ret_record = ogs_calloc(1, sizeof(*ret_record));
    ret_record->record = ret;
    ret_record->aggregation_fn_name = data_collection_strdup("None");

    return ret_record; 
}

static void populate_times_from_communication_record(const data_collection_model_communication_record_t *comm_rec,
                                                     struct timespec *start_time, struct timespec *end_time)
{
    if (!start_time && !end_time) return;
    if (!comm_rec) {
        if (start_time) {
            start_time->tv_sec = 0;
            start_time->tv_nsec = 0;
        }
        if (end_time) {
            end_time->tv_sec = 0;
            end_time->tv_nsec = 0;
        }
        return;
    }

    const data_collection_model_time_window_t* time_window = data_collection_model_communication_record_get_time_interval(comm_rec);

    if (start_time) {
        const char *time_str = data_collection_model_time_window_get_start_time(time_window);
        str_to_rfc3339_time(time_str, start_time);
    }

    if (end_time) {
        const char *time_str = data_collection_model_time_window_get_stop_time(time_window);
        str_to_rfc3339_time(time_str, end_time);
    }
}

static struct timespec *populate_start_time_spec_from_communication_record(const data_collection_model_communication_record_t *communication_record)
{
    struct timespec *time = ogs_calloc(1, sizeof(*time));
    populate_times_from_communication_record(communication_record, time, NULL);
    return time;
}

static struct timespec *populate_stop_time_spec_from_communication_record(const data_collection_model_communication_record_t *communication_record)
{
    struct timespec *time = ogs_calloc(1, sizeof(*time));
    populate_times_from_communication_record(communication_record, NULL, time);
    return time;
}

static struct timespec *aggregate_time_interval_start_get(struct timespec *start_time, data_collection_model_communication_record_t *communication_record){

    if (!start_time) return populate_start_time_spec_from_communication_record(communication_record);

    struct timespec communication_record_start_time;
    populate_times_from_communication_record(communication_record, &communication_record_start_time, NULL);

    /* if the record start time is earlier than _start_time_ then return the record start as the new start time */
    if (timespec_cmp(start_time, &communication_record_start_time) == 1) {
        ogs_free(start_time); /* free the old start time we're replacing */
        start_time = ogs_malloc(sizeof(*start_time));
        *start_time = communication_record_start_time;
    }

    return start_time;
}

static struct timespec *aggregate_time_interval_stop_get(struct timespec *stop_time, data_collection_model_communication_record_t *communication_record){
    if (!stop_time) return populate_stop_time_spec_from_communication_record(communication_record);

    struct timespec communication_record_stop_time;
    populate_times_from_communication_record(communication_record, NULL, &communication_record_stop_time);

    /* if the record end time is later than _stop_time_ then return the record end as the new stop time */
    if (timespec_cmp(stop_time, &communication_record_stop_time) != 1) {
        ogs_free(stop_time); /* free the old stop time we're replacing */
        stop_time = ogs_malloc(sizeof(*stop_time));
        *stop_time = communication_record_stop_time;
    }

    return stop_time;

}

static data_collection_data_report_record_t *generate_aggregate_communication_record(const char *start_time, const char *stop_time, int64_t uplink_volume, int64_t downlink_volume, const ogs_list_t *original_data_report_records, const char *function_name)
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
    data_collection_model_communication_record_set_timestamp_move(communication_record, timestamp);
    if(downlink_volume)
         data_collection_model_communication_record_set_downlink_volume(communication_record, downlink_volume);
    if(uplink_volume)
         data_collection_model_communication_record_set_uplink_volume(communication_record, uplink_volume);

    data_collection_model_communication_record_set_time_interval_move(communication_record, time_window);

    comm_record_and_aggregation_fname_t *record = ogs_calloc(1, sizeof(*record));
    record->record = communication_record;
    record->aggregation_fn_name = data_collection_strdup(function_name);

    data_report_record = data_collection_data_report_record_create_aggregated(record, original_data_report_records);

    return data_report_record;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
