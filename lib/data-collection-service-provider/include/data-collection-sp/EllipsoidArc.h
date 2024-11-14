#ifndef _DATA_COLLECTION_ELLIPSOID_ARC_H_
#define _DATA_COLLECTION_ELLIPSOID_ARC_H_

/**********************************************************************************************************************************
 * EllipsoidArc - Public C interface to the EllipsoidArc object
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

/** A 3GPP EllipsoidArc object reference
 */
typedef struct data_collection_model_ellipsoid_arc_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ellipsoid_arc_t;



/** Create a new EllipsoidArc.
 * \public \memberof data_collection_model_ellipsoid_arc_t
 * @return a new EllipsoidArc object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create();

/** Create a new EllipsoidArc reference.
 * \public \memberof data_collection_model_ellipsoid_arc_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The EllipsoidArc to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_ref(const data_collection_model_ellipsoid_arc_t *other);

/** Create a new copy of a EllipsoidArc object.
 * \public \memberof data_collection_model_ellipsoid_arc_t
 * Creates a new copy of the given @a other object
 * @param other The EllipsoidArc to copy.
 * @return a new EllipsoidArc object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_copy(const data_collection_model_ellipsoid_arc_t *other);

/** Create a new reference of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 * Creates a reference to the same underlying @a other object.
 * @param other The EllipsoidArc to create a new reference to.
 * @return a new EllipsoidArc object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_move(data_collection_model_ellipsoid_arc_t *other);

/** Copy the value of another EllipsoidArc into this object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 * Copies the value of @a other {{classname} object into @a ellipsoid_arc.
 * @param ellipsoid_arc The EllipsoidArc object to copy @a other into.
 * @param other The EllipsoidArc to copy the value from.
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_copy(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_ellipsoid_arc_t *other);

/** Move the value of another EllipsoidArc into this object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 * Discards the current value of @a ellipsoid_arc and moves the value of @a other
 * into @a ellipsoid_arc. This will leave @a other as an empty reference.
 *
 * @param ellipsoid_arc The EllipsoidArc object to move @a other into.
 * @param other The EllipsoidArc to move the value from.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, data_collection_model_ellipsoid_arc_t *other);

/** Delete a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 * Destroys the reference to the EllipsoidArc object and frees the value of EllipsoidArc if this is the last reference.
 *
 * @param ellipsoid_arc The EllipsoidArc to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ellipsoid_arc_free(data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Get a cJSON tree representation of a EllipsoidArc
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * Create a cJSON tree representation of the EllipsoidArc object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ellipsoid_arc The EllipsoidArc to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ellipsoid_arc_toJSON(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc, bool as_request);

/** Parse a cJSON tree into a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * Attempts to interpret a cJSON tree as a EllipsoidArc API request or response (dependent on @a as_request value). If successful
 * will return a new referenced EllipsoidArc object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new EllipsoidArc object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two EllipsoidArc objects to see if they are equivalent
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ellipsoid_arc The first EllipsoidArc object to compare.
 * @param other_ellipsoid_arc The second EllipsoidArc object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ellipsoid_arc_is_equal_to(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_ellipsoid_arc_t *other_ellipsoid_arc);



/** Get the value of the shape field of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_ellipsoid_arc_get_shape(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Set the value of the shape field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_shape The value to copy into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_shape(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_shape The value to move into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_shape_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, data_collection_model_supported_gad_shapes_t* p_shape);


/** Get the value of the point field of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_ellipsoid_arc_get_point(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Set the value of the point field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_point The value to copy into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_point(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_geographical_coordinates_t* p_point);

/** Move a value to the point field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_point The value to move into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_point_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, data_collection_model_geographical_coordinates_t* p_point);


/** Get the value of the innerRadius field of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to examine.
 *
 * @return the value current set for the innerRadius field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_inner_radius(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Set the value of the innerRadius field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_inner_radius The value to copy into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_inner_radius(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_inner_radius);

/** Move a value to the innerRadius field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_inner_radius The value to move into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_inner_radius_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_inner_radius);


/** Get the value of the uncertaintyRadius field of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to examine.
 *
 * @return the value current set for the uncertaintyRadius field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_ellipsoid_arc_get_uncertainty_radius(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Set the value of the uncertaintyRadius field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_uncertainty_radius The value to copy into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_uncertainty_radius(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const float p_uncertainty_radius);

/** Move a value to the uncertaintyRadius field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_uncertainty_radius The value to move into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_uncertainty_radius_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, float p_uncertainty_radius);


/** Get the value of the offsetAngle field of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to examine.
 *
 * @return the value current set for the offsetAngle field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_offset_angle(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Set the value of the offsetAngle field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_offset_angle The value to copy into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_offset_angle(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_offset_angle);

/** Move a value to the offsetAngle field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_offset_angle The value to move into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_offset_angle_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_offset_angle);


/** Get the value of the includedAngle field of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to examine.
 *
 * @return the value current set for the includedAngle field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_included_angle(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Set the value of the includedAngle field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_included_angle The value to copy into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_included_angle(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_included_angle);

/** Move a value to the includedAngle field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_included_angle The value to move into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_included_angle_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_included_angle);


/** Get the value of the confidence field of a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to examine.
 *
 * @return the value current set for the confidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_confidence(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/** Set the value of the confidence field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_confidence The value to copy into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_confidence(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_confidence);

/** Move a value to the confidence field in a EllipsoidArc object
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * @param ellipsoid_arc The EllipsoidArc object to set the field in.
 * @param p_confidence The value to move into the EllipsoidArc object.
 *
 * @return @a ellipsoid_arc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_confidence_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_confidence);

/** lnode helper for generating ogs_list_t nodes's of type EllipsoidArc
 * \public \memberof data_collection_model_ellipsoid_arc_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ellipsoid_arc object.
 * The @a ellipsoid_arc will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ellipsoid_arc The EllipsoidArc object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ellipsoid_arc
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ellipsoid_arc_make_lnode(data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ELLIPSOID_ARC_H_ */

