/**********************************************************************************************************************************
 * DataAccessProfile_locationAccessRestrictions - C interface to the DataAccessProfile_locationAccessRestrictions object
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

/*#include "DataAccessProfile_locationAccessRestrictions.h" already included by data-collection-sp/data-collection.h */
#include "DataAccessProfile_locationAccessRestrictions-internal.h"
#include "openapi/model/DataAccessProfile_locationAccessRestrictions.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_create(

)
{
    return reinterpret_cast<data_collection_model_data_access_profile_location_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_locationAccessRestrictions>(new DataAccessProfile_locationAccessRestrictions(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_create_copy(const data_collection_model_data_access_profile_location_access_restrictions_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_location_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_locationAccessRestrictions >(new DataAccessProfile_locationAccessRestrictions(**reinterpret_cast<const std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_create_move(data_collection_model_data_access_profile_location_access_restrictions_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_location_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_locationAccessRestrictions >(std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_copy(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, const data_collection_model_data_access_profile_location_access_restrictions_t *other)
{
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(data_access_profile_location_access_restrictions);
    *obj = **reinterpret_cast<const std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(other);
    return data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_move(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, data_collection_model_data_access_profile_location_access_restrictions_t *other)
{
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(data_access_profile_location_access_restrictions);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(other));
    return data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_access_profile_location_access_restrictions_free(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions)
{
    delete reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(data_access_profile_location_access_restrictions);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_access_profile_location_access_restrictions_toJSON(const data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, bool as_request)
{
    const std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(data_access_profile_location_access_restrictions);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_access_profile_location_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_locationAccessRestrictions >(new DataAccessProfile_locationAccessRestrictions(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_access_profile_location_access_restrictions_is_equal_to(const data_collection_model_data_access_profile_location_access_restrictions_t *first, const data_collection_model_data_access_profile_location_access_restrictions_t *second)
{
    const std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj1 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(first);
    const std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj2 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_access_profile_location_access_restrictions_get_location_areas(const data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions)
{
    const std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    typedef typename DataAccessProfile_locationAccessRestrictions::LocationAreasType ResultFromType;
    const ResultFromType result_from = obj->getLocationAreas();
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, const ogs_list_t* p_location_areas)
{
    if (obj_data_access_profile_location_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    const auto &value_from = p_location_areas;
    typedef typename DataAccessProfile_locationAccessRestrictions::LocationAreasType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setLocationAreas(value)) return NULL;
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_location_areas_move(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, ogs_list_t* p_location_areas)
{
    if (obj_data_access_profile_location_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    const auto &value_from = p_location_areas;
    typedef typename DataAccessProfile_locationAccessRestrictions::LocationAreasType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_location_areas);
    if (!obj->setLocationAreas(std::move(value))) return NULL;
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_add_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, data_collection_model_location_area5_g_t* p_location_areas)
{
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    typedef typename DataAccessProfile_locationAccessRestrictions::LocationAreasType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_location_areas;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addLocationAreas(value);
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_remove_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, const data_collection_model_location_area5_g_t* p_location_areas)
{
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    typedef typename DataAccessProfile_locationAccessRestrictions::LocationAreasType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_location_areas;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeLocationAreas(value);
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_clear_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions)
{   
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    obj->clearLocationAreas();
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_access_profile_location_access_restrictions_get_aggregation_functions(const data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions)
{
    const std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    typedef typename DataAccessProfile_locationAccessRestrictions::AggregationFunctionsType ResultFromType;
    const ResultFromType result_from = obj->getAggregationFunctions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_aggregation_function_type_t *item_obj = reinterpret_cast<data_collection_model_data_aggregation_function_type_t*>(new std::shared_ptr<DataAggregationFunctionType >(item));
        node = data_collection_model_data_aggregation_function_type_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, const ogs_list_t* p_aggregation_functions)
{
    if (obj_data_access_profile_location_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    const auto &value_from = p_aggregation_functions;
    typedef typename DataAccessProfile_locationAccessRestrictions::AggregationFunctionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setAggregationFunctions(value)) return NULL;
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_aggregation_functions_move(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, ogs_list_t* p_aggregation_functions)
{
    if (obj_data_access_profile_location_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    const auto &value_from = p_aggregation_functions;
    typedef typename DataAccessProfile_locationAccessRestrictions::AggregationFunctionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_aggregation_functions);
    if (!obj->setAggregationFunctions(std::move(value))) return NULL;
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_add_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, data_collection_model_data_aggregation_function_type_t* p_aggregation_functions)
{
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    typedef typename DataAccessProfile_locationAccessRestrictions::AggregationFunctionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_aggregation_functions;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addAggregationFunctions(value);
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_remove_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions, const data_collection_model_data_aggregation_function_type_t* p_aggregation_functions)
{
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    typedef typename DataAccessProfile_locationAccessRestrictions::AggregationFunctionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_aggregation_functions;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeAggregationFunctions(value);
    return obj_data_access_profile_location_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_clear_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions)
{   
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    obj->clearAggregationFunctions();
    return obj_data_access_profile_location_access_restrictions;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_access_profile_location_access_restrictions_make_lnode(data_collection_model_data_access_profile_location_access_restrictions_t *p_data_access_profile_location_access_restrictions)
{
    return data_collection_lnode_create(p_data_access_profile_location_access_restrictions, reinterpret_cast<void(*)(void*)>(data_collection_model_data_access_profile_location_access_restrictions_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_access_profile_location_access_restrictions_refcount(data_collection_model_data_access_profile_location_access_restrictions_t *obj_data_access_profile_location_access_restrictions)
{
    std::shared_ptr<DataAccessProfile_locationAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_locationAccessRestrictions >*>(obj_data_access_profile_location_access_restrictions);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

