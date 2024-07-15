#ifndef _DISPERSION_COLLECTION_INTERNAL_H_
#define _DISPERSION_COLLECTION_INTERNAL_H_

/**********************************************************************************************************************************
 * DispersionCollection - C internal library interface to the DispersionCollection object
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
// #include "UsageThreshold.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_dispersion_collection_refcount(data_collection_model_dispersion_collection_t *DispersionCollection);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DISPERSION_COLLECTION_INTERNAL_H_ */

