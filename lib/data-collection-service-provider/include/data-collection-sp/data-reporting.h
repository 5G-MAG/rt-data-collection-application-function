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

/** \addtogroup dcsp
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/** Property used to convey report data in a DataReport
 *
 * This indicates which property is used to convey the report data in a DataReport (see TS 26.532 Clause 7.3.2.3)
 */
typedef enum {
    DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE = 1,   /**< "serviceExperienceRecords" field present in DataReport */
    DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION,                 /**< "locationRecords" field present in DataReport */
    DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION,            /**< "communicationRecords" field present in DataReport */
    DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE,              /**< "performanceDataRecords" field present in DataReport */
    DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC,             /**< "applicationSpecificRecords" field present in DataReport */
    DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN,                /**< "tripPlanRecords" field present in DataReport */
    DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS,   /**< "mediaStreamingAccessRecords" field present in DataReport */
    DATA_COLLECTION_DATA_REPORT_PROPERTY_ANBR_NET_ASSIST_INVOCATION /**< "aNBRNetworkAssistanceInvocationRecords" field present in DataReport */
} data_collection_data_report_property_e;

/** Type of data reporting client
 *
 * This indicates whether a data reporting session was initiated from a direct client (via interface R2), indirect client (via
 * interface R3) or application server (via interface R4).
 */
typedef enum {
    DATA_COLLECTION_REPORTING_CLIENT_TYPE_DIRECT = 1,         /**< Data reporting session via R2 for direct clients */
    DATA_COLLECTION_REPORTING_CLIENT_TYPE_INDIRECT,           /**< Data reporting session via R3 for indirect clients */
    DATA_COLLECTION_REPORTING_CLIENT_TYPE_APPLICATION_SERVER  /**< Data reporting session via R4 for application servers */
} data_collection_reporting_client_type_e;

/***** Opaque Types *****/

/** \cond FORWARD_DECL */
/** \struct data_collection_data_report_record_t data-report-record.h
 * Data Report
 */
typedef struct data_collection_data_report_record_s data_collection_data_report_record_t;
/** \struct data_collection_data_report_handler_t
 * Report handler
 */
typedef struct data_collection_data_report_handler_s data_collection_data_report_handler_t;
/** \endcond */

/** Reporting Session
 *
 * Use data_collection_reporting_session_*() functions to access this type.
 */
typedef struct data_collection_reporting_session_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_reporting_session_t;

/***** Interface structures *****/

/** Reporting bucket time axis information
 *
 * This holds the time axis information for a reporting bucket.
 */
typedef struct data_collection_bucket_time_info_s {
    struct timespec start; /**< Start time of time period for this bucket */
    struct timespec end;   /**< End time of time period for this bucket */
} data_collection_bucket_time_info_t;

/** Reporting bucket user/group axis information
 *
 * This holds the user/group axis information for a reporting bucket.
 *
 * One of either #user_id or #group_id will be set, the other will be `NULL`.
 */
typedef struct data_collection_bucket_identity_info_s {
    char *user_id; /**< UE User Id for this bucket or `NULL`. */
    char *group_id; /**< UE Group Id for this bucket or `NULL`. */
} data_collection_bucket_identity_info_t;

/** Reporting bucket geographic location axis information
 *
 * This holds the geographic location information for a reporting bucket.
 */
typedef struct data_collection_bucket_location_info_s {
    data_collection_model_geographic_area_t *location; /**< The geographic location for this bucket. */
} data_collection_bucket_location_info_t;

/** Reporting bucket information
 *
 * This holds the information about the bucket
 */
typedef struct data_collection_bucket_info_s {
    const data_collection_bucket_time_info_t *time;         /**< The time axis information or `NULL` for no axis. */
    const data_collection_bucket_identity_info_t *identity; /**< The user/group axis information or `NULL` for no axis. */
    const data_collection_bucket_location_info_t *location; /**< The geographic location axis information or `NULL` for no axis. */
    const data_collection_data_report_handler_t *report_handler; /**< The report handler for the samples in this bucket. */
} data_collection_bucket_info_t;

typedef struct data_collection_bucketed_data_s {
    ogs_lnode_t node;                          /**< This can be an Open5GS list node. */
    data_collection_bucket_info_t bucket_info; /**< The axis information for this bucket. */
    ogs_list_t *data_samples;                  /**< The list of (possibly aggregated) data_collection_data_report_record_t's. */
} data_collection_bucketed_data_t;

