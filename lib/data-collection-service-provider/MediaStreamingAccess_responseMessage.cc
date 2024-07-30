/**********************************************************************************************************************************
 * MediaStreamingAccess_responseMessage - C interface to the MediaStreamingAccess_responseMessage object
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

/*#include "MediaStreamingAccess_responseMessage.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccess_responseMessage-internal.h"
#include "openapi/model/MediaStreamingAccess_responseMessage.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create(



)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_response_message_t*>(new std::shared_ptr<MediaStreamingAccess_responseMessage>(new MediaStreamingAccess_responseMessage(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_copy(const data_collection_model_media_streaming_access_response_message_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_response_message_t*>(new std::shared_ptr<MediaStreamingAccess_responseMessage >(new MediaStreamingAccess_responseMessage(**reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_move(data_collection_model_media_streaming_access_response_message_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_response_message_t*>(new std::shared_ptr<MediaStreamingAccess_responseMessage >(std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_copy(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const data_collection_model_media_streaming_access_response_message_t *other)
{
    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other);
    return media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, data_collection_model_media_streaming_access_response_message_t *other)
{
    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other));
    return media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_access_response_message_free(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message)
{
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_access_response_message_toJSON(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, bool as_request)
{
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_access_response_message_t*>(new std::shared_ptr<MediaStreamingAccess_responseMessage >(new MediaStreamingAccess_responseMessage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_media_streaming_access_response_message_is_equal_to(const data_collection_model_media_streaming_access_response_message_t *first, const data_collection_model_media_streaming_access_response_message_t *second)
{
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(first);
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_media_streaming_access_response_message_get_response_code(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    typedef typename MediaStreamingAccess_responseMessage::ResponseCodeType ResultFromType;
    const ResultFromType result_from = obj->getResponseCode();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const int32_t p_response_code)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_response_code;
    typedef typename MediaStreamingAccess_responseMessage::ResponseCodeType ValueType;

    ValueType value = value_from;
    if (!obj->setResponseCode(value)) return NULL;
    return obj_media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, int32_t p_response_code)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_response_code;
    typedef typename MediaStreamingAccess_responseMessage::ResponseCodeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setResponseCode(std::move(value))) return NULL;
    return obj_media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_media_streaming_access_response_message_get_size(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    typedef typename MediaStreamingAccess_responseMessage::SizeType ResultFromType;
    const ResultFromType result_from = obj->getSize();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const int32_t p_size)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_size;
    typedef typename MediaStreamingAccess_responseMessage::SizeType ValueType;

    ValueType value = value_from;
    if (!obj->setSize(value)) return NULL;
    return obj_media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, int32_t p_size)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_size;
    typedef typename MediaStreamingAccess_responseMessage::SizeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSize(std::move(value))) return NULL;
    return obj_media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_media_streaming_access_response_message_get_body_size(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    typedef typename MediaStreamingAccess_responseMessage::BodySizeType ResultFromType;
    const ResultFromType result_from = obj->getBodySize();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const int32_t p_body_size)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_body_size;
    typedef typename MediaStreamingAccess_responseMessage::BodySizeType ValueType;

    ValueType value = value_from;
    if (!obj->setBodySize(value)) return NULL;
    return obj_media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, int32_t p_body_size)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_body_size;
    typedef typename MediaStreamingAccess_responseMessage::BodySizeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setBodySize(std::move(value))) return NULL;
    return obj_media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_access_response_message_get_content_type(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    typedef typename MediaStreamingAccess_responseMessage::ContentTypeType ResultFromType;
    const ResultFromType result_from = obj->getContentType();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const char* p_content_type)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_content_type;
    typedef typename MediaStreamingAccess_responseMessage::ContentTypeType ValueType;

    ValueType value(value_from);
    if (!obj->setContentType(value)) return NULL;
    return obj_media_streaming_access_response_message;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, char* p_content_type)
{
    if (obj_media_streaming_access_response_message == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    const auto &value_from = p_content_type;
    typedef typename MediaStreamingAccess_responseMessage::ContentTypeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setContentType(std::move(value))) return NULL;
    return obj_media_streaming_access_response_message;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_access_response_message_make_lnode(data_collection_model_media_streaming_access_response_message_t *p_media_streaming_access_response_message)
{
    return data_collection_lnode_create(p_media_streaming_access_response_message, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_response_message_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_response_message_refcount(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

