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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create(



)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_t*>(new std::shared_ptr<NetworkAssistanceInvocation>(new NetworkAssistanceInvocation(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_copy(const data_collection_model_network_assistance_invocation_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_t*>(new std::shared_ptr<NetworkAssistanceInvocation >(new NetworkAssistanceInvocation(**reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_create_move(data_collection_model_network_assistance_invocation_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_t*>(new std::shared_ptr<NetworkAssistanceInvocation >(std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_copy(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, const data_collection_model_network_assistance_invocation_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
    *obj = **reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(other);
    return network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_move(data_collection_model_network_assistance_invocation_t *network_assistance_invocation, data_collection_model_network_assistance_invocation_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
    obj = std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(other));
    return network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_network_assistance_invocation_free(data_collection_model_network_assistance_invocation_t *network_assistance_invocation)
{
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_network_assistance_invocation_toJSON(const data_collection_model_network_assistance_invocation_t *network_assistance_invocation, bool as_request)
{
    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(network_assistance_invocation);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_get_policy_template_id(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    typedef typename NetworkAssistanceInvocation::PolicyTemplateIdType ResultFromType;
    const ResultFromType result_from = obj->getPolicyTemplateId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const char* p_policy_template_id)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocation::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    if (!obj->setPolicyTemplateId(value)) return NULL;
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_policy_template_id_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, char* p_policy_template_id)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocation::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_network_assistance_invocation_get_application_flow_descriptions(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ResultFromType;
    const ResultFromType result_from = obj->getApplicationFlowDescriptions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_application_flow_description_t *item_obj = reinterpret_cast<data_collection_model_application_flow_description_t*>(new std::shared_ptr<ApplicationFlowDescription >(item));
        node = data_collection_model_application_flow_description_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const ogs_list_t* p_application_flow_descriptions)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setApplicationFlowDescriptions(value)) return NULL;
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_application_flow_descriptions_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, ogs_list_t* p_application_flow_descriptions)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_application_flow_descriptions);
    if (!obj->setApplicationFlowDescriptions(std::move(value))) return NULL;
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_add_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_application_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addApplicationFlowDescriptions(value);
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_remove_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    typedef typename NetworkAssistanceInvocation::ApplicationFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_application_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeApplicationFlowDescriptions(value);
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_clear_application_flow_descriptions(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{   
    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    obj->clearApplicationFlowDescriptions();
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_network_assistance_invocation_get_requested_qo_s(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    typedef typename NetworkAssistanceInvocation::RequestedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRequestedQoS();
    const data_collection_model_unidirectional_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_qo_s_specification_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocation::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRequestedQoS(value)) return NULL;
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_requested_qo_s_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocation::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRequestedQoS(std::move(value))) return NULL;
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_network_assistance_invocation_get_recommended_qo_s(const data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    const std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    typedef typename NetworkAssistanceInvocation::RecommendedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRecommendedQoS();
    const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = reinterpret_cast<const data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocation::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRecommendedQoS(value)) return NULL;
    return obj_network_assistance_invocation;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_t *data_collection_model_network_assistance_invocation_set_recommended_qo_s_move(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (obj_network_assistance_invocation == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocation::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRecommendedQoS(std::move(value))) return NULL;
    return obj_network_assistance_invocation;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_network_assistance_invocation_make_lnode(data_collection_model_network_assistance_invocation_t *p_network_assistance_invocation)
{
    return data_collection_lnode_create(p_network_assistance_invocation, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocation_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocation_refcount(data_collection_model_network_assistance_invocation_t *obj_network_assistance_invocation)
{
    std::shared_ptr<NetworkAssistanceInvocation > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation >*>(obj_network_assistance_invocation);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