/** Data Report Type
 *
 * This is used by an AF implementation to describe the types of DataReport it can handle
 */
typedef struct data_collection_data_report_handler_s {
    const char *type_name;        /**< A type name to be used in human readable outputs (logs, etc.). */
    data_collection_data_report_property_e data_report_property; /**< The property of a DataReport that holds the records. */
    const char *data_domain;      /**< The data domain name for the report type. Derived from #data_report_property if set to NULL. */
    const char *event_type;       /**< afEvent enumeration string value for standard event types or any other string for custom events. */
    const char * const *applicable_aggregations; /**< `NULL` terminated array of applicable aggregation function names. */
    /** Data record sample parsing callback
     * 
     * This callback is called by the library to parse an single data sample entry from a DataReport.
     *
     * @param session The reporting session the DataReport arrived for.
     * @param json    The cJSON tree to parse the sample record from.
     * @param[out] error_return Will contain an error reason string on failure.
     * @param[out] error_classname Will contain the class name that generated the error if appropriate or `NULL` for no class name.
     * @param[out] error_parameter Will contain the JSON path of the parameter caused the failure or `NULL` if the failure was not
     *                             caused by a specific parameter.
     *
     * @return The data sample parsed or `NULL` if the parsing failed.
     */
    void *(* const parse_report_data)(const data_collection_reporting_session_t *session, cJSON *json, char **error_return, char **error_classname, char **error_parameter);
    /** Data record clone sample callback
     *
     * This callback is called by the library to create a copy of a data sample.
     *
     * @param report_data The report sample to copy.
     *
     * @return A new report sample with the same values as @a report_data. 
     */
    void *(* const clone_report_data)(const void *report_data);
    /** Data record free sample resources callback
     *
     * This is used by the library to free the resources associated with the data sample.
     *
     * @param report_data The report sample to delete.
     */
    void (* const free_report_data)(void *report_data);
    /** Data record convert sample to a cJSON tree callback
     *
     * This is used by the library to convert the data sample.
     *
     * @param report_data The report sample to return the cJSON tree for.
     *
     * @return A cJSON tree representation of the data sample.
     */
    cJSON *(* const json_for_report_data)(const void *report_data);
    /** Get a data sample timestamp
     * 
     * Get and return the timestamp from the data sample.
     *
     * @param report_data The report sample to examine.
     *
     * @return The timestamp of the sample record or `NULL` if the sample record does not contain a timestamp.
     */
    struct timespec *(* const timestamp_for_report_data)(const void *report_data);
    /** Generate an ETag for a data sample
     * 
     * Generate an instance tag for this data sample. This is not a random tag id, the same data sample will generate the same tag
     * each time this callback is called.
     *
     * @param report_data The report sample to use.
     *
     * @return An instance tag for the data sample, the caller must use ogs_free() to free the tag when it is no longer needed.
     */
    char *(* const tag_for_report_data)(const void *report_data);
    /** Generate a human readable version of the data sample
     *
     * This is used by the library for reporting the data sample value(s) to a log file or in an error report.
     *
     * @param report_data The report sample to use.
     *
     * @return A human readable representation of the sample data.
     */
    char *(* const serialise_report_data)(const void *report_data);
    /** Get the name of the aggregation function applied to create this data sample.
     * 
     * This is used by the library and AF to determine the aggregation function that was used to generate this data sample.
     *
     * If this sample has not been created as part of an aggregation then this will return `NULL`.
     *
     * @param report_data The report sample to use.
     *
     * @return The name of the aggregation function used to create this sample or `NULL`.
     */
    const char *(* const aggregation_name)(const void *report_data);
    /** Get the list of contextIds that this data sample was sampled against
     *
     * The library uses this callback to discover which contextIds the data sample was reported against so that it can filter
     * using relevant DataReportingConfiguration.DataAccessProfile objects.
     *
     * @param report The report sample to use.
     *
     * @return The list of contextIds that the data was sampled for. It is up to the caller to free the list with
     *         data_collection_list_free().
     */
    ogs_list_t *(*context_ids)(const void *report);
    /** Apply an aggregation function to a set of data_collection_data_report_record_t objects
     *
     * Applies the named aggregation function to the set of data samples referenced by the @a records list. The result of the
     * aggregation will be 1 or more aggregated data_collection_data_report_record_t objects.
     *
     * For example the "SUM" aggregation would take a set of records and produce a single record which represents the sum of the
     * same fields from all records in @a records.
     *
     * The AF implementing this callback may choose to pass arrays of each value field in the data sample to the
     * data_collection_aggregation_function_*() function appropriate to the field data type for the standard set of aggregation
     * functions, or may choose to implement it's own aggregation function for custom aggregations.
     *
     * @param function_name The aggregation function to apply to the set of @a records.
     * @param records A set of data_collection_data_report_record_t objects to aggregate.
     *
     * @return A list of aggregated data_collection_data_report_record_t objects.
     */
    ogs_list_t *(*apply_aggregation)(const char *function_name, const ogs_list_t *records);
    /** Return a proportion of a data sample
     *
     * This callback is called by the library to crop a data sample to represent to proportion that would fall within the time
     * window given by @a start and @a end.
     *
     * @param record The data sample to crop.
     * @param start The start time of the time window to crop the result into.
     * @param end The end time of the time window to crop the result into.
     *
     * @return A new data sample representing the proportion of @a record that falls between @a start and @a end.
     */
    void *(*proportion_record)(const void *record, const struct timespec *start, const struct timespec *end);
    /** Return the start time of the time window for a data sample
     *
     * Get the start time of the time window that the data sample represents.
     *
     * @param record The data sample to examine.
     *
     * @return The start time of the time window that the data sample represents.
     */
    struct timespec *(*sample_start)(const void *record);
    /** Return the end time of the time window for a data sample
     *
     * Get the end time of the time window that the data sample represents.
     *
     * @param record The data sample to examine.
     *
     * @return The end time of the time window that the data sample represents.
     */
    struct timespec *(*sample_end)(const void *record);
} data_collection_data_report_handler_t;

