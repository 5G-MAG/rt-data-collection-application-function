/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "openapi/model/dc_api_events_subs.h"
#include "openapi/model/dc_api_af_event.h"
#include "openapi/model/dc_api_af_event_exposure_subsc.h"
#include "data-collection-sp/data-collection.h"
#include "context.h"
#include "hash.h"
#include "timer.h"
#include "utilities.h"
#include "event-subscription.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dc_api_events_subs_s dc_api_events_subs_t;
typedef struct dc_api_af_event_exposure_subsc_s dc_api_af_event_exposure_subsc_t;

typedef struct data_collection_af_events_subscription_s {

    dc_api_events_subs_t *events_subsc;

}  data_collection_af_events_subscription_t;


typedef struct data_collection_af_event_exposure_subscription_s {

    dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc;
    ogs_list_t af_events_subscriptions; // Type: data_collection_af_events_subscription_t*

} data_collection_af_event_exposure_subscription_t;

typedef struct data_collection_event_subscription_s {
    char *subscription_id;
    ogs_time_t received;
    ogs_time_t last_used;
    char *hash;
    ogs_sbi_client_t  *client;
    data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription;
} data_collection_event_subscription_t;

typedef struct free_ogs_hash_event_subscription_s {
    const char *event_subscription;
    ogs_hash_t *hash;
} free_ogs_hash_event_subscription_t;


static char *calculate_event_exposure_subscription_hash(dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc);
static data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription_create(dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc);
static ogs_sbi_client_t *data_collection_event_consumer_client_init(char *notification_uri);
static void data_collection_af_event_exposure_subscription_remove(data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription);
static void data_collection_af_events_subscriptions_remove_all(ogs_list_t *af_events_subscriptions);
static void data_collection_af_events_subscriptions_remove(data_collection_af_events_subscription_t *af_events_subscription);
static bool data_collection_check_reporting_information_imm_rep_flag(data_collection_event_subscription_t *data_collection_event_subscription);
static int free_ogs_hash_event_subscription(void *rec, const void *key, int klen, const void *value);



data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription_from_json_request(cJSON *json /* not-null */, const char **error_return /* output */, const char **error_parameter /* output */) {
    
    dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc = NULL;
    data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription = NULL;


    if (error_return) *error_return = NULL;
    if (error_parameter) *error_parameter = NULL;


    af_event_exposure_subsc = dc_api_af_event_exposure_subsc_parseRequestFromJSON(json, error_return);
    if(!af_event_exposure_subsc) {
        return NULL;
    }

    data_collection_af_event_exposure_subscription = af_event_exposure_subscription_create(af_event_exposure_subsc); 
    if(!data_collection_af_event_exposure_subscription) return NULL;

    return data_collection_af_event_exposure_subscription;
    
}

cJSON *data_collection_af_event_exposure_subscription_json(data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription)
{
    cJSON *json = NULL;

    json = dc_api_af_event_exposure_subsc_convertResponseToJSON(data_collection_af_event_exposure_subscription->af_event_exposure_subsc);

    return json;
}


data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription_new_from_json_request
	(char *request_body, const char *mime_type, const char **error_reason, const char **error_parameter, const char **error_code) {
	
    cJSON *af_event_exposure_subscription;
    dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc = NULL;
    data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription = NULL;
    data_collection_event_subscription_t *data_collection_event_subscription;

    if (error_reason) *error_reason = NULL;
    if (error_parameter) *error_parameter = NULL;
    if (error_code) *error_code = NULL;

    if(strcmp(mime_type,"application/json")){
        if (error_reason) *error_reason = "MIME type is not JSON";
        if (error_code) *error_code = "415";

        return NULL;
    }

    af_event_exposure_subscription = cJSON_Parse(request_body);

    if (!af_event_exposure_subscription) {
        ogs_debug("Unable to parse Event Exposure subscription as JSON.");
        if (error_reason) *error_reason = "Bad Request: Parsing Event Exposure subscription JSON failed.";
        if (error_code) *error_code = "401";
        return NULL;
    }

    {
        char *txt = cJSON_Print(af_event_exposure_subscription);
        ogs_debug("Parsed Event Exposure Subscription JSON: %s", txt);
        cJSON_free(txt);
    }

    af_event_exposure_subsc = dc_api_af_event_exposure_subsc_parseRequestFromJSON(af_event_exposure_subscription, error_reason);
    if(!af_event_exposure_subsc) {
        if (error_code) *error_code = "401";
        return NULL;
    }

    data_collection_af_event_exposure_subscription = af_event_exposure_subscription_create(af_event_exposure_subsc); 
    if(!data_collection_af_event_exposure_subscription) return NULL;

    return data_collection_af_event_exposure_subscription;
    
}


