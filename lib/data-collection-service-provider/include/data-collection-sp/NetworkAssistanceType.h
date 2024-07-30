#ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_TYPE_H_
#define _DATA_COLLECTION_NETWORK_ASSISTANCE_TYPE_H_

/**********************************************************************************************************************************
 * NetworkAssistanceType - Public C interface to the NetworkAssistanceType object
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

#include "NetworkAssistanceType_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_network_assistance_type_s data_collection_model_network_assistance_type_t;

typedef enum {
    DCM_NETWORK_ASSISTANCE_TYPE_NO_VAL,
    DCM_NETWORK_ASSISTANCE_TYPE_VAL_AF_THROUGHPUT_ESTIMATION,
    DCM_NETWORK_ASSISTANCE_TYPE_VAL_AF_DELIVERY_BOOST,
    DCM_NETWORK_ASSISTANCE_TYPE_VAL_ANBR_THROUGHPUT_ESTIMATION,
    DCM_NETWORK_ASSISTANCE_TYPE_VAL_ANBR_DELIVERY_BOOST,
    DCM_NETWORK_ASSISTANCE_TYPE_OTHER
} data_collection_model_network_assistance_type_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_t *data_collection_model_network_assistance_type_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_t *data_collection_model_network_assistance_type_create_copy(const data_collection_model_network_assistance_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_t *data_collection_model_network_assistance_type_create_move(data_collection_model_network_assistance_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_t *data_collection_model_network_assistance_type_copy(data_collection_model_network_assistance_type_t *network_assistance_type, const data_collection_model_network_assistance_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_t *data_collection_model_network_assistance_type_move(data_collection_model_network_assistance_type_t *network_assistance_type, data_collection_model_network_assistance_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_type_free(data_collection_model_network_assistance_type_t *network_assistance_type);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_type_toJSON(const data_collection_model_network_assistance_type_t *network_assistance_type, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_t *data_collection_model_network_assistance_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_is_equal_to(const data_collection_model_network_assistance_type_t *network_assistance_type, const data_collection_model_network_assistance_type_t *other_network_assistance_type);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_is_not_set(const data_collection_model_network_assistance_type_t *network_assistance_type);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_is_non_standard(const data_collection_model_network_assistance_type_t *network_assistance_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_e data_collection_model_network_assistance_type_get_enum(const data_collection_model_network_assistance_type_t *network_assistance_type);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_network_assistance_type_get_string(const data_collection_model_network_assistance_type_t *network_assistance_type);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_set_enum(data_collection_model_network_assistance_type_t *network_assistance_type, data_collection_model_network_assistance_type_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_set_string(data_collection_model_network_assistance_type_t *network_assistance_type, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type NetworkAssistanceType */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_type_make_lnode(data_collection_model_network_assistance_type_t *network_assistance_type);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_TYPE_H_ */

