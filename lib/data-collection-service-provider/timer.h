/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_COLLECTION_TIMER_H
#define DATA_COLLECTION_TIMER_H

#include "ogs-proto.h"
#include "ogs-sbi.h"
#include "event.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DC_TIMER_BASE = OGS_MAX_NUM_OF_PROTO_TIMER,

    DC_TIMER_REPORTING_SESSION_CACHE,

    DC_TIMER_DATA_REPORTS_EXPIRY,
    
    DC_TIMER_DATA_REPORTS_CLEAR,

    DC_TIMER_EVENT_EXPOSURE_NOTIF,

    DC_TIMER_REPORTING_SESSION_EXPIRY,

    MAX_NUM_OF_DC_TIMER,

} dc_timer_e;

const char *data_collection_timer_get_name(int timer_id);

extern void dc_timer_reporting_session_cache(void *data);
extern void dc_timer_data_reports_expire(void *data); 
extern void dc_timer_data_reports_clear(void *data); 
extern void dc_timer_event_exposure_notif(void *data);
extern void dc_timer_reporting_session_expiry(void *data);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_TIMER_H */
