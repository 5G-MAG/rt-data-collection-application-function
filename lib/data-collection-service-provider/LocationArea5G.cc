/**********************************************************************************************************************************
 * LocationArea5G - C interface to the LocationArea5G object
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

/*#include "LocationArea5G.h" already included by data-collection-sp/data-collection.h */
#include "LocationArea5G-internal.h"
#include "openapi/model/LocationArea5G.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_create(


)
{
    return reinterpret_cast<data_collection_model_location_area5_g_t*>(new std::shared_ptr<LocationArea5G>(new LocationArea5G(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_create_copy(const data_collection_model_location_area5_g_t *other)
{
    return reinterpret_cast<data_collection_model_location_area5_g_t*>(new std::shared_ptr<LocationArea5G >(new LocationArea5G(**reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_create_move(data_collection_model_location_area5_g_t *other)
{
    return reinterpret_cast<data_collection_model_location_area5_g_t*>(new std::shared_ptr<LocationArea5G >(std::move(*reinterpret_cast<std::shared_ptr<LocationArea5G >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_copy(data_collection_model_location_area5_g_t *location_area5_g, const data_collection_model_location_area5_g_t *other)
{
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(location_area5_g);
    *obj = **reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(other);
    return location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_move(data_collection_model_location_area5_g_t *location_area5_g, data_collection_model_location_area5_g_t *other)
{
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(location_area5_g);
    obj = std::move(*reinterpret_cast<std::shared_ptr<LocationArea5G >*>(other));
    return location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_location_area5_g_free(data_collection_model_location_area5_g_t *location_area5_g)
{
    delete reinterpret_cast<std::shared_ptr<LocationArea5G >*>(location_area5_g);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_location_area5_g_toJSON(const data_collection_model_location_area5_g_t *location_area5_g, bool as_request)
{
    const std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(location_area5_g);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_location_area5_g_t*>(new std::shared_ptr<LocationArea5G >(new LocationArea5G(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_location_area5_g_is_equal_to(const data_collection_model_location_area5_g_t *first, const data_collection_model_location_area5_g_t *second)
{
    const std::shared_ptr<LocationArea5G > &obj1 = *reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(first);
    const std::shared_ptr<LocationArea5G > &obj2 = *reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_location_area5_g_get_geographic_areas(const data_collection_model_location_area5_g_t *obj_location_area5_g)
{
    const std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    typedef typename LocationArea5G::GeographicAreasType ResultFromType;
    const ResultFromType result_from = obj->getGeographicAreas();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_geographic_area_t *item_obj = reinterpret_cast<data_collection_model_geographic_area_t*>(new std::shared_ptr<GeographicArea >(item));
        node = data_collection_model_geographic_area_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_geographic_areas(data_collection_model_location_area5_g_t *obj_location_area5_g, const ogs_list_t* p_geographic_areas)
{
    if (obj_location_area5_g == NULL) return NULL;

    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    const auto &value_from = p_geographic_areas;
    typedef typename LocationArea5G::GeographicAreasType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setGeographicAreas(value)) return NULL;
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_geographic_areas_move(data_collection_model_location_area5_g_t *obj_location_area5_g, ogs_list_t* p_geographic_areas)
{
    if (obj_location_area5_g == NULL) return NULL;

    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    const auto &value_from = p_geographic_areas;
    typedef typename LocationArea5G::GeographicAreasType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_geographic_areas);
    if (!obj->setGeographicAreas(std::move(value))) return NULL;
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_add_geographic_areas(data_collection_model_location_area5_g_t *obj_location_area5_g, data_collection_model_geographic_area_t* p_geographic_areas)
{
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    typedef typename LocationArea5G::GeographicAreasType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_geographic_areas;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addGeographicAreas(value);
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_remove_geographic_areas(data_collection_model_location_area5_g_t *obj_location_area5_g, const data_collection_model_geographic_area_t* p_geographic_areas)
{
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    typedef typename LocationArea5G::GeographicAreasType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_geographic_areas;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeGeographicAreas(value);
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_clear_geographic_areas(data_collection_model_location_area5_g_t *obj_location_area5_g)
{   
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    obj->clearGeographicAreas();
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_location_area5_g_get_civic_addresses(const data_collection_model_location_area5_g_t *obj_location_area5_g)
{
    const std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    typedef typename LocationArea5G::CivicAddressesType ResultFromType;
    const ResultFromType result_from = obj->getCivicAddresses();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_civic_address_t *item_obj = reinterpret_cast<data_collection_model_civic_address_t*>(new std::shared_ptr<CivicAddress >(item));
        node = data_collection_model_civic_address_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_civic_addresses(data_collection_model_location_area5_g_t *obj_location_area5_g, const ogs_list_t* p_civic_addresses)
{
    if (obj_location_area5_g == NULL) return NULL;

    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    const auto &value_from = p_civic_addresses;
    typedef typename LocationArea5G::CivicAddressesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setCivicAddresses(value)) return NULL;
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_civic_addresses_move(data_collection_model_location_area5_g_t *obj_location_area5_g, ogs_list_t* p_civic_addresses)
{
    if (obj_location_area5_g == NULL) return NULL;

    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    const auto &value_from = p_civic_addresses;
    typedef typename LocationArea5G::CivicAddressesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_civic_addresses);
    if (!obj->setCivicAddresses(std::move(value))) return NULL;
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_add_civic_addresses(data_collection_model_location_area5_g_t *obj_location_area5_g, data_collection_model_civic_address_t* p_civic_addresses)
{
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    typedef typename LocationArea5G::CivicAddressesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_civic_addresses;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addCivicAddresses(value);
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_remove_civic_addresses(data_collection_model_location_area5_g_t *obj_location_area5_g, const data_collection_model_civic_address_t* p_civic_addresses)
{
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    typedef typename LocationArea5G::CivicAddressesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_civic_addresses;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeCivicAddresses(value);
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_clear_civic_addresses(data_collection_model_location_area5_g_t *obj_location_area5_g)
{   
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    obj->clearCivicAddresses();
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_network_area_info_t* data_collection_model_location_area5_g_get_nw_area_info(const data_collection_model_location_area5_g_t *obj_location_area5_g)
{
    const std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<const std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    typedef typename LocationArea5G::NwAreaInfoType ResultFromType;
    const ResultFromType result_from = obj->getNwAreaInfo();
    const data_collection_model_network_area_info_t *result = reinterpret_cast<const data_collection_model_network_area_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_nw_area_info(data_collection_model_location_area5_g_t *obj_location_area5_g, const data_collection_model_network_area_info_t* p_nw_area_info)
{
    if (obj_location_area5_g == NULL) return NULL;

    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    const auto &value_from = p_nw_area_info;
    typedef typename LocationArea5G::NwAreaInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNwAreaInfo(value)) return NULL;
    return obj_location_area5_g;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_area5_g_t *data_collection_model_location_area5_g_set_nw_area_info_move(data_collection_model_location_area5_g_t *obj_location_area5_g, data_collection_model_network_area_info_t* p_nw_area_info)
{
    if (obj_location_area5_g == NULL) return NULL;

    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    const auto &value_from = p_nw_area_info;
    typedef typename LocationArea5G::NwAreaInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNwAreaInfo(std::move(value))) return NULL;
    return obj_location_area5_g;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_location_area5_g_make_lnode(data_collection_model_location_area5_g_t *p_location_area5_g)
{
    return data_collection_lnode_create(p_location_area5_g, reinterpret_cast<void(*)(void*)>(data_collection_model_location_area5_g_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_location_area5_g_refcount(data_collection_model_location_area5_g_t *obj_location_area5_g)
{
    std::shared_ptr<LocationArea5G > &obj = *reinterpret_cast<std::shared_ptr<LocationArea5G >*>(obj_location_area5_g);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

