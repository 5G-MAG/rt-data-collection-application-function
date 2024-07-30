/**********************************************************************************************************************************
 * LocalOrigin - C interface to the LocalOrigin object
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

/*#include "LocalOrigin.h" already included by data-collection-sp/data-collection.h */
#include "LocalOrigin-internal.h"
#include "openapi/model/LocalOrigin.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_create(

)
{
    return reinterpret_cast<data_collection_model_local_origin_t*>(new std::shared_ptr<LocalOrigin>(new LocalOrigin(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_create_copy(const data_collection_model_local_origin_t *other)
{
    return reinterpret_cast<data_collection_model_local_origin_t*>(new std::shared_ptr<LocalOrigin >(new LocalOrigin(**reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_create_move(data_collection_model_local_origin_t *other)
{
    return reinterpret_cast<data_collection_model_local_origin_t*>(new std::shared_ptr<LocalOrigin >(std::move(*reinterpret_cast<std::shared_ptr<LocalOrigin >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_copy(data_collection_model_local_origin_t *local_origin, const data_collection_model_local_origin_t *other)
{
    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(local_origin);
    *obj = **reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(other);
    return local_origin;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_move(data_collection_model_local_origin_t *local_origin, data_collection_model_local_origin_t *other)
{
    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(local_origin);
    obj = std::move(*reinterpret_cast<std::shared_ptr<LocalOrigin >*>(other));
    return local_origin;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_local_origin_free(data_collection_model_local_origin_t *local_origin)
{
    delete reinterpret_cast<std::shared_ptr<LocalOrigin >*>(local_origin);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_local_origin_toJSON(const data_collection_model_local_origin_t *local_origin, bool as_request)
{
    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(local_origin);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_local_origin_t*>(new std::shared_ptr<LocalOrigin >(new LocalOrigin(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_local_origin_is_equal_to(const data_collection_model_local_origin_t *first, const data_collection_model_local_origin_t *second)
{
    const std::shared_ptr<LocalOrigin > &obj1 = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(first);
    const std::shared_ptr<LocalOrigin > &obj2 = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_local_origin_get_coordinate_id(const data_collection_model_local_origin_t *obj_local_origin)
{
    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    typedef typename LocalOrigin::CoordinateIdType ResultFromType;
    const ResultFromType result_from = obj->getCoordinateId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id(data_collection_model_local_origin_t *obj_local_origin, const char* p_coordinate_id)
{
    if (obj_local_origin == NULL) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    const auto &value_from = p_coordinate_id;
    typedef typename LocalOrigin::CoordinateIdType ValueType;

    ValueType value(value_from);
    if (!obj->setCoordinateId(value)) return NULL;
    return obj_local_origin;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id_move(data_collection_model_local_origin_t *obj_local_origin, char* p_coordinate_id)
{
    if (obj_local_origin == NULL) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    const auto &value_from = p_coordinate_id;
    typedef typename LocalOrigin::CoordinateIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setCoordinateId(std::move(value))) return NULL;
    return obj_local_origin;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_local_origin_get_point(const data_collection_model_local_origin_t *obj_local_origin)
{
    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    typedef typename LocalOrigin::PointType ResultFromType;
    const ResultFromType result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_set_point(data_collection_model_local_origin_t *obj_local_origin, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_local_origin == NULL) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    const auto &value_from = p_point;
    typedef typename LocalOrigin::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPoint(value)) return NULL;
    return obj_local_origin;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_local_origin_t *data_collection_model_local_origin_set_point_move(data_collection_model_local_origin_t *obj_local_origin, data_collection_model_geographical_coordinates_t* p_point)
{
    if (obj_local_origin == NULL) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    const auto &value_from = p_point;
    typedef typename LocalOrigin::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPoint(std::move(value))) return NULL;
    return obj_local_origin;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_local_origin_make_lnode(data_collection_model_local_origin_t *p_local_origin)
{
    return data_collection_lnode_create(p_local_origin, reinterpret_cast<void(*)(void*)>(data_collection_model_local_origin_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_local_origin_refcount(data_collection_model_local_origin_t *obj_local_origin)
{
    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

