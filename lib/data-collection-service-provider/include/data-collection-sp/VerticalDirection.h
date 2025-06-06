#ifndef _DATA_COLLECTION_VERTICAL_DIRECTION_H_
#define _DATA_COLLECTION_VERTICAL_DIRECTION_H_

/**********************************************************************************************************************************
 * VerticalDirection - Public C interface to the VerticalDirection object
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

/** A 3GPP VerticalDirection object reference
 */
typedef struct data_collection_model_vertical_direction_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_vertical_direction_t;


/** VerticalDirection enumerated values */
typedef enum {
    DCM_VERTICAL_DIRECTION_NO_VAL, /**< No value */
    DCM_VERTICAL_DIRECTION_VAL_UPWARD, /**< UPWARD */
    DCM_VERTICAL_DIRECTION_VAL_DOWNWARD /**< DOWNWARD */
} data_collection_model_vertical_direction_e;


/** Create a new VerticalDirection.
 * \public \memberof data_collection_model_vertical_direction_t
 * @return a new VerticalDirection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_create();

/** Create a new VerticalDirection reference.
 * \public \memberof data_collection_model_vertical_direction_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The VerticalDirection to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_create_ref(const data_collection_model_vertical_direction_t *other);

/** Create a new copy of a VerticalDirection object.
 * \public \memberof data_collection_model_vertical_direction_t
 * Creates a new copy of the given @a other object
 * @param other The VerticalDirection to copy.
 * @return a new VerticalDirection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_create_copy(const data_collection_model_vertical_direction_t *other);

/** Create a new reference of a VerticalDirection object
 * \public \memberof data_collection_model_vertical_direction_t
 * Creates a reference to the same underlying @a other object.
 * @param other The VerticalDirection to create a new reference to.
 * @return a new VerticalDirection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_create_move(data_collection_model_vertical_direction_t *other);

/** Copy the value of another VerticalDirection into this object
 * \public \memberof data_collection_model_vertical_direction_t
 * Copies the value of @a other {{classname} object into @a vertical_direction.
 * @param vertical_direction The VerticalDirection object to copy @a other into.
 * @param other The VerticalDirection to copy the value from.
 * @return @a vertical_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_copy(data_collection_model_vertical_direction_t *vertical_direction, const data_collection_model_vertical_direction_t *other);

/** Move the value of another VerticalDirection into this object
 * \public \memberof data_collection_model_vertical_direction_t
 * Discards the current value of @a vertical_direction and moves the value of @a other
 * into @a vertical_direction. This will leave @a other as an empty reference.
 *
 * @param vertical_direction The VerticalDirection object to move @a other into.
 * @param other The VerticalDirection to move the value from.
 *
 * @return @a vertical_direction.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_move(data_collection_model_vertical_direction_t *vertical_direction, data_collection_model_vertical_direction_t *other);

/** Delete a VerticalDirection object
 * \public \memberof data_collection_model_vertical_direction_t
 * Destroys the reference to the VerticalDirection object and frees the value of VerticalDirection if this is the last reference.
 *
 * @param vertical_direction The VerticalDirection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_vertical_direction_free(data_collection_model_vertical_direction_t *vertical_direction);

/** Get a cJSON tree representation of a VerticalDirection
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * Create a cJSON tree representation of the VerticalDirection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param vertical_direction The VerticalDirection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_vertical_direction_toJSON(const data_collection_model_vertical_direction_t *vertical_direction, bool as_request);

/** Parse a cJSON tree into a VerticalDirection object
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * Attempts to interpret a cJSON tree as a VerticalDirection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced VerticalDirection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new VerticalDirection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two VerticalDirection objects to see if they are equivalent
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param vertical_direction The first VerticalDirection object to compare.
 * @param other_vertical_direction The second VerticalDirection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_vertical_direction_is_equal_to(const data_collection_model_vertical_direction_t *vertical_direction, const data_collection_model_vertical_direction_t *other_vertical_direction);


/** Check if the VerticalDirection enumeration object has a value set
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * @param vertical_direction The VerticalDirection enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_vertical_direction_is_not_set(const data_collection_model_vertical_direction_t *vertical_direction);

/** Get the enumeration value for a VerticalDirection object
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * @param vertical_direction The VerticalDirection object to extract the enumeration value from.
 *
 * @return the data_collection_model_vertical_direction_e value represented by the VerticalDirection object.
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_e data_collection_model_vertical_direction_get_enum(const data_collection_model_vertical_direction_t *vertical_direction);

/** Get the string representation of the enumeration value for a VerticalDirection object
 * \public \memberof data_collection_model_vertical_direction_t 
 *
 * @param vertical_direction The VerticalDirection object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_vertical_direction_get_string(const data_collection_model_vertical_direction_t *vertical_direction);

/** Set the enumeration value for a VerticalDirection object
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * @param vertical_direction The VerticalDirection object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_vertical_direction_set_enum(data_collection_model_vertical_direction_t *vertical_direction, data_collection_model_vertical_direction_e value);

/** Set the enumeration value as a string for a VerticalDirection object
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * @param vertical_direction The VerticalDirection object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was recognised and set or `false` if the string did not represent a known enumeration value.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_vertical_direction_set_string(data_collection_model_vertical_direction_t *vertical_direction, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type VerticalDirection
 * \public \memberof data_collection_model_vertical_direction_t
 *
 * Creates a new data_collection_lnode_t object containing the @a vertical_direction object.
 * The @a vertical_direction will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param vertical_direction The VerticalDirection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a vertical_direction
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_vertical_direction_make_lnode(data_collection_model_vertical_direction_t *vertical_direction);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_VERTICAL_DIRECTION_H_ */

