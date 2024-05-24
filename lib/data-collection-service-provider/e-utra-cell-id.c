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

#include "openapi/model/dc_api_ecgi.h"

#include "e-utra-cell-id-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

_DC_WRAPPED_OPENAPI_NODE_SIMPLE_TYPE(e_utra_cell_id, ecgi);

/***** Library function API *****/

/** Create a new Ecgi */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_e_utra_cell_id_t* data_collection_e_utra_cell_id_create()
{
    /* TODO: implement this */
    return NULL;
}

/** Destroy a Ecgi */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_e_utra_cell_id_free(data_collection_e_utra_cell_id_t *cell_id)
{
    if (!cell_id) return;

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(e_utra_cell_id, free)(cell_id);
}

/***** Library internal functions *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(e_utra_cell_id, ecgi)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */