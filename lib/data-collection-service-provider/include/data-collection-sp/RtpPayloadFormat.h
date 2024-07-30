#ifndef _DATA_COLLECTION_RTP_PAYLOAD_FORMAT_H_
#define _DATA_COLLECTION_RTP_PAYLOAD_FORMAT_H_

/**********************************************************************************************************************************
 * RtpPayloadFormat - Public C interface to the RtpPayloadFormat object
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

#include "RtpPayloadFormat_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_rtp_payload_format_s data_collection_model_rtp_payload_format_t;

typedef enum {
    DCM_RTP_PAYLOAD_FORMAT_NO_VAL,
    DCM_RTP_PAYLOAD_FORMAT_VAL_H264,
    DCM_RTP_PAYLOAD_FORMAT_VAL_H265,
    DCM_RTP_PAYLOAD_FORMAT_OTHER
} data_collection_model_rtp_payload_format_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_create_copy(const data_collection_model_rtp_payload_format_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_create_move(data_collection_model_rtp_payload_format_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_copy(data_collection_model_rtp_payload_format_t *rtp_payload_format, const data_collection_model_rtp_payload_format_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_move(data_collection_model_rtp_payload_format_t *rtp_payload_format, data_collection_model_rtp_payload_format_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_rtp_payload_format_free(data_collection_model_rtp_payload_format_t *rtp_payload_format);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_rtp_payload_format_toJSON(const data_collection_model_rtp_payload_format_t *rtp_payload_format, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_is_equal_to(const data_collection_model_rtp_payload_format_t *rtp_payload_format, const data_collection_model_rtp_payload_format_t *other_rtp_payload_format);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_is_not_set(const data_collection_model_rtp_payload_format_t *rtp_payload_format);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_is_non_standard(const data_collection_model_rtp_payload_format_t *rtp_payload_format);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_e data_collection_model_rtp_payload_format_get_enum(const data_collection_model_rtp_payload_format_t *rtp_payload_format);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_rtp_payload_format_get_string(const data_collection_model_rtp_payload_format_t *rtp_payload_format);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_set_enum(data_collection_model_rtp_payload_format_t *rtp_payload_format, data_collection_model_rtp_payload_format_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_set_string(data_collection_model_rtp_payload_format_t *rtp_payload_format, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type RtpPayloadFormat */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_rtp_payload_format_make_lnode(data_collection_model_rtp_payload_format_t *rtp_payload_format);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RTP_PAYLOAD_FORMAT_H_ */

