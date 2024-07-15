#ifndef _DATA_COLLECTION_FLOW_INFO_H_
#define _DATA_COLLECTION_FLOW_INFO_H_

/**********************************************************************************************************************************
 * FlowInfo - Public C interface to the FlowInfo object
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

typedef struct data_collection_model_flow_info_s data_collection_model_flow_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create_copy(const data_collection_model_flow_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create_move(data_collection_model_flow_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_copy(data_collection_model_flow_info_t *flow_info, const data_collection_model_flow_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_move(data_collection_model_flow_info_t *flow_info, data_collection_model_flow_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_flow_info_free(data_collection_model_flow_info_t *flow_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_flow_info_toJSON(const data_collection_model_flow_info_t *flow_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_flow_info_get_flow_id(const data_collection_model_flow_info_t *flow_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id(data_collection_model_flow_info_t *flow_info, const int32_t p_flow_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id_move(data_collection_model_flow_info_t *flow_info, int32_t p_flow_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_flow_info_get_flow_descriptions(const data_collection_model_flow_info_t *flow_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions(data_collection_model_flow_info_t *flow_info, const ogs_list_t* p_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions_move(data_collection_model_flow_info_t *flow_info, ogs_list_t* p_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_add_flow_descriptions(data_collection_model_flow_info_t *flow_info, char* flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_remove_flow_descriptions(data_collection_model_flow_info_t *flow_info, const char* flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_clear_flow_descriptions(data_collection_model_flow_info_t *flow_info);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_flow_info_get_tos_tc(const data_collection_model_flow_info_t *flow_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc(data_collection_model_flow_info_t *flow_info, const char* p_tos_tc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc_move(data_collection_model_flow_info_t *flow_info, char* p_tos_tc);

/* lnode helper for generating ogs_list_t nodes's of type FlowInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_flow_info_make_lnode(data_collection_model_flow_info_t *flow_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_FLOW_INFO_H_ */

