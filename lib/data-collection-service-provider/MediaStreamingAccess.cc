/**********************************************************************************************************************************
 * MediaStreamingAccess - C interface to the MediaStreamingAccess object
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

/*#include "MediaStreamingAccess.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccess-internal.h"
#include "openapi/model/MediaStreamingAccess.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create(






)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_t*>(new std::shared_ptr<MediaStreamingAccess>(new MediaStreamingAccess(






)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_copy(const data_collection_model_media_streaming_access_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_t*>(new std::shared_ptr<MediaStreamingAccess >(new MediaStreamingAccess(**reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_move(data_collection_model_media_streaming_access_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_t*>(new std::shared_ptr<MediaStreamingAccess >(std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_copy(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_t *other)
{
    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(other);
    return media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_t *other)
{
    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(other));
    return media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_access_free(data_collection_model_media_streaming_access_t *media_streaming_access)
{
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_access_toJSON(const data_collection_model_media_streaming_access_t *media_streaming_access, bool as_request)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_access_t*>(new std::shared_ptr<MediaStreamingAccess >(new MediaStreamingAccess(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_media_stream_handler_endpoint_address(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    typedef typename MediaStreamingAccess::MediaStreamHandlerEndpointAddressType ResultFromType;
    const ResultFromType result_from = obj->getMediaStreamHandlerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccess::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMediaStreamHandlerEndpointAddress(value)) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccess::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMediaStreamHandlerEndpointAddress(std::move(value))) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_application_server_endpoint_address(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    typedef typename MediaStreamingAccess::ApplicationServerEndpointAddressType ResultFromType;
    const ResultFromType result_from = obj->getApplicationServerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccess::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setApplicationServerEndpointAddress(value)) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccess::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setApplicationServerEndpointAddress(std::move(value))) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_media_streaming_access_request_message_t* data_collection_model_media_streaming_access_get_request_message(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    typedef typename MediaStreamingAccess::RequestMessageType ResultFromType;
    const ResultFromType result_from = obj->getRequestMessage();
    const data_collection_model_media_streaming_access_request_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_request_message_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccess::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRequestMessage(value)) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccess::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRequestMessage(std::move(value))) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_cache_status_t* data_collection_model_media_streaming_access_get_cache_status(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    typedef typename MediaStreamingAccess::CacheStatusType ResultFromType;
    const ResultFromType result_from = obj->getCacheStatus();
    const data_collection_model_cache_status_t *result = reinterpret_cast<const data_collection_model_cache_status_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_cache_status_t* p_cache_status)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccess::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setCacheStatus(value)) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_cache_status_t* p_cache_status)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccess::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setCacheStatus(std::move(value))) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_media_streaming_access_response_message_t* data_collection_model_media_streaming_access_get_response_message(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    typedef typename MediaStreamingAccess::ResponseMessageType ResultFromType;
    const ResultFromType result_from = obj->getResponseMessage();
    const data_collection_model_media_streaming_access_response_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_response_message_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccess::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setResponseMessage(value)) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccess::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setResponseMessage(std::move(value))) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_media_streaming_access_get_processing_latency(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    typedef typename MediaStreamingAccess::ProcessingLatencyType ResultFromType;
    const ResultFromType result_from = obj->getProcessingLatency();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const float p_processing_latency)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccess::ProcessingLatencyType ValueType;

    ValueType value = value_from;
    if (!obj->setProcessingLatency(value)) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, float p_processing_latency)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccess::ProcessingLatencyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setProcessingLatency(std::move(value))) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_media_streaming_access_connection_metrics_t* data_collection_model_media_streaming_access_get_connection_metrics(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    typedef typename MediaStreamingAccess::ConnectionMetricsType ResultFromType;
    const ResultFromType result_from = obj->getConnectionMetrics();
    const data_collection_model_media_streaming_access_connection_metrics_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_connection_metrics_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccess::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setConnectionMetrics(value)) return NULL;
    return obj_media_streaming_access;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (obj_media_streaming_access == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccess::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setConnectionMetrics(std::move(value))) return NULL;
    return obj_media_streaming_access;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_access_make_lnode(data_collection_model_media_streaming_access_t *p_media_streaming_access)
{
    return data_collection_lnode_create(p_media_streaming_access, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_refcount(data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

