#ifndef _DATA_COLLECTION_DATA_SAMPLING_RULE_H_
#define _DATA_COLLECTION_DATA_SAMPLING_RULE_H_

/**********************************************************************************************************************************
 * DataSamplingRule - Public C interface to the DataSamplingRule object
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

#include "LocationArea5G.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_sampling_rule_s data_collection_model_data_sampling_rule_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_copy(const data_collection_model_data_sampling_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_move(data_collection_model_data_sampling_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_copy(data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_data_sampling_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, data_collection_model_data_sampling_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_sampling_rule_free(data_collection_model_data_sampling_rule_t *data_sampling_rule);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_sampling_rule_toJSON(const data_collection_model_data_sampling_rule_t *data_sampling_rule, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_sampling_rule_is_equal_to(const data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_data_sampling_rule_t *other_data_sampling_rule);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_sampling_rule_get_context_ids(const data_collection_model_data_sampling_rule_t *data_sampling_rule);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_context_ids_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_add_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_remove_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_clear_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_data_sampling_rule_get_sampling_period(const data_collection_model_data_sampling_rule_t *data_sampling_rule);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period(data_collection_model_data_sampling_rule_t *data_sampling_rule, const float p_sampling_period);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, float p_sampling_period);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_data_sampling_rule_get_location_filter(const data_collection_model_data_sampling_rule_t *data_sampling_rule);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter(data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_location_area5_g_t* p_location_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, data_collection_model_location_area5_g_t* p_location_filter);

/* lnode helper for generating ogs_list_t nodes's of type DataSamplingRule */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_sampling_rule_make_lnode(data_collection_model_data_sampling_rule_t *data_sampling_rule);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_SAMPLING_RULE_H_ */

