#ifndef _DATA_COLLECTION_HORIZONTAL_WITH_VERTICAL_VELOCITY_H_
#define _DATA_COLLECTION_HORIZONTAL_WITH_VERTICAL_VELOCITY_H_

/**********************************************************************************************************************************
 * HorizontalWithVerticalVelocity - Public C interface to the HorizontalWithVerticalVelocity object
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

#include "VerticalDirection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_horizontal_with_vertical_velocity_s data_collection_model_horizontal_with_vertical_velocity_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_create_copy(const data_collection_model_horizontal_with_vertical_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_create_move(data_collection_model_horizontal_with_vertical_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_copy(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, const data_collection_model_horizontal_with_vertical_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_move(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, data_collection_model_horizontal_with_vertical_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_horizontal_with_vertical_velocity_free(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_horizontal_with_vertical_velocity_toJSON(const data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_horizontal_with_vertical_velocity_is_equal_to(const data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, const data_collection_model_horizontal_with_vertical_velocity_t *other_horizontal_with_vertical_velocity);



DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_with_vertical_velocity_get_h_speed(const data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_h_speed(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, const float p_h_speed);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_h_speed_move(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, float p_h_speed);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_horizontal_with_vertical_velocity_get_bearing(const data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_bearing(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, const int32_t p_bearing);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_bearing_move(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, int32_t p_bearing);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_with_vertical_velocity_get_v_speed(const data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_speed(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, const float p_v_speed);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_speed_move(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, float p_v_speed);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_vertical_direction_t* data_collection_model_horizontal_with_vertical_velocity_get_v_direction(const data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_direction(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, const data_collection_model_vertical_direction_t* p_v_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_direction_move(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, data_collection_model_vertical_direction_t* p_v_direction);

/* lnode helper for generating ogs_list_t nodes's of type HorizontalWithVerticalVelocity */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_horizontal_with_vertical_velocity_make_lnode(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_HORIZONTAL_WITH_VERTICAL_VELOCITY_H_ */

