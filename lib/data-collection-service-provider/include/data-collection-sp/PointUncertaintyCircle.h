#ifndef _DATA_COLLECTION_POINT_UNCERTAINTY_CIRCLE_H_
#define _DATA_COLLECTION_POINT_UNCERTAINTY_CIRCLE_H_

/**********************************************************************************************************************************
 * PointUncertaintyCircle - Public C interface to the PointUncertaintyCircle object
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

/** A 3GPP PointUncertaintyCircle object reference
 */
typedef struct data_collection_model_point_uncertainty_circle_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_point_uncertainty_circle_t;



/** Create a new PointUncertaintyCircle
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 * @return a new PointUncertaintyCircle object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create();

/** Create a new copy of a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 * Creates a new copy of the given @a other object
 * @param other The PointUncertaintyCircle to copy.
 * @return a new PointUncertaintyCircle object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_copy(const data_collection_model_point_uncertainty_circle_t *other);

/** Create a new reference of a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PointUncertaintyCircle to create a new reference to.
 * @return a new PointUncertaintyCircle object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_move(data_collection_model_point_uncertainty_circle_t *other);

/** Copy the value of another PointUncertaintyCircle into this object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 * Copies the value of @a other {{classname} object into @a point_uncertainty_circle.
 * @param point_uncertainty_circle The PointUncertaintyCircle object to copy @a other into.
 * @param other The PointUncertaintyCircle to copy the value from.
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_copy(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_point_uncertainty_circle_t *other);

/** Move the value of another PointUncertaintyCircle into this object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 * Discards the current value of @a point_uncertainty_circle and moves the value of @a other
 * into @a point_uncertainty_circle. This will leave @a other as an empty reference.
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to move @a other into.
 * @param other The PointUncertaintyCircle to move the value from.
 *
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_point_uncertainty_circle_t *other);

/** Delete a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 * Destroys the reference to the PointUncertaintyCircle object and frees the value of PointUncertaintyCircle if this is the last reference.
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_uncertainty_circle_free(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

/** Get a cJSON tree representation of a PointUncertaintyCircle
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * Create a cJSON tree representation of the PointUncertaintyCircle object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_uncertainty_circle_toJSON(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, bool as_request);

/** Parse a cJSON tree into a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * Attempts to interpret a cJSON tree as a PointUncertaintyCircle API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PointUncertaintyCircle object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PointUncertaintyCircle object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PointUncertaintyCircle objects to see if they are equivalent
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param point_uncertainty_circle The first PointUncertaintyCircle object to compare.
 * @param other_point_uncertainty_circle The second PointUncertaintyCircle object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_uncertainty_circle_is_equal_to(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_point_uncertainty_circle_t *other_point_uncertainty_circle);



/** Get the value of the shape field of a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_uncertainty_circle_get_shape(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

/** Set the value of the shape field in a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to set the field in.
 * @param p_shape The value to copy into the PointUncertaintyCircle object.
 *
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to set the field in.
 * @param p_shape The value to move into the PointUncertaintyCircle object.
 *
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_supported_gad_shapes_t* p_shape);


/** Get the value of the point field of a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_uncertainty_circle_get_point(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

/** Set the value of the point field in a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to set the field in.
 * @param p_point The value to copy into the PointUncertaintyCircle object.
 *
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_geographical_coordinates_t* p_point);

/** Move a value to the point field in a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to set the field in.
 * @param p_point The value to move into the PointUncertaintyCircle object.
 *
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_geographical_coordinates_t* p_point);


/** Get the value of the uncertainty field of a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to examine.
 *
 * @return the value current set for the uncertainty field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_point_uncertainty_circle_get_uncertainty(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

/** Set the value of the uncertainty field in a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to set the field in.
 * @param p_uncertainty The value to copy into the PointUncertaintyCircle object.
 *
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const float p_uncertainty);

/** Move a value to the uncertainty field in a PointUncertaintyCircle object
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to set the field in.
 * @param p_uncertainty The value to move into the PointUncertaintyCircle object.
 *
 * @return @a point_uncertainty_circle.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, float p_uncertainty);

/** lnode helper for generating ogs_list_t nodes's of type PointUncertaintyCircle
 * \public \memberof data_collection_model_point_uncertainty_circle_t
 *
 * Creates a new data_collection_lnode_t object containing the @a point_uncertainty_circle object.
 * The @a point_uncertainty_circle will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param point_uncertainty_circle The PointUncertaintyCircle object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a point_uncertainty_circle
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_uncertainty_circle_make_lnode(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POINT_UNCERTAINTY_CIRCLE_H_ */

