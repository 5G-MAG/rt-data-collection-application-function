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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create(













)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent>(new NetworkAssistanceInvocationEvent(













)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create_copy(const data_collection_model_network_assistance_invocation_event_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent >(new NetworkAssistanceInvocationEvent(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create_move(data_collection_model_network_assistance_invocation_event_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > *obj = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_copy(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_network_assistance_invocation_event_t *other)
{
    if (network_assistance_invocation_event) {
        std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
        if (obj) {
            if (other) {
                const std::shared_ptr<NetworkAssistanceInvocationEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other);
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
                const std::shared_ptr<NetworkAssistanceInvocationEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other);
                if (other_obj) {
                    obj.reset(new NetworkAssistanceInvocationEvent(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        network_assistance_invocation_event = data_collection_model_network_assistance_invocation_event_create_copy(other);
    }
    return network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_network_assistance_invocation_event_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent > *other_ptr = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(other);

    if (network_assistance_invocation_event) {
        std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                network_assistance_invocation_event = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_event_free(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event)
{
    if (!network_assistance_invocation_event) return;
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_event_toJSON(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, bool as_request)
{
    if (!network_assistance_invocation_event) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(network_assistance_invocation_event);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_is_equal_to(const data_collection_model_network_assistance_invocation_event_t *first, const data_collection_model_network_assistance_invocation_event_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_network_assistance_invocation_event_get_record_type(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::RecordTypeType ResultFromType;
    const ResultFromType result_from = obj->getRecordType();
    const data_collection_model_event_record_type_t *result = reinterpret_cast<const data_collection_model_event_record_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_type(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename NetworkAssistanceInvocationEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRecordType(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_type_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename NetworkAssistanceInvocationEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setRecordType(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_record_timestamp(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::RecordTimestampType ResultFromType;
    const ResultFromType result_from = obj->getRecordTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_timestamp(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_record_timestamp)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename NetworkAssistanceInvocationEvent::RecordTimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setRecordTimestamp(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_timestamp_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_record_timestamp)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename NetworkAssistanceInvocationEvent::RecordTimestampType ValueType;

    ValueType value(value_from);

    
    if (!obj->setRecordTimestamp(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_app_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_app_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_app_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename NetworkAssistanceInvocationEvent::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_app_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_app_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename NetworkAssistanceInvocationEvent::AppIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAppId(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_provisioning_session_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getProvisioningSessionId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_provisioning_session_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::ProvisioningSessionIdType ResultFromType;
    const ResultFromType result_from = obj->getProvisioningSessionId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_provisioning_session_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_provisioning_session_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename NetworkAssistanceInvocationEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setProvisioningSessionId(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_provisioning_session_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_provisioning_session_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename NetworkAssistanceInvocationEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_session_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getSessionId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_session_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::SessionIdType ResultFromType;
    const ResultFromType result_from = obj->getSessionId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_session_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_session_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename NetworkAssistanceInvocationEvent::SessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSessionId(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_session_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_session_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename NetworkAssistanceInvocationEvent::SessionIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSessionId(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_ue_identification(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getUeIdentification().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_ue_identification(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::UeIdentificationType ResultFromType;
    const ResultFromType result_from = obj->getUeIdentification();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_identification(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_ue_identification)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename NetworkAssistanceInvocationEvent::UeIdentificationType ValueType;

    ValueType value(value_from);

    if (!obj->setUeIdentification(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_identification_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_ue_identification)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename NetworkAssistanceInvocationEvent::UeIdentificationType ValueType;

    ValueType value(value_from);

    
    if (!obj->setUeIdentification(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_data_network_name(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getDataNetworkName().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_data_network_name(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::DataNetworkNameType ResultFromType;
    const ResultFromType result_from = obj->getDataNetworkName();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_data_network_name(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_data_network_name)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename NetworkAssistanceInvocationEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_data_network_name_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_data_network_name)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename NetworkAssistanceInvocationEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_slice_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getSliceId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_network_assistance_invocation_event_get_slice_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::SliceIdType ResultFromType;
    const ResultFromType result_from = obj->getSliceId();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_slice_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename NetworkAssistanceInvocationEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceId(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_slice_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename NetworkAssistanceInvocationEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setSliceId(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_ue_locations(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getUeLocations().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocation_event_get_ue_locations(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ResultFromType;
    const ResultFromType result_from = obj->getUeLocations();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_location_area5_g_t*>(item.has_value()?new std::shared_ptr<LocationArea5G >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_location_area5_g_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const ogs_list_t* p_ue_locations)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ValueType;

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

    if (!obj->setUeLocations(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_locations_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, ogs_list_t* p_ue_locations)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType ValueType;

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

    data_collection_list_free(p_ue_locations);
    if (!obj->setUeLocations(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_add_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_locations;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addUeLocations(value.value());
    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_remove_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocationEvent::UeLocationsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_locations;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeUeLocations(value);
    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_clear_ue_locations(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    obj->clearUeLocations();
    return obj_network_assistance_invocation_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_type_t* data_collection_model_network_assistance_invocation_event_get_network_assistance_type(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const data_collection_model_network_assistance_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const data_collection_model_network_assistance_type_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::NetworkAssistanceTypeType ResultFromType;
    const ResultFromType result_from = obj->getNetworkAssistanceType();
    const data_collection_model_network_assistance_type_t *result = reinterpret_cast<const data_collection_model_network_assistance_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_network_assistance_type(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setNetworkAssistanceType(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_network_assistance_type_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setNetworkAssistanceType(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_policy_template_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getPolicyTemplateId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_policy_template_id(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::PolicyTemplateIdType ResultFromType;
    const ResultFromType result_from = obj->getPolicyTemplateId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_policy_template_id(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const char* p_policy_template_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocationEvent::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    if (!obj->setPolicyTemplateId(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_policy_template_id_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, char* p_policy_template_id)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename NetworkAssistanceInvocationEvent::PolicyTemplateIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_application_flow_descriptions(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getApplicationFlowDescriptions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocation_event_get_application_flow_descriptions(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ResultFromType;
    const ResultFromType result_from = obj->getApplicationFlowDescriptions();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ValueType;

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

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_application_flow_descriptions_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType ValueType;

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

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_add_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_application_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addApplicationFlowDescriptions(value.value());
    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_remove_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocationEvent::ApplicationFlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_application_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeApplicationFlowDescriptions(value);
    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_clear_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    obj->clearApplicationFlowDescriptions();
    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_requested_qo_s(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getRequestedQoS().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_network_assistance_invocation_event_get_requested_qo_s(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::RequestedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRequestedQoS();
    const data_collection_model_unidirectional_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_qo_s_specification_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_requested_qo_s(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRequestedQoS(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_requested_qo_s_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRequestedQoS(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_recommended_qo_s(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return false;

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return false;

    return obj->getRecommendedQoS().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_network_assistance_invocation_event_get_recommended_qo_s(const data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) {
        const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) {
        const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent::RecommendedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRecommendedQoS();
    const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = reinterpret_cast<const data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_recommended_qo_s(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRecommendedQoS(value)) return NULL;

    return obj_network_assistance_invocation_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_recommended_qo_s_move(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (!obj_network_assistance_invocation_event) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    if (!obj) return NULL;

    const auto &value_from = p_recommended_qo_s;
    typedef typename NetworkAssistanceInvocationEvent::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRecommendedQoS(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_event_make_lnode(data_collection_model_network_assistance_invocation_event_t *p_network_assistance_invocation_event)
{
    return data_collection_lnode_create(p_network_assistance_invocation_event, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocation_event_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocation_event_refcount(data_collection_model_network_assistance_invocation_event_t *obj_network_assistance_invocation_event)
{
    if (!obj_network_assistance_invocation_event) return 0l;
    std::shared_ptr<NetworkAssistanceInvocationEvent > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent >*>(obj_network_assistance_invocation_event);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

