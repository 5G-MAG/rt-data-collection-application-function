#ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_CONNECTION_METRICS_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_CONNECTION_METRICS_H_

/**********************************************************************************************************************************
 * MediaStreamingAccess_connectionMetrics - Public C interface to the MediaStreamingAccess_connectionMetrics object
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

typedef struct data_collection_model_media_streaming_access_connection_metrics_s data_collection_model_media_streaming_access_connection_metrics_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create_copy(const data_collection_model_media_streaming_access_connection_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create_move(data_collection_model_media_streaming_access_connection_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_copy(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const data_collection_model_media_streaming_access_connection_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, data_collection_model_media_streaming_access_connection_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_connection_metrics_free(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_connection_metrics_toJSON(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_connection_metrics_get_mean_network_round_trip_time(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_mean_network_round_trip_time(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const float p_mean_network_round_trip_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_mean_network_round_trip_time_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, float p_mean_network_round_trip_time);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_connection_metrics_get_network_round_trip_time_variation(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_network_round_trip_time_variation(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const float p_network_round_trip_time_variation);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_network_round_trip_time_variation_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, float p_network_round_trip_time_variation);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_connection_metrics_get_congestion_window_size(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_congestion_window_size(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const int32_t p_congestion_window_size);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_congestion_window_size_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, int32_t p_congestion_window_size);

/* lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccess_connectionMetrics */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_connection_metrics_make_lnode(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_CONNECTION_METRICS_H_ */

