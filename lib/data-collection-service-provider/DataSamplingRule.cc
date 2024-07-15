/**********************************************************************************************************************************
 * DataSamplingRule - C interface to the DataSamplingRule object
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

/*#include "DataSamplingRule.h" already included by data-collection-sp/data-collection.h */
#include "DataSamplingRule-internal.h"
#include "openapi/model/DataSamplingRule.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create(

)
{
    return reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule>(new DataSamplingRule(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_copy(const data_collection_model_data_sampling_rule_t *other)
{
    return reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule >(new DataSamplingRule(**reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_move(data_collection_model_data_sampling_rule_t *other)
{
    return reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule >(std::move(*reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_copy(data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_data_sampling_rule_t *other)
{
    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
    *obj = **reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(other);
    return data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, data_collection_model_data_sampling_rule_t *other)
{
    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(other));
    return data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_sampling_rule_free(data_collection_model_data_sampling_rule_t *data_sampling_rule)
{
    delete reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_sampling_rule_toJSON(const data_collection_model_data_sampling_rule_t *data_sampling_rule, bool as_request)
{
    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule >(new DataSamplingRule(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_data_sampling_rule_get_sampling_period(const data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    typedef typename DataSamplingRule::SamplingPeriodType ResultFromType;
    const ResultFromType result_from = obj->getSamplingPeriod();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, const float p_sampling_period)
{
    if (obj_data_sampling_rule == NULL) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    const auto &value_from = p_sampling_period;
    typedef typename DataSamplingRule::SamplingPeriodType ValueType;

    ValueType value = value_from;
    if (!obj->setSamplingPeriod(value)) return NULL;
    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period_move(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, float p_sampling_period)
{
    if (obj_data_sampling_rule == NULL) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    const auto &value_from = p_sampling_period;
    typedef typename DataSamplingRule::SamplingPeriodType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSamplingPeriod(std::move(value))) return NULL;
    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_area5_g_t* data_collection_model_data_sampling_rule_get_location_filter(const data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    typedef typename DataSamplingRule::LocationFilterType ResultFromType;
    const ResultFromType result_from = obj->getLocationFilter();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, const data_collection_model_location_area5_g_t* p_location_filter)
{
    if (obj_data_sampling_rule == NULL) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    const auto &value_from = p_location_filter;
    typedef typename DataSamplingRule::LocationFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocationFilter(value)) return NULL;
    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter_move(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, data_collection_model_location_area5_g_t* p_location_filter)
{
    if (obj_data_sampling_rule == NULL) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    const auto &value_from = p_location_filter;
    typedef typename DataSamplingRule::LocationFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocationFilter(std::move(value))) return NULL;
    return obj_data_sampling_rule;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_sampling_rule_make_lnode(data_collection_model_data_sampling_rule_t *p_data_sampling_rule)
{
    return data_collection_lnode_create(p_data_sampling_rule, reinterpret_cast<void(*)(void*)>(data_collection_model_data_sampling_rule_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_sampling_rule_refcount(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

