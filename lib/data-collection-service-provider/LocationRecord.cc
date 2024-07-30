/**********************************************************************************************************************************
 * LocationRecord - C interface to the LocationRecord object
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

/*#include "LocationRecord.h" already included by data-collection-sp/data-collection.h */
#include "LocationRecord-internal.h"
#include "openapi/model/LocationRecord.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_create(


)
{
    return reinterpret_cast<data_collection_model_location_record_t*>(new std::shared_ptr<LocationRecord>(new LocationRecord(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_create_copy(const data_collection_model_location_record_t *other)
{
    return reinterpret_cast<data_collection_model_location_record_t*>(new std::shared_ptr<LocationRecord >(new LocationRecord(**reinterpret_cast<const std::shared_ptr<LocationRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_create_move(data_collection_model_location_record_t *other)
{
    return reinterpret_cast<data_collection_model_location_record_t*>(new std::shared_ptr<LocationRecord >(std::move(*reinterpret_cast<std::shared_ptr<LocationRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_copy(data_collection_model_location_record_t *location_record, const data_collection_model_location_record_t *other)
{
    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(location_record);
    *obj = **reinterpret_cast<const std::shared_ptr<LocationRecord >*>(other);
    return location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_move(data_collection_model_location_record_t *location_record, data_collection_model_location_record_t *other)
{
    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(location_record);
    obj = std::move(*reinterpret_cast<std::shared_ptr<LocationRecord >*>(other));
    return location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_location_record_free(data_collection_model_location_record_t *location_record)
{
    delete reinterpret_cast<std::shared_ptr<LocationRecord >*>(location_record);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_location_record_toJSON(const data_collection_model_location_record_t *location_record, bool as_request)
{
    const std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<LocationRecord >*>(location_record);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_location_record_t*>(new std::shared_ptr<LocationRecord >(new LocationRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_location_record_is_equal_to(const data_collection_model_location_record_t *first, const data_collection_model_location_record_t *second)
{
    const std::shared_ptr<LocationRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<LocationRecord >*>(first);
    const std::shared_ptr<LocationRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<LocationRecord >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_location_record_get_timestamp(const data_collection_model_location_record_t *obj_location_record)
{
    const std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<LocationRecord >*>(obj_location_record);
    typedef typename LocationRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_set_timestamp(data_collection_model_location_record_t *obj_location_record, const char* p_timestamp)
{
    if (obj_location_record == NULL) return NULL;

    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    const auto &value_from = p_timestamp;
    typedef typename LocationRecord::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_set_timestamp_move(data_collection_model_location_record_t *obj_location_record, char* p_timestamp)
{
    if (obj_location_record == NULL) return NULL;

    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    const auto &value_from = p_timestamp;
    typedef typename LocationRecord::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_location_record_get_context_ids(const data_collection_model_location_record_t *obj_location_record)
{
    const std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<LocationRecord >*>(obj_location_record);
    typedef typename LocationRecord::ContextIdsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_set_context_ids(data_collection_model_location_record_t *obj_location_record, const ogs_list_t* p_context_ids)
{
    if (obj_location_record == NULL) return NULL;

    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    const auto &value_from = p_context_ids;
    typedef typename LocationRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_set_context_ids_move(data_collection_model_location_record_t *obj_location_record, ogs_list_t* p_context_ids)
{
    if (obj_location_record == NULL) return NULL;

    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    const auto &value_from = p_context_ids;
    typedef typename LocationRecord::ContextIdsType ValueType;

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
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_add_context_ids(data_collection_model_location_record_t *obj_location_record, char* p_context_ids)
{
    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    typedef typename LocationRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_remove_context_ids(data_collection_model_location_record_t *obj_location_record, const char* p_context_ids)
{
    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    typedef typename LocationRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_clear_context_ids(data_collection_model_location_record_t *obj_location_record)
{   
    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    obj->clearContextIds();
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_data_t* data_collection_model_location_record_get_location(const data_collection_model_location_record_t *obj_location_record)
{
    const std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<LocationRecord >*>(obj_location_record);
    typedef typename LocationRecord::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_set_location(data_collection_model_location_record_t *obj_location_record, const data_collection_model_location_data_t* p_location)
{
    if (obj_location_record == NULL) return NULL;

    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    const auto &value_from = p_location;
    typedef typename LocationRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocation(value)) return NULL;
    return obj_location_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_t *data_collection_model_location_record_set_location_move(data_collection_model_location_record_t *obj_location_record, data_collection_model_location_data_t* p_location)
{
    if (obj_location_record == NULL) return NULL;

    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    const auto &value_from = p_location;
    typedef typename LocationRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocation(std::move(value))) return NULL;
    return obj_location_record;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_location_record_make_lnode(data_collection_model_location_record_t *p_location_record)
{
    return data_collection_lnode_create(p_location_record, reinterpret_cast<void(*)(void*)>(data_collection_model_location_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_location_record_refcount(data_collection_model_location_record_t *obj_location_record)
{
    std::shared_ptr<LocationRecord > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord >*>(obj_location_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

