/**********************************************************************************************************************************
 * PerUeAttribute - C interface to the PerUeAttribute object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "PerUeAttribute.h" already included by data-collection-sp/data-collection.h */
#include "PerUeAttribute-internal.h"
#include "openapi/model/PerUeAttribute.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create(



)
{
    return reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute>(new PerUeAttribute(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_copy(const data_collection_model_per_ue_attribute_t *other)
{
    return reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute >(new PerUeAttribute(**reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_move(data_collection_model_per_ue_attribute_t *other)
{
    return reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute >(std::move(*reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_copy(data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_per_ue_attribute_t *other)
{
    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
    *obj = **reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(other);
    return per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, data_collection_model_per_ue_attribute_t *other)
{
    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(other));
    return per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_per_ue_attribute_free(data_collection_model_per_ue_attribute_t *per_ue_attribute)
{
    delete reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_per_ue_attribute_toJSON(const data_collection_model_per_ue_attribute_t *per_ue_attribute, bool as_request)
{
    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute >(new PerUeAttribute(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_area5_g_t* data_collection_model_per_ue_attribute_get_ue_dest(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    typedef typename PerUeAttribute::UeDestType ResultFromType;
    const ResultFromType result_from = obj->getUeDest();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const data_collection_model_location_area5_g_t* p_ue_dest)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_ue_dest;
    typedef typename PerUeAttribute::UeDestType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUeDest(value)) return NULL;
    return obj_per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, data_collection_model_location_area5_g_t* p_ue_dest)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_ue_dest;
    typedef typename PerUeAttribute::UeDestType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUeDest(std::move(value))) return NULL;
    return obj_per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_per_ue_attribute_get_route(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    typedef typename PerUeAttribute::RouteType ResultFromType;
    const ResultFromType result_from = obj->getRoute();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const char* p_route)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_route;
    typedef typename PerUeAttribute::RouteType ValueType;

    ValueType value(value_from);
    if (!obj->setRoute(value)) return NULL;
    return obj_per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, char* p_route)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_route;
    typedef typename PerUeAttribute::RouteType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRoute(std::move(value))) return NULL;
    return obj_per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_per_ue_attribute_get_avg_speed(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    typedef typename PerUeAttribute::AvgSpeedType ResultFromType;
    const ResultFromType result_from = obj->getAvgSpeed();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const char* p_avg_speed)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_avg_speed;
    typedef typename PerUeAttribute::AvgSpeedType ValueType;

    ValueType value(value_from);
    if (!obj->setAvgSpeed(value)) return NULL;
    return obj_per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, char* p_avg_speed)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_avg_speed;
    typedef typename PerUeAttribute::AvgSpeedType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAvgSpeed(std::move(value))) return NULL;
    return obj_per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_per_ue_attribute_get_time_of_arrival(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    typedef typename PerUeAttribute::TimeOfArrivalType ResultFromType;
    const ResultFromType result_from = obj->getTimeOfArrival();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const char* p_time_of_arrival)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_time_of_arrival;
    typedef typename PerUeAttribute::TimeOfArrivalType ValueType;

    ValueType value(value_from);
    if (!obj->setTimeOfArrival(value)) return NULL;
    return obj_per_ue_attribute;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, char* p_time_of_arrival)
{
    if (obj_per_ue_attribute == NULL) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    const auto &value_from = p_time_of_arrival;
    typedef typename PerUeAttribute::TimeOfArrivalType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimeOfArrival(std::move(value))) return NULL;
    return obj_per_ue_attribute;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_per_ue_attribute_make_lnode(data_collection_model_per_ue_attribute_t *p_per_ue_attribute)
{
    return data_collection_lnode_create(p_per_ue_attribute, reinterpret_cast<void(*)(void*)>(data_collection_model_per_ue_attribute_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_per_ue_attribute_refcount(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

