/**********************************************************************************************************************************
 * RangeDirection - C interface to the RangeDirection object
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

/*#include "RangeDirection.h" already included by data-collection-sp/data-collection.h */
#include "RangeDirection-internal.h"
#include "openapi/model/RangeDirection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create(


)
{
    return reinterpret_cast<data_collection_model_range_direction_t*>(new std::shared_ptr<RangeDirection>(new RangeDirection(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_ref(const data_collection_model_range_direction_t *other)
{
    return reinterpret_cast<data_collection_model_range_direction_t*>(new std::shared_ptr<RangeDirection>(*reinterpret_cast<const std::shared_ptr<RangeDirection >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_copy(const data_collection_model_range_direction_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_range_direction_t*>(new std::shared_ptr<RangeDirection >(new RangeDirection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_create_move(data_collection_model_range_direction_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RangeDirection > *obj = reinterpret_cast<std::shared_ptr<RangeDirection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_copy(data_collection_model_range_direction_t *range_direction, const data_collection_model_range_direction_t *other)
{
    if (range_direction) {
        std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(range_direction);
        if (obj) {
            if (other) {
                const std::shared_ptr<RangeDirection > &other_obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(other);
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
                const std::shared_ptr<RangeDirection > &other_obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(other);
                if (other_obj) {
                    obj.reset(new RangeDirection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        range_direction = data_collection_model_range_direction_create_copy(other);
    }
    return range_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_move(data_collection_model_range_direction_t *range_direction, data_collection_model_range_direction_t *other)
{
    std::shared_ptr<RangeDirection > *other_ptr = reinterpret_cast<std::shared_ptr<RangeDirection >*>(other);

    if (range_direction) {
        std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(range_direction);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                range_direction = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return range_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_range_direction_free(data_collection_model_range_direction_t *range_direction)
{
    if (!range_direction) return;
    delete reinterpret_cast<std::shared_ptr<RangeDirection >*>(range_direction);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_range_direction_toJSON(const data_collection_model_range_direction_t *range_direction, bool as_request)
{
    if (!range_direction) return NULL;
    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(range_direction);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_range_direction_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_range_direction_t*>(new std::shared_ptr<RangeDirection >(new RangeDirection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_is_equal_to(const data_collection_model_range_direction_t *first, const data_collection_model_range_direction_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RangeDirection > &obj2 = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RangeDirection > &obj1 = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_distance(const data_collection_model_range_direction_t *obj_range_direction)
{
    if (!obj_range_direction) return false;

    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return false;

    return obj->getDistance().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_range_direction_get_distance(const data_collection_model_range_direction_t *obj_range_direction)
{
    if (!obj_range_direction) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename RangeDirection::DistanceType ResultFromType;
    const ResultFromType &result_from = obj->getDistance();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_distance(data_collection_model_range_direction_t *obj_range_direction, const double p_distance)
{
    if (!obj_range_direction) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return NULL;

    const auto &value_from = p_distance;
    typedef typename RangeDirection::DistanceType ValueType;

    ValueType value(value_from);

    if (!obj->setDistance(value)) return NULL;

    return obj_range_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_distance_move(data_collection_model_range_direction_t *obj_range_direction, double p_distance)
{
    if (!obj_range_direction) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return NULL;

    const auto &value_from = p_distance;
    typedef typename RangeDirection::DistanceType ValueType;

    ValueType value(value_from);

    if (!obj->setDistance(std::move(value))) return NULL;

    return obj_range_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_azimuth_direction(const data_collection_model_range_direction_t *obj_range_direction)
{
    if (!obj_range_direction) return false;

    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return false;

    return obj->getAzimuthDirection().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_range_direction_get_azimuth_direction(const data_collection_model_range_direction_t *obj_range_direction)
{
    if (!obj_range_direction) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename RangeDirection::AzimuthDirectionType ResultFromType;
    const ResultFromType &result_from = obj->getAzimuthDirection();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction(data_collection_model_range_direction_t *obj_range_direction, const int32_t p_azimuth_direction)
{
    if (!obj_range_direction) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return NULL;

    const auto &value_from = p_azimuth_direction;
    typedef typename RangeDirection::AzimuthDirectionType ValueType;

    ValueType value(value_from);

    if (!obj->setAzimuthDirection(value)) return NULL;

    return obj_range_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction_move(data_collection_model_range_direction_t *obj_range_direction, int32_t p_azimuth_direction)
{
    if (!obj_range_direction) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return NULL;

    const auto &value_from = p_azimuth_direction;
    typedef typename RangeDirection::AzimuthDirectionType ValueType;

    ValueType value(value_from);

    if (!obj->setAzimuthDirection(std::move(value))) return NULL;

    return obj_range_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_range_direction_has_elevation_direction(const data_collection_model_range_direction_t *obj_range_direction)
{
    if (!obj_range_direction) return false;

    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return false;

    return obj->getElevationDirection().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_range_direction_get_elevation_direction(const data_collection_model_range_direction_t *obj_range_direction)
{
    if (!obj_range_direction) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename RangeDirection::ElevationDirectionType ResultFromType;
    const ResultFromType &result_from = obj->getElevationDirection();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction(data_collection_model_range_direction_t *obj_range_direction, const int32_t p_elevation_direction)
{
    if (!obj_range_direction) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return NULL;

    const auto &value_from = p_elevation_direction;
    typedef typename RangeDirection::ElevationDirectionType ValueType;

    ValueType value(value_from);

    if (!obj->setElevationDirection(value)) return NULL;

    return obj_range_direction;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction_move(data_collection_model_range_direction_t *obj_range_direction, int32_t p_elevation_direction)
{
    if (!obj_range_direction) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    if (!obj) return NULL;

    const auto &value_from = p_elevation_direction;
    typedef typename RangeDirection::ElevationDirectionType ValueType;

    ValueType value(value_from);

    if (!obj->setElevationDirection(std::move(value))) return NULL;

    return obj_range_direction;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_range_direction_make_lnode(data_collection_model_range_direction_t *p_range_direction)
{
    return data_collection_lnode_create(p_range_direction, reinterpret_cast<void(*)(void*)>(data_collection_model_range_direction_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_range_direction_refcount(data_collection_model_range_direction_t *obj_range_direction)
{
    if (!obj_range_direction) return 0l;
    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

