/**********************************************************************************************************************************
 * DispersionCollection - C interface to the DispersionCollection object
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

/*#include "DispersionCollection.h" already included by data-collection-sp/data-collection.h */
#include "DispersionCollection-internal.h"
#include "openapi/model/DispersionCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create(








)
{
    return reinterpret_cast<data_collection_model_dispersion_collection_t*>(new std::shared_ptr<DispersionCollection>(new DispersionCollection(








)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create_copy(const data_collection_model_dispersion_collection_t *other)
{
    return reinterpret_cast<data_collection_model_dispersion_collection_t*>(new std::shared_ptr<DispersionCollection >(new DispersionCollection(**reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create_move(data_collection_model_dispersion_collection_t *other)
{
    return reinterpret_cast<data_collection_model_dispersion_collection_t*>(new std::shared_ptr<DispersionCollection >(std::move(*reinterpret_cast<std::shared_ptr<DispersionCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_copy(data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_dispersion_collection_t *other)
{
    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(dispersion_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(other);
    return dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_move(data_collection_model_dispersion_collection_t *dispersion_collection, data_collection_model_dispersion_collection_t *other)
{
    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(dispersion_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DispersionCollection >*>(other));
    return dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_dispersion_collection_free(data_collection_model_dispersion_collection_t *dispersion_collection)
{
    delete reinterpret_cast<std::shared_ptr<DispersionCollection >*>(dispersion_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_dispersion_collection_toJSON(const data_collection_model_dispersion_collection_t *dispersion_collection, bool as_request)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(dispersion_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_dispersion_collection_t*>(new std::shared_ptr<DispersionCollection >(new DispersionCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_dispersion_collection_is_equal_to(const data_collection_model_dispersion_collection_t *first, const data_collection_model_dispersion_collection_t *second)
{
    const std::shared_ptr<DispersionCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(first);
    const std::shared_ptr<DispersionCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dispersion_collection_get_gpsi(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::GpsiType ResultFromType;
    const ResultFromType result_from = obj->getGpsi();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_gpsi(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const char* p_gpsi)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_gpsi;
    typedef typename DispersionCollection::GpsiType ValueType;

    ValueType value(value_from);
    if (!obj->setGpsi(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_gpsi_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, char* p_gpsi)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_gpsi;
    typedef typename DispersionCollection::GpsiType ValueType;

    ValueType value(value_from);
    
    if (!obj->setGpsi(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dispersion_collection_get_supi(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::SupiType ResultFromType;
    const ResultFromType result_from = obj->getSupi();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_supi(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const char* p_supi)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_supi;
    typedef typename DispersionCollection::SupiType ValueType;

    ValueType value(value_from);
    if (!obj->setSupi(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_supi_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, char* p_supi)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_supi;
    typedef typename DispersionCollection::SupiType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSupi(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ip_addr_t* data_collection_model_dispersion_collection_get_ue_addr(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::UeAddrType ResultFromType;
    const ResultFromType result_from = obj->getUeAddr();
    const data_collection_model_ip_addr_t *result = reinterpret_cast<const data_collection_model_ip_addr_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_ue_addr(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const data_collection_model_ip_addr_t* p_ue_addr)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_ue_addr;
    typedef typename DispersionCollection::UeAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUeAddr(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_ue_addr_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, data_collection_model_ip_addr_t* p_ue_addr)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_ue_addr;
    typedef typename DispersionCollection::UeAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUeAddr(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dispersion_collection_get_time_stamp(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::TimeStampType ResultFromType;
    const ResultFromType result_from = obj->getTimeStamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_time_stamp(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const char* p_time_stamp)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_time_stamp;
    typedef typename DispersionCollection::TimeStampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimeStamp(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_time_stamp_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, char* p_time_stamp)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_time_stamp;
    typedef typename DispersionCollection::TimeStampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimeStamp(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_usage_threshold_t* data_collection_model_dispersion_collection_get_data_usage(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::DataUsageType ResultFromType;
    const ResultFromType result_from = obj->getDataUsage();
    const data_collection_model_usage_threshold_t *result = reinterpret_cast<const data_collection_model_usage_threshold_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_data_usage(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const data_collection_model_usage_threshold_t* p_data_usage)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_data_usage;
    typedef typename DispersionCollection::DataUsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDataUsage(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_data_usage_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, data_collection_model_usage_threshold_t* p_data_usage)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_data_usage;
    typedef typename DispersionCollection::DataUsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDataUsage(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dispersion_collection_get_flow_desp(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::FlowDespType ResultFromType;
    const ResultFromType result_from = obj->getFlowDesp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_flow_desp(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const char* p_flow_desp)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_flow_desp;
    typedef typename DispersionCollection::FlowDespType ValueType;

    ValueType value(value_from);
    if (!obj->setFlowDesp(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_flow_desp_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, char* p_flow_desp)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_flow_desp;
    typedef typename DispersionCollection::FlowDespType ValueType;

    ValueType value(value_from);
    
    if (!obj->setFlowDesp(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dispersion_collection_get_app_id(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_id(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const char* p_app_id)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_app_id;
    typedef typename DispersionCollection::AppIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAppId(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_id_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, char* p_app_id)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_app_id;
    typedef typename DispersionCollection::AppIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAppId(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_dispersion_collection_get_dnais(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::DnaisType ResultFromType;
    const ResultFromType result_from = obj->getDnais();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_dnais(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const ogs_list_t* p_dnais)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_dnais;
    typedef typename DispersionCollection::DnaisType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setDnais(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_dnais_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, ogs_list_t* p_dnais)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_dnais;
    typedef typename DispersionCollection::DnaisType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_dnais);
    if (!obj->setDnais(std::move(value))) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_add_dnais(data_collection_model_dispersion_collection_t *obj_dispersion_collection, char* p_dnais)
{
    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::DnaisType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_dnais;

    ValueType value(value_from);

    obj->addDnais(value);
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_remove_dnais(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const char* p_dnais)
{
    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::DnaisType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_dnais;
    ValueType value(value_from);
    obj->removeDnais(value);
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_clear_dnais(data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{   
    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    obj->clearDnais();
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_dispersion_collection_get_app_dur(const data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    const std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<const std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    typedef typename DispersionCollection::AppDurType ResultFromType;
    const ResultFromType result_from = obj->getAppDur();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_dur(data_collection_model_dispersion_collection_t *obj_dispersion_collection, const int32_t p_app_dur)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_app_dur;
    typedef typename DispersionCollection::AppDurType ValueType;

    ValueType value = value_from;
    if (!obj->setAppDur(value)) return NULL;
    return obj_dispersion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_dur_move(data_collection_model_dispersion_collection_t *obj_dispersion_collection, int32_t p_app_dur)
{
    if (obj_dispersion_collection == NULL) return NULL;

    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    const auto &value_from = p_app_dur;
    typedef typename DispersionCollection::AppDurType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAppDur(std::move(value))) return NULL;
    return obj_dispersion_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_dispersion_collection_make_lnode(data_collection_model_dispersion_collection_t *p_dispersion_collection)
{
    return data_collection_lnode_create(p_dispersion_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_dispersion_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_dispersion_collection_refcount(data_collection_model_dispersion_collection_t *obj_dispersion_collection)
{
    std::shared_ptr<DispersionCollection > &obj = *reinterpret_cast<std::shared_ptr<DispersionCollection >*>(obj_dispersion_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

