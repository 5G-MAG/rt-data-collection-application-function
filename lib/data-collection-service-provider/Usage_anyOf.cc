/**********************************************************************************************************************************
 * Usage_anyOf - C interface to the Usage_anyOf object
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

/*#include "Usage_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "Usage_anyOf-internal.h"
#include "openapi/model/Usage_anyOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_any_of_t *data_collection_model_usage_any_of_create()
{
    return reinterpret_cast<data_collection_model_usage_any_of_t*>(new std::shared_ptr<Usage_anyOf>(new Usage_anyOf()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_any_of_t *data_collection_model_usage_any_of_create_copy(const data_collection_model_usage_any_of_t *other)
{
    return reinterpret_cast<data_collection_model_usage_any_of_t*>(new std::shared_ptr<Usage_anyOf >(new Usage_anyOf(**reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_any_of_t *data_collection_model_usage_any_of_create_move(data_collection_model_usage_any_of_t *other)
{
    return reinterpret_cast<data_collection_model_usage_any_of_t*>(new std::shared_ptr<Usage_anyOf >(std::move(*reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_any_of_t *data_collection_model_usage_any_of_copy(data_collection_model_usage_any_of_t *usage_any_of, const data_collection_model_usage_any_of_t *other)
{
    std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(usage_any_of);
    *obj = **reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(other);
    return usage_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_any_of_t *data_collection_model_usage_any_of_move(data_collection_model_usage_any_of_t *usage_any_of, data_collection_model_usage_any_of_t *other)
{
    std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(usage_any_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(other));
    return usage_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_usage_any_of_free(data_collection_model_usage_any_of_t *usage_any_of)
{
    delete reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(usage_any_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_usage_any_of_toJSON(const data_collection_model_usage_any_of_t *usage_any_of, bool as_request)
{
    const std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(usage_any_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_any_of_t *data_collection_model_usage_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_usage_any_of_t*>(new std::shared_ptr<Usage_anyOf >(new Usage_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_usage_any_of_is_equal_to(const data_collection_model_usage_any_of_t *first, const data_collection_model_usage_any_of_t *second)
{
    const std::shared_ptr<Usage_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(first);
    const std::shared_ptr<Usage_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_any_of_is_not_set(const data_collection_model_usage_any_of_t *usage_any_of)
{
    const std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(usage_any_of);
    return obj->getValue() == Usage_anyOf::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_any_of_e data_collection_model_usage_any_of_get_enum(const data_collection_model_usage_any_of_t *obj_usage_any_of)
{
    const std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(obj_usage_any_of);
    switch (obj->getValue()) {
    case Usage_anyOf::Enum::NO_VAL:
        return DCM_USAGE_ANY_OF_NO_VAL;
    case Usage_anyOf::Enum::VAL_UNSUCCESS:
        return DCM_USAGE_ANY_OF_VAL_UNSUCCESS;
    case Usage_anyOf::Enum::VAL_SUCCESS_RESULTS_NOT_USED:
        return DCM_USAGE_ANY_OF_VAL_SUCCESS_RESULTS_NOT_USED;
    case Usage_anyOf::Enum::VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION:
        return DCM_USAGE_ANY_OF_VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION;
    case Usage_anyOf::Enum::VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION:
        return DCM_USAGE_ANY_OF_VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION;
    case Usage_anyOf::Enum::VAL_SUCCESS_METHOD_NOT_DETERMINED:
        return DCM_USAGE_ANY_OF_VAL_SUCCESS_METHOD_NOT_DETERMINED;
    default:
        break;
    }
    return (data_collection_model_usage_any_of_e)-1;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_usage_any_of_get_string(const data_collection_model_usage_any_of_t *obj_usage_any_of)
{
    const std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Usage_anyOf >*>(obj_usage_any_of);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_any_of_set_enum(data_collection_model_usage_any_of_t *obj_usage_any_of, data_collection_model_usage_any_of_e p_value)
{
    std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(obj_usage_any_of);
    switch (p_value) {
    case DCM_USAGE_ANY_OF_NO_VAL:
        *obj = Usage_anyOf::Enum::NO_VAL;
        return true;
    case DCM_USAGE_ANY_OF_VAL_UNSUCCESS:
        *obj = Usage_anyOf::Enum::VAL_UNSUCCESS;
        return true;
    case DCM_USAGE_ANY_OF_VAL_SUCCESS_RESULTS_NOT_USED:
        *obj = Usage_anyOf::Enum::VAL_SUCCESS_RESULTS_NOT_USED;
        return true;
    case DCM_USAGE_ANY_OF_VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION:
        *obj = Usage_anyOf::Enum::VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION;
        return true;
    case DCM_USAGE_ANY_OF_VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION:
        *obj = Usage_anyOf::Enum::VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION;
        return true;
    case DCM_USAGE_ANY_OF_VAL_SUCCESS_METHOD_NOT_DETERMINED:
        *obj = Usage_anyOf::Enum::VAL_SUCCESS_METHOD_NOT_DETERMINED;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_any_of_set_string(data_collection_model_usage_any_of_t *obj_usage_any_of, const char *p_value)
{
    std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(obj_usage_any_of);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = Usage_anyOf::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_usage_any_of_make_lnode(data_collection_model_usage_any_of_t *p_usage_any_of)
{
    return data_collection_lnode_create(p_usage_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_usage_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_usage_any_of_refcount(data_collection_model_usage_any_of_t *obj_usage_any_of)
{
    std::shared_ptr<Usage_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Usage_anyOf >*>(obj_usage_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

