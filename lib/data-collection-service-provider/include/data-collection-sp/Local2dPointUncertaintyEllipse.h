#ifndef _DATA_COLLECTION_LOCAL2D_POINT_UNCERTAINTY_ELLIPSE_H_
#define _DATA_COLLECTION_LOCAL2D_POINT_UNCERTAINTY_ELLIPSE_H_

/**********************************************************************************************************************************
 * Local2dPointUncertaintyEllipse - Public C interface to the Local2dPointUncertaintyEllipse object
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

#include "LocalOrigin.h"
#include "UncertaintyEllipse.h"
#include "RelativeCartesianLocation.h"
#include "GADShape.h"
#include "SupportedGADShapes.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP Local2dPointUncertaintyEllipse object reference
 */
typedef struct data_collection_model_local2d_point_uncertainty_ellipse_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_local2d_point_uncertainty_ellipse_t;



/** Create a new Local2dPointUncertaintyEllipse.
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 * @return a new Local2dPointUncertaintyEllipse object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_create();

/** Create a new Local2dPointUncertaintyEllipse reference.
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The Local2dPointUncertaintyEllipse to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_create_ref(const data_collection_model_local2d_point_uncertainty_ellipse_t *other);

/** Create a new copy of a Local2dPointUncertaintyEllipse object.
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 * Creates a new copy of the given @a other object
 * @param other The Local2dPointUncertaintyEllipse to copy.
 * @return a new Local2dPointUncertaintyEllipse object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_create_copy(const data_collection_model_local2d_point_uncertainty_ellipse_t *other);

/** Create a new reference of a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Local2dPointUncertaintyEllipse to create a new reference to.
 * @return a new Local2dPointUncertaintyEllipse object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_create_move(data_collection_model_local2d_point_uncertainty_ellipse_t *other);

/** Copy the value of another Local2dPointUncertaintyEllipse into this object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 * Copies the value of @a other {{classname} object into @a local2d_point_uncertainty_ellipse.
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to copy @a other into.
 * @param other The Local2dPointUncertaintyEllipse to copy the value from.
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_copy(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, const data_collection_model_local2d_point_uncertainty_ellipse_t *other);

/** Move the value of another Local2dPointUncertaintyEllipse into this object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 * Discards the current value of @a local2d_point_uncertainty_ellipse and moves the value of @a other
 * into @a local2d_point_uncertainty_ellipse. This will leave @a other as an empty reference.
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to move @a other into.
 * @param other The Local2dPointUncertaintyEllipse to move the value from.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_move(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, data_collection_model_local2d_point_uncertainty_ellipse_t *other);

/** Delete a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 * Destroys the reference to the Local2dPointUncertaintyEllipse object and frees the value of Local2dPointUncertaintyEllipse if this is the last reference.
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local2d_point_uncertainty_ellipse_free(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

/** Get a cJSON tree representation of a Local2dPointUncertaintyEllipse
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * Create a cJSON tree representation of the Local2dPointUncertaintyEllipse object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local2d_point_uncertainty_ellipse_toJSON(const data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, bool as_request);

/** Parse a cJSON tree into a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * Attempts to interpret a cJSON tree as a Local2dPointUncertaintyEllipse API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Local2dPointUncertaintyEllipse object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Local2dPointUncertaintyEllipse object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Local2dPointUncertaintyEllipse objects to see if they are equivalent
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param local2d_point_uncertainty_ellipse The first Local2dPointUncertaintyEllipse object to compare.
 * @param other_local2d_point_uncertainty_ellipse The second Local2dPointUncertaintyEllipse object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local2d_point_uncertainty_ellipse_is_equal_to(const data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, const data_collection_model_local2d_point_uncertainty_ellipse_t *other_local2d_point_uncertainty_ellipse);



/** Get the value of the shape field of a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_local2d_point_uncertainty_ellipse_get_shape(const data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

/** Set the value of the shape field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_shape The value to copy into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_shape(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_shape The value to move into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_shape_move(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, data_collection_model_supported_gad_shapes_t* p_shape);


/** Get the value of the localOrigin field of a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to examine.
 *
 * @return the value current set for the localOrigin field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_local_origin_t* data_collection_model_local2d_point_uncertainty_ellipse_get_local_origin(const data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

/** Set the value of the localOrigin field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_local_origin The value to copy into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_local_origin(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, const data_collection_model_local_origin_t* p_local_origin);

/** Move a value to the localOrigin field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_local_origin The value to move into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_local_origin_move(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, data_collection_model_local_origin_t* p_local_origin);


/** Get the value of the point field of a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_relative_cartesian_location_t* data_collection_model_local2d_point_uncertainty_ellipse_get_point(const data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

/** Set the value of the point field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_point The value to copy into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_point(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, const data_collection_model_relative_cartesian_location_t* p_point);

/** Move a value to the point field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_point The value to move into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_point_move(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, data_collection_model_relative_cartesian_location_t* p_point);


/** Get the value of the uncertaintyEllipse field of a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to examine.
 *
 * @return the value current set for the uncertaintyEllipse field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_local2d_point_uncertainty_ellipse_get_uncertainty_ellipse(const data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

/** Set the value of the uncertaintyEllipse field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_uncertainty_ellipse The value to copy into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_uncertainty_ellipse(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);

/** Move a value to the uncertaintyEllipse field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_uncertainty_ellipse The value to move into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_uncertainty_ellipse_move(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);


/** Get the value of the confidence field of a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to examine.
 *
 * @return the value current set for the confidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local2d_point_uncertainty_ellipse_get_confidence(const data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

/** Set the value of the confidence field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_confidence The value to copy into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_confidence(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, const int32_t p_confidence);

/** Move a value to the confidence field in a Local2dPointUncertaintyEllipse object
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to set the field in.
 * @param p_confidence The value to move into the Local2dPointUncertaintyEllipse object.
 *
 * @return @a local2d_point_uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local2d_point_uncertainty_ellipse_t *data_collection_model_local2d_point_uncertainty_ellipse_set_confidence_move(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse, int32_t p_confidence);

/** lnode helper for generating ogs_list_t nodes's of type Local2dPointUncertaintyEllipse
 * \public \memberof data_collection_model_local2d_point_uncertainty_ellipse_t
 *
 * Creates a new data_collection_lnode_t object containing the @a local2d_point_uncertainty_ellipse object.
 * The @a local2d_point_uncertainty_ellipse will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param local2d_point_uncertainty_ellipse The Local2dPointUncertaintyEllipse object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a local2d_point_uncertainty_ellipse
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local2d_point_uncertainty_ellipse_make_lnode(data_collection_model_local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCAL2D_POINT_UNCERTAINTY_ELLIPSE_H_ */

