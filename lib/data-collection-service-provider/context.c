/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "context.h"
#include "utilities.h"
#include "lib-metadata.h"
#include "data-report.h"
#include "data-reporting.h"
#include "data-report.h"
#include "data-reporting-session-cache.h"
#include "data-reporting-provisioning.h"
#include "event-subscription.h"
#include "timer.h"

#include "data-collection-sp/data-collection.h"

static data_collection_context_t *self = NULL;

int __data_collection_log_domain;

static int data_collection_context_prepare(void);
static int data_collection_context_validation(void);
static void data_collection_context_data_reporting_provisioning_sessions_remove(void);
static void data_collection_context_data_reporting_sessions_remove(void);
static void data_collection_context_data_reports_remove(void);
static void data_collection_context_data_reporting_sessions_cache_remove(void);
static ogs_sockaddr_t *does_sockaddr_v4_match(data_collection_configuration_server_ifc_t ifc_num, data_collection_configuration_server_ifc_t ifc_num_conf);
static ogs_sockaddr_t *does_sockaddr_v6_match(data_collection_configuration_server_ifc_t ifc_num, data_collection_configuration_server_ifc_t ifc_num_conf);
//static void data_collection_context_data_reporting_sessions_cache_remove_all(void);
static void data_collection_context_server_sockaddr_remove(void);
//static dc_api_data_domain_e set_data_domain_from_property(data_collection_data_report_property_e data_report_property);
//static data_collection_data_report_property_e set_data_property_from_domain(const char *data_domain);
static void data_collection_context_event_exposure_subscriptions_unsubscribe(void);

int _data_collection_initialise(const data_collection_configuration_t* const configuration)
{
    int rv;
    ogs_assert(!self);
    if (!__data_collection_log_domain) {
        ogs_log_install_domain(&__data_collection_log_domain, "data-collection-service-producer", ogs_core()->log.level);
        ogs_log_config_domain("data-collection-service-producer", ogs_app()->logger.level);
    }
    ogs_debug("Initialising Data Collection library context");
    data_collection_context_init();
    rv = data_collection_parse_config(configuration);
    if (rv != OGS_OK) {
        ogs_error("Failed to configure data collection library");
        return rv;
    }
    self->reporting_session_expiry_timer = ogs_timer_add(ogs_app()->timer_mgr, dc_timer_reporting_session_expiry, NULL);
    if (self->reporting_session_expiry_timer) {
        /* check for expired reporting sessions after 1 minute */
        ogs_timer_start(self->reporting_session_expiry_timer, ogs_time_from_sec(60));
    }

    return OGS_OK;
}
void data_collection_context_init(void)
{
    ogs_assert(self == NULL);

    self = ogs_calloc(1, sizeof(data_collection_context_t));
    ogs_assert(self);

    self->data_reporting_provisioning_sessions = ogs_hash_make();
    self->data_reporting_sessions = ogs_hash_make();
    self->data_reports = ogs_hash_make();
    self->event_subscriptions = ogs_hash_make();
    self->data_reporting_configuration_contexts = ogs_hash_make();

    data_collection_server_response_cache_control_set();
}

void data_collection_context_final(void)
{
    ogs_assert(self);

    if (self->config.server_response_cache_control)
    {
        ogs_free(self->config.server_response_cache_control);
    }

    if (self->config.data_collection_dir)
        ogs_free(self->config.data_collection_dir);

    if (self->reporting_session_expiry_timer) {
        ogs_timer_delete(self->reporting_session_expiry_timer);
        self->reporting_session_expiry_timer = NULL;
    }

    /* drop contextId => configuration index */
    if (self->data_reporting_configuration_contexts) ogs_hash_clear(self->data_reporting_configuration_contexts);

    data_collection_context_data_reporting_provisioning_sessions_remove();
    data_collection_context_data_reporting_sessions_remove();
    data_collection_context_data_reporting_sessions_cache_remove();
    data_collection_context_data_reports_remove();
    data_collection_context_event_exposure_subscriptions_unsubscribe();
    data_collection_free_agent_name();

    ogs_hash_destroy(self->data_reporting_configuration_contexts);
    self->data_reporting_configuration_contexts = NULL;

    data_collection_context_server_sockaddr_remove();

    ogs_free(self);
    self = NULL;
}

data_collection_context_t *data_collection_self(void)
{
    return self;
}

