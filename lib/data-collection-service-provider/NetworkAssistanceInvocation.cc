/**********************************************************************************************************************************
 * NetworkAssistanceInvocation - C interface to the NetworkAssistanceInvocation object
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

/*#include "NetworkAssistanceInvocation.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceInvocation-internal.h"
#include "openapi/model/NetworkAssistanceInvocation.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create(



)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_t*>(new std::shared_ptr<NetworkAssistanceInvocation>(new NetworkAssistanceInvocation(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_copy(const data_collection_model_network_assistance_invocation_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_network_assistance_invocation_t*>(new std::shared_ptr<NetworkAssistanceInvocation >(new NetworkAssistanceInvocation(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_move(data_collection_model_network_assistance_invocation_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > *obj = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_copy(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_network_assistance_invocation_t *other)
{
    if (network_assistance_invocation) {
        std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
        if (obj) {
            if (other) {
                const std::shared_ptr<NetworkAssistanceInvocation > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(other);
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
                const std::shared_ptr<NetworkAssistanceInvocation > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(other);
                if (other_obj) {
                    obj.reset(new NetworkAssistanceInvocation(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        network_assistance_invocation = data_collection_model_network_assistance_invocation_create_copy(other);
    }
    return network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_network_assistance_invocation_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocation > *other_ptr = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(other);

    if (network_assistance_invocation) {
        std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                network_assistance_invocation = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_free(data_collection_model_network_assistance_invocation_t *network_assistance_invocation)
{
    if (!network_assistance_invocation) return;
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_toJSON(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation, bool as_request)
{
    if (!network_assistance_invocation) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_network_assistance_invocation_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_invocation_t*>(new std::shared_ptr<NetworkAssistanceInvocation >(new NetworkAssistanceInvocation(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_is_equal_to(const data_collection_model_network_assistance_invocation_t *first, const data_collection_model_network_assistance_invocation_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NetworkAssistanceInvocation > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NetworkAssistanceInvocation > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_policy_template_id(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) return false;

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return false;

    return obj->getPolicyTemplateId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_get_policy_template_id(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocation::PolicyTemplateIdType ResultFromType;
    const ResultFromType &result_from = obj->getPolicyTemplateId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const char* p_policy_template_id)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocation::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    if (!obj->setPolicyTemplateId(value)) return NULL;

    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, char* p_policy_template_id)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocation::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;

    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) return false;

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return false;

    return obj->getApplicationFlowDescriptions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocation_get_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ResultFromType;
    const ResultFromType &result_from = obj->getApplicationFlowDescriptions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_application_flow_description_t *item_obj = reinterpret_cast<data_collection_model_application_flow_description_t*>(item.has_value()?new std::shared_ptr<ApplicationFlowDescription >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_application_flow_description_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ValueType;

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

    if (!obj->setApplicationFlowDescriptions(value)) return NULL;

    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ValueType;

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

    data_collection_list_free(p_application_flow_descriptions);
    if (!obj->setApplicationFlowDescriptions(std::move(value))) return NULL;

    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_add_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_application_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addApplicationFlowDescriptions(value.value());
    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_remove_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_application_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeApplicationFlowDescriptions(value);
    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_network_assistance_invocation_get_entry_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, size_t idx)
{
    if (!obj_network_assistance_invocation) {
        const data_collection_model_application_flow_description_t *result = NULL;

        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) {
        const data_collection_model_application_flow_description_t *result = NULL;

        return result;
    }

    const NetworkAssistanceInvocation::ApplicationFlowDescriptionsType &container = obj->getApplicationFlowDescriptions();
    if (!container.has_value()) {
        const data_collection_model_application_flow_description_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_application_flow_description_t *result = NULL;

        return result;
    }
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_application_flow_description_t *result = reinterpret_cast<const data_collection_model_application_flow_description_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_clear_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    obj->clearApplicationFlowDescriptions();
    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_requested_qo_s(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) return false;

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return false;

    return obj->getRequestedQoS().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_network_assistance_invocation_get_requested_qo_s(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocation::RequestedQoSType ResultFromType;
    const ResultFromType &result_from = obj->getRequestedQoS();
    const data_collection_model_unidirectional_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_qo_s_specification_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocation::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRequestedQoS(value)) return NULL;

    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocation::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRequestedQoS(std::move(value))) return NULL;

    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_has_recommended_qo_s(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) return false;

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return false;

    return obj->getRecommendedQoS().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_network_assistance_invocation_get_recommended_qo_s(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) {
        const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) {
        const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocation::RecommendedQoSType ResultFromType;
    const ResultFromType &result_from = obj->getRecommendedQoS();
    const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = reinterpret_cast<const data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocation::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRecommendedQoS(value)) return NULL;

    return obj_network_assistance_invocation;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (!obj_network_assistance_invocation) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    if (!obj) return NULL;

    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocation::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRecommendedQoS(std::move(value))) return NULL;

    return obj_network_assistance_invocation;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_make_lnode(data_collection_model_network_assistance_invocation_t *p_network_assistance_invocation)
{
    return data_collection_lnode_create(p_network_assistance_invocation, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocation_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocation_refcount(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    if (!obj_network_assistance_invocation) return 0l;
    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

