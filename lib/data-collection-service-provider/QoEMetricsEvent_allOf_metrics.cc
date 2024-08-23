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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "QoEMetricsEvent_allOf_metrics.h" already included by data-collection-sp/data-collection.h */
#include "QoEMetricsEvent_allOf_metrics-internal.h"
#include "openapi/model/QoEMetricsEvent_allOf_metrics.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create(

)
{
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_metrics_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_metrics>(new QoEMetricsEvent_allOf_metrics(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_copy(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_qo_e_metrics_event_all_of_metrics_t*>(new std::shared_ptr<QoEMetricsEvent_allOf_metrics >(new QoEMetricsEvent_allOf_metrics(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > *obj = reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_copy(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    if (qo_e_metrics_event_all_of_metrics) {
        std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
        if (obj) {
            if (other) {
                const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &other_obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other);
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
                const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &other_obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other);
                if (other_obj) {
                    obj.reset(new QoEMetricsEvent_allOf_metrics(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        qo_e_metrics_event_all_of_metrics = data_collection_model_qo_e_metrics_event_all_of_metrics_create_copy(other);
    }
    return qo_e_metrics_event_all_of_metrics;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, data_collection_model_qo_e_metrics_event_all_of_metrics_t *other)
{
    std::shared_ptr<QoEMetricsEvent_allOf_metrics > *other_ptr = reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(other);

    if (qo_e_metrics_event_all_of_metrics) {
        std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                qo_e_metrics_event_all_of_metrics = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return qo_e_metrics_event_all_of_metrics;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_qo_e_metrics_event_all_of_metrics_free(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics)
{
    if (!qo_e_metrics_event_all_of_metrics) return;
    delete reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_qo_e_metrics_event_all_of_metrics_toJSON(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, bool as_request)
{
    if (!qo_e_metrics_event_all_of_metrics) return NULL;
    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(qo_e_metrics_event_all_of_metrics);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_metrics_is_equal_to(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *first, const data_collection_model_qo_e_metrics_event_all_of_metrics_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj2 = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj1 = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_metrics_get_key(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename QoEMetricsEvent_allOf_metrics::KeyType ResultFromType;
    const ResultFromType result_from = obj->getKey();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, const char* p_key)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    if (!obj) return NULL;

    const auto &value_from = p_key;
    typedef typename QoEMetricsEvent_allOf_metrics::KeyType ValueType;

    ValueType value(value_from);

    if (!obj->setKey(value)) return NULL;

    return obj_qo_e_metrics_event_all_of_metrics;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, char* p_key)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    if (!obj) return NULL;

    const auto &value_from = p_key;
    typedef typename QoEMetricsEvent_allOf_metrics::KeyType ValueType;

    ValueType value(value_from);

    
    if (!obj->setKey(std::move(value))) return NULL;

    return obj_qo_e_metrics_event_all_of_metrics;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_metrics_has_value(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) return false;

    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    if (!obj) return false;

    return obj->getValue().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_any_type_t* data_collection_model_qo_e_metrics_event_all_of_metrics_get_value(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) {
        const data_collection_model_any_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<const std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    if (!obj) {
        const data_collection_model_any_type_t *result = NULL;
        return result;
    }

    typedef typename QoEMetricsEvent_allOf_metrics::ValueType ResultFromType;
    const ResultFromType result_from = obj->getValue();
    const data_collection_model_any_type_t *result = reinterpret_cast<const data_collection_model_any_type_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, const data_collection_model_any_type_t* p_value)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    if (!obj) return NULL;

    const auto &value_from = p_value;
    typedef typename QoEMetricsEvent_allOf_metrics::ValueType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setValue(value)) return NULL;

    return obj_qo_e_metrics_event_all_of_metrics;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics, data_collection_model_any_type_t* p_value)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) return NULL;

    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    if (!obj) return NULL;

    const auto &value_from = p_value;
    typedef typename QoEMetricsEvent_allOf_metrics::ValueType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setValue(std::move(value))) return NULL;

    return obj_qo_e_metrics_event_all_of_metrics;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_metrics_make_lnode(data_collection_model_qo_e_metrics_event_all_of_metrics_t *p_qo_e_metrics_event_all_of_metrics)
{
    return data_collection_lnode_create(p_qo_e_metrics_event_all_of_metrics, reinterpret_cast<void(*)(void*)>(data_collection_model_qo_e_metrics_event_all_of_metrics_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_qo_e_metrics_event_all_of_metrics_refcount(data_collection_model_qo_e_metrics_event_all_of_metrics_t *obj_qo_e_metrics_event_all_of_metrics)
{
    if (!obj_qo_e_metrics_event_all_of_metrics) return 0l;
    std::shared_ptr<QoEMetricsEvent_allOf_metrics > &obj = *reinterpret_cast<std::shared_ptr<QoEMetricsEvent_allOf_metrics >*>(obj_qo_e_metrics_event_all_of_metrics);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

