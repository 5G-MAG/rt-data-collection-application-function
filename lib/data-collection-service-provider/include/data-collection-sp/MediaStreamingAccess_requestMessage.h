#ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_REQUEST_MESSAGE_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_REQUEST_MESSAGE_H_

/**********************************************************************************************************************************
 * MediaStreamingAccess_requestMessage - Public C interface to the MediaStreamingAccess_requestMessage object
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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MediaStreamingAccess_requestMessage object reference
 */
typedef struct data_collection_model_media_streaming_access_request_message_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_media_streaming_access_request_message_t;



/** Create a new MediaStreamingAccess_requestMessage
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 * @return a new MediaStreamingAccess_requestMessage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_create();

/** Create a new copy of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 * Creates a new copy of the given @a other object
 * @param other The MediaStreamingAccess_requestMessage to copy.
 * @return a new MediaStreamingAccess_requestMessage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_create_copy(const data_collection_model_media_streaming_access_request_message_t *other);

/** Create a new reference of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MediaStreamingAccess_requestMessage to create a new reference to.
 * @return a new MediaStreamingAccess_requestMessage object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_create_move(data_collection_model_media_streaming_access_request_message_t *other);

/** Copy the value of another MediaStreamingAccess_requestMessage into this object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 * Copies the value of @a other {{classname} object into @a media_streaming_access_request_message.
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to copy @a other into.
 * @param other The MediaStreamingAccess_requestMessage to copy the value from.
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_copy(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const data_collection_model_media_streaming_access_request_message_t *other);

/** Move the value of another MediaStreamingAccess_requestMessage into this object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 * Discards the current value of @a media_streaming_access_request_message and moves the value of @a other
 * into @a media_streaming_access_request_message. This will leave @a other as an empty reference.
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to move @a other into.
 * @param other The MediaStreamingAccess_requestMessage to move the value from.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, data_collection_model_media_streaming_access_request_message_t *other);

/** Delete a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 * Destroys the reference to the MediaStreamingAccess_requestMessage object and frees the value of MediaStreamingAccess_requestMessage if this is the last reference.
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_request_message_free(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Get a cJSON tree representation of a MediaStreamingAccess_requestMessage
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * Create a cJSON tree representation of the MediaStreamingAccess_requestMessage object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_request_message_toJSON(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, bool as_request);

/** Parse a cJSON tree into a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * Attempts to interpret a cJSON tree as a MediaStreamingAccess_requestMessage API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MediaStreamingAccess_requestMessage object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MediaStreamingAccess_requestMessage object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MediaStreamingAccess_requestMessage objects to see if they are equivalent
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param media_streaming_access_request_message The first MediaStreamingAccess_requestMessage object to compare.
 * @param other_media_streaming_access_request_message The second MediaStreamingAccess_requestMessage object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_request_message_is_equal_to(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const data_collection_model_media_streaming_access_request_message_t *other_media_streaming_access_request_message);



/** Get the value of the method field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the method field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_method(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the method field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_method The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_method(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_method);

/** Move a value to the method field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_method The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_method_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_method);


/** Get the value of the url field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the url field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_url(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the url field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_url The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_url(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_url);

/** Move a value to the url field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_url The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_url_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_url);


/** Get the value of the protocolVersion field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the protocolVersion field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_protocol_version(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the protocolVersion field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_protocol_version The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_protocol_version(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_protocol_version);

/** Move a value to the protocolVersion field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_protocol_version The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_protocol_version_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_protocol_version);

/** Check if the range field of a MediaStreamingAccess_requestMessage object is set
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return `true` if the optional range field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_request_message_has_range(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);


/** Get the value of the range field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the range field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_range(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the range field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_range The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_range(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_range);

/** Move a value to the range field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_range The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_range_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_range);


/** Get the value of the size field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the size field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_request_message_get_size(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the size field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_size The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_size(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const int32_t p_size);

/** Move a value to the size field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_size The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_size_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, int32_t p_size);


/** Get the value of the bodySize field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the bodySize field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_request_message_get_body_size(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the bodySize field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_body_size The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_body_size(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const int32_t p_body_size);

/** Move a value to the bodySize field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_body_size The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_body_size_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, int32_t p_body_size);

/** Check if the contentType field of a MediaStreamingAccess_requestMessage object is set
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return `true` if the optional contentType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_request_message_has_content_type(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);


/** Get the value of the contentType field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the contentType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_content_type(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the contentType field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_content_type The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_content_type(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_content_type);

/** Move a value to the contentType field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_content_type The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_content_type_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_content_type);

/** Check if the userAgent field of a MediaStreamingAccess_requestMessage object is set
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return `true` if the optional userAgent field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_request_message_has_user_agent(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);


/** Get the value of the userAgent field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the userAgent field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_user_agent(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the userAgent field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_user_agent The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_agent(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_user_agent);

/** Move a value to the userAgent field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_user_agent The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_agent_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_user_agent);

/** Check if the userIdentity field of a MediaStreamingAccess_requestMessage object is set
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return `true` if the optional userIdentity field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_request_message_has_user_identity(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);


/** Get the value of the userIdentity field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the userIdentity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_user_identity(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the userIdentity field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_user_identity The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_identity(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_user_identity);

/** Move a value to the userIdentity field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_user_identity The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_identity_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_user_identity);

/** Check if the referer field of a MediaStreamingAccess_requestMessage object is set
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return `true` if the optional referer field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_request_message_has_referer(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);


/** Get the value of the referer field of a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to examine.
 *
 * @return the value current set for the referer field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_request_message_get_referer(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/** Set the value of the referer field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_referer The value to copy into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_referer(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const char* p_referer);

/** Move a value to the referer field in a MediaStreamingAccess_requestMessage object
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to set the field in.
 * @param p_referer The value to move into the MediaStreamingAccess_requestMessage object.
 *
 * @return @a media_streaming_access_request_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_referer_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, char* p_referer);

/** lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccess_requestMessage
 * \public \memberof data_collection_model_media_streaming_access_request_message_t
 *
 * Creates a new data_collection_lnode_t object containing the @a media_streaming_access_request_message object.
 * The @a media_streaming_access_request_message will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param media_streaming_access_request_message The MediaStreamingAccess_requestMessage object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a media_streaming_access_request_message
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_request_message_make_lnode(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_REQUEST_MESSAGE_H_ */

