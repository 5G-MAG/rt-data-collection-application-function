#ifndef _DATA_COLLECTION_IP_PACKET_FILTER_SET_H_
#define _DATA_COLLECTION_IP_PACKET_FILTER_SET_H_

/**********************************************************************************************************************************
 * IpPacketFilterSet - Public C interface to the IpPacketFilterSet object
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

#include "IpAddr.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP IpPacketFilterSet object reference
 */
typedef struct data_collection_model_ip_packet_filter_set_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ip_packet_filter_set_t;



/** Create a new IpPacketFilterSet.
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 * @return a new IpPacketFilterSet object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create();

/** Create a new IpPacketFilterSet reference.
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The IpPacketFilterSet to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create_ref(const data_collection_model_ip_packet_filter_set_t *other);

/** Create a new copy of a IpPacketFilterSet object.
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 * Creates a new copy of the given @a other object
 * @param other The IpPacketFilterSet to copy.
 * @return a new IpPacketFilterSet object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create_copy(const data_collection_model_ip_packet_filter_set_t *other);

/** Create a new reference of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 * Creates a reference to the same underlying @a other object.
 * @param other The IpPacketFilterSet to create a new reference to.
 * @return a new IpPacketFilterSet object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create_move(data_collection_model_ip_packet_filter_set_t *other);

/** Copy the value of another IpPacketFilterSet into this object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 * Copies the value of @a other {{classname} object into @a ip_packet_filter_set.
 * @param ip_packet_filter_set The IpPacketFilterSet object to copy @a other into.
 * @param other The IpPacketFilterSet to copy the value from.
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_copy(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_packet_filter_set_t *other);

/** Move the value of another IpPacketFilterSet into this object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 * Discards the current value of @a ip_packet_filter_set and moves the value of @a other
 * into @a ip_packet_filter_set. This will leave @a other as an empty reference.
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to move @a other into.
 * @param other The IpPacketFilterSet to move the value from.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, data_collection_model_ip_packet_filter_set_t *other);

/** Delete a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 * Destroys the reference to the IpPacketFilterSet object and frees the value of IpPacketFilterSet if this is the last reference.
 *
 * @param ip_packet_filter_set The IpPacketFilterSet to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ip_packet_filter_set_free(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Get a cJSON tree representation of a IpPacketFilterSet
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * Create a cJSON tree representation of the IpPacketFilterSet object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ip_packet_filter_set The IpPacketFilterSet to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ip_packet_filter_set_toJSON(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, bool as_request);

/** Parse a cJSON tree into a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * Attempts to interpret a cJSON tree as a IpPacketFilterSet API request or response (dependent on @a as_request value). If successful
 * will return a new referenced IpPacketFilterSet object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new IpPacketFilterSet object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two IpPacketFilterSet objects to see if they are equivalent
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ip_packet_filter_set The first IpPacketFilterSet object to compare.
 * @param other_ip_packet_filter_set The second IpPacketFilterSet object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_is_equal_to(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_packet_filter_set_t *other_ip_packet_filter_set);



/** Get the value of the direction field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the direction field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ip_packet_filter_set_get_direction(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the direction field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_direction The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_direction(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const char* p_direction);

/** Move a value to the direction field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_direction The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_direction_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, char* p_direction);

/** Check if the sourceAddress field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional sourceAddress field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_source_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the sourceAddress field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the sourceAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_ip_packet_filter_set_get_source_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the sourceAddress field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_source_address The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_address(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_addr_t* p_source_address);

/** Move a value to the sourceAddress field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_source_address The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_address_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, data_collection_model_ip_addr_t* p_source_address);

/** Check if the destinationAddress field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional destinationAddress field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_destination_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the destinationAddress field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the destinationAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_ip_packet_filter_set_get_destination_address(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the destinationAddress field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_destination_address The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_address(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_addr_t* p_destination_address);

/** Move a value to the destinationAddress field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_destination_address The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_address_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, data_collection_model_ip_addr_t* p_destination_address);

/** Check if the protocolNumber field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional protocolNumber field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_protocol_number(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the protocolNumber field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the protocolNumber field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_protocol_number(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the protocolNumber field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_protocol_number The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_protocol_number(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_protocol_number);

/** Move a value to the protocolNumber field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_protocol_number The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_protocol_number_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_protocol_number);

/** Check if the sourcePort field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional sourcePort field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_source_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the sourcePort field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the sourcePort field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_source_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the sourcePort field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_source_port The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_port(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_source_port);

/** Move a value to the sourcePort field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_source_port The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_port_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_source_port);

/** Check if the destinationPort field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional destinationPort field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_destination_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the destinationPort field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the destinationPort field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_destination_port(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the destinationPort field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_destination_port The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_port(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_destination_port);

/** Move a value to the destinationPort field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_destination_port The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_port_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_destination_port);

/** Check if the differentiatedServicesCodePoint field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional differentiatedServicesCodePoint field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_differentiated_services_code_point(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the differentiatedServicesCodePoint field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the differentiatedServicesCodePoint field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_differentiated_services_code_point(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the differentiatedServicesCodePoint field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_differentiated_services_code_point The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_differentiated_services_code_point(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_differentiated_services_code_point);

/** Move a value to the differentiatedServicesCodePoint field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_differentiated_services_code_point The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_differentiated_services_code_point_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_differentiated_services_code_point);

/** Check if the flowLabel field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional flowLabel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_flow_label(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the flowLabel field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the flowLabel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_flow_label(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the flowLabel field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_flow_label The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_flow_label(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_flow_label);

/** Move a value to the flowLabel field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_flow_label The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_flow_label_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_flow_label);

/** Check if the securityParametersIndex field of a IpPacketFilterSet object is set
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return `true` if the optional securityParametersIndex field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_packet_filter_set_has_security_parameters_index(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);


/** Get the value of the securityParametersIndex field of a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to examine.
 *
 * @return the value current set for the securityParametersIndex field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ip_packet_filter_set_get_security_parameters_index(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/** Set the value of the securityParametersIndex field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_security_parameters_index The value to copy into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_security_parameters_index(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const int32_t p_security_parameters_index);

/** Move a value to the securityParametersIndex field in a IpPacketFilterSet object
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to set the field in.
 * @param p_security_parameters_index The value to move into the IpPacketFilterSet object.
 *
 * @return @a ip_packet_filter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_security_parameters_index_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, int32_t p_security_parameters_index);

/** lnode helper for generating ogs_list_t nodes's of type IpPacketFilterSet
 * \public \memberof data_collection_model_ip_packet_filter_set_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ip_packet_filter_set object.
 * The @a ip_packet_filter_set will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ip_packet_filter_set The IpPacketFilterSet object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ip_packet_filter_set
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ip_packet_filter_set_make_lnode(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_IP_PACKET_FILTER_SET_H_ */

