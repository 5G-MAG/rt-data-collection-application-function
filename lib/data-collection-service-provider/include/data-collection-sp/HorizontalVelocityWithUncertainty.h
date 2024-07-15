#ifndef _DATA_COLLECTION_HORIZONTAL_VELOCITY_WITH_UNCERTAINTY_H_
#define _DATA_COLLECTION_HORIZONTAL_VELOCITY_WITH_UNCERTAINTY_H_

/**********************************************************************************************************************************
 * HorizontalVelocityWithUncertainty - Public C interface to the HorizontalVelocityWithUncertainty object
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

typedef struct data_collection_model_horizontal_velocity_with_uncertainty_s data_collection_model_horizontal_velocity_with_uncertainty_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create_copy(const data_collection_model_horizontal_velocity_with_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create_move(data_collection_model_horizontal_velocity_with_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_copy(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const data_collection_model_horizontal_velocity_with_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, data_collection_model_horizontal_velocity_with_uncertainty_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_horizontal_velocity_with_uncertainty_free(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_horizontal_velocity_with_uncertainty_toJSON(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_velocity_with_uncertainty_get_h_speed(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_speed(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const float p_h_speed);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_speed_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, float p_h_speed);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_horizontal_velocity_with_uncertainty_get_bearing(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_bearing(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const int32_t p_bearing);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_bearing_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, int32_t p_bearing);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_velocity_with_uncertainty_get_h_uncertainty(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_uncertainty(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const float p_h_uncertainty);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_uncertainty_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, float p_h_uncertainty);

/* lnode helper for generating ogs_list_t nodes's of type HorizontalVelocityWithUncertainty */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_horizontal_velocity_with_uncertainty_make_lnode(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_HORIZONTAL_VELOCITY_WITH_UNCERTAINTY_H_ */

