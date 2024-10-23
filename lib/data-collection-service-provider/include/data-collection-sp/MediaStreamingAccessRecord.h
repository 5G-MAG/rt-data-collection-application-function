#ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_RECORD_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_RECORD_H_

/**********************************************************************************************************************************
 * MediaStreamingAccessRecord - Public C interface to the MediaStreamingAccessRecord object
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
#include "TypedLocation.h"
#include "MediaStreamingAccess_connectionMetrics.h"
#include "MediaStreamingAccess_responseMessage.h"
#include "Snssai.h"
#include "EndpointAddress.h"
#include "CacheStatus.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MediaStreamingAccessRecord object reference
 */
typedef struct data_collection_model_media_streaming_access_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_media_streaming_access_record_t;



/** Create a new MediaStreamingAccessRecord
 * \public \memberof data_collection_model_media_streaming_access_record_t
 * @return a new MediaStreamingAccessRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_create();

/** Create a new copy of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 * Creates a new copy of the given @a other object
 * @param other The MediaStreamingAccessRecord to copy.
 * @return a new MediaStreamingAccessRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_create_copy(const data_collection_model_media_streaming_access_record_t *other);

/** Create a new reference of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MediaStreamingAccessRecord to create a new reference to.
 * @return a new MediaStreamingAccessRecord object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_create_move(data_collection_model_media_streaming_access_record_t *other);

/** Copy the value of another MediaStreamingAccessRecord into this object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 * Copies the value of @a other {{classname} object into @a media_streaming_access_record.
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to copy @a other into.
 * @param other The MediaStreamingAccessRecord to copy the value from.
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_copy(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_media_streaming_access_record_t *other);

/** Move the value of another MediaStreamingAccessRecord into this object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 * Discards the current value of @a media_streaming_access_record and moves the value of @a other
 * into @a media_streaming_access_record. This will leave @a other as an empty reference.
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to move @a other into.
 * @param other The MediaStreamingAccessRecord to move the value from.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_media_streaming_access_record_t *other);

/** Delete a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 * Destroys the reference to the MediaStreamingAccessRecord object and frees the value of MediaStreamingAccessRecord if this is the last reference.
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_record_free(data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Get a cJSON tree representation of a MediaStreamingAccessRecord
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * Create a cJSON tree representation of the MediaStreamingAccessRecord object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_record_toJSON(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record, bool as_request);

/** Parse a cJSON tree into a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * Attempts to interpret a cJSON tree as a MediaStreamingAccessRecord API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MediaStreamingAccessRecord object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MediaStreamingAccessRecord object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MediaStreamingAccessRecord objects to see if they are equivalent
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param media_streaming_access_record The first MediaStreamingAccessRecord object to compare.
 * @param other_media_streaming_access_record The second MediaStreamingAccessRecord object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_is_equal_to(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_media_streaming_access_record_t *other_media_streaming_access_record);



/** Get the value of the timestamp field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the timestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_record_get_timestamp(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the timestamp field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_timestamp The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_timestamp(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const char* p_timestamp);

/** Move a value to the timestamp field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_timestamp The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_timestamp_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, char* p_timestamp);


/** Get the value of the contextIds field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_media_streaming_access_record_get_context_ids(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the contextIds field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_context_ids The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_context_ids(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_context_ids The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_context_ids_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_add_context_ids(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, char* context_ids);

/** Remove an item from the contextIds array in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_remove_context_ids(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const char* context_ids);

/** Get an item from the contextIds array in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_record_get_entry_context_ids(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record, size_t idx);

/** Remove all entries from the contextIds array in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to empty contextIds for.
 *
 * @return @a media_streaming_access_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_clear_context_ids(data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Check if the sliceInfo field of a MediaStreamingAccessRecord object is set
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return `true` if the optional sliceInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_slice_info(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);


/** Get the value of the sliceInfo field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the sliceInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_media_streaming_access_record_get_slice_info(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the sliceInfo field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_slice_info The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_slice_info(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_snssai_t* p_slice_info);

/** Move a value to the sliceInfo field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_slice_info The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_slice_info_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_snssai_t* p_slice_info);

/** Check if the dataNetworkName field of a MediaStreamingAccessRecord object is set
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return `true` if the optional dataNetworkName field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_data_network_name(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);


/** Get the value of the dataNetworkName field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the dataNetworkName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_record_get_data_network_name(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the dataNetworkName field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_data_network_name The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_data_network_name(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const char* p_data_network_name);

/** Move a value to the dataNetworkName field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_data_network_name The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_data_network_name_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, char* p_data_network_name);

/** Check if the location field of a MediaStreamingAccessRecord object is set
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return `true` if the optional location field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_location(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);


/** Get the value of the location field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the location field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_typed_location_t* data_collection_model_media_streaming_access_record_get_location(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the location field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_location The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_location(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_typed_location_t* p_location);

/** Move a value to the location field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_location The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_location_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_typed_location_t* p_location);


/** Get the value of the sessionId field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the sessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_record_get_session_id(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the sessionId field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_session_id The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_session_id(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const char* p_session_id);

/** Move a value to the sessionId field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_session_id The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_session_id_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, char* p_session_id);


/** Get the value of the mediaStreamHandlerEndpointAddress field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the mediaStreamHandlerEndpointAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_record_get_media_stream_handler_endpoint_address(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the mediaStreamHandlerEndpointAddress field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_media_stream_handler_endpoint_address The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_media_stream_handler_endpoint_address(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address);

/** Move a value to the mediaStreamHandlerEndpointAddress field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_media_stream_handler_endpoint_address The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_media_stream_handler_endpoint_address_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address);


/** Get the value of the applicationServerEndpointAddress field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the applicationServerEndpointAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_record_get_application_server_endpoint_address(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the applicationServerEndpointAddress field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_application_server_endpoint_address The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_application_server_endpoint_address(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_endpoint_address_t* p_application_server_endpoint_address);

/** Move a value to the applicationServerEndpointAddress field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_application_server_endpoint_address The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_application_server_endpoint_address_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_endpoint_address_t* p_application_server_endpoint_address);


/** Get the value of the requestMessage field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the requestMessage field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_request_message_t* data_collection_model_media_streaming_access_record_get_request_message(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the requestMessage field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_request_message The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_request_message(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_media_streaming_access_request_message_t* p_request_message);

/** Move a value to the requestMessage field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_request_message The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_request_message_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_media_streaming_access_request_message_t* p_request_message);

/** Check if the cacheStatus field of a MediaStreamingAccessRecord object is set
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return `true` if the optional cacheStatus field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_cache_status(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);


/** Get the value of the cacheStatus field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the cacheStatus field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cache_status_t* data_collection_model_media_streaming_access_record_get_cache_status(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the cacheStatus field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_cache_status The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_cache_status(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_cache_status_t* p_cache_status);

/** Move a value to the cacheStatus field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_cache_status The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_cache_status_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_cache_status_t* p_cache_status);


/** Get the value of the responseMessage field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the responseMessage field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_response_message_t* data_collection_model_media_streaming_access_record_get_response_message(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the responseMessage field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_response_message The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_response_message(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_media_streaming_access_response_message_t* p_response_message);

/** Move a value to the responseMessage field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_response_message The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_response_message_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_media_streaming_access_response_message_t* p_response_message);


/** Get the value of the processingLatency field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the processingLatency field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_record_get_processing_latency(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the processingLatency field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_processing_latency The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_processing_latency(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const float p_processing_latency);

/** Move a value to the processingLatency field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_processing_latency The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_processing_latency_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, float p_processing_latency);

/** Check if the connectionMetrics field of a MediaStreamingAccessRecord object is set
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return `true` if the optional connectionMetrics field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_connection_metrics(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);


/** Get the value of the connectionMetrics field of a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to examine.
 *
 * @return the value current set for the connectionMetrics field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_connection_metrics_t* data_collection_model_media_streaming_access_record_get_connection_metrics(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/** Set the value of the connectionMetrics field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_connection_metrics The value to copy into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_connection_metrics(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics);

/** Move a value to the connectionMetrics field in a MediaStreamingAccessRecord object
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to set the field in.
 * @param p_connection_metrics The value to move into the MediaStreamingAccessRecord object.
 *
 * @return @a media_streaming_access_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_connection_metrics_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics);

/** lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccessRecord
 * \public \memberof data_collection_model_media_streaming_access_record_t
 *
 * Creates a new data_collection_lnode_t object containing the @a media_streaming_access_record object.
 * The @a media_streaming_access_record will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param media_streaming_access_record The MediaStreamingAccessRecord object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a media_streaming_access_record
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_record_make_lnode(data_collection_model_media_streaming_access_record_t *media_streaming_access_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_RECORD_H_ */

