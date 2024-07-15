/**********************************************************************************************************************************
 * PositioningMethodAndUsage - C interface to the PositioningMethodAndUsage object
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

/*#include "PositioningMethodAndUsage.h" already included by data-collection-sp/data-collection.h */
#include "PositioningMethodAndUsage-internal.h"
#include "openapi/model/PositioningMethodAndUsage.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create(



)
{
    return reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage>(new PositioningMethodAndUsage(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_copy(const data_collection_model_positioning_method_and_usage_t *other)
{
    return reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage >(new PositioningMethodAndUsage(**reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_move(data_collection_model_positioning_method_and_usage_t *other)
{
    return reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage >(std::move(*reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_copy(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_and_usage_t *other)
{
    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
    *obj = **reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(other);
    return positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_method_and_usage_t *other)
{
    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(other));
    return positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_positioning_method_and_usage_free(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage)
{
    delete reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_positioning_method_and_usage_toJSON(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, bool as_request)
{
    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage >(new PositioningMethodAndUsage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_positioning_method_t* data_collection_model_positioning_method_and_usage_get_method(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    typedef typename PositioningMethodAndUsage::MethodType ResultFromType;
    const ResultFromType result_from = obj->getMethod();
    const data_collection_model_positioning_method_t *result = reinterpret_cast<const data_collection_model_positioning_method_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const data_collection_model_positioning_method_t* p_method)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_method;
    typedef typename PositioningMethodAndUsage::MethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMethod(value)) return NULL;
    return obj_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, data_collection_model_positioning_method_t* p_method)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_method;
    typedef typename PositioningMethodAndUsage::MethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMethod(std::move(value))) return NULL;
    return obj_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_positioning_mode_t* data_collection_model_positioning_method_and_usage_get_mode(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    typedef typename PositioningMethodAndUsage::ModeType ResultFromType;
    const ResultFromType result_from = obj->getMode();
    const data_collection_model_positioning_mode_t *result = reinterpret_cast<const data_collection_model_positioning_mode_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const data_collection_model_positioning_mode_t* p_mode)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_mode;
    typedef typename PositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMode(value)) return NULL;
    return obj_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, data_collection_model_positioning_mode_t* p_mode)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_mode;
    typedef typename PositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMode(std::move(value))) return NULL;
    return obj_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_usage_t* data_collection_model_positioning_method_and_usage_get_usage(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    typedef typename PositioningMethodAndUsage::UsageType ResultFromType;
    const ResultFromType result_from = obj->getUsage();
    const data_collection_model_usage_t *result = reinterpret_cast<const data_collection_model_usage_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const data_collection_model_usage_t* p_usage)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_usage;
    typedef typename PositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUsage(value)) return NULL;
    return obj_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, data_collection_model_usage_t* p_usage)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_usage;
    typedef typename PositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUsage(std::move(value))) return NULL;
    return obj_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_positioning_method_and_usage_get_method_code(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    typedef typename PositioningMethodAndUsage::MethodCodeType ResultFromType;
    const ResultFromType result_from = obj->getMethodCode();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const int32_t p_method_code)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_method_code;
    typedef typename PositioningMethodAndUsage::MethodCodeType ValueType;

    ValueType value = value_from;
    if (!obj->setMethodCode(value)) return NULL;
    return obj_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, int32_t p_method_code)
{
    if (obj_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    const auto &value_from = p_method_code;
    typedef typename PositioningMethodAndUsage::MethodCodeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setMethodCode(std::move(value))) return NULL;
    return obj_positioning_method_and_usage;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_positioning_method_and_usage_make_lnode(data_collection_model_positioning_method_and_usage_t *p_positioning_method_and_usage)
{
    return data_collection_lnode_create(p_positioning_method_and_usage, reinterpret_cast<void(*)(void*)>(data_collection_model_positioning_method_and_usage_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_positioning_method_and_usage_refcount(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

