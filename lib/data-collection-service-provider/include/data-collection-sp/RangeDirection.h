#ifndef _DATA_COLLECTION_RANGE_DIRECTION_H_
#define _DATA_COLLECTION_RANGE_DIRECTION_H_

/**********************************************************************************************************************************
 * RangeDirection - Public C interface to the RangeDirection object
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

/** A 3GPP RangeDirection object reference
 */
typedef struct data_collection_model_range_direction_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_range_direction_t;



/** Create a new RangeDirection.
 * \public \memberof data_collection_model_range_direction_t
 * @return a new RangeDirection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create();

/** Create a new RangeDirection reference.
 * \public \memberof data_collection_model_range_direction_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The RangeDirection to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_ref(const data_collection_model_range_direction_t *other);

/** Create a new copy of a RangeDirection object.
 * \public \memberof data_collection_model_range_direction_t
 * Creates a new copy of the given @a other object
 * @param other The RangeDirection to copy.
 * @return a new RangeDirection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_copy(const data_collection_model_range_direction_t *other);

/** Create a new reference of a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 * Creates a reference to the same underlying @a other object.
 * @param other The RangeDirection to create a new reference to.
 * @return a new RangeDirection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_move(data_collection_model_range_direction_t *other);

/** Copy the value of another RangeDirection into this object
 * \public \memberof data_collection_model_range_direction_t
 * Copies the value of @a other {{classname} object into @a range_direction.
 * @param range_direction The RangeDirection object to copy @a other into.
 * @param other The RangeDirection to copy the value from.
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_copy(data_collection_model_range_direction_t *range_direction, const data_collection_model_range_direction_t *other);

/** Move the value of another RangeDirection into this object
 * \public \memberof data_collection_model_range_direction_t
 * Discards the current value of @a range_direction and moves the value of @a other
 * into @a range_direction. This will leave @a other as an empty reference.
 *
 * @param range_direction The RangeDirection object to move @a other into.
 * @param other The RangeDirection to move the value from.
 *
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_move(data_collection_model_range_direction_t *range_direction, data_collection_model_range_direction_t *other);

/** Delete a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 * Destroys the reference to the RangeDirection object and frees the value of RangeDirection if this is the last reference.
 *
 * @param range_direction The RangeDirection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_range_direction_free(data_collection_model_range_direction_t *range_direction);

/** Get a cJSON tree representation of a RangeDirection
 * \public \memberof data_collection_model_range_direction_t
 *
 * Create a cJSON tree representation of the RangeDirection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param range_direction The RangeDirection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_range_direction_toJSON(const data_collection_model_range_direction_t *range_direction, bool as_request);

/** Parse a cJSON tree into a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * Attempts to interpret a cJSON tree as a RangeDirection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced RangeDirection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new RangeDirection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two RangeDirection objects to see if they are equivalent
 * \public \memberof data_collection_model_range_direction_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param range_direction The first RangeDirection object to compare.
 * @param other_range_direction The second RangeDirection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_is_equal_to(const data_collection_model_range_direction_t *range_direction, const data_collection_model_range_direction_t *other_range_direction);


/** Check if the distance field of a RangeDirection object is set
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to examine.
 *
 * @return `true` if the optional distance field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_distance(const data_collection_model_range_direction_t *range_direction);


/** Get the value of the distance field of a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to examine.
 *
 * @return the value current set for the distance field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_range_direction_get_distance(const data_collection_model_range_direction_t *range_direction);

/** Set the value of the distance field in a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to set the field in.
 * @param p_distance The value to copy into the RangeDirection object.
 *
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_distance(data_collection_model_range_direction_t *range_direction, const double p_distance);

/** Move a value to the distance field in a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to set the field in.
 * @param p_distance The value to move into the RangeDirection object.
 *
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_distance_move(data_collection_model_range_direction_t *range_direction, double p_distance);

/** Check if the azimuthDirection field of a RangeDirection object is set
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to examine.
 *
 * @return `true` if the optional azimuthDirection field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_azimuth_direction(const data_collection_model_range_direction_t *range_direction);


/** Get the value of the azimuthDirection field of a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to examine.
 *
 * @return the value current set for the azimuthDirection field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_range_direction_get_azimuth_direction(const data_collection_model_range_direction_t *range_direction);

/** Set the value of the azimuthDirection field in a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to set the field in.
 * @param p_azimuth_direction The value to copy into the RangeDirection object.
 *
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction(data_collection_model_range_direction_t *range_direction, const int32_t p_azimuth_direction);

/** Move a value to the azimuthDirection field in a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to set the field in.
 * @param p_azimuth_direction The value to move into the RangeDirection object.
 *
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction_move(data_collection_model_range_direction_t *range_direction, int32_t p_azimuth_direction);

/** Check if the elevationDirection field of a RangeDirection object is set
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to examine.
 *
 * @return `true` if the optional elevationDirection field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_elevation_direction(const data_collection_model_range_direction_t *range_direction);


/** Get the value of the elevationDirection field of a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to examine.
 *
 * @return the value current set for the elevationDirection field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_range_direction_get_elevation_direction(const data_collection_model_range_direction_t *range_direction);

/** Set the value of the elevationDirection field in a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to set the field in.
 * @param p_elevation_direction The value to copy into the RangeDirection object.
 *
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction(data_collection_model_range_direction_t *range_direction, const int32_t p_elevation_direction);

/** Move a value to the elevationDirection field in a RangeDirection object
 * \public \memberof data_collection_model_range_direction_t
 *
 * @param range_direction The RangeDirection object to set the field in.
 * @param p_elevation_direction The value to move into the RangeDirection object.
 *
 * @return @a range_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction_move(data_collection_model_range_direction_t *range_direction, int32_t p_elevation_direction);

/** lnode helper for generating ogs_list_t nodes's of type RangeDirection
 * \public \memberof data_collection_model_range_direction_t
 *
 * Creates a new data_collection_lnode_t object containing the @a range_direction object.
 * The @a range_direction will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param range_direction The RangeDirection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a range_direction
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_range_direction_make_lnode(data_collection_model_range_direction_t *range_direction);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RANGE_DIRECTION_H_ */

