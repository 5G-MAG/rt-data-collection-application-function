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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create(


)
{
    return reinterpret_cast<data_collection_model_point_uncertainty_circle_t*>(new std::shared_ptr<PointUncertaintyCircle>(new PointUncertaintyCircle(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_copy(const data_collection_model_point_uncertainty_circle_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_point_uncertainty_circle_t*>(new std::shared_ptr<PointUncertaintyCircle >(new PointUncertaintyCircle(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_create_move(data_collection_model_point_uncertainty_circle_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PointUncertaintyCircle > *obj = reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_copy(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, const data_collection_model_point_uncertainty_circle_t *other)
{
    if (point_uncertainty_circle) {
        std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
        if (obj) {
            if (other) {
                const std::shared_ptr<PointUncertaintyCircle > &other_obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(other);
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
                const std::shared_ptr<PointUncertaintyCircle > &other_obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(other);
                if (other_obj) {
                    obj.reset(new PointUncertaintyCircle(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        point_uncertainty_circle = data_collection_model_point_uncertainty_circle_create_copy(other);
    }
    return point_uncertainty_circle;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_move(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, data_collection_model_point_uncertainty_circle_t *other)
{
    std::shared_ptr<PointUncertaintyCircle > *other_ptr = reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(other);

    if (point_uncertainty_circle) {
        std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                point_uncertainty_circle = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return point_uncertainty_circle;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_uncertainty_circle_free(data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle)
{
    if (!point_uncertainty_circle) return;
    delete reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_uncertainty_circle_toJSON(const data_collection_model_point_uncertainty_circle_t *point_uncertainty_circle, bool as_request)
{
    if (!point_uncertainty_circle) return NULL;
    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(point_uncertainty_circle);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_uncertainty_circle_is_equal_to(const data_collection_model_point_uncertainty_circle_t *first, const data_collection_model_point_uncertainty_circle_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PointUncertaintyCircle > &obj2 = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PointUncertaintyCircle > &obj1 = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_uncertainty_circle_get_shape(const data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    if (!obj_point_uncertainty_circle) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename PointUncertaintyCircle::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_point_uncertainty_circle) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename PointUncertaintyCircle::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;

    return obj_point_uncertainty_circle;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_shape_move(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_point_uncertainty_circle) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename PointUncertaintyCircle::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;

    return obj_point_uncertainty_circle;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_uncertainty_circle_get_point(const data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    if (!obj_point_uncertainty_circle) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename PointUncertaintyCircle::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_uncertainty_circle) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointUncertaintyCircle::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;

    return obj_point_uncertainty_circle;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_point_move(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_uncertainty_circle) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointUncertaintyCircle::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;

    return obj_point_uncertainty_circle;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_point_uncertainty_circle_get_uncertainty(const data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    if (!obj_point_uncertainty_circle) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<const std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename PointUncertaintyCircle::UncertaintyType ResultFromType;
    const ResultFromType result_from = obj->getUncertainty();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, const float p_uncertainty)
{
    if (!obj_point_uncertainty_circle) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty;
    typedef typename PointUncertaintyCircle::UncertaintyType ValueType;

    ValueType value = value_from;
    if (!obj->setUncertainty(value)) return NULL;

    return obj_point_uncertainty_circle;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_uncertainty_circle_t *data_collection_model_point_uncertainty_circle_set_uncertainty_move(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle, float p_uncertainty)
{
    if (!obj_point_uncertainty_circle) return NULL;

    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty;
    typedef typename PointUncertaintyCircle::UncertaintyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUncertainty(std::move(value))) return NULL;

    return obj_point_uncertainty_circle;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_uncertainty_circle_make_lnode(data_collection_model_point_uncertainty_circle_t *p_point_uncertainty_circle)
{
    return data_collection_lnode_create(p_point_uncertainty_circle, reinterpret_cast<void(*)(void*)>(data_collection_model_point_uncertainty_circle_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_uncertainty_circle_refcount(data_collection_model_point_uncertainty_circle_t *obj_point_uncertainty_circle)
{
    if (!obj_point_uncertainty_circle) return 0l;
    std::shared_ptr<PointUncertaintyCircle > &obj = *reinterpret_cast<std::shared_ptr<PointUncertaintyCircle >*>(obj_point_uncertainty_circle);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

