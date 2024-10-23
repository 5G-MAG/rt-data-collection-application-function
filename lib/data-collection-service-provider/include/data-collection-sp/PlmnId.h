#ifndef _DATA_COLLECTION_PLMN_ID_H_
#define _DATA_COLLECTION_PLMN_ID_H_

/**********************************************************************************************************************************
 * PlmnId - Public C interface to the PlmnId object
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

/** A 3GPP PlmnId object reference
 */
typedef struct data_collection_model_plmn_id_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_plmn_id_t;



/** Create a new PlmnId
 * \public \memberof data_collection_model_plmn_id_t
 * @return a new PlmnId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create();

/** Create a new copy of a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 * Creates a new copy of the given @a other object
 * @param other The PlmnId to copy.
 * @return a new PlmnId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_copy(const data_collection_model_plmn_id_t *other);

/** Create a new reference of a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PlmnId to create a new reference to.
 * @return a new PlmnId object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_move(data_collection_model_plmn_id_t *other);

/** Copy the value of another PlmnId into this object
 * \public \memberof data_collection_model_plmn_id_t
 * Copies the value of @a other {{classname} object into @a plmn_id.
 * @param plmn_id The PlmnId object to copy @a other into.
 * @param other The PlmnId to copy the value from.
 * @return @a plmn_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_copy(data_collection_model_plmn_id_t *plmn_id, const data_collection_model_plmn_id_t *other);

/** Move the value of another PlmnId into this object
 * \public \memberof data_collection_model_plmn_id_t
 * Discards the current value of @a plmn_id and moves the value of @a other
 * into @a plmn_id. This will leave @a other as an empty reference.
 *
 * @param plmn_id The PlmnId object to move @a other into.
 * @param other The PlmnId to move the value from.
 *
 * @return @a plmn_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_move(data_collection_model_plmn_id_t *plmn_id, data_collection_model_plmn_id_t *other);

/** Delete a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 * Destroys the reference to the PlmnId object and frees the value of PlmnId if this is the last reference.
 *
 * @param plmn_id The PlmnId to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_plmn_id_free(data_collection_model_plmn_id_t *plmn_id);

/** Get a cJSON tree representation of a PlmnId
 * \public \memberof data_collection_model_plmn_id_t
 *
 * Create a cJSON tree representation of the PlmnId object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param plmn_id The PlmnId to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_plmn_id_toJSON(const data_collection_model_plmn_id_t *plmn_id, bool as_request);

/** Parse a cJSON tree into a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 *
 * Attempts to interpret a cJSON tree as a PlmnId API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PlmnId object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PlmnId object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PlmnId objects to see if they are equivalent
 * \public \memberof data_collection_model_plmn_id_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param plmn_id The first PlmnId object to compare.
 * @param other_plmn_id The second PlmnId object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_plmn_id_is_equal_to(const data_collection_model_plmn_id_t *plmn_id, const data_collection_model_plmn_id_t *other_plmn_id);



/** Get the value of the mcc field of a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 *
 * @param plmn_id The PlmnId object to examine.
 *
 * @return the value current set for the mcc field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_get_mcc(const data_collection_model_plmn_id_t *plmn_id);

/** Set the value of the mcc field in a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 *
 * @param plmn_id The PlmnId object to set the field in.
 * @param p_mcc The value to copy into the PlmnId object.
 *
 * @return @a plmn_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc(data_collection_model_plmn_id_t *plmn_id, const char* p_mcc);

/** Move a value to the mcc field in a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 *
 * @param plmn_id The PlmnId object to set the field in.
 * @param p_mcc The value to move into the PlmnId object.
 *
 * @return @a plmn_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc_move(data_collection_model_plmn_id_t *plmn_id, char* p_mcc);


/** Get the value of the mnc field of a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 *
 * @param plmn_id The PlmnId object to examine.
 *
 * @return the value current set for the mnc field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_get_mnc(const data_collection_model_plmn_id_t *plmn_id);

/** Set the value of the mnc field in a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 *
 * @param plmn_id The PlmnId object to set the field in.
 * @param p_mnc The value to copy into the PlmnId object.
 *
 * @return @a plmn_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc(data_collection_model_plmn_id_t *plmn_id, const char* p_mnc);

/** Move a value to the mnc field in a PlmnId object
 * \public \memberof data_collection_model_plmn_id_t
 *
 * @param plmn_id The PlmnId object to set the field in.
 * @param p_mnc The value to move into the PlmnId object.
 *
 * @return @a plmn_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc_move(data_collection_model_plmn_id_t *plmn_id, char* p_mnc);

/** lnode helper for generating ogs_list_t nodes's of type PlmnId
 * \public \memberof data_collection_model_plmn_id_t
 *
 * Creates a new data_collection_lnode_t object containing the @a plmn_id object.
 * The @a plmn_id will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param plmn_id The PlmnId object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a plmn_id
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_plmn_id_make_lnode(data_collection_model_plmn_id_t *plmn_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PLMN_ID_H_ */

