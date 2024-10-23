#ifndef _DATA_COLLECTION_INVALID_PARAM_H_
#define _DATA_COLLECTION_INVALID_PARAM_H_

/**********************************************************************************************************************************
 * InvalidParam - Public C interface to the InvalidParam object
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

/** A 3GPP InvalidParam object reference
 */
typedef struct data_collection_model_invalid_param_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_invalid_param_t;



/** Create a new InvalidParam
 * \public \memberof data_collection_model_invalid_param_t
 * @return a new InvalidParam object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_create();

/** Create a new copy of a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 * Creates a new copy of the given @a other object
 * @param other The InvalidParam to copy.
 * @return a new InvalidParam object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_create_copy(const data_collection_model_invalid_param_t *other);

/** Create a new reference of a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 * Creates a reference to the same underlying @a other object.
 * @param other The InvalidParam to create a new reference to.
 * @return a new InvalidParam object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_create_move(data_collection_model_invalid_param_t *other);

/** Copy the value of another InvalidParam into this object
 * \public \memberof data_collection_model_invalid_param_t
 * Copies the value of @a other {{classname} object into @a invalid_param.
 * @param invalid_param The InvalidParam object to copy @a other into.
 * @param other The InvalidParam to copy the value from.
 * @return @a invalid_param.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_copy(data_collection_model_invalid_param_t *invalid_param, const data_collection_model_invalid_param_t *other);

/** Move the value of another InvalidParam into this object
 * \public \memberof data_collection_model_invalid_param_t
 * Discards the current value of @a invalid_param and moves the value of @a other
 * into @a invalid_param. This will leave @a other as an empty reference.
 *
 * @param invalid_param The InvalidParam object to move @a other into.
 * @param other The InvalidParam to move the value from.
 *
 * @return @a invalid_param.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_move(data_collection_model_invalid_param_t *invalid_param, data_collection_model_invalid_param_t *other);

/** Delete a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 * Destroys the reference to the InvalidParam object and frees the value of InvalidParam if this is the last reference.
 *
 * @param invalid_param The InvalidParam to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_invalid_param_free(data_collection_model_invalid_param_t *invalid_param);

/** Get a cJSON tree representation of a InvalidParam
 * \public \memberof data_collection_model_invalid_param_t
 *
 * Create a cJSON tree representation of the InvalidParam object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param invalid_param The InvalidParam to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_invalid_param_toJSON(const data_collection_model_invalid_param_t *invalid_param, bool as_request);

/** Parse a cJSON tree into a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 *
 * Attempts to interpret a cJSON tree as a InvalidParam API request or response (dependent on @a as_request value). If successful
 * will return a new referenced InvalidParam object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new InvalidParam object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two InvalidParam objects to see if they are equivalent
 * \public \memberof data_collection_model_invalid_param_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param invalid_param The first InvalidParam object to compare.
 * @param other_invalid_param The second InvalidParam object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_invalid_param_is_equal_to(const data_collection_model_invalid_param_t *invalid_param, const data_collection_model_invalid_param_t *other_invalid_param);



/** Get the value of the param field of a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 *
 * @param invalid_param The InvalidParam object to examine.
 *
 * @return the value current set for the param field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_invalid_param_get_param(const data_collection_model_invalid_param_t *invalid_param);

/** Set the value of the param field in a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 *
 * @param invalid_param The InvalidParam object to set the field in.
 * @param p_param The value to copy into the InvalidParam object.
 *
 * @return @a invalid_param.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_param(data_collection_model_invalid_param_t *invalid_param, const char* p_param);

/** Move a value to the param field in a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 *
 * @param invalid_param The InvalidParam object to set the field in.
 * @param p_param The value to move into the InvalidParam object.
 *
 * @return @a invalid_param.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_param_move(data_collection_model_invalid_param_t *invalid_param, char* p_param);

/** Check if the reason field of a InvalidParam object is set
 * \public \memberof data_collection_model_invalid_param_t
 *
 * @param invalid_param The InvalidParam object to examine.
 *
 * @return `true` if the optional reason field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_invalid_param_has_reason(const data_collection_model_invalid_param_t *invalid_param);


/** Get the value of the reason field of a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 *
 * @param invalid_param The InvalidParam object to examine.
 *
 * @return the value current set for the reason field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_invalid_param_get_reason(const data_collection_model_invalid_param_t *invalid_param);

/** Set the value of the reason field in a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 *
 * @param invalid_param The InvalidParam object to set the field in.
 * @param p_reason The value to copy into the InvalidParam object.
 *
 * @return @a invalid_param.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_reason(data_collection_model_invalid_param_t *invalid_param, const char* p_reason);

/** Move a value to the reason field in a InvalidParam object
 * \public \memberof data_collection_model_invalid_param_t
 *
 * @param invalid_param The InvalidParam object to set the field in.
 * @param p_reason The value to move into the InvalidParam object.
 *
 * @return @a invalid_param.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_reason_move(data_collection_model_invalid_param_t *invalid_param, char* p_reason);

/** lnode helper for generating ogs_list_t nodes's of type InvalidParam
 * \public \memberof data_collection_model_invalid_param_t
 *
 * Creates a new data_collection_lnode_t object containing the @a invalid_param object.
 * The @a invalid_param will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param invalid_param The InvalidParam object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a invalid_param
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_invalid_param_make_lnode(data_collection_model_invalid_param_t *invalid_param);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INVALID_PARAM_H_ */

