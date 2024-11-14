/**********************************************************************************************************************************
 * Direction - C interface to the Direction object
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

/*#include "Direction.h" already included by data-collection-sp/data-collection.h */
#include "Direction-internal.h"
#include "openapi/model/Direction.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_create()
{
    return reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction>(new Direction()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_create_ref(const data_collection_model_direction_t *other)
{
    return reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction>(*reinterpret_cast<const std::shared_ptr<Direction >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_create_copy(const data_collection_model_direction_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction >(new Direction(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_create_move(data_collection_model_direction_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Direction > *obj = reinterpret_cast<std::shared_ptr<Direction >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_copy(data_collection_model_direction_t *direction, const data_collection_model_direction_t *other)
{
    if (direction) {
        std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(direction);
        if (obj) {
            if (other) {
                const std::shared_ptr<Direction > &other_obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(other);
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
                const std::shared_ptr<Direction > &other_obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(other);
                if (other_obj) {
                    obj.reset(new Direction(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        direction = data_collection_model_direction_create_copy(other);
    }
    return direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_move(data_collection_model_direction_t *direction, data_collection_model_direction_t *other)
{
    std::shared_ptr<Direction > *other_ptr = reinterpret_cast<std::shared_ptr<Direction >*>(other);

    if (direction) {
        std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(direction);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                direction = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_direction_free(data_collection_model_direction_t *direction)
{
    if (!direction) return;
    delete reinterpret_cast<std::shared_ptr<Direction >*>(direction);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_direction_toJSON(const data_collection_model_direction_t *direction, bool as_request)
{
    if (!direction) return NULL;
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(direction);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_direction_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction >(new Direction(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_equal_to(const data_collection_model_direction_t *first, const data_collection_model_direction_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Direction > &obj2 = *reinterpret_cast<const std::shared_ptr<Direction >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Direction > &obj1 = *reinterpret_cast<const std::shared_ptr<Direction >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_not_set(const data_collection_model_direction_t *obj_direction)
{
    if (!obj_direction) return true;
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
    if (!obj) return true;
    return obj->getValue() == Direction::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_non_standard(const data_collection_model_direction_t *obj_direction)
{
    if (!obj_direction) return false;
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
    if (!obj) return false;
    return obj->getValue() == Direction::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_e data_collection_model_direction_get_enum(const data_collection_model_direction_t *obj_direction)
{
    if (!obj_direction)
        return DCM_DIRECTION_NO_VAL;
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
    if (!obj) return DCM_DIRECTION_NO_VAL;
    switch (obj->getValue()) {
    case Direction::Enum::NO_VAL:
        return DCM_DIRECTION_NO_VAL;
    case Direction::Enum::VAL_NORTH:
        return DCM_DIRECTION_VAL_NORTH;
    case Direction::Enum::VAL_SOUTH:
        return DCM_DIRECTION_VAL_SOUTH;
    case Direction::Enum::VAL_EAST:
        return DCM_DIRECTION_VAL_EAST;
    case Direction::Enum::VAL_WEST:
        return DCM_DIRECTION_VAL_WEST;
    case Direction::Enum::VAL_NORTHWEST:
        return DCM_DIRECTION_VAL_NORTHWEST;
    case Direction::Enum::VAL_NORTHEAST:
        return DCM_DIRECTION_VAL_NORTHEAST;
    case Direction::Enum::VAL_SOUTHWEST:
        return DCM_DIRECTION_VAL_SOUTHWEST;
    case Direction::Enum::VAL_SOUTHEAST:
        return DCM_DIRECTION_VAL_SOUTHEAST;
    default:
        break;
    }
    return DCM_DIRECTION_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_direction_get_string(const data_collection_model_direction_t *obj_direction)
{
    if (!obj_direction) return NULL;
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_set_enum(data_collection_model_direction_t *obj_direction, data_collection_model_direction_e p_value)
{
    if (!obj_direction) return false;
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(obj_direction);
    if (!obj) return false;
    switch (p_value) {
    case DCM_DIRECTION_NO_VAL:
        *obj = Direction::Enum::NO_VAL;
        return true;
    case DCM_DIRECTION_VAL_NORTH:
        *obj = Direction::Enum::VAL_NORTH;
        return true;
    case DCM_DIRECTION_VAL_SOUTH:
        *obj = Direction::Enum::VAL_SOUTH;
        return true;
    case DCM_DIRECTION_VAL_EAST:
        *obj = Direction::Enum::VAL_EAST;
        return true;
    case DCM_DIRECTION_VAL_WEST:
        *obj = Direction::Enum::VAL_WEST;
        return true;
    case DCM_DIRECTION_VAL_NORTHWEST:
        *obj = Direction::Enum::VAL_NORTHWEST;
        return true;
    case DCM_DIRECTION_VAL_NORTHEAST:
        *obj = Direction::Enum::VAL_NORTHEAST;
        return true;
    case DCM_DIRECTION_VAL_SOUTHWEST:
        *obj = Direction::Enum::VAL_SOUTHWEST;
        return true;
    case DCM_DIRECTION_VAL_SOUTHEAST:
        *obj = Direction::Enum::VAL_SOUTHEAST;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_set_string(data_collection_model_direction_t *obj_direction, const char *p_value)
{
    if (!obj_direction) return false;
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(obj_direction);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = Direction::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_direction_make_lnode(data_collection_model_direction_t *p_direction)
{
    return data_collection_lnode_create(p_direction, reinterpret_cast<void(*)(void*)>(data_collection_model_direction_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_direction_refcount(data_collection_model_direction_t *obj_direction)
{
    if (!obj_direction) return 0l;
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(obj_direction);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

