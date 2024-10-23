#ifndef _DATA_COLLECTION_EVENT_FILTER_H_
#define _DATA_COLLECTION_EVENT_FILTER_H_

/**********************************************************************************************************************************
 * EventFilter - Public C interface to the EventFilter object
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
#include "Exception.h"
#include "LocationArea5G.h"
#include "CollectiveBehaviourFilter.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP EventFilter object reference
 */
typedef struct data_collection_model_event_filter_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_event_filter_t;



/** Create a new EventFilter
 * \public \memberof data_collection_model_event_filter_t
 * @return a new EventFilter object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create();

/** Create a new copy of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 * Creates a new copy of the given @a other object
 * @param other The EventFilter to copy.
 * @return a new EventFilter object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create_copy(const data_collection_model_event_filter_t *other);

/** Create a new reference of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 * Creates a reference to the same underlying @a other object.
 * @param other The EventFilter to create a new reference to.
 * @return a new EventFilter object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create_move(data_collection_model_event_filter_t *other);

/** Copy the value of another EventFilter into this object
 * \public \memberof data_collection_model_event_filter_t
 * Copies the value of @a other {{classname} object into @a event_filter.
 * @param event_filter The EventFilter object to copy @a other into.
 * @param other The EventFilter to copy the value from.
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_copy(data_collection_model_event_filter_t *event_filter, const data_collection_model_event_filter_t *other);

/** Move the value of another EventFilter into this object
 * \public \memberof data_collection_model_event_filter_t
 * Discards the current value of @a event_filter and moves the value of @a other
 * into @a event_filter. This will leave @a other as an empty reference.
 *
 * @param event_filter The EventFilter object to move @a other into.
 * @param other The EventFilter to move the value from.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_move(data_collection_model_event_filter_t *event_filter, data_collection_model_event_filter_t *other);

/** Delete a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 * Destroys the reference to the EventFilter object and frees the value of EventFilter if this is the last reference.
 *
 * @param event_filter The EventFilter to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_event_filter_free(data_collection_model_event_filter_t *event_filter);

/** Get a cJSON tree representation of a EventFilter
 * \public \memberof data_collection_model_event_filter_t
 *
 * Create a cJSON tree representation of the EventFilter object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param event_filter The EventFilter to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_event_filter_toJSON(const data_collection_model_event_filter_t *event_filter, bool as_request);

/** Parse a cJSON tree into a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * Attempts to interpret a cJSON tree as a EventFilter API request or response (dependent on @a as_request value). If successful
 * will return a new referenced EventFilter object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new EventFilter object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two EventFilter objects to see if they are equivalent
 * \public \memberof data_collection_model_event_filter_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param event_filter The first EventFilter object to compare.
 * @param other_event_filter The second EventFilter object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_is_equal_to(const data_collection_model_event_filter_t *event_filter, const data_collection_model_event_filter_t *other_event_filter);


/** Check if the gpsis field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional gpsis field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_gpsis(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the gpsis field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the gpsis field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_gpsis(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the gpsis field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_gpsis The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_gpsis(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_gpsis);

/** Move a value to the gpsis field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_gpsis The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_gpsis_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_gpsis);

/** Add a new item to the gpsis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to add the array item to.
 * @param gpsis The value to add.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_gpsis(data_collection_model_event_filter_t *event_filter, char* gpsis);

/** Remove an item from the gpsis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to remove the array value from.
 * @param gpsis The value to remove.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_gpsis(data_collection_model_event_filter_t *event_filter, const char* gpsis);

/** Get an item from the gpsis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_event_filter_get_entry_gpsis(const data_collection_model_event_filter_t *event_filter, size_t idx);

/** Remove all entries from the gpsis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to empty gpsis for.
 *
 * @return @a event_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_gpsis(data_collection_model_event_filter_t *event_filter);

/** Check if the supis field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional supis field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_supis(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the supis field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the supis field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_supis(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the supis field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_supis The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_supis(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_supis);

/** Move a value to the supis field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_supis The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_supis_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_supis);

/** Add a new item to the supis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to add the array item to.
 * @param supis The value to add.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_supis(data_collection_model_event_filter_t *event_filter, char* supis);

/** Remove an item from the supis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to remove the array value from.
 * @param supis The value to remove.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_supis(data_collection_model_event_filter_t *event_filter, const char* supis);

/** Get an item from the supis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_event_filter_get_entry_supis(const data_collection_model_event_filter_t *event_filter, size_t idx);

/** Remove all entries from the supis array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to empty supis for.
 *
 * @return @a event_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_supis(data_collection_model_event_filter_t *event_filter);

/** Check if the exterGroupIds field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional exterGroupIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_exter_group_ids(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the exterGroupIds field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the exterGroupIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_exter_group_ids(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the exterGroupIds field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_exter_group_ids The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exter_group_ids(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_exter_group_ids);

/** Move a value to the exterGroupIds field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_exter_group_ids The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exter_group_ids_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_exter_group_ids);

/** Add a new item to the exterGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to add the array item to.
 * @param exter_group_ids The value to add.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_exter_group_ids(data_collection_model_event_filter_t *event_filter, char* exter_group_ids);

/** Remove an item from the exterGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to remove the array value from.
 * @param exter_group_ids The value to remove.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_exter_group_ids(data_collection_model_event_filter_t *event_filter, const char* exter_group_ids);

/** Get an item from the exterGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_event_filter_get_entry_exter_group_ids(const data_collection_model_event_filter_t *event_filter, size_t idx);

/** Remove all entries from the exterGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to empty exterGroupIds for.
 *
 * @return @a event_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_exter_group_ids(data_collection_model_event_filter_t *event_filter);

/** Check if the interGroupIds field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional interGroupIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_inter_group_ids(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the interGroupIds field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the interGroupIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_inter_group_ids(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the interGroupIds field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_inter_group_ids The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_inter_group_ids(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_inter_group_ids);

/** Move a value to the interGroupIds field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_inter_group_ids The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_inter_group_ids_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_inter_group_ids);

/** Add a new item to the interGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to add the array item to.
 * @param inter_group_ids The value to add.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_inter_group_ids(data_collection_model_event_filter_t *event_filter, char* inter_group_ids);

/** Remove an item from the interGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to remove the array value from.
 * @param inter_group_ids The value to remove.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_inter_group_ids(data_collection_model_event_filter_t *event_filter, const char* inter_group_ids);

/** Get an item from the interGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_event_filter_get_entry_inter_group_ids(const data_collection_model_event_filter_t *event_filter, size_t idx);

/** Remove all entries from the interGroupIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to empty interGroupIds for.
 *
 * @return @a event_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_inter_group_ids(data_collection_model_event_filter_t *event_filter);

/** Check if the anyUeInd field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional anyUeInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_any_ue_ind(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the anyUeInd field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the anyUeInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_event_filter_is_any_ue_ind(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the anyUeInd field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_any_ue_ind The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_any_ue_ind(data_collection_model_event_filter_t *event_filter, const bool p_any_ue_ind);

/** Move a value to the anyUeInd field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_any_ue_ind The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_any_ue_ind_move(data_collection_model_event_filter_t *event_filter, bool p_any_ue_ind);

/** Check if the ueIpAddr field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional ueIpAddr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_ue_ip_addr(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the ueIpAddr field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the ueIpAddr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_event_filter_get_ue_ip_addr(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the ueIpAddr field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_ue_ip_addr The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_ue_ip_addr(data_collection_model_event_filter_t *event_filter, const data_collection_model_ip_addr_t* p_ue_ip_addr);

/** Move a value to the ueIpAddr field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_ue_ip_addr The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_ue_ip_addr_move(data_collection_model_event_filter_t *event_filter, data_collection_model_ip_addr_t* p_ue_ip_addr);

/** Check if the appIds field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional appIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_app_ids(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the appIds field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the appIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_app_ids(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the appIds field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_app_ids The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_app_ids(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_app_ids);

/** Move a value to the appIds field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_app_ids The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_app_ids_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_app_ids);

/** Add a new item to the appIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to add the array item to.
 * @param app_ids The value to add.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_app_ids(data_collection_model_event_filter_t *event_filter, char* app_ids);

/** Remove an item from the appIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to remove the array value from.
 * @param app_ids The value to remove.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_app_ids(data_collection_model_event_filter_t *event_filter, const char* app_ids);

/** Get an item from the appIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_event_filter_get_entry_app_ids(const data_collection_model_event_filter_t *event_filter, size_t idx);

/** Remove all entries from the appIds array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to empty appIds for.
 *
 * @return @a event_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_app_ids(data_collection_model_event_filter_t *event_filter);

/** Check if the locArea field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional locArea field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_loc_area(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the locArea field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the locArea field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_event_filter_get_loc_area(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the locArea field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_loc_area The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_loc_area(data_collection_model_event_filter_t *event_filter, const data_collection_model_location_area5_g_t* p_loc_area);

/** Move a value to the locArea field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_loc_area The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_loc_area_move(data_collection_model_event_filter_t *event_filter, data_collection_model_location_area5_g_t* p_loc_area);

/** Check if the collAttrs field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional collAttrs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_coll_attrs(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the collAttrs field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the collAttrs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_coll_attrs(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the collAttrs field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_coll_attrs The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_coll_attrs(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_coll_attrs);

/** Move a value to the collAttrs field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_coll_attrs The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_coll_attrs_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_coll_attrs);

/** Add a new item to the collAttrs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to add the array item to.
 * @param coll_attrs The value to add.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_coll_attrs(data_collection_model_event_filter_t *event_filter, data_collection_model_collective_behaviour_filter_t* coll_attrs);

/** Remove an item from the collAttrs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to remove the array value from.
 * @param coll_attrs The value to remove.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_coll_attrs(data_collection_model_event_filter_t *event_filter, const data_collection_model_collective_behaviour_filter_t* coll_attrs);

/** Get an item from the collAttrs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_collective_behaviour_filter_t* data_collection_model_event_filter_get_entry_coll_attrs(const data_collection_model_event_filter_t *event_filter, size_t idx);

/** Remove all entries from the collAttrs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to empty collAttrs for.
 *
 * @return @a event_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_coll_attrs(data_collection_model_event_filter_t *event_filter);

/** Check if the exceptionReqs field of a EventFilter object is set
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return `true` if the optional exceptionReqs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_exception_reqs(const data_collection_model_event_filter_t *event_filter);


/** Get the value of the exceptionReqs field of a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 *
 * @return the value current set for the exceptionReqs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_exception_reqs(const data_collection_model_event_filter_t *event_filter);

/** Set the value of the exceptionReqs field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_exception_reqs The value to copy into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exception_reqs(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_exception_reqs);

/** Move a value to the exceptionReqs field in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to set the field in.
 * @param p_exception_reqs The value to move into the EventFilter object.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exception_reqs_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_exception_reqs);

/** Add a new item to the exceptionReqs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to add the array item to.
 * @param exception_reqs The value to add.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_exception_reqs(data_collection_model_event_filter_t *event_filter, data_collection_model_exception_t* exception_reqs);

/** Remove an item from the exceptionReqs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to remove the array value from.
 * @param exception_reqs The value to remove.
 *
 * @return @a event_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_exception_reqs(data_collection_model_event_filter_t *event_filter, const data_collection_model_exception_t* exception_reqs);

/** Get an item from the exceptionReqs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_t* data_collection_model_event_filter_get_entry_exception_reqs(const data_collection_model_event_filter_t *event_filter, size_t idx);

/** Remove all entries from the exceptionReqs array in a EventFilter object
 * \public \memberof data_collection_model_event_filter_t
 *
 * @param event_filter The EventFilter object to empty exceptionReqs for.
 *
 * @return @a event_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_exception_reqs(data_collection_model_event_filter_t *event_filter);

/** lnode helper for generating ogs_list_t nodes's of type EventFilter
 * \public \memberof data_collection_model_event_filter_t
 *
 * Creates a new data_collection_lnode_t object containing the @a event_filter object.
 * The @a event_filter will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param event_filter The EventFilter object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a event_filter
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_event_filter_make_lnode(data_collection_model_event_filter_t *event_filter);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EVENT_FILTER_H_ */

