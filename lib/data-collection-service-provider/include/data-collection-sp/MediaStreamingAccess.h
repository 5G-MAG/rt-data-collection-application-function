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

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MediaStreamingAccess object reference
 */
typedef struct data_collection_model_media_streaming_access_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_media_streaming_access_t;



/** Create a new MediaStreamingAccess.
 * \public \memberof data_collection_model_media_streaming_access_t
 * @return a new MediaStreamingAccess object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create();

/** Create a new MediaStreamingAccess reference.
 * \public \memberof data_collection_model_media_streaming_access_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The MediaStreamingAccess to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_ref(const data_collection_model_media_streaming_access_t *other);

/** Create a new copy of a MediaStreamingAccess object.
 * \public \memberof data_collection_model_media_streaming_access_t
 * Creates a new copy of the given @a other object
 * @param other The MediaStreamingAccess to copy.
 * @return a new MediaStreamingAccess object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_copy(const data_collection_model_media_streaming_access_t *other);

/** Create a new reference of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MediaStreamingAccess to create a new reference to.
 * @return a new MediaStreamingAccess object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_move(data_collection_model_media_streaming_access_t *other);

/** Copy the value of another MediaStreamingAccess into this object
 * \public \memberof data_collection_model_media_streaming_access_t
 * Copies the value of @a other {{classname} object into @a media_streaming_access.
 * @param media_streaming_access The MediaStreamingAccess object to copy @a other into.
 * @param other The MediaStreamingAccess to copy the value from.
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_copy(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_t *other);

/** Move the value of another MediaStreamingAccess into this object
 * \public \memberof data_collection_model_media_streaming_access_t
 * Discards the current value of @a media_streaming_access and moves the value of @a other
 * into @a media_streaming_access. This will leave @a other as an empty reference.
 *
 * @param media_streaming_access The MediaStreamingAccess object to move @a other into.
 * @param other The MediaStreamingAccess to move the value from.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_t *other);

/** Delete a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 * Destroys the reference to the MediaStreamingAccess object and frees the value of MediaStreamingAccess if this is the last reference.
 *
 * @param media_streaming_access The MediaStreamingAccess to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_free(data_collection_model_media_streaming_access_t *media_streaming_access);

/** Get a cJSON tree representation of a MediaStreamingAccess
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * Create a cJSON tree representation of the MediaStreamingAccess object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param media_streaming_access The MediaStreamingAccess to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_toJSON(const data_collection_model_media_streaming_access_t *media_streaming_access, bool as_request);

/** Parse a cJSON tree into a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * Attempts to interpret a cJSON tree as a MediaStreamingAccess API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MediaStreamingAccess object containing the value represented by the cJSON tree. On failure will return
 * `NULL` and will set @a error_reason, @a error_class and @a error_parameter output parameters to indicate the reason for the
 * failure. The @a error_reason, @a error_class and @a error_parameter strings must be freed using ogs_free().
 *
 * @param json The cJSON tree object to interpret.
 * @param as_request `true` to interpret the @a json as an API request or `false` for interpretation as an API response.
 * @param[out] error_reason On failure will be set to a new nul terminated string indicating the reason for the failure.
 * @param[out] error_class On failure will be set to the class name of the object where the failure happened if available or `NULL`.
 * @param[out] error_parameter On failure will be set to the JSON path of the field where the failure happened if available or
                               `NULL`.
 *
 * @return a new MediaStreamingAccess object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MediaStreamingAccess objects to see if they are equivalent
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param media_streaming_access The first MediaStreamingAccess object to compare.
 * @param other_media_streaming_access The second MediaStreamingAccess object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_is_equal_to(const data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_t *other_media_streaming_access);



/** Get the value of the mediaStreamHandlerEndpointAddress field of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return the value current set for the mediaStreamHandlerEndpointAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_media_stream_handler_endpoint_address(const data_collection_model_media_streaming_access_t *media_streaming_access);

/** Set the value of the mediaStreamHandlerEndpointAddress field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_media_stream_handler_endpoint_address The value to copy into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address);

/** Move a value to the mediaStreamHandlerEndpointAddress field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_media_stream_handler_endpoint_address The value to move into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address);


/** Get the value of the applicationServerEndpointAddress field of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return the value current set for the applicationServerEndpointAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_application_server_endpoint_address(const data_collection_model_media_streaming_access_t *media_streaming_access);

/** Set the value of the applicationServerEndpointAddress field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_application_server_endpoint_address The value to copy into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_endpoint_address_t* p_application_server_endpoint_address);

/** Move a value to the applicationServerEndpointAddress field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_application_server_endpoint_address The value to move into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_endpoint_address_t* p_application_server_endpoint_address);


/** Get the value of the requestMessage field of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return the value current set for the requestMessage field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_request_message_t* data_collection_model_media_streaming_access_get_request_message(const data_collection_model_media_streaming_access_t *media_streaming_access);

/** Set the value of the requestMessage field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_request_message The value to copy into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_request_message_t* p_request_message);

/** Move a value to the requestMessage field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_request_message The value to move into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_request_message_t* p_request_message);

/** Check if the cacheStatus field of a MediaStreamingAccess object is set
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return `true` if the optional cacheStatus field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_has_cache_status(const data_collection_model_media_streaming_access_t *media_streaming_access);


/** Get the value of the cacheStatus field of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return the value current set for the cacheStatus field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cache_status_t* data_collection_model_media_streaming_access_get_cache_status(const data_collection_model_media_streaming_access_t *media_streaming_access);

/** Set the value of the cacheStatus field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_cache_status The value to copy into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_cache_status_t* p_cache_status);

/** Move a value to the cacheStatus field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_cache_status The value to move into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_cache_status_t* p_cache_status);


/** Get the value of the responseMessage field of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return the value current set for the responseMessage field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_response_message_t* data_collection_model_media_streaming_access_get_response_message(const data_collection_model_media_streaming_access_t *media_streaming_access);

/** Set the value of the responseMessage field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_response_message The value to copy into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_response_message_t* p_response_message);

/** Move a value to the responseMessage field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_response_message The value to move into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_response_message_t* p_response_message);


/** Get the value of the processingLatency field of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return the value current set for the processingLatency field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_get_processing_latency(const data_collection_model_media_streaming_access_t *media_streaming_access);

/** Set the value of the processingLatency field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_processing_latency The value to copy into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency(data_collection_model_media_streaming_access_t *media_streaming_access, const float p_processing_latency);

/** Move a value to the processingLatency field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_processing_latency The value to move into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency_move(data_collection_model_media_streaming_access_t *media_streaming_access, float p_processing_latency);

/** Check if the connectionMetrics field of a MediaStreamingAccess object is set
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return `true` if the optional connectionMetrics field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_has_connection_metrics(const data_collection_model_media_streaming_access_t *media_streaming_access);


/** Get the value of the connectionMetrics field of a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to examine.
 *
 * @return the value current set for the connectionMetrics field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_connection_metrics_t* data_collection_model_media_streaming_access_get_connection_metrics(const data_collection_model_media_streaming_access_t *media_streaming_access);

/** Set the value of the connectionMetrics field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_connection_metrics The value to copy into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics);

/** Move a value to the connectionMetrics field in a MediaStreamingAccess object
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * @param media_streaming_access The MediaStreamingAccess object to set the field in.
 * @param p_connection_metrics The value to move into the MediaStreamingAccess object.
 *
 * @return @a media_streaming_access.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics);

/** lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccess
 * \public \memberof data_collection_model_media_streaming_access_t
 *
 * Creates a new data_collection_lnode_t object containing the @a media_streaming_access object.
 * The @a media_streaming_access will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param media_streaming_access The MediaStreamingAccess object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a media_streaming_access
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_make_lnode(data_collection_model_media_streaming_access_t *media_streaming_access);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_H_ */

