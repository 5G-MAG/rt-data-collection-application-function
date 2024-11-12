#ifndef _DATA_COLLECTION_DYNAMIC_POLICY_H_
#define _DATA_COLLECTION_DYNAMIC_POLICY_H_

/**********************************************************************************************************************************
 * DynamicPolicy - Public C interface to the DynamicPolicy object
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

#include "ApplicationFlowDescription.h"
#include "MediaType.h"
#include "ClientQosSpecification.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DynamicPolicy object reference
 */
typedef struct data_collection_model_dynamic_policy_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_dynamic_policy_t;



/** Create a new DynamicPolicy
 * \public \memberof data_collection_model_dynamic_policy_t
 * @return a new DynamicPolicy object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create();

/** Create a new copy of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 * Creates a new copy of the given @a other object
 * @param other The DynamicPolicy to copy.
 * @return a new DynamicPolicy object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create_copy(const data_collection_model_dynamic_policy_t *other);

/** Create a new reference of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DynamicPolicy to create a new reference to.
 * @return a new DynamicPolicy object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create_move(data_collection_model_dynamic_policy_t *other);

/** Copy the value of another DynamicPolicy into this object
 * \public \memberof data_collection_model_dynamic_policy_t
 * Copies the value of @a other {{classname} object into @a dynamic_policy.
 * @param dynamic_policy The DynamicPolicy object to copy @a other into.
 * @param other The DynamicPolicy to copy the value from.
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_copy(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_dynamic_policy_t *other);

/** Move the value of another DynamicPolicy into this object
 * \public \memberof data_collection_model_dynamic_policy_t
 * Discards the current value of @a dynamic_policy and moves the value of @a other
 * into @a dynamic_policy. This will leave @a other as an empty reference.
 *
 * @param dynamic_policy The DynamicPolicy object to move @a other into.
 * @param other The DynamicPolicy to move the value from.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_move(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_dynamic_policy_t *other);

/** Delete a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 * Destroys the reference to the DynamicPolicy object and frees the value of DynamicPolicy if this is the last reference.
 *
 * @param dynamic_policy The DynamicPolicy to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dynamic_policy_free(data_collection_model_dynamic_policy_t *dynamic_policy);

/** Get a cJSON tree representation of a DynamicPolicy
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * Create a cJSON tree representation of the DynamicPolicy object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param dynamic_policy The DynamicPolicy to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dynamic_policy_toJSON(const data_collection_model_dynamic_policy_t *dynamic_policy, bool as_request);

/** Parse a cJSON tree into a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * Attempts to interpret a cJSON tree as a DynamicPolicy API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DynamicPolicy object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DynamicPolicy object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DynamicPolicy objects to see if they are equivalent
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param dynamic_policy The first DynamicPolicy object to compare.
 * @param other_dynamic_policy The second DynamicPolicy object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_is_equal_to(const data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_dynamic_policy_t *other_dynamic_policy);



/** Get the value of the dynamicPolicyId field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the dynamicPolicyId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_dynamic_policy_id(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the dynamicPolicyId field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_dynamic_policy_id The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_dynamic_policy_id(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_dynamic_policy_id);

/** Move a value to the dynamicPolicyId field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_dynamic_policy_id The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_dynamic_policy_id_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_dynamic_policy_id);


/** Get the value of the policyTemplateId field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the policyTemplateId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_policy_template_id(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the policyTemplateId field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_policy_template_id The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_policy_template_id(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_policy_template_id);

/** Move a value to the policyTemplateId field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_policy_template_id The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_policy_template_id_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_policy_template_id);


/** Get the value of the serviceDataFlowDescriptions field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the serviceDataFlowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dynamic_policy_get_service_data_flow_descriptions(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the serviceDataFlowDescriptions field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_service_data_flow_descriptions The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy, const ogs_list_t* p_service_data_flow_descriptions);

/** Move a value to the serviceDataFlowDescriptions field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_service_data_flow_descriptions The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_service_data_flow_descriptions_move(data_collection_model_dynamic_policy_t *dynamic_policy, ogs_list_t* p_service_data_flow_descriptions);

/** Add a new item to the serviceDataFlowDescriptions array in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to add the array item to.
 * @param service_data_flow_descriptions The value to add.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_add_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_application_flow_description_t* service_data_flow_descriptions);

/** Remove an item from the serviceDataFlowDescriptions array in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to remove the array value from.
 * @param service_data_flow_descriptions The value to remove.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_remove_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_application_flow_description_t* service_data_flow_descriptions);

/** Get an item from the serviceDataFlowDescriptions array in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_dynamic_policy_get_entry_service_data_flow_descriptions(const data_collection_model_dynamic_policy_t *dynamic_policy, size_t idx);

/** Remove all entries from the serviceDataFlowDescriptions array in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to empty serviceDataFlowDescriptions for.
 *
 * @return @a dynamic_policy
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_clear_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *dynamic_policy);

/** Check if the mediaType field of a DynamicPolicy object is set
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return `true` if the optional mediaType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_media_type(const data_collection_model_dynamic_policy_t *dynamic_policy);


/** Get the value of the mediaType field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the mediaType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_type_t* data_collection_model_dynamic_policy_get_media_type(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the mediaType field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_media_type The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_media_type(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_media_type_t* p_media_type);

/** Move a value to the mediaType field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_media_type The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_media_type_move(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_media_type_t* p_media_type);


/** Get the value of the provisioningSessionId field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the provisioningSessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_provisioning_session_id(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the provisioningSessionId field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_provisioning_session_id The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_provisioning_session_id(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_provisioning_session_id);

/** Move a value to the provisioningSessionId field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_provisioning_session_id The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_provisioning_session_id_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_provisioning_session_id);

/** Check if the qosSpecification field of a DynamicPolicy object is set
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return `true` if the optional qosSpecification field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_qos_specification(const data_collection_model_dynamic_policy_t *dynamic_policy);


/** Get the value of the qosSpecification field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the qosSpecification field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_client_qos_specification_t* data_collection_model_dynamic_policy_get_qos_specification(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the qosSpecification field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_qos_specification The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_qos_specification(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_client_qos_specification_t* p_qos_specification);

/** Move a value to the qosSpecification field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_qos_specification The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_qos_specification_move(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_client_qos_specification_t* p_qos_specification);

/** Check if the enforcementMethod field of a DynamicPolicy object is set
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return `true` if the optional enforcementMethod field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_enforcement_method(const data_collection_model_dynamic_policy_t *dynamic_policy);


/** Get the value of the enforcementMethod field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the enforcementMethod field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_enforcement_method(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the enforcementMethod field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_enforcement_method The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_method(data_collection_model_dynamic_policy_t *dynamic_policy, const char* p_enforcement_method);

/** Move a value to the enforcementMethod field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_enforcement_method The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_method_move(data_collection_model_dynamic_policy_t *dynamic_policy, char* p_enforcement_method);

/** Check if the enforcementBitRate field of a DynamicPolicy object is set
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return `true` if the optional enforcementBitRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_enforcement_bit_rate(const data_collection_model_dynamic_policy_t *dynamic_policy);


/** Get the value of the enforcementBitRate field of a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to examine.
 *
 * @return the value current set for the enforcementBitRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_dynamic_policy_get_enforcement_bit_rate(const data_collection_model_dynamic_policy_t *dynamic_policy);

/** Set the value of the enforcementBitRate field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_enforcement_bit_rate The value to copy into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_bit_rate(data_collection_model_dynamic_policy_t *dynamic_policy, const int32_t p_enforcement_bit_rate);

/** Move a value to the enforcementBitRate field in a DynamicPolicy object
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * @param dynamic_policy The DynamicPolicy object to set the field in.
 * @param p_enforcement_bit_rate The value to move into the DynamicPolicy object.
 *
 * @return @a dynamic_policy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_bit_rate_move(data_collection_model_dynamic_policy_t *dynamic_policy, int32_t p_enforcement_bit_rate);

/** lnode helper for generating ogs_list_t nodes's of type DynamicPolicy
 * \public \memberof data_collection_model_dynamic_policy_t
 *
 * Creates a new data_collection_lnode_t object containing the @a dynamic_policy object.
 * The @a dynamic_policy will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param dynamic_policy The DynamicPolicy object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a dynamic_policy
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dynamic_policy_make_lnode(data_collection_model_dynamic_policy_t *dynamic_policy);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DYNAMIC_POLICY_H_ */

