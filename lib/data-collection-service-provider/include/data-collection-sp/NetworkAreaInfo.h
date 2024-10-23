#ifndef _DATA_COLLECTION_NETWORK_AREA_INFO_H_
#define _DATA_COLLECTION_NETWORK_AREA_INFO_H_

/**********************************************************************************************************************************
 * NetworkAreaInfo - Public C interface to the NetworkAreaInfo object
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

#include "Ecgi.h"
#include "Ncgi.h"
#include "Tai.h"
#include "GlobalRanNodeId.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP NetworkAreaInfo object reference
 */
typedef struct data_collection_model_network_area_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_network_area_info_t;



/** Create a new NetworkAreaInfo
 * \public \memberof data_collection_model_network_area_info_t
 * @return a new NetworkAreaInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create();

/** Create a new copy of a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 * Creates a new copy of the given @a other object
 * @param other The NetworkAreaInfo to copy.
 * @return a new NetworkAreaInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create_copy(const data_collection_model_network_area_info_t *other);

/** Create a new reference of a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The NetworkAreaInfo to create a new reference to.
 * @return a new NetworkAreaInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create_move(data_collection_model_network_area_info_t *other);

/** Copy the value of another NetworkAreaInfo into this object
 * \public \memberof data_collection_model_network_area_info_t
 * Copies the value of @a other {{classname} object into @a network_area_info.
 * @param network_area_info The NetworkAreaInfo object to copy @a other into.
 * @param other The NetworkAreaInfo to copy the value from.
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_copy(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_network_area_info_t *other);

/** Move the value of another NetworkAreaInfo into this object
 * \public \memberof data_collection_model_network_area_info_t
 * Discards the current value of @a network_area_info and moves the value of @a other
 * into @a network_area_info. This will leave @a other as an empty reference.
 *
 * @param network_area_info The NetworkAreaInfo object to move @a other into.
 * @param other The NetworkAreaInfo to move the value from.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_move(data_collection_model_network_area_info_t *network_area_info, data_collection_model_network_area_info_t *other);

/** Delete a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 * Destroys the reference to the NetworkAreaInfo object and frees the value of NetworkAreaInfo if this is the last reference.
 *
 * @param network_area_info The NetworkAreaInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_area_info_free(data_collection_model_network_area_info_t *network_area_info);

/** Get a cJSON tree representation of a NetworkAreaInfo
 * \public \memberof data_collection_model_network_area_info_t
 *
 * Create a cJSON tree representation of the NetworkAreaInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param network_area_info The NetworkAreaInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_area_info_toJSON(const data_collection_model_network_area_info_t *network_area_info, bool as_request);

/** Parse a cJSON tree into a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * Attempts to interpret a cJSON tree as a NetworkAreaInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced NetworkAreaInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new NetworkAreaInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two NetworkAreaInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_network_area_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param network_area_info The first NetworkAreaInfo object to compare.
 * @param other_network_area_info The second NetworkAreaInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_is_equal_to(const data_collection_model_network_area_info_t *network_area_info, const data_collection_model_network_area_info_t *other_network_area_info);


/** Check if the ecgis field of a NetworkAreaInfo object is set
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return `true` if the optional ecgis field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_ecgis(const data_collection_model_network_area_info_t *network_area_info);


/** Get the value of the ecgis field of a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return the value current set for the ecgis field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_ecgis(const data_collection_model_network_area_info_t *network_area_info);

/** Set the value of the ecgis field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_ecgis The value to copy into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ecgis(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_ecgis);

/** Move a value to the ecgis field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_ecgis The value to move into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ecgis_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_ecgis);

/** Add a new item to the ecgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to add the array item to.
 * @param ecgis The value to add.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_ecgis(data_collection_model_network_area_info_t *network_area_info, data_collection_model_ecgi_t* ecgis);

/** Remove an item from the ecgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to remove the array value from.
 * @param ecgis The value to remove.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_ecgis(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_ecgi_t* ecgis);

/** Get an item from the ecgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ecgi_t* data_collection_model_network_area_info_get_entry_ecgis(const data_collection_model_network_area_info_t *network_area_info, size_t idx);

/** Remove all entries from the ecgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to empty ecgis for.
 *
 * @return @a network_area_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_ecgis(data_collection_model_network_area_info_t *network_area_info);

/** Check if the ncgis field of a NetworkAreaInfo object is set
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return `true` if the optional ncgis field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_ncgis(const data_collection_model_network_area_info_t *network_area_info);


/** Get the value of the ncgis field of a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return the value current set for the ncgis field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_ncgis(const data_collection_model_network_area_info_t *network_area_info);

/** Set the value of the ncgis field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_ncgis The value to copy into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ncgis(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_ncgis);

/** Move a value to the ncgis field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_ncgis The value to move into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ncgis_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_ncgis);

/** Add a new item to the ncgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to add the array item to.
 * @param ncgis The value to add.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_ncgis(data_collection_model_network_area_info_t *network_area_info, data_collection_model_ncgi_t* ncgis);

/** Remove an item from the ncgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to remove the array value from.
 * @param ncgis The value to remove.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_ncgis(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_ncgi_t* ncgis);

/** Get an item from the ncgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ncgi_t* data_collection_model_network_area_info_get_entry_ncgis(const data_collection_model_network_area_info_t *network_area_info, size_t idx);

/** Remove all entries from the ncgis array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to empty ncgis for.
 *
 * @return @a network_area_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_ncgis(data_collection_model_network_area_info_t *network_area_info);

/** Check if the gRanNodeIds field of a NetworkAreaInfo object is set
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return `true` if the optional gRanNodeIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_g_ran_node_ids(const data_collection_model_network_area_info_t *network_area_info);


/** Get the value of the gRanNodeIds field of a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return the value current set for the gRanNodeIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_g_ran_node_ids(const data_collection_model_network_area_info_t *network_area_info);

/** Set the value of the gRanNodeIds field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_g_ran_node_ids The value to copy into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_g_ran_node_ids);

/** Move a value to the gRanNodeIds field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_g_ran_node_ids The value to move into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_g_ran_node_ids_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_g_ran_node_ids);

/** Add a new item to the gRanNodeIds array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to add the array item to.
 * @param g_ran_node_ids The value to add.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info, data_collection_model_global_ran_node_id_t* g_ran_node_ids);

/** Remove an item from the gRanNodeIds array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to remove the array value from.
 * @param g_ran_node_ids The value to remove.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_global_ran_node_id_t* g_ran_node_ids);

/** Get an item from the gRanNodeIds array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_global_ran_node_id_t* data_collection_model_network_area_info_get_entry_g_ran_node_ids(const data_collection_model_network_area_info_t *network_area_info, size_t idx);

/** Remove all entries from the gRanNodeIds array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to empty gRanNodeIds for.
 *
 * @return @a network_area_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info);

/** Check if the tais field of a NetworkAreaInfo object is set
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return `true` if the optional tais field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_tais(const data_collection_model_network_area_info_t *network_area_info);


/** Get the value of the tais field of a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 *
 * @return the value current set for the tais field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_tais(const data_collection_model_network_area_info_t *network_area_info);

/** Set the value of the tais field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_tais The value to copy into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_tais(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_tais);

/** Move a value to the tais field in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to set the field in.
 * @param p_tais The value to move into the NetworkAreaInfo object.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_tais_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_tais);

/** Add a new item to the tais array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to add the array item to.
 * @param tais The value to add.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_tais(data_collection_model_network_area_info_t *network_area_info, data_collection_model_tai_t* tais);

/** Remove an item from the tais array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to remove the array value from.
 * @param tais The value to remove.
 *
 * @return @a network_area_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_tais(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_tai_t* tais);

/** Get an item from the tais array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_tai_t* data_collection_model_network_area_info_get_entry_tais(const data_collection_model_network_area_info_t *network_area_info, size_t idx);

/** Remove all entries from the tais array in a NetworkAreaInfo object
 * \public \memberof data_collection_model_network_area_info_t
 *
 * @param network_area_info The NetworkAreaInfo object to empty tais for.
 *
 * @return @a network_area_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_tais(data_collection_model_network_area_info_t *network_area_info);

/** lnode helper for generating ogs_list_t nodes's of type NetworkAreaInfo
 * \public \memberof data_collection_model_network_area_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a network_area_info object.
 * The @a network_area_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param network_area_info The NetworkAreaInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a network_area_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_area_info_make_lnode(data_collection_model_network_area_info_t *network_area_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_AREA_INFO_H_ */

