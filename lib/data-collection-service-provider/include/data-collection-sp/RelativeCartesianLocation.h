#ifndef _DATA_COLLECTION_RELATIVE_CARTESIAN_LOCATION_H_
#define _DATA_COLLECTION_RELATIVE_CARTESIAN_LOCATION_H_

/**********************************************************************************************************************************
 * RelativeCartesianLocation - Public C interface to the RelativeCartesianLocation object
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

typedef struct data_collection_model_relative_cartesian_location_s data_collection_model_relative_cartesian_location_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_copy(const data_collection_model_relative_cartesian_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_move(data_collection_model_relative_cartesian_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_copy(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const data_collection_model_relative_cartesian_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, data_collection_model_relative_cartesian_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_relative_cartesian_location_free(data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_relative_cartesian_location_toJSON(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_cartesian_location_is_equal_to(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const data_collection_model_relative_cartesian_location_t *other_relative_cartesian_location);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_x(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const float p_x);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, float p_x);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_y(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const float p_y);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, float p_y);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_z(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const float p_z);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, float p_z);

/* lnode helper for generating ogs_list_t nodes's of type RelativeCartesianLocation */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_relative_cartesian_location_make_lnode(data_collection_model_relative_cartesian_location_t *relative_cartesian_location);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RELATIVE_CARTESIAN_LOCATION_H_ */

