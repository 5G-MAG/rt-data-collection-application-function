#ifndef _DATA_COLLECTION_SNSSAI_H_
#define _DATA_COLLECTION_SNSSAI_H_

/**********************************************************************************************************************************
 * Snssai - Public C interface to the Snssai object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_snssai_s data_collection_model_snssai_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_create_copy(const data_collection_model_snssai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_create_move(data_collection_model_snssai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_copy(data_collection_model_snssai_t *snssai, const data_collection_model_snssai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_move(data_collection_model_snssai_t *snssai, data_collection_model_snssai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_snssai_free(data_collection_model_snssai_t *snssai);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_snssai_toJSON(const data_collection_model_snssai_t *snssai, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_snssai_is_equal_to(const data_collection_model_snssai_t *snssai, const data_collection_model_snssai_t *other_snssai);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_snssai_get_sst(const data_collection_model_snssai_t *snssai);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sst(data_collection_model_snssai_t *snssai, const int32_t p_sst);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sst_move(data_collection_model_snssai_t *snssai, int32_t p_sst);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_snssai_get_sd(const data_collection_model_snssai_t *snssai);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sd(data_collection_model_snssai_t *snssai, const char* p_sd);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sd_move(data_collection_model_snssai_t *snssai, char* p_sd);

/* lnode helper for generating ogs_list_t nodes's of type Snssai */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_snssai_make_lnode(data_collection_model_snssai_t *snssai);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SNSSAI_H_ */

