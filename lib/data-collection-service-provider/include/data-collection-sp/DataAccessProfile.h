#ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_H_
#define _DATA_COLLECTION_DATA_ACCESS_PROFILE_H_

/**********************************************************************************************************************************
 * DataAccessProfile - Public C interface to the DataAccessProfile object
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

#include "DataAccessProfile_locationAccessRestrictions.h"
#include "DataAccessProfile_timeAccessRestrictions.h"
#include "DataAccessProfile_userAccessRestrictions.h"
#include "EventConsumerType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_access_profile_s data_collection_model_data_access_profile_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_copy(const data_collection_model_data_access_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_move(data_collection_model_data_access_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_copy(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_free(data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_toJSON(const data_collection_model_data_access_profile_t *data_access_profile, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_is_equal_to(const data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_t *other_data_access_profile);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_access_profile_get_data_access_profile_id(const data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id(data_collection_model_data_access_profile_t *data_access_profile, const char* p_data_access_profile_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id_move(data_collection_model_data_access_profile_t *data_access_profile, char* p_data_access_profile_id);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_get_target_event_consumer_types(const data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile, const ogs_list_t* p_target_event_consumer_types);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types_move(data_collection_model_data_access_profile_t *data_access_profile, ogs_list_t* p_target_event_consumer_types);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_event_consumer_type_t* target_event_consumer_types);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_event_consumer_type_t* target_event_consumer_types);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_get_parameters(const data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters(data_collection_model_data_access_profile_t *data_access_profile, const ogs_list_t* p_parameters);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters_move(data_collection_model_data_access_profile_t *data_access_profile, ogs_list_t* p_parameters);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_parameters(data_collection_model_data_access_profile_t *data_access_profile, char* parameters);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_parameters(data_collection_model_data_access_profile_t *data_access_profile, const char* parameters);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_parameters(data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_time_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_time_access_restrictions_t* data_collection_model_data_access_profile_get_time_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_user_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_user_access_restrictions_t* data_collection_model_data_access_profile_get_user_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_location_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_location_access_restrictions_t* data_collection_model_data_access_profile_get_location_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions);

/* lnode helper for generating ogs_list_t nodes's of type DataAccessProfile */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_make_lnode(data_collection_model_data_access_profile_t *data_access_profile);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_H_ */

