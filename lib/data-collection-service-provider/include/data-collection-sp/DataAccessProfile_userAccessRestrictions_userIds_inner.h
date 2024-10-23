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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataAccessProfile_userAccessRestrictions_userIds_inner object reference
 */
typedef struct data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t;



/** Create a new DataAccessProfile_userAccessRestrictions_userIds_inner
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 * @return a new DataAccessProfile_userAccessRestrictions_userIds_inner object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create();

/** Create a new copy of a DataAccessProfile_userAccessRestrictions_userIds_inner object
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 * Creates a new copy of the given @a other object
 * @param other The DataAccessProfile_userAccessRestrictions_userIds_inner to copy.
 * @return a new DataAccessProfile_userAccessRestrictions_userIds_inner object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create_copy(const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

/** Create a new reference of a DataAccessProfile_userAccessRestrictions_userIds_inner object
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataAccessProfile_userAccessRestrictions_userIds_inner to create a new reference to.
 * @return a new DataAccessProfile_userAccessRestrictions_userIds_inner object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create_move(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

/** Copy the value of another DataAccessProfile_userAccessRestrictions_userIds_inner into this object
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 * Copies the value of @a other {{classname} object into @a data_access_profile_user_access_restrictions_user_ids_inner.
 * @param data_access_profile_user_access_restrictions_user_ids_inner The DataAccessProfile_userAccessRestrictions_userIds_inner object to copy @a other into.
 * @param other The DataAccessProfile_userAccessRestrictions_userIds_inner to copy the value from.
 * @return @a data_access_profile_user_access_restrictions_user_ids_inner.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_copy(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

/** Move the value of another DataAccessProfile_userAccessRestrictions_userIds_inner into this object
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 * Discards the current value of @a data_access_profile_user_access_restrictions_user_ids_inner and moves the value of @a other
 * into @a data_access_profile_user_access_restrictions_user_ids_inner. This will leave @a other as an empty reference.
 *
 * @param data_access_profile_user_access_restrictions_user_ids_inner The DataAccessProfile_userAccessRestrictions_userIds_inner object to move @a other into.
 * @param other The DataAccessProfile_userAccessRestrictions_userIds_inner to move the value from.
 *
 * @return @a data_access_profile_user_access_restrictions_user_ids_inner.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_move(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other);

/** Delete a DataAccessProfile_userAccessRestrictions_userIds_inner object
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 * Destroys the reference to the DataAccessProfile_userAccessRestrictions_userIds_inner object and frees the value of DataAccessProfile_userAccessRestrictions_userIds_inner if this is the last reference.
 *
 * @param data_access_profile_user_access_restrictions_user_ids_inner The DataAccessProfile_userAccessRestrictions_userIds_inner to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_free(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner);

/** Get a cJSON tree representation of a DataAccessProfile_userAccessRestrictions_userIds_inner
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 *
 * Create a cJSON tree representation of the DataAccessProfile_userAccessRestrictions_userIds_inner object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_access_profile_user_access_restrictions_user_ids_inner The DataAccessProfile_userAccessRestrictions_userIds_inner to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_toJSON(const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, bool as_request);

/** Parse a cJSON tree into a DataAccessProfile_userAccessRestrictions_userIds_inner object
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 *
 * Attempts to interpret a cJSON tree as a DataAccessProfile_userAccessRestrictions_userIds_inner API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataAccessProfile_userAccessRestrictions_userIds_inner object containing the value represented by the cJSON tree. On failure will return
 * `NULL` and will set @a error_reason, @a error_class and @a error_parameter output parameters to indicate the reason for the
 * failure. The @a error_reason, @a error_class and @a error_parameter strings must be freed using ogs_free().
 *
 * @param json The cJSON tree object to interpret.
 * @param as_request `true` to interpret the @a json as an API request or `false` for interpretation as an API response.
 * @param[out] error_reason On failure will be set to a new nul terminated string indicating the reason for the failure.
 * @param[out] error_class On failure will be set to the class name of the object where the failure happened if available or `NULL`.
 * @param[out] error_parameter On failure will be set to the JSON path of the field where the failure happened if available or
                               `NULL`.
 *
 * @return a new DataAccessProfile_userAccessRestrictions_userIds_inner object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataAccessProfile_userAccessRestrictions_userIds_inner objects to see if they are equivalent
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_access_profile_user_access_restrictions_user_ids_inner The first DataAccessProfile_userAccessRestrictions_userIds_inner object to compare.
 * @param other_data_access_profile_user_access_restrictions_user_ids_inner The second DataAccessProfile_userAccessRestrictions_userIds_inner object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_is_equal_to(const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other_data_access_profile_user_access_restrictions_user_ids_inner);


/** lnode helper for generating ogs_list_t nodes's of type DataAccessProfile_userAccessRestrictions_userIds_inner
 * \public \memberof data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_access_profile_user_access_restrictions_user_ids_inner object.
 * The @a data_access_profile_user_access_restrictions_user_ids_inner will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_access_profile_user_access_restrictions_user_ids_inner The DataAccessProfile_userAccessRestrictions_userIds_inner object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_access_profile_user_access_restrictions_user_ids_inner
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_make_lnode(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_USER_ACCESS_RESTRICTIONS_USER_IDS_INNER_H_ */

