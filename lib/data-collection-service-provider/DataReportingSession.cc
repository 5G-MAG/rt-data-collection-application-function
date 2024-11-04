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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "DataReportingSession.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingSession-internal.h"
#include "openapi/model/DataReportingSession.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create(






)
{
    return reinterpret_cast<data_collection_model_data_reporting_session_t*>(new std::shared_ptr<DataReportingSession>(new DataReportingSession(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_copy(const data_collection_model_data_reporting_session_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_reporting_session_t*>(new std::shared_ptr<DataReportingSession >(new DataReportingSession(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_move(data_collection_model_data_reporting_session_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataReportingSession > *obj = reinterpret_cast<std::shared_ptr<DataReportingSession >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_copy(data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_reporting_session_t *other)
{
    if (data_reporting_session) {
        std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(data_reporting_session);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataReportingSession > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(other);
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
                const std::shared_ptr<DataReportingSession > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(other);
                if (other_obj) {
                    obj.reset(new DataReportingSession(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_reporting_session = data_collection_model_data_reporting_session_create_copy(other);
    }
    return data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_move(data_collection_model_data_reporting_session_t *data_reporting_session, data_collection_model_data_reporting_session_t *other)
{
    std::shared_ptr<DataReportingSession > *other_ptr = reinterpret_cast<std::shared_ptr<DataReportingSession >*>(other);

    if (data_reporting_session) {
        std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(data_reporting_session);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_reporting_session = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_session_free(data_collection_model_data_reporting_session_t *data_reporting_session)
{
    if (!data_reporting_session) return;
    delete reinterpret_cast<std::shared_ptr<DataReportingSession >*>(data_reporting_session);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_session_toJSON(const data_collection_model_data_reporting_session_t *data_reporting_session, bool as_request)
{
    if (!data_reporting_session) return NULL;
    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(data_reporting_session);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_data_reporting_session_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_is_equal_to(const data_collection_model_data_reporting_session_t *first, const data_collection_model_data_reporting_session_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingSession > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingSession > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_session_id(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return false;

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return false;

    return obj->getSessionId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_session_id(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    typedef typename DataReportingSession::SessionIdType ResultFromType;
    const ResultFromType &result_from = obj->getSessionId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char* p_session_id)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename DataReportingSession::SessionIdType ValueType;

    ValueType value(value_from);


    if (!obj->setSessionId(value)) return NULL;

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, char* p_session_id)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename DataReportingSession::SessionIdType ValueType;

    ValueType value(value_from);


    if (!obj->setSessionId(std::move(value))) return NULL;
    ogs_free

(p_session_id);

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_valid_until(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return false;

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return false;

    return obj->getValidUntil().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_valid_until(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    typedef typename DataReportingSession::ValidUntilType ResultFromType;
    const ResultFromType &result_from = obj->getValidUntil();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char* p_valid_until)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_valid_until;
    typedef typename DataReportingSession::ValidUntilType ValueType;

    ValueType value(value_from);


    if (!obj->setValidUntil(value)) return NULL;

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, char* p_valid_until)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_valid_until;
    typedef typename DataReportingSession::ValidUntilType ValueType;

    ValueType value(value_from);


    if (!obj->setValidUntil(std::move(value))) return NULL;
    ogs_free

(p_valid_until);

    return obj_data_reporting_session;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_external_application_id(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataReportingSession::ExternalApplicationIdType ResultFromType;
    const ResultFromType &result_from = obj->getExternalApplicationId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char* p_external_application_id)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_external_application_id;
    typedef typename DataReportingSession::ExternalApplicationIdType ValueType;

    ValueType value(value_from);

    if (!obj->setExternalApplicationId(value)) return NULL;

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, char* p_external_application_id)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_external_application_id;
    typedef typename DataReportingSession::ExternalApplicationIdType ValueType;

    ValueType value(value_from);

    if (!obj->setExternalApplicationId(std::move(value))) return NULL;
    ogs_free
(p_external_application_id);

    return obj_data_reporting_session;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_supported_domains(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReportingSession::SupportedDomainsType ResultFromType;
    const ResultFromType &result_from = obj->getSupportedDomains();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_domain_t *item_obj = reinterpret_cast<data_collection_model_data_domain_t*>(item.has_value()?new std::shared_ptr<DataDomain >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_domain_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_list_t* p_supported_domains)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_supported_domains;
    typedef typename DataReportingSession::SupportedDomainsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setSupportedDomains(value)) return NULL;

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_list_t* p_supported_domains)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_supported_domains;
    typedef typename DataReportingSession::SupportedDomainsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setSupportedDomains(std::move(value))) return NULL;
    data_collection_list_free
(p_supported_domains);

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session, data_collection_model_data_domain_t* p_supported_domains)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    typedef typename DataReportingSession::SupportedDomainsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_supported_domains;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_domain_free
(p_supported_domains);
    obj->addSupportedDomains(value);
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const data_collection_model_data_domain_t* p_supported_domains)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    typedef typename DataReportingSession::SupportedDomainsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_supported_domains;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeSupportedDomains(value);
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_domain_t* data_collection_model_data_reporting_session_get_entry_supported_domains(const data_collection_model_data_reporting_session_t *obj_data_reporting_session, size_t idx)
{
    if (!obj_data_reporting_session) {
        const data_collection_model_data_domain_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        const data_collection_model_data_domain_t *result = NULL;

        return result;
    }

    const DataReportingSession::SupportedDomainsType &container = obj->getSupportedDomains();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_data_domain_t *result = NULL;

        return result;
    }
    typedef typename DataReportingSession::SupportedDomainsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_domain_t *result = reinterpret_cast<const data_collection_model_data_domain_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_supported_domains(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    obj->clearSupportedDomains();
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_sampling_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return false;

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return false;

    return obj->getSamplingRules().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_hash_t* data_collection_model_data_reporting_session_get_sampling_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) {
        ogs_hash_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        ogs_hash_t *result = NULL;
        return result;
    }

    typedef typename DataReportingSession::SamplingRulesType ResultFromType;
    const ResultFromType &result_from = obj->getSamplingRules();
    ogs_hash_t *result = result_from.has_value()?ogs_hash_make():nullptr;
    if (result) {
        for (const auto &item : result_from.value()) {
            ogs_list_t *item_obj = nullptr;
            if (item.second.has_value()) {

            typedef typename ResultFromType::value_type::mapped_type ItemType;
            {
                const auto &result_from = item.second;
                typedef ItemType ResultFromType;
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
                }}                item_obj = result;
            }
            }

    
            if (item_obj) ogs_hash_set(result, item.first.c_str(), OGS_HASH_KEY_STRING, item_obj);
        }
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_hash_t* p_sampling_rules)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_sampling_rules;
    typedef typename DataReportingSession::SamplingRulesType ValueType;

    ValueType value;
    if (value_from) {
        typedef typename ValueType::value_type::mapped_type ItemType;
        value = std::move(typename ValueType::value_type());
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        ogs_hash_index_t *save_entry = entry;
        auto &container(value.value());
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
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
                if (value.has_value()) container.insert(std::make_pair(std::string(key), ItemType(std::move(value))));
    	}
        }
        ogs_free(save_entry);
    }

    if (!obj->setSamplingRules(value)) return NULL;

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_hash_t* p_sampling_rules)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_sampling_rules;
    typedef typename DataReportingSession::SamplingRulesType ValueType;

    ValueType value;
    if (value_from) {
        typedef typename ValueType::value_type::mapped_type ItemType;
        value = std::move(typename ValueType::value_type());
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        ogs_hash_index_t *save_entry = entry;
        auto &container(value.value());
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
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
                if (value.has_value()) container.insert(std::make_pair(std::string(key), ItemType(std::move(value))));
    	}
        }
        ogs_free(save_entry);
    }

    if (!obj->setSamplingRules(std::move(value))) return NULL;
    data_collection_hash_free
(p_sampling_rules, reinterpret_cast<void(*)(void*)>(data_collection_list_free
));

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key, const ogs_list_t* p_sampling_rules)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    typedef typename DataReportingSession::SamplingRulesType::value_type ContainerType;
    typedef typename ContainerType::mapped_type ValueType;
    const auto &value_from = p_sampling_rules;

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

    if (value) obj->addSamplingRules(std::string(p_key), value.value());
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    
    obj->removeSamplingRules(std::string(p_key));
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_entry_sampling_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    if (!obj_data_reporting_session) {
        ogs_list_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        ogs_list_t *result = NULL;

        return result;
    }

    const DataReportingSession::SamplingRulesType &container = obj->getSamplingRules();
    if (!container.has_value()) {
        ogs_list_t *result = NULL;

        return result;
    }

    auto itr = container.value().find(std::string(p_key));
    if (itr == container.value().cend()) {
        ogs_list_t *result = NULL;

        return result;
    }
    typedef typename DataReportingSession::SamplingRulesItemType ResultFromType;
    const ResultFromType &result_from = itr->second;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_sampling_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    obj->clearSamplingRules();
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_reporting_conditions(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return false;

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return false;

    return obj->getReportingConditions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_conditions(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) {
        ogs_hash_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        ogs_hash_t *result = NULL;
        return result;
    }

    typedef typename DataReportingSession::ReportingConditionsType ResultFromType;
    const ResultFromType &result_from = obj->getReportingConditions();
    ogs_hash_t *result = result_from.has_value()?ogs_hash_make():nullptr;
    if (result) {
        for (const auto &item : result_from.value()) {
            ogs_list_t *item_obj = nullptr;
            if (item.second.has_value()) {

            typedef typename ResultFromType::value_type::mapped_type ItemType;
            {
                const auto &result_from = item.second;
                typedef ItemType ResultFromType;
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
                }}                item_obj = result;
            }
            }

    
            if (item_obj) ogs_hash_set(result, item.first.c_str(), OGS_HASH_KEY_STRING, item_obj);
        }
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_hash_t* p_reporting_conditions)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_conditions;
    typedef typename DataReportingSession::ReportingConditionsType ValueType;

    ValueType value;
    if (value_from) {
        typedef typename ValueType::value_type::mapped_type ItemType;
        value = std::move(typename ValueType::value_type());
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        ogs_hash_index_t *save_entry = entry;
        auto &container(value.value());
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
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
                if (value.has_value()) container.insert(std::make_pair(std::string(key), ItemType(std::move(value))));
    	}
        }
        ogs_free(save_entry);
    }

    if (!obj->setReportingConditions(value)) return NULL;

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_hash_t* p_reporting_conditions)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_conditions;
    typedef typename DataReportingSession::ReportingConditionsType ValueType;

    ValueType value;
    if (value_from) {
        typedef typename ValueType::value_type::mapped_type ItemType;
        value = std::move(typename ValueType::value_type());
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        ogs_hash_index_t *save_entry = entry;
        auto &container(value.value());
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
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
                if (value.has_value()) container.insert(std::make_pair(std::string(key), ItemType(std::move(value))));
    	}
        }
        ogs_free(save_entry);
    }

    if (!obj->setReportingConditions(std::move(value))) return NULL;
    data_collection_hash_free
