/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "openapi/model/dc_api_data_access_profile.h"

#include "data-collection-sp/data-collection.h"
#include "data-access-profile-internal.h"

#ifdef __cplusplus
extern "C" {
#endif


/***** Interface callbacks *****/

/***** Interface structures *****/

_DC_WRAPPED_OPENAPI_NODE_SIMPLE_TYPE(data_access_profile, data_access_profile);

/***** Library function API *****/

/** Create a new DataAccessProfile */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_access_profile_t* data_collection_data_access_profile_create(/* TODO: params */)
{
    data_collection_data_access_profile_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_access_profile, create)();

    return ret;
}

/** Destroy a DataAccessProfile */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_access_profile_free(data_collection_data_access_profile_t* profile)
{
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_access_profile, free)(profile);
}

/***** Library internal functions *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(data_access_profile, data_access_profile)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
