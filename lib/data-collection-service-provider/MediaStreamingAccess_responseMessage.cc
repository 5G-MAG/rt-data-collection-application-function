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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create(



)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_response_message_t*>(new std::shared_ptr<MediaStreamingAccess_responseMessage>(new MediaStreamingAccess_responseMessage(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_copy(const data_collection_model_media_streaming_access_response_message_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_streaming_access_response_message_t*>(new std::shared_ptr<MediaStreamingAccess_responseMessage >(new MediaStreamingAccess_responseMessage(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_create_move(data_collection_model_media_streaming_access_response_message_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > *obj = reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_copy(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, const data_collection_model_media_streaming_access_response_message_t *other)
{
    if (media_streaming_access_response_message) {
        std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaStreamingAccess_responseMessage > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other);
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
                const std::shared_ptr<MediaStreamingAccess_responseMessage > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other);
                if (other_obj) {
                    obj.reset(new MediaStreamingAccess_responseMessage(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_streaming_access_response_message = data_collection_model_media_streaming_access_response_message_create_copy(other);
    }
    return media_streaming_access_response_message;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_move(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, data_collection_model_media_streaming_access_response_message_t *other)
{
    std::shared_ptr<MediaStreamingAccess_responseMessage > *other_ptr = reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(other);

    if (media_streaming_access_response_message) {
        std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_streaming_access_response_message = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_streaming_access_response_message;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_response_message_free(data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message)
{
    if (!media_streaming_access_response_message) return;
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_response_message_toJSON(const data_collection_model_media_streaming_access_response_message_t *media_streaming_access_response_message, bool as_request)
{
    if (!media_streaming_access_response_message) return NULL;
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(media_streaming_access_response_message);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_media_streaming_access_response_message_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_response_message_is_equal_to(const data_collection_model_media_streaming_access_response_message_t *first, const data_collection_model_media_streaming_access_response_message_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_response_code(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    if (!obj_media_streaming_access_response_message) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename MediaStreamingAccess_responseMessage::ResponseCodeType ResultFromType;
    const ResultFromType &result_from = obj->getResponseCode();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const int32_t p_response_code)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_response_code;
    typedef typename MediaStreamingAccess_responseMessage::ResponseCodeType ValueType;

    ValueType value(value_from);

    if (!obj->setResponseCode(value)) return NULL;

    return obj_media_streaming_access_response_message;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_response_code_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, int32_t p_response_code)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_response_code;
    typedef typename MediaStreamingAccess_responseMessage::ResponseCodeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setResponseCode(std::move(value))) return NULL;

    return obj_media_streaming_access_response_message;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_size(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    if (!obj_media_streaming_access_response_message) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename MediaStreamingAccess_responseMessage::SizeType ResultFromType;
    const ResultFromType &result_from = obj->getSize();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const int32_t p_size)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_size;
    typedef typename MediaStreamingAccess_responseMessage::SizeType ValueType;

    ValueType value(value_from);

    if (!obj->setSize(value)) return NULL;

    return obj_media_streaming_access_response_message;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_size_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, int32_t p_size)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_size;
    typedef typename MediaStreamingAccess_responseMessage::SizeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSize(std::move(value))) return NULL;

    return obj_media_streaming_access_response_message;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_response_message_get_body_size(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    if (!obj_media_streaming_access_response_message) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename MediaStreamingAccess_responseMessage::BodySizeType ResultFromType;
    const ResultFromType &result_from = obj->getBodySize();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const int32_t p_body_size)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_body_size;
    typedef typename MediaStreamingAccess_responseMessage::BodySizeType ValueType;

    ValueType value(value_from);

    if (!obj->setBodySize(value)) return NULL;

    return obj_media_streaming_access_response_message;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_body_size_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, int32_t p_body_size)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_body_size;
    typedef typename MediaStreamingAccess_responseMessage::BodySizeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setBodySize(std::move(value))) return NULL;

    return obj_media_streaming_access_response_message;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_response_message_has_content_type(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    if (!obj_media_streaming_access_response_message) return false;

    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return false;

    return obj->getContentType().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_response_message_get_content_type(const data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    if (!obj_media_streaming_access_response_message) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccess_responseMessage::ContentTypeType ResultFromType;
    const ResultFromType &result_from = obj->getContentType();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, const char* p_content_type)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_content_type;
    typedef typename MediaStreamingAccess_responseMessage::ContentTypeType ValueType;

    ValueType value(value_from);

    if (!obj->setContentType(value)) return NULL;

    return obj_media_streaming_access_response_message;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_response_message_t *data_collection_model_media_streaming_access_response_message_set_content_type_move(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message, char* p_content_type)
{
    if (!obj_media_streaming_access_response_message) return NULL;

    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    if (!obj) return NULL;

    const auto &value_from = p_content_type;
    typedef typename MediaStreamingAccess_responseMessage::ContentTypeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setContentType(std::move(value))) return NULL;

    return obj_media_streaming_access_response_message;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_response_message_make_lnode(data_collection_model_media_streaming_access_response_message_t *p_media_streaming_access_response_message)
{
    return data_collection_lnode_create(p_media_streaming_access_response_message, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_response_message_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_response_message_refcount(data_collection_model_media_streaming_access_response_message_t *obj_media_streaming_access_response_message)
{
    if (!obj_media_streaming_access_response_message) return 0l;
    std::shared_ptr<MediaStreamingAccess_responseMessage > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccess_responseMessage >*>(obj_media_streaming_access_response_message);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

