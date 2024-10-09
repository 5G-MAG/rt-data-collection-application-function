#ifndef _DATA_COLLECTION_ML_MODEL_INTER_IND_H_
#define _DATA_COLLECTION_ML_MODEL_INTER_IND_H_

/**********************************************************************************************************************************
 * MlModelInterInd - Public C interface to the MlModelInterInd object
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

#include "NwdafEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ml_model_inter_ind_s data_collection_model_ml_model_inter_ind_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create_copy(const data_collection_model_ml_model_inter_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create_move(data_collection_model_ml_model_inter_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_copy(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const data_collection_model_ml_model_inter_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_move(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, data_collection_model_ml_model_inter_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ml_model_inter_ind_free(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ml_model_inter_ind_toJSON(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ml_model_inter_ind_is_equal_to(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const data_collection_model_ml_model_inter_ind_t *other_ml_model_inter_ind);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nwdaf_event_t* data_collection_model_ml_model_inter_ind_get_analytics_id(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_analytics_id(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const data_collection_model_nwdaf_event_t* p_analytics_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_analytics_id_move(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, data_collection_model_nwdaf_event_t* p_analytics_id);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ml_model_inter_ind_get_vendor_list(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const ogs_list_t* p_vendor_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_vendor_list_move(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, ogs_list_t* p_vendor_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_add_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, char* vendor_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_remove_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const char* vendor_list);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ml_model_inter_ind_get_entry_vendor_list(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_clear_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

/* lnode helper for generating ogs_list_t nodes's of type MlModelInterInd */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ml_model_inter_ind_make_lnode(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ML_MODEL_INTER_IND_H_ */

