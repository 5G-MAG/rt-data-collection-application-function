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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_data_access_profile_s {
    dc_api_data_access_profile_t *profile;
} data_collection_data_access_profile_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new DataAccessProfile */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_access_profile_t* data_collection_data_access_profile_create()
{
    data_collection_data_access_profile_t *ret = ogs_calloc(1, sizeof(*ret));

    /* ret->profile = dc_api_data_access_profile_create(); */

    ogs_assert(ret);

    return ret;
}

/** Destroy a DataAccessProfile */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_access_profile_free(data_collection_data_access_profile_t* profile)
{
    if (!profile) return;

    if (profile->profile) {
        dc_api_data_access_profile_free(profile->profile);
        profile->profile = NULL;
    }

    ogs_free(profile);    
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
