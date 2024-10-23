#ifndef _DATA_COLLECTION_GEOGRAPHICAL_COORDINATES_H_
#define _DATA_COLLECTION_GEOGRAPHICAL_COORDINATES_H_

/**********************************************************************************************************************************
 * GeographicalCoordinates - Public C interface to the GeographicalCoordinates object
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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP GeographicalCoordinates object reference
 */
typedef struct data_collection_model_geographical_coordinates_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_geographical_coordinates_t;



/** Create a new GeographicalCoordinates
 * \public \memberof data_collection_model_geographical_coordinates_t
 * @return a new GeographicalCoordinates object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create();

/** Create a new copy of a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 * Creates a new copy of the given @a other object
 * @param other The GeographicalCoordinates to copy.
 * @return a new GeographicalCoordinates object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_copy(const data_collection_model_geographical_coordinates_t *other);

/** Create a new reference of a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GeographicalCoordinates to create a new reference to.
 * @return a new GeographicalCoordinates object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_move(data_collection_model_geographical_coordinates_t *other);

/** Copy the value of another GeographicalCoordinates into this object
 * \public \memberof data_collection_model_geographical_coordinates_t
 * Copies the value of @a other {{classname} object into @a geographical_coordinates.
 * @param geographical_coordinates The GeographicalCoordinates object to copy @a other into.
 * @param other The GeographicalCoordinates to copy the value from.
 * @return @a geographical_coordinates.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_copy(data_collection_model_geographical_coordinates_t *geographical_coordinates, const data_collection_model_geographical_coordinates_t *other);

/** Move the value of another GeographicalCoordinates into this object
 * \public \memberof data_collection_model_geographical_coordinates_t
 * Discards the current value of @a geographical_coordinates and moves the value of @a other
 * into @a geographical_coordinates. This will leave @a other as an empty reference.
 *
 * @param geographical_coordinates The GeographicalCoordinates object to move @a other into.
 * @param other The GeographicalCoordinates to move the value from.
 *
 * @return @a geographical_coordinates.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, data_collection_model_geographical_coordinates_t *other);

/** Delete a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 * Destroys the reference to the GeographicalCoordinates object and frees the value of GeographicalCoordinates if this is the last reference.
 *
 * @param geographical_coordinates The GeographicalCoordinates to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_geographical_coordinates_free(data_collection_model_geographical_coordinates_t *geographical_coordinates);

/** Get a cJSON tree representation of a GeographicalCoordinates
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * Create a cJSON tree representation of the GeographicalCoordinates object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param geographical_coordinates The GeographicalCoordinates to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_geographical_coordinates_toJSON(const data_collection_model_geographical_coordinates_t *geographical_coordinates, bool as_request);

/** Parse a cJSON tree into a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * Attempts to interpret a cJSON tree as a GeographicalCoordinates API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GeographicalCoordinates object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GeographicalCoordinates object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GeographicalCoordinates objects to see if they are equivalent
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param geographical_coordinates The first GeographicalCoordinates object to compare.
 * @param other_geographical_coordinates The second GeographicalCoordinates object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_geographical_coordinates_is_equal_to(const data_collection_model_geographical_coordinates_t *geographical_coordinates, const data_collection_model_geographical_coordinates_t *other_geographical_coordinates);



/** Get the value of the lon field of a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * @param geographical_coordinates The GeographicalCoordinates object to examine.
 *
 * @return the value current set for the lon field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographical_coordinates_get_lon(const data_collection_model_geographical_coordinates_t *geographical_coordinates);

/** Set the value of the lon field in a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * @param geographical_coordinates The GeographicalCoordinates object to set the field in.
 * @param p_lon The value to copy into the GeographicalCoordinates object.
 *
 * @return @a geographical_coordinates.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon(data_collection_model_geographical_coordinates_t *geographical_coordinates, const double p_lon);

/** Move a value to the lon field in a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * @param geographical_coordinates The GeographicalCoordinates object to set the field in.
 * @param p_lon The value to move into the GeographicalCoordinates object.
 *
 * @return @a geographical_coordinates.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, double p_lon);


/** Get the value of the lat field of a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * @param geographical_coordinates The GeographicalCoordinates object to examine.
 *
 * @return the value current set for the lat field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographical_coordinates_get_lat(const data_collection_model_geographical_coordinates_t *geographical_coordinates);

/** Set the value of the lat field in a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * @param geographical_coordinates The GeographicalCoordinates object to set the field in.
 * @param p_lat The value to copy into the GeographicalCoordinates object.
 *
 * @return @a geographical_coordinates.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat(data_collection_model_geographical_coordinates_t *geographical_coordinates, const double p_lat);

/** Move a value to the lat field in a GeographicalCoordinates object
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * @param geographical_coordinates The GeographicalCoordinates object to set the field in.
 * @param p_lat The value to move into the GeographicalCoordinates object.
 *
 * @return @a geographical_coordinates.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, double p_lat);

/** lnode helper for generating ogs_list_t nodes's of type GeographicalCoordinates
 * \public \memberof data_collection_model_geographical_coordinates_t
 *
 * Creates a new data_collection_lnode_t object containing the @a geographical_coordinates object.
 * The @a geographical_coordinates will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param geographical_coordinates The GeographicalCoordinates object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a geographical_coordinates
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_geographical_coordinates_make_lnode(data_collection_model_geographical_coordinates_t *geographical_coordinates);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GEOGRAPHICAL_COORDINATES_H_ */

