/**********************************************************************************************************************************
 * PerformanceDataRecord_allOf - C interface to the PerformanceDataRecord_allOf object
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

/*#include "PerformanceDataRecord_allOf.h" already included by data-collection-sp/data-collection.h */
#include "PerformanceDataRecord_allOf-internal.h"
#include "openapi/model/PerformanceDataRecord_allOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_create(






)
{
    return reinterpret_cast<data_collection_model_performance_data_record_all_of_t*>(new std::shared_ptr<PerformanceDataRecord_allOf>(new PerformanceDataRecord_allOf(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_create_copy(const data_collection_model_performance_data_record_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_performance_data_record_all_of_t*>(new std::shared_ptr<PerformanceDataRecord_allOf >(new PerformanceDataRecord_allOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_create_move(data_collection_model_performance_data_record_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > *obj = reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_copy(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, const data_collection_model_performance_data_record_all_of_t *other)
{
    if (performance_data_record_all_of) {
        std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(performance_data_record_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<PerformanceDataRecord_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(other);
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
                const std::shared_ptr<PerformanceDataRecord_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new PerformanceDataRecord_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        performance_data_record_all_of = data_collection_model_performance_data_record_all_of_create_copy(other);
    }
    return performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_move(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, data_collection_model_performance_data_record_all_of_t *other)
{
    std::shared_ptr<PerformanceDataRecord_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(other);

    if (performance_data_record_all_of) {
        std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(performance_data_record_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                performance_data_record_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_record_all_of_free(data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of)
{
    if (!performance_data_record_all_of) return;
    delete reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(performance_data_record_all_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_record_all_of_toJSON(const data_collection_model_performance_data_record_all_of_t *performance_data_record_all_of, bool as_request)
{
    if (!performance_data_record_all_of) return NULL;
    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(performance_data_record_all_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_performance_data_record_all_of_t*>(new std::shared_ptr<PerformanceDataRecord_allOf >(new PerformanceDataRecord_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_is_equal_to(const data_collection_model_performance_data_record_all_of_t *first, const data_collection_model_performance_data_record_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PerformanceDataRecord_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PerformanceDataRecord_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_performance_data_record_all_of_get_time_interval(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord_allOf::TimeIntervalType ResultFromType;
    const ResultFromType result_from = obj->getTimeInterval();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_time_interval(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, const data_collection_model_time_window_t* p_time_interval)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_time_interval;
    typedef typename PerformanceDataRecord_allOf::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setTimeInterval(value)) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_time_interval_move(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, data_collection_model_time_window_t* p_time_interval)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_time_interval;
    typedef typename PerformanceDataRecord_allOf::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setTimeInterval(std::move(value))) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_location(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) return false;

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return false;

    return obj->getLocation().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_record_all_of_get_location(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord_allOf::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_location(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, const data_collection_model_location_area5_g_t* p_location)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename PerformanceDataRecord_allOf::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocation(value)) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_location_move(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, data_collection_model_location_area5_g_t* p_location)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename PerformanceDataRecord_allOf::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setLocation(std::move(value))) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_remote_endpoint(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) return false;

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return false;

    return obj->getRemoteEndpoint().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_record_all_of_get_remote_endpoint(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord_allOf::RemoteEndpointType ResultFromType;
    const ResultFromType result_from = obj->getRemoteEndpoint();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_remote_endpoint(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, const data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_remote_endpoint;
    typedef typename PerformanceDataRecord_allOf::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRemoteEndpoint(value)) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_remote_endpoint_move(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_remote_endpoint;
    typedef typename PerformanceDataRecord_allOf::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRemoteEndpoint(std::move(value))) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_packet_delay_budget(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) return false;

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return false;

    return obj->getPacketDelayBudget().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_all_of_get_packet_delay_budget(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceDataRecord_allOf::PacketDelayBudgetType ResultFromType;
    const ResultFromType result_from = obj->getPacketDelayBudget();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_delay_budget(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, const int32_t p_packet_delay_budget)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_packet_delay_budget;
    typedef typename PerformanceDataRecord_allOf::PacketDelayBudgetType ValueType;

    ValueType value(value_from);

    if (!obj->setPacketDelayBudget(value)) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_delay_budget_move(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, int32_t p_packet_delay_budget)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_packet_delay_budget;
    typedef typename PerformanceDataRecord_allOf::PacketDelayBudgetType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPacketDelayBudget(std::move(value))) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_packet_loss_rate(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) return false;

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return false;

    return obj->getPacketLossRate().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_record_all_of_get_packet_loss_rate(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceDataRecord_allOf::PacketLossRateType ResultFromType;
    const ResultFromType result_from = obj->getPacketLossRate();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_loss_rate(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, const int32_t p_packet_loss_rate)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_packet_loss_rate;
    typedef typename PerformanceDataRecord_allOf::PacketLossRateType ValueType;

    ValueType value(value_from);

    if (!obj->setPacketLossRate(value)) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_packet_loss_rate_move(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, int32_t p_packet_loss_rate)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_packet_loss_rate;
    typedef typename PerformanceDataRecord_allOf::PacketLossRateType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPacketLossRate(std::move(value))) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_uplink_throughput(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) return false;

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return false;

    return obj->getUplinkThroughput().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_all_of_get_uplink_throughput(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord_allOf::UplinkThroughputType ResultFromType;
    const ResultFromType result_from = obj->getUplinkThroughput();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_uplink_throughput(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, const char* p_uplink_throughput)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_throughput;
    typedef typename PerformanceDataRecord_allOf::UplinkThroughputType ValueType;

    ValueType value(value_from);

    if (!obj->setUplinkThroughput(value)) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_uplink_throughput_move(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, char* p_uplink_throughput)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_throughput;
    typedef typename PerformanceDataRecord_allOf::UplinkThroughputType ValueType;

    ValueType value(value_from);

    
    if (!obj->setUplinkThroughput(std::move(value))) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_record_all_of_has_downlink_througput(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) return false;

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return false;

    return obj->getDownlinkThrougput().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_record_all_of_get_downlink_througput(const data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceDataRecord_allOf::DownlinkThrougputType ResultFromType;
    const ResultFromType result_from = obj->getDownlinkThrougput();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_downlink_througput(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, const char* p_downlink_througput)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_througput;
    typedef typename PerformanceDataRecord_allOf::DownlinkThrougputType ValueType;

    ValueType value(value_from);

    if (!obj->setDownlinkThrougput(value)) return NULL;

    return obj_performance_data_record_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_record_all_of_t *data_collection_model_performance_data_record_all_of_set_downlink_througput_move(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of, char* p_downlink_througput)
{
    if (!obj_performance_data_record_all_of) return NULL;

    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_througput;
    typedef typename PerformanceDataRecord_allOf::DownlinkThrougputType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDownlinkThrougput(std::move(value))) return NULL;

    return obj_performance_data_record_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_record_all_of_make_lnode(data_collection_model_performance_data_record_all_of_t *p_performance_data_record_all_of)
{
    return data_collection_lnode_create(p_performance_data_record_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_performance_data_record_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_performance_data_record_all_of_refcount(data_collection_model_performance_data_record_all_of_t *obj_performance_data_record_all_of)
{
    if (!obj_performance_data_record_all_of) return 0l;
    std::shared_ptr<PerformanceDataRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataRecord_allOf >*>(obj_performance_data_record_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

