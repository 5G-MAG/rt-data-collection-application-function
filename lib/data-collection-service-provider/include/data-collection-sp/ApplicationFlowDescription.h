#ifndef _DATA_COLLECTION_APPLICATION_FLOW_DESCRIPTION_H_
#define _DATA_COLLECTION_APPLICATION_FLOW_DESCRIPTION_H_

/**********************************************************************************************************************************
 * ApplicationFlowDescription - Public C interface to the ApplicationFlowDescription object
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

#include "IpPacketFilterSet.h"
#include "SdfMethod.h"
#include "ProtocolDescription.h"
#include "MediaType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ApplicationFlowDescription object reference
 */
typedef struct data_collection_model_application_flow_description_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_application_flow_description_t;



/** Create a new ApplicationFlowDescription
 * \public \memberof data_collection_model_application_flow_description_t
 * @return a new ApplicationFlowDescription object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create();

/** Create a new copy of a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 * Creates a new copy of the given @a other object
 * @param other The ApplicationFlowDescription to copy.
 * @return a new ApplicationFlowDescription object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create_copy(const data_collection_model_application_flow_description_t *other);

/** Create a new reference of a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ApplicationFlowDescription to create a new reference to.
 * @return a new ApplicationFlowDescription object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create_move(data_collection_model_application_flow_description_t *other);

/** Copy the value of another ApplicationFlowDescription into this object
 * \public \memberof data_collection_model_application_flow_description_t
 * Copies the value of @a other {{classname} object into @a application_flow_description.
 * @param application_flow_description The ApplicationFlowDescription object to copy @a other into.
 * @param other The ApplicationFlowDescription to copy the value from.
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_copy(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_application_flow_description_t *other);

/** Move the value of another ApplicationFlowDescription into this object
 * \public \memberof data_collection_model_application_flow_description_t
 * Discards the current value of @a application_flow_description and moves the value of @a other
 * into @a application_flow_description. This will leave @a other as an empty reference.
 *
 * @param application_flow_description The ApplicationFlowDescription object to move @a other into.
 * @param other The ApplicationFlowDescription to move the value from.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_application_flow_description_t *other);

/** Delete a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 * Destroys the reference to the ApplicationFlowDescription object and frees the value of ApplicationFlowDescription if this is the last reference.
 *
 * @param application_flow_description The ApplicationFlowDescription to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_application_flow_description_free(data_collection_model_application_flow_description_t *application_flow_description);

/** Get a cJSON tree representation of a ApplicationFlowDescription
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * Create a cJSON tree representation of the ApplicationFlowDescription object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param application_flow_description The ApplicationFlowDescription to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_application_flow_description_toJSON(const data_collection_model_application_flow_description_t *application_flow_description, bool as_request);

/** Parse a cJSON tree into a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * Attempts to interpret a cJSON tree as a ApplicationFlowDescription API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ApplicationFlowDescription object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ApplicationFlowDescription object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ApplicationFlowDescription objects to see if they are equivalent
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param application_flow_description The first ApplicationFlowDescription object to compare.
 * @param other_application_flow_description The second ApplicationFlowDescription object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_application_flow_description_is_equal_to(const data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_application_flow_description_t *other_application_flow_description);



/** Get the value of the filterMethod field of a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return the value current set for the filterMethod field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_sdf_method_t* data_collection_model_application_flow_description_get_filter_method(const data_collection_model_application_flow_description_t *application_flow_description);

/** Set the value of the filterMethod field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_filter_method The value to copy into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_filter_method(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_sdf_method_t* p_filter_method);

/** Move a value to the filterMethod field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_filter_method The value to move into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_filter_method_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_sdf_method_t* p_filter_method);

/** Check if the packetFilter field of a ApplicationFlowDescription object is set
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return `true` if the optional packetFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_application_flow_description_has_packet_filter(const data_collection_model_application_flow_description_t *application_flow_description);


/** Get the value of the packetFilter field of a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return the value current set for the packetFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_packet_filter_set_t* data_collection_model_application_flow_description_get_packet_filter(const data_collection_model_application_flow_description_t *application_flow_description);

/** Set the value of the packetFilter field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_packet_filter The value to copy into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_packet_filter(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_ip_packet_filter_set_t* p_packet_filter);

/** Move a value to the packetFilter field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_packet_filter The value to move into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_packet_filter_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_ip_packet_filter_set_t* p_packet_filter);

/** Check if the domainName field of a ApplicationFlowDescription object is set
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return `true` if the optional domainName field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_application_flow_description_has_domain_name(const data_collection_model_application_flow_description_t *application_flow_description);


/** Get the value of the domainName field of a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return the value current set for the domainName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_application_flow_description_get_domain_name(const data_collection_model_application_flow_description_t *application_flow_description);

/** Set the value of the domainName field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_domain_name The value to copy into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_domain_name(data_collection_model_application_flow_description_t *application_flow_description, const char* p_domain_name);

/** Move a value to the domainName field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_domain_name The value to move into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_domain_name_move(data_collection_model_application_flow_description_t *application_flow_description, char* p_domain_name);

/** Check if the mediaType field of a ApplicationFlowDescription object is set
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return `true` if the optional mediaType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_application_flow_description_has_media_type(const data_collection_model_application_flow_description_t *application_flow_description);


/** Get the value of the mediaType field of a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return the value current set for the mediaType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_type_t* data_collection_model_application_flow_description_get_media_type(const data_collection_model_application_flow_description_t *application_flow_description);

/** Set the value of the mediaType field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_media_type The value to copy into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_type(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_media_type_t* p_media_type);

/** Move a value to the mediaType field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_media_type The value to move into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_type_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_media_type_t* p_media_type);

/** Check if the mediaTransportParameters field of a ApplicationFlowDescription object is set
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return `true` if the optional mediaTransportParameters field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_application_flow_description_has_media_transport_parameters(const data_collection_model_application_flow_description_t *application_flow_description);


/** Get the value of the mediaTransportParameters field of a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to examine.
 *
 * @return the value current set for the mediaTransportParameters field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_protocol_description_t* data_collection_model_application_flow_description_get_media_transport_parameters(const data_collection_model_application_flow_description_t *application_flow_description);

/** Set the value of the mediaTransportParameters field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_media_transport_parameters The value to copy into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_transport_parameters(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_protocol_description_t* p_media_transport_parameters);

/** Move a value to the mediaTransportParameters field in a ApplicationFlowDescription object
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * @param application_flow_description The ApplicationFlowDescription object to set the field in.
 * @param p_media_transport_parameters The value to move into the ApplicationFlowDescription object.
 *
 * @return @a application_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_transport_parameters_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_protocol_description_t* p_media_transport_parameters);

/** lnode helper for generating ogs_list_t nodes's of type ApplicationFlowDescription
 * \public \memberof data_collection_model_application_flow_description_t
 *
 * Creates a new data_collection_lnode_t object containing the @a application_flow_description object.
 * The @a application_flow_description will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param application_flow_description The ApplicationFlowDescription object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a application_flow_description
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_application_flow_description_make_lnode(data_collection_model_application_flow_description_t *application_flow_description);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_APPLICATION_FLOW_DESCRIPTION_H_ */

