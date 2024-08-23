#ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_FLOW_H_
#define _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_FLOW_H_

/**********************************************************************************************************************************
 * ServiceExperienceInfoPerFlow - Public C interface to the ServiceExperienceInfoPerFlow object
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

#include "FlowInfo.h"
#include "SvcExperience.h"
#include "EthFlowDescription.h"
#include "TimeWindow.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_service_experience_info_per_flow_s data_collection_model_service_experience_info_per_flow_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create_copy(const data_collection_model_service_experience_info_per_flow_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create_move(data_collection_model_service_experience_info_per_flow_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_copy(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_service_experience_info_per_flow_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_service_experience_info_per_flow_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_service_experience_info_per_flow_free(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_service_experience_info_per_flow_toJSON(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_is_equal_to(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_service_experience_info_per_flow_t *other_service_experience_info_per_flow);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_svc_exprc(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_svc_experience_t* data_collection_model_service_experience_info_per_flow_get_svc_exprc(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_svc_exprc(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_svc_experience_t* p_svc_exprc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_svc_exprc_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_svc_experience_t* p_svc_exprc);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_time_intev(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_service_experience_info_per_flow_get_time_intev(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_time_intev(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_time_window_t* p_time_intev);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_time_intev_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_time_window_t* p_time_intev);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_dnai(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_flow_get_dnai(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_dnai(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const char* p_dnai);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_dnai_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, char* p_dnai);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_ip_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_service_experience_info_per_flow_get_ip_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_ip_traffic_filter(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_ip_traffic_filter_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_eth_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_eth_flow_description_t* data_collection_model_service_experience_info_per_flow_get_eth_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_eth_traffic_filter(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_eth_flow_description_t* p_eth_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_eth_traffic_filter_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_eth_flow_description_t* p_eth_traffic_filter);

/* lnode helper for generating ogs_list_t nodes's of type ServiceExperienceInfoPerFlow */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_service_experience_info_per_flow_make_lnode(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_FLOW_H_ */

