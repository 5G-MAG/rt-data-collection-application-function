/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_COLLECTION_INTERNAL_EVENT_H
#define DATA_COLLECTION_INTERNAL_EVENT_H

#include <stdint.h>

#include "ogs-proto.h"
#include "ogs-sbi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DC_EVENT_BASE = OGS_MAX_NUM_OF_PROTO_EVENT,

    DC_EVENT_LOCAL,

    DC_EVENT_REPORTING_SESSION_CACHE,

    DC_EVENT_DATA_REPORTS_EXPIRY,

    DC_EVENT_DATA_REPORTS_CLEAR,

    MAX_NUM_OF_DC_EVENT,

} dc_event_e;

typedef enum {

    DC_LOCAL_EVENT_EXPOSURE_NOTIFICATION,
    DC_LOCAL_EVENT_REPORTING_SESSION_EXPIRY,

} dc_local_event_e;

#if INT64_MAX <= INTPTR_MAX
#define DC_LOCAL_EVENT_MARKER 0x35474d41472d4443
#else
#define DC_LOCAL_EVENT_MARKER 0x35474443
#endif

typedef struct dc_local_event_s {
    ogs_event_t ogs_event;
    dc_local_event_e local_id;
    void *data;
} dc_local_event_t;

extern ogs_event_t *_local_event_create(dc_local_event_e event_type, void *data);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_INTERNAL_EVENT_H */
