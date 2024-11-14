#ifndef _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_ALL_OF_H_
#define _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_ALL_OF_H_

/**********************************************************************************************************************************
 * PerformanceDataRecord_allOf - Public C interface to the PerformanceDataRecord_allOf object
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

/** A 3GPP PerformanceDataRecord_allOf object reference
 */
typedef struct data_collection_model_performance_data_record_all_of_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_performance_data_record_all_of_t;



/** Create a new PerformanceDataRecord_allOf.
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 * @return a new PerformanceDataRecord_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_create();

/** Create a new PerformanceDataRecord_allOf reference.
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PerformanceDataRecord_allOf to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_create_ref(const data_collection_model_performance_data_record_all_of_t *other);

/** Create a new copy of a PerformanceDataRecord_allOf object.
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 * Creates a new copy of the given @a other object
 * @param other The PerformanceDataRecord_allOf to copy.
 * @return a new PerformanceDataRecord_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_create_copy(const data_collection_model_performance_data_record_all_of_t *other);

/** Create a new reference of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PerformanceDataRecord_allOf to create a new reference to.
 * @return a new PerformanceDataRecord_allOf object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_create_move(data_collection_model_performance_data_record_all_of_t *other);

/** Copy the value of another PerformanceDataRecord_allOf into this object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 * Copies the value of @a other {{classname} object into @a performance_data_record_all_of.
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to copy @a other into.
 * @param other The PerformanceDataRecord_allOf to copy the value from.
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_copy(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const data_collection_model_performance_data_record_all_of_t *other);

/** Move the value of another PerformanceDataRecord_allOf into this object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 * Discards the current value of @a performance_data_record_all_of and moves the value of @a other
 * into @a performance_data_record_all_of. This will leave @a other as an empty reference.
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to move @a other into.
 * @param other The PerformanceDataRecord_allOf to move the value from.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, data_collection_model_performance_data_record_all_of_t *other);

/** Delete a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 * Destroys the reference to the PerformanceDataRecord_allOf object and frees the value of PerformanceDataRecord_allOf if this is the last reference.
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_record_all_of_free(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Get a cJSON tree representation of a PerformanceDataRecord_allOf
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * Create a cJSON tree representation of the PerformanceDataRecord_allOf object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_record_all_of_toJSON(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, bool as_request);

/** Parse a cJSON tree into a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * Attempts to interpret a cJSON tree as a PerformanceDataRecord_allOf API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PerformanceDataRecord_allOf object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PerformanceDataRecord_allOf object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PerformanceDataRecord_allOf objects to see if they are equivalent
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param performance_data_record_all_of The first PerformanceDataRecord_allOf object to compare.
 * @param other_performance_data_record_all_of The second PerformanceDataRecord_allOf object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_is_equal_to(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const data_collection_model_performance_data_record_all_of_t *other_performance_data_record_all_of);



/** Get the value of the timeInterval field of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return the value current set for the timeInterval field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_performance_data_record_all_of_get_time_interval(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Set the value of the timeInterval field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_time_interval The value to copy into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_time_interval(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const data_collection_model_time_window_t* p_time_interval);

/** Move a value to the timeInterval field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_time_interval The value to move into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_time_interval_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, data_collection_model_time_window_t* p_time_interval);

/** Check if the location field of a PerformanceDataRecord_allOf object is set
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return `true` if the optional location field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_location(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);


/** Get the value of the location field of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return the value current set for the location field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_record_all_of_get_location(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Set the value of the location field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_location The value to copy into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_location(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const data_collection_model_location_area5_g_t* p_location);

/** Move a value to the location field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_location The value to move into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_location_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, data_collection_model_location_area5_g_t* p_location);

/** Check if the remoteEndpoint field of a PerformanceDataRecord_allOf object is set
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return `true` if the optional remoteEndpoint field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_remote_endpoint(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);


/** Get the value of the remoteEndpoint field of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return the value current set for the remoteEndpoint field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_record_all_of_get_remote_endpoint(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Set the value of the remoteEndpoint field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_remote_endpoint The value to copy into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_remote_endpoint(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const data_collection_model_addr_fqdn_t* p_remote_endpoint);

/** Move a value to the remoteEndpoint field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_remote_endpoint The value to move into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_remote_endpoint_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, data_collection_model_addr_fqdn_t* p_remote_endpoint);

/** Check if the packetDelayBudget field of a PerformanceDataRecord_allOf object is set
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return `true` if the optional packetDelayBudget field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_packet_delay_budget(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);


/** Get the value of the packetDelayBudget field of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return the value current set for the packetDelayBudget field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_all_of_get_packet_delay_budget(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Set the value of the packetDelayBudget field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_packet_delay_budget The value to copy into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_delay_budget(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const int32_t p_packet_delay_budget);

/** Move a value to the packetDelayBudget field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_packet_delay_budget The value to move into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_delay_budget_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, int32_t p_packet_delay_budget);

/** Check if the packetLossRate field of a PerformanceDataRecord_allOf object is set
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return `true` if the optional packetLossRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_packet_loss_rate(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);


/** Get the value of the packetLossRate field of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return the value current set for the packetLossRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_all_of_get_packet_loss_rate(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Set the value of the packetLossRate field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_packet_loss_rate The value to copy into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_loss_rate(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const int32_t p_packet_loss_rate);

/** Move a value to the packetLossRate field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_packet_loss_rate The value to move into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_loss_rate_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, int32_t p_packet_loss_rate);

/** Check if the uplinkThroughput field of a PerformanceDataRecord_allOf object is set
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return `true` if the optional uplinkThroughput field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_uplink_throughput(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);


/** Get the value of the uplinkThroughput field of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return the value current set for the uplinkThroughput field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_all_of_get_uplink_throughput(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Set the value of the uplinkThroughput field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_uplink_throughput The value to copy into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_uplink_throughput(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const char* p_uplink_throughput);

/** Move a value to the uplinkThroughput field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_uplink_throughput The value to move into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_uplink_throughput_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, char* p_uplink_throughput);

/** Check if the downlinkThrougput field of a PerformanceDataRecord_allOf object is set
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return `true` if the optional downlinkThrougput field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_downlink_througput(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);


/** Get the value of the downlinkThrougput field of a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to examine.
 *
 * @return the value current set for the downlinkThrougput field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_all_of_get_downlink_througput(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/** Set the value of the downlinkThrougput field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_downlink_througput The value to copy into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_downlink_througput(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const char* p_downlink_througput);

/** Move a value to the downlinkThrougput field in a PerformanceDataRecord_allOf object
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to set the field in.
 * @param p_downlink_througput The value to move into the PerformanceDataRecord_allOf object.
 *
 * @return @a performance_data_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_downlink_througput_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, char* p_downlink_througput);

/** lnode helper for generating ogs_list_t nodes's of type PerformanceDataRecord_allOf
 * \public \memberof data_collection_model_performance_data_record_all_of_t
 *
 * Creates a new data_collection_lnode_t object containing the @a performance_data_record_all_of object.
 * The @a performance_data_record_all_of will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param performance_data_record_all_of The PerformanceDataRecord_allOf object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a performance_data_record_all_of
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_record_all_of_make_lnode(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERFORMANCE_DATA_RECORD_ALL_OF_H_ */