(p_reporting_conditions, reinterpret_cast<void(*)(void*)>(data_collection_list_free
));

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key, const ogs_list_t* p_reporting_conditions)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    typedef typename DataReportingSession::ReportingConditionsType::value_type ContainerType;
    typedef typename ContainerType::mapped_type ValueType;
    const auto &value_from = p_reporting_conditions;

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

    if (value) obj->addReportingConditions(std::string(p_key), value.value());
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    
    obj->removeReportingConditions(std::string(p_key));
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_entry_reporting_conditions(const data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    if (!obj_data_reporting_session) {
        ogs_list_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        ogs_list_t *result = NULL;

        return result;
    }

    const DataReportingSession::ReportingConditionsType &container = obj->getReportingConditions();
    if (!container.has_value()) {
        ogs_list_t *result = NULL;

        return result;
    }

    auto itr = container.value().find(std::string(p_key));
    if (itr == container.value().cend()) {
        ogs_list_t *result = NULL;

        return result;
    }
    typedef typename DataReportingSession::ReportingConditionsItemType ResultFromType;
    const ResultFromType &result_from = itr->second;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_conditions(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    obj->clearReportingConditions();
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_reporting_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return false;

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return false;

    return obj->getReportingRules().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) {
        ogs_hash_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        ogs_hash_t *result = NULL;
        return result;
    }

    typedef typename DataReportingSession::ReportingRulesType ResultFromType;
    const ResultFromType &result_from = obj->getReportingRules();
    ogs_hash_t *result = result_from.has_value()?ogs_hash_make():nullptr;
    if (result) {
        for (const auto &item : result_from.value()) {
            ogs_list_t *item_obj = nullptr;
            if (item.second.has_value()) {

            typedef typename ResultFromType::value_type::mapped_type ItemType;
            {
                const auto &result_from = item.second;
                typedef ItemType ResultFromType;
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
                }}                item_obj = result;
            }
            }

    
            if (item_obj) ogs_hash_set(result, item.first.c_str(), OGS_HASH_KEY_STRING, item_obj);
        }
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const ogs_hash_t* p_reporting_rules)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_rules;
    typedef typename DataReportingSession::ReportingRulesType ValueType;

    ValueType value;
    if (value_from) {
        typedef typename ValueType::value_type::mapped_type ItemType;
        value = std::move(typename ValueType::value_type());
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        ogs_hash_index_t *save_entry = entry;
        auto &container(value.value());
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
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
                if (value.has_value()) container.insert(std::make_pair(std::string(key), ItemType(std::move(value))));
    	}
        }
        ogs_free(save_entry);
    }

    if (!obj->setReportingRules(value)) return NULL;

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules_move(data_collection_model_data_reporting_session_t *obj_data_reporting_session, ogs_hash_t* p_reporting_rules)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_rules;
    typedef typename DataReportingSession::ReportingRulesType ValueType;

    ValueType value;
    if (value_from) {
        typedef typename ValueType::value_type::mapped_type ItemType;
        value = std::move(typename ValueType::value_type());
        ogs_hash_index_t *entry = ogs_hash_index_make(value_from);
        ogs_hash_index_t *save_entry = entry;
        auto &container(value.value());
        for (entry = ogs_hash_next(entry); entry; entry = ogs_hash_next(entry)) {
    	const char *key;
            int key_len;
    	const ogs_list_t *item;
    	ogs_hash_this(entry, reinterpret_cast<const void**>(&key), &key_len, reinterpret_cast<void**>(const_cast<std::remove_const<std::remove_pointer<decltype(item)>::type>::type**>(&item)));
    	{
                const auto value_from = item;
    	    typedef ItemType ValueType;
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
                if (value.has_value()) container.insert(std::make_pair(std::string(key), ItemType(std::move(value))));
    	}
        }
        ogs_free(save_entry);
    }

    if (!obj->setReportingRules(std::move(value))) return NULL;
    data_collection_hash_free
