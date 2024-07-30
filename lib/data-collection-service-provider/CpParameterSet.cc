/**********************************************************************************************************************************
 * CpParameterSet - C interface to the CpParameterSet object
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

/*#include "CpParameterSet.h" already included by data-collection-sp/data-collection.h */
#include "CpParameterSet-internal.h"
#include "openapi/model/CpParameterSet.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create(
















)
{
    return reinterpret_cast<data_collection_model_cp_parameter_set_t*>(new std::shared_ptr<CpParameterSet>(new CpParameterSet(
















)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create_copy(const data_collection_model_cp_parameter_set_t *other)
{
    return reinterpret_cast<data_collection_model_cp_parameter_set_t*>(new std::shared_ptr<CpParameterSet >(new CpParameterSet(**reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create_move(data_collection_model_cp_parameter_set_t *other)
{
    return reinterpret_cast<data_collection_model_cp_parameter_set_t*>(new std::shared_ptr<CpParameterSet >(std::move(*reinterpret_cast<std::shared_ptr<CpParameterSet >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_copy(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_cp_parameter_set_t *other)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
    *obj = **reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(other);
    return cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_cp_parameter_set_t *other)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CpParameterSet >*>(other));
    return cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_cp_parameter_set_free(data_collection_model_cp_parameter_set_t *cp_parameter_set)
{
    delete reinterpret_cast<std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_cp_parameter_set_toJSON(const data_collection_model_cp_parameter_set_t *cp_parameter_set, bool as_request)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_cp_parameter_set_t*>(new std::shared_ptr<CpParameterSet >(new CpParameterSet(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_cp_parameter_set_is_equal_to(const data_collection_model_cp_parameter_set_t *first, const data_collection_model_cp_parameter_set_t *second)
{
    const std::shared_ptr<CpParameterSet > &obj1 = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(first);
    const std::shared_ptr<CpParameterSet > &obj2 = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_cp_parameter_set_get_set_id(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::SetIdType ResultFromType;
    const ResultFromType result_from = obj->getSetId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_set_id(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_set_id)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_set_id;
    typedef typename CpParameterSet::SetIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSetId(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_set_id_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_set_id)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_set_id;
    typedef typename CpParameterSet::SetIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSetId(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_cp_parameter_set_get_self(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::SelfType ResultFromType;
    const ResultFromType result_from = obj->getSelf();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_self(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_self)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_self;
    typedef typename CpParameterSet::SelfType ValueType;

    ValueType value(value_from);
    if (!obj->setSelf(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_self_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_self)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_self;
    typedef typename CpParameterSet::SelfType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSelf(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_cp_parameter_set_get_validity_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ValidityTimeType ResultFromType;
    const ResultFromType result_from = obj->getValidityTime();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_validity_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_validity_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_validity_time;
    typedef typename CpParameterSet::ValidityTimeType ValueType;

    ValueType value(value_from);
    if (!obj->setValidityTime(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_validity_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_validity_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_validity_time;
    typedef typename CpParameterSet::ValidityTimeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setValidityTime(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_communication_indicator_t* data_collection_model_cp_parameter_set_get_periodic_communication_indicator(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::PeriodicCommunicationIndicatorType ResultFromType;
    const ResultFromType result_from = obj->getPeriodicCommunicationIndicator();
    const data_collection_model_communication_indicator_t *result = reinterpret_cast<const data_collection_model_communication_indicator_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_communication_indicator(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_communication_indicator_t* p_periodic_communication_indicator)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_periodic_communication_indicator;
    typedef typename CpParameterSet::PeriodicCommunicationIndicatorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPeriodicCommunicationIndicator(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_communication_indicator_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_communication_indicator_t* p_periodic_communication_indicator)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_periodic_communication_indicator;
    typedef typename CpParameterSet::PeriodicCommunicationIndicatorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPeriodicCommunicationIndicator(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_cp_parameter_set_get_communication_duration_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::CommunicationDurationTimeType ResultFromType;
    const ResultFromType result_from = obj->getCommunicationDurationTime();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_communication_duration_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_communication_duration_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_communication_duration_time;
    typedef typename CpParameterSet::CommunicationDurationTimeType ValueType;

    ValueType value = value_from;
    if (!obj->setCommunicationDurationTime(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_communication_duration_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_communication_duration_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_communication_duration_time;
    typedef typename CpParameterSet::CommunicationDurationTimeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setCommunicationDurationTime(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_cp_parameter_set_get_periodic_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::PeriodicTimeType ResultFromType;
    const ResultFromType result_from = obj->getPeriodicTime();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_periodic_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_periodic_time;
    typedef typename CpParameterSet::PeriodicTimeType ValueType;

    ValueType value = value_from;
    if (!obj->setPeriodicTime(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_periodic_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_periodic_time;
    typedef typename CpParameterSet::PeriodicTimeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setPeriodicTime(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_scheduled_communication_time_t* data_collection_model_cp_parameter_set_get_scheduled_communication_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ScheduledCommunicationTimeType ResultFromType;
    const ResultFromType result_from = obj->getScheduledCommunicationTime();
    const data_collection_model_scheduled_communication_time_t *result = reinterpret_cast<const data_collection_model_scheduled_communication_time_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_scheduled_communication_time_t* p_scheduled_communication_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_scheduled_communication_time;
    typedef typename CpParameterSet::ScheduledCommunicationTimeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setScheduledCommunicationTime(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_scheduled_communication_time_t* p_scheduled_communication_time)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_scheduled_communication_time;
    typedef typename CpParameterSet::ScheduledCommunicationTimeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setScheduledCommunicationTime(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_scheduled_communication_type_t* data_collection_model_cp_parameter_set_get_scheduled_communication_type(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ScheduledCommunicationTypeType ResultFromType;
    const ResultFromType result_from = obj->getScheduledCommunicationType();
    const data_collection_model_scheduled_communication_type_t *result = reinterpret_cast<const data_collection_model_scheduled_communication_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_type(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_scheduled_communication_type_t* p_scheduled_communication_type)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_scheduled_communication_type;
    typedef typename CpParameterSet::ScheduledCommunicationTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setScheduledCommunicationType(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_type_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_scheduled_communication_type_t* p_scheduled_communication_type)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_scheduled_communication_type;
    typedef typename CpParameterSet::ScheduledCommunicationTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setScheduledCommunicationType(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_stationary_indication_t* data_collection_model_cp_parameter_set_get_stationary_indication(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::StationaryIndicationType ResultFromType;
    const ResultFromType result_from = obj->getStationaryIndication();
    const data_collection_model_stationary_indication_t *result = reinterpret_cast<const data_collection_model_stationary_indication_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_stationary_indication(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_stationary_indication_t* p_stationary_indication)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_stationary_indication;
    typedef typename CpParameterSet::StationaryIndicationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setStationaryIndication(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_stationary_indication_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_stationary_indication_t* p_stationary_indication)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_stationary_indication;
    typedef typename CpParameterSet::StationaryIndicationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setStationaryIndication(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_cp_parameter_set_get_battery_inds(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::BatteryIndsType ResultFromType;
    const ResultFromType result_from = obj->getBatteryInds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_battery_indication_t *item_obj = reinterpret_cast<data_collection_model_battery_indication_t*>(new std::shared_ptr<BatteryIndication >(item));
        node = data_collection_model_battery_indication_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const ogs_list_t* p_battery_inds)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_battery_inds;
    typedef typename CpParameterSet::BatteryIndsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setBatteryInds(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_battery_inds_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, ogs_list_t* p_battery_inds)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_battery_inds;
    typedef typename CpParameterSet::BatteryIndsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_battery_inds);
    if (!obj->setBatteryInds(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_battery_indication_t* p_battery_inds)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::BatteryIndsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_battery_inds;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addBatteryInds(value);
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_battery_indication_t* p_battery_inds)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::BatteryIndsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_battery_inds;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeBatteryInds(value);
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{   
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    obj->clearBatteryInds();
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_traffic_profile_t* data_collection_model_cp_parameter_set_get_traffic_profile(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::TrafficProfileType ResultFromType;
    const ResultFromType result_from = obj->getTrafficProfile();
    const data_collection_model_traffic_profile_t *result = reinterpret_cast<const data_collection_model_traffic_profile_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_traffic_profile(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_traffic_profile_t* p_traffic_profile)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_traffic_profile;
    typedef typename CpParameterSet::TrafficProfileType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTrafficProfile(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_traffic_profile_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_traffic_profile_t* p_traffic_profile)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_traffic_profile;
    typedef typename CpParameterSet::TrafficProfileType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTrafficProfile(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_cp_parameter_set_get_expected_umts(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ExpectedUmtsType ResultFromType;
    const ResultFromType result_from = obj->getExpectedUmts();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_umt_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_umt_location_area5_g_t*>(new std::shared_ptr<UmtLocationArea5G >(item));
        node = data_collection_model_umt_location_area5_g_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const ogs_list_t* p_expected_umts)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_expected_umts;
    typedef typename CpParameterSet::ExpectedUmtsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setExpectedUmts(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umts_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, ogs_list_t* p_expected_umts)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_expected_umts;
    typedef typename CpParameterSet::ExpectedUmtsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_expected_umts);
    if (!obj->setExpectedUmts(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_umt_location_area5_g_t* p_expected_umts)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ExpectedUmtsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_expected_umts;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addExpectedUmts(value);
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_umt_location_area5_g_t* p_expected_umts)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ExpectedUmtsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_expected_umts;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeExpectedUmts(value);
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{   
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    obj->clearExpectedUmts();
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_cp_parameter_set_get_expected_umt_days(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ExpectedUmtDaysType ResultFromType;
    const ResultFromType result_from = obj->getExpectedUmtDays();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_expected_umt_days)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_expected_umt_days;
    typedef typename CpParameterSet::ExpectedUmtDaysType ValueType;

    ValueType value = value_from;
    if (!obj->setExpectedUmtDays(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_expected_umt_days)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_expected_umt_days;
    typedef typename CpParameterSet::ExpectedUmtDaysType ValueType;

    ValueType value = value_from;
    
    if (!obj->setExpectedUmtDays(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_cp_parameter_set_get_expected_umt_days_add(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ExpectedUmtDaysAddType ResultFromType;
    const ResultFromType result_from = obj->getExpectedUmtDaysAdd();
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const ogs_list_t* p_expected_umt_days_add)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_expected_umt_days_add;
    typedef typename CpParameterSet::ExpectedUmtDaysAddType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setExpectedUmtDaysAdd(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_add_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, ogs_list_t* p_expected_umt_days_add)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_expected_umt_days_add;
    typedef typename CpParameterSet::ExpectedUmtDaysAddType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_expected_umt_days_add);
    if (!obj->setExpectedUmtDaysAdd(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_expected_umt_days_add)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ExpectedUmtDaysAddType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_expected_umt_days_add;

    ValueType value = value_from;

    obj->addExpectedUmtDaysAdd(value);
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_expected_umt_days_add)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ExpectedUmtDaysAddType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_expected_umt_days_add;
    ValueType value = value_from;
    obj->removeExpectedUmtDaysAdd(value);
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{   
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    obj->clearExpectedUmtDaysAdd();
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_app_exp_ue_behaviour_t* data_collection_model_cp_parameter_set_get_app_exp_ue_behv(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::AppExpUeBehvType ResultFromType;
    const ResultFromType result_from = obj->getAppExpUeBehv();
    const data_collection_model_app_exp_ue_behaviour_t *result = reinterpret_cast<const data_collection_model_app_exp_ue_behaviour_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_app_exp_ue_behv(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_app_exp_ue_behaviour_t* p_app_exp_ue_behv)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_app_exp_ue_behv;
    typedef typename CpParameterSet::AppExpUeBehvType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setAppExpUeBehv(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_app_exp_ue_behv_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_app_exp_ue_behaviour_t* p_app_exp_ue_behv)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_app_exp_ue_behv;
    typedef typename CpParameterSet::AppExpUeBehvType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setAppExpUeBehv(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_cp_parameter_set_get_confidence_level(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::ConfidenceLevelType ResultFromType;
    const ResultFromType result_from = obj->getConfidenceLevel();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_confidence_level(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_confidence_level)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_confidence_level;
    typedef typename CpParameterSet::ConfidenceLevelType ValueType;

    ValueType value(value_from);
    if (!obj->setConfidenceLevel(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_confidence_level_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_confidence_level)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_confidence_level;
    typedef typename CpParameterSet::ConfidenceLevelType ValueType;

    ValueType value(value_from);
    
    if (!obj->setConfidenceLevel(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_cp_parameter_set_get_accuracy_level(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    typedef typename CpParameterSet::AccuracyLevelType ResultFromType;
    const ResultFromType result_from = obj->getAccuracyLevel();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_accuracy_level(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_accuracy_level)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_accuracy_level;
    typedef typename CpParameterSet::AccuracyLevelType ValueType;

    ValueType value(value_from);
    if (!obj->setAccuracyLevel(value)) return NULL;
    return obj_cp_parameter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_accuracy_level_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_accuracy_level)
{
    if (obj_cp_parameter_set == NULL) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    const auto &value_from = p_accuracy_level;
    typedef typename CpParameterSet::AccuracyLevelType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAccuracyLevel(std::move(value))) return NULL;
    return obj_cp_parameter_set;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_cp_parameter_set_make_lnode(data_collection_model_cp_parameter_set_t *p_cp_parameter_set)
{
    return data_collection_lnode_create(p_cp_parameter_set, reinterpret_cast<void(*)(void*)>(data_collection_model_cp_parameter_set_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_cp_parameter_set_refcount(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

