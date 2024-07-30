/**********************************************************************************************************************************
 * EventConsumerType - C interface to the EventConsumerType object
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

/*#include "EventConsumerType.h" already included by data-collection-sp/data-collection.h */
#include "EventConsumerType-internal.h"
#include "openapi/model/EventConsumerType.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_event_consumer_type_t *data_collection_model_event_consumer_type_create()
{
    return reinterpret_cast<data_collection_model_event_consumer_type_t*>(new std::shared_ptr<EventConsumerType>(new EventConsumerType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_event_consumer_type_t *data_collection_model_event_consumer_type_create_copy(const data_collection_model_event_consumer_type_t *other)
{
    return reinterpret_cast<data_collection_model_event_consumer_type_t*>(new std::shared_ptr<EventConsumerType >(new EventConsumerType(**reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_event_consumer_type_t *data_collection_model_event_consumer_type_create_move(data_collection_model_event_consumer_type_t *other)
{
    return reinterpret_cast<data_collection_model_event_consumer_type_t*>(new std::shared_ptr<EventConsumerType >(std::move(*reinterpret_cast<std::shared_ptr<EventConsumerType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_event_consumer_type_t *data_collection_model_event_consumer_type_copy(data_collection_model_event_consumer_type_t *event_consumer_type, const data_collection_model_event_consumer_type_t *other)
{
    std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<std::shared_ptr<EventConsumerType >*>(event_consumer_type);
    *obj = **reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(other);
    return event_consumer_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_event_consumer_type_t *data_collection_model_event_consumer_type_move(data_collection_model_event_consumer_type_t *event_consumer_type, data_collection_model_event_consumer_type_t *other)
{
    std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<std::shared_ptr<EventConsumerType >*>(event_consumer_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<EventConsumerType >*>(other));
    return event_consumer_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_event_consumer_type_free(data_collection_model_event_consumer_type_t *event_consumer_type)
{
    delete reinterpret_cast<std::shared_ptr<EventConsumerType >*>(event_consumer_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_event_consumer_type_toJSON(const data_collection_model_event_consumer_type_t *event_consumer_type, bool as_request)
{
    const std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(event_consumer_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_event_consumer_type_t *data_collection_model_event_consumer_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_event_consumer_type_t*>(new std::shared_ptr<EventConsumerType >(new EventConsumerType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_event_consumer_type_is_equal_to(const data_collection_model_event_consumer_type_t *first, const data_collection_model_event_consumer_type_t *second)
{
    const std::shared_ptr<EventConsumerType > &obj1 = *reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(first);
    const std::shared_ptr<EventConsumerType > &obj2 = *reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_consumer_type_is_not_set(const data_collection_model_event_consumer_type_t *obj_event_consumer_type)
{
    const std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(obj_event_consumer_type);
    return obj->getValue() == EventConsumerType::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_consumer_type_is_non_standard(const data_collection_model_event_consumer_type_t *obj_event_consumer_type)
{
    const std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(obj_event_consumer_type);
    return obj->getValue() == EventConsumerType::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_consumer_type_e data_collection_model_event_consumer_type_get_enum(const data_collection_model_event_consumer_type_t *obj_event_consumer_type)
{
    const std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(obj_event_consumer_type);
    switch (obj->getValue()) {
    case EventConsumerType::Enum::NO_VAL:
        return DCM_EVENT_CONSUMER_TYPE_NO_VAL;
    case EventConsumerType::Enum::VAL_NWDAF:
        return DCM_EVENT_CONSUMER_TYPE_VAL_NWDAF;
    case EventConsumerType::Enum::VAL_EVENT_CONSUMER_AF:
        return DCM_EVENT_CONSUMER_TYPE_VAL_EVENT_CONSUMER_AF;
    case EventConsumerType::Enum::VAL_NEF:
        return DCM_EVENT_CONSUMER_TYPE_VAL_NEF;
    default:
        break;
    }
    return DCM_EVENT_CONSUMER_TYPE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_event_consumer_type_get_string(const data_collection_model_event_consumer_type_t *obj_event_consumer_type)
{
    const std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<const std::shared_ptr<EventConsumerType >*>(obj_event_consumer_type);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_consumer_type_set_enum(data_collection_model_event_consumer_type_t *obj_event_consumer_type, data_collection_model_event_consumer_type_e p_value)
{
    std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<std::shared_ptr<EventConsumerType >*>(obj_event_consumer_type);
    switch (p_value) {
    case DCM_EVENT_CONSUMER_TYPE_NO_VAL:
        *obj = EventConsumerType::Enum::NO_VAL;
        return true;
    case DCM_EVENT_CONSUMER_TYPE_VAL_NWDAF:
        *obj = EventConsumerType::Enum::VAL_NWDAF;
        return true;
    case DCM_EVENT_CONSUMER_TYPE_VAL_EVENT_CONSUMER_AF:
        *obj = EventConsumerType::Enum::VAL_EVENT_CONSUMER_AF;
        return true;
    case DCM_EVENT_CONSUMER_TYPE_VAL_NEF:
        *obj = EventConsumerType::Enum::VAL_NEF;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_consumer_type_set_string(data_collection_model_event_consumer_type_t *obj_event_consumer_type, const char *p_value)
{
    std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<std::shared_ptr<EventConsumerType >*>(obj_event_consumer_type);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = EventConsumerType::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_event_consumer_type_make_lnode(data_collection_model_event_consumer_type_t *p_event_consumer_type)
{
    return data_collection_lnode_create(p_event_consumer_type, reinterpret_cast<void(*)(void*)>(data_collection_model_event_consumer_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_event_consumer_type_refcount(data_collection_model_event_consumer_type_t *obj_event_consumer_type)
{
    std::shared_ptr<EventConsumerType > &obj = *reinterpret_cast<std::shared_ptr<EventConsumerType >*>(obj_event_consumer_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

