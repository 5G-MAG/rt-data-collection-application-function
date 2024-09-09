/**********************************************************************************************************************************
 * MediaStreamingAccessRecord - C interface to the MediaStreamingAccessRecord object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "MediaStreamingAccessRecord.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingAccessRecord-internal.h"
#include "openapi/model/MediaStreamingAccessRecord.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_create(












)
{
    return reinterpret_cast<data_collection_model_media_streaming_access_record_t*>(new std::shared_ptr<MediaStreamingAccessRecord>(new MediaStreamingAccessRecord(












)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_create_copy(const data_collection_model_media_streaming_access_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_streaming_access_record_t*>(new std::shared_ptr<MediaStreamingAccessRecord >(new MediaStreamingAccessRecord(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_create_move(data_collection_model_media_streaming_access_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > *obj = reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_copy(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, const data_collection_model_media_streaming_access_record_t *other)
{
    if (media_streaming_access_record) {
        std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(media_streaming_access_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaStreamingAccessRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(other);
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
                const std::shared_ptr<MediaStreamingAccessRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(other);
                if (other_obj) {
                    obj.reset(new MediaStreamingAccessRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_streaming_access_record = data_collection_model_media_streaming_access_record_create_copy(other);
    }
    return media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_move(data_collection_model_media_streaming_access_record_t *media_streaming_access_record, data_collection_model_media_streaming_access_record_t *other)
{
    std::shared_ptr<MediaStreamingAccessRecord > *other_ptr = reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(other);

    if (media_streaming_access_record) {
        std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(media_streaming_access_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_streaming_access_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_record_free(data_collection_model_media_streaming_access_record_t *media_streaming_access_record)
{
    if (!media_streaming_access_record) return;
    delete reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(media_streaming_access_record);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_record_toJSON(const data_collection_model_media_streaming_access_record_t *media_streaming_access_record, bool as_request)
{
    if (!media_streaming_access_record) return NULL;
    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(media_streaming_access_record);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_media_streaming_access_record_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_access_record_t*>(new std::shared_ptr<MediaStreamingAccessRecord >(new MediaStreamingAccessRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_is_equal_to(const data_collection_model_media_streaming_access_record_t *first, const data_collection_model_media_streaming_access_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaStreamingAccessRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaStreamingAccessRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_record_get_timestamp(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::TimestampType ResultFromType;
    const ResultFromType &result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_timestamp(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const char* p_timestamp)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename MediaStreamingAccessRecord::TimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimestamp(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_timestamp_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, char* p_timestamp)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename MediaStreamingAccessRecord::TimestampType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTimestamp(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_media_streaming_access_record_get_context_ids(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::ContextIdsType ResultFromType;
    const ResultFromType &result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_context_ids(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const ogs_list_t* p_context_ids)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename MediaStreamingAccessRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_context_ids_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, ogs_list_t* p_context_ids)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename MediaStreamingAccessRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_add_context_ids(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, char* p_context_ids)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);


    obj->addContextIds(value);
    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_remove_context_ids(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const char* p_context_ids)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    typedef typename MediaStreamingAccessRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);

    obj->removeContextIds(value);
    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_clear_context_ids(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_slice_info(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) return false;

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return false;

    return obj->getSliceInfo().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_media_streaming_access_record_get_slice_info(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::SliceInfoType ResultFromType;
    const ResultFromType &result_from = obj->getSliceInfo();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_slice_info(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename MediaStreamingAccessRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceInfo(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_slice_info_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename MediaStreamingAccessRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setSliceInfo(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_data_network_name(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) return false;

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return false;

    return obj->getDataNetworkName().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_record_get_data_network_name(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::DataNetworkNameType ResultFromType;
    const ResultFromType &result_from = obj->getDataNetworkName();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_data_network_name(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const char* p_data_network_name)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename MediaStreamingAccessRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_data_network_name_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, char* p_data_network_name)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename MediaStreamingAccessRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_location(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) return false;

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return false;

    return obj->getLocation().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_typed_location_t* data_collection_model_media_streaming_access_record_get_location(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_typed_location_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_typed_location_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::LocationType ResultFromType;
    const ResultFromType &result_from = obj->getLocation();
    const data_collection_model_typed_location_t *result = reinterpret_cast<const data_collection_model_typed_location_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_location(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_typed_location_t* p_location)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename MediaStreamingAccessRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocation(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_location_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_typed_location_t* p_location)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename MediaStreamingAccessRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setLocation(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_access_record_get_session_id(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::SessionIdType ResultFromType;
    const ResultFromType &result_from = obj->getSessionId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_session_id(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const char* p_session_id)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename MediaStreamingAccessRecord::SessionIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSessionId(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_session_id_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, char* p_session_id)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename MediaStreamingAccessRecord::SessionIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSessionId(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_record_get_media_stream_handler_endpoint_address(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::MediaStreamHandlerEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getMediaStreamHandlerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_media_stream_handler_endpoint_address(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccessRecord::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMediaStreamHandlerEndpointAddress(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_media_stream_handler_endpoint_address_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_endpoint_address_t* p_media_stream_handler_endpoint_address)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_media_stream_handler_endpoint_address;
    typedef typename MediaStreamingAccessRecord::MediaStreamHandlerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setMediaStreamHandlerEndpointAddress(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_media_streaming_access_record_get_application_server_endpoint_address(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::ApplicationServerEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getApplicationServerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_application_server_endpoint_address(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccessRecord::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setApplicationServerEndpointAddress(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_application_server_endpoint_address_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_endpoint_address_t* p_application_server_endpoint_address)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_application_server_endpoint_address;
    typedef typename MediaStreamingAccessRecord::ApplicationServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setApplicationServerEndpointAddress(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_request_message_t* data_collection_model_media_streaming_access_record_get_request_message(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_media_streaming_access_request_message_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_media_streaming_access_request_message_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::RequestMessageType ResultFromType;
    const ResultFromType &result_from = obj->getRequestMessage();
    const data_collection_model_media_streaming_access_request_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_request_message_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_request_message(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccessRecord::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setRequestMessage(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_request_message_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_media_streaming_access_request_message_t* p_request_message)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_request_message;
    typedef typename MediaStreamingAccessRecord::RequestMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setRequestMessage(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_cache_status(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) return false;

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return false;

    return obj->getCacheStatus().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cache_status_t* data_collection_model_media_streaming_access_record_get_cache_status(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_cache_status_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_cache_status_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::CacheStatusType ResultFromType;
    const ResultFromType &result_from = obj->getCacheStatus();
    const data_collection_model_cache_status_t *result = reinterpret_cast<const data_collection_model_cache_status_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_cache_status(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_cache_status_t* p_cache_status)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccessRecord::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setCacheStatus(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_cache_status_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_cache_status_t* p_cache_status)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_cache_status;
    typedef typename MediaStreamingAccessRecord::CacheStatusType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setCacheStatus(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_response_message_t* data_collection_model_media_streaming_access_record_get_response_message(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_media_streaming_access_response_message_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_media_streaming_access_response_message_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::ResponseMessageType ResultFromType;
    const ResultFromType &result_from = obj->getResponseMessage();
    const data_collection_model_media_streaming_access_response_message_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_response_message_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_response_message(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccessRecord::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setResponseMessage(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_response_message_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_media_streaming_access_response_message_t* p_response_message)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_response_message;
    typedef typename MediaStreamingAccessRecord::ResponseMessageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setResponseMessage(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_record_get_processing_latency(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::ProcessingLatencyType ResultFromType;
    const ResultFromType &result_from = obj->getProcessingLatency();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_processing_latency(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const float p_processing_latency)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccessRecord::ProcessingLatencyType ValueType;

    ValueType value(value_from);

    if (!obj->setProcessingLatency(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_processing_latency_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, float p_processing_latency)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_processing_latency;
    typedef typename MediaStreamingAccessRecord::ProcessingLatencyType ValueType;

    ValueType value(value_from);

    
    if (!obj->setProcessingLatency(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_record_has_connection_metrics(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) return false;

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return false;

    return obj->getConnectionMetrics().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_connection_metrics_t* data_collection_model_media_streaming_access_record_get_connection_metrics(const data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) {
        const data_collection_model_media_streaming_access_connection_metrics_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) {
        const data_collection_model_media_streaming_access_connection_metrics_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingAccessRecord::ConnectionMetricsType ResultFromType;
    const ResultFromType &result_from = obj->getConnectionMetrics();
    const data_collection_model_media_streaming_access_connection_metrics_t *result = reinterpret_cast<const data_collection_model_media_streaming_access_connection_metrics_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_connection_metrics(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, const data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccessRecord::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setConnectionMetrics(value)) return NULL;

    return obj_media_streaming_access_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_record_t *data_collection_model_media_streaming_access_record_set_connection_metrics_move(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record, data_collection_model_media_streaming_access_connection_metrics_t* p_connection_metrics)
{
    if (!obj_media_streaming_access_record) return NULL;

    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    if (!obj) return NULL;

    const auto &value_from = p_connection_metrics;
    typedef typename MediaStreamingAccessRecord::ConnectionMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setConnectionMetrics(std::move(value))) return NULL;

    return obj_media_streaming_access_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_record_make_lnode(data_collection_model_media_streaming_access_record_t *p_media_streaming_access_record)
{
    return data_collection_lnode_create(p_media_streaming_access_record, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_access_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_access_record_refcount(data_collection_model_media_streaming_access_record_t *obj_media_streaming_access_record)
{
    if (!obj_media_streaming_access_record) return 0l;
    std::shared_ptr<MediaStreamingAccessRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingAccessRecord >*>(obj_media_streaming_access_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

