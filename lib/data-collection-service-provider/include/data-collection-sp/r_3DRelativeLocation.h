#ifndef _DATA_COLLECTION_R_3_D_RELATIVE_LOCATION_H_
#define _DATA_COLLECTION_R_3_D_RELATIVE_LOCATION_H_

/**********************************************************************************************************************************
 * r_3DRelativeLocation - Public C interface to the r_3DRelativeLocation object
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

/** A 3GPP r_3DRelativeLocation object reference
 */
typedef struct data_collection_model_r_3_d_relative_location_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_r_3_d_relative_location_t;



/** Create a new r_3DRelativeLocation
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 * @return a new r_3DRelativeLocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_create();

/** Create a new copy of a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 * Creates a new copy of the given @a other object
 * @param other The r_3DRelativeLocation to copy.
 * @return a new r_3DRelativeLocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_create_copy(const data_collection_model_r_3_d_relative_location_t *other);

/** Create a new reference of a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 * Creates a reference to the same underlying @a other object.
 * @param other The r_3DRelativeLocation to create a new reference to.
 * @return a new r_3DRelativeLocation object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_create_move(data_collection_model_r_3_d_relative_location_t *other);

/** Copy the value of another r_3DRelativeLocation into this object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 * Copies the value of @a other {{classname} object into @a r_3_d_relative_location.
 * @param r_3_d_relative_location The r_3DRelativeLocation object to copy @a other into.
 * @param other The r_3DRelativeLocation to copy the value from.
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_copy(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, const data_collection_model_r_3_d_relative_location_t *other);

/** Move the value of another r_3DRelativeLocation into this object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 * Discards the current value of @a r_3_d_relative_location and moves the value of @a other
 * into @a r_3_d_relative_location. This will leave @a other as an empty reference.
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to move @a other into.
 * @param other The r_3DRelativeLocation to move the value from.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_move(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, data_collection_model_r_3_d_relative_location_t *other);

/** Delete a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 * Destroys the reference to the r_3DRelativeLocation object and frees the value of r_3DRelativeLocation if this is the last reference.
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_r_3_d_relative_location_free(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);

/** Get a cJSON tree representation of a r_3DRelativeLocation
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * Create a cJSON tree representation of the r_3DRelativeLocation object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_r_3_d_relative_location_toJSON(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, bool as_request);

/** Parse a cJSON tree into a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * Attempts to interpret a cJSON tree as a r_3DRelativeLocation API request or response (dependent on @a as_request value). If successful
 * will return a new referenced r_3DRelativeLocation object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new r_3DRelativeLocation object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two r_3DRelativeLocation objects to see if they are equivalent
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param r_3_d_relative_location The first r_3DRelativeLocation object to compare.
 * @param other_r_3_d_relative_location The second r_3DRelativeLocation object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_3_d_relative_location_is_equal_to(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, const data_collection_model_r_3_d_relative_location_t *other_r_3_d_relative_location);


/** Check if the semiMinor field of a r_3DRelativeLocation object is set
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return `true` if the optional semiMinor field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_3_d_relative_location_has_semi_minor(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);


/** Get the value of the semiMinor field of a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return the value current set for the semiMinor field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_r_3_d_relative_location_get_semi_minor(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);

/** Set the value of the semiMinor field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_semi_minor The value to copy into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_semi_minor(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, const float p_semi_minor);

/** Move a value to the semiMinor field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_semi_minor The value to move into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_semi_minor_move(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, float p_semi_minor);

/** Check if the semiMajor field of a r_3DRelativeLocation object is set
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return `true` if the optional semiMajor field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_3_d_relative_location_has_semi_major(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);


/** Get the value of the semiMajor field of a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return the value current set for the semiMajor field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_r_3_d_relative_location_get_semi_major(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);

/** Set the value of the semiMajor field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_semi_major The value to copy into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_semi_major(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, const float p_semi_major);

/** Move a value to the semiMajor field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_semi_major The value to move into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_semi_major_move(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, float p_semi_major);

/** Check if the verticalUncertainty field of a r_3DRelativeLocation object is set
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return `true` if the optional verticalUncertainty field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_3_d_relative_location_has_vertical_uncertainty(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);


/** Get the value of the verticalUncertainty field of a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return the value current set for the verticalUncertainty field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_r_3_d_relative_location_get_vertical_uncertainty(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);

/** Set the value of the verticalUncertainty field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_vertical_uncertainty The value to copy into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_vertical_uncertainty(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, const float p_vertical_uncertainty);

/** Move a value to the verticalUncertainty field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_vertical_uncertainty The value to move into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_vertical_uncertainty_move(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, float p_vertical_uncertainty);

/** Check if the orientationAngle field of a r_3DRelativeLocation object is set
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return `true` if the optional orientationAngle field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_r_3_d_relative_location_has_orientation_angle(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);


/** Get the value of the orientationAngle field of a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to examine.
 *
 * @return the value current set for the orientationAngle field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_r_3_d_relative_location_get_orientation_angle(const data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);

/** Set the value of the orientationAngle field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_orientation_angle The value to copy into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_orientation_angle(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, const int32_t p_orientation_angle);

/** Move a value to the orientationAngle field in a r_3DRelativeLocation object
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to set the field in.
 * @param p_orientation_angle The value to move into the r_3DRelativeLocation object.
 *
 * @return @a r_3_d_relative_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_r_3_d_relative_location_t *data_collection_model_r_3_d_relative_location_set_orientation_angle_move(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location, int32_t p_orientation_angle);

/** lnode helper for generating ogs_list_t nodes's of type r_3DRelativeLocation
 * \public \memberof data_collection_model_r_3_d_relative_location_t
 *
 * Creates a new data_collection_lnode_t object containing the @a r_3_d_relative_location object.
 * The @a r_3_d_relative_location will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param r_3_d_relative_location The r_3DRelativeLocation object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a r_3_d_relative_location
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_r_3_d_relative_location_make_lnode(data_collection_model_r_3_d_relative_location_t *r_3_d_relative_location);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_R_3_D_RELATIVE_LOCATION_H_ */

