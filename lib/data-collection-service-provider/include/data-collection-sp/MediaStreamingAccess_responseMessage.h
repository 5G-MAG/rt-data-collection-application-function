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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MediaStreamingAccess_responseMessage object reference
 */
typedef struct data_collection_model_media_streaming_access_response_message_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_media_streaming_access_response_message_t;



/** Create a new MediaStreamingAccess_responseMessage
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 * @return a new MediaStreamingAccess_responseMessage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create();

/** Create a new copy of a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 * Creates a new copy of the given @a other object
 * @param other The MediaStreamingAccess_responseMessage to copy.
 * @return a new MediaStreamingAccess_responseMessage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_copy(const data_collection_model_media_streaming_access_response_message_t *other);

/** Create a new reference of a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MediaStreamingAccess_responseMessage to create a new reference to.
 * @return a new MediaStreamingAccess_responseMessage object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_move(data_collection_model_media_streaming_access_response_message_t *other);

/** Copy the value of another MediaStreamingAccess_responseMessage into this object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 * Copies the value of @a other {{classname} object into @a media_streaming_access_response_message.
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to copy @a other into.
 * @param other The MediaStreamingAccess_responseMessage to copy the value from.
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_copy(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const data_collection_model_media_streaming_access_response_message_t *other);

/** Move the value of another MediaStreamingAccess_responseMessage into this object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 * Discards the current value of @a media_streaming_access_response_message and moves the value of @a other
 * into @a media_streaming_access_response_message. This will leave @a other as an empty reference.
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to move @a other into.
 * @param other The MediaStreamingAccess_responseMessage to move the value from.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, data_collection_model_media_streaming_access_response_message_t *other);

/** Delete a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 * Destroys the reference to the MediaStreamingAccess_responseMessage object and frees the value of MediaStreamingAccess_responseMessage if this is the last reference.
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_response_message_free(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

/** Get a cJSON tree representation of a MediaStreamingAccess_responseMessage
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * Create a cJSON tree representation of the MediaStreamingAccess_responseMessage object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_response_message_toJSON(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, bool as_request);

/** Parse a cJSON tree into a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * Attempts to interpret a cJSON tree as a MediaStreamingAccess_responseMessage API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MediaStreamingAccess_responseMessage object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MediaStreamingAccess_responseMessage object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MediaStreamingAccess_responseMessage objects to see if they are equivalent
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param media_streaming_access_response_message The first MediaStreamingAccess_responseMessage object to compare.
 * @param other_media_streaming_access_response_message The second MediaStreamingAccess_responseMessage object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_response_message_is_equal_to(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const data_collection_model_media_streaming_access_response_message_t *other_media_streaming_access_response_message);



/** Get the value of the responseCode field of a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to examine.
 *
 * @return the value current set for the responseCode field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_response_code(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

/** Set the value of the responseCode field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_response_code The value to copy into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const int32_t p_response_code);

/** Move a value to the responseCode field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_response_code The value to move into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, int32_t p_response_code);


/** Get the value of the size field of a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to examine.
 *
 * @return the value current set for the size field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_size(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

/** Set the value of the size field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_size The value to copy into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const int32_t p_size);

/** Move a value to the size field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_size The value to move into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, int32_t p_size);


/** Get the value of the bodySize field of a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to examine.
 *
 * @return the value current set for the bodySize field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_body_size(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

/** Set the value of the bodySize field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_body_size The value to copy into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const int32_t p_body_size);

/** Move a value to the bodySize field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_body_size The value to move into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, int32_t p_body_size);

/** Check if the contentType field of a MediaStreamingAccess_responseMessage object is set
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to examine.
 *
 * @return `true` if the optional contentType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_response_message_has_content_type(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);


/** Get the value of the contentType field of a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to examine.
 *
 * @return the value current set for the contentType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_response_message_get_content_type(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

/** Set the value of the contentType field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_content_type The value to copy into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const char* p_content_type);

/** Move a value to the contentType field in a MediaStreamingAccess_responseMessage object
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to set the field in.
 * @param p_content_type The value to move into the MediaStreamingAccess_responseMessage object.
 *
 * @return @a media_streaming_access_response_message.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, char* p_content_type);

/** lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccess_responseMessage
 * \public \memberof data_collection_model_media_streaming_access_response_message_t
 *
 * Creates a new data_collection_lnode_t object containing the @a media_streaming_access_response_message object.
 * The @a media_streaming_access_response_message will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param media_streaming_access_response_message The MediaStreamingAccess_responseMessage object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a media_streaming_access_response_message
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_response_message_make_lnode(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_RESPONSE_MESSAGE_H_ */

