/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_COLLECTION_RESPONSE_CACHE_CONTROL_H
#define DATA_COLLECTION_RESPONSE_CACHE_CONTROL_H

#include "ogs-app.h"

#define SERVER_RESPONSE_MAX_AGE 60

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_server_response_cache_control_s {
    int r1_data_collection_reporting_provisioning_session_response_max_age;
    int r2_data_collection_reporting_report_response_max_age;
    int r4_data_collection_reporting_response_max_age;
    int r5_nwdaf_event_exposure_response_max_age;
    int r6_consumer_event_exposure_response_max_age;
}data_collection_server_response_cache_control_t;

extern void data_collection_server_response_cache_control_set(void);
extern void data_collection_server_response_cache_control_set_from_config(int r1_data_collection_reporting_provisioning_session_response_max_age, int r2_data_collection_reporting_report_response_max_age, int r4_data_collection_reporting_response_max_age, int r5_nwdaf_event_exposure_response_max_age, int r6_consumer_event_exposure_response_max_age);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_RESPONSE_CACHE_CONTROL_H */
