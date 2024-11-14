#ifndef _DATA_COLLECTION_RTP_PAYLOAD_INFO_H_
#define _DATA_COLLECTION_RTP_PAYLOAD_INFO_H_

/**********************************************************************************************************************************
 * RtpPayloadInfo - Public C interface to the RtpPayloadInfo object
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

#include "RtpPayloadFormat.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP RtpPayloadInfo object reference
 */
typedef struct data_collection_model_rtp_payload_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_rtp_payload_info_t;



/** Create a new RtpPayloadInfo.
 * \public \memberof data_collection_model_rtp_payload_info_t
 * @return a new RtpPayloadInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create();

/** Create a new RtpPayloadInfo reference.
 * \public \memberof data_collection_model_rtp_payload_info_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The RtpPayloadInfo to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create_ref(const data_collection_model_rtp_payload_info_t *other);

/** Create a new copy of a RtpPayloadInfo object.
 * \public \memberof data_collection_model_rtp_payload_info_t
 * Creates a new copy of the given @a other object
 * @param other The RtpPayloadInfo to copy.
 * @return a new RtpPayloadInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create_copy(const data_collection_model_rtp_payload_info_t *other);

/** Create a new reference of a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The RtpPayloadInfo to create a new reference to.
 * @return a new RtpPayloadInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create_move(data_collection_model_rtp_payload_info_t *other);

/** Copy the value of another RtpPayloadInfo into this object
 * \public \memberof data_collection_model_rtp_payload_info_t
 * Copies the value of @a other {{classname} object into @a rtp_payload_info.
 * @param rtp_payload_info The RtpPayloadInfo object to copy @a other into.
 * @param other The RtpPayloadInfo to copy the value from.
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_copy(data_collection_model_rtp_payload_info_t *rtp_payload_info, const data_collection_model_rtp_payload_info_t *other);

/** Move the value of another RtpPayloadInfo into this object
 * \public \memberof data_collection_model_rtp_payload_info_t
 * Discards the current value of @a rtp_payload_info and moves the value of @a other
 * into @a rtp_payload_info. This will leave @a other as an empty reference.
 *
 * @param rtp_payload_info The RtpPayloadInfo object to move @a other into.
 * @param other The RtpPayloadInfo to move the value from.
 *
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_move(data_collection_model_rtp_payload_info_t *rtp_payload_info, data_collection_model_rtp_payload_info_t *other);

/** Delete a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 * Destroys the reference to the RtpPayloadInfo object and frees the value of RtpPayloadInfo if this is the last reference.
 *
 * @param rtp_payload_info The RtpPayloadInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_rtp_payload_info_free(data_collection_model_rtp_payload_info_t *rtp_payload_info);

/** Get a cJSON tree representation of a RtpPayloadInfo
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * Create a cJSON tree representation of the RtpPayloadInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param rtp_payload_info The RtpPayloadInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_rtp_payload_info_toJSON(const data_collection_model_rtp_payload_info_t *rtp_payload_info, bool as_request);

/** Parse a cJSON tree into a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * Attempts to interpret a cJSON tree as a RtpPayloadInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced RtpPayloadInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new RtpPayloadInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two RtpPayloadInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param rtp_payload_info The first RtpPayloadInfo object to compare.
 * @param other_rtp_payload_info The second RtpPayloadInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_is_equal_to(const data_collection_model_rtp_payload_info_t *rtp_payload_info, const data_collection_model_rtp_payload_info_t *other_rtp_payload_info);


/** Check if the rtpPayloadTypeList field of a RtpPayloadInfo object is set
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to examine.
 *
 * @return `true` if the optional rtpPayloadTypeList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_has_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *rtp_payload_info);


/** Get the value of the rtpPayloadTypeList field of a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to examine.
 *
 * @return the value current set for the rtpPayloadTypeList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_rtp_payload_info_get_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *rtp_payload_info);

/** Set the value of the rtpPayloadTypeList field in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to set the field in.
 * @param p_rtp_payload_type_list The value to copy into the RtpPayloadInfo object.
 *
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info, const ogs_list_t* p_rtp_payload_type_list);

/** Move a value to the rtpPayloadTypeList field in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to set the field in.
 * @param p_rtp_payload_type_list The value to move into the RtpPayloadInfo object.
 *
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_type_list_move(data_collection_model_rtp_payload_info_t *rtp_payload_info, ogs_list_t* p_rtp_payload_type_list);

/** Add a new item to the rtpPayloadTypeList array in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to add the array item to.
 * @param rtp_payload_type_list The value to add.
 *
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_add_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info, int32_t rtp_payload_type_list);

/** Remove an item from the rtpPayloadTypeList array in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to remove the array value from.
 * @param rtp_payload_type_list The value to remove.
 *
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_remove_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info, const int32_t rtp_payload_type_list);

/** Get an item from the rtpPayloadTypeList array in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_rtp_payload_info_get_entry_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *rtp_payload_info, size_t idx);

/** Remove all entries from the rtpPayloadTypeList array in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to empty rtpPayloadTypeList for.
 *
 * @return @a rtp_payload_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_clear_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *rtp_payload_info);

/** Check if the rtpPayloadFormat field of a RtpPayloadInfo object is set
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to examine.
 *
 * @return `true` if the optional rtpPayloadFormat field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_has_rtp_payload_format(const data_collection_model_rtp_payload_info_t *rtp_payload_info);


/** Get the value of the rtpPayloadFormat field of a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to examine.
 *
 * @return the value current set for the rtpPayloadFormat field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_payload_format_t* data_collection_model_rtp_payload_info_get_rtp_payload_format(const data_collection_model_rtp_payload_info_t *rtp_payload_info);

/** Set the value of the rtpPayloadFormat field in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to set the field in.
 * @param p_rtp_payload_format The value to copy into the RtpPayloadInfo object.
 *
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_format(data_collection_model_rtp_payload_info_t *rtp_payload_info, const data_collection_model_rtp_payload_format_t* p_rtp_payload_format);

/** Move a value to the rtpPayloadFormat field in a RtpPayloadInfo object
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * @param rtp_payload_info The RtpPayloadInfo object to set the field in.
 * @param p_rtp_payload_format The value to move into the RtpPayloadInfo object.
 *
 * @return @a rtp_payload_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_format_move(data_collection_model_rtp_payload_info_t *rtp_payload_info, data_collection_model_rtp_payload_format_t* p_rtp_payload_format);

/** lnode helper for generating ogs_list_t nodes's of type RtpPayloadInfo
 * \public \memberof data_collection_model_rtp_payload_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a rtp_payload_info object.
 * The @a rtp_payload_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param rtp_payload_info The RtpPayloadInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a rtp_payload_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_rtp_payload_info_make_lnode(data_collection_model_rtp_payload_info_t *rtp_payload_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RTP_PAYLOAD_INFO_H_ */

