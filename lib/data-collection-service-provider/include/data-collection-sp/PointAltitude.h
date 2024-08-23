#ifndef _DATA_COLLECTION_POINT_ALTITUDE_H_
#define _DATA_COLLECTION_POINT_ALTITUDE_H_

/**********************************************************************************************************************************
 * PointAltitude - Public C interface to the PointAltitude object
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

typedef struct data_collection_model_point_altitude_s data_collection_model_point_altitude_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_create_copy(const data_collection_model_point_altitude_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_create_move(data_collection_model_point_altitude_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_copy(data_collection_model_point_altitude_t *point_altitude, const data_collection_model_point_altitude_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_move(data_collection_model_point_altitude_t *point_altitude, data_collection_model_point_altitude_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_altitude_free(data_collection_model_point_altitude_t *point_altitude);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_altitude_toJSON(const data_collection_model_point_altitude_t *point_altitude, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_is_equal_to(const data_collection_model_point_altitude_t *point_altitude, const data_collection_model_point_altitude_t *other_point_altitude);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_altitude_get_shape(const data_collection_model_point_altitude_t *point_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_shape(data_collection_model_point_altitude_t *point_altitude, const data_collection_model_supported_gad_shapes_t* p_shape);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_shape_move(data_collection_model_point_altitude_t *point_altitude, data_collection_model_supported_gad_shapes_t* p_shape);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_get_point(const data_collection_model_point_altitude_t *point_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_point(data_collection_model_point_altitude_t *point_altitude, const data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_point_move(data_collection_model_point_altitude_t *point_altitude, data_collection_model_geographical_coordinates_t* p_point);


DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_point_altitude_get_altitude(const data_collection_model_point_altitude_t *point_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_altitude(data_collection_model_point_altitude_t *point_altitude, const double p_altitude);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_altitude_move(data_collection_model_point_altitude_t *point_altitude, double p_altitude);

/* lnode helper for generating ogs_list_t nodes's of type PointAltitude */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_altitude_make_lnode(data_collection_model_point_altitude_t *point_altitude);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POINT_ALTITUDE_H_ */

