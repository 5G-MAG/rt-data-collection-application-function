#ifndef _DATA_COLLECTION_DATA_REPORTING_SESSION_H_
#define _DATA_COLLECTION_DATA_REPORTING_SESSION_H_

/**********************************************************************************************************************************
 * DataReportingSession - Public C interface to the DataReportingSession object
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

#include "DataDomain.h"
#include "DataSamplingRule.h"
#include "DataReportingRule.h"
#include "DataReportingCondition.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataReportingSession object reference
 */
typedef struct data_collection_model_data_reporting_session_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_reporting_session_t;



/** Create a new DataReportingSession
 * \public \memberof data_collection_model_data_reporting_session_t
 * @return a new DataReportingSession object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create();

/** Create a new copy of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 * Creates a new copy of the given @a other object
 * @param other The DataReportingSession to copy.
 * @return a new DataReportingSession object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_copy(const data_collection_model_data_reporting_session_t *other);

/** Create a new reference of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataReportingSession to create a new reference to.
 * @return a new DataReportingSession object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_move(data_collection_model_data_reporting_session_t *other);

/** Copy the value of another DataReportingSession into this object
 * \public \memberof data_collection_model_data_reporting_session_t
 * Copies the value of @a other {{classname} object into @a data_reporting_session.
 * @param data_reporting_session The DataReportingSession object to copy @a other into.
 * @param other The DataReportingSession to copy the value from.
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_copy(data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_reporting_session_t *other);

/** Move the value of another DataReportingSession into this object
 * \public \memberof data_collection_model_data_reporting_session_t
 * Discards the current value of @a data_reporting_session and moves the value of @a other
 * into @a data_reporting_session. This will leave @a other as an empty reference.
 *
 * @param data_reporting_session The DataReportingSession object to move @a other into.
 * @param other The DataReportingSession to move the value from.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_move(data_collection_model_data_reporting_session_t *data_reporting_session, data_collection_model_data_reporting_session_t *other);

/** Delete a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 * Destroys the reference to the DataReportingSession object and frees the value of DataReportingSession if this is the last reference.
 *
 * @param data_reporting_session The DataReportingSession to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_session_free(data_collection_model_data_reporting_session_t *data_reporting_session);

/** Get a cJSON tree representation of a DataReportingSession
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * Create a cJSON tree representation of the DataReportingSession object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_reporting_session The DataReportingSession to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_session_toJSON(const data_collection_model_data_reporting_session_t *data_reporting_session, bool as_request);

/** Parse a cJSON tree into a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * Attempts to interpret a cJSON tree as a DataReportingSession API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataReportingSession object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataReportingSession object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataReportingSession objects to see if they are equivalent
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_reporting_session The first DataReportingSession object to compare.
 * @param other_data_reporting_session The second DataReportingSession object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_is_equal_to(const data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_reporting_session_t *other_data_reporting_session);


/** Check if the sessionId field of a DataReportingSession object is set
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return `true` if the optional sessionId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_session_id(const data_collection_model_data_reporting_session_t *data_reporting_session);


/** Get the value of the sessionId field of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return the value current set for the sessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_session_id(const data_collection_model_data_reporting_session_t *data_reporting_session);

/** Set the value of the sessionId field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_session_id The value to copy into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id(data_collection_model_data_reporting_session_t *data_reporting_session, const char* p_session_id);

/** Move a value to the sessionId field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_session_id The value to move into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id_move(data_collection_model_data_reporting_session_t *data_reporting_session, char* p_session_id);

/** Check if the validUntil field of a DataReportingSession object is set
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return `true` if the optional validUntil field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_valid_until(const data_collection_model_data_reporting_session_t *data_reporting_session);


/** Get the value of the validUntil field of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return the value current set for the validUntil field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_valid_until(const data_collection_model_data_reporting_session_t *data_reporting_session);

/** Set the value of the validUntil field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_valid_until The value to copy into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until(data_collection_model_data_reporting_session_t *data_reporting_session, const char* p_valid_until);

/** Move a value to the validUntil field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_valid_until The value to move into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until_move(data_collection_model_data_reporting_session_t *data_reporting_session, char* p_valid_until);


/** Get the value of the externalApplicationId field of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return the value current set for the externalApplicationId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_external_application_id(const data_collection_model_data_reporting_session_t *data_reporting_session);

/** Set the value of the externalApplicationId field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_external_application_id The value to copy into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id(data_collection_model_data_reporting_session_t *data_reporting_session, const char* p_external_application_id);

/** Move a value to the externalApplicationId field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_external_application_id The value to move into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id_move(data_collection_model_data_reporting_session_t *data_reporting_session, char* p_external_application_id);


/** Get the value of the supportedDomains field of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return the value current set for the supportedDomains field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_supported_domains(const data_collection_model_data_reporting_session_t *data_reporting_session);

/** Set the value of the supportedDomains field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_supported_domains The value to copy into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_list_t* p_supported_domains);

/** Move a value to the supportedDomains field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_supported_domains The value to move into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t* p_supported_domains);

/** Add a new item to the supportedDomains array in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to add the array item to.
 * @param supported_domains The value to add.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session, data_collection_model_data_domain_t* supported_domains);

/** Remove an item from the supportedDomains array in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to remove the array value from.
 * @param supported_domains The value to remove.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_domain_t* supported_domains);

/** Get an item from the supportedDomains array in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_domain_t* data_collection_model_data_reporting_session_get_entry_supported_domains(const data_collection_model_data_reporting_session_t *data_reporting_session, size_t idx);

/** Remove all entries from the supportedDomains array in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to empty supportedDomains for.
 *
 * @return @a data_reporting_session
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session);

/** Check if the samplingRules field of a DataReportingSession object is set
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return `true` if the optional samplingRules field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_sampling_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);


/** Get the value of the samplingRules field of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return the value current set for the samplingRules field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_hash_t* data_collection_model_data_reporting_session_get_sampling_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);

/** Set the value of the samplingRules field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_sampling_rules The value to copy into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_hash_t* p_sampling_rules);

/** Move a value to the samplingRules field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_sampling_rules The value to move into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t* p_sampling_rules);

/** Add a new item to the samplingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to add the map object item to.
 * @param key The object key name to map the @a sampling_rules value to.
 * @param sampling_rules The value to add.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session,  const char *key, const ogs_list_t* sampling_rules);

/** Remove an item from the samplingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to remove the map object value from.
 * @param key The map key name to remove.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

/** Get an item from the samplingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine. 
 * @param key The map key name of the value to retrieve.
 *
 * @return The value found at the @a key entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_entry_sampling_rules(const data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

/** Remove all entries from the samplingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to empty samplingRules for.
 *
 * @return @a data_reporting_session
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session);

/** Check if the reportingConditions field of a DataReportingSession object is set
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return `true` if the optional reportingConditions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_reporting_conditions(const data_collection_model_data_reporting_session_t *data_reporting_session);


/** Get the value of the reportingConditions field of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return the value current set for the reportingConditions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_conditions(const data_collection_model_data_reporting_session_t *data_reporting_session);

/** Set the value of the reportingConditions field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_reporting_conditions The value to copy into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_hash_t* p_reporting_conditions);

/** Move a value to the reportingConditions field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_reporting_conditions The value to move into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t* p_reporting_conditions);

/** Add a new item to the reportingConditions map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to add the map object item to.
 * @param key The object key name to map the @a reporting_conditions value to.
 * @param reporting_conditions The value to add.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session,  const char *key, const ogs_list_t* reporting_conditions);

/** Remove an item from the reportingConditions map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to remove the map object value from.
 * @param key The map key name to remove.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

/** Get an item from the reportingConditions map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine. 
 * @param key The map key name of the value to retrieve.
 *
 * @return The value found at the @a key entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_entry_reporting_conditions(const data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

/** Remove all entries from the reportingConditions map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to empty reportingConditions for.
 *
 * @return @a data_reporting_session
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session);

/** Check if the reportingRules field of a DataReportingSession object is set
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return `true` if the optional reportingRules field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_reporting_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);


/** Get the value of the reportingRules field of a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine.
 *
 * @return the value current set for the reportingRules field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);

/** Set the value of the reportingRules field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_reporting_rules The value to copy into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_hash_t* p_reporting_rules);

/** Move a value to the reportingRules field in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to set the field in.
 * @param p_reporting_rules The value to move into the DataReportingSession object.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t* p_reporting_rules);

/** Add a new item to the reportingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to add the map object item to.
 * @param key The object key name to map the @a reporting_rules value to.
 * @param reporting_rules The value to add.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session,  const char *key, const ogs_list_t* reporting_rules);

/** Remove an item from the reportingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to remove the map object value from.
 * @param key The map key name to remove.
 *
 * @return @a data_reporting_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

/** Get an item from the reportingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to examine. 
 * @param key The map key name of the value to retrieve.
 *
 * @return The value found at the @a key entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_entry_reporting_rules(const data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

/** Remove all entries from the reportingRules map object in a DataReportingSession object
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * @param data_reporting_session The DataReportingSession object to empty reportingRules for.
 *
 * @return @a data_reporting_session
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session);

/** lnode helper for generating ogs_list_t nodes's of type DataReportingSession
 * \public \memberof data_collection_model_data_reporting_session_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_reporting_session object.
 * The @a data_reporting_session will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_reporting_session The DataReportingSession object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_reporting_session
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_session_make_lnode(data_collection_model_data_reporting_session_t *data_reporting_session);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_SESSION_H_ */

