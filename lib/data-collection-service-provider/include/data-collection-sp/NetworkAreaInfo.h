#ifndef _DATA_COLLECTION_NETWORK_AREA_INFO_H_
#define _DATA_COLLECTION_NETWORK_AREA_INFO_H_

/**********************************************************************************************************************************
 * NetworkAreaInfo - Public C interface to the NetworkAreaInfo object
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

#include "Ecgi.h"
#include "Ncgi.h"
#include "Tai.h"
#include "GlobalRanNodeId.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_network_area_info_s data_collection_model_network_area_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create_copy(const data_collection_model_network_area_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create_move(data_collection_model_network_area_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_copy(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_network_area_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_move(data_collection_model_network_area_info_t *network_area_info, data_collection_model_network_area_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_area_info_free(data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_area_info_toJSON(const data_collection_model_network_area_info_t *network_area_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_ecgis(const data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ecgis(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_ecgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ecgis_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_ecgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_ecgis(data_collection_model_network_area_info_t *network_area_info, data_collection_model_ecgi_t* ecgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_ecgis(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_ecgi_t* ecgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_ecgis(data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_ncgis(const data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ncgis(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_ncgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ncgis_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_ncgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_ncgis(data_collection_model_network_area_info_t *network_area_info, data_collection_model_ncgi_t* ncgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_ncgis(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_ncgi_t* ncgis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_ncgis(data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_g_ran_node_ids(const data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_g_ran_node_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_g_ran_node_ids_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_g_ran_node_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info, data_collection_model_global_ran_node_id_t* g_ran_node_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_global_ran_node_id_t* g_ran_node_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_g_ran_node_ids(data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_tais(const data_collection_model_network_area_info_t *network_area_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_tais(data_collection_model_network_area_info_t *network_area_info, const ogs_list_t* p_tais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_tais_move(data_collection_model_network_area_info_t *network_area_info, ogs_list_t* p_tais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_tais(data_collection_model_network_area_info_t *network_area_info, data_collection_model_tai_t* tais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_tais(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_tai_t* tais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_tais(data_collection_model_network_area_info_t *network_area_info);

/* lnode helper for generating ogs_list_t nodes's of type NetworkAreaInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_area_info_make_lnode(data_collection_model_network_area_info_t *network_area_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_AREA_INFO_H_ */

