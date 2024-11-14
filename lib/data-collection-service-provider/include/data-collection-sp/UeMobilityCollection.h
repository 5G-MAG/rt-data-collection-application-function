#ifndef _DATA_COLLECTION_UE_MOBILITY_COLLECTION_H_
#define _DATA_COLLECTION_UE_MOBILITY_COLLECTION_H_

/**********************************************************************************************************************************
 * UeMobilityCollection - Public C interface to the UeMobilityCollection object
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

#include "LocationArea5G.h"
#include "UeTrajectoryCollection.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP UeMobilityCollection object reference
 */
typedef struct data_collection_model_ue_mobility_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ue_mobility_collection_t;



/** Create a new UeMobilityCollection.
 * \public \memberof data_collection_model_ue_mobility_collection_t
 * @return a new UeMobilityCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create();

/** Create a new UeMobilityCollection reference.
 * \public \memberof data_collection_model_ue_mobility_collection_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The UeMobilityCollection to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create_ref(const data_collection_model_ue_mobility_collection_t *other);

/** Create a new copy of a UeMobilityCollection object.
 * \public \memberof data_collection_model_ue_mobility_collection_t
 * Creates a new copy of the given @a other object
 * @param other The UeMobilityCollection to copy.
 * @return a new UeMobilityCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create_copy(const data_collection_model_ue_mobility_collection_t *other);

/** Create a new reference of a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UeMobilityCollection to create a new reference to.
 * @return a new UeMobilityCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create_move(data_collection_model_ue_mobility_collection_t *other);

/** Copy the value of another UeMobilityCollection into this object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 * Copies the value of @a other {{classname} object into @a ue_mobility_collection.
 * @param ue_mobility_collection The UeMobilityCollection object to copy @a other into.
 * @param other The UeMobilityCollection to copy the value from.
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_copy(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_ue_mobility_collection_t *other);

/** Move the value of another UeMobilityCollection into this object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 * Discards the current value of @a ue_mobility_collection and moves the value of @a other
 * into @a ue_mobility_collection. This will leave @a other as an empty reference.
 *
 * @param ue_mobility_collection The UeMobilityCollection object to move @a other into.
 * @param other The UeMobilityCollection to move the value from.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, data_collection_model_ue_mobility_collection_t *other);

/** Delete a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 * Destroys the reference to the UeMobilityCollection object and frees the value of UeMobilityCollection if this is the last reference.
 *
 * @param ue_mobility_collection The UeMobilityCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_mobility_collection_free(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Get a cJSON tree representation of a UeMobilityCollection
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * Create a cJSON tree representation of the UeMobilityCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ue_mobility_collection The UeMobilityCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_mobility_collection_toJSON(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, bool as_request);

/** Parse a cJSON tree into a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * Attempts to interpret a cJSON tree as a UeMobilityCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UeMobilityCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UeMobilityCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UeMobilityCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ue_mobility_collection The first UeMobilityCollection object to compare.
 * @param other_ue_mobility_collection The second UeMobilityCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_is_equal_to(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_ue_mobility_collection_t *other_ue_mobility_collection);


/** Check if the gpsi field of a UeMobilityCollection object is set
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return `true` if the optional gpsi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_gpsi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


/** Get the value of the gpsi field of a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return the value current set for the gpsi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_mobility_collection_get_gpsi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Set the value of the gpsi field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_gpsi The value to copy into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_gpsi(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const char* p_gpsi);

/** Move a value to the gpsi field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_gpsi The value to move into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_gpsi_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, char* p_gpsi);

/** Check if the supi field of a UeMobilityCollection object is set
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return `true` if the optional supi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_supi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


/** Get the value of the supi field of a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return the value current set for the supi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_mobility_collection_get_supi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Set the value of the supi field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_supi The value to copy into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_supi(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const char* p_supi);

/** Move a value to the supi field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_supi The value to move into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_supi_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, char* p_supi);


/** Get the value of the appId field of a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_mobility_collection_get_app_id(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Set the value of the appId field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_app_id The value to copy into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_app_id(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const char* p_app_id);

/** Move a value to the appId field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_app_id The value to move into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_app_id_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, char* p_app_id);

/** Check if the allAppInd field of a UeMobilityCollection object is set
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return `true` if the optional allAppInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_all_app_ind(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


/** Get the value of the allAppInd field of a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return the value current set for the allAppInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_ue_mobility_collection_is_all_app_ind(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Set the value of the allAppInd field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_all_app_ind The value to copy into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_all_app_ind(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const bool p_all_app_ind);

/** Move a value to the allAppInd field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_all_app_ind The value to move into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_all_app_ind_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, bool p_all_app_ind);


/** Get the value of the ueTrajs field of a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return the value current set for the ueTrajs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ue_mobility_collection_get_ue_trajs(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Set the value of the ueTrajs field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_ue_trajs The value to copy into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const ogs_list_t* p_ue_trajs);

/** Move a value to the ueTrajs field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_ue_trajs The value to move into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_ue_trajs_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, ogs_list_t* p_ue_trajs);

/** Add a new item to the ueTrajs array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to add the array item to.
 * @param ue_trajs The value to add.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_add_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, data_collection_model_ue_trajectory_collection_t* ue_trajs);

/** Remove an item from the ueTrajs array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to remove the array value from.
 * @param ue_trajs The value to remove.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_remove_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_ue_trajectory_collection_t* ue_trajs);

/** Get an item from the ueTrajs array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_trajectory_collection_t* data_collection_model_ue_mobility_collection_get_entry_ue_trajs(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, size_t idx);

/** Remove all entries from the ueTrajs array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to empty ueTrajs for.
 *
 * @return @a ue_mobility_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_clear_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Check if the areas field of a UeMobilityCollection object is set
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return `true` if the optional areas field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_areas(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


/** Get the value of the areas field of a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 *
 * @return the value current set for the areas field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ue_mobility_collection_get_areas(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** Set the value of the areas field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_areas The value to copy into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const ogs_list_t* p_areas);

/** Move a value to the areas field in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to set the field in.
 * @param p_areas The value to move into the UeMobilityCollection object.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_areas_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, ogs_list_t* p_areas);

/** Add a new item to the areas array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to add the array item to.
 * @param areas The value to add.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_add_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, data_collection_model_location_area5_g_t* areas);

/** Remove an item from the areas array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to remove the array value from.
 * @param areas The value to remove.
 *
 * @return @a ue_mobility_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_remove_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_location_area5_g_t* areas);

/** Get an item from the areas array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_ue_mobility_collection_get_entry_areas(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, size_t idx);

/** Remove all entries from the areas array in a UeMobilityCollection object
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * @param ue_mobility_collection The UeMobilityCollection object to empty areas for.
 *
 * @return @a ue_mobility_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_clear_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/** lnode helper for generating ogs_list_t nodes's of type UeMobilityCollection
 * \public \memberof data_collection_model_ue_mobility_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ue_mobility_collection object.
 * The @a ue_mobility_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ue_mobility_collection The UeMobilityCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ue_mobility_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_mobility_collection_make_lnode(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_MOBILITY_COLLECTION_H_ */

