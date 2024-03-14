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

#include "openapi/model/dc_api_data_reporting_condition.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_data_reporting_condition_s {
    dc_api_data_reporting_condition_t *profile;
} data_collection_data_reporting_condition_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new DataReportingCondition */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_reporting_condition_t* data_collection_data_reporting_condition_create()
{
    data_collection_data_reporting_condition_t *ret = ogs_calloc(1, sizeof(*ret));

    /* ret->profile = dc_api_data_reporting_condition_create(); */

    ogs_assert(ret);

    return ret;
}

/** Destroy a DataReportingCondition */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_reporting_condition_free(data_collection_data_reporting_condition_t* profile)
{
    if (!profile) return;

    if (profile->profile) {
        dc_api_data_reporting_condition_free(profile->profile);
        profile->profile = NULL;
    }

    ogs_free(profile);    
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */