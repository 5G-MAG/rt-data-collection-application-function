#ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_TIME_ACCESS_RESTRICTIONS_H_
#define _DATA_COLLECTION_DATA_ACCESS_PROFILE_TIME_ACCESS_RESTRICTIONS_H_

/**********************************************************************************************************************************
 * DataAccessProfile_timeAccessRestrictions - Public C interface to the DataAccessProfile_timeAccessRestrictions object
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

#include "DataAggregationFunctionType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_access_profile_time_access_restrictions_s data_collection_model_data_access_profile_time_access_restrictions_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_create_copy(const data_collection_model_data_access_profile_time_access_restrictions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_create_move(data_collection_model_data_access_profile_time_access_restrictions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_copy(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, const data_collection_model_data_access_profile_time_access_restrictions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_move(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, data_collection_model_data_access_profile_time_access_restrictions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_time_access_restrictions_free(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_time_access_restrictions_toJSON(const data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_time_access_restrictions_is_equal_to(const data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, const data_collection_model_data_access_profile_time_access_restrictions_t *other_data_access_profile_time_access_restrictions);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_data_access_profile_time_access_restrictions_get_duration(const data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_duration(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, const int32_t p_duration);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_duration_move(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, int32_t p_duration);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_time_access_restrictions_get_aggregation_functions(const data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, const ogs_list_t* p_aggregation_functions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_aggregation_functions_move(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, ogs_list_t* p_aggregation_functions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_add_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, data_collection_model_data_aggregation_function_type_t* aggregation_functions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_remove_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, const data_collection_model_data_aggregation_function_type_t* aggregation_functions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_clear_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions);

/* lnode helper for generating ogs_list_t nodes's of type DataAccessProfile_timeAccessRestrictions */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_time_access_restrictions_make_lnode(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_TIME_ACCESS_RESTRICTIONS_H_ */

