#ifndef _DATA_COLLECTION_RANGE_DIRECTION_H_
#define _DATA_COLLECTION_RANGE_DIRECTION_H_

/**********************************************************************************************************************************
 * RangeDirection - Public C interface to the RangeDirection object
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

typedef struct data_collection_model_range_direction_s data_collection_model_range_direction_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_copy(const data_collection_model_range_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_move(data_collection_model_range_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_copy(data_collection_model_range_direction_t *range_direction, const data_collection_model_range_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_move(data_collection_model_range_direction_t *range_direction, data_collection_model_range_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_range_direction_free(data_collection_model_range_direction_t *range_direction);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_range_direction_toJSON(const data_collection_model_range_direction_t *range_direction, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_is_equal_to(const data_collection_model_range_direction_t *range_direction, const data_collection_model_range_direction_t *other_range_direction);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_distance(const data_collection_model_range_direction_t *range_direction);


DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_range_direction_get_distance(const data_collection_model_range_direction_t *range_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_distance(data_collection_model_range_direction_t *range_direction, const double p_distance);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_distance_move(data_collection_model_range_direction_t *range_direction, double p_distance);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_azimuth_direction(const data_collection_model_range_direction_t *range_direction);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_range_direction_get_azimuth_direction(const data_collection_model_range_direction_t *range_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction(data_collection_model_range_direction_t *range_direction, const int32_t p_azimuth_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction_move(data_collection_model_range_direction_t *range_direction, int32_t p_azimuth_direction);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_elevation_direction(const data_collection_model_range_direction_t *range_direction);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_range_direction_get_elevation_direction(const data_collection_model_range_direction_t *range_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction(data_collection_model_range_direction_t *range_direction, const int32_t p_elevation_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction_move(data_collection_model_range_direction_t *range_direction, int32_t p_elevation_direction);

/* lnode helper for generating ogs_list_t nodes's of type RangeDirection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_range_direction_make_lnode(data_collection_model_range_direction_t *range_direction);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RANGE_DIRECTION_H_ */

