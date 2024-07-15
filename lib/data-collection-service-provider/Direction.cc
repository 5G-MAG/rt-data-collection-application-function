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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "Direction.h" already included by data-collection-sp/data-collection.h */
#include "Direction-internal.h"
#include "openapi/model/Direction.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_direction_t *data_collection_model_direction_create()
{
    return reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction>(new Direction()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_direction_t *data_collection_model_direction_create_copy(const data_collection_model_direction_t *other)
{
    return reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction >(new Direction(**reinterpret_cast<const std::shared_ptr<Direction >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_direction_t *data_collection_model_direction_create_move(data_collection_model_direction_t *other)
{
    return reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction >(std::move(*reinterpret_cast<std::shared_ptr<Direction >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_direction_t *data_collection_model_direction_copy(data_collection_model_direction_t *direction, const data_collection_model_direction_t *other)
{
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(direction);
    *obj = **reinterpret_cast<const std::shared_ptr<Direction >*>(other);
    return direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_direction_t *data_collection_model_direction_move(data_collection_model_direction_t *direction, data_collection_model_direction_t *other)
{
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(direction);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Direction >*>(other));
    return direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_direction_free(data_collection_model_direction_t *direction)
{
    delete reinterpret_cast<std::shared_ptr<Direction >*>(direction);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_direction_toJSON(const data_collection_model_direction_t *direction, bool as_request)
{
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(direction);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_direction_t *data_collection_model_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_not_set(const data_collection_model_direction_t *obj_direction)
{
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
    return obj->getValue() == Direction::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_non_standard(const data_collection_model_direction_t *obj_direction)
{
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
    return obj->getValue() == Direction::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_e data_collection_model_direction_get_enum(const data_collection_model_direction_t *obj_direction)
{
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_direction_get_string(const data_collection_model_direction_t *obj_direction)
{
    const std::shared_ptr<Direction > &obj = *reinterpret_cast<const std::shared_ptr<Direction >*>(obj_direction);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_set_enum(data_collection_model_direction_t *obj_direction, data_collection_model_direction_e p_value)
{
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(obj_direction);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_set_string(data_collection_model_direction_t *obj_direction, const char *p_value)
{
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(obj_direction);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = Direction::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_direction_make_lnode(data_collection_model_direction_t *p_direction)
{
    return data_collection_lnode_create(p_direction, reinterpret_cast<void(*)(void*)>(data_collection_model_direction_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_direction_refcount(data_collection_model_direction_t *obj_direction)
{
    std::shared_ptr<Direction > &obj = *reinterpret_cast<std::shared_ptr<Direction >*>(obj_direction);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

