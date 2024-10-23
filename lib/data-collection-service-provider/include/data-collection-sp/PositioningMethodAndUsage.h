#ifndef _DATA_COLLECTION_POSITIONING_METHOD_AND_USAGE_H_
#define _DATA_COLLECTION_POSITIONING_METHOD_AND_USAGE_H_

/**********************************************************************************************************************************
 * PositioningMethodAndUsage - Public C interface to the PositioningMethodAndUsage object
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

#include "Usage.h"
#include "PositioningMethod.h"
#include "PositioningMode.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PositioningMethodAndUsage object reference
 */
typedef struct data_collection_model_positioning_method_and_usage_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_positioning_method_and_usage_t;



/** Create a new PositioningMethodAndUsage
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 * @return a new PositioningMethodAndUsage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create();

/** Create a new copy of a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 * Creates a new copy of the given @a other object
 * @param other The PositioningMethodAndUsage to copy.
 * @return a new PositioningMethodAndUsage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_copy(const data_collection_model_positioning_method_and_usage_t *other);

/** Create a new reference of a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PositioningMethodAndUsage to create a new reference to.
 * @return a new PositioningMethodAndUsage object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_move(data_collection_model_positioning_method_and_usage_t *other);

/** Copy the value of another PositioningMethodAndUsage into this object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 * Copies the value of @a other {{classname} object into @a positioning_method_and_usage.
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to copy @a other into.
 * @param other The PositioningMethodAndUsage to copy the value from.
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_copy(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_and_usage_t *other);

/** Move the value of another PositioningMethodAndUsage into this object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 * Discards the current value of @a positioning_method_and_usage and moves the value of @a other
 * into @a positioning_method_and_usage. This will leave @a other as an empty reference.
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to move @a other into.
 * @param other The PositioningMethodAndUsage to move the value from.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_method_and_usage_t *other);

/** Delete a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 * Destroys the reference to the PositioningMethodAndUsage object and frees the value of PositioningMethodAndUsage if this is the last reference.
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_method_and_usage_free(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

/** Get a cJSON tree representation of a PositioningMethodAndUsage
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * Create a cJSON tree representation of the PositioningMethodAndUsage object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_method_and_usage_toJSON(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, bool as_request);

/** Parse a cJSON tree into a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * Attempts to interpret a cJSON tree as a PositioningMethodAndUsage API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PositioningMethodAndUsage object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PositioningMethodAndUsage object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PositioningMethodAndUsage objects to see if they are equivalent
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param positioning_method_and_usage The first PositioningMethodAndUsage object to compare.
 * @param other_positioning_method_and_usage The second PositioningMethodAndUsage object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_and_usage_is_equal_to(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_and_usage_t *other_positioning_method_and_usage);



/** Get the value of the method field of a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to examine.
 *
 * @return the value current set for the method field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_method_t* data_collection_model_positioning_method_and_usage_get_method(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

/** Set the value of the method field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_method The value to copy into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_t* p_method);

/** Move a value to the method field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_method The value to move into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_method_t* p_method);


/** Get the value of the mode field of a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to examine.
 *
 * @return the value current set for the mode field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_mode_t* data_collection_model_positioning_method_and_usage_get_mode(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

/** Set the value of the mode field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_mode The value to copy into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_mode_t* p_mode);

/** Move a value to the mode field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_mode The value to move into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_mode_t* p_mode);


/** Get the value of the usage field of a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to examine.
 *
 * @return the value current set for the usage field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_usage_t* data_collection_model_positioning_method_and_usage_get_usage(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

/** Set the value of the usage field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_usage The value to copy into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_usage_t* p_usage);

/** Move a value to the usage field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_usage The value to move into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_usage_t* p_usage);

/** Check if the methodCode field of a PositioningMethodAndUsage object is set
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to examine.
 *
 * @return `true` if the optional methodCode field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_and_usage_has_method_code(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);


/** Get the value of the methodCode field of a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to examine.
 *
 * @return the value current set for the methodCode field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_positioning_method_and_usage_get_method_code(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

/** Set the value of the methodCode field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_method_code The value to copy into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const int32_t p_method_code);

/** Move a value to the methodCode field in a PositioningMethodAndUsage object
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to set the field in.
 * @param p_method_code The value to move into the PositioningMethodAndUsage object.
 *
 * @return @a positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, int32_t p_method_code);

/** lnode helper for generating ogs_list_t nodes's of type PositioningMethodAndUsage
 * \public \memberof data_collection_model_positioning_method_and_usage_t
 *
 * Creates a new data_collection_lnode_t object containing the @a positioning_method_and_usage object.
 * The @a positioning_method_and_usage will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param positioning_method_and_usage The PositioningMethodAndUsage object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a positioning_method_and_usage
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_method_and_usage_make_lnode(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POSITIONING_METHOD_AND_USAGE_H_ */

