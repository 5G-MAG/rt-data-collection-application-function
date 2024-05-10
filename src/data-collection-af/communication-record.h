/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DCAF_COMM_RECORD_H 
#define DCAF_COMM_RECORD_H 

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <features.h>

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

#include "context.h"
#include "sbi-path.h"
#include "utilities.h"
#include "hash.h"
#include "data-collection-sp/data-collection.h"
#include "openapi/model/dcaf_api_data_report.h"
#include "openapi/model/dcaf_api_communication_record.h"

/* Local functions */

typedef struct dcaf_api_communication_record_s dcaf_api_communication_record_t;

extern void *communication_record_parse(const data_collection_reporting_session_t *session, cJSON *json, const char **error_return);
extern void *communication_record_clone(const void *to_copy);
extern void communication_record_free(void *report);
extern cJSON *communication_record_json(const void *report);
extern struct timespec *communication_record_timestamp(const void *report);
extern char *communication_record_make_tag(const void *report);
extern char *communication_record_serialise(const void *report);
/* Event Exposure prototypes - should appear in event-exposure.h file when event exposure is added */
extern ogs_list_t *event_exposure_generate_callback(data_collection_event_subscription_t *data_collection_event_subscription);

static const data_collection_data_report_handler_t communication_record_data_report_type = {
    .type_name = "CommunicationRecord",
    .data_report_property = DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION,
    .data_domain = "COMMUNICATION",
    .event_type = "CommunicationRecordEvent",
    .parse_report_data = communication_record_parse,
    .clone_report_data = communication_record_clone,
    .free_report_data = communication_record_free,
    .json_for_report_data = communication_record_json,
    .timestamp_for_report_data = communication_record_timestamp,
    .tag_for_report_data = communication_record_make_tag,
    .serialise_report_data = communication_record_serialise
};


/* File scope variables */

/* Data Report Types defined by this AF */
static const data_collection_data_report_handler_t * const dc_config_report_types[] = {
    &communication_record_data_report_type,
    NULL
};

/* AF specific Data Collection library configuration */
static const data_collection_configuration_t dc_config = {
    "dataCollection",                /* configuration section */
    0,                               /* library feature disable flags */
#if 1
    DATA_COLLECTION_FEATURE_BIT(29), /* event supported feature flags - 29 = lowest undefined for foobar event */
#else
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION, /* event supported feature flags - when UE_comm implemented */
#endif
    dc_config_report_types,          /* data types to register */
    event_exposure_generate_callback       /* callback to generate events for event exposure */
};

#ifdef __cplusplus
}
#endif

#endif /* DCAF_COMM_RECORD_H */


/* vim:ts=8:sts=4:sw=4:expandtab:
 */
