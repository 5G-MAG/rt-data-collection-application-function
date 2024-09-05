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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "TripPlanRecord.h" already included by data-collection-sp/data-collection.h */
#include "TripPlanRecord-internal.h"
#include "openapi/model/TripPlanRecord.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create(






)
{
    return reinterpret_cast<data_collection_model_trip_plan_record_t*>(new std::shared_ptr<TripPlanRecord>(new TripPlanRecord(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_copy(const data_collection_model_trip_plan_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_trip_plan_record_t*>(new std::shared_ptr<TripPlanRecord >(new TripPlanRecord(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_create_move(data_collection_model_trip_plan_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<TripPlanRecord > *obj = reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_copy(data_collection_model_trip_plan_record_t *trip_plan_record, const data_collection_model_trip_plan_record_t *other)
{
    if (trip_plan_record) {
        std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<TripPlanRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(other);
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
                const std::shared_ptr<TripPlanRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(other);
                if (other_obj) {
                    obj.reset(new TripPlanRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        trip_plan_record = data_collection_model_trip_plan_record_create_copy(other);
    }
    return trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_move(data_collection_model_trip_plan_record_t *trip_plan_record, data_collection_model_trip_plan_record_t *other)
{
    std::shared_ptr<TripPlanRecord > *other_ptr = reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(other);

    if (trip_plan_record) {
        std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                trip_plan_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_trip_plan_record_free(data_collection_model_trip_plan_record_t *trip_plan_record)
{
    if (!trip_plan_record) return;
    delete reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_trip_plan_record_toJSON(const data_collection_model_trip_plan_record_t *trip_plan_record, bool as_request)
{
    if (!trip_plan_record) return NULL;
    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(trip_plan_record);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_trip_plan_record_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_is_equal_to(const data_collection_model_trip_plan_record_t *first, const data_collection_model_trip_plan_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<TripPlanRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<TripPlanRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_get_timestamp(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const char* p_timestamp)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename TripPlanRecord::TimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimestamp(value)) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_timestamp_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, char* p_timestamp)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename TripPlanRecord::TimestampType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTimestamp(std::move(value))) return NULL;

    return obj_trip_plan_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_trip_plan_record_get_context_ids(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const ogs_list_t* p_context_ids)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename TripPlanRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(value)) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_context_ids_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, ogs_list_t* p_context_ids)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename TripPlanRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record, char* p_context_ids)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    typedef typename TripPlanRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);


    obj->addContextIds(value);
    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const char* p_context_ids)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    typedef typename TripPlanRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);

    obj->removeContextIds(value);
    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_context_ids(data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_trip_plan_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_starting_point(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord::StartingPointType ResultFromType;
    const ResultFromType result_from = obj->getStartingPoint();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const data_collection_model_location_data_t* p_starting_point)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_starting_point;
    typedef typename TripPlanRecord::StartingPointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setStartingPoint(value)) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_starting_point_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, data_collection_model_location_data_t* p_starting_point)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_starting_point;
    typedef typename TripPlanRecord::StartingPointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setStartingPoint(std::move(value))) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_has_waypoints(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) return false;

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return false;

    return obj->getWaypoints().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_trip_plan_record_get_waypoints(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord::WaypointsType ResultFromType;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const ogs_list_t* p_waypoints)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_waypoints;
    typedef typename TripPlanRecord::WaypointsType ValueType;

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

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_waypoints_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, ogs_list_t* p_waypoints)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_waypoints;
    typedef typename TripPlanRecord::WaypointsType ValueType;

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

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_add_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record, data_collection_model_location_data_t* p_waypoints)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    typedef typename TripPlanRecord::WaypointsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_waypoints;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addWaypoints(value.value());
    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_remove_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const data_collection_model_location_data_t* p_waypoints)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    typedef typename TripPlanRecord::WaypointsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_waypoints;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeWaypoints(value);
    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_clear_waypoints(data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    obj->clearWaypoints();
    return obj_trip_plan_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_trip_plan_record_get_destination(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) {
        const data_collection_model_location_data_t *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord::DestinationType ResultFromType;
    const ResultFromType result_from = obj->getDestination();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const data_collection_model_location_data_t* p_destination)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_destination;
    typedef typename TripPlanRecord::DestinationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setDestination(value)) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_destination_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, data_collection_model_location_data_t* p_destination)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_destination;
    typedef typename TripPlanRecord::DestinationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setDestination(std::move(value))) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_has_estimated_average_speed(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) return false;

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return false;

    return obj->getEstimatedAverageSpeed().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_trip_plan_record_get_estimated_average_speed(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename TripPlanRecord::EstimatedAverageSpeedType ResultFromType;
    const ResultFromType result_from = obj->getEstimatedAverageSpeed();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const float p_estimated_average_speed)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_average_speed;
    typedef typename TripPlanRecord::EstimatedAverageSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setEstimatedAverageSpeed(value)) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_average_speed_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, float p_estimated_average_speed)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_average_speed;
    typedef typename TripPlanRecord::EstimatedAverageSpeedType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEstimatedAverageSpeed(std::move(value))) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_trip_plan_record_has_estimated_arrival_time(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) return false;

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return false;

    return obj->getEstimatedArrivalTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_trip_plan_record_get_estimated_arrival_time(const data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<const std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename TripPlanRecord::EstimatedArrivalTimeType ResultFromType;
    const ResultFromType result_from = obj->getEstimatedArrivalTime();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time(data_collection_model_trip_plan_record_t *obj_trip_plan_record, const char* p_estimated_arrival_time)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_arrival_time;
    typedef typename TripPlanRecord::EstimatedArrivalTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setEstimatedArrivalTime(value)) return NULL;

    return obj_trip_plan_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_trip_plan_record_t *data_collection_model_trip_plan_record_set_estimated_arrival_time_move(data_collection_model_trip_plan_record_t *obj_trip_plan_record, char* p_estimated_arrival_time)
{
    if (!obj_trip_plan_record) return NULL;

    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    if (!obj) return NULL;

    const auto &value_from = p_estimated_arrival_time;
    typedef typename TripPlanRecord::EstimatedArrivalTimeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setEstimatedArrivalTime(std::move(value))) return NULL;

    return obj_trip_plan_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_trip_plan_record_make_lnode(data_collection_model_trip_plan_record_t *p_trip_plan_record)
{
    return data_collection_lnode_create(p_trip_plan_record, reinterpret_cast<void(*)(void*)>(data_collection_model_trip_plan_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_trip_plan_record_refcount(data_collection_model_trip_plan_record_t *obj_trip_plan_record)
{
    if (!obj_trip_plan_record) return 0l;
    std::shared_ptr<TripPlanRecord > &obj = *reinterpret_cast<std::shared_ptr<TripPlanRecord >*>(obj_trip_plan_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