int data_collection_parse_config(const data_collection_configuration_t* const configuration)
{
    int rv;
    yaml_document_t *document = NULL;
    ogs_yaml_iter_t root_iter;

    document = ogs_app()->document;
    ogs_assert(document);

    rv = data_collection_context_prepare();
    if (rv != OGS_OK) {
        ogs_debug("data_collection_context_prepare() failed");
        return rv;
    }

    self->config.data_collection_configuration = configuration;
    self->config.timeouts.reporting_session = 120; /* Default reportingSession timeout will be 2 minutes */

    ogs_yaml_iter_init(&root_iter, document);
    while (ogs_yaml_iter_next(&root_iter)) {
        const char *root_key = ogs_yaml_iter_key(&root_iter);
        ogs_assert(root_key);
        if (!strcmp(root_key, configuration->configuration_section)) {
            ogs_yaml_iter_t dc_iter;

            bool data_reporting_provisioning_disable_r1;
            bool data_reporting_disable_r2;
            bool data_reporting_disable_r3;
            bool data_reporting_disable_r4;
	    bool event_exposure_disable_r5;
	    bool event_exposure_disable_r6;
	    
	    int i = 0;

            data_reporting_provisioning_disable_r1 = (configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING_R1);
            data_reporting_disable_r2 = (configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R2);
            data_reporting_disable_r3 = (configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R3);
            data_reporting_disable_r4 = (configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R4);
	    event_exposure_disable_r5 = (configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R5);
	    event_exposure_disable_r6 = (configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R6);

            const data_collection_data_report_handler_t * const *handlers = configuration->data_report_handlers;
            if(!handlers[i]) {
                ogs_error("Configuration from the AF has no data report handlers");
                return OGS_ERROR;
            }

            ogs_yaml_iter_recurse(&root_iter, &dc_iter);
            while (ogs_yaml_iter_next(&dc_iter)) {
                const char *dc_key = ogs_yaml_iter_key(&dc_iter);
                ogs_assert(dc_key);
                if (!strcmp(dc_key, "serverResponseCacheControl")) {
                    ogs_yaml_iter_t cc_iter, cc_array;
                    ogs_yaml_iter_recurse(&dc_iter, &cc_array);
                    if (ogs_yaml_iter_type(&cc_array) == YAML_MAPPING_NODE) {
                        memcpy(&cc_iter, &cc_array, sizeof(ogs_yaml_iter_t));
                    } else if (ogs_yaml_iter_type(&cc_array) == YAML_SEQUENCE_NODE) {
                        if (!ogs_yaml_iter_next(&cc_array))
                            break;
                        ogs_yaml_iter_recurse(&cc_array, &cc_iter);
                    } else if (ogs_yaml_iter_type(&cc_array) == YAML_SCALAR_NODE) {
                        break;
                    } else
                        ogs_assert_if_reached();

                    int data_collection_reporting_provisioning_session_response_max_age = SERVER_RESPONSE_MAX_AGE;
                    int data_collection_reporting_report_response_max_age = SERVER_RESPONSE_MAX_AGE;
                    int event_exposure_response_max_age = SERVER_RESPONSE_MAX_AGE;
                    while (ogs_yaml_iter_next(&cc_iter)) {
                        const char *cc_key = ogs_yaml_iter_key(&cc_iter);
                        ogs_assert(cc_key);
                        if (!strcmp(cc_key, "provisioning")) {
                            data_collection_reporting_provisioning_session_response_max_age = ascii_to_long(ogs_yaml_iter_value(&cc_iter));
                        } else if (!strcmp(cc_key, "dataCollectionReports")) {
                            data_collection_reporting_report_response_max_age = ascii_to_long(ogs_yaml_iter_value(&cc_iter));
                        } else if (!strcmp(cc_key, "eventExposure")) {
                            event_exposure_response_max_age = ascii_to_long(ogs_yaml_iter_value(&cc_iter));
                        }
                    }
                    data_collection_server_response_cache_control_set_from_config(
                                data_collection_reporting_provisioning_session_response_max_age, data_collection_reporting_report_response_max_age,
				event_exposure_response_max_age);


                }  else if (!strcmp(dc_key, "provisioning") || !strcmp(dc_key, "applicationServerDataReporting") 
				|| !strcmp(dc_key, "eventConsumerApplicationFunctionEventExposure")
				|| !strcmp(dc_key, "directDataReporting") || !strcmp(dc_key, "indirectDataReporting")
				|| !strcmp(dc_key,"networkDataAnalyticsFunctionEventExposure")) {

                    ogs_list_t list, list6;
                    ogs_socknode_t *node = NULL, *node6 = NULL;

                    ogs_yaml_iter_t sbi_array, sbi_iter;

		    if(data_reporting_provisioning_disable_r1 && !strcmp(dc_key, "provisioning")) continue;

		    if(data_reporting_disable_r2 && !strcmp(dc_key, "directDataReporting")) continue;
		    if(data_reporting_disable_r3 && !strcmp(dc_key, "indirectDataReporting")) continue;
		    if(data_reporting_disable_r4 && !strcmp(dc_key, "applicationServerDataReporting")) continue;
		    
		    if(event_exposure_disable_r5 && !strcmp(dc_key, "eventConsumerApplicationFunctionEventExposure")) continue;
		    if(event_exposure_disable_r6 && !strcmp(dc_key, "networkDataAnalyticsFunctionEventExposure")) continue;

                    ogs_yaml_iter_recurse(&dc_iter, &sbi_array);
                    do {
                        int i, family = AF_UNSPEC;
                        int num = 0;
                        const char *hostname[OGS_MAX_NUM_OF_HOSTNAME];
                        int num_of_advertise = 0;
                        const char *advertise[OGS_MAX_NUM_OF_HOSTNAME];

                        uint16_t port = 0;
                        const char *dev = NULL;
                        ogs_sockaddr_t *addr = NULL;

                        ogs_sockopt_t option;
                        bool is_option = false;

                        if (ogs_yaml_iter_type(&sbi_array) == YAML_MAPPING_NODE) {
                            memcpy(&sbi_iter, &sbi_array, sizeof(ogs_yaml_iter_t));
                        } else if (ogs_yaml_iter_type(&sbi_array) == YAML_SEQUENCE_NODE) {
                            if (!ogs_yaml_iter_next(&sbi_array))
                                break;
                            ogs_yaml_iter_recurse(&sbi_array, &sbi_iter);
                        } else if (ogs_yaml_iter_type(&sbi_array) == YAML_SCALAR_NODE) {
                            break;
                        } else
                            ogs_assert_if_reached();

                        while (ogs_yaml_iter_next(&sbi_iter)) {
                            const char *sbi_key = ogs_yaml_iter_key(&sbi_iter);
                            ogs_assert(sbi_key);
                            if (!strcmp(sbi_key, "family")) {
                                const char *v = ogs_yaml_iter_value(&sbi_iter);
                                if (v) family = atoi(v);
                                if (family != AF_UNSPEC &&
                                        family != AF_INET && family != AF_INET6) {
                                    ogs_warn("Ignore family(%d) : "
                                            "AF_UNSPEC(%d), "
                                            "AF_INET(%d), AF_INET6(%d) ",
                                            family, AF_UNSPEC, AF_INET, AF_INET6);
                                    family = AF_UNSPEC;
                                }
                            } else if (!strcmp(sbi_key, "addr") || !strcmp(sbi_key, "name")) {
                                ogs_yaml_iter_t hostname_iter;
                                ogs_yaml_iter_recurse(&sbi_iter, &hostname_iter);
                                ogs_assert(ogs_yaml_iter_type(&hostname_iter) != YAML_MAPPING_NODE);

                                do {
                                    if (ogs_yaml_iter_type(&hostname_iter) == YAML_SEQUENCE_NODE) {
                                        if (!ogs_yaml_iter_next(&hostname_iter))
                                            break;
                                    }

                                    ogs_assert(num < OGS_MAX_NUM_OF_HOSTNAME);
                                    hostname[num++] = ogs_yaml_iter_value(&hostname_iter);
                                } while (ogs_yaml_iter_type(&hostname_iter) == YAML_SEQUENCE_NODE);
                            } else if (!strcmp(sbi_key, "advertise")) {
                                ogs_yaml_iter_t advertise_iter;
                                ogs_yaml_iter_recurse(&sbi_iter, &advertise_iter);
                                ogs_assert(ogs_yaml_iter_type(&advertise_iter) != YAML_MAPPING_NODE);

                                do {
                                    if (ogs_yaml_iter_type(&advertise_iter) == YAML_SEQUENCE_NODE) {
                                        if (!ogs_yaml_iter_next(&advertise_iter))
                                            break;
                                    }

                                    ogs_assert(num_of_advertise < OGS_MAX_NUM_OF_HOSTNAME);
                                    advertise[num_of_advertise++] = ogs_yaml_iter_value(&advertise_iter);
                                } while (ogs_yaml_iter_type(&advertise_iter) == YAML_SEQUENCE_NODE);
                            } else if (!strcmp(sbi_key, "port")) {
                                const char *v = ogs_yaml_iter_value(&sbi_iter);
                                if (v)
                                    port = atoi(v);
                            } else if (!strcmp(sbi_key, "dev")) {
                                dev = ogs_yaml_iter_value(&sbi_iter);
                            } else if (!strcmp(sbi_key, "option")) {
                                rv = ogs_app_config_parse_sockopt(&sbi_iter, &option);
                                if (rv != OGS_OK) {
                                    ogs_debug("ogs_app_config_parse_sockopt() failed");
                                    return rv;
                                }
                                is_option = true;
                            } else if (!strcmp(sbi_key, "tls")) {
                                ogs_yaml_iter_t tls_iter;
                                ogs_yaml_iter_recurse(&sbi_iter, &tls_iter);

                                while (ogs_yaml_iter_next(&tls_iter)) {
                                    const char *tls_key = ogs_yaml_iter_key(&tls_iter);
                                    ogs_assert(tls_key);

                                    if (!strcmp(tls_key, "key")) {
                                        //key = ogs_yaml_iter_value(&tls_iter);
                                    } else if (!strcmp(tls_key, "pem")) {
                                        //pem = ogs_yaml_iter_value(&tls_iter);
                                    } else
                                        ogs_warn("unknown key `%s`", tls_key);
                                }
                            } else
                                ogs_warn("unknown key `%s`", sbi_key);
                        }

                        if (port == 0){
                            ogs_warn("Specify the [%s] port, otherwise a random port will be used", dc_key);
                        }

                        addr = NULL;
                        for (i = 0; i < num; i++) {
                            rv = ogs_addaddrinfo(&addr, family, hostname[i], port, 0);
                            ogs_assert(rv == OGS_OK);
                        }

                        ogs_list_init(&list);
                        ogs_list_init(&list6);

                        if (addr) {
                            if (ogs_app()->parameter.no_ipv4 == 0)
                                ogs_socknode_add(&list, AF_INET, addr, NULL);
                            if (ogs_app()->parameter.no_ipv6 == 0)
                                ogs_socknode_add(&list6, AF_INET6, addr, NULL);
                            ogs_freeaddrinfo(addr);
                        }

                        if (dev) {
                            rv = ogs_socknode_probe(
                                    ogs_app()->parameter.no_ipv4 ? NULL : &list,
                                    ogs_app()->parameter.no_ipv6 ? NULL : &list6,
                                    dev, port, NULL);
                            ogs_assert(rv == OGS_OK);
                        }

                        addr = NULL;
                        for (i = 0; i < num_of_advertise; i++) {
                            rv = ogs_addaddrinfo(&addr,
                                    family, advertise[i], port, 0);
                            ogs_assert(rv == OGS_OK);
                        }

                        node = ogs_list_first(&list);
                        if (node) {
                            int i,j;
                            int matches = 0;
                            ogs_sbi_server_t *server;
                            data_collection_configuration_server_ifc_t ifc_num;
			    ogs_sockaddr_t *data_report_sockaddr = NULL;
                            char data_report_server_addr[OGS_ADDRSTRLEN];
                            int  data_report_server_port;

			    for (i=0; i<DATA_COLLECTION_SVR_NUM_IFCS; i++) {
                                for (j=0; j<self->config.servers[i].num_v4_server_instances; j++) {
                                    if (self->config.servers[i].ogs_server[j].ipv4 && ogs_sockaddr_is_equal(node->addr, self->config.servers[i].ogs_server[j].ipv4)) {
                                        server = self->config.servers[i].ogs_server[j].server_v4;
                                        matches = 1;
                                        break;
                                    }
                                }
                            }
                            if(!matches) {
                                server = ogs_sbi_server_add(
                                        node->addr, is_option ? &option : NULL);
                                ogs_assert(server);


                                if (addr && ogs_app()->parameter.no_ipv4 == 0)
                                    ogs_sbi_server_set_advertise(
                                            server, AF_INET, addr);
                            /*
                                if (key) server->tls.key = key;
                                if (pem) server->tls.pem = pem;
                            */
                            }

                            SWITCH(dc_key)
                            CASE("provisioning")
                                ifc_num = DATA_COLLECTION_SVR_PROVISIONING;
                                break;
                            CASE("directDataReporting")
                                ifc_num = DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING;
                                break;
                            CASE("indirectDataReporting")
                                ifc_num = DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING;
                                break;
                            CASE("applicationServerDataReporting")
                                ifc_num = DATA_COLLECTION_SVR_AS_DATA_REPORTING;
                                break;
                            CASE("eventConsumerApplicationFunctionEventExposure")
                                ifc_num = DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE;
                                break;
                            CASE("networkDataAnalyticsFunctionEventExposure")
                                ifc_num = DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE;
                                break;
                            DEFAULT
                                ifc_num = DATA_COLLECTION_SVR_SBI;
                                break;
                            END
                            size_t ifc_svr = self->config.servers[ifc_num].num_v4_server_instances;
                            if (ifc_svr+1 >= DATA_COLLECTION_SVR_MAX_SERVERS_PER_IFC) {
                                ogs_error("Too many IPv4 servers in %s.%s section of the configuration", configuration->configuration_section, dc_key);
                                return OGS_ERROR;
                            }
                            ogs_assert(OGS_OK == ogs_copyaddrinfo(&self->config.servers[ifc_num].ogs_server[ifc_svr].ipv4,
                                                                  server->node.addr));
                            self->config.servers[ifc_num].ogs_server[ifc_svr].server_v4 = server;
                            self->config.servers[ifc_num].num_v4_server_instances++;

			    if(!data_reporting_disable_r2 && !data_reporting_disable_r3){
			        data_report_sockaddr = does_sockaddr_v4_match(DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING);
				if(data_report_sockaddr){
				    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
				    data_report_server_port = OGS_PORT(data_report_sockaddr);
				    ogs_error("Configuration Error: Direct and Indirect Data Reporting configurations have same network address [%s] and port [%d]",
					    data_report_server_addr, data_report_server_port);
				    return OGS_ERROR;
				}
			    }

			    if(!data_reporting_disable_r2 && !data_reporting_disable_r4){
                                data_report_sockaddr = does_sockaddr_v4_match(DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_AS_DATA_REPORTING);
                                if(data_report_sockaddr){
                                    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
                                    data_report_server_port = OGS_PORT(data_report_sockaddr);
                                    ogs_error("Configuration Error: Direct and Application Server Data Reporting configurations have same network address [%s] and port [%d]",
                                            data_report_server_addr, data_report_server_port);
                                    return OGS_ERROR;
                                }
                            }

			    if(!data_reporting_disable_r3 && !data_reporting_disable_r4){
                                data_report_sockaddr = does_sockaddr_v4_match(DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_AS_DATA_REPORTING);
                                if(data_report_sockaddr){
                                    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
                                    data_report_server_port = OGS_PORT(data_report_sockaddr);
                                    ogs_error("Configuration Error: Indirect and Application Server Data Reporting configurations have same network address [%s] and port [%d]",
                                            data_report_server_addr, data_report_server_port);
                                    return OGS_ERROR;
                                }
                            }

			    if(!event_exposure_disable_r5 && !event_exposure_disable_r6){
                                data_report_sockaddr = does_sockaddr_v4_match(DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE, DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE);
                                if(data_report_sockaddr){
                                    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
                                    data_report_server_port = OGS_PORT(data_report_sockaddr);
                                    ogs_error("Configuration Error: Event Consumer AF and NWDAF Event Exposure configurations have same network address [%s] and port [%d]",
                                            data_report_server_addr, data_report_server_port);
                                    return OGS_ERROR;
                                }
                            }
                        }

                        node6 = ogs_list_first(&list6);
                        if (node6) {
                            int i,j;
                            int matches = 0;
                            ogs_sbi_server_t *server;
                            data_collection_configuration_server_ifc_t ifc_num;

			    ogs_sockaddr_t *data_report_sockaddr = NULL;
		            char data_report_server_addr[OGS_ADDRSTRLEN];
		            int  data_report_server_port;

                            for (i=0; i<DATA_COLLECTION_SVR_NUM_IFCS; i++) {
                                for (j=0; j<self->config.servers[i].num_v6_server_instances; j++) {
                                    if (self->config.servers[i].ogs_server[j].ipv6 && ogs_sockaddr_is_equal(node->addr, self->config.servers[i].ogs_server[j].ipv6)) {
                                        server = self->config.servers[i].ogs_server[j].server_v6;
                                        matches = 1;
                                        break;
                                    }
                                }
                            }
                            if(!matches) {
                                server = ogs_sbi_server_add(
                                        node->addr, is_option ? &option : NULL);
                                ogs_assert(server);

                                if (addr && ogs_app()->parameter.no_ipv6 == 0)
                                    ogs_sbi_server_set_advertise(
                                            server, AF_INET6, addr);
                            /*
                                if (key) server->tls.key = key;
                                if (pem) server->tls.pem = pem;
                            */
                            }

                            SWITCH(dc_key)
                            CASE("provisioning")
                                ifc_num = DATA_COLLECTION_SVR_PROVISIONING;
                                break;
                            CASE("directDataReporting")
                                ifc_num = DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING;
                                break;
                            CASE("indirectDataReporting")
                                ifc_num = DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING;
                                break;
                            CASE("applicationServerDataReporting")
                                ifc_num = DATA_COLLECTION_SVR_AS_DATA_REPORTING;
                                break;
                            CASE("eventConsumerApplicationFunctionEventExposure")
                                ifc_num = DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE;
                                break;
                            CASE("networkDataAnalyticsFunctionEventExposure")
                                ifc_num = DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE;
                                break;
                            DEFAULT
                                ifc_num = DATA_COLLECTION_SVR_SBI;
                                break;
                            END
                            size_t ifc_svr = self->config.servers[ifc_num].num_v6_server_instances;
                            if (ifc_svr+1 >= DATA_COLLECTION_SVR_MAX_SERVERS_PER_IFC) {
                                ogs_error("Too many IPv6 servers in %s.%s section of the configuration", configuration->configuration_section, dc_key);
                                return OGS_ERROR;
                            }
                            ogs_assert(OGS_OK == ogs_copyaddrinfo(&self->config.servers[ifc_num].ogs_server[ifc_svr].ipv6,
                                                                  server->node.addr));
                            self->config.servers[ifc_num].ogs_server[ifc_svr].server_v6 = server;
                            self->config.servers[ifc_num].num_v6_server_instances++;

			    if(!data_reporting_disable_r2 && !data_reporting_disable_r3){
			        data_report_sockaddr = does_sockaddr_v6_match(DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING);
				if(data_report_sockaddr){
				    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
				    data_report_server_port = OGS_PORT(data_report_sockaddr);
				    ogs_error("Configuration Error: Direct and Indirect Data Reporting configurations have same network address [%s] and port [%d]",
					    data_report_server_addr, data_report_server_port);
				    return OGS_ERROR;
				}
			    }

			    if(!data_reporting_disable_r2 && !data_reporting_disable_r4){
                                data_report_sockaddr = does_sockaddr_v6_match(DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_AS_DATA_REPORTING);
                                if(data_report_sockaddr){
                                    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
                                    data_report_server_port = OGS_PORT(data_report_sockaddr);
                                    ogs_error("Configuration Error: Direct and Application Server Data Reporting configurations have same network address [%s] and port [%d]",
                                            data_report_server_addr, data_report_server_port);
                                    return OGS_ERROR;
                                }
                            }

			    if(!data_reporting_disable_r3 && !data_reporting_disable_r4){
                                data_report_sockaddr = does_sockaddr_v6_match(DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING, DATA_COLLECTION_SVR_AS_DATA_REPORTING);
                                if(data_report_sockaddr){
                                    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
                                    data_report_server_port = OGS_PORT(data_report_sockaddr);
                                    ogs_error("Configuration Error: Indirect and Application Server Data Reporting configurations have same network address [%s] and port [%d]",
                                            data_report_server_addr, data_report_server_port);
                                    return OGS_ERROR;
                                }
                            }

			    if(!event_exposure_disable_r5 && !event_exposure_disable_r6){
                                data_report_sockaddr = does_sockaddr_v6_match(DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE, DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE);
                                if(data_report_sockaddr){
                                    OGS_ADDR(data_report_sockaddr, data_report_server_addr);
                                    data_report_server_port = OGS_PORT(data_report_sockaddr);
                                    ogs_error("Configuration Error: Event Consumer AF and NWDAF Event Exposure configurations have same network address [%s] and port [%d]",
                                            data_report_server_addr, data_report_server_port);
                                    return OGS_ERROR;
                                }
                            }
                        }


                        if (addr)
                            ogs_freeaddrinfo(addr);

                        ogs_socknode_remove_all(&list);
                        ogs_socknode_remove_all(&list6);

                    } while (ogs_yaml_iter_type(&sbi_array) == YAML_SEQUENCE_NODE);

                    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "timeouts")) {
                    ogs_yaml_iter_t tmout_iter;
                    ogs_yaml_iter_recurse(&dc_iter, &tmout_iter);
                    while (ogs_yaml_iter_next(&tmout_iter)) {
                        const char *tmout_key = ogs_yaml_iter_key(&tmout_iter);
                        ogs_assert(tmout_key);
                        if (!strcmp(tmout_key, "reportingSession")) {
                            self->config.timeouts.reporting_session = ascii_to_long(ogs_yaml_iter_value(&tmout_iter));
                        } else {
                            ogs_warn("unknown key in timeouts `%s`", tmout_key);
                        }
                    }
                } else if (!strcmp(dc_key, "service_name")) {
                    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "discovery")) {
                    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "dataCollectionDir")) {
                    self->config.data_collection_dir = data_collection_strdup(ogs_yaml_iter_value(&dc_iter));
                } else {
                    ogs_warn("unknown key `%s`", dc_key);
                }
            }
        }
    }

    rv = data_collection_context_validation();
    if (rv != OGS_OK) {
        ogs_debug("data_collection_context_validation() failed");
        return rv;
    }

    return OGS_OK;
}

