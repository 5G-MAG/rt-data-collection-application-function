/**********************************************************************************************************************************
 * FlowInfo - C interface to the FlowInfo object
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

/*#include "FlowInfo.h" already included by data-collection-sp/data-collection.h */
#include "FlowInfo-internal.h"
#include "openapi/model/FlowInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create(


)
{
    return reinterpret_cast<data_collection_model_flow_info_t*>(new std::shared_ptr<FlowInfo>(new FlowInfo(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create_copy(const data_collection_model_flow_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_flow_info_t*>(new std::shared_ptr<FlowInfo >(new FlowInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create_move(data_collection_model_flow_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<FlowInfo > *obj = reinterpret_cast<std::shared_ptr<FlowInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_copy(data_collection_model_flow_info_t *flow_info, const data_collection_model_flow_info_t *other)
{
    if (flow_info) {
        std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(flow_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<FlowInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(other);
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
                const std::shared_ptr<FlowInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(other);
                if (other_obj) {
                    obj.reset(new FlowInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        flow_info = data_collection_model_flow_info_create_copy(other);
    }
    return flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_move(data_collection_model_flow_info_t *flow_info, data_collection_model_flow_info_t *other)
{
    std::shared_ptr<FlowInfo > *other_ptr = reinterpret_cast<std::shared_ptr<FlowInfo >*>(other);

    if (flow_info) {
        std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(flow_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                flow_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_flow_info_free(data_collection_model_flow_info_t *flow_info)
{
    if (!flow_info) return;
    delete reinterpret_cast<std::shared_ptr<FlowInfo >*>(flow_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_flow_info_toJSON(const data_collection_model_flow_info_t *flow_info, bool as_request)
{
    if (!flow_info) return NULL;
    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(flow_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_flow_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_flow_info_t*>(new std::shared_ptr<FlowInfo >(new FlowInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_info_is_equal_to(const data_collection_model_flow_info_t *first, const data_collection_model_flow_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<FlowInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<FlowInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_flow_info_get_flow_id(const data_collection_model_flow_info_t *obj_flow_info)
{
    if (!obj_flow_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename FlowInfo::FlowIdType ResultFromType;
    const ResultFromType &result_from = obj->getFlowId();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id(data_collection_model_flow_info_t *obj_flow_info, const int32_t p_flow_id)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    const auto &value_from = p_flow_id;
    typedef typename FlowInfo::FlowIdType ValueType;

    ValueType value(value_from);

    if (!obj->setFlowId(value)) return NULL;

    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id_move(data_collection_model_flow_info_t *obj_flow_info, int32_t p_flow_id)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    const auto &value_from = p_flow_id;
    typedef typename FlowInfo::FlowIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setFlowId(std::move(value))) return NULL;

    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_info_has_flow_descriptions(const data_collection_model_flow_info_t *obj_flow_info)
{
    if (!obj_flow_info) return false;

    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return false;

    return obj->getFlowDescriptions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_flow_info_get_flow_descriptions(const data_collection_model_flow_info_t *obj_flow_info)
{
    if (!obj_flow_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename FlowInfo::FlowDescriptionsType ResultFromType;
    const ResultFromType &result_from = obj->getFlowDescriptions();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info, const ogs_list_t* p_flow_descriptions)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    const auto &value_from = p_flow_descriptions;
    typedef typename FlowInfo::FlowDescriptionsType ValueType;

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

    if (!obj->setFlowDescriptions(value)) return NULL;

    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions_move(data_collection_model_flow_info_t *obj_flow_info, ogs_list_t* p_flow_descriptions)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    const auto &value_from = p_flow_descriptions;
    typedef typename FlowInfo::FlowDescriptionsType ValueType;

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

    data_collection_list_free(p_flow_descriptions);
    if (!obj->setFlowDescriptions(std::move(value))) return NULL;

    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_add_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info, char* p_flow_descriptions)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    typedef typename FlowInfo::FlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_flow_descriptions;

    ValueType value(value_from);

    ogs_free(p_flow_descriptions);

    if (value) obj->addFlowDescriptions(value.value());
    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_remove_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info, const char* p_flow_descriptions)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    typedef typename FlowInfo::FlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_flow_descriptions;
    ValueType value(value_from);

    obj->removeFlowDescriptions(value);
    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_flow_info_get_entry_flow_descriptions(const data_collection_model_flow_info_t *obj_flow_info, size_t idx)
{
    if (!obj_flow_info) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const FlowInfo::FlowDescriptionsType &container = obj->getFlowDescriptions();
    if (!container.has_value()) {
        const char *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename FlowInfo::FlowDescriptionsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_clear_flow_descriptions(data_collection_model_flow_info_t *obj_flow_info)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    obj->clearFlowDescriptions();
    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_info_has_tos_tc(const data_collection_model_flow_info_t *obj_flow_info)
{
    if (!obj_flow_info) return false;

    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return false;

    return obj->getTosTC().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_flow_info_get_tos_tc(const data_collection_model_flow_info_t *obj_flow_info)
{
    if (!obj_flow_info) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<const std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename FlowInfo::TosTCType ResultFromType;
    const ResultFromType &result_from = obj->getTosTC();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc(data_collection_model_flow_info_t *obj_flow_info, const char* p_tos_tc)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    const auto &value_from = p_tos_tc;
    typedef typename FlowInfo::TosTCType ValueType;

    ValueType value(value_from);

    if (!obj->setTosTC(value)) return NULL;

    return obj_flow_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc_move(data_collection_model_flow_info_t *obj_flow_info, char* p_tos_tc)
{
    if (!obj_flow_info) return NULL;

    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    if (!obj) return NULL;

    const auto &value_from = p_tos_tc;
    typedef typename FlowInfo::TosTCType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTosTC(std::move(value))) return NULL;

    return obj_flow_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_flow_info_make_lnode(data_collection_model_flow_info_t *p_flow_info)
{
    return data_collection_lnode_create(p_flow_info, reinterpret_cast<void(*)(void*)>(data_collection_model_flow_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_flow_info_refcount(data_collection_model_flow_info_t *obj_flow_info)
{
    if (!obj_flow_info) return 0l;
    std::shared_ptr<FlowInfo > &obj = *reinterpret_cast<std::shared_ptr<FlowInfo >*>(obj_flow_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