data_collection_event_subscription_t *data_collection_event_subscription_subscribe(data_collection_af_event_exposure_subscription_t *subscription /* not-null,transfer */, const char **error_return /* output */, const char **error_parameter /* output */)
{
    ogs_assert(subscription);

    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];
    data_collection_event_subscription_t *data_collection_event_subscription;

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    if (error_return) *error_return = NULL;
    if (error_parameter) *error_parameter = NULL;

    data_collection_event_subscription = ogs_calloc(1, sizeof(data_collection_event_subscription_t));
    ogs_assert(data_collection_event_subscription);

    data_collection_event_subscription->subscription_id = data_collection_strdup(id);

    data_collection_event_subscription->received = ogs_time_now();
    data_collection_event_subscription->last_used = data_collection_event_subscription->received;
    data_collection_event_subscription->af_event_exposure_subscription = subscription;

    data_collection_event_subscription->hash = calculate_event_exposure_subscription_hash(subscription->af_event_exposure_subsc);

    data_collection_event_subscription->client = data_collection_event_consumer_client_init(subscription->af_event_exposure_subsc->notif_uri); 
    ogs_assert(data_collection_event_subscription->client);

    ogs_hash_set(data_collection_self()->event_subscriptions, data_collection_strdup(data_collection_event_subscription->subscription_id), OGS_HASH_KEY_STRING, data_collection_event_subscription);

    return data_collection_event_subscription;

}

void data_collection_event_subscription_unsubscribe(data_collection_event_subscription_t *event_subscription)
{
    ogs_assert(event_subscription);

    free_ogs_hash_event_subscription_t fohes = {
        event_subscription->subscription_id,
        data_collection_self()->event_subscriptions
    };
    ogs_hash_do(free_ogs_hash_event_subscription, &fohes, data_collection_self()->event_subscriptions);

    if (event_subscription->subscription_id) ogs_free(event_subscription->subscription_id);
    if (event_subscription->hash) ogs_free(event_subscription->hash);
    if (event_subscription->client) ogs_sbi_client_remove(event_subscription->client);
    if (event_subscription->af_event_exposure_subscription) data_collection_af_event_exposure_subscription_remove(event_subscription->af_event_exposure_subscription);

    ogs_free(event_subscription);
}

void data_collection_event_subscription_clear(data_collection_event_subscription_t *event_subscription)
{
    ogs_assert(event_subscription);

    if (event_subscription->subscription_id) ogs_free(event_subscription->subscription_id);
    if (event_subscription->hash) ogs_free(event_subscription->hash);
    if (event_subscription->client) ogs_sbi_client_remove(event_subscription->client);
    if (event_subscription->af_event_exposure_subscription) data_collection_af_event_exposure_subscription_remove(event_subscription->af_event_exposure_subscription);

    ogs_free(event_subscription);
}

data_collection_af_event_exposure_subscription_t *data_collection_event_subscription_get_af_event_exposure_subscription(data_collection_event_subscription_t *event_subscription /* not-null */) {
    
    if(!event_subscription || !event_subscription->af_event_exposure_subscription) 
        return NULL;
    return event_subscription->af_event_exposure_subscription;
}

size_t data_collection_af_event_exposure_subscription_num_events_subs(const data_collection_af_event_exposure_subscription_t *subscription /* not-null */) {

    size_t num_events_subs = 0;
    OpenAPI_list_t *events_subs;
    OpenAPI_lnode_t *events_subs_node = NULL;

    if(!subscription) return 0;
    if(!subscription->af_event_exposure_subsc) return 0;
    events_subs = subscription->af_event_exposure_subsc->events_subs;

    OpenAPI_list_for_each(events_subs, events_subs_node) {
        num_events_subs++;

   }
   return num_events_subs; 

}

