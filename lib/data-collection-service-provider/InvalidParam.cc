/**********************************************************************************************************************************
 * InvalidParam - C interface to the InvalidParam object
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

/*#include "InvalidParam.h" already included by data-collection-sp/data-collection.h */
#include "InvalidParam-internal.h"
#include "openapi/model/InvalidParam.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_create(

)
{
    return reinterpret_cast<data_collection_model_invalid_param_t*>(new std::shared_ptr<InvalidParam>(new InvalidParam(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_create_copy(const data_collection_model_invalid_param_t *other)
{
    return reinterpret_cast<data_collection_model_invalid_param_t*>(new std::shared_ptr<InvalidParam >(new InvalidParam(**reinterpret_cast<const std::shared_ptr<InvalidParam >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_create_move(data_collection_model_invalid_param_t *other)
{
    return reinterpret_cast<data_collection_model_invalid_param_t*>(new std::shared_ptr<InvalidParam >(std::move(*reinterpret_cast<std::shared_ptr<InvalidParam >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_copy(data_collection_model_invalid_param_t *invalid_param, const data_collection_model_invalid_param_t *other)
{
    std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<std::shared_ptr<InvalidParam >*>(invalid_param);
    *obj = **reinterpret_cast<const std::shared_ptr<InvalidParam >*>(other);
    return invalid_param;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_move(data_collection_model_invalid_param_t *invalid_param, data_collection_model_invalid_param_t *other)
{
    std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<std::shared_ptr<InvalidParam >*>(invalid_param);
    obj = std::move(*reinterpret_cast<std::shared_ptr<InvalidParam >*>(other));
    return invalid_param;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_invalid_param_free(data_collection_model_invalid_param_t *invalid_param)
{
    delete reinterpret_cast<std::shared_ptr<InvalidParam >*>(invalid_param);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_invalid_param_toJSON(const data_collection_model_invalid_param_t *invalid_param, bool as_request)
{
    const std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<const std::shared_ptr<InvalidParam >*>(invalid_param);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_invalid_param_t*>(new std::shared_ptr<InvalidParam >(new InvalidParam(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_invalid_param_is_equal_to(const data_collection_model_invalid_param_t *first, const data_collection_model_invalid_param_t *second)
{
    const std::shared_ptr<InvalidParam > &obj1 = *reinterpret_cast<const std::shared_ptr<InvalidParam >*>(first);
    const std::shared_ptr<InvalidParam > &obj2 = *reinterpret_cast<const std::shared_ptr<InvalidParam >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_invalid_param_get_param(const data_collection_model_invalid_param_t *obj_invalid_param)
{
    const std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<const std::shared_ptr<InvalidParam >*>(obj_invalid_param);
    typedef typename InvalidParam::ParamType ResultFromType;
    const ResultFromType result_from = obj->getParam();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_param(data_collection_model_invalid_param_t *obj_invalid_param, const char* p_param)
{
    if (obj_invalid_param == NULL) return NULL;

    std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<std::shared_ptr<InvalidParam >*>(obj_invalid_param);
    const auto &value_from = p_param;
    typedef typename InvalidParam::ParamType ValueType;

    ValueType value(value_from);
    if (!obj->setParam(value)) return NULL;
    return obj_invalid_param;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_param_move(data_collection_model_invalid_param_t *obj_invalid_param, char* p_param)
{
    if (obj_invalid_param == NULL) return NULL;

    std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<std::shared_ptr<InvalidParam >*>(obj_invalid_param);
    const auto &value_from = p_param;
    typedef typename InvalidParam::ParamType ValueType;

    ValueType value(value_from);
    
    if (!obj->setParam(std::move(value))) return NULL;
    return obj_invalid_param;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_invalid_param_get_reason(const data_collection_model_invalid_param_t *obj_invalid_param)
{
    const std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<const std::shared_ptr<InvalidParam >*>(obj_invalid_param);
    typedef typename InvalidParam::ReasonType ResultFromType;
    const ResultFromType result_from = obj->getReason();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_reason(data_collection_model_invalid_param_t *obj_invalid_param, const char* p_reason)
{
    if (obj_invalid_param == NULL) return NULL;

    std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<std::shared_ptr<InvalidParam >*>(obj_invalid_param);
    const auto &value_from = p_reason;
    typedef typename InvalidParam::ReasonType ValueType;

    ValueType value(value_from);
    if (!obj->setReason(value)) return NULL;
    return obj_invalid_param;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_reason_move(data_collection_model_invalid_param_t *obj_invalid_param, char* p_reason)
{
    if (obj_invalid_param == NULL) return NULL;

    std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<std::shared_ptr<InvalidParam >*>(obj_invalid_param);
    const auto &value_from = p_reason;
    typedef typename InvalidParam::ReasonType ValueType;

    ValueType value(value_from);
    
    if (!obj->setReason(std::move(value))) return NULL;
    return obj_invalid_param;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_invalid_param_make_lnode(data_collection_model_invalid_param_t *p_invalid_param)
{
    return data_collection_lnode_create(p_invalid_param, reinterpret_cast<void(*)(void*)>(data_collection_model_invalid_param_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_invalid_param_refcount(data_collection_model_invalid_param_t *obj_invalid_param)
{
    std::shared_ptr<InvalidParam > &obj = *reinterpret_cast<std::shared_ptr<InvalidParam >*>(obj_invalid_param);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

