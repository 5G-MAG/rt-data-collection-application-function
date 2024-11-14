#ifndef _DATA_COLLECTION_RTP_HEADER_EXT_INFO_H_
#define _DATA_COLLECTION_RTP_HEADER_EXT_INFO_H_

/**********************************************************************************************************************************
 * RtpHeaderExtInfo - Public C interface to the RtpHeaderExtInfo object
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

#include "RtpHeaderExtType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP RtpHeaderExtInfo object reference
 */
typedef struct data_collection_model_rtp_header_ext_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_rtp_header_ext_info_t;



/** Create a new RtpHeaderExtInfo.
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 * @return a new RtpHeaderExtInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create();

/** Create a new RtpHeaderExtInfo reference.
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The RtpHeaderExtInfo to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_ref(const data_collection_model_rtp_header_ext_info_t *other);

/** Create a new copy of a RtpHeaderExtInfo object.
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 * Creates a new copy of the given @a other object
 * @param other The RtpHeaderExtInfo to copy.
 * @return a new RtpHeaderExtInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_copy(const data_collection_model_rtp_header_ext_info_t *other);

/** Create a new reference of a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The RtpHeaderExtInfo to create a new reference to.
 * @return a new RtpHeaderExtInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_move(data_collection_model_rtp_header_ext_info_t *other);

/** Copy the value of another RtpHeaderExtInfo into this object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 * Copies the value of @a other {{classname} object into @a rtp_header_ext_info.
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to copy @a other into.
 * @param other The RtpHeaderExtInfo to copy the value from.
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_copy(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_info_t *other);

/** Move the value of another RtpHeaderExtInfo into this object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 * Discards the current value of @a rtp_header_ext_info and moves the value of @a other
 * into @a rtp_header_ext_info. This will leave @a other as an empty reference.
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to move @a other into.
 * @param other The RtpHeaderExtInfo to move the value from.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, data_collection_model_rtp_header_ext_info_t *other);

/** Delete a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 * Destroys the reference to the RtpHeaderExtInfo object and frees the value of RtpHeaderExtInfo if this is the last reference.
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_rtp_header_ext_info_free(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

/** Get a cJSON tree representation of a RtpHeaderExtInfo
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * Create a cJSON tree representation of the RtpHeaderExtInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_rtp_header_ext_info_toJSON(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool as_request);

/** Parse a cJSON tree into a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * Attempts to interpret a cJSON tree as a RtpHeaderExtInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced RtpHeaderExtInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new RtpHeaderExtInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two RtpHeaderExtInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param rtp_header_ext_info The first RtpHeaderExtInfo object to compare.
 * @param other_rtp_header_ext_info The second RtpHeaderExtInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_is_equal_to(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_info_t *other_rtp_header_ext_info);


/** Check if the rtpHeaderExtType field of a RtpHeaderExtInfo object is set
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return `true` if the optional rtpHeaderExtType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_rtp_header_ext_type(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);


/** Get the value of the rtpHeaderExtType field of a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return the value current set for the rtpHeaderExtType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_header_ext_type_t* data_collection_model_rtp_header_ext_info_get_rtp_header_ext_type(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

/** Set the value of the rtpHeaderExtType field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_rtp_header_ext_type The value to copy into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type);

/** Move a value to the rtpHeaderExtType field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_rtp_header_ext_type The value to move into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type);

/** Check if the rtpHeaderExtId field of a RtpHeaderExtInfo object is set
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return `true` if the optional rtpHeaderExtId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_rtp_header_ext_id(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);


/** Get the value of the rtpHeaderExtId field of a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return the value current set for the rtpHeaderExtId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_rtp_header_ext_info_get_rtp_header_ext_id(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

/** Set the value of the rtpHeaderExtId field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_rtp_header_ext_id The value to copy into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const int32_t p_rtp_header_ext_id);

/** Move a value to the rtpHeaderExtId field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_rtp_header_ext_id The value to move into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, int32_t p_rtp_header_ext_id);

/** Check if the longFormat field of a RtpHeaderExtInfo object is set
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return `true` if the optional longFormat field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_long_format(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);


/** Get the value of the longFormat field of a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return the value current set for the longFormat field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_rtp_header_ext_info_is_long_format(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

/** Set the value of the longFormat field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_long_format The value to copy into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const bool p_long_format);

/** Move a value to the longFormat field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_long_format The value to move into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool p_long_format);

/** Check if the pduSetSizeActive field of a RtpHeaderExtInfo object is set
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return `true` if the optional pduSetSizeActive field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_pdu_set_size_active(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);


/** Get the value of the pduSetSizeActive field of a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to examine.
 *
 * @return the value current set for the pduSetSizeActive field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_rtp_header_ext_info_is_pdu_set_size_active(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

/** Set the value of the pduSetSizeActive field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_pdu_set_size_active The value to copy into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const bool p_pdu_set_size_active);

/** Move a value to the pduSetSizeActive field in a RtpHeaderExtInfo object
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to set the field in.
 * @param p_pdu_set_size_active The value to move into the RtpHeaderExtInfo object.
 *
 * @return @a rtp_header_ext_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool p_pdu_set_size_active);

/** lnode helper for generating ogs_list_t nodes's of type RtpHeaderExtInfo
 * \public \memberof data_collection_model_rtp_header_ext_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a rtp_header_ext_info object.
 * The @a rtp_header_ext_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param rtp_header_ext_info The RtpHeaderExtInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a rtp_header_ext_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_rtp_header_ext_info_make_lnode(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_RTP_HEADER_EXT_INFO_H_ */

