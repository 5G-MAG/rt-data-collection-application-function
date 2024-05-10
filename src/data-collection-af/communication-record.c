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

static long int get_nsec_from_time_str(const char *time_str);

static int timespec_to_str(char *buf, uint len, struct timespec *ts);


/* Communication Report handling */
void *communication_record_parse(const data_collection_reporting_session_t *session, cJSON *json, const char **error_return)
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

void *communication_record_clone(const void *to_copy)
{
   
    const dcaf_api_communication_record_t *existing_report = (const dcaf_api_communication_record_t*)to_copy;
    return (void*)existing_report;

}

void communication_record_free(void *report)
{
    if (report)
        ogs_free(report);
}

cJSON *communication_record_json(const void *report)
{
    cJSON *report_json = NULL;
    dcaf_api_communication_record_t *communication_record;
    cJSON *communication_record_json = NULL;
    cJSON *item = NULL;

    communication_record = (dcaf_api_communication_record_t *)report;
    if(!communication_record) return NULL;

    report_json = dcaf_api_communication_record_convertRequestToJSON(communication_record);
    return report_json;

}

struct timespec *communication_record_timestamp(const void *report)
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

/* Temporary event exposure callback until event-exposure.c is written */
ogs_list_t *event_exposure_generate_callback(data_collection_event_subscription_t *data_collection_event_subscription)
{
  return NULL;
}


static long int get_nsec_from_time_str(const char *time_str) {

    long int time_nsec = 0; 
    if(!time_nsec_check(time_str)) {
        ogs_error("Malformed time [%s]", time_str);
        //return time_nsec;
    } /*else*/ 
    {
        char *ns;
        char *sec;
        char *time;
        char ms[] = "000000000";
	int i;

        time = dcaf_strdup(time_str);
        sec = strtok_r(time, ".", &ns);

	char millis[strlen(ns)];

        for (i = 0; i<strlen(ns); i++)
        {
            if (ns[i] >= '0' && ns[i] <= '9') {
                millis[i] =  ns[i];
            }
            else {
                millis[i] = '0';
            }
        }
        millis[strlen(ns)-1] = '\0';

        strncpy(ms, millis, max(9,strlen(millis)));

        time_nsec = ascii_to_long(ms);

    }
    return time_nsec;

}

static int timespec_to_str(char *buf, uint len, struct timespec *ts) {
    int ret;
    struct tm t;

    tzset();
    if (localtime_r(&(ts->tv_sec), &t) == NULL)
        return 1;

    ret = strftime(buf, len, "%F %T", &t);
    if (ret == 0)
        return 2;
    len -= ret - 1;

    ret = snprintf(&buf[strlen(buf)], len, ".%09ld", ts->tv_nsec);
    if (ret >= len)
        return 3;

    return 0;
}

char *communication_record_make_tag(const void *report)
{
    cJSON *report_json;
    char *data_report_to_hash;
    char *data_report_hashed = NULL;
    dcaf_api_communication_record_t *communication_record;

    communication_record = (dcaf_api_communication_record_t *)report;
    if(!communication_record) return NULL;

    report_json = dcaf_api_communication_record_convertRequestToJSON(communication_record);
    if (!report_json) return NULL;

    data_report_to_hash = cJSON_Print(report_json);
    cJSON_Delete(report_json);

    data_report_hashed = calculate_hash(data_report_to_hash);
    cJSON_free(data_report_to_hash);

    return data_report_hashed;
	
}

char *communication_record_serialise(const void *report)
{
    const dcaf_api_communication_record_t *existing_report = (const dcaf_api_communication_record_t*)report;
    return NULL;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
