#ifndef _DATA_COLLECTION_PROBLEM_DETAILS_H_
#define _DATA_COLLECTION_PROBLEM_DETAILS_H_

/**********************************************************************************************************************************
 * ProblemDetails - Public C interface to the ProblemDetails object
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

#include "NoProfileMatchInfo.h"
#include "InvalidParam.h"
#include "AccessTokenErr.h"
#include "AccessTokenReq.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ProblemDetails object reference
 */
typedef struct data_collection_model_problem_details_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_problem_details_t;



/** Create a new ProblemDetails
 * \public \memberof data_collection_model_problem_details_t
 * @return a new ProblemDetails object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create();

/** Create a new copy of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 * Creates a new copy of the given @a other object
 * @param other The ProblemDetails to copy.
 * @return a new ProblemDetails object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create_copy(const data_collection_model_problem_details_t *other);

/** Create a new reference of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ProblemDetails to create a new reference to.
 * @return a new ProblemDetails object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create_move(data_collection_model_problem_details_t *other);

/** Copy the value of another ProblemDetails into this object
 * \public \memberof data_collection_model_problem_details_t
 * Copies the value of @a other {{classname} object into @a problem_details.
 * @param problem_details The ProblemDetails object to copy @a other into.
 * @param other The ProblemDetails to copy the value from.
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_copy(data_collection_model_problem_details_t *problem_details, const data_collection_model_problem_details_t *other);

/** Move the value of another ProblemDetails into this object
 * \public \memberof data_collection_model_problem_details_t
 * Discards the current value of @a problem_details and moves the value of @a other
 * into @a problem_details. This will leave @a other as an empty reference.
 *
 * @param problem_details The ProblemDetails object to move @a other into.
 * @param other The ProblemDetails to move the value from.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_move(data_collection_model_problem_details_t *problem_details, data_collection_model_problem_details_t *other);

/** Delete a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 * Destroys the reference to the ProblemDetails object and frees the value of ProblemDetails if this is the last reference.
 *
 * @param problem_details The ProblemDetails to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_problem_details_free(data_collection_model_problem_details_t *problem_details);

/** Get a cJSON tree representation of a ProblemDetails
 * \public \memberof data_collection_model_problem_details_t
 *
 * Create a cJSON tree representation of the ProblemDetails object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param problem_details The ProblemDetails to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_problem_details_toJSON(const data_collection_model_problem_details_t *problem_details, bool as_request);

/** Parse a cJSON tree into a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * Attempts to interpret a cJSON tree as a ProblemDetails API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ProblemDetails object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ProblemDetails object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ProblemDetails objects to see if they are equivalent
 * \public \memberof data_collection_model_problem_details_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param problem_details The first ProblemDetails object to compare.
 * @param other_problem_details The second ProblemDetails object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_is_equal_to(const data_collection_model_problem_details_t *problem_details, const data_collection_model_problem_details_t *other_problem_details);


/** Check if the type field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional type field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_type(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the type field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the type field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_type(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the type field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_type The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_type(data_collection_model_problem_details_t *problem_details, const char* p_type);

/** Move a value to the type field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_type The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_type_move(data_collection_model_problem_details_t *problem_details, char* p_type);

/** Check if the title field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional title field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_title(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the title field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the title field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_title(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the title field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_title The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_title(data_collection_model_problem_details_t *problem_details, const char* p_title);

/** Move a value to the title field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_title The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_title_move(data_collection_model_problem_details_t *problem_details, char* p_title);

/** Check if the status field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional status field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_status(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the status field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the status field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_problem_details_get_status(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the status field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_status The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_status(data_collection_model_problem_details_t *problem_details, const int32_t p_status);

/** Move a value to the status field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_status The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_status_move(data_collection_model_problem_details_t *problem_details, int32_t p_status);

/** Check if the detail field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional detail field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_detail(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the detail field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the detail field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_detail(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the detail field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_detail The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_detail(data_collection_model_problem_details_t *problem_details, const char* p_detail);

/** Move a value to the detail field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_detail The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_detail_move(data_collection_model_problem_details_t *problem_details, char* p_detail);

/** Check if the instance field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional instance field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_instance(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the instance field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the instance field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_instance(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the instance field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_instance The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_instance(data_collection_model_problem_details_t *problem_details, const char* p_instance);

/** Move a value to the instance field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_instance The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_instance_move(data_collection_model_problem_details_t *problem_details, char* p_instance);

/** Check if the cause field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional cause field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_cause(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the cause field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the cause field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_cause(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the cause field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_cause The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_cause(data_collection_model_problem_details_t *problem_details, const char* p_cause);

/** Move a value to the cause field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_cause The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_cause_move(data_collection_model_problem_details_t *problem_details, char* p_cause);

/** Check if the invalidParams field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional invalidParams field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_invalid_params(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the invalidParams field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the invalidParams field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_problem_details_get_invalid_params(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the invalidParams field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_invalid_params The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_invalid_params(data_collection_model_problem_details_t *problem_details, const ogs_list_t* p_invalid_params);

/** Move a value to the invalidParams field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_invalid_params The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_invalid_params_move(data_collection_model_problem_details_t *problem_details, ogs_list_t* p_invalid_params);

/** Add a new item to the invalidParams array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to add the array item to.
 * @param invalid_params The value to add.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_add_invalid_params(data_collection_model_problem_details_t *problem_details, data_collection_model_invalid_param_t* invalid_params);

/** Remove an item from the invalidParams array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to remove the array value from.
 * @param invalid_params The value to remove.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_remove_invalid_params(data_collection_model_problem_details_t *problem_details, const data_collection_model_invalid_param_t* invalid_params);

/** Get an item from the invalidParams array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_invalid_param_t* data_collection_model_problem_details_get_entry_invalid_params(const data_collection_model_problem_details_t *problem_details, size_t idx);

/** Remove all entries from the invalidParams array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to empty invalidParams for.
 *
 * @return @a problem_details
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_clear_invalid_params(data_collection_model_problem_details_t *problem_details);

/** Check if the supportedFeatures field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional supportedFeatures field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_supported_features(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the supportedFeatures field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the supportedFeatures field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_supported_features(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the supportedFeatures field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_supported_features The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_features(data_collection_model_problem_details_t *problem_details, const char* p_supported_features);

/** Move a value to the supportedFeatures field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_supported_features The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_features_move(data_collection_model_problem_details_t *problem_details, char* p_supported_features);

/** Check if the accessTokenError field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional accessTokenError field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_access_token_error(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the accessTokenError field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the accessTokenError field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_access_token_err_t* data_collection_model_problem_details_get_access_token_error(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the accessTokenError field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_access_token_error The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_error(data_collection_model_problem_details_t *problem_details, const data_collection_model_access_token_err_t* p_access_token_error);

/** Move a value to the accessTokenError field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_access_token_error The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_error_move(data_collection_model_problem_details_t *problem_details, data_collection_model_access_token_err_t* p_access_token_error);

/** Check if the accessTokenRequest field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional accessTokenRequest field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_access_token_request(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the accessTokenRequest field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the accessTokenRequest field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_access_token_req_t* data_collection_model_problem_details_get_access_token_request(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the accessTokenRequest field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_access_token_request The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_request(data_collection_model_problem_details_t *problem_details, const data_collection_model_access_token_req_t* p_access_token_request);

/** Move a value to the accessTokenRequest field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_access_token_request The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_request_move(data_collection_model_problem_details_t *problem_details, data_collection_model_access_token_req_t* p_access_token_request);

/** Check if the nrfId field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional nrfId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_nrf_id(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the nrfId field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the nrfId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_nrf_id(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the nrfId field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_nrf_id The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_nrf_id(data_collection_model_problem_details_t *problem_details, const char* p_nrf_id);

/** Move a value to the nrfId field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_nrf_id The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_nrf_id_move(data_collection_model_problem_details_t *problem_details, char* p_nrf_id);

/** Check if the supportedApiVersions field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional supportedApiVersions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_supported_api_versions(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the supportedApiVersions field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the supportedApiVersions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_problem_details_get_supported_api_versions(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the supportedApiVersions field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_supported_api_versions The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_api_versions(data_collection_model_problem_details_t *problem_details, const ogs_list_t* p_supported_api_versions);

/** Move a value to the supportedApiVersions field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_supported_api_versions The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_api_versions_move(data_collection_model_problem_details_t *problem_details, ogs_list_t* p_supported_api_versions);

/** Add a new item to the supportedApiVersions array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to add the array item to.
 * @param supported_api_versions The value to add.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_add_supported_api_versions(data_collection_model_problem_details_t *problem_details, char* supported_api_versions);

/** Remove an item from the supportedApiVersions array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to remove the array value from.
 * @param supported_api_versions The value to remove.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_remove_supported_api_versions(data_collection_model_problem_details_t *problem_details, const char* supported_api_versions);

/** Get an item from the supportedApiVersions array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_entry_supported_api_versions(const data_collection_model_problem_details_t *problem_details, size_t idx);

/** Remove all entries from the supportedApiVersions array in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to empty supportedApiVersions for.
 *
 * @return @a problem_details
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_clear_supported_api_versions(data_collection_model_problem_details_t *problem_details);

/** Check if the noProfileMatchInfo field of a ProblemDetails object is set
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return `true` if the optional noProfileMatchInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_no_profile_match_info(const data_collection_model_problem_details_t *problem_details);


/** Get the value of the noProfileMatchInfo field of a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to examine.
 *
 * @return the value current set for the noProfileMatchInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_no_profile_match_info_t* data_collection_model_problem_details_get_no_profile_match_info(const data_collection_model_problem_details_t *problem_details);

/** Set the value of the noProfileMatchInfo field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_no_profile_match_info The value to copy into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_no_profile_match_info(data_collection_model_problem_details_t *problem_details, const data_collection_model_no_profile_match_info_t* p_no_profile_match_info);

/** Move a value to the noProfileMatchInfo field in a ProblemDetails object
 * \public \memberof data_collection_model_problem_details_t
 *
 * @param problem_details The ProblemDetails object to set the field in.
 * @param p_no_profile_match_info The value to move into the ProblemDetails object.
 *
 * @return @a problem_details.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_no_profile_match_info_move(data_collection_model_problem_details_t *problem_details, data_collection_model_no_profile_match_info_t* p_no_profile_match_info);

/** lnode helper for generating ogs_list_t nodes's of type ProblemDetails
 * \public \memberof data_collection_model_problem_details_t
 *
 * Creates a new data_collection_lnode_t object containing the @a problem_details object.
 * The @a problem_details will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param problem_details The ProblemDetails object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a problem_details
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_problem_details_make_lnode(data_collection_model_problem_details_t *problem_details);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PROBLEM_DETAILS_H_ */

