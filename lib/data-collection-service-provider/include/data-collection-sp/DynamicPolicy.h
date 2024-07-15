#ifndef _DATA_COLLECTION_DYNAMIC_POLICY_H_
#define _DATA_COLLECTION_DYNAMIC_POLICY_H_

/**********************************************************************************************************************************
 * DynamicPolicy - Public C interface to the DynamicPolicy object
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

#include "M5QoSSpecification.h"
#include "ApplicationFlowDescription.h"
#include "MediaType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_dynamic_policy_s data_collection_model_dynamic_policy_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create_copy(const data_collection_model_dynamic_policy_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create_move(data_collection_model_dynamic_policy_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_copy(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_dynamic_policy_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_move(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_dynamic_policy_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dynamic_policy_free(data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dynamic_policy_toJSON(const data_collection_model_dynamic_policy_t *dynamic_policy, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_dynamic_policy_id(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_dynamic_policy_id(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_dynamic_policy_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_dynamic_policy_id_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_dynamic_policy_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_policy_template_id(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_policy_template_id(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_policy_template_id_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dynamic_policy_get_service_data_flow_descriptions(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy, const ogs_list_t* p_service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_service_data_flow_descriptions_move(data_collection_model_dynamic_policy_t *dynamic_policy, ogs_list_t* p_service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_add_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_application_flow_description_t* service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_remove_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_application_flow_description_t* service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_clear_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_type_t* data_collection_model_dynamic_policy_get_media_type(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_media_type(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_media_type_t* p_media_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_media_type_move(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_media_type_t* p_media_type);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_provisioning_session_id(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_provisioning_session_id(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_provisioning_session_id_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_qo_s_specification_t* data_collection_model_dynamic_policy_get_qos_specification(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_qos_specification(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_m5_qo_s_specification_t* p_qos_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_qos_specification_move(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_m5_qo_s_specification_t* p_qos_specification);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_enforcement_method(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_method(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_enforcement_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_method_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_enforcement_method);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_dynamic_policy_get_enforcement_bit_rate(const data_collection_model_dynamic_policy_t *dynamic_policy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_bit_rate(data_collection_model_dynamic_policy_t *dynamic_policy, const int32_t p_enforcement_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_bit_rate_move(data_collection_model_dynamic_policy_t *dynamic_policy, int32_t p_enforcement_bit_rate);

/* lnode helper for generating ogs_list_t nodes's of type DynamicPolicy */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dynamic_policy_make_lnode(data_collection_model_dynamic_policy_t *dynamic_policy);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DYNAMIC_POLICY_H_ */

