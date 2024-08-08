/**********************************************************************************************************************************
 * BaseEventCollection - C interface to the BaseEventCollection object
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

/*#include "BaseEventCollection.h" already included by data-collection-sp/data-collection.h */
#include "BaseEventCollection-internal.h"
#include "openapi/model/BaseEventCollection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_create(






)
{
    return reinterpret_cast<data_collection_model_base_event_collection_t*>(new std::shared_ptr<BaseEventCollection>(new BaseEventCollection(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_create_copy(const data_collection_model_base_event_collection_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_base_event_collection_t*>(new std::shared_ptr<BaseEventCollection >(new BaseEventCollection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_create_move(data_collection_model_base_event_collection_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<BaseEventCollection > *obj = reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_copy(data_collection_model_base_event_collection_t *base_event_collection, const data_collection_model_base_event_collection_t *other)
{
    if (base_event_collection) {
        std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(base_event_collection);
        if (obj) {
            if (other) {
                const std::shared_ptr<BaseEventCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(other);
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
                const std::shared_ptr<BaseEventCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(other);
                if (other_obj) {
                    obj.reset(new BaseEventCollection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        base_event_collection = data_collection_model_base_event_collection_create_copy(other);
    }
    return base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_move(data_collection_model_base_event_collection_t *base_event_collection, data_collection_model_base_event_collection_t *other)
{
    std::shared_ptr<BaseEventCollection > *other_ptr = reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(other);

    if (base_event_collection) {
        std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(base_event_collection);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                base_event_collection = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_event_collection_free(data_collection_model_base_event_collection_t *base_event_collection)
{
    if (!base_event_collection) return;
    delete reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(base_event_collection);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_event_collection_toJSON(const data_collection_model_base_event_collection_t *base_event_collection, bool as_request)
{
    if (!base_event_collection) return NULL;
    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(base_event_collection);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_base_event_collection_t*>(new std::shared_ptr<BaseEventCollection >(new BaseEventCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_collection_is_equal_to(const data_collection_model_base_event_collection_t *first, const data_collection_model_base_event_collection_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<BaseEventCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<BaseEventCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_collection_get_collection_timestamp(const data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventCollection::CollectionTimestampType ResultFromType;
    const ResultFromType result_from = obj->getCollectionTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_collection_timestamp(data_collection_model_base_event_collection_t *obj_base_event_collection, const char* p_collection_timestamp)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_collection_timestamp;
    typedef typename BaseEventCollection::CollectionTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setCollectionTimestamp(value)) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_collection_timestamp_move(data_collection_model_base_event_collection_t *obj_base_event_collection, char* p_collection_timestamp)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_collection_timestamp;
    typedef typename BaseEventCollection::CollectionTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setCollectionTimestamp(std::move(value))) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_collection_get_start_timestamp(const data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventCollection::StartTimestampType ResultFromType;
    const ResultFromType result_from = obj->getStartTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_start_timestamp(data_collection_model_base_event_collection_t *obj_base_event_collection, const char* p_start_timestamp)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_start_timestamp;
    typedef typename BaseEventCollection::StartTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setStartTimestamp(value)) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_start_timestamp_move(data_collection_model_base_event_collection_t *obj_base_event_collection, char* p_start_timestamp)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_start_timestamp;
    typedef typename BaseEventCollection::StartTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setStartTimestamp(std::move(value))) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_collection_get_end_timestamp(const data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseEventCollection::EndTimestampType ResultFromType;
    const ResultFromType result_from = obj->getEndTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_end_timestamp(data_collection_model_base_event_collection_t *obj_base_event_collection, const char* p_end_timestamp)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_end_timestamp;
    typedef typename BaseEventCollection::EndTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setEndTimestamp(value)) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_end_timestamp_move(data_collection_model_base_event_collection_t *obj_base_event_collection, char* p_end_timestamp)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_end_timestamp;
    typedef typename BaseEventCollection::EndTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setEndTimestamp(std::move(value))) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_base_event_collection_get_sample_count(const data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename BaseEventCollection::SampleCountType ResultFromType;
    const ResultFromType result_from = obj->getSampleCount();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_sample_count(data_collection_model_base_event_collection_t *obj_base_event_collection, const int32_t p_sample_count)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_sample_count;
    typedef typename BaseEventCollection::SampleCountType ValueType;

    ValueType value = value_from;
    if (!obj->setSampleCount(value)) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_sample_count_move(data_collection_model_base_event_collection_t *obj_base_event_collection, int32_t p_sample_count)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_sample_count;
    typedef typename BaseEventCollection::SampleCountType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSampleCount(std::move(value))) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_provisioning_session_type_t* data_collection_model_base_event_collection_get_streaming_direction(const data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) {
        const data_collection_model_provisioning_session_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) {
        const data_collection_model_provisioning_session_type_t *result = NULL;
        return result;
    }

    typedef typename BaseEventCollection::StreamingDirectionType ResultFromType;
    const ResultFromType result_from = obj->getStreamingDirection();
    const data_collection_model_provisioning_session_type_t *result = reinterpret_cast<const data_collection_model_provisioning_session_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_streaming_direction(data_collection_model_base_event_collection_t *obj_base_event_collection, const data_collection_model_provisioning_session_type_t* p_streaming_direction)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_streaming_direction;
    typedef typename BaseEventCollection::StreamingDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setStreamingDirection(value)) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_streaming_direction_move(data_collection_model_base_event_collection_t *obj_base_event_collection, data_collection_model_provisioning_session_type_t* p_streaming_direction)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_streaming_direction;
    typedef typename BaseEventCollection::StreamingDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setStreamingDirection(std::move(value))) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_event_collection_get_summarisations(const data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename BaseEventCollection::SummarisationsType ResultFromType;
    const ResultFromType result_from = obj->getSummarisations();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_aggregation_function_type_t *item_obj = reinterpret_cast<data_collection_model_data_aggregation_function_type_t*>(new std::shared_ptr<DataAggregationFunctionType >(item));
        node = data_collection_model_data_aggregation_function_type_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_summarisations(data_collection_model_base_event_collection_t *obj_base_event_collection, const ogs_list_t* p_summarisations)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_summarisations;
    typedef typename BaseEventCollection::SummarisationsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setSummarisations(value)) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_summarisations_move(data_collection_model_base_event_collection_t *obj_base_event_collection, ogs_list_t* p_summarisations)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_summarisations;
    typedef typename BaseEventCollection::SummarisationsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_summarisations);
    if (!obj->setSummarisations(std::move(value))) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_add_summarisations(data_collection_model_base_event_collection_t *obj_base_event_collection, data_collection_model_data_aggregation_function_type_t* p_summarisations)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    typedef typename BaseEventCollection::SummarisationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_summarisations;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addSummarisations(value);
    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_remove_summarisations(data_collection_model_base_event_collection_t *obj_base_event_collection, const data_collection_model_data_aggregation_function_type_t* p_summarisations)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    typedef typename BaseEventCollection::SummarisationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_summarisations;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeSummarisations(value);
    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_clear_summarisations(data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    obj->clearSummarisations();
    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_event_collection_get_records(const data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<const std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename BaseEventCollection::RecordsType ResultFromType;
    const ResultFromType result_from = obj->getRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        void *item_obj = reinterpret_cast<void*>(new std::shared_ptr<AnyType>(item));
        node = data_collection_lnode_create(item_obj, reinterpret_cast<void(*)(void*)>(data_collection_model_any_type_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_records(data_collection_model_base_event_collection_t *obj_base_event_collection, const ogs_list_t* p_records)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_records;
    typedef typename BaseEventCollection::RecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRecords(value)) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_set_records_move(data_collection_model_base_event_collection_t *obj_base_event_collection, ogs_list_t* p_records)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    const auto &value_from = p_records;
    typedef typename BaseEventCollection::RecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_records);
    if (!obj->setRecords(std::move(value))) return NULL;

    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_add_records(data_collection_model_base_event_collection_t *obj_base_event_collection, data_collection_model_any_type_t* p_records)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    typedef typename BaseEventCollection::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRecords(value);
    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_remove_records(data_collection_model_base_event_collection_t *obj_base_event_collection, const data_collection_model_any_type_t* p_records)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    typedef typename BaseEventCollection::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRecords(value);
    return obj_base_event_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_collection_t *data_collection_model_base_event_collection_clear_records(data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) return NULL;

    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    if (!obj) return NULL;

    obj->clearRecords();
    return obj_base_event_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_event_collection_make_lnode(data_collection_model_base_event_collection_t *p_base_event_collection)
{
    return data_collection_lnode_create(p_base_event_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_base_event_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_base_event_collection_refcount(data_collection_model_base_event_collection_t *obj_base_event_collection)
{
    if (!obj_base_event_collection) return 0l;
    std::shared_ptr<BaseEventCollection > &obj = *reinterpret_cast<std::shared_ptr<BaseEventCollection >*>(obj_base_event_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
