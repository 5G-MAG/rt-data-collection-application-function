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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create(



)
{
    return reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule>(new DataReportingRule(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_copy(const data_collection_model_data_reporting_rule_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule >(new DataReportingRule(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_move(data_collection_model_data_reporting_rule_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataReportingRule > *obj = reinterpret_cast<std::shared_ptr<DataReportingRule >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_copy(data_collection_model_data_reporting_rule_t *data_reporting_rule, const data_collection_model_data_reporting_rule_t *other)
{
    if (data_reporting_rule) {
        std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataReportingRule > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(other);
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
                const std::shared_ptr<DataReportingRule > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(other);
                if (other_obj) {
                    obj.reset(new DataReportingRule(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_reporting_rule = data_collection_model_data_reporting_rule_create_copy(other);
    }
    return data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, data_collection_model_data_reporting_rule_t *other)
{
    std::shared_ptr<DataReportingRule > *other_ptr = reinterpret_cast<std::shared_ptr<DataReportingRule >*>(other);

    if (data_reporting_rule) {
        std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_reporting_rule = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_rule_free(data_collection_model_data_reporting_rule_t *data_reporting_rule)
{
    if (!data_reporting_rule) return;
    delete reinterpret_cast<std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_rule_toJSON(const data_collection_model_data_reporting_rule_t *data_reporting_rule, bool as_request)
{
    if (!data_reporting_rule) return NULL;
    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(data_reporting_rule);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_data_reporting_rule_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_is_equal_to(const data_collection_model_data_reporting_rule_t *first, const data_collection_model_data_reporting_rule_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingRule > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingRule > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_context_ids(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) return false;

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return false;

    return obj->getContextIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_rule_get_context_ids(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingRule::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const ogs_list_t* p_context_ids)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename DataReportingRule::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(value)) return NULL;

    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, ogs_list_t* p_context_ids)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename DataReportingRule::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;

    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_add_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, char* p_context_ids)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    typedef typename DataReportingRule::ContextIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);


    if (value) obj->addContextIds(value.value());
    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_remove_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const char* p_context_ids)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    typedef typename DataReportingRule::ContextIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);

    obj->removeContextIds(value);
    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_clear_context_ids(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_reporting_probability(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) return false;

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return false;

    return obj->getReportingProbability().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_data_reporting_rule_get_reporting_probability(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename DataReportingRule::ReportingProbabilityType ResultFromType;
    const ResultFromType result_from = obj->getReportingProbability();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const double p_reporting_probability)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_probability;
    typedef typename DataReportingRule::ReportingProbabilityType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingProbability(value)) return NULL;

    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, double p_reporting_probability)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_probability;
    typedef typename DataReportingRule::ReportingProbabilityType ValueType;

    ValueType value(value_from);

    
    if (!obj->setReportingProbability(std::move(value))) return NULL;

    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_reporting_format(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) return false;

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return false;

    return obj->getReportingFormat().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_rule_get_reporting_format(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataReportingRule::ReportingFormatType ResultFromType;
    const ResultFromType result_from = obj->getReportingFormat();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const char* p_reporting_format)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_format;
    typedef typename DataReportingRule::ReportingFormatType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingFormat(value)) return NULL;

    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, char* p_reporting_format)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_format;
    typedef typename DataReportingRule::ReportingFormatType ValueType;

    ValueType value(value_from);

    
    if (!obj->setReportingFormat(std::move(value))) return NULL;

    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_has_data_packaging_strategy(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) return false;

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return false;

    return obj->getDataPackagingStrategy().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_rule_get_data_packaging_strategy(const data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataReportingRule::DataPackagingStrategyType ResultFromType;
    const ResultFromType result_from = obj->getDataPackagingStrategy();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, const char* p_data_packaging_strategy)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_data_packaging_strategy;
    typedef typename DataReportingRule::DataPackagingStrategyType ValueType;

    ValueType value(value_from);

    if (!obj->setDataPackagingStrategy(value)) return NULL;

    return obj_data_reporting_rule;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy_move(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule, char* p_data_packaging_strategy)
{
    if (!obj_data_reporting_rule) return NULL;

    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    if (!obj) return NULL;

    const auto &value_from = p_data_packaging_strategy;
    typedef typename DataReportingRule::DataPackagingStrategyType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDataPackagingStrategy(std::move(value))) return NULL;

    return obj_data_reporting_rule;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_rule_make_lnode(data_collection_model_data_reporting_rule_t *p_data_reporting_rule)
{
    return data_collection_lnode_create(p_data_reporting_rule, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_rule_free));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_is_equal_to_sans_context_ids(const data_collection_model_data_reporting_rule_t *first, const data_collection_model_data_reporting_rule_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingRule > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingRule > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }

    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* make some temp copies of the two objects without their contextIds */
    DataReportingRule comp1(*obj1);
    comp1.clearContextIds();
    DataReportingRule comp2(*obj2);
    comp2.clearContextIds();
    return comp1 == comp2;
}


/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_rule_refcount(data_collection_model_data_reporting_rule_t *obj_data_reporting_rule)
{
    if (!obj_data_reporting_rule) return 0l;
    std::shared_ptr<DataReportingRule > &obj = *reinterpret_cast<std::shared_ptr<DataReportingRule >*>(obj_data_reporting_rule);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

