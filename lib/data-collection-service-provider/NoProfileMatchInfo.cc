/**********************************************************************************************************************************
 * NoProfileMatchInfo - C interface to the NoProfileMatchInfo object
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

/*#include "NoProfileMatchInfo.h" already included by data-collection-sp/data-collection.h */
#include "NoProfileMatchInfo-internal.h"
#include "openapi/model/NoProfileMatchInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create(

)
{
    return reinterpret_cast<data_collection_model_no_profile_match_info_t*>(new std::shared_ptr<NoProfileMatchInfo>(new NoProfileMatchInfo(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_copy(const data_collection_model_no_profile_match_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_no_profile_match_info_t*>(new std::shared_ptr<NoProfileMatchInfo >(new NoProfileMatchInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_move(data_collection_model_no_profile_match_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NoProfileMatchInfo > *obj = reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_copy(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_info_t *other)
{
    if (no_profile_match_info) {
        std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<NoProfileMatchInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(other);
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
                const std::shared_ptr<NoProfileMatchInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(other);
                if (other_obj) {
                    obj.reset(new NoProfileMatchInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        no_profile_match_info = data_collection_model_no_profile_match_info_create_copy(other);
    }
    return no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_no_profile_match_info_t *other)
{
    std::shared_ptr<NoProfileMatchInfo > *other_ptr = reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(other);

    if (no_profile_match_info) {
        std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                no_profile_match_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_no_profile_match_info_free(data_collection_model_no_profile_match_info_t *no_profile_match_info)
{
    if (!no_profile_match_info) return;
    delete reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_no_profile_match_info_toJSON(const data_collection_model_no_profile_match_info_t *no_profile_match_info, bool as_request)
{
    if (!no_profile_match_info) return NULL;
    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_no_profile_match_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_no_profile_match_info_t*>(new std::shared_ptr<NoProfileMatchInfo >(new NoProfileMatchInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_info_is_equal_to(const data_collection_model_no_profile_match_info_t *first, const data_collection_model_no_profile_match_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NoProfileMatchInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NoProfileMatchInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_no_profile_match_reason_t* data_collection_model_no_profile_match_info_get_reason(const data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    if (!obj_no_profile_match_info) {
        const data_collection_model_no_profile_match_reason_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) {
        const data_collection_model_no_profile_match_reason_t *result = NULL;
        return result;
    }

    typedef typename NoProfileMatchInfo::ReasonType ResultFromType;
    const ResultFromType &result_from = obj->getReason();
    const data_collection_model_no_profile_match_reason_t *result = reinterpret_cast<const data_collection_model_no_profile_match_reason_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, const data_collection_model_no_profile_match_reason_t* p_reason)
{
    if (!obj_no_profile_match_info) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return NULL;

    const auto &value_from = p_reason;
    typedef typename NoProfileMatchInfo::ReasonType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setReason(value)) return NULL;

    return obj_no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason_move(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, data_collection_model_no_profile_match_reason_t* p_reason)
{
    if (!obj_no_profile_match_info) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return NULL;

    const auto &value_from = p_reason;
    typedef typename NoProfileMatchInfo::ReasonType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setReason(std::move(value))) return NULL;

    return obj_no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_info_has_query_param_combination_list(const data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    if (!obj_no_profile_match_info) return false;

    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return false;

    return obj->getQueryParamCombinationList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_no_profile_match_info_get_query_param_combination_list(const data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    if (!obj_no_profile_match_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ResultFromType;
    const ResultFromType &result_from = obj->getQueryParamCombinationList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_query_param_combination_t *item_obj = reinterpret_cast<data_collection_model_query_param_combination_t*>(item.has_value()?new std::shared_ptr<QueryParamCombination >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_query_param_combination_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, const ogs_list_t* p_query_param_combination_list)
{
    if (!obj_no_profile_match_info) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return NULL;

    const auto &value_from = p_query_param_combination_list;
    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ValueType;

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

    if (!obj->setQueryParamCombinationList(value)) return NULL;

    return obj_no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list_move(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, ogs_list_t* p_query_param_combination_list)
{
    if (!obj_no_profile_match_info) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return NULL;

    const auto &value_from = p_query_param_combination_list;
    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ValueType;

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

    data_collection_list_free(p_query_param_combination_list);
    if (!obj->setQueryParamCombinationList(std::move(value))) return NULL;

    return obj_no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_add_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, data_collection_model_query_param_combination_t* p_query_param_combination_list)
{
    if (!obj_no_profile_match_info) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return NULL;

    typedef typename NoProfileMatchInfo::QueryParamCombinationListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_query_param_combination_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addQueryParamCombinationList(value.value());
    return obj_no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_remove_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, const data_collection_model_query_param_combination_t* p_query_param_combination_list)
{
    if (!obj_no_profile_match_info) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return NULL;

    typedef typename NoProfileMatchInfo::QueryParamCombinationListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_query_param_combination_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeQueryParamCombinationList(value);
    return obj_no_profile_match_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_clear_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    if (!obj_no_profile_match_info) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    if (!obj) return NULL;

    obj->clearQueryParamCombinationList();
    return obj_no_profile_match_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_no_profile_match_info_make_lnode(data_collection_model_no_profile_match_info_t *p_no_profile_match_info)
{
    return data_collection_lnode_create(p_no_profile_match_info, reinterpret_cast<void(*)(void*)>(data_collection_model_no_profile_match_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_no_profile_match_info_refcount(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    if (!obj_no_profile_match_info) return 0l;
    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

