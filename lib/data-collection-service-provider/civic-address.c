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
#include "wrap-openapi-macros.h"

#include "openapi/model/dc_api_civic_address.h"

#include "civic-address-internal.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

_DC_WRAPPED_OPENAPI_NODE_SIMPLE_TYPE(civic_address,civic_address);

static bool _is_country_code(const char *country_code);

/***** Library function API *****/

/** Create a new CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_civic_address_t* data_collection_civic_address_create(const char *country_code)
{
    if (!_is_country_code(country_code)) return NULL;

    data_collection_civic_address_t* ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address, create)();

    dc_api_civic_address_t *address = dc_api_civic_address_create(
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
    ogs_assert(address);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(civic_address, create_zero)(address));

    return ret;
}

/** Destroy a CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_civic_address_free(data_collection_civic_address_t *address)
{
    if (!address) return;

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address, free)(address);
}

/** Get the Country Code */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_civic_address_get_country_code(const data_collection_civic_address_t *address)
{
    if (!address) return NULL;
    return _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address,const_openapi)(address)->country;
}

/** Change the Country Code
 * mandatory field cannot be NULL */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_civic_address_set_country_code(data_collection_civic_address_t *address, const char *country_code)
{
    if (!address) {
        ogs_error("Attempt to set country code on NULL Civic Address");
        return OGS_ERROR;
    }

    if (!_is_country_code(country_code)) {
        ogs_error("CivicAddress country code has to be 2 uppercase letters");
        return OGS_ERROR;
    }

    dc_api_civic_address_t *ca = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address,openapi)(address);
    if (!ca) {
        ogs_error("Attempt to set country code on empty Civic Address");
        return OGS_ERROR;
    }

    if (ca->country) ogs_free(ca->country);
    ca->country = data_collection_strdup(country_code);
    ogs_assert(ca->country);

    return OGS_OK;
}

#define _DC_CIVIC_ADDRESS_PARAM(name, field, description) \
DATA_COLLECTION_SVC_PRODUCER_API const char *_DC_CONCAT(data_collection_civic_address_get_,name)(const data_collection_civic_address_t *address) \
{ \
    /* Get description */ \
    if (!address) return NULL; \
 \
    const dc_api_civic_address_t *ca = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address,const_openapi)(address); \
    if (!ca) return NULL; \
 \
    return ca->field; \
} \
DATA_COLLECTION_SVC_PRODUCER_API int _DC_CONCAT(data_collection_civic_address_set_,name)(data_collection_civic_address_t *address, const char *name) \
{ \
    /* Set description */ \
    if (!address) { \
        ogs_error("Attempt to set " _DC_STRING(field) " on NULL Civic Address"); \
        return OGS_ERROR; \
    } \
 \
    dc_api_civic_address_t *ca = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address,openapi)(address); \
    if (!ca) { \
        ogs_error("Attempt to set " _DC_STRING(field) " on empty Civic Address"); \
        return OGS_ERROR; \
    } \
 \
    if (ca->field) ogs_free(ca->field); \
    ca->field = data_collection_strdup(name); \
    ogs_assert(ca->field); \
 \
    return OGS_OK; \
}

#include "data-collection-sp/civic_address_optional_params.inc"

#undef _DC_CIVIC_ADDRESS_PARAM

/***** Library internal functions *****/

/* Add Refcount object methods for dc_api_civic_address_t */
_DC_WRAPPED_OPENAPI_NODE_BODY(civic_address,civic_address)

/** Create CivicAddress from openapi data type */
data_collection_civic_address_t* civic_address_from_openapi(dc_api_civic_address_t *address)
{
    data_collection_civic_address_t* ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address, create)();

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(civic_address, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(civic_address, create_zero)(address));

    return ret;
}

/***** Private functions *****/

/** Check country code */
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
