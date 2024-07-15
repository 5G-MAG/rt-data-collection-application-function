#ifndef _AF_EVENT_NOTIFICATION_INTERNAL_H_
#define _AF_EVENT_NOTIFICATION_INTERNAL_H_

/**********************************************************************************************************************************
 * AfEventNotification - C internal library interface to the AfEventNotification object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "CollectiveBehaviourInfo.h"
// #include "ServiceExperienceInfoPerApp.h"
// #include "MsConsumptionCollection.h"
// #include "QoEMetricsCollection.h"
// #include "AfEvent.h"
// #include "ConsumptionReportingUnitsCollection.h"
// #include "PerformanceDataCollection.h"
// #include "NetworkAssistanceInvocationsCollection.h"
// #include "UeCommunicationCollection.h"
// #include "DynamicPolicyInvocationsCollection.h"
// #include "DispersionCollection.h"
// #include "ExceptionInfo.h"
// #include "MsQoeMetricsCollection.h"
// #include "UserDataCongestionCollection.h"
// #include "UeMobilityCollection.h"
// #include "GNSSAssistDataInfo.h"
// #include "MediaStreamingAccessesCollection.h"
// #include "MsDynPolicyInvocationCollection.h"
// #include "MsNetAssInvocationCollection.h"
// #include "DatVolTransTimeCollection.h"
// #include "MSAccessActivityCollection.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_af_event_notification_refcount(data_collection_model_af_event_notification_t *AfEventNotification);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _AF_EVENT_NOTIFICATION_INTERNAL_H_ */

