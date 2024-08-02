/**********************************************************************************************************************************
 * PointUncertaintyEllipse - C interface to the PointUncertaintyEllipse object
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

/*#include "PointUncertaintyEllipse.h" already included by data-collection-sp/data-collection.h */
#include "PointUncertaintyEllipse-internal.h"
#include "openapi/model/PointUncertaintyEllipse.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_create(



)
{
    return reinterpret_cast<data_collection_model_point_uncertainty_ellipse_t*>(new std::shared_ptr<PointUncertaintyEllipse>(new PointUncertaintyEllipse(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_create_copy(const data_collection_model_point_uncertainty_ellipse_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_point_uncertainty_ellipse_t*>(new std::shared_ptr<PointUncertaintyEllipse >(new PointUncertaintyEllipse(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_create_move(data_collection_model_point_uncertainty_ellipse_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > *obj = reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_copy(data_collection_model_point_uncertainty_ellipse_t *point_uncertainty_ellipse, const data_collection_model_point_uncertainty_ellipse_t *other)
{
    if (point_uncertainty_ellipse) {
        std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(point_uncertainty_ellipse);
        if (obj) {
            if (other) {
                const std::shared_ptr<PointUncertaintyEllipse > &other_obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(other);
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
                const std::shared_ptr<PointUncertaintyEllipse > &other_obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(other);
                if (other_obj) {
                    obj.reset(new PointUncertaintyEllipse(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        point_uncertainty_ellipse = data_collection_model_point_uncertainty_ellipse_create_copy(other);
    }
    return point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_move(data_collection_model_point_uncertainty_ellipse_t *point_uncertainty_ellipse, data_collection_model_point_uncertainty_ellipse_t *other)
{
    std::shared_ptr<PointUncertaintyEllipse > *other_ptr = reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(other);

    if (point_uncertainty_ellipse) {
        std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(point_uncertainty_ellipse);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                point_uncertainty_ellipse = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_point_uncertainty_ellipse_free(data_collection_model_point_uncertainty_ellipse_t *point_uncertainty_ellipse)
{
    if (!point_uncertainty_ellipse) return;
    delete reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(point_uncertainty_ellipse);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_point_uncertainty_ellipse_toJSON(const data_collection_model_point_uncertainty_ellipse_t *point_uncertainty_ellipse, bool as_request)
{
    if (!point_uncertainty_ellipse) return NULL;
    const std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(point_uncertainty_ellipse);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_point_uncertainty_ellipse_t*>(new std::shared_ptr<PointUncertaintyEllipse >(new PointUncertaintyEllipse(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_point_uncertainty_ellipse_is_equal_to(const data_collection_model_point_uncertainty_ellipse_t *first, const data_collection_model_point_uncertainty_ellipse_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PointUncertaintyEllipse > &obj2 = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PointUncertaintyEllipse > &obj1 = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_supported_gad_shapes_t* data_collection_model_point_uncertainty_ellipse_get_shape(const data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse)
{
    if (!obj_point_uncertainty_ellipse) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename PointUncertaintyEllipse::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_shape(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename PointUncertaintyEllipse::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;

    return obj_point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_shape_move(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename PointUncertaintyEllipse::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;

    return obj_point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_point_uncertainty_ellipse_get_point(const data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse)
{
    if (!obj_point_uncertainty_ellipse) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename PointUncertaintyEllipse::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_point(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointUncertaintyEllipse::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;

    return obj_point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_point_move(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointUncertaintyEllipse::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;

    return obj_point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_uncertainty_ellipse_t* data_collection_model_point_uncertainty_ellipse_get_uncertainty_ellipse(const data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse)
{
    if (!obj_point_uncertainty_ellipse) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    typedef typename PointUncertaintyEllipse::UncertaintyEllipseType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyEllipse();
    const data_collection_model_uncertainty_ellipse_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipse_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_uncertainty_ellipse(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename PointUncertaintyEllipse::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUncertaintyEllipse(value)) return NULL;

    return obj_point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_uncertainty_ellipse_move(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename PointUncertaintyEllipse::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUncertaintyEllipse(std::move(value))) return NULL;

    return obj_point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_point_uncertainty_ellipse_get_confidence(const data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse)
{
    if (!obj_point_uncertainty_ellipse) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PointUncertaintyEllipse::ConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_confidence(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, const int32_t p_confidence)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename PointUncertaintyEllipse::ConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setConfidence(value)) return NULL;

    return obj_point_uncertainty_ellipse;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_uncertainty_ellipse_t *data_collection_model_point_uncertainty_ellipse_set_confidence_move(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse, int32_t p_confidence)
{
    if (!obj_point_uncertainty_ellipse) return NULL;

    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename PointUncertaintyEllipse::ConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_point_uncertainty_ellipse;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_point_uncertainty_ellipse_make_lnode(data_collection_model_point_uncertainty_ellipse_t *p_point_uncertainty_ellipse)
{
    return data_collection_lnode_create(p_point_uncertainty_ellipse, reinterpret_cast<void(*)(void*)>(data_collection_model_point_uncertainty_ellipse_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_uncertainty_ellipse_refcount(data_collection_model_point_uncertainty_ellipse_t *obj_point_uncertainty_ellipse)
{
    if (!obj_point_uncertainty_ellipse) return 0l;
    std::shared_ptr<PointUncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyEllipse >*>(obj_point_uncertainty_ellipse);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

