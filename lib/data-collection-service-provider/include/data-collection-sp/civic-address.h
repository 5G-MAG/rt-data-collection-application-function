/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_CIVIC_ADDRESS_H
#define DATA_COLLECTION_CIVIC_ADDRESS_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Constants *****/

/***** Enumerations *****/

/***** Opaque Types *****/

typedef struct data_collection_civic_address_s data_collection_civic_address_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_civic_address_t* data_collection_civic_address_create(const char *country_code);

/** Destroy a CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_civic_address_free(data_collection_civic_address_t*);

#define _DC_CIVIC_ADDRESS_PARAM(name, field, description) \
DATA_COLLECTION_SVC_PRODUCER_API const char *_DC_CONCAT(data_collection_civic_address_get_,name)(const data_collection_civic_address_t *address); \
DATA_COLLECTION_SVC_PRODUCER_API int _DC_CONCAT(data_collection_civic_address_set_,name)(data_collection_civic_address_t *address, const char *name); \

_DC_CIVIC_ADDRESS_PARAM(country_code,country,2 letter country code)
#include "data-collection-sp/civic_address_optional_params.inc"

#undef _DC_CIVIC_ADDRESS_PARAM

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_CIVIC_ADDRESS_H */
