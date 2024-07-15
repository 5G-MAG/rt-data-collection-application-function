#ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_SESSION_H_
#define _DATA_COLLECTION_NETWORK_ASSISTANCE_SESSION_H_

/**********************************************************************************************************************************
 * NetworkAssistanceSession - Public C interface to the NetworkAssistanceSession object
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

typedef struct data_collection_model_network_assistance_session_s data_collection_model_network_assistance_session_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create_copy(const data_collection_model_network_assistance_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create_move(data_collection_model_network_assistance_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_copy(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_network_assistance_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_network_assistance_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_session_free(data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_session_toJSON(const data_collection_model_network_assistance_session_t *network_assistance_session, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_na_session_id(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_na_session_id(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_na_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_na_session_id_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_na_session_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_provisioning_session_id(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_provisioning_session_id(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_provisioning_session_id_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_session_get_service_data_flow_descriptions(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session, const ogs_list_t* p_service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_service_data_flow_descriptions_move(data_collection_model_network_assistance_session_t *network_assistance_session, ogs_list_t* p_service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_add_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_application_flow_description_t* service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_remove_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_application_flow_description_t* service_data_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_clear_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_type_t* data_collection_model_network_assistance_session_get_media_type(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_media_type(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_media_type_t* p_media_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_media_type_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_media_type_t* p_media_type);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_policy_template_id(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_policy_template_id(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_policy_template_id_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_policy_template_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_qo_s_specification_t* data_collection_model_network_assistance_session_get_requested_qo_s(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_requested_qo_s(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_m5_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_requested_qo_s_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_m5_qo_s_specification_t* p_requested_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_qo_s_specification_t* data_collection_model_network_assistance_session_get_recommended_qo_s(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_recommended_qo_s(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_m5_qo_s_specification_t* p_recommended_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_recommended_qo_s_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_m5_qo_s_specification_t* p_recommended_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_notfication_url(const data_collection_model_network_assistance_session_t *network_assistance_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_notfication_url(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_notfication_url);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_notfication_url_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_notfication_url);

/* lnode helper for generating ogs_list_t nodes's of type NetworkAssistanceSession */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_session_make_lnode(data_collection_model_network_assistance_session_t *network_assistance_session);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_SESSION_H_ */

