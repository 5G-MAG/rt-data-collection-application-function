#ifndef _DATA_COLLECTION_ACCESS_TOKEN_REQ_H_
#define _DATA_COLLECTION_ACCESS_TOKEN_REQ_H_

/**********************************************************************************************************************************
 * AccessTokenReq - Public C interface to the AccessTokenReq object
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

#include "NFType.h"
#include "PlmnIdNid.h"
#include "NwdafEvent.h"
#include "PlmnId.h"
#include "MlModelInterInd.h"
#include "Snssai.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP AccessTokenReq object reference
 */
typedef struct data_collection_model_access_token_req_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_access_token_req_t;



/** Create a new AccessTokenReq
 * \public \memberof data_collection_model_access_token_req_t
 * @return a new AccessTokenReq object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_create();

/** Create a new copy of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 * Creates a new copy of the given @a other object
 * @param other The AccessTokenReq to copy.
 * @return a new AccessTokenReq object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_create_copy(const data_collection_model_access_token_req_t *other);

/** Create a new reference of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AccessTokenReq to create a new reference to.
 * @return a new AccessTokenReq object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_create_move(data_collection_model_access_token_req_t *other);

/** Copy the value of another AccessTokenReq into this object
 * \public \memberof data_collection_model_access_token_req_t
 * Copies the value of @a other {{classname} object into @a access_token_req.
 * @param access_token_req The AccessTokenReq object to copy @a other into.
 * @param other The AccessTokenReq to copy the value from.
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_copy(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_access_token_req_t *other);

/** Move the value of another AccessTokenReq into this object
 * \public \memberof data_collection_model_access_token_req_t
 * Discards the current value of @a access_token_req and moves the value of @a other
 * into @a access_token_req. This will leave @a other as an empty reference.
 *
 * @param access_token_req The AccessTokenReq object to move @a other into.
 * @param other The AccessTokenReq to move the value from.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_access_token_req_t *other);

/** Delete a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 * Destroys the reference to the AccessTokenReq object and frees the value of AccessTokenReq if this is the last reference.
 *
 * @param access_token_req The AccessTokenReq to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_access_token_req_free(data_collection_model_access_token_req_t *access_token_req);

/** Get a cJSON tree representation of a AccessTokenReq
 * \public \memberof data_collection_model_access_token_req_t
 *
 * Create a cJSON tree representation of the AccessTokenReq object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param access_token_req The AccessTokenReq to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_access_token_req_toJSON(const data_collection_model_access_token_req_t *access_token_req, bool as_request);

/** Parse a cJSON tree into a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * Attempts to interpret a cJSON tree as a AccessTokenReq API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AccessTokenReq object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AccessTokenReq object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AccessTokenReq objects to see if they are equivalent
 * \public \memberof data_collection_model_access_token_req_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param access_token_req The first AccessTokenReq object to compare.
 * @param other_access_token_req The second AccessTokenReq object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_is_equal_to(const data_collection_model_access_token_req_t *access_token_req, const data_collection_model_access_token_req_t *other_access_token_req);



/** Get the value of the grant_type field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the grant_type field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_grant_type(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the grant_type field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_grant_type The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_grant_type(data_collection_model_access_token_req_t *access_token_req, const char* p_grant_type);

/** Move a value to the grant_type field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_grant_type The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_grant_type_move(data_collection_model_access_token_req_t *access_token_req, char* p_grant_type);


/** Get the value of the nfInstanceId field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the nfInstanceId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_nf_instance_id(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the nfInstanceId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_nf_instance_id The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_instance_id(data_collection_model_access_token_req_t *access_token_req, const char* p_nf_instance_id);

/** Move a value to the nfInstanceId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_nf_instance_id The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_instance_id_move(data_collection_model_access_token_req_t *access_token_req, char* p_nf_instance_id);

/** Check if the nfType field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional nfType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_nf_type(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the nfType field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the nfType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nf_type_t* data_collection_model_access_token_req_get_nf_type(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the nfType field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_nf_type The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_type(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_nf_type_t* p_nf_type);

/** Move a value to the nfType field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_nf_type The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_type_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_nf_type_t* p_nf_type);

/** Check if the targetNfType field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetNfType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_type(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetNfType field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetNfType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nf_type_t* data_collection_model_access_token_req_get_target_nf_type(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetNfType field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_type The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_type(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_nf_type_t* p_target_nf_type);

/** Move a value to the targetNfType field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_type The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_type_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_nf_type_t* p_target_nf_type);


/** Get the value of the scope field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the scope field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_scope(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the scope field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_scope The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_scope(data_collection_model_access_token_req_t *access_token_req, const char* p_scope);

/** Move a value to the scope field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_scope The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_scope_move(data_collection_model_access_token_req_t *access_token_req, char* p_scope);

/** Check if the targetNfInstanceId field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetNfInstanceId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_instance_id(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetNfInstanceId field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetNfInstanceId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_target_nf_instance_id(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetNfInstanceId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_instance_id The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_instance_id(data_collection_model_access_token_req_t *access_token_req, const char* p_target_nf_instance_id);

/** Move a value to the targetNfInstanceId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_instance_id The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_instance_id_move(data_collection_model_access_token_req_t *access_token_req, char* p_target_nf_instance_id);

/** Check if the requesterPlmn field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional requesterPlmn field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_plmn(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the requesterPlmn field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the requesterPlmn field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_requester_plmn(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the requesterPlmn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_plmn The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_plmn_id_t* p_requester_plmn);

/** Move a value to the requesterPlmn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_plmn The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_plmn_id_t* p_requester_plmn);

/** Check if the requesterPlmnList field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional requesterPlmnList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_plmn_list(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the requesterPlmnList field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the requesterPlmnList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_plmn_list(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the requesterPlmnList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_plmn_list The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_list(data_collection_model_access_token_req_t *access_token_req, const ogs_list_t* p_requester_plmn_list);

/** Move a value to the requesterPlmnList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_plmn_list The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_list_move(data_collection_model_access_token_req_t *access_token_req, ogs_list_t* p_requester_plmn_list);

/** Add a new item to the requesterPlmnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to add the array item to.
 * @param requester_plmn_list The value to add.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_plmn_list(data_collection_model_access_token_req_t *access_token_req, data_collection_model_plmn_id_t* requester_plmn_list);

/** Remove an item from the requesterPlmnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to remove the array value from.
 * @param requester_plmn_list The value to remove.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_plmn_list(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_plmn_id_t* requester_plmn_list);

/** Get an item from the requesterPlmnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_entry_requester_plmn_list(const data_collection_model_access_token_req_t *access_token_req, size_t idx);

/** Remove all entries from the requesterPlmnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to empty requesterPlmnList for.
 *
 * @return @a access_token_req
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_plmn_list(data_collection_model_access_token_req_t *access_token_req);

/** Check if the requesterSnssaiList field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional requesterSnssaiList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_snssai_list(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the requesterSnssaiList field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the requesterSnssaiList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_snssai_list(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the requesterSnssaiList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_snssai_list The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snssai_list(data_collection_model_access_token_req_t *access_token_req, const ogs_list_t* p_requester_snssai_list);

/** Move a value to the requesterSnssaiList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_snssai_list The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snssai_list_move(data_collection_model_access_token_req_t *access_token_req, ogs_list_t* p_requester_snssai_list);

/** Add a new item to the requesterSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to add the array item to.
 * @param requester_snssai_list The value to add.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_snssai_list(data_collection_model_access_token_req_t *access_token_req, data_collection_model_snssai_t* requester_snssai_list);

/** Remove an item from the requesterSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to remove the array value from.
 * @param requester_snssai_list The value to remove.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_snssai_list(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_snssai_t* requester_snssai_list);

/** Get an item from the requesterSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_access_token_req_get_entry_requester_snssai_list(const data_collection_model_access_token_req_t *access_token_req, size_t idx);

/** Remove all entries from the requesterSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to empty requesterSnssaiList for.
 *
 * @return @a access_token_req
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_snssai_list(data_collection_model_access_token_req_t *access_token_req);

/** Check if the requesterFqdn field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional requesterFqdn field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_fqdn(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the requesterFqdn field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the requesterFqdn field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_requester_fqdn(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the requesterFqdn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_fqdn The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_fqdn(data_collection_model_access_token_req_t *access_token_req, const char* p_requester_fqdn);

/** Move a value to the requesterFqdn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_fqdn The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_fqdn_move(data_collection_model_access_token_req_t *access_token_req, char* p_requester_fqdn);

/** Check if the requesterSnpnList field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional requesterSnpnList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_snpn_list(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the requesterSnpnList field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the requesterSnpnList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_snpn_list(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the requesterSnpnList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_snpn_list The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snpn_list(data_collection_model_access_token_req_t *access_token_req, const ogs_list_t* p_requester_snpn_list);

/** Move a value to the requesterSnpnList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_snpn_list The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snpn_list_move(data_collection_model_access_token_req_t *access_token_req, ogs_list_t* p_requester_snpn_list);

/** Add a new item to the requesterSnpnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to add the array item to.
 * @param requester_snpn_list The value to add.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_snpn_list(data_collection_model_access_token_req_t *access_token_req, data_collection_model_plmn_id_nid_t* requester_snpn_list);

/** Remove an item from the requesterSnpnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to remove the array value from.
 * @param requester_snpn_list The value to remove.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_snpn_list(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_plmn_id_nid_t* requester_snpn_list);

/** Get an item from the requesterSnpnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_nid_t* data_collection_model_access_token_req_get_entry_requester_snpn_list(const data_collection_model_access_token_req_t *access_token_req, size_t idx);

/** Remove all entries from the requesterSnpnList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to empty requesterSnpnList for.
 *
 * @return @a access_token_req
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_snpn_list(data_collection_model_access_token_req_t *access_token_req);

/** Check if the targetPlmn field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetPlmn field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_plmn(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetPlmn field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetPlmn field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_target_plmn(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetPlmn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_plmn The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_plmn(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_plmn_id_t* p_target_plmn);

/** Move a value to the targetPlmn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_plmn The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_plmn_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_plmn_id_t* p_target_plmn);

/** Check if the targetSnpn field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetSnpn field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_snpn(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetSnpn field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetSnpn field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_nid_t* data_collection_model_access_token_req_get_target_snpn(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetSnpn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_snpn The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snpn(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_plmn_id_nid_t* p_target_snpn);

/** Move a value to the targetSnpn field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_snpn The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snpn_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_plmn_id_nid_t* p_target_snpn);

/** Check if the targetSnssaiList field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetSnssaiList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_snssai_list(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetSnssaiList field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetSnssaiList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_target_snssai_list(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetSnssaiList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_snssai_list The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snssai_list(data_collection_model_access_token_req_t *access_token_req, const ogs_list_t* p_target_snssai_list);

/** Move a value to the targetSnssaiList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_snssai_list The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snssai_list_move(data_collection_model_access_token_req_t *access_token_req, ogs_list_t* p_target_snssai_list);

/** Add a new item to the targetSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to add the array item to.
 * @param target_snssai_list The value to add.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_target_snssai_list(data_collection_model_access_token_req_t *access_token_req, data_collection_model_snssai_t* target_snssai_list);

/** Remove an item from the targetSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to remove the array value from.
 * @param target_snssai_list The value to remove.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_target_snssai_list(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_snssai_t* target_snssai_list);

/** Get an item from the targetSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_access_token_req_get_entry_target_snssai_list(const data_collection_model_access_token_req_t *access_token_req, size_t idx);

/** Remove all entries from the targetSnssaiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to empty targetSnssaiList for.
 *
 * @return @a access_token_req
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_target_snssai_list(data_collection_model_access_token_req_t *access_token_req);

/** Check if the targetNsiList field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetNsiList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nsi_list(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetNsiList field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetNsiList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_target_nsi_list(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetNsiList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nsi_list The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nsi_list(data_collection_model_access_token_req_t *access_token_req, const ogs_list_t* p_target_nsi_list);

/** Move a value to the targetNsiList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nsi_list The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nsi_list_move(data_collection_model_access_token_req_t *access_token_req, ogs_list_t* p_target_nsi_list);

/** Add a new item to the targetNsiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to add the array item to.
 * @param target_nsi_list The value to add.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_target_nsi_list(data_collection_model_access_token_req_t *access_token_req, char* target_nsi_list);

/** Remove an item from the targetNsiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to remove the array value from.
 * @param target_nsi_list The value to remove.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_target_nsi_list(data_collection_model_access_token_req_t *access_token_req, const char* target_nsi_list);

/** Get an item from the targetNsiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_entry_target_nsi_list(const data_collection_model_access_token_req_t *access_token_req, size_t idx);

/** Remove all entries from the targetNsiList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to empty targetNsiList for.
 *
 * @return @a access_token_req
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_target_nsi_list(data_collection_model_access_token_req_t *access_token_req);

/** Check if the targetNfSetId field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetNfSetId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_set_id(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetNfSetId field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetNfSetId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_target_nf_set_id(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetNfSetId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_set_id The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_set_id(data_collection_model_access_token_req_t *access_token_req, const char* p_target_nf_set_id);

/** Move a value to the targetNfSetId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_set_id The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_set_id_move(data_collection_model_access_token_req_t *access_token_req, char* p_target_nf_set_id);

/** Check if the targetNfServiceSetId field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional targetNfServiceSetId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_service_set_id(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the targetNfServiceSetId field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the targetNfServiceSetId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_target_nf_service_set_id(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the targetNfServiceSetId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_service_set_id The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_service_set_id(data_collection_model_access_token_req_t *access_token_req, const char* p_target_nf_service_set_id);

/** Move a value to the targetNfServiceSetId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_target_nf_service_set_id The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_service_set_id_move(data_collection_model_access_token_req_t *access_token_req, char* p_target_nf_service_set_id);

/** Check if the hnrfAccessTokenUri field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional hnrfAccessTokenUri field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_hnrf_access_token_uri(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the hnrfAccessTokenUri field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the hnrfAccessTokenUri field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_hnrf_access_token_uri(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the hnrfAccessTokenUri field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_hnrf_access_token_uri The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_hnrf_access_token_uri(data_collection_model_access_token_req_t *access_token_req, const char* p_hnrf_access_token_uri);

/** Move a value to the hnrfAccessTokenUri field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_hnrf_access_token_uri The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_hnrf_access_token_uri_move(data_collection_model_access_token_req_t *access_token_req, char* p_hnrf_access_token_uri);

/** Check if the sourceNfInstanceId field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional sourceNfInstanceId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_source_nf_instance_id(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the sourceNfInstanceId field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the sourceNfInstanceId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_source_nf_instance_id(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the sourceNfInstanceId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_source_nf_instance_id The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_source_nf_instance_id(data_collection_model_access_token_req_t *access_token_req, const char* p_source_nf_instance_id);

/** Move a value to the sourceNfInstanceId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_source_nf_instance_id The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_source_nf_instance_id_move(data_collection_model_access_token_req_t *access_token_req, char* p_source_nf_instance_id);

/** Check if the vendorId field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional vendorId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_vendor_id(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the vendorId field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the vendorId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_vendor_id(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the vendorId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_vendor_id The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_vendor_id(data_collection_model_access_token_req_t *access_token_req, const char* p_vendor_id);

/** Move a value to the vendorId field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_vendor_id The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_vendor_id_move(data_collection_model_access_token_req_t *access_token_req, char* p_vendor_id);

/** Check if the analyticsIds field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional analyticsIds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_analytics_ids(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the analyticsIds field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the analyticsIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_analytics_ids(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the analyticsIds field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_analytics_ids The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_analytics_ids(data_collection_model_access_token_req_t *access_token_req, const ogs_list_t* p_analytics_ids);

/** Move a value to the analyticsIds field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_analytics_ids The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_analytics_ids_move(data_collection_model_access_token_req_t *access_token_req, ogs_list_t* p_analytics_ids);

/** Add a new item to the analyticsIds array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to add the array item to.
 * @param analytics_ids The value to add.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_analytics_ids(data_collection_model_access_token_req_t *access_token_req, data_collection_model_nwdaf_event_t* analytics_ids);

/** Remove an item from the analyticsIds array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to remove the array value from.
 * @param analytics_ids The value to remove.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_analytics_ids(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_nwdaf_event_t* analytics_ids);

/** Get an item from the analyticsIds array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nwdaf_event_t* data_collection_model_access_token_req_get_entry_analytics_ids(const data_collection_model_access_token_req_t *access_token_req, size_t idx);

/** Remove all entries from the analyticsIds array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to empty analyticsIds for.
 *
 * @return @a access_token_req
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_analytics_ids(data_collection_model_access_token_req_t *access_token_req);

/** Check if the requesterInterIndList field of a AccessTokenReq object is set
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return `true` if the optional requesterInterIndList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_inter_ind_list(const data_collection_model_access_token_req_t *access_token_req);


/** Get the value of the requesterInterIndList field of a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 *
 * @return the value current set for the requesterInterIndList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_inter_ind_list(const data_collection_model_access_token_req_t *access_token_req);

/** Set the value of the requesterInterIndList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_inter_ind_list The value to copy into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_inter_ind_list(data_collection_model_access_token_req_t *access_token_req, const ogs_list_t* p_requester_inter_ind_list);

/** Move a value to the requesterInterIndList field in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to set the field in.
 * @param p_requester_inter_ind_list The value to move into the AccessTokenReq object.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_inter_ind_list_move(data_collection_model_access_token_req_t *access_token_req, ogs_list_t* p_requester_inter_ind_list);

/** Add a new item to the requesterInterIndList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to add the array item to.
 * @param requester_inter_ind_list The value to add.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_inter_ind_list(data_collection_model_access_token_req_t *access_token_req, data_collection_model_ml_model_inter_ind_t* requester_inter_ind_list);

/** Remove an item from the requesterInterIndList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to remove the array value from.
 * @param requester_inter_ind_list The value to remove.
 *
 * @return @a access_token_req.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_inter_ind_list(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_ml_model_inter_ind_t* requester_inter_ind_list);

/** Get an item from the requesterInterIndList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ml_model_inter_ind_t* data_collection_model_access_token_req_get_entry_requester_inter_ind_list(const data_collection_model_access_token_req_t *access_token_req, size_t idx);

/** Remove all entries from the requesterInterIndList array in a AccessTokenReq object
 * \public \memberof data_collection_model_access_token_req_t
 *
 * @param access_token_req The AccessTokenReq object to empty requesterInterIndList for.
 *
 * @return @a access_token_req
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_inter_ind_list(data_collection_model_access_token_req_t *access_token_req);

/** lnode helper for generating ogs_list_t nodes's of type AccessTokenReq
 * \public \memberof data_collection_model_access_token_req_t
 *
 * Creates a new data_collection_lnode_t object containing the @a access_token_req object.
 * The @a access_token_req will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param access_token_req The AccessTokenReq object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a access_token_req
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_access_token_req_make_lnode(data_collection_model_access_token_req_t *access_token_req);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ACCESS_TOKEN_REQ_H_ */

