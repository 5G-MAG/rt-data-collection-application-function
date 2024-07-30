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
#include "data-reporting.h"
#include "data-report-process.h"
#include "data-reporting-session-cache.h"
#include "event-subscription.h"
#include "lib-metadata.h"
#include "event.h"
#include "timer.h"
#include "openapi/model/dc_api_data_reporting_session.h"
#include "openapi/model/dc_api_af_event_exposure_subsc.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingAPI-info.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingProvisioningAPI-info.h"
#include "openapi/api/ApplicationEventSubscriptionCollectionAPI-info.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

static const nf_server_interface_metadata_t
ndcaf_datareporting_api_metadata = {
    NDCAF_DATAREPORTING_API_NAME,
    NDCAF_DATAREPORTING_API_VERSION
};

static const nf_server_interface_metadata_t
ndcaf_datareportingprovisioning_api_metadata = {
    NDCAF_DATAREPORTINGPROVISIONING_API_NAME,
    NDCAF_DATAREPORTINGPROVISIONING_API_VERSION
};

static const char *__event_get_name(ogs_event_t *e);
static bool __does_stream_server_match_server(ogs_sbi_server_t *server, data_collection_configuration_server_ifc_t ifc);
static data_domain_list_t *__populate_supported_domains(OpenAPI_list_t *supported_domains);
static void __free_supported_domains(data_domain_list_t *supported_domains);
static void __send_data_reporting_configuration(ogs_sbi_stream_t *stream, ogs_sbi_message_t *message, 
                                                data_collection_reporting_configuration_t *configuration, int path_length,
                                                const nf_server_interface_metadata_t *api,
                                                const nf_server_app_metadata_t *app_meta);
static void __send_data_reporting_provisioning_session(ogs_sbi_stream_t *stream, ogs_sbi_message_t *message,
                                                data_collection_reporting_provisioning_session_t *session, int path_length,
                                                const nf_server_interface_metadata_t *api,
                                                const nf_server_app_metadata_t *app_meta);
static bool __resource_updated(ogs_sbi_request_t *request, const char *etag, ogs_time_t last_modified);

