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

#include "openapi/model/dc_api_tai.h"

#include "tracking-area-id-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

_DC_WRAPPED_OPENAPI_NODE_SIMPLE_TYPE(tracking_area_id, tai);

/***** Library function API *****/

/** Create a new Tai */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_tracking_area_id_t* data_collection_tracking_area_id_create()
{
    /* TODO: implement */
    return NULL;
}

/** Destroy a Tai */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_tracking_area_id_free(data_collection_tracking_area_id_t *tai)
{
    if (!tai) return;

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(tracking_area_id, free)(tai);
}

/***** Library internal functions *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(tracking_area_id, tai)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
