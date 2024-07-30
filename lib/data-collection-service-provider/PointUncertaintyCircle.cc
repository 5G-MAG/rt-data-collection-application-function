/**********************************************************************************************************************************
 * PointUncertaintyCircle - C interface to the PointUncertaintyCircle object
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

/*#include "PointUncertaintyCircle.h" already included by data-collection-sp/data-collection.h */
#include "PointUncertaintyCircle-internal.h"
#include "openapi/model/PointUncertaintyCircle.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create(


)
{
    return reinterpret_cast<data_collection_model_point_uncertainty_circle_t*>(new std::shared_ptr<PointUncertaintyCircle>(new PointUncertaintyCircle(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_copy(const data_collection_model_point_uncertainty_circle_t *other)
{
    return reinterpret_cast<data_collection_model_point_uncertainty_circle_t*>(new std::shared_ptr<PointUncertaintyCircle >(new PointUncertaintyCircle(**reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_move(data_collection_model_point_uncertainty_circle_t *other)
{
    return reinterpret_cast<data_collection_model_point_uncertainty_circle_t*>(new std::shared_ptr<PointUncertaintyCircle >(std::move(*reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_copy(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_point_uncertainty_circle_t *other)
{
    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
    *obj = **reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(other);
    return point_uncertainty_circle;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_point_uncertainty_circle_t *other)
{
    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(other));
    return point_uncertainty_circle;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_point_uncertainty_circle_free(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle)
{
    delete reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_point_uncertainty_circle_toJSON(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, bool as_request)
{
    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_point_uncertainty_circle_t*>(new std::shared_ptr<PointUncertaintyCircle >(new PointUncertaintyCircle(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_point_uncertainty_circle_is_equal_to(const data_collection_model_point_uncertainty_circle_t *first, const data_collection_model_point_uncertainty_circle_t *second)
{
    const std::shared_ptr<PointUncertaintyCircle > &obj1 = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(first);
    const std::shared_ptr<PointUncertaintyCircle > &obj2 = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_supported_gad_shapes_t* data_collection_model_point_uncertainty_circle_get_shape(const data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    typedef typename PointUncertaintyCircle::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_point_uncertainty_circle == NULL) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    const auto &value_from = p_shape;
    typedef typename PointUncertaintyCircle::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;
    return obj_point_uncertainty_circle;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape_move(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_point_uncertainty_circle == NULL) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    const auto &value_from = p_shape;
    typedef typename PointUncertaintyCircle::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;
    return obj_point_uncertainty_circle;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_point_uncertainty_circle_get_point(const data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    typedef typename PointUncertaintyCircle::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point_uncertainty_circle == NULL) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    const auto &value_from = p_point;
    typedef typename PointUncertaintyCircle::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;
    return obj_point_uncertainty_circle;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point_move(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point_uncertainty_circle == NULL) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    const auto &value_from = p_point;
    typedef typename PointUncertaintyCircle::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;
    return obj_point_uncertainty_circle;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_point_uncertainty_circle_get_uncertainty(const data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    typedef typename PointUncertaintyCircle::UncertaintyType ResultFromType;
    const ResultFromType result_from = obj->getUncertainty();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, const float p_uncertainty)
{
    if (obj_point_uncertainty_circle == NULL) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    const auto &value_from = p_uncertainty;
    typedef typename PointUncertaintyCircle::UncertaintyType ValueType;

    ValueType value = value_from;
    if (!obj->setUncertainty(value)) return NULL;
    return obj_point_uncertainty_circle;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty_move(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, float p_uncertainty)
{
    if (obj_point_uncertainty_circle == NULL) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    const auto &value_from = p_uncertainty;
    typedef typename PointUncertaintyCircle::UncertaintyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUncertainty(std::move(value))) return NULL;
    return obj_point_uncertainty_circle;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_point_uncertainty_circle_make_lnode(data_collection_model_point_uncertainty_circle_t *p_point_uncertainty_circle)
{
    return data_collection_lnode_create(p_point_uncertainty_circle, reinterpret_cast<void(*)(void*)>(data_collection_model_point_uncertainty_circle_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_uncertainty_circle_refcount(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

