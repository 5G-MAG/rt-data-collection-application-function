#ifndef _DATA_COLLECTION_POLYGON_H_
#define _DATA_COLLECTION_POLYGON_H_

/**********************************************************************************************************************************
 * Polygon - Public C interface to the Polygon object
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
#include "GADShape.h"
#include "SupportedGADShapes.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP Polygon object reference
 */
typedef struct data_collection_model_polygon_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_polygon_t;



/** Create a new Polygon
 * \public \memberof data_collection_model_polygon_t
 * @return a new Polygon object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_create();

/** Create a new copy of a Polygon object
 * \public \memberof data_collection_model_polygon_t
 * Creates a new copy of the given @a other object
 * @param other The Polygon to copy.
 * @return a new Polygon object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_create_copy(const data_collection_model_polygon_t *other);

/** Create a new reference of a Polygon object
 * \public \memberof data_collection_model_polygon_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Polygon to create a new reference to.
 * @return a new Polygon object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_create_move(data_collection_model_polygon_t *other);

/** Copy the value of another Polygon into this object
 * \public \memberof data_collection_model_polygon_t
 * Copies the value of @a other {{classname} object into @a polygon.
 * @param polygon The Polygon object to copy @a other into.
 * @param other The Polygon to copy the value from.
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_copy(data_collection_model_polygon_t *polygon, const data_collection_model_polygon_t *other);

/** Move the value of another Polygon into this object
 * \public \memberof data_collection_model_polygon_t
 * Discards the current value of @a polygon and moves the value of @a other
 * into @a polygon. This will leave @a other as an empty reference.
 *
 * @param polygon The Polygon object to move @a other into.
 * @param other The Polygon to move the value from.
 *
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_move(data_collection_model_polygon_t *polygon, data_collection_model_polygon_t *other);

/** Delete a Polygon object
 * \public \memberof data_collection_model_polygon_t
 * Destroys the reference to the Polygon object and frees the value of Polygon if this is the last reference.
 *
 * @param polygon The Polygon to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_polygon_free(data_collection_model_polygon_t *polygon);

/** Get a cJSON tree representation of a Polygon
 * \public \memberof data_collection_model_polygon_t
 *
 * Create a cJSON tree representation of the Polygon object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param polygon The Polygon to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_polygon_toJSON(const data_collection_model_polygon_t *polygon, bool as_request);

/** Parse a cJSON tree into a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * Attempts to interpret a cJSON tree as a Polygon API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Polygon object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Polygon object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Polygon objects to see if they are equivalent
 * \public \memberof data_collection_model_polygon_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param polygon The first Polygon object to compare.
 * @param other_polygon The second Polygon object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_polygon_is_equal_to(const data_collection_model_polygon_t *polygon, const data_collection_model_polygon_t *other_polygon);



/** Get the value of the shape field of a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_polygon_get_shape(const data_collection_model_polygon_t *polygon);

/** Set the value of the shape field in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to set the field in.
 * @param p_shape The value to copy into the Polygon object.
 *
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_shape(data_collection_model_polygon_t *polygon, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to set the field in.
 * @param p_shape The value to move into the Polygon object.
 *
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_shape_move(data_collection_model_polygon_t *polygon, data_collection_model_supported_gad_shapes_t* p_shape);


/** Get the value of the pointList field of a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to examine.
 *
 * @return the value current set for the pointList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_polygon_get_point_list(const data_collection_model_polygon_t *polygon);

/** Set the value of the pointList field in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to set the field in.
 * @param p_point_list The value to copy into the Polygon object.
 *
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_point_list(data_collection_model_polygon_t *polygon, const ogs_list_t* p_point_list);

/** Move a value to the pointList field in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to set the field in.
 * @param p_point_list The value to move into the Polygon object.
 *
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_point_list_move(data_collection_model_polygon_t *polygon, ogs_list_t* p_point_list);

/** Add a new item to the pointList array in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to add the array item to.
 * @param point_list The value to add.
 *
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_add_point_list(data_collection_model_polygon_t *polygon, data_collection_model_geographical_coordinates_t* point_list);

/** Remove an item from the pointList array in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to remove the array value from.
 * @param point_list The value to remove.
 *
 * @return @a polygon.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_remove_point_list(data_collection_model_polygon_t *polygon, const data_collection_model_geographical_coordinates_t* point_list);

/** Get an item from the pointList array in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_polygon_get_entry_point_list(const data_collection_model_polygon_t *polygon, size_t idx);

/** Remove all entries from the pointList array in a Polygon object
 * \public \memberof data_collection_model_polygon_t
 *
 * @param polygon The Polygon object to empty pointList for.
 *
 * @return @a polygon
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_clear_point_list(data_collection_model_polygon_t *polygon);

/** lnode helper for generating ogs_list_t nodes's of type Polygon
 * \public \memberof data_collection_model_polygon_t
 *
 * Creates a new data_collection_lnode_t object containing the @a polygon object.
 * The @a polygon will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param polygon The Polygon object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a polygon
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_polygon_make_lnode(data_collection_model_polygon_t *polygon);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POLYGON_H_ */

