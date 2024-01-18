/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DCAF_EVENT_H
#define DCAF_EVENT_H

#include "ogs-proto.h"
#include "ogs-sbi.h"
//#include "context.h"
#include "server.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dcaf_sess_s dcaf_sess_t;

typedef struct nf_server_interface_metadata_s nf_server_interface_metadata_t;
typedef struct nf_server_app_metadata_s nf_server_app_metadata_t;

typedef enum {
    DCAF_EVENT_BASE = OGS_MAX_NUM_OF_PROTO_EVENT,

    DCAF_EVENT_SBI_LOCAL,

    DCAF_EVENT_NRF_TIMER,

    MAX_NUM_OF_DCAF_EVENT,

} dcaf_event_e;

typedef enum {
    DCAF_SBI_SERVER ,
    DCAF_R1_SERVER,
    DCAF_R2_SERVER,
    DCAF_R4_SERVER,

} dcaf_server_type_e;

typedef enum {

    DCAF_LOCAL_EVENT_DATA_REPORTING_REPORT,

} dcaf_local_event_e;


typedef struct dcaf_event_s {
    ogs_event_t h;
    int local_id;
    void *data;
    ogs_sbi_message_t *message;
    ogs_pkbuf_t *pkbuf;

    struct {
        ogs_sbi_service_type_e service_type;
        void *data;
        ogs_sbi_request_t *(*build)(dcaf_sess_t *sess, void *data);
    } local;

    const nf_server_interface_metadata_t *nf_server_interface_metadata;
    const nf_server_app_metadata_t *app_meta;

    dcaf_sess_t *sess;
} dcaf_event_t;

OGS_STATIC_ASSERT(OGS_EVENT_SIZE >= sizeof(dcaf_event_t));

extern const char *dcaf_event_get_name(dcaf_event_t *e);

#ifdef __cplusplus
}
#endif

#endif /* DCAF_EVENT_H */
