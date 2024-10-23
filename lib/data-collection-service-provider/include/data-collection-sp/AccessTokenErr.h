#ifndef _DATA_COLLECTION_ACCESS_TOKEN_ERR_H_
#define _DATA_COLLECTION_ACCESS_TOKEN_ERR_H_

/**********************************************************************************************************************************
 * AccessTokenErr - Public C interface to the AccessTokenErr object
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

/** A 3GPP AccessTokenErr object reference
 */
typedef struct data_collection_model_access_token_err_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_access_token_err_t;



/** Create a new AccessTokenErr
 * \public \memberof data_collection_model_access_token_err_t
 * @return a new AccessTokenErr object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_create();

/** Create a new copy of a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 * Creates a new copy of the given @a other object
 * @param other The AccessTokenErr to copy.
 * @return a new AccessTokenErr object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_create_copy(const data_collection_model_access_token_err_t *other);

/** Create a new reference of a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AccessTokenErr to create a new reference to.
 * @return a new AccessTokenErr object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_create_move(data_collection_model_access_token_err_t *other);

/** Copy the value of another AccessTokenErr into this object
 * \public \memberof data_collection_model_access_token_err_t
 * Copies the value of @a other {{classname} object into @a access_token_err.
 * @param access_token_err The AccessTokenErr object to copy @a other into.
 * @param other The AccessTokenErr to copy the value from.
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_copy(data_collection_model_access_token_err_t *access_token_err, const data_collection_model_access_token_err_t *other);

/** Move the value of another AccessTokenErr into this object
 * \public \memberof data_collection_model_access_token_err_t
 * Discards the current value of @a access_token_err and moves the value of @a other
 * into @a access_token_err. This will leave @a other as an empty reference.
 *
 * @param access_token_err The AccessTokenErr object to move @a other into.
 * @param other The AccessTokenErr to move the value from.
 *
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_move(data_collection_model_access_token_err_t *access_token_err, data_collection_model_access_token_err_t *other);

/** Delete a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 * Destroys the reference to the AccessTokenErr object and frees the value of AccessTokenErr if this is the last reference.
 *
 * @param access_token_err The AccessTokenErr to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_access_token_err_free(data_collection_model_access_token_err_t *access_token_err);

/** Get a cJSON tree representation of a AccessTokenErr
 * \public \memberof data_collection_model_access_token_err_t
 *
 * Create a cJSON tree representation of the AccessTokenErr object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param access_token_err The AccessTokenErr to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_access_token_err_toJSON(const data_collection_model_access_token_err_t *access_token_err, bool as_request);

/** Parse a cJSON tree into a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * Attempts to interpret a cJSON tree as a AccessTokenErr API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AccessTokenErr object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AccessTokenErr object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AccessTokenErr objects to see if they are equivalent
 * \public \memberof data_collection_model_access_token_err_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param access_token_err The first AccessTokenErr object to compare.
 * @param other_access_token_err The second AccessTokenErr object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_err_is_equal_to(const data_collection_model_access_token_err_t *access_token_err, const data_collection_model_access_token_err_t *other_access_token_err);



/** Get the value of the error field of a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to examine.
 *
 * @return the value current set for the error field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_err_get_error(const data_collection_model_access_token_err_t *access_token_err);

/** Set the value of the error field in a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to set the field in.
 * @param p_error The value to copy into the AccessTokenErr object.
 *
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error(data_collection_model_access_token_err_t *access_token_err, const char* p_error);

/** Move a value to the error field in a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to set the field in.
 * @param p_error The value to move into the AccessTokenErr object.
 *
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_move(data_collection_model_access_token_err_t *access_token_err, char* p_error);

/** Check if the error_description field of a AccessTokenErr object is set
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to examine.
 *
 * @return `true` if the optional error_description field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_err_has_error_description(const data_collection_model_access_token_err_t *access_token_err);


/** Get the value of the error_description field of a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to examine.
 *
 * @return the value current set for the error_description field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_err_get_error_description(const data_collection_model_access_token_err_t *access_token_err);

/** Set the value of the error_description field in a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to set the field in.
 * @param p_error_description The value to copy into the AccessTokenErr object.
 *
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_description(data_collection_model_access_token_err_t *access_token_err, const char* p_error_description);

/** Move a value to the error_description field in a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to set the field in.
 * @param p_error_description The value to move into the AccessTokenErr object.
 *
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_description_move(data_collection_model_access_token_err_t *access_token_err, char* p_error_description);

/** Check if the error_uri field of a AccessTokenErr object is set
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to examine.
 *
 * @return `true` if the optional error_uri field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_err_has_error_uri(const data_collection_model_access_token_err_t *access_token_err);


/** Get the value of the error_uri field of a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to examine.
 *
 * @return the value current set for the error_uri field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_err_get_error_uri(const data_collection_model_access_token_err_t *access_token_err);

/** Set the value of the error_uri field in a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to set the field in.
 * @param p_error_uri The value to copy into the AccessTokenErr object.
 *
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_uri(data_collection_model_access_token_err_t *access_token_err, const char* p_error_uri);

/** Move a value to the error_uri field in a AccessTokenErr object
 * \public \memberof data_collection_model_access_token_err_t
 *
 * @param access_token_err The AccessTokenErr object to set the field in.
 * @param p_error_uri The value to move into the AccessTokenErr object.
 *
 * @return @a access_token_err.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_uri_move(data_collection_model_access_token_err_t *access_token_err, char* p_error_uri);

/** lnode helper for generating ogs_list_t nodes's of type AccessTokenErr
 * \public \memberof data_collection_model_access_token_err_t
 *
 * Creates a new data_collection_lnode_t object containing the @a access_token_err object.
 * The @a access_token_err will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param access_token_err The AccessTokenErr object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a access_token_err
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_access_token_err_make_lnode(data_collection_model_access_token_err_t *access_token_err);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ACCESS_TOKEN_ERR_H_ */

