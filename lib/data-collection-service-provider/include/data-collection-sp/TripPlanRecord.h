#ifndef _DATA_COLLECTION_TRIP_PLAN_RECORD_H_
#define _DATA_COLLECTION_TRIP_PLAN_RECORD_H_

/**********************************************************************************************************************************
 * TripPlanRecord - Public C interface to the TripPlanRecord object
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

#include "LocationData.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP TripPlanRecord object reference
 */
typedef struct data_collection_model_trip_plan_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_trip_plan_record_t;



/** Create a new TripPlanRecord
 * \public \memberof data_collection_model_trip_plan_record_t
 * @return a new TripPlanRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create();

/** Create a new copy of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 * Creates a new copy of the given @a other object
 * @param other The TripPlanRecord to copy.
 * @return a new TripPlanRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_copy(const data_collection_model_trip_plan_record_t *other);

/** Create a new reference of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 * Creates a reference to the same underlying @a other object.
 * @param other The TripPlanRecord to create a new reference to.
 * @return a new TripPlanRecord object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_move(data_collection_model_trip_plan_record_t *other);

/** Copy the value of another TripPlanRecord into this object
 * \public \memberof data_collection_model_trip_plan_record_t
 * Copies the value of @a other {{classname} object into @a trip_plan_record.
 * @param trip_plan_record The TripPlanRecord object to copy @a other into.
 * @param other The TripPlanRecord to copy the value from.
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_copy(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_trip_plan_record_t *other);

/** Move the value of another TripPlanRecord into this object
 * \public \memberof data_collection_model_trip_plan_record_t
 * Discards the current value of @a trip_plan_record and moves the value of @a other
 * into @a trip_plan_record. This will leave @a other as an empty reference.
 *
 * @param trip_plan_record The TripPlanRecord object to move @a other into.
 * @param other The TripPlanRecord to move the value from.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_trip_plan_record_t *other);

/** Delete a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 * Destroys the reference to the TripPlanRecord object and frees the value of TripPlanRecord if this is the last reference.
 *
 * @param trip_plan_record The TripPlanRecord to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_trip_plan_record_free(data_collection_model_trip_plan_record_t *trip_plan_record);

/** Get a cJSON tree representation of a TripPlanRecord
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * Create a cJSON tree representation of the TripPlanRecord object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param trip_plan_record The TripPlanRecord to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_trip_plan_record_toJSON(const data_collection_model_trip_plan_record_t *trip_plan_record, bool as_request);

/** Parse a cJSON tree into a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * Attempts to interpret a cJSON tree as a TripPlanRecord API request or response (dependent on @a as_request value). If successful
 * will return a new referenced TripPlanRecord object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new TripPlanRecord object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two TripPlanRecord objects to see if they are equivalent
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param trip_plan_record The first TripPlanRecord object to compare.
 * @param other_trip_plan_record The second TripPlanRecord object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_is_equal_to(const data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_trip_plan_record_t *other_trip_plan_record);



/** Get the value of the timestamp field of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return the value current set for the timestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_get_timestamp(const data_collection_model_trip_plan_record_t *trip_plan_record);

/** Set the value of the timestamp field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_timestamp The value to copy into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp(data_collection_model_trip_plan_record_t *trip_plan_record, const char* p_timestamp);

/** Move a value to the timestamp field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_timestamp The value to move into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp_move(data_collection_model_trip_plan_record_t *trip_plan_record, char* p_timestamp);


/** Get the value of the contextIds field of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_trip_plan_record_get_context_ids(const data_collection_model_trip_plan_record_t *trip_plan_record);

/** Set the value of the contextIds field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_context_ids The value to copy into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_context_ids The value to move into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids_move(data_collection_model_trip_plan_record_t *trip_plan_record, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record, char* context_ids);

/** Remove an item from the contextIds array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record, const char* context_ids);

/** Get an item from the contextIds array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_get_entry_context_ids(const data_collection_model_trip_plan_record_t *trip_plan_record, size_t idx);

/** Remove all entries from the contextIds array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to empty contextIds for.
 *
 * @return @a trip_plan_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_context_ids(data_collection_model_trip_plan_record_t *trip_plan_record);


/** Get the value of the startingPoint field of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return the value current set for the startingPoint field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_starting_point(const data_collection_model_trip_plan_record_t *trip_plan_record);

/** Set the value of the startingPoint field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_starting_point The value to copy into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_location_data_t* p_starting_point);

/** Move a value to the startingPoint field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_starting_point The value to move into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_location_data_t* p_starting_point);

/** Check if the waypoints field of a TripPlanRecord object is set
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return `true` if the optional waypoints field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_has_waypoints(const data_collection_model_trip_plan_record_t *trip_plan_record);


/** Get the value of the waypoints field of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return the value current set for the waypoints field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_trip_plan_record_get_waypoints(const data_collection_model_trip_plan_record_t *trip_plan_record);

/** Set the value of the waypoints field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_waypoints The value to copy into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record, const ogs_list_t* p_waypoints);

/** Move a value to the waypoints field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_waypoints The value to move into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints_move(data_collection_model_trip_plan_record_t *trip_plan_record, ogs_list_t* p_waypoints);

/** Add a new item to the waypoints array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to add the array item to.
 * @param waypoints The value to add.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_location_data_t* waypoints);

/** Remove an item from the waypoints array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to remove the array value from.
 * @param waypoints The value to remove.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_location_data_t* waypoints);

/** Get an item from the waypoints array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_entry_waypoints(const data_collection_model_trip_plan_record_t *trip_plan_record, size_t idx);

/** Remove all entries from the waypoints array in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to empty waypoints for.
 *
 * @return @a trip_plan_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_waypoints(data_collection_model_trip_plan_record_t *trip_plan_record);


/** Get the value of the destination field of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return the value current set for the destination field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_destination(const data_collection_model_trip_plan_record_t *trip_plan_record);

/** Set the value of the destination field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_destination The value to copy into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_location_data_t* p_destination);

/** Move a value to the destination field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_destination The value to move into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_location_data_t* p_destination);

/** Check if the estimatedAverageSpeed field of a TripPlanRecord object is set
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return `true` if the optional estimatedAverageSpeed field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_has_estimated_average_speed(const data_collection_model_trip_plan_record_t *trip_plan_record);


/** Get the value of the estimatedAverageSpeed field of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return the value current set for the estimatedAverageSpeed field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_trip_plan_record_get_estimated_average_speed(const data_collection_model_trip_plan_record_t *trip_plan_record);

/** Set the value of the estimatedAverageSpeed field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_estimated_average_speed The value to copy into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed(data_collection_model_trip_plan_record_t *trip_plan_record, const float p_estimated_average_speed);

/** Move a value to the estimatedAverageSpeed field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_estimated_average_speed The value to move into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed_move(data_collection_model_trip_plan_record_t *trip_plan_record, float p_estimated_average_speed);

/** Check if the estimatedArrivalTime field of a TripPlanRecord object is set
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return `true` if the optional estimatedArrivalTime field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_has_estimated_arrival_time(const data_collection_model_trip_plan_record_t *trip_plan_record);


/** Get the value of the estimatedArrivalTime field of a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to examine.
 *
 * @return the value current set for the estimatedArrivalTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_get_estimated_arrival_time(const data_collection_model_trip_plan_record_t *trip_plan_record);

/** Set the value of the estimatedArrivalTime field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_estimated_arrival_time The value to copy into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time(data_collection_model_trip_plan_record_t *trip_plan_record, const char* p_estimated_arrival_time);

/** Move a value to the estimatedArrivalTime field in a TripPlanRecord object
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * @param trip_plan_record The TripPlanRecord object to set the field in.
 * @param p_estimated_arrival_time The value to move into the TripPlanRecord object.
 *
 * @return @a trip_plan_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time_move(data_collection_model_trip_plan_record_t *trip_plan_record, char* p_estimated_arrival_time);

/** lnode helper for generating ogs_list_t nodes's of type TripPlanRecord
 * \public \memberof data_collection_model_trip_plan_record_t
 *
 * Creates a new data_collection_lnode_t object containing the @a trip_plan_record object.
 * The @a trip_plan_record will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param trip_plan_record The TripPlanRecord object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a trip_plan_record
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_trip_plan_record_make_lnode(data_collection_model_trip_plan_record_t *trip_plan_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TRIP_PLAN_RECORD_H_ */

