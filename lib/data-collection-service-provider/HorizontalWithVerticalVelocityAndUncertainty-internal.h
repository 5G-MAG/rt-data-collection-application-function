#ifndef _HORIZONTAL_WITH_VERTICAL_VELOCITY_AND_UNCERTAINTY_INTERNAL_H_
#define _HORIZONTAL_WITH_VERTICAL_VELOCITY_AND_UNCERTAINTY_INTERNAL_H_

/**********************************************************************************************************************************
 * HorizontalWithVerticalVelocityAndUncertainty - C internal library interface to the HorizontalWithVerticalVelocityAndUncertainty object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "VerticalDirection.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_horizontal_with_vertical_velocity_and_uncertainty_refcount(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *HorizontalWithVerticalVelocityAndUncertainty);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _HORIZONTAL_WITH_VERTICAL_VELOCITY_AND_UNCERTAINTY_INTERNAL_H_ */

