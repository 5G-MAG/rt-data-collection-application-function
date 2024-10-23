#ifndef _DATA_COLLECTION_GNB_ID_H_
#define _DATA_COLLECTION_GNB_ID_H_

/**********************************************************************************************************************************
 * GNbId - Public C interface to the GNbId object
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

/** A 3GPP GNbId object reference
 */
typedef struct data_collection_model_gnb_id_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_gnb_id_t;



/** Create a new GNbId
 * \public \memberof data_collection_model_gnb_id_t
 * @return a new GNbId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create();

/** Create a new copy of a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 * Creates a new copy of the given @a other object
 * @param other The GNbId to copy.
 * @return a new GNbId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_copy(const data_collection_model_gnb_id_t *other);

/** Create a new reference of a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GNbId to create a new reference to.
 * @return a new GNbId object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_move(data_collection_model_gnb_id_t *other);

/** Copy the value of another GNbId into this object
 * \public \memberof data_collection_model_gnb_id_t
 * Copies the value of @a other {{classname} object into @a gnb_id.
 * @param gnb_id The GNbId object to copy @a other into.
 * @param other The GNbId to copy the value from.
 * @return @a gnb_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_copy(data_collection_model_gnb_id_t *gnb_id, const data_collection_model_gnb_id_t *other);

/** Move the value of another GNbId into this object
 * \public \memberof data_collection_model_gnb_id_t
 * Discards the current value of @a gnb_id and moves the value of @a other
 * into @a gnb_id. This will leave @a other as an empty reference.
 *
 * @param gnb_id The GNbId object to move @a other into.
 * @param other The GNbId to move the value from.
 *
 * @return @a gnb_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_move(data_collection_model_gnb_id_t *gnb_id, data_collection_model_gnb_id_t *other);

/** Delete a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 * Destroys the reference to the GNbId object and frees the value of GNbId if this is the last reference.
 *
 * @param gnb_id The GNbId to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnb_id_free(data_collection_model_gnb_id_t *gnb_id);

/** Get a cJSON tree representation of a GNbId
 * \public \memberof data_collection_model_gnb_id_t
 *
 * Create a cJSON tree representation of the GNbId object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param gnb_id The GNbId to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnb_id_toJSON(const data_collection_model_gnb_id_t *gnb_id, bool as_request);

/** Parse a cJSON tree into a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 *
 * Attempts to interpret a cJSON tree as a GNbId API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GNbId object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GNbId object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GNbId objects to see if they are equivalent
 * \public \memberof data_collection_model_gnb_id_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param gnb_id The first GNbId object to compare.
 * @param other_gnb_id The second GNbId object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnb_id_is_equal_to(const data_collection_model_gnb_id_t *gnb_id, const data_collection_model_gnb_id_t *other_gnb_id);



/** Get the value of the bitLength field of a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 *
 * @param gnb_id The GNbId object to examine.
 *
 * @return the value current set for the bitLength field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_gnb_id_get_bit_length(const data_collection_model_gnb_id_t *gnb_id);

/** Set the value of the bitLength field in a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 *
 * @param gnb_id The GNbId object to set the field in.
 * @param p_bit_length The value to copy into the GNbId object.
 *
 * @return @a gnb_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length(data_collection_model_gnb_id_t *gnb_id, const int32_t p_bit_length);

/** Move a value to the bitLength field in a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 *
 * @param gnb_id The GNbId object to set the field in.
 * @param p_bit_length The value to move into the GNbId object.
 *
 * @return @a gnb_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length_move(data_collection_model_gnb_id_t *gnb_id, int32_t p_bit_length);


/** Get the value of the gNBValue field of a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 *
 * @param gnb_id The GNbId object to examine.
 *
 * @return the value current set for the gNBValue field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_gnb_id_get_gnb_value(const data_collection_model_gnb_id_t *gnb_id);

/** Set the value of the gNBValue field in a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 *
 * @param gnb_id The GNbId object to set the field in.
 * @param p_gnb_value The value to copy into the GNbId object.
 *
 * @return @a gnb_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value(data_collection_model_gnb_id_t *gnb_id, const char* p_gnb_value);

/** Move a value to the gNBValue field in a GNbId object
 * \public \memberof data_collection_model_gnb_id_t
 *
 * @param gnb_id The GNbId object to set the field in.
 * @param p_gnb_value The value to move into the GNbId object.
 *
 * @return @a gnb_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value_move(data_collection_model_gnb_id_t *gnb_id, char* p_gnb_value);

/** lnode helper for generating ogs_list_t nodes's of type GNbId
 * \public \memberof data_collection_model_gnb_id_t
 *
 * Creates a new data_collection_lnode_t object containing the @a gnb_id object.
 * The @a gnb_id will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param gnb_id The GNbId object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a gnb_id
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnb_id_make_lnode(data_collection_model_gnb_id_t *gnb_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNB_ID_H_ */

