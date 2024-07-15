/**********************************************************************************************************************************
 * UncertaintyEllipsoid - C interface to the UncertaintyEllipsoid object
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

/*#include "UncertaintyEllipsoid.h" already included by data-collection-sp/data-collection.h */
#include "UncertaintyEllipsoid-internal.h"
#include "openapi/model/UncertaintyEllipsoid.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_create(



)
{
    return reinterpret_cast<data_collection_model_uncertainty_ellipsoid_t*>(new std::shared_ptr<UncertaintyEllipsoid>(new UncertaintyEllipsoid(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_create_copy(const data_collection_model_uncertainty_ellipsoid_t *other)
{
    return reinterpret_cast<data_collection_model_uncertainty_ellipsoid_t*>(new std::shared_ptr<UncertaintyEllipsoid >(new UncertaintyEllipsoid(**reinterpret_cast<const std::shared_ptr<UncertaintyEllipsoid >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_create_move(data_collection_model_uncertainty_ellipsoid_t *other)
{
    return reinterpret_cast<data_collection_model_uncertainty_ellipsoid_t*>(new std::shared_ptr<UncertaintyEllipsoid >(std::move(*reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_copy(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, const data_collection_model_uncertainty_ellipsoid_t *other)
{
    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(uncertainty_ellipsoid);
    *obj = **reinterpret_cast<const std::shared_ptr<UncertaintyEllipsoid >*>(other);
    return uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_move(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, data_collection_model_uncertainty_ellipsoid_t *other)
{
    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(uncertainty_ellipsoid);
    obj = std::move(*reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(other));
    return uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_uncertainty_ellipsoid_free(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid)
{
    delete reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(uncertainty_ellipsoid);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_uncertainty_ellipsoid_toJSON(const data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, bool as_request)
{
    const std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipsoid >*>(uncertainty_ellipsoid);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_uncertainty_ellipsoid_t*>(new std::shared_ptr<UncertaintyEllipsoid >(new UncertaintyEllipsoid(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_uncertainty_ellipsoid_get_semi_major(const data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid)
{
    const std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    typedef typename UncertaintyEllipsoid::SemiMajorType ResultFromType;
    const ResultFromType result_from = obj->getSemiMajor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_major(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, const float p_semi_major)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_semi_major;
    typedef typename UncertaintyEllipsoid::SemiMajorType ValueType;

    ValueType value = value_from;
    if (!obj->setSemiMajor(value)) return NULL;
    return obj_uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_major_move(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, float p_semi_major)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_semi_major;
    typedef typename UncertaintyEllipsoid::SemiMajorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSemiMajor(std::move(value))) return NULL;
    return obj_uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_uncertainty_ellipsoid_get_semi_minor(const data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid)
{
    const std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    typedef typename UncertaintyEllipsoid::SemiMinorType ResultFromType;
    const ResultFromType result_from = obj->getSemiMinor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_minor(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, const float p_semi_minor)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_semi_minor;
    typedef typename UncertaintyEllipsoid::SemiMinorType ValueType;

    ValueType value = value_from;
    if (!obj->setSemiMinor(value)) return NULL;
    return obj_uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_minor_move(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, float p_semi_minor)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_semi_minor;
    typedef typename UncertaintyEllipsoid::SemiMinorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSemiMinor(std::move(value))) return NULL;
    return obj_uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_uncertainty_ellipsoid_get_vertical(const data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid)
{
    const std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    typedef typename UncertaintyEllipsoid::VerticalType ResultFromType;
    const ResultFromType result_from = obj->getVertical();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_vertical(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, const float p_vertical)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_vertical;
    typedef typename UncertaintyEllipsoid::VerticalType ValueType;

    ValueType value = value_from;
    if (!obj->setVertical(value)) return NULL;
    return obj_uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_vertical_move(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, float p_vertical)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_vertical;
    typedef typename UncertaintyEllipsoid::VerticalType ValueType;

    ValueType value = value_from;
    
    if (!obj->setVertical(std::move(value))) return NULL;
    return obj_uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_uncertainty_ellipsoid_get_orientation_major(const data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid)
{
    const std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    typedef typename UncertaintyEllipsoid::OrientationMajorType ResultFromType;
    const ResultFromType result_from = obj->getOrientationMajor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_orientation_major(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, const int32_t p_orientation_major)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_orientation_major;
    typedef typename UncertaintyEllipsoid::OrientationMajorType ValueType;

    ValueType value = value_from;
    if (!obj->setOrientationMajor(value)) return NULL;
    return obj_uncertainty_ellipsoid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_orientation_major_move(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid, int32_t p_orientation_major)
{
    if (obj_uncertainty_ellipsoid == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    const auto &value_from = p_orientation_major;
    typedef typename UncertaintyEllipsoid::OrientationMajorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setOrientationMajor(std::move(value))) return NULL;
    return obj_uncertainty_ellipsoid;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_uncertainty_ellipsoid_make_lnode(data_collection_model_uncertainty_ellipsoid_t *p_uncertainty_ellipsoid)
{
    return data_collection_lnode_create(p_uncertainty_ellipsoid, reinterpret_cast<void(*)(void*)>(data_collection_model_uncertainty_ellipsoid_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_uncertainty_ellipsoid_refcount(data_collection_model_uncertainty_ellipsoid_t *obj_uncertainty_ellipsoid)
{
    std::shared_ptr<UncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipsoid >*>(obj_uncertainty_ellipsoid);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

