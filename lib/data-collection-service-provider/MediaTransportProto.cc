/**********************************************************************************************************************************
 * MediaTransportProto - C interface to the MediaTransportProto object
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

/*#include "MediaTransportProto.h" already included by data-collection-sp/data-collection.h */
#include "MediaTransportProto-internal.h"
#include "openapi/model/MediaTransportProto.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create()
{
    return reinterpret_cast<data_collection_model_media_transport_proto_t*>(new std::shared_ptr<MediaTransportProto>(new MediaTransportProto()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create_ref(const data_collection_model_media_transport_proto_t *other)
{
    return reinterpret_cast<data_collection_model_media_transport_proto_t*>(new std::shared_ptr<MediaTransportProto>(*reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create_copy(const data_collection_model_media_transport_proto_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_transport_proto_t*>(new std::shared_ptr<MediaTransportProto >(new MediaTransportProto(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create_move(data_collection_model_media_transport_proto_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaTransportProto > *obj = reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_copy(data_collection_model_media_transport_proto_t *media_transport_proto, const data_collection_model_media_transport_proto_t *other)
{
    if (media_transport_proto) {
        std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaTransportProto > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(other);
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
                const std::shared_ptr<MediaTransportProto > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(other);
                if (other_obj) {
                    obj.reset(new MediaTransportProto(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_transport_proto = data_collection_model_media_transport_proto_create_copy(other);
    }
    return media_transport_proto;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_move(data_collection_model_media_transport_proto_t *media_transport_proto, data_collection_model_media_transport_proto_t *other)
{
    std::shared_ptr<MediaTransportProto > *other_ptr = reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(other);

    if (media_transport_proto) {
        std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_transport_proto = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_transport_proto;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_transport_proto_free(data_collection_model_media_transport_proto_t *media_transport_proto)
{
    if (!media_transport_proto) return;
    delete reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_transport_proto_toJSON(const data_collection_model_media_transport_proto_t *media_transport_proto, bool as_request)
{
    if (!media_transport_proto) return NULL;
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_media_transport_proto_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_transport_proto_t*>(new std::shared_ptr<MediaTransportProto >(new MediaTransportProto(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_equal_to(const data_collection_model_media_transport_proto_t *first, const data_collection_model_media_transport_proto_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaTransportProto > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaTransportProto > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_not_set(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    if (!obj_media_transport_proto) return true;
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    if (!obj) return true;
    return obj->getValue() == MediaTransportProto::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_non_standard(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    if (!obj_media_transport_proto) return false;
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    if (!obj) return false;
    return obj->getValue() == MediaTransportProto::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_e data_collection_model_media_transport_proto_get_enum(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    if (!obj_media_transport_proto)
        return DCM_MEDIA_TRANSPORT_PROTO_NO_VAL;
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    if (!obj) return DCM_MEDIA_TRANSPORT_PROTO_NO_VAL;
    switch (obj->getValue()) {
    case MediaTransportProto::Enum::NO_VAL:
        return DCM_MEDIA_TRANSPORT_PROTO_NO_VAL;
    case MediaTransportProto::Enum::VAL_RTP:
        return DCM_MEDIA_TRANSPORT_PROTO_VAL_RTP;
    case MediaTransportProto::Enum::VAL_SRTP:
        return DCM_MEDIA_TRANSPORT_PROTO_VAL_SRTP;
    default:
        break;
    }
    return DCM_MEDIA_TRANSPORT_PROTO_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_media_transport_proto_get_string(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    if (!obj_media_transport_proto) return NULL;
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_set_enum(data_collection_model_media_transport_proto_t *obj_media_transport_proto, data_collection_model_media_transport_proto_e p_value)
{
    if (!obj_media_transport_proto) return false;
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    if (!obj) return false;
    switch (p_value) {
    case DCM_MEDIA_TRANSPORT_PROTO_NO_VAL:
        *obj = MediaTransportProto::Enum::NO_VAL;
        return true;
    case DCM_MEDIA_TRANSPORT_PROTO_VAL_RTP:
        *obj = MediaTransportProto::Enum::VAL_RTP;
        return true;
    case DCM_MEDIA_TRANSPORT_PROTO_VAL_SRTP:
        *obj = MediaTransportProto::Enum::VAL_SRTP;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_set_string(data_collection_model_media_transport_proto_t *obj_media_transport_proto, const char *p_value)
{
    if (!obj_media_transport_proto) return false;
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = MediaTransportProto::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_transport_proto_make_lnode(data_collection_model_media_transport_proto_t *p_media_transport_proto)
{
    return data_collection_lnode_create(p_media_transport_proto, reinterpret_cast<void(*)(void*)>(data_collection_model_media_transport_proto_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_transport_proto_refcount(data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    if (!obj_media_transport_proto) return 0l;
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

