/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 * Author: Dev Audsin <dev.audsin@bbc.co.uk>
 * 
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "ogs-proto.h"

#include "context.h"
#include "data-report-process.h"
#include "event-subscription-process.h"
#include "event.h"

#include "data-collection-process.h"

bool _data_collection_process_event(ogs_event_t *e)
{
    /* check if we're ready */
    if (data_collection_self() == NULL) return false;

    ogs_debug("_data_collection_process_event: %s", _dc_event_name(e));

    if (_data_report_process_event(e)) return true;
    if (_evex_subscription_process_event(e)) return true;

    return false;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
