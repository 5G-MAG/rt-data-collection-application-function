/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "context.h"
#include "response-cache-control.h"

void data_collection_server_response_cache_control_set(void)
{
    data_collection_server_response_cache_control_t *server_response_cache_control = NULL;
    server_response_cache_control = ogs_calloc(1, sizeof(data_collection_server_response_cache_control_t));
    ogs_assert(server_response_cache_control);
    server_response_cache_control->data_collection_reporting_provisioning_session_response_max_age = SERVER_RESPONSE_MAX_AGE;
    server_response_cache_control->data_collection_reporting_report_response_max_age = SERVER_RESPONSE_MAX_AGE;
    server_response_cache_control->event_exposure_response_max_age = SERVER_RESPONSE_MAX_AGE;
    data_collection_self()->config.server_response_cache_control = server_response_cache_control;
}

void data_collection_server_response_cache_control_set_from_config(int data_collection_reporting_provisioning_session_response_max_age,
        int data_collection_reporting_report_response_max_age, int event_exposure_response_max_age)
{
    data_collection_self()->config.server_response_cache_control->data_collection_reporting_provisioning_session_response_max_age = data_collection_reporting_provisioning_session_response_max_age;
    data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age = data_collection_reporting_report_response_max_age;
    data_collection_self()->config.server_response_cache_control->event_exposure_response_max_age = event_exposure_response_max_age;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
