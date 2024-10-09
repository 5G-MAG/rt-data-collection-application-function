#ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_FILTER_H_
#define _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_FILTER_H_

/**********************************************************************************************************************************
 * CollectiveBehaviourFilter - Public C interface to the CollectiveBehaviourFilter object
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

#include "PerUeAttribute.h"
#include "CollectiveBehaviourFilterType.h"
#include "DataProcessingType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_collective_behaviour_filter_s data_collection_model_collective_behaviour_filter_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create_copy(const data_collection_model_collective_behaviour_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create_move(data_collection_model_collective_behaviour_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_copy(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_collective_behaviour_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_collective_behaviour_filter_free(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_collective_behaviour_filter_toJSON(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_is_equal_to(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_t *other_collective_behaviour_filter);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_collective_behaviour_filter_type_t* data_collection_model_collective_behaviour_filter_get_type(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_type(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_type_t* p_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_type_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_collective_behaviour_filter_type_t* p_type);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_filter_get_value(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_value(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const char* p_value);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_value_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, char* p_value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_has_coll_beh_attr(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_filter_get_coll_beh_attr(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const ogs_list_t* p_coll_beh_attr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_coll_beh_attr_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, ogs_list_t* p_coll_beh_attr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_add_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_per_ue_attribute_t* coll_beh_attr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_remove_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_per_ue_attribute_t* coll_beh_attr);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_per_ue_attribute_t* data_collection_model_collective_behaviour_filter_get_entry_coll_beh_attr(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_clear_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_has_data_proc_type(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_processing_type_t* data_collection_model_collective_behaviour_filter_get_data_proc_type(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_data_proc_type(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_data_processing_type_t* p_data_proc_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_data_proc_type_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_data_processing_type_t* p_data_proc_type);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_has_list_of_ue_ind(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);


DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_collective_behaviour_filter_is_list_of_ue_ind(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_list_of_ue_ind(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const bool p_list_of_ue_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_list_of_ue_ind_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, bool p_list_of_ue_ind);

/* lnode helper for generating ogs_list_t nodes's of type CollectiveBehaviourFilter */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_collective_behaviour_filter_make_lnode(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_FILTER_H_ */

