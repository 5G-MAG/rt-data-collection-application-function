#ifndef _GNSS_ASSIST_DATA_INFO_INTERNAL_H_
#define _GNSS_ASSIST_DATA_INFO_INTERNAL_H_

/**********************************************************************************************************************************
 * GNSSAssistDataInfo - C internal library interface to the GNSSAssistDataInfo object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "GeographicalCoordinates.h"
// #include "GNSSServArea.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_gnss_assist_data_info_refcount(data_collection_model_gnss_assist_data_info_t *GNSSAssistDataInfo);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _GNSS_ASSIST_DATA_INFO_INTERNAL_H_ */

