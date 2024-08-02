/**********************************************************************************************************************************
 * MediaStreamingAccessesCollection - C interface to the MediaStreamingAccessesCollection object
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

/*#include "MediaStreamingAccessesCollection.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccessesCollection-internal.h"
#include "openapi/model/MediaStreamingAccessesCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_create(






)
{
    return reinterpret_cast<data_collection_model_media_streaming_accesses_collection_t*>(new std::shared_ptr<MediaStreamingAccessesCollection>(new MediaStreamingAccessesCollection(






)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_create_copy(const data_collection_model_media_streaming_accesses_collection_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_streaming_accesses_collection_t*>(new std::shared_ptr<MediaStreamingAccessesCollection >(new MediaStreamingAccessesCollection(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_create_move(data_collection_model_media_streaming_accesses_collection_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > *obj = reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_copy(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const data_collection_model_media_streaming_accesses_collection_t *other)
{
    if (media_streaming_accesses_collection) {
        std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(media_streaming_accesses_collection);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaStreamingAccessesCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(other);
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
                const std::shared_ptr<MediaStreamingAccessesCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(other);
                if (other_obj) {
                    obj.reset(new MediaStreamingAccessesCollection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_streaming_accesses_collection = data_collection_model_media_streaming_accesses_collection_create_copy(other);
    }
    return media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, data_collection_model_media_streaming_accesses_collection_t *other)
{
    std::shared_ptr<MediaStreamingAccessesCollection > *other_ptr = reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(other);

    if (media_streaming_accesses_collection) {
        std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(media_streaming_accesses_collection);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_streaming_accesses_collection = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_accesses_collection_free(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection)
{
    if (!media_streaming_accesses_collection) return;
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(media_streaming_accesses_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_accesses_collection_toJSON(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, bool as_request)
{
    if (!media_streaming_accesses_collection) return NULL;
    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(media_streaming_accesses_collection);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_accesses_collection_t*>(new std::shared_ptr<MediaStreamingAccessesCollection >(new MediaStreamingAccessesCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_media_streaming_accesses_collection_is_equal_to(const data_collection_model_media_streaming_accesses_collection_t *first, const data_collection_model_media_streaming_accesses_collection_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaStreamingAccessesCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaStreamingAccessesCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_accesses_collection_get_collection_timestamp(const data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessesCollection::CollectionTimestampType ResultFromType;
    const ResultFromType result_from = obj->getCollectionTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_collection_timestamp(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const char* p_collection_timestamp)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_collection_timestamp;
    typedef typename MediaStreamingAccessesCollection::CollectionTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setCollectionTimestamp(value)) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_collection_timestamp_move(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, char* p_collection_timestamp)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_collection_timestamp;
    typedef typename MediaStreamingAccessesCollection::CollectionTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setCollectionTimestamp(std::move(value))) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_accesses_collection_get_start_timestamp(const data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessesCollection::StartTimestampType ResultFromType;
    const ResultFromType result_from = obj->getStartTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_start_timestamp(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const char* p_start_timestamp)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_start_timestamp;
    typedef typename MediaStreamingAccessesCollection::StartTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setStartTimestamp(value)) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_start_timestamp_move(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, char* p_start_timestamp)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_start_timestamp;
    typedef typename MediaStreamingAccessesCollection::StartTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setStartTimestamp(std::move(value))) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_accesses_collection_get_end_timestamp(const data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessesCollection::EndTimestampType ResultFromType;
    const ResultFromType result_from = obj->getEndTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_end_timestamp(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const char* p_end_timestamp)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_end_timestamp;
    typedef typename MediaStreamingAccessesCollection::EndTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setEndTimestamp(value)) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_end_timestamp_move(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, char* p_end_timestamp)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_end_timestamp;
    typedef typename MediaStreamingAccessesCollection::EndTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setEndTimestamp(std::move(value))) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_media_streaming_accesses_collection_get_sample_count(const data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename MediaStreamingAccessesCollection::SampleCountType ResultFromType;
    const ResultFromType result_from = obj->getSampleCount();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_sample_count(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const int32_t p_sample_count)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_sample_count;
    typedef typename MediaStreamingAccessesCollection::SampleCountType ValueType;

    ValueType value = value_from;
    if (!obj->setSampleCount(value)) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_sample_count_move(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, int32_t p_sample_count)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_sample_count;
    typedef typename MediaStreamingAccessesCollection::SampleCountType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSampleCount(std::move(value))) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_provisioning_session_type_t* data_collection_model_media_streaming_accesses_collection_get_streaming_direction(const data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) {
        const data_collection_model_provisioning_session_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) {
        const data_collection_model_provisioning_session_type_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessesCollection::StreamingDirectionType ResultFromType;
    const ResultFromType result_from = obj->getStreamingDirection();
    const data_collection_model_provisioning_session_type_t *result = reinterpret_cast<const data_collection_model_provisioning_session_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_streaming_direction(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const data_collection_model_provisioning_session_type_t* p_streaming_direction)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_streaming_direction;
    typedef typename MediaStreamingAccessesCollection::StreamingDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setStreamingDirection(value)) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_streaming_direction_move(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, data_collection_model_provisioning_session_type_t* p_streaming_direction)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_streaming_direction;
    typedef typename MediaStreamingAccessesCollection::StreamingDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setStreamingDirection(std::move(value))) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_media_streaming_accesses_collection_get_summarisations(const data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessesCollection::SummarisationsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_summarisations(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const ogs_list_t* p_summarisations)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_summarisations;
    typedef typename MediaStreamingAccessesCollection::SummarisationsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setSummarisations(value)) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_summarisations_move(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, ogs_list_t* p_summarisations)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_summarisations;
    typedef typename MediaStreamingAccessesCollection::SummarisationsType ValueType;

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

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_add_summarisations(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, data_collection_model_data_aggregation_function_type_t* p_summarisations)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessesCollection::SummarisationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_summarisations;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addSummarisations(value);
    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_remove_summarisations(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const data_collection_model_data_aggregation_function_type_t* p_summarisations)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessesCollection::SummarisationsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_summarisations;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeSummarisations(value);
    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_clear_summarisations(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    obj->clearSummarisations();
    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_media_streaming_accesses_collection_get_records(const data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessesCollection::RecordsType ResultFromType;
    const ResultFromType result_from = obj->getRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_media_streaming_access_event_t *item_obj = reinterpret_cast<data_collection_model_media_streaming_access_event_t*>(new std::shared_ptr<MediaStreamingAccessEvent >(item));
        node = data_collection_model_media_streaming_access_event_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_records(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const ogs_list_t* p_records)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_records;
    typedef typename MediaStreamingAccessesCollection::RecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRecords(value)) return NULL;

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_records_move(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, ogs_list_t* p_records)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    const auto &value_from = p_records;
    typedef typename MediaStreamingAccessesCollection::RecordsType ValueType;

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

    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_add_records(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, data_collection_model_media_streaming_access_event_t* p_records)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessesCollection::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRecords(value);
    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_remove_records(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection, const data_collection_model_media_streaming_access_event_t* p_records)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessesCollection::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRecords(value);
    return obj_media_streaming_accesses_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_clear_records(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    if (!obj) return NULL;

    obj->clearRecords();
    return obj_media_streaming_accesses_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_accesses_collection_make_lnode(data_collection_model_media_streaming_accesses_collection_t *p_media_streaming_accesses_collection)
{
    return data_collection_lnode_create(p_media_streaming_accesses_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_accesses_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_accesses_collection_refcount(data_collection_model_media_streaming_accesses_collection_t *obj_media_streaming_accesses_collection)
{
    if (!obj_media_streaming_accesses_collection) return 0l;
    std::shared_ptr<MediaStreamingAccessesCollection > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection >*>(obj_media_streaming_accesses_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

