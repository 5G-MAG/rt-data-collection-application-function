#ifndef _DATA_COLLECTION_RELATIVE_CARTESIAN_LOCATION_H_
#define _DATA_COLLECTION_RELATIVE_CARTESIAN_LOCATION_H_

/**********************************************************************************************************************************
 * RelativeCartesianLocation - Public C interface to the RelativeCartesianLocation object
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

/** A 3GPP RelativeCartesianLocation object reference
 */
typedef struct data_collection_model_relative_cartesian_location_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_relative_cartesian_location_t;



/** Create a new RelativeCartesianLocation.
 * \public \memberof data_collection_model_relative_cartesian_location_t
 * @return a new RelativeCartesianLocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create();

/** Create a new RelativeCartesianLocation reference.
 * \public \memberof data_collection_model_relative_cartesian_location_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The RelativeCartesianLocation to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_ref(const data_collection_model_relative_cartesian_location_t *other);

/** Create a new copy of a RelativeCartesianLocation object.
 * \public \memberof data_collection_model_relative_cartesian_location_t
 * Creates a new copy of the given @a other object
 * @param other The RelativeCartesianLocation to copy.
 * @return a new RelativeCartesianLocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_copy(const data_collection_model_relative_cartesian_location_t *other);

/** Create a new reference of a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 * Creates a reference to the same underlying @a other object.
 * @param other The RelativeCartesianLocation to create a new reference to.
 * @return a new RelativeCartesianLocation object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_move(data_collection_model_relative_cartesian_location_t *other);

/** Copy the value of another RelativeCartesianLocation into this object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 * Copies the value of @a other {{classname} object into @a relative_cartesian_location.
 * @param relative_cartesian_location The RelativeCartesianLocation object to copy @a other into.
 * @param other The RelativeCartesianLocation to copy the value from.
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_copy(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const data_collection_model_relative_cartesian_location_t *other);

/** Move the value of another RelativeCartesianLocation into this object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 * Discards the current value of @a relative_cartesian_location and moves the value of @a other
 * into @a relative_cartesian_location. This will leave @a other as an empty reference.
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to move @a other into.
 * @param other The RelativeCartesianLocation to move the value from.
 *
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, data_collection_model_relative_cartesian_location_t *other);

/** Delete a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 * Destroys the reference to the RelativeCartesianLocation object and frees the value of RelativeCartesianLocation if this is the last reference.
 *
 * @param relative_cartesian_location The RelativeCartesianLocation to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_relative_cartesian_location_free(data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

/** Get a cJSON tree representation of a RelativeCartesianLocation
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * Create a cJSON tree representation of the RelativeCartesianLocation object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param relative_cartesian_location The RelativeCartesianLocation to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_relative_cartesian_location_toJSON(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location, bool as_request);

/** Parse a cJSON tree into a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * Attempts to interpret a cJSON tree as a RelativeCartesianLocation API request or response (dependent on @a as_request value). If successful
 * will return a new referenced RelativeCartesianLocation object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new RelativeCartesianLocation object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two RelativeCartesianLocation objects to see if they are equivalent
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param relative_cartesian_location The first RelativeCartesianLocation object to compare.
 * @param other_relative_cartesian_location The second RelativeCartesianLocation object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_cartesian_location_is_equal_to(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const data_collection_model_relative_cartesian_location_t *other_relative_cartesian_location);



/** Get the value of the x field of a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to examine.
 *
 * @return the value current set for the x field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_x(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

/** Set the value of the x field in a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to set the field in.
 * @param p_x The value to copy into the RelativeCartesianLocation object.
 *
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const float p_x);

/** Move a value to the x field in a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to set the field in.
 * @param p_x The value to move into the RelativeCartesianLocation object.
 *
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, float p_x);


/** Get the value of the y field of a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to examine.
 *
 * @return the value current set for the y field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_y(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

/** Set the value of the y field in a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to set the field in.
 * @param p_y The value to copy into the RelativeCartesianLocation object.
 *
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const float p_y);

/** Move a value to the y field in a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to set the field in.
 * @param p_y The value to move into the RelativeCartesianLocation object.
 *
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, float p_y);

/** Check if the z field of a RelativeCartesianLocation object is set
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to examine.
 *
 * @return `true` if the optional z field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_cartesian_location_has_z(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location);


/** Get the value of the z field of a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to examine.
 *
 * @return the value current set for the z field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_z(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

/** Set the value of the z field in a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to set the field in.
 * @param p_z The value to copy into the RelativeCartesianLocation object.
 *
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const float p_z);

/** Move a value to the z field in a RelativeCartesianLocation object
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to set the field in.
 * @param p_z The value to move into the RelativeCartesianLocation object.
 *
 * @return @a relative_cartesian_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, float p_z);

/** lnode helper for generating ogs_list_t nodes's of type RelativeCartesianLocation
 * \public \memberof data_collection_model_relative_cartesian_location_t
 *
 * Creates a new data_collection_lnode_t object containing the @a relative_cartesian_location object.
 * The @a relative_cartesian_location will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param relative_cartesian_location The RelativeCartesianLocation object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a relative_cartesian_location
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_relative_cartesian_location_make_lnode(data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RELATIVE_CARTESIAN_LOCATION_H_ */

