/**********************************************************************************************************************************
 * DataReportingCondition - C interface to the DataReportingCondition object
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

/*#include "DataReportingCondition.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingCondition-internal.h"
#include "openapi/model/DataReportingCondition.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create(






)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition>(new DataReportingCondition(






)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_copy(const data_collection_model_data_reporting_condition_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition >(new DataReportingCondition(**reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_move(data_collection_model_data_reporting_condition_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_copy(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_t *other)
{
    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(other);
    return data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_t *other)
{
    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(other));
    return data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_condition_free(data_collection_model_data_reporting_condition_t *data_reporting_condition)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_condition_toJSON(const data_collection_model_data_reporting_condition_t *data_reporting_condition, bool as_request)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition >(new DataReportingCondition(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_reporting_condition_is_equal_to(const data_collection_model_data_reporting_condition_t *first, const data_collection_model_data_reporting_condition_t *second)
{
    const std::shared_ptr<DataReportingCondition > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(first);
    const std::shared_ptr<DataReportingCondition > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_condition_get_context_ids(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::ContextIdsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const ogs_list_t* p_context_ids)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_context_ids;
    typedef typename DataReportingCondition::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, ogs_list_t* p_context_ids)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_context_ids;
    typedef typename DataReportingCondition::ContextIdsType ValueType;

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
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_add_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, char* p_context_ids)
{
    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_remove_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const char* p_context_ids)
{
    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_clear_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{   
    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    obj->clearContextIds();
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_data_reporting_condition_type_t* data_collection_model_data_reporting_condition_get_type(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::TypeType ResultFromType;
    const ResultFromType result_from = obj->getType();
    const data_collection_model_data_reporting_condition_type_t *result = reinterpret_cast<const data_collection_model_data_reporting_condition_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const data_collection_model_data_reporting_condition_type_t* p_type)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_type;
    typedef typename DataReportingCondition::TypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setType(value)) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, data_collection_model_data_reporting_condition_type_t* p_type)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_type;
    typedef typename DataReportingCondition::TypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setType(std::move(value))) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_data_reporting_condition_get_period(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::PeriodType ResultFromType;
    const ResultFromType result_from = obj->getPeriod();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const int32_t p_period)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_period;
    typedef typename DataReportingCondition::PeriodType ValueType;

    ValueType value = value_from;
    if (!obj->setPeriod(value)) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, int32_t p_period)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_period;
    typedef typename DataReportingCondition::PeriodType ValueType;

    ValueType value = value_from;
    
    if (!obj->setPeriod(std::move(value))) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_condition_get_parameter(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::ParameterType ResultFromType;
    const ResultFromType result_from = obj->getParameter();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const char* p_parameter)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_parameter;
    typedef typename DataReportingCondition::ParameterType ValueType;

    ValueType value(value_from);
    if (!obj->setParameter(value)) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, char* p_parameter)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_parameter;
    typedef typename DataReportingCondition::ParameterType ValueType;

    ValueType value(value_from);
    
    if (!obj->setParameter(std::move(value))) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_data_reporting_condition_threshold_t* data_collection_model_data_reporting_condition_get_threshold(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::ThresholdType ResultFromType;
    const ResultFromType result_from = obj->getThreshold();
    const data_collection_model_data_reporting_condition_threshold_t *result = reinterpret_cast<const data_collection_model_data_reporting_condition_threshold_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const data_collection_model_data_reporting_condition_threshold_t* p_threshold)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_threshold;
    typedef typename DataReportingCondition::ThresholdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setThreshold(value)) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, data_collection_model_data_reporting_condition_threshold_t* p_threshold)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_threshold;
    typedef typename DataReportingCondition::ThresholdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setThreshold(std::move(value))) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_data_reporting_condition_is_report_when_below(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::ReportWhenBelowType ResultFromType;
    const ResultFromType result_from = obj->isReportWhenBelow();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const bool p_report_when_below)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_report_when_below;
    typedef typename DataReportingCondition::ReportWhenBelowType ValueType;

    ValueType value = value_from;
    if (!obj->setReportWhenBelow(value)) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, bool p_report_when_below)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_report_when_below;
    typedef typename DataReportingCondition::ReportWhenBelowType ValueType;

    ValueType value = value_from;
    
    if (!obj->setReportWhenBelow(std::move(value))) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_data_reporting_event_trigger_t* data_collection_model_data_reporting_condition_get_event_trigger(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    typedef typename DataReportingCondition::EventTriggerType ResultFromType;
    const ResultFromType result_from = obj->getEventTrigger();
    const data_collection_model_data_reporting_event_trigger_t *result = reinterpret_cast<const data_collection_model_data_reporting_event_trigger_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const data_collection_model_data_reporting_event_trigger_t* p_event_trigger)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_event_trigger;
    typedef typename DataReportingCondition::EventTriggerType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEventTrigger(value)) return NULL;
    return obj_data_reporting_condition;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, data_collection_model_data_reporting_event_trigger_t* p_event_trigger)
{
    if (obj_data_reporting_condition == NULL) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    const auto &value_from = p_event_trigger;
    typedef typename DataReportingCondition::EventTriggerType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEventTrigger(std::move(value))) return NULL;
    return obj_data_reporting_condition;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_condition_make_lnode(data_collection_model_data_reporting_condition_t *p_data_reporting_condition)
{
    return data_collection_lnode_create(p_data_reporting_condition, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_condition_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_condition_refcount(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

