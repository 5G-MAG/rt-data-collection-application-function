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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create(





)
{
    return reinterpret_cast<data_collection_model_m5_qo_s_specification_t*>(new std::shared_ptr<M5QoSSpecification>(new M5QoSSpecification(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create_copy(const data_collection_model_m5_qo_s_specification_t *other)
{
    return reinterpret_cast<data_collection_model_m5_qo_s_specification_t*>(new std::shared_ptr<M5QoSSpecification >(new M5QoSSpecification(**reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create_move(data_collection_model_m5_qo_s_specification_t *other)
{
    return reinterpret_cast<data_collection_model_m5_qo_s_specification_t*>(new std::shared_ptr<M5QoSSpecification >(std::move(*reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_copy(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_m5_qo_s_specification_t *other)
{
    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
    *obj = **reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(other);
    return m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, data_collection_model_m5_qo_s_specification_t *other)
{
    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
    obj = std::move(*reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(other));
    return m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_m5_qo_s_specification_free(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification)
{
    delete reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_m5_qo_s_specification_toJSON(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, bool as_request)
{
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(m5_qo_s_specification);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_m5_bit_rate_specification_t* data_collection_model_m5_qo_s_specification_get_downlink_bit_rates(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    typedef typename M5QoSSpecification::DownlinkBitRatesType ResultFromType;
    const ResultFromType result_from = obj->getDownlinkBitRates();
    const data_collection_model_m5_bit_rate_specification_t *result = reinterpret_cast<const data_collection_model_m5_bit_rate_specification_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_downlink_bit_rates(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_m5_bit_rate_specification_t* p_downlink_bit_rates)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_downlink_bit_rates;
    typedef typename M5QoSSpecification::DownlinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDownlinkBitRates(value)) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_downlink_bit_rates_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_m5_bit_rate_specification_t* p_downlink_bit_rates)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_downlink_bit_rates;
    typedef typename M5QoSSpecification::DownlinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDownlinkBitRates(std::move(value))) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_m5_bit_rate_specification_t* data_collection_model_m5_qo_s_specification_get_uplink_bit_rates(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    typedef typename M5QoSSpecification::UplinkBitRatesType ResultFromType;
    const ResultFromType result_from = obj->getUplinkBitRates();
    const data_collection_model_m5_bit_rate_specification_t *result = reinterpret_cast<const data_collection_model_m5_bit_rate_specification_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_uplink_bit_rates(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_m5_bit_rate_specification_t* p_uplink_bit_rates)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_uplink_bit_rates;
    typedef typename M5QoSSpecification::UplinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUplinkBitRates(value)) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_uplink_bit_rates_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_m5_bit_rate_specification_t* p_uplink_bit_rates)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_uplink_bit_rates;
    typedef typename M5QoSSpecification::UplinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUplinkBitRates(std::move(value))) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_m5_qo_s_specification_get_desired_packet_latency(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    typedef typename M5QoSSpecification::DesiredPacketLatencyType ResultFromType;
    const ResultFromType result_from = obj->getDesiredPacketLatency();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_latency(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const int32_t p_desired_packet_latency)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_packet_latency;
    typedef typename M5QoSSpecification::DesiredPacketLatencyType ValueType;

    ValueType value = value_from;
    if (!obj->setDesiredPacketLatency(value)) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_latency_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, int32_t p_desired_packet_latency)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_packet_latency;
    typedef typename M5QoSSpecification::DesiredPacketLatencyType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDesiredPacketLatency(std::move(value))) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_m5_qo_s_specification_get_desired_packet_loss_rate(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    typedef typename M5QoSSpecification::DesiredPacketLossRateType ResultFromType;
    const ResultFromType result_from = obj->getDesiredPacketLossRate();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_loss_rate(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const int32_t p_desired_packet_loss_rate)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename M5QoSSpecification::DesiredPacketLossRateType ValueType;

    ValueType value = value_from;
    if (!obj->setDesiredPacketLossRate(value)) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_loss_rate_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, int32_t p_desired_packet_loss_rate)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename M5QoSSpecification::DesiredPacketLossRateType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDesiredPacketLossRate(std::move(value))) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_pdu_set_qos_para_t* data_collection_model_m5_qo_s_specification_get_desired_downlink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    typedef typename M5QoSSpecification::DesiredDownlinkPduSetQosParametersType ResultFromType;
    const ResultFromType result_from = obj->getDesiredDownlinkPduSetQosParameters();
    const data_collection_model_pdu_set_qos_para_t *result = reinterpret_cast<const data_collection_model_pdu_set_qos_para_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_downlink_pdu_set_qos_parameters(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_downlink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredDownlinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDesiredDownlinkPduSetQosParameters(value)) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_downlink_pdu_set_qos_parameters_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_downlink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredDownlinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDesiredDownlinkPduSetQosParameters(std::move(value))) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_pdu_set_qos_para_t* data_collection_model_m5_qo_s_specification_get_desired_uplink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    const std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    typedef typename M5QoSSpecification::DesiredUplinkPduSetQosParametersType ResultFromType;
    const ResultFromType result_from = obj->getDesiredUplinkPduSetQosParameters();
    const data_collection_model_pdu_set_qos_para_t *result = reinterpret_cast<const data_collection_model_pdu_set_qos_para_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_uplink_pdu_set_qos_parameters(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_uplink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredUplinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDesiredUplinkPduSetQosParameters(value)) return NULL;
    return obj_m5_qo_s_specification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_uplink_pdu_set_qos_parameters_move(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification, data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters)
{
    if (obj_m5_qo_s_specification == NULL) return NULL;

    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    const auto &value_from = p_desired_uplink_pdu_set_qos_parameters;
    typedef typename M5QoSSpecification::DesiredUplinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDesiredUplinkPduSetQosParameters(std::move(value))) return NULL;
    return obj_m5_qo_s_specification;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_m5_qo_s_specification_make_lnode(data_collection_model_m5_qo_s_specification_t *p_m5_qo_s_specification)
{
    return data_collection_lnode_create(p_m5_qo_s_specification, reinterpret_cast<void(*)(void*)>(data_collection_model_m5_qo_s_specification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_m5_qo_s_specification_refcount(data_collection_model_m5_qo_s_specification_t *obj_m5_qo_s_specification)
{
    std::shared_ptr<M5QoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<M5QoSSpecification >*>(obj_m5_qo_s_specification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

