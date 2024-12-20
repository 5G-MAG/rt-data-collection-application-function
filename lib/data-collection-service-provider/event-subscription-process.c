/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "ogs-proto.h"
#include "ogs-sbi.h"

/* fix bug in ogs-sbi.h */
#ifndef OGS_SBI_HTTP_STATUS_METHOD_NOT_ALLOWED
#define OGS_SBI_HTTP_STATUS_METHOD_NOT_ALLOWED OGS_SBI_HTTP_STATUS_MEHTOD_NOT_ALLOWED
#endif

#include "context.h"
#include "utilities.h"
#include "server.h"
#include "data-report.h"
#include "data-report-process.h"
#include "data-reporting.h"
#include "data-reporting-session-cache.h"
#include "event-subscription.h"
#include "lib-metadata.h"
#include "event.h"
#include "timer.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingApi-info.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingProvisioningApi-info.h"
#include "openapi/api/ApplicationEventSubscriptionCollectionApi-info.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

static const nf_server_interface_metadata_t
naf_eventexposure_api_metadata = {
    NAF_EVENTEXPOSURE_API_NAME,
    NAF_EVENTEXPOSURE_API_VERSION
};

static bool __does_stream_server_match_server(ogs_sbi_server_t *server, data_collection_configuration_server_ifc_t ifc);
static data_collection_model_af_event_exposure_subsc_t* __af_event_exposure_subscription_request_process(ogs_sbi_request_t *request, ogs_sbi_stream_t *stream, ogs_sbi_message_t *message, const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta);
static data_collection_event_subscription_t* __event_subscription_retrieve(const char *subscription_id, ogs_sbi_stream_t *stream, ogs_sbi_message_t *message, const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta);
static void __send_af_event_exposure_subscription(ogs_sbi_stream_t *stream, ogs_sbi_message_t *message,
                                                data_collection_event_subscription_t *data_collection_event_subscription,
                                                int status_code, char *location, cJSON *response_body, int path_length,
                                                const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta);



