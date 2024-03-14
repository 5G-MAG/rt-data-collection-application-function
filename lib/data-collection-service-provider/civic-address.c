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

#include "openapi/model/dc_api_civic_address.h"

#include "civic-address-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_civic_address_s {
    dc_api_civic_address_t *address;
} data_collection_civic_address_t;

/***** Library function API *****/

/** Create a new CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_civic_address_t* data_collection_civic_address_create()
{
    /* TODO: implement this properly */
    return NULL;
}

/** Destroy a CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_civic_address_free(data_collection_civic_address_t *address)
{
    if (!address) return;

    ogs_free(address);
}

/***** Library internal functions *****/

/** Create CivicAddress from openapi data type */
data_collection_civic_address_t* civic_address_from_openapi(dc_api_civic_address_t *address)
{
    data_collection_civic_address_t *ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ret->address = address;

    return ret;
}

/** Remove the openapi data type from CivicAddress */
dc_api_civic_address_t *civic_address_move_openapi(data_collection_civic_address_t *address)
{
    dc_api_civic_address_t *ret = NULL;

    if (address) {
        ret = address->address;
        address->address = NULL;
    }

    return ret;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
