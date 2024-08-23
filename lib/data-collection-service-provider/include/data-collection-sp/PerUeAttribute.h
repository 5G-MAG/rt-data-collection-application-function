#ifndef _DATA_COLLECTION_PER_UE_ATTRIBUTE_H_
#define _DATA_COLLECTION_PER_UE_ATTRIBUTE_H_

/**********************************************************************************************************************************
 * PerUeAttribute - Public C interface to the PerUeAttribute object
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

#include "LocationArea5G.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_per_ue_attribute_s data_collection_model_per_ue_attribute_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_copy(const data_collection_model_per_ue_attribute_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_move(data_collection_model_per_ue_attribute_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_copy(data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_per_ue_attribute_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, data_collection_model_per_ue_attribute_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_per_ue_attribute_free(data_collection_model_per_ue_attribute_t *per_ue_attribute);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_per_ue_attribute_toJSON(const data_collection_model_per_ue_attribute_t *per_ue_attribute, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_is_equal_to(const data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_per_ue_attribute_t *other_per_ue_attribute);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_ue_dest(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_per_ue_attribute_get_ue_dest(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest(data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_location_area5_g_t* p_ue_dest);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, data_collection_model_location_area5_g_t* p_ue_dest);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_route(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_route(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route(data_collection_model_per_ue_attribute_t *per_ue_attribute, const char* p_route);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, char* p_route);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_avg_speed(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_avg_speed(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed(data_collection_model_per_ue_attribute_t *per_ue_attribute, const char* p_avg_speed);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, char* p_avg_speed);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_time_of_arrival(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_time_of_arrival(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival(data_collection_model_per_ue_attribute_t *per_ue_attribute, const char* p_time_of_arrival);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, char* p_time_of_arrival);

/* lnode helper for generating ogs_list_t nodes's of type PerUeAttribute */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_per_ue_attribute_make_lnode(data_collection_model_per_ue_attribute_t *per_ue_attribute);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PER_UE_ATTRIBUTE_H_ */

