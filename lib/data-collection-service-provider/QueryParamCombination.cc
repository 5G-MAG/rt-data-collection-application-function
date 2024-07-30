/**********************************************************************************************************************************
 * QueryParamCombination - C interface to the QueryParamCombination object
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

/*#include "QueryParamCombination.h" already included by data-collection-sp/data-collection.h */
#include "QueryParamCombination-internal.h"
#include "openapi/model/QueryParamCombination.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create(
)
{
    return reinterpret_cast<data_collection_model_query_param_combination_t*>(new std::shared_ptr<QueryParamCombination>(new QueryParamCombination(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_copy(const data_collection_model_query_param_combination_t *other)
{
    return reinterpret_cast<data_collection_model_query_param_combination_t*>(new std::shared_ptr<QueryParamCombination >(new QueryParamCombination(**reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_move(data_collection_model_query_param_combination_t *other)
{
    return reinterpret_cast<data_collection_model_query_param_combination_t*>(new std::shared_ptr<QueryParamCombination >(std::move(*reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_copy(data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_param_combination_t *other)
{
    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(query_param_combination);
    *obj = **reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(other);
    return query_param_combination;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_move(data_collection_model_query_param_combination_t *query_param_combination, data_collection_model_query_param_combination_t *other)
{
    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(query_param_combination);
    obj = std::move(*reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(other));
    return query_param_combination;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_query_param_combination_free(data_collection_model_query_param_combination_t *query_param_combination)
{
    delete reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(query_param_combination);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_query_param_combination_toJSON(const data_collection_model_query_param_combination_t *query_param_combination, bool as_request)
{
    const std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(query_param_combination);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_query_param_combination_t*>(new std::shared_ptr<QueryParamCombination >(new QueryParamCombination(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_query_param_combination_is_equal_to(const data_collection_model_query_param_combination_t *first, const data_collection_model_query_param_combination_t *second)
{
    const std::shared_ptr<QueryParamCombination > &obj1 = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(first);
    const std::shared_ptr<QueryParamCombination > &obj2 = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_query_param_combination_get_query_params(const data_collection_model_query_param_combination_t *obj_query_param_combination)
{
    const std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    typedef typename QueryParamCombination::QueryParamsType ResultFromType;
    const ResultFromType result_from = obj->getQueryParams();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_query_parameter_t *item_obj = reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter >(item));
        node = data_collection_model_query_parameter_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination, const ogs_list_t* p_query_params)
{
    if (obj_query_param_combination == NULL) return NULL;

    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    const auto &value_from = p_query_params;
    typedef typename QueryParamCombination::QueryParamsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setQueryParams(value)) return NULL;
    return obj_query_param_combination;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params_move(data_collection_model_query_param_combination_t *obj_query_param_combination, ogs_list_t* p_query_params)
{
    if (obj_query_param_combination == NULL) return NULL;

    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    const auto &value_from = p_query_params;
    typedef typename QueryParamCombination::QueryParamsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_query_params);
    if (!obj->setQueryParams(std::move(value))) return NULL;
    return obj_query_param_combination;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_add_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination, data_collection_model_query_parameter_t* p_query_params)
{
    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    typedef typename QueryParamCombination::QueryParamsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_query_params;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addQueryParams(value);
    return obj_query_param_combination;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_remove_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination, const data_collection_model_query_parameter_t* p_query_params)
{
    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    typedef typename QueryParamCombination::QueryParamsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_query_params;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeQueryParams(value);
    return obj_query_param_combination;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_clear_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination)
{   
    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    obj->clearQueryParams();
    return obj_query_param_combination;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_query_param_combination_make_lnode(data_collection_model_query_param_combination_t *p_query_param_combination)
{
    return data_collection_lnode_create(p_query_param_combination, reinterpret_cast<void(*)(void*)>(data_collection_model_query_param_combination_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_query_param_combination_refcount(data_collection_model_query_param_combination_t *obj_query_param_combination)
{
    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

