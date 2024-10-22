/**********************************************************************************************************************************
 * DynamicPolicyInvocationEvent_allOf - C interface to the DynamicPolicyInvocationEvent_allOf object
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

/*#include "DynamicPolicyInvocationEvent_allOf.h" already included by data-collection-sp/data-collection.h */
#include "DynamicPolicyInvocationEvent_allOf-internal.h"
#include "openapi/model/DynamicPolicyInvocationEvent_allOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create(




)
{
    return reinterpret_cast<data_collection_model_dynamic_policy_invocation_event_all_of_t*>(new std::shared_ptr<DynamicPolicyInvocationEvent_allOf>(new DynamicPolicyInvocationEvent_allOf(




)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create_copy(const data_collection_model_dynamic_policy_invocation_event_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_dynamic_policy_invocation_event_all_of_t*>(new std::shared_ptr<DynamicPolicyInvocationEvent_allOf >(new DynamicPolicyInvocationEvent_allOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_create_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > *obj = reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_copy(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, const data_collection_model_dynamic_policy_invocation_event_all_of_t *other)
{
    if (dynamic_policy_invocation_event_all_of) {
        std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(dynamic_policy_invocation_event_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(other);
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
                const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new DynamicPolicyInvocationEvent_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        dynamic_policy_invocation_event_all_of = data_collection_model_dynamic_policy_invocation_event_all_of_create_copy(other);
    }
    return dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, data_collection_model_dynamic_policy_invocation_event_all_of_t *other)
{
    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(other);

    if (dynamic_policy_invocation_event_all_of) {
        std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(dynamic_policy_invocation_event_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                dynamic_policy_invocation_event_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dynamic_policy_invocation_event_all_of_free(data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of)
{
    if (!dynamic_policy_invocation_event_all_of) return;
    delete reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(dynamic_policy_invocation_event_all_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dynamic_policy_invocation_event_all_of_toJSON(const data_collection_model_dynamic_policy_invocation_event_all_of_t *dynamic_policy_invocation_event_all_of, bool as_request)
{
    if (!dynamic_policy_invocation_event_all_of) return NULL;
    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(dynamic_policy_invocation_event_all_of);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_dynamic_policy_invocation_event_all_of_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_dynamic_policy_invocation_event_all_of_t*>(new std::shared_ptr<DynamicPolicyInvocationEvent_allOf >(new DynamicPolicyInvocationEvent_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_is_equal_to(const data_collection_model_dynamic_policy_invocation_event_all_of_t *first, const data_collection_model_dynamic_policy_invocation_event_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_policy_template_id(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DynamicPolicyInvocationEvent_allOf::PolicyTemplateIdType ResultFromType;
    const ResultFromType &result_from = obj->getPolicyTemplateId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_policy_template_id(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, const char* p_policy_template_id)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename DynamicPolicyInvocationEvent_allOf::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    if (!obj->setPolicyTemplateId(value)) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_policy_template_id_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, char* p_policy_template_id)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename DynamicPolicyInvocationEvent_allOf::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_application_flow_descriptions(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return false;

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return false;

    return obj->getApplicationFlowDescriptions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_application_flow_descriptions(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DynamicPolicyInvocationEvent_allOf::ApplicationFlowDescriptionsType ResultFromType;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, const ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename DynamicPolicyInvocationEvent_allOf::ApplicationFlowDescriptionsType ValueType;

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

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_application_flow_descriptions_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename DynamicPolicyInvocationEvent_allOf::ApplicationFlowDescriptionsType ValueType;

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

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_add_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    typedef typename DynamicPolicyInvocationEvent_allOf::ApplicationFlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_application_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_application_flow_description_free(p_application_flow_descriptions);
    if (value) obj->addApplicationFlowDescriptions(value.value());
    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_remove_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, const data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    typedef typename DynamicPolicyInvocationEvent_allOf::ApplicationFlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_application_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeApplicationFlowDescriptions(value);
    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_entry_application_flow_descriptions(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, size_t idx)
{
    if (!obj_dynamic_policy_invocation_event_all_of) {
        const data_collection_model_application_flow_description_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) {
        const data_collection_model_application_flow_description_t *result = NULL;

        return result;
    }

    const DynamicPolicyInvocationEvent_allOf::ApplicationFlowDescriptionsType &container = obj->getApplicationFlowDescriptions();
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
    typedef typename DynamicPolicyInvocationEvent_allOf::ApplicationFlowDescriptionsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_application_flow_description_t *result = reinterpret_cast<const data_collection_model_application_flow_description_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_clear_application_flow_descriptions(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    obj->clearApplicationFlowDescriptions();
    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_requested_qo_s(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return false;

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return false;

    return obj->getRequestedQoS().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_dynamic_policy_invocation_event_all_of_get_requested_qo_s(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    typedef typename DynamicPolicyInvocationEvent_allOf::RequestedQoSType ResultFromType;
    const ResultFromType &result_from = obj->getRequestedQoS();
    const data_collection_model_unidirectional_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_qo_s_specification_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_requested_qo_s(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename DynamicPolicyInvocationEvent_allOf::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRequestedQoS(value)) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_requested_qo_s_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename DynamicPolicyInvocationEvent_allOf::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRequestedQoS(std::move(value))) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_enforcement_method(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return false;

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return false;

    return obj->getEnforcementMethod().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_enforcement_method(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DynamicPolicyInvocationEvent_allOf::EnforcementMethodType ResultFromType;
    const ResultFromType &result_from = obj->getEnforcementMethod();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_method(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, const char* p_enforcement_method)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_method;
    typedef typename DynamicPolicyInvocationEvent_allOf::EnforcementMethodType ValueType;

    ValueType value(value_from);

    if (!obj->setEnforcementMethod(value)) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_method_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, char* p_enforcement_method)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_method;
    typedef typename DynamicPolicyInvocationEvent_allOf::EnforcementMethodType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEnforcementMethod(std::move(value))) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dynamic_policy_invocation_event_all_of_has_enforcement_bit_rate(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return false;

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return false;

    return obj->getEnforcementBitRate().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dynamic_policy_invocation_event_all_of_get_enforcement_bit_rate(const data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DynamicPolicyInvocationEvent_allOf::EnforcementBitRateType ResultFromType;
    const ResultFromType &result_from = obj->getEnforcementBitRate();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_bit_rate(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, const char* p_enforcement_bit_rate)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_bit_rate;
    typedef typename DynamicPolicyInvocationEvent_allOf::EnforcementBitRateType ValueType;

    ValueType value(value_from);

    if (!obj->setEnforcementBitRate(value)) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dynamic_policy_invocation_event_all_of_t *data_collection_model_dynamic_policy_invocation_event_all_of_set_enforcement_bit_rate_move(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of, char* p_enforcement_bit_rate)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return NULL;

    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_enforcement_bit_rate;
    typedef typename DynamicPolicyInvocationEvent_allOf::EnforcementBitRateType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEnforcementBitRate(std::move(value))) return NULL;

    return obj_dynamic_policy_invocation_event_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dynamic_policy_invocation_event_all_of_make_lnode(data_collection_model_dynamic_policy_invocation_event_all_of_t *p_dynamic_policy_invocation_event_all_of)
{
    return data_collection_lnode_create(p_dynamic_policy_invocation_event_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_dynamic_policy_invocation_event_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_dynamic_policy_invocation_event_all_of_refcount(data_collection_model_dynamic_policy_invocation_event_all_of_t *obj_dynamic_policy_invocation_event_all_of)
{
    if (!obj_dynamic_policy_invocation_event_all_of) return 0l;
    std::shared_ptr<DynamicPolicyInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<DynamicPolicyInvocationEvent_allOf >*>(obj_dynamic_policy_invocation_event_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

