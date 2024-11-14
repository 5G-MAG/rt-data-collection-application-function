#ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_H_
#define _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_H_

/**********************************************************************************************************************************
 * NetworkAssistanceInvocation - Public C interface to the NetworkAssistanceInvocation object
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

#include "NetworkAssistanceInvocation_recommendedQoS.h"
#include "UnidirectionalQoSSpecification.h"
#include "ApplicationFlowDescription.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP NetworkAssistanceInvocation object reference
 */
typedef struct data_collection_model_network_assistance_invocation_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_network_assistance_invocation_t;



/** Create a new NetworkAssistanceInvocation.
 * \public \memberof data_collection_model_network_assistance_invocation_t
 * @return a new NetworkAssistanceInvocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create();

/** Create a new NetworkAssistanceInvocation reference.
 * \public \memberof data_collection_model_network_assistance_invocation_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The NetworkAssistanceInvocation to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_ref(const data_collection_model_network_assistance_invocation_t *other);

/** Create a new copy of a NetworkAssistanceInvocation object.
 * \public \memberof data_collection_model_network_assistance_invocation_t
 * Creates a new copy of the given @a other object
 * @param other The NetworkAssistanceInvocation to copy.
 * @return a new NetworkAssistanceInvocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_copy(const data_collection_model_network_assistance_invocation_t *other);

/** Create a new reference of a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 * Creates a reference to the same underlying @a other object.
 * @param other The NetworkAssistanceInvocation to create a new reference to.
 * @return a new NetworkAssistanceInvocation object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_move(data_collection_model_network_assistance_invocation_t *other);

/** Copy the value of another NetworkAssistanceInvocation into this object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 * Copies the value of @a other {{classname} object into @a network_assistance_invocation.
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to copy @a other into.
 * @param other The NetworkAssistanceInvocation to copy the value from.
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_copy(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_network_assistance_invocation_t *other);

/** Move the value of another NetworkAssistanceInvocation into this object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 * Discards the current value of @a network_assistance_invocation and moves the value of @a other
 * into @a network_assistance_invocation. This will leave @a other as an empty reference.
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to move @a other into.
 * @param other The NetworkAssistanceInvocation to move the value from.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_network_assistance_invocation_t *other);

/** Delete a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 * Destroys the reference to the NetworkAssistanceInvocation object and frees the value of NetworkAssistanceInvocation if this is the last reference.
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_free(data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/** Get a cJSON tree representation of a NetworkAssistanceInvocation
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * Create a cJSON tree representation of the NetworkAssistanceInvocation object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_toJSON(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation, bool as_request);

/** Parse a cJSON tree into a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * Attempts to interpret a cJSON tree as a NetworkAssistanceInvocation API request or response (dependent on @a as_request value). If successful
 * will return a new referenced NetworkAssistanceInvocation object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new NetworkAssistanceInvocation object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two NetworkAssistanceInvocation objects to see if they are equivalent
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param network_assistance_invocation The first NetworkAssistanceInvocation object to compare.
 * @param other_network_assistance_invocation The second NetworkAssistanceInvocation object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_is_equal_to(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_network_assistance_invocation_t *other_network_assistance_invocation);


/** Check if the policyTemplateId field of a NetworkAssistanceInvocation object is set
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return `true` if the optional policyTemplateId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_policy_template_id(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);


/** Get the value of the policyTemplateId field of a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return the value current set for the policyTemplateId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_get_policy_template_id(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/** Set the value of the policyTemplateId field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_policy_template_id The value to copy into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const char* p_policy_template_id);

/** Move a value to the policyTemplateId field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_policy_template_id The value to move into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, char* p_policy_template_id);

/** Check if the applicationFlowDescriptions field of a NetworkAssistanceInvocation object is set
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return `true` if the optional applicationFlowDescriptions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);


/** Get the value of the applicationFlowDescriptions field of a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return the value current set for the applicationFlowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocation_get_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/** Set the value of the applicationFlowDescriptions field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_application_flow_descriptions The value to copy into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const ogs_list_t* p_application_flow_descriptions);

/** Move a value to the applicationFlowDescriptions field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_application_flow_descriptions The value to move into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, ogs_list_t* p_application_flow_descriptions);

/** Add a new item to the applicationFlowDescriptions array in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to add the array item to.
 * @param application_flow_descriptions The value to add.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_add_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Remove an item from the applicationFlowDescriptions array in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to remove the array value from.
 * @param application_flow_descriptions The value to remove.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_remove_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Get an item from the applicationFlowDescriptions array in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_network_assistance_invocation_get_entry_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation, size_t idx);

/** Remove all entries from the applicationFlowDescriptions array in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to empty applicationFlowDescriptions for.
 *
 * @return @a network_assistance_invocation
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_clear_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/** Check if the requestedQoS field of a NetworkAssistanceInvocation object is set
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return `true` if the optional requestedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_requested_qo_s(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);


/** Get the value of the requestedQoS field of a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return the value current set for the requestedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_network_assistance_invocation_get_requested_qo_s(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/** Set the value of the requestedQoS field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_requested_qo_s The value to copy into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Move a value to the requestedQoS field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_requested_qo_s The value to move into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Check if the recommendedQoS field of a NetworkAssistanceInvocation object is set
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return `true` if the optional recommendedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_recommended_qo_s(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);


/** Get the value of the recommendedQoS field of a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to examine.
 *
 * @return the value current set for the recommendedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_network_assistance_invocation_get_recommended_qo_s(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/** Set the value of the recommendedQoS field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_recommended_qo_s The value to copy into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/** Move a value to the recommendedQoS field in a NetworkAssistanceInvocation object
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to set the field in.
 * @param p_recommended_qo_s The value to move into the NetworkAssistanceInvocation object.
 *
 * @return @a network_assistance_invocation.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/** lnode helper for generating ogs_list_t nodes's of type NetworkAssistanceInvocation
 * \public \memberof data_collection_model_network_assistance_invocation_t
 *
 * Creates a new data_collection_lnode_t object containing the @a network_assistance_invocation object.
 * The @a network_assistance_invocation will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param network_assistance_invocation The NetworkAssistanceInvocation object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a network_assistance_invocation
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_make_lnode(data_collection_model_network_assistance_invocation_t *network_assistance_invocation);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_H_ */

