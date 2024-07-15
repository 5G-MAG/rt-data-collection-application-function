/**********************************************************************************************************************************
 * IpPacketFilterSet - C interface to the IpPacketFilterSet object
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

/*#include "IpPacketFilterSet.h" already included by data-collection-sp/data-collection.h */
#include "IpPacketFilterSet-internal.h"
#include "openapi/model/IpPacketFilterSet.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create(








)
{
    return reinterpret_cast<data_collection_model_ip_packet_filter_set_t*>(new std::shared_ptr<IpPacketFilterSet>(new IpPacketFilterSet(








)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create_copy(const data_collection_model_ip_packet_filter_set_t *other)
{
    return reinterpret_cast<data_collection_model_ip_packet_filter_set_t*>(new std::shared_ptr<IpPacketFilterSet >(new IpPacketFilterSet(**reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_create_move(data_collection_model_ip_packet_filter_set_t *other)
{
    return reinterpret_cast<data_collection_model_ip_packet_filter_set_t*>(new std::shared_ptr<IpPacketFilterSet >(std::move(*reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_copy(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, const data_collection_model_ip_packet_filter_set_t *other)
{
    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(ip_packet_filter_set);
    *obj = **reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(other);
    return ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_move(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, data_collection_model_ip_packet_filter_set_t *other)
{
    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(ip_packet_filter_set);
    obj = std::move(*reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(other));
    return ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ip_packet_filter_set_free(data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set)
{
    delete reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(ip_packet_filter_set);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ip_packet_filter_set_toJSON(const data_collection_model_ip_packet_filter_set_t *ip_packet_filter_set, bool as_request)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(ip_packet_filter_set);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ip_packet_filter_set_t*>(new std::shared_ptr<IpPacketFilterSet >(new IpPacketFilterSet(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ip_packet_filter_set_get_direction(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::DirectionType ResultFromType;
    const ResultFromType result_from = obj->getDirection();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_direction(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const char* p_direction)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_direction;
    typedef typename IpPacketFilterSet::DirectionType ValueType;

    ValueType value(value_from);
    if (!obj->setDirection(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_direction_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, char* p_direction)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_direction;
    typedef typename IpPacketFilterSet::DirectionType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDirection(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ip_addr_t* data_collection_model_ip_packet_filter_set_get_source_address(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::SourceAddressType ResultFromType;
    const ResultFromType result_from = obj->getSourceAddress();
    const data_collection_model_ip_addr_t *result = reinterpret_cast<const data_collection_model_ip_addr_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_address(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const data_collection_model_ip_addr_t* p_source_address)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_source_address;
    typedef typename IpPacketFilterSet::SourceAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSourceAddress(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_address_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, data_collection_model_ip_addr_t* p_source_address)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_source_address;
    typedef typename IpPacketFilterSet::SourceAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSourceAddress(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ip_addr_t* data_collection_model_ip_packet_filter_set_get_destination_address(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::DestinationAddressType ResultFromType;
    const ResultFromType result_from = obj->getDestinationAddress();
    const data_collection_model_ip_addr_t *result = reinterpret_cast<const data_collection_model_ip_addr_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_address(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const data_collection_model_ip_addr_t* p_destination_address)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_destination_address;
    typedef typename IpPacketFilterSet::DestinationAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDestinationAddress(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_address_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, data_collection_model_ip_addr_t* p_destination_address)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_destination_address;
    typedef typename IpPacketFilterSet::DestinationAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDestinationAddress(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ip_packet_filter_set_get_protocol_number(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::ProtocolNumberType ResultFromType;
    const ResultFromType result_from = obj->getProtocolNumber();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_protocol_number(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const int32_t p_protocol_number)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_protocol_number;
    typedef typename IpPacketFilterSet::ProtocolNumberType ValueType;

    ValueType value = value_from;
    if (!obj->setProtocolNumber(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_protocol_number_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, int32_t p_protocol_number)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_protocol_number;
    typedef typename IpPacketFilterSet::ProtocolNumberType ValueType;

    ValueType value = value_from;
    
    if (!obj->setProtocolNumber(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ip_packet_filter_set_get_source_port(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::SourcePortType ResultFromType;
    const ResultFromType result_from = obj->getSourcePort();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_port(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const int32_t p_source_port)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_source_port;
    typedef typename IpPacketFilterSet::SourcePortType ValueType;

    ValueType value = value_from;
    if (!obj->setSourcePort(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_source_port_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, int32_t p_source_port)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_source_port;
    typedef typename IpPacketFilterSet::SourcePortType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSourcePort(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ip_packet_filter_set_get_destination_port(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::DestinationPortType ResultFromType;
    const ResultFromType result_from = obj->getDestinationPort();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_port(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const int32_t p_destination_port)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_destination_port;
    typedef typename IpPacketFilterSet::DestinationPortType ValueType;

    ValueType value = value_from;
    if (!obj->setDestinationPort(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_destination_port_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, int32_t p_destination_port)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_destination_port;
    typedef typename IpPacketFilterSet::DestinationPortType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDestinationPort(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ip_packet_filter_set_get_differentiated_services_code_point(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::DifferentiatedServicesCodePointType ResultFromType;
    const ResultFromType result_from = obj->getDifferentiatedServicesCodePoint();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_differentiated_services_code_point(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const int32_t p_differentiated_services_code_point)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_differentiated_services_code_point;
    typedef typename IpPacketFilterSet::DifferentiatedServicesCodePointType ValueType;

    ValueType value = value_from;
    if (!obj->setDifferentiatedServicesCodePoint(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_differentiated_services_code_point_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, int32_t p_differentiated_services_code_point)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_differentiated_services_code_point;
    typedef typename IpPacketFilterSet::DifferentiatedServicesCodePointType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDifferentiatedServicesCodePoint(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ip_packet_filter_set_get_flow_label(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::FlowLabelType ResultFromType;
    const ResultFromType result_from = obj->getFlowLabel();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_flow_label(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const int32_t p_flow_label)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_flow_label;
    typedef typename IpPacketFilterSet::FlowLabelType ValueType;

    ValueType value = value_from;
    if (!obj->setFlowLabel(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_flow_label_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, int32_t p_flow_label)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_flow_label;
    typedef typename IpPacketFilterSet::FlowLabelType ValueType;

    ValueType value = value_from;
    
    if (!obj->setFlowLabel(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_ip_packet_filter_set_get_security_parameters_index(const data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    const std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<const std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    typedef typename IpPacketFilterSet::SecurityParametersIndexType ResultFromType;
    const ResultFromType result_from = obj->getSecurityParametersIndex();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_security_parameters_index(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, const int32_t p_security_parameters_index)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_security_parameters_index;
    typedef typename IpPacketFilterSet::SecurityParametersIndexType ValueType;

    ValueType value = value_from;
    if (!obj->setSecurityParametersIndex(value)) return NULL;
    return obj_ip_packet_filter_set;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_packet_filter_set_t *data_collection_model_ip_packet_filter_set_set_security_parameters_index_move(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set, int32_t p_security_parameters_index)
{
    if (obj_ip_packet_filter_set == NULL) return NULL;

    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    const auto &value_from = p_security_parameters_index;
    typedef typename IpPacketFilterSet::SecurityParametersIndexType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSecurityParametersIndex(std::move(value))) return NULL;
    return obj_ip_packet_filter_set;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ip_packet_filter_set_make_lnode(data_collection_model_ip_packet_filter_set_t *p_ip_packet_filter_set)
{
    return data_collection_lnode_create(p_ip_packet_filter_set, reinterpret_cast<void(*)(void*)>(data_collection_model_ip_packet_filter_set_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ip_packet_filter_set_refcount(data_collection_model_ip_packet_filter_set_t *obj_ip_packet_filter_set)
{
    std::shared_ptr<IpPacketFilterSet > &obj = *reinterpret_cast<std::shared_ptr<IpPacketFilterSet >*>(obj_ip_packet_filter_set);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

