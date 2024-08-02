/**********************************************************************************************************************************
 * EllipsoidArc_allOf - C interface to the EllipsoidArc_allOf object
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

/*#include "EllipsoidArc_allOf.h" already included by data-collection-sp/data-collection.h */
#include "EllipsoidArc_allOf-internal.h"
#include "openapi/model/EllipsoidArc_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_create(





)
{
    return reinterpret_cast<data_collection_model_ellipsoid_arc_all_of_t*>(new std::shared_ptr<EllipsoidArc_allOf>(new EllipsoidArc_allOf(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_create_copy(const data_collection_model_ellipsoid_arc_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ellipsoid_arc_all_of_t*>(new std::shared_ptr<EllipsoidArc_allOf >(new EllipsoidArc_allOf(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_create_move(data_collection_model_ellipsoid_arc_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > *obj = reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_copy(data_collection_model_ellipsoid_arc_all_of_t *ellipsoid_arc_all_of, const data_collection_model_ellipsoid_arc_all_of_t *other)
{
    if (ellipsoid_arc_all_of) {
        std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(ellipsoid_arc_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<EllipsoidArc_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(other);
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
                const std::shared_ptr<EllipsoidArc_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new EllipsoidArc_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ellipsoid_arc_all_of = data_collection_model_ellipsoid_arc_all_of_create_copy(other);
    }
    return ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_move(data_collection_model_ellipsoid_arc_all_of_t *ellipsoid_arc_all_of, data_collection_model_ellipsoid_arc_all_of_t *other)
{
    std::shared_ptr<EllipsoidArc_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(other);

    if (ellipsoid_arc_all_of) {
        std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(ellipsoid_arc_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ellipsoid_arc_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ellipsoid_arc_all_of_free(data_collection_model_ellipsoid_arc_all_of_t *ellipsoid_arc_all_of)
{
    if (!ellipsoid_arc_all_of) return;
    delete reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(ellipsoid_arc_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ellipsoid_arc_all_of_toJSON(const data_collection_model_ellipsoid_arc_all_of_t *ellipsoid_arc_all_of, bool as_request)
{
    if (!ellipsoid_arc_all_of) return NULL;
    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(ellipsoid_arc_all_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ellipsoid_arc_all_of_t*>(new std::shared_ptr<EllipsoidArc_allOf >(new EllipsoidArc_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_ellipsoid_arc_all_of_is_equal_to(const data_collection_model_ellipsoid_arc_all_of_t *first, const data_collection_model_ellipsoid_arc_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<EllipsoidArc_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<EllipsoidArc_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_ellipsoid_arc_all_of_get_point(const data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of)
{
    if (!obj_ellipsoid_arc_all_of) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename EllipsoidArc_allOf::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_point(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename EllipsoidArc_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_point_move(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename EllipsoidArc_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ellipsoid_arc_all_of_get_inner_radius(const data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of)
{
    if (!obj_ellipsoid_arc_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc_allOf::InnerRadiusType ResultFromType;
    const ResultFromType result_from = obj->getInnerRadius();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_inner_radius(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, const int32_t p_inner_radius)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_inner_radius;
    typedef typename EllipsoidArc_allOf::InnerRadiusType ValueType;

    ValueType value = value_from;
    if (!obj->setInnerRadius(value)) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_inner_radius_move(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, int32_t p_inner_radius)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_inner_radius;
    typedef typename EllipsoidArc_allOf::InnerRadiusType ValueType;

    ValueType value = value_from;
    
    if (!obj->setInnerRadius(std::move(value))) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_ellipsoid_arc_all_of_get_uncertainty_radius(const data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of)
{
    if (!obj_ellipsoid_arc_all_of) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename EllipsoidArc_allOf::UncertaintyRadiusType ResultFromType;
    const ResultFromType result_from = obj->getUncertaintyRadius();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_uncertainty_radius(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, const float p_uncertainty_radius)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_radius;
    typedef typename EllipsoidArc_allOf::UncertaintyRadiusType ValueType;

    ValueType value = value_from;
    if (!obj->setUncertaintyRadius(value)) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_uncertainty_radius_move(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, float p_uncertainty_radius)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_radius;
    typedef typename EllipsoidArc_allOf::UncertaintyRadiusType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUncertaintyRadius(std::move(value))) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ellipsoid_arc_all_of_get_offset_angle(const data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of)
{
    if (!obj_ellipsoid_arc_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc_allOf::OffsetAngleType ResultFromType;
    const ResultFromType result_from = obj->getOffsetAngle();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_offset_angle(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, const int32_t p_offset_angle)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_offset_angle;
    typedef typename EllipsoidArc_allOf::OffsetAngleType ValueType;

    ValueType value = value_from;
    if (!obj->setOffsetAngle(value)) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_offset_angle_move(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, int32_t p_offset_angle)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_offset_angle;
    typedef typename EllipsoidArc_allOf::OffsetAngleType ValueType;

    ValueType value = value_from;
    
    if (!obj->setOffsetAngle(std::move(value))) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ellipsoid_arc_all_of_get_included_angle(const data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of)
{
    if (!obj_ellipsoid_arc_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc_allOf::IncludedAngleType ResultFromType;
    const ResultFromType result_from = obj->getIncludedAngle();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_included_angle(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, const int32_t p_included_angle)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_included_angle;
    typedef typename EllipsoidArc_allOf::IncludedAngleType ValueType;

    ValueType value = value_from;
    if (!obj->setIncludedAngle(value)) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_included_angle_move(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, int32_t p_included_angle)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_included_angle;
    typedef typename EllipsoidArc_allOf::IncludedAngleType ValueType;

    ValueType value = value_from;
    
    if (!obj->setIncludedAngle(std::move(value))) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ellipsoid_arc_all_of_get_confidence(const data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of)
{
    if (!obj_ellipsoid_arc_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<const std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename EllipsoidArc_allOf::ConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_confidence(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, const int32_t p_confidence)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename EllipsoidArc_allOf::ConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setConfidence(value)) return NULL;

    return obj_ellipsoid_arc_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ellipsoid_arc_all_of_t *data_collection_model_ellipsoid_arc_all_of_set_confidence_move(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of, int32_t p_confidence)
{
    if (!obj_ellipsoid_arc_all_of) return NULL;

    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename EllipsoidArc_allOf::ConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_ellipsoid_arc_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ellipsoid_arc_all_of_make_lnode(data_collection_model_ellipsoid_arc_all_of_t *p_ellipsoid_arc_all_of)
{
    return data_collection_lnode_create(p_ellipsoid_arc_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_ellipsoid_arc_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ellipsoid_arc_all_of_refcount(data_collection_model_ellipsoid_arc_all_of_t *obj_ellipsoid_arc_all_of)
{
    if (!obj_ellipsoid_arc_all_of) return 0l;
    std::shared_ptr<EllipsoidArc_allOf > &obj = *reinterpret_cast<std::shared_ptr<EllipsoidArc_allOf >*>(obj_ellipsoid_arc_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

