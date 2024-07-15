#ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_H_

/**********************************************************************************************************************************
 * MediaStreamingAccess - Public C interface to the MediaStreamingAccess object
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

#include "MediaStreamingAccess_requestMessage.h"
#include "MediaStreamingAccess_connectionMetrics.h"
#include "MediaStreamingAccess_responseMessage.h"
#include "EndpointAddress.h"
#include "CacheStatus.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_media_streaming_access_s data_collection_model_media_streaming_access_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_copy(const data_collection_model_media_streaming_access_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_move(data_collection_model_media_streaming_access_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_copy(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_free(data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_toJSON(const data_collection_model_media_streaming_access_t *media_streaming_access, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_media_stream_handler_endpoint_address(const data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_application_server_endpoint_address(const data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_endpoint_address_t* p_application_server_endpoint_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_endpoint_address_t* p_application_server_endpoint_address);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_request_message_t* data_collection_model_media_streaming_access_get_request_message(const data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_request_message_t* p_request_message);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_request_message_t* p_request_message);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cache_status_t* data_collection_model_media_streaming_access_get_cache_status(const data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_cache_status_t* p_cache_status);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_cache_status_t* p_cache_status);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_response_message_t* data_collection_model_media_streaming_access_get_response_message(const data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_response_message_t* p_response_message);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_response_message_t* p_response_message);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_get_processing_latency(const data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency(data_collection_model_media_streaming_access_t *media_streaming_access, const float p_processing_latency);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency_move(data_collection_model_media_streaming_access_t *media_streaming_access, float p_processing_latency);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_connection_metrics_t* data_collection_model_media_streaming_access_get_connection_metrics(const data_collection_model_media_streaming_access_t *media_streaming_access);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics);

/* lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccess */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_make_lnode(data_collection_model_media_streaming_access_t *media_streaming_access);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_H_ */

