/**********************************************************************************************************************************
 * PositioningMethod - C interface to the PositioningMethod object
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

/*#include "PositioningMethod.h" already included by data-collection-sp/data-collection.h */
#include "PositioningMethod-internal.h"
#include "openapi/model/PositioningMethod.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_t *data_collection_model_positioning_method_create()
{
    return reinterpret_cast<data_collection_model_positioning_method_t*>(new std::shared_ptr<PositioningMethod>(new PositioningMethod()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_t *data_collection_model_positioning_method_create_copy(const data_collection_model_positioning_method_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_positioning_method_t*>(new std::shared_ptr<PositioningMethod >(new PositioningMethod(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_t *data_collection_model_positioning_method_create_move(data_collection_model_positioning_method_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PositioningMethod > *obj = reinterpret_cast<std::shared_ptr<PositioningMethod >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_t *data_collection_model_positioning_method_copy(data_collection_model_positioning_method_t *positioning_method, const data_collection_model_positioning_method_t *other)
{
    if (positioning_method) {
        std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(positioning_method);
        if (obj) {
            if (other) {
                const std::shared_ptr<PositioningMethod > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(other);
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
                const std::shared_ptr<PositioningMethod > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(other);
                if (other_obj) {
                    obj.reset(new PositioningMethod(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        positioning_method = data_collection_model_positioning_method_create_copy(other);
    }
    return positioning_method;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_t *data_collection_model_positioning_method_move(data_collection_model_positioning_method_t *positioning_method, data_collection_model_positioning_method_t *other)
{
    std::shared_ptr<PositioningMethod > *other_ptr = reinterpret_cast<std::shared_ptr<PositioningMethod >*>(other);

    if (positioning_method) {
        std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(positioning_method);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                positioning_method = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return positioning_method;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_method_free(data_collection_model_positioning_method_t *positioning_method)
{
    if (!positioning_method) return;
    delete reinterpret_cast<std::shared_ptr<PositioningMethod >*>(positioning_method);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_method_toJSON(const data_collection_model_positioning_method_t *positioning_method, bool as_request)
{
    if (!positioning_method) return NULL;
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(positioning_method);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_positioning_method_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_t *data_collection_model_positioning_method_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_positioning_method_t*>(new std::shared_ptr<PositioningMethod >(new PositioningMethod(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_is_equal_to(const data_collection_model_positioning_method_t *first, const data_collection_model_positioning_method_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PositioningMethod > &obj2 = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PositioningMethod > &obj1 = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_is_not_set(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    if (!obj_positioning_method) return true;
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    if (!obj) return true;
    return obj->getValue() == PositioningMethod::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_is_non_standard(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    if (!obj_positioning_method) return false;
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    if (!obj) return false;
    return obj->getValue() == PositioningMethod::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_e data_collection_model_positioning_method_get_enum(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    if (!obj_positioning_method)
        return DCM_POSITIONING_METHOD_NO_VAL;
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    if (!obj) return DCM_POSITIONING_METHOD_NO_VAL;
    switch (obj->getValue()) {
    case PositioningMethod::Enum::NO_VAL:
        return DCM_POSITIONING_METHOD_NO_VAL;
    case PositioningMethod::Enum::VAL_CELLID:
        return DCM_POSITIONING_METHOD_VAL_CELLID;
    case PositioningMethod::Enum::VAL_ECID:
        return DCM_POSITIONING_METHOD_VAL_ECID;
    case PositioningMethod::Enum::VAL_OTDOA:
        return DCM_POSITIONING_METHOD_VAL_OTDOA;
    case PositioningMethod::Enum::VAL_BAROMETRIC_PRESSURE:
        return DCM_POSITIONING_METHOD_VAL_BAROMETRIC_PRESSURE;
    case PositioningMethod::Enum::VAL_WLAN:
        return DCM_POSITIONING_METHOD_VAL_WLAN;
    case PositioningMethod::Enum::VAL_BLUETOOTH:
        return DCM_POSITIONING_METHOD_VAL_BLUETOOTH;
    case PositioningMethod::Enum::VAL_MBS:
        return DCM_POSITIONING_METHOD_VAL_MBS;
    case PositioningMethod::Enum::VAL_MOTION_SENSOR:
        return DCM_POSITIONING_METHOD_VAL_MOTION_SENSOR;
    case PositioningMethod::Enum::VAL_DL_TDOA:
        return DCM_POSITIONING_METHOD_VAL_DL_TDOA;
    case PositioningMethod::Enum::VAL_DL_AOD:
        return DCM_POSITIONING_METHOD_VAL_DL_AOD;
    case PositioningMethod::Enum::VAL_MULTI_RTT:
        return DCM_POSITIONING_METHOD_VAL_MULTI_RTT;
    case PositioningMethod::Enum::VAL_NR_ECID:
        return DCM_POSITIONING_METHOD_VAL_NR_ECID;
    case PositioningMethod::Enum::VAL_UL_TDOA:
        return DCM_POSITIONING_METHOD_VAL_UL_TDOA;
    case PositioningMethod::Enum::VAL_UL_AOA:
        return DCM_POSITIONING_METHOD_VAL_UL_AOA;
    case PositioningMethod::Enum::VAL_NETWORK_SPECIFIC:
        return DCM_POSITIONING_METHOD_VAL_NETWORK_SPECIFIC;
    case PositioningMethod::Enum::VAL_SL_TDOA:
        return DCM_POSITIONING_METHOD_VAL_SL_TDOA;
    case PositioningMethod::Enum::VAL_SL_TOA:
        return DCM_POSITIONING_METHOD_VAL_SL_TOA;
    case PositioningMethod::Enum::VAL_SL_AO_A:
        return DCM_POSITIONING_METHOD_VAL_SL_AO_A;
    case PositioningMethod::Enum::VAL_SL_RT:
        return DCM_POSITIONING_METHOD_VAL_SL_RT;
    default:
        break;
    }
    return DCM_POSITIONING_METHOD_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_method_get_string(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    if (!obj_positioning_method) return NULL;
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_set_enum(data_collection_model_positioning_method_t *obj_positioning_method, data_collection_model_positioning_method_e p_value)
{
    if (!obj_positioning_method) return false;
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    if (!obj) return false;
    switch (p_value) {
    case DCM_POSITIONING_METHOD_NO_VAL:
        *obj = PositioningMethod::Enum::NO_VAL;
        return true;
    case DCM_POSITIONING_METHOD_VAL_CELLID:
        *obj = PositioningMethod::Enum::VAL_CELLID;
        return true;
    case DCM_POSITIONING_METHOD_VAL_ECID:
        *obj = PositioningMethod::Enum::VAL_ECID;
        return true;
    case DCM_POSITIONING_METHOD_VAL_OTDOA:
        *obj = PositioningMethod::Enum::VAL_OTDOA;
        return true;
    case DCM_POSITIONING_METHOD_VAL_BAROMETRIC_PRESSURE:
        *obj = PositioningMethod::Enum::VAL_BAROMETRIC_PRESSURE;
        return true;
    case DCM_POSITIONING_METHOD_VAL_WLAN:
        *obj = PositioningMethod::Enum::VAL_WLAN;
        return true;
    case DCM_POSITIONING_METHOD_VAL_BLUETOOTH:
        *obj = PositioningMethod::Enum::VAL_BLUETOOTH;
        return true;
    case DCM_POSITIONING_METHOD_VAL_MBS:
        *obj = PositioningMethod::Enum::VAL_MBS;
        return true;
    case DCM_POSITIONING_METHOD_VAL_MOTION_SENSOR:
        *obj = PositioningMethod::Enum::VAL_MOTION_SENSOR;
        return true;
    case DCM_POSITIONING_METHOD_VAL_DL_TDOA:
        *obj = PositioningMethod::Enum::VAL_DL_TDOA;
        return true;
    case DCM_POSITIONING_METHOD_VAL_DL_AOD:
        *obj = PositioningMethod::Enum::VAL_DL_AOD;
        return true;
    case DCM_POSITIONING_METHOD_VAL_MULTI_RTT:
        *obj = PositioningMethod::Enum::VAL_MULTI_RTT;
        return true;
    case DCM_POSITIONING_METHOD_VAL_NR_ECID:
        *obj = PositioningMethod::Enum::VAL_NR_ECID;
        return true;
    case DCM_POSITIONING_METHOD_VAL_UL_TDOA:
        *obj = PositioningMethod::Enum::VAL_UL_TDOA;
        return true;
    case DCM_POSITIONING_METHOD_VAL_UL_AOA:
        *obj = PositioningMethod::Enum::VAL_UL_AOA;
        return true;
    case DCM_POSITIONING_METHOD_VAL_NETWORK_SPECIFIC:
        *obj = PositioningMethod::Enum::VAL_NETWORK_SPECIFIC;
        return true;
    case DCM_POSITIONING_METHOD_VAL_SL_TDOA:
        *obj = PositioningMethod::Enum::VAL_SL_TDOA;
        return true;
    case DCM_POSITIONING_METHOD_VAL_SL_TOA:
        *obj = PositioningMethod::Enum::VAL_SL_TOA;
        return true;
    case DCM_POSITIONING_METHOD_VAL_SL_AO_A:
        *obj = PositioningMethod::Enum::VAL_SL_AO_A;
        return true;
    case DCM_POSITIONING_METHOD_VAL_SL_RT:
        *obj = PositioningMethod::Enum::VAL_SL_RT;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_set_string(data_collection_model_positioning_method_t *obj_positioning_method, const char *p_value)
{
    if (!obj_positioning_method) return false;
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PositioningMethod::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_method_make_lnode(data_collection_model_positioning_method_t *p_positioning_method)
{
    return data_collection_lnode_create(p_positioning_method, reinterpret_cast<void(*)(void*)>(data_collection_model_positioning_method_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_positioning_method_refcount(data_collection_model_positioning_method_t *obj_positioning_method)
{
    if (!obj_positioning_method) return 0l;
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

