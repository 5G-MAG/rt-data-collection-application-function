#ifndef _DATA_COLLECTION_IPV6_ADDR_H_
#define _DATA_COLLECTION_IPV6_ADDR_H_

/**********************************************************************************************************************************
 * Ipv6Addr - Public C interface to the Ipv6Addr object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ipv6_addr_s data_collection_model_ipv6_addr_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_create_copy(const data_collection_model_ipv6_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_create_move(data_collection_model_ipv6_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_copy(data_collection_model_ipv6_addr_t *ipv6_addr, const data_collection_model_ipv6_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_move(data_collection_model_ipv6_addr_t *ipv6_addr, data_collection_model_ipv6_addr_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ipv6_addr_free(data_collection_model_ipv6_addr_t *ipv6_addr);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ipv6_addr_toJSON(const data_collection_model_ipv6_addr_t *ipv6_addr, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ipv6_addr_is_equal_to(const data_collection_model_ipv6_addr_t *ipv6_addr, const data_collection_model_ipv6_addr_t *other_ipv6_addr);


/* lnode helper for generating ogs_list_t nodes's of type Ipv6Addr */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ipv6_addr_make_lnode(data_collection_model_ipv6_addr_t *ipv6_addr);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_IPV6_ADDR_H_ */

