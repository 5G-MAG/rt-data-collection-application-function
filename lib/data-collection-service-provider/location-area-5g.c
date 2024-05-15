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

_DC_WRAPPED_OPENAPI_NODE_TYPE_START(location_area_5g, location_area5_g)
_DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT_LIST(civic_address);
_DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT_LIST(geographic_area);
_DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT(network_area_info);
_DC_WRAPPED_OPENAPI_NODE_TYPE_END(location_area_5g);

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new LocationArea5G */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_location_area_5g_t*
data_collection_location_area_5g_create(ogs_list_t *civic_addresses /*transfer*/, ogs_list_t *geographic_areas /*transfer*/,
                                        data_collection_network_area_info_t *network_area_info /*transfer*/)
{
    data_collection_location_area_5g_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(location_area_5g, create)();

    OpenAPI_list_t *civic_addresses_openapi = NULL;
    OpenAPI_list_t *geographic_areas_openapi = NULL;
    dc_api_network_area_info_t *network_area_info_obj = NULL;

    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT_LIST(ret, civic_address, civic_addresses, civic_addresses_openapi);
    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT_LIST(ret, geographic_area, geographic_areas, geographic_areas_openapi);
    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT(ret, network_area_info, network_area_info, network_area_info_obj);

    dc_api_location_area5_g_t *location = dc_api_location_area5_g_create(civic_addresses_openapi, geographic_areas_openapi, network_area_info_obj);
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(location_area_5g, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(location_area_5g, create_zero)(location));

    return ret;
}

/** Destroy a LocationArea5G */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_location_area_5g_free(data_collection_location_area_5g_t* location)
{
    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT_LIST(location_area_5g, location_area5_g, location, civic_address, civic_address, civic_addresses);
    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT_LIST(location_area_5g, location_area5_g, location, geographic_area, geographic_area, geographic_areas);
    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT(location_area_5g, location, network_area_info, nw_area_info);
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(location_area_5g, free)(location);
}

/******** Internal library functions ********/

/** Create LocationArea5G from openapi data type */
data_collection_location_area_5g_t* location_area_5g_from_openapi(dc_api_location_area5_g_t *location)
{
    data_collection_location_area_5g_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(location_area_5g, create)();

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(location_area_5g, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(location_area_5g, create_zero)(location));

    return ret;
}

_DC_WRAPPED_OPENAPI_NODE_BODY(location_area_5g, location_area5_g)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
