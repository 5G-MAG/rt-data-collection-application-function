/**********************************************************************************************************************************
 * CommunicationRecord - C interface to the CommunicationRecord object
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

/*#include "CommunicationRecord.h" already included by data-collection-sp/data-collection.h */
#include "CommunicationRecord-internal.h"
#include "openapi/model/CommunicationRecord.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_create(







)
{
    return reinterpret_cast<data_collection_model_communication_record_t*>(new std::shared_ptr<CommunicationRecord>(new CommunicationRecord(







)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_create_copy(const data_collection_model_communication_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_communication_record_t*>(new std::shared_ptr<CommunicationRecord >(new CommunicationRecord(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_create_move(data_collection_model_communication_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CommunicationRecord > *obj = reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_copy(data_collection_model_communication_record_t *communication_record, const data_collection_model_communication_record_t *other)
{
    if (communication_record) {
        std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(communication_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<CommunicationRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(other);
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
                const std::shared_ptr<CommunicationRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(other);
                if (other_obj) {
                    obj.reset(new CommunicationRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        communication_record = data_collection_model_communication_record_create_copy(other);
    }
    return communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_move(data_collection_model_communication_record_t *communication_record, data_collection_model_communication_record_t *other)
{
    std::shared_ptr<CommunicationRecord > *other_ptr = reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(other);

    if (communication_record) {
        std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(communication_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                communication_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_communication_record_free(data_collection_model_communication_record_t *communication_record)
{
    if (!communication_record) return;
    delete reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(communication_record);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_communication_record_toJSON(const data_collection_model_communication_record_t *communication_record, bool as_request)
{
    if (!communication_record) return NULL;
    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(communication_record);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_communication_record_t*>(new std::shared_ptr<CommunicationRecord >(new CommunicationRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_is_equal_to(const data_collection_model_communication_record_t *first, const data_collection_model_communication_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CommunicationRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CommunicationRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_record_get_timestamp(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CommunicationRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_timestamp(data_collection_model_communication_record_t *obj_communication_record, const char* p_timestamp)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename CommunicationRecord::TimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimestamp(value)) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_timestamp_move(data_collection_model_communication_record_t *obj_communication_record, char* p_timestamp)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename CommunicationRecord::TimestampType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTimestamp(std::move(value))) return NULL;

    return obj_communication_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_communication_record_get_context_ids(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CommunicationRecord::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_context_ids(data_collection_model_communication_record_t *obj_communication_record, const ogs_list_t* p_context_ids)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename CommunicationRecord::ContextIdsType ValueType;

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

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_context_ids_move(data_collection_model_communication_record_t *obj_communication_record, ogs_list_t* p_context_ids)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename CommunicationRecord::ContextIdsType ValueType;

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

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_add_context_ids(data_collection_model_communication_record_t *obj_communication_record, char* p_context_ids)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    typedef typename CommunicationRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);


    obj->addContextIds(value);
    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_remove_context_ids(data_collection_model_communication_record_t *obj_communication_record, const char* p_context_ids)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    typedef typename CommunicationRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);

    obj->removeContextIds(value);
    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_clear_context_ids(data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_communication_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_communication_record_get_time_interval(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    typedef typename CommunicationRecord::TimeIntervalType ResultFromType;
    const ResultFromType result_from = obj->getTimeInterval();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_time_interval(data_collection_model_communication_record_t *obj_communication_record, const data_collection_model_time_window_t* p_time_interval)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_time_interval;
    typedef typename CommunicationRecord::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setTimeInterval(value)) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_time_interval_move(data_collection_model_communication_record_t *obj_communication_record, data_collection_model_time_window_t* p_time_interval)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_time_interval;
    typedef typename CommunicationRecord::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setTimeInterval(std::move(value))) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_slice_info(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return false;

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return false;

    return obj->getSliceInfo().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_communication_record_get_slice_info(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename CommunicationRecord::SliceInfoType ResultFromType;
    const ResultFromType result_from = obj->getSliceInfo();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_slice_info(data_collection_model_communication_record_t *obj_communication_record, const data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename CommunicationRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceInfo(value)) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_slice_info_move(data_collection_model_communication_record_t *obj_communication_record, data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename CommunicationRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setSliceInfo(std::move(value))) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_data_network_name(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return false;

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return false;

    return obj->getDataNetworkName().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_record_get_data_network_name(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CommunicationRecord::DataNetworkNameType ResultFromType;
    const ResultFromType result_from = obj->getDataNetworkName();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_data_network_name(data_collection_model_communication_record_t *obj_communication_record, const char* p_data_network_name)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename CommunicationRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_data_network_name_move(data_collection_model_communication_record_t *obj_communication_record, char* p_data_network_name)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename CommunicationRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_location(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return false;

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return false;

    return obj->getLocation().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_communication_record_get_location(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CommunicationRecord::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_location_area5_g_t*>(item.has_value()?new std::shared_ptr<LocationArea5G >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_location_area5_g_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_location(data_collection_model_communication_record_t *obj_communication_record, const ogs_list_t* p_location)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename CommunicationRecord::LocationType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setLocation(value)) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_location_move(data_collection_model_communication_record_t *obj_communication_record, ogs_list_t* p_location)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename CommunicationRecord::LocationType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_location);
    if (!obj->setLocation(std::move(value))) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_add_location(data_collection_model_communication_record_t *obj_communication_record, data_collection_model_location_area5_g_t* p_location)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    typedef typename CommunicationRecord::LocationType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_location;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addLocation(value.value());
    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_remove_location(data_collection_model_communication_record_t *obj_communication_record, const data_collection_model_location_area5_g_t* p_location)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    typedef typename CommunicationRecord::LocationType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_location;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeLocation(value);
    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_clear_location(data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    obj->clearLocation();
    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_uplink_volume(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return false;

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return false;

    return obj->getUplinkVolume().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_get_uplink_volume(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        const int64_t result = 0;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        const int64_t result = 0;
        return result;
    }

    typedef typename CommunicationRecord::UplinkVolumeType ResultFromType;
    const ResultFromType result_from = obj->getUplinkVolume();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_uplink_volume(data_collection_model_communication_record_t *obj_communication_record, const int64_t p_uplink_volume)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_volume;
    typedef typename CommunicationRecord::UplinkVolumeType ValueType;

    ValueType value(value_from);

    if (!obj->setUplinkVolume(value)) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_uplink_volume_move(data_collection_model_communication_record_t *obj_communication_record, int64_t p_uplink_volume)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_uplink_volume;
    typedef typename CommunicationRecord::UplinkVolumeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setUplinkVolume(std::move(value))) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_record_has_downlink_volume(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return false;

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return false;

    return obj->getDownlinkVolume().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_record_get_downlink_volume(const data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) {
        const int64_t result = 0;
        return result;
    }

    const std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) {
        const int64_t result = 0;
        return result;
    }

    typedef typename CommunicationRecord::DownlinkVolumeType ResultFromType;
    const ResultFromType result_from = obj->getDownlinkVolume();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_downlink_volume(data_collection_model_communication_record_t *obj_communication_record, const int64_t p_downlink_volume)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_volume;
    typedef typename CommunicationRecord::DownlinkVolumeType ValueType;

    ValueType value(value_from);

    if (!obj->setDownlinkVolume(value)) return NULL;

    return obj_communication_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_record_t *data_collection_model_communication_record_set_downlink_volume_move(data_collection_model_communication_record_t *obj_communication_record, int64_t p_downlink_volume)
{
    if (!obj_communication_record) return NULL;

    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    if (!obj) return NULL;

    const auto &value_from = p_downlink_volume;
    typedef typename CommunicationRecord::DownlinkVolumeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDownlinkVolume(std::move(value))) return NULL;

    return obj_communication_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_communication_record_make_lnode(data_collection_model_communication_record_t *p_communication_record)
{
    return data_collection_lnode_create(p_communication_record, reinterpret_cast<void(*)(void*)>(data_collection_model_communication_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_communication_record_refcount(data_collection_model_communication_record_t *obj_communication_record)
{
    if (!obj_communication_record) return 0l;
    std::shared_ptr<CommunicationRecord > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord >*>(obj_communication_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

