/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORTING_H
#define DATA_REPORTING_H

#include <time.h>

#include "ogs-core.h"
#include "ogs-proto.h"

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
    ogs_lnode_t node;
    int ref_count;
    char *data_reporting_session_id;
    char *external_application_id;
    data_domain_list_t *supported_domains;
    struct timespec last_access;
    ogs_time_t received;
    char *hash;
    data_collection_model_data_reporting_session_t *data_reporting_session;
    data_collection_reporting_client_type_e client_type;
} data_collection_reporting_session_t;

extern void _reporting_session_expire_old_sessions();
extern data_collection_reporting_session_t *data_reporting_session_populate(data_collection_reporting_session_t *data_collection_reporting_session, data_collection_model_data_reporting_session_t *data_reporting_session);

extern const data_reporting_session_cache_entry_t *data_collection_context_retrieve_reporting_session(const char *reporting_session_id);
extern void _reporting_session_add_sampling_rules(data_collection_reporting_session_t *data_reporting_session, const char *data_domain, const ogs_list_t *data_reporting_session_sampling_rules);
extern void _reporting_session_add_reporting_rules(data_collection_reporting_session_t *data_reporting_session, const char *data_domain, const ogs_list_t *data_reporting_session_reporting_rules);
extern void _reporting_session_add_reporting_conditions(data_collection_reporting_session_t *data_reporting_session, const char *data_domain, const ogs_list_t *data_reporting_session_reporting_conditions);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_H */
