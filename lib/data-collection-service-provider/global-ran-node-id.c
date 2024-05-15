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

#include "openapi/model/dc_api_global_ran_node_id.h"

#include "global-ran-node-id-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

_DC_WRAPPED_OPENAPI_NODE_SIMPLE_TYPE(global_ran_node_id, global_ran_node_id);

/***** Library function API *****/

/** Create a new GlobalRanNodeId */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_global_ran_node_id_t* data_collection_global_ran_node_id_create()
{
    /* TODO: implement */
    return NULL;
}

/** Destroy a GlobalRanNodeId */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_global_ran_node_id_free(data_collection_global_ran_node_id_t *node_id)
{
    if (!node_id) return;

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(global_ran_node_id, free)(node_id);
}

/***** Library internal functions *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(global_ran_node_id, global_ran_node_id)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
