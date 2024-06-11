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
extern bool data_collection_event_subscriptions_clear(ogs_hash_t *event_subscription);
extern void data_collection_event_subscription_destroy(data_collection_event_subscription_t *event_subscription);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* EVENT_SUBSCRIPTION_H */
