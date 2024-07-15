/**********************************************************************************************************************************
 * DataAccessProfile_userAccessRestrictions - C interface to the DataAccessProfile_userAccessRestrictions object
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

/*#include "DataAccessProfile_userAccessRestrictions.h" already included by data-collection-sp/data-collection.h */
#include "DataAccessProfile_userAccessRestrictions-internal.h"
#include "openapi/model/DataAccessProfile_userAccessRestrictions.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_create(


)
{
    return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions>(new DataAccessProfile_userAccessRestrictions(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_create_copy(const data_collection_model_data_access_profile_user_access_restrictions_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions >(new DataAccessProfile_userAccessRestrictions(**reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_create_move(data_collection_model_data_access_profile_user_access_restrictions_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions >(std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_copy(data_collection_model_data_access_profile_user_access_restrictions_t *data_access_profile_user_access_restrictions, const data_collection_model_data_access_profile_user_access_restrictions_t *other)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(data_access_profile_user_access_restrictions);
    *obj = **reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(other);
    return data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_move(data_collection_model_data_access_profile_user_access_restrictions_t *data_access_profile_user_access_restrictions, data_collection_model_data_access_profile_user_access_restrictions_t *other)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(data_access_profile_user_access_restrictions);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(other));
    return data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_access_profile_user_access_restrictions_free(data_collection_model_data_access_profile_user_access_restrictions_t *data_access_profile_user_access_restrictions)
{
    delete reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(data_access_profile_user_access_restrictions);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_access_profile_user_access_restrictions_toJSON(const data_collection_model_data_access_profile_user_access_restrictions_t *data_access_profile_user_access_restrictions, bool as_request)
{
    const std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(data_access_profile_user_access_restrictions);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions >(new DataAccessProfile_userAccessRestrictions(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_access_profile_user_access_restrictions_get_group_ids(const data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions)
{
    const std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::GroupIdsType ResultFromType;
    const ResultFromType result_from = obj->getGroupIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_set_group_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, const ogs_list_t* p_group_ids)
{
    if (obj_data_access_profile_user_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    const auto &value_from = p_group_ids;
    typedef typename DataAccessProfile_userAccessRestrictions::GroupIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setGroupIds(value)) return NULL;
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_set_group_ids_move(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, ogs_list_t* p_group_ids)
{
    if (obj_data_access_profile_user_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    const auto &value_from = p_group_ids;
    typedef typename DataAccessProfile_userAccessRestrictions::GroupIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_group_ids);
    if (!obj->setGroupIds(std::move(value))) return NULL;
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_add_group_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, char* p_group_ids)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::GroupIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_group_ids;

    ValueType value(value_from);

    obj->addGroupIds(value);
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_remove_group_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, const char* p_group_ids)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::GroupIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_group_ids;
    ValueType value(value_from);
    obj->removeGroupIds(value);
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_clear_group_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions)
{   
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    obj->clearGroupIds();
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_access_profile_user_access_restrictions_get_user_ids(const data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions)
{
    const std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::UserIdsType ResultFromType;
    const ResultFromType result_from = obj->getUserIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *item_obj = reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >(item));
        node = data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_set_user_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, const ogs_list_t* p_user_ids)
{
    if (obj_data_access_profile_user_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    const auto &value_from = p_user_ids;
    typedef typename DataAccessProfile_userAccessRestrictions::UserIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setUserIds(value)) return NULL;
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_set_user_ids_move(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, ogs_list_t* p_user_ids)
{
    if (obj_data_access_profile_user_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    const auto &value_from = p_user_ids;
    typedef typename DataAccessProfile_userAccessRestrictions::UserIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_user_ids);
    if (!obj->setUserIds(std::move(value))) return NULL;
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_add_user_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t* p_user_ids)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::UserIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_user_ids;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addUserIds(value);
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_remove_user_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t* p_user_ids)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::UserIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_user_ids;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeUserIds(value);
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_clear_user_ids(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions)
{   
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    obj->clearUserIds();
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_access_profile_user_access_restrictions_get_aggregation_functions(const data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions)
{
    const std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::AggregationFunctionsType ResultFromType;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_set_aggregation_functions(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, const ogs_list_t* p_aggregation_functions)
{
    if (obj_data_access_profile_user_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    const auto &value_from = p_aggregation_functions;
    typedef typename DataAccessProfile_userAccessRestrictions::AggregationFunctionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setAggregationFunctions(value)) return NULL;
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_set_aggregation_functions_move(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, ogs_list_t* p_aggregation_functions)
{
    if (obj_data_access_profile_user_access_restrictions == NULL) return NULL;

    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    const auto &value_from = p_aggregation_functions;
    typedef typename DataAccessProfile_userAccessRestrictions::AggregationFunctionsType ValueType;

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
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_add_aggregation_functions(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, data_collection_model_data_aggregation_function_type_t* p_aggregation_functions)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::AggregationFunctionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_aggregation_functions;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addAggregationFunctions(value);
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_remove_aggregation_functions(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions, const data_collection_model_data_aggregation_function_type_t* p_aggregation_functions)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    typedef typename DataAccessProfile_userAccessRestrictions::AggregationFunctionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_aggregation_functions;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeAggregationFunctions(value);
    return obj_data_access_profile_user_access_restrictions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_t *data_collection_model_data_access_profile_user_access_restrictions_clear_aggregation_functions(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions)
{   
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    obj->clearAggregationFunctions();
    return obj_data_access_profile_user_access_restrictions;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_access_profile_user_access_restrictions_make_lnode(data_collection_model_data_access_profile_user_access_restrictions_t *p_data_access_profile_user_access_restrictions)
{
    return data_collection_lnode_create(p_data_access_profile_user_access_restrictions, reinterpret_cast<void(*)(void*)>(data_collection_model_data_access_profile_user_access_restrictions_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_access_profile_user_access_restrictions_refcount(data_collection_model_data_access_profile_user_access_restrictions_t *obj_data_access_profile_user_access_restrictions)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions >*>(obj_data_access_profile_user_access_restrictions);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

