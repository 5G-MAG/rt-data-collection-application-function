/**********************************************************************************************************************************
 * SupportedGADShapes - C interface to the SupportedGADShapes object
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

/*#include "SupportedGADShapes.h" already included by data-collection-sp/data-collection.h */
#include "SupportedGADShapes-internal.h"
#include "openapi/model/SupportedGADShapes.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_create()
{
    return reinterpret_cast<data_collection_model_supported_gad_shapes_t*>(new std::shared_ptr<SupportedGADShapes>(new SupportedGADShapes()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_create_copy(const data_collection_model_supported_gad_shapes_t *other)
{
    return reinterpret_cast<data_collection_model_supported_gad_shapes_t*>(new std::shared_ptr<SupportedGADShapes >(new SupportedGADShapes(**reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_create_move(data_collection_model_supported_gad_shapes_t *other)
{
    return reinterpret_cast<data_collection_model_supported_gad_shapes_t*>(new std::shared_ptr<SupportedGADShapes >(std::move(*reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_copy(data_collection_model_supported_gad_shapes_t *supported_gad_shapes, const data_collection_model_supported_gad_shapes_t *other)
{
    std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(supported_gad_shapes);
    *obj = **reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(other);
    return supported_gad_shapes;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_move(data_collection_model_supported_gad_shapes_t *supported_gad_shapes, data_collection_model_supported_gad_shapes_t *other)
{
    std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(supported_gad_shapes);
    obj = std::move(*reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(other));
    return supported_gad_shapes;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_supported_gad_shapes_free(data_collection_model_supported_gad_shapes_t *supported_gad_shapes)
{
    delete reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(supported_gad_shapes);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_supported_gad_shapes_toJSON(const data_collection_model_supported_gad_shapes_t *supported_gad_shapes, bool as_request)
{
    const std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(supported_gad_shapes);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_supported_gad_shapes_t *data_collection_model_supported_gad_shapes_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_supported_gad_shapes_t*>(new std::shared_ptr<SupportedGADShapes >(new SupportedGADShapes(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_supported_gad_shapes_is_equal_to(const data_collection_model_supported_gad_shapes_t *first, const data_collection_model_supported_gad_shapes_t *second)
{
    const std::shared_ptr<SupportedGADShapes > &obj1 = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(first);
    const std::shared_ptr<SupportedGADShapes > &obj2 = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_is_not_set(const data_collection_model_supported_gad_shapes_t *obj_supported_gad_shapes)
{
    const std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(obj_supported_gad_shapes);
    return obj->getValue() == SupportedGADShapes::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_is_non_standard(const data_collection_model_supported_gad_shapes_t *obj_supported_gad_shapes)
{
    const std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(obj_supported_gad_shapes);
    return obj->getValue() == SupportedGADShapes::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_supported_gad_shapes_e data_collection_model_supported_gad_shapes_get_enum(const data_collection_model_supported_gad_shapes_t *obj_supported_gad_shapes)
{
    const std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(obj_supported_gad_shapes);
    switch (obj->getValue()) {
    case SupportedGADShapes::Enum::NO_VAL:
        return DCM_SUPPORTED_GAD_SHAPES_NO_VAL;
    case SupportedGADShapes::Enum::VAL_POINT:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_POINT;
    case SupportedGADShapes::Enum::VAL_POINT_UNCERTAINTY_CIRCLE:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_UNCERTAINTY_CIRCLE;
    case SupportedGADShapes::Enum::VAL_POINT_UNCERTAINTY_ELLIPSE:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_UNCERTAINTY_ELLIPSE;
    case SupportedGADShapes::Enum::VAL_POLYGON:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_POLYGON;
    case SupportedGADShapes::Enum::VAL_POINT_ALTITUDE:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_ALTITUDE;
    case SupportedGADShapes::Enum::VAL_POINT_ALTITUDE_UNCERTAINTY:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_ALTITUDE_UNCERTAINTY;
    case SupportedGADShapes::Enum::VAL_ELLIPSOID_ARC:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_ELLIPSOID_ARC;
    case SupportedGADShapes::Enum::VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE;
    case SupportedGADShapes::Enum::VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID;
    case SupportedGADShapes::Enum::VAL_DISTANCE_DIRECTION:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_DISTANCE_DIRECTION;
    case SupportedGADShapes::Enum::VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE;
    case SupportedGADShapes::Enum::VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID:
        return DCM_SUPPORTED_GAD_SHAPES_VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID;
    default:
        break;
    }
    return DCM_SUPPORTED_GAD_SHAPES_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_supported_gad_shapes_get_string(const data_collection_model_supported_gad_shapes_t *obj_supported_gad_shapes)
{
    const std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<const std::shared_ptr<SupportedGADShapes >*>(obj_supported_gad_shapes);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_set_enum(data_collection_model_supported_gad_shapes_t *obj_supported_gad_shapes, data_collection_model_supported_gad_shapes_e p_value)
{
    std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(obj_supported_gad_shapes);
    switch (p_value) {
    case DCM_SUPPORTED_GAD_SHAPES_NO_VAL:
        *obj = SupportedGADShapes::Enum::NO_VAL;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_POINT:
        *obj = SupportedGADShapes::Enum::VAL_POINT;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_UNCERTAINTY_CIRCLE:
        *obj = SupportedGADShapes::Enum::VAL_POINT_UNCERTAINTY_CIRCLE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_UNCERTAINTY_ELLIPSE:
        *obj = SupportedGADShapes::Enum::VAL_POINT_UNCERTAINTY_ELLIPSE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_POLYGON:
        *obj = SupportedGADShapes::Enum::VAL_POLYGON;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_ALTITUDE:
        *obj = SupportedGADShapes::Enum::VAL_POINT_ALTITUDE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_POINT_ALTITUDE_UNCERTAINTY:
        *obj = SupportedGADShapes::Enum::VAL_POINT_ALTITUDE_UNCERTAINTY;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_ELLIPSOID_ARC:
        *obj = SupportedGADShapes::Enum::VAL_ELLIPSOID_ARC;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE:
        *obj = SupportedGADShapes::Enum::VAL_LOCAL_2_D_POINT_UNCERTAINTY_ELLIPSE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID:
        *obj = SupportedGADShapes::Enum::VAL_LOCAL_3_D_POINT_UNCERTAINTY_ELLIPSOID;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_DISTANCE_DIRECTION:
        *obj = SupportedGADShapes::Enum::VAL_DISTANCE_DIRECTION;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE:
        *obj = SupportedGADShapes::Enum::VAL_RELATIVE_2_D_LOCATION_UNCERTAINTY_ELLIPSE;
        return true;
    case DCM_SUPPORTED_GAD_SHAPES_VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID:
        *obj = SupportedGADShapes::Enum::VAL_RELATIVE_3_D_LOCATION_UNCERTAINTY_ELLIPSOID;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_supported_gad_shapes_set_string(data_collection_model_supported_gad_shapes_t *obj_supported_gad_shapes, const char *p_value)
{
    std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(obj_supported_gad_shapes);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = SupportedGADShapes::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_supported_gad_shapes_make_lnode(data_collection_model_supported_gad_shapes_t *p_supported_gad_shapes)
{
    return data_collection_lnode_create(p_supported_gad_shapes, reinterpret_cast<void(*)(void*)>(data_collection_model_supported_gad_shapes_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_supported_gad_shapes_refcount(data_collection_model_supported_gad_shapes_t *obj_supported_gad_shapes)
{
    std::shared_ptr<SupportedGADShapes > &obj = *reinterpret_cast<std::shared_ptr<SupportedGADShapes >*>(obj_supported_gad_shapes);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

