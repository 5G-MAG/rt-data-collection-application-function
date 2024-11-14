/**********************************************************************************************************************************
 * NetworkAreaInfo - C interface to the NetworkAreaInfo object
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

/*#include "NetworkAreaInfo.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAreaInfo-internal.h"
#include "openapi/model/NetworkAreaInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create(



)
{
    return reinterpret_cast<data_collection_model_network_area_info_t*>(new std::shared_ptr<NetworkAreaInfo>(new NetworkAreaInfo(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create_ref(const data_collection_model_network_area_info_t *other)
{
    return reinterpret_cast<data_collection_model_network_area_info_t*>(new std::shared_ptr<NetworkAreaInfo>(*reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create_copy(const data_collection_model_network_area_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_network_area_info_t*>(new std::shared_ptr<NetworkAreaInfo >(new NetworkAreaInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_create_move(data_collection_model_network_area_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NetworkAreaInfo > *obj = reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_copy(data_collection_model_network_area_info_t *network_area_info, const data_collection_model_network_area_info_t *other)
{
    if (network_area_info) {
        std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(network_area_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<NetworkAreaInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(other);
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
                const std::shared_ptr<NetworkAreaInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(other);
                if (other_obj) {
                    obj.reset(new NetworkAreaInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        network_area_info = data_collection_model_network_area_info_create_copy(other);
    }
    return network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_move(data_collection_model_network_area_info_t *network_area_info, data_collection_model_network_area_info_t *other)
{
    std::shared_ptr<NetworkAreaInfo > *other_ptr = reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(other);

    if (network_area_info) {
        std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(network_area_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                network_area_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_area_info_free(data_collection_model_network_area_info_t *network_area_info)
{
    if (!network_area_info) return;
    delete reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(network_area_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_area_info_toJSON(const data_collection_model_network_area_info_t *network_area_info, bool as_request)
{
    if (!network_area_info) return NULL;
    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(network_area_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_network_area_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_area_info_t*>(new std::shared_ptr<NetworkAreaInfo >(new NetworkAreaInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_is_equal_to(const data_collection_model_network_area_info_t *first, const data_collection_model_network_area_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NetworkAreaInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NetworkAreaInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_ecgis(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return false;

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return false;

    return obj->getEcgis().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_ecgis(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAreaInfo::EcgisType ResultFromType;
    const ResultFromType &result_from = obj->getEcgis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_ecgi_t *item_obj = reinterpret_cast<data_collection_model_ecgi_t*>(item.has_value()?new std::shared_ptr<Ecgi >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_ecgi_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ecgis(data_collection_model_network_area_info_t *obj_network_area_info, const ogs_list_t* p_ecgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_ecgis;
    typedef typename NetworkAreaInfo::EcgisType ValueType;

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

    if (!obj->setEcgis(value)) return NULL;

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ecgis_move(data_collection_model_network_area_info_t *obj_network_area_info, ogs_list_t* p_ecgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_ecgis;
    typedef typename NetworkAreaInfo::EcgisType ValueType;

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

    if (!obj->setEcgis(std::move(value))) return NULL;
    data_collection_list_free
(p_ecgis);

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_ecgis(data_collection_model_network_area_info_t *obj_network_area_info, data_collection_model_ecgi_t* p_ecgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::EcgisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ecgis;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_ecgi_free
(p_ecgis);
    if (value) obj->addEcgis(value.value());
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_ecgis(data_collection_model_network_area_info_t *obj_network_area_info, const data_collection_model_ecgi_t* p_ecgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::EcgisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ecgis;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeEcgis(value);
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ecgi_t* data_collection_model_network_area_info_get_entry_ecgis(const data_collection_model_network_area_info_t *obj_network_area_info, size_t idx)
{
    if (!obj_network_area_info) {
        const data_collection_model_ecgi_t *result = NULL;

        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        const data_collection_model_ecgi_t *result = NULL;

        return result;
    }

    const NetworkAreaInfo::EcgisType &container = obj->getEcgis();
    if (!container.has_value()) {
        const data_collection_model_ecgi_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_ecgi_t *result = NULL;

        return result;
    }
    typedef typename NetworkAreaInfo::EcgisItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_ecgi_t *result = reinterpret_cast<const data_collection_model_ecgi_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_ecgis(data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    obj->clearEcgis();
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_ncgis(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return false;

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return false;

    return obj->getNcgis().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_ncgis(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAreaInfo::NcgisType ResultFromType;
    const ResultFromType &result_from = obj->getNcgis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_ncgi_t *item_obj = reinterpret_cast<data_collection_model_ncgi_t*>(item.has_value()?new std::shared_ptr<Ncgi >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_ncgi_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ncgis(data_collection_model_network_area_info_t *obj_network_area_info, const ogs_list_t* p_ncgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_ncgis;
    typedef typename NetworkAreaInfo::NcgisType ValueType;

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

    if (!obj->setNcgis(value)) return NULL;

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_ncgis_move(data_collection_model_network_area_info_t *obj_network_area_info, ogs_list_t* p_ncgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_ncgis;
    typedef typename NetworkAreaInfo::NcgisType ValueType;

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

    if (!obj->setNcgis(std::move(value))) return NULL;
    data_collection_list_free
(p_ncgis);

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_ncgis(data_collection_model_network_area_info_t *obj_network_area_info, data_collection_model_ncgi_t* p_ncgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::NcgisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ncgis;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_ncgi_free
(p_ncgis);
    if (value) obj->addNcgis(value.value());
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_ncgis(data_collection_model_network_area_info_t *obj_network_area_info, const data_collection_model_ncgi_t* p_ncgis)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::NcgisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ncgis;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeNcgis(value);
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ncgi_t* data_collection_model_network_area_info_get_entry_ncgis(const data_collection_model_network_area_info_t *obj_network_area_info, size_t idx)
{
    if (!obj_network_area_info) {
        const data_collection_model_ncgi_t *result = NULL;

        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        const data_collection_model_ncgi_t *result = NULL;

        return result;
    }

    const NetworkAreaInfo::NcgisType &container = obj->getNcgis();
    if (!container.has_value()) {
        const data_collection_model_ncgi_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_ncgi_t *result = NULL;

        return result;
    }
    typedef typename NetworkAreaInfo::NcgisItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_ncgi_t *result = reinterpret_cast<const data_collection_model_ncgi_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_ncgis(data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    obj->clearNcgis();
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_g_ran_node_ids(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return false;

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return false;

    return obj->getGRanNodeIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_g_ran_node_ids(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAreaInfo::GRanNodeIdsType ResultFromType;
    const ResultFromType &result_from = obj->getGRanNodeIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_global_ran_node_id_t *item_obj = reinterpret_cast<data_collection_model_global_ran_node_id_t*>(item.has_value()?new std::shared_ptr<GlobalRanNodeId >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_global_ran_node_id_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_g_ran_node_ids(data_collection_model_network_area_info_t *obj_network_area_info, const ogs_list_t* p_g_ran_node_ids)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_g_ran_node_ids;
    typedef typename NetworkAreaInfo::GRanNodeIdsType ValueType;

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

    if (!obj->setGRanNodeIds(value)) return NULL;

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_g_ran_node_ids_move(data_collection_model_network_area_info_t *obj_network_area_info, ogs_list_t* p_g_ran_node_ids)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_g_ran_node_ids;
    typedef typename NetworkAreaInfo::GRanNodeIdsType ValueType;

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

    if (!obj->setGRanNodeIds(std::move(value))) return NULL;
    data_collection_list_free
(p_g_ran_node_ids);

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_g_ran_node_ids(data_collection_model_network_area_info_t *obj_network_area_info, data_collection_model_global_ran_node_id_t* p_g_ran_node_ids)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::GRanNodeIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_g_ran_node_ids;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_global_ran_node_id_free
(p_g_ran_node_ids);
    if (value) obj->addGRanNodeIds(value.value());
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_g_ran_node_ids(data_collection_model_network_area_info_t *obj_network_area_info, const data_collection_model_global_ran_node_id_t* p_g_ran_node_ids)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::GRanNodeIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_g_ran_node_ids;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeGRanNodeIds(value);
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_global_ran_node_id_t* data_collection_model_network_area_info_get_entry_g_ran_node_ids(const data_collection_model_network_area_info_t *obj_network_area_info, size_t idx)
{
    if (!obj_network_area_info) {
        const data_collection_model_global_ran_node_id_t *result = NULL;

        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        const data_collection_model_global_ran_node_id_t *result = NULL;

        return result;
    }

    const NetworkAreaInfo::GRanNodeIdsType &container = obj->getGRanNodeIds();
    if (!container.has_value()) {
        const data_collection_model_global_ran_node_id_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_global_ran_node_id_t *result = NULL;

        return result;
    }
    typedef typename NetworkAreaInfo::GRanNodeIdsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_global_ran_node_id_t *result = reinterpret_cast<const data_collection_model_global_ran_node_id_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_g_ran_node_ids(data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    obj->clearGRanNodeIds();
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_area_info_has_tais(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return false;

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return false;

    return obj->getTais().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_area_info_get_tais(const data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAreaInfo::TaisType ResultFromType;
    const ResultFromType &result_from = obj->getTais();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_tai_t *item_obj = reinterpret_cast<data_collection_model_tai_t*>(item.has_value()?new std::shared_ptr<Tai >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_tai_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_tais(data_collection_model_network_area_info_t *obj_network_area_info, const ogs_list_t* p_tais)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_tais;
    typedef typename NetworkAreaInfo::TaisType ValueType;

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

    if (!obj->setTais(value)) return NULL;

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_set_tais_move(data_collection_model_network_area_info_t *obj_network_area_info, ogs_list_t* p_tais)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    const auto &value_from = p_tais;
    typedef typename NetworkAreaInfo::TaisType ValueType;

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

    if (!obj->setTais(std::move(value))) return NULL;
    data_collection_list_free
(p_tais);

    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_add_tais(data_collection_model_network_area_info_t *obj_network_area_info, data_collection_model_tai_t* p_tais)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::TaisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_tais;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_tai_free
(p_tais);
    if (value) obj->addTais(value.value());
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_remove_tais(data_collection_model_network_area_info_t *obj_network_area_info, const data_collection_model_tai_t* p_tais)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    typedef typename NetworkAreaInfo::TaisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_tais;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeTais(value);
    return obj_network_area_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_tai_t* data_collection_model_network_area_info_get_entry_tais(const data_collection_model_network_area_info_t *obj_network_area_info, size_t idx)
{
    if (!obj_network_area_info) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }

    const std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }

    const NetworkAreaInfo::TaisType &container = obj->getTais();
    if (!container.has_value()) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }
    typedef typename NetworkAreaInfo::TaisItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_tai_t *result = reinterpret_cast<const data_collection_model_tai_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_area_info_t *data_collection_model_network_area_info_clear_tais(data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return NULL;

    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    if (!obj) return NULL;

    obj->clearTais();
    return obj_network_area_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_area_info_make_lnode(data_collection_model_network_area_info_t *p_network_area_info)
{
    return data_collection_lnode_create(p_network_area_info, reinterpret_cast<void(*)(void*)>(data_collection_model_network_area_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_area_info_refcount(data_collection_model_network_area_info_t *obj_network_area_info)
{
    if (!obj_network_area_info) return 0l;
    std::shared_ptr<NetworkAreaInfo > &obj = *reinterpret_cast<std::shared_ptr<NetworkAreaInfo >*>(obj_network_area_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

