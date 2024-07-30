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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_create(


)
{
    return reinterpret_cast<data_collection_model_events_subs_t*>(new std::shared_ptr<EventsSubs>(new EventsSubs(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_create_copy(const data_collection_model_events_subs_t *other)
{
    return reinterpret_cast<data_collection_model_events_subs_t*>(new std::shared_ptr<EventsSubs >(new EventsSubs(**reinterpret_cast<const std::shared_ptr<EventsSubs >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_create_move(data_collection_model_events_subs_t *other)
{
    return reinterpret_cast<data_collection_model_events_subs_t*>(new std::shared_ptr<EventsSubs >(std::move(*reinterpret_cast<std::shared_ptr<EventsSubs >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_copy(data_collection_model_events_subs_t *events_subs, const data_collection_model_events_subs_t *other)
{
    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(events_subs);
    *obj = **reinterpret_cast<const std::shared_ptr<EventsSubs >*>(other);
    return events_subs;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_move(data_collection_model_events_subs_t *events_subs, data_collection_model_events_subs_t *other)
{
    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(events_subs);
    obj = std::move(*reinterpret_cast<std::shared_ptr<EventsSubs >*>(other));
    return events_subs;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_events_subs_free(data_collection_model_events_subs_t *events_subs)
{
    delete reinterpret_cast<std::shared_ptr<EventsSubs >*>(events_subs);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_events_subs_toJSON(const data_collection_model_events_subs_t *events_subs, bool as_request)
{
    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(events_subs);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_events_subs_is_equal_to(const data_collection_model_events_subs_t *first, const data_collection_model_events_subs_t *second)
{
    const std::shared_ptr<EventsSubs > &obj1 = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(first);
    const std::shared_ptr<EventsSubs > &obj2 = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_af_event_t* data_collection_model_events_subs_get_event(const data_collection_model_events_subs_t *obj_events_subs)
{
    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(obj_events_subs);
    typedef typename EventsSubs::EventType ResultFromType;
    const ResultFromType result_from = obj->getEvent();
    const data_collection_model_af_event_t *result = reinterpret_cast<const data_collection_model_af_event_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_set_event(data_collection_model_events_subs_t *obj_events_subs, const data_collection_model_af_event_t* p_event)
{
    if (obj_events_subs == NULL) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    const auto &value_from = p_event;
    typedef typename EventsSubs::EventType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEvent(value)) return NULL;
    return obj_events_subs;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_move(data_collection_model_events_subs_t *obj_events_subs, data_collection_model_af_event_t* p_event)
{
    if (obj_events_subs == NULL) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    const auto &value_from = p_event;
    typedef typename EventsSubs::EventType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEvent(std::move(value))) return NULL;
    return obj_events_subs;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_event_filter_t* data_collection_model_events_subs_get_event_filter(const data_collection_model_events_subs_t *obj_events_subs)
{
    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(obj_events_subs);
    typedef typename EventsSubs::EventFilterType ResultFromType;
    const ResultFromType result_from = obj->getEventFilter();
    const data_collection_model_event_filter_t *result = reinterpret_cast<const data_collection_model_event_filter_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter(data_collection_model_events_subs_t *obj_events_subs, const data_collection_model_event_filter_t* p_event_filter)
{
    if (obj_events_subs == NULL) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    const auto &value_from = p_event_filter;
    typedef typename EventsSubs::EventFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEventFilter(value)) return NULL;
    return obj_events_subs;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter_move(data_collection_model_events_subs_t *obj_events_subs, data_collection_model_event_filter_t* p_event_filter)
{
    if (obj_events_subs == NULL) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    const auto &value_from = p_event_filter;
    typedef typename EventsSubs::EventFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEventFilter(std::move(value))) return NULL;
    return obj_events_subs;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_reporting_information_t* data_collection_model_events_subs_get_event_rep_info(const data_collection_model_events_subs_t *obj_events_subs)
{
    const std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<const std::shared_ptr<EventsSubs >*>(obj_events_subs);
    typedef typename EventsSubs::EventRepInfoType ResultFromType;
    const ResultFromType result_from = obj->getEventRepInfo();
    const data_collection_model_reporting_information_t *result = reinterpret_cast<const data_collection_model_reporting_information_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info(data_collection_model_events_subs_t *obj_events_subs, const data_collection_model_reporting_information_t* p_event_rep_info)
{
    if (obj_events_subs == NULL) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    const auto &value_from = p_event_rep_info;
    typedef typename EventsSubs::EventRepInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEventRepInfo(value)) return NULL;
    return obj_events_subs;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info_move(data_collection_model_events_subs_t *obj_events_subs, data_collection_model_reporting_information_t* p_event_rep_info)
{
    if (obj_events_subs == NULL) return NULL;

    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    const auto &value_from = p_event_rep_info;
    typedef typename EventsSubs::EventRepInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEventRepInfo(std::move(value))) return NULL;
    return obj_events_subs;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_events_subs_make_lnode(data_collection_model_events_subs_t *p_events_subs)
{
    return data_collection_lnode_create(p_events_subs, reinterpret_cast<void(*)(void*)>(data_collection_model_events_subs_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_events_subs_refcount(data_collection_model_events_subs_t *obj_events_subs)
{
    std::shared_ptr<EventsSubs > &obj = *reinterpret_cast<std::shared_ptr<EventsSubs >*>(obj_events_subs);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

