/**********************************************************************************************************************************
 * HighAccuracyGnssMetrics - C interface to the HighAccuracyGnssMetrics object
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

/*#include "HighAccuracyGnssMetrics.h" already included by data-collection-sp/data-collection.h */
#include "HighAccuracyGnssMetrics-internal.h"
#include "openapi/model/HighAccuracyGnssMetrics.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create(




)
{
    return reinterpret_cast<data_collection_model_high_accuracy_gnss_metrics_t*>(new std::shared_ptr<HighAccuracyGnssMetrics>(new HighAccuracyGnssMetrics(




)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create_copy(const data_collection_model_high_accuracy_gnss_metrics_t *other)
{
    return reinterpret_cast<data_collection_model_high_accuracy_gnss_metrics_t*>(new std::shared_ptr<HighAccuracyGnssMetrics >(new HighAccuracyGnssMetrics(**reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create_move(data_collection_model_high_accuracy_gnss_metrics_t *other)
{
    return reinterpret_cast<data_collection_model_high_accuracy_gnss_metrics_t*>(new std::shared_ptr<HighAccuracyGnssMetrics >(std::move(*reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_copy(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const data_collection_model_high_accuracy_gnss_metrics_t *other)
{
    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(high_accuracy_gnss_metrics);
    *obj = **reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(other);
    return high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, data_collection_model_high_accuracy_gnss_metrics_t *other)
{
    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(high_accuracy_gnss_metrics);
    obj = std::move(*reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(other));
    return high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_high_accuracy_gnss_metrics_free(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics)
{
    delete reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(high_accuracy_gnss_metrics);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_high_accuracy_gnss_metrics_toJSON(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, bool as_request)
{
    const std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(high_accuracy_gnss_metrics);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_high_accuracy_gnss_metrics_t*>(new std::shared_ptr<HighAccuracyGnssMetrics >(new HighAccuracyGnssMetrics(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_high_accuracy_gnss_metrics_get_nr_of_used_satellites(const data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics)
{
    const std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    typedef typename HighAccuracyGnssMetrics::NrOfUsedSatellitesType ResultFromType;
    const ResultFromType result_from = obj->getNrOfUsedSatellites();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_nr_of_used_satellites(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, const int32_t p_nr_of_used_satellites)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_nr_of_used_satellites;
    typedef typename HighAccuracyGnssMetrics::NrOfUsedSatellitesType ValueType;

    ValueType value = value_from;
    if (!obj->setNrOfUsedSatellites(value)) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_nr_of_used_satellites_move(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, int32_t p_nr_of_used_satellites)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_nr_of_used_satellites;
    typedef typename HighAccuracyGnssMetrics::NrOfUsedSatellitesType ValueType;

    ValueType value = value_from;
    
    if (!obj->setNrOfUsedSatellites(std::move(value))) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_high_accuracy_gnss_metrics_get_hdopi(const data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics)
{
    const std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    typedef typename HighAccuracyGnssMetrics::HdopiType ResultFromType;
    const ResultFromType result_from = obj->getHdopi();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_hdopi(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, const int32_t p_hdopi)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_hdopi;
    typedef typename HighAccuracyGnssMetrics::HdopiType ValueType;

    ValueType value = value_from;
    if (!obj->setHdopi(value)) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_hdopi_move(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, int32_t p_hdopi)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_hdopi;
    typedef typename HighAccuracyGnssMetrics::HdopiType ValueType;

    ValueType value = value_from;
    
    if (!obj->setHdopi(std::move(value))) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_high_accuracy_gnss_metrics_get_pdopi(const data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics)
{
    const std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    typedef typename HighAccuracyGnssMetrics::PdopiType ResultFromType;
    const ResultFromType result_from = obj->getPdopi();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_pdopi(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, const int32_t p_pdopi)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_pdopi;
    typedef typename HighAccuracyGnssMetrics::PdopiType ValueType;

    ValueType value = value_from;
    if (!obj->setPdopi(value)) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_pdopi_move(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, int32_t p_pdopi)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_pdopi;
    typedef typename HighAccuracyGnssMetrics::PdopiType ValueType;

    ValueType value = value_from;
    
    if (!obj->setPdopi(std::move(value))) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_high_accuracy_gnss_metrics_get_age(const data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics)
{
    const std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    typedef typename HighAccuracyGnssMetrics::AgeType ResultFromType;
    const ResultFromType result_from = obj->getAge();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_age(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, const int32_t p_age)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_age;
    typedef typename HighAccuracyGnssMetrics::AgeType ValueType;

    ValueType value = value_from;
    if (!obj->setAge(value)) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_age_move(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, int32_t p_age)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_age;
    typedef typename HighAccuracyGnssMetrics::AgeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAge(std::move(value))) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_fix_type_t* data_collection_model_high_accuracy_gnss_metrics_get_fix_type(const data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics)
{
    const std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<const std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    typedef typename HighAccuracyGnssMetrics::FixTypeType ResultFromType;
    const ResultFromType result_from = obj->getFixType();
    const data_collection_model_fix_type_t *result = reinterpret_cast<const data_collection_model_fix_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_fix_type(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, const data_collection_model_fix_type_t* p_fix_type)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_fix_type;
    typedef typename HighAccuracyGnssMetrics::FixTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setFixType(value)) return NULL;
    return obj_high_accuracy_gnss_metrics;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_fix_type_move(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics, data_collection_model_fix_type_t* p_fix_type)
{
    if (obj_high_accuracy_gnss_metrics == NULL) return NULL;

    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    const auto &value_from = p_fix_type;
    typedef typename HighAccuracyGnssMetrics::FixTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setFixType(std::move(value))) return NULL;
    return obj_high_accuracy_gnss_metrics;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_high_accuracy_gnss_metrics_make_lnode(data_collection_model_high_accuracy_gnss_metrics_t *p_high_accuracy_gnss_metrics)
{
    return data_collection_lnode_create(p_high_accuracy_gnss_metrics, reinterpret_cast<void(*)(void*)>(data_collection_model_high_accuracy_gnss_metrics_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_high_accuracy_gnss_metrics_refcount(data_collection_model_high_accuracy_gnss_metrics_t *obj_high_accuracy_gnss_metrics)
{
    std::shared_ptr<HighAccuracyGnssMetrics > &obj = *reinterpret_cast<std::shared_ptr<HighAccuracyGnssMetrics >*>(obj_high_accuracy_gnss_metrics);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

