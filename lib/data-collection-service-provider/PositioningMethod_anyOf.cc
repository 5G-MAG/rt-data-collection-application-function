/**********************************************************************************************************************************
 * PositioningMethod_anyOf - C interface to the PositioningMethod_anyOf object
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

/*#include "PositioningMethod_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "PositioningMethod_anyOf-internal.h"
#include "openapi/model/PositioningMethod_anyOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create()
{
    return reinterpret_cast<data_collection_model_positioning_method_any_of_t*>(new std::shared_ptr<PositioningMethod_anyOf>(new PositioningMethod_anyOf()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create_copy(const data_collection_model_positioning_method_any_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_positioning_method_any_of_t*>(new std::shared_ptr<PositioningMethod_anyOf >(new PositioningMethod_anyOf(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create_move(data_collection_model_positioning_method_any_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PositioningMethod_anyOf > *obj = reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_copy(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, const data_collection_model_positioning_method_any_of_t *other)
{
    if (positioning_method_any_of) {
        std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(positioning_method_any_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<PositioningMethod_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(other);
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
                const std::shared_ptr<PositioningMethod_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(other);
                if (other_obj) {
                    obj.reset(new PositioningMethod_anyOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        positioning_method_any_of = data_collection_model_positioning_method_any_of_create_copy(other);
    }
    return positioning_method_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_move(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, data_collection_model_positioning_method_any_of_t *other)
{
    std::shared_ptr<PositioningMethod_anyOf > *other_ptr = reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(other);

    if (positioning_method_any_of) {
        std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(positioning_method_any_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                positioning_method_any_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return positioning_method_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_positioning_method_any_of_free(data_collection_model_positioning_method_any_of_t *positioning_method_any_of)
{
    if (!positioning_method_any_of) return;
    delete reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(positioning_method_any_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_positioning_method_any_of_toJSON(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of, bool as_request)
{
    if (!positioning_method_any_of) return NULL;
    const std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(positioning_method_any_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_positioning_method_any_of_t*>(new std::shared_ptr<PositioningMethod_anyOf >(new PositioningMethod_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_positioning_method_any_of_is_equal_to(const data_collection_model_positioning_method_any_of_t *first, const data_collection_model_positioning_method_any_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PositioningMethod_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PositioningMethod_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_is_not_set(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of)
{
    if (!positioning_method_any_of) return true;
    const std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(positioning_method_any_of);
    if (!obj) return true;
    return obj->getValue() == PositioningMethod_anyOf::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_e data_collection_model_positioning_method_any_of_get_enum(const data_collection_model_positioning_method_any_of_t *obj_positioning_method_any_of)
{
    if (!obj_positioning_method_any_of)
        return DCM_POSITIONING_METHOD_ANY_OF_NO_VAL;
    const std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(obj_positioning_method_any_of);
    if (!obj) return DCM_POSITIONING_METHOD_ANY_OF_NO_VAL;
    switch (obj->getValue()) {
    case PositioningMethod_anyOf::Enum::NO_VAL:
        return DCM_POSITIONING_METHOD_ANY_OF_NO_VAL;
    case PositioningMethod_anyOf::Enum::VAL_CELLID:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_CELLID;
    case PositioningMethod_anyOf::Enum::VAL_ECID:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_ECID;
    case PositioningMethod_anyOf::Enum::VAL_OTDOA:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_OTDOA;
    case PositioningMethod_anyOf::Enum::VAL_BAROMETRIC_PRESSURE:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_BAROMETRIC_PRESSURE;
    case PositioningMethod_anyOf::Enum::VAL_WLAN:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_WLAN;
    case PositioningMethod_anyOf::Enum::VAL_BLUETOOTH:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_BLUETOOTH;
    case PositioningMethod_anyOf::Enum::VAL_MBS:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_MBS;
    case PositioningMethod_anyOf::Enum::VAL_MOTION_SENSOR:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_MOTION_SENSOR;
    case PositioningMethod_anyOf::Enum::VAL_DL_TDOA:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_TDOA;
    case PositioningMethod_anyOf::Enum::VAL_DL_AOD:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_AOD;
    case PositioningMethod_anyOf::Enum::VAL_MULTI_RTT:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_MULTI_RTT;
    case PositioningMethod_anyOf::Enum::VAL_NR_ECID:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_NR_ECID;
    case PositioningMethod_anyOf::Enum::VAL_UL_TDOA:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_TDOA;
    case PositioningMethod_anyOf::Enum::VAL_UL_AOA:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_AOA;
    case PositioningMethod_anyOf::Enum::VAL_NETWORK_SPECIFIC:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_NETWORK_SPECIFIC;
    case PositioningMethod_anyOf::Enum::VAL_SL_TDOA:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TDOA;
    case PositioningMethod_anyOf::Enum::VAL_SL_TOA:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TOA;
    case PositioningMethod_anyOf::Enum::VAL_SL_AO_A:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_AO_A;
    case PositioningMethod_anyOf::Enum::VAL_SL_RT:
        return DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_RT;
    default:
        break;
    }
    return (data_collection_model_positioning_method_any_of_e)-1;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_method_any_of_get_string(const data_collection_model_positioning_method_any_of_t *obj_positioning_method_any_of)
{
    if (!obj_positioning_method_any_of) return NULL;
    const std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod_anyOf >*>(obj_positioning_method_any_of);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_set_enum(data_collection_model_positioning_method_any_of_t *obj_positioning_method_any_of, data_collection_model_positioning_method_any_of_e p_value)
{
    if (!obj_positioning_method_any_of) return false;
    std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(obj_positioning_method_any_of);
    if (!obj) return false;
    switch (p_value) {
    case DCM_POSITIONING_METHOD_ANY_OF_NO_VAL:
        *obj = PositioningMethod_anyOf::Enum::NO_VAL;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_CELLID:
        *obj = PositioningMethod_anyOf::Enum::VAL_CELLID;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_ECID:
        *obj = PositioningMethod_anyOf::Enum::VAL_ECID;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_OTDOA:
        *obj = PositioningMethod_anyOf::Enum::VAL_OTDOA;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_BAROMETRIC_PRESSURE:
        *obj = PositioningMethod_anyOf::Enum::VAL_BAROMETRIC_PRESSURE;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_WLAN:
        *obj = PositioningMethod_anyOf::Enum::VAL_WLAN;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_BLUETOOTH:
        *obj = PositioningMethod_anyOf::Enum::VAL_BLUETOOTH;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_MBS:
        *obj = PositioningMethod_anyOf::Enum::VAL_MBS;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_MOTION_SENSOR:
        *obj = PositioningMethod_anyOf::Enum::VAL_MOTION_SENSOR;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_TDOA:
        *obj = PositioningMethod_anyOf::Enum::VAL_DL_TDOA;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_AOD:
        *obj = PositioningMethod_anyOf::Enum::VAL_DL_AOD;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_MULTI_RTT:
        *obj = PositioningMethod_anyOf::Enum::VAL_MULTI_RTT;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_NR_ECID:
        *obj = PositioningMethod_anyOf::Enum::VAL_NR_ECID;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_TDOA:
        *obj = PositioningMethod_anyOf::Enum::VAL_UL_TDOA;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_AOA:
        *obj = PositioningMethod_anyOf::Enum::VAL_UL_AOA;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_NETWORK_SPECIFIC:
        *obj = PositioningMethod_anyOf::Enum::VAL_NETWORK_SPECIFIC;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TDOA:
        *obj = PositioningMethod_anyOf::Enum::VAL_SL_TDOA;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TOA:
        *obj = PositioningMethod_anyOf::Enum::VAL_SL_TOA;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_AO_A:
        *obj = PositioningMethod_anyOf::Enum::VAL_SL_AO_A;
        return true;
    case DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_RT:
        *obj = PositioningMethod_anyOf::Enum::VAL_SL_RT;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_set_string(data_collection_model_positioning_method_any_of_t *obj_positioning_method_any_of, const char *p_value)
{
    if (!obj_positioning_method_any_of) return false;
    std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(obj_positioning_method_any_of);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PositioningMethod_anyOf::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_positioning_method_any_of_make_lnode(data_collection_model_positioning_method_any_of_t *p_positioning_method_any_of)
{
    return data_collection_lnode_create(p_positioning_method_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_positioning_method_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_positioning_method_any_of_refcount(data_collection_model_positioning_method_any_of_t *obj_positioning_method_any_of)
{
    if (!obj_positioning_method_any_of) return 0l;
    std::shared_ptr<PositioningMethod_anyOf > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod_anyOf >*>(obj_positioning_method_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