int data_collection_context_get_server_interface(ogs_sbi_server_t *server) {
    int i, j;	
    for (i=0; i<DATA_COLLECTION_SVR_NUM_IFCS; i++) {
        for (j=0; j<self->config.servers[i].num_v4_server_instances; j++) {
            if(self->config.servers[i].ogs_server[j].server_v4) {
                if(self->config.servers[i].ogs_server[j].server_v4 == server) {
                    return i;
                }
            }
	}
    }
    return -1;
}


/***** Private functions *****/

static void data_collection_context_data_reporting_provisioning_sessions_remove(void) {
    ogs_info("Removing all Data Reporting Provisioning Sessions");

    data_collection_hash_free(self->data_reporting_provisioning_sessions, (void(*)(void*))data_collection_reporting_provisioning_session_destroy);
    self->data_reporting_provisioning_sessions = NULL;
}

static void data_collection_context_data_reporting_sessions_cache_remove(void) {
    data_reporting_session_cache_free(self->data_reporting_sessions_cache);
    self->data_reporting_sessions_cache = NULL;
    if(self->reporting_sessions_cache_timer)
        ogs_timer_delete(self->reporting_sessions_cache_timer);
}


static void data_collection_context_data_reporting_sessions_remove(void) {
    ogs_info("Removing all Data Reporting Sessions");

    data_collection_hash_free(self->data_reporting_sessions, (void(*)(void*))data_collection_reporting_session_destroy_active_session);
    self->data_reporting_sessions = NULL;
}

