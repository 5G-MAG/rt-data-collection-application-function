/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation
Author(s): David Waring <david.waring2@bbc.co.uk>

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "event.h"

extern ogs_event_t *_local_event_create(dc_local_event_e event_type, void *data)
{
    dc_local_event_t *event = (dc_local_event_t*)ogs_event_size(DC_EVENT_LOCAL, sizeof(dc_local_event_t));
    event->ogs_event.sbi.data = (void*)DC_LOCAL_EVENT_MARKER;
    event->local_id = event_type;
    event->data = data;
    
    return &(event->ogs_event);
}
