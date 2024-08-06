/**********************************************************************************************************************************
 * Direction_anyOf - C interface to the Direction_anyOf object
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

/*#include "Direction_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "Direction_anyOf-internal.h"
#include "openapi/model/Direction_anyOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_any_of_t *data_collection_model_direction_any_of_create()
{
    return reinterpret_cast<data_collection_model_direction_any_of_t*>(new std::shared_ptr<Direction_anyOf>(new Direction_anyOf()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_any_of_t *data_collection_model_direction_any_of_create_copy(const data_collection_model_direction_any_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_direction_any_of_t*>(new std::shared_ptr<Direction_anyOf >(new Direction_anyOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_any_of_t *data_collection_model_direction_any_of_create_move(data_collection_model_direction_any_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Direction_anyOf > *obj = reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_any_of_t *data_collection_model_direction_any_of_copy(data_collection_model_direction_any_of_t *direction_any_of, const data_collection_model_direction_any_of_t *other)
{
    if (direction_any_of) {
        std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(direction_any_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<Direction_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(other);
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
                const std::shared_ptr<Direction_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(other);
                if (other_obj) {
                    obj.reset(new Direction_anyOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        direction_any_of = data_collection_model_direction_any_of_create_copy(other);
    }
    return direction_any_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_any_of_t *data_collection_model_direction_any_of_move(data_collection_model_direction_any_of_t *direction_any_of, data_collection_model_direction_any_of_t *other)
{
    std::shared_ptr<Direction_anyOf > *other_ptr = reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(other);

    if (direction_any_of) {
        std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(direction_any_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                direction_any_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return direction_any_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_direction_any_of_free(data_collection_model_direction_any_of_t *direction_any_of)
{
    if (!direction_any_of) return;
    delete reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(direction_any_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_direction_any_of_toJSON(const data_collection_model_direction_any_of_t *direction_any_of, bool as_request)
{
    if (!direction_any_of) return NULL;
    const std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(direction_any_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_any_of_t *data_collection_model_direction_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_direction_any_of_t*>(new std::shared_ptr<Direction_anyOf >(new Direction_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_any_of_is_equal_to(const data_collection_model_direction_any_of_t *first, const data_collection_model_direction_any_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Direction_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Direction_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_any_of_is_not_set(const data_collection_model_direction_any_of_t *direction_any_of)
{
    if (!direction_any_of) return true;
    const std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(direction_any_of);
    if (!obj) return true;
    return obj->getValue() == Direction_anyOf::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_any_of_e data_collection_model_direction_any_of_get_enum(const data_collection_model_direction_any_of_t *obj_direction_any_of)
{
    if (!obj_direction_any_of)
        return DCM_DIRECTION_ANY_OF_NO_VAL;
    const std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(obj_direction_any_of);
    if (!obj) return DCM_DIRECTION_ANY_OF_NO_VAL;
    switch (obj->getValue()) {
    case Direction_anyOf::Enum::NO_VAL:
        return DCM_DIRECTION_ANY_OF_NO_VAL;
    case Direction_anyOf::Enum::VAL_NORTH:
        return DCM_DIRECTION_ANY_OF_VAL_NORTH;
    case Direction_anyOf::Enum::VAL_SOUTH:
        return DCM_DIRECTION_ANY_OF_VAL_SOUTH;
    case Direction_anyOf::Enum::VAL_EAST:
        return DCM_DIRECTION_ANY_OF_VAL_EAST;
    case Direction_anyOf::Enum::VAL_WEST:
        return DCM_DIRECTION_ANY_OF_VAL_WEST;
    case Direction_anyOf::Enum::VAL_NORTHWEST:
        return DCM_DIRECTION_ANY_OF_VAL_NORTHWEST;
    case Direction_anyOf::Enum::VAL_NORTHEAST:
        return DCM_DIRECTION_ANY_OF_VAL_NORTHEAST;
    case Direction_anyOf::Enum::VAL_SOUTHWEST:
        return DCM_DIRECTION_ANY_OF_VAL_SOUTHWEST;
    case Direction_anyOf::Enum::VAL_SOUTHEAST:
        return DCM_DIRECTION_ANY_OF_VAL_SOUTHEAST;
    default:
        break;
    }
    return (data_collection_model_direction_any_of_e)-1;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_direction_any_of_get_string(const data_collection_model_direction_any_of_t *obj_direction_any_of)
{
    if (!obj_direction_any_of) return NULL;
    const std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<Direction_anyOf >*>(obj_direction_any_of);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_any_of_set_enum(data_collection_model_direction_any_of_t *obj_direction_any_of, data_collection_model_direction_any_of_e p_value)
{
    if (!obj_direction_any_of) return false;
    std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(obj_direction_any_of);
    if (!obj) return false;
    switch (p_value) {
    case DCM_DIRECTION_ANY_OF_NO_VAL:
        *obj = Direction_anyOf::Enum::NO_VAL;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_NORTH:
        *obj = Direction_anyOf::Enum::VAL_NORTH;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_SOUTH:
        *obj = Direction_anyOf::Enum::VAL_SOUTH;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_EAST:
        *obj = Direction_anyOf::Enum::VAL_EAST;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_WEST:
        *obj = Direction_anyOf::Enum::VAL_WEST;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_NORTHWEST:
        *obj = Direction_anyOf::Enum::VAL_NORTHWEST;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_NORTHEAST:
        *obj = Direction_anyOf::Enum::VAL_NORTHEAST;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_SOUTHWEST:
        *obj = Direction_anyOf::Enum::VAL_SOUTHWEST;
        return true;
    case DCM_DIRECTION_ANY_OF_VAL_SOUTHEAST:
        *obj = Direction_anyOf::Enum::VAL_SOUTHEAST;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_any_of_set_string(data_collection_model_direction_any_of_t *obj_direction_any_of, const char *p_value)
{
    if (!obj_direction_any_of) return false;
    std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(obj_direction_any_of);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = Direction_anyOf::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_direction_any_of_make_lnode(data_collection_model_direction_any_of_t *p_direction_any_of)
{
    return data_collection_lnode_create(p_direction_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_direction_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_direction_any_of_refcount(data_collection_model_direction_any_of_t *obj_direction_any_of)
{
    if (!obj_direction_any_of) return 0l;
    std::shared_ptr<Direction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<Direction_anyOf >*>(obj_direction_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

