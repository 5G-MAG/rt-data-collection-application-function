/**********************************************************************************************************************************
 * M5BitRateSpecification - C interface to the M5BitRateSpecification object
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

/*#include "M5BitRateSpecification.h" already included by data-collection-sp/data-collection.h */
#include "M5BitRateSpecification-internal.h"
#include "openapi/model/M5BitRateSpecification.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_create(


)
{
    return reinterpret_cast<data_collection_model_m5_bit_rate_specification_t*>(new std::shared_ptr<M5BitRateSpecification>(new M5BitRateSpecification(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_create_copy(const data_collection_model_m5_bit_rate_specification_t *other)
{
    return reinterpret_cast<data_collection_model_m5_bit_rate_specification_t*>(new std::shared_ptr<M5BitRateSpecification >(new M5BitRateSpecification(**reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_create_move(data_collection_model_m5_bit_rate_specification_t *other)
{
    return reinterpret_cast<data_collection_model_m5_bit_rate_specification_t*>(new std::shared_ptr<M5BitRateSpecification >(std::move(*reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_copy(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, const data_collection_model_m5_bit_rate_specification_t *other)
{
    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(m5_bit_rate_specification);
    *obj = **reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(other);
    return m5_bit_rate_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_move(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, data_collection_model_m5_bit_rate_specification_t *other)
{
    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(m5_bit_rate_specification);
    obj = std::move(*reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(other));
    return m5_bit_rate_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_m5_bit_rate_specification_free(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification)
{
    delete reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(m5_bit_rate_specification);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_m5_bit_rate_specification_toJSON(const data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, bool as_request)
{
    const std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(m5_bit_rate_specification);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_m5_bit_rate_specification_t*>(new std::shared_ptr<M5BitRateSpecification >(new M5BitRateSpecification(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_m5_bit_rate_specification_is_equal_to(const data_collection_model_m5_bit_rate_specification_t *first, const data_collection_model_m5_bit_rate_specification_t *second)
{
    const std::shared_ptr<M5BitRateSpecification > &obj1 = *reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(first);
    const std::shared_ptr<M5BitRateSpecification > &obj2 = *reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_m5_bit_rate_specification_get_maximum_requested_bit_rate(const data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification)
{
    const std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    typedef typename M5BitRateSpecification::MaximumRequestedBitRateType ResultFromType;
    const ResultFromType result_from = obj->getMaximumRequestedBitRate();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_maximum_requested_bit_rate(data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification, const char* p_maximum_requested_bit_rate)
{
    if (obj_m5_bit_rate_specification == NULL) return NULL;

    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    const auto &value_from = p_maximum_requested_bit_rate;
    typedef typename M5BitRateSpecification::MaximumRequestedBitRateType ValueType;

    ValueType value(value_from);
    if (!obj->setMaximumRequestedBitRate(value)) return NULL;
    return obj_m5_bit_rate_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_maximum_requested_bit_rate_move(data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification, char* p_maximum_requested_bit_rate)
{
    if (obj_m5_bit_rate_specification == NULL) return NULL;

    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    const auto &value_from = p_maximum_requested_bit_rate;
    typedef typename M5BitRateSpecification::MaximumRequestedBitRateType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMaximumRequestedBitRate(std::move(value))) return NULL;
    return obj_m5_bit_rate_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_m5_bit_rate_specification_get_minimum_desired_bit_rate(const data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification)
{
    const std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    typedef typename M5BitRateSpecification::MinimumDesiredBitRateType ResultFromType;
    const ResultFromType result_from = obj->getMinimumDesiredBitRate();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_desired_bit_rate(data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification, const char* p_minimum_desired_bit_rate)
{
    if (obj_m5_bit_rate_specification == NULL) return NULL;

    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    const auto &value_from = p_minimum_desired_bit_rate;
    typedef typename M5BitRateSpecification::MinimumDesiredBitRateType ValueType;

    ValueType value(value_from);
    if (!obj->setMinimumDesiredBitRate(value)) return NULL;
    return obj_m5_bit_rate_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_desired_bit_rate_move(data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification, char* p_minimum_desired_bit_rate)
{
    if (obj_m5_bit_rate_specification == NULL) return NULL;

    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    const auto &value_from = p_minimum_desired_bit_rate;
    typedef typename M5BitRateSpecification::MinimumDesiredBitRateType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMinimumDesiredBitRate(std::move(value))) return NULL;
    return obj_m5_bit_rate_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_m5_bit_rate_specification_get_minimum_requested_bit_rate(const data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification)
{
    const std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    typedef typename M5BitRateSpecification::MinimumRequestedBitRateType ResultFromType;
    const ResultFromType result_from = obj->getMinimumRequestedBitRate();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_requested_bit_rate(data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification, const char* p_minimum_requested_bit_rate)
{
    if (obj_m5_bit_rate_specification == NULL) return NULL;

    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    const auto &value_from = p_minimum_requested_bit_rate;
    typedef typename M5BitRateSpecification::MinimumRequestedBitRateType ValueType;

    ValueType value(value_from);
    if (!obj->setMinimumRequestedBitRate(value)) return NULL;
    return obj_m5_bit_rate_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_requested_bit_rate_move(data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification, char* p_minimum_requested_bit_rate)
{
    if (obj_m5_bit_rate_specification == NULL) return NULL;

    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    const auto &value_from = p_minimum_requested_bit_rate;
    typedef typename M5BitRateSpecification::MinimumRequestedBitRateType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMinimumRequestedBitRate(std::move(value))) return NULL;
    return obj_m5_bit_rate_specification;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_m5_bit_rate_specification_make_lnode(data_collection_model_m5_bit_rate_specification_t *p_m5_bit_rate_specification)
{
    return data_collection_lnode_create(p_m5_bit_rate_specification, reinterpret_cast<void(*)(void*)>(data_collection_model_m5_bit_rate_specification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_m5_bit_rate_specification_refcount(data_collection_model_m5_bit_rate_specification_t *obj_m5_bit_rate_specification)
{
    std::shared_ptr<M5BitRateSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5BitRateSpecification >*>(obj_m5_bit_rate_specification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

