/**********************************************************************************************************************************
 * r_2DRelativeLocation - C interface to the r_2DRelativeLocation object
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

/*#include "r_2DRelativeLocation.h" already included by data-collection-sp/data-collection.h */
#include "r_2DRelativeLocation-internal.h"
#include "openapi/model/r_2DRelativeLocation.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_create(


)
{
    return reinterpret_cast<data_collection_model_r_2_d_relative_location_t*>(new std::shared_ptr<r_2DRelativeLocation>(new r_2DRelativeLocation(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_create_copy(const data_collection_model_r_2_d_relative_location_t *other)
{
    return reinterpret_cast<data_collection_model_r_2_d_relative_location_t*>(new std::shared_ptr<r_2DRelativeLocation >(new r_2DRelativeLocation(**reinterpret_cast<const std::shared_ptr<r_2DRelativeLocation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_create_move(data_collection_model_r_2_d_relative_location_t *other)
{
    return reinterpret_cast<data_collection_model_r_2_d_relative_location_t*>(new std::shared_ptr<r_2DRelativeLocation >(std::move(*reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_copy(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, const data_collection_model_r_2_d_relative_location_t *other)
{
    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(r_2_d_relative_location);
    *obj = **reinterpret_cast<const std::shared_ptr<r_2DRelativeLocation >*>(other);
    return r_2_d_relative_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_move(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, data_collection_model_r_2_d_relative_location_t *other)
{
    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(r_2_d_relative_location);
    obj = std::move(*reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(other));
    return r_2_d_relative_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_r_2_d_relative_location_free(data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location)
{
    delete reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(r_2_d_relative_location);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_r_2_d_relative_location_toJSON(const data_collection_model_r_2_d_relative_location_t *r_2_d_relative_location, bool as_request)
{
    const std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<const std::shared_ptr<r_2DRelativeLocation >*>(r_2_d_relative_location);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_r_2_d_relative_location_t*>(new std::shared_ptr<r_2DRelativeLocation >(new r_2DRelativeLocation(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_r_2_d_relative_location_get_semi_minor(const data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location)
{
    const std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<const std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    typedef typename r_2DRelativeLocation::SemiMinorType ResultFromType;
    const ResultFromType result_from = obj->getSemiMinor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_minor(data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location, const float p_semi_minor)
{
    if (obj_r_2_d_relative_location == NULL) return NULL;

    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    const auto &value_from = p_semi_minor;
    typedef typename r_2DRelativeLocation::SemiMinorType ValueType;

    ValueType value = value_from;
    if (!obj->setSemiMinor(value)) return NULL;
    return obj_r_2_d_relative_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_minor_move(data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location, float p_semi_minor)
{
    if (obj_r_2_d_relative_location == NULL) return NULL;

    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    const auto &value_from = p_semi_minor;
    typedef typename r_2DRelativeLocation::SemiMinorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSemiMinor(std::move(value))) return NULL;
    return obj_r_2_d_relative_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_r_2_d_relative_location_get_semi_major(const data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location)
{
    const std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<const std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    typedef typename r_2DRelativeLocation::SemiMajorType ResultFromType;
    const ResultFromType result_from = obj->getSemiMajor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_major(data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location, const float p_semi_major)
{
    if (obj_r_2_d_relative_location == NULL) return NULL;

    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    const auto &value_from = p_semi_major;
    typedef typename r_2DRelativeLocation::SemiMajorType ValueType;

    ValueType value = value_from;
    if (!obj->setSemiMajor(value)) return NULL;
    return obj_r_2_d_relative_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_semi_major_move(data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location, float p_semi_major)
{
    if (obj_r_2_d_relative_location == NULL) return NULL;

    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    const auto &value_from = p_semi_major;
    typedef typename r_2DRelativeLocation::SemiMajorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSemiMajor(std::move(value))) return NULL;
    return obj_r_2_d_relative_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_r_2_d_relative_location_get_orientation_angle(const data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location)
{
    const std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<const std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    typedef typename r_2DRelativeLocation::OrientationAngleType ResultFromType;
    const ResultFromType result_from = obj->getOrientationAngle();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_orientation_angle(data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location, const int32_t p_orientation_angle)
{
    if (obj_r_2_d_relative_location == NULL) return NULL;

    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    const auto &value_from = p_orientation_angle;
    typedef typename r_2DRelativeLocation::OrientationAngleType ValueType;

    ValueType value = value_from;
    if (!obj->setOrientationAngle(value)) return NULL;
    return obj_r_2_d_relative_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_r_2_d_relative_location_t *data_collection_model_r_2_d_relative_location_set_orientation_angle_move(data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location, int32_t p_orientation_angle)
{
    if (obj_r_2_d_relative_location == NULL) return NULL;

    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    const auto &value_from = p_orientation_angle;
    typedef typename r_2DRelativeLocation::OrientationAngleType ValueType;

    ValueType value = value_from;
    
    if (!obj->setOrientationAngle(std::move(value))) return NULL;
    return obj_r_2_d_relative_location;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_r_2_d_relative_location_make_lnode(data_collection_model_r_2_d_relative_location_t *p_r_2_d_relative_location)
{
    return data_collection_lnode_create(p_r_2_d_relative_location, reinterpret_cast<void(*)(void*)>(data_collection_model_r_2_d_relative_location_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_r_2_d_relative_location_refcount(data_collection_model_r_2_d_relative_location_t *obj_r_2_d_relative_location)
{
    std::shared_ptr<r_2DRelativeLocation > &obj = *reinterpret_cast<std::shared_ptr<r_2DRelativeLocation >*>(obj_r_2_d_relative_location);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

