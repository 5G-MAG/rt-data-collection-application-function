/**********************************************************************************************************************************
 * QoEMetricsEvent_allOf_metrics - C interface to the QoEMetricsEvent_allOf_metrics object
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

/*#include "QoEMetricsEvent_allOf_metrics.h" already included by data-collection-sp/data-collection.h */
#include "QoEMetricsEvent_allOf_metrics-internal.h"
#include "openapi/model/QoEMetricsEvent_allOf_metrics.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create(

)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_metrics_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_metrics>(new QoEMetricsEvent_allOf_metrics(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_copy(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_metrics_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_metrics >(new QoEMetricsEvent_allOf_metrics(**reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_metrics_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_metrics >(std::move(*reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_copy(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
    *obj = **reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other);
    return qo_e_metrics_event_all_of_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
    obj = std::move(*reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other));
    return qo_e_metrics_event_all_of_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_qo_e_metrics_event_all_of_metrics_free(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics)
{
    delete reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_qo_e_metrics_event_all_of_metrics_toJSON(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, bool as_request)
{
    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_metrics_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_metrics >(new QoEMetricsEvent_allOf_metrics(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_qo_e_metrics_event_all_of_metrics_get_key(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics)
{
    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    typedef typename QoEMetricsEvent_allOf_metrics::KeyType ResultFromType;
    const ResultFromType result_from = obj->getKey();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, const char* p_key)
{
    if (obj_qo_e_metrics_event_all_of_metrics == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    const auto &value_from = p_key;
    typedef typename QoEMetricsEvent_allOf_metrics::KeyType ValueType;

    ValueType value(value_from);
    if (!obj->setKey(value)) return NULL;
    return obj_qo_e_metrics_event_all_of_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, char* p_key)
{
    if (obj_qo_e_metrics_event_all_of_metrics == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    const auto &value_from = p_key;
    typedef typename QoEMetricsEvent_allOf_metrics::KeyType ValueType;

    ValueType value(value_from);
    
    if (!obj->setKey(std::move(value))) return NULL;
    return obj_qo_e_metrics_event_all_of_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_any_type_t* data_collection_model_qo_e_metrics_event_all_of_metrics_get_value(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics)
{
    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    typedef typename QoEMetricsEvent_allOf_metrics::ValueType ResultFromType;
    const ResultFromType result_from = obj->getValue();
    const data_collection_model_any_type_t *result = reinterpret_cast<const data_collection_model_any_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, const data_collection_model_any_type_t* p_value)
{
    if (obj_qo_e_metrics_event_all_of_metrics == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    const auto &value_from = p_value;
    typedef typename QoEMetricsEvent_allOf_metrics::ValueType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setValue(value)) return NULL;
    return obj_qo_e_metrics_event_all_of_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, data_collection_model_any_type_t* p_value)
{
    if (obj_qo_e_metrics_event_all_of_metrics == NULL) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    const auto &value_from = p_value;
    typedef typename QoEMetricsEvent_allOf_metrics::ValueType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setValue(std::move(value))) return NULL;
    return obj_qo_e_metrics_event_all_of_metrics;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_metrics_make_lnode(data_collection_model_qo_e_metrics_event_all_of_metrics_t *p_qo_e_metrics_event_all_of_metrics)
{
    return data_collection_lnode_create(p_qo_e_metrics_event_all_of_metrics, reinterpret_cast<void(*)(void*)>(data_collection_model_qo_e_metrics_event_all_of_metrics_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_qo_e_metrics_event_all_of_metrics_refcount(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics)
{
    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

