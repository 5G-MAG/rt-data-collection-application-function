#ifndef _DATA_COLLECTION_TAI_H_
#define _DATA_COLLECTION_TAI_H_

/**********************************************************************************************************************************
 * Tai - Public C interface to the Tai object
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

#include "PlmnId.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_tai_s data_collection_model_tai_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_create_copy(const data_collection_model_tai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_create_move(data_collection_model_tai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_copy(data_collection_model_tai_t *tai, const data_collection_model_tai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_move(data_collection_model_tai_t *tai, data_collection_model_tai_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_tai_free(data_collection_model_tai_t *tai);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_tai_toJSON(const data_collection_model_tai_t *tai, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_tai_is_equal_to(const data_collection_model_tai_t *tai, const data_collection_model_tai_t *other_tai);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_tai_get_plmn_id(const data_collection_model_tai_t *tai);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_plmn_id(data_collection_model_tai_t *tai, const data_collection_model_plmn_id_t* p_plmn_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_plmn_id_move(data_collection_model_tai_t *tai, data_collection_model_plmn_id_t* p_plmn_id);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_tai_get_tac(const data_collection_model_tai_t *tai);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_tac(data_collection_model_tai_t *tai, const char* p_tac);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_tac_move(data_collection_model_tai_t *tai, char* p_tac);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_tai_has_nid(const data_collection_model_tai_t *tai);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_tai_get_nid(const data_collection_model_tai_t *tai);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_nid(data_collection_model_tai_t *tai, const char* p_nid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_nid_move(data_collection_model_tai_t *tai, char* p_nid);

/* lnode helper for generating ogs_list_t nodes's of type Tai */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_tai_make_lnode(data_collection_model_tai_t *tai);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TAI_H_ */

