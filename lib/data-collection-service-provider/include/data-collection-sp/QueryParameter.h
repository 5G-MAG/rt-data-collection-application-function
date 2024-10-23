#ifndef _DATA_COLLECTION_QUERY_PARAMETER_H_
#define _DATA_COLLECTION_QUERY_PARAMETER_H_

/**********************************************************************************************************************************
 * QueryParameter - Public C interface to the QueryParameter object
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

/** A 3GPP QueryParameter object reference
 */
typedef struct data_collection_model_query_parameter_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_query_parameter_t;



/** Create a new QueryParameter
 * \public \memberof data_collection_model_query_parameter_t
 * @return a new QueryParameter object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create();

/** Create a new copy of a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 * Creates a new copy of the given @a other object
 * @param other The QueryParameter to copy.
 * @return a new QueryParameter object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_copy(const data_collection_model_query_parameter_t *other);

/** Create a new reference of a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 * Creates a reference to the same underlying @a other object.
 * @param other The QueryParameter to create a new reference to.
 * @return a new QueryParameter object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_move(data_collection_model_query_parameter_t *other);

/** Copy the value of another QueryParameter into this object
 * \public \memberof data_collection_model_query_parameter_t
 * Copies the value of @a other {{classname} object into @a query_parameter.
 * @param query_parameter The QueryParameter object to copy @a other into.
 * @param other The QueryParameter to copy the value from.
 * @return @a query_parameter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_copy(data_collection_model_query_parameter_t *query_parameter, const data_collection_model_query_parameter_t *other);

/** Move the value of another QueryParameter into this object
 * \public \memberof data_collection_model_query_parameter_t
 * Discards the current value of @a query_parameter and moves the value of @a other
 * into @a query_parameter. This will leave @a other as an empty reference.
 *
 * @param query_parameter The QueryParameter object to move @a other into.
 * @param other The QueryParameter to move the value from.
 *
 * @return @a query_parameter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_move(data_collection_model_query_parameter_t *query_parameter, data_collection_model_query_parameter_t *other);

/** Delete a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 * Destroys the reference to the QueryParameter object and frees the value of QueryParameter if this is the last reference.
 *
 * @param query_parameter The QueryParameter to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_query_parameter_free(data_collection_model_query_parameter_t *query_parameter);

/** Get a cJSON tree representation of a QueryParameter
 * \public \memberof data_collection_model_query_parameter_t
 *
 * Create a cJSON tree representation of the QueryParameter object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param query_parameter The QueryParameter to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_query_parameter_toJSON(const data_collection_model_query_parameter_t *query_parameter, bool as_request);

/** Parse a cJSON tree into a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 *
 * Attempts to interpret a cJSON tree as a QueryParameter API request or response (dependent on @a as_request value). If successful
 * will return a new referenced QueryParameter object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new QueryParameter object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two QueryParameter objects to see if they are equivalent
 * \public \memberof data_collection_model_query_parameter_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param query_parameter The first QueryParameter object to compare.
 * @param other_query_parameter The second QueryParameter object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_query_parameter_is_equal_to(const data_collection_model_query_parameter_t *query_parameter, const data_collection_model_query_parameter_t *other_query_parameter);



/** Get the value of the name field of a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 *
 * @param query_parameter The QueryParameter object to examine.
 *
 * @return the value current set for the name field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_query_parameter_get_name(const data_collection_model_query_parameter_t *query_parameter);

/** Set the value of the name field in a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 *
 * @param query_parameter The QueryParameter object to set the field in.
 * @param p_name The value to copy into the QueryParameter object.
 *
 * @return @a query_parameter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name(data_collection_model_query_parameter_t *query_parameter, const char* p_name);

/** Move a value to the name field in a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 *
 * @param query_parameter The QueryParameter object to set the field in.
 * @param p_name The value to move into the QueryParameter object.
 *
 * @return @a query_parameter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name_move(data_collection_model_query_parameter_t *query_parameter, char* p_name);


/** Get the value of the value field of a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 *
 * @param query_parameter The QueryParameter object to examine.
 *
 * @return the value current set for the value field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_query_parameter_get_value(const data_collection_model_query_parameter_t *query_parameter);

/** Set the value of the value field in a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 *
 * @param query_parameter The QueryParameter object to set the field in.
 * @param p_value The value to copy into the QueryParameter object.
 *
 * @return @a query_parameter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value(data_collection_model_query_parameter_t *query_parameter, const char* p_value);

/** Move a value to the value field in a QueryParameter object
 * \public \memberof data_collection_model_query_parameter_t
 *
 * @param query_parameter The QueryParameter object to set the field in.
 * @param p_value The value to move into the QueryParameter object.
 *
 * @return @a query_parameter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value_move(data_collection_model_query_parameter_t *query_parameter, char* p_value);

/** lnode helper for generating ogs_list_t nodes's of type QueryParameter
 * \public \memberof data_collection_model_query_parameter_t
 *
 * Creates a new data_collection_lnode_t object containing the @a query_parameter object.
 * The @a query_parameter will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param query_parameter The QueryParameter object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a query_parameter
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_query_parameter_make_lnode(data_collection_model_query_parameter_t *query_parameter);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QUERY_PARAMETER_H_ */

