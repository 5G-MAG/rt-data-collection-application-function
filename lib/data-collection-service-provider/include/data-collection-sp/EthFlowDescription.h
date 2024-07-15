#ifndef _DATA_COLLECTION_ETH_FLOW_DESCRIPTION_H_
#define _DATA_COLLECTION_ETH_FLOW_DESCRIPTION_H_

/**********************************************************************************************************************************
 * EthFlowDescription - Public C interface to the EthFlowDescription object
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

#include "FlowDirection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_eth_flow_description_s data_collection_model_eth_flow_description_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create_copy(const data_collection_model_eth_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create_move(data_collection_model_eth_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_copy(data_collection_model_eth_flow_description_t *eth_flow_description, const data_collection_model_eth_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_move(data_collection_model_eth_flow_description_t *eth_flow_description, data_collection_model_eth_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_eth_flow_description_free(data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_eth_flow_description_toJSON(const data_collection_model_eth_flow_description_t *eth_flow_description, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_dest_mac_addr(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_dest_mac_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_dest_mac_addr);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_eth_type(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_eth_type(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_eth_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_eth_type_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_eth_type);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_f_desc(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_desc(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_f_desc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_desc_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_f_desc);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_direction_t* data_collection_model_eth_flow_description_get_f_dir(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_dir(data_collection_model_eth_flow_description_t *eth_flow_description, const data_collection_model_flow_direction_t* p_f_dir);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_dir_move(data_collection_model_eth_flow_description_t *eth_flow_description, data_collection_model_flow_direction_t* p_f_dir);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_source_mac_addr(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_source_mac_addr(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_source_mac_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_source_mac_addr_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_source_mac_addr);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_eth_flow_description_get_vlan_tags(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description, const ogs_list_t* p_vlan_tags);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_vlan_tags_move(data_collection_model_eth_flow_description_t *eth_flow_description, ogs_list_t* p_vlan_tags);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_add_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description, char* vlan_tags);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_remove_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description, const char* vlan_tags);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_clear_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_src_mac_addr_end(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_src_mac_addr_end(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_src_mac_addr_end);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_src_mac_addr_end_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_src_mac_addr_end);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_dest_mac_addr_end(const data_collection_model_eth_flow_description_t *eth_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_end(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_dest_mac_addr_end);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_end_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_dest_mac_addr_end);

/* lnode helper for generating ogs_list_t nodes's of type EthFlowDescription */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_eth_flow_description_make_lnode(data_collection_model_eth_flow_description_t *eth_flow_description);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ETH_FLOW_DESCRIPTION_H_ */

