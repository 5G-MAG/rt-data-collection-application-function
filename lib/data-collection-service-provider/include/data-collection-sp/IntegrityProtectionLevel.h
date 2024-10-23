#ifndef _DATA_COLLECTION_INTEGRITY_PROTECTION_LEVEL_H_
#define _DATA_COLLECTION_INTEGRITY_PROTECTION_LEVEL_H_

/**********************************************************************************************************************************
 * IntegrityProtectionLevel - Public C interface to the IntegrityProtectionLevel object
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

/** A 3GPP IntegrityProtectionLevel object reference
 */
typedef struct data_collection_model_integrity_protection_level_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_integrity_protection_level_t;



/** Create a new IntegrityProtectionLevel
 * \public \memberof data_collection_model_integrity_protection_level_t
 * @return a new IntegrityProtectionLevel object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create();

/** Create a new copy of a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 * Creates a new copy of the given @a other object
 * @param other The IntegrityProtectionLevel to copy.
 * @return a new IntegrityProtectionLevel object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create_copy(const data_collection_model_integrity_protection_level_t *other);

/** Create a new reference of a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 * Creates a reference to the same underlying @a other object.
 * @param other The IntegrityProtectionLevel to create a new reference to.
 * @return a new IntegrityProtectionLevel object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create_move(data_collection_model_integrity_protection_level_t *other);

/** Copy the value of another IntegrityProtectionLevel into this object
 * \public \memberof data_collection_model_integrity_protection_level_t
 * Copies the value of @a other {{classname} object into @a integrity_protection_level.
 * @param integrity_protection_level The IntegrityProtectionLevel object to copy @a other into.
 * @param other The IntegrityProtectionLevel to copy the value from.
 * @return @a integrity_protection_level.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_copy(data_collection_model_integrity_protection_level_t *integrity_protection_level, const data_collection_model_integrity_protection_level_t *other);

/** Move the value of another IntegrityProtectionLevel into this object
 * \public \memberof data_collection_model_integrity_protection_level_t
 * Discards the current value of @a integrity_protection_level and moves the value of @a other
 * into @a integrity_protection_level. This will leave @a other as an empty reference.
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to move @a other into.
 * @param other The IntegrityProtectionLevel to move the value from.
 *
 * @return @a integrity_protection_level.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_move(data_collection_model_integrity_protection_level_t *integrity_protection_level, data_collection_model_integrity_protection_level_t *other);

/** Delete a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 * Destroys the reference to the IntegrityProtectionLevel object and frees the value of IntegrityProtectionLevel if this is the last reference.
 *
 * @param integrity_protection_level The IntegrityProtectionLevel to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_protection_level_free(data_collection_model_integrity_protection_level_t *integrity_protection_level);

/** Get a cJSON tree representation of a IntegrityProtectionLevel
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * Create a cJSON tree representation of the IntegrityProtectionLevel object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param integrity_protection_level The IntegrityProtectionLevel to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_protection_level_toJSON(const data_collection_model_integrity_protection_level_t *integrity_protection_level, bool as_request);

/** Parse a cJSON tree into a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * Attempts to interpret a cJSON tree as a IntegrityProtectionLevel API request or response (dependent on @a as_request value). If successful
 * will return a new referenced IntegrityProtectionLevel object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new IntegrityProtectionLevel object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two IntegrityProtectionLevel objects to see if they are equivalent
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param integrity_protection_level The first IntegrityProtectionLevel object to compare.
 * @param other_integrity_protection_level The second IntegrityProtectionLevel object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_protection_level_is_equal_to(const data_collection_model_integrity_protection_level_t *integrity_protection_level, const data_collection_model_integrity_protection_level_t *other_integrity_protection_level);



/** Get the value of the horizontalProtectionLevel field of a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to examine.
 *
 * @return the value current set for the horizontalProtectionLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_protection_level_get_horizontal_protection_level(const data_collection_model_integrity_protection_level_t *integrity_protection_level);

/** Set the value of the horizontalProtectionLevel field in a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to set the field in.
 * @param p_horizontal_protection_level The value to copy into the IntegrityProtectionLevel object.
 *
 * @return @a integrity_protection_level.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_horizontal_protection_level(data_collection_model_integrity_protection_level_t *integrity_protection_level, const int32_t p_horizontal_protection_level);

/** Move a value to the horizontalProtectionLevel field in a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to set the field in.
 * @param p_horizontal_protection_level The value to move into the IntegrityProtectionLevel object.
 *
 * @return @a integrity_protection_level.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_horizontal_protection_level_move(data_collection_model_integrity_protection_level_t *integrity_protection_level, int32_t p_horizontal_protection_level);

/** Check if the verticalProtectionLevel field of a IntegrityProtectionLevel object is set
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to examine.
 *
 * @return `true` if the optional verticalProtectionLevel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_protection_level_has_vertical_protection_level(const data_collection_model_integrity_protection_level_t *integrity_protection_level);


/** Get the value of the verticalProtectionLevel field of a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to examine.
 *
 * @return the value current set for the verticalProtectionLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_protection_level_get_vertical_protection_level(const data_collection_model_integrity_protection_level_t *integrity_protection_level);

/** Set the value of the verticalProtectionLevel field in a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to set the field in.
 * @param p_vertical_protection_level The value to copy into the IntegrityProtectionLevel object.
 *
 * @return @a integrity_protection_level.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_vertical_protection_level(data_collection_model_integrity_protection_level_t *integrity_protection_level, const int32_t p_vertical_protection_level);

/** Move a value to the verticalProtectionLevel field in a IntegrityProtectionLevel object
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to set the field in.
 * @param p_vertical_protection_level The value to move into the IntegrityProtectionLevel object.
 *
 * @return @a integrity_protection_level.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_vertical_protection_level_move(data_collection_model_integrity_protection_level_t *integrity_protection_level, int32_t p_vertical_protection_level);

/** lnode helper for generating ogs_list_t nodes's of type IntegrityProtectionLevel
 * \public \memberof data_collection_model_integrity_protection_level_t
 *
 * Creates a new data_collection_lnode_t object containing the @a integrity_protection_level object.
 * The @a integrity_protection_level will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param integrity_protection_level The IntegrityProtectionLevel object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a integrity_protection_level
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_protection_level_make_lnode(data_collection_model_integrity_protection_level_t *integrity_protection_level);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INTEGRITY_PROTECTION_LEVEL_H_ */

