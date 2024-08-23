/**********************************************************************************************************************************
 * PerformanceDataCollection - C interface to the PerformanceDataCollection object
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

/*#include "PerformanceDataCollection.h" already included by data-collection-sp/data-collection.h */
#include "PerformanceDataCollection-internal.h"
#include "openapi/model/PerformanceDataCollection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create(







)
{
    return reinterpret_cast<data_collection_model_performance_data_collection_t*>(new std::shared_ptr<PerformanceDataCollection>(new PerformanceDataCollection(







)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create_copy(const data_collection_model_performance_data_collection_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_performance_data_collection_t*>(new std::shared_ptr<PerformanceDataCollection >(new PerformanceDataCollection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_create_move(data_collection_model_performance_data_collection_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PerformanceDataCollection > *obj = reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_copy(data_collection_model_performance_data_collection_t *performance_data_collection, const data_collection_model_performance_data_collection_t *other)
{
    if (performance_data_collection) {
        std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(performance_data_collection);
        if (obj) {
            if (other) {
                const std::shared_ptr<PerformanceDataCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(other);
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
                const std::shared_ptr<PerformanceDataCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(other);
                if (other_obj) {
                    obj.reset(new PerformanceDataCollection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        performance_data_collection = data_collection_model_performance_data_collection_create_copy(other);
    }
    return performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_move(data_collection_model_performance_data_collection_t *performance_data_collection, data_collection_model_performance_data_collection_t *other)
{
    std::shared_ptr<PerformanceDataCollection > *other_ptr = reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(other);

    if (performance_data_collection) {
        std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(performance_data_collection);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                performance_data_collection = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_collection_free(data_collection_model_performance_data_collection_t *performance_data_collection)
{
    if (!performance_data_collection) return;
    delete reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(performance_data_collection);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_collection_toJSON(const data_collection_model_performance_data_collection_t *performance_data_collection, bool as_request)
{
    if (!performance_data_collection) return NULL;
    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(performance_data_collection);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_performance_data_collection_t*>(new std::shared_ptr<PerformanceDataCollection >(new PerformanceDataCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_is_equal_to(const data_collection_model_performance_data_collection_t *first, const data_collection_model_performance_data_collection_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PerformanceDataCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PerformanceDataCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_app_id(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return false;

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return false;

    return obj->getAppId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_collection_get_app_id(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_id(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const char* p_app_id)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename PerformanceDataCollection::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_id_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, char* p_app_id)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename PerformanceDataCollection::AppIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAppId(std::move(value))) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ue_ip_addr(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return false;

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return false;

    return obj->getUeIpAddr().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_performance_data_collection_get_ue_ip_addr(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        const data_collection_model_ip_addr_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        const data_collection_model_ip_addr_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::UeIpAddrType ResultFromType;
    const ResultFromType result_from = obj->getUeIpAddr();
    const data_collection_model_ip_addr_t *result = reinterpret_cast<const data_collection_model_ip_addr_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_ip_addr(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const data_collection_model_ip_addr_t* p_ue_ip_addr)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ue_ip_addr;
    typedef typename PerformanceDataCollection::UeIpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUeIpAddr(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_ip_addr_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, data_collection_model_ip_addr_t* p_ue_ip_addr)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ue_ip_addr;
    typedef typename PerformanceDataCollection::UeIpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setUeIpAddr(std::move(value))) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ip_traffic_filter(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return false;

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return false;

    return obj->getIpTrafficFilter().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_performance_data_collection_get_ip_traffic_filter(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        const data_collection_model_flow_info_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        const data_collection_model_flow_info_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::IpTrafficFilterType ResultFromType;
    const ResultFromType result_from = obj->getIpTrafficFilter();
    const data_collection_model_flow_info_t *result = reinterpret_cast<const data_collection_model_flow_info_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ip_traffic_filter(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ip_traffic_filter;
    typedef typename PerformanceDataCollection::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setIpTrafficFilter(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ip_traffic_filter_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ip_traffic_filter;
    typedef typename PerformanceDataCollection::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setIpTrafficFilter(std::move(value))) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_ue_loc(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return false;

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return false;

    return obj->getUeLoc().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_performance_data_collection_get_ue_loc(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::UeLocType ResultFromType;
    const ResultFromType result_from = obj->getUeLoc();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_loc(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const data_collection_model_location_area5_g_t* p_ue_loc)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ue_loc;
    typedef typename PerformanceDataCollection::UeLocType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUeLoc(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_ue_loc_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, data_collection_model_location_area5_g_t* p_ue_loc)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ue_loc;
    typedef typename PerformanceDataCollection::UeLocType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setUeLoc(std::move(value))) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_app_locs(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return false;

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return false;

    return obj->getAppLocs().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_performance_data_collection_get_app_locs(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::AppLocsType ResultFromType;
    const ResultFromType result_from = obj->getAppLocs();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_locs(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const ogs_list_t* p_app_locs)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_locs;
    typedef typename PerformanceDataCollection::AppLocsType ValueType;

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

    if (!obj->setAppLocs(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_app_locs_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, ogs_list_t* p_app_locs)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_locs;
    typedef typename PerformanceDataCollection::AppLocsType ValueType;

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

    data_collection_list_free(p_app_locs);
    if (!obj->setAppLocs(std::move(value))) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_add_app_locs(data_collection_model_performance_data_collection_t *obj_performance_data_collection, char* p_app_locs)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    typedef typename PerformanceDataCollection::AppLocsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_app_locs;

    ValueType value(value_from);


    if (value) obj->addAppLocs(value.value());
    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_remove_app_locs(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const char* p_app_locs)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    typedef typename PerformanceDataCollection::AppLocsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_app_locs;
    ValueType value(value_from);

    obj->removeAppLocs(value);
    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_clear_app_locs(data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    obj->clearAppLocs();
    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_collection_has_as_addr(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return false;

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return false;

    return obj->getAsAddr().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_performance_data_collection_get_as_addr(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::AsAddrType ResultFromType;
    const ResultFromType result_from = obj->getAsAddr();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_as_addr(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const data_collection_model_addr_fqdn_t* p_as_addr)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_as_addr;
    typedef typename PerformanceDataCollection::AsAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setAsAddr(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_as_addr_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, data_collection_model_addr_fqdn_t* p_as_addr)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_as_addr;
    typedef typename PerformanceDataCollection::AsAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setAsAddr(std::move(value))) return NULL;

    return obj_performance_data_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_performance_data_t* data_collection_model_performance_data_collection_get_perf_data(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        const data_collection_model_performance_data_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        const data_collection_model_performance_data_t *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::PerfDataType ResultFromType;
    const ResultFromType result_from = obj->getPerfData();
    const data_collection_model_performance_data_t *result = reinterpret_cast<const data_collection_model_performance_data_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_perf_data(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const data_collection_model_performance_data_t* p_perf_data)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_perf_data;
    typedef typename PerformanceDataCollection::PerfDataType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPerfData(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_perf_data_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, data_collection_model_performance_data_t* p_perf_data)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_perf_data;
    typedef typename PerformanceDataCollection::PerfDataType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setPerfData(std::move(value))) return NULL;

    return obj_performance_data_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_collection_get_time_stamp(const data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceDataCollection::TimeStampType ResultFromType;
    const ResultFromType result_from = obj->getTimeStamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_time_stamp(data_collection_model_performance_data_collection_t *obj_performance_data_collection, const char* p_time_stamp)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_time_stamp;
    typedef typename PerformanceDataCollection::TimeStampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimeStamp(value)) return NULL;

    return obj_performance_data_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_collection_t *data_collection_model_performance_data_collection_set_time_stamp_move(data_collection_model_performance_data_collection_t *obj_performance_data_collection, char* p_time_stamp)
{
    if (!obj_performance_data_collection) return NULL;

    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    if (!obj) return NULL;

    const auto &value_from = p_time_stamp;
    typedef typename PerformanceDataCollection::TimeStampType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTimeStamp(std::move(value))) return NULL;

    return obj_performance_data_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_collection_make_lnode(data_collection_model_performance_data_collection_t *p_performance_data_collection)
{
    return data_collection_lnode_create(p_performance_data_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_performance_data_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_performance_data_collection_refcount(data_collection_model_performance_data_collection_t *obj_performance_data_collection)
{
    if (!obj_performance_data_collection) return 0l;
    std::shared_ptr<PerformanceDataCollection > &obj = *reinterpret_cast<std::shared_ptr<PerformanceDataCollection >*>(obj_performance_data_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

