#ifndef _DATA_COLLECTION_APPLICATION_FLOW_DESCRIPTION_H_
#define _DATA_COLLECTION_APPLICATION_FLOW_DESCRIPTION_H_

/**********************************************************************************************************************************
 * ApplicationFlowDescription - Public C interface to the ApplicationFlowDescription object
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

#include "IpPacketFilterSet.h"
#include "SdfMethod.h"
#include "ProtocolDescription.h"
#include "MediaType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_application_flow_description_s data_collection_model_application_flow_description_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create_copy(const data_collection_model_application_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create_move(data_collection_model_application_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_copy(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_application_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_application_flow_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_application_flow_description_free(data_collection_model_application_flow_description_t *application_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_application_flow_description_toJSON(const data_collection_model_application_flow_description_t *application_flow_description, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_sdf_method_t* data_collection_model_application_flow_description_get_filter_method(const data_collection_model_application_flow_description_t *application_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_filter_method(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_sdf_method_t* p_filter_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_filter_method_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_sdf_method_t* p_filter_method);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_packet_filter_set_t* data_collection_model_application_flow_description_get_packet_filter(const data_collection_model_application_flow_description_t *application_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_packet_filter(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_ip_packet_filter_set_t* p_packet_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_packet_filter_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_ip_packet_filter_set_t* p_packet_filter);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_application_flow_description_get_domain_name(const data_collection_model_application_flow_description_t *application_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_domain_name(data_collection_model_application_flow_description_t *application_flow_description, const char* p_domain_name);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_domain_name_move(data_collection_model_application_flow_description_t *application_flow_description, char* p_domain_name);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_type_t* data_collection_model_application_flow_description_get_media_type(const data_collection_model_application_flow_description_t *application_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_type(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_media_type_t* p_media_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_type_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_media_type_t* p_media_type);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_protocol_description_t* data_collection_model_application_flow_description_get_media_transport_parameters(const data_collection_model_application_flow_description_t *application_flow_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_transport_parameters(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_protocol_description_t* p_media_transport_parameters);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_transport_parameters_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_protocol_description_t* p_media_transport_parameters);

/* lnode helper for generating ogs_list_t nodes's of type ApplicationFlowDescription */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_application_flow_description_make_lnode(data_collection_model_application_flow_description_t *application_flow_description);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_APPLICATION_FLOW_DESCRIPTION_H_ */

