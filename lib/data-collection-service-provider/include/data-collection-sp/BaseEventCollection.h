#ifndef _DATA_COLLECTION_BASE_EVENT_COLLECTION_H_
#define _DATA_COLLECTION_BASE_EVENT_COLLECTION_H_

/**********************************************************************************************************************************
 * BaseEventCollection - Public C interface to the BaseEventCollection object
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

#include "DataAggregationFunctionType.h"
#include "ProvisioningSessionType.h"
#include "AnyType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_base_event_collection_s data_collection_model_base_event_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_create_copy(const data_collection_model_base_event_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_create_move(data_collection_model_base_event_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_copy(data_collection_model_base_event_collection_t *base_event_collection, const data_collection_model_base_event_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_move(data_collection_model_base_event_collection_t *base_event_collection, data_collection_model_base_event_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_event_collection_free(data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_event_collection_toJSON(const data_collection_model_base_event_collection_t *base_event_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_collection_is_equal_to(const data_collection_model_base_event_collection_t *base_event_collection, const data_collection_model_base_event_collection_t *other_base_event_collection);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_collection_get_collection_timestamp(const data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_collection_timestamp(data_collection_model_base_event_collection_t *base_event_collection, const char* p_collection_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_collection_timestamp_move(data_collection_model_base_event_collection_t *base_event_collection, char* p_collection_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_collection_get_start_timestamp(const data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_start_timestamp(data_collection_model_base_event_collection_t *base_event_collection, const char* p_start_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_start_timestamp_move(data_collection_model_base_event_collection_t *base_event_collection, char* p_start_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_collection_get_end_timestamp(const data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_end_timestamp(data_collection_model_base_event_collection_t *base_event_collection, const char* p_end_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_end_timestamp_move(data_collection_model_base_event_collection_t *base_event_collection, char* p_end_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_base_event_collection_get_sample_count(const data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_sample_count(data_collection_model_base_event_collection_t *base_event_collection, const int32_t p_sample_count);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_sample_count_move(data_collection_model_base_event_collection_t *base_event_collection, int32_t p_sample_count);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_provisioning_session_type_t* data_collection_model_base_event_collection_get_streaming_direction(const data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_streaming_direction(data_collection_model_base_event_collection_t *base_event_collection, const data_collection_model_provisioning_session_type_t* p_streaming_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_streaming_direction_move(data_collection_model_base_event_collection_t *base_event_collection, data_collection_model_provisioning_session_type_t* p_streaming_direction);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_event_collection_get_summarisations(const data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_summarisations(data_collection_model_base_event_collection_t *base_event_collection, const ogs_list_t* p_summarisations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_summarisations_move(data_collection_model_base_event_collection_t *base_event_collection, ogs_list_t* p_summarisations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_add_summarisations(data_collection_model_base_event_collection_t *base_event_collection, data_collection_model_data_aggregation_function_type_t* summarisations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_remove_summarisations(data_collection_model_base_event_collection_t *base_event_collection, const data_collection_model_data_aggregation_function_type_t* summarisations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_clear_summarisations(data_collection_model_base_event_collection_t *base_event_collection);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_event_collection_get_records(const data_collection_model_base_event_collection_t *base_event_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_records(data_collection_model_base_event_collection_t *base_event_collection, const ogs_list_t* p_records);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_records_move(data_collection_model_base_event_collection_t *base_event_collection, ogs_list_t* p_records);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_add_records(data_collection_model_base_event_collection_t *base_event_collection, data_collection_model_any_type_t* records);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_remove_records(data_collection_model_base_event_collection_t *base_event_collection, const data_collection_model_any_type_t* records);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_clear_records(data_collection_model_base_event_collection_t *base_event_collection);

/* lnode helper for generating ogs_list_t nodes's of type BaseEventCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_event_collection_make_lnode(data_collection_model_base_event_collection_t *base_event_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_BASE_EVENT_COLLECTION_H_ */

