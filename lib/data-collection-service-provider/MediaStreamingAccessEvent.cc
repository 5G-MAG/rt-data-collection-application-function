/**********************************************************************************************************************************
 * MediaStreamingAccessEvent - C interface to the MediaStreamingAccessEvent object
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

/*#include "MediaStreamingAccessEvent.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccessEvent-internal.h"
#include "openapi/model/MediaStreamingAccessEvent.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_create(















)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_event_t*>(new std::shared_ptr<MediaStreamingAccessEvent>(new MediaStreamingAccessEvent(















)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_create_copy(const data_collection_model_media_streaming_access_event_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_streaming_access_event_t*>(new std::shared_ptr<MediaStreamingAccessEvent >(new MediaStreamingAccessEvent(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_create_move(data_collection_model_media_streaming_access_event_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > *obj = reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_copy(data_collection_model_media_streaming_access_event_t *media_streaming_access_event, const data_collection_model_media_streaming_access_event_t *other)
{
    if (media_streaming_access_event) {
        std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(media_streaming_access_event);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaStreamingAccessEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(other);
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
                const std::shared_ptr<MediaStreamingAccessEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(other);
                if (other_obj) {
                    obj.reset(new MediaStreamingAccessEvent(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_streaming_access_event = data_collection_model_media_streaming_access_event_create_copy(other);
    }
    return media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_move(data_collection_model_media_streaming_access_event_t *media_streaming_access_event, data_collection_model_media_streaming_access_event_t *other)
{
    std::shared_ptr<MediaStreamingAccessEvent > *other_ptr = reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(other);

    if (media_streaming_access_event) {
        std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(media_streaming_access_event);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_streaming_access_event = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_event_free(data_collection_model_media_streaming_access_event_t *media_streaming_access_event)
{
    if (!media_streaming_access_event) return;
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(media_streaming_access_event);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_event_toJSON(const data_collection_model_media_streaming_access_event_t *media_streaming_access_event, bool as_request)
{
    if (!media_streaming_access_event) return NULL;
    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(media_streaming_access_event);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_access_event_t*>(new std::shared_ptr<MediaStreamingAccessEvent >(new MediaStreamingAccessEvent(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_event_is_equal_to(const data_collection_model_media_streaming_access_event_t *first, const data_collection_model_media_streaming_access_event_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaStreamingAccessEvent > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaStreamingAccessEvent > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_media_streaming_access_event_get_record_type(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_event_record_type_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::RecordTypeType ResultFromType;
    const ResultFromType result_from = obj->getRecordType();
    const data_collection_model_event_record_type_t *result = reinterpret_cast<const data_collection_model_event_record_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_record_type(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename MediaStreamingAccessEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRecordType(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_record_type_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_event_record_type_t* p_record_type)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_type;
    typedef typename MediaStreamingAccessEvent::RecordTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRecordType(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_event_get_record_timestamp(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::RecordTimestampType ResultFromType;
    const ResultFromType result_from = obj->getRecordTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_record_timestamp(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const char* p_record_timestamp)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename MediaStreamingAccessEvent::RecordTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setRecordTimestamp(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_record_timestamp_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, char* p_record_timestamp)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_record_timestamp;
    typedef typename MediaStreamingAccessEvent::RecordTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRecordTimestamp(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_event_get_app_id(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_app_id(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const char* p_app_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename MediaStreamingAccessEvent::AppIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAppId(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_app_id_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, char* p_app_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename MediaStreamingAccessEvent::AppIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAppId(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_event_get_provisioning_session_id(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::ProvisioningSessionIdType ResultFromType;
    const ResultFromType result_from = obj->getProvisioningSessionId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_provisioning_session_id(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const char* p_provisioning_session_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename MediaStreamingAccessEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setProvisioningSessionId(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_provisioning_session_id_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, char* p_provisioning_session_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_provisioning_session_id;
    typedef typename MediaStreamingAccessEvent::ProvisioningSessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setProvisioningSessionId(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_event_get_session_id(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::SessionIdType ResultFromType;
    const ResultFromType result_from = obj->getSessionId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_session_id(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const char* p_session_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename MediaStreamingAccessEvent::SessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSessionId(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_session_id_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, char* p_session_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename MediaStreamingAccessEvent::SessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSessionId(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_event_get_ue_identification(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::UeIdentificationType ResultFromType;
    const ResultFromType result_from = obj->getUeIdentification();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_ue_identification(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const char* p_ue_identification)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename MediaStreamingAccessEvent::UeIdentificationType ValueType;

    ValueType value(value_from);
    if (!obj->setUeIdentification(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_ue_identification_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, char* p_ue_identification)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_identification;
    typedef typename MediaStreamingAccessEvent::UeIdentificationType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUeIdentification(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_event_get_data_network_name(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::DataNetworkNameType ResultFromType;
    const ResultFromType result_from = obj->getDataNetworkName();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_data_network_name(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const char* p_data_network_name)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename MediaStreamingAccessEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);
    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_data_network_name_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, char* p_data_network_name)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename MediaStreamingAccessEvent::DataNetworkNameType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_media_streaming_access_event_get_slice_id(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::SliceIdType ResultFromType;
    const ResultFromType result_from = obj->getSliceId();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_slice_id(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename MediaStreamingAccessEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSliceId(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_slice_id_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_snssai_t* p_slice_id)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_slice_id;
    typedef typename MediaStreamingAccessEvent::SliceIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSliceId(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_media_streaming_access_event_get_ue_locations(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::UeLocationsType ResultFromType;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_ue_locations(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const ogs_list_t* p_ue_locations)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename MediaStreamingAccessEvent::UeLocationsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setUeLocations(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_ue_locations_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, ogs_list_t* p_ue_locations)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_ue_locations;
    typedef typename MediaStreamingAccessEvent::UeLocationsType ValueType;

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

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_add_ue_locations(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessEvent::UeLocationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_locations;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addUeLocations(value);
    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_remove_ue_locations(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_location_area5_g_t* p_ue_locations)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessEvent::UeLocationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_locations;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeUeLocations(value);
    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_clear_ue_locations(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    obj->clearUeLocations();
    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_event_get_media_stream_handler_endpoint_address(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::MediaStreamHandlerEndpointAddressType ResultFromType;
    const ResultFromType result_from = obj->getMediaStreamHandlerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_media_stream_handler_endpoint_address(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccessEvent::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMediaStreamHandlerEndpointAddress(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_media_stream_handler_endpoint_address_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccessEvent::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMediaStreamHandlerEndpointAddress(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_event_get_application_server_endpoint_address(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::ApplicationServerEndpointAddressType ResultFromType;
    const ResultFromType result_from = obj->getApplicationServerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_application_server_endpoint_address(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccessEvent::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setApplicationServerEndpointAddress(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_application_server_endpoint_address_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccessEvent::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setApplicationServerEndpointAddress(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_request_message_t* data_collection_model_media_streaming_access_event_get_request_message(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_media_streaming_access_request_message_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_media_streaming_access_request_message_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::RequestMessageType ResultFromType;
    const ResultFromType result_from = obj->getRequestMessage();
    const data_collection_model_media_streaming_access_request_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_request_message_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_request_message(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccessEvent::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRequestMessage(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_request_message_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccessEvent::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRequestMessage(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cache_status_t* data_collection_model_media_streaming_access_event_get_cache_status(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_cache_status_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_cache_status_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::CacheStatusType ResultFromType;
    const ResultFromType result_from = obj->getCacheStatus();
    const data_collection_model_cache_status_t *result = reinterpret_cast<const data_collection_model_cache_status_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_cache_status(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_cache_status_t* p_cache_status)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccessEvent::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setCacheStatus(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_cache_status_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_cache_status_t* p_cache_status)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccessEvent::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setCacheStatus(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_response_message_t* data_collection_model_media_streaming_access_event_get_response_message(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_media_streaming_access_response_message_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_media_streaming_access_response_message_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::ResponseMessageType ResultFromType;
    const ResultFromType result_from = obj->getResponseMessage();
    const data_collection_model_media_streaming_access_response_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_response_message_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_response_message(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccessEvent::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setResponseMessage(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_response_message_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccessEvent::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setResponseMessage(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_event_get_processing_latency(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::ProcessingLatencyType ResultFromType;
    const ResultFromType result_from = obj->getProcessingLatency();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_processing_latency(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const float p_processing_latency)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccessEvent::ProcessingLatencyType ValueType;

    ValueType value = value_from;
    if (!obj->setProcessingLatency(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_processing_latency_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, float p_processing_latency)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccessEvent::ProcessingLatencyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setProcessingLatency(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_connection_metrics_t* data_collection_model_media_streaming_access_event_get_connection_metrics(const data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) {
        const data_collection_model_media_streaming_access_connection_metrics_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) {
        const data_collection_model_media_streaming_access_connection_metrics_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessEvent::ConnectionMetricsType ResultFromType;
    const ResultFromType result_from = obj->getConnectionMetrics();
    const data_collection_model_media_streaming_access_connection_metrics_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_connection_metrics_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_connection_metrics(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, const data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccessEvent::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setConnectionMetrics(value)) return NULL;

    return obj_media_streaming_access_event;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_event_t *data_collection_model_media_streaming_access_event_set_connection_metrics_move(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event, data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (!obj_media_streaming_access_event) return NULL;

    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    if (!obj) return NULL;

    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccessEvent::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setConnectionMetrics(std::move(value))) return NULL;

    return obj_media_streaming_access_event;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_event_make_lnode(data_collection_model_media_streaming_access_event_t *p_media_streaming_access_event)
{
    return data_collection_lnode_create(p_media_streaming_access_event, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_event_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_event_refcount(data_collection_model_media_streaming_access_event_t *obj_media_streaming_access_event)
{
    if (!obj_media_streaming_access_event) return 0l;
    std::shared_ptr<MediaStreamingAccessEvent > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessEvent >*>(obj_media_streaming_access_event);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

