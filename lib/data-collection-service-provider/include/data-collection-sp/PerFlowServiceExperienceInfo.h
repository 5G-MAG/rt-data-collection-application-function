#ifndef _DATA_COLLECTION_PER_FLOW_SERVICE_EXPERIENCE_INFO_H_
#define _DATA_COLLECTION_PER_FLOW_SERVICE_EXPERIENCE_INFO_H_

/**********************************************************************************************************************************
 * PerFlowServiceExperienceInfo - Public C interface to the PerFlowServiceExperienceInfo object
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

#include "SvcExperience.h"
#include "AddrFqdn.h"
#include "TimeWindow.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_per_flow_service_experience_info_s data_collection_model_per_flow_service_experience_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create_copy(const data_collection_model_per_flow_service_experience_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create_move(data_collection_model_per_flow_service_experience_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_copy(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_per_flow_service_experience_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_per_flow_service_experience_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_per_flow_service_experience_info_free(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_per_flow_service_experience_info_toJSON(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_svc_experience_t* data_collection_model_per_flow_service_experience_info_get_service_experience(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_service_experience(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_svc_experience_t* p_service_experience);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_service_experience_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_svc_experience_t* p_service_experience);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_per_flow_service_experience_info_get_time_interval(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_time_interval(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_time_window_t* p_time_interval);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_time_interval_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_time_window_t* p_time_interval);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_per_flow_service_experience_info_get_remote_endpoint(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_remote_endpoint(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_addr_fqdn_t* p_remote_endpoint);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_remote_endpoint_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_addr_fqdn_t* p_remote_endpoint);

/* lnode helper for generating ogs_list_t nodes's of type PerFlowServiceExperienceInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_per_flow_service_experience_info_make_lnode(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PER_FLOW_SERVICE_EXPERIENCE_INFO_H_ */

