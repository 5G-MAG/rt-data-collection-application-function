/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "openapi/model/dc_api_data_report.h"
#include "data-collection-sp/data-collection.h"
#include "data-collection-sp/data-reporting.h"
#include "context.h"
#include "hash.h"
#include "utilities.h"
#include "data-reporting.h"
#include "data-report.h"
#include "data-report-store.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_report_s {
    ogs_lnode_t node;
    cJSON *data_report;
} data_report_t;
	
static data_collection_report_t *data_collection_report_create(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *handler, void *data_report);	
//static bool data_report_del(ogs_hash_t *data_reports, const char *data_report_type);
//static int free_ogs_hash_data_report(void *rec, const void *key, int klen, const void *value);
static data_collection_data_report_property_e get_report_properties(dc_api_data_report_t *report, ogs_list_t *data_reports);
static void populate_communication_records (dc_api_data_report_t *report, ogs_list_t *data_reports);
//static cJSON *data_collection_report_json(data_collection_report_t *report, cJSON *data_report_json);
static data_collection_data_report_property_e __data_report_handler_report_property(const data_collection_data_report_handler_t *handler);
static data_collection_data_report_property_e __data_domain_to_data_report_property(const char *data_domain);

/*

The library function to handle submitted reports first checks if the MIME type is correct and attempts to parse the message body as a JSON structure. An error is returned if any of these checks fail.

The function then finds all Data Reporting Handlers that have been registered with the library by the Data Collection AF that match the type of Data Report submitted.

The next step is to invoke the secondary parse callback function registered with the library along with the cJSON object and error_return pointer. This validates the semantics of the cJSON object tree and converts it into a C data structure representation of the data in the submitted Data Report. An error is returned to the library if the semantic validation fails. Otherwise, the parsed data object is returned to the library (where it is opaque data). In the initial implementation, this will be passed to another callback to serialise the object which will be dumped to disk.
 
 */

int data_collection_reporting_report(data_collection_reporting_session_t *session, const char *mime_type, const void *data, 
		size_t data_length, const char **error_return, const char **error_code) {
    ogs_info("IN data_collection_reporting_report");
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

    const data_collection_data_report_handler_t * const *handlers = data_collection_self()->config.data_collection_configuration->data_report_handlers;
   
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
                    data_collection_report_create(session, handlers[i], parsed_data);
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

void data_collection_report_destroy(data_collection_report_t *report)
{
    ogs_assert(report);

    /*

    ogs_hash_set(data_collection_self()->data_reports, report->data_report_handler, OGS_HASH_KEY_STRING, NULL);

    if (report->data_report_handler) {
        ogs_free(report->data_report_type);
	report->data_report_type = NULL;
    }
    */
    if (report->hash) {
        ogs_free(report->hash);
	report->hash = NULL;
    }
    if (report->data_report) {
        dc_api_data_report_free(report->data_report);
	report->data_report = NULL;
    }
    ogs_free(report);
}

static data_collection_report_t *data_collection_report_create(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *handler, void *data_report) {

    data_collection_report_t *report;
    //cJSON *report_json;
    cJSON *data_report_json;


    report = ogs_calloc(1, sizeof(data_collection_report_t));
    ogs_assert(report);

    report->data_report_handler = handler; //pointer to handler;
    report->generated = get_time_from_timespec(handler->timestamp_for_report_data(data_report));; // this function returns timespec so change to ogs_time_t;
    report->last_used = ogs_time_now();
    report->session = session;
    report->hash = handler->tag_for_report_data(data_report);
    report->data_report = data_report;
    report->file_path = data_collection_strdup(data_collection_self()->config.data_collection_dir);

    ogs_hash_set(data_collection_self()->data_reports, &report->data_report_handler, sizeof(report->data_report_handler), report);
    
    data_report_json = handler->json_for_report_data(data_report);
    
    //dump to disk report data_collection_report_t stored to disk

    char *report_time = dc_strdup(get_current_time("%Y-%m-%dT%H:%M:%SZ"));
    char *body = cJSON_Print(data_report_json);

    data_collection_report_store(data_collection_strdup(session->data_reporting_session_id), data_collection_strdup(handler->data_domain), report_time, "json", body);
    cJSON_free(body);
    ogs_free(report_time);

    return report;
}
#if 0
static bool data_report_del(ogs_hash_t *data_reports, const char *data_report_handler)
{
    data_collection_report_t *report;

    if (!data_reports) return false;

    ogs_debug("data_report_del(%p, %s)", data_reports, data_report_handler);

    report = (data_collection_report_t *)ogs_hash_get(data_reports, data_report_handler, OGS_HASH_KEY_STRING);

    if (report) {
        ogs_hash_do(free_ogs_hash_data_report, report, data_collection_self()->data_reports);
        return true;
    }

    return false;
}
#endif
#if 0
static int
free_ogs_hash_data_report(void *rec, const void *key, int klen, const void *value)
{
    data_collection_report_t *report = (data_collection_report_t *)rec;

    if (value == report) {
	data_collection_report_destroy(report);    
        ogs_hash_set(data_collection_self()->data_reports, key, klen, NULL);
        ogs_free((void*)key);
        return 0; /* finish search when the first key matches */
    }

    return 1;
}
#endif
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

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
