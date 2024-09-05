/**********************************************************************************************************************************
 * SupportedGADShapes_anyOf - C interface to the SupportedGADShapes_anyOf object
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

/*#include "SupportedGADShapes_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "SupportedGADShapes_anyOf-internal.h"
#include "openapi/model/SupportedGADShapes_anyOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_any_of_t *data_collection_model_supported_gad_shapes_any_of_create()
{
    return reinterpret_cast<data_collection_model_supported_gad_shapes_any_of_t*>(new std::shared_ptr<SupportedGADShapes_anyOf>(new SupportedGADShapes_anyOf()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_any_of_t *data_collection_model_supported_gad_shapes_any_of_create_copy(const data_collection_model_supported_gad_shapes_any_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_supported_gad_shapes_any_of_t*>(new std::shared_ptr<SupportedGADShapes_anyOf >(new SupportedGADShapes_anyOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_any_of_t *data_collection_model_supported_gad_shapes_any_of_create_move(data_collection_model_supported_gad_shapes_any_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<SupportedGADShapes_anyOf > *obj = reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_any_of_t *data_collection_model_supported_gad_shapes_any_of_copy(data_collection_model_supported_gad_shapes_any_of_t *supported_gad_shapes_any_of, const data_collection_model_supported_gad_shapes_any_of_t *other)
{
    if (supported_gad_shapes_any_of) {
        std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(supported_gad_shapes_any_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<SupportedGADShapes_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(other);
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
                const std::shared_ptr<SupportedGADShapes_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(other);
                if (other_obj) {
                    obj.reset(new SupportedGADShapes_anyOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        supported_gad_shapes_any_of = data_collection_model_supported_gad_shapes_any_of_create_copy(other);
    }
    return supported_gad_shapes_any_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_any_of_t *data_collection_model_supported_gad_shapes_any_of_move(data_collection_model_supported_gad_shapes_any_of_t *supported_gad_shapes_any_of, data_collection_model_supported_gad_shapes_any_of_t *other)
{
    std::shared_ptr<SupportedGADShapes_anyOf > *other_ptr = reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(other);

    if (supported_gad_shapes_any_of) {
        std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(supported_gad_shapes_any_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                supported_gad_shapes_any_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return supported_gad_shapes_any_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_supported_gad_shapes_any_of_free(data_collection_model_supported_gad_shapes_any_of_t *supported_gad_shapes_any_of)
{
    if (!supported_gad_shapes_any_of) return;
    delete reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(supported_gad_shapes_any_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_supported_gad_shapes_any_of_toJSON(const data_collection_model_supported_gad_shapes_any_of_t *supported_gad_shapes_any_of, bool as_request)
{
    if (!supported_gad_shapes_any_of) return NULL;
    const std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(supported_gad_shapes_any_of);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_supported_gad_shapes_any_of_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_any_of_t *data_collection_model_supported_gad_shapes_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_supported_gad_shapes_any_of_t*>(new std::shared_ptr<SupportedGADShapes_anyOf >(new SupportedGADShapes_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_any_of_is_equal_to(const data_collection_model_supported_gad_shapes_any_of_t *first, const data_collection_model_supported_gad_shapes_any_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<SupportedGADShapes_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<SupportedGADShapes_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_any_of_is_not_set(const data_collection_model_supported_gad_shapes_any_of_t *supported_gad_shapes_any_of)
{
    if (!supported_gad_shapes_any_of) return true;
    const std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(supported_gad_shapes_any_of);
    if (!obj) return true;
    return obj->getValue() == SupportedGADShapes_anyOf::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_any_of_e data_collection_model_supported_gad_shapes_any_of_get_enum(const data_collection_model_supported_gad_shapes_any_of_t *obj_supported_gad_shapes_any_of)
{
    if (!obj_supported_gad_shapes_any_of)
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_NO_VAL;
    const std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(obj_supported_gad_shapes_any_of);
    if (!obj) return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_NO_VAL;
    switch (obj->getValue()) {
    case SupportedGADShapes_anyOf::Enum::NO_VAL:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_NO_VAL;
    case SupportedGADShapes_anyOf::Enum::VAL_POINT:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT;
    case SupportedGADShapes_anyOf::Enum::VAL_POINT_UNCERTAINTY_CIRCLE:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_UNCERTAINTY_CIRCLE;
    case SupportedGADShapes_anyOf::Enum::VAL_POINT_UNCERTAINTY_ELLIPSE:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_UNCERTAINTY_ELLIPSE;
    case SupportedGADShapes_anyOf::Enum::VAL_POLYGON:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POLYGON;
    case SupportedGADShapes_anyOf::Enum::VAL_POINT_ALTITUDE:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_ALTITUDE;
    case SupportedGADShapes_anyOf::Enum::VAL_POINT_ALTITUDE_UNCERTAINTY:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_ALTITUDE_UNCERTAINTY;
    case SupportedGADShapes_anyOf::Enum::VAL_ELLIPSOID_ARC:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_ELLIPSOID_ARC;
    case SupportedGADShapes_anyOf::Enum::VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE;
    case SupportedGADShapes_anyOf::Enum::VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID;
    case SupportedGADShapes_anyOf::Enum::VAL_DISTANCE_DIRECTION:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_DISTANCE_DIRECTION;
    case SupportedGADShapes_anyOf::Enum::VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE;
    case SupportedGADShapes_anyOf::Enum::VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID:
        return DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID;
    default:
        break;
    }
    return (data_collection_model_supported_gad_shapes_any_of_e)-1;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_supported_gad_shapes_any_of_get_string(const data_collection_model_supported_gad_shapes_any_of_t *obj_supported_gad_shapes_any_of)
{
    if (!obj_supported_gad_shapes_any_of) return NULL;
    const std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes_anyOf >*>(obj_supported_gad_shapes_any_of);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_any_of_set_enum(data_collection_model_supported_gad_shapes_any_of_t *obj_supported_gad_shapes_any_of, data_collection_model_supported_gad_shapes_any_of_e p_value)
{
    if (!obj_supported_gad_shapes_any_of) return false;
    std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(obj_supported_gad_shapes_any_of);
    if (!obj) return false;
    switch (p_value) {
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_NO_VAL:
        *obj = SupportedGADShapes_anyOf::Enum::NO_VAL;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_POINT;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_UNCERTAINTY_CIRCLE:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_POINT_UNCERTAINTY_CIRCLE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_UNCERTAINTY_ELLIPSE:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_POINT_UNCERTAINTY_ELLIPSE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POLYGON:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_POLYGON;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_ALTITUDE:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_POINT_ALTITUDE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_POINT_ALTITUDE_UNCERTAINTY:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_POINT_ALTITUDE_UNCERTAINTY;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_ELLIPSOID_ARC:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_ELLIPSOID_ARC;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_DISTANCE_DIRECTION:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_DISTANCE_DIRECTION;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_ANY_OF_VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID:
        *obj = SupportedGADShapes_anyOf::Enum::VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_any_of_set_string(data_collection_model_supported_gad_shapes_any_of_t *obj_supported_gad_shapes_any_of, const char *p_value)
{
    if (!obj_supported_gad_shapes_any_of) return false;
    std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(obj_supported_gad_shapes_any_of);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = SupportedGADShapes_anyOf::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_supported_gad_shapes_any_of_make_lnode(data_collection_model_supported_gad_shapes_any_of_t *p_supported_gad_shapes_any_of)
{
    return data_collection_lnode_create(p_supported_gad_shapes_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_supported_gad_shapes_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_supported_gad_shapes_any_of_refcount(data_collection_model_supported_gad_shapes_any_of_t *obj_supported_gad_shapes_any_of)
{
    if (!obj_supported_gad_shapes_any_of) return 0l;
    std::shared_ptr<SupportedGADShapes_anyOf > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes_anyOf >*>(obj_supported_gad_shapes_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

