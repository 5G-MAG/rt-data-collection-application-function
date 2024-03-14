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

#include "network-area-info-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_network_area_info_s {
    dc_api_network_area_info_t *info;
} data_collection_network_area_info_t;

/***** Library function API *****/

/** Create a new NetworkAreaInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_network_area_info_t* data_collection_network_area_info_create()
{
    /* TODO: implement this properly */
    return NULL;
}

/** Destroy a NetworkAreaInfo */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_network_area_info_free(data_collection_network_area_info_t *info)
{
    if (!info) return;

    if (info->info) {
        dc_api_network_area_info_free(info->info);
        info->info = NULL;
    }

    ogs_free(info);
}

/***** Library internal functions *****/

/** Create NetworkAreaInfo from openapi data type */
data_collection_network_area_info_t* network_area_info_from_openapi(dc_api_network_area_info_t *info)
{
    data_collection_network_area_info_t *ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ret->info = info;

    return ret;
}

/** Remove the openapi data type from NetworkAreaInfo */
dc_api_network_area_info_t *network_area_info_move_openapi(data_collection_network_area_info_t *info)
{
    dc_api_network_area_info_t *ret = NULL;

    if (info) {
        ret = info->info;
        info->info = NULL;
    }

    return ret;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
