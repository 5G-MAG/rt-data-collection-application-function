/**********************************************************************************************************************************
 * MediaStreamingAccess_requestMessage - C interface to the MediaStreamingAccess_requestMessage object
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

/*#include "MediaStreamingAccess_requestMessage.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccess_requestMessage-internal.h"
#include "openapi/model/MediaStreamingAccess_requestMessage.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_create(









)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_request_message_t*>(new std::shared_ptr<MediaStreamingAccess_requestMessage>(new MediaStreamingAccess_requestMessage(









)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_create_copy(const data_collection_model_media_streaming_access_request_message_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_request_message_t*>(new std::shared_ptr<MediaStreamingAccess_requestMessage >(new MediaStreamingAccess_requestMessage(**reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_create_move(data_collection_model_media_streaming_access_request_message_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_request_message_t*>(new std::shared_ptr<MediaStreamingAccess_requestMessage >(std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_copy(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, const data_collection_model_media_streaming_access_request_message_t *other)
{
    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(media_streaming_access_request_message);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(other);
    return media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_move(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, data_collection_model_media_streaming_access_request_message_t *other)
{
    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(media_streaming_access_request_message);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(other));
    return media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_access_request_message_free(data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message)
{
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(media_streaming_access_request_message);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_access_request_message_toJSON(const data_collection_model_media_streaming_access_request_message_t *media_streaming_access_request_message, bool as_request)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(media_streaming_access_request_message);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_access_request_message_t*>(new std::shared_ptr<MediaStreamingAccess_requestMessage >(new MediaStreamingAccess_requestMessage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_method(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::MethodType ResultFromType;
    const ResultFromType result_from = obj->getMethod();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_method(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_method)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_method;
    typedef typename MediaStreamingAccess_requestMessage::MethodType ValueType;

    ValueType value(value_from);
    if (!obj->setMethod(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_method_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_method)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_method;
    typedef typename MediaStreamingAccess_requestMessage::MethodType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMethod(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_url(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::UrlType ResultFromType;
    const ResultFromType result_from = obj->getUrl();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_url(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_url)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_url;
    typedef typename MediaStreamingAccess_requestMessage::UrlType ValueType;

    ValueType value(value_from);
    if (!obj->setUrl(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_url_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_url)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_url;
    typedef typename MediaStreamingAccess_requestMessage::UrlType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUrl(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_protocol_version(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::ProtocolVersionType ResultFromType;
    const ResultFromType result_from = obj->getProtocolVersion();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_protocol_version(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_protocol_version)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_protocol_version;
    typedef typename MediaStreamingAccess_requestMessage::ProtocolVersionType ValueType;

    ValueType value(value_from);
    if (!obj->setProtocolVersion(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_protocol_version_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_protocol_version)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_protocol_version;
    typedef typename MediaStreamingAccess_requestMessage::ProtocolVersionType ValueType;

    ValueType value(value_from);
    
    if (!obj->setProtocolVersion(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_range(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::RangeType ResultFromType;
    const ResultFromType result_from = obj->getRange();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_range(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_range)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_range;
    typedef typename MediaStreamingAccess_requestMessage::RangeType ValueType;

    ValueType value(value_from);
    if (!obj->setRange(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_range_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_range)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_range;
    typedef typename MediaStreamingAccess_requestMessage::RangeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRange(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_media_streaming_access_request_message_get_size(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::SizeType ResultFromType;
    const ResultFromType result_from = obj->getSize();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_size(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const int32_t p_size)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_size;
    typedef typename MediaStreamingAccess_requestMessage::SizeType ValueType;

    ValueType value = value_from;
    if (!obj->setSize(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_size_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, int32_t p_size)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_size;
    typedef typename MediaStreamingAccess_requestMessage::SizeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSize(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_media_streaming_access_request_message_get_body_size(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::BodySizeType ResultFromType;
    const ResultFromType result_from = obj->getBodySize();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_body_size(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const int32_t p_body_size)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_body_size;
    typedef typename MediaStreamingAccess_requestMessage::BodySizeType ValueType;

    ValueType value = value_from;
    if (!obj->setBodySize(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_body_size_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, int32_t p_body_size)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_body_size;
    typedef typename MediaStreamingAccess_requestMessage::BodySizeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setBodySize(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_content_type(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::ContentTypeType ResultFromType;
    const ResultFromType result_from = obj->getContentType();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_content_type(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_content_type)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_content_type;
    typedef typename MediaStreamingAccess_requestMessage::ContentTypeType ValueType;

    ValueType value(value_from);
    if (!obj->setContentType(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_content_type_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_content_type)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_content_type;
    typedef typename MediaStreamingAccess_requestMessage::ContentTypeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setContentType(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_user_agent(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::UserAgentType ResultFromType;
    const ResultFromType result_from = obj->getUserAgent();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_agent(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_user_agent)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_user_agent;
    typedef typename MediaStreamingAccess_requestMessage::UserAgentType ValueType;

    ValueType value(value_from);
    if (!obj->setUserAgent(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_agent_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_user_agent)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_user_agent;
    typedef typename MediaStreamingAccess_requestMessage::UserAgentType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUserAgent(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_user_identity(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::UserIdentityType ResultFromType;
    const ResultFromType result_from = obj->getUserIdentity();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_identity(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_user_identity)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_user_identity;
    typedef typename MediaStreamingAccess_requestMessage::UserIdentityType ValueType;

    ValueType value(value_from);
    if (!obj->setUserIdentity(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_user_identity_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_user_identity)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_user_identity;
    typedef typename MediaStreamingAccess_requestMessage::UserIdentityType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUserIdentity(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_request_message_get_referer(const data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    const std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    typedef typename MediaStreamingAccess_requestMessage::RefererType ResultFromType;
    const ResultFromType result_from = obj->getReferer();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_referer(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, const char* p_referer)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_referer;
    typedef typename MediaStreamingAccess_requestMessage::RefererType ValueType;

    ValueType value(value_from);
    if (!obj->setReferer(value)) return NULL;
    return obj_media_streaming_access_request_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_request_message_t *data_collection_model_media_streaming_access_request_message_set_referer_move(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message, char* p_referer)
{
    if (obj_media_streaming_access_request_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    const auto &value_from = p_referer;
    typedef typename MediaStreamingAccess_requestMessage::RefererType ValueType;

    ValueType value(value_from);
    
    if (!obj->setReferer(std::move(value))) return NULL;
    return obj_media_streaming_access_request_message;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_access_request_message_make_lnode(data_collection_model_media_streaming_access_request_message_t *p_media_streaming_access_request_message)
{
    return data_collection_lnode_create(p_media_streaming_access_request_message, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_request_message_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_request_message_refcount(data_collection_model_media_streaming_access_request_message_t *obj_media_streaming_access_request_message)
{
    std::shared_ptr<MediaStreamingAccess_requestMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_requestMessage >*>(obj_media_streaming_access_request_message);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

