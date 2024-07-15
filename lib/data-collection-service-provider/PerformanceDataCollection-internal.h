#ifndef _PERFORMANCE_DATA_COLLECTION_INTERNAL_H_
#define _PERFORMANCE_DATA_COLLECTION_INTERNAL_H_

/**********************************************************************************************************************************
 * PerformanceDataCollection - C internal library interface to the PerformanceDataCollection object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "IpAddr.h"
// #include "FlowInfo.h"
// #include "AddrFqdn.h"
// #include "PerformanceData.h"
// #include "LocationArea5G.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_performance_data_collection_refcount(data_collection_model_performance_data_collection_t *PerformanceDataCollection);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _PERFORMANCE_DATA_COLLECTION_INTERNAL_H_ */

