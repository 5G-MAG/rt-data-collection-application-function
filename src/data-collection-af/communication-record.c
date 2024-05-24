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

typedef struct dcaf_api_communication_record_s dcaf_api_communication_record_t;

static void *communication_record_parse(const data_collection_reporting_session_t *session, cJSON *json, const char **error_return);
static void *communication_record_clone(const void *to_copy);
static void communication_record_free(void *report);
static cJSON *communication_record_json(const void *report);
static struct timespec *communication_record_timestamp(const void *report);
static char *communication_record_make_tag(const void *report);
static char *communication_record_serialise(const void *report);

static long int get_nsec_from_time_str(const char *time_str);

/* data structures */

const data_collection_data_report_handler_t communication_record_data_report_type = {
    .type_name = "CommunicationRecord",
    .data_report_property = DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION,
    .data_domain = "COMMUNICATION",
    .event_type = "UE_COMM",
    .parse_report_data = communication_record_parse,
    .clone_report_data = communication_record_clone,
    .free_report_data = communication_record_free,
    .json_for_report_data = communication_record_json,
    .timestamp_for_report_data = communication_record_timestamp,
    .tag_for_report_data = communication_record_make_tag,
    .serialise_report_data = communication_record_serialise
};

/* Communication Report handling */
static void *communication_record_parse(const data_collection_reporting_session_t *session, cJSON *json, const char **error_return)
{
    dcaf_api_communication_record_t *communication_record = NULL;	

    ogs_info("PARSE: Example Consumption Report handling");
    {
        char *txt = cJSON_Print(json);
        ogs_debug("Parsed JSON: %s", txt);
        cJSON_free(txt);
    }

    communication_record = dcaf_api_communication_record_parseRequestFromJSON(json, error_return);
	
    return communication_record;
}

static void *communication_record_clone(const void *to_copy)
{
   
    const dcaf_api_communication_record_t *existing_report = (const dcaf_api_communication_record_t*)to_copy;
    return (void*)existing_report;

}

static void communication_record_free(void *report)
{
    if (report)
        ogs_free(report);
}

static cJSON *communication_record_json(const void *report)
{
    cJSON *report_json = NULL;
    dcaf_api_communication_record_t *communication_record = (dcaf_api_communication_record_t *)report;

    if(!communication_record) return NULL;

    report_json = dcaf_api_communication_record_convertRequestToJSON(communication_record);
    return report_json;

}

static struct timespec *communication_record_timestamp(const void *report)
{
    
    static time_t time;
    static struct timespec ts;
    char *timestamp;

    dcaf_api_communication_record_t *communication_report;
    
    communication_report = (dcaf_api_communication_record_t *)report;
    ogs_assert(communication_report->timestamp);
    timestamp = communication_report->timestamp;
    time = str_to_rfc3339_time((const char *)ogs_strdup(timestamp));

    ts.tv_sec = time;
    ts.tv_nsec = get_nsec_from_time_str((const char *)ogs_strdup(timestamp));
    return &ts;
}

static char *communication_record_make_tag(const void *report)
{
    cJSON *report_json;
    char *data_report_to_hash;
    char *data_report_hashed = NULL;
    const dcaf_api_communication_record_t *communication_record = (const dcaf_api_communication_record_t*)report;

    report_json = communication_record_json(communication_record);
    if (!report_json) return NULL;

    data_report_to_hash = cJSON_Print(report_json);
    cJSON_Delete(report_json);

    data_report_hashed = calculate_hash(data_report_to_hash);
    cJSON_free(data_report_to_hash);

    return data_report_hashed;
	
}

static char *communication_record_serialise(const void *report)
{
    const dcaf_api_communication_record_t *existing_report = (const dcaf_api_communication_record_t*)report;
    char *comm_rec_json_str;
    cJSON *json;

    json = communication_record_json(existing_report);
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

    }
    return time_nsec;

}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
