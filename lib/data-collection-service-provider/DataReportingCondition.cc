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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create(






)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition>(new DataReportingCondition(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_copy(const data_collection_model_data_reporting_condition_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition >(new DataReportingCondition(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_move(data_collection_model_data_reporting_condition_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataReportingCondition > *obj = reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_copy(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_t *other)
{
    if (data_reporting_condition) {
        std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataReportingCondition > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(other);
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
                const std::shared_ptr<DataReportingCondition > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(other);
                if (other_obj) {
                    obj.reset(new DataReportingCondition(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_reporting_condition = data_collection_model_data_reporting_condition_create_copy(other);
    }
    return data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_t *other)
{
    std::shared_ptr<DataReportingCondition > *other_ptr = reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(other);

    if (data_reporting_condition) {
        std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_reporting_condition = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_condition_free(data_collection_model_data_reporting_condition_t *data_reporting_condition)
{
    if (!data_reporting_condition) return;
    delete reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_condition_toJSON(const data_collection_model_data_reporting_condition_t *data_reporting_condition, bool as_request)
{
    if (!data_reporting_condition) return NULL;
    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(data_reporting_condition);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_is_equal_to(const data_collection_model_data_reporting_condition_t *first, const data_collection_model_data_reporting_condition_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingCondition > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingCondition > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_condition_get_context_ids(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingCondition::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const ogs_list_t* p_context_ids)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename DataReportingCondition::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(value)) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, ogs_list_t* p_context_ids)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename DataReportingCondition::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_add_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, char* p_context_ids)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    typedef typename DataReportingCondition::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);


    obj->addContextIds(value);
    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_remove_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const char* p_context_ids)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    typedef typename DataReportingCondition::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);

    obj->removeContextIds(value);
    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_clear_context_ids(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_data_reporting_condition;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_type_t* data_collection_model_data_reporting_condition_get_type(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) {
        const data_collection_model_data_reporting_condition_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) {
        const data_collection_model_data_reporting_condition_type_t *result = NULL;
        return result;
    }

    typedef typename DataReportingCondition::TypeType ResultFromType;
    const ResultFromType result_from = obj->getType();
    const data_collection_model_data_reporting_condition_type_t *result = reinterpret_cast<const data_collection_model_data_reporting_condition_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const data_collection_model_data_reporting_condition_type_t* p_type)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_type;
    typedef typename DataReportingCondition::TypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setType(value)) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, data_collection_model_data_reporting_condition_type_t* p_type)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_type;
    typedef typename DataReportingCondition::TypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setType(std::move(value))) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_period(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) return false;

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return false;

    return obj->getPeriod().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_data_reporting_condition_get_period(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename DataReportingCondition::PeriodType ResultFromType;
    const ResultFromType result_from = obj->getPeriod();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const int32_t p_period)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_period;
    typedef typename DataReportingCondition::PeriodType ValueType;

    ValueType value(value_from);

    if (!obj->setPeriod(value)) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, int32_t p_period)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_period;
    typedef typename DataReportingCondition::PeriodType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPeriod(std::move(value))) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_parameter(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) return false;

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return false;

    return obj->getParameter().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_condition_get_parameter(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataReportingCondition::ParameterType ResultFromType;
    const ResultFromType result_from = obj->getParameter();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const char* p_parameter)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_parameter;
    typedef typename DataReportingCondition::ParameterType ValueType;

    ValueType value(value_from);

    if (!obj->setParameter(value)) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, char* p_parameter)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_parameter;
    typedef typename DataReportingCondition::ParameterType ValueType;

    ValueType value(value_from);

    
    if (!obj->setParameter(std::move(value))) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_threshold(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) return false;

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return false;

    return obj->getThreshold().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_threshold_t* data_collection_model_data_reporting_condition_get_threshold(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) {
        const data_collection_model_data_reporting_condition_threshold_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) {
        const data_collection_model_data_reporting_condition_threshold_t *result = NULL;
        return result;
    }

    typedef typename DataReportingCondition::ThresholdType ResultFromType;
    const ResultFromType result_from = obj->getThreshold();
    const data_collection_model_data_reporting_condition_threshold_t *result = reinterpret_cast<const data_collection_model_data_reporting_condition_threshold_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const data_collection_model_data_reporting_condition_threshold_t* p_threshold)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_threshold;
    typedef typename DataReportingCondition::ThresholdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setThreshold(value)) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, data_collection_model_data_reporting_condition_threshold_t* p_threshold)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_threshold;
    typedef typename DataReportingCondition::ThresholdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setThreshold(std::move(value))) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_report_when_below(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) return false;

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return false;

    return obj->isReportWhenBelow().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_data_reporting_condition_is_report_when_below(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename DataReportingCondition::ReportWhenBelowType ResultFromType;
    const ResultFromType result_from = obj->isReportWhenBelow();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const bool p_report_when_below)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_report_when_below;
    typedef typename DataReportingCondition::ReportWhenBelowType ValueType;

    ValueType value(value_from);

    if (!obj->setReportWhenBelow(value)) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, bool p_report_when_below)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_report_when_below;
    typedef typename DataReportingCondition::ReportWhenBelowType ValueType;

    ValueType value(value_from);

    
    if (!obj->setReportWhenBelow(std::move(value))) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_event_trigger(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) return false;

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return false;

    return obj->getEventTrigger().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_event_trigger_t* data_collection_model_data_reporting_condition_get_event_trigger(const data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) {
        const data_collection_model_data_reporting_event_trigger_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) {
        const data_collection_model_data_reporting_event_trigger_t *result = NULL;
        return result;
    }

    typedef typename DataReportingCondition::EventTriggerType ResultFromType;
    const ResultFromType result_from = obj->getEventTrigger();
    const data_collection_model_data_reporting_event_trigger_t *result = reinterpret_cast<const data_collection_model_data_reporting_event_trigger_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, const data_collection_model_data_reporting_event_trigger_t* p_event_trigger)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_event_trigger;
    typedef typename DataReportingCondition::EventTriggerType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setEventTrigger(value)) return NULL;

    return obj_data_reporting_condition;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger_move(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition, data_collection_model_data_reporting_event_trigger_t* p_event_trigger)
{
    if (!obj_data_reporting_condition) return NULL;

    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    if (!obj) return NULL;

    const auto &value_from = p_event_trigger;
    typedef typename DataReportingCondition::EventTriggerType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setEventTrigger(std::move(value))) return NULL;

    return obj_data_reporting_condition;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_condition_make_lnode(data_collection_model_data_reporting_condition_t *p_data_reporting_condition)
{
    return data_collection_lnode_create(p_data_reporting_condition, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_condition_free));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_is_equal_to_sans_context_ids(const data_collection_model_data_reporting_condition_t *first, const data_collection_model_data_reporting_condition_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingCondition > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingCondition > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }

    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* make some temp copies of the two objects without their contextIds */
    DataReportingCondition comp1(*obj1);
    comp1.clearContextIds();
    DataReportingCondition comp2(*obj2);
    comp2.clearContextIds();
    return comp1 == comp2;
}


/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_condition_refcount(data_collection_model_data_reporting_condition_t *obj_data_reporting_condition)
{
    if (!obj_data_reporting_condition) return 0l;
    std::shared_ptr<DataReportingCondition > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition >*>(obj_data_reporting_condition);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

