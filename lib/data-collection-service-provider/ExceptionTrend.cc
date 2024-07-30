/**********************************************************************************************************************************
 * ExceptionTrend - C interface to the ExceptionTrend object
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

/*#include "ExceptionTrend.h" already included by data-collection-sp/data-collection.h */
#include "ExceptionTrend-internal.h"
#include "openapi/model/ExceptionTrend.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_trend_t *data_collection_model_exception_trend_create()
{
    return reinterpret_cast<data_collection_model_exception_trend_t*>(new std::shared_ptr<ExceptionTrend>(new ExceptionTrend()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_trend_t *data_collection_model_exception_trend_create_copy(const data_collection_model_exception_trend_t *other)
{
    return reinterpret_cast<data_collection_model_exception_trend_t*>(new std::shared_ptr<ExceptionTrend >(new ExceptionTrend(**reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_trend_t *data_collection_model_exception_trend_create_move(data_collection_model_exception_trend_t *other)
{
    return reinterpret_cast<data_collection_model_exception_trend_t*>(new std::shared_ptr<ExceptionTrend >(std::move(*reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_trend_t *data_collection_model_exception_trend_copy(data_collection_model_exception_trend_t *exception_trend, const data_collection_model_exception_trend_t *other)
{
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(exception_trend);
    *obj = **reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(other);
    return exception_trend;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_trend_t *data_collection_model_exception_trend_move(data_collection_model_exception_trend_t *exception_trend, data_collection_model_exception_trend_t *other)
{
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(exception_trend);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(other));
    return exception_trend;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_exception_trend_free(data_collection_model_exception_trend_t *exception_trend)
{
    delete reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(exception_trend);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_exception_trend_toJSON(const data_collection_model_exception_trend_t *exception_trend, bool as_request)
{
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(exception_trend);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_trend_t *data_collection_model_exception_trend_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_exception_trend_t*>(new std::shared_ptr<ExceptionTrend >(new ExceptionTrend(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_exception_trend_is_equal_to(const data_collection_model_exception_trend_t *first, const data_collection_model_exception_trend_t *second)
{
    const std::shared_ptr<ExceptionTrend > &obj1 = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(first);
    const std::shared_ptr<ExceptionTrend > &obj2 = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_is_not_set(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    return obj->getValue() == ExceptionTrend::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_is_non_standard(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    return obj->getValue() == ExceptionTrend::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_e data_collection_model_exception_trend_get_enum(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    switch (obj->getValue()) {
    case ExceptionTrend::Enum::NO_VAL:
        return DCM_EXCEPTION_TREND_NO_VAL;
    case ExceptionTrend::Enum::VAL_UP:
        return DCM_EXCEPTION_TREND_VAL_UP;
    case ExceptionTrend::Enum::VAL_DOWN:
        return DCM_EXCEPTION_TREND_VAL_DOWN;
    case ExceptionTrend::Enum::VAL_UNKNOW:
        return DCM_EXCEPTION_TREND_VAL_UNKNOW;
    case ExceptionTrend::Enum::VAL_STABLE:
        return DCM_EXCEPTION_TREND_VAL_STABLE;
    default:
        break;
    }
    return DCM_EXCEPTION_TREND_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_exception_trend_get_string(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_set_enum(data_collection_model_exception_trend_t *obj_exception_trend, data_collection_model_exception_trend_e p_value)
{
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    switch (p_value) {
    case DCM_EXCEPTION_TREND_NO_VAL:
        *obj = ExceptionTrend::Enum::NO_VAL;
        return true;
    case DCM_EXCEPTION_TREND_VAL_UP:
        *obj = ExceptionTrend::Enum::VAL_UP;
        return true;
    case DCM_EXCEPTION_TREND_VAL_DOWN:
        *obj = ExceptionTrend::Enum::VAL_DOWN;
        return true;
    case DCM_EXCEPTION_TREND_VAL_UNKNOW:
        *obj = ExceptionTrend::Enum::VAL_UNKNOW;
        return true;
    case DCM_EXCEPTION_TREND_VAL_STABLE:
        *obj = ExceptionTrend::Enum::VAL_STABLE;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_set_string(data_collection_model_exception_trend_t *obj_exception_trend, const char *p_value)
{
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = ExceptionTrend::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_exception_trend_make_lnode(data_collection_model_exception_trend_t *p_exception_trend)
{
    return data_collection_lnode_create(p_exception_trend, reinterpret_cast<void(*)(void*)>(data_collection_model_exception_trend_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_exception_trend_refcount(data_collection_model_exception_trend_t *obj_exception_trend)
{
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

