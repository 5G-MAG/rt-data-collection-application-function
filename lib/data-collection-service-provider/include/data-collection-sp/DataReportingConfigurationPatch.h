#ifndef _DATA_COLLECTION_DATA_REPORTING_CONFIGURATION_PATCH_H_
#define _DATA_COLLECTION_DATA_REPORTING_CONFIGURATION_PATCH_H_

/**********************************************************************************************************************************
 * DataReportingConfigurationPatch - Public C interface to the DataReportingConfigurationPatch object
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

#include "DataSamplingRule.h"
#include "DataReportingRule.h"
#include "DataAccessProfile.h"
#include "DataReportingCondition.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataReportingConfigurationPatch object reference
 */
typedef struct data_collection_model_data_reporting_configuration_patch_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_reporting_configuration_patch_t;



/** Create a new DataReportingConfigurationPatch
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 * @return a new DataReportingConfigurationPatch object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create();

/** Create a new copy of a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 * Creates a new copy of the given @a other object
 * @param other The DataReportingConfigurationPatch to copy.
 * @return a new DataReportingConfigurationPatch object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create_copy(const data_collection_model_data_reporting_configuration_patch_t *other);

/** Create a new reference of a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataReportingConfigurationPatch to create a new reference to.
 * @return a new DataReportingConfigurationPatch object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create_move(data_collection_model_data_reporting_configuration_patch_t *other);

/** Copy the value of another DataReportingConfigurationPatch into this object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 * Copies the value of @a other {{classname} object into @a data_reporting_configuration_patch.
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to copy @a other into.
 * @param other The DataReportingConfigurationPatch to copy the value from.
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_copy(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_reporting_configuration_patch_t *other);

/** Move the value of another DataReportingConfigurationPatch into this object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 * Discards the current value of @a data_reporting_configuration_patch and moves the value of @a other
 * into @a data_reporting_configuration_patch. This will leave @a other as an empty reference.
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to move @a other into.
 * @param other The DataReportingConfigurationPatch to move the value from.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, data_collection_model_data_reporting_configuration_patch_t *other);

/** Delete a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 * Destroys the reference to the DataReportingConfigurationPatch object and frees the value of DataReportingConfigurationPatch if this is the last reference.
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_configuration_patch_free(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Get a cJSON tree representation of a DataReportingConfigurationPatch
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * Create a cJSON tree representation of the DataReportingConfigurationPatch object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_configuration_patch_toJSON(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, bool as_request);

/** Parse a cJSON tree into a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * Attempts to interpret a cJSON tree as a DataReportingConfigurationPatch API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataReportingConfigurationPatch object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataReportingConfigurationPatch object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataReportingConfigurationPatch objects to see if they are equivalent
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_reporting_configuration_patch The first DataReportingConfigurationPatch object to compare.
 * @param other_data_reporting_configuration_patch The second DataReportingConfigurationPatch object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_is_equal_to(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_reporting_configuration_patch_t *other_data_reporting_configuration_patch);


/** Check if the authorizationURL field of a DataReportingConfigurationPatch object is set
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return `true` if the optional authorizationURL field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_authorization_url(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);


/** Get the value of the authorizationURL field of a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return the value current set for the authorizationURL field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_configuration_patch_get_authorization_url(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Set the value of the authorizationURL field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_authorization_url The value to copy into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_authorization_url(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const char* p_authorization_url);

/** Move a value to the authorizationURL field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_authorization_url The value to move into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_authorization_url_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, char* p_authorization_url);

/** Check if the dataSamplingRules field of a DataReportingConfigurationPatch object is set
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return `true` if the optional dataSamplingRules field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_sampling_rules(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);


/** Get the value of the dataSamplingRules field of a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return the value current set for the dataSamplingRules field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_sampling_rules(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Set the value of the dataSamplingRules field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_sampling_rules The value to copy into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const ogs_list_t* p_data_sampling_rules);

/** Move a value to the dataSamplingRules field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_sampling_rules The value to move into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_sampling_rules_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, ogs_list_t* p_data_sampling_rules);

/** Add a new item to the dataSamplingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to add the array item to.
 * @param data_sampling_rules The value to add.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, data_collection_model_data_sampling_rule_t* data_sampling_rules);

/** Remove an item from the dataSamplingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to remove the array value from.
 * @param data_sampling_rules The value to remove.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_sampling_rule_t* data_sampling_rules);

/** Get an item from the dataSamplingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_sampling_rule_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_sampling_rules(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, size_t idx);

/** Remove all entries from the dataSamplingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to empty dataSamplingRules for.
 *
 * @return @a data_reporting_configuration_patch
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Check if the dataReportingConditions field of a DataReportingConfigurationPatch object is set
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return `true` if the optional dataReportingConditions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_reporting_conditions(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);


/** Get the value of the dataReportingConditions field of a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return the value current set for the dataReportingConditions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_reporting_conditions(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Set the value of the dataReportingConditions field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_reporting_conditions The value to copy into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const ogs_list_t* p_data_reporting_conditions);

/** Move a value to the dataReportingConditions field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_reporting_conditions The value to move into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_conditions_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, ogs_list_t* p_data_reporting_conditions);

/** Add a new item to the dataReportingConditions array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to add the array item to.
 * @param data_reporting_conditions The value to add.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, data_collection_model_data_reporting_condition_t* data_reporting_conditions);

/** Remove an item from the dataReportingConditions array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to remove the array value from.
 * @param data_reporting_conditions The value to remove.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_reporting_condition_t* data_reporting_conditions);

/** Get an item from the dataReportingConditions array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_reporting_conditions(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, size_t idx);

/** Remove all entries from the dataReportingConditions array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to empty dataReportingConditions for.
 *
 * @return @a data_reporting_configuration_patch
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Check if the dataReportingRules field of a DataReportingConfigurationPatch object is set
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return `true` if the optional dataReportingRules field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_reporting_rules(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);


/** Get the value of the dataReportingRules field of a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return the value current set for the dataReportingRules field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_reporting_rules(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Set the value of the dataReportingRules field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_reporting_rules The value to copy into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const ogs_list_t* p_data_reporting_rules);

/** Move a value to the dataReportingRules field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_reporting_rules The value to move into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_rules_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, ogs_list_t* p_data_reporting_rules);

/** Add a new item to the dataReportingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to add the array item to.
 * @param data_reporting_rules The value to add.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, data_collection_model_data_reporting_rule_t* data_reporting_rules);

/** Remove an item from the dataReportingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to remove the array value from.
 * @param data_reporting_rules The value to remove.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_reporting_rule_t* data_reporting_rules);

/** Get an item from the dataReportingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_rule_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_reporting_rules(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, size_t idx);

/** Remove all entries from the dataReportingRules array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to empty dataReportingRules for.
 *
 * @return @a data_reporting_configuration_patch
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Check if the dataAccessProfiles field of a DataReportingConfigurationPatch object is set
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return `true` if the optional dataAccessProfiles field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_access_profiles(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);


/** Get the value of the dataAccessProfiles field of a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 *
 * @return the value current set for the dataAccessProfiles field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_access_profiles(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** Set the value of the dataAccessProfiles field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_access_profiles The value to copy into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const ogs_list_t* p_data_access_profiles);

/** Move a value to the dataAccessProfiles field in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to set the field in.
 * @param p_data_access_profiles The value to move into the DataReportingConfigurationPatch object.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_access_profiles_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, ogs_list_t* p_data_access_profiles);

/** Add a new item to the dataAccessProfiles array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to add the array item to.
 * @param data_access_profiles The value to add.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, data_collection_model_data_access_profile_t* data_access_profiles);

/** Remove an item from the dataAccessProfiles array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to remove the array value from.
 * @param data_access_profiles The value to remove.
 *
 * @return @a data_reporting_configuration_patch.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_access_profile_t* data_access_profiles);

/** Get an item from the dataAccessProfiles array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_access_profiles(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, size_t idx);

/** Remove all entries from the dataAccessProfiles array in a DataReportingConfigurationPatch object
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to empty dataAccessProfiles for.
 *
 * @return @a data_reporting_configuration_patch
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/** lnode helper for generating ogs_list_t nodes's of type DataReportingConfigurationPatch
 * \public \memberof data_collection_model_data_reporting_configuration_patch_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_reporting_configuration_patch object.
 * The @a data_reporting_configuration_patch will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_reporting_configuration_patch The DataReportingConfigurationPatch object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_reporting_configuration_patch
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_configuration_patch_make_lnode(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_CONFIGURATION_PATCH_H_ */

