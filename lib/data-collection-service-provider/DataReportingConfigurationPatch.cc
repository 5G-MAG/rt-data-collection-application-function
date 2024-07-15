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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "DataReportingConfigurationPatch.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingConfigurationPatch-internal.h"
#include "openapi/model/DataReportingConfigurationPatch.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create(




)
{
    return reinterpret_cast<data_collection_model_data_reporting_configuration_patch_t*>(new std::shared_ptr<DataReportingConfigurationPatch>(new DataReportingConfigurationPatch(




)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create_copy(const data_collection_model_data_reporting_configuration_patch_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_configuration_patch_t*>(new std::shared_ptr<DataReportingConfigurationPatch >(new DataReportingConfigurationPatch(**reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_create_move(data_collection_model_data_reporting_configuration_patch_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_configuration_patch_t*>(new std::shared_ptr<DataReportingConfigurationPatch >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_copy(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, const data_collection_model_data_reporting_configuration_patch_t *other)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(other);
    return data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_move(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, data_collection_model_data_reporting_configuration_patch_t *other)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(other));
    return data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_configuration_patch_free(data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_configuration_patch_toJSON(const data_collection_model_data_reporting_configuration_patch_t *data_reporting_configuration_patch, bool as_request)
{
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(data_reporting_configuration_patch);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_configuration_patch_get_authorization_url(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::AuthorizationURLType ResultFromType;
    const ResultFromType result_from = obj->getAuthorizationURL();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_authorization_url(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const char* p_authorization_url)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_authorization_url;
    typedef typename DataReportingConfigurationPatch::AuthorizationURLType ValueType;

    ValueType value(value_from);
    if (!obj->setAuthorizationURL(value)) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_authorization_url_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, char* p_authorization_url)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_authorization_url;
    typedef typename DataReportingConfigurationPatch::AuthorizationURLType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAuthorizationURL(std::move(value))) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_sampling_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ResultFromType;
    const ResultFromType result_from = obj->getDataSamplingRules();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_sampling_rule_t *item_obj = reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule >(item));
        node = data_collection_model_data_sampling_rule_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_sampling_rules)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_sampling_rules;
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setDataSamplingRules(value)) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_sampling_rules_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_sampling_rules)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_sampling_rules;
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_data_sampling_rules);
    if (!obj->setDataSamplingRules(std::move(value))) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_sampling_rule_t* p_data_sampling_rules)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_sampling_rules;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addDataSamplingRules(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_sampling_rule_t* p_data_sampling_rules)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataSamplingRulesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_sampling_rules;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeDataSamplingRules(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_sampling_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{   
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    obj->clearDataSamplingRules();
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_reporting_conditions(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ResultFromType;
    const ResultFromType result_from = obj->getDataReportingConditions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_reporting_condition_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition >(item));
        node = data_collection_model_data_reporting_condition_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_reporting_conditions)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_reporting_conditions;
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setDataReportingConditions(value)) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_conditions_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_reporting_conditions)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_reporting_conditions;
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_data_reporting_conditions);
    if (!obj->setDataReportingConditions(std::move(value))) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_reporting_condition_t* p_data_reporting_conditions)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_reporting_conditions;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addDataReportingConditions(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_reporting_condition_t* p_data_reporting_conditions)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataReportingConditionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_reporting_conditions;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeDataReportingConditions(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_reporting_conditions(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{   
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    obj->clearDataReportingConditions();
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_reporting_rules(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ResultFromType;
    const ResultFromType result_from = obj->getDataReportingRules();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_reporting_rule_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule >(item));
        node = data_collection_model_data_reporting_rule_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_reporting_rules)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_reporting_rules;
    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setDataReportingRules(value)) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_reporting_rules_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_reporting_rules)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_reporting_rules;
    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_data_reporting_rules);
    if (!obj->setDataReportingRules(std::move(value))) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_reporting_rule_t* p_data_reporting_rules)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_reporting_rules;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addDataReportingRules(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_reporting_rule_t* p_data_reporting_rules)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataReportingRulesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_reporting_rules;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeDataReportingRules(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_reporting_rules(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{   
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    obj->clearDataReportingRules();
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_configuration_patch_get_data_access_profiles(const data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    const std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ResultFromType;
    const ResultFromType result_from = obj->getDataAccessProfiles();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_access_profile_t *item_obj = reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile >(item));
        node = data_collection_model_data_access_profile_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const ogs_list_t* p_data_access_profiles)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_access_profiles;
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setDataAccessProfiles(value)) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_set_data_access_profiles_move(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, ogs_list_t* p_data_access_profiles)
{
    if (obj_data_reporting_configuration_patch == NULL) return NULL;

    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    const auto &value_from = p_data_access_profiles;
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_data_access_profiles);
    if (!obj->setDataAccessProfiles(std::move(value))) return NULL;
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_add_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, data_collection_model_data_access_profile_t* p_data_access_profiles)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_access_profiles;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addDataAccessProfiles(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_remove_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch, const data_collection_model_data_access_profile_t* p_data_access_profiles)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    typedef typename DataReportingConfigurationPatch::DataAccessProfilesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_access_profiles;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeDataAccessProfiles(value);
    return obj_data_reporting_configuration_patch;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_configuration_patch_t *data_collection_model_data_reporting_configuration_patch_clear_data_access_profiles(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{   
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    obj->clearDataAccessProfiles();
    return obj_data_reporting_configuration_patch;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_configuration_patch_make_lnode(data_collection_model_data_reporting_configuration_patch_t *p_data_reporting_configuration_patch)
{
    return data_collection_lnode_create(p_data_reporting_configuration_patch, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_configuration_patch_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_configuration_patch_refcount(data_collection_model_data_reporting_configuration_patch_t *obj_data_reporting_configuration_patch)
{
    std::shared_ptr<DataReportingConfigurationPatch > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConfigurationPatch >*>(obj_data_reporting_configuration_patch);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

