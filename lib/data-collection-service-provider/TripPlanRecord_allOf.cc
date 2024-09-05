/**********************************************************************************************************************************
 * TripPlanRecord_allOf - C interface to the TripPlanRecord_allOf object
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

/*#include "TripPlanRecord_allOf.h" already included by data-collection-sp/data-collection.h */
#include "TripPlanRecord_allOf-internal.h"
#include "openapi/model/TripPlanRecord_allOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_create(




)
{
    return reinterpret_cast<data_collection_model_trip_plan_record_all_of_t*>(new std::shared_ptr<TripPlanRecord_allOf>(new TripPlanRecord_allOf(




)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_create_copy(const data_collection_model_trip_plan_record_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_trip_plan_record_all_of_t*>(new std::shared_ptr<TripPlanRecord_allOf >(new TripPlanRecord_allOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_create_move(data_collection_model_trip_plan_record_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > *obj = reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_copy(data_collection_model_trip_plan_record_all_of_t *trip_plan_record_all_of, const data_collection_model_trip_plan_record_all_of_t *other)
{
    if (trip_plan_record_all_of) {
        std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(trip_plan_record_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<TripPlanRecord_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(other);
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
                const std::shared_ptr<TripPlanRecord_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new TripPlanRecord_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        trip_plan_record_all_of = data_collection_model_trip_plan_record_all_of_create_copy(other);
    }
    return trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_move(data_collection_model_trip_plan_record_all_of_t *trip_plan_record_all_of, data_collection_model_trip_plan_record_all_of_t *other)
{
    std::shared_ptr<TripPlanRecord_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(other);

    if (trip_plan_record_all_of) {
        std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(trip_plan_record_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                trip_plan_record_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_trip_plan_record_all_of_free(data_collection_model_trip_plan_record_all_of_t *trip_plan_record_all_of)
{
    if (!trip_plan_record_all_of) return;
    delete reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(trip_plan_record_all_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_trip_plan_record_all_of_toJSON(const data_collection_model_trip_plan_record_all_of_t *trip_plan_record_all_of, bool as_request)
{
    if (!trip_plan_record_all_of) return NULL;
    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(trip_plan_record_all_of);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_trip_plan_record_all_of_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_trip_plan_record_all_of_t*>(new std::shared_ptr<TripPlanRecord_allOf >(new TripPlanRecord_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_all_of_is_equal_to(const data_collection_model_trip_plan_record_all_of_t *first, const data_collection_model_trip_plan_record_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<TripPlanRecord_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<TripPlanRecord_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_all_of_get_starting_point(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord_allOf::StartingPointType ResultFromType;
    const ResultFromType result_from = obj->getStartingPoint();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_starting_point(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, const data_collection_model_location_data_t* p_starting_point)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_starting_point;
    typedef typename TripPlanRecord_allOf::StartingPointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setStartingPoint(value)) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_starting_point_move(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, data_collection_model_location_data_t* p_starting_point)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_starting_point;
    typedef typename TripPlanRecord_allOf::StartingPointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setStartingPoint(std::move(value))) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_all_of_has_waypoints(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) return false;

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return false;

    return obj->getWaypoints().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_trip_plan_record_all_of_get_waypoints(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord_allOf::WaypointsType ResultFromType;
    const ResultFromType result_from = obj->getWaypoints();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_location_data_t *item_obj = reinterpret_cast<data_collection_model_location_data_t*>(item.has_value()?new std::shared_ptr<LocationData >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_location_data_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_waypoints(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, const ogs_list_t* p_waypoints)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_waypoints;
    typedef typename TripPlanRecord_allOf::WaypointsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setWaypoints(value)) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_waypoints_move(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, ogs_list_t* p_waypoints)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_waypoints;
    typedef typename TripPlanRecord_allOf::WaypointsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_waypoints);
    if (!obj->setWaypoints(std::move(value))) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_add_waypoints(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, data_collection_model_location_data_t* p_waypoints)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    typedef typename TripPlanRecord_allOf::WaypointsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_waypoints;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addWaypoints(value.value());
    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_remove_waypoints(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, const data_collection_model_location_data_t* p_waypoints)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    typedef typename TripPlanRecord_allOf::WaypointsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_waypoints;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeWaypoints(value);
    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_clear_waypoints(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    obj->clearWaypoints();
    return obj_trip_plan_record_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_all_of_get_destination(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord_allOf::DestinationType ResultFromType;
    const ResultFromType result_from = obj->getDestination();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_destination(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, const data_collection_model_location_data_t* p_destination)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_destination;
    typedef typename TripPlanRecord_allOf::DestinationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setDestination(value)) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_destination_move(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, data_collection_model_location_data_t* p_destination)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_destination;
    typedef typename TripPlanRecord_allOf::DestinationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setDestination(std::move(value))) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_all_of_has_estimated_average_speed(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) return false;

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return false;

    return obj->getEstimatedAverageSpeed().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_trip_plan_record_all_of_get_estimated_average_speed(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename TripPlanRecord_allOf::EstimatedAverageSpeedType ResultFromType;
    const ResultFromType result_from = obj->getEstimatedAverageSpeed();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_estimated_average_speed(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, const float p_estimated_average_speed)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_average_speed;
    typedef typename TripPlanRecord_allOf::EstimatedAverageSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setEstimatedAverageSpeed(value)) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_estimated_average_speed_move(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, float p_estimated_average_speed)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_average_speed;
    typedef typename TripPlanRecord_allOf::EstimatedAverageSpeedType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEstimatedAverageSpeed(std::move(value))) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_all_of_has_estimated_arrival_time(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) return false;

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return false;

    return obj->getEstimatedArrivalTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_all_of_get_estimated_arrival_time(const data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord_allOf::EstimatedArrivalTimeType ResultFromType;
    const ResultFromType result_from = obj->getEstimatedArrivalTime();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_estimated_arrival_time(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, const char* p_estimated_arrival_time)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_arrival_time;
    typedef typename TripPlanRecord_allOf::EstimatedArrivalTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setEstimatedArrivalTime(value)) return NULL;

    return obj_trip_plan_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_all_of_t *data_collection_model_trip_plan_record_all_of_set_estimated_arrival_time_move(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of, char* p_estimated_arrival_time)
{
    if (!obj_trip_plan_record_all_of) return NULL;

    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_arrival_time;
    typedef typename TripPlanRecord_allOf::EstimatedArrivalTimeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEstimatedArrivalTime(std::move(value))) return NULL;

    return obj_trip_plan_record_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_trip_plan_record_all_of_make_lnode(data_collection_model_trip_plan_record_all_of_t *p_trip_plan_record_all_of)
{
    return data_collection_lnode_create(p_trip_plan_record_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_trip_plan_record_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_trip_plan_record_all_of_refcount(data_collection_model_trip_plan_record_all_of_t *obj_trip_plan_record_all_of)
{
    if (!obj_trip_plan_record_all_of) return 0l;
    std::shared_ptr<TripPlanRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord_allOf >*>(obj_trip_plan_record_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

