/**********************************************************************************************************************************
 * Local2dPointUncertaintyEllipse_allOf - C interface to the Local2dPointUncertaintyEllipse_allOf object
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

/*#include "Local2dPointUncertaintyEllipse_allOf.h" already included by data-collection-sp/data-collection.h */
#include "Local2dPointUncertaintyEllipse_allOf-internal.h"
#include "openapi/model/Local2dPointUncertaintyEllipse_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_create(



)
{
    return reinterpret_cast<data_collection_model_local2d_point_uncertainty_ellipse_all_of_t*>(new std::shared_ptr<Local2dPointUncertaintyEllipse_allOf>(new Local2dPointUncertaintyEllipse_allOf(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_create_copy(const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_local2d_point_uncertainty_ellipse_all_of_t*>(new std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >(new Local2dPointUncertaintyEllipse_allOf(**reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_create_move(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_local2d_point_uncertainty_ellipse_all_of_t*>(new std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >(std::move(*reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_copy(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *local2d_point_uncertainty_ellipse_all_of, const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *other)
{
    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(local2d_point_uncertainty_ellipse_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(other);
    return local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_move(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *local2d_point_uncertainty_ellipse_all_of, data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *other)
{
    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(local2d_point_uncertainty_ellipse_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(other));
    return local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_local2d_point_uncertainty_ellipse_all_of_free(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *local2d_point_uncertainty_ellipse_all_of)
{
    delete reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(local2d_point_uncertainty_ellipse_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_local2d_point_uncertainty_ellipse_all_of_toJSON(const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *local2d_point_uncertainty_ellipse_all_of, bool as_request)
{
    const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(local2d_point_uncertainty_ellipse_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_local2d_point_uncertainty_ellipse_all_of_t*>(new std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >(new Local2dPointUncertaintyEllipse_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_local2d_point_uncertainty_ellipse_all_of_is_equal_to(const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *first, const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *second)
{
    const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(first);
    const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_local_origin_t* data_collection_model_local2d_point_uncertainty_ellipse_all_of_get_local_origin(const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of)
{
    const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    typedef typename Local2dPointUncertaintyEllipse_allOf::LocalOriginType ResultFromType;
    const ResultFromType result_from = obj->getLocalOrigin();
    const data_collection_model_local_origin_t *result = reinterpret_cast<const data_collection_model_local_origin_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_local_origin(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, const data_collection_model_local_origin_t* p_local_origin)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_local_origin;
    typedef typename Local2dPointUncertaintyEllipse_allOf::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocalOrigin(value)) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_local_origin_move(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, data_collection_model_local_origin_t* p_local_origin)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_local_origin;
    typedef typename Local2dPointUncertaintyEllipse_allOf::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocalOrigin(std::move(value))) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_relative_cartesian_location_t* data_collection_model_local2d_point_uncertainty_ellipse_all_of_get_point(const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of)
{
    const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    typedef typename Local2dPointUncertaintyEllipse_allOf::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_relative_cartesian_location_t *result = reinterpret_cast<const data_collection_model_relative_cartesian_location_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_point(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, const data_collection_model_relative_cartesian_location_t* p_point)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_point;
    typedef typename Local2dPointUncertaintyEllipse_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_point_move(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, data_collection_model_relative_cartesian_location_t* p_point)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_point;
    typedef typename Local2dPointUncertaintyEllipse_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_uncertainty_ellipse_t* data_collection_model_local2d_point_uncertainty_ellipse_all_of_get_uncertainty_ellipse(const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of)
{
    const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    typedef typename Local2dPointUncertaintyEllipse_allOf::UncertaintyEllipseType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyEllipse();
    const data_collection_model_uncertainty_ellipse_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipse_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_uncertainty_ellipse(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_uncertainty_ellipse;
    typedef typename Local2dPointUncertaintyEllipse_allOf::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUncertaintyEllipse(value)) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_uncertainty_ellipse_move(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_uncertainty_ellipse;
    typedef typename Local2dPointUncertaintyEllipse_allOf::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUncertaintyEllipse(std::move(value))) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_local2d_point_uncertainty_ellipse_all_of_get_confidence(const data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of)
{
    const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<const std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    typedef typename Local2dPointUncertaintyEllipse_allOf::ConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_confidence(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, const int32_t p_confidence)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_confidence;
    typedef typename Local2dPointUncertaintyEllipse_allOf::ConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setConfidence(value)) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_set_confidence_move(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of, int32_t p_confidence)
{
    if (obj_local2d_point_uncertainty_ellipse_all_of == NULL) return NULL;

    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    const auto &value_from = p_confidence;
    typedef typename Local2dPointUncertaintyEllipse_allOf::ConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setConfidence(std::move(value))) return NULL;
    return obj_local2d_point_uncertainty_ellipse_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_local2d_point_uncertainty_ellipse_all_of_make_lnode(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *p_local2d_point_uncertainty_ellipse_all_of)
{
    return data_collection_lnode_create(p_local2d_point_uncertainty_ellipse_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_local2d_point_uncertainty_ellipse_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_local2d_point_uncertainty_ellipse_all_of_refcount(data_collection_model_local2d_point_uncertainty_ellipse_all_of_t *obj_local2d_point_uncertainty_ellipse_all_of)
{
    std::shared_ptr<Local2dPointUncertaintyEllipse_allOf > &obj = *reinterpret_cast<std::shared_ptr<Local2dPointUncertaintyEllipse_allOf >*>(obj_local2d_point_uncertainty_ellipse_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

