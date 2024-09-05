/**********************************************************************************************************************************
 * BatteryIndication - C interface to the BatteryIndication object
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

/*#include "BatteryIndication.h" already included by data-collection-sp/data-collection.h */
#include "BatteryIndication-internal.h"
#include "openapi/model/BatteryIndication.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_battery_indication_t *data_collection_model_battery_indication_create()
{
    return reinterpret_cast<data_collection_model_battery_indication_t*>(new std::shared_ptr<BatteryIndication>(new BatteryIndication()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_battery_indication_t *data_collection_model_battery_indication_create_copy(const data_collection_model_battery_indication_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_battery_indication_t*>(new std::shared_ptr<BatteryIndication >(new BatteryIndication(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_battery_indication_t *data_collection_model_battery_indication_create_move(data_collection_model_battery_indication_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<BatteryIndication > *obj = reinterpret_cast<std::shared_ptr<BatteryIndication >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_battery_indication_t *data_collection_model_battery_indication_copy(data_collection_model_battery_indication_t *battery_indication, const data_collection_model_battery_indication_t *other)
{
    if (battery_indication) {
        std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<std::shared_ptr<BatteryIndication >*>(battery_indication);
        if (obj) {
            if (other) {
                const std::shared_ptr<BatteryIndication > &other_obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(other);
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
                const std::shared_ptr<BatteryIndication > &other_obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(other);
                if (other_obj) {
                    obj.reset(new BatteryIndication(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        battery_indication = data_collection_model_battery_indication_create_copy(other);
    }
    return battery_indication;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_battery_indication_t *data_collection_model_battery_indication_move(data_collection_model_battery_indication_t *battery_indication, data_collection_model_battery_indication_t *other)
{
    std::shared_ptr<BatteryIndication > *other_ptr = reinterpret_cast<std::shared_ptr<BatteryIndication >*>(other);

    if (battery_indication) {
        std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<std::shared_ptr<BatteryIndication >*>(battery_indication);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                battery_indication = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return battery_indication;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_battery_indication_free(data_collection_model_battery_indication_t *battery_indication)
{
    if (!battery_indication) return;
    delete reinterpret_cast<std::shared_ptr<BatteryIndication >*>(battery_indication);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_battery_indication_toJSON(const data_collection_model_battery_indication_t *battery_indication, bool as_request)
{
    if (!battery_indication) return NULL;
    const std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(battery_indication);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_battery_indication_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_battery_indication_t *data_collection_model_battery_indication_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_battery_indication_t*>(new std::shared_ptr<BatteryIndication >(new BatteryIndication(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_battery_indication_is_equal_to(const data_collection_model_battery_indication_t *first, const data_collection_model_battery_indication_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<BatteryIndication > &obj2 = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<BatteryIndication > &obj1 = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_battery_indication_is_not_set(const data_collection_model_battery_indication_t *obj_battery_indication)
{
    if (!obj_battery_indication) return true;
    const std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(obj_battery_indication);
    if (!obj) return true;
    return obj->getValue() == BatteryIndication::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_battery_indication_is_non_standard(const data_collection_model_battery_indication_t *obj_battery_indication)
{
    if (!obj_battery_indication) return false;
    const std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(obj_battery_indication);
    if (!obj) return false;
    return obj->getValue() == BatteryIndication::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_battery_indication_e data_collection_model_battery_indication_get_enum(const data_collection_model_battery_indication_t *obj_battery_indication)
{
    if (!obj_battery_indication)
        return DCM_BATTERY_INDICATION_NO_VAL;
    const std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(obj_battery_indication);
    if (!obj) return DCM_BATTERY_INDICATION_NO_VAL;
    switch (obj->getValue()) {
    case BatteryIndication::Enum::NO_VAL:
        return DCM_BATTERY_INDICATION_NO_VAL;
    case BatteryIndication::Enum::VAL_BATTERY_RECHARGE:
        return DCM_BATTERY_INDICATION_VAL_BATTERY_RECHARGE;
    case BatteryIndication::Enum::VAL_BATTERY_REPLACE:
        return DCM_BATTERY_INDICATION_VAL_BATTERY_REPLACE;
    case BatteryIndication::Enum::VAL_BATTERY_NO_RECHARGE:
        return DCM_BATTERY_INDICATION_VAL_BATTERY_NO_RECHARGE;
    case BatteryIndication::Enum::VAL_BATTERY_NO_REPLACE:
        return DCM_BATTERY_INDICATION_VAL_BATTERY_NO_REPLACE;
    case BatteryIndication::Enum::VAL_NO_BATTERY:
        return DCM_BATTERY_INDICATION_VAL_NO_BATTERY;
    default:
        break;
    }
    return DCM_BATTERY_INDICATION_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_battery_indication_get_string(const data_collection_model_battery_indication_t *obj_battery_indication)
{
    if (!obj_battery_indication) return NULL;
    const std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<const std::shared_ptr<BatteryIndication >*>(obj_battery_indication);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_battery_indication_set_enum(data_collection_model_battery_indication_t *obj_battery_indication, data_collection_model_battery_indication_e p_value)
{
    if (!obj_battery_indication) return false;
    std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<std::shared_ptr<BatteryIndication >*>(obj_battery_indication);
    if (!obj) return false;
    switch (p_value) {
    case DCM_BATTERY_INDICATION_NO_VAL:
        *obj = BatteryIndication::Enum::NO_VAL;
        return true;
    case DCM_BATTERY_INDICATION_VAL_BATTERY_RECHARGE:
        *obj = BatteryIndication::Enum::VAL_BATTERY_RECHARGE;
        return true;
    case DCM_BATTERY_INDICATION_VAL_BATTERY_REPLACE:
        *obj = BatteryIndication::Enum::VAL_BATTERY_REPLACE;
        return true;
    case DCM_BATTERY_INDICATION_VAL_BATTERY_NO_RECHARGE:
        *obj = BatteryIndication::Enum::VAL_BATTERY_NO_RECHARGE;
        return true;
    case DCM_BATTERY_INDICATION_VAL_BATTERY_NO_REPLACE:
        *obj = BatteryIndication::Enum::VAL_BATTERY_NO_REPLACE;
        return true;
    case DCM_BATTERY_INDICATION_VAL_NO_BATTERY:
        *obj = BatteryIndication::Enum::VAL_NO_BATTERY;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_battery_indication_set_string(data_collection_model_battery_indication_t *obj_battery_indication, const char *p_value)
{
    if (!obj_battery_indication) return false;
    std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<std::shared_ptr<BatteryIndication >*>(obj_battery_indication);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = BatteryIndication::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_battery_indication_make_lnode(data_collection_model_battery_indication_t *p_battery_indication)
{
    return data_collection_lnode_create(p_battery_indication, reinterpret_cast<void(*)(void*)>(data_collection_model_battery_indication_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_battery_indication_refcount(data_collection_model_battery_indication_t *obj_battery_indication)
{
    if (!obj_battery_indication) return 0l;
    std::shared_ptr<BatteryIndication > &obj = *reinterpret_cast<std::shared_ptr<BatteryIndication >*>(obj_battery_indication);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

