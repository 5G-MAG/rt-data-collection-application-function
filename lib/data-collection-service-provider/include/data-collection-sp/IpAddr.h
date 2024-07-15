#ifndef _DATA_COLLECTION_IP_ADDR_H_
#define _DATA_COLLECTION_IP_ADDR_H_

/**********************************************************************************************************************************
 * IpAddr - Public C interface to the IpAddr object
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

#include "Ipv6Prefix.h"
#include "Ipv6Addr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ip_addr_s data_collection_model_ip_addr_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_copy(const data_collection_model_ip_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_move(data_collection_model_ip_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_copy(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ip_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ip_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ip_addr_free(data_collection_model_ip_addr_t *ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ip_addr_toJSON(const data_collection_model_ip_addr_t *ip_addr, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ip_addr_get_ipv4_addr(const data_collection_model_ip_addr_t *ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr(data_collection_model_ip_addr_t *ip_addr, const char* p_ipv4_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr_move(data_collection_model_ip_addr_t *ip_addr, char* p_ipv4_addr);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ipv6_addr_t* data_collection_model_ip_addr_get_ipv6_addr(const data_collection_model_ip_addr_t *ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ipv6_addr_t* p_ipv6_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ipv6_addr_t* p_ipv6_addr);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ipv6_prefix_t* data_collection_model_ip_addr_get_ipv6_prefix(const data_collection_model_ip_addr_t *ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ipv6_prefix_t* p_ipv6_prefix);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ipv6_prefix_t* p_ipv6_prefix);

/* lnode helper for generating ogs_list_t nodes's of type IpAddr */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ip_addr_make_lnode(data_collection_model_ip_addr_t *ip_addr);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_IP_ADDR_H_ */

