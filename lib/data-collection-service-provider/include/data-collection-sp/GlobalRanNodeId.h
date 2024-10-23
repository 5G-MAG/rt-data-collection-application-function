#ifndef _DATA_COLLECTION_GLOBAL_RAN_NODE_ID_H_
#define _DATA_COLLECTION_GLOBAL_RAN_NODE_ID_H_

/**********************************************************************************************************************************
 * GlobalRanNodeId - Public C interface to the GlobalRanNodeId object
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

#include "GNbId.h"
#include "PlmnId.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP GlobalRanNodeId object reference
 */
typedef struct data_collection_model_global_ran_node_id_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_global_ran_node_id_t;



/** Create a new GlobalRanNodeId
 * \public \memberof data_collection_model_global_ran_node_id_t
 * @return a new GlobalRanNodeId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create();

/** Create a new copy of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 * Creates a new copy of the given @a other object
 * @param other The GlobalRanNodeId to copy.
 * @return a new GlobalRanNodeId object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create_copy(const data_collection_model_global_ran_node_id_t *other);

/** Create a new reference of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GlobalRanNodeId to create a new reference to.
 * @return a new GlobalRanNodeId object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create_move(data_collection_model_global_ran_node_id_t *other);

/** Copy the value of another GlobalRanNodeId into this object
 * \public \memberof data_collection_model_global_ran_node_id_t
 * Copies the value of @a other {{classname} object into @a global_ran_node_id.
 * @param global_ran_node_id The GlobalRanNodeId object to copy @a other into.
 * @param other The GlobalRanNodeId to copy the value from.
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_copy(data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_global_ran_node_id_t *other);

/** Move the value of another GlobalRanNodeId into this object
 * \public \memberof data_collection_model_global_ran_node_id_t
 * Discards the current value of @a global_ran_node_id and moves the value of @a other
 * into @a global_ran_node_id. This will leave @a other as an empty reference.
 *
 * @param global_ran_node_id The GlobalRanNodeId object to move @a other into.
 * @param other The GlobalRanNodeId to move the value from.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, data_collection_model_global_ran_node_id_t *other);

/** Delete a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 * Destroys the reference to the GlobalRanNodeId object and frees the value of GlobalRanNodeId if this is the last reference.
 *
 * @param global_ran_node_id The GlobalRanNodeId to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_global_ran_node_id_free(data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Get a cJSON tree representation of a GlobalRanNodeId
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * Create a cJSON tree representation of the GlobalRanNodeId object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param global_ran_node_id The GlobalRanNodeId to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_global_ran_node_id_toJSON(const data_collection_model_global_ran_node_id_t *global_ran_node_id, bool as_request);

/** Parse a cJSON tree into a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * Attempts to interpret a cJSON tree as a GlobalRanNodeId API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GlobalRanNodeId object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GlobalRanNodeId object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GlobalRanNodeId objects to see if they are equivalent
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param global_ran_node_id The first GlobalRanNodeId object to compare.
 * @param other_global_ran_node_id The second GlobalRanNodeId object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_is_equal_to(const data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_global_ran_node_id_t *other_global_ran_node_id);



/** Get the value of the plmnId field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the plmnId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_global_ran_node_id_get_plmn_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the plmnId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_plmn_id The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_plmn_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_plmn_id_t* p_plmn_id);

/** Move a value to the plmnId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_plmn_id The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_plmn_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, data_collection_model_plmn_id_t* p_plmn_id);

/** Check if the n3IwfId field of a GlobalRanNodeId object is set
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return `true` if the optional n3IwfId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_has_n3_iwf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);


/** Get the value of the n3IwfId field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the n3IwfId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_n3_iwf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the n3IwfId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_n3_iwf_id The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_n3_iwf_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_n3_iwf_id);

/** Move a value to the n3IwfId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_n3_iwf_id The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_n3_iwf_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_n3_iwf_id);

/** Check if the gNbId field of a GlobalRanNodeId object is set
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return `true` if the optional gNbId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_has_gnb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);


/** Get the value of the gNbId field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the gNbId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnb_id_t* data_collection_model_global_ran_node_id_get_gnb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the gNbId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_gnb_id The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_gnb_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_gnb_id_t* p_gnb_id);

/** Move a value to the gNbId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_gnb_id The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_gnb_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, data_collection_model_gnb_id_t* p_gnb_id);

/** Check if the ngeNbId field of a GlobalRanNodeId object is set
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return `true` if the optional ngeNbId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_has_nge_nb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);


/** Get the value of the ngeNbId field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the ngeNbId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_nge_nb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the ngeNbId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_nge_nb_id The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nge_nb_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_nge_nb_id);

/** Move a value to the ngeNbId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_nge_nb_id The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nge_nb_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_nge_nb_id);

/** Check if the wagfId field of a GlobalRanNodeId object is set
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return `true` if the optional wagfId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_has_wagf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);


/** Get the value of the wagfId field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the wagfId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_wagf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the wagfId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_wagf_id The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_wagf_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_wagf_id);

/** Move a value to the wagfId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_wagf_id The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_wagf_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_wagf_id);

/** Check if the tngfId field of a GlobalRanNodeId object is set
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return `true` if the optional tngfId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_has_tngf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);


/** Get the value of the tngfId field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the tngfId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_tngf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the tngfId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_tngf_id The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_tngf_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_tngf_id);

/** Move a value to the tngfId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_tngf_id The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_tngf_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_tngf_id);

/** Check if the nid field of a GlobalRanNodeId object is set
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return `true` if the optional nid field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_has_nid(const data_collection_model_global_ran_node_id_t *global_ran_node_id);


/** Get the value of the nid field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the nid field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_nid(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the nid field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_nid The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nid(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_nid);

/** Move a value to the nid field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_nid The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nid_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_nid);

/** Check if the eNbId field of a GlobalRanNodeId object is set
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return `true` if the optional eNbId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_has_enb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);


/** Get the value of the eNbId field of a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to examine.
 *
 * @return the value current set for the eNbId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_enb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

/** Set the value of the eNbId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_enb_id The value to copy into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_enb_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_enb_id);

/** Move a value to the eNbId field in a GlobalRanNodeId object
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * @param global_ran_node_id The GlobalRanNodeId object to set the field in.
 * @param p_enb_id The value to move into the GlobalRanNodeId object.
 *
 * @return @a global_ran_node_id.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_enb_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_enb_id);

/** lnode helper for generating ogs_list_t nodes's of type GlobalRanNodeId
 * \public \memberof data_collection_model_global_ran_node_id_t
 *
 * Creates a new data_collection_lnode_t object containing the @a global_ran_node_id object.
 * The @a global_ran_node_id will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param global_ran_node_id The GlobalRanNodeId object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a global_ran_node_id
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_global_ran_node_id_make_lnode(data_collection_model_global_ran_node_id_t *global_ran_node_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GLOBAL_RAN_NODE_ID_H_ */

