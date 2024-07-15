/**********************************************************************************************************************************
 * MediaStreamingAccessesCollection_allOf - C interface to the MediaStreamingAccessesCollection_allOf object
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

/*#include "MediaStreamingAccessesCollection_allOf.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccessesCollection_allOf-internal.h"
#include "openapi/model/MediaStreamingAccessesCollection_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_create(
)
{
    return reinterpret_cast<data_collection_model_media_streaming_accesses_collection_all_of_t*>(new std::shared_ptr<MediaStreamingAccessesCollection_allOf>(new MediaStreamingAccessesCollection_allOf(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_create_copy(const data_collection_model_media_streaming_accesses_collection_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_accesses_collection_all_of_t*>(new std::shared_ptr<MediaStreamingAccessesCollection_allOf >(new MediaStreamingAccessesCollection_allOf(**reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_create_move(data_collection_model_media_streaming_accesses_collection_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_accesses_collection_all_of_t*>(new std::shared_ptr<MediaStreamingAccessesCollection_allOf >(std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_copy(data_collection_model_media_streaming_accesses_collection_all_of_t *media_streaming_accesses_collection_all_of, const data_collection_model_media_streaming_accesses_collection_all_of_t *other)
{
    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(media_streaming_accesses_collection_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(other);
    return media_streaming_accesses_collection_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_move(data_collection_model_media_streaming_accesses_collection_all_of_t *media_streaming_accesses_collection_all_of, data_collection_model_media_streaming_accesses_collection_all_of_t *other)
{
    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(media_streaming_accesses_collection_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(other));
    return media_streaming_accesses_collection_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_accesses_collection_all_of_free(data_collection_model_media_streaming_accesses_collection_all_of_t *media_streaming_accesses_collection_all_of)
{
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(media_streaming_accesses_collection_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_accesses_collection_all_of_toJSON(const data_collection_model_media_streaming_accesses_collection_all_of_t *media_streaming_accesses_collection_all_of, bool as_request)
{
    const std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(media_streaming_accesses_collection_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_accesses_collection_all_of_t*>(new std::shared_ptr<MediaStreamingAccessesCollection_allOf >(new MediaStreamingAccessesCollection_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_media_streaming_accesses_collection_all_of_get_records(const data_collection_model_media_streaming_accesses_collection_all_of_t *obj_media_streaming_accesses_collection_all_of)
{
    const std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(obj_media_streaming_accesses_collection_all_of);
    typedef typename MediaStreamingAccessesCollection_allOf::RecordsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_set_records(data_collection_model_media_streaming_accesses_collection_all_of_t *obj_media_streaming_accesses_collection_all_of, const ogs_list_t* p_records)
{
    if (obj_media_streaming_accesses_collection_all_of == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(obj_media_streaming_accesses_collection_all_of);
    const auto &value_from = p_records;
    typedef typename MediaStreamingAccessesCollection_allOf::RecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRecords(value)) return NULL;
    return obj_media_streaming_accesses_collection_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_set_records_move(data_collection_model_media_streaming_accesses_collection_all_of_t *obj_media_streaming_accesses_collection_all_of, ogs_list_t* p_records)
{
    if (obj_media_streaming_accesses_collection_all_of == NULL) return NULL;

    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(obj_media_streaming_accesses_collection_all_of);
    const auto &value_from = p_records;
    typedef typename MediaStreamingAccessesCollection_allOf::RecordsType ValueType;

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
    return obj_media_streaming_accesses_collection_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_add_records(data_collection_model_media_streaming_accesses_collection_all_of_t *obj_media_streaming_accesses_collection_all_of, data_collection_model_media_streaming_access_event_t* p_records)
{
    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(obj_media_streaming_accesses_collection_all_of);
    typedef typename MediaStreamingAccessesCollection_allOf::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRecords(value);
    return obj_media_streaming_accesses_collection_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_remove_records(data_collection_model_media_streaming_accesses_collection_all_of_t *obj_media_streaming_accesses_collection_all_of, const data_collection_model_media_streaming_access_event_t* p_records)
{
    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(obj_media_streaming_accesses_collection_all_of);
    typedef typename MediaStreamingAccessesCollection_allOf::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRecords(value);
    return obj_media_streaming_accesses_collection_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_accesses_collection_all_of_t *data_collection_model_media_streaming_accesses_collection_all_of_clear_records(data_collection_model_media_streaming_accesses_collection_all_of_t *obj_media_streaming_accesses_collection_all_of)
{   
    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(obj_media_streaming_accesses_collection_all_of);
    obj->clearRecords();
    return obj_media_streaming_accesses_collection_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_accesses_collection_all_of_make_lnode(data_collection_model_media_streaming_accesses_collection_all_of_t *p_media_streaming_accesses_collection_all_of)
{
    return data_collection_lnode_create(p_media_streaming_accesses_collection_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_accesses_collection_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_accesses_collection_all_of_refcount(data_collection_model_media_streaming_accesses_collection_all_of_t *obj_media_streaming_accesses_collection_all_of)
{
    std::shared_ptr<MediaStreamingAccessesCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessesCollection_allOf >*>(obj_media_streaming_accesses_collection_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

