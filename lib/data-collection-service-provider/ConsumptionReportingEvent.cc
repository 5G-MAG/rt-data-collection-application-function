/**********************************************************************************************************************************
 * ConsumptionReportingEvent - C interface to the ConsumptionReportingEvent object
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

/*#include "ConsumptionReportingEvent.h" already included by data-collection-sp/data-collection.h */
#include "ConsumptionReportingEvent-internal.h"
#include "openapi/model/ConsumptionReportingEvent.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_create(













)
{
    return reinterpret_cast<data_collection_model_consumption_reporting_event_t*>(new std::shared_ptr<ConsumptionReportingEvent>(new ConsumptionReportingEvent(













)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_create_ref(const data_collection_model_consumption_reporting_event_t *other)
{
    return reinterpret_cast<data_collection_model_consumption_reporting_event_t*>(new std::shared_ptr<ConsumptionReportingEvent>(*reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_create_copy(const data_collection_model_consumption_reporting_event_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_consumption_reporting_event_t*>(new std::shared_ptr<ConsumptionReportingEvent >(new ConsumptionReportingEvent(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_create_move(data_collection_model_consumption_reporting_event_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > *obj = reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_copy(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_consumption_reporting_event_t *other)
{
    if (consumption_reporting_event) {
        std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(consumption_reporting_event);
        if (obj) {
            if (other) {
                const std::shared_ptr<ConsumptionReportingEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(other);
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
                const std::shared_ptr<ConsumptionReportingEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(other);
                if (other_obj) {
                    obj.reset(new ConsumptionReportingEvent(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        consumption_reporting_event = data_collection_model_consumption_reporting_event_create_copy(other);
    }
    return consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, data_collection_model_consumption_reporting_event_t *other)
{
    std::shared_ptr<ConsumptionReportingEvent > *other_ptr = reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(other);

    if (consumption_reporting_event) {
        std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(consumption_reporting_event);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                consumption_reporting_event = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_consumption_reporting_event_free(data_collection_model_consumption_reporting_event_t *consumption_reporting_event)
{
    if (!consumption_reporting_event) return;
    delete reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(consumption_reporting_event);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_consumption_reporting_event_toJSON(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event, bool as_request)
{
    if (!consumption_reporting_event) return NULL;
    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(consumption_reporting_event);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_consumption_reporting_event_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_consumption_reporting_event_t*>(new std::shared_ptr<ConsumptionReportingEvent >(new ConsumptionReportingEvent(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_is_equal_to(const data_collection_model_consumption_reporting_event_t *first, const data_collection_model_consumption_reporting_event_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ConsumptionReportingEvent > &obj2 = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ConsumptionReportingEvent > &obj1 = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_consumption_reporting_event_get_record_type(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::RecordTypeType ResultFromType;
    const ResultFromType &result_from = obj->getRecordType();
    const data_collection_model_event_record_type_t *result = reinterpret_cast<const data_collection_model_event_record_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_type(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename ConsumptionReportingEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRecordType(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_type_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename ConsumptionReportingEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRecordType(std::move(value))) return NULL;
    data_collection_model_event_record_type_free
(p_record_type);

    return obj_consumption_reporting_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_record_timestamp(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::RecordTimestampType ResultFromType;
    const ResultFromType &result_from = obj->getRecordTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_timestamp(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_record_timestamp)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename ConsumptionReportingEvent::RecordTimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setRecordTimestamp(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_timestamp_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_record_timestamp)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename ConsumptionReportingEvent::RecordTimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setRecordTimestamp(std::move(value))) return NULL;
    ogs_free
(p_record_timestamp);

    return obj_consumption_reporting_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_app_id(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::AppIdType ResultFromType;
    const ResultFromType &result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_app_id(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_app_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename ConsumptionReportingEvent::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_app_id_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_app_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename ConsumptionReportingEvent::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(std::move(value))) return NULL;
    ogs_free
(p_app_id);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_provisioning_session_id(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getProvisioningSessionId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_provisioning_session_id(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::ProvisioningSessionIdType ResultFromType;
    const ResultFromType &result_from = obj->getProvisioningSessionId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_provisioning_session_id(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_provisioning_session_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename ConsumptionReportingEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setProvisioningSessionId(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_provisioning_session_id_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_provisioning_session_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename ConsumptionReportingEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;
    ogs_free
(p_provisioning_session_id);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_session_id(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getSessionId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_session_id(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::SessionIdType ResultFromType;
    const ResultFromType &result_from = obj->getSessionId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_session_id(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_session_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename ConsumptionReportingEvent::SessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSessionId(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_session_id_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_session_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename ConsumptionReportingEvent::SessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSessionId(std::move(value))) return NULL;
    ogs_free
(p_session_id);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_ue_identification(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getUeIdentification().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_ue_identification(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::UeIdentificationType ResultFromType;
    const ResultFromType &result_from = obj->getUeIdentification();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_identification(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_ue_identification)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename ConsumptionReportingEvent::UeIdentificationType ValueType;

    ValueType value(value_from);

    if (!obj->setUeIdentification(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_identification_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_ue_identification)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename ConsumptionReportingEvent::UeIdentificationType ValueType;

    ValueType value(value_from);

    if (!obj->setUeIdentification(std::move(value))) return NULL;
    ogs_free
(p_ue_identification);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_data_network_name(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getDataNetworkName().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_data_network_name(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::DataNetworkNameType ResultFromType;
    const ResultFromType &result_from = obj->getDataNetworkName();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_data_network_name(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_data_network_name)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename ConsumptionReportingEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_data_network_name_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_data_network_name)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename ConsumptionReportingEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(std::move(value))) return NULL;
    ogs_free
(p_data_network_name);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_slice_id(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getSliceId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_consumption_reporting_event_get_slice_id(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::SliceIdType ResultFromType;
    const ResultFromType &result_from = obj->getSliceId();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_slice_id(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename ConsumptionReportingEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceId(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_slice_id_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename ConsumptionReportingEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceId(std::move(value))) return NULL;
    data_collection_model_snssai_free
(p_slice_id);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_ue_locations(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getUeLocations().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_consumption_reporting_event_get_ue_locations(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::UeLocationsType ResultFromType;
    const ResultFromType &result_from = obj->getUeLocations();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_locations(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const ogs_list_t* p_ue_locations)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename ConsumptionReportingEvent::UeLocationsType ValueType;

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

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_locations_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, ogs_list_t* p_ue_locations)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename ConsumptionReportingEvent::UeLocationsType ValueType;

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

    if (!obj->setUeLocations(std::move(value))) return NULL;
    data_collection_list_free
(p_ue_locations);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_add_ue_locations(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    typedef typename ConsumptionReportingEvent::UeLocationsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_locations;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_location_area5_g_free
(p_ue_locations);
    if (value) obj->addUeLocations(value.value());
    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_remove_ue_locations(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    typedef typename ConsumptionReportingEvent::UeLocationsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_locations;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeUeLocations(value);
    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_consumption_reporting_event_get_entry_ue_locations(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, size_t idx)
{
    if (!obj_consumption_reporting_event) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }

    const ConsumptionReportingEvent::UeLocationsType &container = obj->getUeLocations();
    if (!container.has_value()) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_location_area5_g_t *result = NULL;

        return result;
    }
    typedef typename ConsumptionReportingEvent::UeLocationsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_clear_ue_locations(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    obj->clearUeLocations();
    return obj_consumption_reporting_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_unit_duration(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::UnitDurationType ResultFromType;
    const ResultFromType &result_from = obj->getUnitDuration();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_unit_duration(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_unit_duration)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_unit_duration;
    typedef typename ConsumptionReportingEvent::UnitDurationType ValueType;

    ValueType value(value_from);

    if (!obj->setUnitDuration(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_unit_duration_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_unit_duration)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_unit_duration;
    typedef typename ConsumptionReportingEvent::UnitDurationType ValueType;

    ValueType value(value_from);

    if (!obj->setUnitDuration(std::move(value))) return NULL;
    ogs_free
(p_unit_duration);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_client_endpoint_address(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getClientEndpointAddress().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_get_client_endpoint_address(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::ClientEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getClientEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_client_endpoint_address(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const data_collection_model_endpoint_address_t* p_client_endpoint_address)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_client_endpoint_address;
    typedef typename ConsumptionReportingEvent::ClientEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setClientEndpointAddress(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_client_endpoint_address_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, data_collection_model_endpoint_address_t* p_client_endpoint_address)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_client_endpoint_address;
    typedef typename ConsumptionReportingEvent::ClientEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setClientEndpointAddress(std::move(value))) return NULL;
    data_collection_model_endpoint_address_free
(p_client_endpoint_address);

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_server_endpoint_address(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return false;

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return false;

    return obj->getServerEndpointAddress().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_get_server_endpoint_address(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::ServerEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getServerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_server_endpoint_address(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const data_collection_model_endpoint_address_t* p_server_endpoint_address)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_server_endpoint_address;
    typedef typename ConsumptionReportingEvent::ServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setServerEndpointAddress(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_server_endpoint_address_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, data_collection_model_endpoint_address_t* p_server_endpoint_address)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_server_endpoint_address;
    typedef typename ConsumptionReportingEvent::ServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setServerEndpointAddress(std::move(value))) return NULL;
    data_collection_model_endpoint_address_free
(p_server_endpoint_address);

    return obj_consumption_reporting_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_media_player_entry_url(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::MediaPlayerEntryUrlType ResultFromType;
    const ResultFromType &result_from = obj->getMediaPlayerEntryUrl();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_player_entry_url(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_media_player_entry_url)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_media_player_entry_url;
    typedef typename ConsumptionReportingEvent::MediaPlayerEntryUrlType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaPlayerEntryUrl(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_player_entry_url_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_media_player_entry_url)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_media_player_entry_url;
    typedef typename ConsumptionReportingEvent::MediaPlayerEntryUrlType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaPlayerEntryUrl(std::move(value))) return NULL;
    ogs_free
(p_media_player_entry_url);

    return obj_consumption_reporting_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_media_component_identifier(const data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent::MediaComponentIdentifierType ResultFromType;
    const ResultFromType &result_from = obj->getMediaComponentIdentifier();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_component_identifier(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, const char* p_media_component_identifier)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_media_component_identifier;
    typedef typename ConsumptionReportingEvent::MediaComponentIdentifierType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaComponentIdentifier(value)) return NULL;

    return obj_consumption_reporting_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_component_identifier_move(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event, char* p_media_component_identifier)
{
    if (!obj_consumption_reporting_event) return NULL;

    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    if (!obj) return NULL;

    const auto &value_from = p_media_component_identifier;
    typedef typename ConsumptionReportingEvent::MediaComponentIdentifierType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaComponentIdentifier(std::move(value))) return NULL;
    ogs_free
(p_media_component_identifier);

    return obj_consumption_reporting_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_consumption_reporting_event_make_lnode(data_collection_model_consumption_reporting_event_t *p_consumption_reporting_event)
{
    return data_collection_lnode_create(p_consumption_reporting_event, reinterpret_cast<void(*)(void*)>(data_collection_model_consumption_reporting_event_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_consumption_reporting_event_refcount(data_collection_model_consumption_reporting_event_t *obj_consumption_reporting_event)
{
    if (!obj_consumption_reporting_event) return 0l;
    std::shared_ptr<ConsumptionReportingEvent > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent >*>(obj_consumption_reporting_event);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