static void data_collection_context_data_reports_remove(void) {
    ogs_info("Removing all Data Reports");
    
    data_collection_hash_free(self->data_reports, (void(*)(void*))data_report_hash_record_free);
    self->data_reports = NULL;
	
}

static void data_collection_context_event_exposure_subscriptions_unsubscribe(void) {
    ogs_info("Unsubscribing all Event Subscriptions ");

    data_collection_hash_free(self->event_subscriptions, (void(*)(void*))data_collection_event_subscription_unsubscribe);
    self->event_subscriptions = NULL;
}

#if 0
static data_collection_model_data_domain_e set_data_domain_from_property(data_collection_data_report_property_e data_report_property)
{
    switch (data_report_property) {
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC:
        return DCM_DATA_DOMAIN_VAL_APPLICATION_SPECIFIC;
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION:
        return  DCM_DATA_DOMAIN_VAL_COMMUNICATION;
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION:
        return DCM_DATA_DOMAIN_VAL_LOCATION;
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS:
        return DCM_DATA_DOMAIN_VAL_MS_ACCESS_ACTIVITY;
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE:
        return DCM_DATA_DOMAIN_VAL_PERFORMANCE;
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE:
        return DCM_DATA_DOMAIN_VAL_SERVICE_EXPERIENCE;
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN:
        return DCM_DATA_DOMAIN_VAL_PLANNED_TRIPS;
    case DATA_COLLECTION_DATA_REPORT_PROPERTY_ANBR_NET_ASSIST_INVOCATION:
        return DCM_DATA_DOMAIN_VAL_MS_ANBR_NETWORK_ASSISTANCE;
    }

    return DCM_DATA_DOMAIN_NO_VAL;
}

