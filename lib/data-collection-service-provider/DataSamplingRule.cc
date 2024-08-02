/**********************************************************************************************************************************
 * DataSamplingRule - C interface to the DataSamplingRule object
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

/*#include "DataSamplingRule.h" already included by data-collection-sp/data-collection.h */
#include "DataSamplingRule-internal.h"
#include "openapi/model/DataSamplingRule.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create(


)
{
    return reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule>(new DataSamplingRule(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_copy(const data_collection_model_data_sampling_rule_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule >(new DataSamplingRule(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_create_move(data_collection_model_data_sampling_rule_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataSamplingRule > *obj = reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_copy(data_collection_model_data_sampling_rule_t *data_sampling_rule, const data_collection_model_data_sampling_rule_t *other)
{
    if (data_sampling_rule) {
        std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataSamplingRule > &other_obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(other);
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
                const std::shared_ptr<DataSamplingRule > &other_obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(other);
                if (other_obj) {
                    obj.reset(new DataSamplingRule(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_sampling_rule = data_collection_model_data_sampling_rule_create_copy(other);
    }
    return data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_move(data_collection_model_data_sampling_rule_t *data_sampling_rule, data_collection_model_data_sampling_rule_t *other)
{
    std::shared_ptr<DataSamplingRule > *other_ptr = reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(other);

    if (data_sampling_rule) {
        std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_sampling_rule = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_sampling_rule_free(data_collection_model_data_sampling_rule_t *data_sampling_rule)
{
    if (!data_sampling_rule) return;
    delete reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_sampling_rule_toJSON(const data_collection_model_data_sampling_rule_t *data_sampling_rule, bool as_request)
{
    if (!data_sampling_rule) return NULL;
    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(data_sampling_rule);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_sampling_rule_t*>(new std::shared_ptr<DataSamplingRule >(new DataSamplingRule(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_sampling_rule_is_equal_to(const data_collection_model_data_sampling_rule_t *first, const data_collection_model_data_sampling_rule_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataSamplingRule > &obj2 = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataSamplingRule > &obj1 = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_sampling_rule_get_context_ids(const data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    if (!obj_data_sampling_rule) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataSamplingRule::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_context_ids(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, const ogs_list_t* p_context_ids)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename DataSamplingRule::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;

    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_context_ids_move(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, ogs_list_t* p_context_ids)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename DataSamplingRule::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;

    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_add_context_ids(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, char* p_context_ids)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    typedef typename DataSamplingRule::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_remove_context_ids(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, const char* p_context_ids)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    typedef typename DataSamplingRule::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_clear_context_ids(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_data_sampling_rule_get_sampling_period(const data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    if (!obj_data_sampling_rule) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename DataSamplingRule::SamplingPeriodType ResultFromType;
    const ResultFromType result_from = obj->getSamplingPeriod();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, const float p_sampling_period)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    const auto &value_from = p_sampling_period;
    typedef typename DataSamplingRule::SamplingPeriodType ValueType;

    ValueType value = value_from;
    if (!obj->setSamplingPeriod(value)) return NULL;

    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_sampling_period_move(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, float p_sampling_period)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    const auto &value_from = p_sampling_period;
    typedef typename DataSamplingRule::SamplingPeriodType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSamplingPeriod(std::move(value))) return NULL;

    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_area5_g_t* data_collection_model_data_sampling_rule_get_location_filter(const data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    if (!obj_data_sampling_rule) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<const std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    typedef typename DataSamplingRule::LocationFilterType ResultFromType;
    const ResultFromType result_from = obj->getLocationFilter();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, const data_collection_model_location_area5_g_t* p_location_filter)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    const auto &value_from = p_location_filter;
    typedef typename DataSamplingRule::LocationFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocationFilter(value)) return NULL;

    return obj_data_sampling_rule;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_sampling_rule_t *data_collection_model_data_sampling_rule_set_location_filter_move(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule, data_collection_model_location_area5_g_t* p_location_filter)
{
    if (!obj_data_sampling_rule) return NULL;

    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    if (!obj) return NULL;

    const auto &value_from = p_location_filter;
    typedef typename DataSamplingRule::LocationFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocationFilter(std::move(value))) return NULL;

    return obj_data_sampling_rule;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_sampling_rule_make_lnode(data_collection_model_data_sampling_rule_t *p_data_sampling_rule)
{
    return data_collection_lnode_create(p_data_sampling_rule, reinterpret_cast<void(*)(void*)>(data_collection_model_data_sampling_rule_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_sampling_rule_refcount(data_collection_model_data_sampling_rule_t *obj_data_sampling_rule)
{
    if (!obj_data_sampling_rule) return 0l;
    std::shared_ptr<DataSamplingRule > &obj = *reinterpret_cast<std::shared_ptr<DataSamplingRule >*>(obj_data_sampling_rule);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

