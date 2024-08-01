#ifndef _DATA_COLLECTION_LOCAL3D_POINT_UNCERTAINTY_ELLIPSOID_H_
#define _DATA_COLLECTION_LOCAL3D_POINT_UNCERTAINTY_ELLIPSOID_H_

/**********************************************************************************************************************************
 * Local3dPointUncertaintyEllipsoid - Public C interface to the Local3dPointUncertaintyEllipsoid object
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
#include "RelativeCartesianLocation.h"
#include "GADShape.h"
#include "UncertaintyEllipsoid.h"
#include "SupportedGADShapes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_local3d_point_uncertainty_ellipsoid_s data_collection_model_local3d_point_uncertainty_ellipsoid_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_create_copy(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_create_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_copy(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const data_collection_model_local3d_point_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, data_collection_model_local3d_point_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local3d_point_uncertainty_ellipsoid_free(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local3d_point_uncertainty_ellipsoid_toJSON(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local3d_point_uncertainty_ellipsoid_is_equal_to(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const data_collection_model_local3d_point_uncertainty_ellipsoid_t *other_local3d_point_uncertainty_ellipsoid);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_shape(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_shape(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_shape_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_local_origin_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_local_origin(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_local_origin(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const data_collection_model_local_origin_t* p_local_origin);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_local_origin_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, data_collection_model_local_origin_t* p_local_origin);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_relative_cartesian_location_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_point(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_point(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const data_collection_model_relative_cartesian_location_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_point_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, data_collection_model_relative_cartesian_location_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipsoid_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_uncertainty_ellipsoid(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_uncertainty_ellipsoid(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_uncertainty_ellipsoid_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local3d_point_uncertainty_ellipsoid_get_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_confidence(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_confidence_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, int32_t p_confidence);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local3d_point_uncertainty_ellipsoid_get_v_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_v_confidence(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const int32_t p_v_confidence);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_v_confidence_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, int32_t p_v_confidence);

/* lnode helper for generating ogs_list_t nodes's of type Local3dPointUncertaintyEllipsoid */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local3d_point_uncertainty_ellipsoid_make_lnode(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCAL3D_POINT_UNCERTAINTY_ELLIPSOID_H_ */

