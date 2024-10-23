#ifndef _DATA_COLLECTION_MS_DYN_POLICY_INVOCATION_COLLECTION_H_
#define _DATA_COLLECTION_MS_DYN_POLICY_INVOCATION_COLLECTION_H_

/**********************************************************************************************************************************
 * MsDynPolicyInvocationCollection - Public C interface to the MsDynPolicyInvocationCollection object
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

#include "DynamicPolicy.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MsDynPolicyInvocationCollection object reference
 */
typedef struct data_collection_model_ms_dyn_policy_invocation_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ms_dyn_policy_invocation_collection_t;



/** Create a new MsDynPolicyInvocationCollection
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 * @return a new MsDynPolicyInvocationCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_create();

/** Create a new copy of a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 * Creates a new copy of the given @a other object
 * @param other The MsDynPolicyInvocationCollection to copy.
 * @return a new MsDynPolicyInvocationCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_create_copy(const data_collection_model_ms_dyn_policy_invocation_collection_t *other);

/** Create a new reference of a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MsDynPolicyInvocationCollection to create a new reference to.
 * @return a new MsDynPolicyInvocationCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_create_move(data_collection_model_ms_dyn_policy_invocation_collection_t *other);

/** Copy the value of another MsDynPolicyInvocationCollection into this object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 * Copies the value of @a other {{classname} object into @a ms_dyn_policy_invocation_collection.
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to copy @a other into.
 * @param other The MsDynPolicyInvocationCollection to copy the value from.
 * @return @a ms_dyn_policy_invocation_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_copy(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, const data_collection_model_ms_dyn_policy_invocation_collection_t *other);

/** Move the value of another MsDynPolicyInvocationCollection into this object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 * Discards the current value of @a ms_dyn_policy_invocation_collection and moves the value of @a other
 * into @a ms_dyn_policy_invocation_collection. This will leave @a other as an empty reference.
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to move @a other into.
 * @param other The MsDynPolicyInvocationCollection to move the value from.
 *
 * @return @a ms_dyn_policy_invocation_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_move(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, data_collection_model_ms_dyn_policy_invocation_collection_t *other);

/** Delete a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 * Destroys the reference to the MsDynPolicyInvocationCollection object and frees the value of MsDynPolicyInvocationCollection if this is the last reference.
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ms_dyn_policy_invocation_collection_free(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

/** Get a cJSON tree representation of a MsDynPolicyInvocationCollection
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * Create a cJSON tree representation of the MsDynPolicyInvocationCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ms_dyn_policy_invocation_collection_toJSON(const data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, bool as_request);

/** Parse a cJSON tree into a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * Attempts to interpret a cJSON tree as a MsDynPolicyInvocationCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MsDynPolicyInvocationCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MsDynPolicyInvocationCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MsDynPolicyInvocationCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ms_dyn_policy_invocation_collection The first MsDynPolicyInvocationCollection object to compare.
 * @param other_ms_dyn_policy_invocation_collection The second MsDynPolicyInvocationCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ms_dyn_policy_invocation_collection_is_equal_to(const data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, const data_collection_model_ms_dyn_policy_invocation_collection_t *other_ms_dyn_policy_invocation_collection);



/** Get the value of the msDynPlyInvocs field of a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to examine.
 *
 * @return the value current set for the msDynPlyInvocs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ms_dyn_policy_invocation_collection_get_ms_dyn_ply_invocs(const data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

/** Set the value of the msDynPlyInvocs field in a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to set the field in.
 * @param p_ms_dyn_ply_invocs The value to copy into the MsDynPolicyInvocationCollection object.
 *
 * @return @a ms_dyn_policy_invocation_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_set_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, const ogs_list_t* p_ms_dyn_ply_invocs);

/** Move a value to the msDynPlyInvocs field in a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to set the field in.
 * @param p_ms_dyn_ply_invocs The value to move into the MsDynPolicyInvocationCollection object.
 *
 * @return @a ms_dyn_policy_invocation_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_set_ms_dyn_ply_invocs_move(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, ogs_list_t* p_ms_dyn_ply_invocs);

/** Add a new item to the msDynPlyInvocs array in a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to add the array item to.
 * @param ms_dyn_ply_invocs The value to add.
 *
 * @return @a ms_dyn_policy_invocation_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_add_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, data_collection_model_dynamic_policy_t* ms_dyn_ply_invocs);

/** Remove an item from the msDynPlyInvocs array in a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to remove the array value from.
 * @param ms_dyn_ply_invocs The value to remove.
 *
 * @return @a ms_dyn_policy_invocation_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_remove_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, const data_collection_model_dynamic_policy_t* ms_dyn_ply_invocs);

/** Get an item from the msDynPlyInvocs array in a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_dynamic_policy_t* data_collection_model_ms_dyn_policy_invocation_collection_get_entry_ms_dyn_ply_invocs(const data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, size_t idx);

/** Remove all entries from the msDynPlyInvocs array in a MsDynPolicyInvocationCollection object
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to empty msDynPlyInvocs for.
 *
 * @return @a ms_dyn_policy_invocation_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_clear_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

/** lnode helper for generating ogs_list_t nodes's of type MsDynPolicyInvocationCollection
 * \public \memberof data_collection_model_ms_dyn_policy_invocation_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ms_dyn_policy_invocation_collection object.
 * The @a ms_dyn_policy_invocation_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ms_dyn_policy_invocation_collection The MsDynPolicyInvocationCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ms_dyn_policy_invocation_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ms_dyn_policy_invocation_collection_make_lnode(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MS_DYN_POLICY_INVOCATION_COLLECTION_H_ */

