/**********************************************************************************************************************************
 * DataReportingConfigurationPatch - C interface to the DataReportingConfigurationPatch object
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

/*#include "DataReportingConfigurationPatch.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingConfigurationPatch-internal.h"
#include "openapi/model/DataReportingConfigurationPatch.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create(




)
{
    return reinterpret_cast<data_collection_model_data_reporting_configuration_patch_t*>(new std::shared_ptr<DataReportingConfigurationPatch>(new DataReportingConfigurationPatch(




)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create_copy(const data_collection_model_data_reporting_configuration_patch_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_reporting_configuration_patch_t*>(new std::shared_ptr<DataReportingConfigurationPatch >(new DataReportingConfigurationPatch(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create_move(data_collection_model_data_reporting_configuration_patch_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > *obj = reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_copy(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_reporting_configuration_patch_t *other)
{
    if (data_reporting_configuration_patch) {
        std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataReportingConfigurationPatch > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(other);
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
                const std::shared_ptr<DataReportingConfigurationPatch > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(other);
                if (other_obj) {
                    obj.reset(new DataReportingConfigurationPatch(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_reporting_configuration_patch = data_collection_model_data_reporting_configuration_patch_create_copy(other);
    }
    return data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, data_collection_model_data_reporting_configuration_patch_t *other)
{
    std::shared_ptr<DataReportingConfigurationPatch > *other_ptr = reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(other);

    if (data_reporting_configuration_patch) {
        std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_reporting_configuration_patch = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_configuration_patch_free(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch)
{
    if (!data_reporting_configuration_patch) return;
    delete reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_configuration_patch_toJSON(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, bool as_request)
{
    if (!data_reporting_configuration_patch) return NULL;
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_data_reporting_configuration_patch_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_configuration_patch_t*>(new std::shared_ptr<DataReportingConfigurationPatch >(new DataReportingConfigurationPatch(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_is_equal_to(const data_collection_model_data_reporting_configuration_patch_t *first, const data_collection_model_data_reporting_configuration_patch_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingConfigurationPatch > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingConfigurationPatch > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_authorization_url(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return false;

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return false;

    return obj->getAuthorizationURL().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_configuration_patch_get_authorization_url(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataReportingConfigurationPatch::AuthorizationURLType ResultFromType;
    const ResultFromType &result_from = obj->getAuthorizationURL();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_authorization_url(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const char* p_authorization_url)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_authorization_url;
    typedef typename DataReportingConfigurationPatch::AuthorizationURLType ValueType;

    ValueType value(value_from);

    if (!obj->setAuthorizationURL(value)) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_authorization_url_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, char* p_authorization_url)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_authorization_url;
    typedef typename DataReportingConfigurationPatch::AuthorizationURLType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAuthorizationURL(std::move(value))) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_sampling_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return false;

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return false;

    return obj->getDataSamplingRules().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_sampling_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ResultFromType;
    const ResultFromType &result_from = obj->getDataSamplingRules();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_sampling_rule_t *item_obj = reinterpret_cast<data_collection_model_data_sampling_rule_t*>(item.has_value()?new std::shared_ptr<DataSamplingRule >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_sampling_rule_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_sampling_rules;
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataSamplingRules(value)) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_sampling_rules_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_sampling_rules;
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_data_sampling_rules);
    if (!obj->setDataSamplingRules(std::move(value))) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_sampling_rule_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_sampling_rules;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_sampling_rule_free(p_data_sampling_rules);
    if (value) obj->addDataSamplingRules(value.value());
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_sampling_rule_t* p_data_sampling_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_sampling_rules;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataSamplingRules(value);
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_sampling_rule_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_sampling_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, size_t idx)
{
    if (!obj_data_reporting_configuration_patch) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }

    const DataReportingConfigurationPatch::DataSamplingRulesType &container = obj->getDataSamplingRules();
    if (!container.has_value()) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_data_sampling_rule_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_sampling_rule_t *result = reinterpret_cast<const data_collection_model_data_sampling_rule_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    obj->clearDataSamplingRules();
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_reporting_conditions(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return false;

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return false;

    return obj->getDataReportingConditions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_reporting_conditions(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ResultFromType;
    const ResultFromType &result_from = obj->getDataReportingConditions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_reporting_condition_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_condition_t*>(item.has_value()?new std::shared_ptr<DataReportingCondition >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_reporting_condition_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_conditions;
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataReportingConditions(value)) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_conditions_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_conditions;
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_data_reporting_conditions);
    if (!obj->setDataReportingConditions(std::move(value))) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_reporting_condition_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_reporting_conditions;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_reporting_condition_free(p_data_reporting_conditions);
    if (value) obj->addDataReportingConditions(value.value());
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_reporting_condition_t* p_data_reporting_conditions)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_reporting_conditions;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataReportingConditions(value);
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_reporting_conditions(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, size_t idx)
{
    if (!obj_data_reporting_configuration_patch) {
        const data_collection_model_data_reporting_condition_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        const data_collection_model_data_reporting_condition_t *result = NULL;

        return result;
    }

    const DataReportingConfigurationPatch::DataReportingConditionsType &container = obj->getDataReportingConditions();
    if (!container.has_value()) {
        const data_collection_model_data_reporting_condition_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_data_reporting_condition_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_reporting_condition_t *result = reinterpret_cast<const data_collection_model_data_reporting_condition_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    obj->clearDataReportingConditions();
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_reporting_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return false;

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return false;

    return obj->getDataReportingRules().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_reporting_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ResultFromType;
    const ResultFromType &result_from = obj->getDataReportingRules();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_reporting_rule_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_rule_t*>(item.has_value()?new std::shared_ptr<DataReportingRule >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_reporting_rule_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_rules;
    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataReportingRules(value)) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_rules_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_reporting_rules;
    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_data_reporting_rules);
    if (!obj->setDataReportingRules(std::move(value))) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_reporting_rule_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataReportingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_reporting_rules;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_reporting_rule_free(p_data_reporting_rules);
    if (value) obj->addDataReportingRules(value.value());
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_reporting_rule_t* p_data_reporting_rules)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataReportingRulesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_reporting_rules;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataReportingRules(value);
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_rule_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_reporting_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, size_t idx)
{
    if (!obj_data_reporting_configuration_patch) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }

    const DataReportingConfigurationPatch::DataReportingRulesType &container = obj->getDataReportingRules();
    if (!container.has_value()) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_data_reporting_rule_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfigurationPatch::DataReportingRulesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_reporting_rule_t *result = reinterpret_cast<const data_collection_model_data_reporting_rule_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    obj->clearDataReportingRules();
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_configuration_patch_has_data_access_profiles(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return false;

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return false;

    return obj->getDataAccessProfiles().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_access_profiles(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ResultFromType;
    const ResultFromType &result_from = obj->getDataAccessProfiles();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_access_profile_t *item_obj = reinterpret_cast<data_collection_model_data_access_profile_t*>(item.has_value()?new std::shared_ptr<DataAccessProfile >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_access_profile_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_access_profiles;
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setDataAccessProfiles(value)) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_access_profiles_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    const auto &value_from = p_data_access_profiles;
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_data_access_profiles);
    if (!obj->setDataAccessProfiles(std::move(value))) return NULL;

    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_access_profile_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_access_profiles;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_access_profile_free(p_data_access_profiles);
    if (value) obj->addDataAccessProfiles(value.value());
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_access_profile_t* p_data_access_profiles)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_access_profiles;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeDataAccessProfiles(value);
    return obj_data_reporting_configuration_patch;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_t* data_collection_model_data_reporting_configuration_patch_get_entry_data_access_profiles(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, size_t idx)
{
    if (!obj_data_reporting_configuration_patch) {
        const data_collection_model_data_access_profile_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) {
        const data_collection_model_data_access_profile_t *result = NULL;

        return result;
    }

    const DataReportingConfigurationPatch::DataAccessProfilesType &container = obj->getDataAccessProfiles();
    if (!container.has_value()) {
        const data_collection_model_data_access_profile_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_data_access_profile_t *result = NULL;

        return result;
    }
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_access_profile_t *result = reinterpret_cast<const data_collection_model_data_access_profile_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    if (!obj) return NULL;

    obj->clearDataAccessProfiles();
    return obj_data_reporting_configuration_patch;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_configuration_patch_make_lnode(data_collection_model_data_reporting_configuration_patch_t *p_data_reporting_configuration_patch)
{
    return data_collection_lnode_create(p_data_reporting_configuration_patch, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_configuration_patch_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_configuration_patch_refcount(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    if (!obj_data_reporting_configuration_patch) return 0l;
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

