/**********************************************************************************************************************************
 * ScheduledCommunicationTime - C interface to the ScheduledCommunicationTime object
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

/*#include "ScheduledCommunicationTime.h" already included by data-collection-sp/data-collection.h */
#include "ScheduledCommunicationTime-internal.h"
#include "openapi/model/ScheduledCommunicationTime.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create(


)
{
    return reinterpret_cast<data_collection_model_scheduled_communication_time_t*>(new std::shared_ptr<ScheduledCommunicationTime>(new ScheduledCommunicationTime(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_copy(const data_collection_model_scheduled_communication_time_t *other)
{
    return reinterpret_cast<data_collection_model_scheduled_communication_time_t*>(new std::shared_ptr<ScheduledCommunicationTime >(new ScheduledCommunicationTime(**reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_move(data_collection_model_scheduled_communication_time_t *other)
{
    return reinterpret_cast<data_collection_model_scheduled_communication_time_t*>(new std::shared_ptr<ScheduledCommunicationTime >(std::move(*reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_copy(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const data_collection_model_scheduled_communication_time_t *other)
{
    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
    *obj = **reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(other);
    return scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, data_collection_model_scheduled_communication_time_t *other)
{
    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(other));
    return scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_scheduled_communication_time_free(data_collection_model_scheduled_communication_time_t *scheduled_communication_time)
{
    delete reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_scheduled_communication_time_toJSON(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time, bool as_request)
{
    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_scheduled_communication_time_t*>(new std::shared_ptr<ScheduledCommunicationTime >(new ScheduledCommunicationTime(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_scheduled_communication_time_is_equal_to(const data_collection_model_scheduled_communication_time_t *first, const data_collection_model_scheduled_communication_time_t *second)
{
    const std::shared_ptr<ScheduledCommunicationTime > &obj1 = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(first);
    const std::shared_ptr<ScheduledCommunicationTime > &obj2 = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_scheduled_communication_time_get_days_of_week(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    typedef typename ScheduledCommunicationTime::DaysOfWeekType ResultFromType;
    const ResultFromType result_from = obj->getDaysOfWeek();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        int32_t *item_obj = reinterpret_cast<int32_t*>(ogs_malloc(sizeof(*item_obj)));
        *item_obj = item;
        node = data_collection_lnode_create(item_obj, reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const ogs_list_t* p_days_of_week)
{
    if (obj_scheduled_communication_time == NULL) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    const auto &value_from = p_days_of_week;
    typedef typename ScheduledCommunicationTime::DaysOfWeekType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setDaysOfWeek(value)) return NULL;
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week_move(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, ogs_list_t* p_days_of_week)
{
    if (obj_scheduled_communication_time == NULL) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    const auto &value_from = p_days_of_week;
    typedef typename ScheduledCommunicationTime::DaysOfWeekType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_days_of_week);
    if (!obj->setDaysOfWeek(std::move(value))) return NULL;
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_add_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, int32_t p_days_of_week)
{
    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    typedef typename ScheduledCommunicationTime::DaysOfWeekType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_days_of_week;

    ValueType value = value_from;

    obj->addDaysOfWeek(value);
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_remove_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const int32_t p_days_of_week)
{
    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    typedef typename ScheduledCommunicationTime::DaysOfWeekType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_days_of_week;
    ValueType value = value_from;
    obj->removeDaysOfWeek(value);
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_clear_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{   
    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    obj->clearDaysOfWeek();
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_scheduled_communication_time_get_time_of_day_start(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    typedef typename ScheduledCommunicationTime::TimeOfDayStartType ResultFromType;
    const ResultFromType result_from = obj->getTimeOfDayStart();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const char* p_time_of_day_start)
{
    if (obj_scheduled_communication_time == NULL) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    const auto &value_from = p_time_of_day_start;
    typedef typename ScheduledCommunicationTime::TimeOfDayStartType ValueType;

    ValueType value(value_from);
    if (!obj->setTimeOfDayStart(value)) return NULL;
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start_move(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, char* p_time_of_day_start)
{
    if (obj_scheduled_communication_time == NULL) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    const auto &value_from = p_time_of_day_start;
    typedef typename ScheduledCommunicationTime::TimeOfDayStartType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimeOfDayStart(std::move(value))) return NULL;
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_scheduled_communication_time_get_time_of_day_end(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    typedef typename ScheduledCommunicationTime::TimeOfDayEndType ResultFromType;
    const ResultFromType result_from = obj->getTimeOfDayEnd();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const char* p_time_of_day_end)
{
    if (obj_scheduled_communication_time == NULL) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    const auto &value_from = p_time_of_day_end;
    typedef typename ScheduledCommunicationTime::TimeOfDayEndType ValueType;

    ValueType value(value_from);
    if (!obj->setTimeOfDayEnd(value)) return NULL;
    return obj_scheduled_communication_time;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end_move(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, char* p_time_of_day_end)
{
    if (obj_scheduled_communication_time == NULL) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    const auto &value_from = p_time_of_day_end;
    typedef typename ScheduledCommunicationTime::TimeOfDayEndType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimeOfDayEnd(std::move(value))) return NULL;
    return obj_scheduled_communication_time;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_scheduled_communication_time_make_lnode(data_collection_model_scheduled_communication_time_t *p_scheduled_communication_time)
{
    return data_collection_lnode_create(p_scheduled_communication_time, reinterpret_cast<void(*)(void*)>(data_collection_model_scheduled_communication_time_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_scheduled_communication_time_refcount(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

