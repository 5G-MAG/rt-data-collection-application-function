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
#include "data-collection.h"

static dcaf_context_t *self = NULL;

int __dcaf_log_domain;

static int dcaf_context_prepare(void);
static int dcaf_context_validation(void);
static int check_for_data_collection_support(void);
static void dcaf_context_server_sockaddr_remove(void);

void dcaf_context_init(void)
{
    ogs_assert(self == NULL);

    self = ogs_calloc(1, sizeof(dcaf_context_t));
    ogs_assert(self);

    ogs_log_install_domain(&__dcaf_log_domain, "DCAF", ogs_core()->log.level);

}

void dcaf_context_final(void)
{
    ogs_assert(self);

    data_collection_finalise();

    if (self->config.data_collection_dir)
        ogs_free(self->config.data_collection_dir);

    dcaf_context_server_sockaddr_remove();


    ogs_free(self);
    self = NULL;
}

dcaf_context_t *dcaf_self(void)
{
    return self;
}

int dcaf_context_parse_config(void)
{
    int rv;
    yaml_document_t *document = NULL;
    ogs_yaml_iter_t root_iter;

    document = ogs_app()->document;
    ogs_assert(document);

    rv = dcaf_context_prepare();
    if (rv != OGS_OK) {
        ogs_debug("dcaf_context_prepare() failed");
        return rv;
    }

    ogs_yaml_iter_init(&root_iter, document);
    while (ogs_yaml_iter_next(&root_iter)) {
        const char *root_key = ogs_yaml_iter_key(&root_iter);
        ogs_assert(root_key);
        if (!strcmp(root_key, "dataCollection")) {
            ogs_yaml_iter_t dc_iter;
            ogs_yaml_iter_recurse(&root_iter, &dc_iter);
            while (ogs_yaml_iter_next(&dc_iter)) {
                const char *dc_key = ogs_yaml_iter_key(&dc_iter);
                ogs_assert(dc_key);
                if (!strcmp(dc_key, "open5gsIntegration")) {
		    self->config.open5gsIntegration_flag = ogs_yaml_iter_bool(&dc_iter);
                } else if ((!strcmp(dc_key, "sbi") && self->config.open5gsIntegration_flag)) {

		 /* handle config in sbi library */

                }  else if (!strcmp(dc_key, "sbi")) {
                    
                    ogs_list_t list, list6;
                    ogs_socknode_t *node = NULL, *node6 = NULL;

                    ogs_yaml_iter_t sbi_array, sbi_iter;
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
                            int i;
                            int matches = 0;
                            ogs_sbi_server_t *server;
                            for (i=0; i<DCAF_SVR_NUM_IFCS; i++) {
                                if (self->config.servers[i].ipv4 && ogs_sockaddr_is_equal(node->addr, self->config.servers[i].ipv4)) {
                                    server = self->config.servers[i].server_v4;
                                    matches = 1;
                                    break;
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
                            if (!strcmp(dc_key, "sbi")) {
                                for (i=0; i<DCAF_SVR_NUM_IFCS; i++) {
                                    if (i == DCAF_SVR_SBI || !self->config.servers[i].ipv4) {
                                        ogs_assert(OGS_OK == ogs_copyaddrinfo(&self->config.servers[i].ipv4, server->node.addr));
                                        self->config.servers[i].server_v4 = server;
                                    }
                                }
                            }
                        }
                        node6 = ogs_list_first(&list6);
                        if (node6) {
                            int i;
                            int matches = 0;
                            ogs_sbi_server_t *server;
                            for (i=0; i<DCAF_SVR_NUM_IFCS; i++) {
                                if (self->config.servers[i].ipv6 && ogs_sockaddr_is_equal(node->addr, self->config.servers[i].ipv6)) {
                                    server = self->config.servers[i].server_v6;
                                    matches = 1;
                                    break;
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
                            if (!strcmp(dc_key, "sbi")) {
                                for (i=0; i<DCAF_SVR_NUM_IFCS; i++) {
                                    if (i == DCAF_SVR_SBI || !self->config.servers[i].ipv6) {
                                        ogs_assert(OGS_OK == ogs_copyaddrinfo(&self->config.servers[i].ipv6, server->node.addr));
                                        self->config.servers[i].server_v6 = server;
                                    }
                                }
                            }
                        }

                        if (addr)
                            ogs_freeaddrinfo(addr);

                        ogs_socknode_remove_all(&list);
                        ogs_socknode_remove_all(&list6);

                    } while (ogs_yaml_iter_type(&sbi_array) == YAML_SEQUENCE_NODE);
                    
                    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "service_name")) {
                    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "discovery")) {
                    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "dataCollectionDir")) {
                    self->config.data_collection_dir = dcaf_strdup(ogs_yaml_iter_value(&dc_iter));
                } else {
                    ogs_warn("unknown key `%s`", dc_key);
                }
            }
        }
    }

    rv = check_for_data_collection_support();
    if (rv != OGS_OK) {
        ogs_debug("check_for_data_collection_support() failed");
        return rv;
    }

    rv = dcaf_context_validation();
    if (rv != OGS_OK) {
        ogs_debug("dcaf_context_validation() failed");

        return rv;
    }

    return OGS_OK;
}

/***** Private functions *****/

static int check_for_data_collection_support(void){

    if(!self->config.open5gsIntegration_flag) {
        ogs_info("dataCollection.open5gsIntegration must be true for data collection AF. Set \"open5gsIntegration: true\" in the configuration file");
	return OGS_ERROR;
    }

    return OGS_OK;

}

static void dcaf_context_server_sockaddr_remove(void){
    int i;
    for (i=0; i<DCAF_SVR_NUM_IFCS; i++) {
        if(self->config.servers[i].ipv4) ogs_freeaddrinfo(self->config.servers[i].ipv4);
        if(self->config.servers[i].ipv6) ogs_freeaddrinfo(self->config.servers[i].ipv6);
    }
}

static int dcaf_context_prepare(void)
{
    return OGS_OK;
}

static int
dcaf_context_validation(void)
{
    return OGS_OK;
}

int dcaf_context_server_name_set(void) {

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
