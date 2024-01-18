/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */


#include "ogs-sbi.h"

#include "data-collection-service-producer.h"

#include "sbi-path.h"
#include "context.h"
#include "server.h"
#include "local.h"
#include "response-cache-control.h"
#include "dcaf-version.h"
#include "dcaf-sm.h"

void dcaf_state_initial(ogs_fsm_t *s, dcaf_event_t *e)
{
    dcaf_sm_debug(e);

    ogs_assert(s);

    OGS_FSM_TRAN(s, &dcaf_state_functional);
}

void dcaf_state_final(ogs_fsm_t *s, dcaf_event_t *e)
{
    dcaf_sm_debug(e);

    ogs_assert(s);
}

void dcaf_state_functional(ogs_fsm_t *s, dcaf_event_t *e)
{
    int rv;

    ogs_sbi_stream_t *stream = NULL;
    ogs_sbi_request_t *request = NULL;

    ogs_sbi_nf_instance_t *nf_instance = NULL;
    ogs_sbi_subscription_data_t *subscription_data = NULL;
    ogs_sbi_response_t *response = NULL;
    ogs_sbi_message_t *message = NULL;
    ogs_sbi_xact_t *sbi_xact = NULL;

    dcaf_sm_debug(e);

    if (data_collection_process_event(&e->h)) return;
    if (local_process_event(e)) return;

    message = ogs_calloc(1, sizeof(*message));
    const nf_server_app_metadata_t *app_meta = dcaf_app_metadata();

    ogs_assert(s);

    switch (e->h.id) {
        case OGS_FSM_ENTRY_SIG:
            ogs_info("[%s] MSAF Running", ogs_sbi_self()->nf_instance->id);
            break;

        case OGS_FSM_EXIT_SIG:
            break;

        case OGS_EVENT_SBI_SERVER:
            request = e->h.sbi.request;
            ogs_assert(request);
            stream = e->h.sbi.data;
            ogs_assert(stream);

            if (!strcmp(request->h.method, OGS_SBI_HTTP_METHOD_OPTIONS) && !strcmp(request->h.uri, "*")){
                char *methods = NULL;
                methods = ogs_msprintf("%s, %s, %s, %s, %s",OGS_SBI_HTTP_METHOD_POST, OGS_SBI_HTTP_METHOD_GET, OGS_SBI_HTTP_METHOD_PUT, OGS_SBI_HTTP_METHOD_DELETE, OGS_SBI_HTTP_METHOD_OPTIONS);
                response = nf_server_new_response(NULL, NULL,  0, NULL, 0, methods, NULL, app_meta);
                nf_server_populate_response(response, 0, NULL, 204);
                ogs_assert(response);
                ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                ogs_free(methods);
                response = NULL;
                break;
            }

            rv = ogs_sbi_parse_header(message, &request->h);
            if (rv != OGS_OK) {
                ogs_error("ogs_sbi_parse_header() failed");
                ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1, NULL, "cannot parse HTTP message", NULL, NULL, NULL, app_meta));
                ogs_sbi_message_free(message);
                break;
            }

            SWITCH(message->h.service.name)
            CASE(OGS_SBI_SERVICE_NAME_NNRF_NFM)
                if (strcmp(message->h.api.version, OGS_SBI_API_V1) != 0) {
                    ogs_error("Not supported version [%s]", message->h.api.version);
                    ogs_assert(true == ogs_sbi_server_send_error(
                                stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                                message, "Not supported version", NULL));
                    break;
                }
                SWITCH(message->h.resource.component[0])
                CASE(OGS_SBI_RESOURCE_NAME_NF_STATUS_NOTIFY)
                    SWITCH(message->h.method)
                    CASE(OGS_SBI_HTTP_METHOD_POST)
                        ogs_nnrf_nfm_handle_nf_status_notify(stream, message);
                        break;

                    DEFAULT
                        ogs_error("Invalid HTTP method [%s]", message->h.method);
                        ogs_assert(true ==
                                ogs_sbi_server_send_error(stream,
                                        OGS_SBI_HTTP_STATUS_FORBIDDEN, message,
                                        "Invalid HTTP method", message->h.method));
                    END
                    break;

                DEFAULT
                    ogs_error("Invalid resource name [%s]",
                            message->h.resource.component[0]);
                    ogs_assert(true ==
                            ogs_sbi_server_send_error(stream,
                                    OGS_SBI_HTTP_STATUS_BAD_REQUEST, message,
                                    "Invalid resource name",
                                    message->h.resource.component[0]));
                END
                break;

            DEFAULT
                ogs_error("Invalid API name [%s]", message->h.service.name);
                ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0, message, "Invalid API name.",  message->h.service.name, NULL, NULL, app_meta));

            END
            if (message) ogs_sbi_message_free(message);
            break;

        case OGS_EVENT_SBI_CLIENT:
            ogs_assert(e);

            response = e->h.sbi.response;
            ogs_assert(response);
            rv = ogs_sbi_parse_header(message, &response->h);
            if (rv != OGS_OK) {
                ogs_error("ogs_sbi_parse_header() failed");
                ogs_sbi_message_free(message);
                break;
            }
            message->res_status = response->status;

            SWITCH(message->h.service.name)
            
            CASE(OGS_SBI_SERVICE_NAME_NNRF_NFM)

                SWITCH(message->h.resource.component[0])
                CASE(OGS_SBI_RESOURCE_NAME_NF_INSTANCES)
		    cJSON *nf_profile;
                    OpenAPI_nf_profile_t *nfprofile;

                    nf_instance = e->h.sbi.data;
                    ogs_assert(nf_instance);

		    if (response->http.content_length && response->http.content){
                       ogs_debug( "response: %s", response->http.content);
                       nf_profile = cJSON_Parse(response->http.content);
                       nfprofile = OpenAPI_nf_profile_parseFromJSON(nf_profile);
                       message->NFProfile = nfprofile;

                       if (!message->NFProfile) {
                           ogs_error("No nf_profile");
                       }
                       cJSON_Delete(nf_profile);
                    }

                    ogs_assert(OGS_FSM_STATE(&nf_instance->sm));

                    e->h.sbi.message = message;
                    //message = NULL;
                    ogs_fsm_dispatch(&nf_instance->sm, e);
		    ogs_sbi_response_free(response);
                    break;

                CASE(OGS_SBI_RESOURCE_NAME_SUBSCRIPTIONS)
                    subscription_data = e->h.sbi.data;
                    ogs_assert(subscription_data);

                    SWITCH(message->h.method)
                    CASE(OGS_SBI_HTTP_METHOD_POST)
                        if (message->res_status == OGS_SBI_HTTP_STATUS_CREATED ||
                                message->res_status == OGS_SBI_HTTP_STATUS_OK) {
                            ogs_nnrf_nfm_handle_nf_status_subscribe(
                                    subscription_data, message);
                        } else {
                            ogs_error("HTTP response error : %d",
                                    message->res_status);
                        }
                        break;

                    CASE(OGS_SBI_HTTP_METHOD_DELETE)
                        if (message->res_status == OGS_SBI_HTTP_STATUS_NO_CONTENT) {
                            ogs_sbi_subscription_data_remove(subscription_data);
                        } else {
                            ogs_error("HTTP response error : %d",
                                    message->res_status);
                        }
                        break;

                    DEFAULT
                        ogs_error("Invalid HTTP method [%s]", message->h.method);
                    END
                    break;

                DEFAULT
                    ogs_error("Invalid resource name [%s]",
                            message->h.resource.component[0]);
                END
                break;

            DEFAULT
                ogs_error("Invalid service name [%s]", message->h.service.name);
                ogs_assert_if_reached();
            END

            if (message) ogs_sbi_message_free(message);
            break;

	case OGS_EVENT_SBI_TIMER:
            ogs_assert(e);

            switch(e->h.timer_id) {
                case OGS_TIMER_NF_INSTANCE_REGISTRATION_INTERVAL:
                case OGS_TIMER_NF_INSTANCE_HEARTBEAT_INTERVAL:
                case OGS_TIMER_NF_INSTANCE_NO_HEARTBEAT:
                case OGS_TIMER_NF_INSTANCE_VALIDITY:
                    nf_instance = e->h.sbi.data;
                    ogs_assert(nf_instance);
                    ogs_assert(OGS_FSM_STATE(&nf_instance->sm));

                    ogs_fsm_dispatch(&nf_instance->sm, e);
                    if (OGS_FSM_CHECK(&nf_instance->sm, ogs_sbi_nf_state_exception))
                        ogs_error("State machine exception [%d]", e->h.timer_id);
                    break;

                case OGS_TIMER_SUBSCRIPTION_VALIDITY:
                    subscription_data = e->h.sbi.data;
                    ogs_assert(subscription_data);

                    ogs_assert(true ==
                            ogs_nnrf_nfm_send_nf_status_subscribe(
                            ogs_sbi_self()->nf_instance->nf_type,
                            subscription_data->req_nf_instance_id,
                            subscription_data->subscr_cond.nf_type,
                            subscription_data->subscr_cond.service_name));


                    ogs_debug("Subscription validity expired [%s]",
                            subscription_data->id);
                    ogs_sbi_subscription_data_remove(subscription_data);
                    break;

                case OGS_TIMER_SBI_CLIENT_WAIT:
                    sbi_xact = e->h.sbi.data;
                    ogs_assert(sbi_xact);

                    stream = sbi_xact->assoc_stream;

                    ogs_sbi_xact_remove(sbi_xact);

                    ogs_error("Cannot receive SBI message");
                    if (stream) {
                        ogs_assert(true ==
                                ogs_sbi_server_send_error(stream,
                                    OGS_SBI_HTTP_STATUS_GATEWAY_TIMEOUT, NULL,
                                    "Cannot receive SBI message", NULL));
                    }
                    break;

                default:
                    ogs_error("Unknown timer[%s:%d]",
                            ogs_timer_get_name(e->h.timer_id), e->h.timer_id);
            }
            break;

        default:
            ogs_error("No handler for event %s", dcaf_event_get_name(e));
            break;
    }
    if (message) ogs_free(message);
}

static char *nf_name = NULL;
static nf_server_app_metadata_t app_metadata = { DCAF_NAME, DCAF_VERSION, NULL };

const nf_server_app_metadata_t *dcaf_app_metadata()
{
    if (!nf_name) {
        if (!dcaf_self()->server_name[0]) dcaf_context_server_name_set();
        nf_name = ogs_msprintf("5GMSAF-%s", dcaf_self()->server_name);
        ogs_assert(nf_name);
        app_metadata.server_name = nf_name;
    }

    return &app_metadata;
}

void dcaf_free_agent_name()
{
    if (nf_name) ogs_free(nf_name);
}

/* vim:ts=8:sts=4:sw=4:expandtab:
*/
