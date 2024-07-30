/**********************************************************************************************************************************
 * PerformanceDataRecord - C interface to the PerformanceDataRecord object
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

/*#include "PerformanceDataRecord.h" already included by data-collection-sp/data-collection.h */
#include "PerformanceDataRecord-internal.h"
#include "openapi/model/PerformanceDataRecord.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create(








)
{
    return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord>(new PerformanceDataRecord(








)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_copy(const data_collection_model_performance_data_record_t *other)
{
    return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord >(new PerformanceDataRecord(**reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_create_move(data_collection_model_performance_data_record_t *other)
{
    return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord >(std::move(*reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_copy(data_collection_model_performance_data_record_t *performance_data_record, const data_collection_model_performance_data_record_t *other)
{
    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
    *obj = **reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(other);
    return performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_move(data_collection_model_performance_data_record_t *performance_data_record, data_collection_model_performance_data_record_t *other)
{
    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(other));
    return performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_performance_data_record_free(data_collection_model_performance_data_record_t *performance_data_record)
{
    delete reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_performance_data_record_toJSON(const data_collection_model_performance_data_record_t *performance_data_record, bool as_request)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(performance_data_record);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord >(new PerformanceDataRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_performance_data_record_is_equal_to(const data_collection_model_performance_data_record_t *first, const data_collection_model_performance_data_record_t *second)
{
    const std::shared_ptr<PerformanceDataRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(first);
    const std::shared_ptr<PerformanceDataRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_performance_data_record_get_timestamp(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_timestamp)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_timestamp;
    typedef typename PerformanceDataRecord::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_timestamp_move(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_timestamp)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_timestamp;
    typedef typename PerformanceDataRecord::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_performance_data_record_get_context_ids(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::ContextIdsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record, const ogs_list_t* p_context_ids)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_context_ids;
    typedef typename PerformanceDataRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_context_ids_move(data_collection_model_performance_data_record_t *obj_performance_data_record, ogs_list_t* p_context_ids)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_context_ids;
    typedef typename PerformanceDataRecord::ContextIdsType ValueType;

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
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_add_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_context_ids)
{
    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_remove_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_context_ids)
{
    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_clear_context_ids(data_collection_model_performance_data_record_t *obj_performance_data_record)
{   
    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    obj->clearContextIds();
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_performance_data_record_get_time_interval(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::TimeIntervalType ResultFromType;
    const ResultFromType result_from = obj->getTimeInterval();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval(data_collection_model_performance_data_record_t *obj_performance_data_record, const data_collection_model_time_window_t* p_time_interval)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_time_interval;
    typedef typename PerformanceDataRecord::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTimeInterval(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_time_interval_move(data_collection_model_performance_data_record_t *obj_performance_data_record, data_collection_model_time_window_t* p_time_interval)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_time_interval;
    typedef typename PerformanceDataRecord::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTimeInterval(std::move(value))) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_area5_g_t* data_collection_model_performance_data_record_get_location(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location(data_collection_model_performance_data_record_t *obj_performance_data_record, const data_collection_model_location_area5_g_t* p_location)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_location;
    typedef typename PerformanceDataRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocation(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_location_move(data_collection_model_performance_data_record_t *obj_performance_data_record, data_collection_model_location_area5_g_t* p_location)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_location;
    typedef typename PerformanceDataRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocation(std::move(value))) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_record_get_remote_endpoint(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::RemoteEndpointType ResultFromType;
    const ResultFromType result_from = obj->getRemoteEndpoint();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint(data_collection_model_performance_data_record_t *obj_performance_data_record, const data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_remote_endpoint;
    typedef typename PerformanceDataRecord::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRemoteEndpoint(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_remote_endpoint_move(data_collection_model_performance_data_record_t *obj_performance_data_record, data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_remote_endpoint;
    typedef typename PerformanceDataRecord::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRemoteEndpoint(std::move(value))) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_performance_data_record_get_packet_delay_budget(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::PacketDelayBudgetType ResultFromType;
    const ResultFromType result_from = obj->getPacketDelayBudget();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget(data_collection_model_performance_data_record_t *obj_performance_data_record, const int32_t p_packet_delay_budget)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_packet_delay_budget;
    typedef typename PerformanceDataRecord::PacketDelayBudgetType ValueType;

    ValueType value = value_from;
    if (!obj->setPacketDelayBudget(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_delay_budget_move(data_collection_model_performance_data_record_t *obj_performance_data_record, int32_t p_packet_delay_budget)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_packet_delay_budget;
    typedef typename PerformanceDataRecord::PacketDelayBudgetType ValueType;

    ValueType value = value_from;
    
    if (!obj->setPacketDelayBudget(std::move(value))) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_performance_data_record_get_packet_loss_rate(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::PacketLossRateType ResultFromType;
    const ResultFromType result_from = obj->getPacketLossRate();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate(data_collection_model_performance_data_record_t *obj_performance_data_record, const int32_t p_packet_loss_rate)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_packet_loss_rate;
    typedef typename PerformanceDataRecord::PacketLossRateType ValueType;

    ValueType value = value_from;
    if (!obj->setPacketLossRate(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_packet_loss_rate_move(data_collection_model_performance_data_record_t *obj_performance_data_record, int32_t p_packet_loss_rate)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_packet_loss_rate;
    typedef typename PerformanceDataRecord::PacketLossRateType ValueType;

    ValueType value = value_from;
    
    if (!obj->setPacketLossRate(std::move(value))) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_performance_data_record_get_uplink_throughput(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::UplinkThroughputType ResultFromType;
    const ResultFromType result_from = obj->getUplinkThroughput();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_uplink_throughput)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_uplink_throughput;
    typedef typename PerformanceDataRecord::UplinkThroughputType ValueType;

    ValueType value(value_from);
    if (!obj->setUplinkThroughput(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_uplink_throughput_move(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_uplink_throughput)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_uplink_throughput;
    typedef typename PerformanceDataRecord::UplinkThroughputType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUplinkThroughput(std::move(value))) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_performance_data_record_get_downlink_througput(const data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    const std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    typedef typename PerformanceDataRecord::DownlinkThrougputType ResultFromType;
    const ResultFromType result_from = obj->getDownlinkThrougput();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput(data_collection_model_performance_data_record_t *obj_performance_data_record, const char* p_downlink_througput)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_downlink_througput;
    typedef typename PerformanceDataRecord::DownlinkThrougputType ValueType;

    ValueType value(value_from);
    if (!obj->setDownlinkThrougput(value)) return NULL;
    return obj_performance_data_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_performance_data_record_t *data_collection_model_performance_data_record_set_downlink_througput_move(data_collection_model_performance_data_record_t *obj_performance_data_record, char* p_downlink_througput)
{
    if (obj_performance_data_record == NULL) return NULL;

    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    const auto &value_from = p_downlink_througput;
    typedef typename PerformanceDataRecord::DownlinkThrougputType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDownlinkThrougput(std::move(value))) return NULL;
    return obj_performance_data_record;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_performance_data_record_make_lnode(data_collection_model_performance_data_record_t *p_performance_data_record)
{
    return data_collection_lnode_create(p_performance_data_record, reinterpret_cast<void(*)(void*)>(data_collection_model_performance_data_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_performance_data_record_refcount(data_collection_model_performance_data_record_t *obj_performance_data_record)
{
    std::shared_ptr<PerformanceDataRecord > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord >*>(obj_performance_data_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

