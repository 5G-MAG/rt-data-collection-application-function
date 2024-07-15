#ifndef _MEDIA_STREAMING_ACCESS_EVENT_INTERNAL_H_
#define _MEDIA_STREAMING_ACCESS_EVENT_INTERNAL_H_

/**********************************************************************************************************************************
 * MediaStreamingAccessEvent - C internal library interface to the MediaStreamingAccessEvent object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "MediaStreamingAccess_requestMessage.h"
// #include "EventRecordType.h"
// #include "MediaStreamingAccess_connectionMetrics.h"
// #include "MediaStreamingAccess_responseMessage.h"
// #include "LocationArea5G.h"
// #include "Snssai.h"
// #include "EndpointAddress.h"
// #include "CacheStatus.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_media_streaming_access_event_refcount(data_collection_model_media_streaming_access_event_t *MediaStreamingAccessEvent);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _MEDIA_STREAMING_ACCESS_EVENT_INTERNAL_H_ */

