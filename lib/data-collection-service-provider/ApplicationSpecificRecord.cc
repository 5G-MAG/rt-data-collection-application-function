/**********************************************************************************************************************************
 * ApplicationSpecificRecord - C interface to the ApplicationSpecificRecord object
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

/*#include "ApplicationSpecificRecord.h" already included by data-collection-sp/data-collection.h */
#include "ApplicationSpecificRecord-internal.h"
#include "openapi/model/ApplicationSpecificRecord.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_create(



)
{
    return reinterpret_cast<data_collection_model_application_specific_record_t*>(new std::shared_ptr<ApplicationSpecificRecord>(new ApplicationSpecificRecord(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_create_copy(const data_collection_model_application_specific_record_t *other)
{
    return reinterpret_cast<data_collection_model_application_specific_record_t*>(new std::shared_ptr<ApplicationSpecificRecord >(new ApplicationSpecificRecord(**reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_create_move(data_collection_model_application_specific_record_t *other)
{
    return reinterpret_cast<data_collection_model_application_specific_record_t*>(new std::shared_ptr<ApplicationSpecificRecord >(std::move(*reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_copy(data_collection_model_application_specific_record_t *application_specific_record, const data_collection_model_application_specific_record_t *other)
{
    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(application_specific_record);
    *obj = **reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(other);
    return application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_move(data_collection_model_application_specific_record_t *application_specific_record, data_collection_model_application_specific_record_t *other)
{
    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(application_specific_record);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(other));
    return application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_application_specific_record_free(data_collection_model_application_specific_record_t *application_specific_record)
{
    delete reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(application_specific_record);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_application_specific_record_toJSON(const data_collection_model_application_specific_record_t *application_specific_record, bool as_request)
{
    const std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(application_specific_record);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_application_specific_record_t*>(new std::shared_ptr<ApplicationSpecificRecord >(new ApplicationSpecificRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_application_specific_record_is_equal_to(const data_collection_model_application_specific_record_t *first, const data_collection_model_application_specific_record_t *second)
{
    const std::shared_ptr<ApplicationSpecificRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(first);
    const std::shared_ptr<ApplicationSpecificRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_application_specific_record_get_timestamp(const data_collection_model_application_specific_record_t *obj_application_specific_record)
{
    const std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    typedef typename ApplicationSpecificRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_timestamp(data_collection_model_application_specific_record_t *obj_application_specific_record, const char* p_timestamp)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_timestamp;
    typedef typename ApplicationSpecificRecord::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_timestamp_move(data_collection_model_application_specific_record_t *obj_application_specific_record, char* p_timestamp)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_timestamp;
    typedef typename ApplicationSpecificRecord::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_application_specific_record_get_context_ids(const data_collection_model_application_specific_record_t *obj_application_specific_record)
{
    const std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    typedef typename ApplicationSpecificRecord::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_context_ids(data_collection_model_application_specific_record_t *obj_application_specific_record, const ogs_list_t* p_context_ids)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_context_ids;
    typedef typename ApplicationSpecificRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_context_ids_move(data_collection_model_application_specific_record_t *obj_application_specific_record, ogs_list_t* p_context_ids)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_context_ids;
    typedef typename ApplicationSpecificRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_add_context_ids(data_collection_model_application_specific_record_t *obj_application_specific_record, char* p_context_ids)
{
    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    typedef typename ApplicationSpecificRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_remove_context_ids(data_collection_model_application_specific_record_t *obj_application_specific_record, const char* p_context_ids)
{
    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    typedef typename ApplicationSpecificRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_clear_context_ids(data_collection_model_application_specific_record_t *obj_application_specific_record)
{   
    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    obj->clearContextIds();
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_application_specific_record_get_record_type(const data_collection_model_application_specific_record_t *obj_application_specific_record)
{
    const std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    typedef typename ApplicationSpecificRecord::RecordTypeType ResultFromType;
    const ResultFromType result_from = obj->getRecordType();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_type(data_collection_model_application_specific_record_t *obj_application_specific_record, const char* p_record_type)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_record_type;
    typedef typename ApplicationSpecificRecord::RecordTypeType ValueType;

    ValueType value(value_from);
    if (!obj->setRecordType(value)) return NULL;
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_type_move(data_collection_model_application_specific_record_t *obj_application_specific_record, char* p_record_type)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_record_type;
    typedef typename ApplicationSpecificRecord::RecordTypeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRecordType(std::move(value))) return NULL;
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_any_type_t* data_collection_model_application_specific_record_get_record_container(const data_collection_model_application_specific_record_t *obj_application_specific_record)
{
    const std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    typedef typename ApplicationSpecificRecord::RecordContainerType ResultFromType;
    const ResultFromType result_from = obj->getRecordContainer();
    const data_collection_model_any_type_t *result = reinterpret_cast<const data_collection_model_any_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_container(data_collection_model_application_specific_record_t *obj_application_specific_record, const data_collection_model_any_type_t* p_record_container)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_record_container;
    typedef typename ApplicationSpecificRecord::RecordContainerType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRecordContainer(value)) return NULL;
    return obj_application_specific_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_container_move(data_collection_model_application_specific_record_t *obj_application_specific_record, data_collection_model_any_type_t* p_record_container)
{
    if (obj_application_specific_record == NULL) return NULL;

    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    const auto &value_from = p_record_container;
    typedef typename ApplicationSpecificRecord::RecordContainerType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRecordContainer(std::move(value))) return NULL;
    return obj_application_specific_record;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_application_specific_record_make_lnode(data_collection_model_application_specific_record_t *p_application_specific_record)
{
    return data_collection_lnode_create(p_application_specific_record, reinterpret_cast<void(*)(void*)>(data_collection_model_application_specific_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_application_specific_record_refcount(data_collection_model_application_specific_record_t *obj_application_specific_record)
{
    std::shared_ptr<ApplicationSpecificRecord > &obj = *reinterpret_cast<std::shared_ptr<ApplicationSpecificRecord >*>(obj_application_specific_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

