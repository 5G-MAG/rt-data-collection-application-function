/**********************************************************************************************************************************
 * HorizontalWithVerticalVelocity - C interface to the HorizontalWithVerticalVelocity object
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

/*#include "HorizontalWithVerticalVelocity.h" already included by data-collection-sp/data-collection.h */
#include "HorizontalWithVerticalVelocity-internal.h"
#include "openapi/model/HorizontalWithVerticalVelocity.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_create(



)
{
    return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_t*>(new std::shared_ptr<HorizontalWithVerticalVelocity>(new HorizontalWithVerticalVelocity(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_create_copy(const data_collection_model_horizontal_with_vertical_velocity_t *other)
{
    return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_t*>(new std::shared_ptr<HorizontalWithVerticalVelocity >(new HorizontalWithVerticalVelocity(**reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocity >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_create_move(data_collection_model_horizontal_with_vertical_velocity_t *other)
{
    return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_t*>(new std::shared_ptr<HorizontalWithVerticalVelocity >(std::move(*reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_copy(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, const data_collection_model_horizontal_with_vertical_velocity_t *other)
{
    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(horizontal_with_vertical_velocity);
    *obj = **reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocity >*>(other);
    return horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_move(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, data_collection_model_horizontal_with_vertical_velocity_t *other)
{
    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(horizontal_with_vertical_velocity);
    obj = std::move(*reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(other));
    return horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_horizontal_with_vertical_velocity_free(data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity)
{
    delete reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(horizontal_with_vertical_velocity);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_horizontal_with_vertical_velocity_toJSON(const data_collection_model_horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity, bool as_request)
{
    const std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocity >*>(horizontal_with_vertical_velocity);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_t*>(new std::shared_ptr<HorizontalWithVerticalVelocity >(new HorizontalWithVerticalVelocity(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_horizontal_with_vertical_velocity_get_h_speed(const data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity)
{
    const std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    typedef typename HorizontalWithVerticalVelocity::HSpeedType ResultFromType;
    const ResultFromType result_from = obj->getHSpeed();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_h_speed(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, const float p_h_speed)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_h_speed;
    typedef typename HorizontalWithVerticalVelocity::HSpeedType ValueType;

    ValueType value = value_from;
    if (!obj->setHSpeed(value)) return NULL;
    return obj_horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_h_speed_move(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, float p_h_speed)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_h_speed;
    typedef typename HorizontalWithVerticalVelocity::HSpeedType ValueType;

    ValueType value = value_from;
    
    if (!obj->setHSpeed(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_horizontal_with_vertical_velocity_get_bearing(const data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity)
{
    const std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    typedef typename HorizontalWithVerticalVelocity::BearingType ResultFromType;
    const ResultFromType result_from = obj->getBearing();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_bearing(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, const int32_t p_bearing)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_bearing;
    typedef typename HorizontalWithVerticalVelocity::BearingType ValueType;

    ValueType value = value_from;
    if (!obj->setBearing(value)) return NULL;
    return obj_horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_bearing_move(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, int32_t p_bearing)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_bearing;
    typedef typename HorizontalWithVerticalVelocity::BearingType ValueType;

    ValueType value = value_from;
    
    if (!obj->setBearing(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_horizontal_with_vertical_velocity_get_v_speed(const data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity)
{
    const std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    typedef typename HorizontalWithVerticalVelocity::VSpeedType ResultFromType;
    const ResultFromType result_from = obj->getVSpeed();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_speed(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, const float p_v_speed)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_v_speed;
    typedef typename HorizontalWithVerticalVelocity::VSpeedType ValueType;

    ValueType value = value_from;
    if (!obj->setVSpeed(value)) return NULL;
    return obj_horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_speed_move(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, float p_v_speed)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_v_speed;
    typedef typename HorizontalWithVerticalVelocity::VSpeedType ValueType;

    ValueType value = value_from;
    
    if (!obj->setVSpeed(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_vertical_direction_t* data_collection_model_horizontal_with_vertical_velocity_get_v_direction(const data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity)
{
    const std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    typedef typename HorizontalWithVerticalVelocity::VDirectionType ResultFromType;
    const ResultFromType result_from = obj->getVDirection();
    const data_collection_model_vertical_direction_t *result = reinterpret_cast<const data_collection_model_vertical_direction_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_direction(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, const data_collection_model_vertical_direction_t* p_v_direction)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_v_direction;
    typedef typename HorizontalWithVerticalVelocity::VDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setVDirection(value)) return NULL;
    return obj_horizontal_with_vertical_velocity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_t *data_collection_model_horizontal_with_vertical_velocity_set_v_direction_move(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity, data_collection_model_vertical_direction_t* p_v_direction)
{
    if (obj_horizontal_with_vertical_velocity == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    const auto &value_from = p_v_direction;
    typedef typename HorizontalWithVerticalVelocity::VDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setVDirection(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_horizontal_with_vertical_velocity_make_lnode(data_collection_model_horizontal_with_vertical_velocity_t *p_horizontal_with_vertical_velocity)
{
    return data_collection_lnode_create(p_horizontal_with_vertical_velocity, reinterpret_cast<void(*)(void*)>(data_collection_model_horizontal_with_vertical_velocity_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_horizontal_with_vertical_velocity_refcount(data_collection_model_horizontal_with_vertical_velocity_t *obj_horizontal_with_vertical_velocity)
{
    std::shared_ptr<HorizontalWithVerticalVelocity > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocity >*>(obj_horizontal_with_vertical_velocity);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

