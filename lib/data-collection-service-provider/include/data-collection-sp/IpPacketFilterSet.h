#ifndef _DATA_COLLECTION_IP_PACKET_FILTER_SET_H_
#define _DATA_COLLECTION_IP_PACKET_FILTER_SET_H_

/**********************************************************************************************************************************
 * IpPacketFilterSet - Public C interface to the IpPacketFilterSet object
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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ip_packet_filter_set_s data_collection_model_ip_packet_filter_set_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create_copy(const data_collection_model_ip_packet_filter_set_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create_move(data_collection_model_ip_packet_filter_set_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_copy(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_packet_filter_set_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, data_collection_model_ip_packet_filter_set_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ip_packet_filter_set_free(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ip_packet_filter_set_toJSON(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_is_equal_to(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_packet_filter_set_t *other_ip_packet_filter_set);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ip_packet_filter_set_get_direction(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_direction(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const char* p_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_direction_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, char* p_direction);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_source_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_ip_packet_filter_set_get_source_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_address(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_addr_t* p_source_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_address_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, data_collection_model_ip_addr_t* p_source_address);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_destination_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_ip_packet_filter_set_get_destination_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_address(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_addr_t* p_destination_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_address_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, data_collection_model_ip_addr_t* p_destination_address);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_protocol_number(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_protocol_number(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_protocol_number(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_protocol_number);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_protocol_number_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_protocol_number);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_source_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_source_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_port(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_source_port);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_port_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_source_port);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_destination_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_destination_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_port(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_destination_port);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_port_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_destination_port);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_differentiated_services_code_point(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_differentiated_services_code_point(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_differentiated_services_code_point(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_differentiated_services_code_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_differentiated_services_code_point_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_differentiated_services_code_point);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_flow_label(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_flow_label(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_flow_label(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_flow_label);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_flow_label_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_flow_label);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_security_parameters_index(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_security_parameters_index(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_security_parameters_index(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_security_parameters_index);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_security_parameters_index_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_security_parameters_index);

/* lnode helper for generating ogs_list_t nodes's of type IpPacketFilterSet */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ip_packet_filter_set_make_lnode(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_IP_PACKET_FILTER_SET_H_ */

