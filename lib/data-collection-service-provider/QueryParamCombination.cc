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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create(
)
{
    return reinterpret_cast<data_collection_model_query_param_combination_t*>(new std::shared_ptr<QueryParamCombination>(new QueryParamCombination(
)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_copy(const data_collection_model_query_param_combination_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_query_param_combination_t*>(new std::shared_ptr<QueryParamCombination >(new QueryParamCombination(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_create_move(data_collection_model_query_param_combination_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<QueryParamCombination > *obj = reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_copy(data_collection_model_query_param_combination_t *query_param_combination, const data_collection_model_query_param_combination_t *other)
{
    if (query_param_combination) {
        std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(query_param_combination);
        if (obj) {
            if (other) {
                const std::shared_ptr<QueryParamCombination > &other_obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(other);
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
                const std::shared_ptr<QueryParamCombination > &other_obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(other);
                if (other_obj) {
                    obj.reset(new QueryParamCombination(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        query_param_combination = data_collection_model_query_param_combination_create_copy(other);
    }
    return query_param_combination;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_move(data_collection_model_query_param_combination_t *query_param_combination, data_collection_model_query_param_combination_t *other)
{
    std::shared_ptr<QueryParamCombination > *other_ptr = reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(other);

    if (query_param_combination) {
        std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(query_param_combination);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                query_param_combination = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return query_param_combination;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_query_param_combination_free(data_collection_model_query_param_combination_t *query_param_combination)
{
    if (!query_param_combination) return;
    delete reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(query_param_combination);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_query_param_combination_toJSON(const data_collection_model_query_param_combination_t *query_param_combination, bool as_request)
{
    if (!query_param_combination) return NULL;
    const std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(query_param_combination);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_query_param_combination_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_query_param_combination_is_equal_to(const data_collection_model_query_param_combination_t *first, const data_collection_model_query_param_combination_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<QueryParamCombination > &obj2 = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<QueryParamCombination > &obj1 = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_query_param_combination_get_query_params(const data_collection_model_query_param_combination_t *obj_query_param_combination)
{
    if (!obj_query_param_combination) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename QueryParamCombination::QueryParamsType ResultFromType;
    const ResultFromType &result_from = obj->getQueryParams();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_query_parameter_t *item_obj = reinterpret_cast<data_collection_model_query_parameter_t*>(item.has_value()?new std::shared_ptr<QueryParameter >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_query_parameter_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination, const ogs_list_t* p_query_params)
{
    if (!obj_query_param_combination) return NULL;

    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    if (!obj) return NULL;

    const auto &value_from = p_query_params;
    typedef typename QueryParamCombination::QueryParamsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setQueryParams(value)) return NULL;

    return obj_query_param_combination;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_set_query_params_move(data_collection_model_query_param_combination_t *obj_query_param_combination, ogs_list_t* p_query_params)
{
    if (!obj_query_param_combination) return NULL;

    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    if (!obj) return NULL;

    const auto &value_from = p_query_params;
    typedef typename QueryParamCombination::QueryParamsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_query_params);
    if (!obj->setQueryParams(std::move(value))) return NULL;

    return obj_query_param_combination;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_add_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination, data_collection_model_query_parameter_t* p_query_params)
{
    if (!obj_query_param_combination) return NULL;

    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    if (!obj) return NULL;

    typedef typename QueryParamCombination::QueryParamsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_query_params;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    obj->addQueryParams(value);
    return obj_query_param_combination;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_remove_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination, const data_collection_model_query_parameter_t* p_query_params)
{
    if (!obj_query_param_combination) return NULL;

    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    if (!obj) return NULL;

    typedef typename QueryParamCombination::QueryParamsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_query_params;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeQueryParams(value);
    return obj_query_param_combination;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_query_parameter_t* data_collection_model_query_param_combination_get_entry_query_params(const data_collection_model_query_param_combination_t *obj_query_param_combination, size_t idx)
{
    if (!obj_query_param_combination) {
        const data_collection_model_query_parameter_t *result = NULL;

        return result;
    }

    const std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<const std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    if (!obj) {
        const data_collection_model_query_parameter_t *result = NULL;

        return result;
    }

    const QueryParamCombination::QueryParamsType &container = obj->getQueryParams();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_query_parameter_t *result = NULL;

        return result;
    }
    typedef typename QueryParamCombination::QueryParamsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_query_parameter_t *result = reinterpret_cast<const data_collection_model_query_parameter_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_param_combination_t *data_collection_model_query_param_combination_clear_query_params(data_collection_model_query_param_combination_t *obj_query_param_combination)
{
    if (!obj_query_param_combination) return NULL;

    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    if (!obj) return NULL;

    obj->clearQueryParams();
    return obj_query_param_combination;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_query_param_combination_make_lnode(data_collection_model_query_param_combination_t *p_query_param_combination)
{
    return data_collection_lnode_create(p_query_param_combination, reinterpret_cast<void(*)(void*)>(data_collection_model_query_param_combination_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_query_param_combination_refcount(data_collection_model_query_param_combination_t *obj_query_param_combination)
{
    if (!obj_query_param_combination) return 0l;
    std::shared_ptr<QueryParamCombination > &obj = *reinterpret_cast<std::shared_ptr<QueryParamCombination >*>(obj_query_param_combination);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

