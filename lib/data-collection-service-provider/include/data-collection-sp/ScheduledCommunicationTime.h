#ifndef _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TIME_H_
#define _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TIME_H_

/**********************************************************************************************************************************
 * ScheduledCommunicationTime - Public C interface to the ScheduledCommunicationTime object
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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ScheduledCommunicationTime object reference
 */
typedef struct data_collection_model_scheduled_communication_time_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_scheduled_communication_time_t;



/** Create a new ScheduledCommunicationTime
 * \public \memberof data_collection_model_scheduled_communication_time_t
 * @return a new ScheduledCommunicationTime object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create();

/** Create a new copy of a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 * Creates a new copy of the given @a other object
 * @param other The ScheduledCommunicationTime to copy.
 * @return a new ScheduledCommunicationTime object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_copy(const data_collection_model_scheduled_communication_time_t *other);

/** Create a new reference of a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ScheduledCommunicationTime to create a new reference to.
 * @return a new ScheduledCommunicationTime object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_move(data_collection_model_scheduled_communication_time_t *other);

/** Copy the value of another ScheduledCommunicationTime into this object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 * Copies the value of @a other {{classname} object into @a scheduled_communication_time.
 * @param scheduled_communication_time The ScheduledCommunicationTime object to copy @a other into.
 * @param other The ScheduledCommunicationTime to copy the value from.
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_copy(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const data_collection_model_scheduled_communication_time_t *other);

/** Move the value of another ScheduledCommunicationTime into this object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 * Discards the current value of @a scheduled_communication_time and moves the value of @a other
 * into @a scheduled_communication_time. This will leave @a other as an empty reference.
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to move @a other into.
 * @param other The ScheduledCommunicationTime to move the value from.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, data_collection_model_scheduled_communication_time_t *other);

/** Delete a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 * Destroys the reference to the ScheduledCommunicationTime object and frees the value of ScheduledCommunicationTime if this is the last reference.
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_scheduled_communication_time_free(data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

/** Get a cJSON tree representation of a ScheduledCommunicationTime
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * Create a cJSON tree representation of the ScheduledCommunicationTime object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_scheduled_communication_time_toJSON(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time, bool as_request);

/** Parse a cJSON tree into a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * Attempts to interpret a cJSON tree as a ScheduledCommunicationTime API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ScheduledCommunicationTime object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ScheduledCommunicationTime object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ScheduledCommunicationTime objects to see if they are equivalent
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param scheduled_communication_time The first ScheduledCommunicationTime object to compare.
 * @param other_scheduled_communication_time The second ScheduledCommunicationTime object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_is_equal_to(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const data_collection_model_scheduled_communication_time_t *other_scheduled_communication_time);


/** Check if the daysOfWeek field of a ScheduledCommunicationTime object is set
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to examine.
 *
 * @return `true` if the optional daysOfWeek field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_days_of_week(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);


/** Get the value of the daysOfWeek field of a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to examine.
 *
 * @return the value current set for the daysOfWeek field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_scheduled_communication_time_get_days_of_week(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

/** Set the value of the daysOfWeek field in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to set the field in.
 * @param p_days_of_week The value to copy into the ScheduledCommunicationTime object.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const ogs_list_t* p_days_of_week);

/** Move a value to the daysOfWeek field in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to set the field in.
 * @param p_days_of_week The value to move into the ScheduledCommunicationTime object.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, ogs_list_t* p_days_of_week);

/** Add a new item to the daysOfWeek array in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to add the array item to.
 * @param days_of_week The value to add.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_add_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, int32_t days_of_week);

/** Remove an item from the daysOfWeek array in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to remove the array value from.
 * @param days_of_week The value to remove.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_remove_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const int32_t days_of_week);

/** Get an item from the daysOfWeek array in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_scheduled_communication_time_get_entry_days_of_week(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time, size_t idx);

/** Remove all entries from the daysOfWeek array in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to empty daysOfWeek for.
 *
 * @return @a scheduled_communication_time
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_clear_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

/** Check if the timeOfDayStart field of a ScheduledCommunicationTime object is set
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to examine.
 *
 * @return `true` if the optional timeOfDayStart field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_time_of_day_start(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);


/** Get the value of the timeOfDayStart field of a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to examine.
 *
 * @return the value current set for the timeOfDayStart field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_scheduled_communication_time_get_time_of_day_start(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

/** Set the value of the timeOfDayStart field in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to set the field in.
 * @param p_time_of_day_start The value to copy into the ScheduledCommunicationTime object.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const char* p_time_of_day_start);

/** Move a value to the timeOfDayStart field in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to set the field in.
 * @param p_time_of_day_start The value to move into the ScheduledCommunicationTime object.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, char* p_time_of_day_start);

/** Check if the timeOfDayEnd field of a ScheduledCommunicationTime object is set
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to examine.
 *
 * @return `true` if the optional timeOfDayEnd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_time_of_day_end(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);


/** Get the value of the timeOfDayEnd field of a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to examine.
 *
 * @return the value current set for the timeOfDayEnd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_scheduled_communication_time_get_time_of_day_end(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

/** Set the value of the timeOfDayEnd field in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to set the field in.
 * @param p_time_of_day_end The value to copy into the ScheduledCommunicationTime object.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const char* p_time_of_day_end);

/** Move a value to the timeOfDayEnd field in a ScheduledCommunicationTime object
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to set the field in.
 * @param p_time_of_day_end The value to move into the ScheduledCommunicationTime object.
 *
 * @return @a scheduled_communication_time.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, char* p_time_of_day_end);

/** lnode helper for generating ogs_list_t nodes's of type ScheduledCommunicationTime
 * \public \memberof data_collection_model_scheduled_communication_time_t
 *
 * Creates a new data_collection_lnode_t object containing the @a scheduled_communication_time object.
 * The @a scheduled_communication_time will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param scheduled_communication_time The ScheduledCommunicationTime object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a scheduled_communication_time
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_scheduled_communication_time_make_lnode(data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TIME_H_ */

