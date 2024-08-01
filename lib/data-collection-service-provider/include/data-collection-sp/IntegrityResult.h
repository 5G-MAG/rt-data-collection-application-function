#ifndef _DATA_COLLECTION_INTEGRITY_RESULT_H_
#define _DATA_COLLECTION_INTEGRITY_RESULT_H_

/**********************************************************************************************************************************
 * IntegrityResult - Public C interface to the IntegrityResult object
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

#include "IntegrityComputingEntity.h"
#include "IntegrityProtectionLevel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_integrity_result_s data_collection_model_integrity_result_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_copy(const data_collection_model_integrity_result_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_move(data_collection_model_integrity_result_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_copy(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_result_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_result_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_result_free(data_collection_model_integrity_result_t *integrity_result);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_result_toJSON(const data_collection_model_integrity_result_t *integrity_result, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_is_equal_to(const data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_result_t *other_integrity_result);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_integrity_computing_entity_t* data_collection_model_integrity_result_get_computing_entity(const data_collection_model_integrity_result_t *integrity_result);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_computing_entity_t* p_computing_entity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_computing_entity_t* p_computing_entity);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_integrity_protection_level_t* data_collection_model_integrity_result_get_protection_level(const data_collection_model_integrity_result_t *integrity_result);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_protection_level_t* p_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_protection_level_t* p_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_integrity_result_is_integrity_req_met_ind(const data_collection_model_integrity_result_t *integrity_result);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind(data_collection_model_integrity_result_t *integrity_result, const bool p_integrity_req_met_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind_move(data_collection_model_integrity_result_t *integrity_result, bool p_integrity_req_met_ind);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_result_get_achieved_tir(const data_collection_model_integrity_result_t *integrity_result);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir(data_collection_model_integrity_result_t *integrity_result, const int32_t p_achieved_tir);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir_move(data_collection_model_integrity_result_t *integrity_result, int32_t p_achieved_tir);

/* lnode helper for generating ogs_list_t nodes's of type IntegrityResult */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_result_make_lnode(data_collection_model_integrity_result_t *integrity_result);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INTEGRITY_RESULT_H_ */

