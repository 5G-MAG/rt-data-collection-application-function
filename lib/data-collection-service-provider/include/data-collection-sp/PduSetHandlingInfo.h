#ifndef _DATA_COLLECTION_PDU_SET_HANDLING_INFO_H_
#define _DATA_COLLECTION_PDU_SET_HANDLING_INFO_H_

/**********************************************************************************************************************************
 * PduSetHandlingInfo - Public C interface to the PduSetHandlingInfo object
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

#include "PduSetHandlingInfo_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_pdu_set_handling_info_s data_collection_model_pdu_set_handling_info_t;

typedef enum {
    DCM_PDU_SET_HANDLING_INFO_NO_VAL,
    DCM_PDU_SET_HANDLING_INFO_VAL_ALL_PDUS_NEEDED,
    DCM_PDU_SET_HANDLING_INFO_VAL_ALL_PDUS_NOT_NEEDED,
    DCM_PDU_SET_HANDLING_INFO_OTHER
} data_collection_model_pdu_set_handling_info_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create_copy(const data_collection_model_pdu_set_handling_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create_move(data_collection_model_pdu_set_handling_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_copy(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, const data_collection_model_pdu_set_handling_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_move(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, data_collection_model_pdu_set_handling_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_pdu_set_handling_info_free(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_pdu_set_handling_info_toJSON(const data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_is_not_set(const data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_is_non_standard(const data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_e data_collection_model_pdu_set_handling_info_get_enum(const data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_pdu_set_handling_info_get_string(const data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_set_enum(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, data_collection_model_pdu_set_handling_info_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_set_string(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type PduSetHandlingInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_pdu_set_handling_info_make_lnode(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PDU_SET_HANDLING_INFO_H_ */

