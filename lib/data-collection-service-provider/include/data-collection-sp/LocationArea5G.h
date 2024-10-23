#ifndef _DATA_COLLECTION_LOCATION_AREA5_G_H_
#define _DATA_COLLECTION_LOCATION_AREA5_G_H_

/**********************************************************************************************************************************
 * LocationArea5G - Public C interface to the LocationArea5G object
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

#include "CivicAddress.h"
#include "GeographicArea.h"
#include "NetworkAreaInfo.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP LocationArea5G object reference
 */
typedef struct data_collection_model_location_area5_g_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_location_area5_g_t;



/** Create a new LocationArea5G
 * \public \memberof data_collection_model_location_area5_g_t
 * @return a new LocationArea5G object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_create();

/** Create a new copy of a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 * Creates a new copy of the given @a other object
 * @param other The LocationArea5G to copy.
 * @return a new LocationArea5G object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_create_copy(const data_collection_model_location_area5_g_t *other);

/** Create a new reference of a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 * Creates a reference to the same underlying @a other object.
 * @param other The LocationArea5G to create a new reference to.
 * @return a new LocationArea5G object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_create_move(data_collection_model_location_area5_g_t *other);

/** Copy the value of another LocationArea5G into this object
 * \public \memberof data_collection_model_location_area5_g_t
 * Copies the value of @a other {{classname} object into @a location_area5_g.
 * @param location_area5_g The LocationArea5G object to copy @a other into.
 * @param other The LocationArea5G to copy the value from.
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_copy(data_collection_model_location_area5_g_t *location_area5_g, const data_collection_model_location_area5_g_t *other);

/** Move the value of another LocationArea5G into this object
 * \public \memberof data_collection_model_location_area5_g_t
 * Discards the current value of @a location_area5_g and moves the value of @a other
 * into @a location_area5_g. This will leave @a other as an empty reference.
 *
 * @param location_area5_g The LocationArea5G object to move @a other into.
 * @param other The LocationArea5G to move the value from.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_move(data_collection_model_location_area5_g_t *location_area5_g, data_collection_model_location_area5_g_t *other);

/** Delete a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 * Destroys the reference to the LocationArea5G object and frees the value of LocationArea5G if this is the last reference.
 *
 * @param location_area5_g The LocationArea5G to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_location_area5_g_free(data_collection_model_location_area5_g_t *location_area5_g);

/** Get a cJSON tree representation of a LocationArea5G
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * Create a cJSON tree representation of the LocationArea5G object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param location_area5_g The LocationArea5G to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_location_area5_g_toJSON(const data_collection_model_location_area5_g_t *location_area5_g, bool as_request);

/** Parse a cJSON tree into a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * Attempts to interpret a cJSON tree as a LocationArea5G API request or response (dependent on @a as_request value). If successful
 * will return a new referenced LocationArea5G object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new LocationArea5G object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two LocationArea5G objects to see if they are equivalent
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param location_area5_g The first LocationArea5G object to compare.
 * @param other_location_area5_g The second LocationArea5G object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_area5_g_is_equal_to(const data_collection_model_location_area5_g_t *location_area5_g, const data_collection_model_location_area5_g_t *other_location_area5_g);


/** Check if the geographicAreas field of a LocationArea5G object is set
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 *
 * @return `true` if the optional geographicAreas field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_area5_g_has_geographic_areas(const data_collection_model_location_area5_g_t *location_area5_g);


/** Get the value of the geographicAreas field of a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 *
 * @return the value current set for the geographicAreas field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_location_area5_g_get_geographic_areas(const data_collection_model_location_area5_g_t *location_area5_g);

/** Set the value of the geographicAreas field in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to set the field in.
 * @param p_geographic_areas The value to copy into the LocationArea5G object.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_geographic_areas(data_collection_model_location_area5_g_t *location_area5_g, const ogs_list_t* p_geographic_areas);

/** Move a value to the geographicAreas field in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to set the field in.
 * @param p_geographic_areas The value to move into the LocationArea5G object.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_geographic_areas_move(data_collection_model_location_area5_g_t *location_area5_g, ogs_list_t* p_geographic_areas);

/** Add a new item to the geographicAreas array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to add the array item to.
 * @param geographic_areas The value to add.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_add_geographic_areas(data_collection_model_location_area5_g_t *location_area5_g, data_collection_model_geographic_area_t* geographic_areas);

/** Remove an item from the geographicAreas array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to remove the array value from.
 * @param geographic_areas The value to remove.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_remove_geographic_areas(data_collection_model_location_area5_g_t *location_area5_g, const data_collection_model_geographic_area_t* geographic_areas);

/** Get an item from the geographicAreas array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_location_area5_g_get_entry_geographic_areas(const data_collection_model_location_area5_g_t *location_area5_g, size_t idx);

/** Remove all entries from the geographicAreas array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to empty geographicAreas for.
 *
 * @return @a location_area5_g
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_clear_geographic_areas(data_collection_model_location_area5_g_t *location_area5_g);

/** Check if the civicAddresses field of a LocationArea5G object is set
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 *
 * @return `true` if the optional civicAddresses field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_area5_g_has_civic_addresses(const data_collection_model_location_area5_g_t *location_area5_g);


/** Get the value of the civicAddresses field of a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 *
 * @return the value current set for the civicAddresses field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_location_area5_g_get_civic_addresses(const data_collection_model_location_area5_g_t *location_area5_g);

/** Set the value of the civicAddresses field in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to set the field in.
 * @param p_civic_addresses The value to copy into the LocationArea5G object.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_civic_addresses(data_collection_model_location_area5_g_t *location_area5_g, const ogs_list_t* p_civic_addresses);

/** Move a value to the civicAddresses field in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to set the field in.
 * @param p_civic_addresses The value to move into the LocationArea5G object.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_civic_addresses_move(data_collection_model_location_area5_g_t *location_area5_g, ogs_list_t* p_civic_addresses);

/** Add a new item to the civicAddresses array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to add the array item to.
 * @param civic_addresses The value to add.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_add_civic_addresses(data_collection_model_location_area5_g_t *location_area5_g, data_collection_model_civic_address_t* civic_addresses);

/** Remove an item from the civicAddresses array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to remove the array value from.
 * @param civic_addresses The value to remove.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_remove_civic_addresses(data_collection_model_location_area5_g_t *location_area5_g, const data_collection_model_civic_address_t* civic_addresses);

/** Get an item from the civicAddresses array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_civic_address_t* data_collection_model_location_area5_g_get_entry_civic_addresses(const data_collection_model_location_area5_g_t *location_area5_g, size_t idx);

/** Remove all entries from the civicAddresses array in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to empty civicAddresses for.
 *
 * @return @a location_area5_g
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_clear_civic_addresses(data_collection_model_location_area5_g_t *location_area5_g);

/** Check if the nwAreaInfo field of a LocationArea5G object is set
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 *
 * @return `true` if the optional nwAreaInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_area5_g_has_nw_area_info(const data_collection_model_location_area5_g_t *location_area5_g);


/** Get the value of the nwAreaInfo field of a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to examine.
 *
 * @return the value current set for the nwAreaInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_area_info_t* data_collection_model_location_area5_g_get_nw_area_info(const data_collection_model_location_area5_g_t *location_area5_g);

/** Set the value of the nwAreaInfo field in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to set the field in.
 * @param p_nw_area_info The value to copy into the LocationArea5G object.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_nw_area_info(data_collection_model_location_area5_g_t *location_area5_g, const data_collection_model_network_area_info_t* p_nw_area_info);

/** Move a value to the nwAreaInfo field in a LocationArea5G object
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * @param location_area5_g The LocationArea5G object to set the field in.
 * @param p_nw_area_info The value to move into the LocationArea5G object.
 *
 * @return @a location_area5_g.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_nw_area_info_move(data_collection_model_location_area5_g_t *location_area5_g, data_collection_model_network_area_info_t* p_nw_area_info);

/** lnode helper for generating ogs_list_t nodes's of type LocationArea5G
 * \public \memberof data_collection_model_location_area5_g_t
 *
 * Creates a new data_collection_lnode_t object containing the @a location_area5_g object.
 * The @a location_area5_g will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param location_area5_g The LocationArea5G object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a location_area5_g
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_location_area5_g_make_lnode(data_collection_model_location_area5_g_t *location_area5_g);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCATION_AREA5_G_H_ */

