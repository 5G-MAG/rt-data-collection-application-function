#ifndef _DATA_COLLECTION_EXCEPTION_H_
#define _DATA_COLLECTION_EXCEPTION_H_

/**********************************************************************************************************************************
 * Exception - Public C interface to the Exception object
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

#include "ExceptionTrend.h"
#include "ExceptionId.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP Exception object reference
 */
typedef struct data_collection_model_exception_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_exception_t;



/** Create a new Exception
 * \public \memberof data_collection_model_exception_t
 * @return a new Exception object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create();

/** Create a new copy of a Exception object
 * \public \memberof data_collection_model_exception_t
 * Creates a new copy of the given @a other object
 * @param other The Exception to copy.
 * @return a new Exception object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create_copy(const data_collection_model_exception_t *other);

/** Create a new reference of a Exception object
 * \public \memberof data_collection_model_exception_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Exception to create a new reference to.
 * @return a new Exception object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create_move(data_collection_model_exception_t *other);

/** Copy the value of another Exception into this object
 * \public \memberof data_collection_model_exception_t
 * Copies the value of @a other {{classname} object into @a exception.
 * @param exception The Exception object to copy @a other into.
 * @param other The Exception to copy the value from.
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_copy(data_collection_model_exception_t *exception, const data_collection_model_exception_t *other);

/** Move the value of another Exception into this object
 * \public \memberof data_collection_model_exception_t
 * Discards the current value of @a exception and moves the value of @a other
 * into @a exception. This will leave @a other as an empty reference.
 *
 * @param exception The Exception object to move @a other into.
 * @param other The Exception to move the value from.
 *
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_move(data_collection_model_exception_t *exception, data_collection_model_exception_t *other);

/** Delete a Exception object
 * \public \memberof data_collection_model_exception_t
 * Destroys the reference to the Exception object and frees the value of Exception if this is the last reference.
 *
 * @param exception The Exception to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_exception_free(data_collection_model_exception_t *exception);

/** Get a cJSON tree representation of a Exception
 * \public \memberof data_collection_model_exception_t
 *
 * Create a cJSON tree representation of the Exception object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param exception The Exception to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_exception_toJSON(const data_collection_model_exception_t *exception, bool as_request);

/** Parse a cJSON tree into a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * Attempts to interpret a cJSON tree as a Exception API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Exception object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Exception object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Exception objects to see if they are equivalent
 * \public \memberof data_collection_model_exception_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param exception The first Exception object to compare.
 * @param other_exception The second Exception object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_is_equal_to(const data_collection_model_exception_t *exception, const data_collection_model_exception_t *other_exception);



/** Get the value of the excepId field of a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to examine.
 *
 * @return the value current set for the excepId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_id_t* data_collection_model_exception_get_excep_id(const data_collection_model_exception_t *exception);

/** Set the value of the excepId field in a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to set the field in.
 * @param p_excep_id The value to copy into the Exception object.
 *
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_id(data_collection_model_exception_t *exception, const data_collection_model_exception_id_t* p_excep_id);

/** Move a value to the excepId field in a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to set the field in.
 * @param p_excep_id The value to move into the Exception object.
 *
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_id_move(data_collection_model_exception_t *exception, data_collection_model_exception_id_t* p_excep_id);

/** Check if the excepLevel field of a Exception object is set
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to examine.
 *
 * @return `true` if the optional excepLevel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_has_excep_level(const data_collection_model_exception_t *exception);


/** Get the value of the excepLevel field of a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to examine.
 *
 * @return the value current set for the excepLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_exception_get_excep_level(const data_collection_model_exception_t *exception);

/** Set the value of the excepLevel field in a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to set the field in.
 * @param p_excep_level The value to copy into the Exception object.
 *
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_level(data_collection_model_exception_t *exception, const int32_t p_excep_level);

/** Move a value to the excepLevel field in a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to set the field in.
 * @param p_excep_level The value to move into the Exception object.
 *
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_level_move(data_collection_model_exception_t *exception, int32_t p_excep_level);

/** Check if the excepTrend field of a Exception object is set
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to examine.
 *
 * @return `true` if the optional excepTrend field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_has_excep_trend(const data_collection_model_exception_t *exception);


/** Get the value of the excepTrend field of a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to examine.
 *
 * @return the value current set for the excepTrend field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_trend_t* data_collection_model_exception_get_excep_trend(const data_collection_model_exception_t *exception);

/** Set the value of the excepTrend field in a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to set the field in.
 * @param p_excep_trend The value to copy into the Exception object.
 *
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_trend(data_collection_model_exception_t *exception, const data_collection_model_exception_trend_t* p_excep_trend);

/** Move a value to the excepTrend field in a Exception object
 * \public \memberof data_collection_model_exception_t
 *
 * @param exception The Exception object to set the field in.
 * @param p_excep_trend The value to move into the Exception object.
 *
 * @return @a exception.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_trend_move(data_collection_model_exception_t *exception, data_collection_model_exception_trend_t* p_excep_trend);

/** lnode helper for generating ogs_list_t nodes's of type Exception
 * \public \memberof data_collection_model_exception_t
 *
 * Creates a new data_collection_lnode_t object containing the @a exception object.
 * The @a exception will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param exception The Exception object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a exception
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_exception_make_lnode(data_collection_model_exception_t *exception);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EXCEPTION_H_ */

