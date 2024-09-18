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

static long int get_nsec_from_time_str(const char *time_str);

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
    .serialise_report_data = communication_record_serialise
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

static char *communication_record_make_tag(const void *report)
{
    cJSON *report_json;
    char *data_report_to_hash;
    char *data_report_hashed = NULL;
    const data_collection_model_communication_record_t *communication_record = (const data_collection_model_communication_record_t*)report;

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
    const data_collection_model_communication_record_t *existing_report = (const data_collection_model_communication_record_t*)report;
    char *comm_rec_json_str;
    cJSON *json;

    json = data_collection_model_communication_record_toJSON(existing_report, false);
    if (!json) return NULL;

    comm_rec_json_str = cJSON_Print(json);
    cJSON_Delete(json);

    return comm_rec_json_str;
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
