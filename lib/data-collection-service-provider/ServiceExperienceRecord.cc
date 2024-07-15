/**********************************************************************************************************************************
 * ServiceExperienceRecord - C interface to the ServiceExperienceRecord object
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

/*#include "ServiceExperienceRecord.h" already included by data-collection-sp/data-collection.h */
#include "ServiceExperienceRecord-internal.h"
#include "openapi/model/ServiceExperienceRecord.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_create(

)
{
    return reinterpret_cast<data_collection_model_service_experience_record_t*>(new std::shared_ptr<ServiceExperienceRecord>(new ServiceExperienceRecord(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_create_copy(const data_collection_model_service_experience_record_t *other)
{
    return reinterpret_cast<data_collection_model_service_experience_record_t*>(new std::shared_ptr<ServiceExperienceRecord >(new ServiceExperienceRecord(**reinterpret_cast<const std::shared_ptr<ServiceExperienceRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_create_move(data_collection_model_service_experience_record_t *other)
{
    return reinterpret_cast<data_collection_model_service_experience_record_t*>(new std::shared_ptr<ServiceExperienceRecord >(std::move(*reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_copy(data_collection_model_service_experience_record_t *service_experience_record, const data_collection_model_service_experience_record_t *other)
{
    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(service_experience_record);
    *obj = **reinterpret_cast<const std::shared_ptr<ServiceExperienceRecord >*>(other);
    return service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_move(data_collection_model_service_experience_record_t *service_experience_record, data_collection_model_service_experience_record_t *other)
{
    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(service_experience_record);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(other));
    return service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_service_experience_record_free(data_collection_model_service_experience_record_t *service_experience_record)
{
    delete reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(service_experience_record);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_service_experience_record_toJSON(const data_collection_model_service_experience_record_t *service_experience_record, bool as_request)
{
    const std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceRecord >*>(service_experience_record);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_service_experience_record_t*>(new std::shared_ptr<ServiceExperienceRecord >(new ServiceExperienceRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_service_experience_record_get_timestamp(const data_collection_model_service_experience_record_t *obj_service_experience_record)
{
    const std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    typedef typename ServiceExperienceRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_timestamp(data_collection_model_service_experience_record_t *obj_service_experience_record, const char* p_timestamp)
{
    if (obj_service_experience_record == NULL) return NULL;

    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    const auto &value_from = p_timestamp;
    typedef typename ServiceExperienceRecord::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_timestamp_move(data_collection_model_service_experience_record_t *obj_service_experience_record, char* p_timestamp)
{
    if (obj_service_experience_record == NULL) return NULL;

    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    const auto &value_from = p_timestamp;
    typedef typename ServiceExperienceRecord::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_service_experience_record_get_service_experience_infos(const data_collection_model_service_experience_record_t *obj_service_experience_record)
{
    const std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    typedef typename ServiceExperienceRecord::ServiceExperienceInfosType ResultFromType;
    const ResultFromType result_from = obj->getServiceExperienceInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_per_flow_service_experience_info_t *item_obj = reinterpret_cast<data_collection_model_per_flow_service_experience_info_t*>(new std::shared_ptr<PerFlowServiceExperienceInfo >(item));
        node = data_collection_model_per_flow_service_experience_info_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_service_experience_infos(data_collection_model_service_experience_record_t *obj_service_experience_record, const ogs_list_t* p_service_experience_infos)
{
    if (obj_service_experience_record == NULL) return NULL;

    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    const auto &value_from = p_service_experience_infos;
    typedef typename ServiceExperienceRecord::ServiceExperienceInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setServiceExperienceInfos(value)) return NULL;
    return obj_service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_service_experience_infos_move(data_collection_model_service_experience_record_t *obj_service_experience_record, ogs_list_t* p_service_experience_infos)
{
    if (obj_service_experience_record == NULL) return NULL;

    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    const auto &value_from = p_service_experience_infos;
    typedef typename ServiceExperienceRecord::ServiceExperienceInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_service_experience_infos);
    if (!obj->setServiceExperienceInfos(std::move(value))) return NULL;
    return obj_service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_add_service_experience_infos(data_collection_model_service_experience_record_t *obj_service_experience_record, data_collection_model_per_flow_service_experience_info_t* p_service_experience_infos)
{
    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    typedef typename ServiceExperienceRecord::ServiceExperienceInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_service_experience_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addServiceExperienceInfos(value);
    return obj_service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_remove_service_experience_infos(data_collection_model_service_experience_record_t *obj_service_experience_record, const data_collection_model_per_flow_service_experience_info_t* p_service_experience_infos)
{
    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    typedef typename ServiceExperienceRecord::ServiceExperienceInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_service_experience_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeServiceExperienceInfos(value);
    return obj_service_experience_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_clear_service_experience_infos(data_collection_model_service_experience_record_t *obj_service_experience_record)
{   
    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    obj->clearServiceExperienceInfos();
    return obj_service_experience_record;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_service_experience_record_make_lnode(data_collection_model_service_experience_record_t *p_service_experience_record)
{
    return data_collection_lnode_create(p_service_experience_record, reinterpret_cast<void(*)(void*)>(data_collection_model_service_experience_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_service_experience_record_refcount(data_collection_model_service_experience_record_t *obj_service_experience_record)
{
    std::shared_ptr<ServiceExperienceRecord > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceRecord >*>(obj_service_experience_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

