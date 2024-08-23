#ifndef _DATA_COLLECTION_NO_PROFILE_MATCH_INFO_H_
#define _DATA_COLLECTION_NO_PROFILE_MATCH_INFO_H_

/**********************************************************************************************************************************
 * NoProfileMatchInfo - Public C interface to the NoProfileMatchInfo object
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

#include "NoProfileMatchReason.h"
#include "QueryParamCombination.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_no_profile_match_info_s data_collection_model_no_profile_match_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_copy(const data_collection_model_no_profile_match_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_move(data_collection_model_no_profile_match_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_copy(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_no_profile_match_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_no_profile_match_info_free(data_collection_model_no_profile_match_info_t *no_profile_match_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_no_profile_match_info_toJSON(const data_collection_model_no_profile_match_info_t *no_profile_match_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_info_is_equal_to(const data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_info_t *other_no_profile_match_info);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_no_profile_match_reason_t* data_collection_model_no_profile_match_info_get_reason(const data_collection_model_no_profile_match_info_t *no_profile_match_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_reason_t* p_reason);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_no_profile_match_reason_t* p_reason);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_info_has_query_param_combination_list(const data_collection_model_no_profile_match_info_t *no_profile_match_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_no_profile_match_info_get_query_param_combination_list(const data_collection_model_no_profile_match_info_t *no_profile_match_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info, const ogs_list_t* p_query_param_combination_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, ogs_list_t* p_query_param_combination_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_add_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_query_param_combination_t* query_param_combination_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_remove_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_query_param_combination_t* query_param_combination_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_clear_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info);

/* lnode helper for generating ogs_list_t nodes's of type NoProfileMatchInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_no_profile_match_info_make_lnode(data_collection_model_no_profile_match_info_t *no_profile_match_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NO_PROFILE_MATCH_INFO_H_ */

