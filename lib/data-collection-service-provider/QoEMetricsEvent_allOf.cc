/**********************************************************************************************************************************
 * QoEMetricsEvent_allOf - C interface to the QoEMetricsEvent_allOf object
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

/*#include "QoEMetricsEvent_allOf.h" already included by data-collection-sp/data-collection.h */
#include "QoEMetricsEvent_allOf-internal.h"
#include "openapi/model/QoEMetricsEvent_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_create(

)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_t*>(new std::shared_ptr<QoEMetricsEvent_allOf>(new QoEMetricsEvent_allOf(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_create_copy(const data_collection_model_qo_e_metrics_event_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_t*>(new std::shared_ptr<QoEMetricsEvent_allOf >(new QoEMetricsEvent_allOf(**reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_create_move(data_collection_model_qo_e_metrics_event_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_t*>(new std::shared_ptr<QoEMetricsEvent_allOf >(std::move(*reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_copy(data_collection_model_qo_e_metrics_event_all_of_t *qo_e_metrics_event_all_of, const data_collection_model_qo_e_metrics_event_all_of_t *other)
{
    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(qo_e_metrics_event_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf >*>(other);
    return qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_move(data_collection_model_qo_e_metrics_event_all_of_t *qo_e_metrics_event_all_of, data_collection_model_qo_e_metrics_event_all_of_t *other)
{
    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(qo_e_metrics_event_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(other));
    return qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_qo_e_metrics_event_all_of_free(data_collection_model_qo_e_metrics_event_all_of_t *qo_e_metrics_event_all_of)
{
    delete reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(qo_e_metrics_event_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_qo_e_metrics_event_all_of_toJSON(const data_collection_model_qo_e_metrics_event_all_of_t *qo_e_metrics_event_all_of, bool as_request)
{
    const std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf >*>(qo_e_metrics_event_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_t*>(new std::shared_ptr<QoEMetricsEvent_allOf >(new QoEMetricsEvent_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_qo_e_metrics_event_all_of_get_metric_type(const data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of)
{
    const std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    typedef typename QoEMetricsEvent_allOf::MetricTypeType ResultFromType;
    const ResultFromType result_from = obj->getMetricType();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_set_metric_type(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of, const char* p_metric_type)
{
    if (obj_qo_e_metrics_event_all_of == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    const auto &value_from = p_metric_type;
    typedef typename QoEMetricsEvent_allOf::MetricTypeType ValueType;

    ValueType value(value_from);
    if (!obj->setMetricType(value)) return NULL;
    return obj_qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_set_metric_type_move(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of, char* p_metric_type)
{
    if (obj_qo_e_metrics_event_all_of == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    const auto &value_from = p_metric_type;
    typedef typename QoEMetricsEvent_allOf::MetricTypeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMetricType(std::move(value))) return NULL;
    return obj_qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_qo_e_metrics_event_all_of_get_samples(const data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of)
{
    const std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    typedef typename QoEMetricsEvent_allOf::SamplesType ResultFromType;
    const ResultFromType result_from = obj->getSamples();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_qo_e_metrics_event_all_of_samples_t *item_obj = reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_samples_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_samples >(item));
        node = data_collection_model_qo_e_metrics_event_all_of_samples_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_set_samples(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of, const ogs_list_t* p_samples)
{
    if (obj_qo_e_metrics_event_all_of == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    const auto &value_from = p_samples;
    typedef typename QoEMetricsEvent_allOf::SamplesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setSamples(value)) return NULL;
    return obj_qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_set_samples_move(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of, ogs_list_t* p_samples)
{
    if (obj_qo_e_metrics_event_all_of == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    const auto &value_from = p_samples;
    typedef typename QoEMetricsEvent_allOf::SamplesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_samples);
    if (!obj->setSamples(std::move(value))) return NULL;
    return obj_qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_add_samples(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of, data_collection_model_qo_e_metrics_event_all_of_samples_t* p_samples)
{
    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    typedef typename QoEMetricsEvent_allOf::SamplesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_samples;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addSamples(value);
    return obj_qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_remove_samples(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of, const data_collection_model_qo_e_metrics_event_all_of_samples_t* p_samples)
{
    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    typedef typename QoEMetricsEvent_allOf::SamplesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_samples;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeSamples(value);
    return obj_qo_e_metrics_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_t *data_collection_model_qo_e_metrics_event_all_of_clear_samples(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of)
{   
    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    obj->clearSamples();
    return obj_qo_e_metrics_event_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_make_lnode(data_collection_model_qo_e_metrics_event_all_of_t *p_qo_e_metrics_event_all_of)
{
    return data_collection_lnode_create(p_qo_e_metrics_event_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_qo_e_metrics_event_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_qo_e_metrics_event_all_of_refcount(data_collection_model_qo_e_metrics_event_all_of_t *obj_qo_e_metrics_event_all_of)
{
    std::shared_ptr<QoEMetricsEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf >*>(obj_qo_e_metrics_event_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

