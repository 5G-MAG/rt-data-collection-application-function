#ifndef _DATA_COLLECTION_TAI_H_
#define _DATA_COLLECTION_TAI_H_

/**********************************************************************************************************************************
 * Tai - Public C interface to the Tai object
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

#include "PlmnId.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP Tai object reference
 */
typedef struct data_collection_model_tai_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_tai_t;



/** Create a new Tai.
 * \public \memberof data_collection_model_tai_t
 * @return a new Tai object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_create();

/** Create a new Tai reference.
 * \public \memberof data_collection_model_tai_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The Tai to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_create_ref(const data_collection_model_tai_t *other);

/** Create a new copy of a Tai object.
 * \public \memberof data_collection_model_tai_t
 * Creates a new copy of the given @a other object
 * @param other The Tai to copy.
 * @return a new Tai object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_create_copy(const data_collection_model_tai_t *other);

/** Create a new reference of a Tai object
 * \public \memberof data_collection_model_tai_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Tai to create a new reference to.
 * @return a new Tai object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_create_move(data_collection_model_tai_t *other);

/** Copy the value of another Tai into this object
 * \public \memberof data_collection_model_tai_t
 * Copies the value of @a other {{classname} object into @a tai.
 * @param tai The Tai object to copy @a other into.
 * @param other The Tai to copy the value from.
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_copy(data_collection_model_tai_t *tai, const data_collection_model_tai_t *other);

/** Move the value of another Tai into this object
 * \public \memberof data_collection_model_tai_t
 * Discards the current value of @a tai and moves the value of @a other
 * into @a tai. This will leave @a other as an empty reference.
 *
 * @param tai The Tai object to move @a other into.
 * @param other The Tai to move the value from.
 *
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_move(data_collection_model_tai_t *tai, data_collection_model_tai_t *other);

/** Delete a Tai object
 * \public \memberof data_collection_model_tai_t
 * Destroys the reference to the Tai object and frees the value of Tai if this is the last reference.
 *
 * @param tai The Tai to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_tai_free(data_collection_model_tai_t *tai);

/** Get a cJSON tree representation of a Tai
 * \public \memberof data_collection_model_tai_t
 *
 * Create a cJSON tree representation of the Tai object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param tai The Tai to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_tai_toJSON(const data_collection_model_tai_t *tai, bool as_request);

/** Parse a cJSON tree into a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * Attempts to interpret a cJSON tree as a Tai API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Tai object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Tai object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Tai objects to see if they are equivalent
 * \public \memberof data_collection_model_tai_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param tai The first Tai object to compare.
 * @param other_tai The second Tai object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_tai_is_equal_to(const data_collection_model_tai_t *tai, const data_collection_model_tai_t *other_tai);



/** Get the value of the plmnId field of a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to examine.
 *
 * @return the value current set for the plmnId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_tai_get_plmn_id(const data_collection_model_tai_t *tai);

/** Set the value of the plmnId field in a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to set the field in.
 * @param p_plmn_id The value to copy into the Tai object.
 *
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_plmn_id(data_collection_model_tai_t *tai, const data_collection_model_plmn_id_t* p_plmn_id);

/** Move a value to the plmnId field in a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to set the field in.
 * @param p_plmn_id The value to move into the Tai object.
 *
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_plmn_id_move(data_collection_model_tai_t *tai, data_collection_model_plmn_id_t* p_plmn_id);


/** Get the value of the tac field of a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to examine.
 *
 * @return the value current set for the tac field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_tai_get_tac(const data_collection_model_tai_t *tai);

/** Set the value of the tac field in a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to set the field in.
 * @param p_tac The value to copy into the Tai object.
 *
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_tac(data_collection_model_tai_t *tai, const char* p_tac);

/** Move a value to the tac field in a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to set the field in.
 * @param p_tac The value to move into the Tai object.
 *
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_tac_move(data_collection_model_tai_t *tai, char* p_tac);

/** Check if the nid field of a Tai object is set
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to examine.
 *
 * @return `true` if the optional nid field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_tai_has_nid(const data_collection_model_tai_t *tai);


/** Get the value of the nid field of a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to examine.
 *
 * @return the value current set for the nid field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_tai_get_nid(const data_collection_model_tai_t *tai);

/** Set the value of the nid field in a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to set the field in.
 * @param p_nid The value to copy into the Tai object.
 *
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_nid(data_collection_model_tai_t *tai, const char* p_nid);

/** Move a value to the nid field in a Tai object
 * \public \memberof data_collection_model_tai_t
 *
 * @param tai The Tai object to set the field in.
 * @param p_nid The value to move into the Tai object.
 *
 * @return @a tai.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_tai_t *data_collection_model_tai_set_nid_move(data_collection_model_tai_t *tai, char* p_nid);

/** lnode helper for generating ogs_list_t nodes's of type Tai
 * \public \memberof data_collection_model_tai_t
 *
 * Creates a new data_collection_lnode_t object containing the @a tai object.
 * The @a tai will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param tai The Tai object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a tai
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_tai_make_lnode(data_collection_model_tai_t *tai);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TAI_H_ */

