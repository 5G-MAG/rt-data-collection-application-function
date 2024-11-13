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

#ifndef DATA_COLLECTION_DATA_REPORT_RECORD_H
#define DATA_COLLECTION_DATA_REPORT_RECORD_H

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

/***** Opaque Types *****/

/** Data Report
 *
 * Use data_collection_data_report_*() functions to access this type.
 */
typedef struct data_collection_data_report_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_data_report_record_t;

/** \cond FORWARD_DECL */
/** \struct data_collection_reporting_session_t data-reporting.h
 * Reporting Session
 */
typedef struct data_collection_reporting_session_s data_collection_reporting_session_t;
/** \struct data_collection_data_report_handler_t
 * Report handler
 */
typedef struct data_collection_data_report_handler_s data_collection_data_report_handler_t;
/** \endcond */

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new Data Report Record.
 * \public \memberof data_collection_data_report_record_t
 *
 * Creates a data report record that owns the @a data_sample. The @a session must point to a current data reporting session if this
 * data report record is to be recorded in the library database.
 *
 * @param session The data reporting session this data sample was reported to.
 * @param data_handler The data report handler for the @a data_sample.
 * @param data_sample The data sample to put in the record.
 * @param external_application_id The external application id of the application that reported this data sample.
 * @param expedite The expedite flag of DataReport.
 *
 * @return A new data report record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_new(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *data_handler, void *data_sample, const char *external_application_id, bool expedite);

/** Create a reference copy of a Data Report Record.
 * \public \memberof data_collection_data_report_record_t
 *
 * Creates a duplicate of the data report that can then be placed into results lists. The duplicate does not own the sample data,
 * that will be freed when the original data report record is freed. The returned report record will remember that it is derived
 * from @a data_report_record and therefore should be freed before @a data_report_record. Marking this report record as used or
 * expired by calling data_collection_reporting_report_used() or data_collection_reporting_report_expire() will apply that mark to
 * the original data report record.
 *
 * The data report record returned must not be placed in the library database.
 *
 * @param data_report_record The data report record to make a copy of.
 *
 * @return A new data report record which refers to the same data sample as the original and retains a reference to the original.
 *
 * @see data_collection_reporting_report_used
 * @see data_collection_reporting_report_expire
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_copy(data_collection_data_report_record_t *data_report_record);

/** Create a copy of a data record with new sample data.
 *
 * Creates a data report record that owns the @a data_sample. This record will refer to the original \a record that it is based on.
 * This is mostly used when creating a record which is a proportion of another.
 *
 * @param record The Data Report Record this is derived from.
 * @param data_sample The new derived data sample.
 *
 * @return the new Data Report Record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_copy_new_result(data_collection_data_report_record_t *record, void *data_sample);

/** Create a new aggregated Data Report Record.
 * \public \memberof data_collection_data_report_record_t
 *
 * Creates a data report record that owns the @a data_sample. This record will refer to the list of original data report records
 * provided in @a original_reports, which must have at least one entry. All reports in @a original_reports must share the same data
 * report handler. Other Data Report Record parameters will be derived from @a original_reports, such as a common Data Reporting
 * Session and data report handler.
 *
 * @param data_sample The aggregated data sample to put in the new data report record.
 * @param original_reports The list of original data report records to reference from this data report record.
 *
 * @return A new Data Report Record for the aggregated @a data_sample or `NULL` if there was a problem with the @a original_reports.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_create_aggregated(void *data_sample, const ogs_list_t *original_reports);

/** Destroy a Data Report.
 * \public \memberof data_collection_data_report_record_t
 *
 * Free resources owned by this data report record and delete the record object. This will also remove the record from the library
 * database if it exists there.
 *
 * @param report_record The data report record to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_report_record_destroy(data_collection_data_report_record_t *report_record);

/** Get the AF managed data sample record from the data report record.
 * \public \memberof data_collection_data_report_record_t
 *
 * This will return the data sample, as understood by the AF, that is attached to the @a data_report.
 *
 * @param data_report The report to extract the sample from.
 *
 * @return A pointer to the sample data.
 */
DATA_COLLECTION_SVC_PRODUCER_API void *data_collection_data_report_record_get_data_sample(const data_collection_data_report_record_t *data_report);

