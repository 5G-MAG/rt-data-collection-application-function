/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "data-collection-sp/data-collection.h"
#include "AfEventExposureSubsc-internal.h"
#include "context.h"
#include "hash.h"
#include "event.h"
#include "timer.h"
#include "utilities.h"
#include "event-subscription.h"

#ifdef __cplusplus
extern "C" {
#endif

/******** Private Data Structures ********/

typedef struct data_collection_event_subscription_s {
    ogs_lnode_t node;
    char *subscription_id;
    ogs_time_t received;
    ogs_time_t last_used;
    char *hash;
    ogs_sbi_client_t  *client;
    data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subscription;
    const struct data_collection_event_subscription_s *original_event_subscription;
    ogs_timer_t *event_notification_timer;
    bool send_notif;
} data_collection_event_subscription_t;

/********* Private function prototypes **********/

static char *__calculate_event_exposure_subscription_hash(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);
static ogs_sbi_client_t *__event_consumer_client_init(const char *notification_uri);
static int __client_notify_cb(int status, ogs_sbi_response_t *response, void *data);
static void __event_subscription_process_notif_method(data_collection_event_subscription_t *event_subscription);

/******** Public Library API functions ********/

DATA_COLLECTION_SVC_PRODUCER_API data_collection_event_subscription_t *data_collection_event_subscription_subscribe(
            data_collection_model_af_event_exposure_subsc_t *subscription /* not-null, transfer */,
            char **error_return /* output, transfer */,
            char **error_classname /* output, transfer */,
            char **error_parameter /* output, transfer */)
{
    ogs_assert(subscription);

    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];
    data_collection_event_subscription_t *data_collection_event_subscription;
    const char *notif_uri;

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    if (error_return) *error_return = NULL;
    if (error_classname) *error_classname = NULL;
    if (error_parameter) *error_parameter = NULL;

    data_collection_event_subscription = ogs_calloc(1, sizeof(data_collection_event_subscription_t));
    ogs_assert(data_collection_event_subscription);

    data_collection_event_subscription->subscription_id = data_collection_strdup(id);

    data_collection_event_subscription->received = ogs_time_now();
    data_collection_event_subscription->last_used = data_collection_event_subscription->received;
    data_collection_event_subscription->af_event_exposure_subscription = subscription;

    data_collection_event_subscription->hash = __calculate_event_exposure_subscription_hash(subscription);

    notif_uri = data_collection_model_af_event_exposure_subsc_get_notif_uri(subscription);
    if (!data_collection_event_subscription->client && notif_uri && strlen(notif_uri)) {
        data_collection_event_subscription->client = __event_consumer_client_init(notif_uri);
        ogs_assert(data_collection_event_subscription->client);
    }

    data_collection_event_subscription->send_notif = false;
    data_collection_event_subscription->original_event_subscription = NULL;

    __event_subscription_process_notif_method(data_collection_event_subscription);

    ogs_hash_set(data_collection_self()->event_subscriptions, data_collection_event_subscription->subscription_id, OGS_HASH_KEY_STRING, data_collection_event_subscription);

    return data_collection_event_subscription;
}

