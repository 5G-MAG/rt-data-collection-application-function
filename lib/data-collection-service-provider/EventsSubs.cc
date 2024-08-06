/**********************************************************************************************************************************
 * EventsSubs - C interface to the EventsSubs object
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

/*#include "EventsSubs.h" already included by data-collection-sp/data-collection.h */
#include "EventsSubs-internal.h"
#include "openapi/model/EventsSubs.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create(


)
{
    return reinterpret_cast<data_collection_model_events_subs_t*>(new std::shared_ptr<EventsSubs>(new EventsSubs(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create_copy(const data_collection_model_events_subs_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_events_subs_t*>(new std::shared_ptr<EventsSubs >(new EventsSubs(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create_move(data_collection_model_events_subs_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<EventsSubs > *obj = reinterpret_cast<std::shared_ptr<EventsSubs >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_copy(data_collection_model_events_subs_t *events_subs, const data_collection_model_events_subs_t *other)
{
    if (events_subs) {
        std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(events_subs);
        if (obj) {
            if (other) {
                const std::shared_ptr<EventsSubs > &other_obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(other);
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
                const std::shared_ptr<EventsSubs > &other_obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(other);
                if (other_obj) {
                    obj.reset(new EventsSubs(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        events_subs = data_collection_model_events_subs_create_copy(other);
    }
    return events_subs;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_move(data_collection_model_events_subs_t *events_subs, data_collection_model_events_subs_t *other)
{
    std::shared_ptr<EventsSubs > *other_ptr = reinterpret_cast<std::shared_ptr<EventsSubs >*>(other);

    if (events_subs) {
        std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(events_subs);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                events_subs = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return events_subs;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_events_subs_free(data_collection_model_events_subs_t *events_subs)
{
    if (!events_subs) return;
    delete reinterpret_cast<std::shared_ptr<EventsSubs >*>(events_subs);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_events_subs_toJSON(const data_collection_model_events_subs_t *events_subs, bool as_request)
{
    if (!events_subs) return NULL;
    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(events_subs);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_events_subs_t*>(new std::shared_ptr<EventsSubs >(new EventsSubs(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_events_subs_is_equal_to(const data_collection_model_events_subs_t *first, const data_collection_model_events_subs_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<EventsSubs > &obj2 = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<EventsSubs > &obj1 = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_t* data_collection_model_events_subs_get_event(const data_collection_model_events_subs_t *obj_events_subs)
{
    if (!obj_events_subs) {
        const data_collection_model_af_event_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) {
        const data_collection_model_af_event_t *result = NULL;
        return result;
    }

    typedef typename EventsSubs::EventType ResultFromType;
    const ResultFromType result_from = obj->getEvent();
    const data_collection_model_af_event_t *result = reinterpret_cast<const data_collection_model_af_event_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event(data_collection_model_events_subs_t *obj_events_subs, const data_collection_model_af_event_t* p_event)
{
    if (!obj_events_subs) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) return NULL;

    const auto &value_from = p_event;
    typedef typename EventsSubs::EventType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEvent(value)) return NULL;

    return obj_events_subs;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_move(data_collection_model_events_subs_t *obj_events_subs, data_collection_model_af_event_t* p_event)
{
    if (!obj_events_subs) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) return NULL;

    const auto &value_from = p_event;
    typedef typename EventsSubs::EventType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEvent(std::move(value))) return NULL;

    return obj_events_subs;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_filter_t* data_collection_model_events_subs_get_event_filter(const data_collection_model_events_subs_t *obj_events_subs)
{
    if (!obj_events_subs) {
        const data_collection_model_event_filter_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) {
        const data_collection_model_event_filter_t *result = NULL;
        return result;
    }

    typedef typename EventsSubs::EventFilterType ResultFromType;
    const ResultFromType result_from = obj->getEventFilter();
    const data_collection_model_event_filter_t *result = reinterpret_cast<const data_collection_model_event_filter_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter(data_collection_model_events_subs_t *obj_events_subs, const data_collection_model_event_filter_t* p_event_filter)
{
    if (!obj_events_subs) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) return NULL;

    const auto &value_from = p_event_filter;
    typedef typename EventsSubs::EventFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEventFilter(value)) return NULL;

    return obj_events_subs;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter_move(data_collection_model_events_subs_t *obj_events_subs, data_collection_model_event_filter_t* p_event_filter)
{
    if (!obj_events_subs) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) return NULL;

    const auto &value_from = p_event_filter;
    typedef typename EventsSubs::EventFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEventFilter(std::move(value))) return NULL;

    return obj_events_subs;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_reporting_information_t* data_collection_model_events_subs_get_event_rep_info(const data_collection_model_events_subs_t *obj_events_subs)
{
    if (!obj_events_subs) {
        const data_collection_model_reporting_information_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) {
        const data_collection_model_reporting_information_t *result = NULL;
        return result;
    }

    typedef typename EventsSubs::EventRepInfoType ResultFromType;
    const ResultFromType result_from = obj->getEventRepInfo();
    const data_collection_model_reporting_information_t *result = reinterpret_cast<const data_collection_model_reporting_information_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info(data_collection_model_events_subs_t *obj_events_subs, const data_collection_model_reporting_information_t* p_event_rep_info)
{
    if (!obj_events_subs) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) return NULL;

    const auto &value_from = p_event_rep_info;
    typedef typename EventsSubs::EventRepInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEventRepInfo(value)) return NULL;

    return obj_events_subs;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info_move(data_collection_model_events_subs_t *obj_events_subs, data_collection_model_reporting_information_t* p_event_rep_info)
{
    if (!obj_events_subs) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    if (!obj) return NULL;

    const auto &value_from = p_event_rep_info;
    typedef typename EventsSubs::EventRepInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEventRepInfo(std::move(value))) return NULL;

    return obj_events_subs;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_events_subs_make_lnode(data_collection_model_events_subs_t *p_events_subs)
{
    return data_collection_lnode_create(p_events_subs, reinterpret_cast<void(*)(void*)>(data_collection_model_events_subs_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_events_subs_refcount(data_collection_model_events_subs_t *obj_events_subs)
{
    if (!obj_events_subs) return 0l;
    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

