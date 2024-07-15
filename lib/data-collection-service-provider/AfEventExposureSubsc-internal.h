#ifndef _AF_EVENT_EXPOSURE_SUBSC_INTERNAL_H_
#define _AF_EVENT_EXPOSURE_SUBSC_INTERNAL_H_

/**********************************************************************************************************************************
 * AfEventExposureSubsc - C internal library interface to the AfEventExposureSubsc object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "ReportingInformation.h"
// #include "AfEventNotification.h"
// #include "EventsSubs.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern cJSON *_model_af_event_exposure_subsc_generate_response(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t *af_events_notifications);
extern cJSON *_model_af_event_exposure_subsc_generate_notification(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t *af_events_notifications);

extern long _model_af_event_exposure_subsc_refcount(data_collection_model_af_event_exposure_subsc_t *AfEventExposureSubsc);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _AF_EVENT_EXPOSURE_SUBSC_INTERNAL_H_ */

