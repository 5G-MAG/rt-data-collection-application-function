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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create(

)
{
    return reinterpret_cast<data_collection_model_no_profile_match_info_t*>(new std::shared_ptr<NoProfileMatchInfo>(new NoProfileMatchInfo(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_copy(const data_collection_model_no_profile_match_info_t *other)
{
    return reinterpret_cast<data_collection_model_no_profile_match_info_t*>(new std::shared_ptr<NoProfileMatchInfo >(new NoProfileMatchInfo(**reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_create_move(data_collection_model_no_profile_match_info_t *other)
{
    return reinterpret_cast<data_collection_model_no_profile_match_info_t*>(new std::shared_ptr<NoProfileMatchInfo >(std::move(*reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_copy(data_collection_model_no_profile_match_info_t *no_profile_match_info, const data_collection_model_no_profile_match_info_t *other)
{
    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
    *obj = **reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(other);
    return no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_move(data_collection_model_no_profile_match_info_t *no_profile_match_info, data_collection_model_no_profile_match_info_t *other)
{
    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(other));
    return no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_no_profile_match_info_free(data_collection_model_no_profile_match_info_t *no_profile_match_info)
{
    delete reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_no_profile_match_info_toJSON(const data_collection_model_no_profile_match_info_t *no_profile_match_info, bool as_request)
{
    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(no_profile_match_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_no_profile_match_info_is_equal_to(const data_collection_model_no_profile_match_info_t *first, const data_collection_model_no_profile_match_info_t *second)
{
    const std::shared_ptr<NoProfileMatchInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(first);
    const std::shared_ptr<NoProfileMatchInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_no_profile_match_reason_t* data_collection_model_no_profile_match_info_get_reason(const data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    typedef typename NoProfileMatchInfo::ReasonType ResultFromType;
    const ResultFromType result_from = obj->getReason();
    const data_collection_model_no_profile_match_reason_t *result = reinterpret_cast<const data_collection_model_no_profile_match_reason_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, const data_collection_model_no_profile_match_reason_t* p_reason)
{
    if (obj_no_profile_match_info == NULL) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    const auto &value_from = p_reason;
    typedef typename NoProfileMatchInfo::ReasonType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setReason(value)) return NULL;
    return obj_no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_reason_move(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, data_collection_model_no_profile_match_reason_t* p_reason)
{
    if (obj_no_profile_match_info == NULL) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    const auto &value_from = p_reason;
    typedef typename NoProfileMatchInfo::ReasonType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setReason(std::move(value))) return NULL;
    return obj_no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_no_profile_match_info_get_query_param_combination_list(const data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    const std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ResultFromType;
    const ResultFromType result_from = obj->getQueryParamCombinationList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_query_param_combination_t *item_obj = reinterpret_cast<data_collection_model_query_param_combination_t*>(new std::shared_ptr<QueryParamCombination >(item));
        node = data_collection_model_query_param_combination_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, const ogs_list_t* p_query_param_combination_list)
{
    if (obj_no_profile_match_info == NULL) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    const auto &value_from = p_query_param_combination_list;
    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setQueryParamCombinationList(value)) return NULL;
    return obj_no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_set_query_param_combination_list_move(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, ogs_list_t* p_query_param_combination_list)
{
    if (obj_no_profile_match_info == NULL) return NULL;

    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    const auto &value_from = p_query_param_combination_list;
    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_query_param_combination_list);
    if (!obj->setQueryParamCombinationList(std::move(value))) return NULL;
    return obj_no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_add_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, data_collection_model_query_param_combination_t* p_query_param_combination_list)
{
    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_query_param_combination_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addQueryParamCombinationList(value);
    return obj_no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_remove_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info, const data_collection_model_query_param_combination_t* p_query_param_combination_list)
{
    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    typedef typename NoProfileMatchInfo::QueryParamCombinationListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_query_param_combination_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeQueryParamCombinationList(value);
    return obj_no_profile_match_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_no_profile_match_info_t *data_collection_model_no_profile_match_info_clear_query_param_combination_list(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{   
    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    obj->clearQueryParamCombinationList();
    return obj_no_profile_match_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_no_profile_match_info_make_lnode(data_collection_model_no_profile_match_info_t *p_no_profile_match_info)
{
    return data_collection_lnode_create(p_no_profile_match_info, reinterpret_cast<void(*)(void*)>(data_collection_model_no_profile_match_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_no_profile_match_info_refcount(data_collection_model_no_profile_match_info_t *obj_no_profile_match_info)
{
    std::shared_ptr<NoProfileMatchInfo > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchInfo >*>(obj_no_profile_match_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

