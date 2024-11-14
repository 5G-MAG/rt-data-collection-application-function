#ifndef _DATA_COLLECTION_EXCEPTION_ID_H_
#define _DATA_COLLECTION_EXCEPTION_ID_H_

/**********************************************************************************************************************************
 * ExceptionId - Public C interface to the ExceptionId object
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

#include "ExceptionId_anyOf.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ExceptionId object reference
 */
typedef struct data_collection_model_exception_id_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_exception_id_t;


/** ExceptionId enumerated values */
typedef enum {
    DCM_EXCEPTION_ID_NO_VAL, /**< No value */
    DCM_EXCEPTION_ID_VAL_UNEXPECTED_UE_LOCATION, /**< UNEXPECTED_UE_LOCATION */
    DCM_EXCEPTION_ID_VAL_UNEXPECTED_LONG_LIVE_FLOW, /**< UNEXPECTED_LONG_LIVE_FLOW */
    DCM_EXCEPTION_ID_VAL_UNEXPECTED_LARGE_RATE_FLOW, /**< UNEXPECTED_LARGE_RATE_FLOW */
    DCM_EXCEPTION_ID_VAL_UNEXPECTED_WAKEUP, /**< UNEXPECTED_WAKEUP */
    DCM_EXCEPTION_ID_VAL_SUSPICION_OF_DDOS_ATTACK, /**< SUSPICION_OF_DDOS_ATTACK */
    DCM_EXCEPTION_ID_VAL_WRONG_DESTINATION_ADDRESS, /**< WRONG_DESTINATION_ADDRESS */
    DCM_EXCEPTION_ID_VAL_TOO_FREQUENT_SERVICE_ACCESS, /**< TOO_FREQUENT_SERVICE_ACCESS */
    DCM_EXCEPTION_ID_VAL_UNEXPECTED_RADIO_LINK_FAILURES, /**< UNEXPECTED_RADIO_LINK_FAILURES */
    DCM_EXCEPTION_ID_VAL_PING_PONG_ACROSS_CELLS, /**< PING_PONG_ACROSS_CELLS */
    DCM_EXCEPTION_ID_OTHER  /**< Custom value (future expansion) */
} data_collection_model_exception_id_e;


/** Create a new ExceptionId.
 * \public \memberof data_collection_model_exception_id_t
 * @return a new ExceptionId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_t *data_collection_model_exception_id_create();

/** Create a new ExceptionId reference.
 * \public \memberof data_collection_model_exception_id_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ExceptionId to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_t *data_collection_model_exception_id_create_ref(const data_collection_model_exception_id_t *other);

/** Create a new copy of a ExceptionId object.
 * \public \memberof data_collection_model_exception_id_t
 * Creates a new copy of the given @a other object
 * @param other The ExceptionId to copy.
 * @return a new ExceptionId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_t *data_collection_model_exception_id_create_copy(const data_collection_model_exception_id_t *other);

/** Create a new reference of a ExceptionId object
 * \public \memberof data_collection_model_exception_id_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ExceptionId to create a new reference to.
 * @return a new ExceptionId object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_t *data_collection_model_exception_id_create_move(data_collection_model_exception_id_t *other);

/** Copy the value of another ExceptionId into this object
 * \public \memberof data_collection_model_exception_id_t
 * Copies the value of @a other {{classname} object into @a exception_id.
 * @param exception_id The ExceptionId object to copy @a other into.
 * @param other The ExceptionId to copy the value from.
 * @return @a exception_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_t *data_collection_model_exception_id_copy(data_collection_model_exception_id_t *exception_id, const data_collection_model_exception_id_t *other);

/** Move the value of another ExceptionId into this object
 * \public \memberof data_collection_model_exception_id_t
 * Discards the current value of @a exception_id and moves the value of @a other
 * into @a exception_id. This will leave @a other as an empty reference.
 *
 * @param exception_id The ExceptionId object to move @a other into.
 * @param other The ExceptionId to move the value from.
 *
 * @return @a exception_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_t *data_collection_model_exception_id_move(data_collection_model_exception_id_t *exception_id, data_collection_model_exception_id_t *other);

/** Delete a ExceptionId object
 * \public \memberof data_collection_model_exception_id_t
 * Destroys the reference to the ExceptionId object and frees the value of ExceptionId if this is the last reference.
 *
 * @param exception_id The ExceptionId to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_exception_id_free(data_collection_model_exception_id_t *exception_id);

/** Get a cJSON tree representation of a ExceptionId
 * \public \memberof data_collection_model_exception_id_t
 *
 * Create a cJSON tree representation of the ExceptionId object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param exception_id The ExceptionId to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_exception_id_toJSON(const data_collection_model_exception_id_t *exception_id, bool as_request);

/** Parse a cJSON tree into a ExceptionId object
 * \public \memberof data_collection_model_exception_id_t
 *
 * Attempts to interpret a cJSON tree as a ExceptionId API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ExceptionId object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ExceptionId object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_t *data_collection_model_exception_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ExceptionId objects to see if they are equivalent
 * \public \memberof data_collection_model_exception_id_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param exception_id The first ExceptionId object to compare.
 * @param other_exception_id The second ExceptionId object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_is_equal_to(const data_collection_model_exception_id_t *exception_id, const data_collection_model_exception_id_t *other_exception_id);


/** Check if the ExceptionId enumeration object has a value set
 * \public \memberof data_collection_model_exception_id_t
 *
 * @param exception_id The ExceptionId enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_is_not_set(const data_collection_model_exception_id_t *exception_id);

/** Check if the ExceptionId enumeration object has a custom value set
 * \public \memberof data_collection_model_exception_id_t
 *
 * @param exception_id The ExceptionId enumeration object to check.
 * @return `true` if the enumeration object has an unknown string value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_is_non_standard(const data_collection_model_exception_id_t *exception_id);

/** Get the enumeration value for a ExceptionId object
 * \public \memberof data_collection_model_exception_id_t
 *
 * @param exception_id The ExceptionId object to extract the enumeration value from.
 *
 * @return the data_collection_model_exception_id_e value represented by the ExceptionId object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_e data_collection_model_exception_id_get_enum(const data_collection_model_exception_id_t *exception_id);

/** Get the string representation of the enumeration value for a ExceptionId object
 * \public \memberof data_collection_model_exception_id_t
 *
 * @param exception_id The ExceptionId object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_exception_id_get_string(const data_collection_model_exception_id_t *exception_id);

/** Set the enumeration value for a ExceptionId object
 * \public \memberof data_collection_model_exception_id_t
 *
 * @param exception_id The ExceptionId object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_set_enum(data_collection_model_exception_id_t *exception_id, data_collection_model_exception_id_e value);

/** Set the enumeration value as a string for a ExceptionId object
 * \public \memberof data_collection_model_exception_id_t
 *
 * Sets the enumeration value from the string given. If the string is a non-standard, custom value then the
 * data_collection_model_exception_id_get_enum
 * function will return DCM_EXCEPTION_ID_OTHER
 * while this value is set to indicate that this is a custom value.
 *
 * @param exception_id The ExceptionId object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` to indicate that the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_set_string(data_collection_model_exception_id_t *exception_id, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type ExceptionId
 * \public \memberof data_collection_model_exception_id_t
 *
 * Creates a new data_collection_lnode_t object containing the @a exception_id object.
 * The @a exception_id will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param exception_id The ExceptionId object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a exception_id
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_exception_id_make_lnode(data_collection_model_exception_id_t *exception_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EXCEPTION_ID_H_ */

