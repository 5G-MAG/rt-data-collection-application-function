#ifndef _DATA_COLLECTION_DATA_REPORTING_PROVISIONING_SESSION_H_
#define _DATA_COLLECTION_DATA_REPORTING_PROVISIONING_SESSION_H_

/**********************************************************************************************************************************
 * DataReportingProvisioningSession - Public C interface to the DataReportingProvisioningSession object
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

#include "AfEvent.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataReportingProvisioningSession object reference
 */
typedef struct data_collection_model_data_reporting_provisioning_session_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_reporting_provisioning_session_t;



/** Create a new DataReportingProvisioningSession.
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 * @return a new DataReportingProvisioningSession object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create();

/** Create a new DataReportingProvisioningSession reference.
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The DataReportingProvisioningSession to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create_ref(const data_collection_model_data_reporting_provisioning_session_t *other);

/** Create a new copy of a DataReportingProvisioningSession object.
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 * Creates a new copy of the given @a other object
 * @param other The DataReportingProvisioningSession to copy.
 * @return a new DataReportingProvisioningSession object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create_copy(const data_collection_model_data_reporting_provisioning_session_t *other);

/** Create a new reference of a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataReportingProvisioningSession to create a new reference to.
 * @return a new DataReportingProvisioningSession object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create_move(data_collection_model_data_reporting_provisioning_session_t *other);

/** Copy the value of another DataReportingProvisioningSession into this object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 * Copies the value of @a other {{classname} object into @a data_reporting_provisioning_session.
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to copy @a other into.
 * @param other The DataReportingProvisioningSession to copy the value from.
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_copy(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const data_collection_model_data_reporting_provisioning_session_t *other);

/** Move the value of another DataReportingProvisioningSession into this object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 * Discards the current value of @a data_reporting_provisioning_session and moves the value of @a other
 * into @a data_reporting_provisioning_session. This will leave @a other as an empty reference.
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to move @a other into.
 * @param other The DataReportingProvisioningSession to move the value from.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, data_collection_model_data_reporting_provisioning_session_t *other);

/** Delete a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 * Destroys the reference to the DataReportingProvisioningSession object and frees the value of DataReportingProvisioningSession if this is the last reference.
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_provisioning_session_free(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** Get a cJSON tree representation of a DataReportingProvisioningSession
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * Create a cJSON tree representation of the DataReportingProvisioningSession object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_provisioning_session_toJSON(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, bool as_request);

/** Parse a cJSON tree into a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * Attempts to interpret a cJSON tree as a DataReportingProvisioningSession API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataReportingProvisioningSession object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataReportingProvisioningSession object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataReportingProvisioningSession objects to see if they are equivalent
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_reporting_provisioning_session The first DataReportingProvisioningSession object to compare.
 * @param other_data_reporting_provisioning_session The second DataReportingProvisioningSession object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_provisioning_session_is_equal_to(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const data_collection_model_data_reporting_provisioning_session_t *other_data_reporting_provisioning_session);


/** Check if the provisioningSessionId field of a DataReportingProvisioningSession object is set
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return `true` if the optional provisioningSessionId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_provisioning_session_has_provisioning_session_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);


/** Get the value of the provisioningSessionId field of a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return the value current set for the provisioningSessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_provisioning_session_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** Set the value of the provisioningSessionId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_provisioning_session_id The value to copy into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_provisioning_session_id);

/** Move a value to the provisioningSessionId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_provisioning_session_id The value to move into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_provisioning_session_id);


/** Get the value of the aspId field of a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return the value current set for the aspId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_asp_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** Set the value of the aspId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_asp_id The value to copy into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_asp_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_asp_id);

/** Move a value to the aspId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_asp_id The value to move into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_asp_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_asp_id);


/** Get the value of the externalApplicationId field of a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return the value current set for the externalApplicationId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_external_application_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** Set the value of the externalApplicationId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_external_application_id The value to copy into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_external_application_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_external_application_id);

/** Move a value to the externalApplicationId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_external_application_id The value to move into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_external_application_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_external_application_id);

/** Check if the internalApplicationId field of a DataReportingProvisioningSession object is set
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return `true` if the optional internalApplicationId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_provisioning_session_has_internal_application_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);


/** Get the value of the internalApplicationId field of a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return the value current set for the internalApplicationId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_internal_application_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** Set the value of the internalApplicationId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_internal_application_id The value to copy into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_internal_application_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_internal_application_id);

/** Move a value to the internalApplicationId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_internal_application_id The value to move into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_internal_application_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_internal_application_id);


/** Get the value of the eventId field of a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return the value current set for the eventId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_t* data_collection_model_data_reporting_provisioning_session_get_event_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** Set the value of the eventId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_event_id The value to copy into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_event_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const data_collection_model_af_event_t* p_event_id);

/** Move a value to the eventId field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_event_id The value to move into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_event_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, data_collection_model_af_event_t* p_event_id);

/** Check if the dataReportingConfigurationIds field of a DataReportingProvisioningSession object is set
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return `true` if the optional dataReportingConfigurationIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_provisioning_session_has_data_reporting_configuration_ids(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);


/** Get the value of the dataReportingConfigurationIds field of a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 *
 * @return the value current set for the dataReportingConfigurationIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_provisioning_session_get_data_reporting_configuration_ids(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** Set the value of the dataReportingConfigurationIds field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_data_reporting_configuration_ids The value to copy into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const ogs_list_t* p_data_reporting_configuration_ids);

/** Move a value to the dataReportingConfigurationIds field in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to set the field in.
 * @param p_data_reporting_configuration_ids The value to move into the DataReportingProvisioningSession object.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_data_reporting_configuration_ids_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, ogs_list_t* p_data_reporting_configuration_ids);

/** Add a new item to the dataReportingConfigurationIds array in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to add the array item to.
 * @param data_reporting_configuration_ids The value to add.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_add_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* data_reporting_configuration_ids);

/** Remove an item from the dataReportingConfigurationIds array in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to remove the array value from.
 * @param data_reporting_configuration_ids The value to remove.
 *
 * @return @a data_reporting_provisioning_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_remove_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* data_reporting_configuration_ids);

/** Get an item from the dataReportingConfigurationIds array in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_entry_data_reporting_configuration_ids(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, size_t idx);

/** Remove all entries from the dataReportingConfigurationIds array in a DataReportingProvisioningSession object
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to empty dataReportingConfigurationIds for.
 *
 * @return @a data_reporting_provisioning_session
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_clear_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/** lnode helper for generating ogs_list_t nodes's of type DataReportingProvisioningSession
 * \public \memberof data_collection_model_data_reporting_provisioning_session_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_reporting_provisioning_session object.
 * The @a data_reporting_provisioning_session will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_reporting_provisioning_session The DataReportingProvisioningSession object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_reporting_provisioning_session
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_provisioning_session_make_lnode(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_PROVISIONING_SESSION_H_ */

