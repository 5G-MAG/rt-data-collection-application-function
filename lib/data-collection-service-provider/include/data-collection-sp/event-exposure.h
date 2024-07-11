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

#ifndef DATA_COLLECTION_EVENT_EXPOSURE_H
#define DATA_COLLECTION_EVENT_EXPOSURE_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "ogs-core.h"
#include "ogs-sbi.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/** Event Exposure supported feature bit masks
 *
 * The feature numbers come from TS 29.517 v18.4.0 Table 5.8-1
 */
typedef enum {
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE=DATA_COLLECTION_FEATURE_BIT(1),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_MOBILITY=DATA_COLLECTION_FEATURE_BIT(2),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION=DATA_COLLECTION_FEATURE_BIT(3),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_EXCEPTIONS=DATA_COLLECTION_FEATURE_BIT(4),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ES3XX=DATA_COLLECTION_FEATURE_BIT(5),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENHANCED_NA=DATA_COLLECTION_FEATURE_BIT(6),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_USER_DATA_CONGESTION=DATA_COLLECTION_FEATURE_BIT(7),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_PERFORMANCE_DATA=DATA_COLLECTION_FEATURE_BIT(8),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DISPERSION=DATA_COLLECTION_FEATURE_BIT(9),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_COLLECTIVE_BEHAVIOUR=DATA_COLLECTION_FEATURE_BIT(10),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE_EXT=DATA_COLLECTION_FEATURE_BIT(11),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_QOE_METRICS=DATA_COLLECTION_FEATURE_BIT(12),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_CONSUMPTION=DATA_COLLECTION_FEATURE_BIT(13),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_NET_ASSIST_INVOCN=DATA_COLLECTION_FEATURE_BIT(14),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_DYN_POLICY_INVOCN=DATA_COLLECTION_FEATURE_BIT(15),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_ACCESS_ACTIVITY=DATA_COLLECTION_FEATURE_BIT(16),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DATA_ACCESS_PROFILE_ID=DATA_COLLECTION_FEATURE_BIT(17),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ALL_APPLICATIONS=DATA_COLLECTION_FEATURE_BIT(18),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_GNSS_ASSIST_DATA=DATA_COLLECTION_FEATURE_BIT(19),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_PERFORMANCE_DATA_AIML=DATA_COLLECTION_FEATURE_BIT(20),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_MOBILITY_AIML=DATA_COLLECTION_FEATURE_BIT(21),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENH_PERFORMANCE_DATA=DATA_COLLECTION_FEATURE_BIT(22),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION_ENA=DATA_COLLECTION_FEATURE_BIT(23),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE_ENA=DATA_COLLECTION_FEATURE_BIT(24),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENH_DATA_MANAGEMENT=DATA_COLLECTION_FEATURE_BIT(25),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_EXTENDED_EVENT_FILTERS=DATA_COLLECTION_FEATURE_BIT(26),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DATA_VOL_TRANSFER_TIME=DATA_COLLECTION_FEATURE_BIT(27),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_EVENT_EXPOSURE=DATA_COLLECTION_FEATURE_BIT(28)
} data_collection_supported_features_event_e;

/***** Opaque Types *****/

/** Event Subscription
 *
 * Use data_collection_event_subscription_*() functions to access this type.
 */

typedef struct dc_api_events_subs_s dc_api_events_subs_t;
typedef struct dc_api_af_event_exposure_subsc_s dc_api_af_event_exposure_subsc_t;
typedef struct dc_api_event_filter_s dc_api_event_filter_t;
typedef struct data_collection_event_subscription_s data_collection_event_subscription_t;
typedef struct data_collection_af_event_exposure_subscription_s data_collection_af_event_exposure_subscription_t;
typedef struct data_collection_af_events_subscription_s data_collection_af_events_subscription_t;

/***** Interface callbacks *****/

/** Callback to generate events using the given subscription as a filter */
typedef ogs_list_t* (*data_collection_event_generation_cb)(data_collection_event_subscription_t *);

