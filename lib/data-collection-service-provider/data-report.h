/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORTING_REPORT_H
#define DATA_REPORTING_REPORT_H

#include "ogs-proto.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct data_collection_reporting_session_s data_collection_reporting_session_t;
typedef struct dc_api_data_report_s dc_api_data_report_t;

typedef struct data_collection_data_report_record_s {
    ogs_lnode_t node;
    data_collection_data_report_handler_t *data_report_handler;
    ogs_time_t generated;
    ogs_time_t last_used;
    ogs_list_t usage; //Type: data_collection_event_subscription_t*
    char *hash;
    char *external_application_id;
    data_collection_reporting_session_t *session;
    void *data_report_record;
    char *file_path;
    bool expired;
} data_collection_data_report_record_t;

extern bool remove_expired_data_reports(ogs_hash_t *data_reports);
extern bool data_reports_clear(ogs_hash_t *data_reports);
extern void data_collection_report_destroy(data_collection_data_report_record_t *report);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_REPORT_H */
