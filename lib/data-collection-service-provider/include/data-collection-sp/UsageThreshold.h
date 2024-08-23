#ifndef _DATA_COLLECTION_USAGE_THRESHOLD_H_
#define _DATA_COLLECTION_USAGE_THRESHOLD_H_

/**********************************************************************************************************************************
 * UsageThreshold - Public C interface to the UsageThreshold object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_usage_threshold_s data_collection_model_usage_threshold_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create_copy(const data_collection_model_usage_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create_move(data_collection_model_usage_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_copy(data_collection_model_usage_threshold_t *usage_threshold, const data_collection_model_usage_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_move(data_collection_model_usage_threshold_t *usage_threshold, data_collection_model_usage_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_usage_threshold_free(data_collection_model_usage_threshold_t *usage_threshold);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_usage_threshold_toJSON(const data_collection_model_usage_threshold_t *usage_threshold, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_is_equal_to(const data_collection_model_usage_threshold_t *usage_threshold, const data_collection_model_usage_threshold_t *other_usage_threshold);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_duration(const data_collection_model_usage_threshold_t *usage_threshold);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_usage_threshold_get_duration(const data_collection_model_usage_threshold_t *usage_threshold);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_duration(data_collection_model_usage_threshold_t *usage_threshold, const int32_t p_duration);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_duration_move(data_collection_model_usage_threshold_t *usage_threshold, int32_t p_duration);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_total_volume(const data_collection_model_usage_threshold_t *usage_threshold);


DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_usage_threshold_get_total_volume(const data_collection_model_usage_threshold_t *usage_threshold);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_total_volume(data_collection_model_usage_threshold_t *usage_threshold, const int64_t p_total_volume);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_total_volume_move(data_collection_model_usage_threshold_t *usage_threshold, int64_t p_total_volume);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_downlink_volume(const data_collection_model_usage_threshold_t *usage_threshold);


DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_usage_threshold_get_downlink_volume(const data_collection_model_usage_threshold_t *usage_threshold);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_downlink_volume(data_collection_model_usage_threshold_t *usage_threshold, const int64_t p_downlink_volume);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_downlink_volume_move(data_collection_model_usage_threshold_t *usage_threshold, int64_t p_downlink_volume);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_uplink_volume(const data_collection_model_usage_threshold_t *usage_threshold);


DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_usage_threshold_get_uplink_volume(const data_collection_model_usage_threshold_t *usage_threshold);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_uplink_volume(data_collection_model_usage_threshold_t *usage_threshold, const int64_t p_uplink_volume);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_uplink_volume_move(data_collection_model_usage_threshold_t *usage_threshold, int64_t p_uplink_volume);

/* lnode helper for generating ogs_list_t nodes's of type UsageThreshold */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_usage_threshold_make_lnode(data_collection_model_usage_threshold_t *usage_threshold);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_USAGE_THRESHOLD_H_ */

