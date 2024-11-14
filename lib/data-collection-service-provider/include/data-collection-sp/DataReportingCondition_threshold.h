#ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_THRESHOLD_H_
#define _DATA_COLLECTION_DATA_REPORTING_CONDITION_THRESHOLD_H_

/**********************************************************************************************************************************
 * DataReportingCondition_threshold - Public C interface to the DataReportingCondition_threshold object
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

/** A 3GPP DataReportingCondition_threshold object reference
 */
typedef struct data_collection_model_data_reporting_condition_threshold_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_reporting_condition_threshold_t;



/** Create a new DataReportingCondition_threshold.
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 * @return a new DataReportingCondition_threshold object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create();

/** Create a new DataReportingCondition_threshold reference.
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The DataReportingCondition_threshold to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create_ref(const data_collection_model_data_reporting_condition_threshold_t *other);

/** Create a new copy of a DataReportingCondition_threshold object.
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 * Creates a new copy of the given @a other object
 * @param other The DataReportingCondition_threshold to copy.
 * @return a new DataReportingCondition_threshold object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create_copy(const data_collection_model_data_reporting_condition_threshold_t *other);

/** Create a new reference of a DataReportingCondition_threshold object
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataReportingCondition_threshold to create a new reference to.
 * @return a new DataReportingCondition_threshold object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create_move(data_collection_model_data_reporting_condition_threshold_t *other);

/** Copy the value of another DataReportingCondition_threshold into this object
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 * Copies the value of @a other {{classname} object into @a data_reporting_condition_threshold.
 * @param data_reporting_condition_threshold The DataReportingCondition_threshold object to copy @a other into.
 * @param other The DataReportingCondition_threshold to copy the value from.
 * @return @a data_reporting_condition_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_copy(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, const data_collection_model_data_reporting_condition_threshold_t *other);

/** Move the value of another DataReportingCondition_threshold into this object
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 * Discards the current value of @a data_reporting_condition_threshold and moves the value of @a other
 * into @a data_reporting_condition_threshold. This will leave @a other as an empty reference.
 *
 * @param data_reporting_condition_threshold The DataReportingCondition_threshold object to move @a other into.
 * @param other The DataReportingCondition_threshold to move the value from.
 *
 * @return @a data_reporting_condition_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_move(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, data_collection_model_data_reporting_condition_threshold_t *other);

/** Delete a DataReportingCondition_threshold object
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 * Destroys the reference to the DataReportingCondition_threshold object and frees the value of DataReportingCondition_threshold if this is the last reference.
 *
 * @param data_reporting_condition_threshold The DataReportingCondition_threshold to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_condition_threshold_free(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold);

/** Get a cJSON tree representation of a DataReportingCondition_threshold
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 *
 * Create a cJSON tree representation of the DataReportingCondition_threshold object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_reporting_condition_threshold The DataReportingCondition_threshold to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_condition_threshold_toJSON(const data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, bool as_request);

/** Parse a cJSON tree into a DataReportingCondition_threshold object
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 *
 * Attempts to interpret a cJSON tree as a DataReportingCondition_threshold API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataReportingCondition_threshold object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataReportingCondition_threshold object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataReportingCondition_threshold objects to see if they are equivalent
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_reporting_condition_threshold The first DataReportingCondition_threshold object to compare.
 * @param other_data_reporting_condition_threshold The second DataReportingCondition_threshold object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_threshold_is_equal_to(const data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, const data_collection_model_data_reporting_condition_threshold_t *other_data_reporting_condition_threshold);


/** lnode helper for generating ogs_list_t nodes's of type DataReportingCondition_threshold
 * \public \memberof data_collection_model_data_reporting_condition_threshold_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_reporting_condition_threshold object.
 * The @a data_reporting_condition_threshold will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_reporting_condition_threshold The DataReportingCondition_threshold object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_reporting_condition_threshold
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_condition_threshold_make_lnode(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_THRESHOLD_H_ */

