#ifndef _DATA_COLLECTION_NO_PROFILE_MATCH_REASON_H_
#define _DATA_COLLECTION_NO_PROFILE_MATCH_REASON_H_

/**********************************************************************************************************************************
 * NoProfileMatchReason - Public C interface to the NoProfileMatchReason object
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

#include "NoProfileMatchReason_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_no_profile_match_reason_s data_collection_model_no_profile_match_reason_t;

typedef enum {
    DCM_NO_PROFILE_MATCH_REASON_NO_VAL,
    DCM_NO_PROFILE_MATCH_REASON_VAL_REQUESTER_PLMN_NOT_ALLOWED,
    DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_SUSPENDED,
    DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_UNDISCOVERABLE,
    DCM_NO_PROFILE_MATCH_REASON_VAL_QUERY_PARAMS_COMBINATION_NO_MATCH,
    DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_TYPE_NOT_SUPPORTED,
    DCM_NO_PROFILE_MATCH_REASON_VAL_UNSPECIFIED,
    DCM_NO_PROFILE_MATCH_REASON_OTHER
} data_collection_model_no_profile_match_reason_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_create_copy(const data_collection_model_no_profile_match_reason_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_create_move(data_collection_model_no_profile_match_reason_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_copy(data_collection_model_no_profile_match_reason_t *no_profile_match_reason, const data_collection_model_no_profile_match_reason_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_move(data_collection_model_no_profile_match_reason_t *no_profile_match_reason, data_collection_model_no_profile_match_reason_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_no_profile_match_reason_free(data_collection_model_no_profile_match_reason_t *no_profile_match_reason);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_no_profile_match_reason_toJSON(const data_collection_model_no_profile_match_reason_t *no_profile_match_reason, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_is_not_set(const data_collection_model_no_profile_match_reason_t *no_profile_match_reason);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_is_non_standard(const data_collection_model_no_profile_match_reason_t *no_profile_match_reason);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_e data_collection_model_no_profile_match_reason_get_enum(const data_collection_model_no_profile_match_reason_t *no_profile_match_reason);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_no_profile_match_reason_get_string(const data_collection_model_no_profile_match_reason_t *no_profile_match_reason);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_set_enum(data_collection_model_no_profile_match_reason_t *no_profile_match_reason, data_collection_model_no_profile_match_reason_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_set_string(data_collection_model_no_profile_match_reason_t *no_profile_match_reason, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type NoProfileMatchReason */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_no_profile_match_reason_make_lnode(data_collection_model_no_profile_match_reason_t *no_profile_match_reason);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NO_PROFILE_MATCH_REASON_H_ */