/** List node for data domain names
 *
 * This is a list node suitable for adding to an ogs_list_t which represents a list of data domain strings.
 */
typedef struct data_domain_node_s {
    ogs_lnode_t node;  /**< This is an Open5GS list node */
    char *data_domain; /**< The data domain string */
} data_domain_node_t;

typedef ogs_list_t data_domain_list_t; /**< list of data_domain_node_t */

/***** Library function API *****/

/** Create a new data reporting session
 * \public \memberof data_collection_reporting_session_t
 *
 * Creates a new reporting session object
 *
 * @param external_app_id The external application id for the app requesting the reporting session.
 * @param supported_domains The list of data domains the UE is willing to provide reports for.
 * @param client_type The type of data reporting client (direct, indirect or application server).
 *
 * @return A new reporting session object. 
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_create(const char *external_app_id, const data_domain_list_t *supported_domains, data_collection_reporting_client_type_e client_type);

/** Destroy a data reporting session
 * \public \memberof data_collection_reporting_session_t
 *
 * Delete and remove a data reporting session from the library.
 *
 * @param session The data reporting session to delete.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_session_destroy(data_collection_reporting_session_t *session);

/** Find a data reporting session by the session id
 * \public \memberof data_collection_reporting_session_t
 *
 * Find a reporting session that matches @a session_id.
 *
 * @return The reporting session that matches @a session_id or `NULL` if no such reporting session can be found.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_reporting_session_find(const char *session_id);

/** Refresh the last active time of a data reporting session
 * \public \memberof data_collection_reporting_session_t
 *
 * Resets the timestamp for when this reporting session was last used. Please note that old sessions will be assumed to be abandoned
 * and will be destroyed if they have not been accessed recently.
 *
 * If the AF is handling reporting sessions directly with the data reporting clients, i.e. it is not using the built in library
 * handling for R2, R3 and R4 interfaces, then the AF should call this function when a data reporting client makes any request
 * against a reporting session, either directly (e.g. session create, retrieve and modify operations) or indirectly (e.g.
 * submitting a data report against a reporting session).
 *
 * @param session The reporting session to mark as recently used.
 *
 * @return The timestamp as recorded for the reporting session.
 */
DATA_COLLECTION_SVC_PRODUCER_API const struct timespec* data_collection_reporting_session_refresh(data_collection_reporting_session_t *session);

