/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_GEOGRAPHIC_AREA_INTERNAL_H
#define DATA_COLLECTION_GEOGRAPHIC_AREA_INTERNAL_H

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dc_api_geographic_area_s dc_api_geographic_area_t;

/** Create GeographicArea from openapi data type */
data_collection_geographic_area_t* geographic_area_from_openapi(dc_api_geographic_area_t *location);

/** Remove the openapi data type from GeographicArea */
dc_api_geographic_area_t *geographic_area_move_openapi(data_collection_geographic_area_t*);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_GEOGRAPHIC_AREA_INTERNAL_H */
