#ifndef _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TYPE_H_
#define _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TYPE_H_

/**********************************************************************************************************************************
 * ScheduledCommunicationType - Public C interface to the ScheduledCommunicationType object
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

#include "ScheduledCommunicationType_anyOf.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ScheduledCommunicationType object reference
 */
typedef struct data_collection_model_scheduled_communication_type_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_scheduled_communication_type_t;


/** ScheduledCommunicationType enumerated values */
typedef enum {
    DCM_SCHEDULED_COMMUNICATION_TYPE_NO_VAL, /**< No value */
    DCM_SCHEDULED_COMMUNICATION_TYPE_VAL_DOWNLINK, /**< DOWNLINK */
    DCM_SCHEDULED_COMMUNICATION_TYPE_VAL_UPLINK, /**< UPLINK */
    DCM_SCHEDULED_COMMUNICATION_TYPE_VAL_BIDIRECTIONAL, /**< BIDIRECTIONAL */
    DCM_SCHEDULED_COMMUNICATION_TYPE_OTHER  /**< Custom value (future expansion) */
} data_collection_model_scheduled_communication_type_e;


/** Create a new ScheduledCommunicationType.
 * \public \memberof data_collection_model_scheduled_communication_type_t
 * @return a new ScheduledCommunicationType object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_t *data_collection_model_scheduled_communication_type_create();

/** Create a new ScheduledCommunicationType reference.
 * \public \memberof data_collection_model_scheduled_communication_type_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ScheduledCommunicationType to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_t *data_collection_model_scheduled_communication_type_create_ref(const data_collection_model_scheduled_communication_type_t *other);

/** Create a new copy of a ScheduledCommunicationType object.
 * \public \memberof data_collection_model_scheduled_communication_type_t
 * Creates a new copy of the given @a other object
 * @param other The ScheduledCommunicationType to copy.
 * @return a new ScheduledCommunicationType object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_t *data_collection_model_scheduled_communication_type_create_copy(const data_collection_model_scheduled_communication_type_t *other);

/** Create a new reference of a ScheduledCommunicationType object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ScheduledCommunicationType to create a new reference to.
 * @return a new ScheduledCommunicationType object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_t *data_collection_model_scheduled_communication_type_create_move(data_collection_model_scheduled_communication_type_t *other);

/** Copy the value of another ScheduledCommunicationType into this object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 * Copies the value of @a other {{classname} object into @a scheduled_communication_type.
 * @param scheduled_communication_type The ScheduledCommunicationType object to copy @a other into.
 * @param other The ScheduledCommunicationType to copy the value from.
 * @return @a scheduled_communication_type.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_t *data_collection_model_scheduled_communication_type_copy(data_collection_model_scheduled_communication_type_t *scheduled_communication_type, const data_collection_model_scheduled_communication_type_t *other);

/** Move the value of another ScheduledCommunicationType into this object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 * Discards the current value of @a scheduled_communication_type and moves the value of @a other
 * into @a scheduled_communication_type. This will leave @a other as an empty reference.
 *
 * @param scheduled_communication_type The ScheduledCommunicationType object to move @a other into.
 * @param other The ScheduledCommunicationType to move the value from.
 *
 * @return @a scheduled_communication_type.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_t *data_collection_model_scheduled_communication_type_move(data_collection_model_scheduled_communication_type_t *scheduled_communication_type, data_collection_model_scheduled_communication_type_t *other);

/** Delete a ScheduledCommunicationType object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 * Destroys the reference to the ScheduledCommunicationType object and frees the value of ScheduledCommunicationType if this is the last reference.
 *
 * @param scheduled_communication_type The ScheduledCommunicationType to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_scheduled_communication_type_free(data_collection_model_scheduled_communication_type_t *scheduled_communication_type);

/** Get a cJSON tree representation of a ScheduledCommunicationType
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * Create a cJSON tree representation of the ScheduledCommunicationType object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param scheduled_communication_type The ScheduledCommunicationType to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_scheduled_communication_type_toJSON(const data_collection_model_scheduled_communication_type_t *scheduled_communication_type, bool as_request);

/** Parse a cJSON tree into a ScheduledCommunicationType object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * Attempts to interpret a cJSON tree as a ScheduledCommunicationType API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ScheduledCommunicationType object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ScheduledCommunicationType object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_t *data_collection_model_scheduled_communication_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ScheduledCommunicationType objects to see if they are equivalent
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param scheduled_communication_type The first ScheduledCommunicationType object to compare.
 * @param other_scheduled_communication_type The second ScheduledCommunicationType object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_type_is_equal_to(const data_collection_model_scheduled_communication_type_t *scheduled_communication_type, const data_collection_model_scheduled_communication_type_t *other_scheduled_communication_type);


/** Check if the ScheduledCommunicationType enumeration object has a value set
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * @param scheduled_communication_type The ScheduledCommunicationType enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_type_is_not_set(const data_collection_model_scheduled_communication_type_t *scheduled_communication_type);

/** Check if the ScheduledCommunicationType enumeration object has a custom value set
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * @param scheduled_communication_type The ScheduledCommunicationType enumeration object to check.
 * @return `true` if the enumeration object has an unknown string value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_type_is_non_standard(const data_collection_model_scheduled_communication_type_t *scheduled_communication_type);

/** Get the enumeration value for a ScheduledCommunicationType object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * @param scheduled_communication_type The ScheduledCommunicationType object to extract the enumeration value from.
 *
 * @return the data_collection_model_scheduled_communication_type_e value represented by the ScheduledCommunicationType object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_type_e data_collection_model_scheduled_communication_type_get_enum(const data_collection_model_scheduled_communication_type_t *scheduled_communication_type);

/** Get the string representation of the enumeration value for a ScheduledCommunicationType object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * @param scheduled_communication_type The ScheduledCommunicationType object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_scheduled_communication_type_get_string(const data_collection_model_scheduled_communication_type_t *scheduled_communication_type);

/** Set the enumeration value for a ScheduledCommunicationType object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * @param scheduled_communication_type The ScheduledCommunicationType object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_type_set_enum(data_collection_model_scheduled_communication_type_t *scheduled_communication_type, data_collection_model_scheduled_communication_type_e value);

/** Set the enumeration value as a string for a ScheduledCommunicationType object
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * Sets the enumeration value from the string given. If the string is a non-standard, custom value then the
 * data_collection_model_scheduled_communication_type_get_enum
 * function will return DCM_SCHEDULED_COMMUNICATION_TYPE_OTHER
 * while this value is set to indicate that this is a custom value.
 *
 * @param scheduled_communication_type The ScheduledCommunicationType object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` to indicate that the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_type_set_string(data_collection_model_scheduled_communication_type_t *scheduled_communication_type, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type ScheduledCommunicationType
 * \public \memberof data_collection_model_scheduled_communication_type_t
 *
 * Creates a new data_collection_lnode_t object containing the @a scheduled_communication_type object.
 * The @a scheduled_communication_type will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param scheduled_communication_type The ScheduledCommunicationType object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a scheduled_communication_type
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_scheduled_communication_type_make_lnode(data_collection_model_scheduled_communication_type_t *scheduled_communication_type);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TYPE_H_ */

