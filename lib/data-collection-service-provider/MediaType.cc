/**********************************************************************************************************************************
 * MediaType - C interface to the MediaType object
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

/*#include "MediaType.h" already included by data-collection-sp/data-collection.h */
#include "MediaType-internal.h"
#include "openapi/model/MediaType.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_t *data_collection_model_media_type_create()
{
    return reinterpret_cast<data_collection_model_media_type_t*>(new std::shared_ptr<MediaType>(new MediaType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_t *data_collection_model_media_type_create_copy(const data_collection_model_media_type_t *other)
{
    return reinterpret_cast<data_collection_model_media_type_t*>(new std::shared_ptr<MediaType >(new MediaType(**reinterpret_cast<const std::shared_ptr<MediaType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_t *data_collection_model_media_type_create_move(data_collection_model_media_type_t *other)
{
    return reinterpret_cast<data_collection_model_media_type_t*>(new std::shared_ptr<MediaType >(std::move(*reinterpret_cast<std::shared_ptr<MediaType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_t *data_collection_model_media_type_copy(data_collection_model_media_type_t *media_type, const data_collection_model_media_type_t *other)
{
    std::shared_ptr<MediaType > &obj = *reinterpret_cast<std::shared_ptr<MediaType >*>(media_type);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaType >*>(other);
    return media_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_t *data_collection_model_media_type_move(data_collection_model_media_type_t *media_type, data_collection_model_media_type_t *other)
{
    std::shared_ptr<MediaType > &obj = *reinterpret_cast<std::shared_ptr<MediaType >*>(media_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaType >*>(other));
    return media_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_type_free(data_collection_model_media_type_t *media_type)
{
    delete reinterpret_cast<std::shared_ptr<MediaType >*>(media_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_type_toJSON(const data_collection_model_media_type_t *media_type, bool as_request)
{
    const std::shared_ptr<MediaType > &obj = *reinterpret_cast<const std::shared_ptr<MediaType >*>(media_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_t *data_collection_model_media_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_type_t*>(new std::shared_ptr<MediaType >(new MediaType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_media_type_is_equal_to(const data_collection_model_media_type_t *first, const data_collection_model_media_type_t *second)
{
    const std::shared_ptr<MediaType > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaType >*>(first);
    const std::shared_ptr<MediaType > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaType >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_type_is_not_set(const data_collection_model_media_type_t *obj_media_type)
{
    const std::shared_ptr<MediaType > &obj = *reinterpret_cast<const std::shared_ptr<MediaType >*>(obj_media_type);
    return obj->getValue() == MediaType::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_type_is_non_standard(const data_collection_model_media_type_t *obj_media_type)
{
    const std::shared_ptr<MediaType > &obj = *reinterpret_cast<const std::shared_ptr<MediaType >*>(obj_media_type);
    return obj->getValue() == MediaType::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_type_e data_collection_model_media_type_get_enum(const data_collection_model_media_type_t *obj_media_type)
{
    const std::shared_ptr<MediaType > &obj = *reinterpret_cast<const std::shared_ptr<MediaType >*>(obj_media_type);
    switch (obj->getValue()) {
    case MediaType::Enum::NO_VAL:
        return DCM_MEDIA_TYPE_NO_VAL;
    case MediaType::Enum::VAL_AUDIO:
        return DCM_MEDIA_TYPE_VAL_AUDIO;
    case MediaType::Enum::VAL_VIDEO:
        return DCM_MEDIA_TYPE_VAL_VIDEO;
    case MediaType::Enum::VAL_DATA:
        return DCM_MEDIA_TYPE_VAL_DATA;
    case MediaType::Enum::VAL_APPLICATION:
        return DCM_MEDIA_TYPE_VAL_APPLICATION;
    case MediaType::Enum::VAL_CONTROL:
        return DCM_MEDIA_TYPE_VAL_CONTROL;
    case MediaType::Enum::VAL_TEXT:
        return DCM_MEDIA_TYPE_VAL_TEXT;
    case MediaType::Enum::VAL_MESSAGE:
        return DCM_MEDIA_TYPE_VAL_MESSAGE;
    case MediaType::Enum::VAL_OTHER:
        return DCM_MEDIA_TYPE_VAL_OTHER;
    default:
        break;
    }
    return DCM_MEDIA_TYPE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_media_type_get_string(const data_collection_model_media_type_t *obj_media_type)
{
    const std::shared_ptr<MediaType > &obj = *reinterpret_cast<const std::shared_ptr<MediaType >*>(obj_media_type);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_type_set_enum(data_collection_model_media_type_t *obj_media_type, data_collection_model_media_type_e p_value)
{
    std::shared_ptr<MediaType > &obj = *reinterpret_cast<std::shared_ptr<MediaType >*>(obj_media_type);
    switch (p_value) {
    case DCM_MEDIA_TYPE_NO_VAL:
        *obj = MediaType::Enum::NO_VAL;
        return true;
    case DCM_MEDIA_TYPE_VAL_AUDIO:
        *obj = MediaType::Enum::VAL_AUDIO;
        return true;
    case DCM_MEDIA_TYPE_VAL_VIDEO:
        *obj = MediaType::Enum::VAL_VIDEO;
        return true;
    case DCM_MEDIA_TYPE_VAL_DATA:
        *obj = MediaType::Enum::VAL_DATA;
        return true;
    case DCM_MEDIA_TYPE_VAL_APPLICATION:
        *obj = MediaType::Enum::VAL_APPLICATION;
        return true;
    case DCM_MEDIA_TYPE_VAL_CONTROL:
        *obj = MediaType::Enum::VAL_CONTROL;
        return true;
    case DCM_MEDIA_TYPE_VAL_TEXT:
        *obj = MediaType::Enum::VAL_TEXT;
        return true;
    case DCM_MEDIA_TYPE_VAL_MESSAGE:
        *obj = MediaType::Enum::VAL_MESSAGE;
        return true;
    case DCM_MEDIA_TYPE_VAL_OTHER:
        *obj = MediaType::Enum::VAL_OTHER;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_type_set_string(data_collection_model_media_type_t *obj_media_type, const char *p_value)
{
    std::shared_ptr<MediaType > &obj = *reinterpret_cast<std::shared_ptr<MediaType >*>(obj_media_type);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = MediaType::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_type_make_lnode(data_collection_model_media_type_t *p_media_type)
{
    return data_collection_lnode_create(p_media_type, reinterpret_cast<void(*)(void*)>(data_collection_model_media_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_type_refcount(data_collection_model_media_type_t *obj_media_type)
{
    std::shared_ptr<MediaType > &obj = *reinterpret_cast<std::shared_ptr<MediaType >*>(obj_media_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

