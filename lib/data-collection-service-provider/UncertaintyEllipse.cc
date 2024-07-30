/**********************************************************************************************************************************
 * UncertaintyEllipse - C interface to the UncertaintyEllipse object
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

/*#include "UncertaintyEllipse.h" already included by data-collection-sp/data-collection.h */
#include "UncertaintyEllipse-internal.h"
#include "openapi/model/UncertaintyEllipse.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create(


)
{
    return reinterpret_cast<data_collection_model_uncertainty_ellipse_t*>(new std::shared_ptr<UncertaintyEllipse>(new UncertaintyEllipse(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create_copy(const data_collection_model_uncertainty_ellipse_t *other)
{
    return reinterpret_cast<data_collection_model_uncertainty_ellipse_t*>(new std::shared_ptr<UncertaintyEllipse >(new UncertaintyEllipse(**reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create_move(data_collection_model_uncertainty_ellipse_t *other)
{
    return reinterpret_cast<data_collection_model_uncertainty_ellipse_t*>(new std::shared_ptr<UncertaintyEllipse >(std::move(*reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_copy(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, const data_collection_model_uncertainty_ellipse_t *other)
{
    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
    *obj = **reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(other);
    return uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_move(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, data_collection_model_uncertainty_ellipse_t *other)
{
    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
    obj = std::move(*reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(other));
    return uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_uncertainty_ellipse_free(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse)
{
    delete reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_uncertainty_ellipse_toJSON(const data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, bool as_request)
{
    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_uncertainty_ellipse_t*>(new std::shared_ptr<UncertaintyEllipse >(new UncertaintyEllipse(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_uncertainty_ellipse_is_equal_to(const data_collection_model_uncertainty_ellipse_t *first, const data_collection_model_uncertainty_ellipse_t *second)
{
    const std::shared_ptr<UncertaintyEllipse > &obj1 = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(first);
    const std::shared_ptr<UncertaintyEllipse > &obj2 = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_uncertainty_ellipse_get_semi_major(const data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    typedef typename UncertaintyEllipse::SemiMajorType ResultFromType;
    const ResultFromType result_from = obj->getSemiMajor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_major(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, const float p_semi_major)
{
    if (obj_uncertainty_ellipse == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    const auto &value_from = p_semi_major;
    typedef typename UncertaintyEllipse::SemiMajorType ValueType;

    ValueType value = value_from;
    if (!obj->setSemiMajor(value)) return NULL;
    return obj_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_major_move(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, float p_semi_major)
{
    if (obj_uncertainty_ellipse == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    const auto &value_from = p_semi_major;
    typedef typename UncertaintyEllipse::SemiMajorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSemiMajor(std::move(value))) return NULL;
    return obj_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_uncertainty_ellipse_get_semi_minor(const data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    typedef typename UncertaintyEllipse::SemiMinorType ResultFromType;
    const ResultFromType result_from = obj->getSemiMinor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_minor(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, const float p_semi_minor)
{
    if (obj_uncertainty_ellipse == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    const auto &value_from = p_semi_minor;
    typedef typename UncertaintyEllipse::SemiMinorType ValueType;

    ValueType value = value_from;
    if (!obj->setSemiMinor(value)) return NULL;
    return obj_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_minor_move(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, float p_semi_minor)
{
    if (obj_uncertainty_ellipse == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    const auto &value_from = p_semi_minor;
    typedef typename UncertaintyEllipse::SemiMinorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSemiMinor(std::move(value))) return NULL;
    return obj_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_uncertainty_ellipse_get_orientation_major(const data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    typedef typename UncertaintyEllipse::OrientationMajorType ResultFromType;
    const ResultFromType result_from = obj->getOrientationMajor();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_orientation_major(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, const int32_t p_orientation_major)
{
    if (obj_uncertainty_ellipse == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    const auto &value_from = p_orientation_major;
    typedef typename UncertaintyEllipse::OrientationMajorType ValueType;

    ValueType value = value_from;
    if (!obj->setOrientationMajor(value)) return NULL;
    return obj_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_orientation_major_move(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, int32_t p_orientation_major)
{
    if (obj_uncertainty_ellipse == NULL) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    const auto &value_from = p_orientation_major;
    typedef typename UncertaintyEllipse::OrientationMajorType ValueType;

    ValueType value = value_from;
    
    if (!obj->setOrientationMajor(std::move(value))) return NULL;
    return obj_uncertainty_ellipse;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_uncertainty_ellipse_make_lnode(data_collection_model_uncertainty_ellipse_t *p_uncertainty_ellipse)
{
    return data_collection_lnode_create(p_uncertainty_ellipse, reinterpret_cast<void(*)(void*)>(data_collection_model_uncertainty_ellipse_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_uncertainty_ellipse_refcount(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