(p_reporting_rules, reinterpret_cast<void(*)(void*)>(data_collection_list_free
));

    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key, const ogs_list_t* p_reporting_rules)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    typedef typename DataReportingSession::ReportingRulesType::value_type ContainerType;
    typedef typename ContainerType::mapped_type ValueType;
    const auto &value_from = p_reporting_rules;

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

    if (value) obj->addReportingRules(std::string(p_key), value.value());
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    
    obj->removeReportingRules(std::string(p_key));
    return obj_data_reporting_session;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_entry_reporting_rules(const data_collection_model_data_reporting_session_t *obj_data_reporting_session, const char *p_key)
{
    if (!obj_data_reporting_session) {
        ogs_list_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) {
        ogs_list_t *result = NULL;

        return result;
    }

    const DataReportingSession::ReportingRulesType &container = obj->getReportingRules();
    if (!container.has_value()) {
        ogs_list_t *result = NULL;

        return result;
    }

    auto itr = container.value().find(std::string(p_key));
    if (itr == container.value().cend()) {
        ogs_list_t *result = NULL;

        return result;
    }
    typedef typename DataReportingSession::ReportingRulesItemType ResultFromType;
    const ResultFromType &result_from = itr->second;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_rules(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return NULL;

    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    if (!obj) return NULL;

    obj->clearReportingRules();
    return obj_data_reporting_session;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_session_make_lnode(data_collection_model_data_reporting_session_t *p_data_reporting_session)
{
    return data_collection_lnode_create(p_data_reporting_session, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_session_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_session_refcount(data_collection_model_data_reporting_session_t *obj_data_reporting_session)
{
    if (!obj_data_reporting_session) return 0l;
    std::shared_ptr<DataReportingSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingSession >*>(obj_data_reporting_session);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