/** Get the external application id of the Data Report.
 * \public \memberof data_collection_data_report_record_t
 *
 * This will return the external application id associated with the data sample attached to the @a data_report.
 *
 * @param data_report The report to extract the applicationId from.
 *
 * @return The externalApplicationId string.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_data_report_record_get_external_application_id(const data_collection_data_report_record_t *data_report);

/** Get the data reporting session associated with this Data Report Record.
 * \public \memberof data_collection_data_report_record_t
 *
 * Returns the Data Reporting Session associated with this Data Report Record. This will be `NULL` if this Data Report Record is
 * derived from records from multiple different Data Reporting Sessions.
 *
 * @param report_record The data report record to return the Data Reporting Session for.
 *
 * @return The Data Reporting Session associated with this data report or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_data_report_record_get_session(const data_collection_data_report_record_t *report_record);

/** Get the number of data report records that this result derives from.
 * \public \memberof data_collection_data_report_record_t
 *
 * This will return 0 for original results, 1 or more for copies of originals or aggregated results.
 *
 * @param data_report_record The data report record to get the number of originating reports for.
 *
 * @return The number of reports this data report record is derived from.
 */
DATA_COLLECTION_SVC_PRODUCER_API size_t data_collection_data_report_record_get_number_of_original_records(const data_collection_data_report_record_t *data_report_record);

/** Get the list of context ids the data sample was recorded for.
 * \public \memberof data_collection_data_report_record_t
 *
 * @param report_record The data report record to get the list of context ids for.
 *
 * @return A list of context ids that the data sample was collected for. The caller must use data_collection_list_free() on the
 *         result once it is no longer needed.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_data_report_record_get_context_ids(const data_collection_data_report_record_t *report_record);

/** Get the report handler responsible for the sample data.
 * \public \memberof data_collection_data_report_record_t
 *
 * @param report_record The data report record to get the data sample handler for.
 *
 * @return The data report handler for this report record.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_data_report_handler_t *data_collection_data_report_record_get_data_report_handler(const data_collection_data_report_record_t *report_record);

/** Mark a data report as having been used.
 * \public \memberof data_collection_data_report_record_t
 *
 * Mark a @a data_report as having been used in an event exposure notification for the @a event_subscription. This allows
 * subsequent calls to data_collection_reporting_report_find(), with the `omit_used` flag set to true, to ignore previously used
 * data samples so that they do not get reported twice to the event subscriber.
 *
 * The AF, upon using a data report in a data_collection_model_af_event_exposure_notificiation_t, should call this function to
 * mark the report as having been used.
 *
 * If the data record provided in @a data_report is derived from one or more data report records then the original report or
 * reports will marked.
 *
 * @param data_report The data report to mark as used by @a event_subscription.
 * @param event_subscription The event subscription that a notification has been sent to that used @a data_report.
 *
 * @return OGS_OK on success.
 *
 * @see data_collection_reporting_report_find
 */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_data_report_record_mark_used(data_collection_data_report_record_t *data_report, const data_collection_event_subscription_t *event_subscription);

/** Expire a data report.
 * \public \memberof data_collection_data_report_record_t
 *
 * Mark a data record as being expired. Data records will be expired by the library after a configured amount of time anyway, but
 * this function allows the AF to prematurely mark a data record as expired if it knows it will no longer be used by any current or
 * future event exposure subscriptions. Expired records will be tidied up by the library during its next housekeeping cycle and
 * will be excluded from data_collection_reporting_report_find() results until that time. If the data record provided in
 * @a data_report is derived from one or more data report records then the original report or reports will marked.
 *
 * @param data_report The data report to expire.
 *
 * @return OGS_OK on success.
 */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_data_report_record_mark_expired(data_collection_data_report_record_t *data_report);

/** Check if a data report record is marked as used by a given event subscription.
 * \public \memberof data_collection_data_report_record_t
 *
 * Checks the list of event subscriptions that have used this report record to see if the list contains the given event
 * subscription.
 *
 * @param data_report The data report to check.
 * @param event_subscription The event subscription to look for a mark for.
 *
 * @return `true` if the report record is marked as used by the event subscription, or `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_data_report_record_used_by(const data_collection_data_report_record_t *data_report, const data_collection_event_subscription_t *event_subscription);

/** Set expedite flag on a Data Report record if set on a DataReport.
 * \public \memberof data_collection_data_report_record_t
 *
 * @param data_report The data report on which expedite flag needs to be set.
 *
 * @return `true` if the expedite flag is set on the Data Report record, or `false` otherwise.
 */

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_data_report_record_set_expedite(data_collection_data_report_record_t *data_report);

/** Retrieve the expedite flag from data report record.
 * \public \memberof data_collection_data_report_record_t
 *
 * @param data_report The data report to retrieve expedite flag from.
 *
 * @return `true` if the Data Report record has expedite flag, or `false` otherwise.
 */

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_data_report_record_get_expedite(const data_collection_data_report_record_t *data_report);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DATA_COLLECTION_DATA_REPORT_RECORD_H */
