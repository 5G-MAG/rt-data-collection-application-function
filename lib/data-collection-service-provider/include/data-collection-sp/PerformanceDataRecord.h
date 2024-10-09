#ifndef _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_H_
#define _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_H_

/**********************************************************************************************************************************
 * PerformanceDataRecord - Public C interface to the PerformanceDataRecord object
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

#include "AddrFqdn.h"
#include "TimeWindow.h"
#include "LocationArea5G.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_performance_data_record_s data_collection_model_performance_data_record_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_copy(const data_collection_model_performance_data_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_move(data_collection_model_performance_data_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_copy(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_performance_data_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_performance_data_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_record_free(data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_record_toJSON(const data_collection_model_performance_data_record_t *performance_data_record, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_is_equal_to(const data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_performance_data_record_t *other_performance_data_record);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_timestamp(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp(data_collection_model_performance_data_record_t *performance_data_record, const char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp_move(data_collection_model_performance_data_record_t *performance_data_record, char* p_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_performance_data_record_get_context_ids(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids(data_collection_model_performance_data_record_t *performance_data_record, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids_move(data_collection_model_performance_data_record_t *performance_data_record, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_add_context_ids(data_collection_model_performance_data_record_t *performance_data_record, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_remove_context_ids(data_collection_model_performance_data_record_t *performance_data_record, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_entry_context_ids(const data_collection_model_performance_data_record_t *performance_data_record, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_clear_context_ids(data_collection_model_performance_data_record_t *performance_data_record);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_performance_data_record_get_time_interval(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_time_window_t* p_time_interval);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_time_window_t* p_time_interval);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_location(const data_collection_model_performance_data_record_t *performance_data_record);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_record_get_location(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_location_area5_g_t* p_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_location_area5_g_t* p_location);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_remote_endpoint(const data_collection_model_performance_data_record_t *performance_data_record);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_record_get_remote_endpoint(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_addr_fqdn_t* p_remote_endpoint);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_addr_fqdn_t* p_remote_endpoint);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_packet_delay_budget(const data_collection_model_performance_data_record_t *performance_data_record);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_get_packet_delay_budget(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget(data_collection_model_performance_data_record_t *performance_data_record, const int32_t p_packet_delay_budget);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget_move(data_collection_model_performance_data_record_t *performance_data_record, int32_t p_packet_delay_budget);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_packet_loss_rate(const data_collection_model_performance_data_record_t *performance_data_record);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_get_packet_loss_rate(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate(data_collection_model_performance_data_record_t *performance_data_record, const int32_t p_packet_loss_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate_move(data_collection_model_performance_data_record_t *performance_data_record, int32_t p_packet_loss_rate);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_uplink_throughput(const data_collection_model_performance_data_record_t *performance_data_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_uplink_throughput(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput(data_collection_model_performance_data_record_t *performance_data_record, const char* p_uplink_throughput);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput_move(data_collection_model_performance_data_record_t *performance_data_record, char* p_uplink_throughput);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_downlink_througput(const data_collection_model_performance_data_record_t *performance_data_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_downlink_througput(const data_collection_model_performance_data_record_t *performance_data_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput(data_collection_model_performance_data_record_t *performance_data_record, const char* p_downlink_througput);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput_move(data_collection_model_performance_data_record_t *performance_data_record, char* p_downlink_througput);

/* lnode helper for generating ogs_list_t nodes's of type PerformanceDataRecord */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_record_make_lnode(data_collection_model_performance_data_record_t *performance_data_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_H_ */

