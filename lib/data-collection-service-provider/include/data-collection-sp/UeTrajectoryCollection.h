#ifndef _DATA_COLLECTION_UE_TRAJECTORY_COLLECTION_H_
#define _DATA_COLLECTION_UE_TRAJECTORY_COLLECTION_H_

/**********************************************************************************************************************************
 * UeTrajectoryCollection - Public C interface to the UeTrajectoryCollection object
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

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP UeTrajectoryCollection object reference
 */
typedef struct data_collection_model_ue_trajectory_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ue_trajectory_collection_t;



/** Create a new UeTrajectoryCollection
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 * @return a new UeTrajectoryCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create();

/** Create a new copy of a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 * Creates a new copy of the given @a other object
 * @param other The UeTrajectoryCollection to copy.
 * @return a new UeTrajectoryCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create_copy(const data_collection_model_ue_trajectory_collection_t *other);

/** Create a new reference of a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UeTrajectoryCollection to create a new reference to.
 * @return a new UeTrajectoryCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create_move(data_collection_model_ue_trajectory_collection_t *other);

/** Copy the value of another UeTrajectoryCollection into this object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 * Copies the value of @a other {{classname} object into @a ue_trajectory_collection.
 * @param ue_trajectory_collection The UeTrajectoryCollection object to copy @a other into.
 * @param other The UeTrajectoryCollection to copy the value from.
 * @return @a ue_trajectory_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_copy(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const data_collection_model_ue_trajectory_collection_t *other);

/** Move the value of another UeTrajectoryCollection into this object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 * Discards the current value of @a ue_trajectory_collection and moves the value of @a other
 * into @a ue_trajectory_collection. This will leave @a other as an empty reference.
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to move @a other into.
 * @param other The UeTrajectoryCollection to move the value from.
 *
 * @return @a ue_trajectory_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_move(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, data_collection_model_ue_trajectory_collection_t *other);

/** Delete a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 * Destroys the reference to the UeTrajectoryCollection object and frees the value of UeTrajectoryCollection if this is the last reference.
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_trajectory_collection_free(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

/** Get a cJSON tree representation of a UeTrajectoryCollection
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * Create a cJSON tree representation of the UeTrajectoryCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_trajectory_collection_toJSON(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, bool as_request);

/** Parse a cJSON tree into a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * Attempts to interpret a cJSON tree as a UeTrajectoryCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UeTrajectoryCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UeTrajectoryCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UeTrajectoryCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ue_trajectory_collection The first UeTrajectoryCollection object to compare.
 * @param other_ue_trajectory_collection The second UeTrajectoryCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_trajectory_collection_is_equal_to(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const data_collection_model_ue_trajectory_collection_t *other_ue_trajectory_collection);



/** Get the value of the ts field of a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to examine.
 *
 * @return the value current set for the ts field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_trajectory_collection_get_ts(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

/** Set the value of the ts field in a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to set the field in.
 * @param p_ts The value to copy into the UeTrajectoryCollection object.
 *
 * @return @a ue_trajectory_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_ts(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const char* p_ts);

/** Move a value to the ts field in a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to set the field in.
 * @param p_ts The value to move into the UeTrajectoryCollection object.
 *
 * @return @a ue_trajectory_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_ts_move(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, char* p_ts);


/** Get the value of the locArea field of a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to examine.
 *
 * @return the value current set for the locArea field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_ue_trajectory_collection_get_loc_area(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

/** Set the value of the locArea field in a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to set the field in.
 * @param p_loc_area The value to copy into the UeTrajectoryCollection object.
 *
 * @return @a ue_trajectory_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_loc_area(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const data_collection_model_location_area5_g_t* p_loc_area);

/** Move a value to the locArea field in a UeTrajectoryCollection object
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to set the field in.
 * @param p_loc_area The value to move into the UeTrajectoryCollection object.
 *
 * @return @a ue_trajectory_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_loc_area_move(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, data_collection_model_location_area5_g_t* p_loc_area);

/** lnode helper for generating ogs_list_t nodes's of type UeTrajectoryCollection
 * \public \memberof data_collection_model_ue_trajectory_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ue_trajectory_collection object.
 * The @a ue_trajectory_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ue_trajectory_collection The UeTrajectoryCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ue_trajectory_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_trajectory_collection_make_lnode(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_TRAJECTORY_COLLECTION_H_ */

