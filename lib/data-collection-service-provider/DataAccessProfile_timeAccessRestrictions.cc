/**********************************************************************************************************************************
 * DataAccessProfile_timeAccessRestrictions - C interface to the DataAccessProfile_timeAccessRestrictions object
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

/*#include "DataAccessProfile_timeAccessRestrictions.h" already included by data-collection-sp/data-collection.h */
#include "DataAccessProfile_timeAccessRestrictions-internal.h"
#include "openapi/model/DataAccessProfile_timeAccessRestrictions.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_create(

)
{
    return reinterpret_cast<data_collection_model_data_access_profile_time_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_timeAccessRestrictions>(new DataAccessProfile_timeAccessRestrictions(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_create_ref(const data_collection_model_data_access_profile_time_access_restrictions_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_time_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_timeAccessRestrictions>(*reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_create_copy(const data_collection_model_data_access_profile_time_access_restrictions_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_access_profile_time_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_timeAccessRestrictions >(new DataAccessProfile_timeAccessRestrictions(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_create_move(data_collection_model_data_access_profile_time_access_restrictions_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > *obj = reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_copy(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, const data_collection_model_data_access_profile_time_access_restrictions_t *other)
{
    if (data_access_profile_time_access_restrictions) {
        std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(data_access_profile_time_access_restrictions);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &other_obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(other);
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
                const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &other_obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(other);
                if (other_obj) {
                    obj.reset(new DataAccessProfile_timeAccessRestrictions(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_access_profile_time_access_restrictions = data_collection_model_data_access_profile_time_access_restrictions_create_copy(other);
    }
    return data_access_profile_time_access_restrictions;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_move(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, data_collection_model_data_access_profile_time_access_restrictions_t *other)
{
    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > *other_ptr = reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(other);

    if (data_access_profile_time_access_restrictions) {
        std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(data_access_profile_time_access_restrictions);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_access_profile_time_access_restrictions = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_access_profile_time_access_restrictions;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_time_access_restrictions_free(data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions)
{
    if (!data_access_profile_time_access_restrictions) return;
    delete reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(data_access_profile_time_access_restrictions);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_time_access_restrictions_toJSON(const data_collection_model_data_access_profile_time_access_restrictions_t *data_access_profile_time_access_restrictions, bool as_request)
{
    if (!data_access_profile_time_access_restrictions) return NULL;
    const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(data_access_profile_time_access_restrictions);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_data_access_profile_time_access_restrictions_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_access_profile_time_access_restrictions_t*>(new std::shared_ptr<DataAccessProfile_timeAccessRestrictions >(new DataAccessProfile_timeAccessRestrictions(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_time_access_restrictions_is_equal_to(const data_collection_model_data_access_profile_time_access_restrictions_t *first, const data_collection_model_data_access_profile_time_access_restrictions_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj2 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj1 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_data_access_profile_time_access_restrictions_get_duration(const data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions)
{
    if (!obj_data_access_profile_time_access_restrictions) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename DataAccessProfile_timeAccessRestrictions::DurationType ResultFromType;
    const ResultFromType &result_from = obj->getDuration();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_duration(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions, const int32_t p_duration)
{
    if (!obj_data_access_profile_time_access_restrictions) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) return NULL;

    const auto &value_from = p_duration;
    typedef typename DataAccessProfile_timeAccessRestrictions::DurationType ValueType;

    ValueType value(value_from);

    if (!obj->setDuration(value)) return NULL;

    return obj_data_access_profile_time_access_restrictions;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_duration_move(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions, int32_t p_duration)
{
    if (!obj_data_access_profile_time_access_restrictions) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) return NULL;

    const auto &value_from = p_duration;
    typedef typename DataAccessProfile_timeAccessRestrictions::DurationType ValueType;

    ValueType value(value_from);

    if (!obj->setDuration(std::move(value))) return NULL;

    return obj_data_access_profile_time_access_restrictions;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_time_access_restrictions_get_aggregation_functions(const data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions)
{
    if (!obj_data_access_profile_time_access_restrictions) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataAccessProfile_timeAccessRestrictions::AggregationFunctionsType ResultFromType;
    const ResultFromType &result_from = obj->getAggregationFunctions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_data_aggregation_function_type_t *item_obj = reinterpret_cast<data_collection_model_data_aggregation_function_type_t*>(item.has_value()?new std::shared_ptr<DataAggregationFunctionType >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_data_aggregation_function_type_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions, const ogs_list_t* p_aggregation_functions)
{
    if (!obj_data_access_profile_time_access_restrictions) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) return NULL;

    const auto &value_from = p_aggregation_functions;
    typedef typename DataAccessProfile_timeAccessRestrictions::AggregationFunctionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setAggregationFunctions(value)) return NULL;

    return obj_data_access_profile_time_access_restrictions;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_set_aggregation_functions_move(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions, ogs_list_t* p_aggregation_functions)
{
    if (!obj_data_access_profile_time_access_restrictions) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) return NULL;

    const auto &value_from = p_aggregation_functions;
    typedef typename DataAccessProfile_timeAccessRestrictions::AggregationFunctionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setAggregationFunctions(std::move(value))) return NULL;
    data_collection_list_free
(p_aggregation_functions);

    return obj_data_access_profile_time_access_restrictions;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_add_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions, data_collection_model_data_aggregation_function_type_t* p_aggregation_functions)
{
    if (!obj_data_access_profile_time_access_restrictions) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) return NULL;

    typedef typename DataAccessProfile_timeAccessRestrictions::AggregationFunctionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_aggregation_functions;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_data_aggregation_function_type_free
(p_aggregation_functions);
    obj->addAggregationFunctions(value);
    return obj_data_access_profile_time_access_restrictions;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_remove_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions, const data_collection_model_data_aggregation_function_type_t* p_aggregation_functions)
{
    if (!obj_data_access_profile_time_access_restrictions) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) return NULL;

    typedef typename DataAccessProfile_timeAccessRestrictions::AggregationFunctionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_aggregation_functions;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeAggregationFunctions(value);
    return obj_data_access_profile_time_access_restrictions;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_aggregation_function_type_t* data_collection_model_data_access_profile_time_access_restrictions_get_entry_aggregation_functions(const data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions, size_t idx)
{
    if (!obj_data_access_profile_time_access_restrictions) {
        const data_collection_model_data_aggregation_function_type_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) {
        const data_collection_model_data_aggregation_function_type_t *result = NULL;

        return result;
    }

    const DataAccessProfile_timeAccessRestrictions::AggregationFunctionsType &container = obj->getAggregationFunctions();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_data_aggregation_function_type_t *result = NULL;

        return result;
    }
    typedef typename DataAccessProfile_timeAccessRestrictions::AggregationFunctionsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_data_aggregation_function_type_t *result = reinterpret_cast<const data_collection_model_data_aggregation_function_type_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_time_access_restrictions_t *data_collection_model_data_access_profile_time_access_restrictions_clear_aggregation_functions(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions)
{
    if (!obj_data_access_profile_time_access_restrictions) return NULL;

    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    if (!obj) return NULL;

    obj->clearAggregationFunctions();
    return obj_data_access_profile_time_access_restrictions;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_time_access_restrictions_make_lnode(data_collection_model_data_access_profile_time_access_restrictions_t *p_data_access_profile_time_access_restrictions)
{
    return data_collection_lnode_create(p_data_access_profile_time_access_restrictions, reinterpret_cast<void(*)(void*)>(data_collection_model_data_access_profile_time_access_restrictions_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_access_profile_time_access_restrictions_refcount(data_collection_model_data_access_profile_time_access_restrictions_t *obj_data_access_profile_time_access_restrictions)
{
    if (!obj_data_access_profile_time_access_restrictions) return 0l;
    std::shared_ptr<DataAccessProfile_timeAccessRestrictions > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_timeAccessRestrictions >*>(obj_data_access_profile_time_access_restrictions);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

