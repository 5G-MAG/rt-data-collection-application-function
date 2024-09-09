/**********************************************************************************************************************************
 * Local3dPointUncertaintyEllipsoid - C interface to the Local3dPointUncertaintyEllipsoid object
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

/*#include "Local3dPointUncertaintyEllipsoid.h" already included by data-collection-sp/data-collection.h */
#include "Local3dPointUncertaintyEllipsoid-internal.h"
#include "openapi/model/Local3dPointUncertaintyEllipsoid.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_create(





)
{
    return reinterpret_cast<data_collection_model_local3d_point_uncertainty_ellipsoid_t*>(new std::shared_ptr<Local3dPointUncertaintyEllipsoid>(new Local3dPointUncertaintyEllipsoid(





)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_create_copy(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_local3d_point_uncertainty_ellipsoid_t*>(new std::shared_ptr<Local3dPointUncertaintyEllipsoid >(new Local3dPointUncertaintyEllipsoid(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_create_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > *obj = reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_copy(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, const data_collection_model_local3d_point_uncertainty_ellipsoid_t *other)
{
    if (local3d_point_uncertainty_ellipsoid) {
        std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(local3d_point_uncertainty_ellipsoid);
        if (obj) {
            if (other) {
                const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &other_obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(other);
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
                const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &other_obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(other);
                if (other_obj) {
                    obj.reset(new Local3dPointUncertaintyEllipsoid(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        local3d_point_uncertainty_ellipsoid = data_collection_model_local3d_point_uncertainty_ellipsoid_create_copy(other);
    }
    return local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, data_collection_model_local3d_point_uncertainty_ellipsoid_t *other)
{
    std::shared_ptr<Local3dPointUncertaintyEllipsoid > *other_ptr = reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(other);

    if (local3d_point_uncertainty_ellipsoid) {
        std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(local3d_point_uncertainty_ellipsoid);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                local3d_point_uncertainty_ellipsoid = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local3d_point_uncertainty_ellipsoid_free(data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid)
{
    if (!local3d_point_uncertainty_ellipsoid) return;
    delete reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(local3d_point_uncertainty_ellipsoid);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local3d_point_uncertainty_ellipsoid_toJSON(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid, bool as_request)
{
    if (!local3d_point_uncertainty_ellipsoid) return NULL;
    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(local3d_point_uncertainty_ellipsoid);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_local3d_point_uncertainty_ellipsoid_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_local3d_point_uncertainty_ellipsoid_t*>(new std::shared_ptr<Local3dPointUncertaintyEllipsoid >(new Local3dPointUncertaintyEllipsoid(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local3d_point_uncertainty_ellipsoid_is_equal_to(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *first, const data_collection_model_local3d_point_uncertainty_ellipsoid_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj2 = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj1 = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_shape(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename Local3dPointUncertaintyEllipsoid::ShapeType ResultFromType;
    const ResultFromType &result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_shape(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename Local3dPointUncertaintyEllipsoid::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setShape(value)) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_shape_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename Local3dPointUncertaintyEllipsoid::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setShape(std::move(value))) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_local_origin_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_local_origin(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) {
        const data_collection_model_local_origin_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) {
        const data_collection_model_local_origin_t *result = NULL;
        return result;
    }

    typedef typename Local3dPointUncertaintyEllipsoid::LocalOriginType ResultFromType;
    const ResultFromType &result_from = obj->getLocalOrigin();
    const data_collection_model_local_origin_t *result = reinterpret_cast<const data_collection_model_local_origin_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_local_origin(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, const data_collection_model_local_origin_t* p_local_origin)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_local_origin;
    typedef typename Local3dPointUncertaintyEllipsoid::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setLocalOrigin(value)) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_local_origin_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, data_collection_model_local_origin_t* p_local_origin)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_local_origin;
    typedef typename Local3dPointUncertaintyEllipsoid::LocalOriginType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setLocalOrigin(std::move(value))) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_relative_cartesian_location_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_point(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) {
        const data_collection_model_relative_cartesian_location_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) {
        const data_collection_model_relative_cartesian_location_t *result = NULL;
        return result;
    }

    typedef typename Local3dPointUncertaintyEllipsoid::PointType ResultFromType;
    const ResultFromType &result_from = obj->getPoint();
    const data_collection_model_relative_cartesian_location_t *result = reinterpret_cast<const data_collection_model_relative_cartesian_location_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_point(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, const data_collection_model_relative_cartesian_location_t* p_point)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename Local3dPointUncertaintyEllipsoid::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPoint(value)) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_point_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, data_collection_model_relative_cartesian_location_t* p_point)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename Local3dPointUncertaintyEllipsoid::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setPoint(std::move(value))) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_uncertainty_ellipsoid_t* data_collection_model_local3d_point_uncertainty_ellipsoid_get_uncertainty_ellipsoid(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) {
        const data_collection_model_uncertainty_ellipsoid_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) {
        const data_collection_model_uncertainty_ellipsoid_t *result = NULL;
        return result;
    }

    typedef typename Local3dPointUncertaintyEllipsoid::UncertaintyEllipsoidType ResultFromType;
    const ResultFromType &result_from = obj->getUncertaintyEllipsoid();
    const data_collection_model_uncertainty_ellipsoid_t *result = reinterpret_cast<const data_collection_model_uncertainty_ellipsoid_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_uncertainty_ellipsoid(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, const data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipsoid;
    typedef typename Local3dPointUncertaintyEllipsoid::UncertaintyEllipsoidType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUncertaintyEllipsoid(value)) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_uncertainty_ellipsoid_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, data_collection_model_uncertainty_ellipsoid_t* p_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_uncertainty_ellipsoid;
    typedef typename Local3dPointUncertaintyEllipsoid::UncertaintyEllipsoidType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setUncertaintyEllipsoid(std::move(value))) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local3d_point_uncertainty_ellipsoid_get_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename Local3dPointUncertaintyEllipsoid::ConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_confidence(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, const int32_t p_confidence)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename Local3dPointUncertaintyEllipsoid::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(value)) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_confidence_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, int32_t p_confidence)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename Local3dPointUncertaintyEllipsoid::ConfidenceType ValueType;

    ValueType value(value_from);

    
    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local3d_point_uncertainty_ellipsoid_has_v_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return false;

    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return false;

    return obj->getVConfidence().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local3d_point_uncertainty_ellipsoid_get_v_confidence(const data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<const std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename Local3dPointUncertaintyEllipsoid::VConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getVConfidence();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_v_confidence(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, const int32_t p_v_confidence)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename Local3dPointUncertaintyEllipsoid::VConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setVConfidence(value)) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local3d_point_uncertainty_ellipsoid_t *data_collection_model_local3d_point_uncertainty_ellipsoid_set_v_confidence_move(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid, int32_t p_v_confidence)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return NULL;

    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    if (!obj) return NULL;

    const auto &value_from = p_v_confidence;
    typedef typename Local3dPointUncertaintyEllipsoid::VConfidenceType ValueType;

    ValueType value(value_from);

    
    if (!obj->setVConfidence(std::move(value))) return NULL;

    return obj_local3d_point_uncertainty_ellipsoid;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local3d_point_uncertainty_ellipsoid_make_lnode(data_collection_model_local3d_point_uncertainty_ellipsoid_t *p_local3d_point_uncertainty_ellipsoid)
{
    return data_collection_lnode_create(p_local3d_point_uncertainty_ellipsoid, reinterpret_cast<void(*)(void*)>(data_collection_model_local3d_point_uncertainty_ellipsoid_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_local3d_point_uncertainty_ellipsoid_refcount(data_collection_model_local3d_point_uncertainty_ellipsoid_t *obj_local3d_point_uncertainty_ellipsoid)
{
    if (!obj_local3d_point_uncertainty_ellipsoid) return 0l;
    std::shared_ptr<Local3dPointUncertaintyEllipsoid > &obj = *reinterpret_cast<std::shared_ptr<Local3dPointUncertaintyEllipsoid >*>(obj_local3d_point_uncertainty_ellipsoid);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

