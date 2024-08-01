#ifndef _LOCATION_DATA_INTERNAL_H_
#define _LOCATION_DATA_INTERNAL_H_

/**********************************************************************************************************************************
 * LocationData - C internal library interface to the LocationData object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "Ncgi.h"
// #include "RangeDirection.h"
// #include "CivicAddress.h"
// #include "GeographicArea.h"
// #include "VelocityEstimate.h"
// #include "UeAreaIndication.h"
// #include "LosNlosMeasureInd.h"
// #include "HighAccuracyGnssMetrics.h"
// #include "PeriodicEventInfo.h"
// #include "IntegrityResult.h"
// #include "r_3DRelativeLocation.h"
// #include "GnssPositioningMethodAndUsage.h"
// #include "AccuracyFulfilmentIndicator.h"
// #include "Ecgi.h"
// #include "r_2DRelativeLocation.h"
// #include "IndoorOutdoorInd.h"
// #include "PositioningMethodAndUsage.h"
// #include "LocalArea.h"
// #include "MinorLocationQoS.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_location_data_refcount(data_collection_model_location_data_t *LocationData);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _LOCATION_DATA_INTERNAL_H_ */

