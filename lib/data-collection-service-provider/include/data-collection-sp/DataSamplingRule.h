#ifndef _DATA_COLLECTION_DATA_SAMPLING_RULE_H_
#define _DATA_COLLECTION_DATA_SAMPLING_RULE_H_

/**********************************************************************************************************************************
 * DataSamplingRule - Public C interface to the DataSamplingRule object
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

#include "LocationArea5G.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataSamplingRule object reference
 */
typedef struct data_collection_model_data_sampling_rule_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_sampling_rule_t;



/** Create a new DataSamplingRule
 * \public \memberof data_collection_model_data_sampling_rule_t
 * @return a new DataSamplingRule object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create();

/** Create a new copy of a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 * Creates a new copy of the given @a other object
 * @param other The DataSamplingRule to copy.
 * @return a new DataSamplingRule object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_copy(const data_collection_model_data_sampling_rule_t *other);

/** Create a new reference of a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataSamplingRule to create a new reference to.
 * @return a new DataSamplingRule object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_move(data_collection_model_data_sampling_rule_t *other);

/** Copy the value of another DataSamplingRule into this object
 * \public \memberof data_collection_model_data_sampling_rule_t
 * Copies the value of @a other {{classname} object into @a data_sampling_rule.
 * @param data_sampling_rule The DataSamplingRule object to copy @a other into.
 * @param other The DataSamplingRule to copy the value from.
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_copy(data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_data_sampling_rule_t *other);

/** Move the value of another DataSamplingRule into this object
 * \public \memberof data_collection_model_data_sampling_rule_t
 * Discards the current value of @a data_sampling_rule and moves the value of @a other
 * into @a data_sampling_rule. This will leave @a other as an empty reference.
 *
 * @param data_sampling_rule The DataSamplingRule object to move @a other into.
 * @param other The DataSamplingRule to move the value from.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, data_collection_model_data_sampling_rule_t *other);

/** Delete a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 * Destroys the reference to the DataSamplingRule object and frees the value of DataSamplingRule if this is the last reference.
 *
 * @param data_sampling_rule The DataSamplingRule to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_sampling_rule_free(data_collection_model_data_sampling_rule_t *data_sampling_rule);

/** Get a cJSON tree representation of a DataSamplingRule
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * Create a cJSON tree representation of the DataSamplingRule object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_sampling_rule The DataSamplingRule to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_sampling_rule_toJSON(const data_collection_model_data_sampling_rule_t *data_sampling_rule, bool as_request);

/** Parse a cJSON tree into a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * Attempts to interpret a cJSON tree as a DataSamplingRule API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataSamplingRule object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataSamplingRule object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataSamplingRule objects to see if they are equivalent
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_sampling_rule The first DataSamplingRule object to compare.
 * @param other_data_sampling_rule The second DataSamplingRule object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_sampling_rule_is_equal_to(const data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_data_sampling_rule_t *other_data_sampling_rule);


/** Check if the contextIds field of a DataSamplingRule object is set
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to examine.
 *
 * @return `true` if the optional contextIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_sampling_rule_has_context_ids(const data_collection_model_data_sampling_rule_t *data_sampling_rule);


/** Get the value of the contextIds field of a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_sampling_rule_get_context_ids(const data_collection_model_data_sampling_rule_t *data_sampling_rule);

/** Set the value of the contextIds field in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to set the field in.
 * @param p_context_ids The value to copy into the DataSamplingRule object.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to set the field in.
 * @param p_context_ids The value to move into the DataSamplingRule object.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_context_ids_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_add_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule, char* context_ids);

/** Remove an item from the contextIds array in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_remove_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule, const char* context_ids);

/** Get an item from the contextIds array in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_sampling_rule_get_entry_context_ids(const data_collection_model_data_sampling_rule_t *data_sampling_rule, size_t idx);

/** Remove all entries from the contextIds array in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to empty contextIds for.
 *
 * @return @a data_sampling_rule
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_clear_context_ids(data_collection_model_data_sampling_rule_t *data_sampling_rule);

/** Check if the samplingPeriod field of a DataSamplingRule object is set
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to examine.
 *
 * @return `true` if the optional samplingPeriod field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_sampling_rule_has_sampling_period(const data_collection_model_data_sampling_rule_t *data_sampling_rule);


/** Get the value of the samplingPeriod field of a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to examine.
 *
 * @return the value current set for the samplingPeriod field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_data_sampling_rule_get_sampling_period(const data_collection_model_data_sampling_rule_t *data_sampling_rule);

/** Set the value of the samplingPeriod field in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to set the field in.
 * @param p_sampling_period The value to copy into the DataSamplingRule object.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period(data_collection_model_data_sampling_rule_t *data_sampling_rule, const float p_sampling_period);

/** Move a value to the samplingPeriod field in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to set the field in.
 * @param p_sampling_period The value to move into the DataSamplingRule object.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, float p_sampling_period);

/** Check if the locationFilter field of a DataSamplingRule object is set
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to examine.
 *
 * @return `true` if the optional locationFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_sampling_rule_has_location_filter(const data_collection_model_data_sampling_rule_t *data_sampling_rule);


/** Get the value of the locationFilter field of a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to examine.
 *
 * @return the value current set for the locationFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_data_sampling_rule_get_location_filter(const data_collection_model_data_sampling_rule_t *data_sampling_rule);

/** Set the value of the locationFilter field in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to set the field in.
 * @param p_location_filter The value to copy into the DataSamplingRule object.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter(data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_location_area5_g_t* p_location_filter);

/** Move a value to the locationFilter field in a DataSamplingRule object
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * @param data_sampling_rule The DataSamplingRule object to set the field in.
 * @param p_location_filter The value to move into the DataSamplingRule object.
 *
 * @return @a data_sampling_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, data_collection_model_location_area5_g_t* p_location_filter);

/** lnode helper for generating ogs_list_t nodes's of type DataSamplingRule
 * \public \memberof data_collection_model_data_sampling_rule_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_sampling_rule object.
 * The @a data_sampling_rule will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_sampling_rule The DataSamplingRule object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_sampling_rule
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_sampling_rule_make_lnode(data_collection_model_data_sampling_rule_t *data_sampling_rule);

/** Check if two DataSamplingRules are equal without checking the contextIds array */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_sampling_rule_is_equal_to_sans_context_ids(const data_collection_model_data_sampling_rule_t *first, const data_collection_model_data_sampling_rule_t *second);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_SAMPLING_RULE_H_ */

