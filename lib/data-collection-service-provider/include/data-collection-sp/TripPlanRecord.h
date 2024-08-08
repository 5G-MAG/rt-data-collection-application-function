#ifndef _DATA_COLLECTION_TRIP_PLAN_RECORD_H_
#define _DATA_COLLECTION_TRIP_PLAN_RECORD_H_

/**********************************************************************************************************************************
 * TripPlanRecord - Public C interface to the TripPlanRecord object
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

#include "LocationData.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_trip_plan_record_s data_collection_model_trip_plan_record_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_copy(const data_collection_model_trip_plan_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_move(data_collection_model_trip_plan_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_copy(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_trip_plan_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_trip_plan_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_trip_plan_record_free(data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_trip_plan_record_toJSON(const data_collection_model_trip_plan_record_t *trip_plan_record, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_is_equal_to(const data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_trip_plan_record_t *other_trip_plan_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_get_timestamp(const data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp(data_collection_model_trip_plan_record_t *trip_plan_record, const char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp_move(data_collection_model_trip_plan_record_t *trip_plan_record, char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_trip_plan_record_get_context_ids(const data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids_move(data_collection_model_trip_plan_record_t *trip_plan_record, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_starting_point(const data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_location_data_t* p_starting_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_location_data_t* p_starting_point);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_trip_plan_record_get_waypoints(const data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record, const ogs_list_t* p_waypoints);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints_move(data_collection_model_trip_plan_record_t *trip_plan_record, ogs_list_t* p_waypoints);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_location_data_t* waypoints);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_location_data_t* waypoints);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_destination(const data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_location_data_t* p_destination);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_location_data_t* p_destination);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_trip_plan_record_get_estimated_average_speed(const data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed(data_collection_model_trip_plan_record_t *trip_plan_record, const float p_estimated_average_speed);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed_move(data_collection_model_trip_plan_record_t *trip_plan_record, float p_estimated_average_speed);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_get_estimated_arrival_time(const data_collection_model_trip_plan_record_t *trip_plan_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time(data_collection_model_trip_plan_record_t *trip_plan_record, const char* p_estimated_arrival_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time_move(data_collection_model_trip_plan_record_t *trip_plan_record, char* p_estimated_arrival_time);

/* lnode helper for generating ogs_list_t nodes's of type TripPlanRecord */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_trip_plan_record_make_lnode(data_collection_model_trip_plan_record_t *trip_plan_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TRIP_PLAN_RECORD_H_ */
