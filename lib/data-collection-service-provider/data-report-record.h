/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORT_RECORD_H
#define DATA_REPORT_RECORD_H

#include "ogs-core.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Data Report Record
 *
 * This holds a single data sample. The object also tracks if this record owns the sample data (i.e. the sample resources will be
 * freed when this record is freed), which data report records this record may have been derived from and which data reporting
 * session this data report record belongs to.
 *
 * Original samples keep track of the file that has been used to store the sample. Original samples also record the time the sample
 * was generated and when it was last used, either directly or indirectly, in an event exposure notification as well as the
 * application id of the application which reported it. Original samples will always have an associated data reporting session and
 * the list of reporting context ids that the sample was taken against. Original samples also track which event subscriptions have
 * already used this record. Original sample records are stored in the library database for later use in event exposure
 * notifications.
 *
 * Copies of original samples will duplicate the data reporting session, external app id, reporting times, etc. Copies are used in
 * working lists for producing event exposure notifications. Copies do not own the sample data so will not cause the sample to
 * freed when the record is freed. Copies record the original sample record they are derived from.
 *
 * Aggregated samples own their sample data and also record a list of which data report records they have been derived from.
 * If all original records are from the same external application then the external application id will hold the id, otherwise it
 * will be set to `NULL` to indicate that this aggregate results comes from multiple different applications.
 * If all original records were reported from the same data reporting session, then the aggregate record will retain a reference to
 * the data reporting session, otherwise if the aggregate report is from multiple sessions then the data reporting session will be
 * `NULL`.
 */
typedef struct data_collection_data_report_record_s {
    ogs_lnode_t node;
    const data_collection_data_report_handler_t *data_report_handler;
    ogs_time_t generated;
    ogs_time_t last_used;
    ogs_list_t *context_ids; //Type: data_collection_lnode_t with object=char*
    ogs_list_t *usage; //Type: data_collection_lnode_t with object=data_collection_event_subscription_t*
    char *hash;
    char *external_application_id;
    data_collection_reporting_session_t *session;
    void *data_report_record;
    struct data_collection_data_report_record_s **original_records;
    size_t number_of_original_records;
    char *file_path;
    bool expired;
    bool data_report_record_owner;
    bool expedite;
} data_collection_data_report_record_t;

/** Check if an event subscription has already used a data report record
 *
 * @param data_report The data report record to check.
 * @param event_subscription The event subscription to check for.
 *
 * @return `true` if the data report record has been previously marked as used for the @a event_subscription.
 *
 * @see data_collection_data_report_record_mark_used
 */
extern bool _data_report_record_is_event_subscription_used(const data_collection_data_report_record_t *data_report, const data_collection_event_subscription_t *event_subscription);

/** Remove the used marker for an event subscription.
 *
 * Normally called by when the event subscription is being deleted so that the data report record is not pointing to a freed
 * resource.
 *
 * @param data_report The report to remove the marker for.
 * @param event_subscription The event subscription to remove.
 */
extern void _data_report_record_unmark_used(data_collection_data_report_record_t *data_report, data_collection_event_subscription_t *event_subscription);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_REPORT_H */
