#ifndef _DATA_COLLECTION_PLMN_ID_NID_H_
#define _DATA_COLLECTION_PLMN_ID_NID_H_

/**********************************************************************************************************************************
 * PlmnIdNid - Public C interface to the PlmnIdNid object
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

/** A 3GPP PlmnIdNid object reference
 */
typedef struct data_collection_model_plmn_id_nid_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_plmn_id_nid_t;



/** Create a new PlmnIdNid
 * \public \memberof data_collection_model_plmn_id_nid_t
 * @return a new PlmnIdNid object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create();

/** Create a new copy of a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 * Creates a new copy of the given @a other object
 * @param other The PlmnIdNid to copy.
 * @return a new PlmnIdNid object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create_copy(const data_collection_model_plmn_id_nid_t *other);

/** Create a new reference of a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PlmnIdNid to create a new reference to.
 * @return a new PlmnIdNid object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create_move(data_collection_model_plmn_id_nid_t *other);

/** Copy the value of another PlmnIdNid into this object
 * \public \memberof data_collection_model_plmn_id_nid_t
 * Copies the value of @a other {{classname} object into @a plmn_id_nid.
 * @param plmn_id_nid The PlmnIdNid object to copy @a other into.
 * @param other The PlmnIdNid to copy the value from.
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_copy(data_collection_model_plmn_id_nid_t *plmn_id_nid, const data_collection_model_plmn_id_nid_t *other);

/** Move the value of another PlmnIdNid into this object
 * \public \memberof data_collection_model_plmn_id_nid_t
 * Discards the current value of @a plmn_id_nid and moves the value of @a other
 * into @a plmn_id_nid. This will leave @a other as an empty reference.
 *
 * @param plmn_id_nid The PlmnIdNid object to move @a other into.
 * @param other The PlmnIdNid to move the value from.
 *
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, data_collection_model_plmn_id_nid_t *other);

/** Delete a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 * Destroys the reference to the PlmnIdNid object and frees the value of PlmnIdNid if this is the last reference.
 *
 * @param plmn_id_nid The PlmnIdNid to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_plmn_id_nid_free(data_collection_model_plmn_id_nid_t *plmn_id_nid);

/** Get a cJSON tree representation of a PlmnIdNid
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * Create a cJSON tree representation of the PlmnIdNid object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param plmn_id_nid The PlmnIdNid to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_plmn_id_nid_toJSON(const data_collection_model_plmn_id_nid_t *plmn_id_nid, bool as_request);

/** Parse a cJSON tree into a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * Attempts to interpret a cJSON tree as a PlmnIdNid API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PlmnIdNid object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PlmnIdNid object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PlmnIdNid objects to see if they are equivalent
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param plmn_id_nid The first PlmnIdNid object to compare.
 * @param other_plmn_id_nid The second PlmnIdNid object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_plmn_id_nid_is_equal_to(const data_collection_model_plmn_id_nid_t *plmn_id_nid, const data_collection_model_plmn_id_nid_t *other_plmn_id_nid);



/** Get the value of the mcc field of a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to examine.
 *
 * @return the value current set for the mcc field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_nid_get_mcc(const data_collection_model_plmn_id_nid_t *plmn_id_nid);

/** Set the value of the mcc field in a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to set the field in.
 * @param p_mcc The value to copy into the PlmnIdNid object.
 *
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mcc(data_collection_model_plmn_id_nid_t *plmn_id_nid, const char* p_mcc);

/** Move a value to the mcc field in a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to set the field in.
 * @param p_mcc The value to move into the PlmnIdNid object.
 *
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mcc_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, char* p_mcc);


/** Get the value of the mnc field of a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to examine.
 *
 * @return the value current set for the mnc field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_nid_get_mnc(const data_collection_model_plmn_id_nid_t *plmn_id_nid);

/** Set the value of the mnc field in a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to set the field in.
 * @param p_mnc The value to copy into the PlmnIdNid object.
 *
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mnc(data_collection_model_plmn_id_nid_t *plmn_id_nid, const char* p_mnc);

/** Move a value to the mnc field in a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to set the field in.
 * @param p_mnc The value to move into the PlmnIdNid object.
 *
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mnc_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, char* p_mnc);

/** Check if the nid field of a PlmnIdNid object is set
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to examine.
 *
 * @return `true` if the optional nid field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_plmn_id_nid_has_nid(const data_collection_model_plmn_id_nid_t *plmn_id_nid);


/** Get the value of the nid field of a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to examine.
 *
 * @return the value current set for the nid field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_nid_get_nid(const data_collection_model_plmn_id_nid_t *plmn_id_nid);

/** Set the value of the nid field in a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to set the field in.
 * @param p_nid The value to copy into the PlmnIdNid object.
 *
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_nid(data_collection_model_plmn_id_nid_t *plmn_id_nid, const char* p_nid);

/** Move a value to the nid field in a PlmnIdNid object
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * @param plmn_id_nid The PlmnIdNid object to set the field in.
 * @param p_nid The value to move into the PlmnIdNid object.
 *
 * @return @a plmn_id_nid.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_nid_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, char* p_nid);

/** lnode helper for generating ogs_list_t nodes's of type PlmnIdNid
 * \public \memberof data_collection_model_plmn_id_nid_t
 *
 * Creates a new data_collection_lnode_t object containing the @a plmn_id_nid object.
 * The @a plmn_id_nid will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param plmn_id_nid The PlmnIdNid object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a plmn_id_nid
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_plmn_id_nid_make_lnode(data_collection_model_plmn_id_nid_t *plmn_id_nid);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PLMN_ID_NID_H_ */

