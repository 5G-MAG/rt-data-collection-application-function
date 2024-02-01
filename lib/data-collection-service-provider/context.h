/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_COLLECTION_CONTEXT_H
#define DATA_COLLECTION_CONTEXT_H

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
//#include "event.h"
//#include "data-collection-sm.h"
#include "response-cache-control.h"
#include "data-collection-service-producer.h"


#ifdef __cplusplus
extern "C" {
#endif

extern int __data_collection_log_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __data_collection_log_domain

typedef struct data_collection_configuration_server_s {
    ogs_sockaddr_t *ipv4;
    ogs_sockaddr_t *ipv6;
    ogs_sbi_server_t *server_v4;
    ogs_sbi_server_t *server_v6;
} data_collection_configuration_server_t;

typedef enum data_collection_configuration_server_ifc_e {
    DATA_COLLECTION_SVR_SBI = 0,
    DATA_COLLECTION_SVR_R1,
    DATA_COLLECTION_SVR_R2,
    DATA_COLLECTION_SVR_R4,
    DATA_COLLECTION_SVR_R5,
    DATA_COLLECTION_SVR_R6,
    
    DATA_COLLECTION_SVR_NUM_IFCS
} data_collection_configuration_server_ifc_t;

typedef struct data_collection_lib_configuration_s {
    bool open5gsIntegration_flag;
    data_collection_configuration_server_t servers[DATA_COLLECTION_SVR_NUM_IFCS];
    data_collection_server_response_cache_control_t *server_response_cache_control;

    char *data_collection_dir;
} data_collection_lib_configuration_t;

typedef struct data_collection_context_s {
    data_collection_lib_configuration_t config;
    ogs_hash_t  *dataReportingProvisioningSessions;
    char server_name[NI_MAXHOST];
} data_collection_context_t;

typedef struct data_collection_server_addr_s {
    ogs_lnode_t node;
    const char *server_addr;
} data_collection_context_server_addr_t;

extern int _data_collection_initialise(const data_collection_configuration_t* const configuration);
extern void data_collection_context_init(void);
extern void data_collection_context_final(void);
extern data_collection_context_t *data_collection_self(void);
extern int data_collection_context_parse_config(void);
extern int data_collection_parse_config(const data_collection_configuration_t* const configuration);

extern int data_collection_context_server_name_set(void);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_CONTEXT_H */
