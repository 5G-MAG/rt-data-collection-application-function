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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create()
{
    return reinterpret_cast<data_collection_model_media_transport_proto_t*>(new std::shared_ptr<MediaTransportProto>(new MediaTransportProto()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create_copy(const data_collection_model_media_transport_proto_t *other)
{
    return reinterpret_cast<data_collection_model_media_transport_proto_t*>(new std::shared_ptr<MediaTransportProto >(new MediaTransportProto(**reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create_move(data_collection_model_media_transport_proto_t *other)
{
    return reinterpret_cast<data_collection_model_media_transport_proto_t*>(new std::shared_ptr<MediaTransportProto >(std::move(*reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_copy(data_collection_model_media_transport_proto_t *media_transport_proto, const data_collection_model_media_transport_proto_t *other)
{
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(other);
    return media_transport_proto;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_move(data_collection_model_media_transport_proto_t *media_transport_proto, data_collection_model_media_transport_proto_t *other)
{
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(other));
    return media_transport_proto;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_transport_proto_free(data_collection_model_media_transport_proto_t *media_transport_proto)
{
    delete reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_transport_proto_toJSON(const data_collection_model_media_transport_proto_t *media_transport_proto, bool as_request)
{
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(media_transport_proto);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_media_transport_proto_is_equal_to(const data_collection_model_media_transport_proto_t *first, const data_collection_model_media_transport_proto_t *second)
{
    const std::shared_ptr<MediaTransportProto > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(first);
    const std::shared_ptr<MediaTransportProto > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_not_set(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    return obj->getValue() == MediaTransportProto::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_non_standard(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    return obj->getValue() == MediaTransportProto::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_e data_collection_model_media_transport_proto_get_enum(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_media_transport_proto_get_string(const data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    const std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<const std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_set_enum(data_collection_model_media_transport_proto_t *obj_media_transport_proto, data_collection_model_media_transport_proto_e p_value)
{
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_set_string(data_collection_model_media_transport_proto_t *obj_media_transport_proto, const char *p_value)
{
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = MediaTransportProto::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_transport_proto_make_lnode(data_collection_model_media_transport_proto_t *p_media_transport_proto)
{
    return data_collection_lnode_create(p_media_transport_proto, reinterpret_cast<void(*)(void*)>(data_collection_model_media_transport_proto_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_transport_proto_refcount(data_collection_model_media_transport_proto_t *obj_media_transport_proto)
{
    std::shared_ptr<MediaTransportProto > &obj = *reinterpret_cast<std::shared_ptr<MediaTransportProto >*>(obj_media_transport_proto);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

