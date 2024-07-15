/**********************************************************************************************************************************
 * PointAltitude - C interface to the PointAltitude object
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

/*#include "PointAltitude.h" already included by data-collection-sp/data-collection.h */
#include "PointAltitude-internal.h"
#include "openapi/model/PointAltitude.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_create(


)
{
    return reinterpret_cast<data_collection_model_point_altitude_t*>(new std::shared_ptr<PointAltitude>(new PointAltitude(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_create_copy(const data_collection_model_point_altitude_t *other)
{
    return reinterpret_cast<data_collection_model_point_altitude_t*>(new std::shared_ptr<PointAltitude >(new PointAltitude(**reinterpret_cast<const std::shared_ptr<PointAltitude >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_create_move(data_collection_model_point_altitude_t *other)
{
    return reinterpret_cast<data_collection_model_point_altitude_t*>(new std::shared_ptr<PointAltitude >(std::move(*reinterpret_cast<std::shared_ptr<PointAltitude >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_copy(data_collection_model_point_altitude_t *point_altitude, const data_collection_model_point_altitude_t *other)
{
    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(point_altitude);
    *obj = **reinterpret_cast<const std::shared_ptr<PointAltitude >*>(other);
    return point_altitude;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_move(data_collection_model_point_altitude_t *point_altitude, data_collection_model_point_altitude_t *other)
{
    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(point_altitude);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PointAltitude >*>(other));
    return point_altitude;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_point_altitude_free(data_collection_model_point_altitude_t *point_altitude)
{
    delete reinterpret_cast<std::shared_ptr<PointAltitude >*>(point_altitude);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_point_altitude_toJSON(const data_collection_model_point_altitude_t *point_altitude, bool as_request)
{
    const std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitude >*>(point_altitude);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_point_altitude_t*>(new std::shared_ptr<PointAltitude >(new PointAltitude(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_supported_gad_shapes_t* data_collection_model_point_altitude_get_shape(const data_collection_model_point_altitude_t *obj_point_altitude)
{
    const std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    typedef typename PointAltitude::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_shape(data_collection_model_point_altitude_t *obj_point_altitude, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_point_altitude == NULL) return NULL;

    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    const auto &value_from = p_shape;
    typedef typename PointAltitude::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;
    return obj_point_altitude;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_shape_move(data_collection_model_point_altitude_t *obj_point_altitude, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_point_altitude == NULL) return NULL;

    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    const auto &value_from = p_shape;
    typedef typename PointAltitude::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;
    return obj_point_altitude;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_get_point(const data_collection_model_point_altitude_t *obj_point_altitude)
{
    const std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    typedef typename PointAltitude::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_point(data_collection_model_point_altitude_t *obj_point_altitude, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point_altitude == NULL) return NULL;

    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    const auto &value_from = p_point;
    typedef typename PointAltitude::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;
    return obj_point_altitude;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_point_move(data_collection_model_point_altitude_t *obj_point_altitude, data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point_altitude == NULL) return NULL;

    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    const auto &value_from = p_point;
    typedef typename PointAltitude::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;
    return obj_point_altitude;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const double data_collection_model_point_altitude_get_altitude(const data_collection_model_point_altitude_t *obj_point_altitude)
{
    const std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    typedef typename PointAltitude::AltitudeType ResultFromType;
    const ResultFromType result_from = obj->getAltitude();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_altitude(data_collection_model_point_altitude_t *obj_point_altitude, const double p_altitude)
{
    if (obj_point_altitude == NULL) return NULL;

    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    const auto &value_from = p_altitude;
    typedef typename PointAltitude::AltitudeType ValueType;

    ValueType value = value_from;
    if (!obj->setAltitude(value)) return NULL;
    return obj_point_altitude;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_t *data_collection_model_point_altitude_set_altitude_move(data_collection_model_point_altitude_t *obj_point_altitude, double p_altitude)
{
    if (obj_point_altitude == NULL) return NULL;

    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    const auto &value_from = p_altitude;
    typedef typename PointAltitude::AltitudeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAltitude(std::move(value))) return NULL;
    return obj_point_altitude;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_point_altitude_make_lnode(data_collection_model_point_altitude_t *p_point_altitude)
{
    return data_collection_lnode_create(p_point_altitude, reinterpret_cast<void(*)(void*)>(data_collection_model_point_altitude_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_altitude_refcount(data_collection_model_point_altitude_t *obj_point_altitude)
{
    std::shared_ptr<PointAltitude > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude >*>(obj_point_altitude);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