char *data_collection_af_events_subscription_get_event_type(data_collection_af_events_subscription_t *events_subs) {

    ogs_assert(events_subs);
    ogs_assert(events_subs->events_subsc);
    ogs_info("Event type from AF Events Subscription: [%s]", dc_api_af_event_ToString(events_subs->events_subsc->event));
    return dc_api_af_event_ToString(events_subs->events_subsc->event);
}



data_collection_af_events_subscription_t *data_collection_af_event_exposure_subscription_get_events_subs(data_collection_af_event_exposure_subscription_t *subscription /* not-null */, size_t index) 
{
    
    OpenAPI_list_t *events_subs;
    OpenAPI_lnode_t *events_subs_node = NULL;
    data_collection_af_events_subscription_t *data_collection_af_events_subscription = NULL;
    size_t i = 0;
    ogs_assert(subscription);
    if(!subscription->af_event_exposure_subsc) return NULL;
    events_subs = subscription->af_event_exposure_subsc->events_subs;
    OpenAPI_list_for_each(events_subs, events_subs_node) {
        if( i++ > index) break;
    }
    if(events_subs_node) {
        dc_api_events_subs_t *event_subsc;
	event_subsc = (dc_api_events_subs_t*)events_subs_node->data;
        data_collection_af_events_subscription =  ogs_calloc(1, sizeof(data_collection_event_subscription_t));
        ogs_assert(data_collection_af_events_subscription);
	data_collection_af_events_subscription->events_subsc =  ogs_calloc(1, sizeof(dc_api_events_subs_t));
	ogs_assert(data_collection_af_events_subscription->events_subsc);
        data_collection_af_events_subscription->events_subsc = event_subsc;	
        return data_collection_af_events_subscription;
    }    
    return NULL;
}

data_collection_event_subscription_t *data_collection_event_subscription_find_by_id(const char *subscription_id /* not-null */) {
 
   data_collection_event_subscription_t *event_subscription = NULL; 
   if(!subscription_id) return NULL;

    event_subscription = (data_collection_event_subscription_t *)ogs_hash_get(data_collection_self()->event_subscriptions, subscription_id, OGS_HASH_KEY_STRING);
    return event_subscription;

}

const data_collection_af_event_exposure_subscription_t *data_collection_event_subscription_get_af_event_exposure_subscription_const(const data_collection_event_subscription_t *event_subscription /* not-null */) {
    
    if(!event_subscription ||!event_subscription->af_event_exposure_subscription) return NULL;
    return (const data_collection_af_event_exposure_subscription_t *)event_subscription->af_event_exposure_subscription;
}

bool data_collection_event_subscription_set_af_event_exposure_subscription_const(data_collection_event_subscription_t *event_subscription /* not-null */, data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription /* not-null, transfer */) {

    if(!event_subscription) return false;
    if(event_subscription->af_event_exposure_subscription)
        data_collection_af_event_exposure_subscription_remove(event_subscription->af_event_exposure_subscription);

    event_subscription->af_event_exposure_subscription = af_event_exposure_subscription;
    return true;
}

char *data_collection_event_subscription_get_id(data_collection_event_subscription_t *event_subscription) {
    if(!event_subscription || !event_subscription->subscription_id) return NULL;
    return event_subscription->subscription_id;
}

void data_collection_generate_af_event_notification_for_subscription(data_collection_event_subscription_t *data_collection_event_subscription) {

    bool rv;

    rv = data_collection_check_reporting_information_imm_rep_flag(data_collection_event_subscription);
    if (rv) {
        ogs_list_t *af_events_notifications;	
        	
        af_events_notifications = data_collection_self()->config.data_collection_configuration->event_generation_callback(data_collection_event_subscription); 
    }

}

ogs_time_t data_collection_event_exposure_subscription_last_used(data_collection_event_subscription_t *event_subscription) {
    if(!event_subscription) return 0;
    return event_subscription->last_used;
}

char *data_collection_event_exposure_subscription_etag(data_collection_event_subscription_t *event_subscription) {

    if(!event_subscription) return NULL;
    return event_subscription->hash;
}

dc_api_event_filter_t *data_collection_event_exposure_subscription_get_filter(data_collection_af_events_subscription_t *events_subscription) {

    if(!events_subscription) return NULL;
    return events_subscription->events_subsc->event_filter;
}


