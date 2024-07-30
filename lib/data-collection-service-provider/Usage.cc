/**********************************************************************************************************************************
 * Usage - C interface to the Usage object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "Usage.h" already included by data-collection-sp/data-collection.h */
#include "Usage-internal.h"
#include "openapi/model/Usage.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_t *data_collection_model_usage_create()
{
    return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage>(new Usage()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_t *data_collection_model_usage_create_copy(const data_collection_model_usage_t *other)
{
    return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage >(new Usage(**reinterpret_cast<const std::shared_ptr<Usage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_t *data_collection_model_usage_create_move(data_collection_model_usage_t *other)
{
    return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage >(std::move(*reinterpret_cast<std::shared_ptr<Usage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_t *data_collection_model_usage_copy(data_collection_model_usage_t *usage, const data_collection_model_usage_t *other)
{
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(usage);
    *obj = **reinterpret_cast<const std::shared_ptr<Usage >*>(other);
    return usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_t *data_collection_model_usage_move(data_collection_model_usage_t *usage, data_collection_model_usage_t *other)
{
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(usage);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Usage >*>(other));
    return usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_usage_free(data_collection_model_usage_t *usage)
{
    delete reinterpret_cast<std::shared_ptr<Usage >*>(usage);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_usage_toJSON(const data_collection_model_usage_t *usage, bool as_request)
{
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(usage);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_t *data_collection_model_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage >(new Usage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_usage_is_equal_to(const data_collection_model_usage_t *first, const data_collection_model_usage_t *second)
{
    const std::shared_ptr<Usage > &obj1 = *reinterpret_cast<const std::shared_ptr<Usage >*>(first);
    const std::shared_ptr<Usage > &obj2 = *reinterpret_cast<const std::shared_ptr<Usage >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_not_set(const data_collection_model_usage_t *obj_usage)
{
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    return obj->getValue() == Usage::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_non_standard(const data_collection_model_usage_t *obj_usage)
{
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    return obj->getValue() == Usage::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_e data_collection_model_usage_get_enum(const data_collection_model_usage_t *obj_usage)
{
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    switch (obj->getValue()) {
    case Usage::Enum::NO_VAL:
        return DCM_USAGE_NO_VAL;
    case Usage::Enum::VAL_UNSUCCESS:
        return DCM_USAGE_VAL_UNSUCCESS;
    case Usage::Enum::VAL_SUCCESS_RESULTS_NOT_USED:
        return DCM_USAGE_VAL_SUCCESS_RESULTS_NOT_USED;
    case Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION:
        return DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION;
    case Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION:
        return DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION;
    case Usage::Enum::VAL_SUCCESS_METHOD_NOT_DETERMINED:
        return DCM_USAGE_VAL_SUCCESS_METHOD_NOT_DETERMINED;
    default:
        break;
    }
    return DCM_USAGE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_usage_get_string(const data_collection_model_usage_t *obj_usage)
{
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_set_enum(data_collection_model_usage_t *obj_usage, data_collection_model_usage_e p_value)
{
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(obj_usage);
    switch (p_value) {
    case DCM_USAGE_NO_VAL:
        *obj = Usage::Enum::NO_VAL;
        return true;
    case DCM_USAGE_VAL_UNSUCCESS:
        *obj = Usage::Enum::VAL_UNSUCCESS;
        return true;
    case DCM_USAGE_VAL_SUCCESS_RESULTS_NOT_USED:
        *obj = Usage::Enum::VAL_SUCCESS_RESULTS_NOT_USED;
        return true;
    case DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION:
        *obj = Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION;
        return true;
    case DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION:
        *obj = Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION;
        return true;
    case DCM_USAGE_VAL_SUCCESS_METHOD_NOT_DETERMINED:
        *obj = Usage::Enum::VAL_SUCCESS_METHOD_NOT_DETERMINED;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_set_string(data_collection_model_usage_t *obj_usage, const char *p_value)
{
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(obj_usage);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = Usage::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_usage_make_lnode(data_collection_model_usage_t *p_usage)
{
    return data_collection_lnode_create(p_usage, reinterpret_cast<void(*)(void*)>(data_collection_model_usage_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_usage_refcount(data_collection_model_usage_t *obj_usage)
{
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(obj_usage);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