bool _data_report_process_event(ogs_event_t *e)
{

    ogs_debug("_data_reporting_process_event: %s", __event_get_name(e));

    static const nf_server_interface_metadata_t *ndcaf_datareporting_api = &ndcaf_datareporting_api_metadata;
    static const nf_server_interface_metadata_t *ndcaf_datareportingprovisioning_api = &ndcaf_datareportingprovisioning_api_metadata;
    const nf_server_app_metadata_t *app_meta = data_collection_lib_metadata();

    switch (e->id) {
    case DC_EVENT_REPORTING_SESSION_CACHE:
        ogs_assert(e);
        switch(e->timer_id) {
            case DC_TIMER_REPORTING_SESSION_CACHE:
                {
		    data_reporting_session_cache_prune(data_collection_self()->data_reporting_sessions_cache);
                }
                break;
            default:
                ogs_error("Invalid timer for event %s", __event_get_name(e));
                break;

        }
        break;
	    
    case DC_EVENT_DATA_REPORTS_EXPIRY:
        ogs_assert(e);
        switch(e->timer_id) {
            case DC_TIMER_DATA_REPORTS_EXPIRY:
                {
		    remove_expired_data_reports(data_collection_self()->data_reports);
                }
                break;
            default:
                ogs_error("Invalid timer for event %s", __event_get_name(e));
                break;

        }
        break;
	    
    case DC_EVENT_DATA_REPORTS_CLEAR:
        ogs_assert(e);
        switch(e->timer_id) {
            case DC_TIMER_DATA_REPORTS_CLEAR:
                {
		    data_reports_clear(data_collection_self()->data_reports);
                }
                break;
            default:
                ogs_error("Invalid timer for event %s", __event_get_name(e));
                break;

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
            static const data_collection_configuration_server_ifc_t server_types[] = {DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_AS_DATA_REPORTING, DATA_COLLECTION_SVR_PROVISIONING};
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
                CASE("3gpp-ndcaf_data-reporting")
                    api = ndcaf_datareporting_api;
                    break;
                CASE("3gpp-ndcaf_data-reporting_provisioning")
                    api = ndcaf_datareportingprovisioning_api;
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
                if (api == ndcaf_datareporting_api) {
                    /******** 3gpp-ndcaf_data-reporting ********/
		    static const data_collection_configuration_server_ifc_t data_reporting_server_types[] = {DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_AS_DATA_REPORTING};
                    data_collection_configuration_server_ifc_t data_reporting_server_found = -1;
		    int j;

		    for (j=0; j<(sizeof(data_reporting_server_types)/sizeof(data_reporting_server_types[0])); i++) {
                        if (__does_stream_server_match_server(server, data_reporting_server_types[i])) {
                            data_reporting_server_found = data_reporting_server_types[i];
                            break;
                        }
                    } 

                    if (data_reporting_server_found == -1) {
                        ogs_error("3gpp-ndcaf_data-reporting request on wrong interface");
                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_NOT_FOUND, 0, &message,
                                                "Not found", NULL, NULL, NULL, NULL, api, app_meta));
                    }

		    if (strcmp(message.h.api.version, OGS_SBI_API_V1) != 0) {
                        ogs_error("Unsupported API version [%s]", message.h.api.version);
                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0, &message,
                                                "Unsupported API version", NULL, NULL, NULL, NULL, api, app_meta));
                        break;
                    }

                    if (message.h.resource.component[0]) {
                        SWITCH(message.h.resource.component[0])
                        CASE("sessions")
			    SWITCH(message.h.method)
                            CASE(OGS_SBI_HTTP_METHOD_POST)
			        ogs_debug("POST response: status = %i", message.res_status);
			        
				if (message.h.resource.component[2] && !strcmp(message.h.resource.component[2], "report")) {
					int rv;
                                        data_collection_reporting_session_t *data_collection_reporting_session;
					//cJSON *data_report;
					const char *error_return = NULL;
					const char *mime_type = NULL;
					const char *error_code = NULL;
					const char *error_parameter = NULL;
					ogs_sbi_response_t *response;

                                        ogs_debug("Request body: %s", request->http.content);

                                        if(check_http_content_type(request->http,"application/json")){
					    mime_type = "application/json";	
					}

                                        data_collection_reporting_session = data_collection_reporting_session_find(message.h.resource.component[1]);

                                        if (!data_collection_reporting_session) {
                                            char *err = NULL;

				            OpenAPI_list_t *invalid_params;
				            static const char *param = "{sessionId}";
				            char *reason = NULL;

                                            err = ogs_msprintf("Data reporting Session [%s] is not found.", message.h.resource.component[1]);
                                            ogs_error("%s", err);

					    reason = ogs_msprintf("Invalid Data Reporting Session identifier [%s]",message.h.resource.component[1]);

					    invalid_params = nf_server_make_invalid_params(param, reason);

                                            ogs_assert(true == nf_server_send_error(stream, 404, 1, &message, "Data Reporting Session not found.", err, NULL, invalid_params, NULL, ndcaf_datareporting_api, app_meta));
                                            ogs_free(err);
                                            ogs_free(reason);
                                            break;
                                        }

					rv = data_collection_reporting_report(data_collection_reporting_session,mime_type?(const char *)data_collection_strdup(mime_type): NULL, (const void *)data_collection_strdup(request->http.content), strlen(request->http.content), &error_return, &error_code, &error_parameter);
					
					if(rv == OGS_ERROR) {

				            if (error_parameter) {
						OpenAPI_list_t *invalid_params;
					        char *err = NULL;
                                                err = ogs_msprintf("Unable to parse Data Report as JSON.");
                                                ogs_error("%s", err);
	
                                                invalid_params = nf_server_make_invalid_params(error_parameter, error_return);
                                                  
                                                ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0,
                                                                        &message, "Bad Request", err, NULL, invalid_params, NULL,
                                                                        api, app_meta));
                                                ogs_free(err);                  
                                                break;
                                            }
					    
                                            if (!strcmp(error_code, "400")) {
                                                char *err = NULL;
                                                err = ogs_msprintf("Unable to parse Data Report as JSON.");
                                                ogs_error("%s", err);
                                                ogs_assert(true == nf_server_send_error(stream, 400, 1, &message, "Bad Data Report.", err, NULL, NULL, NULL, ndcaf_datareporting_api, app_meta));
                                                ogs_free(err);
                                                break;
                                            }

					    if (!strcmp(error_code, "415")) {
					        ogs_assert(true == nf_server_send_error(stream, 415, 1, &message, "Unsupported Media Type.", "Expected content type: application/json", NULL, NULL, NULL, ndcaf_datareporting_api, app_meta));
                                                break;
 	    
					    } 

					}
					response = nf_server_new_response(NULL, NULL, 0, NULL, 0, NULL, ndcaf_datareporting_api, app_meta);
                                        nf_server_populate_response(response, 0, NULL, 204);
                                        ogs_assert(response);
                                        ogs_assert(true == ogs_sbi_server_send_response(stream, response));
					data_collection_event_exposure_notification_send_local_event(NULL);

				} else
			        
		                {
		                    ogs_debug("In Data reporting session");
				    cJSON *data_reporting_sess;
				    dc_api_data_reporting_session_t *data_reporting_session;
				    data_collection_reporting_session_t *data_collection_reporting_session;
                                    const char *reason;
				    data_domain_list_t *supported_domains;
				    data_collection_reporting_client_type_e client_type;

				    ogs_debug("Request body: %s", request->http.content);

				    if (!check_http_content_type(request->http,"application/json")){
                                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE,
                                                                    3, &message, "Unsupported Media Type",
                                                                    "Expected content type: application/json", NULL, NULL, NULL,
                                                                    api, app_meta));
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
                                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1,
                                                                    &message, "Bad Data Reporting Session", err, NULL, NULL, NULL,
                                                                    api, app_meta));
                                        ogs_free(err);
					break;
                                    }

                                    data_reporting_session = dc_api_data_reporting_session_parseRequestFromJSON(
                                                                        data_reporting_sess, &reason);
                                    if (!data_reporting_session) {
                                        ogs_error("%s", reason);
                                        char *err;
                                        err = ogs_msprintf("Bad DataReportingSession: %s", reason);
                                        ogs_error("%s", err);
                                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1,
                                                                    &message, "Bad request.", err, NULL, NULL, NULL, api, app_meta)
                                                  );
                                        ogs_free(err);
                                        if (data_reporting_sess) cJSON_Delete(data_reporting_sess);
                                        data_reporting_sess = NULL;
                                        break;

                                    } /*else {
                                        dc_api_data_reporting_session_free(data_reporting_session);
                                    } */
				    supported_domains = __populate_supported_domains(data_reporting_session->supported_domains);
				    client_type = (data_collection_reporting_client_type_e) data_collection_report_client_type(server);
				    data_collection_reporting_session = data_collection_reporting_session_create(data_reporting_session->external_application_id, supported_domains, client_type);
                                    __free_supported_domains(supported_domains);
				    if (!data_collection_reporting_session) {
                                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR,
                                                                    1, &message, "Internal Server Error", NULL, NULL, NULL, NULL,
                                                                    api, app_meta));
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

					if (!data_collection_reporting_sess) {
					    ogs_assert(true == nf_server_send_error(stream,
                                                                        OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR, 1, &message,
                                                                        "Internal Server Error",
                                                                        "Unable to convert data reporting session to JSON", NULL,
                                                                        NULL, NULL, api, app_meta));
                                            if (data_reporting_sess) cJSON_Delete(data_reporting_sess);
                                            data_reporting_sess = NULL;
                                            break;
					}

					body = cJSON_Print(data_collection_reporting_sess);

                                        location = ogs_msprintf("%s/%s", request->h.uri, data_collection_reporting_session->data_reporting_session_id);


					response = nf_server_new_response(location, "application/json",  data_collection_reporting_session->received, data_collection_reporting_session->hash, data_collection_self()->config.server_response_cache_control-> data_collection_reporting_report_response_max_age, NULL, api, app_meta);

                                         nf_server_populate_response(response, strlen(body), body, OGS_SBI_HTTP_STATUS_CREATED);
                                         ogs_assert(response);
                                         ogs_assert(true == ogs_sbi_server_send_response(stream, response));

					ogs_free(location);
					if (data_reporting_sess) cJSON_Delete(data_reporting_sess);
                                        data_reporting_sess = NULL;

					if (data_collection_reporting_sess) cJSON_Delete(data_collection_reporting_sess);
					break;

				    }

		                }
			        break;
		            CASE(OGS_SBI_HTTP_METHOD_GET)
			        {
                                    const char *data_reporting_session_id = message.h.resource.component[1];

                                    if (!data_reporting_session_id) {
                                        char *err = ogs_msprintf("Invalid resource [%s]", message.h.uri);
                                        ogs_error("%s", err);
                                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1,
                                                                    &message, "Bad Request", err, NULL, NULL, NULL, api, app_meta));
                                        ogs_free(err);
                                        break;
                                    }

				    const data_reporting_session_cache_entry_t *data_reporting_session_cache_entry;
                                    data_reporting_session_cache_entry = data_collection_context_retrieve_reporting_session(
                                                                                    data_reporting_session_id);

                                    if (!data_reporting_session_cache_entry) {
                                        char *err = NULL;
				        OpenAPI_list_t *invalid_params;
				        static const char *param = "{sessionId}";
				        char *reason = NULL;

				        err = ogs_msprintf("Data Reporting Session [%s] does not exist.", data_reporting_session_id
                                                          );
                                        ogs_error("%s", err);

				        reason = ogs_msprintf("Invalid Data Reporting Session identifier [%s]",
                                                            data_reporting_session_id);
				        invalid_params = nf_server_make_invalid_params(param, reason);
                                           
                                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_NOT_FOUND, 2, &message,
                                                                    "Data Reporting Session not found", err, NULL, invalid_params,
                                                                    NULL, api, app_meta));
                                        ogs_free(err);
				        ogs_free(reason);
                                    } else {
                                        ogs_sbi_response_t *response;
                                        int response_code = 200;
                                        const char *response_body = data_reporting_session_cache_entry->reporting_session;

                                        if (!__resource_updated(request, data_reporting_session_cache_entry->hash,
                                                                data_reporting_session_cache_entry->generated)) {
                                            response_code = 304;
                                            response_body = NULL;
                                        }

                                        response = nf_server_new_response(NULL, response_body?"application/json":NULL,
                                                        data_reporting_session_cache_entry->generated,
                                                        data_reporting_session_cache_entry->hash,
                                                        data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age,
                                                        NULL, api, app_meta);
                                        ogs_assert(response);
                                        nf_server_populate_response(response, response_body?strlen(response_body):0,
                                                                    data_collection_strdup(response_body), response_code);
                                        ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                    }
				}
                                break;

		            CASE(OGS_SBI_HTTP_METHOD_DELETE)
                                {
				    if (message.h.resource.component[1] && !message.h.resource.component[2]) {
                                        const char *data_reporting_session_id = message.h.resource.component[1];
                                        data_collection_reporting_session_t *data_collection_reporting_session;
                                        ogs_sbi_response_t *response;

                                        data_collection_reporting_session =
                                                    data_collection_reporting_session_find(data_reporting_session_id);

                                        if (!data_collection_reporting_session) {
                                            char *err = NULL;
                                            err = ogs_msprintf("Data reporting Session [%s] is not found.",
                                                                data_reporting_session_id);
                                            ogs_error("%s", err);
                                            ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_NOT_FOUND, 1,
                                                                        &message, "Data reporting session does not exist", err,
                                                                        NULL, NULL, NULL, api, app_meta));
                                            ogs_free(err);
                                            break;
                                        }
					data_collection_reporting_session_destroy(data_collection_reporting_session);
					response = nf_server_new_response(NULL, NULL, 0, NULL, 0, NULL, api, app_meta);
                                        nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_NO_CONTENT);
                                        ogs_assert(response);
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
                            char *err = ogs_msprintf("Unknown object type \"%s\" in Data Reporting request",
                                                        message.h.resource.component[0]);
                            ogs_error("%s", err);
                            ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1, &message, 
                                                        "Bad request", err, NULL, NULL, NULL, api, app_meta));
                            ogs_free(err);
			END
		    }
	            break;
                } else if (api == ndcaf_datareportingprovisioning_api) {
                    /******** 3gpp-ndcaf_data-reporting-provisioning ********/
                    if (!__does_stream_server_match_server(server, DATA_COLLECTION_SVR_PROVISIONING)) {
                        ogs_error("3gpp-ndcaf_data-reporting-provisioning request on wrong interface");
                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_NOT_FOUND, 0, &message, "Not found",
                                                    NULL, NULL, NULL, NULL, api, app_meta));
                    }

                    if (strcmp(message.h.api.version, OGS_SBI_API_V1) != 0) {
                        ogs_error("Unsupported API version [%s]", message.h.api.version);
                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0, &message,
                                                    "Bad Request", "Unsupported API version", NULL, NULL, NULL, api, app_meta));
                        break;
                    }

                    if (message.h.resource.component[0]) {
                        const char *resource = message.h.resource.component[0];
                        SWITCH(resource)
                        CASE("sessions")
                            if (message.h.resource.component[1]) {
                                /* /sessions/{sessionId}... request */
                                const char *sessionId = message.h.resource.component[1];
                                data_collection_reporting_provisioning_session_t *session = data_collection_reporting_provisioning_session_find(sessionId);
                                if (!session) {
                                    OpenAPI_list_t *invalid_params;
                                    char *err = ogs_msprintf("DataReportingProvisioningSession id [%s] not known", sessionId);
                                    ogs_error("%s", err);
                                    invalid_params = nf_server_make_invalid_params("{sessionId}", err);
                                    ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_NOT_FOUND, 2, &message,
                                                                                "Not found",
                                                                                "DataReportingProvisioningSession not found",
                                                                                NULL, invalid_params, NULL, api, app_meta));
                                    ogs_free(err);
                                } else {
                                    if (message.h.resource.component[2]) {
                                        /* /sessions/{sessionId}/<sub-resource>... request */
                                        const char *subresource = message.h.resource.component[2];
                                        SWITCH(subresource)
                                        CASE("configurations")
                                            if (message.h.resource.component[3]) {
                                                /* /sessions/{sessionId}/configurations/{configurationId}... request */
                                                const char *configurationId = message.h.resource.component[3];
                                                data_collection_reporting_configuration_t *configuration = data_collection_reporting_configuration_find(session, configurationId);
                                                if (!configuration) {
                                                    OpenAPI_list_t *invalid_params;
                                                    char *err = ogs_msprintf("DataReportingConfiguration id [%s] not known in DataReportingProvisioningSession [%s]", configurationId, sessionId);
                                                    ogs_error("%s", err);
                                                    invalid_params = nf_server_make_invalid_params("{configurationId}", err);
                                                    ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_NOT_FOUND,
                                                                                4, &message, "Not found",
                                                                                "DataReportingConfiguration not found", NULL,
                                                                                invalid_params, NULL, api, app_meta));
                                                    ogs_free(err);
                                                    break;
                                                } else {
                                                    if (message.h.resource.component[4]) {
                                                        char *err = ogs_msprintf("Bad request on DataReportingConfiguration [%s] in DataReportingProvisioningSession [%s]", configurationId, sessionId);
                                                        ogs_error("%s", err);
                                                        ogs_assert(true == nf_server_send_error(stream,
                                                                                OGS_SBI_HTTP_STATUS_BAD_REQUEST, 5, &message,
                                                                                "Bad Request", err, NULL, NULL, NULL, api,
                                                                                app_meta));
                                                        ogs_free(err);
                                                        break;
                                                    } else {
                                                        /* /sessions/{sessionId}/configurations/{configurationId} request: GET, PUT, PATCH, DELETE and OPTIONS */
                                                        SWITCH(message.h.method)
                                                        CASE(OGS_SBI_HTTP_METHOD_GET)
                                                            /* RetrieveConfiguration */
                                                            {
                                                                __send_data_reporting_configuration(stream, &message,
                                                                                                    configuration, 4, api,
                                                                                                    app_meta);
                                                            }
                                                            break;
                                                        CASE(OGS_SBI_HTTP_METHOD_PUT)
                                                            /* UpdateConfiguration */
                                                            {
                                                                const char *error_return = NULL;
                                                                cJSON *json = cJSON_Parse(request->http.content);
                                                                data_collection_reporting_configuration_t *new_config =
                                                                    data_collection_reporting_configuration_parse_from_json(json, configuration, &error_return);
                                                                if (!new_config) {
                                                                    /* Report parse error */
                                                                    char *err = ogs_msprintf("DataReportingConfiguration parse failed: %s", error_return);
                                                                    ogs_error("%s", err);
                                                                    ogs_assert(true == nf_server_send_error(stream,
                                                                                OGS_SBI_HTTP_STATUS_BAD_REQUEST, 4, 
                                                                                &message, "Bad Request", err, NULL, NULL, NULL,
                                                                                api, app_meta));
                                                                } else {
                                                                    data_collection_reporting_configuration_update(configuration, new_config);
                                                                    __send_data_reporting_configuration(stream, &message,
                                                                                                        new_config, 4, api,
                                                                                                        app_meta);
                                                                }
                                                            }
                                                            break;
                                                        CASE(OGS_SBI_HTTP_METHOD_PATCH)
                                                            /* ModifyConfiguration */
                                                            {
                                                                static const char *err = "Patch operation for DataCollectionConfigurations is not yet implemented";
                                                                ogs_info("%s", err);
                                                                ogs_assert(true == nf_server_send_error(stream,
                                                                                OGS_SBI_HTTP_STATUS_NOT_IMPLEMENTED, 4,
                                                                                &message, "Not implemented", err, NULL, NULL,
                                                                                NULL, api, app_meta));
                                                            }
                                                            break;
                                                        CASE(OGS_SBI_HTTP_METHOD_DELETE)
                                                            /* DestroyConfiguration */
                                                            {
                                                                data_collection_reporting_configuration_destroy(configuration);
                                                                ogs_sbi_response_t *response = nf_server_new_response(
                                                                            NULL, NULL, 0, NULL, 0, NULL, api, app_meta);
                                                                ogs_assert(response);
                                                                nf_server_populate_response(response, 0, NULL,
                                                                                            OGS_SBI_HTTP_STATUS_NO_CONTENT);
                                                                ogs_assert(true == ogs_sbi_server_send_response(stream, response)
                                                                            );
                                                            }
                                                            break;
                                                        CASE(OGS_SBI_HTTP_METHOD_OPTIONS)
                                                            {
                                                                ogs_sbi_response_t *response = nf_server_new_response(
                                                                            NULL, NULL, 0, NULL, 0,
                                                                            OGS_SBI_HTTP_METHOD_GET ","
                                                                            OGS_SBI_HTTP_METHOD_PUT ","
                                                                            OGS_SBI_HTTP_METHOD_PATCH ","
                                                                            OGS_SBI_HTTP_METHOD_DELETE ","
                                                                            OGS_SBI_HTTP_METHOD_OPTIONS, api, app_meta);
                                                                ogs_assert(response);
                                                                nf_server_populate_response(response, 0, NULL,
                                                                                            OGS_SBI_HTTP_STATUS_OK);
                                                                ogs_assert(true == ogs_sbi_server_send_response(stream, response)
                                                                            );
                                                            }
                                                            break;
                                                        DEFAULT
                                                            char *err = ogs_msprintf("Method [%s] not allowed on this resource",
                                                                                        message.h.method);
                                                            ogs_error("%s", err);
                                                            ogs_assert(true == nf_server_send_error(stream,
                                                                                        OGS_SBI_HTTP_STATUS_METHOD_NOT_ALLOWED, 4,
                                                                                        &message, "Method Not Allowed", err, NULL,
                                                                                        NULL, NULL, api, app_meta));
                                                            ogs_free(err);
                                                            break;
                                                        END
                                                    }
                                                }
                                            } else {
                                                /* /sessions/{sessionId}/configurations request: POST and OPTIONS */
                                                SWITCH(message.h.method)
                                                CASE(OGS_SBI_HTTP_METHOD_POST)
                                                    /* CreateConfiguration */
                                                    {
                                                        const char *error_return = NULL;
                                                        cJSON *json = cJSON_Parse(request->http.content);
                                                        data_collection_reporting_configuration_t *new_config =
                                                                    data_collection_reporting_configuration_parse_from_json(json,
                                                                                NULL, &error_return);
                                                        if (!new_config) {
                                                            /* report parse error */
                                                            char *err = ogs_msprintf(
                                                                            "Unable to parse DataReportingConfiguration JSON: %s",
                                                                            error_return);
                                                            ogs_error("%s", err);
                                                            ogs_assert(true == nf_server_send_error(stream,
                                                                                        OGS_SBI_HTTP_STATUS_BAD_REQUEST, 4,
                                                                                        &message, "Bad Request", err, NULL,
                                                                                        NULL, NULL, api, app_meta));
                                                            ogs_free(err);
                                                            break;
                                                        }
                                                        data_collection_reporting_configuration_set_session(new_config, session);

                                                        __send_data_reporting_configuration(stream, &message, new_config, 3, api,
                                                                                            app_meta);
                                                    }
                                                    break;
                                                CASE(OGS_SBI_HTTP_METHOD_OPTIONS)
                                                    {
                                                        ogs_sbi_response_t *response = nf_server_new_response(
                                                                            NULL, NULL, 0, NULL, 0,
                                                                            OGS_SBI_HTTP_METHOD_POST ","
                                                                            OGS_SBI_HTTP_METHOD_OPTIONS, api, app_meta);
                                                        ogs_assert(response);
                                                        nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_OK);
                                                        ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                                    }
                                                    break;
                                                DEFAULT
                                                    char *err = ogs_msprintf("Method [%s] not allowed on this resource",
                                                                                message.h.method);
                                                    ogs_error("%s", err);
                                                    ogs_assert(true == nf_server_send_error(stream,
                                                                                OGS_SBI_HTTP_STATUS_METHOD_NOT_ALLOWED, 3,
                                                                                &message, "Method Not Allowed", err, NULL, NULL,
                                                                                NULL, api, app_meta));
                                                    ogs_free(err);
                                                    break;
                                                END
                                            }
                                        DEFAULT
                                            char *err = ogs_msprintf("DataReportingProvisioningSession sub-resource [%s] not "
                                                                     "available", subresource);
                                            ogs_error("%s", err);
                                            ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 3,
                                                                            &message, "Bad Request", err, NULL, NULL, NULL, api,
                                                                            app_meta));
                                            ogs_free(err);
                                            break;
                                        END
                                    } else {
                                        /* /sessions/{sessionId} request: GET, DELETE and OPTIONS */
                                        SWITCH(message.h.method)
                                        CASE(OGS_SBI_HTTP_METHOD_GET)
                                            /* RetrieveSession */
                                            {
                                                __send_data_reporting_provisioning_session(stream, &message, session, 2, api,
                                                                                           app_meta);
                                            }
                                            break;
                                        CASE(OGS_SBI_HTTP_METHOD_DELETE)
                                            /* DestroySession */
                                            {
                                                data_collection_reporting_provisioning_session_destroy(session);
                                                ogs_sbi_response_t *response = nf_server_new_response(NULL, NULL, 0, NULL, 0, NULL,
                                                                                                      api, app_meta);
                                                ogs_assert(response);
                                                nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_NO_CONTENT);
                                                ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                            }
                                            break;
                                        CASE(OGS_SBI_HTTP_METHOD_OPTIONS)
                                            {
                                                ogs_sbi_response_t *response = nf_server_new_response(
                                                                            NULL, NULL, 0, NULL, 0,
                                                                            OGS_SBI_HTTP_METHOD_GET ","
                                                                            OGS_SBI_HTTP_METHOD_DELETE ","
                                                                            OGS_SBI_HTTP_METHOD_OPTIONS, api, app_meta);
                                                ogs_assert(response);
                                                nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_OK);
                                                ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                            }
                                            break;
                                        DEFAULT
                                            char *err = ogs_msprintf("Method [%s] not allowed on this resource", message.h.method);
                                            ogs_error("%s", err);
                                            ogs_assert(true == nf_server_send_error(stream,
                                                                        OGS_SBI_HTTP_STATUS_METHOD_NOT_ALLOWED,
                                                                        2, &message, "Method Not Allowed", err, NULL, NULL, NULL,
                                                                        api, app_meta));
                                            ogs_free(err);
                                            break;
                                        END
                                    }
                                }
                            } else {
                                /* /sessions request: POST or OPTIONS */
                                SWITCH(message.h.method)
                                CASE(OGS_SBI_HTTP_METHOD_POST)
                                    /* CreateSession */
                                    {
                                        const char *error_return = NULL;
                                        const char *error_parameter = NULL;
                                        cJSON *json = cJSON_Parse(request->http.content);
                                        data_collection_reporting_provisioning_session_t *new_session =
                                                    data_collection_reporting_provisioning_session_parse_from_json(json,
                                                                                                 &error_return, &error_parameter);
                                        if (!new_session) {
                                            /* report parse error */
                                            OpenAPI_list_t *invalid_params = NULL;
                                            char *err = ogs_msprintf("Unable to parse DataReportingProvisioningSession JSON: %s",
                                                            error_return);
                                            ogs_error("%s", err);
                                            if (error_parameter) {
                                                invalid_params = nf_server_make_invalid_params(error_parameter, error_return);
                                            }
                                            ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 4,
                                                                        &message, "Bad Request", err, NULL, invalid_params, NULL,
                                                                        api, app_meta));
                                            ogs_free(err);
                                            break;
                                        }
                                        __send_data_reporting_provisioning_session(stream, &message, new_session, 3, api, app_meta);
                                    }
                                    break;
                                CASE(OGS_SBI_HTTP_METHOD_OPTIONS)
                                    {
                                        ogs_sbi_response_t *response = nf_server_new_response(
                                                                            NULL, NULL, 0, NULL, 0,
                                                                            OGS_SBI_HTTP_METHOD_POST ","
                                                                            OGS_SBI_HTTP_METHOD_OPTIONS, api, app_meta);
                                        ogs_assert(response);
                                        nf_server_populate_response(response, 0, NULL, OGS_SBI_HTTP_STATUS_OK);
                                        ogs_assert(true == ogs_sbi_server_send_response(stream, response));
                                    }
                                    break;
                                DEFAULT
                                    char *err = ogs_msprintf("Method [%s] not allowed on this resource", message.h.method);
                                    ogs_error("%s", err);
                                    ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_METHOD_NOT_ALLOWED, 1,
                                                                &message, "Method Not Allowed", err, NULL, NULL, NULL, api,
                                                                app_meta));
                                    ogs_free(err);
                                    break;
                                END
                            }
                        DEFAULT
                            /* First path resource name not known */
                            char *err = ogs_msprintf("DataReportingProvisioningSession resource [%s] not available", resource);
                            ogs_error("%s", err);
                            ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 1, &message,
                                                        "Bad Request", err, NULL, NULL, NULL, api, app_meta));
                            ogs_free(err);
                            break;
                        END
                    } else {
                        static const char *err = "Resource not provided in Data Reporting Provisioning request";
                        ogs_error("%s", err);
                        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_BAD_REQUEST, 0, &message,
                                                    "Bad Request", err, NULL, NULL, NULL, NULL, app_meta));
                        break;
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

