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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "Exception.h" already included by data-collection-sp/data-collection.h */
#include "Exception-internal.h"
#include "openapi/model/Exception.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_create(


)
{
    return reinterpret_cast<data_collection_model_exception_t*>(new std::shared_ptr<Exception>(new Exception(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_create_copy(const data_collection_model_exception_t *other)
{
    return reinterpret_cast<data_collection_model_exception_t*>(new std::shared_ptr<Exception >(new Exception(**reinterpret_cast<const std::shared_ptr<Exception >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_create_move(data_collection_model_exception_t *other)
{
    return reinterpret_cast<data_collection_model_exception_t*>(new std::shared_ptr<Exception >(std::move(*reinterpret_cast<std::shared_ptr<Exception >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_copy(data_collection_model_exception_t *exception, const data_collection_model_exception_t *other)
{
    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(exception);
    *obj = **reinterpret_cast<const std::shared_ptr<Exception >*>(other);
    return exception;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_move(data_collection_model_exception_t *exception, data_collection_model_exception_t *other)
{
    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(exception);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Exception >*>(other));
    return exception;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_exception_free(data_collection_model_exception_t *exception)
{
    delete reinterpret_cast<std::shared_ptr<Exception >*>(exception);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_exception_toJSON(const data_collection_model_exception_t *exception, bool as_request)
{
    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(exception);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_exception_is_equal_to(const data_collection_model_exception_t *first, const data_collection_model_exception_t *second)
{
    const std::shared_ptr<Exception > &obj1 = *reinterpret_cast<const std::shared_ptr<Exception >*>(first);
    const std::shared_ptr<Exception > &obj2 = *reinterpret_cast<const std::shared_ptr<Exception >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_exception_id_t* data_collection_model_exception_get_excep_id(const data_collection_model_exception_t *obj_exception)
{
    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    typedef typename Exception::ExcepIdType ResultFromType;
    const ResultFromType result_from = obj->getExcepId();
    const data_collection_model_exception_id_t *result = reinterpret_cast<const data_collection_model_exception_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_set_excep_id(data_collection_model_exception_t *obj_exception, const data_collection_model_exception_id_t* p_excep_id)
{
    if (obj_exception == NULL) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    const auto &value_from = p_excep_id;
    typedef typename Exception::ExcepIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setExcepId(value)) return NULL;
    return obj_exception;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_set_excep_id_move(data_collection_model_exception_t *obj_exception, data_collection_model_exception_id_t* p_excep_id)
{
    if (obj_exception == NULL) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    const auto &value_from = p_excep_id;
    typedef typename Exception::ExcepIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setExcepId(std::move(value))) return NULL;
    return obj_exception;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_exception_get_excep_level(const data_collection_model_exception_t *obj_exception)
{
    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    typedef typename Exception::ExcepLevelType ResultFromType;
    const ResultFromType result_from = obj->getExcepLevel();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_set_excep_level(data_collection_model_exception_t *obj_exception, const int32_t p_excep_level)
{
    if (obj_exception == NULL) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    const auto &value_from = p_excep_level;
    typedef typename Exception::ExcepLevelType ValueType;

    ValueType value = value_from;
    if (!obj->setExcepLevel(value)) return NULL;
    return obj_exception;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_set_excep_level_move(data_collection_model_exception_t *obj_exception, int32_t p_excep_level)
{
    if (obj_exception == NULL) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    const auto &value_from = p_excep_level;
    typedef typename Exception::ExcepLevelType ValueType;

    ValueType value = value_from;
    
    if (!obj->setExcepLevel(std::move(value))) return NULL;
    return obj_exception;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_exception_trend_t* data_collection_model_exception_get_excep_trend(const data_collection_model_exception_t *obj_exception)
{
    const std::shared_ptr<Exception > &obj = *reinterpret_cast<const std::shared_ptr<Exception >*>(obj_exception);
    typedef typename Exception::ExcepTrendType ResultFromType;
    const ResultFromType result_from = obj->getExcepTrend();
    const data_collection_model_exception_trend_t *result = reinterpret_cast<const data_collection_model_exception_trend_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_set_excep_trend(data_collection_model_exception_t *obj_exception, const data_collection_model_exception_trend_t* p_excep_trend)
{
    if (obj_exception == NULL) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    const auto &value_from = p_excep_trend;
    typedef typename Exception::ExcepTrendType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setExcepTrend(value)) return NULL;
    return obj_exception;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_t *data_collection_model_exception_set_excep_trend_move(data_collection_model_exception_t *obj_exception, data_collection_model_exception_trend_t* p_excep_trend)
{
    if (obj_exception == NULL) return NULL;

    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    const auto &value_from = p_excep_trend;
    typedef typename Exception::ExcepTrendType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setExcepTrend(std::move(value))) return NULL;
    return obj_exception;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_exception_make_lnode(data_collection_model_exception_t *p_exception)
{
    return data_collection_lnode_create(p_exception, reinterpret_cast<void(*)(void*)>(data_collection_model_exception_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_exception_refcount(data_collection_model_exception_t *obj_exception)
{
    std::shared_ptr<Exception > &obj = *reinterpret_cast<std::shared_ptr<Exception >*>(obj_exception);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

