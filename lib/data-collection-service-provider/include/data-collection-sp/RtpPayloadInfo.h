#ifndef _DATA_COLLECTION_RTP_PAYLOAD_INFO_H_
#define _DATA_COLLECTION_RTP_PAYLOAD_INFO_H_

/**********************************************************************************************************************************
 * RtpPayloadInfo - Public C interface to the RtpPayloadInfo object
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

#include "RtpPayloadFormat.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_rtp_payload_info_s data_collection_model_rtp_payload_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create_copy(const data_collection_model_rtp_payload_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create_move(data_collection_model_rtp_payload_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_copy(data_collection_model_rtp_payload_info_t *rtp_payload_info, const data_collection_model_rtp_payload_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_move(data_collection_model_rtp_payload_info_t *rtp_payload_info, data_collection_model_rtp_payload_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_rtp_payload_info_free(data_collection_model_rtp_payload_info_t *rtp_payload_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_rtp_payload_info_toJSON(const data_collection_model_rtp_payload_info_t *rtp_payload_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_is_equal_to(const data_collection_model_rtp_payload_info_t *rtp_payload_info, const data_collection_model_rtp_payload_info_t *other_rtp_payload_info);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_has_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *rtp_payload_info);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_rtp_payload_info_get_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *rtp_payload_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info, const ogs_list_t* p_rtp_payload_type_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_type_list_move(data_collection_model_rtp_payload_info_t *rtp_payload_info, ogs_list_t* p_rtp_payload_type_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_add_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info, int32_t rtp_payload_type_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_remove_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info, const int32_t rtp_payload_type_list);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_rtp_payload_info_get_entry_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *rtp_payload_info, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_clear_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_has_rtp_payload_format(const data_collection_model_rtp_payload_info_t *rtp_payload_info);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_payload_format_t* data_collection_model_rtp_payload_info_get_rtp_payload_format(const data_collection_model_rtp_payload_info_t *rtp_payload_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_format(data_collection_model_rtp_payload_info_t *rtp_payload_info, const data_collection_model_rtp_payload_format_t* p_rtp_payload_format);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_format_move(data_collection_model_rtp_payload_info_t *rtp_payload_info, data_collection_model_rtp_payload_format_t* p_rtp_payload_format);

/* lnode helper for generating ogs_list_t nodes's of type RtpPayloadInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_rtp_payload_info_make_lnode(data_collection_model_rtp_payload_info_t *rtp_payload_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RTP_PAYLOAD_INFO_H_ */

