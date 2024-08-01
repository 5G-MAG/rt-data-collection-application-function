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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_geographic_area_s data_collection_model_geographic_area_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create_copy(const data_collection_model_geographic_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create_move(data_collection_model_geographic_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_copy(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographic_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_geographic_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_geographic_area_free(data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_geographic_area_toJSON(const data_collection_model_geographic_area_t *geographic_area, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_geographic_area_is_equal_to(const data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographic_area_t *other_geographic_area);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_geographic_area_get_shape(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_shape(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_shape_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_geographic_area_get_point(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty(data_collection_model_geographic_area_t *geographic_area, const float p_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_move(data_collection_model_geographic_area_t *geographic_area, float p_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_geographic_area_get_uncertainty_ellipse(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_ellipse(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_ellipse_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_confidence(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_confidence(data_collection_model_geographic_area_t *geographic_area, const int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_confidence_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_geographic_area_get_point_list(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_list(data_collection_model_geographic_area_t *geographic_area, const ogs_list_t* p_point_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_list_move(data_collection_model_geographic_area_t *geographic_area, ogs_list_t* p_point_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_add_point_list(data_collection_model_geographic_area_t *geographic_area, data_collection_model_geographical_coordinates_t* point_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_remove_point_list(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographical_coordinates_t* point_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_clear_point_list(data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographic_area_get_altitude(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_altitude(data_collection_model_geographic_area_t *geographic_area, const double p_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_altitude_move(data_collection_model_geographic_area_t *geographic_area, double p_altitude);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty_altitude(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_altitude(data_collection_model_geographic_area_t *geographic_area, const float p_uncertainty_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_altitude_move(data_collection_model_geographic_area_t *geographic_area, float p_uncertainty_altitude);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_v_confidence(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_v_confidence(data_collection_model_geographic_area_t *geographic_area, const int32_t p_v_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_v_confidence_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_v_confidence);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_inner_radius(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_inner_radius(data_collection_model_geographic_area_t *geographic_area, const int32_t p_inner_radius);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_inner_radius_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_inner_radius);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty_radius(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_radius(data_collection_model_geographic_area_t *geographic_area, const float p_uncertainty_radius);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_radius_move(data_collection_model_geographic_area_t *geographic_area, float p_uncertainty_radius);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_offset_angle(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_offset_angle(data_collection_model_geographic_area_t *geographic_area, const int32_t p_offset_angle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_offset_angle_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_offset_angle);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_included_angle(const data_collection_model_geographic_area_t *geographic_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_included_angle(data_collection_model_geographic_area_t *geographic_area, const int32_t p_included_angle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_included_angle_move(data_collection_model_geographic_area_t *geographic_area, int32_t p_included_angle);

/* lnode helper for generating ogs_list_t nodes's of type GeographicArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_geographic_area_make_lnode(data_collection_model_geographic_area_t *geographic_area);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GEOGRAPHIC_AREA_H_ */

