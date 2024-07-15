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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "RangeDirection.h" already included by data-collection-sp/data-collection.h */
#include "RangeDirection-internal.h"
#include "openapi/model/RangeDirection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_create(


)
{
    return reinterpret_cast<data_collection_model_range_direction_t*>(new std::shared_ptr<RangeDirection>(new RangeDirection(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_create_copy(const data_collection_model_range_direction_t *other)
{
    return reinterpret_cast<data_collection_model_range_direction_t*>(new std::shared_ptr<RangeDirection >(new RangeDirection(**reinterpret_cast<const std::shared_ptr<RangeDirection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_create_move(data_collection_model_range_direction_t *other)
{
    return reinterpret_cast<data_collection_model_range_direction_t*>(new std::shared_ptr<RangeDirection >(std::move(*reinterpret_cast<std::shared_ptr<RangeDirection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_copy(data_collection_model_range_direction_t *range_direction, const data_collection_model_range_direction_t *other)
{
    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(range_direction);
    *obj = **reinterpret_cast<const std::shared_ptr<RangeDirection >*>(other);
    return range_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_move(data_collection_model_range_direction_t *range_direction, data_collection_model_range_direction_t *other)
{
    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(range_direction);
    obj = std::move(*reinterpret_cast<std::shared_ptr<RangeDirection >*>(other));
    return range_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_range_direction_free(data_collection_model_range_direction_t *range_direction)
{
    delete reinterpret_cast<std::shared_ptr<RangeDirection >*>(range_direction);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_range_direction_toJSON(const data_collection_model_range_direction_t *range_direction, bool as_request)
{
    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(range_direction);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const double data_collection_model_range_direction_get_range(const data_collection_model_range_direction_t *obj_range_direction)
{
    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    typedef typename RangeDirection::RangeType ResultFromType;
    const ResultFromType result_from = obj->getRange();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_set_range(data_collection_model_range_direction_t *obj_range_direction, const double p_range)
{
    if (obj_range_direction == NULL) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    const auto &value_from = p_range;
    typedef typename RangeDirection::RangeType ValueType;

    ValueType value = value_from;
    if (!obj->setRange(value)) return NULL;
    return obj_range_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_set_range_move(data_collection_model_range_direction_t *obj_range_direction, double p_range)
{
    if (obj_range_direction == NULL) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    const auto &value_from = p_range;
    typedef typename RangeDirection::RangeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setRange(std::move(value))) return NULL;
    return obj_range_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_range_direction_get_azimuth_direction(const data_collection_model_range_direction_t *obj_range_direction)
{
    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    typedef typename RangeDirection::AzimuthDirectionType ResultFromType;
    const ResultFromType result_from = obj->getAzimuthDirection();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction(data_collection_model_range_direction_t *obj_range_direction, const int32_t p_azimuth_direction)
{
    if (obj_range_direction == NULL) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    const auto &value_from = p_azimuth_direction;
    typedef typename RangeDirection::AzimuthDirectionType ValueType;

    ValueType value = value_from;
    if (!obj->setAzimuthDirection(value)) return NULL;
    return obj_range_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_set_azimuth_direction_move(data_collection_model_range_direction_t *obj_range_direction, int32_t p_azimuth_direction)
{
    if (obj_range_direction == NULL) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    const auto &value_from = p_azimuth_direction;
    typedef typename RangeDirection::AzimuthDirectionType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAzimuthDirection(std::move(value))) return NULL;
    return obj_range_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_range_direction_get_elevation_direction(const data_collection_model_range_direction_t *obj_range_direction)
{
    const std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<const std::shared_ptr<RangeDirection >*>(obj_range_direction);
    typedef typename RangeDirection::ElevationDirectionType ResultFromType;
    const ResultFromType result_from = obj->getElevationDirection();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction(data_collection_model_range_direction_t *obj_range_direction, const int32_t p_elevation_direction)
{
    if (obj_range_direction == NULL) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    const auto &value_from = p_elevation_direction;
    typedef typename RangeDirection::ElevationDirectionType ValueType;

    ValueType value = value_from;
    if (!obj->setElevationDirection(value)) return NULL;
    return obj_range_direction;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_range_direction_t *data_collection_model_range_direction_set_elevation_direction_move(data_collection_model_range_direction_t *obj_range_direction, int32_t p_elevation_direction)
{
    if (obj_range_direction == NULL) return NULL;

    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    const auto &value_from = p_elevation_direction;
    typedef typename RangeDirection::ElevationDirectionType ValueType;

    ValueType value = value_from;
    
    if (!obj->setElevationDirection(std::move(value))) return NULL;
    return obj_range_direction;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_range_direction_make_lnode(data_collection_model_range_direction_t *p_range_direction)
{
    return data_collection_lnode_create(p_range_direction, reinterpret_cast<void(*)(void*)>(data_collection_model_range_direction_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_range_direction_refcount(data_collection_model_range_direction_t *obj_range_direction)
{
    std::shared_ptr<RangeDirection > &obj = *reinterpret_cast<std::shared_ptr<RangeDirection >*>(obj_range_direction);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

