/**********************************************************************************************************************************
 * MSAccessActivityCollection - C interface to the MSAccessActivityCollection object
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

/*#include "MSAccessActivityCollection.h" already included by data-collection-sp/data-collection.h */
#include "MSAccessActivityCollection-internal.h"
#include "openapi/model/MSAccessActivityCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_create(
)
{
    return reinterpret_cast<data_collection_model_ms_access_activity_collection_t*>(new std::shared_ptr<MSAccessActivityCollection>(new MSAccessActivityCollection(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_create_copy(const data_collection_model_ms_access_activity_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ms_access_activity_collection_t*>(new std::shared_ptr<MSAccessActivityCollection >(new MSAccessActivityCollection(**reinterpret_cast<const std::shared_ptr<MSAccessActivityCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_create_move(data_collection_model_ms_access_activity_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ms_access_activity_collection_t*>(new std::shared_ptr<MSAccessActivityCollection >(std::move(*reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_copy(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, const data_collection_model_ms_access_activity_collection_t *other)
{
    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(ms_access_activity_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<MSAccessActivityCollection >*>(other);
    return ms_access_activity_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_move(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, data_collection_model_ms_access_activity_collection_t *other)
{
    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(ms_access_activity_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(other));
    return ms_access_activity_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ms_access_activity_collection_free(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection)
{
    delete reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(ms_access_activity_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ms_access_activity_collection_toJSON(const data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, bool as_request)
{
    const std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<const std::shared_ptr<MSAccessActivityCollection >*>(ms_access_activity_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ms_access_activity_collection_t*>(new std::shared_ptr<MSAccessActivityCollection >(new MSAccessActivityCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_ms_access_activity_collection_is_equal_to(const data_collection_model_ms_access_activity_collection_t *first, const data_collection_model_ms_access_activity_collection_t *second)
{
    const std::shared_ptr<MSAccessActivityCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<MSAccessActivityCollection >*>(first);
    const std::shared_ptr<MSAccessActivityCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<MSAccessActivityCollection >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_ms_access_activity_collection_get_ms_acc_acts(const data_collection_model_ms_access_activity_collection_t *obj_ms_access_activity_collection)
{
    const std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<const std::shared_ptr<MSAccessActivityCollection >*>(obj_ms_access_activity_collection);
    typedef typename MSAccessActivityCollection::MsAccActsType ResultFromType;
    const ResultFromType result_from = obj->getMsAccActs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_media_streaming_access_record_t *item_obj = reinterpret_cast<data_collection_model_media_streaming_access_record_t*>(new std::shared_ptr<MediaStreamingAccessRecord >(item));
        node = data_collection_model_media_streaming_access_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_set_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *obj_ms_access_activity_collection, const ogs_list_t* p_ms_acc_acts)
{
    if (obj_ms_access_activity_collection == NULL) return NULL;

    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(obj_ms_access_activity_collection);
    const auto &value_from = p_ms_acc_acts;
    typedef typename MSAccessActivityCollection::MsAccActsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsAccActs(value)) return NULL;
    return obj_ms_access_activity_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_set_ms_acc_acts_move(data_collection_model_ms_access_activity_collection_t *obj_ms_access_activity_collection, ogs_list_t* p_ms_acc_acts)
{
    if (obj_ms_access_activity_collection == NULL) return NULL;

    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(obj_ms_access_activity_collection);
    const auto &value_from = p_ms_acc_acts;
    typedef typename MSAccessActivityCollection::MsAccActsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_acc_acts);
    if (!obj->setMsAccActs(std::move(value))) return NULL;
    return obj_ms_access_activity_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_add_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *obj_ms_access_activity_collection, data_collection_model_media_streaming_access_record_t* p_ms_acc_acts)
{
    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(obj_ms_access_activity_collection);
    typedef typename MSAccessActivityCollection::MsAccActsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_acc_acts;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsAccActs(value);
    return obj_ms_access_activity_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_remove_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *obj_ms_access_activity_collection, const data_collection_model_media_streaming_access_record_t* p_ms_acc_acts)
{
    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(obj_ms_access_activity_collection);
    typedef typename MSAccessActivityCollection::MsAccActsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_acc_acts;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsAccActs(value);
    return obj_ms_access_activity_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_clear_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *obj_ms_access_activity_collection)
{   
    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(obj_ms_access_activity_collection);
    obj->clearMsAccActs();
    return obj_ms_access_activity_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ms_access_activity_collection_make_lnode(data_collection_model_ms_access_activity_collection_t *p_ms_access_activity_collection)
{
    return data_collection_lnode_create(p_ms_access_activity_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_ms_access_activity_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ms_access_activity_collection_refcount(data_collection_model_ms_access_activity_collection_t *obj_ms_access_activity_collection)
{
    std::shared_ptr<MSAccessActivityCollection > &obj = *reinterpret_cast<std::shared_ptr<MSAccessActivityCollection >*>(obj_ms_access_activity_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

