#ifndef _DATA_COLLECTION_COMMUNICATION_RECORD_ALL_OF_H_
#define _DATA_COLLECTION_COMMUNICATION_RECORD_ALL_OF_H_

/**********************************************************************************************************************************
 * CommunicationRecord_allOf - Public C interface to the CommunicationRecord_allOf object
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

#include "TimeWindow.h"
#include "LocationArea5G.h"
#include "Snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_communication_record_all_of_s data_collection_model_communication_record_all_of_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create_copy(const data_collection_model_communication_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create_move(data_collection_model_communication_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_copy(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_communication_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_communication_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_communication_record_all_of_free(data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_communication_record_all_of_toJSON(const data_collection_model_communication_record_all_of_t *communication_record_all_of, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_is_equal_to(const data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_communication_record_all_of_t *other_communication_record_all_of);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_communication_record_all_of_get_time_interval(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_time_interval(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_time_window_t* p_time_interval);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_time_interval_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_time_window_t* p_time_interval);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_slice_info(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_communication_record_all_of_get_slice_info(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_slice_info(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_snssai_t* p_slice_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_slice_info_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_snssai_t* p_slice_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_data_network_name(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_record_all_of_get_data_network_name(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_data_network_name(data_collection_model_communication_record_all_of_t *communication_record_all_of, const char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_data_network_name_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_location(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_communication_record_all_of_get_location(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_location(data_collection_model_communication_record_all_of_t *communication_record_all_of, const ogs_list_t* p_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_location_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, ogs_list_t* p_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_add_location(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_location_area5_g_t* location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_remove_location(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_location_area5_g_t* location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_clear_location(data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_uplink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_all_of_get_uplink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_uplink_volume(data_collection_model_communication_record_all_of_t *communication_record_all_of, const int64_t p_uplink_volume);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_uplink_volume_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, int64_t p_uplink_volume);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_downlink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_all_of_get_downlink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_downlink_volume(data_collection_model_communication_record_all_of_t *communication_record_all_of, const int64_t p_downlink_volume);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_downlink_volume_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, int64_t p_downlink_volume);

/* lnode helper for generating ogs_list_t nodes's of type CommunicationRecord_allOf */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_communication_record_all_of_make_lnode(data_collection_model_communication_record_all_of_t *communication_record_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COMMUNICATION_RECORD_ALL_OF_H_ */

