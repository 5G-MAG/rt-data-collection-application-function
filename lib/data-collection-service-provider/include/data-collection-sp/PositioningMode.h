#ifndef _DATA_COLLECTION_POSITIONING_MODE_H_
#define _DATA_COLLECTION_POSITIONING_MODE_H_

/**********************************************************************************************************************************
 * PositioningMode - Public C interface to the PositioningMode object
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

#include "PositioningMode_anyOf.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PositioningMode object reference
 */
typedef struct data_collection_model_positioning_mode_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_positioning_mode_t;


/** PositioningMode enumerated values */
typedef enum {
    DCM_POSITIONING_MODE_NO_VAL, /**< No value */
    DCM_POSITIONING_MODE_VAL_UE_BASED, /**< UE_BASED */
    DCM_POSITIONING_MODE_VAL_UE_ASSISTED, /**< UE_ASSISTED */
    DCM_POSITIONING_MODE_VAL_CONVENTIONAL, /**< CONVENTIONAL */
    DCM_POSITIONING_MODE_OTHER  /**< Custom value (future expansion) */
} data_collection_model_positioning_mode_e;


/** Create a new PositioningMode
 * \public \memberof data_collection_model_positioning_mode_t
 * @return a new PositioningMode object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create();

/** Create a new copy of a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 * Creates a new copy of the given @a other object
 * @param other The PositioningMode to copy.
 * @return a new PositioningMode object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_copy(const data_collection_model_positioning_mode_t *other);

/** Create a new reference of a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PositioningMode to create a new reference to.
 * @return a new PositioningMode object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_move(data_collection_model_positioning_mode_t *other);

/** Copy the value of another PositioningMode into this object
 * \public \memberof data_collection_model_positioning_mode_t
 * Copies the value of @a other {{classname} object into @a positioning_mode.
 * @param positioning_mode The PositioningMode object to copy @a other into.
 * @param other The PositioningMode to copy the value from.
 * @return @a positioning_mode.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_copy(data_collection_model_positioning_mode_t *positioning_mode, const data_collection_model_positioning_mode_t *other);

/** Move the value of another PositioningMode into this object
 * \public \memberof data_collection_model_positioning_mode_t
 * Discards the current value of @a positioning_mode and moves the value of @a other
 * into @a positioning_mode. This will leave @a other as an empty reference.
 *
 * @param positioning_mode The PositioningMode object to move @a other into.
 * @param other The PositioningMode to move the value from.
 *
 * @return @a positioning_mode.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_move(data_collection_model_positioning_mode_t *positioning_mode, data_collection_model_positioning_mode_t *other);

/** Delete a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 * Destroys the reference to the PositioningMode object and frees the value of PositioningMode if this is the last reference.
 *
 * @param positioning_mode The PositioningMode to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_mode_free(data_collection_model_positioning_mode_t *positioning_mode);

/** Get a cJSON tree representation of a PositioningMode
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * Create a cJSON tree representation of the PositioningMode object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param positioning_mode The PositioningMode to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_mode_toJSON(const data_collection_model_positioning_mode_t *positioning_mode, bool as_request);

/** Parse a cJSON tree into a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * Attempts to interpret a cJSON tree as a PositioningMode API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PositioningMode object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PositioningMode object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PositioningMode objects to see if they are equivalent
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param positioning_mode The first PositioningMode object to compare.
 * @param other_positioning_mode The second PositioningMode object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_equal_to(const data_collection_model_positioning_mode_t *positioning_mode, const data_collection_model_positioning_mode_t *other_positioning_mode);


/** Check if the PositioningMode enumeration object has a value set
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * @param positioning_mode The PositioningMode enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_not_set(const data_collection_model_positioning_mode_t *positioning_mode);

/** Check if the PositioningMode enumeration object has a custom value set
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * @param positioning_mode The PositioningMode enumeration object to check.
 * @return `true` if the enumeration object has an unknown string value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_non_standard(const data_collection_model_positioning_mode_t *positioning_mode);

/** Get the enumeration value for a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * @param positioning_mode The PositioningMode object to extract the enumeration value from.
 *
 * @return the data_collection_model_positioning_mode_e value represented by the PositioningMode object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_e data_collection_model_positioning_mode_get_enum(const data_collection_model_positioning_mode_t *positioning_mode);

/** Get the string representation of the enumeration value for a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * @param positioning_mode The PositioningMode object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_mode_get_string(const data_collection_model_positioning_mode_t *positioning_mode);

/** Set the enumeration value for a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * @param positioning_mode The PositioningMode object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_enum(data_collection_model_positioning_mode_t *positioning_mode, data_collection_model_positioning_mode_e value);

/** Set the enumeration value as a string for a PositioningMode object
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * Sets the enumeration value from the string given. If the string is a non-standard, custom value then the
 * data_collection_model_positioning_mode_get_enum
 * function will return DCM_POSITIONING_MODE_OTHER
 * while this value is set to indicate that this is a custom value.
 *
 * @param positioning_mode The PositioningMode object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` to indicate that the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_string(data_collection_model_positioning_mode_t *positioning_mode, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type PositioningMode
 * \public \memberof data_collection_model_positioning_mode_t
 *
 * Creates a new data_collection_lnode_t object containing the @a positioning_mode object.
 * The @a positioning_mode will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param positioning_mode The PositioningMode object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a positioning_mode
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_mode_make_lnode(data_collection_model_positioning_mode_t *positioning_mode);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POSITIONING_MODE_H_ */

