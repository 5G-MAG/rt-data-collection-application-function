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

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP NoProfileMatchInfo object reference
 */
typedef struct data_collection_model_no_profile_match_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_no_profile_match_info_t;



/** Create a new NoProfileMatchInfo
 * \public \memberof data_collection_model_no_profile_match_info_t
 * @return a new NoProfileMatchInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create();

/** Create a new copy of a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 * Creates a new copy of the given @a other object
 * @param other The NoProfileMatchInfo to copy.
 * @return a new NoProfileMatchInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_copy(const data_collection_model_no_profile_match_info_t *other);

/** Create a new reference of a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The NoProfileMatchInfo to create a new reference to.
 * @return a new NoProfileMatchInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_move(data_collection_model_no_profile_match_info_t *other);

/** Copy the value of another NoProfileMatchInfo into this object
 * \public \memberof data_collection_model_no_profile_match_info_t
 * Copies the value of @a other {{classname} object into @a no_profile_match_info.
 * @param no_profile_match_info The NoProfileMatchInfo object to copy @a other into.
 * @param other The NoProfileMatchInfo to copy the value from.
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_copy(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_info_t *other);

/** Move the value of another NoProfileMatchInfo into this object
 * \public \memberof data_collection_model_no_profile_match_info_t
 * Discards the current value of @a no_profile_match_info and moves the value of @a other
 * into @a no_profile_match_info. This will leave @a other as an empty reference.
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to move @a other into.
 * @param other The NoProfileMatchInfo to move the value from.
 *
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_no_profile_match_info_t *other);

/** Delete a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 * Destroys the reference to the NoProfileMatchInfo object and frees the value of NoProfileMatchInfo if this is the last reference.
 *
 * @param no_profile_match_info The NoProfileMatchInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_no_profile_match_info_free(data_collection_model_no_profile_match_info_t *no_profile_match_info);

/** Get a cJSON tree representation of a NoProfileMatchInfo
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * Create a cJSON tree representation of the NoProfileMatchInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param no_profile_match_info The NoProfileMatchInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_no_profile_match_info_toJSON(const data_collection_model_no_profile_match_info_t *no_profile_match_info, bool as_request);

/** Parse a cJSON tree into a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * Attempts to interpret a cJSON tree as a NoProfileMatchInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced NoProfileMatchInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new NoProfileMatchInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two NoProfileMatchInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param no_profile_match_info The first NoProfileMatchInfo object to compare.
 * @param other_no_profile_match_info The second NoProfileMatchInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_info_is_equal_to(const data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_info_t *other_no_profile_match_info);



/** Get the value of the reason field of a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to examine.
 *
 * @return the value current set for the reason field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_no_profile_match_reason_t* data_collection_model_no_profile_match_info_get_reason(const data_collection_model_no_profile_match_info_t *no_profile_match_info);

/** Set the value of the reason field in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to set the field in.
 * @param p_reason The value to copy into the NoProfileMatchInfo object.
 *
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_reason_t* p_reason);

/** Move a value to the reason field in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to set the field in.
 * @param p_reason The value to move into the NoProfileMatchInfo object.
 *
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_no_profile_match_reason_t* p_reason);

/** Check if the queryParamCombinationList field of a NoProfileMatchInfo object is set
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to examine.
 *
 * @return `true` if the optional queryParamCombinationList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_info_has_query_param_combination_list(const data_collection_model_no_profile_match_info_t *no_profile_match_info);


/** Get the value of the queryParamCombinationList field of a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to examine.
 *
 * @return the value current set for the queryParamCombinationList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_no_profile_match_info_get_query_param_combination_list(const data_collection_model_no_profile_match_info_t *no_profile_match_info);

/** Set the value of the queryParamCombinationList field in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to set the field in.
 * @param p_query_param_combination_list The value to copy into the NoProfileMatchInfo object.
 *
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info, const ogs_list_t* p_query_param_combination_list);

/** Move a value to the queryParamCombinationList field in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to set the field in.
 * @param p_query_param_combination_list The value to move into the NoProfileMatchInfo object.
 *
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, ogs_list_t* p_query_param_combination_list);

/** Add a new item to the queryParamCombinationList array in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to add the array item to.
 * @param query_param_combination_list The value to add.
 *
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_add_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_query_param_combination_t* query_param_combination_list);

/** Remove an item from the queryParamCombinationList array in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to remove the array value from.
 * @param query_param_combination_list The value to remove.
 *
 * @return @a no_profile_match_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_remove_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_query_param_combination_t* query_param_combination_list);

/** Get an item from the queryParamCombinationList array in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_query_param_combination_t* data_collection_model_no_profile_match_info_get_entry_query_param_combination_list(const data_collection_model_no_profile_match_info_t *no_profile_match_info, size_t idx);

/** Remove all entries from the queryParamCombinationList array in a NoProfileMatchInfo object
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to empty queryParamCombinationList for.
 *
 * @return @a no_profile_match_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_clear_query_param_combination_list(data_collection_model_no_profile_match_info_t *no_profile_match_info);

/** lnode helper for generating ogs_list_t nodes's of type NoProfileMatchInfo
 * \public \memberof data_collection_model_no_profile_match_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a no_profile_match_info object.
 * The @a no_profile_match_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param no_profile_match_info The NoProfileMatchInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a no_profile_match_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_no_profile_match_info_make_lnode(data_collection_model_no_profile_match_info_t *no_profile_match_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NO_PROFILE_MATCH_INFO_H_ */

