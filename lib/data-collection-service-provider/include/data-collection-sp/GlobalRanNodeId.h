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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_global_ran_node_id_s data_collection_model_global_ran_node_id_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create_copy(const data_collection_model_global_ran_node_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create_move(data_collection_model_global_ran_node_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_copy(data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_global_ran_node_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, data_collection_model_global_ran_node_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_global_ran_node_id_free(data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_global_ran_node_id_toJSON(const data_collection_model_global_ran_node_id_t *global_ran_node_id, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_global_ran_node_id_is_equal_to(const data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_global_ran_node_id_t *other_global_ran_node_id);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_global_ran_node_id_get_plmn_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_plmn_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_plmn_id_t* p_plmn_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_plmn_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, data_collection_model_plmn_id_t* p_plmn_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_n3_iwf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_n3_iwf_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_n3_iwf_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_n3_iwf_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_n3_iwf_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnb_id_t* data_collection_model_global_ran_node_id_get_gnb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_gnb_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_gnb_id_t* p_gnb_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_gnb_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, data_collection_model_gnb_id_t* p_gnb_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_nge_nb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nge_nb_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_nge_nb_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nge_nb_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_nge_nb_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_wagf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_wagf_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_wagf_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_wagf_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_wagf_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_tngf_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_tngf_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_tngf_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_tngf_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_tngf_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_nid(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nid(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_nid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nid_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_nid);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_global_ran_node_id_get_enb_id(const data_collection_model_global_ran_node_id_t *global_ran_node_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_enb_id(data_collection_model_global_ran_node_id_t *global_ran_node_id, const char* p_enb_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_enb_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, char* p_enb_id);

/* lnode helper for generating ogs_list_t nodes's of type GlobalRanNodeId */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_global_ran_node_id_make_lnode(data_collection_model_global_ran_node_id_t *global_ran_node_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GLOBAL_RAN_NODE_ID_H_ */

