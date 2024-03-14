/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_CIVIC_ADDRESS_INTERNAL_H
#define DATA_COLLECTION_CIVIC_ADDRESS_INTERNAL_H

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dc_api_civic_address_s dc_api_civic_address_t;

/** Create CivicAddress from openapi data type */
data_collection_civic_address_t* civic_address_from_openapi(dc_api_civic_address_t *address);

/** Remove the openapi data type from CivicAddress */
dc_api_civic_address_t *civic_address_move_openapi(data_collection_civic_address_t*);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_CIVIC_ADDRESS_INTERNAL_H */
