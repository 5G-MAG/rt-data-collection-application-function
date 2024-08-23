#ifndef _DATA_COLLECTION_POINT_H_
#define _DATA_COLLECTION_POINT_H_

/**********************************************************************************************************************************
 * Point - Public C interface to the Point object
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

typedef struct data_collection_model_point_s data_collection_model_point_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_create_copy(const data_collection_model_point_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_create_move(data_collection_model_point_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_copy(data_collection_model_point_t *point, const data_collection_model_point_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_move(data_collection_model_point_t *point, data_collection_model_point_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_free(data_collection_model_point_t *point);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_toJSON(const data_collection_model_point_t *point, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_is_equal_to(const data_collection_model_point_t *point, const data_collection_model_point_t *other_point);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_get_shape(const data_collection_model_point_t *point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_set_shape(data_collection_model_point_t *point, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_set_shape_move(data_collection_model_point_t *point, data_collection_model_supported_gad_shapes_t* p_shape);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_get_point(const data_collection_model_point_t *point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_set_point(data_collection_model_point_t *point, const data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_t *data_collection_model_point_set_point_move(data_collection_model_point_t *point, data_collection_model_geographical_coordinates_t* p_point);

/* lnode helper for generating ogs_list_t nodes's of type Point */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_make_lnode(data_collection_model_point_t *point);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POINT_H_ */

