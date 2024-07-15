/**********************************************************************************************************************************
 * PointAltitude_allOf - C interface to the PointAltitude_allOf object
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

/*#include "PointAltitude_allOf.h" already included by data-collection-sp/data-collection.h */
#include "PointAltitude_allOf-internal.h"
#include "openapi/model/PointAltitude_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_create(

)
{
    return reinterpret_cast<data_collection_model_point_altitude_all_of_t*>(new std::shared_ptr<PointAltitude_allOf>(new PointAltitude_allOf(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_create_copy(const data_collection_model_point_altitude_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_point_altitude_all_of_t*>(new std::shared_ptr<PointAltitude_allOf >(new PointAltitude_allOf(**reinterpret_cast<const std::shared_ptr<PointAltitude_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_create_move(data_collection_model_point_altitude_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_point_altitude_all_of_t*>(new std::shared_ptr<PointAltitude_allOf >(std::move(*reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_copy(data_collection_model_point_altitude_all_of_t *point_altitude_all_of, const data_collection_model_point_altitude_all_of_t *other)
{
    std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(point_altitude_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<PointAltitude_allOf >*>(other);
    return point_altitude_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_move(data_collection_model_point_altitude_all_of_t *point_altitude_all_of, data_collection_model_point_altitude_all_of_t *other)
{
    std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(point_altitude_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(other));
    return point_altitude_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_point_altitude_all_of_free(data_collection_model_point_altitude_all_of_t *point_altitude_all_of)
{
    delete reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(point_altitude_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_point_altitude_all_of_toJSON(const data_collection_model_point_altitude_all_of_t *point_altitude_all_of, bool as_request)
{
    const std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitude_allOf >*>(point_altitude_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_point_altitude_all_of_t*>(new std::shared_ptr<PointAltitude_allOf >(new PointAltitude_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_point_altitude_all_of_get_point(const data_collection_model_point_altitude_all_of_t *obj_point_altitude_all_of)
{
    const std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitude_allOf >*>(obj_point_altitude_all_of);
    typedef typename PointAltitude_allOf::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_set_point(data_collection_model_point_altitude_all_of_t *obj_point_altitude_all_of, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point_altitude_all_of == NULL) return NULL;

    std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(obj_point_altitude_all_of);
    const auto &value_from = p_point;
    typedef typename PointAltitude_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;
    return obj_point_altitude_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_set_point_move(data_collection_model_point_altitude_all_of_t *obj_point_altitude_all_of, data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_point_altitude_all_of == NULL) return NULL;

    std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(obj_point_altitude_all_of);
    const auto &value_from = p_point;
    typedef typename PointAltitude_allOf::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;
    return obj_point_altitude_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const double data_collection_model_point_altitude_all_of_get_altitude(const data_collection_model_point_altitude_all_of_t *obj_point_altitude_all_of)
{
    const std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PointAltitude_allOf >*>(obj_point_altitude_all_of);
    typedef typename PointAltitude_allOf::AltitudeType ResultFromType;
    const ResultFromType result_from = obj->getAltitude();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_set_altitude(data_collection_model_point_altitude_all_of_t *obj_point_altitude_all_of, const double p_altitude)
{
    if (obj_point_altitude_all_of == NULL) return NULL;

    std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(obj_point_altitude_all_of);
    const auto &value_from = p_altitude;
    typedef typename PointAltitude_allOf::AltitudeType ValueType;

    ValueType value = value_from;
    if (!obj->setAltitude(value)) return NULL;
    return obj_point_altitude_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_point_altitude_all_of_t *data_collection_model_point_altitude_all_of_set_altitude_move(data_collection_model_point_altitude_all_of_t *obj_point_altitude_all_of, double p_altitude)
{
    if (obj_point_altitude_all_of == NULL) return NULL;

    std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(obj_point_altitude_all_of);
    const auto &value_from = p_altitude;
    typedef typename PointAltitude_allOf::AltitudeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAltitude(std::move(value))) return NULL;
    return obj_point_altitude_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_point_altitude_all_of_make_lnode(data_collection_model_point_altitude_all_of_t *p_point_altitude_all_of)
{
    return data_collection_lnode_create(p_point_altitude_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_point_altitude_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_point_altitude_all_of_refcount(data_collection_model_point_altitude_all_of_t *obj_point_altitude_all_of)
{
    std::shared_ptr<PointAltitude_allOf > &obj = *reinterpret_cast<std::shared_ptr<PointAltitude_allOf >*>(obj_point_altitude_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

