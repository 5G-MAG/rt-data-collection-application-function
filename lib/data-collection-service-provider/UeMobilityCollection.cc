/**********************************************************************************************************************************
 * UeMobilityCollection - C interface to the UeMobilityCollection object
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

/*#include "UeMobilityCollection.h" already included by data-collection-sp/data-collection.h */
#include "UeMobilityCollection-internal.h"
#include "openapi/model/UeMobilityCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create(





)
{
    return reinterpret_cast<data_collection_model_ue_mobility_collection_t*>(new std::shared_ptr<UeMobilityCollection>(new UeMobilityCollection(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create_copy(const data_collection_model_ue_mobility_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ue_mobility_collection_t*>(new std::shared_ptr<UeMobilityCollection >(new UeMobilityCollection(**reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create_move(data_collection_model_ue_mobility_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ue_mobility_collection_t*>(new std::shared_ptr<UeMobilityCollection >(std::move(*reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_copy(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_ue_mobility_collection_t *other)
{
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(ue_mobility_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(other);
    return ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, data_collection_model_ue_mobility_collection_t *other)
{
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(ue_mobility_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(other));
    return ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ue_mobility_collection_free(data_collection_model_ue_mobility_collection_t *ue_mobility_collection)
{
    delete reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(ue_mobility_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ue_mobility_collection_toJSON(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, bool as_request)
{
    const std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(ue_mobility_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ue_mobility_collection_t*>(new std::shared_ptr<UeMobilityCollection >(new UeMobilityCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_ue_mobility_collection_is_equal_to(const data_collection_model_ue_mobility_collection_t *first, const data_collection_model_ue_mobility_collection_t *second)
{
    const std::shared_ptr<UeMobilityCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(first);
    const std::shared_ptr<UeMobilityCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ue_mobility_collection_get_gpsi(const data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{
    const std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::GpsiType ResultFromType;
    const ResultFromType result_from = obj->getGpsi();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_gpsi(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const char* p_gpsi)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_gpsi;
    typedef typename UeMobilityCollection::GpsiType ValueType;

    ValueType value(value_from);
    if (!obj->setGpsi(value)) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_gpsi_move(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, char* p_gpsi)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_gpsi;
    typedef typename UeMobilityCollection::GpsiType ValueType;

    ValueType value(value_from);
    
    if (!obj->setGpsi(std::move(value))) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ue_mobility_collection_get_supi(const data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{
    const std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::SupiType ResultFromType;
    const ResultFromType result_from = obj->getSupi();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_supi(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const char* p_supi)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_supi;
    typedef typename UeMobilityCollection::SupiType ValueType;

    ValueType value(value_from);
    if (!obj->setSupi(value)) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_supi_move(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, char* p_supi)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_supi;
    typedef typename UeMobilityCollection::SupiType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSupi(std::move(value))) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ue_mobility_collection_get_app_id(const data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{
    const std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_app_id(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const char* p_app_id)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_app_id;
    typedef typename UeMobilityCollection::AppIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAppId(value)) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_app_id_move(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, char* p_app_id)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_app_id;
    typedef typename UeMobilityCollection::AppIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAppId(std::move(value))) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_ue_mobility_collection_is_all_app_ind(const data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{
    const std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::AllAppIndType ResultFromType;
    const ResultFromType result_from = obj->isAllAppInd();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_all_app_ind(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const bool p_all_app_ind)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_all_app_ind;
    typedef typename UeMobilityCollection::AllAppIndType ValueType;

    ValueType value = value_from;
    if (!obj->setAllAppInd(value)) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_all_app_ind_move(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, bool p_all_app_ind)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_all_app_ind;
    typedef typename UeMobilityCollection::AllAppIndType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAllAppInd(std::move(value))) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_ue_mobility_collection_get_ue_trajs(const data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{
    const std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::UeTrajsType ResultFromType;
    const ResultFromType result_from = obj->getUeTrajs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ue_trajectory_collection_t *item_obj = reinterpret_cast<data_collection_model_ue_trajectory_collection_t*>(new std::shared_ptr<UeTrajectoryCollection >(item));
        node = data_collection_model_ue_trajectory_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_ue_trajs(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const ogs_list_t* p_ue_trajs)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_ue_trajs;
    typedef typename UeMobilityCollection::UeTrajsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setUeTrajs(value)) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_ue_trajs_move(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, ogs_list_t* p_ue_trajs)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_ue_trajs;
    typedef typename UeMobilityCollection::UeTrajsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ue_trajs);
    if (!obj->setUeTrajs(std::move(value))) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_add_ue_trajs(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, data_collection_model_ue_trajectory_collection_t* p_ue_trajs)
{
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::UeTrajsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_trajs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addUeTrajs(value);
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_remove_ue_trajs(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const data_collection_model_ue_trajectory_collection_t* p_ue_trajs)
{
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::UeTrajsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_trajs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeUeTrajs(value);
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_clear_ue_trajs(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{   
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    obj->clearUeTrajs();
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_ue_mobility_collection_get_areas(const data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{
    const std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::AreasType ResultFromType;
    const ResultFromType result_from = obj->getAreas();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_location_area5_g_t*>(new std::shared_ptr<LocationArea5G >(item));
        node = data_collection_model_location_area5_g_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_areas(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const ogs_list_t* p_areas)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_areas;
    typedef typename UeMobilityCollection::AreasType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setAreas(value)) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_areas_move(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, ogs_list_t* p_areas)
{
    if (obj_ue_mobility_collection == NULL) return NULL;

    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    const auto &value_from = p_areas;
    typedef typename UeMobilityCollection::AreasType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_areas);
    if (!obj->setAreas(std::move(value))) return NULL;
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_add_areas(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, data_collection_model_location_area5_g_t* p_areas)
{
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::AreasType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_areas;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addAreas(value);
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_remove_areas(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection, const data_collection_model_location_area5_g_t* p_areas)
{
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    typedef typename UeMobilityCollection::AreasType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_areas;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeAreas(value);
    return obj_ue_mobility_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_clear_areas(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{   
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    obj->clearAreas();
    return obj_ue_mobility_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ue_mobility_collection_make_lnode(data_collection_model_ue_mobility_collection_t *p_ue_mobility_collection)
{
    return data_collection_lnode_create(p_ue_mobility_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_ue_mobility_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ue_mobility_collection_refcount(data_collection_model_ue_mobility_collection_t *obj_ue_mobility_collection)
{
    std::shared_ptr<UeMobilityCollection > &obj = *reinterpret_cast<std::shared_ptr<UeMobilityCollection >*>(obj_ue_mobility_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

