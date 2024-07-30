/**********************************************************************************************************************************
 * ProtocolDescription - C interface to the ProtocolDescription object
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

/*#include "ProtocolDescription.h" already included by data-collection-sp/data-collection.h */
#include "ProtocolDescription-internal.h"
#include "openapi/model/ProtocolDescription.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_create(


)
{
    return reinterpret_cast<data_collection_model_protocol_description_t*>(new std::shared_ptr<ProtocolDescription>(new ProtocolDescription(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_copy(const data_collection_model_protocol_description_t *other)
{
    return reinterpret_cast<data_collection_model_protocol_description_t*>(new std::shared_ptr<ProtocolDescription >(new ProtocolDescription(**reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_move(data_collection_model_protocol_description_t *other)
{
    return reinterpret_cast<data_collection_model_protocol_description_t*>(new std::shared_ptr<ProtocolDescription >(std::move(*reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_copy(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_protocol_description_t *other)
{
    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(protocol_description);
    *obj = **reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(other);
    return protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_protocol_description_t *other)
{
    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(protocol_description);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(other));
    return protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_protocol_description_free(data_collection_model_protocol_description_t *protocol_description)
{
    delete reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(protocol_description);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_protocol_description_toJSON(const data_collection_model_protocol_description_t *protocol_description, bool as_request)
{
    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(protocol_description);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_protocol_description_t*>(new std::shared_ptr<ProtocolDescription >(new ProtocolDescription(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_protocol_description_is_equal_to(const data_collection_model_protocol_description_t *first, const data_collection_model_protocol_description_t *second)
{
    const std::shared_ptr<ProtocolDescription > &obj1 = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(first);
    const std::shared_ptr<ProtocolDescription > &obj2 = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_media_transport_proto_t* data_collection_model_protocol_description_get_transport_proto(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    typedef typename ProtocolDescription::TransportProtoType ResultFromType;
    const ResultFromType result_from = obj->getTransportProto();
    const data_collection_model_media_transport_proto_t *result = reinterpret_cast<const data_collection_model_media_transport_proto_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto(data_collection_model_protocol_description_t *obj_protocol_description, const data_collection_model_media_transport_proto_t* p_transport_proto)
{
    if (obj_protocol_description == NULL) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    const auto &value_from = p_transport_proto;
    typedef typename ProtocolDescription::TransportProtoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTransportProto(value)) return NULL;
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto_move(data_collection_model_protocol_description_t *obj_protocol_description, data_collection_model_media_transport_proto_t* p_transport_proto)
{
    if (obj_protocol_description == NULL) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    const auto &value_from = p_transport_proto;
    typedef typename ProtocolDescription::TransportProtoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTransportProto(std::move(value))) return NULL;
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_rtp_header_ext_info_t* data_collection_model_protocol_description_get_rtp_header_ext_info(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    typedef typename ProtocolDescription::RtpHeaderExtInfoType ResultFromType;
    const ResultFromType result_from = obj->getRtpHeaderExtInfo();
    const data_collection_model_rtp_header_ext_info_t *result = reinterpret_cast<const data_collection_model_rtp_header_ext_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info(data_collection_model_protocol_description_t *obj_protocol_description, const data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info)
{
    if (obj_protocol_description == NULL) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    const auto &value_from = p_rtp_header_ext_info;
    typedef typename ProtocolDescription::RtpHeaderExtInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRtpHeaderExtInfo(value)) return NULL;
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info_move(data_collection_model_protocol_description_t *obj_protocol_description, data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info)
{
    if (obj_protocol_description == NULL) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    const auto &value_from = p_rtp_header_ext_info;
    typedef typename ProtocolDescription::RtpHeaderExtInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRtpHeaderExtInfo(std::move(value))) return NULL;
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_protocol_description_get_rtp_payload_info_list(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    typedef typename ProtocolDescription::RtpPayloadInfoListType ResultFromType;
    const ResultFromType result_from = obj->getRtpPayloadInfoList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_rtp_payload_info_t *item_obj = reinterpret_cast<data_collection_model_rtp_payload_info_t*>(new std::shared_ptr<RtpPayloadInfo >(item));
        node = data_collection_model_rtp_payload_info_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description, const ogs_list_t* p_rtp_payload_info_list)
{
    if (obj_protocol_description == NULL) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    const auto &value_from = p_rtp_payload_info_list;
    typedef typename ProtocolDescription::RtpPayloadInfoListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRtpPayloadInfoList(value)) return NULL;
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list_move(data_collection_model_protocol_description_t *obj_protocol_description, ogs_list_t* p_rtp_payload_info_list)
{
    if (obj_protocol_description == NULL) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    const auto &value_from = p_rtp_payload_info_list;
    typedef typename ProtocolDescription::RtpPayloadInfoListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_rtp_payload_info_list);
    if (!obj->setRtpPayloadInfoList(std::move(value))) return NULL;
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_add_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description, data_collection_model_rtp_payload_info_t* p_rtp_payload_info_list)
{
    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    typedef typename ProtocolDescription::RtpPayloadInfoListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_rtp_payload_info_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRtpPayloadInfoList(value);
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_remove_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description, const data_collection_model_rtp_payload_info_t* p_rtp_payload_info_list)
{
    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    typedef typename ProtocolDescription::RtpPayloadInfoListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_rtp_payload_info_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRtpPayloadInfoList(value);
    return obj_protocol_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_protocol_description_t *data_collection_model_protocol_description_clear_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description)
{   
    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    obj->clearRtpPayloadInfoList();
    return obj_protocol_description;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_protocol_description_make_lnode(data_collection_model_protocol_description_t *p_protocol_description)
{
    return data_collection_lnode_create(p_protocol_description, reinterpret_cast<void(*)(void*)>(data_collection_model_protocol_description_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_protocol_description_refcount(data_collection_model_protocol_description_t *obj_protocol_description)
{
    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

