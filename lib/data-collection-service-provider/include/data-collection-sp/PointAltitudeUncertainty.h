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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_point_altitude_uncertainty_s data_collection_model_point_altitude_uncertainty_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create_copy(const data_collection_model_point_altitude_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create_move(data_collection_model_point_altitude_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_copy(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_point_altitude_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_point_altitude_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_altitude_uncertainty_free(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_altitude_uncertainty_toJSON(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_is_equal_to(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_point_altitude_uncertainty_t *other_point_altitude_uncertainty);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_altitude_uncertainty_get_shape(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_shape(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_shape_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_supported_gad_shapes_t* p_shape);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_uncertainty_get_point(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_point(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_point_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_geographical_coordinates_t* p_point);


DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_point_altitude_uncertainty_get_altitude(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_altitude(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const double p_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_altitude_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, double p_altitude);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_point_altitude_uncertainty_get_uncertainty_ellipse(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_ellipse(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_ellipse_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_point_altitude_uncertainty_get_uncertainty_altitude(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_altitude(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const float p_uncertainty_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_altitude_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, float p_uncertainty_altitude);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_get_confidence(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_confidence(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_confidence_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_has_v_confidence(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_get_v_confidence(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_v_confidence(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const int32_t p_v_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_v_confidence_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, int32_t p_v_confidence);

/* lnode helper for generating ogs_list_t nodes's of type PointAltitudeUncertainty */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_altitude_uncertainty_make_lnode(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POINT_ALTITUDE_UNCERTAINTY_H_ */

