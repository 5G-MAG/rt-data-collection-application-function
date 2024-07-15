#ifndef _DATA_COLLECTION_ENDPOINT_ADDRESS_H_
#define _DATA_COLLECTION_ENDPOINT_ADDRESS_H_

/**********************************************************************************************************************************
 * EndpointAddress - Public C interface to the EndpointAddress object
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

typedef struct data_collection_model_endpoint_address_s data_collection_model_endpoint_address_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create_copy(const data_collection_model_endpoint_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create_move(data_collection_model_endpoint_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_copy(data_collection_model_endpoint_address_t *endpoint_address, const data_collection_model_endpoint_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_move(data_collection_model_endpoint_address_t *endpoint_address, data_collection_model_endpoint_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_endpoint_address_free(data_collection_model_endpoint_address_t *endpoint_address);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_endpoint_address_toJSON(const data_collection_model_endpoint_address_t *endpoint_address, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_endpoint_address_get_domain_name(const data_collection_model_endpoint_address_t *endpoint_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_domain_name(data_collection_model_endpoint_address_t *endpoint_address, const char* p_domain_name);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_domain_name_move(data_collection_model_endpoint_address_t *endpoint_address, char* p_domain_name);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_endpoint_address_get_port_numbers(const data_collection_model_endpoint_address_t *endpoint_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_port_numbers(data_collection_model_endpoint_address_t *endpoint_address, const ogs_list_t* p_port_numbers);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_port_numbers_move(data_collection_model_endpoint_address_t *endpoint_address, ogs_list_t* p_port_numbers);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_add_port_numbers(data_collection_model_endpoint_address_t *endpoint_address, int32_t port_numbers);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_remove_port_numbers(data_collection_model_endpoint_address_t *endpoint_address, const int32_t port_numbers);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_clear_port_numbers(data_collection_model_endpoint_address_t *endpoint_address);

/* lnode helper for generating ogs_list_t nodes's of type EndpointAddress */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_endpoint_address_make_lnode(data_collection_model_endpoint_address_t *endpoint_address);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ENDPOINT_ADDRESS_H_ */

