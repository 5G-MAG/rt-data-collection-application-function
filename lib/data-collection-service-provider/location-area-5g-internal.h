/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_LOCATION_AREA_5G_INTERNAL_H
#define DATA_COLLECTION_LOCATION_AREA_5G_INTERNAL_H

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dc_api_location_area5_g_s dc_api_location_area5_g_t;

/** Create LocationArea5G from openapi data type */
data_collection_location_area_5g_t* location_area_5g_from_openapi(dc_api_location_area5_g_t *location /*transfer*/);

/** Create openapi data type from LocationArea5G */
dc_api_location_area5_g_t *location_area_5g_move_openapi(data_collection_location_area_5g_t*);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_LOCATION_AREA_5G_INTERNAL_H */
