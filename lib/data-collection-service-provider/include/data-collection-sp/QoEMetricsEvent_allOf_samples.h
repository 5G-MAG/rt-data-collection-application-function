#ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_SAMPLES_H_
#define _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_SAMPLES_H_

/**********************************************************************************************************************************
 * QoEMetricsEvent_allOf_samples - Public C interface to the QoEMetricsEvent_allOf_samples object
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

#include "QoEMetricsEvent_allOf_metrics.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_qo_e_metrics_event_all_of_samples_s data_collection_model_qo_e_metrics_event_all_of_samples_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create_copy(const data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_copy(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_qo_e_metrics_event_all_of_samples_free(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_qo_e_metrics_event_all_of_samples_toJSON(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_sample_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_timestamp(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const char* p_sample_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_timestamp_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, char* p_sample_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_sample_duration(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_duration(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const char* p_sample_duration);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_duration_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, char* p_sample_duration);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_media_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_media_timestamp(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const char* p_media_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_media_timestamp_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, char* p_media_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_qo_e_metrics_event_all_of_samples_get_metrics(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const ogs_list_t* p_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_metrics_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, ogs_list_t* p_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_add_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, data_collection_model_qo_e_metrics_event_all_of_metrics_t* metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_remove_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const data_collection_model_qo_e_metrics_event_all_of_metrics_t* metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_clear_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/* lnode helper for generating ogs_list_t nodes's of type QoEMetricsEvent_allOf_samples */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_samples_make_lnode(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_SAMPLES_H_ */

