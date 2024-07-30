/**********************************************************************************************************************************
 * ExceptionInfo - C interface to the ExceptionInfo object
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

/*#include "ExceptionInfo.h" already included by data-collection-sp/data-collection.h */
#include "ExceptionInfo-internal.h"
#include "openapi/model/ExceptionInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_create(


)
{
    return reinterpret_cast<data_collection_model_exception_info_t*>(new std::shared_ptr<ExceptionInfo>(new ExceptionInfo(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_create_copy(const data_collection_model_exception_info_t *other)
{
    return reinterpret_cast<data_collection_model_exception_info_t*>(new std::shared_ptr<ExceptionInfo >(new ExceptionInfo(**reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_create_move(data_collection_model_exception_info_t *other)
{
    return reinterpret_cast<data_collection_model_exception_info_t*>(new std::shared_ptr<ExceptionInfo >(std::move(*reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_copy(data_collection_model_exception_info_t *exception_info, const data_collection_model_exception_info_t *other)
{
    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(exception_info);
    *obj = **reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(other);
    return exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_move(data_collection_model_exception_info_t *exception_info, data_collection_model_exception_info_t *other)
{
    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(exception_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(other));
    return exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_exception_info_free(data_collection_model_exception_info_t *exception_info)
{
    delete reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(exception_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_exception_info_toJSON(const data_collection_model_exception_info_t *exception_info, bool as_request)
{
    const std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(exception_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_exception_info_t*>(new std::shared_ptr<ExceptionInfo >(new ExceptionInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_exception_info_is_equal_to(const data_collection_model_exception_info_t *first, const data_collection_model_exception_info_t *second)
{
    const std::shared_ptr<ExceptionInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(first);
    const std::shared_ptr<ExceptionInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_flow_info_t* data_collection_model_exception_info_get_ip_traffic_filter(const data_collection_model_exception_info_t *obj_exception_info)
{
    const std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    typedef typename ExceptionInfo::IpTrafficFilterType ResultFromType;
    const ResultFromType result_from = obj->getIpTrafficFilter();
    const data_collection_model_flow_info_t *result = reinterpret_cast<const data_collection_model_flow_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_set_ip_traffic_filter(data_collection_model_exception_info_t *obj_exception_info, const data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (obj_exception_info == NULL) return NULL;

    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    const auto &value_from = p_ip_traffic_filter;
    typedef typename ExceptionInfo::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIpTrafficFilter(value)) return NULL;
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_set_ip_traffic_filter_move(data_collection_model_exception_info_t *obj_exception_info, data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (obj_exception_info == NULL) return NULL;

    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    const auto &value_from = p_ip_traffic_filter;
    typedef typename ExceptionInfo::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIpTrafficFilter(std::move(value))) return NULL;
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_eth_flow_description_t* data_collection_model_exception_info_get_eth_traffic_filter(const data_collection_model_exception_info_t *obj_exception_info)
{
    const std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    typedef typename ExceptionInfo::EthTrafficFilterType ResultFromType;
    const ResultFromType result_from = obj->getEthTrafficFilter();
    const data_collection_model_eth_flow_description_t *result = reinterpret_cast<const data_collection_model_eth_flow_description_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_set_eth_traffic_filter(data_collection_model_exception_info_t *obj_exception_info, const data_collection_model_eth_flow_description_t* p_eth_traffic_filter)
{
    if (obj_exception_info == NULL) return NULL;

    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    const auto &value_from = p_eth_traffic_filter;
    typedef typename ExceptionInfo::EthTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEthTrafficFilter(value)) return NULL;
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_set_eth_traffic_filter_move(data_collection_model_exception_info_t *obj_exception_info, data_collection_model_eth_flow_description_t* p_eth_traffic_filter)
{
    if (obj_exception_info == NULL) return NULL;

    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    const auto &value_from = p_eth_traffic_filter;
    typedef typename ExceptionInfo::EthTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEthTrafficFilter(std::move(value))) return NULL;
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_exception_info_get_exceps(const data_collection_model_exception_info_t *obj_exception_info)
{
    const std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    typedef typename ExceptionInfo::ExcepsType ResultFromType;
    const ResultFromType result_from = obj->getExceps();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_exception_t *item_obj = reinterpret_cast<data_collection_model_exception_t*>(new std::shared_ptr<Exception >(item));
        node = data_collection_model_exception_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_set_exceps(data_collection_model_exception_info_t *obj_exception_info, const ogs_list_t* p_exceps)
{
    if (obj_exception_info == NULL) return NULL;

    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    const auto &value_from = p_exceps;
    typedef typename ExceptionInfo::ExcepsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setExceps(value)) return NULL;
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_set_exceps_move(data_collection_model_exception_info_t *obj_exception_info, ogs_list_t* p_exceps)
{
    if (obj_exception_info == NULL) return NULL;

    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    const auto &value_from = p_exceps;
    typedef typename ExceptionInfo::ExcepsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_exceps);
    if (!obj->setExceps(std::move(value))) return NULL;
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_add_exceps(data_collection_model_exception_info_t *obj_exception_info, data_collection_model_exception_t* p_exceps)
{
    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    typedef typename ExceptionInfo::ExcepsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_exceps;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addExceps(value);
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_remove_exceps(data_collection_model_exception_info_t *obj_exception_info, const data_collection_model_exception_t* p_exceps)
{
    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    typedef typename ExceptionInfo::ExcepsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_exceps;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeExceps(value);
    return obj_exception_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_info_t *data_collection_model_exception_info_clear_exceps(data_collection_model_exception_info_t *obj_exception_info)
{   
    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    obj->clearExceps();
    return obj_exception_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_exception_info_make_lnode(data_collection_model_exception_info_t *p_exception_info)
{
    return data_collection_lnode_create(p_exception_info, reinterpret_cast<void(*)(void*)>(data_collection_model_exception_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_exception_info_refcount(data_collection_model_exception_info_t *obj_exception_info)
{
    std::shared_ptr<ExceptionInfo > &obj = *reinterpret_cast<std::shared_ptr<ExceptionInfo >*>(obj_exception_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

