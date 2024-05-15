/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORTING_SESSION_CACHE_H
#define DATA_REPORTING_SESSION_CACHE_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "ogs-core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_reporting_session_s data_collection_reporting_session_t;
typedef struct  dc_api_data_reporting_session_s  dc_api_data_reporting_session_t;

typedef struct data_reporting_session_cache_entry_s {
    char *session_id;
    char *reporting_session;
    char *hash;
    ogs_time_t reporting_session_received; 
    ogs_time_t access_time;
    ogs_time_t generated;
} data_reporting_session_cache_entry_t;

extern ogs_hash_t *data_reporting_session_cache_new(void);
extern void data_reporting_session_cache_free(ogs_hash_t*);
extern bool data_reporting_session_cache_add(ogs_hash_t*, const data_collection_reporting_session_t *data_collection_reporting_session);
extern bool data_reporting_session_cache_del(ogs_hash_t*, const char *session_id);
extern data_reporting_session_cache_entry_t *data_reporting_session_cache_find(ogs_hash_t*, const char *session_id);
extern bool data_reporting_session_cache_clear(ogs_hash_t*);

extern data_reporting_session_cache_entry_t *data_reporting_session_cache_entry_new(const dc_api_data_reporting_session_t *);
extern void data_reporting_session_cache_entry_free(data_reporting_session_cache_entry_t*);
extern bool data_reporting_session_cache_prune(ogs_hash_t *cache);
extern void data_collection_reporting_session_cache_destroy(data_reporting_session_cache_entry_t *entry);
extern void data_reporting_session_cache_accessed(data_reporting_session_cache_entry_t *entry);



#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_SESSION_CACHE_H */
