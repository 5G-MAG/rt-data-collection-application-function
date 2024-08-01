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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_point_uncertainty_circle_s data_collection_model_point_uncertainty_circle_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_copy(const data_collection_model_point_uncertainty_circle_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_move(data_collection_model_point_uncertainty_circle_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_copy(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_point_uncertainty_circle_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_point_uncertainty_circle_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_uncertainty_circle_free(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_uncertainty_circle_toJSON(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_uncertainty_circle_is_equal_to(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_point_uncertainty_circle_t *other_point_uncertainty_circle);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_uncertainty_circle_get_shape(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_uncertainty_circle_get_point(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_point_uncertainty_circle_get_uncertainty(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const float p_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, float p_uncertainty);

/* lnode helper for generating ogs_list_t nodes's of type PointUncertaintyCircle */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_uncertainty_circle_make_lnode(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POINT_UNCERTAINTY_CIRCLE_H_ */

