/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "context.h"

#include "utilities.h"
#include "event.h"

const char *dcaf_event_get_name(dcaf_event_t *e)
{
    if (e == NULL) {
        return OGS_FSM_NAME_INIT_SIG;
    }

    switch (e->h.id) {
    case DCAF_EVENT_SBI_LOCAL:
        return "DCAF_EVENT_SBI_LOCAL";

    default:
       break;
    }

    return ogs_event_get_name(&e->h);
}

/* vim:ts=8:sts=4:sw=4:expandtab:
*/