static data_collection_data_report_property_e set_data_property_from_domain(const char *data_domain)
{
    SWITCH(data_domain)
    CASE("APPLICATION_SPECIFIC")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC;
    CASE("COMMUNICATION")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION;
    CASE("LOCATION")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION;
    CASE("MS_ACCESS_ACTIVITY")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS;
    CASE("PERFORMANCE")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE;
    CASE("SERVICE_EXPERIENCE")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE;
    CASE("PLANNED_TRIPS")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN;
    CASE("MS_ANBR_NETWORK_ASSISTANCE")
        return DATA_COLLECTION_DATA_REPORT_PROPERTY_ANBR_NET_ASSIST_INVOCATION;
    END
    return 0;
}
#endif

static void data_collection_context_server_sockaddr_remove(void){
    int i,j;
    for (i=0; i<DATA_COLLECTION_SVR_NUM_IFCS; i++) {
        for (j=0; j<self->config.servers[i].num_v4_server_instances; j++) {
            if(self->config.servers[i].ogs_server[j].ipv4) ogs_freeaddrinfo(self->config.servers[i].ogs_server[j].ipv4);
        }
        for (j=0; j<self->config.servers[i].num_v6_server_instances; j++) {
            if(self->config.servers[i].ogs_server[j].ipv6) ogs_freeaddrinfo(self->config.servers[i].ogs_server[j].ipv6);
        }
    }
}

