/**********************************************************************************************************************************
 * MediaType_anyOf - C interface to the MediaType_anyOf object
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

/*#include "MediaType_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "MediaType_anyOf-internal.h"
#include "openapi/model/MediaType_anyOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_any_of_t *data_collection_model_media_type_any_of_create()
{
    return reinterpret_cast<data_collection_model_media_type_any_of_t*>(new std::shared_ptr<MediaType_anyOf>(new MediaType_anyOf()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_any_of_t *data_collection_model_media_type_any_of_create_copy(const data_collection_model_media_type_any_of_t *other)
{
    return reinterpret_cast<data_collection_model_media_type_any_of_t*>(new std::shared_ptr<MediaType_anyOf >(new MediaType_anyOf(**reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_any_of_t *data_collection_model_media_type_any_of_create_move(data_collection_model_media_type_any_of_t *other)
{
    return reinterpret_cast<data_collection_model_media_type_any_of_t*>(new std::shared_ptr<MediaType_anyOf >(std::move(*reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_any_of_t *data_collection_model_media_type_any_of_copy(data_collection_model_media_type_any_of_t *media_type_any_of, const data_collection_model_media_type_any_of_t *other)
{
    std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(media_type_any_of);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(other);
    return media_type_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_any_of_t *data_collection_model_media_type_any_of_move(data_collection_model_media_type_any_of_t *media_type_any_of, data_collection_model_media_type_any_of_t *other)
{
    std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(media_type_any_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(other));
    return media_type_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_type_any_of_free(data_collection_model_media_type_any_of_t *media_type_any_of)
{
    delete reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(media_type_any_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_type_any_of_toJSON(const data_collection_model_media_type_any_of_t *media_type_any_of, bool as_request)
{
    const std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(media_type_any_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_type_any_of_t *data_collection_model_media_type_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_type_any_of_t*>(new std::shared_ptr<MediaType_anyOf >(new MediaType_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_media_type_any_of_is_equal_to(const data_collection_model_media_type_any_of_t *first, const data_collection_model_media_type_any_of_t *second)
{
    const std::shared_ptr<MediaType_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(first);
    const std::shared_ptr<MediaType_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_type_any_of_is_not_set(const data_collection_model_media_type_any_of_t *media_type_any_of)
{
    const std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(media_type_any_of);
    return obj->getValue() == MediaType_anyOf::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_type_any_of_e data_collection_model_media_type_any_of_get_enum(const data_collection_model_media_type_any_of_t *obj_media_type_any_of)
{
    const std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(obj_media_type_any_of);
    switch (obj->getValue()) {
    case MediaType_anyOf::Enum::NO_VAL:
        return DCM_MEDIA_TYPE_ANY_OF_NO_VAL;
    case MediaType_anyOf::Enum::VAL_AUDIO:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_AUDIO;
    case MediaType_anyOf::Enum::VAL_VIDEO:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_VIDEO;
    case MediaType_anyOf::Enum::VAL_DATA:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_DATA;
    case MediaType_anyOf::Enum::VAL_APPLICATION:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_APPLICATION;
    case MediaType_anyOf::Enum::VAL_CONTROL:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_CONTROL;
    case MediaType_anyOf::Enum::VAL_TEXT:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_TEXT;
    case MediaType_anyOf::Enum::VAL_MESSAGE:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_MESSAGE;
    case MediaType_anyOf::Enum::VAL_OTHER:
        return DCM_MEDIA_TYPE_ANY_OF_VAL_OTHER;
    default:
        break;
    }
    return (data_collection_model_media_type_any_of_e)-1;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_media_type_any_of_get_string(const data_collection_model_media_type_any_of_t *obj_media_type_any_of)
{
    const std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<MediaType_anyOf >*>(obj_media_type_any_of);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_type_any_of_set_enum(data_collection_model_media_type_any_of_t *obj_media_type_any_of, data_collection_model_media_type_any_of_e p_value)
{
    std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(obj_media_type_any_of);
    switch (p_value) {
    case DCM_MEDIA_TYPE_ANY_OF_NO_VAL:
        *obj = MediaType_anyOf::Enum::NO_VAL;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_AUDIO:
        *obj = MediaType_anyOf::Enum::VAL_AUDIO;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_VIDEO:
        *obj = MediaType_anyOf::Enum::VAL_VIDEO;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_DATA:
        *obj = MediaType_anyOf::Enum::VAL_DATA;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_APPLICATION:
        *obj = MediaType_anyOf::Enum::VAL_APPLICATION;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_CONTROL:
        *obj = MediaType_anyOf::Enum::VAL_CONTROL;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_TEXT:
        *obj = MediaType_anyOf::Enum::VAL_TEXT;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_MESSAGE:
        *obj = MediaType_anyOf::Enum::VAL_MESSAGE;
        return true;
    case DCM_MEDIA_TYPE_ANY_OF_VAL_OTHER:
        *obj = MediaType_anyOf::Enum::VAL_OTHER;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_type_any_of_set_string(data_collection_model_media_type_any_of_t *obj_media_type_any_of, const char *p_value)
{
    std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(obj_media_type_any_of);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = MediaType_anyOf::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_type_any_of_make_lnode(data_collection_model_media_type_any_of_t *p_media_type_any_of)
{
    return data_collection_lnode_create(p_media_type_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_media_type_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_type_any_of_refcount(data_collection_model_media_type_any_of_t *obj_media_type_any_of)
{
    std::shared_ptr<MediaType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<MediaType_anyOf >*>(obj_media_type_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

