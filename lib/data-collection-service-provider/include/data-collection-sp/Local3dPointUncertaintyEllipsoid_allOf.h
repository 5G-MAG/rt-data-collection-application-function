#ifndef _DATA_COLLECTION_LOCAL3D_POINT_UNCERTAINTY_ELLIPSOID_ALL_OF_H_
#define _DATA_COLLECTION_LOCAL3D_POINT_UNCERTAINTY_ELLIPSOID_ALL_OF_H_

/**********************************************************************************************************************************
 * Local3dPointUncertaintyEllipsoid_allOf - Public C interface to the Local3dPointUncertaintyEllipsoid_allOf object
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

#include "LocalOrigin.h"
#include "RelativeCartesianLocation.h"
#include "UncertaintyEllipsoid.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP Local3dPointUncertaintyEllipsoid_allOf object reference
 */
typedef struct data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t;



/** Create a new Local3dPointUncertaintyEllipsoid_allOf
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 * @return a new Local3dPointUncertaintyEllipsoid_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_create();

/** Create a new copy of a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 * Creates a new copy of the given @a other object
 * @param other The Local3dPointUncertaintyEllipsoid_allOf to copy.
 * @return a new Local3dPointUncertaintyEllipsoid_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_create_copy(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *other);

/** Create a new reference of a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Local3dPointUncertaintyEllipsoid_allOf to create a new reference to.
 * @return a new Local3dPointUncertaintyEllipsoid_allOf object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_create_move(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *other);

/** Copy the value of another Local3dPointUncertaintyEllipsoid_allOf into this object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 * Copies the value of @a other {{classname} object into @a local3d_point_uncertainty_ellipsoid_all_of.
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to copy @a other into.
 * @param other The Local3dPointUncertaintyEllipsoid_allOf to copy the value from.
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_copy(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *other);

/** Move the value of another Local3dPointUncertaintyEllipsoid_allOf into this object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 * Discards the current value of @a local3d_point_uncertainty_ellipsoid_all_of and moves the value of @a other
 * into @a local3d_point_uncertainty_ellipsoid_all_of. This will leave @a other as an empty reference.
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to move @a other into.
 * @param other The Local3dPointUncertaintyEllipsoid_allOf to move the value from.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_move(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *other);

/** Delete a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 * Destroys the reference to the Local3dPointUncertaintyEllipsoid_allOf object and frees the value of Local3dPointUncertaintyEllipsoid_allOf if this is the last reference.
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_free(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);

/** Get a cJSON tree representation of a Local3dPointUncertaintyEllipsoid_allOf
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * Create a cJSON tree representation of the Local3dPointUncertaintyEllipsoid_allOf object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_toJSON(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, bool as_request);

/** Parse a cJSON tree into a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * Attempts to interpret a cJSON tree as a Local3dPointUncertaintyEllipsoid_allOf API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Local3dPointUncertaintyEllipsoid_allOf object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Local3dPointUncertaintyEllipsoid_allOf object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Local3dPointUncertaintyEllipsoid_allOf objects to see if they are equivalent
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The first Local3dPointUncertaintyEllipsoid_allOf object to compare.
 * @param other_local3d_point_uncertainty_ellipsoid_all_of The second Local3dPointUncertaintyEllipsoid_allOf object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_is_equal_to(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *other_local3d_point_uncertainty_ellipsoid_all_of);



/** Get the value of the localOrigin field of a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to examine.
 *
 * @return the value current set for the localOrigin field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_local_origin_t* data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_get_local_origin(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);

/** Set the value of the localOrigin field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_local_origin The value to copy into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_local_origin(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, const data_collection_model_local_origin_t* p_local_origin);

/** Move a value to the localOrigin field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_local_origin The value to move into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_local_origin_move(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, data_collection_model_local_origin_t* p_local_origin);


/** Get the value of the point field of a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to examine.
 *
 * @return the value current set for the point field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_relative_cartesian_location_t* data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_get_point(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);

/** Set the value of the point field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_point The value to copy into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_point(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, const data_collection_model_relative_cartesian_location_t* p_point);

/** Move a value to the point field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_point The value to move into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_point_move(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, data_collection_model_relative_cartesian_location_t* p_point);


/** Get the value of the uncertaintyEllipsoid field of a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to examine.
 *
 * @return the value current set for the uncertaintyEllipsoid field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipsoid_t* data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_get_uncertainty_ellipsoid(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);

/** Set the value of the uncertaintyEllipsoid field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_uncertainty_ellipsoid The value to copy into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_uncertainty_ellipsoid(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, const data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid);

/** Move a value to the uncertaintyEllipsoid field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_uncertainty_ellipsoid The value to move into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_uncertainty_ellipsoid_move(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid);


/** Get the value of the confidence field of a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to examine.
 *
 * @return the value current set for the confidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_get_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);

/** Set the value of the confidence field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_confidence The value to copy into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_confidence(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, const int32_t p_confidence);

/** Move a value to the confidence field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_confidence The value to move into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_confidence_move(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, int32_t p_confidence);

/** Check if the vConfidence field of a Local3dPointUncertaintyEllipsoid_allOf object is set
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to examine.
 *
 * @return `true` if the optional vConfidence field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_has_v_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);


/** Get the value of the vConfidence field of a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to examine.
 *
 * @return the value current set for the vConfidence field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_get_v_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);

/** Set the value of the vConfidence field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_v_confidence The value to copy into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_v_confidence(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, const int32_t p_v_confidence);

/** Move a value to the vConfidence field in a Local3dPointUncertaintyEllipsoid_allOf object
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to set the field in.
 * @param p_v_confidence The value to move into the Local3dPointUncertaintyEllipsoid_allOf object.
 *
 * @return @a local3d_point_uncertainty_ellipsoid_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_set_v_confidence_move(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of, int32_t p_v_confidence);

/** lnode helper for generating ogs_list_t nodes's of type Local3dPointUncertaintyEllipsoid_allOf
 * \public \memberof data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t
 *
 * Creates a new data_collection_lnode_t object containing the @a local3d_point_uncertainty_ellipsoid_all_of object.
 * The @a local3d_point_uncertainty_ellipsoid_all_of will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param local3d_point_uncertainty_ellipsoid_all_of The Local3dPointUncertaintyEllipsoid_allOf object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a local3d_point_uncertainty_ellipsoid_all_of
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_make_lnode(data_collection_model_local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCAL3D_POINT_UNCERTAINTY_ELLIPSOID_ALL_OF_H_ */

