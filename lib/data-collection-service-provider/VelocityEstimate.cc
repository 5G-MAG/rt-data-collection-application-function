/**********************************************************************************************************************************
 * VelocityEstimate - C interface to the VelocityEstimate object
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

/*#include "VelocityEstimate.h" already included by data-collection-sp/data-collection.h */
#include "VelocityEstimate-internal.h"
#include "openapi/model/VelocityEstimate.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_create(





)
{
    return reinterpret_cast<data_collection_model_velocity_estimate_t*>(new std::shared_ptr<VelocityEstimate>(new VelocityEstimate(





)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_create_copy(const data_collection_model_velocity_estimate_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_velocity_estimate_t*>(new std::shared_ptr<VelocityEstimate >(new VelocityEstimate(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_create_move(data_collection_model_velocity_estimate_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<VelocityEstimate > *obj = reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_copy(data_collection_model_velocity_estimate_t *velocity_estimate, const data_collection_model_velocity_estimate_t *other)
{
    if (velocity_estimate) {
        std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(velocity_estimate);
        if (obj) {
            if (other) {
                const std::shared_ptr<VelocityEstimate > &other_obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(other);
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
                const std::shared_ptr<VelocityEstimate > &other_obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(other);
                if (other_obj) {
                    obj.reset(new VelocityEstimate(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        velocity_estimate = data_collection_model_velocity_estimate_create_copy(other);
    }
    return velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_move(data_collection_model_velocity_estimate_t *velocity_estimate, data_collection_model_velocity_estimate_t *other)
{
    std::shared_ptr<VelocityEstimate > *other_ptr = reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(other);

    if (velocity_estimate) {
        std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(velocity_estimate);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                velocity_estimate = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_velocity_estimate_free(data_collection_model_velocity_estimate_t *velocity_estimate)
{
    if (!velocity_estimate) return;
    delete reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(velocity_estimate);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_velocity_estimate_toJSON(const data_collection_model_velocity_estimate_t *velocity_estimate, bool as_request)
{
    if (!velocity_estimate) return NULL;
    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(velocity_estimate);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_velocity_estimate_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_velocity_estimate_t*>(new std::shared_ptr<VelocityEstimate >(new VelocityEstimate(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_velocity_estimate_is_equal_to(const data_collection_model_velocity_estimate_t *first, const data_collection_model_velocity_estimate_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<VelocityEstimate > &obj2 = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<VelocityEstimate > &obj1 = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_velocity_estimate_get_h_speed(const data_collection_model_velocity_estimate_t *obj_velocity_estimate)
{
    if (!obj_velocity_estimate) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename VelocityEstimate::HSpeedType ResultFromType;
    const ResultFromType &result_from = obj->getHSpeed();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_h_speed(data_collection_model_velocity_estimate_t *obj_velocity_estimate, const float p_h_speed)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_h_speed;
    typedef typename VelocityEstimate::HSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setHSpeed(value)) return NULL;

    return obj_velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_h_speed_move(data_collection_model_velocity_estimate_t *obj_velocity_estimate, float p_h_speed)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_h_speed;
    typedef typename VelocityEstimate::HSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setHSpeed(std::move(value))) return NULL;

    return obj_velocity_estimate;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_velocity_estimate_get_bearing(const data_collection_model_velocity_estimate_t *obj_velocity_estimate)
{
    if (!obj_velocity_estimate) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename VelocityEstimate::BearingType ResultFromType;
    const ResultFromType &result_from = obj->getBearing();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_bearing(data_collection_model_velocity_estimate_t *obj_velocity_estimate, const int32_t p_bearing)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_bearing;
    typedef typename VelocityEstimate::BearingType ValueType;

    ValueType value(value_from);

    if (!obj->setBearing(value)) return NULL;

    return obj_velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_bearing_move(data_collection_model_velocity_estimate_t *obj_velocity_estimate, int32_t p_bearing)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_bearing;
    typedef typename VelocityEstimate::BearingType ValueType;

    ValueType value(value_from);

    if (!obj->setBearing(std::move(value))) return NULL;

    return obj_velocity_estimate;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_velocity_estimate_get_v_speed(const data_collection_model_velocity_estimate_t *obj_velocity_estimate)
{
    if (!obj_velocity_estimate) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename VelocityEstimate::VSpeedType ResultFromType;
    const ResultFromType &result_from = obj->getVSpeed();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_v_speed(data_collection_model_velocity_estimate_t *obj_velocity_estimate, const float p_v_speed)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_v_speed;
    typedef typename VelocityEstimate::VSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setVSpeed(value)) return NULL;

    return obj_velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_v_speed_move(data_collection_model_velocity_estimate_t *obj_velocity_estimate, float p_v_speed)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_v_speed;
    typedef typename VelocityEstimate::VSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setVSpeed(std::move(value))) return NULL;

    return obj_velocity_estimate;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_vertical_direction_t* data_collection_model_velocity_estimate_get_v_direction(const data_collection_model_velocity_estimate_t *obj_velocity_estimate)
{
    if (!obj_velocity_estimate) {
        const data_collection_model_vertical_direction_t *result = NULL;
        return result;
    }

    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) {
        const data_collection_model_vertical_direction_t *result = NULL;
        return result;
    }

    typedef typename VelocityEstimate::VDirectionType ResultFromType;
    const ResultFromType &result_from = obj->getVDirection();
    const data_collection_model_vertical_direction_t *result = reinterpret_cast<const data_collection_model_vertical_direction_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_v_direction(data_collection_model_velocity_estimate_t *obj_velocity_estimate, const data_collection_model_vertical_direction_t* p_v_direction)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_v_direction;
    typedef typename VelocityEstimate::VDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setVDirection(value)) return NULL;

    return obj_velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_v_direction_move(data_collection_model_velocity_estimate_t *obj_velocity_estimate, data_collection_model_vertical_direction_t* p_v_direction)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_v_direction;
    typedef typename VelocityEstimate::VDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setVDirection(std::move(value))) return NULL;
    data_collection_model_vertical_direction_free
(p_v_direction);

    return obj_velocity_estimate;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_velocity_estimate_get_h_uncertainty(const data_collection_model_velocity_estimate_t *obj_velocity_estimate)
{
    if (!obj_velocity_estimate) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename VelocityEstimate::HUncertaintyType ResultFromType;
    const ResultFromType &result_from = obj->getHUncertainty();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_h_uncertainty(data_collection_model_velocity_estimate_t *obj_velocity_estimate, const float p_h_uncertainty)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_h_uncertainty;
    typedef typename VelocityEstimate::HUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setHUncertainty(value)) return NULL;

    return obj_velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_h_uncertainty_move(data_collection_model_velocity_estimate_t *obj_velocity_estimate, float p_h_uncertainty)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_h_uncertainty;
    typedef typename VelocityEstimate::HUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setHUncertainty(std::move(value))) return NULL;

    return obj_velocity_estimate;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_velocity_estimate_get_v_uncertainty(const data_collection_model_velocity_estimate_t *obj_velocity_estimate)
{
    if (!obj_velocity_estimate) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<const std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename VelocityEstimate::VUncertaintyType ResultFromType;
    const ResultFromType &result_from = obj->getVUncertainty();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_v_uncertainty(data_collection_model_velocity_estimate_t *obj_velocity_estimate, const float p_v_uncertainty)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_v_uncertainty;
    typedef typename VelocityEstimate::VUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setVUncertainty(value)) return NULL;

    return obj_velocity_estimate;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_velocity_estimate_t *data_collection_model_velocity_estimate_set_v_uncertainty_move(data_collection_model_velocity_estimate_t *obj_velocity_estimate, float p_v_uncertainty)
{
    if (!obj_velocity_estimate) return NULL;

    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    if (!obj) return NULL;

    const auto &value_from = p_v_uncertainty;
    typedef typename VelocityEstimate::VUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setVUncertainty(std::move(value))) return NULL;

    return obj_velocity_estimate;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_velocity_estimate_make_lnode(data_collection_model_velocity_estimate_t *p_velocity_estimate)
{
    return data_collection_lnode_create(p_velocity_estimate, reinterpret_cast<void(*)(void*)>(data_collection_model_velocity_estimate_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_velocity_estimate_refcount(data_collection_model_velocity_estimate_t *obj_velocity_estimate)
{
    if (!obj_velocity_estimate) return 0l;
    std::shared_ptr<VelocityEstimate > &obj = *reinterpret_cast<std::shared_ptr<VelocityEstimate >*>(obj_velocity_estimate);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

