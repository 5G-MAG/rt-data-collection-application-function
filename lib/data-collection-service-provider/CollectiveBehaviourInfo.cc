/**********************************************************************************************************************************
 * CollectiveBehaviourInfo - C interface to the CollectiveBehaviourInfo object
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

/*#include "CollectiveBehaviourInfo.h" already included by data-collection-sp/data-collection.h */
#include "CollectiveBehaviourInfo-internal.h"
#include "openapi/model/CollectiveBehaviourInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create(









)
{
    return reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo>(new CollectiveBehaviourInfo(









)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_copy(const data_collection_model_collective_behaviour_info_t *other)
{
    return reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo >(new CollectiveBehaviourInfo(**reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_move(data_collection_model_collective_behaviour_info_t *other)
{
    return reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo >(std::move(*reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_copy(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_collective_behaviour_info_t *other)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
    *obj = **reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(other);
    return collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_collective_behaviour_info_t *other)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(other));
    return collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_collective_behaviour_info_free(data_collection_model_collective_behaviour_info_t *collective_behaviour_info)
{
    delete reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_collective_behaviour_info_toJSON(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, bool as_request)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo >(new CollectiveBehaviourInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_collective_behaviour_info_is_equal_to(const data_collection_model_collective_behaviour_info_t *first, const data_collection_model_collective_behaviour_info_t *second)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(first);
    const std::shared_ptr<CollectiveBehaviourInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_collective_behaviour_info_get_col_attrib(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::ColAttribType ResultFromType;
    const ResultFromType result_from = obj->getColAttrib();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_per_ue_attribute_t *item_obj = reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute >(item));
        node = data_collection_model_per_ue_attribute_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_col_attrib)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_col_attrib;
    typedef typename CollectiveBehaviourInfo::ColAttribType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setColAttrib(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_col_attrib)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_col_attrib;
    typedef typename CollectiveBehaviourInfo::ColAttribType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_col_attrib);
    if (!obj->setColAttrib(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_per_ue_attribute_t* p_col_attrib)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::ColAttribType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_col_attrib;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addColAttrib(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_per_ue_attribute_t* p_col_attrib)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::ColAttribType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_col_attrib;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeColAttrib(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{   
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    obj->clearColAttrib();
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_collective_behaviour_info_get_no_of_ues(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::NoOfUesType ResultFromType;
    const ResultFromType result_from = obj->getNoOfUes();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const int32_t p_no_of_ues)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_no_of_ues;
    typedef typename CollectiveBehaviourInfo::NoOfUesType ValueType;

    ValueType value = value_from;
    if (!obj->setNoOfUes(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, int32_t p_no_of_ues)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_no_of_ues;
    typedef typename CollectiveBehaviourInfo::NoOfUesType ValueType;

    ValueType value = value_from;
    
    if (!obj->setNoOfUes(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_collective_behaviour_info_get_app_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::AppIdsType ResultFromType;
    const ResultFromType result_from = obj->getAppIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_app_ids)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_app_ids;
    typedef typename CollectiveBehaviourInfo::AppIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setAppIds(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_app_ids)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_app_ids;
    typedef typename CollectiveBehaviourInfo::AppIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_app_ids);
    if (!obj->setAppIds(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, char* p_app_ids)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::AppIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_app_ids;

    ValueType value(value_from);

    obj->addAppIds(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const char* p_app_ids)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::AppIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_app_ids;
    ValueType value(value_from);
    obj->removeAppIds(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{   
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    obj->clearAppIds();
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_collective_behaviour_info_get_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ResultFromType;
    const ResultFromType result_from = obj->getExtUeIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_ext_ue_ids)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_ext_ue_ids;
    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setExtUeIds(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_ext_ue_ids)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_ext_ue_ids;
    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_ext_ue_ids);
    if (!obj->setExtUeIds(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, char* p_ext_ue_ids)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ext_ue_ids;

    ValueType value(value_from);

    obj->addExtUeIds(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const char* p_ext_ue_ids)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ext_ue_ids;
    ValueType value(value_from);
    obj->removeExtUeIds(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{   
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    obj->clearExtUeIds();
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_collective_behaviour_info_get_ue_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::UeIdsType ResultFromType;
    const ResultFromType result_from = obj->getUeIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_ue_ids)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_ue_ids;
    typedef typename CollectiveBehaviourInfo::UeIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setUeIds(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_ue_ids)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_ue_ids;
    typedef typename CollectiveBehaviourInfo::UeIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_ue_ids);
    if (!obj->setUeIds(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, char* p_ue_ids)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::UeIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_ids;

    ValueType value(value_from);

    obj->addUeIds(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const char* p_ue_ids)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::UeIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_ids;
    ValueType value(value_from);
    obj->removeUeIds(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{   
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    obj->clearUeIds();
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_collective_behaviour_info_get_collision_dist(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::CollisionDistType ResultFromType;
    const ResultFromType result_from = obj->getCollisionDist();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const int32_t p_collision_dist)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_collision_dist;
    typedef typename CollectiveBehaviourInfo::CollisionDistType ValueType;

    ValueType value = value_from;
    if (!obj->setCollisionDist(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, int32_t p_collision_dist)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_collision_dist;
    typedef typename CollectiveBehaviourInfo::CollisionDistType ValueType;

    ValueType value = value_from;
    
    if (!obj->setCollisionDist(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_collective_behaviour_info_get_abs_dirs(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::AbsDirsType ResultFromType;
    const ResultFromType result_from = obj->getAbsDirs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_direction_t *item_obj = reinterpret_cast<data_collection_model_direction_t*>(new std::shared_ptr<Direction >(item));
        node = data_collection_model_direction_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_abs_dirs)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_abs_dirs;
    typedef typename CollectiveBehaviourInfo::AbsDirsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setAbsDirs(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_abs_dirs)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_abs_dirs;
    typedef typename CollectiveBehaviourInfo::AbsDirsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_abs_dirs);
    if (!obj->setAbsDirs(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_direction_t* p_abs_dirs)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::AbsDirsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_abs_dirs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addAbsDirs(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_direction_t* p_abs_dirs)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::AbsDirsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_abs_dirs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeAbsDirs(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{   
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    obj->clearAbsDirs();
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_collective_behaviour_info_get_rel_dirs(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::RelDirsType ResultFromType;
    const ResultFromType result_from = obj->getRelDirs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_relative_direction_t *item_obj = reinterpret_cast<data_collection_model_relative_direction_t*>(new std::shared_ptr<RelativeDirection >(item));
        node = data_collection_model_relative_direction_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_rel_dirs)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_rel_dirs;
    typedef typename CollectiveBehaviourInfo::RelDirsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRelDirs(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_rel_dirs)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_rel_dirs;
    typedef typename CollectiveBehaviourInfo::RelDirsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_rel_dirs);
    if (!obj->setRelDirs(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_relative_direction_t* p_rel_dirs)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::RelDirsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_rel_dirs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRelDirs(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_relative_direction_t* p_rel_dirs)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::RelDirsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_rel_dirs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRelDirs(value);
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{   
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    obj->clearRelDirs();
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ue_trajectory_collection_t* data_collection_model_collective_behaviour_info_get_ue_trajectory(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::UeTrajectoryType ResultFromType;
    const ResultFromType result_from = obj->getUeTrajectory();
    const data_collection_model_ue_trajectory_collection_t *result = reinterpret_cast<const data_collection_model_ue_trajectory_collection_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_ue_trajectory_collection_t* p_ue_trajectory)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_ue_trajectory;
    typedef typename CollectiveBehaviourInfo::UeTrajectoryType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUeTrajectory(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_ue_trajectory_collection_t* p_ue_trajectory)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_ue_trajectory;
    typedef typename CollectiveBehaviourInfo::UeTrajectoryType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUeTrajectory(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_collective_behaviour_info_get_confidence(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    typedef typename CollectiveBehaviourInfo::ConfidenceType ResultFromType;
    const ResultFromType result_from = obj->getConfidence();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const int32_t p_confidence)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_confidence;
    typedef typename CollectiveBehaviourInfo::ConfidenceType ValueType;

    ValueType value = value_from;
    if (!obj->setConfidence(value)) return NULL;
    return obj_collective_behaviour_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, int32_t p_confidence)
{
    if (obj_collective_behaviour_info == NULL) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    const auto &value_from = p_confidence;
    typedef typename CollectiveBehaviourInfo::ConfidenceType ValueType;

    ValueType value = value_from;
    
    if (!obj->setConfidence(std::move(value))) return NULL;
    return obj_collective_behaviour_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_collective_behaviour_info_make_lnode(data_collection_model_collective_behaviour_info_t *p_collective_behaviour_info)
{
    return data_collection_lnode_create(p_collective_behaviour_info, reinterpret_cast<void(*)(void*)>(data_collection_model_collective_behaviour_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_collective_behaviour_info_refcount(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