bool _evex_subscription_process_event(ogs_event_t *e)
{

    ogs_assert(e);
    ogs_debug("_evex_subscription_process_event %s", _dc_event_name(e));

    static const nf_server_interface_metadata_t *naf_eventexposure_api = &naf_eventexposure_api_metadata;
    const nf_server_app_metadata_t *app_meta = data_collection_lib_metadata();

    switch (e->id) {

    case DC_EVENT_LOCAL:
        if ((intptr_t)(e->sbi.data) == DC_LOCAL_EVENT_MARKER) {
            dc_local_event_t *local_event = (dc_local_event_t*)e;
            switch (local_event->local_id) {
            case DC_LOCAL_EVENT_EXPOSURE_NOTIFICATION:
                _event_subscriptions_process(local_event->data);
                return true;
            default:
                /* non-event-exposure local event, so ignore here */
                break;
            }
        }
        break;

    case OGS_EVENT_SBI_SERVER:
        {
            int rv = 0;
            ogs_sbi_request_t *request = e->sbi.request;
            ogs_sbi_message_t message;
            ogs_sbi_stream_t *stream = e->sbi.data;
            ogs_sbi_server_t *server;
            const nf_server_interface_metadata_t *api = NULL;
            static const data_collection_configuration_server_ifc_t server_types[] = {DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE, DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE};
            data_collection_configuration_server_ifc_t server_found = -1;
            int i;

            ogs_assert(request);
            ogs_assert(stream);

            server = ogs_sbi_server_from_stream(stream);
            ogs_assert(server);

            for (i=0; i<(sizeof(server_types)/sizeof(server_types[0])); i++) {
                if (__does_stream_server_match_server(server, server_types[i])) {
                    server_found = server_types[i];
                    break;
                }
            }
            if (server_found == -1) {
                return false;
            }

            rv = ogs_sbi_parse_header(&message, &request->h);
            if (rv != OGS_OK) {
                ogs_error("Failed to parse request headers");
                ogs_sbi_message_free(&message);
                break;
            }

            ogs_debug("OGS_EVENT_SBI_SERVER: service=%s, component[0]=%s", message.h.service.name, message.h.resource.component[0]);
            if (message.h.service.name) {
                SWITCH(message.h.service.name)
                CASE("naf-eventexposure")
                    api = naf_eventexposure_api;
                    break;
                DEFAULT
                    /*
                    char *err = ogs_msprintf("Invalid API name \"%s\" in Data Collection request", message.h.service.name);
                    ogs_error("%s", err);
                    ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0, &message,
                                                "Invalid API name", err, NULL, NULL, NULL, NULL, app_meta));
                    ogs_free(err);
                    */
                    ogs_sbi_message_free(&message);
                    ogs_sbi_request_free(request);

                    return true;
                END
                if (api == naf_eventexposure_api) {

                    /******** naf-eventexposure ********/
                    if (strcmp(message.h.api.version, OGS_SBI_API_V1) != 0) {
                        ogs_error("Unsupported API version [%s]", message.h.api.version);
                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0, &message,
                                                "Unsupported API version", NULL, NULL, NULL, NULL, api, app_meta));
                        break;
                    }
                    if (message.h.resource.component[0]) {
                        const char *resource = message.h.resource.component[0];
                        SWITCH(resource)
                        CASE("subscriptions")
                            SWITCH(message.h.method)
                            CASE(OGS_SBI_HTTP_METHOD_POST)
                                ogs_debug("POST response: status = %i", message.res_status);
                                if (message.h.resource.component[1]) {
                                    ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1,
                                                                        &message, "Bad Request", NULL, NULL, NULL, NULL,
                                                                        api, app_meta));

                                    ogs_debug("Additional path element on POST = %s", message.h.resource.component[1]);
                                } else {
                                    data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc = NULL;
                                    data_collection_event_subscription_t *data_collection_event_subscription;
                                    char *error_reason = NULL;
                                    char *error_classname = NULL;
                                    char *error_parameter = NULL;
                                    cJSON *response_body_json =  NULL;
                                    char *location;
                                    const char *client_type;


                                    switch (server_found) {
                                    case DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE:
                                        client_type = "NWDAF";
                                        break;
                                    case DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE:
                                        client_type = "EVENT_CONSUMER_AF";
                                        break;
                                    default:
                                        client_type = "NEF";
                                    }

                                    af_event_exposure_subsc = __af_event_exposure_subscription_request_process(request, stream,
                                                                                                          &message, api, app_meta);
                                    if (!af_event_exposure_subsc) break; /* Errors already reported */

                                    data_collection_event_subscription =
                                            data_collection_event_subscription_subscribe(af_event_exposure_subsc, client_type,
                                                                                         &error_reason, &error_classname,
                                                                                         &error_parameter);
                                    if(!data_collection_event_subscription) {
                                        OpenAPI_list_t *invalid_params = NULL;
                                        char *err = ogs_msprintf("Bad Request %s", error_reason);
                                        ogs_error("%s", err);
                                        if (error_parameter) {
                                                invalid_params = nf_server_make_invalid_params(error_parameter, error_reason);
                                        }
                                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0,
                                                                        &message, "Bad Request", err, NULL, invalid_params, NULL,
                                                                        api, app_meta));
                                        if (error_reason) ogs_free(error_reason);
                                        if (error_parameter) ogs_free(error_parameter);
                                        if (error_classname) ogs_free(error_classname);
                                        ogs_free(err);
                                        break;
                                    }

                                    response_body_json = data_collection_event_subscription_generate_af_event_exposure_subsc(data_collection_event_subscription);
                                    location = ogs_msprintf("%s/%s", request->h.uri, data_collection_event_subscription_get_id(data_collection_event_subscription));
                                    __send_af_event_exposure_subscription(stream, &message, data_collection_event_subscription, OGS_SBI_HTTP_STATUS_CREATED, location, response_body_json, 0, api, app_meta);
                                }
                                break;

                            CASE(OGS_SBI_HTTP_METHOD_GET)
                                {
                                    data_collection_event_subscription_t *event_subscription =
                                            __event_subscription_retrieve(message.h.resource.component[1], stream, &message,
                                                                          api, app_meta);
                                    if (event_subscription) {
                                        __send_af_event_exposure_subscription(stream, &message, event_subscription, OGS_SBI_HTTP_STATUS_OK, 
                                                                              data_collection_strdup(message.h.uri), NULL, 0, api,
                                                                              app_meta);
                                    } /* no else needed, errors already reported back to client */
                                }
                                break;

                            CASE(OGS_SBI_HTTP_METHOD_PUT)
                                {
                                    data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc;
                                    data_collection_event_subscription_t *event_subscription;
                                    const char *subscription_id = message.h.resource.component[1];

                                    af_event_exposure_subsc = __af_event_exposure_subscription_request_process(request, stream, &message, api, app_meta);
                                    if (!af_event_exposure_subsc) break; /* Errors already reported back to client */

                                    event_subscription = __event_subscription_retrieve(subscription_id, stream, &message, api, app_meta);
                                    if (!event_subscription) break; /* Errors already reported back to client */
                                    data_collection_event_subscription_set_af_event_exposure_subsc(event_subscription, af_event_exposure_subsc);
                                    __send_af_event_exposure_subscription(stream, &message, event_subscription, OGS_SBI_HTTP_STATUS_OK, data_collection_strdup(message.h.uri), NULL, 0, api, app_meta);
                                }
                                break;

                            CASE(OGS_SBI_HTTP_METHOD_DELETE)
                                {
                                    data_collection_event_subscription_t *event_subscription =
                                                __event_subscription_retrieve(message.h.resource.component[1], stream, &message,
                                                                              api, app_meta);
                                    if (event_subscription) {
                                        ogs_sbi_response_t *response;

                                        data_collection_event_subscription_unsubscribe(event_subscription);
                                        response = nf_server_new_response(NULL, NULL, 0, NULL, 0, NULL, api, app_meta);
                                        nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_NO_CONTENT);
                                        ogs_assert(response);
                                        ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                    } /* no else needed, errors already reported back to client */
                                }
                                break;

                            CASE(OGS_SBI_HTTP_METHOD_OPTIONS)
                                {
                                    if (message.h.resource.component[1]) {
                                        data_collection_event_subscription_t *event_subscription =
                                                __event_subscription_retrieve(message.h.resource.component[1], stream, &message,
                                                                              api, app_meta);
                                        if (event_subscription) {
                                            ogs_sbi_response_t *response = nf_server_new_response(
                                                            NULL, NULL, 0, NULL, 0,
                                                            OGS_SBI_HTTP_METHOD_GET ", "
                                                            OGS_SBI_HTTP_METHOD_PUT ", "
                                                            OGS_SBI_HTTP_METHOD_DELETE ", "
                                                            OGS_SBI_HTTP_METHOD_OPTIONS, api, app_meta);
                                            ogs_assert(response);
                                            nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_NO_CONTENT);
                                            ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                        } /* no else needed, errors already reported back to client */
                                    } else {
                                        ogs_sbi_response_t *response = nf_server_new_response(
                                                    NULL, NULL, 0, NULL, 0,
                                                    OGS_SBI_HTTP_METHOD_POST ", "
                                                    OGS_SBI_HTTP_METHOD_OPTIONS, api, app_meta);
                                        ogs_assert(response);
                                        nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_NO_CONTENT);
                                        ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                    }
                                }
                                break;

                            DEFAULT
                                ogs_debug("Invalid method [%s] for %s/%s/%s", message.h.method, message.h.service.name,
                                            message.h.api.version, message.h.resource.component[0]);
                                char *err = ogs_msprintf("Invalid method [%s] for %s/%s/%s", message.h.method,
                                                            message.h.service.name, message.h.api.version,
                                                            message.h.resource.component[0]);
                                ogs_error("%s", err);
                                ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1, &message,
                                                            "Bad request", err, NULL, NULL, NULL, api, app_meta));
                                ogs_free(err);
                            END
                            break;

                        DEFAULT
                            char *err = ogs_msprintf("Unknown object type \"%s\" in Naf Event Exposure request",
                                                        message.h.resource.component[0]);
                            ogs_error("%s", err);
                            ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1, &message,
                                                        "Bad request", err, NULL, NULL, NULL, api, app_meta));
                            ogs_free(err);
                            break;
                        END

                    }
                }
            } else {
                static const char *err = "Missing service name from URL path";
                ogs_error("%s", err);
                ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0, &message,
                                                "Missing service name", err, NULL, NULL, NULL, NULL, app_meta));
            }
            ogs_sbi_message_free(&message);
            return true;
        }
    case OGS_EVENT_SBI_CLIENT:
        {
            ogs_sbi_message_t message;
            data_collection_event_subscription_t *event_subsc;
            ogs_sbi_response_t *response;
            ogs_hash_index_t *hash_it;

            ogs_assert(e);

            /* check if this is one of ours */
            event_subsc = (data_collection_event_subscription_t*)e->sbi.data;
            for (hash_it = ogs_hash_first(data_collection_self()->event_subscriptions); hash_it; hash_it = ogs_hash_next(hash_it)) {
                if (event_subsc == (data_collection_event_subscription_t*)ogs_hash_this_val(hash_it)) break;
            }
            if (!hash_it) return false;

            /* ok this is a notification response */
            response = e->sbi.response;
            ogs_assert(response);

            if (ogs_sbi_parse_header(&message, &response->h) != OGS_OK) {
                ogs_error("ogs_sbi_parse_header() failed");
                ogs_sbi_message_free(&message);
                ogs_sbi_response_free(response);
                break;
            }
            message.res_status = response->status;

            if (message.res_status != OGS_SBI_HTTP_STATUS_NO_CONTENT) {
                ogs_error("Received notification response with non-OK status code: %i", message.res_status);
            }

            ogs_sbi_message_free(&message);
            ogs_sbi_response_free(response);
        }
        return true;
    default:
        break;
    }
    return false;
}

