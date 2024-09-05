/**********************************************************************************************************************************
 * DynamicPolicy - C interface to the DynamicPolicy object
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

/*#include "DynamicPolicy.h" already included by data-collection-sp/data-collection.h */
#include "DynamicPolicy-internal.h"
#include "openapi/model/DynamicPolicy.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create(







)
{
    return reinterpret_cast<data_collection_model_dynamic_policy_t*>(new std::shared_ptr<DynamicPolicy>(new DynamicPolicy(







)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create_copy(const data_collection_model_dynamic_policy_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_dynamic_policy_t*>(new std::shared_ptr<DynamicPolicy >(new DynamicPolicy(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_create_move(data_collection_model_dynamic_policy_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DynamicPolicy > *obj = reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_copy(data_collection_model_dynamic_policy_t *dynamic_policy, const data_collection_model_dynamic_policy_t *other)
{
    if (dynamic_policy) {
        std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(dynamic_policy);
        if (obj) {
            if (other) {
                const std::shared_ptr<DynamicPolicy > &other_obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(other);
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
                const std::shared_ptr<DynamicPolicy > &other_obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(other);
                if (other_obj) {
                    obj.reset(new DynamicPolicy(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        dynamic_policy = data_collection_model_dynamic_policy_create_copy(other);
    }
    return dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_move(data_collection_model_dynamic_policy_t *dynamic_policy, data_collection_model_dynamic_policy_t *other)
{
    std::shared_ptr<DynamicPolicy > *other_ptr = reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(other);

    if (dynamic_policy) {
        std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(dynamic_policy);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                dynamic_policy = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dynamic_policy_free(data_collection_model_dynamic_policy_t *dynamic_policy)
{
    if (!dynamic_policy) return;
    delete reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(dynamic_policy);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dynamic_policy_toJSON(const data_collection_model_dynamic_policy_t *dynamic_policy, bool as_request)
{
    if (!dynamic_policy) return NULL;
    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(dynamic_policy);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_dynamic_policy_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_dynamic_policy_t*>(new std::shared_ptr<DynamicPolicy >(new DynamicPolicy(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_is_equal_to(const data_collection_model_dynamic_policy_t *first, const data_collection_model_dynamic_policy_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DynamicPolicy > &obj2 = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DynamicPolicy > &obj1 = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_dynamic_policy_id(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DynamicPolicy::DynamicPolicyIdType ResultFromType;
    const ResultFromType result_from = obj->getDynamicPolicyId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_dynamic_policy_id(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const char* p_dynamic_policy_id)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_dynamic_policy_id;
    typedef typename DynamicPolicy::DynamicPolicyIdType ValueType;

    ValueType value(value_from);

    if (!obj->setDynamicPolicyId(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_dynamic_policy_id_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, char* p_dynamic_policy_id)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_dynamic_policy_id;
    typedef typename DynamicPolicy::DynamicPolicyIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDynamicPolicyId(std::move(value))) return NULL;

    return obj_dynamic_policy;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_policy_template_id(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DynamicPolicy::PolicyTemplateIdType ResultFromType;
    const ResultFromType result_from = obj->getPolicyTemplateId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_policy_template_id(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const char* p_policy_template_id)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename DynamicPolicy::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    if (!obj->setPolicyTemplateId(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_policy_template_id_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, char* p_policy_template_id)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename DynamicPolicy::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;

    return obj_dynamic_policy;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dynamic_policy_get_service_data_flow_descriptions(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DynamicPolicy::ServiceDataFlowDescriptionsType ResultFromType;
    const ResultFromType result_from = obj->getServiceDataFlowDescriptions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_application_flow_description_t *item_obj = reinterpret_cast<data_collection_model_application_flow_description_t*>(item.has_value()?new std::shared_ptr<ApplicationFlowDescription >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_application_flow_description_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const ogs_list_t* p_service_data_flow_descriptions)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_service_data_flow_descriptions;
    typedef typename DynamicPolicy::ServiceDataFlowDescriptionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setServiceDataFlowDescriptions(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_service_data_flow_descriptions_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, ogs_list_t* p_service_data_flow_descriptions)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_service_data_flow_descriptions;
    typedef typename DynamicPolicy::ServiceDataFlowDescriptionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_service_data_flow_descriptions);
    if (!obj->setServiceDataFlowDescriptions(std::move(value))) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_add_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *obj_dynamic_policy, data_collection_model_application_flow_description_t* p_service_data_flow_descriptions)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    typedef typename DynamicPolicy::ServiceDataFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_service_data_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    obj->addServiceDataFlowDescriptions(value);
    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_remove_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const data_collection_model_application_flow_description_t* p_service_data_flow_descriptions)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    typedef typename DynamicPolicy::ServiceDataFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_service_data_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeServiceDataFlowDescriptions(value);
    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_clear_service_data_flow_descriptions(data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    obj->clearServiceDataFlowDescriptions();
    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_media_type(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) return false;

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return false;

    return obj->getMediaType().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_type_t* data_collection_model_dynamic_policy_get_media_type(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        const data_collection_model_media_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        const data_collection_model_media_type_t *result = NULL;
        return result;
    }

    typedef typename DynamicPolicy::MediaTypeType ResultFromType;
    const ResultFromType result_from = obj->getMediaType();
    const data_collection_model_media_type_t *result = reinterpret_cast<const data_collection_model_media_type_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_media_type(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const data_collection_model_media_type_t* p_media_type)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_media_type;
    typedef typename DynamicPolicy::MediaTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setMediaType(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_media_type_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, data_collection_model_media_type_t* p_media_type)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_media_type;
    typedef typename DynamicPolicy::MediaTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setMediaType(std::move(value))) return NULL;

    return obj_dynamic_policy;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_provisioning_session_id(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DynamicPolicy::ProvisioningSessionIdType ResultFromType;
    const ResultFromType result_from = obj->getProvisioningSessionId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_provisioning_session_id(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const char* p_provisioning_session_id)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename DynamicPolicy::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setProvisioningSessionId(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_provisioning_session_id_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, char* p_provisioning_session_id)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename DynamicPolicy::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_qos_specification(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) return false;

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return false;

    return obj->getQosSpecification().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_qo_s_specification_t* data_collection_model_dynamic_policy_get_qos_specification(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        const data_collection_model_m5_qo_s_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        const data_collection_model_m5_qo_s_specification_t *result = NULL;
        return result;
    }

    typedef typename DynamicPolicy::QosSpecificationType ResultFromType;
    const ResultFromType result_from = obj->getQosSpecification();
    const data_collection_model_m5_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_m5_qo_s_specification_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_qos_specification(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const data_collection_model_m5_qo_s_specification_t* p_qos_specification)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_qos_specification;
    typedef typename DynamicPolicy::QosSpecificationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setQosSpecification(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_qos_specification_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, data_collection_model_m5_qo_s_specification_t* p_qos_specification)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_qos_specification;
    typedef typename DynamicPolicy::QosSpecificationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setQosSpecification(std::move(value))) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_enforcement_method(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) return false;

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return false;

    return obj->getEnforcementMethod().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_get_enforcement_method(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DynamicPolicy::EnforcementMethodType ResultFromType;
    const ResultFromType result_from = obj->getEnforcementMethod();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_method(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const char* p_enforcement_method)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_method;
    typedef typename DynamicPolicy::EnforcementMethodType ValueType;

    ValueType value(value_from);

    if (!obj->setEnforcementMethod(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_method_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, char* p_enforcement_method)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_method;
    typedef typename DynamicPolicy::EnforcementMethodType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEnforcementMethod(std::move(value))) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_has_enforcement_bit_rate(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) return false;

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return false;

    return obj->getEnforcementBitRate().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_dynamic_policy_get_enforcement_bit_rate(const data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename DynamicPolicy::EnforcementBitRateType ResultFromType;
    const ResultFromType result_from = obj->getEnforcementBitRate();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_bit_rate(data_collection_model_dynamic_policy_t *obj_dynamic_policy, const int32_t p_enforcement_bit_rate)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_bit_rate;
    typedef typename DynamicPolicy::EnforcementBitRateType ValueType;

    ValueType value(value_from);

    if (!obj->setEnforcementBitRate(value)) return NULL;

    return obj_dynamic_policy;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_t *data_collection_model_dynamic_policy_set_enforcement_bit_rate_move(data_collection_model_dynamic_policy_t *obj_dynamic_policy, int32_t p_enforcement_bit_rate)
{
    if (!obj_dynamic_policy) return NULL;

    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_bit_rate;
    typedef typename DynamicPolicy::EnforcementBitRateType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEnforcementBitRate(std::move(value))) return NULL;

    return obj_dynamic_policy;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dynamic_policy_make_lnode(data_collection_model_dynamic_policy_t *p_dynamic_policy)
{
    return data_collection_lnode_create(p_dynamic_policy, reinterpret_cast<void(*)(void*)>(data_collection_model_dynamic_policy_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_dynamic_policy_refcount(data_collection_model_dynamic_policy_t *obj_dynamic_policy)
{
    if (!obj_dynamic_policy) return 0l;
    std::shared_ptr<DynamicPolicy > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicy >*>(obj_dynamic_policy);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

