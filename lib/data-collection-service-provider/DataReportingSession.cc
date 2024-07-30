/**********************************************************************************************************************************
 * DataReportingSession - C interface to the DataReportingSession object
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

/*#include "DataReportingSession.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingSession-internal.h"
#include "openapi/model/DataReportingSession.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create(






)
{
    return reinterpret_cast<data_collection_model_data_reporting_session_t*>(new std::shared_ptr<DataReportingSession>(new DataReportingSession(






)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_copy(const data_collection_model_data_reporting_session_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_session_t*>(new std::shared_ptr<DataReportingSession >(new DataReportingSession(**reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_move(data_collection_model_data_reporting_session_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_session_t*>(new std::shared_ptr<DataReportingSession >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingSession >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_copy(data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_reporting_session_t *other)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(data_reporting_session);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(other);
    return data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_move(data_collection_model_data_reporting_session_t *data_reporting_session, data_collection_model_data_reporting_session_t *other)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(data_reporting_session);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingSession >*>(other));
    return data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_session_free(data_collection_model_data_reporting_session_t *data_reporting_session)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingSession >*>(data_reporting_session);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_session_toJSON(const data_collection_model_data_reporting_session_t *data_reporting_session, bool as_request)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(data_reporting_session);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_session_t*>(new std::shared_ptr<DataReportingSession >(new DataReportingSession(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_reporting_session_is_equal_to(const data_collection_model_data_reporting_session_t *first, const data_collection_model_data_reporting_session_t *second)
{
    const std::shared_ptr<DataReportingSession > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(first);
    const std::shared_ptr<DataReportingSession > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_session_get_session_id(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::SessionIdType ResultFromType;
    const ResultFromType result_from = obj->getSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char* p_session_id)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_session_id;
    typedef typename DataReportingSession::SessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSessionId(value)) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, char* p_session_id)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_session_id;
    typedef typename DataReportingSession::SessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSessionId(std::move(value))) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_session_get_valid_until(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::ValidUntilType ResultFromType;
    const ResultFromType result_from = obj->getValidUntil();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char* p_valid_until)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_valid_until;
    typedef typename DataReportingSession::ValidUntilType ValueType;

    ValueType value(value_from);
    if (!obj->setValidUntil(value)) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, char* p_valid_until)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_valid_until;
    typedef typename DataReportingSession::ValidUntilType ValueType;

    ValueType value(value_from);
    
    if (!obj->setValidUntil(std::move(value))) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_session_get_external_application_id(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::ExternalApplicationIdType ResultFromType;
    const ResultFromType result_from = obj->getExternalApplicationId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char* p_external_application_id)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_external_application_id;
    typedef typename DataReportingSession::ExternalApplicationIdType ValueType;

    ValueType value(value_from);
    if (!obj->setExternalApplicationId(value)) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, char* p_external_application_id)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_external_application_id;
    typedef typename DataReportingSession::ExternalApplicationIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setExternalApplicationId(std::move(value))) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_session_get_supported_domains(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::SupportedDomainsType ResultFromType;
    const ResultFromType result_from = obj->getSupportedDomains();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_domain_t *item_obj = reinterpret_cast<data_collection_model_data_domain_t*>(new std::shared_ptr<DataDomain >(item));
        node = data_collection_model_data_domain_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_list_t* p_supported_domains)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_supported_domains;
    typedef typename DataReportingSession::SupportedDomainsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setSupportedDomains(value)) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_list_t* p_supported_domains)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_supported_domains;
    typedef typename DataReportingSession::SupportedDomainsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_supported_domains);
    if (!obj->setSupportedDomains(std::move(value))) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session, data_collection_model_data_domain_t* p_supported_domains)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::SupportedDomainsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_supported_domains;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addSupportedDomains(value);
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const data_collection_model_data_domain_t* p_supported_domains)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::SupportedDomainsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_supported_domains;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeSupportedDomains(value);
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{   
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    obj->clearSupportedDomains();
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const ogs_hash_t* data_collection_model_data_reporting_session_get_sampling_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::SamplingRulesType ResultFromType;
    const ResultFromType result_from = obj->getSamplingRules();
    ogs_hash_t *result = ogs_hash_make();
    for (const auto &item : result_from) {
        ogs_list_t *item_obj;
        typedef typename ResultFromType::mapped_type ItemType;
        {
    	const auto &result_from = item.second;
            typedef ItemType ResultFromType;
    	ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    	typedef typename ResultFromType::value_type ItemType;
    	for (const ItemType &item : result_from) {
    	    data_collection_lnode_t *node;
    	    data_collection_model_data_sampling_rule_t *item_obj = reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule >(item));
    	    node = data_collection_model_data_sampling_rule_make_lnode(item_obj);
    	    
    	    ogs_list_add(result, node);
    	}    	item_obj = result;
        }
    
    
        ogs_hash_set(result, item.first.c_str(), OGS_HASH_KEY_STRING, item_obj);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_hash_t* p_sampling_rules)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_sampling_rules;
    typedef typename DataReportingSession::SamplingRulesType ValueType;

    ValueType value;
    {
        typedef typename ValueType::mapped_type ItemType;
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	auto &container(value);
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
    	    ValueType value;
    	    {
    	        data_collection_lnode_t *lnode;
    	        typedef typename ValueType::value_type ItemType;
    	        ogs_list_for_each(value_from, lnode) {
    	    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	    	
    	        }
    	    }                container.insert(std::make_pair(std::string(key), value));
    	}
        }
        ogs_free(entry);
    }
    if (!obj->setSamplingRules(value)) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_hash_t* p_sampling_rules)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_sampling_rules;
    typedef typename DataReportingSession::SamplingRulesType ValueType;

    ValueType value;
    {
        typedef typename ValueType::mapped_type ItemType;
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	auto &container(value);
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
    	    ValueType value;
    	    {
    	        data_collection_lnode_t *lnode;
    	        typedef typename ValueType::value_type ItemType;
    	        ogs_list_for_each(value_from, lnode) {
    	    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	    	
    	        }
    	    }                container.insert(std::make_pair(std::string(key), value));
    	}
        }
        ogs_free(entry);
    }
    data_collection_hash_free(p_sampling_rules, reinterpret_cast<void(*)(void*)>(data_collection_model_data_sampling_rule_free));
    if (!obj->setSamplingRules(std::move(value))) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key, const ogs_list_t* p_sampling_rules)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::SamplingRulesType ContainerType;
    typedef typename ContainerType::mapped_type ValueType;
    const auto &value_from = p_sampling_rules;

    ValueType value;
{
    data_collection_lnode_t *lnode;
    typedef typename ValueType::value_type ItemType;
    ogs_list_for_each(value_from, lnode) {
	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
	
    }
}

    obj->addSamplingRules(std::string(p_key), value);
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    
    obj->removeSamplingRules(std::string(p_key));
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{   
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    obj->clearSamplingRules();
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_conditions(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::ReportingConditionsType ResultFromType;
    const ResultFromType result_from = obj->getReportingConditions();
    ogs_hash_t *result = ogs_hash_make();
    for (const auto &item : result_from) {
        ogs_list_t *item_obj;
        typedef typename ResultFromType::mapped_type ItemType;
        {
    	const auto &result_from = item.second;
            typedef ItemType ResultFromType;
    	ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    	typedef typename ResultFromType::value_type ItemType;
    	for (const ItemType &item : result_from) {
    	    data_collection_lnode_t *node;
    	    data_collection_model_data_reporting_condition_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_condition_t*>(new std::shared_ptr<DataReportingCondition >(item));
    	    node = data_collection_model_data_reporting_condition_make_lnode(item_obj);
    	    
    	    ogs_list_add(result, node);
    	}    	item_obj = result;
        }
    
    
        ogs_hash_set(result, item.first.c_str(), OGS_HASH_KEY_STRING, item_obj);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_hash_t* p_reporting_conditions)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_reporting_conditions;
    typedef typename DataReportingSession::ReportingConditionsType ValueType;

    ValueType value;
    {
        typedef typename ValueType::mapped_type ItemType;
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	auto &container(value);
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
    	    ValueType value;
    	    {
    	        data_collection_lnode_t *lnode;
    	        typedef typename ValueType::value_type ItemType;
    	        ogs_list_for_each(value_from, lnode) {
    	    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	    	
    	        }
    	    }                container.insert(std::make_pair(std::string(key), value));
    	}
        }
        ogs_free(entry);
    }
    if (!obj->setReportingConditions(value)) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_hash_t* p_reporting_conditions)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_reporting_conditions;
    typedef typename DataReportingSession::ReportingConditionsType ValueType;

    ValueType value;
    {
        typedef typename ValueType::mapped_type ItemType;
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	auto &container(value);
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
    	    ValueType value;
    	    {
    	        data_collection_lnode_t *lnode;
    	        typedef typename ValueType::value_type ItemType;
    	        ogs_list_for_each(value_from, lnode) {
    	    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	    	
    	        }
    	    }                container.insert(std::make_pair(std::string(key), value));
    	}
        }
        ogs_free(entry);
    }
    data_collection_hash_free(p_reporting_conditions, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_condition_free));
    if (!obj->setReportingConditions(std::move(value))) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key, const ogs_list_t* p_reporting_conditions)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::ReportingConditionsType ContainerType;
    typedef typename ContainerType::mapped_type ValueType;
    const auto &value_from = p_reporting_conditions;

    ValueType value;
{
    data_collection_lnode_t *lnode;
    typedef typename ValueType::value_type ItemType;
    ogs_list_for_each(value_from, lnode) {
	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
	
    }
}

    obj->addReportingConditions(std::string(p_key), value);
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    
    obj->removeReportingConditions(std::string(p_key));
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{   
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    obj->clearReportingConditions();
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::ReportingRulesType ResultFromType;
    const ResultFromType result_from = obj->getReportingRules();
    ogs_hash_t *result = ogs_hash_make();
    for (const auto &item : result_from) {
        ogs_list_t *item_obj;
        typedef typename ResultFromType::mapped_type ItemType;
        {
    	const auto &result_from = item.second;
            typedef ItemType ResultFromType;
    	ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    	typedef typename ResultFromType::value_type ItemType;
    	for (const ItemType &item : result_from) {
    	    data_collection_lnode_t *node;
    	    data_collection_model_data_reporting_rule_t *item_obj = reinterpret_cast<data_collection_model_data_reporting_rule_t*>(new std::shared_ptr<DataReportingRule >(item));
    	    node = data_collection_model_data_reporting_rule_make_lnode(item_obj);
    	    
    	    ogs_list_add(result, node);
    	}    	item_obj = result;
        }
    
    
        ogs_hash_set(result, item.first.c_str(), OGS_HASH_KEY_STRING, item_obj);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_hash_t* p_reporting_rules)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_reporting_rules;
    typedef typename DataReportingSession::ReportingRulesType ValueType;

    ValueType value;
    {
        typedef typename ValueType::mapped_type ItemType;
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	auto &container(value);
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
    	    ValueType value;
    	    {
    	        data_collection_lnode_t *lnode;
    	        typedef typename ValueType::value_type ItemType;
    	        ogs_list_for_each(value_from, lnode) {
    	    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	    	
    	        }
    	    }                container.insert(std::make_pair(std::string(key), value));
    	}
        }
        ogs_free(entry);
    }
    if (!obj->setReportingRules(value)) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_hash_t* p_reporting_rules)
{
    if (obj_data_reporting_session == NULL) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    const auto &value_from = p_reporting_rules;
    typedef typename DataReportingSession::ReportingRulesType ValueType;

    ValueType value;
    {
        typedef typename ValueType::mapped_type ItemType;
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	auto &container(value);
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
    	    ValueType value;
    	    {
    	        data_collection_lnode_t *lnode;
    	        typedef typename ValueType::value_type ItemType;
    	        ogs_list_for_each(value_from, lnode) {
    	    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	    	
    	        }
    	    }                container.insert(std::make_pair(std::string(key), value));
    	}
        }
        ogs_free(entry);
    }
    data_collection_hash_free(p_reporting_rules, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_rule_free));
    if (!obj->setReportingRules(std::move(value))) return NULL;
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key, const ogs_list_t* p_reporting_rules)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    typedef typename DataReportingSession::ReportingRulesType ContainerType;
    typedef typename ContainerType::mapped_type ValueType;
    const auto &value_from = p_reporting_rules;

    ValueType value;
{
    data_collection_lnode_t *lnode;
    typedef typename ValueType::value_type ItemType;
    ogs_list_for_each(value_from, lnode) {
	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
	
    }
}

    obj->addReportingRules(std::string(p_key), value);
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    
    obj->removeReportingRules(std::string(p_key));
    return obj_data_reporting_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{   
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    obj->clearReportingRules();
    return obj_data_reporting_session;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_session_make_lnode(data_collection_model_data_reporting_session_t *p_data_reporting_session)
{
    return data_collection_lnode_create(p_data_reporting_session, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_session_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_session_refcount(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

