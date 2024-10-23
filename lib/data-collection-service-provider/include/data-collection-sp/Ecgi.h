#ifndef _DATA_COLLECTION_ECGI_H_
#define _DATA_COLLECTION_ECGI_H_

/**********************************************************************************************************************************
 * Ecgi - Public C interface to the Ecgi object
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

/** A 3GPP Ecgi object reference
 */
typedef struct data_collection_model_ecgi_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ecgi_t;



/** Create a new Ecgi
 * \public \memberof data_collection_model_ecgi_t
 * @return a new Ecgi object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_create();

/** Create a new copy of a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 * Creates a new copy of the given @a other object
 * @param other The Ecgi to copy.
 * @return a new Ecgi object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_create_copy(const data_collection_model_ecgi_t *other);

/** Create a new reference of a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Ecgi to create a new reference to.
 * @return a new Ecgi object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_create_move(data_collection_model_ecgi_t *other);

/** Copy the value of another Ecgi into this object
 * \public \memberof data_collection_model_ecgi_t
 * Copies the value of @a other {{classname} object into @a ecgi.
 * @param ecgi The Ecgi object to copy @a other into.
 * @param other The Ecgi to copy the value from.
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_copy(data_collection_model_ecgi_t *ecgi, const data_collection_model_ecgi_t *other);

/** Move the value of another Ecgi into this object
 * \public \memberof data_collection_model_ecgi_t
 * Discards the current value of @a ecgi and moves the value of @a other
 * into @a ecgi. This will leave @a other as an empty reference.
 *
 * @param ecgi The Ecgi object to move @a other into.
 * @param other The Ecgi to move the value from.
 *
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_move(data_collection_model_ecgi_t *ecgi, data_collection_model_ecgi_t *other);

/** Delete a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 * Destroys the reference to the Ecgi object and frees the value of Ecgi if this is the last reference.
 *
 * @param ecgi The Ecgi to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ecgi_free(data_collection_model_ecgi_t *ecgi);

/** Get a cJSON tree representation of a Ecgi
 * \public \memberof data_collection_model_ecgi_t
 *
 * Create a cJSON tree representation of the Ecgi object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ecgi The Ecgi to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ecgi_toJSON(const data_collection_model_ecgi_t *ecgi, bool as_request);

/** Parse a cJSON tree into a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * Attempts to interpret a cJSON tree as a Ecgi API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Ecgi object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Ecgi object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Ecgi objects to see if they are equivalent
 * \public \memberof data_collection_model_ecgi_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ecgi The first Ecgi object to compare.
 * @param other_ecgi The second Ecgi object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ecgi_is_equal_to(const data_collection_model_ecgi_t *ecgi, const data_collection_model_ecgi_t *other_ecgi);



/** Get the value of the plmnId field of a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to examine.
 *
 * @return the value current set for the plmnId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_ecgi_get_plmn_id(const data_collection_model_ecgi_t *ecgi);

/** Set the value of the plmnId field in a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to set the field in.
 * @param p_plmn_id The value to copy into the Ecgi object.
 *
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_plmn_id(data_collection_model_ecgi_t *ecgi, const data_collection_model_plmn_id_t* p_plmn_id);

/** Move a value to the plmnId field in a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to set the field in.
 * @param p_plmn_id The value to move into the Ecgi object.
 *
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_plmn_id_move(data_collection_model_ecgi_t *ecgi, data_collection_model_plmn_id_t* p_plmn_id);


/** Get the value of the eutraCellId field of a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to examine.
 *
 * @return the value current set for the eutraCellId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ecgi_get_eutra_cell_id(const data_collection_model_ecgi_t *ecgi);

/** Set the value of the eutraCellId field in a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to set the field in.
 * @param p_eutra_cell_id The value to copy into the Ecgi object.
 *
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_eutra_cell_id(data_collection_model_ecgi_t *ecgi, const char* p_eutra_cell_id);

/** Move a value to the eutraCellId field in a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to set the field in.
 * @param p_eutra_cell_id The value to move into the Ecgi object.
 *
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_eutra_cell_id_move(data_collection_model_ecgi_t *ecgi, char* p_eutra_cell_id);

/** Check if the nid field of a Ecgi object is set
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to examine.
 *
 * @return `true` if the optional nid field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ecgi_has_nid(const data_collection_model_ecgi_t *ecgi);


/** Get the value of the nid field of a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to examine.
 *
 * @return the value current set for the nid field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ecgi_get_nid(const data_collection_model_ecgi_t *ecgi);

/** Set the value of the nid field in a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to set the field in.
 * @param p_nid The value to copy into the Ecgi object.
 *
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_nid(data_collection_model_ecgi_t *ecgi, const char* p_nid);

/** Move a value to the nid field in a Ecgi object
 * \public \memberof data_collection_model_ecgi_t
 *
 * @param ecgi The Ecgi object to set the field in.
 * @param p_nid The value to move into the Ecgi object.
 *
 * @return @a ecgi.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_nid_move(data_collection_model_ecgi_t *ecgi, char* p_nid);

/** lnode helper for generating ogs_list_t nodes's of type Ecgi
 * \public \memberof data_collection_model_ecgi_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ecgi object.
 * The @a ecgi will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ecgi The Ecgi object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ecgi
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ecgi_make_lnode(data_collection_model_ecgi_t *ecgi);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ECGI_H_ */

