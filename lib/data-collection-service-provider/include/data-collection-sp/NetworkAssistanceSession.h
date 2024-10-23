#ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_SESSION_H_
#define _DATA_COLLECTION_NETWORK_ASSISTANCE_SESSION_H_

/**********************************************************************************************************************************
 * NetworkAssistanceSession - Public C interface to the NetworkAssistanceSession object
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

#include "M5QoSSpecification.h"
#include "ApplicationFlowDescription.h"
#include "MediaType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP NetworkAssistanceSession object reference
 */
typedef struct data_collection_model_network_assistance_session_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_network_assistance_session_t;



/** Create a new NetworkAssistanceSession
 * \public \memberof data_collection_model_network_assistance_session_t
 * @return a new NetworkAssistanceSession object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create();

/** Create a new copy of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 * Creates a new copy of the given @a other object
 * @param other The NetworkAssistanceSession to copy.
 * @return a new NetworkAssistanceSession object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create_copy(const data_collection_model_network_assistance_session_t *other);

/** Create a new reference of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 * Creates a reference to the same underlying @a other object.
 * @param other The NetworkAssistanceSession to create a new reference to.
 * @return a new NetworkAssistanceSession object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create_move(data_collection_model_network_assistance_session_t *other);

/** Copy the value of another NetworkAssistanceSession into this object
 * \public \memberof data_collection_model_network_assistance_session_t
 * Copies the value of @a other {{classname} object into @a network_assistance_session.
 * @param network_assistance_session The NetworkAssistanceSession object to copy @a other into.
 * @param other The NetworkAssistanceSession to copy the value from.
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_copy(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_network_assistance_session_t *other);

/** Move the value of another NetworkAssistanceSession into this object
 * \public \memberof data_collection_model_network_assistance_session_t
 * Discards the current value of @a network_assistance_session and moves the value of @a other
 * into @a network_assistance_session. This will leave @a other as an empty reference.
 *
 * @param network_assistance_session The NetworkAssistanceSession object to move @a other into.
 * @param other The NetworkAssistanceSession to move the value from.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_network_assistance_session_t *other);

/** Delete a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 * Destroys the reference to the NetworkAssistanceSession object and frees the value of NetworkAssistanceSession if this is the last reference.
 *
 * @param network_assistance_session The NetworkAssistanceSession to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_session_free(data_collection_model_network_assistance_session_t *network_assistance_session);

/** Get a cJSON tree representation of a NetworkAssistanceSession
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * Create a cJSON tree representation of the NetworkAssistanceSession object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param network_assistance_session The NetworkAssistanceSession to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_session_toJSON(const data_collection_model_network_assistance_session_t *network_assistance_session, bool as_request);

/** Parse a cJSON tree into a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * Attempts to interpret a cJSON tree as a NetworkAssistanceSession API request or response (dependent on @a as_request value). If successful
 * will return a new referenced NetworkAssistanceSession object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new NetworkAssistanceSession object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two NetworkAssistanceSession objects to see if they are equivalent
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param network_assistance_session The first NetworkAssistanceSession object to compare.
 * @param other_network_assistance_session The second NetworkAssistanceSession object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_session_is_equal_to(const data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_network_assistance_session_t *other_network_assistance_session);



/** Get the value of the naSessionId field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the naSessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_na_session_id(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the naSessionId field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_na_session_id The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_na_session_id(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_na_session_id);

/** Move a value to the naSessionId field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_na_session_id The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_na_session_id_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_na_session_id);


/** Get the value of the provisioningSessionId field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the provisioningSessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_provisioning_session_id(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the provisioningSessionId field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_provisioning_session_id The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_provisioning_session_id(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_provisioning_session_id);

/** Move a value to the provisioningSessionId field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_provisioning_session_id The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_provisioning_session_id_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_provisioning_session_id);


/** Get the value of the serviceDataFlowDescriptions field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the serviceDataFlowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_session_get_service_data_flow_descriptions(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the serviceDataFlowDescriptions field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_service_data_flow_descriptions The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session, const ogs_list_t* p_service_data_flow_descriptions);

/** Move a value to the serviceDataFlowDescriptions field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_service_data_flow_descriptions The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_service_data_flow_descriptions_move(data_collection_model_network_assistance_session_t *network_assistance_session, ogs_list_t* p_service_data_flow_descriptions);

/** Add a new item to the serviceDataFlowDescriptions array in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to add the array item to.
 * @param service_data_flow_descriptions The value to add.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_add_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_application_flow_description_t* service_data_flow_descriptions);

/** Remove an item from the serviceDataFlowDescriptions array in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to remove the array value from.
 * @param service_data_flow_descriptions The value to remove.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_remove_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_application_flow_description_t* service_data_flow_descriptions);

/** Get an item from the serviceDataFlowDescriptions array in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_network_assistance_session_get_entry_service_data_flow_descriptions(const data_collection_model_network_assistance_session_t *network_assistance_session, size_t idx);

/** Remove all entries from the serviceDataFlowDescriptions array in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to empty serviceDataFlowDescriptions for.
 *
 * @return @a network_assistance_session
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_clear_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *network_assistance_session);

/** Check if the mediaType field of a NetworkAssistanceSession object is set
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return `true` if the optional mediaType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_session_has_media_type(const data_collection_model_network_assistance_session_t *network_assistance_session);


/** Get the value of the mediaType field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the mediaType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_type_t* data_collection_model_network_assistance_session_get_media_type(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the mediaType field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_media_type The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_media_type(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_media_type_t* p_media_type);

/** Move a value to the mediaType field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_media_type The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_media_type_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_media_type_t* p_media_type);

/** Check if the policyTemplateId field of a NetworkAssistanceSession object is set
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return `true` if the optional policyTemplateId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_session_has_policy_template_id(const data_collection_model_network_assistance_session_t *network_assistance_session);


/** Get the value of the policyTemplateId field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the policyTemplateId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_policy_template_id(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the policyTemplateId field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_policy_template_id The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_policy_template_id(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_policy_template_id);

/** Move a value to the policyTemplateId field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_policy_template_id The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_policy_template_id_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_policy_template_id);

/** Check if the requestedQoS field of a NetworkAssistanceSession object is set
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return `true` if the optional requestedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_session_has_requested_qo_s(const data_collection_model_network_assistance_session_t *network_assistance_session);


/** Get the value of the requestedQoS field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the requestedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_qo_s_specification_t* data_collection_model_network_assistance_session_get_requested_qo_s(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the requestedQoS field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_requested_qo_s The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_requested_qo_s(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_m5_qo_s_specification_t* p_requested_qo_s);

/** Move a value to the requestedQoS field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_requested_qo_s The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_requested_qo_s_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_m5_qo_s_specification_t* p_requested_qo_s);

/** Check if the recommendedQoS field of a NetworkAssistanceSession object is set
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return `true` if the optional recommendedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_session_has_recommended_qo_s(const data_collection_model_network_assistance_session_t *network_assistance_session);


/** Get the value of the recommendedQoS field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the recommendedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_qo_s_specification_t* data_collection_model_network_assistance_session_get_recommended_qo_s(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the recommendedQoS field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_recommended_qo_s The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_recommended_qo_s(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_m5_qo_s_specification_t* p_recommended_qo_s);

/** Move a value to the recommendedQoS field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_recommended_qo_s The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_recommended_qo_s_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_m5_qo_s_specification_t* p_recommended_qo_s);

/** Check if the notficationURL field of a NetworkAssistanceSession object is set
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return `true` if the optional notficationURL field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_session_has_notfication_url(const data_collection_model_network_assistance_session_t *network_assistance_session);


/** Get the value of the notficationURL field of a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to examine.
 *
 * @return the value current set for the notficationURL field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_session_get_notfication_url(const data_collection_model_network_assistance_session_t *network_assistance_session);

/** Set the value of the notficationURL field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_notfication_url The value to copy into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_notfication_url(data_collection_model_network_assistance_session_t *network_assistance_session, const char* p_notfication_url);

/** Move a value to the notficationURL field in a NetworkAssistanceSession object
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * @param network_assistance_session The NetworkAssistanceSession object to set the field in.
 * @param p_notfication_url The value to move into the NetworkAssistanceSession object.
 *
 * @return @a network_assistance_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_notfication_url_move(data_collection_model_network_assistance_session_t *network_assistance_session, char* p_notfication_url);

/** lnode helper for generating ogs_list_t nodes's of type NetworkAssistanceSession
 * \public \memberof data_collection_model_network_assistance_session_t
 *
 * Creates a new data_collection_lnode_t object containing the @a network_assistance_session object.
 * The @a network_assistance_session will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param network_assistance_session The NetworkAssistanceSession object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a network_assistance_session
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_session_make_lnode(data_collection_model_network_assistance_session_t *network_assistance_session);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_SESSION_H_ */

