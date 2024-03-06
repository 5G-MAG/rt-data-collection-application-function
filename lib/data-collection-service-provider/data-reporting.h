/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORTING_H
#define DATA_REPORTING_H

#include "ogs-proto.h"
#include "openapi/model/dc_api_data_reporting_session.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_reporting_session_s data_collection_reporting_session_t;

typedef struct data_domain_node_s {
    ogs_lnode_t node;
    char *data_domain;
} data_domain_node_t;

typedef ogs_list_t data_domain_list_t; /* list of data_domain_node_t */

#if 0
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

typedef struct data_collection_data_report_type_s {
    const char *type_name;
    data_collection_data_report_property_e data_report_property;
    const char *data_domain;      /* derived from data_report_property if NULL */
    void *(* const parse_report_data)(const data_collection_reporting_session_t *session, cJSON *json, const char **error_return);
    void *(* const clone_report_data)(const void *report_data);
    void (* const free_report_data)(void *report_data);
    cJSON *(* const json_for_report_data)(const void *report_data);
    struct timespec *(* const timestamp_for_report_data)(const void *report_data);
    char *(* const tag_for_report_data)(const void *report_data);
    char *(* const serialise_report_data)(const void *report_data);
} data_collection_data_report_type_t;
#endif

typedef struct data_collection_http_metadata_s {
    time_t received;
    char *hash;
} data_collection_http_metadata_t;

typedef struct data_collection_reporting_session_s {
    ogs_lnode_t node;
    char *data_reporting_session_id;
    char *external_application_id;
    data_domain_list_t *supported_domains;
    time_t received;
    char *hash;
    char *valid_until; 
    dc_api_data_reporting_session_t *data_reporting_session;
	
} data_collection_reporting_session_t;

typedef struct data_collection_data_report_s data_collection_data_report_t;

extern data_collection_reporting_session_t *data_collection_reporting_session_create(const char *external_app_id, const data_domain_list_t *supported_domains);

extern void data_collection_reporting_session_destroy(data_collection_reporting_session_t *session);

extern data_collection_reporting_session_t *data_collection_reporting_session_find(const char *session_id);

extern const struct timespec* data_collection_reporting_session_refresh(data_collection_reporting_session_t *session);

extern cJSON *data_collection_reporting_session_json(const data_collection_reporting_session_t *session);

extern ogs_list_t *data_collection_reporting_report_find(const data_collection_data_report_type_t* const *report_types, data_collection_event_subscription_t *omit_used);

extern const char *data_collection_reporting_session_get_id(const data_collection_reporting_session_t *session);

extern int data_collection_reporting_report(data_collection_reporting_session_t *session, const char *mime_type, const void *data, size_t data_length, const char **error_return);

extern int data_collection_reporting_report_used(data_collection_data_report_t *, data_collection_event_subscription_t *);

extern int data_collection_reporting_report_expire(data_collection_data_report_t *);

extern data_collection_reporting_session_t *data_reporting_session_populate(data_collection_reporting_session_t *data_collection_reporting_session, dc_api_data_reporting_session_t *data_reporting_session);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_H */
