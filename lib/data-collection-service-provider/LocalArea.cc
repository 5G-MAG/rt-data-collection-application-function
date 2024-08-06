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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_create(






)
{
    return reinterpret_cast<data_collection_model_local_area_t*>(new std::shared_ptr<LocalArea>(new LocalArea(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_create_copy(const data_collection_model_local_area_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_local_area_t*>(new std::shared_ptr<LocalArea >(new LocalArea(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_create_move(data_collection_model_local_area_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<LocalArea > *obj = reinterpret_cast<std::shared_ptr<LocalArea >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_copy(data_collection_model_local_area_t *local_area, const data_collection_model_local_area_t *other)
{
    if (local_area) {
        std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(local_area);
        if (obj) {
            if (other) {
                const std::shared_ptr<LocalArea > &other_obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(other);
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
                const std::shared_ptr<LocalArea > &other_obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(other);
                if (other_obj) {
                    obj.reset(new LocalArea(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        local_area = data_collection_model_local_area_create_copy(other);
    }
    return local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_move(data_collection_model_local_area_t *local_area, data_collection_model_local_area_t *other)
{
    std::shared_ptr<LocalArea > *other_ptr = reinterpret_cast<std::shared_ptr<LocalArea >*>(other);

    if (local_area) {
        std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(local_area);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                local_area = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local_area_free(data_collection_model_local_area_t *local_area)
{
    if (!local_area) return;
    delete reinterpret_cast<std::shared_ptr<LocalArea >*>(local_area);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local_area_toJSON(const data_collection_model_local_area_t *local_area, bool as_request)
{
    if (!local_area) return NULL;
    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(local_area);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_area_is_equal_to(const data_collection_model_local_area_t *first, const data_collection_model_local_area_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<LocalArea > &obj2 = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<LocalArea > &obj1 = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_local_area_get_shape(const data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename LocalArea::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_shape(data_collection_model_local_area_t *obj_local_area, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename LocalArea::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_shape_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename LocalArea::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_local_origin_t* data_collection_model_local_area_get_local_origin(const data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) {
        const data_collection_model_local_origin_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) {
        const data_collection_model_local_origin_t *result = NULL;
        return result;
    }

    typedef typename LocalArea::LocalOriginType ResultFromType;
    const ResultFromType result_from = obj->getLocalOrigin();
    const data_collection_model_local_origin_t *result = reinterpret_cast<const data_collection_model_local_origin_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_local_origin(data_collection_model_local_area_t *obj_local_area, const data_collection_model_local_origin_t* p_local_origin)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_local_origin;
    typedef typename LocalArea::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocalOrigin(value)) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_local_origin_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_local_origin_t* p_local_origin)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_local_origin;
    typedef typename LocalArea::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocalOrigin(std::move(value))) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_relative_cartesian_location_t* data_collection_model_local_area_get_point(const data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) {
        const data_collection_model_relative_cartesian_location_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) {
        const data_collection_model_relative_cartesian_location_t *result = NULL;
        return result;
    }

    typedef typename LocalArea::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_relative_cartesian_location_t *result = reinterpret_cast<const data_collection_model_relative_cartesian_location_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_point(data_collection_model_local_area_t *obj_local_area, const data_collection_model_relative_cartesian_location_t* p_point)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename LocalArea::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_point_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_relative_cartesian_location_t* p_point)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename LocalArea::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_local_area_get_uncertainty_ellipse(const data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    typedef typename LocalArea::UncertaintyEllipseType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyEllipse();
    const data_collection_model_uncertainty_ellipse_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipse_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipse(data_collection_model_local_area_t *obj_local_area, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename LocalArea::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUncertaintyEllipse(value)) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipse_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename LocalArea::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUncertaintyEllipse(std::move(value))) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local_area_get_confidence(const data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename LocalArea::ConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_confidence(data_collection_model_local_area_t *obj_local_area, const int32_t p_confidence)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename LocalArea::ConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setConfidence(value)) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_confidence_move(data_collection_model_local_area_t *obj_local_area, int32_t p_confidence)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename LocalArea::ConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipsoid_t* data_collection_model_local_area_get_uncertainty_ellipsoid(const data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) {
        const data_collection_model_uncertainty_ellipsoid_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) {
        const data_collection_model_uncertainty_ellipsoid_t *result = NULL;
        return result;
    }

    typedef typename LocalArea::UncertaintyEllipsoidType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyEllipsoid();
    const data_collection_model_uncertainty_ellipsoid_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipsoid_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipsoid(data_collection_model_local_area_t *obj_local_area, const data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipsoid;
    typedef typename LocalArea::UncertaintyEllipsoidType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUncertaintyEllipsoid(value)) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_uncertainty_ellipsoid_move(data_collection_model_local_area_t *obj_local_area, data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipsoid;
    typedef typename LocalArea::UncertaintyEllipsoidType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUncertaintyEllipsoid(std::move(value))) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local_area_get_v_confidence(const data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<LocalArea > &obj = *reinterpret_cast<const std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename LocalArea::VConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getVConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_v_confidence(data_collection_model_local_area_t *obj_local_area, const int32_t p_v_confidence)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename LocalArea::VConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setVConfidence(value)) return NULL;

    return obj_local_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_area_t *data_collection_model_local_area_set_v_confidence_move(data_collection_model_local_area_t *obj_local_area, int32_t p_v_confidence)
{
    if (!obj_local_area) return NULL;

    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename LocalArea::VConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setVConfidence(std::move(value))) return NULL;

    return obj_local_area;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local_area_make_lnode(data_collection_model_local_area_t *p_local_area)
{
    return data_collection_lnode_create(p_local_area, reinterpret_cast<void(*)(void*)>(data_collection_model_local_area_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_local_area_refcount(data_collection_model_local_area_t *obj_local_area)
{
    if (!obj_local_area) return 0l;
    std::shared_ptr<LocalArea > &obj = *reinterpret_cast<std::shared_ptr<LocalArea >*>(obj_local_area);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

