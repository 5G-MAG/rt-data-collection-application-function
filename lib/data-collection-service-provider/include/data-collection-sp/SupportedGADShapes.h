#ifndef _DATA_COLLECTION_SUPPORTED_GAD_SHAPES_H_
#define _DATA_COLLECTION_SUPPORTED_GAD_SHAPES_H_

/**********************************************************************************************************************************
 * SupportedGADShapes - Public C interface to the SupportedGADShapes object
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

#include "SupportedGADShapes_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_supported_gad_shapes_s data_collection_model_supported_gad_shapes_t;

typedef enum {
    DCM_SUPPORTED_GAD_SHAPES_NO_VAL,
    DCM_SUPPORTED_GAD_SHAPES_VAL_POINT,
    DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_UNCERTAINTY_CIRCLE,
    DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_UNCERTAINTY_ELLIPSE,
    DCM_SUPPORTED_GAD_SHAPES_VAL_POLYGON,
    DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_ALTITUDE,
    DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_ALTITUDE_UNCERTAINTY,
    DCM_SUPPORTED_GAD_SHAPES_VAL_ELLIPSOID_ARC,
    DCM_SUPPORTED_GAD_SHAPES_VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE,
    DCM_SUPPORTED_GAD_SHAPES_VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID,
    DCM_SUPPORTED_GAD_SHAPES_VAL_RANGE_DIRECTION,
    DCM_SUPPORTED_GAD_SHAPES_VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE,
    DCM_SUPPORTED_GAD_SHAPES_VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID,
    DCM_SUPPORTED_GAD_SHAPES_OTHER
} data_collection_model_supported_gad_shapes_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_create_copy(const data_collection_model_supported_gad_shapes_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_create_move(data_collection_model_supported_gad_shapes_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_copy(data_collection_model_supported_gad_shapes_t *supported_gad_shapes, const data_collection_model_supported_gad_shapes_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_move(data_collection_model_supported_gad_shapes_t *supported_gad_shapes, data_collection_model_supported_gad_shapes_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_supported_gad_shapes_free(data_collection_model_supported_gad_shapes_t *supported_gad_shapes);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_supported_gad_shapes_toJSON(const data_collection_model_supported_gad_shapes_t *supported_gad_shapes, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_is_not_set(const data_collection_model_supported_gad_shapes_t *supported_gad_shapes);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_is_non_standard(const data_collection_model_supported_gad_shapes_t *supported_gad_shapes);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_e data_collection_model_supported_gad_shapes_get_enum(const data_collection_model_supported_gad_shapes_t *supported_gad_shapes);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_supported_gad_shapes_get_string(const data_collection_model_supported_gad_shapes_t *supported_gad_shapes);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_set_enum(data_collection_model_supported_gad_shapes_t *supported_gad_shapes, data_collection_model_supported_gad_shapes_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_set_string(data_collection_model_supported_gad_shapes_t *supported_gad_shapes, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type SupportedGADShapes */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_supported_gad_shapes_make_lnode(data_collection_model_supported_gad_shapes_t *supported_gad_shapes);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SUPPORTED_GAD_SHAPES_H_ */

