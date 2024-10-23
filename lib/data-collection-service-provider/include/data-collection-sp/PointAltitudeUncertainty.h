#ifndef _DATA_COLLECTION_POINT_ALTITUDE_UNCERTAINTY_H_
#define _DATA_COLLECTION_POINT_ALTITUDE_UNCERTAINTY_H_

/**********************************************************************************************************************************
 * PointAltitudeUncertainty - Public C interface to the PointAltitudeUncertainty object
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
#include "UncertaintyEllipse.h"
#include "GADShape.h"
#include "SupportedGADShapes.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PointAltitudeUncertainty object reference
 */
typedef struct data_collection_model_point_altitude_uncertainty_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_point_altitude_uncertainty_t;



/** Create a new PointAltitudeUncertainty
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 * @return a new PointAltitudeUncertainty object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create();

/** Create a new copy of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 * Creates a new copy of the given @a other object
 * @param other The PointAltitudeUncertainty to copy.
 * @return a new PointAltitudeUncertainty object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create_copy(const data_collection_model_point_altitude_uncertainty_t *other);

/** Create a new reference of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PointAltitudeUncertainty to create a new reference to.
 * @return a new PointAltitudeUncertainty object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create_move(data_collection_model_point_altitude_uncertainty_t *other);

/** Copy the value of another PointAltitudeUncertainty into this object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 * Copies the value of @a other {{classname} object into @a point_altitude_uncertainty.
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to copy @a other into.
 * @param other The PointAltitudeUncertainty to copy the value from.
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_copy(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_point_altitude_uncertainty_t *other);

/** Move the value of another PointAltitudeUncertainty into this object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 * Discards the current value of @a point_altitude_uncertainty and moves the value of @a other
 * into @a point_altitude_uncertainty. This will leave @a other as an empty reference.
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to move @a other into.
 * @param other The PointAltitudeUncertainty to move the value from.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_point_altitude_uncertainty_t *other);

/** Delete a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 * Destroys the reference to the PointAltitudeUncertainty object and frees the value of PointAltitudeUncertainty if this is the last reference.
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_altitude_uncertainty_free(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Get a cJSON tree representation of a PointAltitudeUncertainty
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * Create a cJSON tree representation of the PointAltitudeUncertainty object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_altitude_uncertainty_toJSON(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, bool as_request);

/** Parse a cJSON tree into a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * Attempts to interpret a cJSON tree as a PointAltitudeUncertainty API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PointAltitudeUncertainty object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PointAltitudeUncertainty object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PointAltitudeUncertainty objects to see if they are equivalent
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param point_altitude_uncertainty The first PointAltitudeUncertainty object to compare.
 * @param other_point_altitude_uncertainty The second PointAltitudeUncertainty object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_is_equal_to(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_point_altitude_uncertainty_t *other_point_altitude_uncertainty);



/** Get the value of the shape field of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_altitude_uncertainty_get_shape(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Set the value of the shape field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_shape The value to copy into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_shape(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_shape The value to move into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_shape_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_supported_gad_shapes_t* p_shape);


/** Get the value of the point field of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_uncertainty_get_point(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Set the value of the point field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_point The value to copy into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_point(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_geographical_coordinates_t* p_point);

/** Move a value to the point field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_point The value to move into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_point_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_geographical_coordinates_t* p_point);


/** Get the value of the altitude field of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return the value current set for the altitude field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_point_altitude_uncertainty_get_altitude(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Set the value of the altitude field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_altitude The value to copy into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_altitude(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const double p_altitude);

/** Move a value to the altitude field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_altitude The value to move into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_altitude_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, double p_altitude);


/** Get the value of the uncertaintyEllipse field of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return the value current set for the uncertaintyEllipse field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_point_altitude_uncertainty_get_uncertainty_ellipse(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Set the value of the uncertaintyEllipse field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_uncertainty_ellipse The value to copy into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_ellipse(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);

/** Move a value to the uncertaintyEllipse field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_uncertainty_ellipse The value to move into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_ellipse_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);


/** Get the value of the uncertaintyAltitude field of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return the value current set for the uncertaintyAltitude field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_point_altitude_uncertainty_get_uncertainty_altitude(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Set the value of the uncertaintyAltitude field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_uncertainty_altitude The value to copy into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_altitude(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const float p_uncertainty_altitude);

/** Move a value to the uncertaintyAltitude field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_uncertainty_altitude The value to move into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_altitude_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, float p_uncertainty_altitude);


/** Get the value of the confidence field of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return the value current set for the confidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_get_confidence(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Set the value of the confidence field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_confidence The value to copy into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_confidence(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const int32_t p_confidence);

/** Move a value to the confidence field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_confidence The value to move into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_confidence_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, int32_t p_confidence);

/** Check if the vConfidence field of a PointAltitudeUncertainty object is set
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return `true` if the optional vConfidence field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_has_v_confidence(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);


/** Get the value of the vConfidence field of a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to examine.
 *
 * @return the value current set for the vConfidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_get_v_confidence(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/** Set the value of the vConfidence field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_v_confidence The value to copy into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_v_confidence(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const int32_t p_v_confidence);

/** Move a value to the vConfidence field in a PointAltitudeUncertainty object
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to set the field in.
 * @param p_v_confidence The value to move into the PointAltitudeUncertainty object.
 *
 * @return @a point_altitude_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_v_confidence_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, int32_t p_v_confidence);

/** lnode helper for generating ogs_list_t nodes's of type PointAltitudeUncertainty
 * \public \memberof data_collection_model_point_altitude_uncertainty_t
 *
 * Creates a new data_collection_lnode_t object containing the @a point_altitude_uncertainty object.
 * The @a point_altitude_uncertainty will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param point_altitude_uncertainty The PointAltitudeUncertainty object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a point_altitude_uncertainty
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_altitude_uncertainty_make_lnode(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POINT_ALTITUDE_UNCERTAINTY_H_ */

