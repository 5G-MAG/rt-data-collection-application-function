/**********************************************************************************************************************************
 * EventFilter - C interface to the EventFilter object
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

/*#include "EventFilter.h" already included by data-collection-sp/data-collection.h */
#include "EventFilter-internal.h"
#include "openapi/model/EventFilter.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create(









)
{
    return reinterpret_cast<data_collection_model_event_filter_t*>(new std::shared_ptr<EventFilter>(new EventFilter(









)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create_copy(const data_collection_model_event_filter_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_event_filter_t*>(new std::shared_ptr<EventFilter >(new EventFilter(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create_move(data_collection_model_event_filter_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<EventFilter > *obj = reinterpret_cast<std::shared_ptr<EventFilter >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_copy(data_collection_model_event_filter_t *event_filter, const data_collection_model_event_filter_t *other)
{
    if (event_filter) {
        std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(event_filter);
        if (obj) {
            if (other) {
                const std::shared_ptr<EventFilter > &other_obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(other);
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
                const std::shared_ptr<EventFilter > &other_obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(other);
                if (other_obj) {
                    obj.reset(new EventFilter(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        event_filter = data_collection_model_event_filter_create_copy(other);
    }
    return event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_move(data_collection_model_event_filter_t *event_filter, data_collection_model_event_filter_t *other)
{
    std::shared_ptr<EventFilter > *other_ptr = reinterpret_cast<std::shared_ptr<EventFilter >*>(other);

    if (event_filter) {
        std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(event_filter);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                event_filter = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_event_filter_free(data_collection_model_event_filter_t *event_filter)
{
    if (!event_filter) return;
    delete reinterpret_cast<std::shared_ptr<EventFilter >*>(event_filter);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_event_filter_toJSON(const data_collection_model_event_filter_t *event_filter, bool as_request)
{
    if (!event_filter) return NULL;
    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(event_filter);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_event_filter_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_event_filter_t*>(new std::shared_ptr<EventFilter >(new EventFilter(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_is_equal_to(const data_collection_model_event_filter_t *first, const data_collection_model_event_filter_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<EventFilter > &obj2 = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<EventFilter > &obj1 = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_gpsis(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getGpsis().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_gpsis(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::GpsisType ResultFromType;
    const ResultFromType &result_from = obj->getGpsis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_gpsis(data_collection_model_event_filter_t *obj_event_filter, const ogs_list_t* p_gpsis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_gpsis;
    typedef typename EventFilter::GpsisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setGpsis(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_gpsis_move(data_collection_model_event_filter_t *obj_event_filter, ogs_list_t* p_gpsis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_gpsis;
    typedef typename EventFilter::GpsisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_gpsis);
    if (!obj->setGpsis(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_gpsis(data_collection_model_event_filter_t *obj_event_filter, char* p_gpsis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::GpsisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_gpsis;

    ValueType value(value_from);


    if (value) obj->addGpsis(value.value());
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_gpsis(data_collection_model_event_filter_t *obj_event_filter, const char* p_gpsis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::GpsisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_gpsis;
    ValueType value(value_from);

    obj->removeGpsis(value);
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_gpsis(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    obj->clearGpsis();
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_supis(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getSupis().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_supis(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::SupisType ResultFromType;
    const ResultFromType &result_from = obj->getSupis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_supis(data_collection_model_event_filter_t *obj_event_filter, const ogs_list_t* p_supis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_supis;
    typedef typename EventFilter::SupisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setSupis(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_supis_move(data_collection_model_event_filter_t *obj_event_filter, ogs_list_t* p_supis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_supis;
    typedef typename EventFilter::SupisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_supis);
    if (!obj->setSupis(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_supis(data_collection_model_event_filter_t *obj_event_filter, char* p_supis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::SupisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_supis;

    ValueType value(value_from);


    if (value) obj->addSupis(value.value());
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_supis(data_collection_model_event_filter_t *obj_event_filter, const char* p_supis)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::SupisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_supis;
    ValueType value(value_from);

    obj->removeSupis(value);
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_supis(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    obj->clearSupis();
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_exter_group_ids(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getExterGroupIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_exter_group_ids(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::ExterGroupIdsType ResultFromType;
    const ResultFromType &result_from = obj->getExterGroupIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exter_group_ids(data_collection_model_event_filter_t *obj_event_filter, const ogs_list_t* p_exter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_exter_group_ids;
    typedef typename EventFilter::ExterGroupIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setExterGroupIds(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exter_group_ids_move(data_collection_model_event_filter_t *obj_event_filter, ogs_list_t* p_exter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_exter_group_ids;
    typedef typename EventFilter::ExterGroupIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_exter_group_ids);
    if (!obj->setExterGroupIds(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_exter_group_ids(data_collection_model_event_filter_t *obj_event_filter, char* p_exter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::ExterGroupIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_exter_group_ids;

    ValueType value(value_from);


    if (value) obj->addExterGroupIds(value.value());
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_exter_group_ids(data_collection_model_event_filter_t *obj_event_filter, const char* p_exter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::ExterGroupIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_exter_group_ids;
    ValueType value(value_from);

    obj->removeExterGroupIds(value);
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_exter_group_ids(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    obj->clearExterGroupIds();
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_inter_group_ids(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getInterGroupIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_inter_group_ids(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::InterGroupIdsType ResultFromType;
    const ResultFromType &result_from = obj->getInterGroupIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_inter_group_ids(data_collection_model_event_filter_t *obj_event_filter, const ogs_list_t* p_inter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_inter_group_ids;
    typedef typename EventFilter::InterGroupIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setInterGroupIds(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_inter_group_ids_move(data_collection_model_event_filter_t *obj_event_filter, ogs_list_t* p_inter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_inter_group_ids;
    typedef typename EventFilter::InterGroupIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_inter_group_ids);
    if (!obj->setInterGroupIds(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_inter_group_ids(data_collection_model_event_filter_t *obj_event_filter, char* p_inter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::InterGroupIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_inter_group_ids;

    ValueType value(value_from);


    if (value) obj->addInterGroupIds(value.value());
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_inter_group_ids(data_collection_model_event_filter_t *obj_event_filter, const char* p_inter_group_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::InterGroupIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_inter_group_ids;
    ValueType value(value_from);

    obj->removeInterGroupIds(value);
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_inter_group_ids(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    obj->clearInterGroupIds();
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_any_ue_ind(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->isAnyUeInd().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_event_filter_is_any_ue_ind(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename EventFilter::AnyUeIndType ResultFromType;
    const ResultFromType &result_from = obj->isAnyUeInd();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_any_ue_ind(data_collection_model_event_filter_t *obj_event_filter, const bool p_any_ue_ind)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_any_ue_ind;
    typedef typename EventFilter::AnyUeIndType ValueType;

    ValueType value(value_from);

    if (!obj->setAnyUeInd(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_any_ue_ind_move(data_collection_model_event_filter_t *obj_event_filter, bool p_any_ue_ind)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_any_ue_ind;
    typedef typename EventFilter::AnyUeIndType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAnyUeInd(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_ue_ip_addr(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getUeIpAddr().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_event_filter_get_ue_ip_addr(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        const data_collection_model_ip_addr_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        const data_collection_model_ip_addr_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::UeIpAddrType ResultFromType;
    const ResultFromType &result_from = obj->getUeIpAddr();
    const data_collection_model_ip_addr_t *result = reinterpret_cast<const data_collection_model_ip_addr_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_ue_ip_addr(data_collection_model_event_filter_t *obj_event_filter, const data_collection_model_ip_addr_t* p_ue_ip_addr)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_ue_ip_addr;
    typedef typename EventFilter::UeIpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUeIpAddr(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_ue_ip_addr_move(data_collection_model_event_filter_t *obj_event_filter, data_collection_model_ip_addr_t* p_ue_ip_addr)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_ue_ip_addr;
    typedef typename EventFilter::UeIpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setUeIpAddr(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_app_ids(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getAppIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_app_ids(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::AppIdsType ResultFromType;
    const ResultFromType &result_from = obj->getAppIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_app_ids(data_collection_model_event_filter_t *obj_event_filter, const ogs_list_t* p_app_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_app_ids;
    typedef typename EventFilter::AppIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setAppIds(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_app_ids_move(data_collection_model_event_filter_t *obj_event_filter, ogs_list_t* p_app_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_app_ids;
    typedef typename EventFilter::AppIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_app_ids);
    if (!obj->setAppIds(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_app_ids(data_collection_model_event_filter_t *obj_event_filter, char* p_app_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::AppIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_app_ids;

    ValueType value(value_from);


    if (value) obj->addAppIds(value.value());
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_app_ids(data_collection_model_event_filter_t *obj_event_filter, const char* p_app_ids)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::AppIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_app_ids;
    ValueType value(value_from);

    obj->removeAppIds(value);
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_app_ids(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    obj->clearAppIds();
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_loc_area(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getLocArea().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_event_filter_get_loc_area(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::LocAreaType ResultFromType;
    const ResultFromType &result_from = obj->getLocArea();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_loc_area(data_collection_model_event_filter_t *obj_event_filter, const data_collection_model_location_area5_g_t* p_loc_area)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_loc_area;
    typedef typename EventFilter::LocAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocArea(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_loc_area_move(data_collection_model_event_filter_t *obj_event_filter, data_collection_model_location_area5_g_t* p_loc_area)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_loc_area;
    typedef typename EventFilter::LocAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setLocArea(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_coll_attrs(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getCollAttrs().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_coll_attrs(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::CollAttrsType ResultFromType;
    const ResultFromType &result_from = obj->getCollAttrs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_collective_behaviour_filter_t *item_obj = reinterpret_cast<data_collection_model_collective_behaviour_filter_t*>(item.has_value()?new std::shared_ptr<CollectiveBehaviourFilter >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_collective_behaviour_filter_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_coll_attrs(data_collection_model_event_filter_t *obj_event_filter, const ogs_list_t* p_coll_attrs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_coll_attrs;
    typedef typename EventFilter::CollAttrsType ValueType;

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

    if (!obj->setCollAttrs(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_coll_attrs_move(data_collection_model_event_filter_t *obj_event_filter, ogs_list_t* p_coll_attrs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_coll_attrs;
    typedef typename EventFilter::CollAttrsType ValueType;

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

    data_collection_list_free(p_coll_attrs);
    if (!obj->setCollAttrs(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_coll_attrs(data_collection_model_event_filter_t *obj_event_filter, data_collection_model_collective_behaviour_filter_t* p_coll_attrs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::CollAttrsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_coll_attrs;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addCollAttrs(value.value());
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_coll_attrs(data_collection_model_event_filter_t *obj_event_filter, const data_collection_model_collective_behaviour_filter_t* p_coll_attrs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::CollAttrsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_coll_attrs;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeCollAttrs(value);
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_coll_attrs(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    obj->clearCollAttrs();
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_exception_reqs(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return false;

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return false;

    return obj->getExceptionReqs().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_exception_reqs(const data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EventFilter > &obj = *reinterpret_cast<const std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EventFilter::ExceptionReqsType ResultFromType;
    const ResultFromType &result_from = obj->getExceptionReqs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_exception_t *item_obj = reinterpret_cast<data_collection_model_exception_t*>(item.has_value()?new std::shared_ptr<Exception >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_exception_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exception_reqs(data_collection_model_event_filter_t *obj_event_filter, const ogs_list_t* p_exception_reqs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_exception_reqs;
    typedef typename EventFilter::ExceptionReqsType ValueType;

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

    if (!obj->setExceptionReqs(value)) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exception_reqs_move(data_collection_model_event_filter_t *obj_event_filter, ogs_list_t* p_exception_reqs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    const auto &value_from = p_exception_reqs;
    typedef typename EventFilter::ExceptionReqsType ValueType;

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

    data_collection_list_free(p_exception_reqs);
    if (!obj->setExceptionReqs(std::move(value))) return NULL;

    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_exception_reqs(data_collection_model_event_filter_t *obj_event_filter, data_collection_model_exception_t* p_exception_reqs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::ExceptionReqsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_exception_reqs;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addExceptionReqs(value.value());
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_exception_reqs(data_collection_model_event_filter_t *obj_event_filter, const data_collection_model_exception_t* p_exception_reqs)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    typedef typename EventFilter::ExceptionReqsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_exception_reqs;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeExceptionReqs(value);
    return obj_event_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_exception_reqs(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return NULL;

    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    if (!obj) return NULL;

    obj->clearExceptionReqs();
    return obj_event_filter;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_event_filter_make_lnode(data_collection_model_event_filter_t *p_event_filter)
{
    return data_collection_lnode_create(p_event_filter, reinterpret_cast<void(*)(void*)>(data_collection_model_event_filter_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_event_filter_refcount(data_collection_model_event_filter_t *obj_event_filter)
{
    if (!obj_event_filter) return 0l;
    std::shared_ptr<EventFilter > &obj = *reinterpret_cast<std::shared_ptr<EventFilter >*>(obj_event_filter);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

