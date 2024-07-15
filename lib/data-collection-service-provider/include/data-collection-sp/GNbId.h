#ifndef _DATA_COLLECTION_GNB_ID_H_
#define _DATA_COLLECTION_GNB_ID_H_

/**********************************************************************************************************************************
 * GNbId - Public C interface to the GNbId object
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

typedef struct data_collection_model_gnb_id_s data_collection_model_gnb_id_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_copy(const data_collection_model_gnb_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_move(data_collection_model_gnb_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_copy(data_collection_model_gnb_id_t *gnb_id, const data_collection_model_gnb_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_move(data_collection_model_gnb_id_t *gnb_id, data_collection_model_gnb_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnb_id_free(data_collection_model_gnb_id_t *gnb_id);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnb_id_toJSON(const data_collection_model_gnb_id_t *gnb_id, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_gnb_id_get_bit_length(const data_collection_model_gnb_id_t *gnb_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length(data_collection_model_gnb_id_t *gnb_id, const int32_t p_bit_length);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length_move(data_collection_model_gnb_id_t *gnb_id, int32_t p_bit_length);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_gnb_id_get_gnb_value(const data_collection_model_gnb_id_t *gnb_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value(data_collection_model_gnb_id_t *gnb_id, const char* p_gnb_value);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value_move(data_collection_model_gnb_id_t *gnb_id, char* p_gnb_value);

/* lnode helper for generating ogs_list_t nodes's of type GNbId */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnb_id_make_lnode(data_collection_model_gnb_id_t *gnb_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNB_ID_H_ */

