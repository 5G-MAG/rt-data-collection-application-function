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
#include "data-sampling-rule-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

/******** Private type definitions ********/

_DC_WRAPPED_OPENAPI_NODE_TYPE_START(data_sampling_rule, data_sampling_rule)
_DC_WRAPPED_OPENAPI_NODE_TYPE_OBJECT(location_area_5g);
_DC_WRAPPED_OPENAPI_NODE_TYPE_END(data_sampling_rule);

/***** Library function API *****/

/** Create a new DataSamplingRule */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_sampling_rule_t* data_collection_data_sampling_rule_create(data_collection_location_area_5g_t *location_filter /*transfer*/, double sampling_period)
{
    data_collection_data_sampling_rule_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_sampling_rule, create)();
    dc_api_location_area5_g_t *location_filter_obj = NULL;

    _DC_WRAPPED_OPENAPI_NODE_INIT_OBJECT(ret, location_area_5g, location_filter, location_filter_obj);
    dc_api_data_sampling_rule_t *openapi = dc_api_data_sampling_rule_create(location_filter_obj,
                                                    sampling_period!=DATA_COLLECTION_SAMPLING_PERIOD_NONE, sampling_period);
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_sampling_rule, set_ref)(ret, _DC_OPENAPI_REF_METHODNAME(data_sampling_rule, create_zero)(openapi));

    return ret;
}

/** Destroy a DataSamplingRule */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_sampling_rule_free(data_collection_data_sampling_rule_t* rule)
{
    if (!rule) return;

    _DC_WRAPPED_OPENAPI_NODE_PREFREE_OBJECT(data_sampling_rule, rule, location_area_5g, location_filter);

    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_sampling_rule, free)(rule);
}

/********* Library internal functions ********/

_DC_WRAPPED_OPENAPI_NODE_BODY(data_sampling_rule, data_sampling_rule)

/******** Private functions ********/



#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
