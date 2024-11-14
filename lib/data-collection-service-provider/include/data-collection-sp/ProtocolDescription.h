#ifndef _DATA_COLLECTION_PROTOCOL_DESCRIPTION_H_
#define _DATA_COLLECTION_PROTOCOL_DESCRIPTION_H_

/**********************************************************************************************************************************
 * ProtocolDescription - Public C interface to the ProtocolDescription object
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

#include "RtpPayloadInfo.h"
#include "MediaTransportProto.h"
#include "RtpHeaderExtInfo.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ProtocolDescription object reference
 */
typedef struct data_collection_model_protocol_description_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_protocol_description_t;



/** Create a new ProtocolDescription.
 * \public \memberof data_collection_model_protocol_description_t
 * @return a new ProtocolDescription object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create();

/** Create a new ProtocolDescription reference.
 * \public \memberof data_collection_model_protocol_description_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ProtocolDescription to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_ref(const data_collection_model_protocol_description_t *other);

/** Create a new copy of a ProtocolDescription object.
 * \public \memberof data_collection_model_protocol_description_t
 * Creates a new copy of the given @a other object
 * @param other The ProtocolDescription to copy.
 * @return a new ProtocolDescription object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_copy(const data_collection_model_protocol_description_t *other);

/** Create a new reference of a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ProtocolDescription to create a new reference to.
 * @return a new ProtocolDescription object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_move(data_collection_model_protocol_description_t *other);

/** Copy the value of another ProtocolDescription into this object
 * \public \memberof data_collection_model_protocol_description_t
 * Copies the value of @a other {{classname} object into @a protocol_description.
 * @param protocol_description The ProtocolDescription object to copy @a other into.
 * @param other The ProtocolDescription to copy the value from.
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_copy(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_protocol_description_t *other);

/** Move the value of another ProtocolDescription into this object
 * \public \memberof data_collection_model_protocol_description_t
 * Discards the current value of @a protocol_description and moves the value of @a other
 * into @a protocol_description. This will leave @a other as an empty reference.
 *
 * @param protocol_description The ProtocolDescription object to move @a other into.
 * @param other The ProtocolDescription to move the value from.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_protocol_description_t *other);

/** Delete a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 * Destroys the reference to the ProtocolDescription object and frees the value of ProtocolDescription if this is the last reference.
 *
 * @param protocol_description The ProtocolDescription to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_protocol_description_free(data_collection_model_protocol_description_t *protocol_description);

/** Get a cJSON tree representation of a ProtocolDescription
 * \public \memberof data_collection_model_protocol_description_t
 *
 * Create a cJSON tree representation of the ProtocolDescription object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param protocol_description The ProtocolDescription to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_protocol_description_toJSON(const data_collection_model_protocol_description_t *protocol_description, bool as_request);

/** Parse a cJSON tree into a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * Attempts to interpret a cJSON tree as a ProtocolDescription API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ProtocolDescription object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ProtocolDescription object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ProtocolDescription objects to see if they are equivalent
 * \public \memberof data_collection_model_protocol_description_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param protocol_description The first ProtocolDescription object to compare.
 * @param other_protocol_description The second ProtocolDescription object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_is_equal_to(const data_collection_model_protocol_description_t *protocol_description, const data_collection_model_protocol_description_t *other_protocol_description);


/** Check if the transportProto field of a ProtocolDescription object is set
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to examine.
 *
 * @return `true` if the optional transportProto field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_has_transport_proto(const data_collection_model_protocol_description_t *protocol_description);


/** Get the value of the transportProto field of a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to examine.
 *
 * @return the value current set for the transportProto field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_transport_proto_t* data_collection_model_protocol_description_get_transport_proto(const data_collection_model_protocol_description_t *protocol_description);

/** Set the value of the transportProto field in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to set the field in.
 * @param p_transport_proto The value to copy into the ProtocolDescription object.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_media_transport_proto_t* p_transport_proto);

/** Move a value to the transportProto field in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to set the field in.
 * @param p_transport_proto The value to move into the ProtocolDescription object.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_media_transport_proto_t* p_transport_proto);

/** Check if the rtpHeaderExtInfo field of a ProtocolDescription object is set
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to examine.
 *
 * @return `true` if the optional rtpHeaderExtInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_has_rtp_header_ext_info(const data_collection_model_protocol_description_t *protocol_description);


/** Get the value of the rtpHeaderExtInfo field of a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to examine.
 *
 * @return the value current set for the rtpHeaderExtInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_header_ext_info_t* data_collection_model_protocol_description_get_rtp_header_ext_info(const data_collection_model_protocol_description_t *protocol_description);

/** Set the value of the rtpHeaderExtInfo field in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to set the field in.
 * @param p_rtp_header_ext_info The value to copy into the ProtocolDescription object.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info);

/** Move a value to the rtpHeaderExtInfo field in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to set the field in.
 * @param p_rtp_header_ext_info The value to move into the ProtocolDescription object.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info);

/** Check if the rtpPayloadInfoList field of a ProtocolDescription object is set
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to examine.
 *
 * @return `true` if the optional rtpPayloadInfoList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_has_rtp_payload_info_list(const data_collection_model_protocol_description_t *protocol_description);


/** Get the value of the rtpPayloadInfoList field of a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to examine.
 *
 * @return the value current set for the rtpPayloadInfoList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_protocol_description_get_rtp_payload_info_list(const data_collection_model_protocol_description_t *protocol_description);

/** Set the value of the rtpPayloadInfoList field in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to set the field in.
 * @param p_rtp_payload_info_list The value to copy into the ProtocolDescription object.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description, const ogs_list_t* p_rtp_payload_info_list);

/** Move a value to the rtpPayloadInfoList field in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to set the field in.
 * @param p_rtp_payload_info_list The value to move into the ProtocolDescription object.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list_move(data_collection_model_protocol_description_t *protocol_description, ogs_list_t* p_rtp_payload_info_list);

/** Add a new item to the rtpPayloadInfoList array in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to add the array item to.
 * @param rtp_payload_info_list The value to add.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_add_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description, data_collection_model_rtp_payload_info_t* rtp_payload_info_list);

/** Remove an item from the rtpPayloadInfoList array in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to remove the array value from.
 * @param rtp_payload_info_list The value to remove.
 *
 * @return @a protocol_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_remove_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_rtp_payload_info_t* rtp_payload_info_list);

/** Get an item from the rtpPayloadInfoList array in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_payload_info_t* data_collection_model_protocol_description_get_entry_rtp_payload_info_list(const data_collection_model_protocol_description_t *protocol_description, size_t idx);

/** Remove all entries from the rtpPayloadInfoList array in a ProtocolDescription object
 * \public \memberof data_collection_model_protocol_description_t
 *
 * @param protocol_description The ProtocolDescription object to empty rtpPayloadInfoList for.
 *
 * @return @a protocol_description
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_clear_rtp_payload_info_list(data_collection_model_protocol_description_t *protocol_description);

/** lnode helper for generating ogs_list_t nodes's of type ProtocolDescription
 * \public \memberof data_collection_model_protocol_description_t
 *
 * Creates a new data_collection_lnode_t object containing the @a protocol_description object.
 * The @a protocol_description will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param protocol_description The ProtocolDescription object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a protocol_description
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_protocol_description_make_lnode(data_collection_model_protocol_description_t *protocol_description);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PROTOCOL_DESCRIPTION_H_ */

