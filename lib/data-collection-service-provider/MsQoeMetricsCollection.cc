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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "MsQoeMetricsCollection.h" already included by data-collection-sp/data-collection.h */
#include "MsQoeMetricsCollection-internal.h"
#include "openapi/model/MsQoeMetricsCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_create(
)
{
    return reinterpret_cast<data_collection_model_ms_qoe_metrics_collection_t*>(new std::shared_ptr<MsQoeMetricsCollection>(new MsQoeMetricsCollection(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_create_copy(const data_collection_model_ms_qoe_metrics_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ms_qoe_metrics_collection_t*>(new std::shared_ptr<MsQoeMetricsCollection >(new MsQoeMetricsCollection(**reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_create_move(data_collection_model_ms_qoe_metrics_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ms_qoe_metrics_collection_t*>(new std::shared_ptr<MsQoeMetricsCollection >(std::move(*reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_copy(data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection, const data_collection_model_ms_qoe_metrics_collection_t *other)
{
    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(other);
    return ms_qoe_metrics_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_move(data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection, data_collection_model_ms_qoe_metrics_collection_t *other)
{
    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(other));
    return ms_qoe_metrics_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ms_qoe_metrics_collection_free(data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection)
{
    delete reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ms_qoe_metrics_collection_toJSON(const data_collection_model_ms_qoe_metrics_collection_t *ms_qoe_metrics_collection, bool as_request)
{
    const std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(ms_qoe_metrics_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_ms_qoe_metrics_collection_get_ms_qoe_metrics(const data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection)
{
    const std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ResultFromType;
    const ResultFromType result_from = obj->getMsQoeMetrics();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_set_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, const ogs_list_t* p_ms_qoe_metrics)
{
    if (obj_ms_qoe_metrics_collection == NULL) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    const auto &value_from = p_ms_qoe_metrics;
    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setMsQoeMetrics(value)) return NULL;
    return obj_ms_qoe_metrics_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_set_ms_qoe_metrics_move(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, ogs_list_t* p_ms_qoe_metrics)
{
    if (obj_ms_qoe_metrics_collection == NULL) return NULL;

    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    const auto &value_from = p_ms_qoe_metrics;
    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_ms_qoe_metrics);
    if (!obj->setMsQoeMetrics(std::move(value))) return NULL;
    return obj_ms_qoe_metrics_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_add_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, char* p_ms_qoe_metrics)
{
    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_qoe_metrics;

    ValueType value(value_from);

    obj->addMsQoeMetrics(value);
    return obj_ms_qoe_metrics_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_remove_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection, const char* p_ms_qoe_metrics)
{
    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    typedef typename MsQoeMetricsCollection::MsQoeMetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_qoe_metrics;
    ValueType value(value_from);
    obj->removeMsQoeMetrics(value);
    return obj_ms_qoe_metrics_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_qoe_metrics_collection_t *data_collection_model_ms_qoe_metrics_collection_clear_ms_qoe_metrics(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection)
{   
    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    obj->clearMsQoeMetrics();
    return obj_ms_qoe_metrics_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ms_qoe_metrics_collection_make_lnode(data_collection_model_ms_qoe_metrics_collection_t *p_ms_qoe_metrics_collection)
{
    return data_collection_lnode_create(p_ms_qoe_metrics_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_ms_qoe_metrics_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ms_qoe_metrics_collection_refcount(data_collection_model_ms_qoe_metrics_collection_t *obj_ms_qoe_metrics_collection)
{
    std::shared_ptr<MsQoeMetricsCollection > &obj = *reinterpret_cast<std::shared_ptr<MsQoeMetricsCollection >*>(obj_ms_qoe_metrics_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

