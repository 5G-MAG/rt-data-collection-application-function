#ifndef _DATA_COLLECTION_COMMUNICATION_RECORD_H_
#define _DATA_COLLECTION_COMMUNICATION_RECORD_H_

/**********************************************************************************************************************************
 * CommunicationRecord - Public C interface to the CommunicationRecord object
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

#include "TimeWindow.h"
#include "LocationArea5G.h"
#include "Snssai.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP CommunicationRecord object reference
 */
typedef struct data_collection_model_communication_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_communication_record_t;



/** Create a new CommunicationRecord.
 * \public \memberof data_collection_model_communication_record_t
 * @return a new CommunicationRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_create();

/** Create a new CommunicationRecord reference.
 * \public \memberof data_collection_model_communication_record_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The CommunicationRecord to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_create_ref(const data_collection_model_communication_record_t *other);

/** Create a new copy of a CommunicationRecord object.
 * \public \memberof data_collection_model_communication_record_t
 * Creates a new copy of the given @a other object
 * @param other The CommunicationRecord to copy.
 * @return a new CommunicationRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_create_copy(const data_collection_model_communication_record_t *other);

/** Create a new reference of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 * Creates a reference to the same underlying @a other object.
 * @param other The CommunicationRecord to create a new reference to.
 * @return a new CommunicationRecord object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_create_move(data_collection_model_communication_record_t *other);

/** Copy the value of another CommunicationRecord into this object
 * \public \memberof data_collection_model_communication_record_t
 * Copies the value of @a other {{classname} object into @a communication_record.
 * @param communication_record The CommunicationRecord object to copy @a other into.
 * @param other The CommunicationRecord to copy the value from.
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_copy(data_collection_model_communication_record_t *communication_record, const data_collection_model_communication_record_t *other);

/** Move the value of another CommunicationRecord into this object
 * \public \memberof data_collection_model_communication_record_t
 * Discards the current value of @a communication_record and moves the value of @a other
 * into @a communication_record. This will leave @a other as an empty reference.
 *
 * @param communication_record The CommunicationRecord object to move @a other into.
 * @param other The CommunicationRecord to move the value from.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_move(data_collection_model_communication_record_t *communication_record, data_collection_model_communication_record_t *other);

/** Delete a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 * Destroys the reference to the CommunicationRecord object and frees the value of CommunicationRecord if this is the last reference.
 *
 * @param communication_record The CommunicationRecord to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_communication_record_free(data_collection_model_communication_record_t *communication_record);

/** Get a cJSON tree representation of a CommunicationRecord
 * \public \memberof data_collection_model_communication_record_t
 *
 * Create a cJSON tree representation of the CommunicationRecord object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param communication_record The CommunicationRecord to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_communication_record_toJSON(const data_collection_model_communication_record_t *communication_record, bool as_request);

/** Parse a cJSON tree into a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * Attempts to interpret a cJSON tree as a CommunicationRecord API request or response (dependent on @a as_request value). If successful
 * will return a new referenced CommunicationRecord object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new CommunicationRecord object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two CommunicationRecord objects to see if they are equivalent
 * \public \memberof data_collection_model_communication_record_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param communication_record The first CommunicationRecord object to compare.
 * @param other_communication_record The second CommunicationRecord object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_is_equal_to(const data_collection_model_communication_record_t *communication_record, const data_collection_model_communication_record_t *other_communication_record);



/** Get the value of the timestamp field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the timestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_record_get_timestamp(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the timestamp field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_timestamp The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_timestamp(data_collection_model_communication_record_t *communication_record, const char* p_timestamp);

/** Move a value to the timestamp field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_timestamp The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_timestamp_move(data_collection_model_communication_record_t *communication_record, char* p_timestamp);


/** Get the value of the contextIds field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_communication_record_get_context_ids(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the contextIds field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_context_ids The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_context_ids(data_collection_model_communication_record_t *communication_record, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_context_ids The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_context_ids_move(data_collection_model_communication_record_t *communication_record, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_add_context_ids(data_collection_model_communication_record_t *communication_record, char* context_ids);

/** Remove an item from the contextIds array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_remove_context_ids(data_collection_model_communication_record_t *communication_record, const char* context_ids);

/** Get an item from the contextIds array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_record_get_entry_context_ids(const data_collection_model_communication_record_t *communication_record, size_t idx);

/** Remove all entries from the contextIds array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to empty contextIds for.
 *
 * @return @a communication_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_clear_context_ids(data_collection_model_communication_record_t *communication_record);


/** Get the value of the timeInterval field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the timeInterval field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_communication_record_get_time_interval(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the timeInterval field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_time_interval The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_time_interval(data_collection_model_communication_record_t *communication_record, const data_collection_model_time_window_t* p_time_interval);

/** Move a value to the timeInterval field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_time_interval The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_time_interval_move(data_collection_model_communication_record_t *communication_record, data_collection_model_time_window_t* p_time_interval);

/** Check if the sliceInfo field of a CommunicationRecord object is set
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return `true` if the optional sliceInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_slice_info(const data_collection_model_communication_record_t *communication_record);


/** Get the value of the sliceInfo field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the sliceInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_communication_record_get_slice_info(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the sliceInfo field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_slice_info The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_slice_info(data_collection_model_communication_record_t *communication_record, const data_collection_model_snssai_t* p_slice_info);

/** Move a value to the sliceInfo field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_slice_info The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_slice_info_move(data_collection_model_communication_record_t *communication_record, data_collection_model_snssai_t* p_slice_info);

/** Check if the dataNetworkName field of a CommunicationRecord object is set
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return `true` if the optional dataNetworkName field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_data_network_name(const data_collection_model_communication_record_t *communication_record);


/** Get the value of the dataNetworkName field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the dataNetworkName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_record_get_data_network_name(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the dataNetworkName field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_data_network_name The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_data_network_name(data_collection_model_communication_record_t *communication_record, const char* p_data_network_name);

/** Move a value to the dataNetworkName field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_data_network_name The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_data_network_name_move(data_collection_model_communication_record_t *communication_record, char* p_data_network_name);

/** Check if the location field of a CommunicationRecord object is set
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return `true` if the optional location field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_location(const data_collection_model_communication_record_t *communication_record);


/** Get the value of the location field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the location field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_communication_record_get_location(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the location field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_location The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_location(data_collection_model_communication_record_t *communication_record, const ogs_list_t* p_location);

/** Move a value to the location field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_location The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_location_move(data_collection_model_communication_record_t *communication_record, ogs_list_t* p_location);

/** Add a new item to the location array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to add the array item to.
 * @param location The value to add.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_add_location(data_collection_model_communication_record_t *communication_record, data_collection_model_location_area5_g_t* location);

/** Remove an item from the location array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to remove the array value from.
 * @param location The value to remove.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_remove_location(data_collection_model_communication_record_t *communication_record, const data_collection_model_location_area5_g_t* location);

/** Get an item from the location array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_communication_record_get_entry_location(const data_collection_model_communication_record_t *communication_record, size_t idx);

/** Remove all entries from the location array in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to empty location for.
 *
 * @return @a communication_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_clear_location(data_collection_model_communication_record_t *communication_record);

/** Check if the uplinkVolume field of a CommunicationRecord object is set
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return `true` if the optional uplinkVolume field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_uplink_volume(const data_collection_model_communication_record_t *communication_record);


/** Get the value of the uplinkVolume field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the uplinkVolume field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_get_uplink_volume(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the uplinkVolume field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_uplink_volume The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_uplink_volume(data_collection_model_communication_record_t *communication_record, const int64_t p_uplink_volume);

/** Move a value to the uplinkVolume field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_uplink_volume The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_uplink_volume_move(data_collection_model_communication_record_t *communication_record, int64_t p_uplink_volume);

/** Check if the downlinkVolume field of a CommunicationRecord object is set
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return `true` if the optional downlinkVolume field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_downlink_volume(const data_collection_model_communication_record_t *communication_record);


/** Get the value of the downlinkVolume field of a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to examine.
 *
 * @return the value current set for the downlinkVolume field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_get_downlink_volume(const data_collection_model_communication_record_t *communication_record);

/** Set the value of the downlinkVolume field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_downlink_volume The value to copy into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_downlink_volume(data_collection_model_communication_record_t *communication_record, const int64_t p_downlink_volume);

/** Move a value to the downlinkVolume field in a CommunicationRecord object
 * \public \memberof data_collection_model_communication_record_t
 *
 * @param communication_record The CommunicationRecord object to set the field in.
 * @param p_downlink_volume The value to move into the CommunicationRecord object.
 *
 * @return @a communication_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_downlink_volume_move(data_collection_model_communication_record_t *communication_record, int64_t p_downlink_volume);

/** lnode helper for generating ogs_list_t nodes's of type CommunicationRecord
 * \public \memberof data_collection_model_communication_record_t
 *
 * Creates a new data_collection_lnode_t object containing the @a communication_record object.
 * The @a communication_record will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param communication_record The CommunicationRecord object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a communication_record
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_communication_record_make_lnode(data_collection_model_communication_record_t *communication_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COMMUNICATION_RECORD_H_ */

