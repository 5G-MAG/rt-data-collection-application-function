/**********************************************************************************************************************************
 * CollectiveBehaviourInfo - C interface to the CollectiveBehaviourInfo object
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

/*#include "CollectiveBehaviourInfo.h" already included by data-collection-sp/data-collection.h */
#include "CollectiveBehaviourInfo-internal.h"
#include "openapi/model/CollectiveBehaviourInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create(









)
{
    return reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo>(new CollectiveBehaviourInfo(









)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_copy(const data_collection_model_collective_behaviour_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo >(new CollectiveBehaviourInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_create_move(data_collection_model_collective_behaviour_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > *obj = reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_copy(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, const data_collection_model_collective_behaviour_info_t *other)
{
    if (collective_behaviour_info) {
        std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<CollectiveBehaviourInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(other);
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
                const std::shared_ptr<CollectiveBehaviourInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(other);
                if (other_obj) {
                    obj.reset(new CollectiveBehaviourInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        collective_behaviour_info = data_collection_model_collective_behaviour_info_create_copy(other);
    }
    return collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_move(data_collection_model_collective_behaviour_info_t *collective_behaviour_info, data_collection_model_collective_behaviour_info_t *other)
{
    std::shared_ptr<CollectiveBehaviourInfo > *other_ptr = reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(other);

    if (collective_behaviour_info) {
        std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                collective_behaviour_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_collective_behaviour_info_free(data_collection_model_collective_behaviour_info_t *collective_behaviour_info)
{
    if (!collective_behaviour_info) return;
    delete reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_collective_behaviour_info_toJSON(const data_collection_model_collective_behaviour_info_t *collective_behaviour_info, bool as_request)
{
    if (!collective_behaviour_info) return NULL;
    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(collective_behaviour_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_collective_behaviour_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo >(new CollectiveBehaviourInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_is_equal_to(const data_collection_model_collective_behaviour_info_t *first, const data_collection_model_collective_behaviour_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CollectiveBehaviourInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CollectiveBehaviourInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_col_attrib(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getColAttrib().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_col_attrib(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::ColAttribType ResultFromType;
    const ResultFromType &result_from = obj->getColAttrib();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_per_ue_attribute_t *item_obj = reinterpret_cast<data_collection_model_per_ue_attribute_t*>(item.has_value()?new std::shared_ptr<PerUeAttribute >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_per_ue_attribute_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_col_attrib)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_col_attrib;
    typedef typename CollectiveBehaviourInfo::ColAttribType ValueType;

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

    if (!obj->setColAttrib(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_col_attrib_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_col_attrib)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_col_attrib;
    typedef typename CollectiveBehaviourInfo::ColAttribType ValueType;

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

    data_collection_list_free(p_col_attrib);
    if (!obj->setColAttrib(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_per_ue_attribute_t* p_col_attrib)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::ColAttribType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_col_attrib;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addColAttrib(value.value());
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_per_ue_attribute_t* p_col_attrib)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::ColAttribType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_col_attrib;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeColAttrib(value);
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_col_attrib(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    obj->clearColAttrib();
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_no_of_ues(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getNoOfUes().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_no_of_ues(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::NoOfUesType ResultFromType;
    const ResultFromType &result_from = obj->getNoOfUes();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const int32_t p_no_of_ues)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_no_of_ues;
    typedef typename CollectiveBehaviourInfo::NoOfUesType ValueType;

    ValueType value(value_from);

    if (!obj->setNoOfUes(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_no_of_ues_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, int32_t p_no_of_ues)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_no_of_ues;
    typedef typename CollectiveBehaviourInfo::NoOfUesType ValueType;

    ValueType value(value_from);

    
    if (!obj->setNoOfUes(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_app_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getAppIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_app_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::AppIdsType ResultFromType;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_app_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_app_ids;
    typedef typename CollectiveBehaviourInfo::AppIdsType ValueType;

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

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_app_ids_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_app_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_app_ids;
    typedef typename CollectiveBehaviourInfo::AppIdsType ValueType;

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

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, char* p_app_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::AppIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_app_ids;

    ValueType value(value_from);

    ogs_free(p_app_ids);

    if (value) obj->addAppIds(value.value());
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const char* p_app_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::AppIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_app_ids;
    ValueType value(value_from);

    obj->removeAppIds(value);
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_app_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    obj->clearAppIds();
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getExtUeIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_ext_ue_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ResultFromType;
    const ResultFromType &result_from = obj->getExtUeIds();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_ext_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_ext_ue_ids;
    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ValueType;

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

    if (!obj->setExtUeIds(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ext_ue_ids_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_ext_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_ext_ue_ids;
    typedef typename CollectiveBehaviourInfo::ExtUeIdsType ValueType;

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

    data_collection_list_free(p_ext_ue_ids);
    if (!obj->setExtUeIds(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, char* p_ext_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::ExtUeIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ext_ue_ids;

    ValueType value(value_from);

    ogs_free(p_ext_ue_ids);

    if (value) obj->addExtUeIds(value.value());
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const char* p_ext_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::ExtUeIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ext_ue_ids;
    ValueType value(value_from);

    obj->removeExtUeIds(value);
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ext_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    obj->clearExtUeIds();
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ue_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getUeIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_ue_ids(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::UeIdsType ResultFromType;
    const ResultFromType &result_from = obj->getUeIds();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_ue_ids;
    typedef typename CollectiveBehaviourInfo::UeIdsType ValueType;

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

    if (!obj->setUeIds(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_ids_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_ue_ids;
    typedef typename CollectiveBehaviourInfo::UeIdsType ValueType;

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

    data_collection_list_free(p_ue_ids);
    if (!obj->setUeIds(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, char* p_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::UeIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_ids;

    ValueType value(value_from);

    ogs_free(p_ue_ids);

    if (value) obj->addUeIds(value.value());
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const char* p_ue_ids)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::UeIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_ids;
    ValueType value(value_from);

    obj->removeUeIds(value);
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_ue_ids(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    obj->clearUeIds();
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_collision_dist(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getCollisionDist().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_collision_dist(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::CollisionDistType ResultFromType;
    const ResultFromType &result_from = obj->getCollisionDist();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const int32_t p_collision_dist)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_collision_dist;
    typedef typename CollectiveBehaviourInfo::CollisionDistType ValueType;

    ValueType value(value_from);

    if (!obj->setCollisionDist(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_collision_dist_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, int32_t p_collision_dist)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_collision_dist;
    typedef typename CollectiveBehaviourInfo::CollisionDistType ValueType;

    ValueType value(value_from);

    
    if (!obj->setCollisionDist(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_abs_dirs(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getAbsDirs().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_abs_dirs(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::AbsDirsType ResultFromType;
    const ResultFromType &result_from = obj->getAbsDirs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_direction_t *item_obj = reinterpret_cast<data_collection_model_direction_t*>(item.has_value()?new std::shared_ptr<Direction >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_direction_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_abs_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_abs_dirs;
    typedef typename CollectiveBehaviourInfo::AbsDirsType ValueType;

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

    if (!obj->setAbsDirs(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_abs_dirs_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_abs_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_abs_dirs;
    typedef typename CollectiveBehaviourInfo::AbsDirsType ValueType;

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

    data_collection_list_free(p_abs_dirs);
    if (!obj->setAbsDirs(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_direction_t* p_abs_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::AbsDirsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_abs_dirs;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addAbsDirs(value.value());
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_direction_t* p_abs_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::AbsDirsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_abs_dirs;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeAbsDirs(value);
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_abs_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    obj->clearAbsDirs();
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_rel_dirs(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getRelDirs().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_info_get_rel_dirs(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::RelDirsType ResultFromType;
    const ResultFromType &result_from = obj->getRelDirs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_relative_direction_t *item_obj = reinterpret_cast<data_collection_model_relative_direction_t*>(item.has_value()?new std::shared_ptr<RelativeDirection >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_relative_direction_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const ogs_list_t* p_rel_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_rel_dirs;
    typedef typename CollectiveBehaviourInfo::RelDirsType ValueType;

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

    if (!obj->setRelDirs(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_rel_dirs_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, ogs_list_t* p_rel_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_rel_dirs;
    typedef typename CollectiveBehaviourInfo::RelDirsType ValueType;

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

    data_collection_list_free(p_rel_dirs);
    if (!obj->setRelDirs(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_add_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_relative_direction_t* p_rel_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::RelDirsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_rel_dirs;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addRelDirs(value.value());
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_remove_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_relative_direction_t* p_rel_dirs)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourInfo::RelDirsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_rel_dirs;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeRelDirs(value);
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_clear_rel_dirs(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    obj->clearRelDirs();
    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_ue_trajectory(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getUeTrajectory().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_trajectory_collection_t* data_collection_model_collective_behaviour_info_get_ue_trajectory(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        const data_collection_model_ue_trajectory_collection_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        const data_collection_model_ue_trajectory_collection_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::UeTrajectoryType ResultFromType;
    const ResultFromType &result_from = obj->getUeTrajectory();
    const data_collection_model_ue_trajectory_collection_t *result = reinterpret_cast<const data_collection_model_ue_trajectory_collection_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const data_collection_model_ue_trajectory_collection_t* p_ue_trajectory)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_ue_trajectory;
    typedef typename CollectiveBehaviourInfo::UeTrajectoryType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUeTrajectory(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_ue_trajectory_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, data_collection_model_ue_trajectory_collection_t* p_ue_trajectory)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_ue_trajectory;
    typedef typename CollectiveBehaviourInfo::UeTrajectoryType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setUeTrajectory(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_info_has_confidence(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return false;

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return false;

    return obj->getConfidence().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_collective_behaviour_info_get_confidence(const data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename CollectiveBehaviourInfo::ConfidenceType ResultFromType;
    const ResultFromType &result_from = obj->getConfidence();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, const int32_t p_confidence)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename CollectiveBehaviourInfo::ConfidenceType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidence(value)) return NULL;

    return obj_collective_behaviour_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_info_t *data_collection_model_collective_behaviour_info_set_confidence_move(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info, int32_t p_confidence)
{
    if (!obj_collective_behaviour_info) return NULL;

    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    if (!obj) return NULL;

    const auto &value_from = p_confidence;
    typedef typename CollectiveBehaviourInfo::ConfidenceType ValueType;

    ValueType value(value_from);

    
    if (!obj->setConfidence(std::move(value))) return NULL;

    return obj_collective_behaviour_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_collective_behaviour_info_make_lnode(data_collection_model_collective_behaviour_info_t *p_collective_behaviour_info)
{
    return data_collection_lnode_create(p_collective_behaviour_info, reinterpret_cast<void(*)(void*)>(data_collection_model_collective_behaviour_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_collective_behaviour_info_refcount(data_collection_model_collective_behaviour_info_t *obj_collective_behaviour_info)
{
    if (!obj_collective_behaviour_info) return 0l;
    std::shared_ptr<CollectiveBehaviourInfo > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourInfo >*>(obj_collective_behaviour_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