static bool __does_stream_server_match_server(ogs_sbi_server_t *server, data_collection_configuration_server_ifc_t ifc)
{
    int i;

    if (!server) return false;

    for (i=0; i<data_collection_self()->config.servers[ifc].num_v4_server_instances; i++) {
        if(data_collection_self()->config.servers[ifc].ogs_server[i].server_v4) {
            if(data_collection_self()->config.servers[ifc].ogs_server[i].server_v4 == server) {
                return true;
            }
        }
    }

    for (i=0; i<data_collection_self()->config.servers[ifc].num_v6_server_instances; i++) {
        if(data_collection_self()->config.servers[ifc].ogs_server[i].server_v6) {
            if(data_collection_self()->config.servers[ifc].ogs_server[i].server_v6 == server) {
                return true;
            }
        }
    }

    return false;
}

static data_collection_model_af_event_exposure_subsc_t* __af_event_exposure_subscription_request_process(ogs_sbi_request_t *request, ogs_sbi_stream_t *stream, ogs_sbi_message_t *message, const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta)
{
    cJSON *af_event_exposure_subscription;
    data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc = NULL;
    char *error_reason = NULL;
    char *error_classname = NULL;
    char *error_parameter = NULL;

    ogs_debug("Request body: %s", request->http.content);

    if (!check_http_content_type(request->http,"application/json")){
        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE,
                                0, message, "Unsupported Media Type",
                                "Expected content type: application/json", NULL, NULL, NULL,
                                 api, app_meta));
        return NULL;
    }

    af_event_exposure_subscription = cJSON_Parse(request->http.content);
    {
        char *txt = cJSON_Print(af_event_exposure_subscription);
        ogs_debug("Parsed JSON: %s", txt);
        cJSON_free(txt);
    }
    if (!af_event_exposure_subscription) {
        char *err = NULL;
        err = ogs_msprintf("Unable to parse AF Event Exposure Subscription as JSON.");
        ogs_error("%s", err);
        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0,
                                message, "Bad Event Exposure Subscription", err, NULL, NULL, NULL,
                                api, app_meta));
        ogs_free(err);
        return NULL;
    }

    af_event_exposure_subsc = data_collection_model_af_event_exposure_subsc_fromJSON(af_event_exposure_subscription, true, &error_reason, &error_classname, &error_parameter);
    cJSON_Delete(af_event_exposure_subscription);

    if (!af_event_exposure_subsc) {
        ogs_error("%s", error_reason);
        char *err;
        err = ogs_msprintf("Bad Event Exposure Subscription at %s.%s: %s", error_classname, error_parameter, error_reason);
        ogs_error("%s", err);
        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1,
                                message, "Bad request.", err, NULL, NULL, NULL, api, app_meta));
        if (error_reason) ogs_free(error_reason);
        if (error_classname) ogs_free(error_classname);
        if (error_parameter) ogs_free(error_parameter);
        ogs_free(err);
        return NULL;

    }
    return af_event_exposure_subsc;
}

