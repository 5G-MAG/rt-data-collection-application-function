#ifndef _DATA_COLLECTION_UNCERTAINTY_ELLIPSE_H_
#define _DATA_COLLECTION_UNCERTAINTY_ELLIPSE_H_

/**********************************************************************************************************************************
 * UncertaintyEllipse - Public C interface to the UncertaintyEllipse object
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

/** A 3GPP UncertaintyEllipse object reference
 */
typedef struct data_collection_model_uncertainty_ellipse_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_uncertainty_ellipse_t;



/** Create a new UncertaintyEllipse
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 * @return a new UncertaintyEllipse object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create();

/** Create a new copy of a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 * Creates a new copy of the given @a other object
 * @param other The UncertaintyEllipse to copy.
 * @return a new UncertaintyEllipse object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create_copy(const data_collection_model_uncertainty_ellipse_t *other);

/** Create a new reference of a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UncertaintyEllipse to create a new reference to.
 * @return a new UncertaintyEllipse object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create_move(data_collection_model_uncertainty_ellipse_t *other);

/** Copy the value of another UncertaintyEllipse into this object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 * Copies the value of @a other {{classname} object into @a uncertainty_ellipse.
 * @param uncertainty_ellipse The UncertaintyEllipse object to copy @a other into.
 * @param other The UncertaintyEllipse to copy the value from.
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_copy(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, const data_collection_model_uncertainty_ellipse_t *other);

/** Move the value of another UncertaintyEllipse into this object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 * Discards the current value of @a uncertainty_ellipse and moves the value of @a other
 * into @a uncertainty_ellipse. This will leave @a other as an empty reference.
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to move @a other into.
 * @param other The UncertaintyEllipse to move the value from.
 *
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_move(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, data_collection_model_uncertainty_ellipse_t *other);

/** Delete a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 * Destroys the reference to the UncertaintyEllipse object and frees the value of UncertaintyEllipse if this is the last reference.
 *
 * @param uncertainty_ellipse The UncertaintyEllipse to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_uncertainty_ellipse_free(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse);

/** Get a cJSON tree representation of a UncertaintyEllipse
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * Create a cJSON tree representation of the UncertaintyEllipse object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param uncertainty_ellipse The UncertaintyEllipse to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_uncertainty_ellipse_toJSON(const data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, bool as_request);

/** Parse a cJSON tree into a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * Attempts to interpret a cJSON tree as a UncertaintyEllipse API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UncertaintyEllipse object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UncertaintyEllipse object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UncertaintyEllipse objects to see if they are equivalent
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param uncertainty_ellipse The first UncertaintyEllipse object to compare.
 * @param other_uncertainty_ellipse The second UncertaintyEllipse object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_uncertainty_ellipse_is_equal_to(const data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, const data_collection_model_uncertainty_ellipse_t *other_uncertainty_ellipse);



/** Get the value of the semiMajor field of a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to examine.
 *
 * @return the value current set for the semiMajor field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_uncertainty_ellipse_get_semi_major(const data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse);

/** Set the value of the semiMajor field in a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to set the field in.
 * @param p_semi_major The value to copy into the UncertaintyEllipse object.
 *
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_major(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, const float p_semi_major);

/** Move a value to the semiMajor field in a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to set the field in.
 * @param p_semi_major The value to move into the UncertaintyEllipse object.
 *
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_major_move(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, float p_semi_major);


/** Get the value of the semiMinor field of a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to examine.
 *
 * @return the value current set for the semiMinor field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_uncertainty_ellipse_get_semi_minor(const data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse);

/** Set the value of the semiMinor field in a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to set the field in.
 * @param p_semi_minor The value to copy into the UncertaintyEllipse object.
 *
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_minor(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, const float p_semi_minor);

/** Move a value to the semiMinor field in a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to set the field in.
 * @param p_semi_minor The value to move into the UncertaintyEllipse object.
 *
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_minor_move(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, float p_semi_minor);


/** Get the value of the orientationMajor field of a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to examine.
 *
 * @return the value current set for the orientationMajor field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_uncertainty_ellipse_get_orientation_major(const data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse);

/** Set the value of the orientationMajor field in a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to set the field in.
 * @param p_orientation_major The value to copy into the UncertaintyEllipse object.
 *
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_orientation_major(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, const int32_t p_orientation_major);

/** Move a value to the orientationMajor field in a UncertaintyEllipse object
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to set the field in.
 * @param p_orientation_major The value to move into the UncertaintyEllipse object.
 *
 * @return @a uncertainty_ellipse.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_orientation_major_move(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, int32_t p_orientation_major);

/** lnode helper for generating ogs_list_t nodes's of type UncertaintyEllipse
 * \public \memberof data_collection_model_uncertainty_ellipse_t
 *
 * Creates a new data_collection_lnode_t object containing the @a uncertainty_ellipse object.
 * The @a uncertainty_ellipse will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param uncertainty_ellipse The UncertaintyEllipse object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a uncertainty_ellipse
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_uncertainty_ellipse_make_lnode(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UNCERTAINTY_ELLIPSE_H_ */

