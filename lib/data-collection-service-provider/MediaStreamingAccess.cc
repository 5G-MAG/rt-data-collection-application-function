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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create(






)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_t*>(new std::shared_ptr<MediaStreamingAccess>(new MediaStreamingAccess(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_ref(const data_collection_model_media_streaming_access_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_t*>(new std::shared_ptr<MediaStreamingAccess>(*reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_copy(const data_collection_model_media_streaming_access_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_streaming_access_t*>(new std::shared_ptr<MediaStreamingAccess >(new MediaStreamingAccess(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_create_move(data_collection_model_media_streaming_access_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaStreamingAccess > *obj = reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_copy(data_collection_model_media_streaming_access_t *media_streaming_access, const data_collection_model_media_streaming_access_t *other)
{
    if (media_streaming_access) {
        std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaStreamingAccess > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(other);
                if (other_obj) {
                    *obj = *other_obj;
                } else {
                    obj.reset();
                }
            } else {
                obj.reset();
            }
        } else {
            if (other) {
                const std::shared_ptr<MediaStreamingAccess > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(other);
                if (other_obj) {
                    obj.reset(new MediaStreamingAccess(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_streaming_access = data_collection_model_media_streaming_access_create_copy(other);
    }
    return media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_move(data_collection_model_media_streaming_access_t *media_streaming_access, data_collection_model_media_streaming_access_t *other)
{
    std::shared_ptr<MediaStreamingAccess > *other_ptr = reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(other);

    if (media_streaming_access) {
        std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_streaming_access = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_free(data_collection_model_media_streaming_access_t *media_streaming_access)
{
    if (!media_streaming_access) return;
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_toJSON(const data_collection_model_media_streaming_access_t *media_streaming_access, bool as_request)
{
    if (!media_streaming_access) return NULL;
    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(media_streaming_access);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_media_streaming_access_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_is_equal_to(const data_collection_model_media_streaming_access_t *first, const data_collection_model_media_streaming_access_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaStreamingAccess > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaStreamingAccess > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }
    
    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* different shared_ptr objects pointing to different instances, so compare instances */
    return (*obj1 == *obj2);
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_media_stream_handler_endpoint_address(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccess::MediaStreamHandlerEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getMediaStreamHandlerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccess::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMediaStreamHandlerEndpointAddress(value)) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_media_stream_handler_endpoint_address_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccess::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMediaStreamHandlerEndpointAddress(std::move(value))) return NULL;
    data_collection_model_endpoint_address_free
(p_media_stream_handler_endpoint_address);

    return obj_media_streaming_access;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_get_application_server_endpoint_address(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccess::ApplicationServerEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getApplicationServerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccess::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setApplicationServerEndpointAddress(value)) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_application_server_endpoint_address_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccess::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setApplicationServerEndpointAddress(std::move(value))) return NULL;
    data_collection_model_endpoint_address_free
(p_application_server_endpoint_address);

    return obj_media_streaming_access;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_request_message_t* data_collection_model_media_streaming_access_get_request_message(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) {
        const data_collection_model_media_streaming_access_request_message_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) {
        const data_collection_model_media_streaming_access_request_message_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccess::RequestMessageType ResultFromType;
    const ResultFromType &result_from = obj->getRequestMessage();
    const data_collection_model_media_streaming_access_request_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_request_message_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccess::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRequestMessage(value)) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_request_message_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccess::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRequestMessage(std::move(value))) return NULL;
    data_collection_model_media_streaming_access_request_message_free
(p_request_message);

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_has_cache_status(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) return false;

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return false;

    return obj->getCacheStatus().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cache_status_t* data_collection_model_media_streaming_access_get_cache_status(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) {
        const data_collection_model_cache_status_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) {
        const data_collection_model_cache_status_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccess::CacheStatusType ResultFromType;
    const ResultFromType &result_from = obj->getCacheStatus();
    const data_collection_model_cache_status_t *result = reinterpret_cast<const data_collection_model_cache_status_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_cache_status_t* p_cache_status)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccess::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setCacheStatus(value)) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_cache_status_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_cache_status_t* p_cache_status)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccess::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setCacheStatus(std::move(value))) return NULL;
    data_collection_model_cache_status_free
(p_cache_status);

    return obj_media_streaming_access;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_response_message_t* data_collection_model_media_streaming_access_get_response_message(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) {
        const data_collection_model_media_streaming_access_response_message_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) {
        const data_collection_model_media_streaming_access_response_message_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccess::ResponseMessageType ResultFromType;
    const ResultFromType &result_from = obj->getResponseMessage();
    const data_collection_model_media_streaming_access_response_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_response_message_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccess::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setResponseMessage(value)) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_response_message_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccess::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setResponseMessage(std::move(value))) return NULL;
    data_collection_model_media_streaming_access_response_message_free
(p_response_message);

    return obj_media_streaming_access;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_get_processing_latency(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename MediaStreamingAccess::ProcessingLatencyType ResultFromType;
    const ResultFromType &result_from = obj->getProcessingLatency();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const float p_processing_latency)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccess::ProcessingLatencyType ValueType;

    ValueType value(value_from);

    if (!obj->setProcessingLatency(value)) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_processing_latency_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, float p_processing_latency)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccess::ProcessingLatencyType ValueType;

    ValueType value(value_from);

    if (!obj->setProcessingLatency(std::move(value))) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_has_connection_metrics(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) return false;

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return false;

    return obj->getConnectionMetrics().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_connection_metrics_t* data_collection_model_media_streaming_access_get_connection_metrics(const data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) {
        const data_collection_model_media_streaming_access_connection_metrics_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) {
        const data_collection_model_media_streaming_access_connection_metrics_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccess::ConnectionMetricsType ResultFromType;
    const ResultFromType &result_from = obj->getConnectionMetrics();
    const data_collection_model_media_streaming_access_connection_metrics_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_connection_metrics_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics(data_collection_model_media_streaming_access_t *obj_media_streaming_access, const data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccess::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setConnectionMetrics(value)) return NULL;

    return obj_media_streaming_access;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_t *data_collection_model_media_streaming_access_set_connection_metrics_move(data_collection_model_media_streaming_access_t *obj_media_streaming_access, data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (!obj_media_streaming_access) return NULL;

    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    if (!obj) return NULL;

    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccess::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setConnectionMetrics(std::move(value))) return NULL;
    data_collection_model_media_streaming_access_connection_metrics_free
(p_connection_metrics);

    return obj_media_streaming_access;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_make_lnode(data_collection_model_media_streaming_access_t *p_media_streaming_access)
{
    return data_collection_lnode_create(p_media_streaming_access, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_refcount(data_collection_model_media_streaming_access_t *obj_media_streaming_access)
{
    if (!obj_media_streaming_access) return 0l;
    std::shared_ptr<MediaStreamingAccess > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess >*>(obj_media_streaming_access);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

