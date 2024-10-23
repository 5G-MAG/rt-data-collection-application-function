#ifndef _DATA_COLLECTION_GAD_SHAPE_H_
#define _DATA_COLLECTION_GAD_SHAPE_H_

/**********************************************************************************************************************************
 * GADShape - Public C interface to the GADShape object
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

#include "SupportedGADShapes.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP GADShape object reference
 */
typedef struct data_collection_model_gad_shape_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_gad_shape_t;



/** Create a new GADShape
 * \public \memberof data_collection_model_gad_shape_t
 * @return a new GADShape object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create();

/** Create a new copy of a GADShape object
 * \public \memberof data_collection_model_gad_shape_t
 * Creates a new copy of the given @a other object
 * @param other The GADShape to copy.
 * @return a new GADShape object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_copy(const data_collection_model_gad_shape_t *other);

/** Create a new reference of a GADShape object
 * \public \memberof data_collection_model_gad_shape_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GADShape to create a new reference to.
 * @return a new GADShape object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_move(data_collection_model_gad_shape_t *other);

/** Copy the value of another GADShape into this object
 * \public \memberof data_collection_model_gad_shape_t
 * Copies the value of @a other {{classname} object into @a gad_shape.
 * @param gad_shape The GADShape object to copy @a other into.
 * @param other The GADShape to copy the value from.
 * @return @a gad_shape.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_copy(data_collection_model_gad_shape_t *gad_shape, const data_collection_model_gad_shape_t *other);

/** Move the value of another GADShape into this object
 * \public \memberof data_collection_model_gad_shape_t
 * Discards the current value of @a gad_shape and moves the value of @a other
 * into @a gad_shape. This will leave @a other as an empty reference.
 *
 * @param gad_shape The GADShape object to move @a other into.
 * @param other The GADShape to move the value from.
 *
 * @return @a gad_shape.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_move(data_collection_model_gad_shape_t *gad_shape, data_collection_model_gad_shape_t *other);

/** Delete a GADShape object
 * \public \memberof data_collection_model_gad_shape_t
 * Destroys the reference to the GADShape object and frees the value of GADShape if this is the last reference.
 *
 * @param gad_shape The GADShape to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gad_shape_free(data_collection_model_gad_shape_t *gad_shape);

/** Get a cJSON tree representation of a GADShape
 * \public \memberof data_collection_model_gad_shape_t
 *
 * Create a cJSON tree representation of the GADShape object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param gad_shape The GADShape to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gad_shape_toJSON(const data_collection_model_gad_shape_t *gad_shape, bool as_request);

/** Parse a cJSON tree into a GADShape object
 * \public \memberof data_collection_model_gad_shape_t
 *
 * Attempts to interpret a cJSON tree as a GADShape API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GADShape object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GADShape object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GADShape objects to see if they are equivalent
 * \public \memberof data_collection_model_gad_shape_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param gad_shape The first GADShape object to compare.
 * @param other_gad_shape The second GADShape object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gad_shape_is_equal_to(const data_collection_model_gad_shape_t *gad_shape, const data_collection_model_gad_shape_t *other_gad_shape);



/** Get the value of the shape field of a GADShape object
 * \public \memberof data_collection_model_gad_shape_t
 *
 * @param gad_shape The GADShape object to examine.
 *
 * @return the value current set for the shape field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_gad_shape_get_shape(const data_collection_model_gad_shape_t *gad_shape);

/** Set the value of the shape field in a GADShape object
 * \public \memberof data_collection_model_gad_shape_t
 *
 * @param gad_shape The GADShape object to set the field in.
 * @param p_shape The value to copy into the GADShape object.
 *
 * @return @a gad_shape.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape(data_collection_model_gad_shape_t *gad_shape, const data_collection_model_supported_gad_shapes_t* p_shape);

/** Move a value to the shape field in a GADShape object
 * \public \memberof data_collection_model_gad_shape_t
 *
 * @param gad_shape The GADShape object to set the field in.
 * @param p_shape The value to move into the GADShape object.
 *
 * @return @a gad_shape.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape_move(data_collection_model_gad_shape_t *gad_shape, data_collection_model_supported_gad_shapes_t* p_shape);

/** lnode helper for generating ogs_list_t nodes's of type GADShape
 * \public \memberof data_collection_model_gad_shape_t
 *
 * Creates a new data_collection_lnode_t object containing the @a gad_shape object.
 * The @a gad_shape will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param gad_shape The GADShape object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a gad_shape
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gad_shape_make_lnode(data_collection_model_gad_shape_t *gad_shape);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GAD_SHAPE_H_ */

