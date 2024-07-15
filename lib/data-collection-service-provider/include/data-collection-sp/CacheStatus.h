#ifndef _DATA_COLLECTION_CACHE_STATUS_H_
#define _DATA_COLLECTION_CACHE_STATUS_H_

/**********************************************************************************************************************************
 * CacheStatus - Public C interface to the CacheStatus object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "CacheStatus_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_cache_status_s data_collection_model_cache_status_t;

typedef enum {
    DCM_CACHE_STATUS_NO_VAL,
    DCM_CACHE_STATUS_VAL_HIT,
    DCM_CACHE_STATUS_VAL_MISS,
    DCM_CACHE_STATUS_VAL_EXPIRED,
    DCM_CACHE_STATUS_OTHER
} data_collection_model_cache_status_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_create_copy(const data_collection_model_cache_status_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_create_move(data_collection_model_cache_status_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_copy(data_collection_model_cache_status_t *cache_status, const data_collection_model_cache_status_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_move(data_collection_model_cache_status_t *cache_status, data_collection_model_cache_status_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_cache_status_free(data_collection_model_cache_status_t *cache_status);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_cache_status_toJSON(const data_collection_model_cache_status_t *cache_status, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_is_not_set(const data_collection_model_cache_status_t *cache_status);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_is_non_standard(const data_collection_model_cache_status_t *cache_status);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_e data_collection_model_cache_status_get_enum(const data_collection_model_cache_status_t *cache_status);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_cache_status_get_string(const data_collection_model_cache_status_t *cache_status);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_set_enum(data_collection_model_cache_status_t *cache_status, data_collection_model_cache_status_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_set_string(data_collection_model_cache_status_t *cache_status, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type CacheStatus */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_cache_status_make_lnode(data_collection_model_cache_status_t *cache_status);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_CACHE_STATUS_H_ */

