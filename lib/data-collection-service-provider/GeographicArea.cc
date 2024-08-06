/**********************************************************************************************************************************
 * GeographicArea - C interface to the GeographicArea object
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

/*#include "GeographicArea.h" already included by data-collection-sp/data-collection.h */
#include "GeographicArea-internal.h"
#include "openapi/model/GeographicArea.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create(












)
{
    return reinterpret_cast<data_collection_model_geographic_area_t*>(new std::shared_ptr<GeographicArea>(new GeographicArea(












)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create_copy(const data_collection_model_geographic_area_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_geographic_area_t*>(new std::shared_ptr<GeographicArea >(new GeographicArea(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_create_move(data_collection_model_geographic_area_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GeographicArea > *obj = reinterpret_cast<std::shared_ptr<GeographicArea >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_copy(data_collection_model_geographic_area_t *geographic_area, const data_collection_model_geographic_area_t *other)
{
    if (geographic_area) {
        std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(geographic_area);
        if (obj) {
            if (other) {
                const std::shared_ptr<GeographicArea > &other_obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(other);
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
                const std::shared_ptr<GeographicArea > &other_obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(other);
                if (other_obj) {
                    obj.reset(new GeographicArea(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        geographic_area = data_collection_model_geographic_area_create_copy(other);
    }
    return geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_move(data_collection_model_geographic_area_t *geographic_area, data_collection_model_geographic_area_t *other)
{
    std::shared_ptr<GeographicArea > *other_ptr = reinterpret_cast<std::shared_ptr<GeographicArea >*>(other);

    if (geographic_area) {
        std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(geographic_area);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                geographic_area = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_geographic_area_free(data_collection_model_geographic_area_t *geographic_area)
{
    if (!geographic_area) return;
    delete reinterpret_cast<std::shared_ptr<GeographicArea >*>(geographic_area);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_geographic_area_toJSON(const data_collection_model_geographic_area_t *geographic_area, bool as_request)
{
    if (!geographic_area) return NULL;
    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(geographic_area);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_geographic_area_t*>(new std::shared_ptr<GeographicArea >(new GeographicArea(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_geographic_area_is_equal_to(const data_collection_model_geographic_area_t *first, const data_collection_model_geographic_area_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GeographicArea > &obj2 = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GeographicArea > &obj1 = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_geographic_area_get_shape(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename GeographicArea::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_shape(data_collection_model_geographic_area_t *obj_geographic_area, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename GeographicArea::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_shape_move(data_collection_model_geographic_area_t *obj_geographic_area, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename GeographicArea::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_geographic_area_get_point(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename GeographicArea::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point(data_collection_model_geographic_area_t *obj_geographic_area, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename GeographicArea::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_move(data_collection_model_geographic_area_t *obj_geographic_area, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename GeographicArea::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename GeographicArea::UncertaintyType ResultFromType;
    const ResultFromType result_from = obj->getUncertainty();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty(data_collection_model_geographic_area_t *obj_geographic_area, const float p_uncertainty)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty;
    typedef typename GeographicArea::UncertaintyType ValueType;

    ValueType value = value_from;
    if (!obj->setUncertainty(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_move(data_collection_model_geographic_area_t *obj_geographic_area, float p_uncertainty)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty;
    typedef typename GeographicArea::UncertaintyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUncertainty(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_geographic_area_get_uncertainty_ellipse(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    typedef typename GeographicArea::UncertaintyEllipseType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyEllipse();
    const data_collection_model_uncertainty_ellipse_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipse_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_ellipse(data_collection_model_geographic_area_t *obj_geographic_area, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename GeographicArea::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUncertaintyEllipse(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_ellipse_move(data_collection_model_geographic_area_t *obj_geographic_area, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename GeographicArea::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUncertaintyEllipse(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_confidence(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename GeographicArea::ConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_confidence(data_collection_model_geographic_area_t *obj_geographic_area, const int32_t p_confidence)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename GeographicArea::ConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setConfidence(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_confidence_move(data_collection_model_geographic_area_t *obj_geographic_area, int32_t p_confidence)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename GeographicArea::ConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_geographic_area_get_point_list(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename GeographicArea::PointListType ResultFromType;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_list(data_collection_model_geographic_area_t *obj_geographic_area, const ogs_list_t* p_point_list)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_point_list;
    typedef typename GeographicArea::PointListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setPointList(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_point_list_move(data_collection_model_geographic_area_t *obj_geographic_area, ogs_list_t* p_point_list)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_point_list;
    typedef typename GeographicArea::PointListType ValueType;

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

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_add_point_list(data_collection_model_geographic_area_t *obj_geographic_area, data_collection_model_geographical_coordinates_t* p_point_list)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    typedef typename GeographicArea::PointListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_point_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addPointList(value);
    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_remove_point_list(data_collection_model_geographic_area_t *obj_geographic_area, const data_collection_model_geographical_coordinates_t* p_point_list)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    typedef typename GeographicArea::PointListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_point_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removePointList(value);
    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_clear_point_list(data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    obj->clearPointList();
    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographic_area_get_altitude(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename GeographicArea::AltitudeType ResultFromType;
    const ResultFromType result_from = obj->getAltitude();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_altitude(data_collection_model_geographic_area_t *obj_geographic_area, const double p_altitude)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename GeographicArea::AltitudeType ValueType;

    ValueType value = value_from;
    if (!obj->setAltitude(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_altitude_move(data_collection_model_geographic_area_t *obj_geographic_area, double p_altitude)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename GeographicArea::AltitudeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAltitude(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty_altitude(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename GeographicArea::UncertaintyAltitudeType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyAltitude();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_altitude(data_collection_model_geographic_area_t *obj_geographic_area, const float p_uncertainty_altitude)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_altitude;
    typedef typename GeographicArea::UncertaintyAltitudeType ValueType;

    ValueType value = value_from;
    if (!obj->setUncertaintyAltitude(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_altitude_move(data_collection_model_geographic_area_t *obj_geographic_area, float p_uncertainty_altitude)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_altitude;
    typedef typename GeographicArea::UncertaintyAltitudeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUncertaintyAltitude(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_v_confidence(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename GeographicArea::VConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getVConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_v_confidence(data_collection_model_geographic_area_t *obj_geographic_area, const int32_t p_v_confidence)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename GeographicArea::VConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setVConfidence(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_v_confidence_move(data_collection_model_geographic_area_t *obj_geographic_area, int32_t p_v_confidence)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename GeographicArea::VConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setVConfidence(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_inner_radius(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename GeographicArea::InnerRadiusType ResultFromType;
    const ResultFromType result_from = obj->getInnerRadius();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_inner_radius(data_collection_model_geographic_area_t *obj_geographic_area, const int32_t p_inner_radius)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_inner_radius;
    typedef typename GeographicArea::InnerRadiusType ValueType;

    ValueType value = value_from;
    if (!obj->setInnerRadius(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_inner_radius_move(data_collection_model_geographic_area_t *obj_geographic_area, int32_t p_inner_radius)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_inner_radius;
    typedef typename GeographicArea::InnerRadiusType ValueType;

    ValueType value = value_from;
    
    if (!obj->setInnerRadius(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_geographic_area_get_uncertainty_radius(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename GeographicArea::UncertaintyRadiusType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyRadius();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_radius(data_collection_model_geographic_area_t *obj_geographic_area, const float p_uncertainty_radius)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_radius;
    typedef typename GeographicArea::UncertaintyRadiusType ValueType;

    ValueType value = value_from;
    if (!obj->setUncertaintyRadius(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_uncertainty_radius_move(data_collection_model_geographic_area_t *obj_geographic_area, float p_uncertainty_radius)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_radius;
    typedef typename GeographicArea::UncertaintyRadiusType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUncertaintyRadius(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_offset_angle(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename GeographicArea::OffsetAngleType ResultFromType;
    const ResultFromType result_from = obj->getOffsetAngle();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_offset_angle(data_collection_model_geographic_area_t *obj_geographic_area, const int32_t p_offset_angle)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_offset_angle;
    typedef typename GeographicArea::OffsetAngleType ValueType;

    ValueType value = value_from;
    if (!obj->setOffsetAngle(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_offset_angle_move(data_collection_model_geographic_area_t *obj_geographic_area, int32_t p_offset_angle)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_offset_angle;
    typedef typename GeographicArea::OffsetAngleType ValueType;

    ValueType value = value_from;
    
    if (!obj->setOffsetAngle(std::move(value))) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_geographic_area_get_included_angle(const data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<const std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename GeographicArea::IncludedAngleType ResultFromType;
    const ResultFromType result_from = obj->getIncludedAngle();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_included_angle(data_collection_model_geographic_area_t *obj_geographic_area, const int32_t p_included_angle)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_included_angle;
    typedef typename GeographicArea::IncludedAngleType ValueType;

    ValueType value = value_from;
    if (!obj->setIncludedAngle(value)) return NULL;

    return obj_geographic_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographic_area_t *data_collection_model_geographic_area_set_included_angle_move(data_collection_model_geographic_area_t *obj_geographic_area, int32_t p_included_angle)
{
    if (!obj_geographic_area) return NULL;

    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    if (!obj) return NULL;

    const auto &value_from = p_included_angle;
    typedef typename GeographicArea::IncludedAngleType ValueType;

    ValueType value = value_from;
    
    if (!obj->setIncludedAngle(std::move(value))) return NULL;

    return obj_geographic_area;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_geographic_area_make_lnode(data_collection_model_geographic_area_t *p_geographic_area)
{
    return data_collection_lnode_create(p_geographic_area, reinterpret_cast<void(*)(void*)>(data_collection_model_geographic_area_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_geographic_area_refcount(data_collection_model_geographic_area_t *obj_geographic_area)
{
    if (!obj_geographic_area) return 0l;
    std::shared_ptr<GeographicArea > &obj = *reinterpret_cast<std::shared_ptr<GeographicArea >*>(obj_geographic_area);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

