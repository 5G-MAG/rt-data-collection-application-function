/**********************************************************************************************************************************
 * NetworkAssistanceSession - C interface to the NetworkAssistanceSession object
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

/*#include "NetworkAssistanceSession.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceSession-internal.h"
#include "openapi/model/NetworkAssistanceSession.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create(







)
{
    return reinterpret_cast<data_collection_model_network_assistance_session_t*>(new std::shared_ptr<NetworkAssistanceSession>(new NetworkAssistanceSession(







)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create_copy(const data_collection_model_network_assistance_session_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_session_t*>(new std::shared_ptr<NetworkAssistanceSession >(new NetworkAssistanceSession(**reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_create_move(data_collection_model_network_assistance_session_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_session_t*>(new std::shared_ptr<NetworkAssistanceSession >(std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_copy(data_collection_model_network_assistance_session_t *network_assistance_session, const data_collection_model_network_assistance_session_t *other)
{
    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(network_assistance_session);
    *obj = **reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(other);
    return network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_move(data_collection_model_network_assistance_session_t *network_assistance_session, data_collection_model_network_assistance_session_t *other)
{
    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(network_assistance_session);
    obj = std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(other));
    return network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_network_assistance_session_free(data_collection_model_network_assistance_session_t *network_assistance_session)
{
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(network_assistance_session);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_network_assistance_session_toJSON(const data_collection_model_network_assistance_session_t *network_assistance_session, bool as_request)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(network_assistance_session);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_session_t*>(new std::shared_ptr<NetworkAssistanceSession >(new NetworkAssistanceSession(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_session_get_na_session_id(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::NaSessionIdType ResultFromType;
    const ResultFromType result_from = obj->getNaSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_na_session_id(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const char* p_na_session_id)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_na_session_id;
    typedef typename NetworkAssistanceSession::NaSessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setNaSessionId(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_na_session_id_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, char* p_na_session_id)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_na_session_id;
    typedef typename NetworkAssistanceSession::NaSessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNaSessionId(std::move(value))) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_session_get_provisioning_session_id(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::ProvisioningSessionIdType ResultFromType;
    const ResultFromType result_from = obj->getProvisioningSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_provisioning_session_id(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const char* p_provisioning_session_id)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_provisioning_session_id;
    typedef typename NetworkAssistanceSession::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setProvisioningSessionId(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_provisioning_session_id_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, char* p_provisioning_session_id)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_provisioning_session_id;
    typedef typename NetworkAssistanceSession::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_network_assistance_session_get_service_data_flow_descriptions(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::ServiceDataFlowDescriptionsType ResultFromType;
    const ResultFromType result_from = obj->getServiceDataFlowDescriptions();
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const ogs_list_t* p_service_data_flow_descriptions)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_service_data_flow_descriptions;
    typedef typename NetworkAssistanceSession::ServiceDataFlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setServiceDataFlowDescriptions(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_service_data_flow_descriptions_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, ogs_list_t* p_service_data_flow_descriptions)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_service_data_flow_descriptions;
    typedef typename NetworkAssistanceSession::ServiceDataFlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_service_data_flow_descriptions);
    if (!obj->setServiceDataFlowDescriptions(std::move(value))) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_add_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *obj_network_assistance_session, data_collection_model_application_flow_description_t* p_service_data_flow_descriptions)
{
    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::ServiceDataFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_service_data_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addServiceDataFlowDescriptions(value);
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_remove_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const data_collection_model_application_flow_description_t* p_service_data_flow_descriptions)
{
    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::ServiceDataFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_service_data_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeServiceDataFlowDescriptions(value);
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_clear_service_data_flow_descriptions(data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{   
    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    obj->clearServiceDataFlowDescriptions();
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_media_type_t* data_collection_model_network_assistance_session_get_media_type(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::MediaTypeType ResultFromType;
    const ResultFromType result_from = obj->getMediaType();
    const data_collection_model_media_type_t *result = reinterpret_cast<const data_collection_model_media_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_media_type(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const data_collection_model_media_type_t* p_media_type)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_media_type;
    typedef typename NetworkAssistanceSession::MediaTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMediaType(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_media_type_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, data_collection_model_media_type_t* p_media_type)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_media_type;
    typedef typename NetworkAssistanceSession::MediaTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMediaType(std::move(value))) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_session_get_policy_template_id(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::PolicyTemplateIdType ResultFromType;
    const ResultFromType result_from = obj->getPolicyTemplateId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_policy_template_id(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const char* p_policy_template_id)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceSession::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    if (!obj->setPolicyTemplateId(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_policy_template_id_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, char* p_policy_template_id)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceSession::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_m5_qo_s_specification_t* data_collection_model_network_assistance_session_get_requested_qo_s(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::RequestedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRequestedQoS();
    const data_collection_model_m5_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_m5_qo_s_specification_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_requested_qo_s(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const data_collection_model_m5_qo_s_specification_t* p_requested_qo_s)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceSession::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRequestedQoS(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_requested_qo_s_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, data_collection_model_m5_qo_s_specification_t* p_requested_qo_s)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceSession::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRequestedQoS(std::move(value))) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_m5_qo_s_specification_t* data_collection_model_network_assistance_session_get_recommended_qo_s(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::RecommendedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRecommendedQoS();
    const data_collection_model_m5_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_m5_qo_s_specification_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_recommended_qo_s(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const data_collection_model_m5_qo_s_specification_t* p_recommended_qo_s)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceSession::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRecommendedQoS(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_recommended_qo_s_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, data_collection_model_m5_qo_s_specification_t* p_recommended_qo_s)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceSession::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRecommendedQoS(std::move(value))) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_session_get_notfication_url(const data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    const std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    typedef typename NetworkAssistanceSession::NotficationURLType ResultFromType;
    const ResultFromType result_from = obj->getNotficationURL();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_notfication_url(data_collection_model_network_assistance_session_t *obj_network_assistance_session, const char* p_notfication_url)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_notfication_url;
    typedef typename NetworkAssistanceSession::NotficationURLType ValueType;

    ValueType value(value_from);
    if (!obj->setNotficationURL(value)) return NULL;
    return obj_network_assistance_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_session_t *data_collection_model_network_assistance_session_set_notfication_url_move(data_collection_model_network_assistance_session_t *obj_network_assistance_session, char* p_notfication_url)
{
    if (obj_network_assistance_session == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    const auto &value_from = p_notfication_url;
    typedef typename NetworkAssistanceSession::NotficationURLType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNotficationURL(std::move(value))) return NULL;
    return obj_network_assistance_session;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_network_assistance_session_make_lnode(data_collection_model_network_assistance_session_t *p_network_assistance_session)
{
    return data_collection_lnode_create(p_network_assistance_session, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_session_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_session_refcount(data_collection_model_network_assistance_session_t *obj_network_assistance_session)
{
    std::shared_ptr<NetworkAssistanceSession > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceSession >*>(obj_network_assistance_session);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

