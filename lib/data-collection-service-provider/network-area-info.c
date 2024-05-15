/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "ogs-core.h"

#include "openapi/model/dc_api_network_area_info.h"
#include "openapi/model/dc_api_ecgi.h"
#include "openapi/model/dc_api_ncgi.h"
#include "openapi/model/dc_api_global_ran_node_id.h"
#include "openapi/model/dc_api_tai.h"

#include "e-utra-cell-id-internal.h"
#include "nr-cell-id-internal.h"
#include "global-ran-node-id-internal.h"
#include "tracking-area-id-internal.h"

#include "network-area-info-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

_DC_WRAPPED_OPENAPI_NODE_TYPE_START(network_area_info, network_area_info)
    _DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT_LIST(e_utra_cell_id);
    _DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT_LIST(nr_cell_id);
    _DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT_LIST(global_ran_node_id);
    _DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT_LIST(tracking_area_id);
_DC_WRAPPED_OPENAPI_NODE_TYPE_END(network_area_info);

/***** Library function API *****/

/** Create a new NetworkAreaInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_network_area_info_t* data_collection_network_area_info_create(
                    ogs_list_t *e_utra_cell_ids,
                    ogs_list_t *nr_cell_ids,
                    ogs_list_t *global_ran_node_ids,
                    ogs_list_t *tracking_area_ids
                    )
{
    data_collection_network_area_info_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(network_area_info, create)();

    OpenAPI_list_t *ecgis = NULL, *ncgis = NULL, *g_ran_node_ids = NULL, *tais = NULL;

    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT_LIST(ret, e_utra_cell_id, e_utra_cell_ids, ecgis);
    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT_LIST(ret, nr_cell_id, nr_cell_ids, ncgis);
    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT_LIST(ret, global_ran_node_id, global_ran_node_ids, g_ran_node_ids);
    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT_LIST(ret, tracking_area_id, tracking_area_ids, tais);

    dc_api_network_area_info_t *nai = dc_api_network_area_info_create(ecgis, ncgis, g_ran_node_ids, tais);
    ogs_assert(nai);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(network_area_info, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(network_area_info, create_zero)(nai));

    return ret;
}

/** Destroy a NetworkAreaInfo */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_network_area_info_free(data_collection_network_area_info_t *info)
{
    if (!info) return;

    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT_LIST(network_area_info, network_area_info, info, e_utra_cell_id, ecgi, ecgis);
    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT_LIST(network_area_info, network_area_info, info, nr_cell_id, ncgi, ncgis);
    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT_LIST(network_area_info, network_area_info, info, global_ran_node_id, global_ran_node_id, g_ran_node_ids);
    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT_LIST(network_area_info, network_area_info, info, tracking_area_id, tai, tais);
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(network_area_info, free)(info);
}

/***** Library internal functions *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(network_area_info, network_area_info)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
