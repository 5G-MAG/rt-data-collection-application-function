#ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_RESPONSE_MESSAGE_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_RESPONSE_MESSAGE_H_

/**********************************************************************************************************************************
 * MediaStreamingAccess_responseMessage - Public C interface to the MediaStreamingAccess_responseMessage object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_media_streaming_access_response_message_s data_collection_model_media_streaming_access_response_message_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_copy(const data_collection_model_media_streaming_access_response_message_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_move(data_collection_model_media_streaming_access_response_message_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_copy(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const data_collection_model_media_streaming_access_response_message_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, data_collection_model_media_streaming_access_response_message_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_response_message_free(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_response_message_toJSON(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_response_message_is_equal_to(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const data_collection_model_media_streaming_access_response_message_t *other_media_streaming_access_response_message);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_response_code(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const int32_t p_response_code);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, int32_t p_response_code);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_size(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const int32_t p_size);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, int32_t p_size);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_body_size(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const int32_t p_body_size);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, int32_t p_body_size);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_response_message_get_content_type(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const char* p_content_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, char* p_content_type);

/* lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccess_responseMessage */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_response_message_make_lnode(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_RESPONSE_MESSAGE_H_ */

