/**********************************************************************************************************************************
 * NwdafEvent - C interface to the NwdafEvent object
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

/*#include "NwdafEvent.h" already included by data-collection-sp/data-collection.h */
#include "NwdafEvent-internal.h"
#include "openapi/model/NwdafEvent.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_create()
{
    return reinterpret_cast<data_collection_model_nwdaf_event_t*>(new std::shared_ptr<NwdafEvent>(new NwdafEvent()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_create_copy(const data_collection_model_nwdaf_event_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_nwdaf_event_t*>(new std::shared_ptr<NwdafEvent >(new NwdafEvent(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_create_move(data_collection_model_nwdaf_event_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NwdafEvent > *obj = reinterpret_cast<std::shared_ptr<NwdafEvent >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_copy(data_collection_model_nwdaf_event_t *nwdaf_event, const data_collection_model_nwdaf_event_t *other)
{
    if (nwdaf_event) {
        std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent >*>(nwdaf_event);
        if (obj) {
            if (other) {
                const std::shared_ptr<NwdafEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(other);
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
                const std::shared_ptr<NwdafEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(other);
                if (other_obj) {
                    obj.reset(new NwdafEvent(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        nwdaf_event = data_collection_model_nwdaf_event_create_copy(other);
    }
    return nwdaf_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_move(data_collection_model_nwdaf_event_t *nwdaf_event, data_collection_model_nwdaf_event_t *other)
{
    std::shared_ptr<NwdafEvent > *other_ptr = reinterpret_cast<std::shared_ptr<NwdafEvent >*>(other);

    if (nwdaf_event) {
        std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent >*>(nwdaf_event);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                nwdaf_event = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return nwdaf_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_nwdaf_event_free(data_collection_model_nwdaf_event_t *nwdaf_event)
{
    if (!nwdaf_event) return;
    delete reinterpret_cast<std::shared_ptr<NwdafEvent >*>(nwdaf_event);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_nwdaf_event_toJSON(const data_collection_model_nwdaf_event_t *nwdaf_event, bool as_request)
{
    if (!nwdaf_event) return NULL;
    const std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(nwdaf_event);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_nwdaf_event_t*>(new std::shared_ptr<NwdafEvent >(new NwdafEvent(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_nwdaf_event_is_equal_to(const data_collection_model_nwdaf_event_t *first, const data_collection_model_nwdaf_event_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NwdafEvent > &obj2 = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NwdafEvent > &obj1 = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_is_not_set(const data_collection_model_nwdaf_event_t *obj_nwdaf_event)
{
    if (!obj_nwdaf_event) return true;
    const std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(obj_nwdaf_event);
    if (!obj) return true;
    return obj->getValue() == NwdafEvent::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_is_non_standard(const data_collection_model_nwdaf_event_t *obj_nwdaf_event)
{
    if (!obj_nwdaf_event) return false;
    const std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(obj_nwdaf_event);
    if (!obj) return false;
    return obj->getValue() == NwdafEvent::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_e data_collection_model_nwdaf_event_get_enum(const data_collection_model_nwdaf_event_t *obj_nwdaf_event)
{
    if (!obj_nwdaf_event)
        return DCM_NWDAF_EVENT_NO_VAL;
    const std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(obj_nwdaf_event);
    if (!obj) return DCM_NWDAF_EVENT_NO_VAL;
    switch (obj->getValue()) {
    case NwdafEvent::Enum::NO_VAL:
        return DCM_NWDAF_EVENT_NO_VAL;
    case NwdafEvent::Enum::VAL_SLICE_LOAD_LEVEL:
        return DCM_NWDAF_EVENT_VAL_SLICE_LOAD_LEVEL;
    case NwdafEvent::Enum::VAL_NETWORK_PERFORMANCE:
        return DCM_NWDAF_EVENT_VAL_NETWORK_PERFORMANCE;
    case NwdafEvent::Enum::VAL_NF_LOAD:
        return DCM_NWDAF_EVENT_VAL_NF_LOAD;
    case NwdafEvent::Enum::VAL_SERVICE_EXPERIENCE:
        return DCM_NWDAF_EVENT_VAL_SERVICE_EXPERIENCE;
    case NwdafEvent::Enum::VAL_UE_MOBILITY:
        return DCM_NWDAF_EVENT_VAL_UE_MOBILITY;
    case NwdafEvent::Enum::VAL_UE_COMMUNICATION:
        return DCM_NWDAF_EVENT_VAL_UE_COMMUNICATION;
    case NwdafEvent::Enum::VAL_QOS_SUSTAINABILITY:
        return DCM_NWDAF_EVENT_VAL_QOS_SUSTAINABILITY;
    case NwdafEvent::Enum::VAL_ABNORMAL_BEHAVIOUR:
        return DCM_NWDAF_EVENT_VAL_ABNORMAL_BEHAVIOUR;
    case NwdafEvent::Enum::VAL_USER_DATA_CONGESTION:
        return DCM_NWDAF_EVENT_VAL_USER_DATA_CONGESTION;
    case NwdafEvent::Enum::VAL_NSI_LOAD_LEVEL:
        return DCM_NWDAF_EVENT_VAL_NSI_LOAD_LEVEL;
    case NwdafEvent::Enum::VAL_DN_PERFORMANCE:
        return DCM_NWDAF_EVENT_VAL_DN_PERFORMANCE;
    case NwdafEvent::Enum::VAL_DISPERSION:
        return DCM_NWDAF_EVENT_VAL_DISPERSION;
    case NwdafEvent::Enum::VAL_RED_TRANS_EXP:
        return DCM_NWDAF_EVENT_VAL_RED_TRANS_EXP;
    case NwdafEvent::Enum::VAL_WLAN_PERFORMANCE:
        return DCM_NWDAF_EVENT_VAL_WLAN_PERFORMANCE;
    case NwdafEvent::Enum::VAL_SM_CONGESTION:
        return DCM_NWDAF_EVENT_VAL_SM_CONGESTION;
    case NwdafEvent::Enum::VAL_PFD_DETERMINATION:
        return DCM_NWDAF_EVENT_VAL_PFD_DETERMINATION;
    case NwdafEvent::Enum::VAL_PDU_SESSION_TRAFFIC:
        return DCM_NWDAF_EVENT_VAL_PDU_SESSION_TRAFFIC;
    case NwdafEvent::Enum::VAL_E2_E_DATA_VOL_TRANS_TIME:
        return DCM_NWDAF_EVENT_VAL_E2_E_DATA_VOL_TRANS_TIME;
    case NwdafEvent::Enum::VAL_MOVEMENT_BEHAVIOUR:
        return DCM_NWDAF_EVENT_VAL_MOVEMENT_BEHAVIOUR;
    case NwdafEvent::Enum::VAL_NUM_OF_UE:
        return DCM_NWDAF_EVENT_VAL_NUM_OF_UE;
    case NwdafEvent::Enum::VAL_MOV_UE_RATIO:
        return DCM_NWDAF_EVENT_VAL_MOV_UE_RATIO;
    case NwdafEvent::Enum::VAL_AVR_SPEED:
        return DCM_NWDAF_EVENT_VAL_AVR_SPEED;
    case NwdafEvent::Enum::VAL_SPEED_THRESHOLD:
        return DCM_NWDAF_EVENT_VAL_SPEED_THRESHOLD;
    case NwdafEvent::Enum::VAL_MOV_UE_DIRECTION:
        return DCM_NWDAF_EVENT_VAL_MOV_UE_DIRECTION;
    case NwdafEvent::Enum::VAL_LOC_ACCURACY:
        return DCM_NWDAF_EVENT_VAL_LOC_ACCURACY;
    case NwdafEvent::Enum::VAL_RELATIVE_PROXIMITY:
        return DCM_NWDAF_EVENT_VAL_RELATIVE_PROXIMITY;
    default:
        break;
    }
    return DCM_NWDAF_EVENT_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_nwdaf_event_get_string(const data_collection_model_nwdaf_event_t *obj_nwdaf_event)
{
    if (!obj_nwdaf_event) return NULL;
    const std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent >*>(obj_nwdaf_event);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_set_enum(data_collection_model_nwdaf_event_t *obj_nwdaf_event, data_collection_model_nwdaf_event_e p_value)
{
    if (!obj_nwdaf_event) return false;
    std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent >*>(obj_nwdaf_event);
    if (!obj) return false;
    switch (p_value) {
    case DCM_NWDAF_EVENT_NO_VAL:
        *obj = NwdafEvent::Enum::NO_VAL;
        return true;
    case DCM_NWDAF_EVENT_VAL_SLICE_LOAD_LEVEL:
        *obj = NwdafEvent::Enum::VAL_SLICE_LOAD_LEVEL;
        return true;
    case DCM_NWDAF_EVENT_VAL_NETWORK_PERFORMANCE:
        *obj = NwdafEvent::Enum::VAL_NETWORK_PERFORMANCE;
        return true;
    case DCM_NWDAF_EVENT_VAL_NF_LOAD:
        *obj = NwdafEvent::Enum::VAL_NF_LOAD;
        return true;
    case DCM_NWDAF_EVENT_VAL_SERVICE_EXPERIENCE:
        *obj = NwdafEvent::Enum::VAL_SERVICE_EXPERIENCE;
        return true;
    case DCM_NWDAF_EVENT_VAL_UE_MOBILITY:
        *obj = NwdafEvent::Enum::VAL_UE_MOBILITY;
        return true;
    case DCM_NWDAF_EVENT_VAL_UE_COMMUNICATION:
        *obj = NwdafEvent::Enum::VAL_UE_COMMUNICATION;
        return true;
    case DCM_NWDAF_EVENT_VAL_QOS_SUSTAINABILITY:
        *obj = NwdafEvent::Enum::VAL_QOS_SUSTAINABILITY;
        return true;
    case DCM_NWDAF_EVENT_VAL_ABNORMAL_BEHAVIOUR:
        *obj = NwdafEvent::Enum::VAL_ABNORMAL_BEHAVIOUR;
        return true;
    case DCM_NWDAF_EVENT_VAL_USER_DATA_CONGESTION:
        *obj = NwdafEvent::Enum::VAL_USER_DATA_CONGESTION;
        return true;
    case DCM_NWDAF_EVENT_VAL_NSI_LOAD_LEVEL:
        *obj = NwdafEvent::Enum::VAL_NSI_LOAD_LEVEL;
        return true;
    case DCM_NWDAF_EVENT_VAL_DN_PERFORMANCE:
        *obj = NwdafEvent::Enum::VAL_DN_PERFORMANCE;
        return true;
    case DCM_NWDAF_EVENT_VAL_DISPERSION:
        *obj = NwdafEvent::Enum::VAL_DISPERSION;
        return true;
    case DCM_NWDAF_EVENT_VAL_RED_TRANS_EXP:
        *obj = NwdafEvent::Enum::VAL_RED_TRANS_EXP;
        return true;
    case DCM_NWDAF_EVENT_VAL_WLAN_PERFORMANCE:
        *obj = NwdafEvent::Enum::VAL_WLAN_PERFORMANCE;
        return true;
    case DCM_NWDAF_EVENT_VAL_SM_CONGESTION:
        *obj = NwdafEvent::Enum::VAL_SM_CONGESTION;
        return true;
    case DCM_NWDAF_EVENT_VAL_PFD_DETERMINATION:
        *obj = NwdafEvent::Enum::VAL_PFD_DETERMINATION;
        return true;
    case DCM_NWDAF_EVENT_VAL_PDU_SESSION_TRAFFIC:
        *obj = NwdafEvent::Enum::VAL_PDU_SESSION_TRAFFIC;
        return true;
    case DCM_NWDAF_EVENT_VAL_E2_E_DATA_VOL_TRANS_TIME:
        *obj = NwdafEvent::Enum::VAL_E2_E_DATA_VOL_TRANS_TIME;
        return true;
    case DCM_NWDAF_EVENT_VAL_MOVEMENT_BEHAVIOUR:
        *obj = NwdafEvent::Enum::VAL_MOVEMENT_BEHAVIOUR;
        return true;
    case DCM_NWDAF_EVENT_VAL_NUM_OF_UE:
        *obj = NwdafEvent::Enum::VAL_NUM_OF_UE;
        return true;
    case DCM_NWDAF_EVENT_VAL_MOV_UE_RATIO:
        *obj = NwdafEvent::Enum::VAL_MOV_UE_RATIO;
        return true;
    case DCM_NWDAF_EVENT_VAL_AVR_SPEED:
        *obj = NwdafEvent::Enum::VAL_AVR_SPEED;
        return true;
    case DCM_NWDAF_EVENT_VAL_SPEED_THRESHOLD:
        *obj = NwdafEvent::Enum::VAL_SPEED_THRESHOLD;
        return true;
    case DCM_NWDAF_EVENT_VAL_MOV_UE_DIRECTION:
        *obj = NwdafEvent::Enum::VAL_MOV_UE_DIRECTION;
        return true;
    case DCM_NWDAF_EVENT_VAL_LOC_ACCURACY:
        *obj = NwdafEvent::Enum::VAL_LOC_ACCURACY;
        return true;
    case DCM_NWDAF_EVENT_VAL_RELATIVE_PROXIMITY:
        *obj = NwdafEvent::Enum::VAL_RELATIVE_PROXIMITY;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_set_string(data_collection_model_nwdaf_event_t *obj_nwdaf_event, const char *p_value)
{
    if (!obj_nwdaf_event) return false;
    std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent >*>(obj_nwdaf_event);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NwdafEvent::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_nwdaf_event_make_lnode(data_collection_model_nwdaf_event_t *p_nwdaf_event)
{
    return data_collection_lnode_create(p_nwdaf_event, reinterpret_cast<void(*)(void*)>(data_collection_model_nwdaf_event_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_nwdaf_event_refcount(data_collection_model_nwdaf_event_t *obj_nwdaf_event)
{
    if (!obj_nwdaf_event) return 0l;
    std::shared_ptr<NwdafEvent > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent >*>(obj_nwdaf_event);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

