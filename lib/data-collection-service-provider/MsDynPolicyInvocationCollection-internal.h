#ifndef _MS_DYN_POLICY_INVOCATION_COLLECTION_INTERNAL_H_
#define _MS_DYN_POLICY_INVOCATION_COLLECTION_INTERNAL_H_

/**********************************************************************************************************************************
 * MsDynPolicyInvocationCollection - C internal library interface to the MsDynPolicyInvocationCollection object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "DynamicPolicy.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_ms_dyn_policy_invocation_collection_refcount(data_collection_model_ms_dyn_policy_invocation_collection_t *MsDynPolicyInvocationCollection);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _MS_DYN_POLICY_INVOCATION_COLLECTION_INTERNAL_H_ */

