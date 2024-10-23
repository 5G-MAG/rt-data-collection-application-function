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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MediaStreamingSessionIdentification object reference
 */
typedef struct data_collection_model_media_streaming_session_identification_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_media_streaming_session_identification_t;



/** Create a new MediaStreamingSessionIdentification
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 * @return a new MediaStreamingSessionIdentification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create();

/** Create a new copy of a MediaStreamingSessionIdentification object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 * Creates a new copy of the given @a other object
 * @param other The MediaStreamingSessionIdentification to copy.
 * @return a new MediaStreamingSessionIdentification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_copy(const data_collection_model_media_streaming_session_identification_t *other);

/** Create a new reference of a MediaStreamingSessionIdentification object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MediaStreamingSessionIdentification to create a new reference to.
 * @return a new MediaStreamingSessionIdentification object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_move(data_collection_model_media_streaming_session_identification_t *other);

/** Copy the value of another MediaStreamingSessionIdentification into this object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 * Copies the value of @a other {{classname} object into @a media_streaming_session_identification.
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification object to copy @a other into.
 * @param other The MediaStreamingSessionIdentification to copy the value from.
 * @return @a media_streaming_session_identification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_copy(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const data_collection_model_media_streaming_session_identification_t *other);

/** Move the value of another MediaStreamingSessionIdentification into this object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 * Discards the current value of @a media_streaming_session_identification and moves the value of @a other
 * into @a media_streaming_session_identification. This will leave @a other as an empty reference.
 *
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification object to move @a other into.
 * @param other The MediaStreamingSessionIdentification to move the value from.
 *
 * @return @a media_streaming_session_identification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_move(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, data_collection_model_media_streaming_session_identification_t *other);

/** Delete a MediaStreamingSessionIdentification object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 * Destroys the reference to the MediaStreamingSessionIdentification object and frees the value of MediaStreamingSessionIdentification if this is the last reference.
 *
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_session_identification_free(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification);

/** Get a cJSON tree representation of a MediaStreamingSessionIdentification
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 *
 * Create a cJSON tree representation of the MediaStreamingSessionIdentification object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_session_identification_toJSON(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, bool as_request);

/** Parse a cJSON tree into a MediaStreamingSessionIdentification object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 *
 * Attempts to interpret a cJSON tree as a MediaStreamingSessionIdentification API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MediaStreamingSessionIdentification object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MediaStreamingSessionIdentification object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MediaStreamingSessionIdentification objects to see if they are equivalent
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param media_streaming_session_identification The first MediaStreamingSessionIdentification object to compare.
 * @param other_media_streaming_session_identification The second MediaStreamingSessionIdentification object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_session_identification_is_equal_to(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const data_collection_model_media_streaming_session_identification_t *other_media_streaming_session_identification);



/** Get the value of the sessionId field of a MediaStreamingSessionIdentification object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 *
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification object to examine.
 *
 * @return the value current set for the sessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_session_identification_get_session_id(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification);

/** Set the value of the sessionId field in a MediaStreamingSessionIdentification object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 *
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification object to set the field in.
 * @param p_session_id The value to copy into the MediaStreamingSessionIdentification object.
 *
 * @return @a media_streaming_session_identification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const char* p_session_id);

/** Move a value to the sessionId field in a MediaStreamingSessionIdentification object
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 *
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification object to set the field in.
 * @param p_session_id The value to move into the MediaStreamingSessionIdentification object.
 *
 * @return @a media_streaming_session_identification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id_move(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, char* p_session_id);

/** lnode helper for generating ogs_list_t nodes's of type MediaStreamingSessionIdentification
 * \public \memberof data_collection_model_media_streaming_session_identification_t
 *
 * Creates a new data_collection_lnode_t object containing the @a media_streaming_session_identification object.
 * The @a media_streaming_session_identification will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param media_streaming_session_identification The MediaStreamingSessionIdentification object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a media_streaming_session_identification
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_session_identification_make_lnode(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_SESSION_IDENTIFICATION_H_ */

