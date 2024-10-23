#ifndef _DATA_COLLECTION_QUERY_PARAM_COMBINATION_H_
#define _DATA_COLLECTION_QUERY_PARAM_COMBINATION_H_

/**********************************************************************************************************************************
 * QueryParamCombination - Public C interface to the QueryParamCombination object
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

#include "QueryParameter.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP QueryParamCombination object reference
 */
typedef struct data_collection_model_query_param_combination_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_query_param_combination_t;



/** Create a new QueryParamCombination
 * \public \memberof data_collection_model_query_param_combination_t
 * @return a new QueryParamCombination object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create();

/** Create a new copy of a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 * Creates a new copy of the given @a other object
 * @param other The QueryParamCombination to copy.
 * @return a new QueryParamCombination object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_copy(const data_collection_model_query_param_combination_t *other);

/** Create a new reference of a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 * Creates a reference to the same underlying @a other object.
 * @param other The QueryParamCombination to create a new reference to.
 * @return a new QueryParamCombination object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_move(data_collection_model_query_param_combination_t *other);

/** Copy the value of another QueryParamCombination into this object
 * \public \memberof data_collection_model_query_param_combination_t
 * Copies the value of @a other {{classname} object into @a query_param_combination.
 * @param query_param_combination The QueryParamCombination object to copy @a other into.
 * @param other The QueryParamCombination to copy the value from.
 * @return @a query_param_combination.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_copy(data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_param_combination_t *other);

/** Move the value of another QueryParamCombination into this object
 * \public \memberof data_collection_model_query_param_combination_t
 * Discards the current value of @a query_param_combination and moves the value of @a other
 * into @a query_param_combination. This will leave @a other as an empty reference.
 *
 * @param query_param_combination The QueryParamCombination object to move @a other into.
 * @param other The QueryParamCombination to move the value from.
 *
 * @return @a query_param_combination.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_move(data_collection_model_query_param_combination_t *query_param_combination, data_collection_model_query_param_combination_t *other);

/** Delete a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 * Destroys the reference to the QueryParamCombination object and frees the value of QueryParamCombination if this is the last reference.
 *
 * @param query_param_combination The QueryParamCombination to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_query_param_combination_free(data_collection_model_query_param_combination_t *query_param_combination);

/** Get a cJSON tree representation of a QueryParamCombination
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * Create a cJSON tree representation of the QueryParamCombination object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param query_param_combination The QueryParamCombination to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_query_param_combination_toJSON(const data_collection_model_query_param_combination_t *query_param_combination, bool as_request);

/** Parse a cJSON tree into a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * Attempts to interpret a cJSON tree as a QueryParamCombination API request or response (dependent on @a as_request value). If successful
 * will return a new referenced QueryParamCombination object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new QueryParamCombination object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two QueryParamCombination objects to see if they are equivalent
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param query_param_combination The first QueryParamCombination object to compare.
 * @param other_query_param_combination The second QueryParamCombination object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_query_param_combination_is_equal_to(const data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_param_combination_t *other_query_param_combination);



/** Get the value of the queryParams field of a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * @param query_param_combination The QueryParamCombination object to examine.
 *
 * @return the value current set for the queryParams field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_query_param_combination_get_query_params(const data_collection_model_query_param_combination_t *query_param_combination);

/** Set the value of the queryParams field in a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * @param query_param_combination The QueryParamCombination object to set the field in.
 * @param p_query_params The value to copy into the QueryParamCombination object.
 *
 * @return @a query_param_combination.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params(data_collection_model_query_param_combination_t *query_param_combination, const ogs_list_t* p_query_params);

/** Move a value to the queryParams field in a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * @param query_param_combination The QueryParamCombination object to set the field in.
 * @param p_query_params The value to move into the QueryParamCombination object.
 *
 * @return @a query_param_combination.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params_move(data_collection_model_query_param_combination_t *query_param_combination, ogs_list_t* p_query_params);

/** Add a new item to the queryParams array in a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * @param query_param_combination The QueryParamCombination object to add the array item to.
 * @param query_params The value to add.
 *
 * @return @a query_param_combination.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_add_query_params(data_collection_model_query_param_combination_t *query_param_combination, data_collection_model_query_parameter_t* query_params);

/** Remove an item from the queryParams array in a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * @param query_param_combination The QueryParamCombination object to remove the array value from.
 * @param query_params The value to remove.
 *
 * @return @a query_param_combination.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_remove_query_params(data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_parameter_t* query_params);

/** Get an item from the queryParams array in a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * @param query_param_combination The QueryParamCombination object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_query_parameter_t* data_collection_model_query_param_combination_get_entry_query_params(const data_collection_model_query_param_combination_t *query_param_combination, size_t idx);

/** Remove all entries from the queryParams array in a QueryParamCombination object
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * @param query_param_combination The QueryParamCombination object to empty queryParams for.
 *
 * @return @a query_param_combination
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_clear_query_params(data_collection_model_query_param_combination_t *query_param_combination);

/** lnode helper for generating ogs_list_t nodes's of type QueryParamCombination
 * \public \memberof data_collection_model_query_param_combination_t
 *
 * Creates a new data_collection_lnode_t object containing the @a query_param_combination object.
 * The @a query_param_combination will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param query_param_combination The QueryParamCombination object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a query_param_combination
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_query_param_combination_make_lnode(data_collection_model_query_param_combination_t *query_param_combination);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QUERY_PARAM_COMBINATION_H_ */

