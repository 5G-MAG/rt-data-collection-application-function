#ifndef _DATA_COLLECTION_QUERY_PARAM_COMBINATION_H_
#define _DATA_COLLECTION_QUERY_PARAM_COMBINATION_H_

/**********************************************************************************************************************************
 * QueryParamCombination - Public C interface to the QueryParamCombination object
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

#include "QueryParameter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_query_param_combination_s data_collection_model_query_param_combination_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_copy(const data_collection_model_query_param_combination_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_move(data_collection_model_query_param_combination_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_copy(data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_param_combination_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_move(data_collection_model_query_param_combination_t *query_param_combination, data_collection_model_query_param_combination_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_query_param_combination_free(data_collection_model_query_param_combination_t *query_param_combination);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_query_param_combination_toJSON(const data_collection_model_query_param_combination_t *query_param_combination, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_query_param_combination_is_equal_to(const data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_param_combination_t *other_query_param_combination);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_query_param_combination_get_query_params(const data_collection_model_query_param_combination_t *query_param_combination);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params(data_collection_model_query_param_combination_t *query_param_combination, const ogs_list_t* p_query_params);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params_move(data_collection_model_query_param_combination_t *query_param_combination, ogs_list_t* p_query_params);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_add_query_params(data_collection_model_query_param_combination_t *query_param_combination, data_collection_model_query_parameter_t* query_params);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_remove_query_params(data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_parameter_t* query_params);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_clear_query_params(data_collection_model_query_param_combination_t *query_param_combination);

/* lnode helper for generating ogs_list_t nodes's of type QueryParamCombination */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_query_param_combination_make_lnode(data_collection_model_query_param_combination_t *query_param_combination);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QUERY_PARAM_COMBINATION_H_ */

