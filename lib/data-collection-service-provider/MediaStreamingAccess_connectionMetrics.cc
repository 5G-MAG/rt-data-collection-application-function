/**********************************************************************************************************************************
 * MediaStreamingAccess_connectionMetrics - C interface to the MediaStreamingAccess_connectionMetrics object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "MediaStreamingAccess_connectionMetrics.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccess_connectionMetrics-internal.h"
#include "openapi/model/MediaStreamingAccess_connectionMetrics.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create(


)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_connection_metrics_t*>(new std::shared_ptr<MediaStreamingAccess_connectionMetrics>(new MediaStreamingAccess_connectionMetrics(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create_copy(const data_collection_model_media_streaming_access_connection_metrics_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_connection_metrics_t*>(new std::shared_ptr<MediaStreamingAccess_connectionMetrics >(new MediaStreamingAccess_connectionMetrics(**reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create_move(data_collection_model_media_streaming_access_connection_metrics_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_connection_metrics_t*>(new std::shared_ptr<MediaStreamingAccess_connectionMetrics >(std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_copy(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const data_collection_model_media_streaming_access_connection_metrics_t *other)
{
    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(media_streaming_access_connection_metrics);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(other);
    return media_streaming_access_connection_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, data_collection_model_media_streaming_access_connection_metrics_t *other)
{
    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(media_streaming_access_connection_metrics);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(other));
    return media_streaming_access_connection_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_access_connection_metrics_free(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics)
{
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(media_streaming_access_connection_metrics);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_access_connection_metrics_toJSON(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, bool as_request)
{
    const std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(media_streaming_access_connection_metrics);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_access_connection_metrics_t*>(new std::shared_ptr<MediaStreamingAccess_connectionMetrics >(new MediaStreamingAccess_connectionMetrics(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_media_streaming_access_connection_metrics_is_equal_to(const data_collection_model_media_streaming_access_connection_metrics_t *first, const data_collection_model_media_streaming_access_connection_metrics_t *second)
{
    const std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(first);
    const std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_media_streaming_access_connection_metrics_get_mean_network_round_trip_time(const data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics)
{
    const std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    typedef typename MediaStreamingAccess_connectionMetrics::MeanNetworkRoundTripTimeType ResultFromType;
    const ResultFromType result_from = obj->getMeanNetworkRoundTripTime();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_mean_network_round_trip_time(data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics, const float p_mean_network_round_trip_time)
{
    if (obj_media_streaming_access_connection_metrics == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    const auto &value_from = p_mean_network_round_trip_time;
    typedef typename MediaStreamingAccess_connectionMetrics::MeanNetworkRoundTripTimeType ValueType;

    ValueType value = value_from;
    if (!obj->setMeanNetworkRoundTripTime(value)) return NULL;
    return obj_media_streaming_access_connection_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_mean_network_round_trip_time_move(data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics, float p_mean_network_round_trip_time)
{
    if (obj_media_streaming_access_connection_metrics == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    const auto &value_from = p_mean_network_round_trip_time;
    typedef typename MediaStreamingAccess_connectionMetrics::MeanNetworkRoundTripTimeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setMeanNetworkRoundTripTime(std::move(value))) return NULL;
    return obj_media_streaming_access_connection_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_media_streaming_access_connection_metrics_get_network_round_trip_time_variation(const data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics)
{
    const std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    typedef typename MediaStreamingAccess_connectionMetrics::NetworkRoundTripTimeVariationType ResultFromType;
    const ResultFromType result_from = obj->getNetworkRoundTripTimeVariation();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_network_round_trip_time_variation(data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics, const float p_network_round_trip_time_variation)
{
    if (obj_media_streaming_access_connection_metrics == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    const auto &value_from = p_network_round_trip_time_variation;
    typedef typename MediaStreamingAccess_connectionMetrics::NetworkRoundTripTimeVariationType ValueType;

    ValueType value = value_from;
    if (!obj->setNetworkRoundTripTimeVariation(value)) return NULL;
    return obj_media_streaming_access_connection_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_network_round_trip_time_variation_move(data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics, float p_network_round_trip_time_variation)
{
    if (obj_media_streaming_access_connection_metrics == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    const auto &value_from = p_network_round_trip_time_variation;
    typedef typename MediaStreamingAccess_connectionMetrics::NetworkRoundTripTimeVariationType ValueType;

    ValueType value = value_from;
    
    if (!obj->setNetworkRoundTripTimeVariation(std::move(value))) return NULL;
    return obj_media_streaming_access_connection_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_media_streaming_access_connection_metrics_get_congestion_window_size(const data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics)
{
    const std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    typedef typename MediaStreamingAccess_connectionMetrics::CongestionWindowSizeType ResultFromType;
    const ResultFromType result_from = obj->getCongestionWindowSize();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_congestion_window_size(data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics, const int32_t p_congestion_window_size)
{
    if (obj_media_streaming_access_connection_metrics == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    const auto &value_from = p_congestion_window_size;
    typedef typename MediaStreamingAccess_connectionMetrics::CongestionWindowSizeType ValueType;

    ValueType value = value_from;
    if (!obj->setCongestionWindowSize(value)) return NULL;
    return obj_media_streaming_access_connection_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_congestion_window_size_move(data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics, int32_t p_congestion_window_size)
{
    if (obj_media_streaming_access_connection_metrics == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    const auto &value_from = p_congestion_window_size;
    typedef typename MediaStreamingAccess_connectionMetrics::CongestionWindowSizeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setCongestionWindowSize(std::move(value))) return NULL;
    return obj_media_streaming_access_connection_metrics;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_access_connection_metrics_make_lnode(data_collection_model_media_streaming_access_connection_metrics_t *p_media_streaming_access_connection_metrics)
{
    return data_collection_lnode_create(p_media_streaming_access_connection_metrics, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_connection_metrics_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_connection_metrics_refcount(data_collection_model_media_streaming_access_connection_metrics_t *obj_media_streaming_access_connection_metrics)
{
    std::shared_ptr<MediaStreamingAccess_connectionMetrics > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_connectionMetrics >*>(obj_media_streaming_access_connection_metrics);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

