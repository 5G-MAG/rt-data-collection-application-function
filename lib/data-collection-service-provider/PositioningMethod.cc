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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "PositioningMethod.h" already included by data-collection-sp/data-collection.h */
#include "PositioningMethod-internal.h"
#include "openapi/model/PositioningMethod.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_t *data_collection_model_positioning_method_create()
{
    return reinterpret_cast<data_collection_model_positioning_method_t*>(new std::shared_ptr<PositioningMethod>(new PositioningMethod()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_t *data_collection_model_positioning_method_create_copy(const data_collection_model_positioning_method_t *other)
{
    return reinterpret_cast<data_collection_model_positioning_method_t*>(new std::shared_ptr<PositioningMethod >(new PositioningMethod(**reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_t *data_collection_model_positioning_method_create_move(data_collection_model_positioning_method_t *other)
{
    return reinterpret_cast<data_collection_model_positioning_method_t*>(new std::shared_ptr<PositioningMethod >(std::move(*reinterpret_cast<std::shared_ptr<PositioningMethod >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_t *data_collection_model_positioning_method_copy(data_collection_model_positioning_method_t *positioning_method, const data_collection_model_positioning_method_t *other)
{
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(positioning_method);
    *obj = **reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(other);
    return positioning_method;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_t *data_collection_model_positioning_method_move(data_collection_model_positioning_method_t *positioning_method, data_collection_model_positioning_method_t *other)
{
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(positioning_method);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PositioningMethod >*>(other));
    return positioning_method;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_positioning_method_free(data_collection_model_positioning_method_t *positioning_method)
{
    delete reinterpret_cast<std::shared_ptr<PositioningMethod >*>(positioning_method);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_positioning_method_toJSON(const data_collection_model_positioning_method_t *positioning_method, bool as_request)
{
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(positioning_method);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_method_t *data_collection_model_positioning_method_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_positioning_method_is_equal_to(const data_collection_model_positioning_method_t *first, const data_collection_model_positioning_method_t *second)
{
    const std::shared_ptr<PositioningMethod > &obj1 = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(first);
    const std::shared_ptr<PositioningMethod > &obj2 = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_is_not_set(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    return obj->getValue() == PositioningMethod::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_is_non_standard(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    return obj->getValue() == PositioningMethod::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_e data_collection_model_positioning_method_get_enum(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
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
    default:
        break;
    }
    return DCM_POSITIONING_METHOD_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_method_get_string(const data_collection_model_positioning_method_t *obj_positioning_method)
{
    const std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_set_enum(data_collection_model_positioning_method_t *obj_positioning_method, data_collection_model_positioning_method_e p_value)
{
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
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
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_set_string(data_collection_model_positioning_method_t *obj_positioning_method, const char *p_value)
{
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PositioningMethod::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_positioning_method_make_lnode(data_collection_model_positioning_method_t *p_positioning_method)
{
    return data_collection_lnode_create(p_positioning_method, reinterpret_cast<void(*)(void*)>(data_collection_model_positioning_method_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_positioning_method_refcount(data_collection_model_positioning_method_t *obj_positioning_method)
{
    std::shared_ptr<PositioningMethod > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethod >*>(obj_positioning_method);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

