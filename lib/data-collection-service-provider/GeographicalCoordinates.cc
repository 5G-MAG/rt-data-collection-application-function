/**********************************************************************************************************************************
 * GeographicalCoordinates - C interface to the GeographicalCoordinates object
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

/*#include "GeographicalCoordinates.h" already included by data-collection-sp/data-collection.h */
#include "GeographicalCoordinates-internal.h"
#include "openapi/model/GeographicalCoordinates.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create(

)
{
    return reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates>(new GeographicalCoordinates(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_copy(const data_collection_model_geographical_coordinates_t *other)
{
    return reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates >(new GeographicalCoordinates(**reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_move(data_collection_model_geographical_coordinates_t *other)
{
    return reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates >(std::move(*reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_copy(data_collection_model_geographical_coordinates_t *geographical_coordinates, const data_collection_model_geographical_coordinates_t *other)
{
    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
    *obj = **reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(other);
    return geographical_coordinates;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, data_collection_model_geographical_coordinates_t *other)
{
    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
    obj = std::move(*reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(other));
    return geographical_coordinates;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_geographical_coordinates_free(data_collection_model_geographical_coordinates_t *geographical_coordinates)
{
    delete reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_geographical_coordinates_toJSON(const data_collection_model_geographical_coordinates_t *geographical_coordinates, bool as_request)
{
    const std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates >(new GeographicalCoordinates(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const double data_collection_model_geographical_coordinates_get_lon(const data_collection_model_geographical_coordinates_t *obj_geographical_coordinates)
{
    const std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    typedef typename GeographicalCoordinates::LonType ResultFromType;
    const ResultFromType result_from = obj->getLon();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, const double p_lon)
{
    if (obj_geographical_coordinates == NULL) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    const auto &value_from = p_lon;
    typedef typename GeographicalCoordinates::LonType ValueType;

    ValueType value = value_from;
    if (!obj->setLon(value)) return NULL;
    return obj_geographical_coordinates;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon_move(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, double p_lon)
{
    if (obj_geographical_coordinates == NULL) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    const auto &value_from = p_lon;
    typedef typename GeographicalCoordinates::LonType ValueType;

    ValueType value = value_from;
    
    if (!obj->setLon(std::move(value))) return NULL;
    return obj_geographical_coordinates;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const double data_collection_model_geographical_coordinates_get_lat(const data_collection_model_geographical_coordinates_t *obj_geographical_coordinates)
{
    const std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    typedef typename GeographicalCoordinates::LatType ResultFromType;
    const ResultFromType result_from = obj->getLat();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, const double p_lat)
{
    if (obj_geographical_coordinates == NULL) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    const auto &value_from = p_lat;
    typedef typename GeographicalCoordinates::LatType ValueType;

    ValueType value = value_from;
    if (!obj->setLat(value)) return NULL;
    return obj_geographical_coordinates;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat_move(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, double p_lat)
{
    if (obj_geographical_coordinates == NULL) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    const auto &value_from = p_lat;
    typedef typename GeographicalCoordinates::LatType ValueType;

    ValueType value = value_from;
    
    if (!obj->setLat(std::move(value))) return NULL;
    return obj_geographical_coordinates;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_geographical_coordinates_make_lnode(data_collection_model_geographical_coordinates_t *p_geographical_coordinates)
{
    return data_collection_lnode_create(p_geographical_coordinates, reinterpret_cast<void(*)(void*)>(data_collection_model_geographical_coordinates_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_geographical_coordinates_refcount(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates)
{
    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

