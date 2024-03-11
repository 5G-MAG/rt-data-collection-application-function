/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "ogs-sbi.h"
#include "data-collection-sp/data-collection.h"

#include "sbi-path.h"

static int server_cb(ogs_sbi_request_t *request, void *data)
{
    dcaf_event_t *e = NULL;
    int rv;

    ogs_assert(request);
    ogs_assert(data);

    e = (dcaf_event_t*) ogs_event_new(OGS_EVENT_SBI_SERVER);
    ogs_assert(e);

    e->h.sbi.request = request;
    e->h.sbi.data = data;

    rv = ogs_queue_push(ogs_app()->queue, e);
    if (rv != OGS_OK) {
        ogs_error("ogs_queue_push() failed:%d", (int)rv);
        ogs_sbi_request_free(request);
        ogs_event_free(e);
        return OGS_ERROR;
    }

    return OGS_OK;
}

int dcaf_sbi_open(void)
{
    ogs_sbi_nf_instance_t *nf_instance = NULL;

    nf_instance = ogs_sbi_self()->nf_instance;
    ogs_assert(nf_instance);
    ogs_sbi_nf_fsm_init(nf_instance);

    ogs_sbi_nf_instance_build_default(nf_instance);

    if (data_collection_set_nf_services()!= OGS_OK) {
        return OGS_ERROR;
    }

    nf_instance = ogs_sbi_self()->nrf_instance;
    if (nf_instance) {
        ogs_sbi_nf_fsm_init(nf_instance);
    }

    if (ogs_sbi_server_start_all(server_cb) != OGS_OK) {
        return OGS_ERROR;
    }

    return OGS_OK;
}

void dcaf_sbi_close(void)
{
    ogs_sbi_client_stop_all();
    ogs_sbi_server_stop_all();
}
