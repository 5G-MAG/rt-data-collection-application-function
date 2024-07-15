#ifndef _DATA_COLLECTION_PROTOCOL_DESCRIPTION_H_
#define _DATA_COLLECTION_PROTOCOL_DESCRIPTION_H_

/**********************************************************************************************************************************
 * ProtocolDescription - Public C interface to the ProtocolDescription object
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

#include "RtpPayloadInfo.h"
#include "MediaTransportProto.h"
#include "RtpHeaderExtInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_protocol_description_s data_collection_model_protocol_description_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_copy(const data_collection_model_protocol_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_move(data_collection_model_protocol_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_copy(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_protocol_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_protocol_description_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_protocol_description_free(data_collection_model_protocol_description_t *protocol_description);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_protocol_description_toJSON(const data_collection_model_protocol_description_t *protocol_description, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_transport_proto_t* data_collection_model_protocol_description_get_transport_proto(const data_collection_model_protocol_description_t *protocol_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_media_transport_proto_t* p_transport_proto);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_media_transport_proto_t* p_transport_proto);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_header_ext_info_t* data_collection_model_protocol_description_get_rtp_header_ext_info(const data_collection_model_protocol_description_t *protocol_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_protocol_description_get_rtp_payload_info_list(const data_collection_model_protocol_description_t *protocol_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description, const ogs_list_t* p_rtp_payload_info_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list_move(data_collection_model_protocol_description_t *protocol_description, ogs_list_t* p_rtp_payload_info_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_add_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description, data_collection_model_rtp_payload_info_t* rtp_payload_info_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_remove_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_rtp_payload_info_t* rtp_payload_info_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_clear_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description);

/* lnode helper for generating ogs_list_t nodes's of type ProtocolDescription */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_protocol_description_make_lnode(data_collection_model_protocol_description_t *protocol_description);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PROTOCOL_DESCRIPTION_H_ */

