#ifndef _DATA_COLLECTION_DYNAMIC_POLICY_INVOCATION_EVENT_ALL_OF_H_
#define _DATA_COLLECTION_DYNAMIC_POLICY_INVOCATION_EVENT_ALL_OF_H_

/**********************************************************************************************************************************
 * DynamicPolicyInvocationEvent_allOf - Public C interface to the DynamicPolicyInvocationEvent_allOf object
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

#include "UnidirectionalQoSSpecification.h"
#include "ApplicationFlowDescription.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_dynamic_policy_invocation_event_all_of_s data_collection_model_dynamic_policy_invocation_event_all_of_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create_copy(const data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_copy(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dynamic_policy_invocation_event_all_of_free(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dynamic_policy_invocation_event_all_of_toJSON(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_policy_template_id(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_policy_template_id(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_policy_template_id_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_application_flow_descriptions(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const ogs_list_t* p_application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_application_flow_descriptions_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, ogs_list_t* p_application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_add_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, data_collection_model_application_flow_description_t* application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_remove_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_application_flow_description_t* application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_clear_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_requested_qo_s(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_requested_qo_s(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_requested_qo_s_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_enforcement_method(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_method(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const char* p_enforcement_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_method_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, char* p_enforcement_method);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_enforcement_bit_rate(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_bit_rate(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const char* p_enforcement_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_bit_rate_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, char* p_enforcement_bit_rate);

/* lnode helper for generating ogs_list_t nodes's of type DynamicPolicyInvocationEvent_allOf */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dynamic_policy_invocation_event_all_of_make_lnode(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DYNAMIC_POLICY_INVOCATION_EVENT_ALL_OF_H_ */

