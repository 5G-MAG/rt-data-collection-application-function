/**********************************************************************************************************************************
 * Exception - C interface to the Exception object
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

/*#include "Exception.h" already included by data-collection-sp/data-collection.h */
#include "Exception-internal.h"
#include "openapi/model/Exception.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create(


)
{
    return reinterpret_cast<data_collection_model_exception_t*>(new std::shared_ptr<Exception>(new Exception(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create_copy(const data_collection_model_exception_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_exception_t*>(new std::shared_ptr<Exception >(new Exception(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create_move(data_collection_model_exception_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Exception > *obj = reinterpret_cast<std::shared_ptr<Exception >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_copy(data_collection_model_exception_t *exception, const data_collection_model_exception_t *other)
{
    if (exception) {
        std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(exception);
        if (obj) {
            if (other) {
                const std::shared_ptr<Exception > &other_obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(other);
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
                const std::shared_ptr<Exception > &other_obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(other);
                if (other_obj) {
                    obj.reset(new Exception(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        exception = data_collection_model_exception_create_copy(other);
    }
    return exception;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_move(data_collection_model_exception_t *exception, data_collection_model_exception_t *other)
{
    std::shared_ptr<Exception > *other_ptr = reinterpret_cast<std::shared_ptr<Exception >*>(other);

    if (exception) {
        std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(exception);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                exception = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return exception;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_exception_free(data_collection_model_exception_t *exception)
{
    if (!exception) return;
    delete reinterpret_cast<std::shared_ptr<Exception >*>(exception);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_exception_toJSON(const data_collection_model_exception_t *exception, bool as_request)
{
    if (!exception) return NULL;
    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(exception);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_exception_t*>(new std::shared_ptr<Exception >(new Exception(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_is_equal_to(const data_collection_model_exception_t *first, const data_collection_model_exception_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Exception > &obj2 = *reinterpret_cast<const std::shared_ptr<Exception >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Exception > &obj1 = *reinterpret_cast<const std::shared_ptr<Exception >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_id_t* data_collection_model_exception_get_excep_id(const data_collection_model_exception_t *obj_exception)
{
    if (!obj_exception) {
        const data_collection_model_exception_id_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) {
        const data_collection_model_exception_id_t *result = NULL;
        return result;
    }

    typedef typename Exception::ExcepIdType ResultFromType;
    const ResultFromType result_from = obj->getExcepId();
    const data_collection_model_exception_id_t *result = reinterpret_cast<const data_collection_model_exception_id_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_id(data_collection_model_exception_t *obj_exception, const data_collection_model_exception_id_t* p_excep_id)
{
    if (!obj_exception) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return NULL;

    const auto &value_from = p_excep_id;
    typedef typename Exception::ExcepIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setExcepId(value)) return NULL;

    return obj_exception;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_id_move(data_collection_model_exception_t *obj_exception, data_collection_model_exception_id_t* p_excep_id)
{
    if (!obj_exception) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return NULL;

    const auto &value_from = p_excep_id;
    typedef typename Exception::ExcepIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setExcepId(std::move(value))) return NULL;

    return obj_exception;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_has_excep_level(const data_collection_model_exception_t *obj_exception)
{
    if (!obj_exception) return false;

    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return false;

    return obj->getExcepLevel().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_exception_get_excep_level(const data_collection_model_exception_t *obj_exception)
{
    if (!obj_exception) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename Exception::ExcepLevelType ResultFromType;
    const ResultFromType result_from = obj->getExcepLevel();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_level(data_collection_model_exception_t *obj_exception, const int32_t p_excep_level)
{
    if (!obj_exception) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return NULL;

    const auto &value_from = p_excep_level;
    typedef typename Exception::ExcepLevelType ValueType;

    ValueType value(value_from);

    if (!obj->setExcepLevel(value)) return NULL;

    return obj_exception;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_level_move(data_collection_model_exception_t *obj_exception, int32_t p_excep_level)
{
    if (!obj_exception) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return NULL;

    const auto &value_from = p_excep_level;
    typedef typename Exception::ExcepLevelType ValueType;

    ValueType value(value_from);

    
    if (!obj->setExcepLevel(std::move(value))) return NULL;

    return obj_exception;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_has_excep_trend(const data_collection_model_exception_t *obj_exception)
{
    if (!obj_exception) return false;

    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return false;

    return obj->getExcepTrend().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_trend_t* data_collection_model_exception_get_excep_trend(const data_collection_model_exception_t *obj_exception)
{
    if (!obj_exception) {
        const data_collection_model_exception_trend_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) {
        const data_collection_model_exception_trend_t *result = NULL;
        return result;
    }

    typedef typename Exception::ExcepTrendType ResultFromType;
    const ResultFromType result_from = obj->getExcepTrend();
    const data_collection_model_exception_trend_t *result = reinterpret_cast<const data_collection_model_exception_trend_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_trend(data_collection_model_exception_t *obj_exception, const data_collection_model_exception_trend_t* p_excep_trend)
{
    if (!obj_exception) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return NULL;

    const auto &value_from = p_excep_trend;
    typedef typename Exception::ExcepTrendType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setExcepTrend(value)) return NULL;

    return obj_exception;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_trend_move(data_collection_model_exception_t *obj_exception, data_collection_model_exception_trend_t* p_excep_trend)
{
    if (!obj_exception) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    if (!obj) return NULL;

    const auto &value_from = p_excep_trend;
    typedef typename Exception::ExcepTrendType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setExcepTrend(std::move(value))) return NULL;

    return obj_exception;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_exception_make_lnode(data_collection_model_exception_t *p_exception)
{
    return data_collection_lnode_create(p_exception, reinterpret_cast<void(*)(void*)>(data_collection_model_exception_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_exception_refcount(data_collection_model_exception_t *obj_exception)
{
    if (!obj_exception) return 0l;
    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

