/**********************************************************************************************************************************
 * Point - C interface to the Point object
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

/*#include "Point.h" already included by data-collection-sp/data-collection.h */
#include "Point-internal.h"
#include "openapi/model/Point.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_create(

)
{
    return reinterpret_cast<data_collection_model_point_t*>(new std::shared_ptr<Point>(new Point(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_create_copy(const data_collection_model_point_t *other)
{
    return reinterpret_cast<data_collection_model_point_t*>(new std::shared_ptr<Point >(new Point(**reinterpret_cast<const std::shared_ptr<Point >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_create_move(data_collection_model_point_t *other)
{
    return reinterpret_cast<data_collection_model_point_t*>(new std::shared_ptr<Point >(std::move(*reinterpret_cast<std::shared_ptr<Point >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_copy(data_collection_model_point_t *point, const data_collection_model_point_t *other)
{
    std::shared_ptr<Point > &obj = *reinterpret_cast<std::shared_ptr<Point >*>(point);
    *obj = **reinterpret_cast<const std::shared_ptr<Point >*>(other);
    return point;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_move(data_collection_model_point_t *point, data_collection_model_point_t *other)
{
    std::shared_ptr<Point > &obj = *reinterpret_cast<std::shared_ptr<Point >*>(point);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Point >*>(other));
    return point;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_point_free(data_collection_model_point_t *point)
{
    delete reinterpret_cast<std::shared_ptr<Point >*>(point);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_point_toJSON(const data_collection_model_point_t *point, bool as_request)
{
    const std::shared_ptr<Point > &obj = *reinterpret_cast<const std::shared_ptr<Point >*>(point);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_point_t*>(new std::shared_ptr<Point >(new Point(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_point_is_equal_to(const data_collection_model_point_t *first, const data_collection_model_point_t *second)
{
    const std::shared_ptr<Point > &obj1 = *reinterpret_cast<const std::shared_ptr<Point >*>(first);
    const std::shared_ptr<Point > &obj2 = *reinterpret_cast<const std::shared_ptr<Point >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_supported_gad_shapes_t* data_collection_model_point_get_shape(const data_collection_model_point_t *obj_point)
{
    const std::shared_ptr<Point > &obj = *reinterpret_cast<const std::shared_ptr<Point >*>(obj_point);
    typedef typename Point::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_set_shape(data_collection_model_point_t *obj_point, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_point == NULL) return NULL;

    std::shared_ptr<Point > &obj = *reinterpret_cast<std::shared_ptr<Point >*>(obj_point);
    const auto &value_from = p_shape;
    typedef typename Point::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;
    return obj_point;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_set_shape_move(data_collection_model_point_t *obj_point, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_point == NULL) return NULL;

    std::shared_ptr<Point > &obj = *reinterpret_cast<std::shared_ptr<Point >*>(obj_point);
    const auto &value_from = p_shape;
    typedef typename Point::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;
    return obj_point;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_point_get_point(const data_collection_model_point_t *obj_point)
{
    const std::shared_ptr<Point > &obj = *reinterpret_cast<const std::shared_ptr<Point >*>(obj_point);
    typedef typename Point::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_set_point(data_collection_model_point_t *obj_point, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point == NULL) return NULL;

    std::shared_ptr<Point > &obj = *reinterpret_cast<std::shared_ptr<Point >*>(obj_point);
    const auto &value_from = p_point;
    typedef typename Point::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;
    return obj_point;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_t *data_collection_model_point_set_point_move(data_collection_model_point_t *obj_point, data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point == NULL) return NULL;

    std::shared_ptr<Point > &obj = *reinterpret_cast<std::shared_ptr<Point >*>(obj_point);
    const auto &value_from = p_point;
    typedef typename Point::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;
    return obj_point;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_point_make_lnode(data_collection_model_point_t *p_point)
{
    return data_collection_lnode_create(p_point, reinterpret_cast<void(*)(void*)>(data_collection_model_point_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_refcount(data_collection_model_point_t *obj_point)
{
    std::shared_ptr<Point > &obj = *reinterpret_cast<std::shared_ptr<Point >*>(obj_point);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

