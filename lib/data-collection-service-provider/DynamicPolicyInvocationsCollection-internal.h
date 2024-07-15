#ifndef _DYNAMIC_POLICY_INVOCATIONS_COLLECTION_INTERNAL_H_
#define _DYNAMIC_POLICY_INVOCATIONS_COLLECTION_INTERNAL_H_

/**********************************************************************************************************************************
 * DynamicPolicyInvocationsCollection - C internal library interface to the DynamicPolicyInvocationsCollection object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "DynamicPolicyInvocationEvent.h"
// #include "DataAggregationFunctionType.h"
// #include "ProvisioningSessionType.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_dynamic_policy_invocations_collection_refcount(data_collection_model_dynamic_policy_invocations_collection_t *DynamicPolicyInvocationsCollection);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DYNAMIC_POLICY_INVOCATIONS_COLLECTION_INTERNAL_H_ */

