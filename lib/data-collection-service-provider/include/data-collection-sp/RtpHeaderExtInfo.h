#ifndef _DATA_COLLECTION_RTP_HEADER_EXT_INFO_H_
#define _DATA_COLLECTION_RTP_HEADER_EXT_INFO_H_

/**********************************************************************************************************************************
 * RtpHeaderExtInfo - Public C interface to the RtpHeaderExtInfo object
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

#include "RtpHeaderExtType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_rtp_header_ext_info_s data_collection_model_rtp_header_ext_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_copy(const data_collection_model_rtp_header_ext_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_move(data_collection_model_rtp_header_ext_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_copy(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, data_collection_model_rtp_header_ext_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_rtp_header_ext_info_free(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_rtp_header_ext_info_toJSON(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_is_equal_to(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_info_t *other_rtp_header_ext_info);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_header_ext_type_t* data_collection_model_rtp_header_ext_info_get_rtp_header_ext_type(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_rtp_header_ext_info_get_rtp_header_ext_id(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const int32_t p_rtp_header_ext_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, int32_t p_rtp_header_ext_id);

DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_rtp_header_ext_info_is_long_format(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const bool p_long_format);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool p_long_format);

DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_rtp_header_ext_info_is_pdu_set_size_active(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const bool p_pdu_set_size_active);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool p_pdu_set_size_active);

/* lnode helper for generating ogs_list_t nodes's of type RtpHeaderExtInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_rtp_header_ext_info_make_lnode(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RTP_HEADER_EXT_INFO_H_ */

