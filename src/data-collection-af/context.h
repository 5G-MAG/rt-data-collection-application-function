/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DCAF_CONTEXT_H
#define DCAF_CONTEXT_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <features.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include "ogs-sbi.h"
#include "ogs-app.h"
#include "event.h"
#include "dcaf-sm.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int __dcaf_log_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __dcaf_log_domain

typedef struct dcaf_configuration_server_s {
    ogs_sockaddr_t *ipv4;
    ogs_sockaddr_t *ipv6;
    ogs_sbi_server_t *server_v4;
    ogs_sbi_server_t *server_v6;
} dcaf_configuration_server_t;

typedef enum dcaf_configuration_server_ifc_e {
    DCAF_SVR_SBI = 0,

    DCAF_SVR_NUM_IFCS
} dcaf_configuration_server_ifc_t;

typedef struct dcaf_configuration_s {
    dcaf_configuration_server_t servers[DCAF_SVR_NUM_IFCS];
} dcaf_configuration_t;

typedef struct dcaf_context_s {
    dcaf_configuration_t config;
    ogs_hash_t  *data_reporting_reports;
    char server_name[NI_MAXHOST];
} dcaf_context_t;

typedef struct dcaf_context_server_addr_s {
    ogs_lnode_t node;
    const char *server_addr;
} dcaf_context_server_addr_t;

extern void dcaf_context_init(void);
extern void dcaf_context_final(void);
extern dcaf_context_t *dcaf_self(void);
extern int dcaf_context_parse_config(void);

extern int dcaf_context_server_name_set(void);

#ifdef __cplusplus
}
#endif

#endif /* DCAF_CONTEXT_H */