static data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription_create(dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc) {
    
    data_collection_af_event_exposure_subscription_t *data_collection_af_event_exposure_subscription;

    data_collection_af_event_exposure_subscription = ogs_calloc(1, sizeof(data_collection_af_event_exposure_subscription_t));
    ogs_assert(data_collection_af_event_exposure_subscription);
    data_collection_af_event_exposure_subscription->af_event_exposure_subsc = af_event_exposure_subsc;
    return data_collection_af_event_exposure_subscription;
    
}


static bool data_collection_check_reporting_information_imm_rep_flag(data_collection_event_subscription_t *data_collection_event_subscription) {

    dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc = NULL;
    
    if(!data_collection_event_subscription || !data_collection_event_subscription->af_event_exposure_subscription) return false;
    
    af_event_exposure_subsc = data_collection_event_subscription->af_event_exposure_subscription->af_event_exposure_subsc;
    if(!af_event_exposure_subsc) return false;
    
    if(af_event_exposure_subsc->events_rep_info->is_imm_rep || af_event_exposure_subsc->events_rep_info->imm_rep)
        return true;
   
    return false; 

}


static void data_collection_af_event_exposure_subscription_remove(data_collection_af_event_exposure_subscription_t *af_event_exposure_subscription) {
    if(af_event_exposure_subscription->af_event_exposure_subsc) 
        dc_api_af_event_exposure_subsc_free(af_event_exposure_subscription->af_event_exposure_subsc);
    if(ogs_list_first(&af_event_exposure_subscription->af_events_subscriptions))
        data_collection_af_events_subscriptions_remove_all(&af_event_exposure_subscription->af_events_subscriptions);	    
    ogs_free(af_event_exposure_subscription);
}

static void data_collection_af_events_subscriptions_remove_all(ogs_list_t *af_events_subscriptions) {
    data_collection_af_events_subscription_t *af_events_subscription = NULL;
    data_collection_af_events_subscription_t *af_event_subscription = NULL;

    ogs_list_for_each_safe(af_events_subscriptions, af_event_subscription, af_events_subscription) {
        ogs_list_remove(af_events_subscriptions, af_events_subscription);
	data_collection_af_events_subscriptions_remove(af_events_subscription);
    }

}

static void data_collection_af_events_subscriptions_remove(data_collection_af_events_subscription_t *af_events_subscription) {
 
    if(!af_events_subscription) return;	
    if(af_events_subscription->events_subsc) dc_api_events_subs_free(af_events_subscription->events_subsc); 
    ogs_free(af_events_subscription);
}

static int
free_ogs_hash_event_subscription(void *rec, const void *key, int klen, const void *value)
{
    free_ogs_hash_event_subscription_t *fohes = (free_ogs_hash_event_subscription_t *)rec;
    if (!strcmp(fohes->event_subscription, (char *)key)) {

        ogs_hash_set(fohes->hash, key, klen, NULL);
        ogs_free((void*)key);

    }
    return 1;
}


static char *calculate_event_exposure_subscription_hash(dc_api_af_event_exposure_subsc_t *af_event_exposure_subsc)
{
    cJSON *event_subscription;
    char *event_exposure_subscription;
    char *event_subsc = NULL;

    event_subscription = dc_api_af_event_exposure_subsc_convertResponseToJSON(af_event_exposure_subsc);
    if (!event_subscription) return NULL;

    event_exposure_subscription = cJSON_Print(event_subscription);
    cJSON_Delete(event_subscription);

    event_subsc = calculate_hash(event_exposure_subscription);
    cJSON_free(event_exposure_subscription);

    return event_subsc;
}

static ogs_sbi_client_t *data_collection_event_consumer_client_init(char *notification_uri) {

    OpenAPI_uri_scheme_e scheme = OpenAPI_uri_scheme_NULL;
    ogs_sockaddr_t *addr = NULL;
    bool rv;
    ogs_sbi_client_t *client;

    rv = ogs_sbi_getaddr_from_uri(&scheme, &addr, notification_uri);
    if (rv == false || scheme == OpenAPI_uri_scheme_NULL) {
        ogs_error("Invalid URL [%s]", notification_uri);
        return NULL;
    }

    client = ogs_sbi_client_add(scheme, addr);
    ogs_freeaddrinfo(addr);

    return client;

}



/* vim:ts=8:sts=4:sw=4:expandtab:
 */
