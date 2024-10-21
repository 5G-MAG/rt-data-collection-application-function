/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_DATA_REPORTING_H
#define DATA_COLLECTION_DATA_REPORTING_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "sbi/openapi/external/cJSON.h"

#include "ogs-core.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/** Property used to convey report data in a DataReport
 *
 * This indicates which property is used to convey the report data in a DataReport (see TS 26.532 Clause 7.3.2.3)
 */

#define DATA_COLLECTION_DATA_REPORT_PROPERTIES 7

typedef enum {
    DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_ANBR_NET_ASSIST_INVOCATION
} data_collection_data_report_property_e;

typedef enum {
    DATA_COLLECTION_REPORTING_CLIENT_TYPE_DIRECT = 1,
    DATA_COLLECTION_REPORTING_CLIENT_TYPE_INDIRECT,
    DATA_COLLECTION_REPORTING_CLIENT_TYPE_APPLICATION_SERVER
} data_collection_reporting_client_type_e;

/***** Opaque Types *****/

/** Data Report
 *
 * Use data_collection_data_report_*() functions to access this type.
 */
typedef struct data_collection_data_report_record_s data_collection_data_report_record_t;

/** Reporting Session
 *
 * Use data_collection_reporting_session_*() functions to access this type.
 */
typedef struct data_collection_reporting_session_s data_collection_reporting_session_t;

/***** Interface structures *****/

/** Data Report Type
 *
 * Used by an AF implementation to describe the types of DataReport it can handle
 */
typedef struct data_collection_data_report_handler_s {
    const char *type_name;
    data_collection_data_report_property_e data_report_property;
    const char *data_domain;      /* derived from data_report_property if NULL */
    const char *event_type;       /* afEvent enumeration string value or any other string for custom events */
    const char * const *applicable_aggregations; /* NULL terminated array of aggregation function names */
    void *(* const parse_report_data)(const data_collection_reporting_session_t *session, cJSON *json, char **error_return, char **error_classname, char **error_parameter);
    void *(* const clone_report_data)(const void *report_data);
    void (* const free_report_data)(void *report_data);
    cJSON *(* const json_for_report_data)(const void *report_data);
    struct timespec *(* const timestamp_for_report_data)(const void *report_data);
    char *(* const tag_for_report_data)(const void *report_data);
    char *(* const serialise_report_data)(const void *report_data);
    ogs_list_t *(*apply_aggregation)(const char *function_name, const ogs_list_t *records);
    void *(*proportion_record)(const void *record, const struct timespec *start, const struct timespec *end);
    struct timespec *(*sample_start)(const void *record);
    struct timespec *(*sample_end)(const void *record);
} data_collection_data_report_handler_t;

typedef struct data_domain_node_s {
    ogs_lnode_t node;
    char *data_domain;
} data_domain_node_t;

typedef ogs_list_t data_domain_list_t; /* list of data_domain_node_t */

/***** Library function API *****/

/** Create a new data reporting session */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_create(const char *external_app_id, const data_domain_list_t *supported_domains, data_collection_reporting_client_type_e client_type);

/** Destroy a data reporting session */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_session_destroy(data_collection_reporting_session_t *session);

/** Find a data reporting session by the session id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_find(const char *session_id);

/** Refresh the last active time of a data reporting session */
DATA_COLLECTION_SVC_PRODUCER_API const struct timespec* data_collection_reporting_session_refresh(data_collection_reporting_session_t *session);

/** Get the TS 26.532 DataReportingSession JSON structure for a data reporting session */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_session_json(const data_collection_reporting_session_t *session);

/** Find the cached data reports matching the filters */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_report_find(const data_collection_data_report_handler_t* const *report_handlers, data_collection_event_subscription_t *event_subscription, bool omit_used);

/** Get the Opaque Data Report from the Library */
DATA_COLLECTION_SVC_PRODUCER_API void *data_collection_reporting_data_report_get(data_collection_data_report_record_t *data_report);

/** Get the Application ID of the Data Report */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_data_report_get_application_id(const data_collection_data_report_record_t *data_report);

/** Get the data reporting session id */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_session_get_id(const data_collection_reporting_session_t *session);

/** Process a data report from HTTP */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_report(data_collection_reporting_session_t *session, const char *mime_type, const void *data, size_t data_length, char **error_return, char **error_classname, char **error_parameter, const char **error_code);

/** Mark a data report as having been used */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_report_used(data_collection_data_report_record_t *, const data_collection_event_subscription_t *);

/** Expire a data report */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_report_expire(data_collection_data_report_record_t *);

/** Get the AF managed data block for this report */
DATA_COLLECTION_SVC_PRODUCER_API void *data_collection_reporting_data_report_get(data_collection_data_report_record_t *data_report_record);

/**Create a copy of Data Report*/
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_copy(data_collection_data_report_record_t *data_report_record);

/** Delete copied Data Report */

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_data_report_record_copy_delete(data_collection_data_report_record_t *data_report_record);

/** Create a minimal Data Report structure for aggregation */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_aggregation_functions_report_create(void *data_report_record, const char *external_application_id);

/** Prepare a Data Report record for aggregation */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_aggregated_data_report_record(data_collection_data_report_record_t *data_report_record);

/** Set Data Report Record to a Aggregrated Data Report */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_reporting_set_report(data_collection_data_report_record_t *aggregated_data_report_record, void *data_report_record);

/** Get the Data Reporting Session for a Data Report */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_get(data_collection_data_report_record_t *report_record);

/** Destroy a Data Report */

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_report_destroy(data_collection_data_report_record_t *report_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_reporting_add_report_record(data_collection_data_report_record_t *data_report_record_aggregated, data_collection_data_report_record_t *original_data_report_record);

DATA_COLLECTION_SVC_PRODUCER_API size_t data_collection_reporting_get_number_of_original_records(data_collection_data_report_record_t *data_report_record);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_reporting_client_type_cmp_to_model(data_collection_reporting_client_type_e reporting_client_type, data_collection_model_data_collection_client_type_e model_client_type);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_DATA_REPORTING_H */
