#ifndef _DATA_COLLECTION_REDIRECT_RESPONSE_H_
#define _DATA_COLLECTION_REDIRECT_RESPONSE_H_

/**********************************************************************************************************************************
 * RedirectResponse - Public C interface to the RedirectResponse object
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

/** A 3GPP RedirectResponse object reference
 */
typedef struct data_collection_model_redirect_response_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_redirect_response_t;



/** Create a new RedirectResponse.
 * \public \memberof data_collection_model_redirect_response_t
 * @return a new RedirectResponse object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create();

/** Create a new RedirectResponse reference.
 * \public \memberof data_collection_model_redirect_response_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The RedirectResponse to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_ref(const data_collection_model_redirect_response_t *other);

/** Create a new copy of a RedirectResponse object.
 * \public \memberof data_collection_model_redirect_response_t
 * Creates a new copy of the given @a other object
 * @param other The RedirectResponse to copy.
 * @return a new RedirectResponse object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_copy(const data_collection_model_redirect_response_t *other);

/** Create a new reference of a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 * Creates a reference to the same underlying @a other object.
 * @param other The RedirectResponse to create a new reference to.
 * @return a new RedirectResponse object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_move(data_collection_model_redirect_response_t *other);

/** Copy the value of another RedirectResponse into this object
 * \public \memberof data_collection_model_redirect_response_t
 * Copies the value of @a other {{classname} object into @a redirect_response.
 * @param redirect_response The RedirectResponse object to copy @a other into.
 * @param other The RedirectResponse to copy the value from.
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_copy(data_collection_model_redirect_response_t *redirect_response, const data_collection_model_redirect_response_t *other);

/** Move the value of another RedirectResponse into this object
 * \public \memberof data_collection_model_redirect_response_t
 * Discards the current value of @a redirect_response and moves the value of @a other
 * into @a redirect_response. This will leave @a other as an empty reference.
 *
 * @param redirect_response The RedirectResponse object to move @a other into.
 * @param other The RedirectResponse to move the value from.
 *
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_move(data_collection_model_redirect_response_t *redirect_response, data_collection_model_redirect_response_t *other);

/** Delete a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 * Destroys the reference to the RedirectResponse object and frees the value of RedirectResponse if this is the last reference.
 *
 * @param redirect_response The RedirectResponse to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_redirect_response_free(data_collection_model_redirect_response_t *redirect_response);

/** Get a cJSON tree representation of a RedirectResponse
 * \public \memberof data_collection_model_redirect_response_t
 *
 * Create a cJSON tree representation of the RedirectResponse object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param redirect_response The RedirectResponse to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_redirect_response_toJSON(const data_collection_model_redirect_response_t *redirect_response, bool as_request);

/** Parse a cJSON tree into a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * Attempts to interpret a cJSON tree as a RedirectResponse API request or response (dependent on @a as_request value). If successful
 * will return a new referenced RedirectResponse object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new RedirectResponse object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two RedirectResponse objects to see if they are equivalent
 * \public \memberof data_collection_model_redirect_response_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param redirect_response The first RedirectResponse object to compare.
 * @param other_redirect_response The second RedirectResponse object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_redirect_response_is_equal_to(const data_collection_model_redirect_response_t *redirect_response, const data_collection_model_redirect_response_t *other_redirect_response);


/** Check if the cause field of a RedirectResponse object is set
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to examine.
 *
 * @return `true` if the optional cause field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_redirect_response_has_cause(const data_collection_model_redirect_response_t *redirect_response);


/** Get the value of the cause field of a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to examine.
 *
 * @return the value current set for the cause field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_cause(const data_collection_model_redirect_response_t *redirect_response);

/** Set the value of the cause field in a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to set the field in.
 * @param p_cause The value to copy into the RedirectResponse object.
 *
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause(data_collection_model_redirect_response_t *redirect_response, const char* p_cause);

/** Move a value to the cause field in a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to set the field in.
 * @param p_cause The value to move into the RedirectResponse object.
 *
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause_move(data_collection_model_redirect_response_t *redirect_response, char* p_cause);

/** Check if the targetScp field of a RedirectResponse object is set
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to examine.
 *
 * @return `true` if the optional targetScp field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_redirect_response_has_target_scp(const data_collection_model_redirect_response_t *redirect_response);


/** Get the value of the targetScp field of a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to examine.
 *
 * @return the value current set for the targetScp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_target_scp(const data_collection_model_redirect_response_t *redirect_response);

/** Set the value of the targetScp field in a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to set the field in.
 * @param p_target_scp The value to copy into the RedirectResponse object.
 *
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp(data_collection_model_redirect_response_t *redirect_response, const char* p_target_scp);

/** Move a value to the targetScp field in a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to set the field in.
 * @param p_target_scp The value to move into the RedirectResponse object.
 *
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp_move(data_collection_model_redirect_response_t *redirect_response, char* p_target_scp);

/** Check if the targetSepp field of a RedirectResponse object is set
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to examine.
 *
 * @return `true` if the optional targetSepp field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_redirect_response_has_target_sepp(const data_collection_model_redirect_response_t *redirect_response);


/** Get the value of the targetSepp field of a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to examine.
 *
 * @return the value current set for the targetSepp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_target_sepp(const data_collection_model_redirect_response_t *redirect_response);

/** Set the value of the targetSepp field in a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to set the field in.
 * @param p_target_sepp The value to copy into the RedirectResponse object.
 *
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp(data_collection_model_redirect_response_t *redirect_response, const char* p_target_sepp);

/** Move a value to the targetSepp field in a RedirectResponse object
 * \public \memberof data_collection_model_redirect_response_t
 *
 * @param redirect_response The RedirectResponse object to set the field in.
 * @param p_target_sepp The value to move into the RedirectResponse object.
 *
 * @return @a redirect_response.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp_move(data_collection_model_redirect_response_t *redirect_response, char* p_target_sepp);

/** lnode helper for generating ogs_list_t nodes's of type RedirectResponse
 * \public \memberof data_collection_model_redirect_response_t
 *
 * Creates a new data_collection_lnode_t object containing the @a redirect_response object.
 * The @a redirect_response will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param redirect_response The RedirectResponse object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a redirect_response
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_redirect_response_make_lnode(data_collection_model_redirect_response_t *redirect_response);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_REDIRECT_RESPONSE_H_ */

