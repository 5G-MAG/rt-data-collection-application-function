#ifndef _DATA_COLLECTION_PDU_SET_QOS_PARA_H_
#define _DATA_COLLECTION_PDU_SET_QOS_PARA_H_

/**********************************************************************************************************************************
 * PduSetQosPara - Public C interface to the PduSetQosPara object
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

#include "PduSetHandlingInfo.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PduSetQosPara object reference
 */
typedef struct data_collection_model_pdu_set_qos_para_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_pdu_set_qos_para_t;



/** Create a new PduSetQosPara.
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 * @return a new PduSetQosPara object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create();

/** Create a new PduSetQosPara reference.
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PduSetQosPara to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create_ref(const data_collection_model_pdu_set_qos_para_t *other);

/** Create a new copy of a PduSetQosPara object.
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 * Creates a new copy of the given @a other object
 * @param other The PduSetQosPara to copy.
 * @return a new PduSetQosPara object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create_copy(const data_collection_model_pdu_set_qos_para_t *other);

/** Create a new reference of a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PduSetQosPara to create a new reference to.
 * @return a new PduSetQosPara object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create_move(data_collection_model_pdu_set_qos_para_t *other);

/** Copy the value of another PduSetQosPara into this object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 * Copies the value of @a other {{classname} object into @a pdu_set_qos_para.
 * @param pdu_set_qos_para The PduSetQosPara object to copy @a other into.
 * @param other The PduSetQosPara to copy the value from.
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_copy(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const data_collection_model_pdu_set_qos_para_t *other);

/** Move the value of another PduSetQosPara into this object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 * Discards the current value of @a pdu_set_qos_para and moves the value of @a other
 * into @a pdu_set_qos_para. This will leave @a other as an empty reference.
 *
 * @param pdu_set_qos_para The PduSetQosPara object to move @a other into.
 * @param other The PduSetQosPara to move the value from.
 *
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, data_collection_model_pdu_set_qos_para_t *other);

/** Delete a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 * Destroys the reference to the PduSetQosPara object and frees the value of PduSetQosPara if this is the last reference.
 *
 * @param pdu_set_qos_para The PduSetQosPara to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_pdu_set_qos_para_free(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

/** Get a cJSON tree representation of a PduSetQosPara
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * Create a cJSON tree representation of the PduSetQosPara object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param pdu_set_qos_para The PduSetQosPara to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_pdu_set_qos_para_toJSON(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, bool as_request);

/** Parse a cJSON tree into a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * Attempts to interpret a cJSON tree as a PduSetQosPara API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PduSetQosPara object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PduSetQosPara object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PduSetQosPara objects to see if they are equivalent
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param pdu_set_qos_para The first PduSetQosPara object to compare.
 * @param other_pdu_set_qos_para The second PduSetQosPara object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_qos_para_is_equal_to(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const data_collection_model_pdu_set_qos_para_t *other_pdu_set_qos_para);


/** Check if the pduSetDelayBudget field of a PduSetQosPara object is set
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to examine.
 *
 * @return `true` if the optional pduSetDelayBudget field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_qos_para_has_pdu_set_delay_budget(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);


/** Get the value of the pduSetDelayBudget field of a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to examine.
 *
 * @return the value current set for the pduSetDelayBudget field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_pdu_set_qos_para_get_pdu_set_delay_budget(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

/** Set the value of the pduSetDelayBudget field in a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to set the field in.
 * @param p_pdu_set_delay_budget The value to copy into the PduSetQosPara object.
 *
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_delay_budget(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const int32_t p_pdu_set_delay_budget);

/** Move a value to the pduSetDelayBudget field in a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to set the field in.
 * @param p_pdu_set_delay_budget The value to move into the PduSetQosPara object.
 *
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_delay_budget_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, int32_t p_pdu_set_delay_budget);

/** Check if the pduSetErrRate field of a PduSetQosPara object is set
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to examine.
 *
 * @return `true` if the optional pduSetErrRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_qos_para_has_pdu_set_err_rate(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);


/** Get the value of the pduSetErrRate field of a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to examine.
 *
 * @return the value current set for the pduSetErrRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_pdu_set_qos_para_get_pdu_set_err_rate(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

/** Set the value of the pduSetErrRate field in a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to set the field in.
 * @param p_pdu_set_err_rate The value to copy into the PduSetQosPara object.
 *
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_err_rate(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const char* p_pdu_set_err_rate);

/** Move a value to the pduSetErrRate field in a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to set the field in.
 * @param p_pdu_set_err_rate The value to move into the PduSetQosPara object.
 *
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_err_rate_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, char* p_pdu_set_err_rate);

/** Check if the pduSetHandlingInfo field of a PduSetQosPara object is set
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to examine.
 *
 * @return `true` if the optional pduSetHandlingInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_qos_para_has_pdu_set_handling_info(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);


/** Get the value of the pduSetHandlingInfo field of a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to examine.
 *
 * @return the value current set for the pduSetHandlingInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_handling_info_t* data_collection_model_pdu_set_qos_para_get_pdu_set_handling_info(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

/** Set the value of the pduSetHandlingInfo field in a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to set the field in.
 * @param p_pdu_set_handling_info The value to copy into the PduSetQosPara object.
 *
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_handling_info(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const data_collection_model_pdu_set_handling_info_t* p_pdu_set_handling_info);

/** Move a value to the pduSetHandlingInfo field in a PduSetQosPara object
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * @param pdu_set_qos_para The PduSetQosPara object to set the field in.
 * @param p_pdu_set_handling_info The value to move into the PduSetQosPara object.
 *
 * @return @a pdu_set_qos_para.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_handling_info_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, data_collection_model_pdu_set_handling_info_t* p_pdu_set_handling_info);

/** lnode helper for generating ogs_list_t nodes's of type PduSetQosPara
 * \public \memberof data_collection_model_pdu_set_qos_para_t
 *
 * Creates a new data_collection_lnode_t object containing the @a pdu_set_qos_para object.
 * The @a pdu_set_qos_para will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param pdu_set_qos_para The PduSetQosPara object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a pdu_set_qos_para
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_pdu_set_qos_para_make_lnode(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PDU_SET_QOS_PARA_H_ */

