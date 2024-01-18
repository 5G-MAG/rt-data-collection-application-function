/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DCAF_SM_H
#define DCAF_SM_H

#include "event.h"

#ifdef __cplusplus
extern "C" {
#endif

void dcaf_state_initial(ogs_fsm_t *s, dcaf_event_t *e);
void dcaf_state_final(ogs_fsm_t *s, dcaf_event_t *e);
void dcaf_state_functional(ogs_fsm_t *s, dcaf_event_t *e);
void dcaf_state_exception(ogs_fsm_t *s, dcaf_event_t *e);

const nf_server_app_metadata_t *dcaf_app_metadata();
void dcaf_free_agent_name();

#define dcaf_sm_debug(__pe) \
    ogs_debug("%s(): %s", __func__, dcaf_event_get_name(__pe))

#ifdef __cplusplus
}
#endif

#endif
