#ifndef _DATA_COLLECTION_GEOGRAPHIC_AREA_H_
#define _DATA_COLLECTION_GEOGRAPHIC_AREA_H_

/**********************************************************************************************************************************
 * GeographicArea - Public C interface to the GeographicArea object
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

#include "PointUncertaintyCircle.h"
#include "Point.h"
#include "PointUncertaintyEllipse.h"
#include "GeographicalCoordinates.h"
#include "PointAltitude.h"
#include "UncertaintyEllipse.h"
#include "EllipsoidArc.h"
#include "PointAltitudeUncertainty.h"
#include "Polygon.h"
#include "SupportedGADShapes.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP GeographicArea object reference
 */
typedef struct data_collection_model_geographic_area_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_geographic_area_t;



/** Create a new GeographicArea.
 * \public \memberof data_collection_model_geographic_area_t
 * @return a new GeographicArea object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create();

/** Create a new GeographicArea reference.
 * \public \memberof data_collection_model_geographic_area_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The GeographicArea to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create_ref(const data_collection_model_geographic_area_t *other);

/** Create a new copy of a GeographicArea object.
 * \public \memberof data_collection_model_geographic_area_t
 * Creates a new copy of the given @a other object
 * @param other The GeographicArea to copy.
 * @return a new GeographicArea object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create_copy(const data_collection_model_geographic_area_t *other);

/** Create a new reference of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GeographicArea to create a new reference to.
 * @return a new GeographicArea object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create_move(data_collection_model_geographic_area_t *other);

/** Copy the value of another GeographicArea into this object
 * \public \memberof data_collection_model_geographic_area_t
 * Copies the value of @a other {{classname} object into @a geographic_area.
 * @param geographic_area The GeographicArea object to copy @a other into.
 * @param other The GeographicArea to copy the value from.
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_copy(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographic_area_t *other);

/** Move the value of another GeographicArea into this object
 * \public \memberof data_collection_model_geographic_area_t
 * Discards the current value of @a geographic_area and moves the value of @a other
 * into @a geographic_area. This will leave @a other as an empty reference.
 *
 * @param geographic_area The GeographicArea object to move @a other into.
 * @param other The GeographicArea to move the value from.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_geographic_area_t *other);

/** Delete a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 * Destroys the reference to the GeographicArea object and frees the value of GeographicArea if this is the last reference.
 *
 * @param geographic_area The GeographicArea to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_geographic_area_free(data_collection_model_geographic_area_t *geographic_area);

/** Get a cJSON tree representation of a GeographicArea
 * \public \memberof data_collection_model_geographic_area_t
 *
 * Create a cJSON tree representation of the GeographicArea object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param geographic_area The GeographicArea to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_geographic_area_toJSON(const data_collection_model_geographic_area_t *geographic_area, bool as_request);

/** Parse a cJSON tree into a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * Attempts to interpret a cJSON tree as a GeographicArea API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GeographicArea object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GeographicArea object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GeographicArea objects to see if they are equivalent
 * \public \memberof data_collection_model_geographic_area_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param geographic_area The first GeographicArea object to compare.
 * @param other_geographic_area The second GeographicArea object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_geographic_area_is_equal_to(const data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographic_area_t *other_geographic_area);



/** Get the value of the shape field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_geographic_area_get_shape(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the shape field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_shape The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_shape(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_shape The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_shape_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_supported_gad_shapes_t* p_shape);


/** Get the value of the point field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_geographic_area_get_point(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the point field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_point The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographical_coordinates_t* p_point);

/** Move a value to the point field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_point The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_geographical_coordinates_t* p_point);


/** Get the value of the uncertainty field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the uncertainty field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the uncertainty field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty(data_collection_model_geographic_area_t *geographic_area, const float p_uncertainty);

/** Move a value to the uncertainty field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_move(data_collection_model_geographic_area_t *geographic_area, float p_uncertainty);


/** Get the value of the uncertaintyEllipse field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the uncertaintyEllipse field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_geographic_area_get_uncertainty_ellipse(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the uncertaintyEllipse field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty_ellipse The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_ellipse(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);

/** Move a value to the uncertaintyEllipse field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty_ellipse The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_ellipse_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);


/** Get the value of the confidence field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the confidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_confidence(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the confidence field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_confidence The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_confidence(data_collection_model_geographic_area_t *geographic_area, const int32_t p_confidence);

/** Move a value to the confidence field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_confidence The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_confidence_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_confidence);


/** Get the value of the pointList field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the pointList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_geographic_area_get_point_list(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the pointList field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_point_list The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_list(data_collection_model_geographic_area_t *geographic_area, const ogs_list_t* p_point_list);

/** Move a value to the pointList field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_point_list The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_list_move(data_collection_model_geographic_area_t *geographic_area, ogs_list_t* p_point_list);

/** Add a new item to the pointList array in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to add the array item to.
 * @param point_list The value to add.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_add_point_list(data_collection_model_geographic_area_t *geographic_area, data_collection_model_geographical_coordinates_t* point_list);

/** Remove an item from the pointList array in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to remove the array value from.
 * @param point_list The value to remove.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_remove_point_list(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographical_coordinates_t* point_list);

/** Get an item from the pointList array in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_geographic_area_get_entry_point_list(const data_collection_model_geographic_area_t *geographic_area, size_t idx);

/** Remove all entries from the pointList array in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to empty pointList for.
 *
 * @return @a geographic_area
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_clear_point_list(data_collection_model_geographic_area_t *geographic_area);


/** Get the value of the altitude field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the altitude field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographic_area_get_altitude(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the altitude field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_altitude The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_altitude(data_collection_model_geographic_area_t *geographic_area, const double p_altitude);

/** Move a value to the altitude field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_altitude The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_altitude_move(data_collection_model_geographic_area_t *geographic_area, double p_altitude);


/** Get the value of the uncertaintyAltitude field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the uncertaintyAltitude field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty_altitude(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the uncertaintyAltitude field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty_altitude The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_altitude(data_collection_model_geographic_area_t *geographic_area, const float p_uncertainty_altitude);

/** Move a value to the uncertaintyAltitude field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty_altitude The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_altitude_move(data_collection_model_geographic_area_t *geographic_area, float p_uncertainty_altitude);

/** Check if the vConfidence field of a GeographicArea object is set
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return `true` if the optional vConfidence field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_geographic_area_has_v_confidence(const data_collection_model_geographic_area_t *geographic_area);


/** Get the value of the vConfidence field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the vConfidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_v_confidence(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the vConfidence field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_v_confidence The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_v_confidence(data_collection_model_geographic_area_t *geographic_area, const int32_t p_v_confidence);

/** Move a value to the vConfidence field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_v_confidence The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_v_confidence_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_v_confidence);


/** Get the value of the innerRadius field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the innerRadius field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_inner_radius(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the innerRadius field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_inner_radius The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_inner_radius(data_collection_model_geographic_area_t *geographic_area, const int32_t p_inner_radius);

/** Move a value to the innerRadius field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_inner_radius The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_inner_radius_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_inner_radius);


/** Get the value of the uncertaintyRadius field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the uncertaintyRadius field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty_radius(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the uncertaintyRadius field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty_radius The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_radius(data_collection_model_geographic_area_t *geographic_area, const float p_uncertainty_radius);

/** Move a value to the uncertaintyRadius field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_uncertainty_radius The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_radius_move(data_collection_model_geographic_area_t *geographic_area, float p_uncertainty_radius);


/** Get the value of the offsetAngle field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the offsetAngle field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_offset_angle(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the offsetAngle field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_offset_angle The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_offset_angle(data_collection_model_geographic_area_t *geographic_area, const int32_t p_offset_angle);

/** Move a value to the offsetAngle field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_offset_angle The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_offset_angle_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_offset_angle);


/** Get the value of the includedAngle field of a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to examine.
 *
 * @return the value current set for the includedAngle field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_included_angle(const data_collection_model_geographic_area_t *geographic_area);

/** Set the value of the includedAngle field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_included_angle The value to copy into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_included_angle(data_collection_model_geographic_area_t *geographic_area, const int32_t p_included_angle);

/** Move a value to the includedAngle field in a GeographicArea object
 * \public \memberof data_collection_model_geographic_area_t
 *
 * @param geographic_area The GeographicArea object to set the field in.
 * @param p_included_angle The value to move into the GeographicArea object.
 *
 * @return @a geographic_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_included_angle_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_included_angle);

/** lnode helper for generating ogs_list_t nodes's of type GeographicArea
 * \public \memberof data_collection_model_geographic_area_t
 *
 * Creates a new data_collection_lnode_t object containing the @a geographic_area object.
 * The @a geographic_area will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param geographic_area The GeographicArea object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a geographic_area
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_geographic_area_make_lnode(data_collection_model_geographic_area_t *geographic_area);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GEOGRAPHIC_AREA_H_ */

