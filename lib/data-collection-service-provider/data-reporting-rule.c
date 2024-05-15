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

#include "openapi/model/dc_api_data_reporting_rule.h"

#include "data-collection-sp/data-collection.h"
#include "data-reporting-rule-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Interface callbacks *****/

/***** Interface structures *****/

_DC_WRAPPED_OPENAPI_NODE_TYPE_START(data_reporting_rule, data_reporting_rule)
_DC_WRAPPED_OPENAPI_NODE_TYPE_END(data_reporting_rule);

/***** Library function API *****/

/** Create a new DataReportingRule */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_reporting_rule_t* data_collection_data_reporting_rule_create(/* TODO: */)
{
    data_collection_data_reporting_rule_t *ret = _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_reporting_rule,create)();

    ogs_assert(ret);

    return ret;
}

/** Destroy a DataReportingRule */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_reporting_rule_free(data_collection_data_reporting_rule_t* rule)
{
    _DC_WRAPPED_OPENAPI_NODE_METHODNAME(data_reporting_rule,free)(rule);
}

/***** Library internal functions *****/

_DC_WRAPPED_OPENAPI_NODE_BODY(data_reporting_rule, data_reporting_rule)

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