/***** Interface structures *****/

/** Event
 *
 * Event to be exposed to a client which has subscribed via the EventExposure API
 */
typedef struct data_collection_data_event_s {
    const char *event_type;            /** See TS 29.517 Table 5.6.3.3-1 for standard event types */
    struct timespec timestamp;         /** nano-second accurate UTC time when the event was observed */
    const char *event_attribute_name;  /** Attribute name to report the event data with */
    cJSON *event_data;                 /** event data as a JSON object/array */
} data_collection_data_event_t;

/***** Library function API *****/

/* DATA_COLLECTION_SVC_PRODUCER_API {fn-prototype} */
data_collection_event_subscription_t *data_collection_event_subscription_subscribe(data_collection_af_event_exposure_subscription_t *subscription, const char **error_return, const char **error_parameter /* output */);

void data_collection_event_subscription_unsubscribe(data_collection_event_subscription_t *event_subscription);

extern data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription_from_json_request(cJSON *json /* not-null */, const char **error_return /* output */, const char **error_parameter /* output */);

int data_collection_af_event_exposure_subscription_num_events_subs(const data_collection_af_event_exposure_subscription_t *subscription /* not-null */);

extern data_collection_af_event_exposure_subscription_t *data_collection_event_subscription_get_af_event_exposure_subscription(data_collection_event_subscription_t *event_subscription /* not-null */);
extern data_collection_af_events_subscription_t *data_collection_af_event_exposure_subscription_get_events_subs(data_collection_af_event_exposure_subscription_t *subscription /* not-null */, size_t index);

extern dc_api_events_subs_t *data_collection_af_event_exposure_subscription_get_events_subsc(data_collection_af_event_exposure_subscription_t *subscription /* not-null */, size_t index);

char *data_collection_af_events_exposure_subscription_get_event_type(dc_api_events_subs_t *events_subsc);

/**Find an event subscription by the {subscriptionId} */
data_collection_event_subscription_t *data_collection_event_subscription_find_by_id(const char *subscription_id /* not-null */);


/** Get the AF Event Exposure Subscription for the event subscription context*/
data_collection_af_event_exposure_subscription_t *data_collection_event_subscription_get_af_event_exposure_subscription(data_collection_event_subscription_t *event_subscription /* not-null */);

/** Get the AF Event Exposure Subscription for the event subscription context (const version) */
const data_collection_af_event_exposure_subscription_t *data_collection_event_subscription_get_af_event_exposure_subscription_const(const data_collection_event_subscription_t *event_subscription /* not-null */);

/** Set the AF Event Exposure Subscription for the event subscription context */
bool data_collection_event_subscription_set_af_event_exposure_subscription_const(data_collection_event_subscription_t *event_subscription /* not-null */, data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription /* not-null, transfer */);

/** Get the event subscription id */
char *data_collection_event_subscription_get_id(data_collection_event_subscription_t *event_subscription);


/** Get the Event Exposure Subscription last used date-time */
ogs_time_t data_collection_event_exposure_subscription_last_used(data_collection_event_subscription_t *event_subscription);

/** Get the Event Exposure Subscription entity instance tag */
char *data_collection_event_exposure_subscription_etag(data_collection_event_subscription_t *event_subscription);

/** Get the Event Filter */
dc_api_event_filter_t *data_collection_event_exposure_subscription_get_filter(data_collection_af_events_subscription_t *events_subscription);

/** Generate AfEventNotification for AfEventExposureSubsc response */
cJSON *data_collection_generate_af_event_notification_for_subscription(data_collection_event_subscription_t *data_collection_event_subscription);

cJSON *data_collection_generate_af_event_notification(data_collection_event_subscription_t *data_collection_event_subscription);

int data_collection_send_af_event_exposure_notif(data_collection_event_subscription_t *data_collection_event_subscription, cJSON *af_event_notification);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_EVENT_EXPOSURE_H */
