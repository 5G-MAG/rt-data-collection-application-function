#ifndef _DATA_COLLECTION_ANBR_NETWORK_ASSISTANCE_INVOCATION_RECORD_H_
#define _DATA_COLLECTION_ANBR_NETWORK_ASSISTANCE_INVOCATION_RECORD_H_

/**********************************************************************************************************************************
 * ANBRNetworkAssistanceInvocationRecord - Public C interface to the ANBRNetworkAssistanceInvocationRecord object
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
#include "TypedLocation.h"
#include "UnidirectionalQoSSpecification.h"
#include "ApplicationFlowDescription.h"
#include "Snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_anbr_network_assistance_invocation_record_s data_collection_model_anbr_network_assistance_invocation_record_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create_copy(const data_collection_model_anbr_network_assistance_invocation_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create_move(data_collection_model_anbr_network_assistance_invocation_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_copy(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_anbr_network_assistance_invocation_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_anbr_network_assistance_invocation_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_anbr_network_assistance_invocation_record_free(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_anbr_network_assistance_invocation_record_toJSON(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_is_equal_to(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_anbr_network_assistance_invocation_record_t *other_anbr_network_assistance_invocation_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_timestamp(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_timestamp(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_timestamp_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_anbr_network_assistance_invocation_record_get_context_ids(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_context_ids_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_add_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_remove_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_clear_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_anbr_network_assistance_invocation_record_get_slice_info(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_slice_info(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_snssai_t* p_slice_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_slice_info_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_snssai_t* p_slice_info);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_data_network_name(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_data_network_name(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_data_network_name_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_typed_location_t* data_collection_model_anbr_network_assistance_invocation_record_get_location(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_location(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_typed_location_t* p_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_location_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_typed_location_t* p_location);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_session_id(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_session_id(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_session_id_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_policy_template_id(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_policy_template_id(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_policy_template_id_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_anbr_network_assistance_invocation_record_get_application_flow_descriptions(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const ogs_list_t* p_application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_application_flow_descriptions_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, ogs_list_t* p_application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_add_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_application_flow_description_t* application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_remove_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_application_flow_description_t* application_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_clear_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_anbr_network_assistance_invocation_record_get_requested_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_requested_qo_s(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_requested_qo_s_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_anbr_network_assistance_invocation_record_get_recommended_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_recommended_qo_s(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_recommended_qo_s_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/* lnode helper for generating ogs_list_t nodes's of type ANBRNetworkAssistanceInvocationRecord */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_anbr_network_assistance_invocation_record_make_lnode(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ANBR_NETWORK_ASSISTANCE_INVOCATION_RECORD_H_ */