static data_collection_event_subscription_t* __event_subscription_retrieve(const char *subscription_id, ogs_sbi_stream_t *stream, ogs_sbi_message_t *message, const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta)
{
    if (!subscription_id) {
        char *err = ogs_msprintf("Invalid resource [%s]", message->h.uri);
        ogs_error("%s", err);
        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1,
                                message, "Bad Request", err, NULL, NULL, NULL, api, app_meta));
        ogs_free(err);
        return NULL;;
    }
    data_collection_event_subscription_t *event_subscription = data_collection_event_subscription_find_by_id(subscription_id);
    if (!event_subscription) {
        char *err = NULL;
        OpenAPI_list_t *invalid_params;
        static const char *param = "{subscriptionId}";
        char *reason = NULL;
        err = ogs_msprintf("Event Subscription [%s] is not found.", subscription_id);
        ogs_error("%s", err);
        reason = ogs_msprintf("Invalid Event Subscription identifier [%s]",subscription_id);
        invalid_params = nf_server_make_invalid_params(param, reason);
        ogs_assert(true == nf_server_send_error(stream, 404, 1, message, "Event Subscription not found.", err, NULL, invalid_params, NULL, api, app_meta));
        ogs_free(err);
        ogs_free(reason);
        return NULL;
    }
    return event_subscription;
}

