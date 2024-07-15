#ifndef _DATA_COLLECTION_HORIZONTAL_VELOCITY_H_
#define _DATA_COLLECTION_HORIZONTAL_VELOCITY_H_

/**********************************************************************************************************************************
 * HorizontalVelocity - Public C interface to the HorizontalVelocity object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_horizontal_velocity_s data_collection_model_horizontal_velocity_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_create_copy(const data_collection_model_horizontal_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_create_move(data_collection_model_horizontal_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_copy(data_collection_model_horizontal_velocity_t *horizontal_velocity, const data_collection_model_horizontal_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_move(data_collection_model_horizontal_velocity_t *horizontal_velocity, data_collection_model_horizontal_velocity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_horizontal_velocity_free(data_collection_model_horizontal_velocity_t *horizontal_velocity);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_horizontal_velocity_toJSON(const data_collection_model_horizontal_velocity_t *horizontal_velocity, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_velocity_get_h_speed(const data_collection_model_horizontal_velocity_t *horizontal_velocity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_set_h_speed(data_collection_model_horizontal_velocity_t *horizontal_velocity, const float p_h_speed);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_set_h_speed_move(data_collection_model_horizontal_velocity_t *horizontal_velocity, float p_h_speed);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_horizontal_velocity_get_bearing(const data_collection_model_horizontal_velocity_t *horizontal_velocity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_set_bearing(data_collection_model_horizontal_velocity_t *horizontal_velocity, const int32_t p_bearing);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_t *data_collection_model_horizontal_velocity_set_bearing_move(data_collection_model_horizontal_velocity_t *horizontal_velocity, int32_t p_bearing);

/* lnode helper for generating ogs_list_t nodes's of type HorizontalVelocity */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_horizontal_velocity_make_lnode(data_collection_model_horizontal_velocity_t *horizontal_velocity);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_HORIZONTAL_VELOCITY_H_ */

