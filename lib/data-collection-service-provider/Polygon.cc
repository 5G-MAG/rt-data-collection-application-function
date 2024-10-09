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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_create(

)
{
    return reinterpret_cast<data_collection_model_polygon_t*>(new std::shared_ptr<Polygon>(new Polygon(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_create_copy(const data_collection_model_polygon_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_polygon_t*>(new std::shared_ptr<Polygon >(new Polygon(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_create_move(data_collection_model_polygon_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Polygon > *obj = reinterpret_cast<std::shared_ptr<Polygon >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_copy(data_collection_model_polygon_t *polygon, const data_collection_model_polygon_t *other)
{
    if (polygon) {
        std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(polygon);
        if (obj) {
            if (other) {
                const std::shared_ptr<Polygon > &other_obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(other);
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
                const std::shared_ptr<Polygon > &other_obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(other);
                if (other_obj) {
                    obj.reset(new Polygon(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        polygon = data_collection_model_polygon_create_copy(other);
    }
    return polygon;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_move(data_collection_model_polygon_t *polygon, data_collection_model_polygon_t *other)
{
    std::shared_ptr<Polygon > *other_ptr = reinterpret_cast<std::shared_ptr<Polygon >*>(other);

    if (polygon) {
        std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(polygon);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                polygon = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return polygon;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_polygon_free(data_collection_model_polygon_t *polygon)
{
    if (!polygon) return;
    delete reinterpret_cast<std::shared_ptr<Polygon >*>(polygon);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_polygon_toJSON(const data_collection_model_polygon_t *polygon, bool as_request)
{
    if (!polygon) return NULL;
    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(polygon);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_polygon_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_polygon_is_equal_to(const data_collection_model_polygon_t *first, const data_collection_model_polygon_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Polygon > &obj2 = *reinterpret_cast<const std::shared_ptr<Polygon >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Polygon > &obj1 = *reinterpret_cast<const std::shared_ptr<Polygon >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_polygon_get_shape(const data_collection_model_polygon_t *obj_polygon)
{
    if (!obj_polygon) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename Polygon::ShapeType ResultFromType;
    const ResultFromType &result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_shape(data_collection_model_polygon_t *obj_polygon, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_polygon) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename Polygon::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setShape(value)) return NULL;

    return obj_polygon;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_shape_move(data_collection_model_polygon_t *obj_polygon, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_polygon) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename Polygon::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setShape(std::move(value))) return NULL;

    return obj_polygon;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_polygon_get_point_list(const data_collection_model_polygon_t *obj_polygon)
{
    if (!obj_polygon) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename Polygon::PointListType ResultFromType;
    const ResultFromType &result_from = obj->getPointList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_geographical_coordinates_t *item_obj = reinterpret_cast<data_collection_model_geographical_coordinates_t*>(item.has_value()?new std::shared_ptr<GeographicalCoordinates >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_geographical_coordinates_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_point_list(data_collection_model_polygon_t *obj_polygon, const ogs_list_t* p_point_list)
{
    if (!obj_polygon) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) return NULL;

    const auto &value_from = p_point_list;
    typedef typename Polygon::PointListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setPointList(value)) return NULL;

    return obj_polygon;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_set_point_list_move(data_collection_model_polygon_t *obj_polygon, ogs_list_t* p_point_list)
{
    if (!obj_polygon) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) return NULL;

    const auto &value_from = p_point_list;
    typedef typename Polygon::PointListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_point_list);
    if (!obj->setPointList(std::move(value))) return NULL;

    return obj_polygon;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_add_point_list(data_collection_model_polygon_t *obj_polygon, data_collection_model_geographical_coordinates_t* p_point_list)
{
    if (!obj_polygon) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) return NULL;

    typedef typename Polygon::PointListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_point_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    obj->addPointList(value);
    return obj_polygon;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_remove_point_list(data_collection_model_polygon_t *obj_polygon, const data_collection_model_geographical_coordinates_t* p_point_list)
{
    if (!obj_polygon) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) return NULL;

    typedef typename Polygon::PointListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_point_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removePointList(value);
    return obj_polygon;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_polygon_get_entry_point_list(const data_collection_model_polygon_t *obj_polygon, size_t idx)
{
    if (!obj_polygon) {
        const data_collection_model_geographical_coordinates_t *result = NULL;

        return result;
    }

    const std::shared_ptr<Polygon > &obj = *reinterpret_cast<const std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;

        return result;
    }

    const Polygon::PointListType &container = obj->getPointList();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_geographical_coordinates_t *result = NULL;

        return result;
    }
    typedef typename Polygon::PointListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_polygon_t *data_collection_model_polygon_clear_point_list(data_collection_model_polygon_t *obj_polygon)
{
    if (!obj_polygon) return NULL;

    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    if (!obj) return NULL;

    obj->clearPointList();
    return obj_polygon;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_polygon_make_lnode(data_collection_model_polygon_t *p_polygon)
{
    return data_collection_lnode_create(p_polygon, reinterpret_cast<void(*)(void*)>(data_collection_model_polygon_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_polygon_refcount(data_collection_model_polygon_t *obj_polygon)
{
    if (!obj_polygon) return 0l;
    std::shared_ptr<Polygon > &obj = *reinterpret_cast<std::shared_ptr<Polygon >*>(obj_polygon);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

