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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "ScheduledCommunicationTime.h" already included by data-collection-sp/data-collection.h */
#include "ScheduledCommunicationTime-internal.h"
#include "openapi/model/ScheduledCommunicationTime.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create(


)
{
    return reinterpret_cast<data_collection_model_scheduled_communication_time_t*>(new std::shared_ptr<ScheduledCommunicationTime>(new ScheduledCommunicationTime(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_copy(const data_collection_model_scheduled_communication_time_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_scheduled_communication_time_t*>(new std::shared_ptr<ScheduledCommunicationTime >(new ScheduledCommunicationTime(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_move(data_collection_model_scheduled_communication_time_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > *obj = reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_copy(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const data_collection_model_scheduled_communication_time_t *other)
{
    if (scheduled_communication_time) {
        std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
        if (obj) {
            if (other) {
                const std::shared_ptr<ScheduledCommunicationTime > &other_obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(other);
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
                const std::shared_ptr<ScheduledCommunicationTime > &other_obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(other);
                if (other_obj) {
                    obj.reset(new ScheduledCommunicationTime(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        scheduled_communication_time = data_collection_model_scheduled_communication_time_create_copy(other);
    }
    return scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, data_collection_model_scheduled_communication_time_t *other)
{
    std::shared_ptr<ScheduledCommunicationTime > *other_ptr = reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(other);

    if (scheduled_communication_time) {
        std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                scheduled_communication_time = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_scheduled_communication_time_free(data_collection_model_scheduled_communication_time_t *scheduled_communication_time)
{
    if (!scheduled_communication_time) return;
    delete reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_scheduled_communication_time_toJSON(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time, bool as_request)
{
    if (!scheduled_communication_time) return NULL;
    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(scheduled_communication_time);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_is_equal_to(const data_collection_model_scheduled_communication_time_t *first, const data_collection_model_scheduled_communication_time_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ScheduledCommunicationTime > &obj2 = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ScheduledCommunicationTime > &obj1 = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_days_of_week(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) return false;

    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return false;

    return obj->getDaysOfWeek().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_scheduled_communication_time_get_days_of_week(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ScheduledCommunicationTime::DaysOfWeekType ResultFromType;
    const ResultFromType result_from = obj->getDaysOfWeek();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        int32_t *item_obj = reinterpret_cast<int32_t*>(item.has_value()?ogs_malloc(sizeof(*item_obj)):nullptr);
        if (item_obj) {
            *item_obj = item.value();
            node = data_collection_lnode_create(item_obj, reinterpret_cast<void(*)(void*)>(_ogs_free));
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const ogs_list_t* p_days_of_week)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    const auto &value_from = p_days_of_week;
    typedef typename ScheduledCommunicationTime::DaysOfWeekType ValueType;

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

    if (!obj->setDaysOfWeek(value)) return NULL;

    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week_move(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, ogs_list_t* p_days_of_week)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    const auto &value_from = p_days_of_week;
    typedef typename ScheduledCommunicationTime::DaysOfWeekType ValueType;

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

    data_collection_list_free(p_days_of_week);
    if (!obj->setDaysOfWeek(std::move(value))) return NULL;

    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_add_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, int32_t p_days_of_week)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    typedef typename ScheduledCommunicationTime::DaysOfWeekType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_days_of_week;

    ValueType value(value_from);


    if (value) obj->addDaysOfWeek(value.value());
    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_remove_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const int32_t p_days_of_week)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    typedef typename ScheduledCommunicationTime::DaysOfWeekType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_days_of_week;
    ValueType value(value_from);

    obj->removeDaysOfWeek(value);
    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_clear_days_of_week(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    obj->clearDaysOfWeek();
    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_time_of_day_start(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) return false;

    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return false;

    return obj->getTimeOfDayStart().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_scheduled_communication_time_get_time_of_day_start(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ScheduledCommunicationTime::TimeOfDayStartType ResultFromType;
    const ResultFromType result_from = obj->getTimeOfDayStart();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const char* p_time_of_day_start)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    const auto &value_from = p_time_of_day_start;
    typedef typename ScheduledCommunicationTime::TimeOfDayStartType ValueType;

    ValueType value(value_from);

    if (!obj->setTimeOfDayStart(value)) return NULL;

    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start_move(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, char* p_time_of_day_start)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    const auto &value_from = p_time_of_day_start;
    typedef typename ScheduledCommunicationTime::TimeOfDayStartType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTimeOfDayStart(std::move(value))) return NULL;

    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_time_of_day_end(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) return false;

    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return false;

    return obj->getTimeOfDayEnd().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_scheduled_communication_time_get_time_of_day_end(const data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<const std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ScheduledCommunicationTime::TimeOfDayEndType ResultFromType;
    const ResultFromType result_from = obj->getTimeOfDayEnd();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, const char* p_time_of_day_end)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    const auto &value_from = p_time_of_day_end;
    typedef typename ScheduledCommunicationTime::TimeOfDayEndType ValueType;

    ValueType value(value_from);

    if (!obj->setTimeOfDayEnd(value)) return NULL;

    return obj_scheduled_communication_time;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end_move(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time, char* p_time_of_day_end)
{
    if (!obj_scheduled_communication_time) return NULL;

    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    if (!obj) return NULL;

    const auto &value_from = p_time_of_day_end;
    typedef typename ScheduledCommunicationTime::TimeOfDayEndType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTimeOfDayEnd(std::move(value))) return NULL;

    return obj_scheduled_communication_time;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_scheduled_communication_time_make_lnode(data_collection_model_scheduled_communication_time_t *p_scheduled_communication_time)
{
    return data_collection_lnode_create(p_scheduled_communication_time, reinterpret_cast<void(*)(void*)>(data_collection_model_scheduled_communication_time_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_scheduled_communication_time_refcount(data_collection_model_scheduled_communication_time_t *obj_scheduled_communication_time)
{
    if (!obj_scheduled_communication_time) return 0l;
    std::shared_ptr<ScheduledCommunicationTime > &obj = *reinterpret_cast<std::shared_ptr<ScheduledCommunicationTime >*>(obj_scheduled_communication_time);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