/** Get the TS 26.532 DataReportingSession JSON structure for a data reporting session
 * \public \memberof data_collection_reporting_session_t
 *
 * This will generate a cJSON tree for the DataReportingSession object represented by this data reporting session.
 *
 * @param session The reporting session to base the result on.
 *
 * @return A cJSON tree containing a TS 26.532 DataReportingSession representation of @a session. It is the responsibility of the
 *         caller to use cJSON_Delete() on this result when it is no longer needed.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_session_json(const data_collection_reporting_session_t *session);

/** Find the cached data reports matching the filters
 * \public \memberof data_collection_data_report_handler_t
 *
 * Query the data samples database for bucketed aggregated samples applicable to a given @a event_subscription. Additionally the
 * returned samples may filter out data samples used previously to generate event exposure notifications for the
 * @a event_subscription by setting the @a omit_used flag to `true`.
 *
 * @param report_handlers A `NULL` terminated array of data sample types (indicated by data_collection_data_report_handler_t*) to
 *                        retrieve the samples for.
 * @param event_subscription The event subscription to use to filter results. Only results matching a `DataAccessProfile` suitable
 *                           for the event subscription will be included.
 * @param omit_used Indicates whether or not to exclude reports previously marked as used (by calling
 *                  data_collection_reporting_report_used()) for this event subscription.
 *
 * @return A list of data_collection_bucketed_data_t* containing the bucketed and aggregated samples, according to provisioned
 *         configurations, that match the function parameters. Free this result with data_collection_bucketed_data_list_free().
 *
 * @see data_collection_reporting_report_used
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_report_find(const data_collection_data_report_handler_t* const *report_handlers, data_collection_event_subscription_t *event_subscription, bool omit_used);

/** Free a bucketed results list.
 *
 * Frees all the buckets in the bucketed list and any associated private data structures associated with the result.
 *
 * @param buckets The list of bucketed data to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_bucketed_data_list_free(ogs_list_t *buckets);

/** Get the data reporting session id
 * \public \memberof data_collection_reporting_session_t
 *
 * This will return the dataReportingSessionId associated with the reporting session @a session.
 *
 * @param session The data reporting session to extract the id from.
 *
 * @return The dataReportingSessionId associated with the reporting session.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_session_get_id(const data_collection_reporting_session_t *session);

/** Process a data report from HTTP
 * \public \memberof data_collection_reporting_session_t
 *
 * Parse, validate and extract the data samples from an HTTP data report submission. Upon success `OGS_OK` is returned. This will
 * indicate an error by returning `OGS_ERROR` and setting the @a error_return, @a error_classname, @a error_parameter and
 * @a error_code output parameters. If an error is returned then the caller is responsible for freeing the strings returned in
 * @a error_return, @a error_classname and @a error_parameter using ogs_free().
 *
 * @param session The data reporting session to submit this data report for.
 * @param mime_type The MIME type string from the HTTP request Content-Type header.
 * @param data The body data from the HTTP request.
 * @param data_length The size of the body data from the HTTP request.
 * @param[out] error_return Upon error will contain a human readable reason for the failure.
 * @param[out] error_classname Upon error will contain the model class name giving the reason for the failure or `NULL` if there is
 *                             no associated class.
 * @param[out] error_parameter Upon error will contain the JSON path to the field that generated the failure or `NULL` if there is
 *                             no specifric field associated with the failure.
 * @param[out] error_code Upon error will contain the error status code that should be used when forming an HTTP response.
 *
 * @return `OGS_OK` on success or `OGS_ERROR` on failure.
 */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_report(data_collection_reporting_session_t *session, const char *mime_type, const void *data, size_t data_length, char **error_return, char **error_classname, char **error_parameter, const char **error_code);

/** Compare a reporting client type to the equivalent 3GPP reporting client type
 *
 * @param reporting_client_type The library reporting client type to compare.
 * @param model_client_type The 3GPP reporting client type to compare.
 *
 * @return `true` if the two are equal and `false` if they are not equal.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_reporting_client_type_cmp_to_model(data_collection_reporting_client_type_e reporting_client_type, data_collection_model_data_collection_client_type_e model_client_type);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DATA_COLLECTION_DATA_REPORTING_H */
