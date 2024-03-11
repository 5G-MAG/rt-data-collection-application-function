/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "ogs-proto.h"
#include "ogs-sbi.h"

#include "context.h"
#include "utils.h"
#include "utilities.h"
#include "server.h"
#include "data-reporting.h"
#include "data-reporting-process.h"
#include "lib-metadata.h"
#include "openapi/model/dc_api_data_reporting_session.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingAPI-info.h"

#ifdef __cplusplus
extern "C" {
#endif

static const nf_server_interface_metadata_t
ndcaf_datareporting_api_metadata = {
    NDCAF_DATAREPORTING_API_NAME,
    NDCAF_DATAREPORTING_API_VERSION
};

static const char *__event_get_name(ogs_event_t *e);
static bool __does_stream_server_match_data_reporting_server(ogs_sbi_server_t *server);
static data_domain_list_t *__populate_supported_domains(OpenAPI_list_t *supported_domains);

bool _data_reporting_process_event(ogs_event_t *e)
{

    ogs_debug("_data_reporting_process_event: %s", __event_get_name(e));

    static const nf_server_interface_metadata_t *ndcaf_datareporting_api = &ndcaf_datareporting_api_metadata;
    const nf_server_app_metadata_t *app_meta = data_collection_lib_metadata();

    switch (e->id) {
    case OGS_EVENT_SBI_SERVER:
        {
            int rv = 0;
            ogs_sbi_request_t *request = e->sbi.request;
            ogs_sbi_message_t message;
            ogs_sbi_stream_t *stream = e->sbi.data;
            ogs_sbi_server_t *server;

            ogs_assert(request);
            ogs_assert(stream);

            server = ogs_sbi_server_from_stream(stream);
            ogs_assert(server);

            /* Check this event is from data reporting server */

	    if(__does_stream_server_match_data_reporting_server(server)) {
                rv = 1;
            }

            if (!rv) {
                /* This event didn't come in on the data reporting server, so ignore it */
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
                CASE("3gpp-ndcaf_data-reporting")
		    if (strcmp(message.h.api.version, OGS_SBI_API_V1) != 0) {
                        ogs_error("Not supported version [%s]", message.h.api.version);
                        ogs_assert(true == ogs_sbi_server_send_error(
                                stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                                &message, "Not supported version", NULL));
                        break;
                    }

                    if (message.h.resource.component[0]) {
                        SWITCH(message.h.resource.component[0])
                        CASE("sessions")
			    SWITCH(message.h.method)
                            CASE(OGS_SBI_HTTP_METHOD_POST)
			        ogs_debug("POST response: status = %i", message.res_status);
		                {
		                    ogs_info("In Data reporting session");
				    cJSON *data_reporting_sess;
				    dc_api_data_reporting_session_t *data_reporting_session;
				    data_collection_reporting_session_t *data_collection_reporting_session;
                                    const char *reason;
				    const data_domain_list_t *supported_domains;

				    ogs_debug("Request body: %s", request->http.content);

				    if(!check_http_content_type(request->http,"application/json")){
                                        ogs_assert(true == nf_server_send_error(stream, 415, 3, &message, "Unsupported Media Type.", "Expected content type: application/json", NULL, ndcaf_datareporting_api, app_meta));
                                        break;
                                    }

                                    data_reporting_sess = cJSON_Parse(request->http.content);
                                    {
                                        char *txt = cJSON_Print(data_reporting_sess);
                                        ogs_debug("Parsed JSON: %s", txt);
                                        cJSON_free(txt);
                                    }
				    if (!data_reporting_sess) {
                                        char *err = NULL;
                                        err = ogs_msprintf("Unable to parse Data Reporting Session as JSON.");
                                        ogs_error("%s", err);
                                        ogs_assert(true == nf_server_send_error(stream, 400, 1, &message, "Bad Data Reporting Session.", err, NULL, ndcaf_datareporting_api, app_meta));
                                        ogs_free(err);
					break;
                                    }

                                    data_reporting_session = dc_api_data_reporting_session_parseRequestFromJSON(data_reporting_sess, &reason);
                                    if (!data_reporting_session) {
                                        ogs_error("%s", reason);
                                        char *err;
                                        err = ogs_msprintf("Bad DataReportingSession: %s", reason);
                                        ogs_error("%s", err);
                                        ogs_assert(true == nf_server_send_error(stream, 400, 1, &message, "Bad request.", err, NULL, ndcaf_datareporting_api, app_meta));
                                        ogs_free(err);
                                        if (data_reporting_sess) cJSON_Delete(data_reporting_sess);
                                        data_reporting_sess = NULL;
                                        break;

                                    } /*else {
                                        dc_api_data_reporting_session_free(data_reporting_session);
                                    } */
				    supported_domains = __populate_supported_domains(data_reporting_session->supported_domains);
				    data_collection_reporting_session = data_collection_reporting_session_create(data_reporting_session->external_application_id, supported_domains);
				    if (!data_collection_reporting_session) {
                                        ogs_assert(true == nf_server_send_error(stream, 500, 1, &message, "Internal Server Error.", NULL, NULL, ndcaf_datareporting_api, app_meta));
					if (data_reporting_sess) cJSON_Delete(data_reporting_sess);
                                        data_reporting_sess = NULL;

                                        break;
                                    } else {
					cJSON *data_collection_reporting_sess;
					char *location;
					ogs_sbi_response_t *response;
					char *body;

					data_reporting_session_populate(data_collection_reporting_session, data_reporting_session);

					//data_collection_reporting_sess = dc_api_data_reporting_session_convertResponseToJSON(data_collection_reporting_session->data_reporting_session);
					data_collection_reporting_sess = data_collection_reporting_session_json(data_collection_reporting_session);

					if(!data_collection_reporting_sess) {

					    ogs_assert(true == nf_server_send_error(stream, 500, 1, &message, "Internal Server Error.", "Unable to convert data reporting session to JSON", NULL, ndcaf_datareporting_api, app_meta));
                                            if (data_reporting_sess) cJSON_Delete(data_reporting_sess);
                                            data_reporting_sess = NULL;
                                            break;
					}

					body = cJSON_Print(data_collection_reporting_sess);

                                        location = ogs_msprintf("%s/%s", request->h.uri, data_collection_reporting_session->data_reporting_session_id);


					response = nf_server_new_response(location, "application/json",  data_collection_reporting_session->received, data_collection_reporting_session->hash, data_collection_self()->config.server_response_cache_control-> data_collection_reporting_report_response_max_age, NULL, ndcaf_datareporting_api, app_meta);

                                         nf_server_populate_response(response, strlen(body), body, 201);
                                         ogs_assert(response);
                                         ogs_assert(true == ogs_sbi_server_send_response(stream, response));

					ogs_free(location);
					if (data_reporting_sess) cJSON_Delete(data_reporting_sess);
                                        data_reporting_sess = NULL;

					if(data_collection_reporting_sess) cJSON_Delete(data_collection_reporting_sess);
					break;

				    }

		                }
			        break;
			    CASE(OGS_SBI_HTTP_METHOD_GET)
			        {
				    if (message.h.resource.component[1] && !message.h.resource.component[2]) {

					data_collection_reporting_session_t *data_collection_reporting_session;
                                        cJSON *data_collection_reporting_sess;
                                        ogs_sbi_response_t *response;
                                        char *body;

					data_collection_reporting_session = data_collection_reporting_session_find(message.h.resource.component[1]);

				        if (!data_collection_reporting_session) {
                                            char *err = NULL;
                                            err = ogs_msprintf("Data reporting Session [%s] is not available.", message.h.resource.component[1]);
                                            ogs_error("%s", err);

                                            ogs_assert(true == nf_server_send_error(stream, 404, 1, &message, "Data reporting session does not exists.", err, NULL, ndcaf_datareporting_api, app_meta));
                                            ogs_free(err);
					    break;
                                        }

				        data_collection_reporting_sess = data_collection_reporting_session_json(data_collection_reporting_session);

                                        if(!data_collection_reporting_sess) {

                                            ogs_assert(true == nf_server_send_error(stream, 500, 1, &message, "Internal Server Error.", "Unable to convert data reporting session to JSON", NULL, ndcaf_datareporting_api, app_meta));
                                            break;
                                        }
					body = cJSON_Print(data_collection_reporting_sess);

					response = nf_server_new_response(NULL, "application/json",  data_collection_reporting_session->received, data_collection_reporting_session->hash, data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age, NULL, ndcaf_datareporting_api, app_meta);

                                         nf_server_populate_response(response, strlen(body), body, 200);
                                         ogs_assert(response);
                                         ogs_assert(true == ogs_sbi_server_send_response(stream, response));
					 if(data_collection_reporting_sess) cJSON_Delete(data_collection_reporting_sess);
                                         break;

				    } else {
                                        char *err = NULL;
                                        err = ogs_msprintf("Unknown sub-resource [%s] for data reporting Session [%s].", message.h.resource.component[2], message.h.resource.component[1]);
                                        ogs_error("%s", err);

                                        ogs_assert(true == nf_server_send_error(stream, 404, 2, &message, "Unknown data reporting session sub-resource.", err, NULL, ndcaf_datareporting_api, app_meta));
                                        ogs_free(err);
					break;
                                    }

				}
		                break;
		            CASE(OGS_SBI_HTTP_METHOD_DELETE)
                                {
				    if (message.h.resource.component[1] && !message.h.resource.component[2]) {

                                        data_collection_reporting_session_t *data_collection_reporting_session;
                                        ogs_sbi_response_t *response;

                                        data_collection_reporting_session = data_collection_reporting_session_find(message.h.resource.component[1]);

                                        if (!data_collection_reporting_session) {
                                            char *err = NULL;
                                            err = ogs_msprintf("Data reporting Session [%s] is not found.", message.h.resource.component[1]);
                                            ogs_error("%s", err);

                                            ogs_assert(true == nf_server_send_error(stream, 404, 1, &message, "Data reporting session does not exists.", err, NULL, ndcaf_datareporting_api, app_meta));
                                            ogs_free(err);
                                            break;
                                        }
					data_collection_reporting_session_destroy(data_collection_reporting_session);
					response = nf_server_new_response(NULL, NULL, 0, NULL, 0, NULL, ndcaf_datareporting_api, app_meta);
                                        nf_server_populate_response(response, 0, NULL, 204);
                                        ogs_assert(response);
                                        ogs_assert(true == ogs_sbi_server_send_response(stream, response));
				    }

				}
                                break;

			    DEFAULT
                                ogs_debug("Invalid method [%s] for %s/%s/%s", message.h.method, message.h.service.name, message.h.api.version, message.h.resource.component[0]);
			        char *err = ogs_msprintf("Invalid method [%s] for %s/%s/%s", message.h.method, message.h.service.name,
                                                         message.h.api.version, message.h.resource.component[0]);
                                ogs_error("%s", err);
                                ogs_assert(true == ogs_sbi_server_send_error(stream,
                                           OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                                           &message, "Bad request", err));
                                ogs_free(err);

                            END

			    break;
			DEFAULT
                            char *err = ogs_msprintf("Unknown object type \"%s\" in Data Reporting request",
                                                         message.h.resource.component[0]);
                            ogs_error("%s", err);
                            ogs_assert(true == ogs_sbi_server_send_error(stream,
                                           OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                                           &message, "Bad request", err));
                            ogs_free(err);
			END
		    }
	            break;
		DEFAULT
                    ogs_error("Invalid API name [%s]", message.h.service.name);
		            char *err = ogs_msprintf("Invalid API name \"%s\" in Data Reporting request",
                                                         message.h.service.name);
                    ogs_error("%s", err);
                    ogs_assert(true == ogs_sbi_server_send_error(stream,
                                           OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                                           &message, "Invalid API name", err));
                    ogs_free(err);

                END

	    } else {
                    static const char *err = "Missing service name from URL path";
                    ogs_error("%s", err);
                    ogs_assert(true == ogs_sbi_server_send_error(stream,
                               OGS_SBI_HTTP_STATUS_BAD_REQUEST,
                               &message, "Missing service name", err));
            }
            ogs_sbi_message_free(&message);
            return true;

	}
	default:
        break;
    }
    return false;
}

static data_domain_list_t *__populate_supported_domains(OpenAPI_list_t *supported_domains) {
    OpenAPI_lnode_t *node = NULL;
    const char *data_domain;
    data_domain_node_t *data_domain_node;
    data_domain_list_t *data_domains;

    data_domains = (data_domain_list_t *)list_create();
    ogs_assert(data_domains);

    OpenAPI_list_for_each(supported_domains, node) {
	data_domain = dc_api_data_domain_ToString((intptr_t)node->data);

        data_domain_node = ogs_calloc(1,sizeof(data_domain_node_t));
        data_domain_node->data_domain = data_collection_strdup(data_domain);

	ogs_list_add(data_domains, data_domain_node);
    }
    return data_domains;
}

static const char *__event_get_name(ogs_event_t *e)
{
    if (e->id < OGS_MAX_NUM_OF_PROTO_EVENT)
        return ogs_event_get_name(e);
    return "Unknown Event Type";
}

static bool __does_stream_server_match_data_reporting_server(ogs_sbi_server_t *server)
{
    int i;

    if (!server) return false;

    for (i=0; i<data_collection_self()->config.servers[DATA_COLLECTION_SVR_DATA_REPORTING].num_v4_server_instances; i++) {
        if(data_collection_self()->config.servers[DATA_COLLECTION_SVR_DATA_REPORTING].ogs_server[i].server_v4) {
            if(data_collection_self()->config.servers[DATA_COLLECTION_SVR_DATA_REPORTING].ogs_server[i].server_v4 == server) {
                return true;
            }
        }
    }


    for (i=0; i<data_collection_self()->config.servers[DATA_COLLECTION_SVR_DATA_REPORTING].num_v6_server_instances; i++) {
        if(data_collection_self()->config.servers[DATA_COLLECTION_SVR_DATA_REPORTING].ogs_server[i].server_v6) {
            if(data_collection_self()->config.servers[DATA_COLLECTION_SVR_DATA_REPORTING].ogs_server[i].server_v6 == server) {
                return true;
            }
        }
    }

    return false;
}


#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
