#ifndef _DATA_COLLECTION_GNSS_SERV_AREA_H_
#define _DATA_COLLECTION_GNSS_SERV_AREA_H_

/**********************************************************************************************************************************
 * GNSSServArea - Public C interface to the GNSSServArea object
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

#include "Tai.h"
#include "GeographicArea.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP GNSSServArea object reference
 */
typedef struct data_collection_model_gnss_serv_area_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_gnss_serv_area_t;



/** Create a new GNSSServArea.
 * \public \memberof data_collection_model_gnss_serv_area_t
 * @return a new GNSSServArea object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create();

/** Create a new GNSSServArea reference.
 * \public \memberof data_collection_model_gnss_serv_area_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The GNSSServArea to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create_ref(const data_collection_model_gnss_serv_area_t *other);

/** Create a new copy of a GNSSServArea object.
 * \public \memberof data_collection_model_gnss_serv_area_t
 * Creates a new copy of the given @a other object
 * @param other The GNSSServArea to copy.
 * @return a new GNSSServArea object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create_copy(const data_collection_model_gnss_serv_area_t *other);

/** Create a new reference of a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GNSSServArea to create a new reference to.
 * @return a new GNSSServArea object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create_move(data_collection_model_gnss_serv_area_t *other);

/** Copy the value of another GNSSServArea into this object
 * \public \memberof data_collection_model_gnss_serv_area_t
 * Copies the value of @a other {{classname} object into @a gnss_serv_area.
 * @param gnss_serv_area The GNSSServArea object to copy @a other into.
 * @param other The GNSSServArea to copy the value from.
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_copy(data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_gnss_serv_area_t *other);

/** Move the value of another GNSSServArea into this object
 * \public \memberof data_collection_model_gnss_serv_area_t
 * Discards the current value of @a gnss_serv_area and moves the value of @a other
 * into @a gnss_serv_area. This will leave @a other as an empty reference.
 *
 * @param gnss_serv_area The GNSSServArea object to move @a other into.
 * @param other The GNSSServArea to move the value from.
 *
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_move(data_collection_model_gnss_serv_area_t *gnss_serv_area, data_collection_model_gnss_serv_area_t *other);

/** Delete a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 * Destroys the reference to the GNSSServArea object and frees the value of GNSSServArea if this is the last reference.
 *
 * @param gnss_serv_area The GNSSServArea to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_serv_area_free(data_collection_model_gnss_serv_area_t *gnss_serv_area);

/** Get a cJSON tree representation of a GNSSServArea
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * Create a cJSON tree representation of the GNSSServArea object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param gnss_serv_area The GNSSServArea to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_serv_area_toJSON(const data_collection_model_gnss_serv_area_t *gnss_serv_area, bool as_request);

/** Parse a cJSON tree into a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * Attempts to interpret a cJSON tree as a GNSSServArea API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GNSSServArea object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GNSSServArea object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GNSSServArea objects to see if they are equivalent
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param gnss_serv_area The first GNSSServArea object to compare.
 * @param other_gnss_serv_area The second GNSSServArea object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_serv_area_is_equal_to(const data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_gnss_serv_area_t *other_gnss_serv_area);


/** Check if the geographicalArea field of a GNSSServArea object is set
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to examine.
 *
 * @return `true` if the optional geographicalArea field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_serv_area_has_geographical_area(const data_collection_model_gnss_serv_area_t *gnss_serv_area);


/** Get the value of the geographicalArea field of a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to examine.
 *
 * @return the value current set for the geographicalArea field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_gnss_serv_area_get_geographical_area(const data_collection_model_gnss_serv_area_t *gnss_serv_area);

/** Set the value of the geographicalArea field in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to set the field in.
 * @param p_geographical_area The value to copy into the GNSSServArea object.
 *
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_geographical_area(data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_geographic_area_t* p_geographical_area);

/** Move a value to the geographicalArea field in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to set the field in.
 * @param p_geographical_area The value to move into the GNSSServArea object.
 *
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_geographical_area_move(data_collection_model_gnss_serv_area_t *gnss_serv_area, data_collection_model_geographic_area_t* p_geographical_area);

/** Check if the taiList field of a GNSSServArea object is set
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to examine.
 *
 * @return `true` if the optional taiList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_serv_area_has_tai_list(const data_collection_model_gnss_serv_area_t *gnss_serv_area);


/** Get the value of the taiList field of a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to examine.
 *
 * @return the value current set for the taiList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_gnss_serv_area_get_tai_list(const data_collection_model_gnss_serv_area_t *gnss_serv_area);

/** Set the value of the taiList field in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to set the field in.
 * @param p_tai_list The value to copy into the GNSSServArea object.
 *
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area, const ogs_list_t* p_tai_list);

/** Move a value to the taiList field in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to set the field in.
 * @param p_tai_list The value to move into the GNSSServArea object.
 *
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_tai_list_move(data_collection_model_gnss_serv_area_t *gnss_serv_area, ogs_list_t* p_tai_list);

/** Add a new item to the taiList array in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to add the array item to.
 * @param tai_list The value to add.
 *
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_add_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area, data_collection_model_tai_t* tai_list);

/** Remove an item from the taiList array in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to remove the array value from.
 * @param tai_list The value to remove.
 *
 * @return @a gnss_serv_area.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_remove_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_tai_t* tai_list);

/** Get an item from the taiList array in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_tai_t* data_collection_model_gnss_serv_area_get_entry_tai_list(const data_collection_model_gnss_serv_area_t *gnss_serv_area, size_t idx);

/** Remove all entries from the taiList array in a GNSSServArea object
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * @param gnss_serv_area The GNSSServArea object to empty taiList for.
 *
 * @return @a gnss_serv_area
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_clear_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area);

/** lnode helper for generating ogs_list_t nodes's of type GNSSServArea
 * \public \memberof data_collection_model_gnss_serv_area_t
 *
 * Creates a new data_collection_lnode_t object containing the @a gnss_serv_area object.
 * The @a gnss_serv_area will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param gnss_serv_area The GNSSServArea object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a gnss_serv_area
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_serv_area_make_lnode(data_collection_model_gnss_serv_area_t *gnss_serv_area);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNSS_SERV_AREA_H_ */

