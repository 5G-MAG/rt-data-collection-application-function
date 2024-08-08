/**********************************************************************************************************************************
 * M5QoSSpecification - C interface to the M5QoSSpecification object
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

/*#include "M5QoSSpecification.h" already included by data-collection-sp/data-collection.h */
#include "M5QoSSpecification-internal.h"
#include "openapi/model/M5QoSSpecification.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create(





)
{
    return reinterpret_cast<data_collection_model_m5_qo_s_specification_t*>(new std::shared_ptr<M5QoSSpecification>(new M5QoSSpecification(





)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create_copy(const data_collection_model_m5_qo_s_specification_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_m5_qo_s_specification_t*>(new std::shared_ptr<M5QoSSpecification >(new M5QoSSpecification(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create_move(data_collection_model_m5_qo_s_specification_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<M5QoSSpecification > *obj = reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_copy(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_m5_qo_s_specification_t *other)
{
    if (m5_qo_s_specification) {
        std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
        if (obj) {
            if (other) {
                const std::shared_ptr<M5QoSSpecification > &other_obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(other);
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
                const std::shared_ptr<M5QoSSpecification > &other_obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(other);
                if (other_obj) {
                    obj.reset(new M5QoSSpecification(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        m5_qo_s_specification = data_collection_model_m5_qo_s_specification_create_copy(other);
    }
    return m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, data_collection_model_m5_qo_s_specification_t *other)
{
    std::shared_ptr<M5QoSSpecification > *other_ptr = reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(other);

    if (m5_qo_s_specification) {
        std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                m5_qo_s_specification = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_m5_qo_s_specification_free(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification)
{
    if (!m5_qo_s_specification) return;
    delete reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_m5_qo_s_specification_toJSON(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, bool as_request)
{
    if (!m5_qo_s_specification) return NULL;
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_m5_qo_s_specification_t*>(new std::shared_ptr<M5QoSSpecification >(new M5QoSSpecification(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_m5_qo_s_specification_is_equal_to(const data_collection_model_m5_qo_s_specification_t *first, const data_collection_model_m5_qo_s_specification_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<M5QoSSpecification > &obj2 = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<M5QoSSpecification > &obj1 = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_bit_rate_specification_t* data_collection_model_m5_qo_s_specification_get_downlink_bit_rates(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    if (!obj_m5_qo_s_specification) {
        const data_collection_model_m5_bit_rate_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) {
        const data_collection_model_m5_bit_rate_specification_t *result = NULL;
        return result;
    }

    typedef typename M5QoSSpecification::DownlinkBitRatesType ResultFromType;
    const ResultFromType result_from = obj->getDownlinkBitRates();
    const data_collection_model_m5_bit_rate_specification_t *result = reinterpret_cast<const data_collection_model_m5_bit_rate_specification_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_downlink_bit_rates(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_m5_bit_rate_specification_t* p_downlink_bit_rates)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_bit_rates;
    typedef typename M5QoSSpecification::DownlinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDownlinkBitRates(value)) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_downlink_bit_rates_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_m5_bit_rate_specification_t* p_downlink_bit_rates)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_bit_rates;
    typedef typename M5QoSSpecification::DownlinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDownlinkBitRates(std::move(value))) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_bit_rate_specification_t* data_collection_model_m5_qo_s_specification_get_uplink_bit_rates(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    if (!obj_m5_qo_s_specification) {
        const data_collection_model_m5_bit_rate_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) {
        const data_collection_model_m5_bit_rate_specification_t *result = NULL;
        return result;
    }

    typedef typename M5QoSSpecification::UplinkBitRatesType ResultFromType;
    const ResultFromType result_from = obj->getUplinkBitRates();
    const data_collection_model_m5_bit_rate_specification_t *result = reinterpret_cast<const data_collection_model_m5_bit_rate_specification_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_uplink_bit_rates(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_m5_bit_rate_specification_t* p_uplink_bit_rates)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_bit_rates;
    typedef typename M5QoSSpecification::UplinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUplinkBitRates(value)) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_uplink_bit_rates_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_m5_bit_rate_specification_t* p_uplink_bit_rates)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_bit_rates;
    typedef typename M5QoSSpecification::UplinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUplinkBitRates(std::move(value))) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_m5_qo_s_specification_get_desired_packet_latency(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    if (!obj_m5_qo_s_specification) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename M5QoSSpecification::DesiredPacketLatencyType ResultFromType;
    const ResultFromType result_from = obj->getDesiredPacketLatency();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_latency(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const int32_t p_desired_packet_latency)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_latency;
    typedef typename M5QoSSpecification::DesiredPacketLatencyType ValueType;

    ValueType value = value_from;
    if (!obj->setDesiredPacketLatency(value)) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_latency_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, int32_t p_desired_packet_latency)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_latency;
    typedef typename M5QoSSpecification::DesiredPacketLatencyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDesiredPacketLatency(std::move(value))) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_m5_qo_s_specification_get_desired_packet_loss_rate(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    if (!obj_m5_qo_s_specification) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename M5QoSSpecification::DesiredPacketLossRateType ResultFromType;
    const ResultFromType result_from = obj->getDesiredPacketLossRate();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_loss_rate(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const int32_t p_desired_packet_loss_rate)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename M5QoSSpecification::DesiredPacketLossRateType ValueType;

    ValueType value = value_from;
    if (!obj->setDesiredPacketLossRate(value)) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_loss_rate_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, int32_t p_desired_packet_loss_rate)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename M5QoSSpecification::DesiredPacketLossRateType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDesiredPacketLossRate(std::move(value))) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_m5_qo_s_specification_get_desired_downlink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    if (!obj_m5_qo_s_specification) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    typedef typename M5QoSSpecification::DesiredDownlinkPduSetQosParametersType ResultFromType;
    const ResultFromType result_from = obj->getDesiredDownlinkPduSetQosParameters();
    const data_collection_model_pdu_set_qos_para_t *result = reinterpret_cast<const data_collection_model_pdu_set_qos_para_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_downlink_pdu_set_qos_parameters(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_downlink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredDownlinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDesiredDownlinkPduSetQosParameters(value)) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_downlink_pdu_set_qos_parameters_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_downlink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredDownlinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDesiredDownlinkPduSetQosParameters(std::move(value))) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_m5_qo_s_specification_get_desired_uplink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    if (!obj_m5_qo_s_specification) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    typedef typename M5QoSSpecification::DesiredUplinkPduSetQosParametersType ResultFromType;
    const ResultFromType result_from = obj->getDesiredUplinkPduSetQosParameters();
    const data_collection_model_pdu_set_qos_para_t *result = reinterpret_cast<const data_collection_model_pdu_set_qos_para_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_uplink_pdu_set_qos_parameters(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_uplink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredUplinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDesiredUplinkPduSetQosParameters(value)) return NULL;

    return obj_m5_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_uplink_pdu_set_qos_parameters_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters)
{
    if (!obj_m5_qo_s_specification) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_uplink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredUplinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDesiredUplinkPduSetQosParameters(std::move(value))) return NULL;

    return obj_m5_qo_s_specification;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_m5_qo_s_specification_make_lnode(data_collection_model_m5_qo_s_specification_t *p_m5_qo_s_specification)
{
    return data_collection_lnode_create(p_m5_qo_s_specification, reinterpret_cast<void(*)(void*)>(data_collection_model_m5_qo_s_specification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_m5_qo_s_specification_refcount(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    if (!obj_m5_qo_s_specification) return 0l;
    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
