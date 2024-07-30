#ifndef _DATA_COLLECTION_EXCEPTION_INFO_H_
#define _DATA_COLLECTION_EXCEPTION_INFO_H_

/**********************************************************************************************************************************
 * ExceptionInfo - Public C interface to the ExceptionInfo object
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
#include "EthFlowDescription.h"
#include "Exception.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_exception_info_s data_collection_model_exception_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_create_copy(const data_collection_model_exception_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_create_move(data_collection_model_exception_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_copy(data_collection_model_exception_info_t *exception_info, const data_collection_model_exception_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_move(data_collection_model_exception_info_t *exception_info, data_collection_model_exception_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_exception_info_free(data_collection_model_exception_info_t *exception_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_exception_info_toJSON(const data_collection_model_exception_info_t *exception_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_info_is_equal_to(const data_collection_model_exception_info_t *exception_info, const data_collection_model_exception_info_t *other_exception_info);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_exception_info_get_ip_traffic_filter(const data_collection_model_exception_info_t *exception_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_ip_traffic_filter(data_collection_model_exception_info_t *exception_info, const data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_ip_traffic_filter_move(data_collection_model_exception_info_t *exception_info, data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_eth_flow_description_t* data_collection_model_exception_info_get_eth_traffic_filter(const data_collection_model_exception_info_t *exception_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_eth_traffic_filter(data_collection_model_exception_info_t *exception_info, const data_collection_model_eth_flow_description_t* p_eth_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_eth_traffic_filter_move(data_collection_model_exception_info_t *exception_info, data_collection_model_eth_flow_description_t* p_eth_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_exception_info_get_exceps(const data_collection_model_exception_info_t *exception_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_exceps(data_collection_model_exception_info_t *exception_info, const ogs_list_t* p_exceps);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_exceps_move(data_collection_model_exception_info_t *exception_info, ogs_list_t* p_exceps);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_add_exceps(data_collection_model_exception_info_t *exception_info, data_collection_model_exception_t* exceps);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_remove_exceps(data_collection_model_exception_info_t *exception_info, const data_collection_model_exception_t* exceps);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_clear_exceps(data_collection_model_exception_info_t *exception_info);

/* lnode helper for generating ogs_list_t nodes's of type ExceptionInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_exception_info_make_lnode(data_collection_model_exception_info_t *exception_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EXCEPTION_INFO_H_ */

