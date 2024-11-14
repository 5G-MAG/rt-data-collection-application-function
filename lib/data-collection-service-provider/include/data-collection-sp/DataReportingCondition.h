#ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_H_
#define _DATA_COLLECTION_DATA_REPORTING_CONDITION_H_

/**********************************************************************************************************************************
 * DataReportingCondition - Public C interface to the DataReportingCondition object
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

#include "DataReportingEventTrigger.h"
#include "DataReportingCondition_threshold.h"
#include "DataReportingConditionType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataReportingCondition object reference
 */
typedef struct data_collection_model_data_reporting_condition_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_reporting_condition_t;



/** Create a new DataReportingCondition.
 * \public \memberof data_collection_model_data_reporting_condition_t
 * @return a new DataReportingCondition object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create();

/** Create a new DataReportingCondition reference.
 * \public \memberof data_collection_model_data_reporting_condition_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The DataReportingCondition to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_ref(const data_collection_model_data_reporting_condition_t *other);

/** Create a new copy of a DataReportingCondition object.
 * \public \memberof data_collection_model_data_reporting_condition_t
 * Creates a new copy of the given @a other object
 * @param other The DataReportingCondition to copy.
 * @return a new DataReportingCondition object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_copy(const data_collection_model_data_reporting_condition_t *other);

/** Create a new reference of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataReportingCondition to create a new reference to.
 * @return a new DataReportingCondition object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_move(data_collection_model_data_reporting_condition_t *other);

/** Copy the value of another DataReportingCondition into this object
 * \public \memberof data_collection_model_data_reporting_condition_t
 * Copies the value of @a other {{classname} object into @a data_reporting_condition.
 * @param data_reporting_condition The DataReportingCondition object to copy @a other into.
 * @param other The DataReportingCondition to copy the value from.
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_copy(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_t *other);

/** Move the value of another DataReportingCondition into this object
 * \public \memberof data_collection_model_data_reporting_condition_t
 * Discards the current value of @a data_reporting_condition and moves the value of @a other
 * into @a data_reporting_condition. This will leave @a other as an empty reference.
 *
 * @param data_reporting_condition The DataReportingCondition object to move @a other into.
 * @param other The DataReportingCondition to move the value from.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_t *other);

/** Delete a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 * Destroys the reference to the DataReportingCondition object and frees the value of DataReportingCondition if this is the last reference.
 *
 * @param data_reporting_condition The DataReportingCondition to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_condition_free(data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Get a cJSON tree representation of a DataReportingCondition
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * Create a cJSON tree representation of the DataReportingCondition object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_reporting_condition The DataReportingCondition to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_condition_toJSON(const data_collection_model_data_reporting_condition_t *data_reporting_condition, bool as_request);

/** Parse a cJSON tree into a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * Attempts to interpret a cJSON tree as a DataReportingCondition API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataReportingCondition object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataReportingCondition object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataReportingCondition objects to see if they are equivalent
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_reporting_condition The first DataReportingCondition object to compare.
 * @param other_data_reporting_condition The second DataReportingCondition object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_is_equal_to(const data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_t *other_data_reporting_condition);


/** Check if the contextIds field of a DataReportingCondition object is set
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return `true` if the optional contextIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_context_ids(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


/** Get the value of the contextIds field of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_condition_get_context_ids(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Set the value of the contextIds field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_context_ids The value to copy into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_context_ids The value to move into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_add_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition, char* context_ids);

/** Remove an item from the contextIds array in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_remove_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition, const char* context_ids);

/** Get an item from the contextIds array in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_condition_get_entry_context_ids(const data_collection_model_data_reporting_condition_t *data_reporting_condition, size_t idx);

/** Remove all entries from the contextIds array in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to empty contextIds for.
 *
 * @return @a data_reporting_condition
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_clear_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition);


/** Get the value of the type field of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return the value current set for the type field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_type_t* data_collection_model_data_reporting_condition_get_type(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Set the value of the type field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_type The value to copy into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_type_t* p_type);

/** Move a value to the type field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_type The value to move into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_type_t* p_type);

/** Check if the period field of a DataReportingCondition object is set
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return `true` if the optional period field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_period(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


/** Get the value of the period field of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return the value current set for the period field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_data_reporting_condition_get_period(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Set the value of the period field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_period The value to copy into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period(data_collection_model_data_reporting_condition_t *data_reporting_condition, const int32_t p_period);

/** Move a value to the period field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_period The value to move into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, int32_t p_period);

/** Check if the parameter field of a DataReportingCondition object is set
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return `true` if the optional parameter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_parameter(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


/** Get the value of the parameter field of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return the value current set for the parameter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_condition_get_parameter(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Set the value of the parameter field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_parameter The value to copy into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter(data_collection_model_data_reporting_condition_t *data_reporting_condition, const char* p_parameter);

/** Move a value to the parameter field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_parameter The value to move into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, char* p_parameter);

/** Check if the threshold field of a DataReportingCondition object is set
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return `true` if the optional threshold field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_threshold(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


/** Get the value of the threshold field of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return the value current set for the threshold field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_threshold_t* data_collection_model_data_reporting_condition_get_threshold(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Set the value of the threshold field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_threshold The value to copy into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_threshold_t* p_threshold);

/** Move a value to the threshold field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_threshold The value to move into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_threshold_t* p_threshold);

/** Check if the reportWhenBelow field of a DataReportingCondition object is set
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return `true` if the optional reportWhenBelow field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_report_when_below(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


/** Get the value of the reportWhenBelow field of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return the value current set for the reportWhenBelow field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_data_reporting_condition_is_report_when_below(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Set the value of the reportWhenBelow field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_report_when_below The value to copy into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below(data_collection_model_data_reporting_condition_t *data_reporting_condition, const bool p_report_when_below);

/** Move a value to the reportWhenBelow field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_report_when_below The value to move into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, bool p_report_when_below);

/** Check if the eventTrigger field of a DataReportingCondition object is set
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return `true` if the optional eventTrigger field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_event_trigger(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


/** Get the value of the eventTrigger field of a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to examine.
 *
 * @return the value current set for the eventTrigger field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_event_trigger_t* data_collection_model_data_reporting_condition_get_event_trigger(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Set the value of the eventTrigger field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_event_trigger The value to copy into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_event_trigger_t* p_event_trigger);

/** Move a value to the eventTrigger field in a DataReportingCondition object
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * @param data_reporting_condition The DataReportingCondition object to set the field in.
 * @param p_event_trigger The value to move into the DataReportingCondition object.
 *
 * @return @a data_reporting_condition.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_event_trigger_t* p_event_trigger);

/** lnode helper for generating ogs_list_t nodes's of type DataReportingCondition
 * \public \memberof data_collection_model_data_reporting_condition_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_reporting_condition object.
 * The @a data_reporting_condition will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_reporting_condition The DataReportingCondition object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_reporting_condition
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_condition_make_lnode(data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Check if two DataReportingConditions are equal without checking the contextIds array */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_is_equal_to_sans_context_ids(const data_collection_model_data_reporting_condition_t *first, const data_collection_model_data_reporting_condition_t *second);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_H_ */

