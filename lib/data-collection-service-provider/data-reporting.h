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

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_reporting_session_cache_entry_s data_reporting_session_cache_entry_t;

typedef struct data_collection_http_metadata_s {
    time_t received;
    char *hash;
} data_collection_http_metadata_t;

typedef struct data_collection_reporting_session_s {
    char *data_reporting_session_id;
    char *external_application_id;
    data_domain_list_t *supported_domains;
    ogs_time_t received;
    char *hash;
    dc_api_data_reporting_session_t *data_reporting_session;
} data_collection_reporting_session_t;

extern data_collection_reporting_session_t *data_reporting_session_populate(data_collection_reporting_session_t *data_collection_reporting_session, dc_api_data_reporting_session_t *data_reporting_session);

extern const data_reporting_session_cache_entry_t *data_collection_context_retrieve_reporting_session(const char *reporting_session_id);


#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_H */
