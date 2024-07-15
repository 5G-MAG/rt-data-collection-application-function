#ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_USER_ACCESS_RESTRICTIONS_USER_IDS_INNER_H_
#define _DATA_COLLECTION_DATA_ACCESS_PROFILE_USER_ACCESS_RESTRICTIONS_USER_IDS_INNER_H_

/**********************************************************************************************************************************
 * DataAccessProfile_userAccessRestrictions_userIds_inner - Public C interface to the DataAccessProfile_userAccessRestrictions_userIds_inner object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_s data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create_copy(const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create_move(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_copy(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_move(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_free(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_toJSON(const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


/* lnode helper for generating ogs_list_t nodes's of type DataAccessProfile_userAccessRestrictions_userIds_inner */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_make_lnode(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_USER_ACCESS_RESTRICTIONS_USER_IDS_INNER_H_ */

