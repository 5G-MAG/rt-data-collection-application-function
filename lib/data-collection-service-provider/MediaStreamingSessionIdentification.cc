/**********************************************************************************************************************************
 * MediaStreamingSessionIdentification - C interface to the MediaStreamingSessionIdentification object
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

/*#include "MediaStreamingSessionIdentification.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingSessionIdentification-internal.h"
#include "openapi/model/MediaStreamingSessionIdentification.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create(
)
{
    return reinterpret_cast<data_collection_model_media_streaming_session_identification_t*>(new std::shared_ptr<MediaStreamingSessionIdentification>(new MediaStreamingSessionIdentification(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_copy(const data_collection_model_media_streaming_session_identification_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_streaming_session_identification_t*>(new std::shared_ptr<MediaStreamingSessionIdentification >(new MediaStreamingSessionIdentification(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_move(data_collection_model_media_streaming_session_identification_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaStreamingSessionIdentification > *obj = reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_copy(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const data_collection_model_media_streaming_session_identification_t *other)
{
    if (media_streaming_session_identification) {
        std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaStreamingSessionIdentification > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(other);
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
                const std::shared_ptr<MediaStreamingSessionIdentification > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(other);
                if (other_obj) {
                    obj.reset(new MediaStreamingSessionIdentification(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_streaming_session_identification = data_collection_model_media_streaming_session_identification_create_copy(other);
    }
    return media_streaming_session_identification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_move(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, data_collection_model_media_streaming_session_identification_t *other)
{
    std::shared_ptr<MediaStreamingSessionIdentification > *other_ptr = reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(other);

    if (media_streaming_session_identification) {
        std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_streaming_session_identification = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_streaming_session_identification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_session_identification_free(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification)
{
    if (!media_streaming_session_identification) return;
    delete reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_session_identification_toJSON(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, bool as_request)
{
    if (!media_streaming_session_identification) return NULL;
    const std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_session_identification_t*>(new std::shared_ptr<MediaStreamingSessionIdentification >(new MediaStreamingSessionIdentification(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_media_streaming_session_identification_is_equal_to(const data_collection_model_media_streaming_session_identification_t *first, const data_collection_model_media_streaming_session_identification_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaStreamingSessionIdentification > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaStreamingSessionIdentification > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_session_identification_get_session_id(const data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification)
{
    if (!obj_media_streaming_session_identification) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingSessionIdentification::SessionIdType ResultFromType;
    const ResultFromType result_from = obj->getSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id(data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification, const char* p_session_id)
{
    if (!obj_media_streaming_session_identification) return NULL;

    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename MediaStreamingSessionIdentification::SessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSessionId(value)) return NULL;

    return obj_media_streaming_session_identification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id_move(data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification, char* p_session_id)
{
    if (!obj_media_streaming_session_identification) return NULL;

    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename MediaStreamingSessionIdentification::SessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSessionId(std::move(value))) return NULL;

    return obj_media_streaming_session_identification;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_session_identification_make_lnode(data_collection_model_media_streaming_session_identification_t *p_media_streaming_session_identification)
{
    return data_collection_lnode_create(p_media_streaming_session_identification, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_session_identification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_session_identification_refcount(data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification)
{
    if (!obj_media_streaming_session_identification) return 0l;
    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

