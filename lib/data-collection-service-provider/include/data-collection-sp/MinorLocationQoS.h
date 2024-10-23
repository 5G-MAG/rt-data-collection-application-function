#ifndef _DATA_COLLECTION_MINOR_LOCATION_QO_S_H_
#define _DATA_COLLECTION_MINOR_LOCATION_QO_S_H_

/**********************************************************************************************************************************
 * MinorLocationQoS - Public C interface to the MinorLocationQoS object
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

/** A 3GPP MinorLocationQoS object reference
 */
typedef struct data_collection_model_minor_location_qo_s_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_minor_location_qo_s_t;



/** Create a new MinorLocationQoS
 * \public \memberof data_collection_model_minor_location_qo_s_t
 * @return a new MinorLocationQoS object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create();

/** Create a new copy of a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 * Creates a new copy of the given @a other object
 * @param other The MinorLocationQoS to copy.
 * @return a new MinorLocationQoS object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create_copy(const data_collection_model_minor_location_qo_s_t *other);

/** Create a new reference of a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MinorLocationQoS to create a new reference to.
 * @return a new MinorLocationQoS object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create_move(data_collection_model_minor_location_qo_s_t *other);

/** Copy the value of another MinorLocationQoS into this object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 * Copies the value of @a other {{classname} object into @a minor_location_qo_s.
 * @param minor_location_qo_s The MinorLocationQoS object to copy @a other into.
 * @param other The MinorLocationQoS to copy the value from.
 * @return @a minor_location_qo_s.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_copy(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const data_collection_model_minor_location_qo_s_t *other);

/** Move the value of another MinorLocationQoS into this object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 * Discards the current value of @a minor_location_qo_s and moves the value of @a other
 * into @a minor_location_qo_s. This will leave @a other as an empty reference.
 *
 * @param minor_location_qo_s The MinorLocationQoS object to move @a other into.
 * @param other The MinorLocationQoS to move the value from.
 *
 * @return @a minor_location_qo_s.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_move(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, data_collection_model_minor_location_qo_s_t *other);

/** Delete a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 * Destroys the reference to the MinorLocationQoS object and frees the value of MinorLocationQoS if this is the last reference.
 *
 * @param minor_location_qo_s The MinorLocationQoS to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_minor_location_qo_s_free(data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

/** Get a cJSON tree representation of a MinorLocationQoS
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * Create a cJSON tree representation of the MinorLocationQoS object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param minor_location_qo_s The MinorLocationQoS to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_minor_location_qo_s_toJSON(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s, bool as_request);

/** Parse a cJSON tree into a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * Attempts to interpret a cJSON tree as a MinorLocationQoS API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MinorLocationQoS object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MinorLocationQoS object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MinorLocationQoS objects to see if they are equivalent
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param minor_location_qo_s The first MinorLocationQoS object to compare.
 * @param other_minor_location_qo_s The second MinorLocationQoS object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_is_equal_to(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const data_collection_model_minor_location_qo_s_t *other_minor_location_qo_s);


/** Check if the hAccuracy field of a MinorLocationQoS object is set
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to examine.
 *
 * @return `true` if the optional hAccuracy field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_has_h_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);


/** Get the value of the hAccuracy field of a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to examine.
 *
 * @return the value current set for the hAccuracy field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_minor_location_qo_s_get_h_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

/** Set the value of the hAccuracy field in a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to set the field in.
 * @param p_h_accuracy The value to copy into the MinorLocationQoS object.
 *
 * @return @a minor_location_qo_s.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_h_accuracy(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const float p_h_accuracy);

/** Move a value to the hAccuracy field in a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to set the field in.
 * @param p_h_accuracy The value to move into the MinorLocationQoS object.
 *
 * @return @a minor_location_qo_s.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_h_accuracy_move(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, float p_h_accuracy);

/** Check if the vAccuracy field of a MinorLocationQoS object is set
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to examine.
 *
 * @return `true` if the optional vAccuracy field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_has_v_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);


/** Get the value of the vAccuracy field of a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to examine.
 *
 * @return the value current set for the vAccuracy field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_minor_location_qo_s_get_v_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

/** Set the value of the vAccuracy field in a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to set the field in.
 * @param p_v_accuracy The value to copy into the MinorLocationQoS object.
 *
 * @return @a minor_location_qo_s.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_v_accuracy(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const float p_v_accuracy);

/** Move a value to the vAccuracy field in a MinorLocationQoS object
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * @param minor_location_qo_s The MinorLocationQoS object to set the field in.
 * @param p_v_accuracy The value to move into the MinorLocationQoS object.
 *
 * @return @a minor_location_qo_s.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_v_accuracy_move(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, float p_v_accuracy);

/** lnode helper for generating ogs_list_t nodes's of type MinorLocationQoS
 * \public \memberof data_collection_model_minor_location_qo_s_t
 *
 * Creates a new data_collection_lnode_t object containing the @a minor_location_qo_s object.
 * The @a minor_location_qo_s will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param minor_location_qo_s The MinorLocationQoS object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a minor_location_qo_s
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_minor_location_qo_s_make_lnode(data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MINOR_LOCATION_QO_S_H_ */

