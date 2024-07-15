#ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_H_
#define _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_H_

/**********************************************************************************************************************************
 * NetworkAssistanceInvocation - Public C interface to the NetworkAssistanceInvocation object
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

#include "NetworkAssistanceInvocation_recommendedQoS.h"
#include "UnidirectionalQoSSpecification.h"
#include "ApplicationFlowDescription.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_network_assistance_invocation_s data_collection_model_network_assistance_invocation_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_copy(const data_collection_model_network_assistance_invocation_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_move(data_collection_model_network_assistance_invocation_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_copy(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_network_assistance_invocation_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_network_assistance_invocation_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_free(data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_toJSON(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_get_policy_template_id(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocation_get_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const ogs_list_t* p_application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, ogs_list_t* p_application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_add_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_application_flow_description_t* application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_remove_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_application_flow_description_t* application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_clear_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_network_assistance_invocation_get_requested_qo_s(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_network_assistance_invocation_get_recommended_qo_s(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/* lnode helper for generating ogs_list_t nodes's of type NetworkAssistanceInvocation */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_make_lnode(data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_H_ */

