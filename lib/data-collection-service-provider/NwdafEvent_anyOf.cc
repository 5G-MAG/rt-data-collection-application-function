/**********************************************************************************************************************************
 * NwdafEvent_anyOf - C interface to the NwdafEvent_anyOf object
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

/*#include "NwdafEvent_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "NwdafEvent_anyOf-internal.h"
#include "openapi/model/NwdafEvent_anyOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_any_of_t *data_collection_model_nwdaf_event_any_of_create()
{
    return reinterpret_cast<data_collection_model_nwdaf_event_any_of_t*>(new std::shared_ptr<NwdafEvent_anyOf>(new NwdafEvent_anyOf()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_any_of_t *data_collection_model_nwdaf_event_any_of_create_copy(const data_collection_model_nwdaf_event_any_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_nwdaf_event_any_of_t*>(new std::shared_ptr<NwdafEvent_anyOf >(new NwdafEvent_anyOf(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_any_of_t *data_collection_model_nwdaf_event_any_of_create_move(data_collection_model_nwdaf_event_any_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NwdafEvent_anyOf > *obj = reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_any_of_t *data_collection_model_nwdaf_event_any_of_copy(data_collection_model_nwdaf_event_any_of_t *nwdaf_event_any_of, const data_collection_model_nwdaf_event_any_of_t *other)
{
    if (nwdaf_event_any_of) {
        std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(nwdaf_event_any_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<NwdafEvent_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(other);
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
                const std::shared_ptr<NwdafEvent_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(other);
                if (other_obj) {
                    obj.reset(new NwdafEvent_anyOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        nwdaf_event_any_of = data_collection_model_nwdaf_event_any_of_create_copy(other);
    }
    return nwdaf_event_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_any_of_t *data_collection_model_nwdaf_event_any_of_move(data_collection_model_nwdaf_event_any_of_t *nwdaf_event_any_of, data_collection_model_nwdaf_event_any_of_t *other)
{
    std::shared_ptr<NwdafEvent_anyOf > *other_ptr = reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(other);

    if (nwdaf_event_any_of) {
        std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(nwdaf_event_any_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                nwdaf_event_any_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return nwdaf_event_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_nwdaf_event_any_of_free(data_collection_model_nwdaf_event_any_of_t *nwdaf_event_any_of)
{
    if (!nwdaf_event_any_of) return;
    delete reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(nwdaf_event_any_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_nwdaf_event_any_of_toJSON(const data_collection_model_nwdaf_event_any_of_t *nwdaf_event_any_of, bool as_request)
{
    if (!nwdaf_event_any_of) return NULL;
    const std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(nwdaf_event_any_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_nwdaf_event_any_of_t *data_collection_model_nwdaf_event_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_nwdaf_event_any_of_t*>(new std::shared_ptr<NwdafEvent_anyOf >(new NwdafEvent_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_nwdaf_event_any_of_is_equal_to(const data_collection_model_nwdaf_event_any_of_t *first, const data_collection_model_nwdaf_event_any_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NwdafEvent_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NwdafEvent_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_any_of_is_not_set(const data_collection_model_nwdaf_event_any_of_t *nwdaf_event_any_of)
{
    if (!nwdaf_event_any_of) return true;
    const std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(nwdaf_event_any_of);
    if (!obj) return true;
    return obj->getValue() == NwdafEvent_anyOf::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_any_of_e data_collection_model_nwdaf_event_any_of_get_enum(const data_collection_model_nwdaf_event_any_of_t *obj_nwdaf_event_any_of)
{
    if (!obj_nwdaf_event_any_of)
        return DCM_NWDAF_EVENT_ANY_OF_NO_VAL;
    const std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(obj_nwdaf_event_any_of);
    if (!obj) return DCM_NWDAF_EVENT_ANY_OF_NO_VAL;
    switch (obj->getValue()) {
    case NwdafEvent_anyOf::Enum::NO_VAL:
        return DCM_NWDAF_EVENT_ANY_OF_NO_VAL;
    case NwdafEvent_anyOf::Enum::VAL_SLICE_LOAD_LEVEL:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_SLICE_LOAD_LEVEL;
    case NwdafEvent_anyOf::Enum::VAL_NETWORK_PERFORMANCE:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_NETWORK_PERFORMANCE;
    case NwdafEvent_anyOf::Enum::VAL_NF_LOAD:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_NF_LOAD;
    case NwdafEvent_anyOf::Enum::VAL_SERVICE_EXPERIENCE:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_SERVICE_EXPERIENCE;
    case NwdafEvent_anyOf::Enum::VAL_UE_MOBILITY:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_UE_MOBILITY;
    case NwdafEvent_anyOf::Enum::VAL_UE_COMMUNICATION:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_UE_COMMUNICATION;
    case NwdafEvent_anyOf::Enum::VAL_QOS_SUSTAINABILITY:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_QOS_SUSTAINABILITY;
    case NwdafEvent_anyOf::Enum::VAL_ABNORMAL_BEHAVIOUR:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_ABNORMAL_BEHAVIOUR;
    case NwdafEvent_anyOf::Enum::VAL_USER_DATA_CONGESTION:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_USER_DATA_CONGESTION;
    case NwdafEvent_anyOf::Enum::VAL_NSI_LOAD_LEVEL:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_NSI_LOAD_LEVEL;
    case NwdafEvent_anyOf::Enum::VAL_DN_PERFORMANCE:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_DN_PERFORMANCE;
    case NwdafEvent_anyOf::Enum::VAL_DISPERSION:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_DISPERSION;
    case NwdafEvent_anyOf::Enum::VAL_RED_TRANS_EXP:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_RED_TRANS_EXP;
    case NwdafEvent_anyOf::Enum::VAL_WLAN_PERFORMANCE:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_WLAN_PERFORMANCE;
    case NwdafEvent_anyOf::Enum::VAL_SM_CONGESTION:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_SM_CONGESTION;
    case NwdafEvent_anyOf::Enum::VAL_PFD_DETERMINATION:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_PFD_DETERMINATION;
    case NwdafEvent_anyOf::Enum::VAL_PDU_SESSION_TRAFFIC:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_PDU_SESSION_TRAFFIC;
    case NwdafEvent_anyOf::Enum::VAL_E2_E_DATA_VOL_TRANS_TIME:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_E2_E_DATA_VOL_TRANS_TIME;
    case NwdafEvent_anyOf::Enum::VAL_MOVEMENT_BEHAVIOUR:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_MOVEMENT_BEHAVIOUR;
    case NwdafEvent_anyOf::Enum::VAL_NUM_OF_UE:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_NUM_OF_UE;
    case NwdafEvent_anyOf::Enum::VAL_MOV_UE_RATIO:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_MOV_UE_RATIO;
    case NwdafEvent_anyOf::Enum::VAL_AVR_SPEED:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_AVR_SPEED;
    case NwdafEvent_anyOf::Enum::VAL_SPEED_THRESHOLD:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_SPEED_THRESHOLD;
    case NwdafEvent_anyOf::Enum::VAL_MOV_UE_DIRECTION:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_MOV_UE_DIRECTION;
    case NwdafEvent_anyOf::Enum::VAL_LOC_ACCURACY:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_LOC_ACCURACY;
    case NwdafEvent_anyOf::Enum::VAL_RELATIVE_PROXIMITY:
        return DCM_NWDAF_EVENT_ANY_OF_VAL_RELATIVE_PROXIMITY;
    default:
        break;
    }
    return (data_collection_model_nwdaf_event_any_of_e)-1;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_nwdaf_event_any_of_get_string(const data_collection_model_nwdaf_event_any_of_t *obj_nwdaf_event_any_of)
{
    if (!obj_nwdaf_event_any_of) return NULL;
    const std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NwdafEvent_anyOf >*>(obj_nwdaf_event_any_of);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_any_of_set_enum(data_collection_model_nwdaf_event_any_of_t *obj_nwdaf_event_any_of, data_collection_model_nwdaf_event_any_of_e p_value)
{
    if (!obj_nwdaf_event_any_of) return false;
    std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(obj_nwdaf_event_any_of);
    if (!obj) return false;
    switch (p_value) {
    case DCM_NWDAF_EVENT_ANY_OF_NO_VAL:
        *obj = NwdafEvent_anyOf::Enum::NO_VAL;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_SLICE_LOAD_LEVEL:
        *obj = NwdafEvent_anyOf::Enum::VAL_SLICE_LOAD_LEVEL;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_NETWORK_PERFORMANCE:
        *obj = NwdafEvent_anyOf::Enum::VAL_NETWORK_PERFORMANCE;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_NF_LOAD:
        *obj = NwdafEvent_anyOf::Enum::VAL_NF_LOAD;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_SERVICE_EXPERIENCE:
        *obj = NwdafEvent_anyOf::Enum::VAL_SERVICE_EXPERIENCE;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_UE_MOBILITY:
        *obj = NwdafEvent_anyOf::Enum::VAL_UE_MOBILITY;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_UE_COMMUNICATION:
        *obj = NwdafEvent_anyOf::Enum::VAL_UE_COMMUNICATION;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_QOS_SUSTAINABILITY:
        *obj = NwdafEvent_anyOf::Enum::VAL_QOS_SUSTAINABILITY;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_ABNORMAL_BEHAVIOUR:
        *obj = NwdafEvent_anyOf::Enum::VAL_ABNORMAL_BEHAVIOUR;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_USER_DATA_CONGESTION:
        *obj = NwdafEvent_anyOf::Enum::VAL_USER_DATA_CONGESTION;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_NSI_LOAD_LEVEL:
        *obj = NwdafEvent_anyOf::Enum::VAL_NSI_LOAD_LEVEL;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_DN_PERFORMANCE:
        *obj = NwdafEvent_anyOf::Enum::VAL_DN_PERFORMANCE;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_DISPERSION:
        *obj = NwdafEvent_anyOf::Enum::VAL_DISPERSION;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_RED_TRANS_EXP:
        *obj = NwdafEvent_anyOf::Enum::VAL_RED_TRANS_EXP;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_WLAN_PERFORMANCE:
        *obj = NwdafEvent_anyOf::Enum::VAL_WLAN_PERFORMANCE;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_SM_CONGESTION:
        *obj = NwdafEvent_anyOf::Enum::VAL_SM_CONGESTION;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_PFD_DETERMINATION:
        *obj = NwdafEvent_anyOf::Enum::VAL_PFD_DETERMINATION;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_PDU_SESSION_TRAFFIC:
        *obj = NwdafEvent_anyOf::Enum::VAL_PDU_SESSION_TRAFFIC;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_E2_E_DATA_VOL_TRANS_TIME:
        *obj = NwdafEvent_anyOf::Enum::VAL_E2_E_DATA_VOL_TRANS_TIME;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_MOVEMENT_BEHAVIOUR:
        *obj = NwdafEvent_anyOf::Enum::VAL_MOVEMENT_BEHAVIOUR;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_NUM_OF_UE:
        *obj = NwdafEvent_anyOf::Enum::VAL_NUM_OF_UE;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_MOV_UE_RATIO:
        *obj = NwdafEvent_anyOf::Enum::VAL_MOV_UE_RATIO;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_AVR_SPEED:
        *obj = NwdafEvent_anyOf::Enum::VAL_AVR_SPEED;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_SPEED_THRESHOLD:
        *obj = NwdafEvent_anyOf::Enum::VAL_SPEED_THRESHOLD;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_MOV_UE_DIRECTION:
        *obj = NwdafEvent_anyOf::Enum::VAL_MOV_UE_DIRECTION;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_LOC_ACCURACY:
        *obj = NwdafEvent_anyOf::Enum::VAL_LOC_ACCURACY;
        return true;
    case DCM_NWDAF_EVENT_ANY_OF_VAL_RELATIVE_PROXIMITY:
        *obj = NwdafEvent_anyOf::Enum::VAL_RELATIVE_PROXIMITY;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_any_of_set_string(data_collection_model_nwdaf_event_any_of_t *obj_nwdaf_event_any_of, const char *p_value)
{
    if (!obj_nwdaf_event_any_of) return false;
    std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(obj_nwdaf_event_any_of);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NwdafEvent_anyOf::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_nwdaf_event_any_of_make_lnode(data_collection_model_nwdaf_event_any_of_t *p_nwdaf_event_any_of)
{
    return data_collection_lnode_create(p_nwdaf_event_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_nwdaf_event_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_nwdaf_event_any_of_refcount(data_collection_model_nwdaf_event_any_of_t *obj_nwdaf_event_any_of)
{
    if (!obj_nwdaf_event_any_of) return 0l;
    std::shared_ptr<NwdafEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NwdafEvent_anyOf >*>(obj_nwdaf_event_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

