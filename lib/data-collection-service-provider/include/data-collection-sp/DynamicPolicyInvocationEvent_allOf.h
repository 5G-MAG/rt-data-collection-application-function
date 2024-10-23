#ifndef _DATA_COLLECTION_DYNAMIC_POLICY_INVOCATION_EVENT_ALL_OF_H_
#define _DATA_COLLECTION_DYNAMIC_POLICY_INVOCATION_EVENT_ALL_OF_H_

/**********************************************************************************************************************************
 * DynamicPolicyInvocationEvent_allOf - Public C interface to the DynamicPolicyInvocationEvent_allOf object
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

#include "UnidirectionalQoSSpecification.h"
#include "ApplicationFlowDescription.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DynamicPolicyInvocationEvent_allOf object reference
 */
typedef struct data_collection_model_dynamic_policy_invocation_event_all_of_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_dynamic_policy_invocation_event_all_of_t;



/** Create a new DynamicPolicyInvocationEvent_allOf
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 * @return a new DynamicPolicyInvocationEvent_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create();

/** Create a new copy of a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 * Creates a new copy of the given @a other object
 * @param other The DynamicPolicyInvocationEvent_allOf to copy.
 * @return a new DynamicPolicyInvocationEvent_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create_copy(const data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

/** Create a new reference of a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DynamicPolicyInvocationEvent_allOf to create a new reference to.
 * @return a new DynamicPolicyInvocationEvent_allOf object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

/** Copy the value of another DynamicPolicyInvocationEvent_allOf into this object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 * Copies the value of @a other {{classname} object into @a dynamic_policy_invocation_event_all_of.
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to copy @a other into.
 * @param other The DynamicPolicyInvocationEvent_allOf to copy the value from.
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_copy(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

/** Move the value of another DynamicPolicyInvocationEvent_allOf into this object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 * Discards the current value of @a dynamic_policy_invocation_event_all_of and moves the value of @a other
 * into @a dynamic_policy_invocation_event_all_of. This will leave @a other as an empty reference.
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to move @a other into.
 * @param other The DynamicPolicyInvocationEvent_allOf to move the value from.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, data_collection_model_dynamic_policy_invocation_event_all_of_t *other);

/** Delete a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 * Destroys the reference to the DynamicPolicyInvocationEvent_allOf object and frees the value of DynamicPolicyInvocationEvent_allOf if this is the last reference.
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dynamic_policy_invocation_event_all_of_free(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/** Get a cJSON tree representation of a DynamicPolicyInvocationEvent_allOf
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * Create a cJSON tree representation of the DynamicPolicyInvocationEvent_allOf object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dynamic_policy_invocation_event_all_of_toJSON(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, bool as_request);

/** Parse a cJSON tree into a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * Attempts to interpret a cJSON tree as a DynamicPolicyInvocationEvent_allOf API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DynamicPolicyInvocationEvent_allOf object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DynamicPolicyInvocationEvent_allOf object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DynamicPolicyInvocationEvent_allOf objects to see if they are equivalent
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param dynamic_policy_invocation_event_all_of The first DynamicPolicyInvocationEvent_allOf object to compare.
 * @param other_dynamic_policy_invocation_event_all_of The second DynamicPolicyInvocationEvent_allOf object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_is_equal_to(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_dynamic_policy_invocation_event_all_of_t *other_dynamic_policy_invocation_event_all_of);



/** Get the value of the policyTemplateId field of a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return the value current set for the policyTemplateId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_policy_template_id(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/** Set the value of the policyTemplateId field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_policy_template_id The value to copy into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_policy_template_id(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const char* p_policy_template_id);

/** Move a value to the policyTemplateId field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_policy_template_id The value to move into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_policy_template_id_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, char* p_policy_template_id);

/** Check if the applicationFlowDescriptions field of a DynamicPolicyInvocationEvent_allOf object is set
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return `true` if the optional applicationFlowDescriptions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_application_flow_descriptions(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);


/** Get the value of the applicationFlowDescriptions field of a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return the value current set for the applicationFlowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_application_flow_descriptions(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/** Set the value of the applicationFlowDescriptions field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_application_flow_descriptions The value to copy into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const ogs_list_t* p_application_flow_descriptions);

/** Move a value to the applicationFlowDescriptions field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_application_flow_descriptions The value to move into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_application_flow_descriptions_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, ogs_list_t* p_application_flow_descriptions);

/** Add a new item to the applicationFlowDescriptions array in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to add the array item to.
 * @param application_flow_descriptions The value to add.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_add_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Remove an item from the applicationFlowDescriptions array in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to remove the array value from.
 * @param application_flow_descriptions The value to remove.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_remove_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Get an item from the applicationFlowDescriptions array in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_entry_application_flow_descriptions(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, size_t idx);

/** Remove all entries from the applicationFlowDescriptions array in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to empty applicationFlowDescriptions for.
 *
 * @return @a dynamic_policy_invocation_event_all_of
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_clear_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/** Check if the requestedQoS field of a DynamicPolicyInvocationEvent_allOf object is set
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return `true` if the optional requestedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_requested_qo_s(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);


/** Get the value of the requestedQoS field of a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return the value current set for the requestedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_requested_qo_s(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/** Set the value of the requestedQoS field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_requested_qo_s The value to copy into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_requested_qo_s(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Move a value to the requestedQoS field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_requested_qo_s The value to move into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_requested_qo_s_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Check if the enforcementMethod field of a DynamicPolicyInvocationEvent_allOf object is set
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return `true` if the optional enforcementMethod field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_enforcement_method(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);


/** Get the value of the enforcementMethod field of a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return the value current set for the enforcementMethod field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_enforcement_method(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/** Set the value of the enforcementMethod field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_enforcement_method The value to copy into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_method(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const char* p_enforcement_method);

/** Move a value to the enforcementMethod field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_enforcement_method The value to move into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_method_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, char* p_enforcement_method);

/** Check if the enforcementBitRate field of a DynamicPolicyInvocationEvent_allOf object is set
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return `true` if the optional enforcementBitRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_enforcement_bit_rate(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);


/** Get the value of the enforcementBitRate field of a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to examine.
 *
 * @return the value current set for the enforcementBitRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_enforcement_bit_rate(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/** Set the value of the enforcementBitRate field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_enforcement_bit_rate The value to copy into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_bit_rate(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const char* p_enforcement_bit_rate);

/** Move a value to the enforcementBitRate field in a DynamicPolicyInvocationEvent_allOf object
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to set the field in.
 * @param p_enforcement_bit_rate The value to move into the DynamicPolicyInvocationEvent_allOf object.
 *
 * @return @a dynamic_policy_invocation_event_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_bit_rate_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, char* p_enforcement_bit_rate);

/** lnode helper for generating ogs_list_t nodes's of type DynamicPolicyInvocationEvent_allOf
 * \public \memberof data_collection_model_dynamic_policy_invocation_event_all_of_t
 *
 * Creates a new data_collection_lnode_t object containing the @a dynamic_policy_invocation_event_all_of object.
 * The @a dynamic_policy_invocation_event_all_of will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param dynamic_policy_invocation_event_all_of The DynamicPolicyInvocationEvent_allOf object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a dynamic_policy_invocation_event_all_of
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dynamic_policy_invocation_event_all_of_make_lnode(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DYNAMIC_POLICY_INVOCATION_EVENT_ALL_OF_H_ */

