#ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_INFO_H_
#define _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_INFO_H_

/**********************************************************************************************************************************
 * CollectiveBehaviourInfo - Public C interface to the CollectiveBehaviourInfo object
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

#include "Direction.h"
#include "PerUeAttribute.h"
#include "RelativeDirection.h"
#include "UeTrajectoryCollection.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP CollectiveBehaviourInfo object reference
 */
typedef struct data_collection_model_collective_behaviour_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_collective_behaviour_info_t;



/** Create a new CollectiveBehaviourInfo
 * \public \memberof data_collection_model_collective_behaviour_info_t
 * @return a new CollectiveBehaviourInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create();

/** Create a new copy of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 * Creates a new copy of the given @a other object
 * @param other The CollectiveBehaviourInfo to copy.
 * @return a new CollectiveBehaviourInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_copy(const data_collection_model_collective_behaviour_info_t *other);

/** Create a new reference of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The CollectiveBehaviourInfo to create a new reference to.
 * @return a new CollectiveBehaviourInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_move(data_collection_model_collective_behaviour_info_t *other);

/** Copy the value of another CollectiveBehaviourInfo into this object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 * Copies the value of @a other {{classname} object into @a collective_behaviour_info.
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to copy @a other into.
 * @param other The CollectiveBehaviourInfo to copy the value from.
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_copy(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_collective_behaviour_info_t *other);

/** Move the value of another CollectiveBehaviourInfo into this object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 * Discards the current value of @a collective_behaviour_info and moves the value of @a other
 * into @a collective_behaviour_info. This will leave @a other as an empty reference.
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to move @a other into.
 * @param other The CollectiveBehaviourInfo to move the value from.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_collective_behaviour_info_t *other);

/** Delete a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 * Destroys the reference to the CollectiveBehaviourInfo object and frees the value of CollectiveBehaviourInfo if this is the last reference.
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_collective_behaviour_info_free(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Get a cJSON tree representation of a CollectiveBehaviourInfo
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * Create a cJSON tree representation of the CollectiveBehaviourInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_collective_behaviour_info_toJSON(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, bool as_request);

/** Parse a cJSON tree into a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * Attempts to interpret a cJSON tree as a CollectiveBehaviourInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced CollectiveBehaviourInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new CollectiveBehaviourInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two CollectiveBehaviourInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param collective_behaviour_info The first CollectiveBehaviourInfo object to compare.
 * @param other_collective_behaviour_info The second CollectiveBehaviourInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_is_equal_to(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_collective_behaviour_info_t *other_collective_behaviour_info);


/** Check if the colAttrib field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional colAttrib field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_col_attrib(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the colAttrib field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the colAttrib field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_col_attrib(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the colAttrib field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_col_attrib The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_col_attrib);

/** Move a value to the colAttrib field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_col_attrib The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_col_attrib);

/** Add a new item to the colAttrib array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to add the array item to.
 * @param col_attrib The value to add.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_per_ue_attribute_t* col_attrib);

/** Remove an item from the colAttrib array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to remove the array value from.
 * @param col_attrib The value to remove.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_per_ue_attribute_t* col_attrib);

/** Get an item from the colAttrib array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_per_ue_attribute_t* data_collection_model_collective_behaviour_info_get_entry_col_attrib(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

/** Remove all entries from the colAttrib array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to empty colAttrib for.
 *
 * @return @a collective_behaviour_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_col_attrib(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Check if the noOfUes field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional noOfUes field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_no_of_ues(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the noOfUes field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the noOfUes field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_no_of_ues(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the noOfUes field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_no_of_ues The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const int32_t p_no_of_ues);

/** Move a value to the noOfUes field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_no_of_ues The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, int32_t p_no_of_ues);

/** Check if the appIds field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional appIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_app_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the appIds field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the appIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_app_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the appIds field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_app_ids The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_app_ids);

/** Move a value to the appIds field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_app_ids The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_app_ids);

/** Add a new item to the appIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to add the array item to.
 * @param app_ids The value to add.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, char* app_ids);

/** Remove an item from the appIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to remove the array value from.
 * @param app_ids The value to remove.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const char* app_ids);

/** Get an item from the appIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_info_get_entry_app_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

/** Remove all entries from the appIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to empty appIds for.
 *
 * @return @a collective_behaviour_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_app_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Check if the extUeIds field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional extUeIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the extUeIds field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the extUeIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the extUeIds field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_ext_ue_ids The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_ext_ue_ids);

/** Move a value to the extUeIds field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_ext_ue_ids The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_ext_ue_ids);

/** Add a new item to the extUeIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to add the array item to.
 * @param ext_ue_ids The value to add.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, char* ext_ue_ids);

/** Remove an item from the extUeIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to remove the array value from.
 * @param ext_ue_ids The value to remove.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const char* ext_ue_ids);

/** Get an item from the extUeIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_info_get_entry_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

/** Remove all entries from the extUeIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to empty extUeIds for.
 *
 * @return @a collective_behaviour_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ext_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Check if the ueIds field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional ueIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the ueIds field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the ueIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the ueIds field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_ue_ids The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_ue_ids);

/** Move a value to the ueIds field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_ue_ids The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_ue_ids);

/** Add a new item to the ueIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to add the array item to.
 * @param ue_ids The value to add.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, char* ue_ids);

/** Remove an item from the ueIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to remove the array value from.
 * @param ue_ids The value to remove.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const char* ue_ids);

/** Get an item from the ueIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_info_get_entry_ue_ids(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

/** Remove all entries from the ueIds array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to empty ueIds for.
 *
 * @return @a collective_behaviour_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ue_ids(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Check if the collisionDist field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional collisionDist field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_collision_dist(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the collisionDist field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the collisionDist field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_collision_dist(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the collisionDist field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_collision_dist The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const int32_t p_collision_dist);

/** Move a value to the collisionDist field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_collision_dist The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, int32_t p_collision_dist);

/** Check if the absDirs field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional absDirs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_abs_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the absDirs field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the absDirs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_abs_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the absDirs field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_abs_dirs The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_abs_dirs);

/** Move a value to the absDirs field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_abs_dirs The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_abs_dirs);

/** Add a new item to the absDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to add the array item to.
 * @param abs_dirs The value to add.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_direction_t* abs_dirs);

/** Remove an item from the absDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to remove the array value from.
 * @param abs_dirs The value to remove.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_direction_t* abs_dirs);

/** Get an item from the absDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_direction_t* data_collection_model_collective_behaviour_info_get_entry_abs_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

/** Remove all entries from the absDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to empty absDirs for.
 *
 * @return @a collective_behaviour_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_abs_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Check if the relDirs field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional relDirs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_rel_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the relDirs field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the relDirs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_rel_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the relDirs field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_rel_dirs The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const ogs_list_t* p_rel_dirs);

/** Move a value to the relDirs field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_rel_dirs The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, ogs_list_t* p_rel_dirs);

/** Add a new item to the relDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to add the array item to.
 * @param rel_dirs The value to add.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_relative_direction_t* rel_dirs);

/** Remove an item from the relDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to remove the array value from.
 * @param rel_dirs The value to remove.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_relative_direction_t* rel_dirs);

/** Get an item from the relDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_relative_direction_t* data_collection_model_collective_behaviour_info_get_entry_rel_dirs(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, size_t idx);

/** Remove all entries from the relDirs array in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to empty relDirs for.
 *
 * @return @a collective_behaviour_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_rel_dirs(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Check if the ueTrajectory field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional ueTrajectory field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ue_trajectory(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the ueTrajectory field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the ueTrajectory field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_trajectory_collection_t* data_collection_model_collective_behaviour_info_get_ue_trajectory(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the ueTrajectory field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_ue_trajectory The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_ue_trajectory_collection_t* p_ue_trajectory);

/** Move a value to the ueTrajectory field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_ue_trajectory The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_ue_trajectory_collection_t* p_ue_trajectory);

/** Check if the confidence field of a CollectiveBehaviourInfo object is set
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return `true` if the optional confidence field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_confidence(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);


/** Get the value of the confidence field of a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to examine.
 *
 * @return the value current set for the confidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_confidence(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/** Set the value of the confidence field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_confidence The value to copy into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const int32_t p_confidence);

/** Move a value to the confidence field in a CollectiveBehaviourInfo object
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to set the field in.
 * @param p_confidence The value to move into the CollectiveBehaviourInfo object.
 *
 * @return @a collective_behaviour_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, int32_t p_confidence);

/** lnode helper for generating ogs_list_t nodes's of type CollectiveBehaviourInfo
 * \public \memberof data_collection_model_collective_behaviour_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a collective_behaviour_info object.
 * The @a collective_behaviour_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param collective_behaviour_info The CollectiveBehaviourInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a collective_behaviour_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_collective_behaviour_info_make_lnode(data_collection_model_collective_behaviour_info_t *collective_behaviour_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_INFO_H_ */

