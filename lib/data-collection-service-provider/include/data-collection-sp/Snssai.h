#ifndef _DATA_COLLECTION_SNSSAI_H_
#define _DATA_COLLECTION_SNSSAI_H_

/**********************************************************************************************************************************
 * Snssai - Public C interface to the Snssai object
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

/** A 3GPP Snssai object reference
 */
typedef struct data_collection_model_snssai_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_snssai_t;



/** Create a new Snssai.
 * \public \memberof data_collection_model_snssai_t
 * @return a new Snssai object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_create();

/** Create a new Snssai reference.
 * \public \memberof data_collection_model_snssai_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The Snssai to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_create_ref(const data_collection_model_snssai_t *other);

/** Create a new copy of a Snssai object.
 * \public \memberof data_collection_model_snssai_t
 * Creates a new copy of the given @a other object
 * @param other The Snssai to copy.
 * @return a new Snssai object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_create_copy(const data_collection_model_snssai_t *other);

/** Create a new reference of a Snssai object
 * \public \memberof data_collection_model_snssai_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Snssai to create a new reference to.
 * @return a new Snssai object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_create_move(data_collection_model_snssai_t *other);

/** Copy the value of another Snssai into this object
 * \public \memberof data_collection_model_snssai_t
 * Copies the value of @a other {{classname} object into @a snssai.
 * @param snssai The Snssai object to copy @a other into.
 * @param other The Snssai to copy the value from.
 * @return @a snssai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_copy(data_collection_model_snssai_t *snssai, const data_collection_model_snssai_t *other);

/** Move the value of another Snssai into this object
 * \public \memberof data_collection_model_snssai_t
 * Discards the current value of @a snssai and moves the value of @a other
 * into @a snssai. This will leave @a other as an empty reference.
 *
 * @param snssai The Snssai object to move @a other into.
 * @param other The Snssai to move the value from.
 *
 * @return @a snssai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_move(data_collection_model_snssai_t *snssai, data_collection_model_snssai_t *other);

/** Delete a Snssai object
 * \public \memberof data_collection_model_snssai_t
 * Destroys the reference to the Snssai object and frees the value of Snssai if this is the last reference.
 *
 * @param snssai The Snssai to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_snssai_free(data_collection_model_snssai_t *snssai);

/** Get a cJSON tree representation of a Snssai
 * \public \memberof data_collection_model_snssai_t
 *
 * Create a cJSON tree representation of the Snssai object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param snssai The Snssai to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_snssai_toJSON(const data_collection_model_snssai_t *snssai, bool as_request);

/** Parse a cJSON tree into a Snssai object
 * \public \memberof data_collection_model_snssai_t
 *
 * Attempts to interpret a cJSON tree as a Snssai API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Snssai object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Snssai object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Snssai objects to see if they are equivalent
 * \public \memberof data_collection_model_snssai_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param snssai The first Snssai object to compare.
 * @param other_snssai The second Snssai object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_snssai_is_equal_to(const data_collection_model_snssai_t *snssai, const data_collection_model_snssai_t *other_snssai);



/** Get the value of the sst field of a Snssai object
 * \public \memberof data_collection_model_snssai_t
 *
 * @param snssai The Snssai object to examine.
 *
 * @return the value current set for the sst field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_snssai_get_sst(const data_collection_model_snssai_t *snssai);

/** Set the value of the sst field in a Snssai object
 * \public \memberof data_collection_model_snssai_t
 *
 * @param snssai The Snssai object to set the field in.
 * @param p_sst The value to copy into the Snssai object.
 *
 * @return @a snssai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sst(data_collection_model_snssai_t *snssai, const int32_t p_sst);

/** Move a value to the sst field in a Snssai object
 * \public \memberof data_collection_model_snssai_t
 *
 * @param snssai The Snssai object to set the field in.
 * @param p_sst The value to move into the Snssai object.
 *
 * @return @a snssai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sst_move(data_collection_model_snssai_t *snssai, int32_t p_sst);

/** Check if the sd field of a Snssai object is set
 * \public \memberof data_collection_model_snssai_t
 *
 * @param snssai The Snssai object to examine.
 *
 * @return `true` if the optional sd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_snssai_has_sd(const data_collection_model_snssai_t *snssai);


/** Get the value of the sd field of a Snssai object
 * \public \memberof data_collection_model_snssai_t
 *
 * @param snssai The Snssai object to examine.
 *
 * @return the value current set for the sd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_snssai_get_sd(const data_collection_model_snssai_t *snssai);

/** Set the value of the sd field in a Snssai object
 * \public \memberof data_collection_model_snssai_t
 *
 * @param snssai The Snssai object to set the field in.
 * @param p_sd The value to copy into the Snssai object.
 *
 * @return @a snssai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sd(data_collection_model_snssai_t *snssai, const char* p_sd);

/** Move a value to the sd field in a Snssai object
 * \public \memberof data_collection_model_snssai_t
 *
 * @param snssai The Snssai object to set the field in.
 * @param p_sd The value to move into the Snssai object.
 *
 * @return @a snssai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_snssai_t *data_collection_model_snssai_set_sd_move(data_collection_model_snssai_t *snssai, char* p_sd);

/** lnode helper for generating ogs_list_t nodes's of type Snssai
 * \public \memberof data_collection_model_snssai_t
 *
 * Creates a new data_collection_lnode_t object containing the @a snssai object.
 * The @a snssai will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param snssai The Snssai object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a snssai
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_snssai_make_lnode(data_collection_model_snssai_t *snssai);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SNSSAI_H_ */

