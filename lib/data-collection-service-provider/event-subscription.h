/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef EVENT_SUBSCRIPTION_H
#define EVENT_SUBSCRIPTION_H

#include "ogs-proto.h"
#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif


extern data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription_new_from_json_request(char *request_body, const char *mime_type, const char **error_reason, const char **error_parameter, const char **error_code);
extern cJSON *data_collection_af_event_exposure_subscription_json(data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription);
extern char *data_collection_af_events_subscription_get_event_type(data_collection_af_events_subscription_t *events_subs);
extern void data_collection_event_subscription_unsubscribe(data_collection_event_subscription_t *event_subscription);
extern void data_collection_event_subscription_clear(data_collection_event_subscription_t *event_subscription);
extern bool data_collection_remove_expired_event_subscriptions(ogs_hash_t *event_subscriptions);
extern bool data_collection_event_exposure_notification_send_local_event(void *data);
extern bool data_collection_event_subscriptions_process(void *data);
extern void event_notification_timer_activate(data_collection_event_subscription_t *data_collection_event_subscription);
extern bool is_notif_method_periodic(data_collection_event_subscription_t *data_collection_event_subscription);
//extern bool data_collection_event_subscriptions_clear(ogs_hash_t *event_subscription);
extern void data_collection_event_subscription_destroy(data_collection_event_subscription_t *event_subscription);
extern OpenAPI_list_t *application_ids_from_event_filter_get(dc_api_events_subs_t *events_subsc);
extern bool data_collection_set_event_subscription_send_notif(data_collection_event_subscription_t *event_subscription);
extern data_collection_event_subscription_t *data_collection_event_subscription_update(data_collection_event_subscription_t *event_subscription, dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc);
extern void data_collection_remove_af_event_exposure_subscription_notifs(data_collection_event_subscription_t *data_collection_event_subscription);
//extern cJSON *af_event_exposure_subscription_generate_response(const data_collection_af_event_exposure_subscription_t *subscription /* not-null */, const ogs_list_t *af_event_notification_list);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* EVENT_SUBSCRIPTION_H */