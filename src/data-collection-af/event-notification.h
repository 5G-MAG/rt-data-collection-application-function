/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DCAF_EVENT_NOTIF_H 
#define DCAF_EVENT_NOTIF_H 

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <features.h>

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

#include "context.h"
#include "sbi-path.h"
#include "utilities.h"
#include "hash.h"
#include "event-notification.h"
#include "data-collection-sp/data-collection.h"
#include "openapi/model/dcaf_api_communication_collection.h"
#include "openapi/model/dcaf_api_ue_communication_collection.h"
#include "openapi/model/dcaf_api_af_event_notification.h"
#include "openapi/model/dcaf_api_af_event_exposure_notif.h"
#include "openapi/model/dcaf_api_communication_record.h"

/* Local functions */

typedef struct dcaf_api_communication_collection_s dcaf_api_communication_collection_t;

typedef struct dcaf_api_ue_communication_collection_s dcaf_api_ue_communication_collection_t;

typedef struct dcaf_api_af_event_notification_s dcaf_api_af_event_notification_t;

typedef struct dcaf_api_af_event_exposure_notif_s dcaf_api_af_event_exposure_notif_t;

extern ogs_list_t *generate_af_event_notifications(ogs_list_t *data_reports, data_collection_event_subscription_t *data_collection_event_subscription);

#ifdef __cplusplus
}
#endif

#endif /* DCAF_EVENT_NOTIF_H */


/* vim:ts=8:sts=4:sw=4:expandtab:
 */
