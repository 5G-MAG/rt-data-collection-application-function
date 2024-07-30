#ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_RECOMMENDED_QO_S_H_
#define _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_RECOMMENDED_QO_S_H_

/**********************************************************************************************************************************
 * NetworkAssistanceInvocation_recommendedQoS - Public C interface to the NetworkAssistanceInvocation_recommendedQoS object
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

typedef struct data_collection_model_network_assistance_invocation_recommended_qo_s_s data_collection_model_network_assistance_invocation_recommended_qo_s_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_create_copy(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_create_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_copy(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, const data_collection_model_network_assistance_invocation_recommended_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, data_collection_model_network_assistance_invocation_recommended_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_recommended_qo_s_free(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_recommended_qo_s_toJSON(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_recommended_qo_s_is_equal_to(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, const data_collection_model_network_assistance_invocation_recommended_qo_s_t *other_network_assistance_invocation_recommended_qo_s);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_recommended_qo_s_get_maximum_bit_rate(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_maximum_bit_rate(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, const char* p_maximum_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_maximum_bit_rate_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, char* p_maximum_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_recommended_qo_s_get_minimum_bit_rate(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_minimum_bit_rate(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, const char* p_minimum_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_minimum_bit_rate_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, char* p_minimum_bit_rate);

/* lnode helper for generating ogs_list_t nodes's of type NetworkAssistanceInvocation_recommendedQoS */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_recommended_qo_s_make_lnode(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_RECOMMENDED_QO_S_H_ */

