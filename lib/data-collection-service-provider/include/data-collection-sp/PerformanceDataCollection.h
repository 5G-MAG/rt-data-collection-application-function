#ifndef _DATA_COLLECTION_PERFORMANCE_DATA_COLLECTION_H_
#define _DATA_COLLECTION_PERFORMANCE_DATA_COLLECTION_H_

/**********************************************************************************************************************************
 * PerformanceDataCollection - Public C interface to the PerformanceDataCollection object
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

#include "IpAddr.h"
#include "FlowInfo.h"
#include "AddrFqdn.h"
#include "PerformanceData.h"
#include "LocationArea5G.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_performance_data_collection_s data_collection_model_performance_data_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create_copy(const data_collection_model_performance_data_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create_move(data_collection_model_performance_data_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_copy(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_performance_data_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_performance_data_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_collection_free(data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_collection_toJSON(const data_collection_model_performance_data_collection_t *performance_data_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_is_equal_to(const data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_performance_data_collection_t *other_performance_data_collection);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_app_id(const data_collection_model_performance_data_collection_t *performance_data_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_collection_get_app_id(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_id(data_collection_model_performance_data_collection_t *performance_data_collection, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_id_move(data_collection_model_performance_data_collection_t *performance_data_collection, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ue_ip_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_performance_data_collection_get_ue_ip_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_ip_addr(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_ip_addr_t* p_ue_ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_ip_addr_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_ip_addr_t* p_ue_ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ip_traffic_filter(const data_collection_model_performance_data_collection_t *performance_data_collection);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_performance_data_collection_get_ip_traffic_filter(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ip_traffic_filter(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ip_traffic_filter_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ue_loc(const data_collection_model_performance_data_collection_t *performance_data_collection);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_collection_get_ue_loc(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_loc(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_location_area5_g_t* p_ue_loc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_loc_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_location_area5_g_t* p_ue_loc);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_app_locs(const data_collection_model_performance_data_collection_t *performance_data_collection);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_performance_data_collection_get_app_locs(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection, const ogs_list_t* p_app_locs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_locs_move(data_collection_model_performance_data_collection_t *performance_data_collection, ogs_list_t* p_app_locs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_add_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection, char* app_locs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_remove_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection, const char* app_locs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_clear_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_as_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_collection_get_as_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_as_addr(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_addr_fqdn_t* p_as_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_as_addr_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_addr_fqdn_t* p_as_addr);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_performance_data_t* data_collection_model_performance_data_collection_get_perf_data(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_perf_data(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_performance_data_t* p_perf_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_perf_data_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_performance_data_t* p_perf_data);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_collection_get_time_stamp(const data_collection_model_performance_data_collection_t *performance_data_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_time_stamp(data_collection_model_performance_data_collection_t *performance_data_collection, const char* p_time_stamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_time_stamp_move(data_collection_model_performance_data_collection_t *performance_data_collection, char* p_time_stamp);

/* lnode helper for generating ogs_list_t nodes's of type PerformanceDataCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_collection_make_lnode(data_collection_model_performance_data_collection_t *performance_data_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERFORMANCE_DATA_COLLECTION_H_ */