static int data_collection_context_prepare(void)
{
    return OGS_OK;
}

static int data_collection_context_validation(void)
{
    return OGS_OK;
}

static ogs_sockaddr_t *does_sockaddr_v4_match(data_collection_configuration_server_ifc_t ifc_num, data_collection_configuration_server_ifc_t ifc_num_conf)        
{
    int i, j; 	
    for(i=0; i < self->config.servers[ifc_num].num_v4_server_instances; i++) {
        for(j=0; j < self->config.servers[ifc_num_conf].num_v4_server_instances; j++) {
            if(self->config.servers[ifc_num].ogs_server[i].ipv4
                && self->config.servers[ifc_num_conf].ogs_server[j].ipv4
                && ogs_sockaddr_is_equal(self->config.servers[ifc_num].ogs_server[i].ipv4,
                    self->config.servers[ifc_num_conf].ogs_server[j].ipv4)) {
                return self->config.servers[ifc_num].ogs_server[i].ipv4;
	    }
	}
    }
    return NULL;
}

static ogs_sockaddr_t *does_sockaddr_v6_match(data_collection_configuration_server_ifc_t ifc_num, data_collection_configuration_server_ifc_t ifc_num_conf)
{
    int i, j;
    for(i=0; i < self->config.servers[ifc_num].num_v6_server_instances; i++) {
        for(j=0; j < self->config.servers[ifc_num_conf].num_v6_server_instances; j++) {
            if(self->config.servers[ifc_num].ogs_server[i].ipv6
                && self->config.servers[ifc_num_conf].ogs_server[j].ipv6
                && ogs_sockaddr_is_equal(self->config.servers[ifc_num].ogs_server[i].ipv6,
                    self->config.servers[ifc_num_conf].ogs_server[j].ipv6)) {
                return self->config.servers[ifc_num].ogs_server[i].ipv6;
            }
        }
    }
    return NULL;
}

int data_collection_context_server_name_set(void) {

    ogs_sbi_server_t *server = NULL;

    ogs_list_for_each(&ogs_sbi_self()->server_list, server) {

	ogs_sockaddr_t *advertise = NULL;
        int res = 0;

        advertise = server->advertise;
        if (!advertise)
            advertise = server->node.addr;
        ogs_assert(advertise);
        res = getnameinfo(&advertise->sa, ogs_sockaddr_len(advertise),
            self->server_name, sizeof(self->server_name),
                          NULL, 0, NI_NAMEREQD);
        if(res) {
            ogs_debug("Unable to retrieve server name: %d\n", res);
            continue;
        } else {
            ogs_debug("node=%s", self->server_name);
            return 1;
        }
    }
    return 0;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
*/
