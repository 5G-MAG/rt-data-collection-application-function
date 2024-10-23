#ifndef _DATA_COLLECTION_LOCAL_ORIGIN_H_
#define _DATA_COLLECTION_LOCAL_ORIGIN_H_

/**********************************************************************************************************************************
 * LocalOrigin - Public C interface to the LocalOrigin object
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

#include "GeographicalCoordinates.h"
#include "GeographicArea.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP LocalOrigin object reference
 */
typedef struct data_collection_model_local_origin_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_local_origin_t;



/** Create a new LocalOrigin
 * \public \memberof data_collection_model_local_origin_t
 * @return a new LocalOrigin object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create();

/** Create a new copy of a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 * Creates a new copy of the given @a other object
 * @param other The LocalOrigin to copy.
 * @return a new LocalOrigin object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create_copy(const data_collection_model_local_origin_t *other);

/** Create a new reference of a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 * Creates a reference to the same underlying @a other object.
 * @param other The LocalOrigin to create a new reference to.
 * @return a new LocalOrigin object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create_move(data_collection_model_local_origin_t *other);

/** Copy the value of another LocalOrigin into this object
 * \public \memberof data_collection_model_local_origin_t
 * Copies the value of @a other {{classname} object into @a local_origin.
 * @param local_origin The LocalOrigin object to copy @a other into.
 * @param other The LocalOrigin to copy the value from.
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_copy(data_collection_model_local_origin_t *local_origin, const data_collection_model_local_origin_t *other);

/** Move the value of another LocalOrigin into this object
 * \public \memberof data_collection_model_local_origin_t
 * Discards the current value of @a local_origin and moves the value of @a other
 * into @a local_origin. This will leave @a other as an empty reference.
 *
 * @param local_origin The LocalOrigin object to move @a other into.
 * @param other The LocalOrigin to move the value from.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_move(data_collection_model_local_origin_t *local_origin, data_collection_model_local_origin_t *other);

/** Delete a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 * Destroys the reference to the LocalOrigin object and frees the value of LocalOrigin if this is the last reference.
 *
 * @param local_origin The LocalOrigin to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local_origin_free(data_collection_model_local_origin_t *local_origin);

/** Get a cJSON tree representation of a LocalOrigin
 * \public \memberof data_collection_model_local_origin_t
 *
 * Create a cJSON tree representation of the LocalOrigin object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param local_origin The LocalOrigin to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local_origin_toJSON(const data_collection_model_local_origin_t *local_origin, bool as_request);

/** Parse a cJSON tree into a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * Attempts to interpret a cJSON tree as a LocalOrigin API request or response (dependent on @a as_request value). If successful
 * will return a new referenced LocalOrigin object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new LocalOrigin object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two LocalOrigin objects to see if they are equivalent
 * \public \memberof data_collection_model_local_origin_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param local_origin The first LocalOrigin object to compare.
 * @param other_local_origin The second LocalOrigin object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_is_equal_to(const data_collection_model_local_origin_t *local_origin, const data_collection_model_local_origin_t *other_local_origin);



/** Get the value of the coordinateId field of a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to examine.
 *
 * @return the value current set for the coordinateId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_local_origin_get_coordinate_id(const data_collection_model_local_origin_t *local_origin);

/** Set the value of the coordinateId field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_coordinate_id The value to copy into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id(data_collection_model_local_origin_t *local_origin, const char* p_coordinate_id);

/** Move a value to the coordinateId field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_coordinate_id The value to move into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id_move(data_collection_model_local_origin_t *local_origin, char* p_coordinate_id);

/** Check if the point field of a LocalOrigin object is set
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to examine.
 *
 * @return `true` if the optional point field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_has_point(const data_collection_model_local_origin_t *local_origin);


/** Get the value of the point field of a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_local_origin_get_point(const data_collection_model_local_origin_t *local_origin);

/** Set the value of the point field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_point The value to copy into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_point(data_collection_model_local_origin_t *local_origin, const data_collection_model_geographical_coordinates_t* p_point);

/** Move a value to the point field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_point The value to move into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_point_move(data_collection_model_local_origin_t *local_origin, data_collection_model_geographical_coordinates_t* p_point);

/** Check if the area field of a LocalOrigin object is set
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to examine.
 *
 * @return `true` if the optional area field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_has_area(const data_collection_model_local_origin_t *local_origin);


/** Get the value of the area field of a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to examine.
 *
 * @return the value current set for the area field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_local_origin_get_area(const data_collection_model_local_origin_t *local_origin);

/** Set the value of the area field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_area The value to copy into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_area(data_collection_model_local_origin_t *local_origin, const data_collection_model_geographic_area_t* p_area);

/** Move a value to the area field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_area The value to move into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_area_move(data_collection_model_local_origin_t *local_origin, data_collection_model_geographic_area_t* p_area);

/** Check if the horizAxesOrientation field of a LocalOrigin object is set
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to examine.
 *
 * @return `true` if the optional horizAxesOrientation field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_has_horiz_axes_orientation(const data_collection_model_local_origin_t *local_origin);


/** Get the value of the horizAxesOrientation field of a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to examine.
 *
 * @return the value current set for the horizAxesOrientation field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local_origin_get_horiz_axes_orientation(const data_collection_model_local_origin_t *local_origin);

/** Set the value of the horizAxesOrientation field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_horiz_axes_orientation The value to copy into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_horiz_axes_orientation(data_collection_model_local_origin_t *local_origin, const int32_t p_horiz_axes_orientation);

/** Move a value to the horizAxesOrientation field in a LocalOrigin object
 * \public \memberof data_collection_model_local_origin_t
 *
 * @param local_origin The LocalOrigin object to set the field in.
 * @param p_horiz_axes_orientation The value to move into the LocalOrigin object.
 *
 * @return @a local_origin.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_horiz_axes_orientation_move(data_collection_model_local_origin_t *local_origin, int32_t p_horiz_axes_orientation);

/** lnode helper for generating ogs_list_t nodes's of type LocalOrigin
 * \public \memberof data_collection_model_local_origin_t
 *
 * Creates a new data_collection_lnode_t object containing the @a local_origin object.
 * The @a local_origin will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param local_origin The LocalOrigin object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a local_origin
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local_origin_make_lnode(data_collection_model_local_origin_t *local_origin);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCAL_ORIGIN_H_ */

