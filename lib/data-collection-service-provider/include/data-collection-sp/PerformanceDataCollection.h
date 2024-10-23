#ifndef _DATA_COLLECTION_PERFORMANCE_DATA_COLLECTION_H_
#define _DATA_COLLECTION_PERFORMANCE_DATA_COLLECTION_H_

/**********************************************************************************************************************************
 * PerformanceDataCollection - Public C interface to the PerformanceDataCollection object
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

#include "IpAddr.h"
#include "FlowInfo.h"
#include "AddrFqdn.h"
#include "PerformanceData.h"
#include "LocationArea5G.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PerformanceDataCollection object reference
 */
typedef struct data_collection_model_performance_data_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_performance_data_collection_t;



/** Create a new PerformanceDataCollection
 * \public \memberof data_collection_model_performance_data_collection_t
 * @return a new PerformanceDataCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create();

/** Create a new copy of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 * Creates a new copy of the given @a other object
 * @param other The PerformanceDataCollection to copy.
 * @return a new PerformanceDataCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create_copy(const data_collection_model_performance_data_collection_t *other);

/** Create a new reference of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PerformanceDataCollection to create a new reference to.
 * @return a new PerformanceDataCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create_move(data_collection_model_performance_data_collection_t *other);

/** Copy the value of another PerformanceDataCollection into this object
 * \public \memberof data_collection_model_performance_data_collection_t
 * Copies the value of @a other {{classname} object into @a performance_data_collection.
 * @param performance_data_collection The PerformanceDataCollection object to copy @a other into.
 * @param other The PerformanceDataCollection to copy the value from.
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_copy(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_performance_data_collection_t *other);

/** Move the value of another PerformanceDataCollection into this object
 * \public \memberof data_collection_model_performance_data_collection_t
 * Discards the current value of @a performance_data_collection and moves the value of @a other
 * into @a performance_data_collection. This will leave @a other as an empty reference.
 *
 * @param performance_data_collection The PerformanceDataCollection object to move @a other into.
 * @param other The PerformanceDataCollection to move the value from.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_performance_data_collection_t *other);

/** Delete a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 * Destroys the reference to the PerformanceDataCollection object and frees the value of PerformanceDataCollection if this is the last reference.
 *
 * @param performance_data_collection The PerformanceDataCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_collection_free(data_collection_model_performance_data_collection_t *performance_data_collection);

/** Get a cJSON tree representation of a PerformanceDataCollection
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * Create a cJSON tree representation of the PerformanceDataCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param performance_data_collection The PerformanceDataCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_collection_toJSON(const data_collection_model_performance_data_collection_t *performance_data_collection, bool as_request);

/** Parse a cJSON tree into a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * Attempts to interpret a cJSON tree as a PerformanceDataCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PerformanceDataCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PerformanceDataCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PerformanceDataCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param performance_data_collection The first PerformanceDataCollection object to compare.
 * @param other_performance_data_collection The second PerformanceDataCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_is_equal_to(const data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_performance_data_collection_t *other_performance_data_collection);


/** Check if the appId field of a PerformanceDataCollection object is set
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return `true` if the optional appId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_app_id(const data_collection_model_performance_data_collection_t *performance_data_collection);


/** Get the value of the appId field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_collection_get_app_id(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the appId field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_app_id The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_id(data_collection_model_performance_data_collection_t *performance_data_collection, const char* p_app_id);

/** Move a value to the appId field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_app_id The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_id_move(data_collection_model_performance_data_collection_t *performance_data_collection, char* p_app_id);

/** Check if the ueIpAddr field of a PerformanceDataCollection object is set
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return `true` if the optional ueIpAddr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ue_ip_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);


/** Get the value of the ueIpAddr field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the ueIpAddr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_performance_data_collection_get_ue_ip_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the ueIpAddr field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_ue_ip_addr The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_ip_addr(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_ip_addr_t* p_ue_ip_addr);

/** Move a value to the ueIpAddr field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_ue_ip_addr The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_ip_addr_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_ip_addr_t* p_ue_ip_addr);

/** Check if the ipTrafficFilter field of a PerformanceDataCollection object is set
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return `true` if the optional ipTrafficFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ip_traffic_filter(const data_collection_model_performance_data_collection_t *performance_data_collection);


/** Get the value of the ipTrafficFilter field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the ipTrafficFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_performance_data_collection_get_ip_traffic_filter(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the ipTrafficFilter field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_ip_traffic_filter The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ip_traffic_filter(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Move a value to the ipTrafficFilter field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_ip_traffic_filter The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ip_traffic_filter_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Check if the ueLoc field of a PerformanceDataCollection object is set
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return `true` if the optional ueLoc field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ue_loc(const data_collection_model_performance_data_collection_t *performance_data_collection);


/** Get the value of the ueLoc field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the ueLoc field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_collection_get_ue_loc(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the ueLoc field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_ue_loc The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_loc(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_location_area5_g_t* p_ue_loc);

/** Move a value to the ueLoc field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_ue_loc The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_loc_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_location_area5_g_t* p_ue_loc);

/** Check if the appLocs field of a PerformanceDataCollection object is set
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return `true` if the optional appLocs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_app_locs(const data_collection_model_performance_data_collection_t *performance_data_collection);


/** Get the value of the appLocs field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the appLocs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_performance_data_collection_get_app_locs(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the appLocs field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_app_locs The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection, const ogs_list_t* p_app_locs);

/** Move a value to the appLocs field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_app_locs The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_locs_move(data_collection_model_performance_data_collection_t *performance_data_collection, ogs_list_t* p_app_locs);

/** Add a new item to the appLocs array in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to add the array item to.
 * @param app_locs The value to add.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_add_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection, char* app_locs);

/** Remove an item from the appLocs array in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to remove the array value from.
 * @param app_locs The value to remove.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_remove_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection, const char* app_locs);

/** Get an item from the appLocs array in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_collection_get_entry_app_locs(const data_collection_model_performance_data_collection_t *performance_data_collection, size_t idx);

/** Remove all entries from the appLocs array in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to empty appLocs for.
 *
 * @return @a performance_data_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_clear_app_locs(data_collection_model_performance_data_collection_t *performance_data_collection);

/** Check if the asAddr field of a PerformanceDataCollection object is set
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return `true` if the optional asAddr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_as_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);


/** Get the value of the asAddr field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the asAddr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_collection_get_as_addr(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the asAddr field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_as_addr The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_as_addr(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_addr_fqdn_t* p_as_addr);

/** Move a value to the asAddr field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_as_addr The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_as_addr_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_addr_fqdn_t* p_as_addr);


/** Get the value of the perfData field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the perfData field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_performance_data_t* data_collection_model_performance_data_collection_get_perf_data(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the perfData field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_perf_data The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_perf_data(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_performance_data_t* p_perf_data);

/** Move a value to the perfData field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_perf_data The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_perf_data_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_performance_data_t* p_perf_data);


/** Get the value of the timeStamp field of a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to examine.
 *
 * @return the value current set for the timeStamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_collection_get_time_stamp(const data_collection_model_performance_data_collection_t *performance_data_collection);

/** Set the value of the timeStamp field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_time_stamp The value to copy into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_time_stamp(data_collection_model_performance_data_collection_t *performance_data_collection, const char* p_time_stamp);

/** Move a value to the timeStamp field in a PerformanceDataCollection object
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * @param performance_data_collection The PerformanceDataCollection object to set the field in.
 * @param p_time_stamp The value to move into the PerformanceDataCollection object.
 *
 * @return @a performance_data_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_time_stamp_move(data_collection_model_performance_data_collection_t *performance_data_collection, char* p_time_stamp);

/** lnode helper for generating ogs_list_t nodes's of type PerformanceDataCollection
 * \public \memberof data_collection_model_performance_data_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a performance_data_collection object.
 * The @a performance_data_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param performance_data_collection The PerformanceDataCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a performance_data_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_collection_make_lnode(data_collection_model_performance_data_collection_t *performance_data_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERFORMANCE_DATA_COLLECTION_H_ */

