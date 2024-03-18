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

#include "utilities.h"

#include "openapi/model/dc_api_civic_address.h"

#include "civic-address-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_civic_address_s {
    dc_api_civic_address_t *address;
} data_collection_civic_address_t;

static bool _is_country_code(const char *country_code);

/***** Library function API *****/

/** Create a new CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_civic_address_t* data_collection_civic_address_create(const char *country_code)
{
    data_collection_civic_address_t *ret;

    if (!_is_country_code(country_code)) return NULL;

    ret = ogs_malloc(sizeof(*ret));
    ogs_assert(ret);

    ret->address = dc_api_civic_address_create(
            NULL /*a1*/,
            NULL /*a2*/,
            NULL /*a3*/,
            NULL /*a4*/,
            NULL /*a5*/,
            NULL /*a6*/,
            NULL /*addcode*/,
            NULL /*bld*/,
            NULL /*flr*/,
            NULL /*hno*/,
            NULL /*hns*/,
            NULL /*lmk*/,
            NULL /*loc*/,
            NULL /*nam*/,
            NULL /*pc*/,
            NULL /*pcn*/,
            NULL /*plc*/,
            NULL /*pobox*/,
            NULL /*pod*/,
            NULL /*pom*/,
            NULL /*prd*/,
            NULL /*prm*/,
            NULL /*rd*/,
            NULL /*rdbr*/,
            NULL /*rdsec*/,
            NULL /*rdsubbr*/,
            NULL /*room*/,
            NULL /*seat*/,
            NULL /*sts*/,
            NULL /*unit*/,
            data_collection_strdup(country_code) /*country*/,
            NULL /*method*/,
            NULL /*provided_by*/,
            NULL /*usage_rules*/
            );

    return ret;
}

/** Destroy a CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_civic_address_free(data_collection_civic_address_t *address)
{
    if (!address) return;

    if (address->address) dc_api_civic_address_free(address->address);

    ogs_free(address);
}

/** Get the Country Code */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_civic_address_get_country_code(data_collection_civic_address_t *address)
{
    if (!address || !address->address) return NULL;
    return address->address->country;
}

/** Change the Country Code
 * mandatory field cannot be NULL */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_civic_address_set_country_code(data_collection_civic_address_t *address, const char *country_code)
{
    if (!address || !address->address) {
        ogs_error("Attempt to set country code on NULL or empty Civic Address");
        return OGS_ERROR;
    }

    if (!_is_country_code(country_code)) {
        ogs_error("CivicAddress country code has to be 2 uppercase letters");
        return OGS_ERROR;
    }

    if (address->address->country) ogs_free(address->address->country);
    address->address->country = data_collection_strdup(country_code);
    ogs_assert(address->address->country);

    return OGS_OK;
}

#define _DC_CONCAT(a,b) a##b
#define _DC_CIVIC_ADDRESS_PARAM(name, field, description) \
DATA_COLLECTION_SVC_PRODUCER_API const char *_DC_CONCAT(data_collection_civic_address_get_,name)(data_collection_civic_address_t *address) \
{ \
    /* Get description */ \
    if (!address || !address->address) return NULL; \
    return address->address->field; \
} \
DATA_COLLECTION_SVC_PRODUCER_API int _DC_CONCAT(data_collection_civic_address_set_,name)(data_collection_civic_address_t *address, const char *name) \
{ \
    /* Set description */ \
    if (!address || !address->address) return OGS_ERROR; \
    if (address->address->field) ogs_free(address->address->field); \
    address->address->field = data_collection_strdup(name); \
    ogs_assert(address->address->field); \
    return OGS_OK; \
}

#include "data-collection-sp/civic_address_optional_params.inc"

#undef _DC_CIVIC_ADDRESS_PARAM
#undef _DC_CONCAT

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

/***** Private functions *****/
static bool _is_country_code(const char *country_code)
{
    if (!country_code) {
        ogs_error("CivicAddress country code is mandatory, it cannot be NULL");
        return false;
    }
    if (country_code[0] < 'A' || country_code[0] > 'Z' ||
        country_code[1] < 'A' || country_code[1] > 'Z' ||
        country_code[2] != 0) {
        ogs_error("CivicAddress country code has to be 2 uppercase letters");
        return false;
    }
    return true;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
