/**********************************************************************************************************************************
 * QoEMetricsEvent_allOf_samples - C interface to the QoEMetricsEvent_allOf_samples object
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

/*#include "QoEMetricsEvent_allOf_samples.h" already included by data-collection-sp/data-collection.h */
#include "QoEMetricsEvent_allOf_samples-internal.h"
#include "openapi/model/QoEMetricsEvent_allOf_samples.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create(



)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_samples_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_samples>(new QoEMetricsEvent_allOf_samples(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create_copy(const data_collection_model_qo_e_metrics_event_all_of_samples_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_samples_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_samples >(new QoEMetricsEvent_allOf_samples(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > *obj = reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_copy(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const data_collection_model_qo_e_metrics_event_all_of_samples_t *other)
{
    if (qo_e_metrics_event_all_of_samples) {
        std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(qo_e_metrics_event_all_of_samples);
        if (obj) {
            if (other) {
                const std::shared_ptr<QoEMetricsEvent_allOf_samples > &other_obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(other);
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
                const std::shared_ptr<QoEMetricsEvent_allOf_samples > &other_obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(other);
                if (other_obj) {
                    obj.reset(new QoEMetricsEvent_allOf_samples(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        qo_e_metrics_event_all_of_samples = data_collection_model_qo_e_metrics_event_all_of_samples_create_copy(other);
    }
    return qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, data_collection_model_qo_e_metrics_event_all_of_samples_t *other)
{
    std::shared_ptr<QoEMetricsEvent_allOf_samples > *other_ptr = reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(other);

    if (qo_e_metrics_event_all_of_samples) {
        std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(qo_e_metrics_event_all_of_samples);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                qo_e_metrics_event_all_of_samples = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_qo_e_metrics_event_all_of_samples_free(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples)
{
    if (!qo_e_metrics_event_all_of_samples) return;
    delete reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(qo_e_metrics_event_all_of_samples);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_qo_e_metrics_event_all_of_samples_toJSON(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, bool as_request)
{
    if (!qo_e_metrics_event_all_of_samples) return NULL;
    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_samples_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_samples >(new QoEMetricsEvent_allOf_samples(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_qo_e_metrics_event_all_of_samples_is_equal_to(const data_collection_model_qo_e_metrics_event_all_of_samples_t *first, const data_collection_model_qo_e_metrics_event_all_of_samples_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj2 = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj1 = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_sample_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples)
{
    if (!obj_qo_e_metrics_event_all_of_samples) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename QoEMetricsEvent_allOf_samples::SampleTimestampType ResultFromType;
    const ResultFromType result_from = obj->getSampleTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_timestamp(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, const char* p_sample_timestamp)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_sample_timestamp;
    typedef typename QoEMetricsEvent_allOf_samples::SampleTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setSampleTimestamp(value)) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_timestamp_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, char* p_sample_timestamp)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_sample_timestamp;
    typedef typename QoEMetricsEvent_allOf_samples::SampleTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSampleTimestamp(std::move(value))) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_sample_duration(const data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples)
{
    if (!obj_qo_e_metrics_event_all_of_samples) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename QoEMetricsEvent_allOf_samples::SampleDurationType ResultFromType;
    const ResultFromType result_from = obj->getSampleDuration();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_duration(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, const char* p_sample_duration)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_sample_duration;
    typedef typename QoEMetricsEvent_allOf_samples::SampleDurationType ValueType;

    ValueType value(value_from);
    if (!obj->setSampleDuration(value)) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_duration_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, char* p_sample_duration)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_sample_duration;
    typedef typename QoEMetricsEvent_allOf_samples::SampleDurationType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSampleDuration(std::move(value))) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_media_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples)
{
    if (!obj_qo_e_metrics_event_all_of_samples) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename QoEMetricsEvent_allOf_samples::MediaTimestampType ResultFromType;
    const ResultFromType result_from = obj->getMediaTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_media_timestamp(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, const char* p_media_timestamp)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_media_timestamp;
    typedef typename QoEMetricsEvent_allOf_samples::MediaTimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setMediaTimestamp(value)) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_media_timestamp_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, char* p_media_timestamp)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_media_timestamp;
    typedef typename QoEMetricsEvent_allOf_samples::MediaTimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMediaTimestamp(std::move(value))) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_qo_e_metrics_event_all_of_samples_get_metrics(const data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples)
{
    if (!obj_qo_e_metrics_event_all_of_samples) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename QoEMetricsEvent_allOf_samples::MetricsType ResultFromType;
    const ResultFromType result_from = obj->getMetrics();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_qo_e_metrics_event_all_of_metrics_t *item_obj = reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_metrics_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_metrics >(item));
        node = data_collection_model_qo_e_metrics_event_all_of_metrics_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, const ogs_list_t* p_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_metrics;
    typedef typename QoEMetricsEvent_allOf_samples::MetricsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMetrics(value)) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_metrics_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, ogs_list_t* p_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    const auto &value_from = p_metrics;
    typedef typename QoEMetricsEvent_allOf_samples::MetricsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_metrics);
    if (!obj->setMetrics(std::move(value))) return NULL;

    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_add_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, data_collection_model_qo_e_metrics_event_all_of_metrics_t* p_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    typedef typename QoEMetricsEvent_allOf_samples::MetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_metrics;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMetrics(value);
    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_remove_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples, const data_collection_model_qo_e_metrics_event_all_of_metrics_t* p_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    typedef typename QoEMetricsEvent_allOf_samples::MetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_metrics;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMetrics(value);
    return obj_qo_e_metrics_event_all_of_samples;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_clear_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    if (!obj) return NULL;

    obj->clearMetrics();
    return obj_qo_e_metrics_event_all_of_samples;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_samples_make_lnode(data_collection_model_qo_e_metrics_event_all_of_samples_t *p_qo_e_metrics_event_all_of_samples)
{
    return data_collection_lnode_create(p_qo_e_metrics_event_all_of_samples, reinterpret_cast<void(*)(void*)>(data_collection_model_qo_e_metrics_event_all_of_samples_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_qo_e_metrics_event_all_of_samples_refcount(data_collection_model_qo_e_metrics_event_all_of_samples_t *obj_qo_e_metrics_event_all_of_samples)
{
    if (!obj_qo_e_metrics_event_all_of_samples) return 0l;
    std::shared_ptr<QoEMetricsEvent_allOf_samples > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_samples >*>(obj_qo_e_metrics_event_all_of_samples);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

