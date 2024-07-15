/**********************************************************************************************************************************
 * HorizontalWithVerticalVelocityAndUncertainty - C interface to the HorizontalWithVerticalVelocityAndUncertainty object
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

/*#include "HorizontalWithVerticalVelocityAndUncertainty.h" already included by data-collection-sp/data-collection.h */
#include "HorizontalWithVerticalVelocityAndUncertainty-internal.h"
#include "openapi/model/HorizontalWithVerticalVelocityAndUncertainty.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_create(





)
{
    return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t*>(new std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty>(new HorizontalWithVerticalVelocityAndUncertainty(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_create_copy(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *other)
{
    return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t*>(new std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >(new HorizontalWithVerticalVelocityAndUncertainty(**reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_create_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *other)
{
    return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t*>(new std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >(std::move(*reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_copy(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty, const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *other)
{
    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(horizontal_with_vertical_velocity_and_uncertainty);
    *obj = **reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(other);
    return horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty, data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *other)
{
    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(horizontal_with_vertical_velocity_and_uncertainty);
    obj = std::move(*reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(other));
    return horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_free(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty)
{
    delete reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(horizontal_with_vertical_velocity_and_uncertainty);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_toJSON(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty, bool as_request)
{
    const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(horizontal_with_vertical_velocity_and_uncertainty);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t*>(new std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >(new HorizontalWithVerticalVelocityAndUncertainty(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_get_h_speed(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty)
{
    const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::HSpeedType ResultFromType;
    const ResultFromType result_from = obj->getHSpeed();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_h_speed(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, const float p_h_speed)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_h_speed;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::HSpeedType ValueType;

    ValueType value = value_from;
    if (!obj->setHSpeed(value)) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_h_speed_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, float p_h_speed)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_h_speed;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::HSpeedType ValueType;

    ValueType value = value_from;
    
    if (!obj->setHSpeed(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_get_bearing(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty)
{
    const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::BearingType ResultFromType;
    const ResultFromType result_from = obj->getBearing();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_bearing(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, const int32_t p_bearing)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_bearing;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::BearingType ValueType;

    ValueType value = value_from;
    if (!obj->setBearing(value)) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_bearing_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, int32_t p_bearing)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_bearing;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::BearingType ValueType;

    ValueType value = value_from;
    
    if (!obj->setBearing(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_get_v_speed(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty)
{
    const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VSpeedType ResultFromType;
    const ResultFromType result_from = obj->getVSpeed();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_v_speed(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, const float p_v_speed)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_v_speed;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VSpeedType ValueType;

    ValueType value = value_from;
    if (!obj->setVSpeed(value)) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_v_speed_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, float p_v_speed)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_v_speed;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VSpeedType ValueType;

    ValueType value = value_from;
    
    if (!obj->setVSpeed(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_vertical_direction_t* data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_get_v_direction(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty)
{
    const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VDirectionType ResultFromType;
    const ResultFromType result_from = obj->getVDirection();
    const data_collection_model_vertical_direction_t *result = reinterpret_cast<const data_collection_model_vertical_direction_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_v_direction(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, const data_collection_model_vertical_direction_t* p_v_direction)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_v_direction;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setVDirection(value)) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_v_direction_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, data_collection_model_vertical_direction_t* p_v_direction)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_v_direction;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setVDirection(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_get_h_uncertainty(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty)
{
    const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::HUncertaintyType ResultFromType;
    const ResultFromType result_from = obj->getHUncertainty();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_h_uncertainty(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, const float p_h_uncertainty)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_h_uncertainty;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::HUncertaintyType ValueType;

    ValueType value = value_from;
    if (!obj->setHUncertainty(value)) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_h_uncertainty_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, float p_h_uncertainty)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_h_uncertainty;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::HUncertaintyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setHUncertainty(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_get_v_uncertainty(const data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty)
{
    const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VUncertaintyType ResultFromType;
    const ResultFromType result_from = obj->getVUncertainty();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_v_uncertainty(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, const float p_v_uncertainty)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_v_uncertainty;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VUncertaintyType ValueType;

    ValueType value = value_from;
    if (!obj->setVUncertainty(value)) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_set_v_uncertainty_move(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty, float p_v_uncertainty)
{
    if (obj_horizontal_with_vertical_velocity_and_uncertainty == NULL) return NULL;

    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    const auto &value_from = p_v_uncertainty;
    typedef typename HorizontalWithVerticalVelocityAndUncertainty::VUncertaintyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setVUncertainty(std::move(value))) return NULL;
    return obj_horizontal_with_vertical_velocity_and_uncertainty;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_make_lnode(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *p_horizontal_with_vertical_velocity_and_uncertainty)
{
    return data_collection_lnode_create(p_horizontal_with_vertical_velocity_and_uncertainty, reinterpret_cast<void(*)(void*)>(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_horizontal_with_vertical_velocity_and_uncertainty_refcount(data_collection_model_horizontal_with_vertical_velocity_and_uncertainty_t *obj_horizontal_with_vertical_velocity_and_uncertainty)
{
    std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalWithVerticalVelocityAndUncertainty >*>(obj_horizontal_with_vertical_velocity_and_uncertainty);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

