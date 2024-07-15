#ifndef _GEOGRAPHIC_AREA_INTERNAL_H_
#define _GEOGRAPHIC_AREA_INTERNAL_H_

/**********************************************************************************************************************************
 * GeographicArea - C internal library interface to the GeographicArea object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "PointUncertaintyCircle.h"
// #include "Point.h"
// #include "PointUncertaintyEllipse.h"
// #include "GeographicalCoordinates.h"
// #include "PointAltitude.h"
// #include "UncertaintyEllipse.h"
// #include "EllipsoidArc.h"
// #include "PointAltitudeUncertainty.h"
// #include "Polygon.h"
// #include "SupportedGADShapes.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_geographic_area_refcount(data_collection_model_geographic_area_t *GeographicArea);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _GEOGRAPHIC_AREA_INTERNAL_H_ */

