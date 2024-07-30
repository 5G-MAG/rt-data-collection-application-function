/**********************************************************************************************************************************
 * BaseRecord_1 - C interface to the BaseRecord_1 object
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

/*#include "BaseRecord_1.h" already included by data-collection-sp/data-collection.h */
#include "BaseRecord_1-internal.h"
#include "openapi/model/BaseRecord_1.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_create(

)
{
    return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1>(new BaseRecord_1(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_create_copy(const data_collection_model_base_record_1_t *other)
{
    return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1 >(new BaseRecord_1(**reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_create_move(data_collection_model_base_record_1_t *other)
{
    return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1 >(std::move(*reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_copy(data_collection_model_base_record_1_t *base_record_1, const data_collection_model_base_record_1_t *other)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(base_record_1);
    *obj = **reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(other);
    return base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_move(data_collection_model_base_record_1_t *base_record_1, data_collection_model_base_record_1_t *other)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(base_record_1);
    obj = std::move(*reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(other));
    return base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_base_record_1_free(data_collection_model_base_record_1_t *base_record_1)
{
    delete reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(base_record_1);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_base_record_1_toJSON(const data_collection_model_base_record_1_t *base_record_1, bool as_request)
{
    const std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(base_record_1);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1 >(new BaseRecord_1(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_base_record_1_is_equal_to(const data_collection_model_base_record_1_t *first, const data_collection_model_base_record_1_t *second)
{
    const std::shared_ptr<BaseRecord_1 > &obj1 = *reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(first);
    const std::shared_ptr<BaseRecord_1 > &obj2 = *reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_base_record_1_get_timestamp(const data_collection_model_base_record_1_t *obj_base_record_1)
{
    const std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    typedef typename BaseRecord_1::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_timestamp(data_collection_model_base_record_1_t *obj_base_record_1, const char* p_timestamp)
{
    if (obj_base_record_1 == NULL) return NULL;

    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    const auto &value_from = p_timestamp;
    typedef typename BaseRecord_1::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_timestamp_move(data_collection_model_base_record_1_t *obj_base_record_1, char* p_timestamp)
{
    if (obj_base_record_1 == NULL) return NULL;

    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    const auto &value_from = p_timestamp;
    typedef typename BaseRecord_1::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_base_record_1_get_context_ids(const data_collection_model_base_record_1_t *obj_base_record_1)
{
    const std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    typedef typename BaseRecord_1::ContextIdsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_context_ids(data_collection_model_base_record_1_t *obj_base_record_1, const ogs_list_t* p_context_ids)
{
    if (obj_base_record_1 == NULL) return NULL;

    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    const auto &value_from = p_context_ids;
    typedef typename BaseRecord_1::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;
    return obj_base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_context_ids_move(data_collection_model_base_record_1_t *obj_base_record_1, ogs_list_t* p_context_ids)
{
    if (obj_base_record_1 == NULL) return NULL;

    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    const auto &value_from = p_context_ids;
    typedef typename BaseRecord_1::ContextIdsType ValueType;

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
    return obj_base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_add_context_ids(data_collection_model_base_record_1_t *obj_base_record_1, char* p_context_ids)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    typedef typename BaseRecord_1::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_remove_context_ids(data_collection_model_base_record_1_t *obj_base_record_1, const char* p_context_ids)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    typedef typename BaseRecord_1::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_clear_context_ids(data_collection_model_base_record_1_t *obj_base_record_1)
{   
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    obj->clearContextIds();
    return obj_base_record_1;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_base_record_1_make_lnode(data_collection_model_base_record_1_t *p_base_record_1)
{
    return data_collection_lnode_create(p_base_record_1, reinterpret_cast<void(*)(void*)>(data_collection_model_base_record_1_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_base_record_1_refcount(data_collection_model_base_record_1_t *obj_base_record_1)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

