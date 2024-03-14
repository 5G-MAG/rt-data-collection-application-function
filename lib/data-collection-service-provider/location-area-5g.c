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

#include "openapi/model/dc_api_location_area5_g.h"

#include "civic-address-internal.h"
#include "geographic-area-internal.h"
#include "network-area-info-internal.h"

#include "location-area-5g-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_location_area_5g_s {
    dc_api_location_area5_g_t *location;
} data_collection_location_area_5g_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new LocationArea5G */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_location_area_5g_t*
data_collection_location_area_5g_create(ogs_list_t *civic_addresses /*transfer*/, ogs_list_t *geographic_areas /*transfer*/,
                                        data_collection_network_area_info_t *network_area_info /*transfer*/)
{
    data_collection_location_area_5g_t *ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    OpenAPI_list_t *civic_addresses_openapi = NULL;
    OpenAPI_list_t *geographic_areas_openapi = NULL;
    dc_api_network_area_info_t *network_area_info_openapi = NULL;

    if (civic_addresses) {
        data_collection_civic_address_t *next, *node;
        civic_addresses_openapi = ogs_calloc(1,sizeof(*civic_addresses_openapi));
        ogs_list_for_each_safe(civic_addresses, next, node) {
            dc_api_civic_address_t *ca = civic_address_move_openapi(node);
            ogs_list_remove(civic_addresses, node);
            data_collection_civic_address_free(node);
            OpenAPI_list_add(civic_addresses_openapi, ca);
        }
        ogs_free(civic_addresses);
    }

    if (geographic_areas) {
        data_collection_geographic_area_t *next, *node;
        geographic_areas_openapi = ogs_calloc(1,sizeof(*geographic_areas_openapi));
        ogs_list_for_each_safe(geographic_areas, next, node) {
            dc_api_geographic_area_t *ga = geographic_area_move_openapi(node);
            ogs_list_remove(geographic_areas, node);
            data_collection_geographic_area_free(node);
            OpenAPI_list_add(geographic_areas_openapi, ga);
        }
        ogs_free(geographic_areas);
    }

    if (network_area_info) {
        network_area_info_openapi = network_area_info_move_openapi(network_area_info);
    }

    ret->location = dc_api_location_area5_g_create(civic_addresses_openapi, geographic_areas_openapi, network_area_info_openapi);

    return ret;
}

/** Destroy a LocationArea5G */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_location_area_5g_free(data_collection_location_area_5g_t* location)
{
    if (!location) return;

    if (location->location) dc_api_location_area5_g_free(location->location);

    ogs_free(location);
}

/******** Internal library functions ********/

/** Create LocationArea5G from openapi data type */
data_collection_location_area_5g_t* location_area_5g_from_openapi(dc_api_location_area5_g_t *location)
{
    data_collection_location_area_5g_t *ret = ogs_calloc(1, sizeof(*ret));

    ret->location = location;

    return ret;
}

/** Remove and return the openapi data type from a LocationArea5G */
dc_api_location_area5_g_t *location_area_5g_move_openapi(data_collection_location_area_5g_t *location)
{
    dc_api_location_area5_g_t *ret = NULL;

    if (location) {
        ret = location->location;
        location->location = NULL;
    }

    return ret;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
