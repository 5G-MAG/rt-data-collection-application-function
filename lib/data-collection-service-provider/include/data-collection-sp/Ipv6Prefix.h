#ifndef _DATA_COLLECTION_IPV6_PREFIX_H_
#define _DATA_COLLECTION_IPV6_PREFIX_H_

/**********************************************************************************************************************************
 * Ipv6Prefix - Public C interface to the Ipv6Prefix object
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

typedef struct data_collection_model_ipv6_prefix_s data_collection_model_ipv6_prefix_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_copy(const data_collection_model_ipv6_prefix_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_move(data_collection_model_ipv6_prefix_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_copy(data_collection_model_ipv6_prefix_t *ipv6_prefix, const data_collection_model_ipv6_prefix_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_move(data_collection_model_ipv6_prefix_t *ipv6_prefix, data_collection_model_ipv6_prefix_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ipv6_prefix_free(data_collection_model_ipv6_prefix_t *ipv6_prefix);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ipv6_prefix_toJSON(const data_collection_model_ipv6_prefix_t *ipv6_prefix, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


/* lnode helper for generating ogs_list_t nodes's of type Ipv6Prefix */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ipv6_prefix_make_lnode(data_collection_model_ipv6_prefix_t *ipv6_prefix);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_IPV6_PREFIX_H_ */

