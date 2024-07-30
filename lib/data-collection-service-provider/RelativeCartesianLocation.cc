/**********************************************************************************************************************************
 * RelativeCartesianLocation - C interface to the RelativeCartesianLocation object
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

/*#include "RelativeCartesianLocation.h" already included by data-collection-sp/data-collection.h */
#include "RelativeCartesianLocation-internal.h"
#include "openapi/model/RelativeCartesianLocation.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create(


)
{
    return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation>(new RelativeCartesianLocation(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_copy(const data_collection_model_relative_cartesian_location_t *other)
{
    return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation >(new RelativeCartesianLocation(**reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_move(data_collection_model_relative_cartesian_location_t *other)
{
    return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation >(std::move(*reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_copy(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const data_collection_model_relative_cartesian_location_t *other)
{
    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
    *obj = **reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(other);
    return relative_cartesian_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, data_collection_model_relative_cartesian_location_t *other)
{
    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
    obj = std::move(*reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(other));
    return relative_cartesian_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_relative_cartesian_location_free(data_collection_model_relative_cartesian_location_t *relative_cartesian_location)
{
    delete reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_relative_cartesian_location_toJSON(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location, bool as_request)
{
    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation >(new RelativeCartesianLocation(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_relative_cartesian_location_is_equal_to(const data_collection_model_relative_cartesian_location_t *first, const data_collection_model_relative_cartesian_location_t *second)
{
    const std::shared_ptr<RelativeCartesianLocation > &obj1 = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(first);
    const std::shared_ptr<RelativeCartesianLocation > &obj2 = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_relative_cartesian_location_get_x(const data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    typedef typename RelativeCartesianLocation::xType ResultFromType;
    const ResultFromType result_from = obj->getX();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, const float p_x)
{
    if (obj_relative_cartesian_location == NULL) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    const auto &value_from = p_x;
    typedef typename RelativeCartesianLocation::xType ValueType;

    ValueType value = value_from;
    if (!obj->setX(value)) return NULL;
    return obj_relative_cartesian_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x_move(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, float p_x)
{
    if (obj_relative_cartesian_location == NULL) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    const auto &value_from = p_x;
    typedef typename RelativeCartesianLocation::xType ValueType;

    ValueType value = value_from;
    
    if (!obj->setX(std::move(value))) return NULL;
    return obj_relative_cartesian_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_relative_cartesian_location_get_y(const data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    typedef typename RelativeCartesianLocation::yType ResultFromType;
    const ResultFromType result_from = obj->getY();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, const float p_y)
{
    if (obj_relative_cartesian_location == NULL) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    const auto &value_from = p_y;
    typedef typename RelativeCartesianLocation::yType ValueType;

    ValueType value = value_from;
    if (!obj->setY(value)) return NULL;
    return obj_relative_cartesian_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y_move(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, float p_y)
{
    if (obj_relative_cartesian_location == NULL) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    const auto &value_from = p_y;
    typedef typename RelativeCartesianLocation::yType ValueType;

    ValueType value = value_from;
    
    if (!obj->setY(std::move(value))) return NULL;
    return obj_relative_cartesian_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_relative_cartesian_location_get_z(const data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    typedef typename RelativeCartesianLocation::zType ResultFromType;
    const ResultFromType result_from = obj->getZ();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, const float p_z)
{
    if (obj_relative_cartesian_location == NULL) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    const auto &value_from = p_z;
    typedef typename RelativeCartesianLocation::zType ValueType;

    ValueType value = value_from;
    if (!obj->setZ(value)) return NULL;
    return obj_relative_cartesian_location;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z_move(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, float p_z)
{
    if (obj_relative_cartesian_location == NULL) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    const auto &value_from = p_z;
    typedef typename RelativeCartesianLocation::zType ValueType;

    ValueType value = value_from;
    
    if (!obj->setZ(std::move(value))) return NULL;
    return obj_relative_cartesian_location;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_relative_cartesian_location_make_lnode(data_collection_model_relative_cartesian_location_t *p_relative_cartesian_location)
{
    return data_collection_lnode_create(p_relative_cartesian_location, reinterpret_cast<void(*)(void*)>(data_collection_model_relative_cartesian_location_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_relative_cartesian_location_refcount(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

