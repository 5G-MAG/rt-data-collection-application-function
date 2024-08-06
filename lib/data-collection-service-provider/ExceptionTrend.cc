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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_t *data_collection_model_exception_trend_create()
{
    return reinterpret_cast<data_collection_model_exception_trend_t*>(new std::shared_ptr<ExceptionTrend>(new ExceptionTrend()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_t *data_collection_model_exception_trend_create_copy(const data_collection_model_exception_trend_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_exception_trend_t*>(new std::shared_ptr<ExceptionTrend >(new ExceptionTrend(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_t *data_collection_model_exception_trend_create_move(data_collection_model_exception_trend_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ExceptionTrend > *obj = reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_t *data_collection_model_exception_trend_copy(data_collection_model_exception_trend_t *exception_trend, const data_collection_model_exception_trend_t *other)
{
    if (exception_trend) {
        std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(exception_trend);
        if (obj) {
            if (other) {
                const std::shared_ptr<ExceptionTrend > &other_obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(other);
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
                const std::shared_ptr<ExceptionTrend > &other_obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(other);
                if (other_obj) {
                    obj.reset(new ExceptionTrend(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        exception_trend = data_collection_model_exception_trend_create_copy(other);
    }
    return exception_trend;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_t *data_collection_model_exception_trend_move(data_collection_model_exception_trend_t *exception_trend, data_collection_model_exception_trend_t *other)
{
    std::shared_ptr<ExceptionTrend > *other_ptr = reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(other);

    if (exception_trend) {
        std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(exception_trend);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                exception_trend = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return exception_trend;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_exception_trend_free(data_collection_model_exception_trend_t *exception_trend)
{
    if (!exception_trend) return;
    delete reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(exception_trend);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_exception_trend_toJSON(const data_collection_model_exception_trend_t *exception_trend, bool as_request)
{
    if (!exception_trend) return NULL;
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(exception_trend);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_t *data_collection_model_exception_trend_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_is_equal_to(const data_collection_model_exception_trend_t *first, const data_collection_model_exception_trend_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ExceptionTrend > &obj2 = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ExceptionTrend > &obj1 = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_is_not_set(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    if (!obj_exception_trend) return true;
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    if (!obj) return true;
    return obj->getValue() == ExceptionTrend::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_is_non_standard(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    if (!obj_exception_trend) return false;
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    if (!obj) return false;
    return obj->getValue() == ExceptionTrend::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_trend_e data_collection_model_exception_trend_get_enum(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    if (!obj_exception_trend)
        return DCM_EXCEPTION_TREND_NO_VAL;
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    if (!obj) return DCM_EXCEPTION_TREND_NO_VAL;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_exception_trend_get_string(const data_collection_model_exception_trend_t *obj_exception_trend)
{
    if (!obj_exception_trend) return NULL;
    const std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_set_enum(data_collection_model_exception_trend_t *obj_exception_trend, data_collection_model_exception_trend_e p_value)
{
    if (!obj_exception_trend) return false;
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    if (!obj) return false;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_trend_set_string(data_collection_model_exception_trend_t *obj_exception_trend, const char *p_value)
{
    if (!obj_exception_trend) return false;
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = ExceptionTrend::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_exception_trend_make_lnode(data_collection_model_exception_trend_t *p_exception_trend)
{
    return data_collection_lnode_create(p_exception_trend, reinterpret_cast<void(*)(void*)>(data_collection_model_exception_trend_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_exception_trend_refcount(data_collection_model_exception_trend_t *obj_exception_trend)
{
    if (!obj_exception_trend) return 0l;
    std::shared_ptr<ExceptionTrend > &obj = *reinterpret_cast<std::shared_ptr<ExceptionTrend >*>(obj_exception_trend);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

