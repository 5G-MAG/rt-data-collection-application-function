/**********************************************************************************************************************************
 * ClientQosSpecification - C interface to the ClientQosSpecification object
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

/*#include "ClientQosSpecification.h" already included by data-collection-sp/data-collection.h */
#include "ClientQosSpecification-internal.h"
#include "openapi/model/ClientQosSpecification.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create(





)
{
    return reinterpret_cast<data_collection_model_client_qos_specification_t*>(new std::shared_ptr<ClientQosSpecification>(new ClientQosSpecification(





)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create_ref(const data_collection_model_client_qos_specification_t *other)
{
    return reinterpret_cast<data_collection_model_client_qos_specification_t*>(new std::shared_ptr<ClientQosSpecification>(*reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create_copy(const data_collection_model_client_qos_specification_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_client_qos_specification_t*>(new std::shared_ptr<ClientQosSpecification >(new ClientQosSpecification(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create_move(data_collection_model_client_qos_specification_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ClientQosSpecification > *obj = reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_copy(data_collection_model_client_qos_specification_t *client_qos_specification, const data_collection_model_client_qos_specification_t *other)
{
    if (client_qos_specification) {
        std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(client_qos_specification);
        if (obj) {
            if (other) {
                const std::shared_ptr<ClientQosSpecification > &other_obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(other);
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
                const std::shared_ptr<ClientQosSpecification > &other_obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(other);
                if (other_obj) {
                    obj.reset(new ClientQosSpecification(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        client_qos_specification = data_collection_model_client_qos_specification_create_copy(other);
    }
    return client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_move(data_collection_model_client_qos_specification_t *client_qos_specification, data_collection_model_client_qos_specification_t *other)
{
    std::shared_ptr<ClientQosSpecification > *other_ptr = reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(other);

    if (client_qos_specification) {
        std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(client_qos_specification);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                client_qos_specification = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_client_qos_specification_free(data_collection_model_client_qos_specification_t *client_qos_specification)
{
    if (!client_qos_specification) return;
    delete reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(client_qos_specification);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_client_qos_specification_toJSON(const data_collection_model_client_qos_specification_t *client_qos_specification, bool as_request)
{
    if (!client_qos_specification) return NULL;
    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(client_qos_specification);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_client_qos_specification_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_client_qos_specification_t*>(new std::shared_ptr<ClientQosSpecification >(new ClientQosSpecification(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_is_equal_to(const data_collection_model_client_qos_specification_t *first, const data_collection_model_client_qos_specification_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ClientQosSpecification > &obj2 = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ClientQosSpecification > &obj1 = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_bit_rate_specification_t* data_collection_model_client_qos_specification_get_downlink_bit_rates(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) {
        const data_collection_model_unidirectional_bit_rate_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) {
        const data_collection_model_unidirectional_bit_rate_specification_t *result = NULL;
        return result;
    }

    typedef typename ClientQosSpecification::DownlinkBitRatesType ResultFromType;
    const ResultFromType &result_from = obj->getDownlinkBitRates();
    const data_collection_model_unidirectional_bit_rate_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_bit_rate_specification_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_downlink_bit_rates(data_collection_model_client_qos_specification_t *obj_client_qos_specification, const data_collection_model_unidirectional_bit_rate_specification_t* p_downlink_bit_rates)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_bit_rates;
    typedef typename ClientQosSpecification::DownlinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setDownlinkBitRates(value)) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_downlink_bit_rates_move(data_collection_model_client_qos_specification_t *obj_client_qos_specification, data_collection_model_unidirectional_bit_rate_specification_t* p_downlink_bit_rates)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_bit_rates;
    typedef typename ClientQosSpecification::DownlinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setDownlinkBitRates(std::move(value))) return NULL;
    data_collection_model_unidirectional_bit_rate_specification_free
(p_downlink_bit_rates);

    return obj_client_qos_specification;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_bit_rate_specification_t* data_collection_model_client_qos_specification_get_uplink_bit_rates(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) {
        const data_collection_model_unidirectional_bit_rate_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) {
        const data_collection_model_unidirectional_bit_rate_specification_t *result = NULL;
        return result;
    }

    typedef typename ClientQosSpecification::UplinkBitRatesType ResultFromType;
    const ResultFromType &result_from = obj->getUplinkBitRates();
    const data_collection_model_unidirectional_bit_rate_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_bit_rate_specification_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_uplink_bit_rates(data_collection_model_client_qos_specification_t *obj_client_qos_specification, const data_collection_model_unidirectional_bit_rate_specification_t* p_uplink_bit_rates)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_bit_rates;
    typedef typename ClientQosSpecification::UplinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUplinkBitRates(value)) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_uplink_bit_rates_move(data_collection_model_client_qos_specification_t *obj_client_qos_specification, data_collection_model_unidirectional_bit_rate_specification_t* p_uplink_bit_rates)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_bit_rates;
    typedef typename ClientQosSpecification::UplinkBitRatesType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUplinkBitRates(std::move(value))) return NULL;
    data_collection_model_unidirectional_bit_rate_specification_free
(p_uplink_bit_rates);

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_packet_latency(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) return false;

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return false;

    return obj->getDesiredPacketLatency().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_client_qos_specification_get_desired_packet_latency(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename ClientQosSpecification::DesiredPacketLatencyType ResultFromType;
    const ResultFromType &result_from = obj->getDesiredPacketLatency();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_latency(data_collection_model_client_qos_specification_t *obj_client_qos_specification, const int32_t p_desired_packet_latency)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_latency;
    typedef typename ClientQosSpecification::DesiredPacketLatencyType ValueType;

    ValueType value(value_from);

    if (!obj->setDesiredPacketLatency(value)) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_latency_move(data_collection_model_client_qos_specification_t *obj_client_qos_specification, int32_t p_desired_packet_latency)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_latency;
    typedef typename ClientQosSpecification::DesiredPacketLatencyType ValueType;

    ValueType value(value_from);

    if (!obj->setDesiredPacketLatency(std::move(value))) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_packet_loss_rate(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) return false;

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return false;

    return obj->getDesiredPacketLossRate().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_client_qos_specification_get_desired_packet_loss_rate(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename ClientQosSpecification::DesiredPacketLossRateType ResultFromType;
    const ResultFromType &result_from = obj->getDesiredPacketLossRate();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_loss_rate(data_collection_model_client_qos_specification_t *obj_client_qos_specification, const int32_t p_desired_packet_loss_rate)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename ClientQosSpecification::DesiredPacketLossRateType ValueType;

    ValueType value(value_from);

    if (!obj->setDesiredPacketLossRate(value)) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_loss_rate_move(data_collection_model_client_qos_specification_t *obj_client_qos_specification, int32_t p_desired_packet_loss_rate)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename ClientQosSpecification::DesiredPacketLossRateType ValueType;

    ValueType value(value_from);

    if (!obj->setDesiredPacketLossRate(std::move(value))) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_downlink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) return false;

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return false;

    return obj->getDesiredDownlinkPduSetQosParameters().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_client_qos_specification_get_desired_downlink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    typedef typename ClientQosSpecification::DesiredDownlinkPduSetQosParametersType ResultFromType;
    const ResultFromType &result_from = obj->getDesiredDownlinkPduSetQosParameters();
    const data_collection_model_pdu_set_qos_para_t *result = reinterpret_cast<const data_collection_model_pdu_set_qos_para_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_downlink_pdu_set_qos_parameters(data_collection_model_client_qos_specification_t *obj_client_qos_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_downlink_pdu_set_qos_parameters;
    typedef typename ClientQosSpecification::DesiredDownlinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setDesiredDownlinkPduSetQosParameters(value)) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_downlink_pdu_set_qos_parameters_move(data_collection_model_client_qos_specification_t *obj_client_qos_specification, data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_downlink_pdu_set_qos_parameters;
    typedef typename ClientQosSpecification::DesiredDownlinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setDesiredDownlinkPduSetQosParameters(std::move(value))) return NULL;
    data_collection_model_pdu_set_qos_para_free
(p_desired_downlink_pdu_set_qos_parameters);

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_uplink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) return false;

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return false;

    return obj->getDesiredUplinkPduSetQosParameters().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_client_qos_specification_get_desired_uplink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<const std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) {
        const data_collection_model_pdu_set_qos_para_t *result = NULL;
        return result;
    }

    typedef typename ClientQosSpecification::DesiredUplinkPduSetQosParametersType ResultFromType;
    const ResultFromType &result_from = obj->getDesiredUplinkPduSetQosParameters();
    const data_collection_model_pdu_set_qos_para_t *result = reinterpret_cast<const data_collection_model_pdu_set_qos_para_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_uplink_pdu_set_qos_parameters(data_collection_model_client_qos_specification_t *obj_client_qos_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_uplink_pdu_set_qos_parameters;
    typedef typename ClientQosSpecification::DesiredUplinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setDesiredUplinkPduSetQosParameters(value)) return NULL;

    return obj_client_qos_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_uplink_pdu_set_qos_parameters_move(data_collection_model_client_qos_specification_t *obj_client_qos_specification, data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters)
{
    if (!obj_client_qos_specification) return NULL;

    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_uplink_pdu_set_qos_parameters;
    typedef typename ClientQosSpecification::DesiredUplinkPduSetQosParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setDesiredUplinkPduSetQosParameters(std::move(value))) return NULL;
    data_collection_model_pdu_set_qos_para_free
(p_desired_uplink_pdu_set_qos_parameters);

    return obj_client_qos_specification;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_client_qos_specification_make_lnode(data_collection_model_client_qos_specification_t *p_client_qos_specification)
{
    return data_collection_lnode_create(p_client_qos_specification, reinterpret_cast<void(*)(void*)>(data_collection_model_client_qos_specification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_client_qos_specification_refcount(data_collection_model_client_qos_specification_t *obj_client_qos_specification)
{
    if (!obj_client_qos_specification) return 0l;
    std::shared_ptr<ClientQosSpecification > &obj = *reinterpret_cast<std::shared_ptr<ClientQosSpecification >*>(obj_client_qos_specification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

