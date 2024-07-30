/**********************************************************************************************************************************
 * DataReportingEventTrigger - C interface to the DataReportingEventTrigger object
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

/*#include "DataReportingEventTrigger.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingEventTrigger-internal.h"
#include "openapi/model/DataReportingEventTrigger.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_create()
{
    return reinterpret_cast<data_collection_model_data_reporting_event_trigger_t*>(new std::shared_ptr<DataReportingEventTrigger>(new DataReportingEventTrigger()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_create_copy(const data_collection_model_data_reporting_event_trigger_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_event_trigger_t*>(new std::shared_ptr<DataReportingEventTrigger >(new DataReportingEventTrigger(**reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_create_move(data_collection_model_data_reporting_event_trigger_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_event_trigger_t*>(new std::shared_ptr<DataReportingEventTrigger >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_copy(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, const data_collection_model_data_reporting_event_trigger_t *other)
{
    std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(data_reporting_event_trigger);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(other);
    return data_reporting_event_trigger;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_move(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, data_collection_model_data_reporting_event_trigger_t *other)
{
    std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(data_reporting_event_trigger);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(other));
    return data_reporting_event_trigger;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_event_trigger_free(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(data_reporting_event_trigger);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_event_trigger_toJSON(const data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, bool as_request)
{
    const std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(data_reporting_event_trigger);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_event_trigger_t*>(new std::shared_ptr<DataReportingEventTrigger >(new DataReportingEventTrigger(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_reporting_event_trigger_is_equal_to(const data_collection_model_data_reporting_event_trigger_t *first, const data_collection_model_data_reporting_event_trigger_t *second)
{
    const std::shared_ptr<DataReportingEventTrigger > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(first);
    const std::shared_ptr<DataReportingEventTrigger > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_is_not_set(const data_collection_model_data_reporting_event_trigger_t *obj_data_reporting_event_trigger)
{
    const std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(obj_data_reporting_event_trigger);
    return obj->getValue() == DataReportingEventTrigger::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_is_non_standard(const data_collection_model_data_reporting_event_trigger_t *obj_data_reporting_event_trigger)
{
    const std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(obj_data_reporting_event_trigger);
    return obj->getValue() == DataReportingEventTrigger::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_e data_collection_model_data_reporting_event_trigger_get_enum(const data_collection_model_data_reporting_event_trigger_t *obj_data_reporting_event_trigger)
{
    const std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(obj_data_reporting_event_trigger);
    switch (obj->getValue()) {
    case DataReportingEventTrigger::Enum::NO_VAL:
        return DCM_DATA_REPORTING_EVENT_TRIGGER_NO_VAL;
    case DataReportingEventTrigger::Enum::VAL_LOCATION:
        return DCM_DATA_REPORTING_EVENT_TRIGGER_VAL_LOCATION;
    case DataReportingEventTrigger::Enum::VAL_DESTINATION:
        return DCM_DATA_REPORTING_EVENT_TRIGGER_VAL_DESTINATION;
    default:
        break;
    }
    return DCM_DATA_REPORTING_EVENT_TRIGGER_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_data_reporting_event_trigger_get_string(const data_collection_model_data_reporting_event_trigger_t *obj_data_reporting_event_trigger)
{
    const std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingEventTrigger >*>(obj_data_reporting_event_trigger);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_set_enum(data_collection_model_data_reporting_event_trigger_t *obj_data_reporting_event_trigger, data_collection_model_data_reporting_event_trigger_e p_value)
{
    std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(obj_data_reporting_event_trigger);
    switch (p_value) {
    case DCM_DATA_REPORTING_EVENT_TRIGGER_NO_VAL:
        *obj = DataReportingEventTrigger::Enum::NO_VAL;
        return true;
    case DCM_DATA_REPORTING_EVENT_TRIGGER_VAL_LOCATION:
        *obj = DataReportingEventTrigger::Enum::VAL_LOCATION;
        return true;
    case DCM_DATA_REPORTING_EVENT_TRIGGER_VAL_DESTINATION:
        *obj = DataReportingEventTrigger::Enum::VAL_DESTINATION;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_set_string(data_collection_model_data_reporting_event_trigger_t *obj_data_reporting_event_trigger, const char *p_value)
{
    std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(obj_data_reporting_event_trigger);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = DataReportingEventTrigger::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_event_trigger_make_lnode(data_collection_model_data_reporting_event_trigger_t *p_data_reporting_event_trigger)
{
    return data_collection_lnode_create(p_data_reporting_event_trigger, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_event_trigger_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_event_trigger_refcount(data_collection_model_data_reporting_event_trigger_t *obj_data_reporting_event_trigger)
{
    std::shared_ptr<DataReportingEventTrigger > &obj = *reinterpret_cast<std::shared_ptr<DataReportingEventTrigger >*>(obj_data_reporting_event_trigger);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

