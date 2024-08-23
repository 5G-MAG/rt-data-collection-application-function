#ifndef _DATA_COLLECTION_BASE_RECORD_H_
#define _DATA_COLLECTION_BASE_RECORD_H_

/**********************************************************************************************************************************
 * BaseRecord - Public C interface to the BaseRecord object
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

typedef struct data_collection_model_base_record_s data_collection_model_base_record_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create_copy(const data_collection_model_base_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create_move(data_collection_model_base_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_copy(data_collection_model_base_record_t *base_record, const data_collection_model_base_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_move(data_collection_model_base_record_t *base_record, data_collection_model_base_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_record_free(data_collection_model_base_record_t *base_record);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_record_toJSON(const data_collection_model_base_record_t *base_record, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_record_is_equal_to(const data_collection_model_base_record_t *base_record, const data_collection_model_base_record_t *other_base_record);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_record_get_timestamp(const data_collection_model_base_record_t *base_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp(data_collection_model_base_record_t *base_record, const char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp_move(data_collection_model_base_record_t *base_record, char* p_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_record_get_context_ids(const data_collection_model_base_record_t *base_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_context_ids(data_collection_model_base_record_t *base_record, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_context_ids_move(data_collection_model_base_record_t *base_record, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_add_context_ids(data_collection_model_base_record_t *base_record, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_remove_context_ids(data_collection_model_base_record_t *base_record, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_clear_context_ids(data_collection_model_base_record_t *base_record);

/* lnode helper for generating ogs_list_t nodes's of type BaseRecord */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_record_make_lnode(data_collection_model_base_record_t *base_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_BASE_RECORD_H_ */

