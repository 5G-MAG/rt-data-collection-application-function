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
        if (!strcmp(root_key, "dcaf")) {
            ogs_yaml_iter_t dc_iter;
            ogs_yaml_iter_recurse(&root_iter, &dc_iter);
            while (ogs_yaml_iter_next(&dc_iter)) {
                const char *dc_key = ogs_yaml_iter_key(&dc_iter);
                ogs_assert(dc_key);
                if (!strcmp(dc_key, "sbi")) {
		    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "service_name")) {
                    /* handle config in sbi library */
                } else if (!strcmp(dc_key, "discovery")) {
                    /* handle config in sbi library */
                } else {
                    ogs_warn("unknown key `%s`", dc_key);
                }
            }
        }
    }

    rv = dcaf_context_validation();
    if (rv != OGS_OK) {
        ogs_debug("dcaf_context_validation() failed");

        return rv;
    }

    return OGS_OK;
}

/***** Private functions *****/

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
