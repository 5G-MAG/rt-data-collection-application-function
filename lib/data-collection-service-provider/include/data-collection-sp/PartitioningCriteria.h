#ifndef _DATA_COLLECTION_PARTITIONING_CRITERIA_H_
#define _DATA_COLLECTION_PARTITIONING_CRITERIA_H_

/**********************************************************************************************************************************
 * PartitioningCriteria - Public C interface to the PartitioningCriteria object
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

#include "PartitioningCriteria_anyOf.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PartitioningCriteria object reference
 */
typedef struct data_collection_model_partitioning_criteria_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_partitioning_criteria_t;


/** PartitioningCriteria enumerated values */
typedef enum {
    DCM_PARTITIONING_CRITERIA_NO_VAL, /**< No value */
    DCM_PARTITIONING_CRITERIA_VAL_TAC, /**< TAC */
    DCM_PARTITIONING_CRITERIA_VAL_SUBPLMN, /**< SUBPLMN */
    DCM_PARTITIONING_CRITERIA_VAL_GEOAREA, /**< GEOAREA */
    DCM_PARTITIONING_CRITERIA_VAL_SNSSAI, /**< SNSSAI */
    DCM_PARTITIONING_CRITERIA_VAL_DNN, /**< DNN */
    DCM_PARTITIONING_CRITERIA_OTHER  /**< Custom value (future expansion) */
} data_collection_model_partitioning_criteria_e;


/** Create a new PartitioningCriteria.
 * \public \memberof data_collection_model_partitioning_criteria_t
 * @return a new PartitioningCriteria object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create();

/** Create a new PartitioningCriteria reference.
 * \public \memberof data_collection_model_partitioning_criteria_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PartitioningCriteria to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create_ref(const data_collection_model_partitioning_criteria_t *other);

/** Create a new copy of a PartitioningCriteria object.
 * \public \memberof data_collection_model_partitioning_criteria_t
 * Creates a new copy of the given @a other object
 * @param other The PartitioningCriteria to copy.
 * @return a new PartitioningCriteria object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create_copy(const data_collection_model_partitioning_criteria_t *other);

/** Create a new reference of a PartitioningCriteria object
 * \public \memberof data_collection_model_partitioning_criteria_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PartitioningCriteria to create a new reference to.
 * @return a new PartitioningCriteria object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create_move(data_collection_model_partitioning_criteria_t *other);

/** Copy the value of another PartitioningCriteria into this object
 * \public \memberof data_collection_model_partitioning_criteria_t
 * Copies the value of @a other {{classname} object into @a partitioning_criteria.
 * @param partitioning_criteria The PartitioningCriteria object to copy @a other into.
 * @param other The PartitioningCriteria to copy the value from.
 * @return @a partitioning_criteria.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_copy(data_collection_model_partitioning_criteria_t *partitioning_criteria, const data_collection_model_partitioning_criteria_t *other);

/** Move the value of another PartitioningCriteria into this object
 * \public \memberof data_collection_model_partitioning_criteria_t
 * Discards the current value of @a partitioning_criteria and moves the value of @a other
 * into @a partitioning_criteria. This will leave @a other as an empty reference.
 *
 * @param partitioning_criteria The PartitioningCriteria object to move @a other into.
 * @param other The PartitioningCriteria to move the value from.
 *
 * @return @a partitioning_criteria.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_move(data_collection_model_partitioning_criteria_t *partitioning_criteria, data_collection_model_partitioning_criteria_t *other);

/** Delete a PartitioningCriteria object
 * \public \memberof data_collection_model_partitioning_criteria_t
 * Destroys the reference to the PartitioningCriteria object and frees the value of PartitioningCriteria if this is the last reference.
 *
 * @param partitioning_criteria The PartitioningCriteria to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_partitioning_criteria_free(data_collection_model_partitioning_criteria_t *partitioning_criteria);

/** Get a cJSON tree representation of a PartitioningCriteria
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * Create a cJSON tree representation of the PartitioningCriteria object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param partitioning_criteria The PartitioningCriteria to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_partitioning_criteria_toJSON(const data_collection_model_partitioning_criteria_t *partitioning_criteria, bool as_request);

/** Parse a cJSON tree into a PartitioningCriteria object
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * Attempts to interpret a cJSON tree as a PartitioningCriteria API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PartitioningCriteria object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PartitioningCriteria object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PartitioningCriteria objects to see if they are equivalent
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param partitioning_criteria The first PartitioningCriteria object to compare.
 * @param other_partitioning_criteria The second PartitioningCriteria object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_equal_to(const data_collection_model_partitioning_criteria_t *partitioning_criteria, const data_collection_model_partitioning_criteria_t *other_partitioning_criteria);


/** Check if the PartitioningCriteria enumeration object has a value set
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * @param partitioning_criteria The PartitioningCriteria enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_not_set(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

/** Check if the PartitioningCriteria enumeration object has a custom value set
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * @param partitioning_criteria The PartitioningCriteria enumeration object to check.
 * @return `true` if the enumeration object has an unknown string value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_non_standard(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

/** Get the enumeration value for a PartitioningCriteria object
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * @param partitioning_criteria The PartitioningCriteria object to extract the enumeration value from.
 *
 * @return the data_collection_model_partitioning_criteria_e value represented by the PartitioningCriteria object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_e data_collection_model_partitioning_criteria_get_enum(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

/** Get the string representation of the enumeration value for a PartitioningCriteria object
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * @param partitioning_criteria The PartitioningCriteria object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_partitioning_criteria_get_string(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

/** Set the enumeration value for a PartitioningCriteria object
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * @param partitioning_criteria The PartitioningCriteria object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_set_enum(data_collection_model_partitioning_criteria_t *partitioning_criteria, data_collection_model_partitioning_criteria_e value);

/** Set the enumeration value as a string for a PartitioningCriteria object
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * Sets the enumeration value from the string given. If the string is a non-standard, custom value then the
 * data_collection_model_partitioning_criteria_get_enum
 * function will return DCM_PARTITIONING_CRITERIA_OTHER
 * while this value is set to indicate that this is a custom value.
 *
 * @param partitioning_criteria The PartitioningCriteria object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` to indicate that the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_set_string(data_collection_model_partitioning_criteria_t *partitioning_criteria, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type PartitioningCriteria
 * \public \memberof data_collection_model_partitioning_criteria_t
 *
 * Creates a new data_collection_lnode_t object containing the @a partitioning_criteria object.
 * The @a partitioning_criteria will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param partitioning_criteria The PartitioningCriteria object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a partitioning_criteria
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_partitioning_criteria_make_lnode(data_collection_model_partitioning_criteria_t *partitioning_criteria);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PARTITIONING_CRITERIA_H_ */

