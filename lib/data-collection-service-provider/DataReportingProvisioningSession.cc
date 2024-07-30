/**********************************************************************************************************************************
 * DataReportingProvisioningSession - C interface to the DataReportingProvisioningSession object
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

/*#include "DataReportingProvisioningSession.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingProvisioningSession-internal.h"
#include "openapi/model/DataReportingProvisioningSession.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create(





)
{
    return reinterpret_cast<data_collection_model_data_reporting_provisioning_session_t*>(new std::shared_ptr<DataReportingProvisioningSession>(new DataReportingProvisioningSession(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create_copy(const data_collection_model_data_reporting_provisioning_session_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_provisioning_session_t*>(new std::shared_ptr<DataReportingProvisioningSession >(new DataReportingProvisioningSession(**reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create_move(data_collection_model_data_reporting_provisioning_session_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_provisioning_session_t*>(new std::shared_ptr<DataReportingProvisioningSession >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_copy(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const data_collection_model_data_reporting_provisioning_session_t *other)
{
    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(data_reporting_provisioning_session);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(other);
    return data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, data_collection_model_data_reporting_provisioning_session_t *other)
{
    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(data_reporting_provisioning_session);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(other));
    return data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_provisioning_session_free(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(data_reporting_provisioning_session);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_provisioning_session_toJSON(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, bool as_request)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(data_reporting_provisioning_session);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_provisioning_session_t*>(new std::shared_ptr<DataReportingProvisioningSession >(new DataReportingProvisioningSession(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_reporting_provisioning_session_is_equal_to(const data_collection_model_data_reporting_provisioning_session_t *first, const data_collection_model_data_reporting_provisioning_session_t *second)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(first);
    const std::shared_ptr<DataReportingProvisioningSession > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_provisioning_session_get_provisioning_session_id(const data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::ProvisioningSessionIdType ResultFromType;
    const ResultFromType result_from = obj->getProvisioningSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, const char* p_provisioning_session_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_provisioning_session_id;
    typedef typename DataReportingProvisioningSession::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setProvisioningSessionId(value)) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id_move(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, char* p_provisioning_session_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_provisioning_session_id;
    typedef typename DataReportingProvisioningSession::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_provisioning_session_get_asp_id(const data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::AspIdType ResultFromType;
    const ResultFromType result_from = obj->getAspId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_asp_id(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, const char* p_asp_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_asp_id;
    typedef typename DataReportingProvisioningSession::AspIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAspId(value)) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_asp_id_move(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, char* p_asp_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_asp_id;
    typedef typename DataReportingProvisioningSession::AspIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAspId(std::move(value))) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_provisioning_session_get_external_application_id(const data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::ExternalApplicationIdType ResultFromType;
    const ResultFromType result_from = obj->getExternalApplicationId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_external_application_id(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, const char* p_external_application_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_external_application_id;
    typedef typename DataReportingProvisioningSession::ExternalApplicationIdType ValueType;

    ValueType value(value_from);
    if (!obj->setExternalApplicationId(value)) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_external_application_id_move(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, char* p_external_application_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_external_application_id;
    typedef typename DataReportingProvisioningSession::ExternalApplicationIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setExternalApplicationId(std::move(value))) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_reporting_provisioning_session_get_internal_application_id(const data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::InternalApplicationIdType ResultFromType;
    const ResultFromType result_from = obj->getInternalApplicationId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_internal_application_id(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, const char* p_internal_application_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_internal_application_id;
    typedef typename DataReportingProvisioningSession::InternalApplicationIdType ValueType;

    ValueType value(value_from);
    if (!obj->setInternalApplicationId(value)) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_internal_application_id_move(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, char* p_internal_application_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_internal_application_id;
    typedef typename DataReportingProvisioningSession::InternalApplicationIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setInternalApplicationId(std::move(value))) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_af_event_t* data_collection_model_data_reporting_provisioning_session_get_event_id(const data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::EventIdType ResultFromType;
    const ResultFromType result_from = obj->getEventId();
    const data_collection_model_af_event_t *result = reinterpret_cast<const data_collection_model_af_event_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_event_id(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, const data_collection_model_af_event_t* p_event_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_event_id;
    typedef typename DataReportingProvisioningSession::EventIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEventId(value)) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_event_id_move(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, data_collection_model_af_event_t* p_event_id)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_event_id;
    typedef typename DataReportingProvisioningSession::EventIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEventId(std::move(value))) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_reporting_provisioning_session_get_data_reporting_configuration_ids(const data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{
    const std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::DataReportingConfigurationIdsType ResultFromType;
    const ResultFromType result_from = obj->getDataReportingConfigurationIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, const ogs_list_t* p_data_reporting_configuration_ids)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_data_reporting_configuration_ids;
    typedef typename DataReportingProvisioningSession::DataReportingConfigurationIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setDataReportingConfigurationIds(value)) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_data_reporting_configuration_ids_move(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, ogs_list_t* p_data_reporting_configuration_ids)
{
    if (obj_data_reporting_provisioning_session == NULL) return NULL;

    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    const auto &value_from = p_data_reporting_configuration_ids;
    typedef typename DataReportingProvisioningSession::DataReportingConfigurationIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_data_reporting_configuration_ids);
    if (!obj->setDataReportingConfigurationIds(std::move(value))) return NULL;
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_add_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, char* p_data_reporting_configuration_ids)
{
    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::DataReportingConfigurationIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_data_reporting_configuration_ids;

    ValueType value(value_from);

    obj->addDataReportingConfigurationIds(value);
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_remove_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session, const char* p_data_reporting_configuration_ids)
{
    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    typedef typename DataReportingProvisioningSession::DataReportingConfigurationIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_data_reporting_configuration_ids;
    ValueType value(value_from);
    obj->removeDataReportingConfigurationIds(value);
    return obj_data_reporting_provisioning_session;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_clear_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{   
    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    obj->clearDataReportingConfigurationIds();
    return obj_data_reporting_provisioning_session;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_provisioning_session_make_lnode(data_collection_model_data_reporting_provisioning_session_t *p_data_reporting_provisioning_session)
{
    return data_collection_lnode_create(p_data_reporting_provisioning_session, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_provisioning_session_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_provisioning_session_refcount(data_collection_model_data_reporting_provisioning_session_t *obj_data_reporting_provisioning_session)
{
    std::shared_ptr<DataReportingProvisioningSession > &obj = *reinterpret_cast<std::shared_ptr<DataReportingProvisioningSession >*>(obj_data_reporting_provisioning_session);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

