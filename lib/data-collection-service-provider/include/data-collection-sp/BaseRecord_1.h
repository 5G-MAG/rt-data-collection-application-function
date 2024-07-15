#ifndef _DATA_COLLECTION_BASE_RECORD_1_H_
#define _DATA_COLLECTION_BASE_RECORD_1_H_

/**********************************************************************************************************************************
 * BaseRecord_1 - Public C interface to the BaseRecord_1 object
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

typedef struct data_collection_model_base_record_1_s data_collection_model_base_record_1_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_create_copy(const data_collection_model_base_record_1_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_create_move(data_collection_model_base_record_1_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_copy(data_collection_model_base_record_1_t *base_record_1, const data_collection_model_base_record_1_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_move(data_collection_model_base_record_1_t *base_record_1, data_collection_model_base_record_1_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_record_1_free(data_collection_model_base_record_1_t *base_record_1);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_record_1_toJSON(const data_collection_model_base_record_1_t *base_record_1, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_record_1_get_timestamp(const data_collection_model_base_record_1_t *base_record_1);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_timestamp(data_collection_model_base_record_1_t *base_record_1, const char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_timestamp_move(data_collection_model_base_record_1_t *base_record_1, char* p_timestamp);

/* lnode helper for generating ogs_list_t nodes's of type BaseRecord_1 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_record_1_make_lnode(data_collection_model_base_record_1_t *base_record_1);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_BASE_RECORD_1_H_ */