static void __free_supported_domains(data_domain_list_t *supported_domains)
{
    data_domain_node_t *next, *node;

    ogs_list_for_each_safe(supported_domains, next, node) {
        ogs_list_remove(supported_domains, node);
        if (node->data_domain) ogs_free(node->data_domain);
        ogs_free(node);
    }
    ogs_free(supported_domains);
}

static const char *__event_get_name(ogs_event_t *e)
{
    if (e->id < OGS_MAX_NUM_OF_PROTO_EVENT)
        return ogs_event_get_name(e);
    return "Unknown Event Type";
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

static void __send_data_reporting_configuration(ogs_sbi_stream_t *stream, ogs_sbi_message_t *message,
                                                data_collection_reporting_configuration_t *configuration, int path_length,
                                                const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta)
{
    cJSON *json = data_collection_reporting_configuration_json(configuration);
    if (!json) {
        static const char *err = "Unable to convert DataReportingConfiguration to JSON";
        ogs_error("%s", err);
        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR, path_length, message,
                                                "Internal Server Error", err, NULL, NULL, NULL, api, app_meta));
        return;
    }

    char *body = cJSON_Print(json);
    cJSON_Delete(json);

    ogs_sbi_response_t *response = nf_server_new_response(message->h.uri /* Location */, "application/json",
                                                          data_collection_reporting_configuration_last_modified(configuration),
                                                          data_collection_reporting_configuration_etag(configuration),
                                                          data_collection_self()->config.server_response_cache_control->data_collection_reporting_provisioning_session_response_max_age,
                                                          NULL /* Allow */, api, app_meta);
    ogs_assert(response);
    nf_server_populate_response(response, strlen(body), body, OGS_SBI_HTTP_STATUS_OK);
    ogs_assert(true == ogs_sbi_server_send_response(stream, response));
    cJSON_free(body);
}

