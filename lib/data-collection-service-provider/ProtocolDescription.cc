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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create(


)
{
    return reinterpret_cast<data_collection_model_protocol_description_t*>(new std::shared_ptr<ProtocolDescription>(new ProtocolDescription(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_copy(const data_collection_model_protocol_description_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_protocol_description_t*>(new std::shared_ptr<ProtocolDescription >(new ProtocolDescription(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_create_move(data_collection_model_protocol_description_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ProtocolDescription > *obj = reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_copy(data_collection_model_protocol_description_t *protocol_description, const data_collection_model_protocol_description_t *other)
{
    if (protocol_description) {
        std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(protocol_description);
        if (obj) {
            if (other) {
                const std::shared_ptr<ProtocolDescription > &other_obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(other);
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
                const std::shared_ptr<ProtocolDescription > &other_obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(other);
                if (other_obj) {
                    obj.reset(new ProtocolDescription(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        protocol_description = data_collection_model_protocol_description_create_copy(other);
    }
    return protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_move(data_collection_model_protocol_description_t *protocol_description, data_collection_model_protocol_description_t *other)
{
    std::shared_ptr<ProtocolDescription > *other_ptr = reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(other);

    if (protocol_description) {
        std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(protocol_description);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                protocol_description = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_protocol_description_free(data_collection_model_protocol_description_t *protocol_description)
{
    if (!protocol_description) return;
    delete reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(protocol_description);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_protocol_description_toJSON(const data_collection_model_protocol_description_t *protocol_description, bool as_request)
{
    if (!protocol_description) return NULL;
    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(protocol_description);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_is_equal_to(const data_collection_model_protocol_description_t *first, const data_collection_model_protocol_description_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ProtocolDescription > &obj2 = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ProtocolDescription > &obj1 = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_has_transport_proto(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) return false;

    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return false;

    return obj->getTransportProto().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_transport_proto_t* data_collection_model_protocol_description_get_transport_proto(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) {
        const data_collection_model_media_transport_proto_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) {
        const data_collection_model_media_transport_proto_t *result = NULL;
        return result;
    }

    typedef typename ProtocolDescription::TransportProtoType ResultFromType;
    const ResultFromType result_from = obj->getTransportProto();
    const data_collection_model_media_transport_proto_t *result = reinterpret_cast<const data_collection_model_media_transport_proto_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto(data_collection_model_protocol_description_t *obj_protocol_description, const data_collection_model_media_transport_proto_t* p_transport_proto)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    const auto &value_from = p_transport_proto;
    typedef typename ProtocolDescription::TransportProtoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTransportProto(value)) return NULL;

    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_transport_proto_move(data_collection_model_protocol_description_t *obj_protocol_description, data_collection_model_media_transport_proto_t* p_transport_proto)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    const auto &value_from = p_transport_proto;
    typedef typename ProtocolDescription::TransportProtoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setTransportProto(std::move(value))) return NULL;

    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_has_rtp_header_ext_info(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) return false;

    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return false;

    return obj->getRtpHeaderExtInfo().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_header_ext_info_t* data_collection_model_protocol_description_get_rtp_header_ext_info(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) {
        const data_collection_model_rtp_header_ext_info_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) {
        const data_collection_model_rtp_header_ext_info_t *result = NULL;
        return result;
    }

    typedef typename ProtocolDescription::RtpHeaderExtInfoType ResultFromType;
    const ResultFromType result_from = obj->getRtpHeaderExtInfo();
    const data_collection_model_rtp_header_ext_info_t *result = reinterpret_cast<const data_collection_model_rtp_header_ext_info_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info(data_collection_model_protocol_description_t *obj_protocol_description, const data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_header_ext_info;
    typedef typename ProtocolDescription::RtpHeaderExtInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRtpHeaderExtInfo(value)) return NULL;

    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_header_ext_info_move(data_collection_model_protocol_description_t *obj_protocol_description, data_collection_model_rtp_header_ext_info_t* p_rtp_header_ext_info)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_header_ext_info;
    typedef typename ProtocolDescription::RtpHeaderExtInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRtpHeaderExtInfo(std::move(value))) return NULL;

    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_protocol_description_has_rtp_payload_info_list(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) return false;

    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return false;

    return obj->getRtpPayloadInfoList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_protocol_description_get_rtp_payload_info_list(const data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<const std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ProtocolDescription::RtpPayloadInfoListType ResultFromType;
    const ResultFromType result_from = obj->getRtpPayloadInfoList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_rtp_payload_info_t *item_obj = reinterpret_cast<data_collection_model_rtp_payload_info_t*>(item.has_value()?new std::shared_ptr<RtpPayloadInfo >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_rtp_payload_info_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description, const ogs_list_t* p_rtp_payload_info_list)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_payload_info_list;
    typedef typename ProtocolDescription::RtpPayloadInfoListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRtpPayloadInfoList(value)) return NULL;

    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_set_rtp_payload_info_list_move(data_collection_model_protocol_description_t *obj_protocol_description, ogs_list_t* p_rtp_payload_info_list)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_payload_info_list;
    typedef typename ProtocolDescription::RtpPayloadInfoListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_rtp_payload_info_list);
    if (!obj->setRtpPayloadInfoList(std::move(value))) return NULL;

    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_add_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description, data_collection_model_rtp_payload_info_t* p_rtp_payload_info_list)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    typedef typename ProtocolDescription::RtpPayloadInfoListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_rtp_payload_info_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addRtpPayloadInfoList(value.value());
    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_remove_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description, const data_collection_model_rtp_payload_info_t* p_rtp_payload_info_list)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    typedef typename ProtocolDescription::RtpPayloadInfoListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_rtp_payload_info_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeRtpPayloadInfoList(value);
    return obj_protocol_description;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_protocol_description_t *data_collection_model_protocol_description_clear_rtp_payload_info_list(data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) return NULL;

    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    if (!obj) return NULL;

    obj->clearRtpPayloadInfoList();
    return obj_protocol_description;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_protocol_description_make_lnode(data_collection_model_protocol_description_t *p_protocol_description)
{
    return data_collection_lnode_create(p_protocol_description, reinterpret_cast<void(*)(void*)>(data_collection_model_protocol_description_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_protocol_description_refcount(data_collection_model_protocol_description_t *obj_protocol_description)
{
    if (!obj_protocol_description) return 0l;
    std::shared_ptr<ProtocolDescription > &obj = *reinterpret_cast<std::shared_ptr<ProtocolDescription >*>(obj_protocol_description);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

