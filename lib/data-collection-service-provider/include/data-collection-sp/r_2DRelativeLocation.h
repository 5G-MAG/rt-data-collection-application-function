#ifndef _DATA_COLLECTION_R_2_D_RELATIVE_LOCATION_H_
#define _DATA_COLLECTION_R_2_D_RELATIVE_LOCATION_H_

/**********************************************************************************************************************************
 * r_2DRelativeLocation - Public C interface to the r_2DRelativeLocation object
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

typedef struct data_collection_model_r_2_d_relative_location_s data_collection_model_r_2_d_relative_location_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_create_copy(const data_collection_model_r_2_d_relative_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_create_move(data_collection_model_r_2_d_relative_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_copy(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, const data_collection_model_r_2_d_relative_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_move(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, data_collection_model_r_2_d_relative_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_r_2_d_relative_location_free(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_r_2_d_relative_location_toJSON(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_2_d_relative_location_is_equal_to(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, const data_collection_model_r_2_d_relative_location_t *other_r_2_d_relative_location);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_2_d_relative_location_has_semi_minor(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_r_2_d_relative_location_get_semi_minor(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_minor(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, const float p_semi_minor);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_minor_move(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, float p_semi_minor);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_2_d_relative_location_has_semi_major(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_r_2_d_relative_location_get_semi_major(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_major(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, const float p_semi_major);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_major_move(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, float p_semi_major);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_2_d_relative_location_has_orientation_angle(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_r_2_d_relative_location_get_orientation_angle(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_orientation_angle(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, const int32_t p_orientation_angle);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_orientation_angle_move(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, int32_t p_orientation_angle);

/* lnode helper for generating ogs_list_t nodes's of type r_2DRelativeLocation */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_r_2_d_relative_location_make_lnode(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_R_2_D_RELATIVE_LOCATION_H_ */

