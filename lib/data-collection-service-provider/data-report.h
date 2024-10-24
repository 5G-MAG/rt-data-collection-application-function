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
#include "ogs-core.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_report_hash_record_s data_report_hash_record_t;

extern bool remove_expired_data_reports(ogs_hash_t *data_reports);
extern data_collection_reporting_client_type_e _report_client_type_from_ogs_server(ogs_sbi_server_t *server);
extern void data_report_event_subscriptions_remove_all(ogs_list_t *event_subscriptions);
extern void data_report_hash_record_free(data_report_hash_record_t *report_hash_record);
extern int data_collection_report_remove(data_report_hash_record_t *report_hash_record);

/** Check if an aggregation function name is applicable to a given data report handler */
extern bool data_report_handler_valid_aggregation_function(const data_collection_data_report_handler_t *handler, const char *aggregation_name);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_REPORT_H */
