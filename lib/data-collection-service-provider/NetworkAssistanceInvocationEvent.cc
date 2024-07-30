/**********************************************************************************************************************************
 * NetworkAssistanceInvocationEvent - C interface to the NetworkAssistanceInvocationEvent object
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

/*#include "NetworkAssistanceInvocationEvent.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceInvocationEvent-internal.h"
#include "openapi/model/NetworkAssistanceInvocationEvent.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create(













)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent>(new NetworkAssistanceInvocationEvent(













)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create_copy(const data_collection_model_network_assistance_invocation_event_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent >(new NetworkAssistanceInvocationEvent(**reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create_move(data_collection_model_network_assistance_invocation_event_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent >(std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_copy(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_network_assistance_invocation_event_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
    *obj = **reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other);
    return network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_network_assistance_invocation_event_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
    obj = std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other));
    return network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_network_assistance_invocation_event_free(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event)
{
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_network_assistance_invocation_event_toJSON(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, bool as_request)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_invocation_event_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent >(new NetworkAssistanceInvocationEvent(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_network_assistance_invocation_event_is_equal_to(const data_collection_model_network_assistance_invocation_event_t *first, const data_collection_model_network_assistance_invocation_event_t *second)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(first);
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_event_record_type_t* data_collection_model_network_assistance_invocation_event_get_record_type(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::RecordTypeType ResultFromType;
    const ResultFromType result_from = obj->getRecordType();
    const data_collection_model_event_record_type_t *result = reinterpret_cast<const data_collection_model_event_record_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_type(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_event_record_type_t* p_record_type)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_record_type;
    typedef typename NetworkAssistanceInvocationEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRecordType(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_type_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_event_record_type_t* p_record_type)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_record_type;
    typedef typename NetworkAssistanceInvocationEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRecordType(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_event_get_record_timestamp(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::RecordTimestampType ResultFromType;
    const ResultFromType result_from = obj->getRecordTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_timestamp(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_record_timestamp)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_record_timestamp;
    typedef typename NetworkAssistanceInvocationEvent::RecordTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setRecordTimestamp(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_timestamp_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_record_timestamp)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_record_timestamp;
    typedef typename NetworkAssistanceInvocationEvent::RecordTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRecordTimestamp(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_event_get_app_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_app_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_app_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_app_id;
    typedef typename NetworkAssistanceInvocationEvent::AppIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAppId(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_app_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_app_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_app_id;
    typedef typename NetworkAssistanceInvocationEvent::AppIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAppId(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_event_get_provisioning_session_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::ProvisioningSessionIdType ResultFromType;
    const ResultFromType result_from = obj->getProvisioningSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_provisioning_session_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_provisioning_session_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_provisioning_session_id;
    typedef typename NetworkAssistanceInvocationEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setProvisioningSessionId(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_provisioning_session_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_provisioning_session_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_provisioning_session_id;
    typedef typename NetworkAssistanceInvocationEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_event_get_session_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::SessionIdType ResultFromType;
    const ResultFromType result_from = obj->getSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_session_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_session_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_session_id;
    typedef typename NetworkAssistanceInvocationEvent::SessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSessionId(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_session_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_session_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_session_id;
    typedef typename NetworkAssistanceInvocationEvent::SessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSessionId(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_event_get_ue_identification(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::UeIdentificationType ResultFromType;
    const ResultFromType result_from = obj->getUeIdentification();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_identification(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_ue_identification)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_ue_identification;
    typedef typename NetworkAssistanceInvocationEvent::UeIdentificationType ValueType;

    ValueType value(value_from);
    if (!obj->setUeIdentification(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_identification_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_ue_identification)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_ue_identification;
    typedef typename NetworkAssistanceInvocationEvent::UeIdentificationType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUeIdentification(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_event_get_data_network_name(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::DataNetworkNameType ResultFromType;
    const ResultFromType result_from = obj->getDataNetworkName();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_data_network_name(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_data_network_name)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_data_network_name;
    typedef typename NetworkAssistanceInvocationEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);
    if (!obj->setDataNetworkName(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_data_network_name_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_data_network_name)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_data_network_name;
    typedef typename NetworkAssistanceInvocationEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_snssai_t* data_collection_model_network_assistance_invocation_event_get_slice_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::SliceIdType ResultFromType;
    const ResultFromType result_from = obj->getSliceId();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_slice_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_snssai_t* p_slice_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_slice_id;
    typedef typename NetworkAssistanceInvocationEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSliceId(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_slice_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_snssai_t* p_slice_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_slice_id;
    typedef typename NetworkAssistanceInvocationEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSliceId(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_network_assistance_invocation_event_get_ue_locations(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ResultFromType;
    const ResultFromType result_from = obj->getUeLocations();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_location_area5_g_t*>(new std::shared_ptr<LocationArea5G >(item));
        node = data_collection_model_location_area5_g_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const ogs_list_t* p_ue_locations)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_ue_locations;
    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setUeLocations(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_locations_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, ogs_list_t* p_ue_locations)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_ue_locations;
    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ue_locations);
    if (!obj->setUeLocations(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_add_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_location_area5_g_t* p_ue_locations)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_locations;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addUeLocations(value);
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_remove_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_location_area5_g_t* p_ue_locations)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_locations;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeUeLocations(value);
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_clear_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{   
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    obj->clearUeLocations();
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_network_assistance_type_t* data_collection_model_network_assistance_invocation_event_get_network_assistance_type(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::NetworkAssistanceTypeType ResultFromType;
    const ResultFromType result_from = obj->getNetworkAssistanceType();
    const data_collection_model_network_assistance_type_t *result = reinterpret_cast<const data_collection_model_network_assistance_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_network_assistance_type(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNetworkAssistanceType(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_network_assistance_type_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNetworkAssistanceType(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_network_assistance_invocation_event_get_policy_template_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::PolicyTemplateIdType ResultFromType;
    const ResultFromType result_from = obj->getPolicyTemplateId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_policy_template_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_policy_template_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocationEvent::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    if (!obj->setPolicyTemplateId(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_policy_template_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_policy_template_id)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocationEvent::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_network_assistance_invocation_event_get_application_flow_descriptions(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const ogs_list_t* p_application_flow_descriptions)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setApplicationFlowDescriptions(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_application_flow_descriptions_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, ogs_list_t* p_application_flow_descriptions)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ValueType;

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
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_add_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_application_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addApplicationFlowDescriptions(value);
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_remove_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_application_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeApplicationFlowDescriptions(value);
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_clear_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{   
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    obj->clearApplicationFlowDescriptions();
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_network_assistance_invocation_event_get_requested_qo_s(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::RequestedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRequestedQoS();
    const data_collection_model_unidirectional_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_qo_s_specification_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_requested_qo_s(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRequestedQoS(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_requested_qo_s_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRequestedQoS(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_network_assistance_invocation_event_get_recommended_qo_s(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    typedef typename NetworkAssistanceInvocationEvent::RecommendedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRecommendedQoS();
    const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = reinterpret_cast<const data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_recommended_qo_s(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRecommendedQoS(value)) return NULL;
    return obj_network_assistance_invocation_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_recommended_qo_s_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (obj_network_assistance_invocation_event == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRecommendedQoS(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_network_assistance_invocation_event_make_lnode(data_collection_model_network_assistance_invocation_event_t *p_network_assistance_invocation_event)
{
    return data_collection_lnode_create(p_network_assistance_invocation_event, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocation_event_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocation_event_refcount(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

