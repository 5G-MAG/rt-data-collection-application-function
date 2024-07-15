/**********************************************************************************************************************************
 * LocalArea - C interface to the LocalArea object
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

/*#include "LocalArea.h" already included by data-collection-sp/data-collection.h */
#include "LocalArea-internal.h"
#include "openapi/model/LocalArea.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_create(





)
{
    return reinterpret_cast<data_collection_model_local_area_t*>(new std::shared_ptr<LocalArea>(new LocalArea(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_create_copy(const data_collection_model_local_area_t *other)
{
    return reinterpret_cast<data_collection_model_local_area_t*>(new std::shared_ptr<LocalArea >(new LocalArea(**reinterpret_cast<const std::shared_ptr<LocalArea >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_create_move(data_collection_model_local_area_t *other)
{
    return reinterpret_cast<data_collection_model_local_area_t*>(new std::shared_ptr<LocalArea >(std::move(*reinterpret_cast<std::shared_ptr<LocalArea >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_copy(data_collection_model_local_area_t *local_area, const data_collection_model_local_area_t *other)
{
    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(local_area);
    *obj = **reinterpret_cast<const std::shared_ptr<LocalArea >*>(other);
    return local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_move(data_collection_model_local_area_t *local_area, data_collection_model_local_area_t *other)
{
    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(local_area);
    obj = std::move(*reinterpret_cast<std::shared_ptr<LocalArea >*>(other));
    return local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_local_area_free(data_collection_model_local_area_t *local_area)
{
    delete reinterpret_cast<std::shared_ptr<LocalArea >*>(local_area);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_local_area_toJSON(const data_collection_model_local_area_t *local_area, bool as_request)
{
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(local_area);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_local_area_t*>(new std::shared_ptr<LocalArea >(new LocalArea(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_supported_gad_shapes_t* data_collection_model_local_area_get_shape(const data_collection_model_local_area_t *obj_local_area)
{
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    typedef typename LocalArea::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_shape(data_collection_model_local_area_t *obj_local_area, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_shape;
    typedef typename LocalArea::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_shape_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_shape;
    typedef typename LocalArea::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_local_origin_t* data_collection_model_local_area_get_local_origin(const data_collection_model_local_area_t *obj_local_area)
{
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    typedef typename LocalArea::LocalOriginType ResultFromType;
    const ResultFromType result_from = obj->getLocalOrigin();
    const data_collection_model_local_origin_t *result = reinterpret_cast<const data_collection_model_local_origin_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_local_origin(data_collection_model_local_area_t *obj_local_area, const data_collection_model_local_origin_t* p_local_origin)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_local_origin;
    typedef typename LocalArea::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocalOrigin(value)) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_local_origin_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_local_origin_t* p_local_origin)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_local_origin;
    typedef typename LocalArea::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocalOrigin(std::move(value))) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_relative_cartesian_location_t* data_collection_model_local_area_get_point(const data_collection_model_local_area_t *obj_local_area)
{
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    typedef typename LocalArea::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_relative_cartesian_location_t *result = reinterpret_cast<const data_collection_model_relative_cartesian_location_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_point(data_collection_model_local_area_t *obj_local_area, const data_collection_model_relative_cartesian_location_t* p_point)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_point;
    typedef typename LocalArea::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_point_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_relative_cartesian_location_t* p_point)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_point;
    typedef typename LocalArea::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_uncertainty_ellipse_t* data_collection_model_local_area_get_uncertainty_ellipse(const data_collection_model_local_area_t *obj_local_area)
{
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    typedef typename LocalArea::UncertaintyEllipseType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyEllipse();
    const data_collection_model_uncertainty_ellipse_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipse_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipse(data_collection_model_local_area_t *obj_local_area, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_uncertainty_ellipse;
    typedef typename LocalArea::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUncertaintyEllipse(value)) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipse_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_uncertainty_ellipse;
    typedef typename LocalArea::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUncertaintyEllipse(std::move(value))) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_local_area_get_confidence(const data_collection_model_local_area_t *obj_local_area)
{
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    typedef typename LocalArea::ConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_confidence(data_collection_model_local_area_t *obj_local_area, const int32_t p_confidence)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_confidence;
    typedef typename LocalArea::ConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setConfidence(value)) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_confidence_move(data_collection_model_local_area_t *obj_local_area, int32_t p_confidence)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_confidence;
    typedef typename LocalArea::ConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setConfidence(std::move(value))) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_uncertainty_ellipsoid_t* data_collection_model_local_area_get_uncertainty_ellipsoid(const data_collection_model_local_area_t *obj_local_area)
{
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    typedef typename LocalArea::UncertaintyEllipsoidType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyEllipsoid();
    const data_collection_model_uncertainty_ellipsoid_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipsoid_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipsoid(data_collection_model_local_area_t *obj_local_area, const data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_uncertainty_ellipsoid;
    typedef typename LocalArea::UncertaintyEllipsoidType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUncertaintyEllipsoid(value)) return NULL;
    return obj_local_area;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipsoid_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid)
{
    if (obj_local_area == NULL) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    const auto &value_from = p_uncertainty_ellipsoid;
    typedef typename LocalArea::UncertaintyEllipsoidType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUncertaintyEllipsoid(std::move(value))) return NULL;
    return obj_local_area;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_local_area_make_lnode(data_collection_model_local_area_t *p_local_area)
{
    return data_collection_lnode_create(p_local_area, reinterpret_cast<void(*)(void*)>(data_collection_model_local_area_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_local_area_refcount(data_collection_model_local_area_t *obj_local_area)
{
    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