static void __send_data_reporting_provisioning_session(ogs_sbi_stream_t *stream, ogs_sbi_message_t *message,
                                                data_collection_reporting_provisioning_session_t *session, int path_length,
                                                const nf_server_interface_metadata_t *api, const nf_server_app_metadata_t *app_meta)
{
    cJSON *json = data_collection_reporting_provisioning_session_json(session);
    
    if (!json) {
        static const char *err = "Unable to convert DataReportingProvisioningSession to JSON";
        ogs_error("%s", err);
        ogs_assert(true == nf_server_send_error(stream, OGS_SBI_HTTP_STATUS_INTERNAL_SERVER_ERROR, path_length, message,
                                                "Internal Server Error", err, NULL, NULL, NULL, api, app_meta));
        return;
    }

    char *body = cJSON_Print(json);
    cJSON_Delete(json);
    json = NULL;

    ogs_sbi_response_t *response = nf_server_new_response(message->h.uri /* Location */, "application/json",
                                                          data_collection_reporting_provisioning_session_last_modified(session),
                                                          data_collection_reporting_provisioning_session_etag(session),
                                                          data_collection_self()->config.server_response_cache_control->data_collection_reporting_provisioning_session_response_max_age,
                                                          NULL /* Allow */, api, app_meta);
    ogs_assert(response);
    nf_server_populate_response(response, strlen(body), body, OGS_SBI_HTTP_STATUS_OK);
    ogs_assert(true == ogs_sbi_server_send_response(stream, response));
    cJSON_free(body);
}

static bool __resource_updated(ogs_sbi_request_t *request, const char *etag, ogs_time_t last_modified)
{
    const char *if_none_match = ogs_hash_get(request->http.headers, "If-None-Match", OGS_HASH_KEY_STRING);
    if (if_none_match) {
        return (strcmp(etag, if_none_match) == 0);
    }

    const char *if_modified_since = ogs_hash_get(request->http.headers, "If-Modified-Since", OGS_HASH_KEY_STRING);
    if (if_modified_since) {
        struct tm tm = {0};
        ogs_time_t modified_since;

        ogs_strptime(if_modified_since, "%a, %d %b %Y %H:%M:%S GMT", &tm);
        ogs_debug("If-Modified-Since: sec=%i, min=%i, hour=%i, mday=%i, mon=%i, year=%i, gmtoff=%li",
                  tm.tm_sec, tm.tm_min, tm.tm_hour, tm.tm_mday, tm.tm_mon, tm.tm_year, tm.tm_gmtoff);
        ogs_time_from_gmt(&modified_since, &tm, 0);
        ogs_debug("If-Modified-Since: %li < %li?", modified_since, last_modified);
        return (modified_since >= last_modified);
    }

    return false;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
