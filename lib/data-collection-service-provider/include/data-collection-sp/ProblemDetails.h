#ifndef _DATA_COLLECTION_PROBLEM_DETAILS_H_
#define _DATA_COLLECTION_PROBLEM_DETAILS_H_

/**********************************************************************************************************************************
 * ProblemDetails - Public C interface to the ProblemDetails object
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

#include "NoProfileMatchInfo.h"
#include "InvalidParam.h"
#include "AccessTokenErr.h"
#include "AccessTokenReq.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_problem_details_s data_collection_model_problem_details_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create_copy(const data_collection_model_problem_details_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create_move(data_collection_model_problem_details_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_copy(data_collection_model_problem_details_t *problem_details, const data_collection_model_problem_details_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_move(data_collection_model_problem_details_t *problem_details, data_collection_model_problem_details_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_problem_details_free(data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_problem_details_toJSON(const data_collection_model_problem_details_t *problem_details, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_is_equal_to(const data_collection_model_problem_details_t *problem_details, const data_collection_model_problem_details_t *other_problem_details);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_type(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_type(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_type(data_collection_model_problem_details_t *problem_details, const char* p_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_type_move(data_collection_model_problem_details_t *problem_details, char* p_type);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_title(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_title(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_title(data_collection_model_problem_details_t *problem_details, const char* p_title);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_title_move(data_collection_model_problem_details_t *problem_details, char* p_title);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_status(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_problem_details_get_status(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_status(data_collection_model_problem_details_t *problem_details, const int32_t p_status);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_status_move(data_collection_model_problem_details_t *problem_details, int32_t p_status);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_detail(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_detail(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_detail(data_collection_model_problem_details_t *problem_details, const char* p_detail);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_detail_move(data_collection_model_problem_details_t *problem_details, char* p_detail);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_instance(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_instance(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_instance(data_collection_model_problem_details_t *problem_details, const char* p_instance);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_instance_move(data_collection_model_problem_details_t *problem_details, char* p_instance);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_cause(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_cause(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_cause(data_collection_model_problem_details_t *problem_details, const char* p_cause);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_cause_move(data_collection_model_problem_details_t *problem_details, char* p_cause);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_invalid_params(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_problem_details_get_invalid_params(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_invalid_params(data_collection_model_problem_details_t *problem_details, const ogs_list_t* p_invalid_params);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_invalid_params_move(data_collection_model_problem_details_t *problem_details, ogs_list_t* p_invalid_params);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_add_invalid_params(data_collection_model_problem_details_t *problem_details, data_collection_model_invalid_param_t* invalid_params);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_remove_invalid_params(data_collection_model_problem_details_t *problem_details, const data_collection_model_invalid_param_t* invalid_params);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_invalid_param_t* data_collection_model_problem_details_get_entry_invalid_params(const data_collection_model_problem_details_t *problem_details, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_clear_invalid_params(data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_supported_features(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_supported_features(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_features(data_collection_model_problem_details_t *problem_details, const char* p_supported_features);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_features_move(data_collection_model_problem_details_t *problem_details, char* p_supported_features);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_access_token_error(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_access_token_err_t* data_collection_model_problem_details_get_access_token_error(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_error(data_collection_model_problem_details_t *problem_details, const data_collection_model_access_token_err_t* p_access_token_error);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_error_move(data_collection_model_problem_details_t *problem_details, data_collection_model_access_token_err_t* p_access_token_error);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_access_token_request(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_access_token_req_t* data_collection_model_problem_details_get_access_token_request(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_request(data_collection_model_problem_details_t *problem_details, const data_collection_model_access_token_req_t* p_access_token_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_request_move(data_collection_model_problem_details_t *problem_details, data_collection_model_access_token_req_t* p_access_token_request);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_nrf_id(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_nrf_id(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_nrf_id(data_collection_model_problem_details_t *problem_details, const char* p_nrf_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_nrf_id_move(data_collection_model_problem_details_t *problem_details, char* p_nrf_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_supported_api_versions(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_problem_details_get_supported_api_versions(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_api_versions(data_collection_model_problem_details_t *problem_details, const ogs_list_t* p_supported_api_versions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_api_versions_move(data_collection_model_problem_details_t *problem_details, ogs_list_t* p_supported_api_versions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_add_supported_api_versions(data_collection_model_problem_details_t *problem_details, char* supported_api_versions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_remove_supported_api_versions(data_collection_model_problem_details_t *problem_details, const char* supported_api_versions);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_entry_supported_api_versions(const data_collection_model_problem_details_t *problem_details, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_clear_supported_api_versions(data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_no_profile_match_info(const data_collection_model_problem_details_t *problem_details);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_no_profile_match_info_t* data_collection_model_problem_details_get_no_profile_match_info(const data_collection_model_problem_details_t *problem_details);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_no_profile_match_info(data_collection_model_problem_details_t *problem_details, const data_collection_model_no_profile_match_info_t* p_no_profile_match_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_no_profile_match_info_move(data_collection_model_problem_details_t *problem_details, data_collection_model_no_profile_match_info_t* p_no_profile_match_info);

/* lnode helper for generating ogs_list_t nodes's of type ProblemDetails */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_problem_details_make_lnode(data_collection_model_problem_details_t *problem_details);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PROBLEM_DETAILS_H_ */

