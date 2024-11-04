/**********************************************************************************************************************************
 * HorizontalVelocityWithUncertainty - C interface to the HorizontalVelocityWithUncertainty object
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

/*#include "HorizontalVelocityWithUncertainty.h" already included by data-collection-sp/data-collection.h */
#include "HorizontalVelocityWithUncertainty-internal.h"
#include "openapi/model/HorizontalVelocityWithUncertainty.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create(


)
{
    return reinterpret_cast<data_collection_model_horizontal_velocity_with_uncertainty_t*>(new std::shared_ptr<HorizontalVelocityWithUncertainty>(new HorizontalVelocityWithUncertainty(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create_copy(const data_collection_model_horizontal_velocity_with_uncertainty_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_horizontal_velocity_with_uncertainty_t*>(new std::shared_ptr<HorizontalVelocityWithUncertainty >(new HorizontalVelocityWithUncertainty(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_create_move(data_collection_model_horizontal_velocity_with_uncertainty_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<HorizontalVelocityWithUncertainty > *obj = reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_copy(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, const data_collection_model_horizontal_velocity_with_uncertainty_t *other)
{
    if (horizontal_velocity_with_uncertainty) {
        std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(horizontal_velocity_with_uncertainty);
        if (obj) {
            if (other) {
                const std::shared_ptr<HorizontalVelocityWithUncertainty > &other_obj = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(other);
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
                const std::shared_ptr<HorizontalVelocityWithUncertainty > &other_obj = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(other);
                if (other_obj) {
                    obj.reset(new HorizontalVelocityWithUncertainty(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        horizontal_velocity_with_uncertainty = data_collection_model_horizontal_velocity_with_uncertainty_create_copy(other);
    }
    return horizontal_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_move(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, data_collection_model_horizontal_velocity_with_uncertainty_t *other)
{
    std::shared_ptr<HorizontalVelocityWithUncertainty > *other_ptr = reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(other);

    if (horizontal_velocity_with_uncertainty) {
        std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(horizontal_velocity_with_uncertainty);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                horizontal_velocity_with_uncertainty = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return horizontal_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_horizontal_velocity_with_uncertainty_free(data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty)
{
    if (!horizontal_velocity_with_uncertainty) return;
    delete reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(horizontal_velocity_with_uncertainty);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_horizontal_velocity_with_uncertainty_toJSON(const data_collection_model_horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty, bool as_request)
{
    if (!horizontal_velocity_with_uncertainty) return NULL;
    const std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(horizontal_velocity_with_uncertainty);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_horizontal_velocity_with_uncertainty_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_horizontal_velocity_with_uncertainty_t*>(new std::shared_ptr<HorizontalVelocityWithUncertainty >(new HorizontalVelocityWithUncertainty(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_horizontal_velocity_with_uncertainty_is_equal_to(const data_collection_model_horizontal_velocity_with_uncertainty_t *first, const data_collection_model_horizontal_velocity_with_uncertainty_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<HorizontalVelocityWithUncertainty > &obj2 = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<HorizontalVelocityWithUncertainty > &obj1 = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_velocity_with_uncertainty_get_h_speed(const data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty)
{
    if (!obj_horizontal_velocity_with_uncertainty) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename HorizontalVelocityWithUncertainty::HSpeedType ResultFromType;
    const ResultFromType &result_from = obj->getHSpeed();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_speed(data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty, const float p_h_speed)
{
    if (!obj_horizontal_velocity_with_uncertainty) return NULL;

    std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_h_speed;
    typedef typename HorizontalVelocityWithUncertainty::HSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setHSpeed(value)) return NULL;

    return obj_horizontal_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_speed_move(data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty, float p_h_speed)
{
    if (!obj_horizontal_velocity_with_uncertainty) return NULL;

    std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_h_speed;
    typedef typename HorizontalVelocityWithUncertainty::HSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setHSpeed(std::move(value))) return NULL;

    return obj_horizontal_velocity_with_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_horizontal_velocity_with_uncertainty_get_bearing(const data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty)
{
    if (!obj_horizontal_velocity_with_uncertainty) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename HorizontalVelocityWithUncertainty::BearingType ResultFromType;
    const ResultFromType &result_from = obj->getBearing();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_bearing(data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty, const int32_t p_bearing)
{
    if (!obj_horizontal_velocity_with_uncertainty) return NULL;

    std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_bearing;
    typedef typename HorizontalVelocityWithUncertainty::BearingType ValueType;

    ValueType value(value_from);

    if (!obj->setBearing(value)) return NULL;

    return obj_horizontal_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_bearing_move(data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty, int32_t p_bearing)
{
    if (!obj_horizontal_velocity_with_uncertainty) return NULL;

    std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_bearing;
    typedef typename HorizontalVelocityWithUncertainty::BearingType ValueType;

    ValueType value(value_from);

    if (!obj->setBearing(std::move(value))) return NULL;

    return obj_horizontal_velocity_with_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_horizontal_velocity_with_uncertainty_get_h_uncertainty(const data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty)
{
    if (!obj_horizontal_velocity_with_uncertainty) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename HorizontalVelocityWithUncertainty::HUncertaintyType ResultFromType;
    const ResultFromType &result_from = obj->getHUncertainty();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_uncertainty(data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty, const float p_h_uncertainty)
{
    if (!obj_horizontal_velocity_with_uncertainty) return NULL;

    std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_h_uncertainty;
    typedef typename HorizontalVelocityWithUncertainty::HUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setHUncertainty(value)) return NULL;

    return obj_horizontal_velocity_with_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_horizontal_velocity_with_uncertainty_t *data_collection_model_horizontal_velocity_with_uncertainty_set_h_uncertainty_move(data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty, float p_h_uncertainty)
{
    if (!obj_horizontal_velocity_with_uncertainty) return NULL;

    std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_h_uncertainty;
    typedef typename HorizontalVelocityWithUncertainty::HUncertaintyType ValueType;

    ValueType value(value_from);

    if (!obj->setHUncertainty(std::move(value))) return NULL;

    return obj_horizontal_velocity_with_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_horizontal_velocity_with_uncertainty_make_lnode(data_collection_model_horizontal_velocity_with_uncertainty_t *p_horizontal_velocity_with_uncertainty)
{
    return data_collection_lnode_create(p_horizontal_velocity_with_uncertainty, reinterpret_cast<void(*)(void*)>(data_collection_model_horizontal_velocity_with_uncertainty_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_horizontal_velocity_with_uncertainty_refcount(data_collection_model_horizontal_velocity_with_uncertainty_t *obj_horizontal_velocity_with_uncertainty)
{
    if (!obj_horizontal_velocity_with_uncertainty) return 0l;
    std::shared_ptr<HorizontalVelocityWithUncertainty > &obj = *reinterpret_cast<std::shared_ptr<HorizontalVelocityWithUncertainty >*>(obj_horizontal_velocity_with_uncertainty);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

