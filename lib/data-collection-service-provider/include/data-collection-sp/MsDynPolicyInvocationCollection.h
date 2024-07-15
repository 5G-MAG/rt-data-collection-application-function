#ifndef _DATA_COLLECTION_MS_DYN_POLICY_INVOCATION_COLLECTION_H_
#define _DATA_COLLECTION_MS_DYN_POLICY_INVOCATION_COLLECTION_H_

/**********************************************************************************************************************************
 * MsDynPolicyInvocationCollection - Public C interface to the MsDynPolicyInvocationCollection object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "DynamicPolicy.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ms_dyn_policy_invocation_collection_s data_collection_model_ms_dyn_policy_invocation_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_create_copy(const data_collection_model_ms_dyn_policy_invocation_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_create_move(data_collection_model_ms_dyn_policy_invocation_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_copy(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, const data_collection_model_ms_dyn_policy_invocation_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_move(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, data_collection_model_ms_dyn_policy_invocation_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ms_dyn_policy_invocation_collection_free(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ms_dyn_policy_invocation_collection_toJSON(const data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ms_dyn_policy_invocation_collection_get_ms_dyn_ply_invocs(const data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_set_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, const ogs_list_t* p_ms_dyn_ply_invocs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_set_ms_dyn_ply_invocs_move(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, ogs_list_t* p_ms_dyn_ply_invocs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_add_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, data_collection_model_dynamic_policy_t* ms_dyn_ply_invocs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_remove_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection, const data_collection_model_dynamic_policy_t* ms_dyn_ply_invocs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_dyn_policy_invocation_collection_t *data_collection_model_ms_dyn_policy_invocation_collection_clear_ms_dyn_ply_invocs(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

/* lnode helper for generating ogs_list_t nodes's of type MsDynPolicyInvocationCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ms_dyn_policy_invocation_collection_make_lnode(data_collection_model_ms_dyn_policy_invocation_collection_t *ms_dyn_policy_invocation_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MS_DYN_POLICY_INVOCATION_COLLECTION_H_ */

