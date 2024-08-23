/**********************************************************************************************************************************
 * PositioningMode - C interface to the PositioningMode object
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

/*#include "PositioningMode.h" already included by data-collection-sp/data-collection.h */
#include "PositioningMode-internal.h"
#include "openapi/model/PositioningMode.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create()
{
    return reinterpret_cast<data_collection_model_positioning_mode_t*>(new std::shared_ptr<PositioningMode>(new PositioningMode()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_copy(const data_collection_model_positioning_mode_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_positioning_mode_t*>(new std::shared_ptr<PositioningMode >(new PositioningMode(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_move(data_collection_model_positioning_mode_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PositioningMode > *obj = reinterpret_cast<std::shared_ptr<PositioningMode >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_copy(data_collection_model_positioning_mode_t *positioning_mode, const data_collection_model_positioning_mode_t *other)
{
    if (positioning_mode) {
        std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(positioning_mode);
        if (obj) {
            if (other) {
                const std::shared_ptr<PositioningMode > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(other);
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
                const std::shared_ptr<PositioningMode > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(other);
                if (other_obj) {
                    obj.reset(new PositioningMode(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        positioning_mode = data_collection_model_positioning_mode_create_copy(other);
    }
    return positioning_mode;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_move(data_collection_model_positioning_mode_t *positioning_mode, data_collection_model_positioning_mode_t *other)
{
    std::shared_ptr<PositioningMode > *other_ptr = reinterpret_cast<std::shared_ptr<PositioningMode >*>(other);

    if (positioning_mode) {
        std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(positioning_mode);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                positioning_mode = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return positioning_mode;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_mode_free(data_collection_model_positioning_mode_t *positioning_mode)
{
    if (!positioning_mode) return;
    delete reinterpret_cast<std::shared_ptr<PositioningMode >*>(positioning_mode);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_mode_toJSON(const data_collection_model_positioning_mode_t *positioning_mode, bool as_request)
{
    if (!positioning_mode) return NULL;
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(positioning_mode);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_positioning_mode_t*>(new std::shared_ptr<PositioningMode >(new PositioningMode(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_equal_to(const data_collection_model_positioning_mode_t *first, const data_collection_model_positioning_mode_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PositioningMode > &obj2 = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PositioningMode > &obj1 = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_not_set(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    if (!obj_positioning_mode) return true;
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    if (!obj) return true;
    return obj->getValue() == PositioningMode::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_non_standard(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    if (!obj_positioning_mode) return false;
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    if (!obj) return false;
    return obj->getValue() == PositioningMode::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_e data_collection_model_positioning_mode_get_enum(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    if (!obj_positioning_mode)
        return DCM_POSITIONING_MODE_NO_VAL;
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    if (!obj) return DCM_POSITIONING_MODE_NO_VAL;
    switch (obj->getValue()) {
    case PositioningMode::Enum::NO_VAL:
        return DCM_POSITIONING_MODE_NO_VAL;
    case PositioningMode::Enum::VAL_UE_BASED:
        return DCM_POSITIONING_MODE_VAL_UE_BASED;
    case PositioningMode::Enum::VAL_UE_ASSISTED:
        return DCM_POSITIONING_MODE_VAL_UE_ASSISTED;
    case PositioningMode::Enum::VAL_CONVENTIONAL:
        return DCM_POSITIONING_MODE_VAL_CONVENTIONAL;
    default:
        break;
    }
    return DCM_POSITIONING_MODE_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_mode_get_string(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    if (!obj_positioning_mode) return NULL;
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_enum(data_collection_model_positioning_mode_t *obj_positioning_mode, data_collection_model_positioning_mode_e p_value)
{
    if (!obj_positioning_mode) return false;
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    if (!obj) return false;
    switch (p_value) {
    case DCM_POSITIONING_MODE_NO_VAL:
        *obj = PositioningMode::Enum::NO_VAL;
        return true;
    case DCM_POSITIONING_MODE_VAL_UE_BASED:
        *obj = PositioningMode::Enum::VAL_UE_BASED;
        return true;
    case DCM_POSITIONING_MODE_VAL_UE_ASSISTED:
        *obj = PositioningMode::Enum::VAL_UE_ASSISTED;
        return true;
    case DCM_POSITIONING_MODE_VAL_CONVENTIONAL:
        *obj = PositioningMode::Enum::VAL_CONVENTIONAL;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_string(data_collection_model_positioning_mode_t *obj_positioning_mode, const char *p_value)
{
    if (!obj_positioning_mode) return false;
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PositioningMode::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_mode_make_lnode(data_collection_model_positioning_mode_t *p_positioning_mode)
{
    return data_collection_lnode_create(p_positioning_mode, reinterpret_cast<void(*)(void*)>(data_collection_model_positioning_mode_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_positioning_mode_refcount(data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    if (!obj_positioning_mode) return 0l;
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

