#ifndef _DATA_COLLECTION_TRAFFIC_PROFILE_H_
#define _DATA_COLLECTION_TRAFFIC_PROFILE_H_

/**********************************************************************************************************************************
 * TrafficProfile - Public C interface to the TrafficProfile object
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

#include "TrafficProfile_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_traffic_profile_s data_collection_model_traffic_profile_t;

typedef enum {
    DCM_TRAFFIC_PROFILE_NO_VAL,
    DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_UL,
    DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_DL,
    DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_UL_FIRST,
    DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_DL_FIRST,
    DCM_TRAFFIC_PROFILE_VAL_MULTI_TRANS,
    DCM_TRAFFIC_PROFILE_OTHER
} data_collection_model_traffic_profile_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create_copy(const data_collection_model_traffic_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create_move(data_collection_model_traffic_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_copy(data_collection_model_traffic_profile_t *traffic_profile, const data_collection_model_traffic_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_move(data_collection_model_traffic_profile_t *traffic_profile, data_collection_model_traffic_profile_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_traffic_profile_free(data_collection_model_traffic_profile_t *traffic_profile);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_traffic_profile_toJSON(const data_collection_model_traffic_profile_t *traffic_profile, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_equal_to(const data_collection_model_traffic_profile_t *traffic_profile, const data_collection_model_traffic_profile_t *other_traffic_profile);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_not_set(const data_collection_model_traffic_profile_t *traffic_profile);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_non_standard(const data_collection_model_traffic_profile_t *traffic_profile);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_e data_collection_model_traffic_profile_get_enum(const data_collection_model_traffic_profile_t *traffic_profile);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_traffic_profile_get_string(const data_collection_model_traffic_profile_t *traffic_profile);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_set_enum(data_collection_model_traffic_profile_t *traffic_profile, data_collection_model_traffic_profile_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_set_string(data_collection_model_traffic_profile_t *traffic_profile, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type TrafficProfile */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_traffic_profile_make_lnode(data_collection_model_traffic_profile_t *traffic_profile);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TRAFFIC_PROFILE_H_ */

