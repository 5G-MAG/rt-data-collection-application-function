/**********************************************************************************************************************************
 * EthFlowDescription - C interface to the EthFlowDescription object
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

/*#include "EthFlowDescription.h" already included by data-collection-sp/data-collection.h */
#include "EthFlowDescription-internal.h"
#include "openapi/model/EthFlowDescription.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create(







)
{
    return reinterpret_cast<data_collection_model_eth_flow_description_t*>(new std::shared_ptr<EthFlowDescription>(new EthFlowDescription(







)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create_copy(const data_collection_model_eth_flow_description_t *other)
{
    return reinterpret_cast<data_collection_model_eth_flow_description_t*>(new std::shared_ptr<EthFlowDescription >(new EthFlowDescription(**reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create_move(data_collection_model_eth_flow_description_t *other)
{
    return reinterpret_cast<data_collection_model_eth_flow_description_t*>(new std::shared_ptr<EthFlowDescription >(std::move(*reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_copy(data_collection_model_eth_flow_description_t *eth_flow_description, const data_collection_model_eth_flow_description_t *other)
{
    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(eth_flow_description);
    *obj = **reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(other);
    return eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_move(data_collection_model_eth_flow_description_t *eth_flow_description, data_collection_model_eth_flow_description_t *other)
{
    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(eth_flow_description);
    obj = std::move(*reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(other));
    return eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_eth_flow_description_free(data_collection_model_eth_flow_description_t *eth_flow_description)
{
    delete reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(eth_flow_description);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_eth_flow_description_toJSON(const data_collection_model_eth_flow_description_t *eth_flow_description, bool as_request)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(eth_flow_description);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_eth_flow_description_t*>(new std::shared_ptr<EthFlowDescription >(new EthFlowDescription(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_eth_flow_description_is_equal_to(const data_collection_model_eth_flow_description_t *first, const data_collection_model_eth_flow_description_t *second)
{
    const std::shared_ptr<EthFlowDescription > &obj1 = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(first);
    const std::shared_ptr<EthFlowDescription > &obj2 = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_eth_flow_description_get_dest_mac_addr(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::DestMacAddrType ResultFromType;
    const ResultFromType result_from = obj->getDestMacAddr();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const char* p_dest_mac_addr)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_dest_mac_addr;
    typedef typename EthFlowDescription::DestMacAddrType ValueType;

    ValueType value(value_from);
    if (!obj->setDestMacAddr(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, char* p_dest_mac_addr)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_dest_mac_addr;
    typedef typename EthFlowDescription::DestMacAddrType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDestMacAddr(std::move(value))) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_eth_flow_description_get_eth_type(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::EthTypeType ResultFromType;
    const ResultFromType result_from = obj->getEthType();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_eth_type(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const char* p_eth_type)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_eth_type;
    typedef typename EthFlowDescription::EthTypeType ValueType;

    ValueType value(value_from);
    if (!obj->setEthType(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_eth_type_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, char* p_eth_type)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_eth_type;
    typedef typename EthFlowDescription::EthTypeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setEthType(std::move(value))) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_eth_flow_description_get_f_desc(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::FDescType ResultFromType;
    const ResultFromType result_from = obj->getFDesc();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_desc(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const char* p_f_desc)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_f_desc;
    typedef typename EthFlowDescription::FDescType ValueType;

    ValueType value(value_from);
    if (!obj->setFDesc(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_desc_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, char* p_f_desc)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_f_desc;
    typedef typename EthFlowDescription::FDescType ValueType;

    ValueType value(value_from);
    
    if (!obj->setFDesc(std::move(value))) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_flow_direction_t* data_collection_model_eth_flow_description_get_f_dir(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::FDirType ResultFromType;
    const ResultFromType result_from = obj->getFDir();
    const data_collection_model_flow_direction_t *result = reinterpret_cast<const data_collection_model_flow_direction_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_dir(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const data_collection_model_flow_direction_t* p_f_dir)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_f_dir;
    typedef typename EthFlowDescription::FDirType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setFDir(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_dir_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, data_collection_model_flow_direction_t* p_f_dir)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_f_dir;
    typedef typename EthFlowDescription::FDirType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setFDir(std::move(value))) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_eth_flow_description_get_source_mac_addr(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::SourceMacAddrType ResultFromType;
    const ResultFromType result_from = obj->getSourceMacAddr();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_source_mac_addr(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const char* p_source_mac_addr)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_source_mac_addr;
    typedef typename EthFlowDescription::SourceMacAddrType ValueType;

    ValueType value(value_from);
    if (!obj->setSourceMacAddr(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_source_mac_addr_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, char* p_source_mac_addr)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_source_mac_addr;
    typedef typename EthFlowDescription::SourceMacAddrType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSourceMacAddr(std::move(value))) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_eth_flow_description_get_vlan_tags(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::VlanTagsType ResultFromType;
    const ResultFromType result_from = obj->getVlanTags();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_vlan_tags(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const ogs_list_t* p_vlan_tags)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_vlan_tags;
    typedef typename EthFlowDescription::VlanTagsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setVlanTags(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_vlan_tags_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, ogs_list_t* p_vlan_tags)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_vlan_tags;
    typedef typename EthFlowDescription::VlanTagsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_vlan_tags);
    if (!obj->setVlanTags(std::move(value))) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_add_vlan_tags(data_collection_model_eth_flow_description_t *obj_eth_flow_description, char* p_vlan_tags)
{
    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::VlanTagsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_vlan_tags;

    ValueType value(value_from);

    obj->addVlanTags(value);
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_remove_vlan_tags(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const char* p_vlan_tags)
{
    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::VlanTagsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_vlan_tags;
    ValueType value(value_from);
    obj->removeVlanTags(value);
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_clear_vlan_tags(data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{   
    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    obj->clearVlanTags();
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_eth_flow_description_get_src_mac_addr_end(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::SrcMacAddrEndType ResultFromType;
    const ResultFromType result_from = obj->getSrcMacAddrEnd();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_src_mac_addr_end(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const char* p_src_mac_addr_end)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_src_mac_addr_end;
    typedef typename EthFlowDescription::SrcMacAddrEndType ValueType;

    ValueType value(value_from);
    if (!obj->setSrcMacAddrEnd(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_src_mac_addr_end_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, char* p_src_mac_addr_end)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_src_mac_addr_end;
    typedef typename EthFlowDescription::SrcMacAddrEndType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSrcMacAddrEnd(std::move(value))) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_eth_flow_description_get_dest_mac_addr_end(const data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    const std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    typedef typename EthFlowDescription::DestMacAddrEndType ResultFromType;
    const ResultFromType result_from = obj->getDestMacAddrEnd();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_end(data_collection_model_eth_flow_description_t *obj_eth_flow_description, const char* p_dest_mac_addr_end)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_dest_mac_addr_end;
    typedef typename EthFlowDescription::DestMacAddrEndType ValueType;

    ValueType value(value_from);
    if (!obj->setDestMacAddrEnd(value)) return NULL;
    return obj_eth_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_end_move(data_collection_model_eth_flow_description_t *obj_eth_flow_description, char* p_dest_mac_addr_end)
{
    if (obj_eth_flow_description == NULL) return NULL;

    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    const auto &value_from = p_dest_mac_addr_end;
    typedef typename EthFlowDescription::DestMacAddrEndType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDestMacAddrEnd(std::move(value))) return NULL;
    return obj_eth_flow_description;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_eth_flow_description_make_lnode(data_collection_model_eth_flow_description_t *p_eth_flow_description)
{
    return data_collection_lnode_create(p_eth_flow_description, reinterpret_cast<void(*)(void*)>(data_collection_model_eth_flow_description_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_eth_flow_description_refcount(data_collection_model_eth_flow_description_t *obj_eth_flow_description)
{
    std::shared_ptr<EthFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<EthFlowDescription >*>(obj_eth_flow_description);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

