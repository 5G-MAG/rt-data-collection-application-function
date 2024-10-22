/**********************************************************************************************************************************
 * MsQoeMetricsCollection - C interface to the MsQoeMetricsCollection object
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

/*#include "MsQoeMetricsCollection.h" already included by data-collection-sp/data-collection.h */
#include "MsQoeMetricsCollection-internal.h"
#include "openapi/model/MsQoeMetricsCollection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_create(
)
{
    return reinterpret_cast<data_collection_model_ms_qoe_metrics_collection_t*>(new std::shared_ptr<MsQoeMetricsCollection>(new MsQoeMetricsCollection(
)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_create_copy(const data_collection_model_ms_qoe_metrics_collection_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ms_qoe_metrics_collection_t*>(new std::shared_ptr<MsQoeMetricsCollection >(new MsQoeMetricsCollection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_create_move(data_collection_model_ms_qoe_metrics_collection_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > *obj = reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_copy(data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection, const data_collection_model_ms_qoe_metrics_collection_t *other)
{
    if (ms_qoe_metrics_collection) {
        std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
        if (obj) {
            if (other) {
                const std::shared_ptr<MsQoeMetricsCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(other);
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
                const std::shared_ptr<MsQoeMetricsCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(other);
                if (other_obj) {
                    obj.reset(new MsQoeMetricsCollection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ms_qoe_metrics_collection = data_collection_model_ms_qoe_metrics_collection_create_copy(other);
    }
    return ms_qoe_metrics_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_move(data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection, data_collection_model_ms_qoe_metrics_collection_t *other)
{
    std::shared_ptr<MsQoeMetricsCollection > *other_ptr = reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(other);

    if (ms_qoe_metrics_collection) {
        std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ms_qoe_metrics_collection = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ms_qoe_metrics_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ms_qoe_metrics_collection_free(data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection)
{
    if (!ms_qoe_metrics_collection) return;
    delete reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ms_qoe_metrics_collection_toJSON(const data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection, bool as_request)
{
    if (!ms_qoe_metrics_collection) return NULL;
    const std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_ms_qoe_metrics_collection_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ms_qoe_metrics_collection_t*>(new std::shared_ptr<MsQoeMetricsCollection >(new MsQoeMetricsCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ms_qoe_metrics_collection_is_equal_to(const data_collection_model_ms_qoe_metrics_collection_t *first, const data_collection_model_ms_qoe_metrics_collection_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MsQoeMetricsCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MsQoeMetricsCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ms_qoe_metrics_collection_get_ms_qoe_metrics(const data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection)
{
    if (!obj_ms_qoe_metrics_collection) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ResultFromType;
    const ResultFromType &result_from = obj->getMsQoeMetrics();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_set_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, const ogs_list_t* p_ms_qoe_metrics)
{
    if (!obj_ms_qoe_metrics_collection) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ms_qoe_metrics;
    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setMsQoeMetrics(value)) return NULL;

    return obj_ms_qoe_metrics_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_set_ms_qoe_metrics_move(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, ogs_list_t* p_ms_qoe_metrics)
{
    if (!obj_ms_qoe_metrics_collection) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ms_qoe_metrics;
    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_ms_qoe_metrics);
    if (!obj->setMsQoeMetrics(std::move(value))) return NULL;

    return obj_ms_qoe_metrics_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_add_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, char* p_ms_qoe_metrics)
{
    if (!obj_ms_qoe_metrics_collection) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    if (!obj) return NULL;

    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_qoe_metrics;

    ValueType value(value_from);

    ogs_free(p_ms_qoe_metrics);
    obj->addMsQoeMetrics(value);
    return obj_ms_qoe_metrics_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_remove_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, const char* p_ms_qoe_metrics)
{
    if (!obj_ms_qoe_metrics_collection) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    if (!obj) return NULL;

    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_qoe_metrics;
    ValueType value(value_from);

    obj->removeMsQoeMetrics(value);
    return obj_ms_qoe_metrics_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ms_qoe_metrics_collection_get_entry_ms_qoe_metrics(const data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, size_t idx)
{
    if (!obj_ms_qoe_metrics_collection) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const MsQoeMetricsCollection::MsQoeMetricsType &container = obj->getMsQoeMetrics();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename MsQoeMetricsCollection::MsQoeMetricsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_clear_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection)
{
    if (!obj_ms_qoe_metrics_collection) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    if (!obj) return NULL;

    obj->clearMsQoeMetrics();
    return obj_ms_qoe_metrics_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ms_qoe_metrics_collection_make_lnode(data_collection_model_ms_qoe_metrics_collection_t *p_ms_qoe_metrics_collection)
{
    return data_collection_lnode_create(p_ms_qoe_metrics_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_ms_qoe_metrics_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ms_qoe_metrics_collection_refcount(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection)
{
    if (!obj_ms_qoe_metrics_collection) return 0l;
    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

