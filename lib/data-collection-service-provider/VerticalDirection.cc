/**********************************************************************************************************************************
 * VerticalDirection - C interface to the VerticalDirection object
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

/*#include "VerticalDirection.h" already included by data-collection-sp/data-collection.h */
#include "VerticalDirection-internal.h"
#include "openapi/model/VerticalDirection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_create()
{
    return reinterpret_cast<data_collection_model_vertical_direction_t*>(new std::shared_ptr<VerticalDirection>(new VerticalDirection()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_create_copy(const data_collection_model_vertical_direction_t *other)
{
    return reinterpret_cast<data_collection_model_vertical_direction_t*>(new std::shared_ptr<VerticalDirection >(new VerticalDirection(**reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_create_move(data_collection_model_vertical_direction_t *other)
{
    return reinterpret_cast<data_collection_model_vertical_direction_t*>(new std::shared_ptr<VerticalDirection >(std::move(*reinterpret_cast<std::shared_ptr<VerticalDirection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_copy(data_collection_model_vertical_direction_t *vertical_direction, const data_collection_model_vertical_direction_t *other)
{
    std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<std::shared_ptr<VerticalDirection >*>(vertical_direction);
    *obj = **reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(other);
    return vertical_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_move(data_collection_model_vertical_direction_t *vertical_direction, data_collection_model_vertical_direction_t *other)
{
    std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<std::shared_ptr<VerticalDirection >*>(vertical_direction);
    obj = std::move(*reinterpret_cast<std::shared_ptr<VerticalDirection >*>(other));
    return vertical_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_vertical_direction_free(data_collection_model_vertical_direction_t *vertical_direction)
{
    delete reinterpret_cast<std::shared_ptr<VerticalDirection >*>(vertical_direction);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_vertical_direction_toJSON(const data_collection_model_vertical_direction_t *vertical_direction, bool as_request)
{
    const std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(vertical_direction);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_vertical_direction_t *data_collection_model_vertical_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_vertical_direction_t*>(new std::shared_ptr<VerticalDirection >(new VerticalDirection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_vertical_direction_is_equal_to(const data_collection_model_vertical_direction_t *first, const data_collection_model_vertical_direction_t *second)
{
    const std::shared_ptr<VerticalDirection > &obj1 = *reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(first);
    const std::shared_ptr<VerticalDirection > &obj2 = *reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_vertical_direction_is_not_set(const data_collection_model_vertical_direction_t *vertical_direction)
{
    const std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(vertical_direction);
    return obj->getValue() == VerticalDirection::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_vertical_direction_e data_collection_model_vertical_direction_get_enum(const data_collection_model_vertical_direction_t *obj_vertical_direction)
{
    const std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(obj_vertical_direction);
    switch (obj->getValue()) {
    case VerticalDirection::Enum::NO_VAL:
        return DCM_VERTICAL_DIRECTION_NO_VAL;
    case VerticalDirection::Enum::VAL_UPWARD:
        return DCM_VERTICAL_DIRECTION_VAL_UPWARD;
    case VerticalDirection::Enum::VAL_DOWNWARD:
        return DCM_VERTICAL_DIRECTION_VAL_DOWNWARD;
    default:
        break;
    }
    return (data_collection_model_vertical_direction_e)-1;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_vertical_direction_get_string(const data_collection_model_vertical_direction_t *obj_vertical_direction)
{
    const std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<const std::shared_ptr<VerticalDirection >*>(obj_vertical_direction);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_vertical_direction_set_enum(data_collection_model_vertical_direction_t *obj_vertical_direction, data_collection_model_vertical_direction_e p_value)
{
    std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<std::shared_ptr<VerticalDirection >*>(obj_vertical_direction);
    switch (p_value) {
    case DCM_VERTICAL_DIRECTION_NO_VAL:
        *obj = VerticalDirection::Enum::NO_VAL;
        return true;
    case DCM_VERTICAL_DIRECTION_VAL_UPWARD:
        *obj = VerticalDirection::Enum::VAL_UPWARD;
        return true;
    case DCM_VERTICAL_DIRECTION_VAL_DOWNWARD:
        *obj = VerticalDirection::Enum::VAL_DOWNWARD;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_vertical_direction_set_string(data_collection_model_vertical_direction_t *obj_vertical_direction, const char *p_value)
{
    std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<std::shared_ptr<VerticalDirection >*>(obj_vertical_direction);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = VerticalDirection::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_vertical_direction_make_lnode(data_collection_model_vertical_direction_t *p_vertical_direction)
{
    return data_collection_lnode_create(p_vertical_direction, reinterpret_cast<void(*)(void*)>(data_collection_model_vertical_direction_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_vertical_direction_refcount(data_collection_model_vertical_direction_t *obj_vertical_direction)
{
    std::shared_ptr<VerticalDirection > &obj = *reinterpret_cast<std::shared_ptr<VerticalDirection >*>(obj_vertical_direction);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