static void __send_af_event_exposure_subscription(ogs_sbi_stream_t *stream, ogs_sbi_message_t *message,
                                                data_collection_event_subscription_t *data_collection_event_subscription,
                                                int status_code, char *location, cJSON *response_body, int path_length,
                                                const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta)
{
    cJSON *json = NULL;
    ogs_sbi_response_t *response;
    const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subscription = data_collection_event_subscription_get_af_event_exposure_subsc(data_collection_event_subscription);
    if (response_body) {
        json = response_body;
    } else {
        json = data_collection_model_af_event_exposure_subsc_toJSON(af_event_exposure_subscription, false);
    }
    if (!json) {
        static const char *err = "Unable to convert AfEventExposureSubsc to JSON";
        ogs_error("%s", err);
        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR, path_length, message,
                                                "Internal Server Error", err, NULL, NULL, NULL, api, app_meta));
        return;
    }
    char *body = cJSON_Print(json);
    cJSON_Delete(json);

    ogs_info("LOC: %s", location);
    response = nf_server_new_response(location, "application/json",
                    data_collection_event_subscription_get_last_modified(data_collection_event_subscription),
                    data_collection_event_subscription_get_etag(data_collection_event_subscription),
                    data_collection_self()->config.server_response_cache_control->
                                data_collection_reporting_provisioning_session_response_max_age, NULL, api, app_meta);

    ogs_assert(response);
    nf_server_populate_response(response, strlen(body), body, status_code);
    ogs_assert(true == ogs_sbi_server_send_response(stream, response));
    //cJSON_free(body);

    if (location) ogs_free(location);
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
