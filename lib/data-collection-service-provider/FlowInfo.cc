/**********************************************************************************************************************************
 * FlowInfo - C interface to the FlowInfo object
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

/*#include "FlowInfo.h" already included by data-collection-sp/data-collection.h */
#include "FlowInfo-internal.h"
#include "openapi/model/FlowInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_create(


)
{
    return reinterpret_cast<data_collection_model_flow_info_t*>(new std::shared_ptr<FlowInfo>(new FlowInfo(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_create_copy(const data_collection_model_flow_info_t *other)
{
    return reinterpret_cast<data_collection_model_flow_info_t*>(new std::shared_ptr<FlowInfo >(new FlowInfo(**reinterpret_cast<const std::shared_ptr<FlowInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_create_move(data_collection_model_flow_info_t *other)
{
    return reinterpret_cast<data_collection_model_flow_info_t*>(new std::shared_ptr<FlowInfo >(std::move(*reinterpret_cast<std::shared_ptr<FlowInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_copy(data_collection_model_flow_info_t *flow_info, const data_collection_model_flow_info_t *other)
{
    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(flow_info);
    *obj = **reinterpret_cast<const std::shared_ptr<FlowInfo >*>(other);
    return flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_move(data_collection_model_flow_info_t *flow_info, data_collection_model_flow_info_t *other)
{
    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(flow_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<FlowInfo >*>(other));
    return flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_flow_info_free(data_collection_model_flow_info_t *flow_info)
{
    delete reinterpret_cast<std::shared_ptr<FlowInfo >*>(flow_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_flow_info_toJSON(const data_collection_model_flow_info_t *flow_info, bool as_request)
{
    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(flow_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_flow_info_t*>(new std::shared_ptr<FlowInfo >(new FlowInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_flow_info_is_equal_to(const data_collection_model_flow_info_t *first, const data_collection_model_flow_info_t *second)
{
    const std::shared_ptr<FlowInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(first);
    const std::shared_ptr<FlowInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_flow_info_get_flow_id(const data_collection_model_flow_info_t *obj_flow_info)
{
    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    typedef typename FlowInfo::FlowIdType ResultFromType;
    const ResultFromType result_from = obj->getFlowId();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id(data_collection_model_flow_info_t *obj_flow_info, const int32_t p_flow_id)
{
    if (obj_flow_info == NULL) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    const auto &value_from = p_flow_id;
    typedef typename FlowInfo::FlowIdType ValueType;

    ValueType value = value_from;
    if (!obj->setFlowId(value)) return NULL;
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id_move(data_collection_model_flow_info_t *obj_flow_info, int32_t p_flow_id)
{
    if (obj_flow_info == NULL) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    const auto &value_from = p_flow_id;
    typedef typename FlowInfo::FlowIdType ValueType;

    ValueType value = value_from;
    
    if (!obj->setFlowId(std::move(value))) return NULL;
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_flow_info_get_flow_descriptions(const data_collection_model_flow_info_t *obj_flow_info)
{
    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    typedef typename FlowInfo::FlowDescriptionsType ResultFromType;
    const ResultFromType result_from = obj->getFlowDescriptions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info, const ogs_list_t* p_flow_descriptions)
{
    if (obj_flow_info == NULL) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    const auto &value_from = p_flow_descriptions;
    typedef typename FlowInfo::FlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setFlowDescriptions(value)) return NULL;
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions_move(data_collection_model_flow_info_t *obj_flow_info, ogs_list_t* p_flow_descriptions)
{
    if (obj_flow_info == NULL) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    const auto &value_from = p_flow_descriptions;
    typedef typename FlowInfo::FlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_flow_descriptions);
    if (!obj->setFlowDescriptions(std::move(value))) return NULL;
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_add_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info, char* p_flow_descriptions)
{
    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    typedef typename FlowInfo::FlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_flow_descriptions;

    ValueType value(value_from);

    obj->addFlowDescriptions(value);
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_remove_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info, const char* p_flow_descriptions)
{
    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    typedef typename FlowInfo::FlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_flow_descriptions;
    ValueType value(value_from);
    obj->removeFlowDescriptions(value);
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_clear_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info)
{   
    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    obj->clearFlowDescriptions();
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_flow_info_get_tos_tc(const data_collection_model_flow_info_t *obj_flow_info)
{
    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    typedef typename FlowInfo::TosTCType ResultFromType;
    const ResultFromType result_from = obj->getTosTC();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc(data_collection_model_flow_info_t *obj_flow_info, const char* p_tos_tc)
{
    if (obj_flow_info == NULL) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    const auto &value_from = p_tos_tc;
    typedef typename FlowInfo::TosTCType ValueType;

    ValueType value(value_from);
    if (!obj->setTosTC(value)) return NULL;
    return obj_flow_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc_move(data_collection_model_flow_info_t *obj_flow_info, char* p_tos_tc)
{
    if (obj_flow_info == NULL) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    const auto &value_from = p_tos_tc;
    typedef typename FlowInfo::TosTCType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTosTC(std::move(value))) return NULL;
    return obj_flow_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_flow_info_make_lnode(data_collection_model_flow_info_t *p_flow_info)
{
    return data_collection_lnode_create(p_flow_info, reinterpret_cast<void(*)(void*)>(data_collection_model_flow_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_flow_info_refcount(data_collection_model_flow_info_t *obj_flow_info)
{
    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

