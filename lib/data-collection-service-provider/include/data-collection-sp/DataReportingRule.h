#ifndef _DATA_COLLECTION_DATA_REPORTING_RULE_H_
#define _DATA_COLLECTION_DATA_REPORTING_RULE_H_

/**********************************************************************************************************************************
 * DataReportingRule - Public C interface to the DataReportingRule object
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

/** A 3GPP DataReportingRule object reference
 */
typedef struct data_collection_model_data_reporting_rule_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_reporting_rule_t;



/** Create a new DataReportingRule
 * \public \memberof data_collection_model_data_reporting_rule_t
 * @return a new DataReportingRule object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create();

/** Create a new copy of a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 * Creates a new copy of the given @a other object
 * @param other The DataReportingRule to copy.
 * @return a new DataReportingRule object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_copy(const data_collection_model_data_reporting_rule_t *other);

/** Create a new reference of a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataReportingRule to create a new reference to.
 * @return a new DataReportingRule object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_move(data_collection_model_data_reporting_rule_t *other);

/** Copy the value of another DataReportingRule into this object
 * \public \memberof data_collection_model_data_reporting_rule_t
 * Copies the value of @a other {{classname} object into @a data_reporting_rule.
 * @param data_reporting_rule The DataReportingRule object to copy @a other into.
 * @param other The DataReportingRule to copy the value from.
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_copy(data_collection_model_data_reporting_rule_t *data_reporting_rule, const data_collection_model_data_reporting_rule_t *other);

/** Move the value of another DataReportingRule into this object
 * \public \memberof data_collection_model_data_reporting_rule_t
 * Discards the current value of @a data_reporting_rule and moves the value of @a other
 * into @a data_reporting_rule. This will leave @a other as an empty reference.
 *
 * @param data_reporting_rule The DataReportingRule object to move @a other into.
 * @param other The DataReportingRule to move the value from.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, data_collection_model_data_reporting_rule_t *other);

/** Delete a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 * Destroys the reference to the DataReportingRule object and frees the value of DataReportingRule if this is the last reference.
 *
 * @param data_reporting_rule The DataReportingRule to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_rule_free(data_collection_model_data_reporting_rule_t *data_reporting_rule);

/** Get a cJSON tree representation of a DataReportingRule
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * Create a cJSON tree representation of the DataReportingRule object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_reporting_rule The DataReportingRule to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_rule_toJSON(const data_collection_model_data_reporting_rule_t *data_reporting_rule, bool as_request);

/** Parse a cJSON tree into a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * Attempts to interpret a cJSON tree as a DataReportingRule API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataReportingRule object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataReportingRule object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataReportingRule objects to see if they are equivalent
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_reporting_rule The first DataReportingRule object to compare.
 * @param other_data_reporting_rule The second DataReportingRule object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_is_equal_to(const data_collection_model_data_reporting_rule_t *data_reporting_rule, const data_collection_model_data_reporting_rule_t *other_data_reporting_rule);


/** Check if the contextIds field of a DataReportingRule object is set
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return `true` if the optional contextIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_context_ids(const data_collection_model_data_reporting_rule_t *data_reporting_rule);


/** Get the value of the contextIds field of a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_rule_get_context_ids(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

/** Set the value of the contextIds field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_context_ids The value to copy into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_context_ids The value to move into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_add_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule, char* context_ids);

/** Remove an item from the contextIds array in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_remove_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule, const char* context_ids);

/** Get an item from the contextIds array in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_rule_get_entry_context_ids(const data_collection_model_data_reporting_rule_t *data_reporting_rule, size_t idx);

/** Remove all entries from the contextIds array in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to empty contextIds for.
 *
 * @return @a data_reporting_rule
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_clear_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule);

/** Check if the reportingProbability field of a DataReportingRule object is set
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return `true` if the optional reportingProbability field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_reporting_probability(const data_collection_model_data_reporting_rule_t *data_reporting_rule);


/** Get the value of the reportingProbability field of a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return the value current set for the reportingProbability field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_data_reporting_rule_get_reporting_probability(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

/** Set the value of the reportingProbability field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_reporting_probability The value to copy into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability(data_collection_model_data_reporting_rule_t *data_reporting_rule, const double p_reporting_probability);

/** Move a value to the reportingProbability field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_reporting_probability The value to move into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, double p_reporting_probability);

/** Check if the reportingFormat field of a DataReportingRule object is set
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return `true` if the optional reportingFormat field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_reporting_format(const data_collection_model_data_reporting_rule_t *data_reporting_rule);


/** Get the value of the reportingFormat field of a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return the value current set for the reportingFormat field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_rule_get_reporting_format(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

/** Set the value of the reportingFormat field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_reporting_format The value to copy into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format(data_collection_model_data_reporting_rule_t *data_reporting_rule, const char* p_reporting_format);

/** Move a value to the reportingFormat field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_reporting_format The value to move into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, char* p_reporting_format);

/** Check if the dataPackagingStrategy field of a DataReportingRule object is set
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return `true` if the optional dataPackagingStrategy field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_data_packaging_strategy(const data_collection_model_data_reporting_rule_t *data_reporting_rule);


/** Get the value of the dataPackagingStrategy field of a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to examine.
 *
 * @return the value current set for the dataPackagingStrategy field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_rule_get_data_packaging_strategy(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

/** Set the value of the dataPackagingStrategy field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_data_packaging_strategy The value to copy into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy(data_collection_model_data_reporting_rule_t *data_reporting_rule, const char* p_data_packaging_strategy);

/** Move a value to the dataPackagingStrategy field in a DataReportingRule object
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * @param data_reporting_rule The DataReportingRule object to set the field in.
 * @param p_data_packaging_strategy The value to move into the DataReportingRule object.
 *
 * @return @a data_reporting_rule.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, char* p_data_packaging_strategy);

/** lnode helper for generating ogs_list_t nodes's of type DataReportingRule
 * \public \memberof data_collection_model_data_reporting_rule_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_reporting_rule object.
 * The @a data_reporting_rule will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_reporting_rule The DataReportingRule object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_reporting_rule
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_rule_make_lnode(data_collection_model_data_reporting_rule_t *data_reporting_rule);

/** Check if two DataReportingRules are equal without checking the contextIds array */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_is_equal_to_sans_context_ids(const data_collection_model_data_reporting_rule_t *first, const data_collection_model_data_reporting_rule_t *second);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_RULE_H_ */

