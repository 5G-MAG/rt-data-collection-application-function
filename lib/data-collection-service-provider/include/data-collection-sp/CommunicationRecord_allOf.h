#ifndef _DATA_COLLECTION_COMMUNICATION_RECORD_ALL_OF_H_
#define _DATA_COLLECTION_COMMUNICATION_RECORD_ALL_OF_H_

/**********************************************************************************************************************************
 * CommunicationRecord_allOf - Public C interface to the CommunicationRecord_allOf object
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

/** A 3GPP CommunicationRecord_allOf object reference
 */
typedef struct data_collection_model_communication_record_all_of_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_communication_record_all_of_t;



/** Create a new CommunicationRecord_allOf
 * \public \memberof data_collection_model_communication_record_all_of_t
 * @return a new CommunicationRecord_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create();

/** Create a new copy of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 * Creates a new copy of the given @a other object
 * @param other The CommunicationRecord_allOf to copy.
 * @return a new CommunicationRecord_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create_copy(const data_collection_model_communication_record_all_of_t *other);

/** Create a new reference of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 * Creates a reference to the same underlying @a other object.
 * @param other The CommunicationRecord_allOf to create a new reference to.
 * @return a new CommunicationRecord_allOf object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create_move(data_collection_model_communication_record_all_of_t *other);

/** Copy the value of another CommunicationRecord_allOf into this object
 * \public \memberof data_collection_model_communication_record_all_of_t
 * Copies the value of @a other {{classname} object into @a communication_record_all_of.
 * @param communication_record_all_of The CommunicationRecord_allOf object to copy @a other into.
 * @param other The CommunicationRecord_allOf to copy the value from.
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_copy(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_communication_record_all_of_t *other);

/** Move the value of another CommunicationRecord_allOf into this object
 * \public \memberof data_collection_model_communication_record_all_of_t
 * Discards the current value of @a communication_record_all_of and moves the value of @a other
 * into @a communication_record_all_of. This will leave @a other as an empty reference.
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to move @a other into.
 * @param other The CommunicationRecord_allOf to move the value from.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_communication_record_all_of_t *other);

/** Delete a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 * Destroys the reference to the CommunicationRecord_allOf object and frees the value of CommunicationRecord_allOf if this is the last reference.
 *
 * @param communication_record_all_of The CommunicationRecord_allOf to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_communication_record_all_of_free(data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Get a cJSON tree representation of a CommunicationRecord_allOf
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * Create a cJSON tree representation of the CommunicationRecord_allOf object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param communication_record_all_of The CommunicationRecord_allOf to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_communication_record_all_of_toJSON(const data_collection_model_communication_record_all_of_t *communication_record_all_of, bool as_request);

/** Parse a cJSON tree into a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * Attempts to interpret a cJSON tree as a CommunicationRecord_allOf API request or response (dependent on @a as_request value). If successful
 * will return a new referenced CommunicationRecord_allOf object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new CommunicationRecord_allOf object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two CommunicationRecord_allOf objects to see if they are equivalent
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param communication_record_all_of The first CommunicationRecord_allOf object to compare.
 * @param other_communication_record_all_of The second CommunicationRecord_allOf object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_is_equal_to(const data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_communication_record_all_of_t *other_communication_record_all_of);



/** Get the value of the timeInterval field of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return the value current set for the timeInterval field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_communication_record_all_of_get_time_interval(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Set the value of the timeInterval field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_time_interval The value to copy into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_time_interval(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_time_window_t* p_time_interval);

/** Move a value to the timeInterval field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_time_interval The value to move into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_time_interval_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_time_window_t* p_time_interval);

/** Check if the sliceInfo field of a CommunicationRecord_allOf object is set
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return `true` if the optional sliceInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_slice_info(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


/** Get the value of the sliceInfo field of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return the value current set for the sliceInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_communication_record_all_of_get_slice_info(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Set the value of the sliceInfo field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_slice_info The value to copy into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_slice_info(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_snssai_t* p_slice_info);

/** Move a value to the sliceInfo field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_slice_info The value to move into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_slice_info_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_snssai_t* p_slice_info);

/** Check if the dataNetworkName field of a CommunicationRecord_allOf object is set
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return `true` if the optional dataNetworkName field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_data_network_name(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


/** Get the value of the dataNetworkName field of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return the value current set for the dataNetworkName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_record_all_of_get_data_network_name(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Set the value of the dataNetworkName field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_data_network_name The value to copy into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_data_network_name(data_collection_model_communication_record_all_of_t *communication_record_all_of, const char* p_data_network_name);

/** Move a value to the dataNetworkName field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_data_network_name The value to move into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_data_network_name_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, char* p_data_network_name);

/** Check if the location field of a CommunicationRecord_allOf object is set
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return `true` if the optional location field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_location(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


/** Get the value of the location field of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return the value current set for the location field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_communication_record_all_of_get_location(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Set the value of the location field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_location The value to copy into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_location(data_collection_model_communication_record_all_of_t *communication_record_all_of, const ogs_list_t* p_location);

/** Move a value to the location field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_location The value to move into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_location_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, ogs_list_t* p_location);

/** Add a new item to the location array in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to add the array item to.
 * @param location The value to add.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_add_location(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_location_area5_g_t* location);

/** Remove an item from the location array in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to remove the array value from.
 * @param location The value to remove.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_remove_location(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_location_area5_g_t* location);

/** Get an item from the location array in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_communication_record_all_of_get_entry_location(const data_collection_model_communication_record_all_of_t *communication_record_all_of, size_t idx);

/** Remove all entries from the location array in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to empty location for.
 *
 * @return @a communication_record_all_of
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_clear_location(data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Check if the uplinkVolume field of a CommunicationRecord_allOf object is set
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return `true` if the optional uplinkVolume field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_uplink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


/** Get the value of the uplinkVolume field of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return the value current set for the uplinkVolume field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_all_of_get_uplink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Set the value of the uplinkVolume field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_uplink_volume The value to copy into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_uplink_volume(data_collection_model_communication_record_all_of_t *communication_record_all_of, const int64_t p_uplink_volume);

/** Move a value to the uplinkVolume field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_uplink_volume The value to move into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_uplink_volume_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, int64_t p_uplink_volume);

/** Check if the downlinkVolume field of a CommunicationRecord_allOf object is set
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return `true` if the optional downlinkVolume field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_all_of_has_downlink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);


/** Get the value of the downlinkVolume field of a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to examine.
 *
 * @return the value current set for the downlinkVolume field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_all_of_get_downlink_volume(const data_collection_model_communication_record_all_of_t *communication_record_all_of);

/** Set the value of the downlinkVolume field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_downlink_volume The value to copy into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_downlink_volume(data_collection_model_communication_record_all_of_t *communication_record_all_of, const int64_t p_downlink_volume);

/** Move a value to the downlinkVolume field in a CommunicationRecord_allOf object
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to set the field in.
 * @param p_downlink_volume The value to move into the CommunicationRecord_allOf object.
 *
 * @return @a communication_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_downlink_volume_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, int64_t p_downlink_volume);

/** lnode helper for generating ogs_list_t nodes's of type CommunicationRecord_allOf
 * \public \memberof data_collection_model_communication_record_all_of_t
 *
 * Creates a new data_collection_lnode_t object containing the @a communication_record_all_of object.
 * The @a communication_record_all_of will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param communication_record_all_of The CommunicationRecord_allOf object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a communication_record_all_of
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_communication_record_all_of_make_lnode(data_collection_model_communication_record_all_of_t *communication_record_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COMMUNICATION_RECORD_ALL_OF_H_ */

