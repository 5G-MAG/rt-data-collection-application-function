/**********************************************************************************************************************************
 * DataReportingRule - C interface to the DataReportingRule object
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

/*#include "DataReportingRule.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingRule-internal.h"
#include "openapi/model/DataReportingRule.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create(



)
{
    return reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule>(new DataReportingRule(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_copy(const data_collection_model_data_reporting_rule_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule >(new DataReportingRule(**reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_move(data_collection_model_data_reporting_rule_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingRule >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_copy(data_collection_model_data_reporting_rule_t *data_reporting_rule, const data_collection_model_data_reporting_rule_t *other)
{
    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(other);
    return data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, data_collection_model_data_reporting_rule_t *other)
{
    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingRule >*>(other));
    return data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_rule_free(data_collection_model_data_reporting_rule_t *data_reporting_rule)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_rule_toJSON(const data_collection_model_data_reporting_rule_t *data_reporting_rule, bool as_request)
{
    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule >(new DataReportingRule(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_reporting_rule_is_equal_to(const data_collection_model_data_reporting_rule_t *first, const data_collection_model_data_reporting_rule_t *second)
{
    const std::shared_ptr<DataReportingRule > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(first);
    const std::shared_ptr<DataReportingRule > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_rule_get_context_ids(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    typedef typename DataReportingRule::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const ogs_list_t* p_context_ids)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_context_ids;
    typedef typename DataReportingRule::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, ogs_list_t* p_context_ids)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_context_ids;
    typedef typename DataReportingRule::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_add_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, char* p_context_ids)
{
    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    typedef typename DataReportingRule::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_remove_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const char* p_context_ids)
{
    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    typedef typename DataReportingRule::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_clear_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{   
    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    obj->clearContextIds();
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const double data_collection_model_data_reporting_rule_get_reporting_probability(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    typedef typename DataReportingRule::ReportingProbabilityType ResultFromType;
    const ResultFromType result_from = obj->getReportingProbability();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const double p_reporting_probability)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_reporting_probability;
    typedef typename DataReportingRule::ReportingProbabilityType ValueType;

    ValueType value = value_from;
    if (!obj->setReportingProbability(value)) return NULL;
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, double p_reporting_probability)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_reporting_probability;
    typedef typename DataReportingRule::ReportingProbabilityType ValueType;

    ValueType value = value_from;
    
    if (!obj->setReportingProbability(std::move(value))) return NULL;
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_rule_get_reporting_format(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    typedef typename DataReportingRule::ReportingFormatType ResultFromType;
    const ResultFromType result_from = obj->getReportingFormat();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const char* p_reporting_format)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_reporting_format;
    typedef typename DataReportingRule::ReportingFormatType ValueType;

    ValueType value(value_from);
    if (!obj->setReportingFormat(value)) return NULL;
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, char* p_reporting_format)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_reporting_format;
    typedef typename DataReportingRule::ReportingFormatType ValueType;

    ValueType value(value_from);
    
    if (!obj->setReportingFormat(std::move(value))) return NULL;
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_rule_get_data_packaging_strategy(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    typedef typename DataReportingRule::DataPackagingStrategyType ResultFromType;
    const ResultFromType result_from = obj->getDataPackagingStrategy();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const char* p_data_packaging_strategy)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_data_packaging_strategy;
    typedef typename DataReportingRule::DataPackagingStrategyType ValueType;

    ValueType value(value_from);
    if (!obj->setDataPackagingStrategy(value)) return NULL;
    return obj_data_reporting_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, char* p_data_packaging_strategy)
{
    if (obj_data_reporting_rule == NULL) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    const auto &value_from = p_data_packaging_strategy;
    typedef typename DataReportingRule::DataPackagingStrategyType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDataPackagingStrategy(std::move(value))) return NULL;
    return obj_data_reporting_rule;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_rule_make_lnode(data_collection_model_data_reporting_rule_t *p_data_reporting_rule)
{
    return data_collection_lnode_create(p_data_reporting_rule, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_rule_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_rule_refcount(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

