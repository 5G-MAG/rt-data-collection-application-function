#ifndef _DATA_COLLECTION_HORIZONTAL_VELOCITY_WITH_UNCERTAINTY_H_
#define _DATA_COLLECTION_HORIZONTAL_VELOCITY_WITH_UNCERTAINTY_H_

/**********************************************************************************************************************************
 * HorizontalVelocityWithUncertainty - Public C interface to the HorizontalVelocityWithUncertainty object
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

/** A 3GPP HorizontalVelocityWithUncertainty object reference
 */
typedef struct data_collection_model_horizontal_velocity_with_uncertainty_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_horizontal_velocity_with_uncertainty_t;



/** Create a new HorizontalVelocityWithUncertainty
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 * @return a new HorizontalVelocityWithUncertainty object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create();

/** Create a new copy of a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 * Creates a new copy of the given @a other object
 * @param other The HorizontalVelocityWithUncertainty to copy.
 * @return a new HorizontalVelocityWithUncertainty object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create_copy(const data_collection_model_horizontal_velocity_with_uncertainty_t *other);

/** Create a new reference of a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 * Creates a reference to the same underlying @a other object.
 * @param other The HorizontalVelocityWithUncertainty to create a new reference to.
 * @return a new HorizontalVelocityWithUncertainty object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create_move(data_collection_model_horizontal_velocity_with_uncertainty_t *other);

/** Copy the value of another HorizontalVelocityWithUncertainty into this object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 * Copies the value of @a other {{classname} object into @a horizontal_velocity_with_uncertainty.
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to copy @a other into.
 * @param other The HorizontalVelocityWithUncertainty to copy the value from.
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_copy(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const data_collection_model_horizontal_velocity_with_uncertainty_t *other);

/** Move the value of another HorizontalVelocityWithUncertainty into this object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 * Discards the current value of @a horizontal_velocity_with_uncertainty and moves the value of @a other
 * into @a horizontal_velocity_with_uncertainty. This will leave @a other as an empty reference.
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to move @a other into.
 * @param other The HorizontalVelocityWithUncertainty to move the value from.
 *
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, data_collection_model_horizontal_velocity_with_uncertainty_t *other);

/** Delete a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 * Destroys the reference to the HorizontalVelocityWithUncertainty object and frees the value of HorizontalVelocityWithUncertainty if this is the last reference.
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_horizontal_velocity_with_uncertainty_free(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

/** Get a cJSON tree representation of a HorizontalVelocityWithUncertainty
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * Create a cJSON tree representation of the HorizontalVelocityWithUncertainty object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_horizontal_velocity_with_uncertainty_toJSON(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, bool as_request);

/** Parse a cJSON tree into a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * Attempts to interpret a cJSON tree as a HorizontalVelocityWithUncertainty API request or response (dependent on @a as_request value). If successful
 * will return a new referenced HorizontalVelocityWithUncertainty object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new HorizontalVelocityWithUncertainty object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two HorizontalVelocityWithUncertainty objects to see if they are equivalent
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param horizontal_velocity_with_uncertainty The first HorizontalVelocityWithUncertainty object to compare.
 * @param other_horizontal_velocity_with_uncertainty The second HorizontalVelocityWithUncertainty object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_horizontal_velocity_with_uncertainty_is_equal_to(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const data_collection_model_horizontal_velocity_with_uncertainty_t *other_horizontal_velocity_with_uncertainty);



/** Get the value of the hSpeed field of a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to examine.
 *
 * @return the value current set for the hSpeed field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_velocity_with_uncertainty_get_h_speed(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

/** Set the value of the hSpeed field in a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to set the field in.
 * @param p_h_speed The value to copy into the HorizontalVelocityWithUncertainty object.
 *
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_speed(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const float p_h_speed);

/** Move a value to the hSpeed field in a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to set the field in.
 * @param p_h_speed The value to move into the HorizontalVelocityWithUncertainty object.
 *
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_speed_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, float p_h_speed);


/** Get the value of the bearing field of a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to examine.
 *
 * @return the value current set for the bearing field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_horizontal_velocity_with_uncertainty_get_bearing(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

/** Set the value of the bearing field in a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to set the field in.
 * @param p_bearing The value to copy into the HorizontalVelocityWithUncertainty object.
 *
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_bearing(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const int32_t p_bearing);

/** Move a value to the bearing field in a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to set the field in.
 * @param p_bearing The value to move into the HorizontalVelocityWithUncertainty object.
 *
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_bearing_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, int32_t p_bearing);


/** Get the value of the hUncertainty field of a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to examine.
 *
 * @return the value current set for the hUncertainty field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_velocity_with_uncertainty_get_h_uncertainty(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

/** Set the value of the hUncertainty field in a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to set the field in.
 * @param p_h_uncertainty The value to copy into the HorizontalVelocityWithUncertainty object.
 *
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_uncertainty(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const float p_h_uncertainty);

/** Move a value to the hUncertainty field in a HorizontalVelocityWithUncertainty object
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to set the field in.
 * @param p_h_uncertainty The value to move into the HorizontalVelocityWithUncertainty object.
 *
 * @return @a horizontal_velocity_with_uncertainty.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_uncertainty_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, float p_h_uncertainty);

/** lnode helper for generating ogs_list_t nodes's of type HorizontalVelocityWithUncertainty
 * \public \memberof data_collection_model_horizontal_velocity_with_uncertainty_t
 *
 * Creates a new data_collection_lnode_t object containing the @a horizontal_velocity_with_uncertainty object.
 * The @a horizontal_velocity_with_uncertainty will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param horizontal_velocity_with_uncertainty The HorizontalVelocityWithUncertainty object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a horizontal_velocity_with_uncertainty
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_horizontal_velocity_with_uncertainty_make_lnode(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_HORIZONTAL_VELOCITY_WITH_UNCERTAINTY_H_ */

