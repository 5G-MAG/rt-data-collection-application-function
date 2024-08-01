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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ellipsoid_arc_s data_collection_model_ellipsoid_arc_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_copy(const data_collection_model_ellipsoid_arc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_move(data_collection_model_ellipsoid_arc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_copy(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_ellipsoid_arc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, data_collection_model_ellipsoid_arc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ellipsoid_arc_free(data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ellipsoid_arc_toJSON(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ellipsoid_arc_is_equal_to(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_ellipsoid_arc_t *other_ellipsoid_arc);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_ellipsoid_arc_get_shape(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_shape(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_shape_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_ellipsoid_arc_get_point(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_point(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_point_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_inner_radius(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_inner_radius(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_inner_radius);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_inner_radius_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_inner_radius);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_ellipsoid_arc_get_uncertainty_radius(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_uncertainty_radius(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const float p_uncertainty_radius);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_uncertainty_radius_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, float p_uncertainty_radius);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_offset_angle(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_offset_angle(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_offset_angle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_offset_angle_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_offset_angle);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_included_angle(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_included_angle(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_included_angle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_included_angle_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_included_angle);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_confidence(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_confidence(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_confidence_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, int32_t p_confidence);

/* lnode helper for generating ogs_list_t nodes's of type EllipsoidArc */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ellipsoid_arc_make_lnode(data_collection_model_ellipsoid_arc_t *ellipsoid_arc);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ELLIPSOID_ARC_H_ */

