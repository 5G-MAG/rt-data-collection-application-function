/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_COLLECTION_INTERNAL_EVENT_H
#define DATA_COLLECTION_INTERNAL_EVENT_H

#include "ogs-proto.h"
#include "ogs-sbi.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DC_EVENT_BASE = OGS_MAX_NUM_OF_PROTO_EVENT,

    DC_EVENT_SBI_LOCAL,

    DC_EVENT_REPORTING_SESSION_CACHE,

    DC_EVENT_DATA_REPORTS_EXPIRY,

    DC_EVENT_DATA_REPORTS_CLEAR,

    MAX_NUM_OF_DC_EVENT,

} dc_event_e;

typedef enum {

    DC_LOCAL_EVENT_EXPOSURE_NOTIFICATION,

} dc_local_event_e;


#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_INTERNAL_EVENT_H */
