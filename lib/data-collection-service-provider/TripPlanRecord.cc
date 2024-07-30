/**********************************************************************************************************************************
 * TripPlanRecord - C interface to the TripPlanRecord object
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

/*#include "TripPlanRecord.h" already included by data-collection-sp/data-collection.h */
#include "TripPlanRecord-internal.h"
#include "openapi/model/TripPlanRecord.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create(






)
{
    return reinterpret_cast<data_collection_model_trip_plan_record_t*>(new std::shared_ptr<TripPlanRecord>(new TripPlanRecord(






)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_copy(const data_collection_model_trip_plan_record_t *other)
{
    return reinterpret_cast<data_collection_model_trip_plan_record_t*>(new std::shared_ptr<TripPlanRecord >(new TripPlanRecord(**reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_move(data_collection_model_trip_plan_record_t *other)
{
    return reinterpret_cast<data_collection_model_trip_plan_record_t*>(new std::shared_ptr<TripPlanRecord >(std::move(*reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_copy(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_trip_plan_record_t *other)
{
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
    *obj = **reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(other);
    return trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_trip_plan_record_t *other)
{
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
    obj = std::move(*reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(other));
    return trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_trip_plan_record_free(data_collection_model_trip_plan_record_t *trip_plan_record)
{
    delete reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_trip_plan_record_toJSON(const data_collection_model_trip_plan_record_t *trip_plan_record, bool as_request)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_trip_plan_record_t*>(new std::shared_ptr<TripPlanRecord >(new TripPlanRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_trip_plan_record_is_equal_to(const data_collection_model_trip_plan_record_t *first, const data_collection_model_trip_plan_record_t *second)
{
    const std::shared_ptr<TripPlanRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(first);
    const std::shared_ptr<TripPlanRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_trip_plan_record_get_timestamp(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const char* p_timestamp)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_timestamp;
    typedef typename TripPlanRecord::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, char* p_timestamp)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_timestamp;
    typedef typename TripPlanRecord::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_trip_plan_record_get_context_ids(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const ogs_list_t* p_context_ids)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_context_ids;
    typedef typename TripPlanRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, ogs_list_t* p_context_ids)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_context_ids;
    typedef typename TripPlanRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record, char* p_context_ids)
{
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const char* p_context_ids)
{
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{   
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    obj->clearContextIds();
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_starting_point(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::StartingPointType ResultFromType;
    const ResultFromType result_from = obj->getStartingPoint();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const data_collection_model_location_data_t* p_starting_point)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_starting_point;
    typedef typename TripPlanRecord::StartingPointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setStartingPoint(value)) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, data_collection_model_location_data_t* p_starting_point)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_starting_point;
    typedef typename TripPlanRecord::StartingPointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setStartingPoint(std::move(value))) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_trip_plan_record_get_waypoints(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::WaypointsType ResultFromType;
    const ResultFromType result_from = obj->getWaypoints();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_location_data_t *item_obj = reinterpret_cast<data_collection_model_location_data_t*>(new std::shared_ptr<LocationData >(item));
        node = data_collection_model_location_data_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const ogs_list_t* p_waypoints)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_waypoints;
    typedef typename TripPlanRecord::WaypointsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setWaypoints(value)) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, ogs_list_t* p_waypoints)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_waypoints;
    typedef typename TripPlanRecord::WaypointsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_waypoints);
    if (!obj->setWaypoints(std::move(value))) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record, data_collection_model_location_data_t* p_waypoints)
{
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::WaypointsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_waypoints;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addWaypoints(value);
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const data_collection_model_location_data_t* p_waypoints)
{
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::WaypointsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_waypoints;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeWaypoints(value);
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{   
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    obj->clearWaypoints();
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_destination(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::DestinationType ResultFromType;
    const ResultFromType result_from = obj->getDestination();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const data_collection_model_location_data_t* p_destination)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_destination;
    typedef typename TripPlanRecord::DestinationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDestination(value)) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, data_collection_model_location_data_t* p_destination)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_destination;
    typedef typename TripPlanRecord::DestinationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDestination(std::move(value))) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_trip_plan_record_get_estimated_average_speed(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::EstimatedAverageSpeedType ResultFromType;
    const ResultFromType result_from = obj->getEstimatedAverageSpeed();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const float p_estimated_average_speed)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_estimated_average_speed;
    typedef typename TripPlanRecord::EstimatedAverageSpeedType ValueType;

    ValueType value = value_from;
    if (!obj->setEstimatedAverageSpeed(value)) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, float p_estimated_average_speed)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_estimated_average_speed;
    typedef typename TripPlanRecord::EstimatedAverageSpeedType ValueType;

    ValueType value = value_from;
    
    if (!obj->setEstimatedAverageSpeed(std::move(value))) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_trip_plan_record_get_estimated_arrival_time(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    typedef typename TripPlanRecord::EstimatedArrivalTimeType ResultFromType;
    const ResultFromType result_from = obj->getEstimatedArrivalTime();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const char* p_estimated_arrival_time)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_estimated_arrival_time;
    typedef typename TripPlanRecord::EstimatedArrivalTimeType ValueType;

    ValueType value(value_from);
    if (!obj->setEstimatedArrivalTime(value)) return NULL;
    return obj_trip_plan_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, char* p_estimated_arrival_time)
{
    if (obj_trip_plan_record == NULL) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    const auto &value_from = p_estimated_arrival_time;
    typedef typename TripPlanRecord::EstimatedArrivalTimeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setEstimatedArrivalTime(std::move(value))) return NULL;
    return obj_trip_plan_record;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_trip_plan_record_make_lnode(data_collection_model_trip_plan_record_t *p_trip_plan_record)
{
    return data_collection_lnode_create(p_trip_plan_record, reinterpret_cast<void(*)(void*)>(data_collection_model_trip_plan_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_trip_plan_record_refcount(data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

