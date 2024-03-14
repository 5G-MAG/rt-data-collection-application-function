/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_LOCATION_AREA_5G_H
#define DATA_COLLECTION_LOCATION_AREA_5G_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "ogs-core.h"

#include "civic-address.h"
#include "geographic-area.h"
#include "network-area-info.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Constants *****/

/***** Enumerations *****/

/***** Opaque Types *****/

typedef struct data_collection_location_area_5g_s data_collection_location_area_5g_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new LocationArea5G */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_location_area_5g_t*
data_collection_location_area_5g_create(ogs_list_t *civic_addresses /*transfer*/, ogs_list_t *geographic_areas /*transfer*/,
                                        data_collection_network_area_info_t *network_area_info /*transfer*/);

/** Destroy a LocationArea5G */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_location_area_5g_free(data_collection_location_area_5g_t*);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_LOCATION_AREA_5G_H */
