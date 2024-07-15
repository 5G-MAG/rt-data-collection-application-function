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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_pdu_set_qos_para_s data_collection_model_pdu_set_qos_para_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create_copy(const data_collection_model_pdu_set_qos_para_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create_move(data_collection_model_pdu_set_qos_para_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_copy(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const data_collection_model_pdu_set_qos_para_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, data_collection_model_pdu_set_qos_para_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_pdu_set_qos_para_free(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_pdu_set_qos_para_toJSON(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_pdu_set_qos_para_get_pdu_set_delay_budget(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_delay_budget(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const int32_t p_pdu_set_delay_budget);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_delay_budget_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, int32_t p_pdu_set_delay_budget);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_pdu_set_qos_para_get_pdu_set_err_rate(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_err_rate(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const char* p_pdu_set_err_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_err_rate_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, char* p_pdu_set_err_rate);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_handling_info_t* data_collection_model_pdu_set_qos_para_get_pdu_set_handling_info(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_handling_info(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const data_collection_model_pdu_set_handling_info_t* p_pdu_set_handling_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_handling_info_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, data_collection_model_pdu_set_handling_info_t* p_pdu_set_handling_info);

/* lnode helper for generating ogs_list_t nodes's of type PduSetQosPara */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_pdu_set_qos_para_make_lnode(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PDU_SET_QOS_PARA_H_ */