data_collection_event_subscription_t *data_collection_event_subscription_update(data_collection_event_subscription_t *event_subscription, data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc) {
    const char *notif_uri;

    event_subscription->received = ogs_time_now();
    event_subscription->last_used = event_subscription->received;

    if (event_subscription->client) {
        ogs_sbi_client_remove(event_subscription->client);
        event_subscription->client = NULL;
    }

    if (event_subscription->af_event_exposure_subscription) {
        data_collection_model_af_event_exposure_subsc_move(event_subscription->af_event_exposure_subscription, af_event_exposure_subsc);
        data_collection_model_af_event_exposure_subsc_free(af_event_exposure_subsc);
    } else {
        event_subscription->af_event_exposure_subscription = af_event_exposure_subsc;
    }

    if (event_subscription->hash) ogs_free(event_subscription->hash);
    event_subscription->hash = __calculate_event_exposure_subscription_hash(event_subscription->af_event_exposure_subscription);

    notif_uri = data_collection_model_af_event_exposure_subsc_get_notif_uri(event_subscription->af_event_exposure_subscription);
    if (notif_uri) {
        event_subscription->client = __event_consumer_client_init(notif_uri);
        ogs_assert(event_subscription->client);
    }

    event_subscription->send_notif = false;

    __event_subscription_process_notif_method(event_subscription);

    return event_subscription;	
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_event_subscription_unsubscribe(data_collection_event_subscription_t *event_subscription)
{
    ogs_assert(event_subscription);

    ogs_hash_set(data_collection_self()->event_subscriptions, event_subscription->subscription_id, OGS_HASH_KEY_STRING, NULL);

    _event_subscription_free(event_subscription);
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_event_subscription_t *data_collection_event_subscription_set_original_event_subscription(data_collection_event_subscription_t *event_subscription, const data_collection_event_subscription_t *event_subscription_original /* not-null */)
{
    if (!event_subscription || !event_subscription_original) return NULL;
    event_subscription->original_event_subscription = event_subscription_original;
    return event_subscription;   

}

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_event_subscription_t *data_collection_event_subscription_get_original_event_subscription(const data_collection_event_subscription_t *event_subscription /* not-null */)
{
    if (!event_subscription) return NULL;
    return event_subscription->original_event_subscription;
}


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_exposure_subsc_t *data_collection_event_subscription_get_af_event_exposure_subsc(const data_collection_event_subscription_t *event_subscription /* not-null */)
{
    if (!event_subscription || !event_subscription->af_event_exposure_subscription) return NULL;
    return event_subscription->af_event_exposure_subscription;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_event_subscription_t *
data_collection_event_subscription_find_by_id(const char *subscription_id /* not-null */)
{
    data_collection_event_subscription_t *event_subscription = NULL;

    if (!subscription_id) return NULL;

    event_subscription =
        (data_collection_event_subscription_t*)ogs_hash_get(data_collection_self()->event_subscriptions, subscription_id,
                                                            OGS_HASH_KEY_STRING);
    return event_subscription;
}

DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_event_subscription_set_af_event_exposure_subsc(
                        data_collection_event_subscription_t *event_subscription /* not-null */,
                        data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subscription /* not-null, transfer */)
{

    if (!event_subscription) return false;
    if (event_subscription->af_event_exposure_subscription) {
        data_collection_model_af_event_exposure_subsc_free(event_subscription->af_event_exposure_subscription);
    }

    event_subscription->af_event_exposure_subscription = af_event_exposure_subscription;
    return true;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_event_subscription_get_id(const data_collection_event_subscription_t *event_subscription)
{
    if (!event_subscription || !event_subscription->subscription_id) return NULL;
    return event_subscription->subscription_id;
}

DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_event_subscription_get_imm_rep_flag(const data_collection_event_subscription_t *event_subscription)
{

    if (!event_subscription || !event_subscription->af_event_exposure_subscription) return false;

    const data_collection_model_reporting_information_t *rep_info =
            data_collection_model_af_event_exposure_subsc_get_events_rep_info(event_subscription->af_event_exposure_subscription);

    return (rep_info && data_collection_model_reporting_information_is_imm_rep(rep_info));
}

DATA_COLLECTION_SVC_PRODUCER_API cJSON *
data_collection_event_subscription_generate_af_event_exposure_subsc(data_collection_event_subscription_t *event_subscription)
{
    cJSON *response_json = NULL;
    ogs_list_t *af_events_notifications = NULL;

    if (event_subscription && event_subscription->af_event_exposure_subscription) {
        if (data_collection_event_subscription_get_imm_rep_flag(event_subscription)) {
            af_events_notifications =
                    data_collection_self()->config.data_collection_configuration->event_generation_callback(event_subscription);
        }

        response_json = _model_af_event_exposure_subsc_generate_response(event_subscription->af_event_exposure_subscription,
                                                                         af_events_notifications);

        if (af_events_notifications) data_collection_list_free(af_events_notifications);
    }

    return response_json;
}

DATA_COLLECTION_SVC_PRODUCER_API void
data_collection_event_subscription_generate_af_event_notifications(data_collection_event_subscription_t *event_subscription)
{
    cJSON *body_json = NULL;
    ogs_list_t *af_events_notifications = NULL;

    if (!event_subscription || !event_subscription->af_event_exposure_subscription) return;

    af_events_notifications =
            data_collection_self()->config.data_collection_configuration->event_generation_callback(event_subscription);

    if (af_events_notifications) {
        /* Generate JSON notification */
        body_json = _model_af_event_exposure_subsc_generate_notification(event_subscription->af_event_exposure_subscription,
                                                                         af_events_notifications);

        /* send notification */
        _event_subscription_send_af_event_exposure_notif(event_subscription, body_json);

        /* Tidy up */
        data_collection_list_free(af_events_notifications);
        cJSON_Delete(body_json);
    }
}

DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_event_subscription_get_last_modified(const data_collection_event_subscription_t *event_subscription)
{
    if(!event_subscription) return 0;
    return event_subscription->received;
}

DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_event_subscription_get_last_used(const data_collection_event_subscription_t *event_subscription)
{
    if(!event_subscription) return 0;
    return event_subscription->last_used;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_event_subscription_get_etag(const data_collection_event_subscription_t *event_subscription)
{
    if(!event_subscription) return NULL;
    return event_subscription->hash;
}

/******** Internal library functions **********/

void _event_subscription_free(data_collection_event_subscription_t *event_subscription)
{
    ogs_assert(event_subscription);

    if (event_subscription->subscription_id) ogs_free(event_subscription->subscription_id);
    if (event_subscription->hash) ogs_free(event_subscription->hash);
    if (event_subscription->client) ogs_sbi_client_remove(event_subscription->client);
    if (event_subscription->af_event_exposure_subscription) data_collection_model_af_event_exposure_subsc_free(event_subscription->af_event_exposure_subscription);
    if (event_subscription->event_notification_timer)
        ogs_timer_delete(event_subscription->event_notification_timer);

    ogs_free(event_subscription);
}

bool _event_subscriptions_process(void *data) {

    ogs_hash_index_t *it;

    ogs_hash_t *event_subscriptions = data_collection_self()->event_subscriptions;

    if (!event_subscriptions) return false;

    ogs_debug("Event Subscriptions(%p) [%i entries]", event_subscriptions, ogs_hash_count(event_subscriptions));
    for (it = ogs_hash_first(event_subscriptions); it; it = ogs_hash_next(it)) {
        const char *key;
        int key_len;
        data_collection_event_subscription_t *data_collection_event_subscription;
	cJSON *response = NULL;
        int rv;

        ogs_hash_this(it, (const void **)&key, &key_len, (void**)(&data_collection_event_subscription));
        ogs_debug("Event Subscription: Key: [%p: %s][%i]: %p", key, key, key_len, data_collection_event_subscription);
	//if(__is_notif_method_periodic(data_collection_event_subscription)) continue;
	 if(data_collection_event_subscription->event_notification_timer && !data_collection_event_subscription->send_notif) continue;

        response = _event_subscription_generate_af_event_notification(data_collection_event_subscription);
	if(response){
	    rv = _event_subscription_send_af_event_exposure_notif(data_collection_event_subscription, response);
            cJSON_Delete(response);
            ogs_info("RV: %d", rv);
	}
        if(data_collection_event_subscription->send_notif) data_collection_event_subscription->send_notif = false;	
    }
    return true;
}

bool _event_subscription_set_send_notif(data_collection_event_subscription_t *event_subscription)
{
     if(event_subscription->event_notification_timer) {
         event_subscription->send_notif = true;
     } else {
         event_subscription->send_notif = false;
     }
     return event_subscription->send_notif;
}

cJSON *_event_subscription_generate_af_event_notification(data_collection_event_subscription_t *event_subscription)
{
    cJSON *response = NULL;
    ogs_list_t *af_events_notifications;

    af_events_notifications = data_collection_self()->config.data_collection_configuration->event_generation_callback(event_subscription);

    if (af_events_notifications && ogs_list_first(af_events_notifications)) {
        if(event_subscription->af_event_exposure_subscription) {
            response = _model_af_event_exposure_subsc_generate_notification(event_subscription->af_event_exposure_subscription,
                                                                            af_events_notifications);
        }
    }
    
    if(af_events_notifications) data_collection_list_free(af_events_notifications);

    return response;
}

bool _event_exposure_notification_send_local_event(void *data){
    ogs_event_t *event;
    int rv;

    event = _local_event_create(DC_LOCAL_EVENT_EXPOSURE_NOTIFICATION, data);

    rv = ogs_queue_push(ogs_app()->queue, event);
    if (rv !=OGS_OK) {
        ogs_error("OGS Queue Push failed %d", rv);
        ogs_event_free(event);
        return false;
    }
    return true;

}

int _event_subscription_send_af_event_exposure_notif(data_collection_event_subscription_t *event_subscription, cJSON *af_event_notification)
{
    ogs_sbi_request_t *request;
    char *method = (char *)OGS_SBI_HTTP_METHOD_POST;
    char *body = NULL;

    if (af_event_notification) {
	body = cJSON_Print(af_event_notification);
    }

    request = ogs_sbi_request_new();
    request->h.method = data_collection_strdup(method);
    request->h.uri = data_collection_strdup(data_collection_model_af_event_exposure_subsc_get_notif_uri(
                                                    event_subscription->af_event_exposure_subscription));
    request->h.api.version = data_collection_strdup("v1");

    if(body) {
        request->http.content = data_collection_strdup(body);
        request->http.content_length = strlen(body);
    }
    ogs_sbi_header_set(request->http.headers, "Content-Type", "application/json");
    ogs_sbi_client_send_request(event_subscription->client, __client_notify_cb, request, event_subscription);

    ogs_sbi_request_free(request);

    return 1;

}

void _event_subscription_notification_timer_activate(data_collection_event_subscription_t *event_subscription)
{
    if (!event_subscription) return;

    if (!event_subscription->event_notification_timer) {
        event_subscription->event_notification_timer =
                ogs_timer_add(ogs_app()->timer_mgr, dc_timer_event_exposure_notif, event_subscription);
    }

    if (event_subscription->event_notification_timer) {
        const data_collection_model_reporting_information_t* rep_info =
                data_collection_model_af_event_exposure_subsc_get_events_rep_info(
                        event_subscription->af_event_exposure_subscription);
        if (!rep_info) return;

        const data_collection_model_notification_method_t *notif_method =
                data_collection_model_reporting_information_get_notif_method(rep_info);
        if (!notif_method) return;

        if (data_collection_model_notification_method_get_enum(notif_method) != DCM_NOTIFICATION_METHOD_VAL_PERIODIC) return;

        int32_t rep_period = data_collection_model_reporting_information_get_rep_period(rep_info);
        ogs_timer_start(event_subscription->event_notification_timer, ogs_time_from_sec(
                rep_period?rep_period
                          :data_collection_self()->config.server_response_cache_control->event_exposure_response_max_age
        ));
    }
}

/******** Private functions ************/

static int __client_notify_cb(int status, ogs_sbi_response_t *response, void *data)
{
    int rv;
    data_collection_event_subscription_t *data_collection_event_subscription = (data_collection_event_subscription_t *)data;
    ogs_event_t *event;

    if (status == OGS_TIMEUP) {
        /* ignore timeouts */
        return OGS_OK;
    }

    if (status != OGS_OK) {
        ogs_log_message(
                status == OGS_DONE ? OGS_LOG_DEBUG : OGS_LOG_WARN, 0,
                "client_notify_cb() failed [%d]", status);
        if (response) ogs_sbi_response_free(response);
        return OGS_ERROR;
    }

    ogs_assert(response);

    event = (ogs_event_t*)ogs_event_new(OGS_EVENT_SBI_CLIENT);
    event->sbi.response = response;
    event->sbi.data = data_collection_event_subscription;
    rv = ogs_queue_push(ogs_app()->queue, event);
    if (rv !=OGS_OK) {
        ogs_error("OGS Queue Push failed %d", rv);
        ogs_sbi_response_free(response);
        ogs_event_free(event);
        return OGS_ERROR;
    }
    return OGS_OK;
}

static ogs_sbi_client_t *__event_consumer_client_init(const char *notification_uri)
{
    OpenAPI_uri_scheme_e scheme = OpenAPI_uri_scheme_NULL;
    ogs_sockaddr_t *addr = NULL;
    bool rv;
    ogs_sbi_client_t *client;

    rv = ogs_sbi_getaddr_from_uri(&scheme, &addr, (char*)notification_uri /* safe, see ogs_sbi_getaddr_from_uri */);
    if (rv == false || scheme == OpenAPI_uri_scheme_NULL) {
        ogs_error("Invalid URL [%s]", notification_uri);
        return NULL;
    }

    client = ogs_sbi_client_add(scheme, addr);
    ogs_freeaddrinfo(addr);

    return client;
}

static char *__calculate_event_exposure_subscription_hash(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc)
{
    /* convert obj => JSON => string => hash */
    if (!af_event_exposure_subsc) return NULL;

    cJSON *json = data_collection_model_af_event_exposure_subsc_toJSON(af_event_exposure_subsc,false);
    if (!json) return NULL;

    char *jsonstr = cJSON_Print(json);
    cJSON_Delete(json);
    if (!jsonstr) return NULL;

    char *hash = calculate_hash(jsonstr);
    cJSON_free(jsonstr);

    return hash;
}

static void __event_subscription_process_notif_method(data_collection_event_subscription_t *event_subscription) {
    /* Start the timer if the notif_method is periodic */
    _event_subscription_notification_timer_activate(event_subscription);
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
