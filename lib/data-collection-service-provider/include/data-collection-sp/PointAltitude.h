#ifndef _DATA_COLLECTION_POINT_ALTITUDE_H_
#define _DATA_COLLECTION_POINT_ALTITUDE_H_

/**********************************************************************************************************************************
 * PointAltitude - Public C interface to the PointAltitude object
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

#include "GeographicalCoordinates.h"
#include "GADShape.h"
#include "SupportedGADShapes.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PointAltitude object reference
 */
typedef struct data_collection_model_point_altitude_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_point_altitude_t;



/** Create a new PointAltitude.
 * \public \memberof data_collection_model_point_altitude_t
 * @return a new PointAltitude object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_create();

/** Create a new PointAltitude reference.
 * \public \memberof data_collection_model_point_altitude_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PointAltitude to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_create_ref(const data_collection_model_point_altitude_t *other);

/** Create a new copy of a PointAltitude object.
 * \public \memberof data_collection_model_point_altitude_t
 * Creates a new copy of the given @a other object
 * @param other The PointAltitude to copy.
 * @return a new PointAltitude object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_create_copy(const data_collection_model_point_altitude_t *other);

/** Create a new reference of a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PointAltitude to create a new reference to.
 * @return a new PointAltitude object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_create_move(data_collection_model_point_altitude_t *other);

/** Copy the value of another PointAltitude into this object
 * \public \memberof data_collection_model_point_altitude_t
 * Copies the value of @a other {{classname} object into @a point_altitude.
 * @param point_altitude The PointAltitude object to copy @a other into.
 * @param other The PointAltitude to copy the value from.
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_copy(data_collection_model_point_altitude_t *point_altitude, const data_collection_model_point_altitude_t *other);

/** Move the value of another PointAltitude into this object
 * \public \memberof data_collection_model_point_altitude_t
 * Discards the current value of @a point_altitude and moves the value of @a other
 * into @a point_altitude. This will leave @a other as an empty reference.
 *
 * @param point_altitude The PointAltitude object to move @a other into.
 * @param other The PointAltitude to move the value from.
 *
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_move(data_collection_model_point_altitude_t *point_altitude, data_collection_model_point_altitude_t *other);

/** Delete a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 * Destroys the reference to the PointAltitude object and frees the value of PointAltitude if this is the last reference.
 *
 * @param point_altitude The PointAltitude to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_altitude_free(data_collection_model_point_altitude_t *point_altitude);

/** Get a cJSON tree representation of a PointAltitude
 * \public \memberof data_collection_model_point_altitude_t
 *
 * Create a cJSON tree representation of the PointAltitude object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param point_altitude The PointAltitude to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_altitude_toJSON(const data_collection_model_point_altitude_t *point_altitude, bool as_request);

/** Parse a cJSON tree into a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * Attempts to interpret a cJSON tree as a PointAltitude API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PointAltitude object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PointAltitude object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PointAltitude objects to see if they are equivalent
 * \public \memberof data_collection_model_point_altitude_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param point_altitude The first PointAltitude object to compare.
 * @param other_point_altitude The second PointAltitude object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_is_equal_to(const data_collection_model_point_altitude_t *point_altitude, const data_collection_model_point_altitude_t *other_point_altitude);



/** Get the value of the shape field of a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_altitude_get_shape(const data_collection_model_point_altitude_t *point_altitude);

/** Set the value of the shape field in a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to set the field in.
 * @param p_shape The value to copy into the PointAltitude object.
 *
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_shape(data_collection_model_point_altitude_t *point_altitude, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to set the field in.
 * @param p_shape The value to move into the PointAltitude object.
 *
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_shape_move(data_collection_model_point_altitude_t *point_altitude, data_collection_model_supported_gad_shapes_t* p_shape);


/** Get the value of the point field of a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_get_point(const data_collection_model_point_altitude_t *point_altitude);

/** Set the value of the point field in a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to set the field in.
 * @param p_point The value to copy into the PointAltitude object.
 *
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_point(data_collection_model_point_altitude_t *point_altitude, const data_collection_model_geographical_coordinates_t* p_point);

/** Move a value to the point field in a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to set the field in.
 * @param p_point The value to move into the PointAltitude object.
 *
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_point_move(data_collection_model_point_altitude_t *point_altitude, data_collection_model_geographical_coordinates_t* p_point);


/** Get the value of the altitude field of a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to examine.
 *
 * @return the value current set for the altitude field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_point_altitude_get_altitude(const data_collection_model_point_altitude_t *point_altitude);

/** Set the value of the altitude field in a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to set the field in.
 * @param p_altitude The value to copy into the PointAltitude object.
 *
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_altitude(data_collection_model_point_altitude_t *point_altitude, const double p_altitude);

/** Move a value to the altitude field in a PointAltitude object
 * \public \memberof data_collection_model_point_altitude_t
 *
 * @param point_altitude The PointAltitude object to set the field in.
 * @param p_altitude The value to move into the PointAltitude object.
 *
 * @return @a point_altitude.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_altitude_move(data_collection_model_point_altitude_t *point_altitude, double p_altitude);

/** lnode helper for generating ogs_list_t nodes's of type PointAltitude
 * \public \memberof data_collection_model_point_altitude_t
 *
 * Creates a new data_collection_lnode_t object containing the @a point_altitude object.
 * The @a point_altitude will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param point_altitude The PointAltitude object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a point_altitude
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_altitude_make_lnode(data_collection_model_point_altitude_t *point_altitude);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POINT_ALTITUDE_H_ */

