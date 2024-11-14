/**********************************************************************************************************************************
 * EllipsoidArc - C interface to the EllipsoidArc object
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

/*#include "EllipsoidArc.h" already included by data-collection-sp/data-collection.h */
#include "EllipsoidArc-internal.h"
#include "openapi/model/EllipsoidArc.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create(






)
{
    return reinterpret_cast<data_collection_model_ellipsoid_arc_t*>(new std::shared_ptr<EllipsoidArc>(new EllipsoidArc(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_ref(const data_collection_model_ellipsoid_arc_t *other)
{
    return reinterpret_cast<data_collection_model_ellipsoid_arc_t*>(new std::shared_ptr<EllipsoidArc>(*reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_copy(const data_collection_model_ellipsoid_arc_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ellipsoid_arc_t*>(new std::shared_ptr<EllipsoidArc >(new EllipsoidArc(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_create_move(data_collection_model_ellipsoid_arc_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<EllipsoidArc > *obj = reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_copy(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, const data_collection_model_ellipsoid_arc_t *other)
{
    if (ellipsoid_arc) {
        std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(ellipsoid_arc);
        if (obj) {
            if (other) {
                const std::shared_ptr<EllipsoidArc > &other_obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(other);
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
                const std::shared_ptr<EllipsoidArc > &other_obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(other);
                if (other_obj) {
                    obj.reset(new EllipsoidArc(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ellipsoid_arc = data_collection_model_ellipsoid_arc_create_copy(other);
    }
    return ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_move(data_collection_model_ellipsoid_arc_t *ellipsoid_arc, data_collection_model_ellipsoid_arc_t *other)
{
    std::shared_ptr<EllipsoidArc > *other_ptr = reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(other);

    if (ellipsoid_arc) {
        std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(ellipsoid_arc);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ellipsoid_arc = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ellipsoid_arc_free(data_collection_model_ellipsoid_arc_t *ellipsoid_arc)
{
    if (!ellipsoid_arc) return;
    delete reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(ellipsoid_arc);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ellipsoid_arc_toJSON(const data_collection_model_ellipsoid_arc_t *ellipsoid_arc, bool as_request)
{
    if (!ellipsoid_arc) return NULL;
    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(ellipsoid_arc);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_ellipsoid_arc_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ellipsoid_arc_t*>(new std::shared_ptr<EllipsoidArc >(new EllipsoidArc(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ellipsoid_arc_is_equal_to(const data_collection_model_ellipsoid_arc_t *first, const data_collection_model_ellipsoid_arc_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<EllipsoidArc > &obj2 = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<EllipsoidArc > &obj1 = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_ellipsoid_arc_get_shape(const data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename EllipsoidArc::ShapeType ResultFromType;
    const ResultFromType &result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_shape(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename EllipsoidArc::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setShape(value)) return NULL;

    return obj_ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_shape_move(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename EllipsoidArc::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setShape(std::move(value))) return NULL;
    data_collection_model_supported_gad_shapes_free
(p_shape);

    return obj_ellipsoid_arc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_ellipsoid_arc_get_point(const data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename EllipsoidArc::PointType ResultFromType;
    const ResultFromType &result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_point(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename EllipsoidArc::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPoint(value)) return NULL;

    return obj_ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_point_move(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename EllipsoidArc::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPoint(std::move(value))) return NULL;
    data_collection_model_geographical_coordinates_free
(p_point);

    return obj_ellipsoid_arc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_inner_radius(const data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc::InnerRadiusType ResultFromType;
    const ResultFromType &result_from = obj->getInnerRadius();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_inner_radius(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, const int32_t p_inner_radius)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_inner_radius;
    typedef typename EllipsoidArc::InnerRadiusType ValueType;

    ValueType value(value_from);

    if (!obj->setInnerRadius(value)) return NULL;

    return obj_ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_inner_radius_move(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, int32_t p_inner_radius)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_inner_radius;
    typedef typename EllipsoidArc::InnerRadiusType ValueType;

    ValueType value(value_from);

    if (!obj->setInnerRadius(std::move(value))) return NULL;

    return obj_ellipsoid_arc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_ellipsoid_arc_get_uncertainty_radius(const data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename EllipsoidArc::UncertaintyRadiusType ResultFromType;
    const ResultFromType &result_from = obj->getUncertaintyRadius();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_uncertainty_radius(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, const float p_uncertainty_radius)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_radius;
    typedef typename EllipsoidArc::UncertaintyRadiusType ValueType;

    ValueType value(value_from);

    if (!obj->setUncertaintyRadius(value)) return NULL;

    return obj_ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_uncertainty_radius_move(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, float p_uncertainty_radius)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_radius;
    typedef typename EllipsoidArc::UncertaintyRadiusType ValueType;

    ValueType value(value_from);

    if (!obj->setUncertaintyRadius(std::move(value))) return NULL;

    return obj_ellipsoid_arc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_offset_angle(const data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc::OffsetAngleType ResultFromType;
    const ResultFromType &result_from = obj->getOffsetAngle();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_offset_angle(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, const int32_t p_offset_angle)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_offset_angle;
    typedef typename EllipsoidArc::OffsetAngleType ValueType;

    ValueType value(value_from);

    if (!obj->setOffsetAngle(value)) return NULL;

    return obj_ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_offset_angle_move(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, int32_t p_offset_angle)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_offset_angle;
    typedef typename EllipsoidArc::OffsetAngleType ValueType;

    ValueType value(value_from);

    if (!obj->setOffsetAngle(std::move(value))) return NULL;

    return obj_ellipsoid_arc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_included_angle(const data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc::IncludedAngleType ResultFromType;
    const ResultFromType &result_from = obj->getIncludedAngle();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_included_angle(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, const int32_t p_included_angle)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_included_angle;
    typedef typename EllipsoidArc::IncludedAngleType ValueType;

    ValueType value(value_from);

    if (!obj->setIncludedAngle(value)) return NULL;

    return obj_ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_included_angle_move(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, int32_t p_included_angle)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_included_angle;
    typedef typename EllipsoidArc::IncludedAngleType ValueType;

    ValueType value(value_from);

    if (!obj->setIncludedAngle(std::move(value))) return NULL;

    return obj_ellipsoid_arc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_ellipsoid_arc_get_confidence(const data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc::ConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_confidence(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, const int32_t p_confidence)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename EllipsoidArc::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(value)) return NULL;

    return obj_ellipsoid_arc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ellipsoid_arc_t *data_collection_model_ellipsoid_arc_set_confidence_move(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc, int32_t p_confidence)
{
    if (!obj_ellipsoid_arc) return NULL;

    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename EllipsoidArc::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_ellipsoid_arc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ellipsoid_arc_make_lnode(data_collection_model_ellipsoid_arc_t *p_ellipsoid_arc)
{
    return data_collection_lnode_create(p_ellipsoid_arc, reinterpret_cast<void(*)(void*)>(data_collection_model_ellipsoid_arc_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ellipsoid_arc_refcount(data_collection_model_ellipsoid_arc_t *obj_ellipsoid_arc)
{
    if (!obj_ellipsoid_arc) return 0l;
    std::shared_ptr<EllipsoidArc > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc >*>(obj_ellipsoid_arc);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

