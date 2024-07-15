#ifndef _MEDIA_STREAMING_ACCESS_REQUEST_MESSAGE_INTERNAL_H_
#define _MEDIA_STREAMING_ACCESS_REQUEST_MESSAGE_INTERNAL_H_

/**********************************************************************************************************************************
 * MediaStreamingAccess_requestMessage - C internal library interface to the MediaStreamingAccess_requestMessage object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/


#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_media_streaming_access_request_message_refcount(data_collection_model_media_streaming_access_request_message_t *MediaStreamingAccess_requestMessage);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _MEDIA_STREAMING_ACCESS_REQUEST_MESSAGE_INTERNAL_H_ */

