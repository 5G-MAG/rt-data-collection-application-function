#ifndef _DATA_COLLECTION_GAD_SHAPE_H_
#define _DATA_COLLECTION_GAD_SHAPE_H_

/**********************************************************************************************************************************
 * GADShape - Public C interface to the GADShape object
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

#include "SupportedGADShapes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_gad_shape_s data_collection_model_gad_shape_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_copy(const data_collection_model_gad_shape_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_move(data_collection_model_gad_shape_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_copy(data_collection_model_gad_shape_t *gad_shape, const data_collection_model_gad_shape_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_move(data_collection_model_gad_shape_t *gad_shape, data_collection_model_gad_shape_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gad_shape_free(data_collection_model_gad_shape_t *gad_shape);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gad_shape_toJSON(const data_collection_model_gad_shape_t *gad_shape, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gad_shape_is_equal_to(const data_collection_model_gad_shape_t *gad_shape, const data_collection_model_gad_shape_t *other_gad_shape);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_gad_shape_get_shape(const data_collection_model_gad_shape_t *gad_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape(data_collection_model_gad_shape_t *gad_shape, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape_move(data_collection_model_gad_shape_t *gad_shape, data_collection_model_supported_gad_shapes_t* p_shape);

/* lnode helper for generating ogs_list_t nodes's of type GADShape */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gad_shape_make_lnode(data_collection_model_gad_shape_t *gad_shape);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GAD_SHAPE_H_ */

