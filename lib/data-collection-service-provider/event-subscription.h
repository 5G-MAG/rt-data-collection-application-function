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

extern bool _event_subscription_set_send_notif(data_collection_event_subscription_t *event_subscription);

extern void _event_subscription_free(data_collection_event_subscription_t *event_subscription);
extern bool _event_exposure_notification_send_local_event(bool expedite);
extern bool _event_subscriptions_process(void *data);
extern void _event_subscription_notification_timer_activate(data_collection_event_subscription_t *event_subscription);
extern void _event_subscription_destroy(data_collection_event_subscription_t *event_subscription);
extern bool _event_subscriptions_remove_expired(ogs_hash_t *event_subscriptions);
extern bool _event_subscriptions_clear(ogs_hash_t *event_subscription);

extern ogs_list_t *application_ids_from_event_filter_get(data_collection_model_events_subs_t *events_subsc);
extern bool _event_subscription_is_notif_method_periodic(const data_collection_event_subscription_t *event_subscription);
extern cJSON *_event_subscription_generate_af_event_notification(data_collection_event_subscription_t *event_subscription);
extern int _event_subscription_send_af_event_exposure_notif(data_collection_event_subscription_t *event_subscription,
                                                            cJSON *af_event_notification);
extern void _event_subscription_add_data_report_used(data_collection_event_subscription_t *event_subscription,
                                                     data_collection_data_report_record_t *report_record);
extern void _event_subscription_remove_data_report_used(data_collection_event_subscription_t *event_subscription,
                                                        data_collection_data_report_record_t *report_record);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* EVENT_SUBSCRIPTION_H */
