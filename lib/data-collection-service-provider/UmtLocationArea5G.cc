/**********************************************************************************************************************************
 * UmtLocationArea5G - C interface to the UmtLocationArea5G object
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

/*#include "UmtLocationArea5G.h" already included by data-collection-sp/data-collection.h */
#include "UmtLocationArea5G-internal.h"
#include "openapi/model/UmtLocationArea5G.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_create(




)
{
    return reinterpret_cast<data_collection_model_umt_location_area5_g_t*>(new std::shared_ptr<UmtLocationArea5G>(new UmtLocationArea5G(




)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_create_copy(const data_collection_model_umt_location_area5_g_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_umt_location_area5_g_t*>(new std::shared_ptr<UmtLocationArea5G >(new UmtLocationArea5G(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_create_move(data_collection_model_umt_location_area5_g_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<UmtLocationArea5G > *obj = reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_copy(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const data_collection_model_umt_location_area5_g_t *other)
{
    if (umt_location_area5_g) {
        std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(umt_location_area5_g);
        if (obj) {
            if (other) {
                const std::shared_ptr<UmtLocationArea5G > &other_obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(other);
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
                const std::shared_ptr<UmtLocationArea5G > &other_obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(other);
                if (other_obj) {
                    obj.reset(new UmtLocationArea5G(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        umt_location_area5_g = data_collection_model_umt_location_area5_g_create_copy(other);
    }
    return umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_move(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, data_collection_model_umt_location_area5_g_t *other)
{
    std::shared_ptr<UmtLocationArea5G > *other_ptr = reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(other);

    if (umt_location_area5_g) {
        std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(umt_location_area5_g);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                umt_location_area5_g = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_umt_location_area5_g_free(data_collection_model_umt_location_area5_g_t *umt_location_area5_g)
{
    if (!umt_location_area5_g) return;
    delete reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(umt_location_area5_g);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_umt_location_area5_g_toJSON(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g, bool as_request)
{
    if (!umt_location_area5_g) return NULL;
    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(umt_location_area5_g);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_umt_location_area5_g_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_umt_location_area5_g_t*>(new std::shared_ptr<UmtLocationArea5G >(new UmtLocationArea5G(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_umt_location_area5_g_is_equal_to(const data_collection_model_umt_location_area5_g_t *first, const data_collection_model_umt_location_area5_g_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<UmtLocationArea5G > &obj2 = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<UmtLocationArea5G > &obj1 = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_umt_location_area5_g_has_geographic_areas(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return false;

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return false;

    return obj->getGeographicAreas().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_umt_location_area5_g_get_geographic_areas(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename UmtLocationArea5G::GeographicAreasType ResultFromType;
    const ResultFromType &result_from = obj->getGeographicAreas();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_geographic_area_t *item_obj = reinterpret_cast<data_collection_model_geographic_area_t*>(item.has_value()?new std::shared_ptr<GeographicArea >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_geographic_area_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_geographic_areas(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, const ogs_list_t* p_geographic_areas)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_geographic_areas;
    typedef typename UmtLocationArea5G::GeographicAreasType ValueType;

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

    if (!obj->setGeographicAreas(value)) return NULL;

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_geographic_areas_move(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, ogs_list_t* p_geographic_areas)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_geographic_areas;
    typedef typename UmtLocationArea5G::GeographicAreasType ValueType;

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

    if (!obj->setGeographicAreas(std::move(value))) return NULL;
    data_collection_list_free
(p_geographic_areas);

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_add_geographic_areas(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, data_collection_model_geographic_area_t* p_geographic_areas)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    typedef typename UmtLocationArea5G::GeographicAreasType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_geographic_areas;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_geographic_area_free
(p_geographic_areas);
    if (value) obj->addGeographicAreas(value.value());
    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_remove_geographic_areas(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, const data_collection_model_geographic_area_t* p_geographic_areas)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    typedef typename UmtLocationArea5G::GeographicAreasType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_geographic_areas;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeGeographicAreas(value);
    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_umt_location_area5_g_get_entry_geographic_areas(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, size_t idx)
{
    if (!obj_umt_location_area5_g) {
        const data_collection_model_geographic_area_t *result = NULL;

        return result;
    }

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) {
        const data_collection_model_geographic_area_t *result = NULL;

        return result;
    }

    const UmtLocationArea5G::GeographicAreasType &container = obj->getGeographicAreas();
    if (!container.has_value()) {
        const data_collection_model_geographic_area_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_geographic_area_t *result = NULL;

        return result;
    }
    typedef typename UmtLocationArea5G::GeographicAreasItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_geographic_area_t *result = reinterpret_cast<const data_collection_model_geographic_area_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_clear_geographic_areas(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    obj->clearGeographicAreas();
    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_umt_location_area5_g_has_civic_addresses(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return false;

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return false;

    return obj->getCivicAddresses().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_umt_location_area5_g_get_civic_addresses(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename UmtLocationArea5G::CivicAddressesType ResultFromType;
    const ResultFromType &result_from = obj->getCivicAddresses();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_civic_address_t *item_obj = reinterpret_cast<data_collection_model_civic_address_t*>(item.has_value()?new std::shared_ptr<CivicAddress >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_civic_address_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_civic_addresses(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, const ogs_list_t* p_civic_addresses)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_civic_addresses;
    typedef typename UmtLocationArea5G::CivicAddressesType ValueType;

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

    if (!obj->setCivicAddresses(value)) return NULL;

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_civic_addresses_move(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, ogs_list_t* p_civic_addresses)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_civic_addresses;
    typedef typename UmtLocationArea5G::CivicAddressesType ValueType;

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

    if (!obj->setCivicAddresses(std::move(value))) return NULL;
    data_collection_list_free
(p_civic_addresses);

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_add_civic_addresses(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, data_collection_model_civic_address_t* p_civic_addresses)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    typedef typename UmtLocationArea5G::CivicAddressesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_civic_addresses;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_civic_address_free
(p_civic_addresses);
    if (value) obj->addCivicAddresses(value.value());
    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_remove_civic_addresses(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, const data_collection_model_civic_address_t* p_civic_addresses)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    typedef typename UmtLocationArea5G::CivicAddressesType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_civic_addresses;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeCivicAddresses(value);
    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_civic_address_t* data_collection_model_umt_location_area5_g_get_entry_civic_addresses(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, size_t idx)
{
    if (!obj_umt_location_area5_g) {
        const data_collection_model_civic_address_t *result = NULL;

        return result;
    }

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) {
        const data_collection_model_civic_address_t *result = NULL;

        return result;
    }

    const UmtLocationArea5G::CivicAddressesType &container = obj->getCivicAddresses();
    if (!container.has_value()) {
        const data_collection_model_civic_address_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_civic_address_t *result = NULL;

        return result;
    }
    typedef typename UmtLocationArea5G::CivicAddressesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_civic_address_t *result = reinterpret_cast<const data_collection_model_civic_address_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_clear_civic_addresses(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    obj->clearCivicAddresses();
    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_umt_location_area5_g_has_nw_area_info(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return false;

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return false;

    return obj->getNwAreaInfo().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_area_info_t* data_collection_model_umt_location_area5_g_get_nw_area_info(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) {
        const data_collection_model_network_area_info_t *result = NULL;
        return result;
    }

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) {
        const data_collection_model_network_area_info_t *result = NULL;
        return result;
    }

    typedef typename UmtLocationArea5G::NwAreaInfoType ResultFromType;
    const ResultFromType &result_from = obj->getNwAreaInfo();
    const data_collection_model_network_area_info_t *result = reinterpret_cast<const data_collection_model_network_area_info_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_nw_area_info(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, const data_collection_model_network_area_info_t* p_nw_area_info)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_nw_area_info;
    typedef typename UmtLocationArea5G::NwAreaInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setNwAreaInfo(value)) return NULL;

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_nw_area_info_move(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, data_collection_model_network_area_info_t* p_nw_area_info)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_nw_area_info;
    typedef typename UmtLocationArea5G::NwAreaInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setNwAreaInfo(std::move(value))) return NULL;
    data_collection_model_network_area_info_free
(p_nw_area_info);

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_umt_location_area5_g_has_umt_time(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return false;

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return false;

    return obj->getUmtTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_umt_location_area5_g_get_umt_time(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UmtLocationArea5G::UmtTimeType ResultFromType;
    const ResultFromType &result_from = obj->getUmtTime();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_time(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, const char* p_umt_time)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_umt_time;
    typedef typename UmtLocationArea5G::UmtTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setUmtTime(value)) return NULL;

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_time_move(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, char* p_umt_time)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_umt_time;
    typedef typename UmtLocationArea5G::UmtTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setUmtTime(std::move(value))) return NULL;
    ogs_free
(p_umt_time);

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_umt_location_area5_g_has_umt_duration(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return false;

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return false;

    return obj->getUmtDuration().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_umt_location_area5_g_get_umt_duration(const data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename UmtLocationArea5G::UmtDurationType ResultFromType;
    const ResultFromType &result_from = obj->getUmtDuration();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_duration(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, const int32_t p_umt_duration)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_umt_duration;
    typedef typename UmtLocationArea5G::UmtDurationType ValueType;

    ValueType value(value_from);

    if (!obj->setUmtDuration(value)) return NULL;

    return obj_umt_location_area5_g;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_duration_move(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g, int32_t p_umt_duration)
{
    if (!obj_umt_location_area5_g) return NULL;

    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    if (!obj) return NULL;

    const auto &value_from = p_umt_duration;
    typedef typename UmtLocationArea5G::UmtDurationType ValueType;

    ValueType value(value_from);

    if (!obj->setUmtDuration(std::move(value))) return NULL;

    return obj_umt_location_area5_g;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_umt_location_area5_g_make_lnode(data_collection_model_umt_location_area5_g_t *p_umt_location_area5_g)
{
    return data_collection_lnode_create(p_umt_location_area5_g, reinterpret_cast<void(*)(void*)>(data_collection_model_umt_location_area5_g_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_umt_location_area5_g_refcount(data_collection_model_umt_location_area5_g_t *obj_umt_location_area5_g)
{
    if (!obj_umt_location_area5_g) return 0l;
    std::shared_ptr<UmtLocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<UmtLocationArea5G >*>(obj_umt_location_area5_g);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

