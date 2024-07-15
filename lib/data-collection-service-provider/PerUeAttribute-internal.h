#ifndef _PER_UE_ATTRIBUTE_INTERNAL_H_
#define _PER_UE_ATTRIBUTE_INTERNAL_H_

/**********************************************************************************************************************************
 * PerUeAttribute - C internal library interface to the PerUeAttribute object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "LocationArea5G.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_per_ue_attribute_refcount(data_collection_model_per_ue_attribute_t *PerUeAttribute);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _PER_UE_ATTRIBUTE_INTERNAL_H_ */

