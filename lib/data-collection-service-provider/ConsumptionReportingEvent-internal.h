#ifndef _CONSUMPTION_REPORTING_EVENT_INTERNAL_H_
#define _CONSUMPTION_REPORTING_EVENT_INTERNAL_H_

/**********************************************************************************************************************************
 * ConsumptionReportingEvent - C internal library interface to the ConsumptionReportingEvent object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "EventRecordType.h"
// #include "LocationArea5G.h"
// #include "Snssai.h"
// #include "EndpointAddress.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_consumption_reporting_event_refcount(data_collection_model_consumption_reporting_event_t *ConsumptionReportingEvent);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _CONSUMPTION_REPORTING_EVENT_INTERNAL_H_ */

