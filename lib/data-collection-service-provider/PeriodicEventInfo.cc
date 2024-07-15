/**********************************************************************************************************************************
 * PeriodicEventInfo - C interface to the PeriodicEventInfo object
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

/*#include "PeriodicEventInfo.h" already included by data-collection-sp/data-collection.h */
#include "PeriodicEventInfo-internal.h"
#include "openapi/model/PeriodicEventInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create(



)
{
    return reinterpret_cast<data_collection_model_periodic_event_info_t*>(new std::shared_ptr<PeriodicEventInfo>(new PeriodicEventInfo(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_copy(const data_collection_model_periodic_event_info_t *other)
{
    return reinterpret_cast<data_collection_model_periodic_event_info_t*>(new std::shared_ptr<PeriodicEventInfo >(new PeriodicEventInfo(**reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_move(data_collection_model_periodic_event_info_t *other)
{
    return reinterpret_cast<data_collection_model_periodic_event_info_t*>(new std::shared_ptr<PeriodicEventInfo >(std::move(*reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_copy(data_collection_model_periodic_event_info_t *periodic_event_info, const data_collection_model_periodic_event_info_t *other)
{
    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
    *obj = **reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(other);
    return periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_move(data_collection_model_periodic_event_info_t *periodic_event_info, data_collection_model_periodic_event_info_t *other)
{
    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(other));
    return periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_periodic_event_info_free(data_collection_model_periodic_event_info_t *periodic_event_info)
{
    delete reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_periodic_event_info_toJSON(const data_collection_model_periodic_event_info_t *periodic_event_info, bool as_request)
{
    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_periodic_event_info_t*>(new std::shared_ptr<PeriodicEventInfo >(new PeriodicEventInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_periodic_event_info_get_reporting_amount(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    typedef typename PeriodicEventInfo::ReportingAmountType ResultFromType;
    const ResultFromType result_from = obj->getReportingAmount();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const int32_t p_reporting_amount)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_amount;
    typedef typename PeriodicEventInfo::ReportingAmountType ValueType;

    ValueType value = value_from;
    if (!obj->setReportingAmount(value)) return NULL;
    return obj_periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, int32_t p_reporting_amount)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_amount;
    typedef typename PeriodicEventInfo::ReportingAmountType ValueType;

    ValueType value = value_from;
    
    if (!obj->setReportingAmount(std::move(value))) return NULL;
    return obj_periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_periodic_event_info_get_reporting_interval(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    typedef typename PeriodicEventInfo::ReportingIntervalType ResultFromType;
    const ResultFromType result_from = obj->getReportingInterval();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const int32_t p_reporting_interval)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_interval;
    typedef typename PeriodicEventInfo::ReportingIntervalType ValueType;

    ValueType value = value_from;
    if (!obj->setReportingInterval(value)) return NULL;
    return obj_periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, int32_t p_reporting_interval)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_interval;
    typedef typename PeriodicEventInfo::ReportingIntervalType ValueType;

    ValueType value = value_from;
    
    if (!obj->setReportingInterval(std::move(value))) return NULL;
    return obj_periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_periodic_event_info_is_reporting_infinite_ind(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    typedef typename PeriodicEventInfo::ReportingInfiniteIndType ResultFromType;
    const ResultFromType result_from = obj->isReportingInfiniteInd();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const bool p_reporting_infinite_ind)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_infinite_ind;
    typedef typename PeriodicEventInfo::ReportingInfiniteIndType ValueType;

    ValueType value = value_from;
    if (!obj->setReportingInfiniteInd(value)) return NULL;
    return obj_periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, bool p_reporting_infinite_ind)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_infinite_ind;
    typedef typename PeriodicEventInfo::ReportingInfiniteIndType ValueType;

    ValueType value = value_from;
    
    if (!obj->setReportingInfiniteInd(std::move(value))) return NULL;
    return obj_periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_periodic_event_info_get_reporting_interval_ms(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    typedef typename PeriodicEventInfo::ReportingIntervalMsType ResultFromType;
    const ResultFromType result_from = obj->getReportingIntervalMs();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const int32_t p_reporting_interval_ms)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_interval_ms;
    typedef typename PeriodicEventInfo::ReportingIntervalMsType ValueType;

    ValueType value = value_from;
    if (!obj->setReportingIntervalMs(value)) return NULL;
    return obj_periodic_event_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, int32_t p_reporting_interval_ms)
{
    if (obj_periodic_event_info == NULL) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    const auto &value_from = p_reporting_interval_ms;
    typedef typename PeriodicEventInfo::ReportingIntervalMsType ValueType;

    ValueType value = value_from;
    
    if (!obj->setReportingIntervalMs(std::move(value))) return NULL;
    return obj_periodic_event_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_periodic_event_info_make_lnode(data_collection_model_periodic_event_info_t *p_periodic_event_info)
{
    return data_collection_lnode_create(p_periodic_event_info, reinterpret_cast<void(*)(void*)>(data_collection_model_periodic_event_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_periodic_event_info_refcount(data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

