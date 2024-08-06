/**********************************************************************************************************************************
 * RelativeDirection - C interface to the RelativeDirection object
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

/*#include "RelativeDirection.h" already included by data-collection-sp/data-collection.h */
#include "RelativeDirection-internal.h"
#include "openapi/model/RelativeDirection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_direction_t *data_collection_model_relative_direction_create()
{
    return reinterpret_cast<data_collection_model_relative_direction_t*>(new std::shared_ptr<RelativeDirection>(new RelativeDirection()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_direction_t *data_collection_model_relative_direction_create_copy(const data_collection_model_relative_direction_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_relative_direction_t*>(new std::shared_ptr<RelativeDirection >(new RelativeDirection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_direction_t *data_collection_model_relative_direction_create_move(data_collection_model_relative_direction_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RelativeDirection > *obj = reinterpret_cast<std::shared_ptr<RelativeDirection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_direction_t *data_collection_model_relative_direction_copy(data_collection_model_relative_direction_t *relative_direction, const data_collection_model_relative_direction_t *other)
{
    if (relative_direction) {
        std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<std::shared_ptr<RelativeDirection >*>(relative_direction);
        if (obj) {
            if (other) {
                const std::shared_ptr<RelativeDirection > &other_obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(other);
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
                const std::shared_ptr<RelativeDirection > &other_obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(other);
                if (other_obj) {
                    obj.reset(new RelativeDirection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        relative_direction = data_collection_model_relative_direction_create_copy(other);
    }
    return relative_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_direction_t *data_collection_model_relative_direction_move(data_collection_model_relative_direction_t *relative_direction, data_collection_model_relative_direction_t *other)
{
    std::shared_ptr<RelativeDirection > *other_ptr = reinterpret_cast<std::shared_ptr<RelativeDirection >*>(other);

    if (relative_direction) {
        std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<std::shared_ptr<RelativeDirection >*>(relative_direction);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                relative_direction = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return relative_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_relative_direction_free(data_collection_model_relative_direction_t *relative_direction)
{
    if (!relative_direction) return;
    delete reinterpret_cast<std::shared_ptr<RelativeDirection >*>(relative_direction);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_relative_direction_toJSON(const data_collection_model_relative_direction_t *relative_direction, bool as_request)
{
    if (!relative_direction) return NULL;
    const std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(relative_direction);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_direction_t *data_collection_model_relative_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_relative_direction_t*>(new std::shared_ptr<RelativeDirection >(new RelativeDirection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_direction_is_equal_to(const data_collection_model_relative_direction_t *first, const data_collection_model_relative_direction_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RelativeDirection > &obj2 = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RelativeDirection > &obj1 = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_direction_is_not_set(const data_collection_model_relative_direction_t *obj_relative_direction)
{
    if (!obj_relative_direction) return true;
    const std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(obj_relative_direction);
    if (!obj) return true;
    return obj->getValue() == RelativeDirection::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_direction_is_non_standard(const data_collection_model_relative_direction_t *obj_relative_direction)
{
    if (!obj_relative_direction) return false;
    const std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(obj_relative_direction);
    if (!obj) return false;
    return obj->getValue() == RelativeDirection::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_direction_e data_collection_model_relative_direction_get_enum(const data_collection_model_relative_direction_t *obj_relative_direction)
{
    if (!obj_relative_direction)
        return DCM_RELATIVE_DIRECTION_NO_VAL;
    const std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(obj_relative_direction);
    if (!obj) return DCM_RELATIVE_DIRECTION_NO_VAL;
    switch (obj->getValue()) {
    case RelativeDirection::Enum::NO_VAL:
        return DCM_RELATIVE_DIRECTION_NO_VAL;
    case RelativeDirection::Enum::VAL_ABOVE:
        return DCM_RELATIVE_DIRECTION_VAL_ABOVE;
    case RelativeDirection::Enum::VAL_BELOW:
        return DCM_RELATIVE_DIRECTION_VAL_BELOW;
    case RelativeDirection::Enum::VAL_LEFT:
        return DCM_RELATIVE_DIRECTION_VAL_LEFT;
    case RelativeDirection::Enum::VAL_RIGHT:
        return DCM_RELATIVE_DIRECTION_VAL_RIGHT;
    case RelativeDirection::Enum::VAL_BEFORE:
        return DCM_RELATIVE_DIRECTION_VAL_BEFORE;
    case RelativeDirection::Enum::VAL_AFTER:
        return DCM_RELATIVE_DIRECTION_VAL_AFTER;
    default:
        break;
    }
    return DCM_RELATIVE_DIRECTION_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_relative_direction_get_string(const data_collection_model_relative_direction_t *obj_relative_direction)
{
    if (!obj_relative_direction) return NULL;
    const std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RelativeDirection >*>(obj_relative_direction);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_direction_set_enum(data_collection_model_relative_direction_t *obj_relative_direction, data_collection_model_relative_direction_e p_value)
{
    if (!obj_relative_direction) return false;
    std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<std::shared_ptr<RelativeDirection >*>(obj_relative_direction);
    if (!obj) return false;
    switch (p_value) {
    case DCM_RELATIVE_DIRECTION_NO_VAL:
        *obj = RelativeDirection::Enum::NO_VAL;
        return true;
    case DCM_RELATIVE_DIRECTION_VAL_ABOVE:
        *obj = RelativeDirection::Enum::VAL_ABOVE;
        return true;
    case DCM_RELATIVE_DIRECTION_VAL_BELOW:
        *obj = RelativeDirection::Enum::VAL_BELOW;
        return true;
    case DCM_RELATIVE_DIRECTION_VAL_LEFT:
        *obj = RelativeDirection::Enum::VAL_LEFT;
        return true;
    case DCM_RELATIVE_DIRECTION_VAL_RIGHT:
        *obj = RelativeDirection::Enum::VAL_RIGHT;
        return true;
    case DCM_RELATIVE_DIRECTION_VAL_BEFORE:
        *obj = RelativeDirection::Enum::VAL_BEFORE;
        return true;
    case DCM_RELATIVE_DIRECTION_VAL_AFTER:
        *obj = RelativeDirection::Enum::VAL_AFTER;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_direction_set_string(data_collection_model_relative_direction_t *obj_relative_direction, const char *p_value)
{
    if (!obj_relative_direction) return false;
    std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<std::shared_ptr<RelativeDirection >*>(obj_relative_direction);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = RelativeDirection::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_relative_direction_make_lnode(data_collection_model_relative_direction_t *p_relative_direction)
{
    return data_collection_lnode_create(p_relative_direction, reinterpret_cast<void(*)(void*)>(data_collection_model_relative_direction_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_relative_direction_refcount(data_collection_model_relative_direction_t *obj_relative_direction)
{
    if (!obj_relative_direction) return 0l;
    std::shared_ptr<RelativeDirection > &obj = *reinterpret_cast<std::shared_ptr<RelativeDirection >*>(obj_relative_direction);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

