#ifndef _DATA_COLLECTION_ADDR_FQDN_H_
#define _DATA_COLLECTION_ADDR_FQDN_H_

/**********************************************************************************************************************************
 * AddrFqdn - Public C interface to the AddrFqdn object
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

typedef struct data_collection_model_addr_fqdn_s data_collection_model_addr_fqdn_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_copy(const data_collection_model_addr_fqdn_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_move(data_collection_model_addr_fqdn_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_copy(data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_addr_fqdn_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_move(data_collection_model_addr_fqdn_t *addr_fqdn, data_collection_model_addr_fqdn_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_addr_fqdn_free(data_collection_model_addr_fqdn_t *addr_fqdn);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_addr_fqdn_toJSON(const data_collection_model_addr_fqdn_t *addr_fqdn, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_addr_fqdn_is_equal_to(const data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_addr_fqdn_t *other_addr_fqdn);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_addr_fqdn_has_ip_addr(const data_collection_model_addr_fqdn_t *addr_fqdn);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_addr_fqdn_get_ip_addr(const data_collection_model_addr_fqdn_t *addr_fqdn);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr(data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_ip_addr_t* p_ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr_move(data_collection_model_addr_fqdn_t *addr_fqdn, data_collection_model_ip_addr_t* p_ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_addr_fqdn_has_fqdn(const data_collection_model_addr_fqdn_t *addr_fqdn);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_addr_fqdn_get_fqdn(const data_collection_model_addr_fqdn_t *addr_fqdn);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn(data_collection_model_addr_fqdn_t *addr_fqdn, const char* p_fqdn);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn_move(data_collection_model_addr_fqdn_t *addr_fqdn, char* p_fqdn);

/* lnode helper for generating ogs_list_t nodes's of type AddrFqdn */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_addr_fqdn_make_lnode(data_collection_model_addr_fqdn_t *addr_fqdn);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ADDR_FQDN_H_ */

