#ifndef _DATA_COLLECTION_MEDIA_STREAMING_SESSION_IDENTIFICATION_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_SESSION_IDENTIFICATION_H_

/**********************************************************************************************************************************
 * MediaStreamingSessionIdentification - Public C interface to the MediaStreamingSessionIdentification object
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

typedef struct data_collection_model_media_streaming_session_identification_s data_collection_model_media_streaming_session_identification_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_copy(const data_collection_model_media_streaming_session_identification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_move(data_collection_model_media_streaming_session_identification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_copy(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const data_collection_model_media_streaming_session_identification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_move(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, data_collection_model_media_streaming_session_identification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_session_identification_free(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_session_identification_toJSON(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_session_identification_is_equal_to(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const data_collection_model_media_streaming_session_identification_t *other_media_streaming_session_identification);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_session_identification_get_session_id(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id_move(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, char* p_session_id);

/* lnode helper for generating ogs_list_t nodes's of type MediaStreamingSessionIdentification */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_session_identification_make_lnode(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_SESSION_IDENTIFICATION_H_ */

