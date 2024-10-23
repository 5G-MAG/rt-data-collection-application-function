#ifndef _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_H_
#define _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_H_

/**********************************************************************************************************************************
 * PerformanceDataRecord - Public C interface to the PerformanceDataRecord object
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

#include "AddrFqdn.h"
#include "TimeWindow.h"
#include "LocationArea5G.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PerformanceDataRecord object reference
 */
typedef struct data_collection_model_performance_data_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_performance_data_record_t;



/** Create a new PerformanceDataRecord
 * \public \memberof data_collection_model_performance_data_record_t
 * @return a new PerformanceDataRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create();

/** Create a new copy of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 * Creates a new copy of the given @a other object
 * @param other The PerformanceDataRecord to copy.
 * @return a new PerformanceDataRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_copy(const data_collection_model_performance_data_record_t *other);

/** Create a new reference of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PerformanceDataRecord to create a new reference to.
 * @return a new PerformanceDataRecord object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_move(data_collection_model_performance_data_record_t *other);

/** Copy the value of another PerformanceDataRecord into this object
 * \public \memberof data_collection_model_performance_data_record_t
 * Copies the value of @a other {{classname} object into @a performance_data_record.
 * @param performance_data_record The PerformanceDataRecord object to copy @a other into.
 * @param other The PerformanceDataRecord to copy the value from.
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_copy(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_performance_data_record_t *other);

/** Move the value of another PerformanceDataRecord into this object
 * \public \memberof data_collection_model_performance_data_record_t
 * Discards the current value of @a performance_data_record and moves the value of @a other
 * into @a performance_data_record. This will leave @a other as an empty reference.
 *
 * @param performance_data_record The PerformanceDataRecord object to move @a other into.
 * @param other The PerformanceDataRecord to move the value from.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_performance_data_record_t *other);

/** Delete a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 * Destroys the reference to the PerformanceDataRecord object and frees the value of PerformanceDataRecord if this is the last reference.
 *
 * @param performance_data_record The PerformanceDataRecord to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_record_free(data_collection_model_performance_data_record_t *performance_data_record);

/** Get a cJSON tree representation of a PerformanceDataRecord
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * Create a cJSON tree representation of the PerformanceDataRecord object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param performance_data_record The PerformanceDataRecord to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_record_toJSON(const data_collection_model_performance_data_record_t *performance_data_record, bool as_request);

/** Parse a cJSON tree into a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * Attempts to interpret a cJSON tree as a PerformanceDataRecord API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PerformanceDataRecord object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PerformanceDataRecord object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PerformanceDataRecord objects to see if they are equivalent
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param performance_data_record The first PerformanceDataRecord object to compare.
 * @param other_performance_data_record The second PerformanceDataRecord object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_is_equal_to(const data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_performance_data_record_t *other_performance_data_record);



/** Get the value of the timestamp field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the timestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_timestamp(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the timestamp field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_timestamp The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp(data_collection_model_performance_data_record_t *performance_data_record, const char* p_timestamp);

/** Move a value to the timestamp field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_timestamp The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp_move(data_collection_model_performance_data_record_t *performance_data_record, char* p_timestamp);


/** Get the value of the contextIds field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_performance_data_record_get_context_ids(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the contextIds field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_context_ids The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids(data_collection_model_performance_data_record_t *performance_data_record, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_context_ids The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids_move(data_collection_model_performance_data_record_t *performance_data_record, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_add_context_ids(data_collection_model_performance_data_record_t *performance_data_record, char* context_ids);

/** Remove an item from the contextIds array in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_remove_context_ids(data_collection_model_performance_data_record_t *performance_data_record, const char* context_ids);

/** Get an item from the contextIds array in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_entry_context_ids(const data_collection_model_performance_data_record_t *performance_data_record, size_t idx);

/** Remove all entries from the contextIds array in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to empty contextIds for.
 *
 * @return @a performance_data_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_clear_context_ids(data_collection_model_performance_data_record_t *performance_data_record);


/** Get the value of the timeInterval field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the timeInterval field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_performance_data_record_get_time_interval(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the timeInterval field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_time_interval The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_time_window_t* p_time_interval);

/** Move a value to the timeInterval field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_time_interval The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_time_window_t* p_time_interval);

/** Check if the location field of a PerformanceDataRecord object is set
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return `true` if the optional location field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_location(const data_collection_model_performance_data_record_t *performance_data_record);


/** Get the value of the location field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the location field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_record_get_location(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the location field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_location The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_location_area5_g_t* p_location);

/** Move a value to the location field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_location The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_location_area5_g_t* p_location);

/** Check if the remoteEndpoint field of a PerformanceDataRecord object is set
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return `true` if the optional remoteEndpoint field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_remote_endpoint(const data_collection_model_performance_data_record_t *performance_data_record);


/** Get the value of the remoteEndpoint field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the remoteEndpoint field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_record_get_remote_endpoint(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the remoteEndpoint field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_remote_endpoint The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_addr_fqdn_t* p_remote_endpoint);

/** Move a value to the remoteEndpoint field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_remote_endpoint The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_addr_fqdn_t* p_remote_endpoint);

/** Check if the packetDelayBudget field of a PerformanceDataRecord object is set
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return `true` if the optional packetDelayBudget field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_packet_delay_budget(const data_collection_model_performance_data_record_t *performance_data_record);


/** Get the value of the packetDelayBudget field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the packetDelayBudget field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_get_packet_delay_budget(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the packetDelayBudget field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_packet_delay_budget The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget(data_collection_model_performance_data_record_t *performance_data_record, const int32_t p_packet_delay_budget);

/** Move a value to the packetDelayBudget field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_packet_delay_budget The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget_move(data_collection_model_performance_data_record_t *performance_data_record, int32_t p_packet_delay_budget);

/** Check if the packetLossRate field of a PerformanceDataRecord object is set
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return `true` if the optional packetLossRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_packet_loss_rate(const data_collection_model_performance_data_record_t *performance_data_record);


/** Get the value of the packetLossRate field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the packetLossRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_get_packet_loss_rate(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the packetLossRate field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_packet_loss_rate The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate(data_collection_model_performance_data_record_t *performance_data_record, const int32_t p_packet_loss_rate);

/** Move a value to the packetLossRate field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_packet_loss_rate The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate_move(data_collection_model_performance_data_record_t *performance_data_record, int32_t p_packet_loss_rate);

/** Check if the uplinkThroughput field of a PerformanceDataRecord object is set
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return `true` if the optional uplinkThroughput field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_uplink_throughput(const data_collection_model_performance_data_record_t *performance_data_record);


/** Get the value of the uplinkThroughput field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the uplinkThroughput field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_uplink_throughput(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the uplinkThroughput field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_uplink_throughput The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput(data_collection_model_performance_data_record_t *performance_data_record, const char* p_uplink_throughput);

/** Move a value to the uplinkThroughput field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_uplink_throughput The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput_move(data_collection_model_performance_data_record_t *performance_data_record, char* p_uplink_throughput);

/** Check if the downlinkThrougput field of a PerformanceDataRecord object is set
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return `true` if the optional downlinkThrougput field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_has_downlink_througput(const data_collection_model_performance_data_record_t *performance_data_record);


/** Get the value of the downlinkThrougput field of a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to examine.
 *
 * @return the value current set for the downlinkThrougput field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_get_downlink_througput(const data_collection_model_performance_data_record_t *performance_data_record);

/** Set the value of the downlinkThrougput field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_downlink_througput The value to copy into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput(data_collection_model_performance_data_record_t *performance_data_record, const char* p_downlink_througput);

/** Move a value to the downlinkThrougput field in a PerformanceDataRecord object
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * @param performance_data_record The PerformanceDataRecord object to set the field in.
 * @param p_downlink_througput The value to move into the PerformanceDataRecord object.
 *
 * @return @a performance_data_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput_move(data_collection_model_performance_data_record_t *performance_data_record, char* p_downlink_througput);

/** lnode helper for generating ogs_list_t nodes's of type PerformanceDataRecord
 * \public \memberof data_collection_model_performance_data_record_t
 *
 * Creates a new data_collection_lnode_t object containing the @a performance_data_record object.
 * The @a performance_data_record will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param performance_data_record The PerformanceDataRecord object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a performance_data_record
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_record_make_lnode(data_collection_model_performance_data_record_t *performance_data_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_H_ */

