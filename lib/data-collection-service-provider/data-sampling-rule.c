/*
 * License: 5G-MAG Public License (v1.0)
 * Author: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "openapi/model/dc_api_data_sampling_rule.h"

#include "location-area-5g-internal.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/******** Private type definitions ********/

typedef struct data_collection_data_sampling_rule_s {
    dc_api_data_sampling_rule_t *profile;
} data_collection_data_sampling_rule_t;

/***** Library function API *****/

/** Create a new DataSamplingRule */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_sampling_rule_t* data_collection_data_sampling_rule_create(data_collection_location_area_5g_t *location_filter /*transfer*/, double sampling_period)
{
    data_collection_data_sampling_rule_t *ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    dc_api_location_area5_g_t *openapi_location_filter = location_area_5g_move_openapi(location_filter);
    data_collection_location_area_5g_free(location_filter);

    ret->profile = dc_api_data_sampling_rule_create(openapi_location_filter, sampling_period!=DATA_COLLECTION_SAMPLING_PERIOD_NONE,
                                                    sampling_period);
    ogs_assert(ret->profile);

    return ret;
}

/** Destroy a DataSamplingRule */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_sampling_rule_free(data_collection_data_sampling_rule_t* profile)
{
    if (!profile) return;

    if (profile->profile) {
        dc_api_data_sampling_rule_free(profile->profile);
        profile->profile = NULL;
    }

    ogs_free(profile);    
}

/********* Library internal functions ********/


/******** Private functions ********/



#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
