#ifndef _VELOCITY_ESTIMATE_INTERNAL_H_
#define _VELOCITY_ESTIMATE_INTERNAL_H_

/**********************************************************************************************************************************
 * VelocityEstimate - C internal library interface to the VelocityEstimate object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "HorizontalVelocityWithUncertainty.h"
// #include "HorizontalWithVerticalVelocityAndUncertainty.h"
// #include "HorizontalWithVerticalVelocity.h"
// #include "VerticalDirection.h"
// #include "HorizontalVelocity.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_velocity_estimate_refcount(data_collection_model_velocity_estimate_t *VelocityEstimate);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _VELOCITY_ESTIMATE_INTERNAL_H_ */

