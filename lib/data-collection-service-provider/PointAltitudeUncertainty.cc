/**********************************************************************************************************************************
 * PointAltitudeUncertainty - C interface to the PointAltitudeUncertainty object
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

/*#include "PointAltitudeUncertainty.h" already included by data-collection-sp/data-collection.h */
#include "PointAltitudeUncertainty-internal.h"
#include "openapi/model/PointAltitudeUncertainty.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create(






)
{
    return reinterpret_cast<data_collection_model_point_altitude_uncertainty_t*>(new std::shared_ptr<PointAltitudeUncertainty>(new PointAltitudeUncertainty(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create_ref(const data_collection_model_point_altitude_uncertainty_t *other)
{
    return reinterpret_cast<data_collection_model_point_altitude_uncertainty_t*>(new std::shared_ptr<PointAltitudeUncertainty>(*reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create_copy(const data_collection_model_point_altitude_uncertainty_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_point_altitude_uncertainty_t*>(new std::shared_ptr<PointAltitudeUncertainty >(new PointAltitudeUncertainty(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_create_move(data_collection_model_point_altitude_uncertainty_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > *obj = reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_copy(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, const data_collection_model_point_altitude_uncertainty_t *other)
{
    if (point_altitude_uncertainty) {
        std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(point_altitude_uncertainty);
        if (obj) {
            if (other) {
                const std::shared_ptr<PointAltitudeUncertainty > &other_obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(other);
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
                const std::shared_ptr<PointAltitudeUncertainty > &other_obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(other);
                if (other_obj) {
                    obj.reset(new PointAltitudeUncertainty(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        point_altitude_uncertainty = data_collection_model_point_altitude_uncertainty_create_copy(other);
    }
    return point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_move(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, data_collection_model_point_altitude_uncertainty_t *other)
{
    std::shared_ptr<PointAltitudeUncertainty > *other_ptr = reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(other);

    if (point_altitude_uncertainty) {
        std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(point_altitude_uncertainty);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                point_altitude_uncertainty = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_altitude_uncertainty_free(data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty)
{
    if (!point_altitude_uncertainty) return;
    delete reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(point_altitude_uncertainty);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_altitude_uncertainty_toJSON(const data_collection_model_point_altitude_uncertainty_t *point_altitude_uncertainty, bool as_request)
{
    if (!point_altitude_uncertainty) return NULL;
    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(point_altitude_uncertainty);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_point_altitude_uncertainty_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_point_altitude_uncertainty_t*>(new std::shared_ptr<PointAltitudeUncertainty >(new PointAltitudeUncertainty(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_is_equal_to(const data_collection_model_point_altitude_uncertainty_t *first, const data_collection_model_point_altitude_uncertainty_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PointAltitudeUncertainty > &obj2 = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PointAltitudeUncertainty > &obj1 = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_point_altitude_uncertainty_get_shape(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename PointAltitudeUncertainty::ShapeType ResultFromType;
    const ResultFromType &result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_shape(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename PointAltitudeUncertainty::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setShape(value)) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_shape_move(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename PointAltitudeUncertainty::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setShape(std::move(value))) return NULL;
    data_collection_model_supported_gad_shapes_free
(p_shape);

    return obj_point_altitude_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_uncertainty_get_point(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename PointAltitudeUncertainty::PointType ResultFromType;
    const ResultFromType &result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_point(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointAltitudeUncertainty::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPoint(value)) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_point_move(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointAltitudeUncertainty::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPoint(std::move(value))) return NULL;
    data_collection_model_geographical_coordinates_free
(p_point);

    return obj_point_altitude_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_point_altitude_uncertainty_get_altitude(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty::AltitudeType ResultFromType;
    const ResultFromType &result_from = obj->getAltitude();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_altitude(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, const double p_altitude)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename PointAltitudeUncertainty::AltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setAltitude(value)) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_altitude_move(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, double p_altitude)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename PointAltitudeUncertainty::AltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setAltitude(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_point_altitude_uncertainty_get_uncertainty_ellipse(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    typedef typename PointAltitudeUncertainty::UncertaintyEllipseType ResultFromType;
    const ResultFromType &result_from = obj->getUncertaintyEllipse();
    const data_collection_model_uncertainty_ellipse_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipse_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_ellipse(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename PointAltitudeUncertainty::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUncertaintyEllipse(value)) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_ellipse_move(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename PointAltitudeUncertainty::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUncertaintyEllipse(std::move(value))) return NULL;
    data_collection_model_uncertainty_ellipse_free
(p_uncertainty_ellipse);

    return obj_point_altitude_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_point_altitude_uncertainty_get_uncertainty_altitude(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty::UncertaintyAltitudeType ResultFromType;
    const ResultFromType &result_from = obj->getUncertaintyAltitude();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_altitude(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, const float p_uncertainty_altitude)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_altitude;
    typedef typename PointAltitudeUncertainty::UncertaintyAltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setUncertaintyAltitude(value)) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_uncertainty_altitude_move(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, float p_uncertainty_altitude)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_altitude;
    typedef typename PointAltitudeUncertainty::UncertaintyAltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setUncertaintyAltitude(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_get_confidence(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty::ConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_confidence(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, const int32_t p_confidence)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename PointAltitudeUncertainty::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(value)) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_confidence_move(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, int32_t p_confidence)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename PointAltitudeUncertainty::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_has_v_confidence(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) return false;

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return false;

    return obj->getVConfidence().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_get_v_confidence(const data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty::VConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getVConfidence();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_v_confidence(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, const int32_t p_v_confidence)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename PointAltitudeUncertainty::VConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setVConfidence(value)) return NULL;

    return obj_point_altitude_uncertainty;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_t *data_collection_model_point_altitude_uncertainty_set_v_confidence_move(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty, int32_t p_v_confidence)
{
    if (!obj_point_altitude_uncertainty) return NULL;

    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename PointAltitudeUncertainty::VConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setVConfidence(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_altitude_uncertainty_make_lnode(data_collection_model_point_altitude_uncertainty_t *p_point_altitude_uncertainty)
{
    return data_collection_lnode_create(p_point_altitude_uncertainty, reinterpret_cast<void(*)(void*)>(data_collection_model_point_altitude_uncertainty_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_altitude_uncertainty_refcount(data_collection_model_point_altitude_uncertainty_t *obj_point_altitude_uncertainty)
{
    if (!obj_point_altitude_uncertainty) return 0l;
    std::shared_ptr<PointAltitudeUncertainty > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty >*>(obj_point_altitude_uncertainty);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

