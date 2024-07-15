/**********************************************************************************************************************************
 * Polygon - C interface to the Polygon object
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

/*#include "Polygon.h" already included by data-collection-sp/data-collection.h */
#include "Polygon-internal.h"
#include "openapi/model/Polygon.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_create(

)
{
    return reinterpret_cast<data_collection_model_polygon_t*>(new std::shared_ptr<Polygon>(new Polygon(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_create_copy(const data_collection_model_polygon_t *other)
{
    return reinterpret_cast<data_collection_model_polygon_t*>(new std::shared_ptr<Polygon >(new Polygon(**reinterpret_cast<const std::shared_ptr<Polygon >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_create_move(data_collection_model_polygon_t *other)
{
    return reinterpret_cast<data_collection_model_polygon_t*>(new std::shared_ptr<Polygon >(std::move(*reinterpret_cast<std::shared_ptr<Polygon >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_copy(data_collection_model_polygon_t *polygon, const data_collection_model_polygon_t *other)
{
    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(polygon);
    *obj = **reinterpret_cast<const std::shared_ptr<Polygon >*>(other);
    return polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_move(data_collection_model_polygon_t *polygon, data_collection_model_polygon_t *other)
{
    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(polygon);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Polygon >*>(other));
    return polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_polygon_free(data_collection_model_polygon_t *polygon)
{
    delete reinterpret_cast<std::shared_ptr<Polygon >*>(polygon);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_polygon_toJSON(const data_collection_model_polygon_t *polygon, bool as_request)
{
    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(polygon);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_polygon_t*>(new std::shared_ptr<Polygon >(new Polygon(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_supported_gad_shapes_t* data_collection_model_polygon_get_shape(const data_collection_model_polygon_t *obj_polygon)
{
    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(obj_polygon);
    typedef typename Polygon::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_set_shape(data_collection_model_polygon_t *obj_polygon, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_polygon == NULL) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    const auto &value_from = p_shape;
    typedef typename Polygon::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;
    return obj_polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_set_shape_move(data_collection_model_polygon_t *obj_polygon, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_polygon == NULL) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    const auto &value_from = p_shape;
    typedef typename Polygon::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;
    return obj_polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_polygon_get_point_list(const data_collection_model_polygon_t *obj_polygon)
{
    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(obj_polygon);
    typedef typename Polygon::PointListType ResultFromType;
    const ResultFromType result_from = obj->getPointList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_geographical_coordinates_t *item_obj = reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates >(item));
        node = data_collection_model_geographical_coordinates_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_set_point_list(data_collection_model_polygon_t *obj_polygon, const ogs_list_t* p_point_list)
{
    if (obj_polygon == NULL) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    const auto &value_from = p_point_list;
    typedef typename Polygon::PointListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setPointList(value)) return NULL;
    return obj_polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_set_point_list_move(data_collection_model_polygon_t *obj_polygon, ogs_list_t* p_point_list)
{
    if (obj_polygon == NULL) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    const auto &value_from = p_point_list;
    typedef typename Polygon::PointListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_point_list);
    if (!obj->setPointList(std::move(value))) return NULL;
    return obj_polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_add_point_list(data_collection_model_polygon_t *obj_polygon, data_collection_model_geographical_coordinates_t* p_point_list)
{
    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    typedef typename Polygon::PointListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_point_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addPointList(value);
    return obj_polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_remove_point_list(data_collection_model_polygon_t *obj_polygon, const data_collection_model_geographical_coordinates_t* p_point_list)
{
    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    typedef typename Polygon::PointListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_point_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removePointList(value);
    return obj_polygon;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_polygon_t *data_collection_model_polygon_clear_point_list(data_collection_model_polygon_t *obj_polygon)
{   
    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    obj->clearPointList();
    return obj_polygon;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_polygon_make_lnode(data_collection_model_polygon_t *p_polygon)
{
    return data_collection_lnode_create(p_polygon, reinterpret_cast<void(*)(void*)>(data_collection_model_polygon_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_polygon_refcount(data_collection_model_polygon_t *obj_polygon)
{
    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

