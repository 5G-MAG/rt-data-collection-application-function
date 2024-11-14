/**********************************************************************************************************************************
 * PointAltitudeUncertainty_allOf - C interface to the PointAltitudeUncertainty_allOf object
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

/*#include "PointAltitudeUncertainty_allOf.h" already included by data-collection-sp/data-collection.h */
#include "PointAltitudeUncertainty_allOf-internal.h"
#include "openapi/model/PointAltitudeUncertainty_allOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_create(





)
{
    return reinterpret_cast<data_collection_model_point_altitude_uncertainty_all_of_t*>(new std::shared_ptr<PointAltitudeUncertainty_allOf>(new PointAltitudeUncertainty_allOf(





)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_create_ref(const data_collection_model_point_altitude_uncertainty_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_point_altitude_uncertainty_all_of_t*>(new std::shared_ptr<PointAltitudeUncertainty_allOf>(*reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_create_copy(const data_collection_model_point_altitude_uncertainty_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_point_altitude_uncertainty_all_of_t*>(new std::shared_ptr<PointAltitudeUncertainty_allOf >(new PointAltitudeUncertainty_allOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_create_move(data_collection_model_point_altitude_uncertainty_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > *obj = reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_copy(data_collection_model_point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of, const data_collection_model_point_altitude_uncertainty_all_of_t *other)
{
    if (point_altitude_uncertainty_all_of) {
        std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(point_altitude_uncertainty_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<PointAltitudeUncertainty_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(other);
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
                const std::shared_ptr<PointAltitudeUncertainty_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new PointAltitudeUncertainty_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        point_altitude_uncertainty_all_of = data_collection_model_point_altitude_uncertainty_all_of_create_copy(other);
    }
    return point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_move(data_collection_model_point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of, data_collection_model_point_altitude_uncertainty_all_of_t *other)
{
    std::shared_ptr<PointAltitudeUncertainty_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(other);

    if (point_altitude_uncertainty_all_of) {
        std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(point_altitude_uncertainty_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                point_altitude_uncertainty_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_point_altitude_uncertainty_all_of_free(data_collection_model_point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of)
{
    if (!point_altitude_uncertainty_all_of) return;
    delete reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(point_altitude_uncertainty_all_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_point_altitude_uncertainty_all_of_toJSON(const data_collection_model_point_altitude_uncertainty_all_of_t *point_altitude_uncertainty_all_of, bool as_request)
{
    if (!point_altitude_uncertainty_all_of) return NULL;
    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(point_altitude_uncertainty_all_of);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_point_altitude_uncertainty_all_of_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_point_altitude_uncertainty_all_of_t*>(new std::shared_ptr<PointAltitudeUncertainty_allOf >(new PointAltitudeUncertainty_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_all_of_is_equal_to(const data_collection_model_point_altitude_uncertainty_all_of_t *first, const data_collection_model_point_altitude_uncertainty_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_uncertainty_all_of_get_point(const data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename PointAltitudeUncertainty_allOf::PointType ResultFromType;
    const ResultFromType &result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_point(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointAltitudeUncertainty_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPoint(value)) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_point_move(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename PointAltitudeUncertainty_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPoint(std::move(value))) return NULL;
    data_collection_model_geographical_coordinates_free
(p_point);

    return obj_point_altitude_uncertainty_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_point_altitude_uncertainty_all_of_get_altitude(const data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty_allOf::AltitudeType ResultFromType;
    const ResultFromType &result_from = obj->getAltitude();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_altitude(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, const double p_altitude)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename PointAltitudeUncertainty_allOf::AltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setAltitude(value)) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_altitude_move(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, double p_altitude)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename PointAltitudeUncertainty_allOf::AltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setAltitude(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipse_t* data_collection_model_point_altitude_uncertainty_all_of_get_uncertainty_ellipse(const data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) {
        const data_collection_model_uncertainty_ellipse_t *result = NULL;
        return result;
    }

    typedef typename PointAltitudeUncertainty_allOf::UncertaintyEllipseType ResultFromType;
    const ResultFromType &result_from = obj->getUncertaintyEllipse();
    const data_collection_model_uncertainty_ellipse_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipse_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_uncertainty_ellipse(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, const data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename PointAltitudeUncertainty_allOf::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUncertaintyEllipse(value)) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_uncertainty_ellipse_move(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, data_collection_model_uncertainty_ellipse_t* p_uncertainty_ellipse)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipse;
    typedef typename PointAltitudeUncertainty_allOf::UncertaintyEllipseType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUncertaintyEllipse(std::move(value))) return NULL;
    data_collection_model_uncertainty_ellipse_free
(p_uncertainty_ellipse);

    return obj_point_altitude_uncertainty_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_point_altitude_uncertainty_all_of_get_uncertainty_altitude(const data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty_allOf::UncertaintyAltitudeType ResultFromType;
    const ResultFromType &result_from = obj->getUncertaintyAltitude();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_uncertainty_altitude(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, const float p_uncertainty_altitude)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_altitude;
    typedef typename PointAltitudeUncertainty_allOf::UncertaintyAltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setUncertaintyAltitude(value)) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_uncertainty_altitude_move(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, float p_uncertainty_altitude)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_altitude;
    typedef typename PointAltitudeUncertainty_allOf::UncertaintyAltitudeType ValueType;

    ValueType value(value_from);

    if (!obj->setUncertaintyAltitude(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_all_of_get_confidence(const data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty_allOf::ConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_confidence(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, const int32_t p_confidence)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename PointAltitudeUncertainty_allOf::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(value)) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_confidence_move(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, int32_t p_confidence)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename PointAltitudeUncertainty_allOf::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_point_altitude_uncertainty_all_of_has_v_confidence(const data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) return false;

    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return false;

    return obj->getVConfidence().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_point_altitude_uncertainty_all_of_get_v_confidence(const data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PointAltitudeUncertainty_allOf::VConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getVConfidence();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_v_confidence(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, const int32_t p_v_confidence)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename PointAltitudeUncertainty_allOf::VConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setVConfidence(value)) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_point_altitude_uncertainty_all_of_t *data_collection_model_point_altitude_uncertainty_all_of_set_v_confidence_move(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of, int32_t p_v_confidence)
{
    if (!obj_point_altitude_uncertainty_all_of) return NULL;

    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename PointAltitudeUncertainty_allOf::VConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setVConfidence(std::move(value))) return NULL;

    return obj_point_altitude_uncertainty_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_point_altitude_uncertainty_all_of_make_lnode(data_collection_model_point_altitude_uncertainty_all_of_t *p_point_altitude_uncertainty_all_of)
{
    return data_collection_lnode_create(p_point_altitude_uncertainty_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_point_altitude_uncertainty_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_altitude_uncertainty_all_of_refcount(data_collection_model_point_altitude_uncertainty_all_of_t *obj_point_altitude_uncertainty_all_of)
{
    if (!obj_point_altitude_uncertainty_all_of) return 0l;
    std::shared_ptr<PointAltitudeUncertainty_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitudeUncertainty_allOf >*>(obj_point_altitude_uncertainty_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

