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
#include "data-reporting-condition-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

_DC_WRAPPED_OPENAPI_NODE_SIMPLE_TYPE(data_reporting_condition, data_reporting_condition);

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new DataReportingCondition */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_reporting_condition_t* data_collection_data_reporting_condition_create()
{
    data_collection_data_reporting_condition_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_reporting_condition, create)();

    return ret;
}

/** Destroy a DataReportingCondition */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_reporting_condition_free(data_collection_data_reporting_condition_t* condition)
{
    if (!condition) return;
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_reporting_condition, free)(condition);
}

/***** Library internal functions *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(data_reporting_condition, data_reporting_condition)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
