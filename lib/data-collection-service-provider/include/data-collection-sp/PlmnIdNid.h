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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_plmn_id_nid_s data_collection_model_plmn_id_nid_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create_copy(const data_collection_model_plmn_id_nid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create_move(data_collection_model_plmn_id_nid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_copy(data_collection_model_plmn_id_nid_t *plmn_id_nid, const data_collection_model_plmn_id_nid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, data_collection_model_plmn_id_nid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_plmn_id_nid_free(data_collection_model_plmn_id_nid_t *plmn_id_nid);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_plmn_id_nid_toJSON(const data_collection_model_plmn_id_nid_t *plmn_id_nid, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_nid_get_mcc(const data_collection_model_plmn_id_nid_t *plmn_id_nid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mcc(data_collection_model_plmn_id_nid_t *plmn_id_nid, const char* p_mcc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mcc_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, char* p_mcc);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_nid_get_mnc(const data_collection_model_plmn_id_nid_t *plmn_id_nid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mnc(data_collection_model_plmn_id_nid_t *plmn_id_nid, const char* p_mnc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mnc_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, char* p_mnc);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_nid_get_nid(const data_collection_model_plmn_id_nid_t *plmn_id_nid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_nid(data_collection_model_plmn_id_nid_t *plmn_id_nid, const char* p_nid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_nid_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, char* p_nid);

/* lnode helper for generating ogs_list_t nodes's of type PlmnIdNid */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_plmn_id_nid_make_lnode(data_collection_model_plmn_id_nid_t *plmn_id_nid);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PLMN_ID_NID_H_ */

