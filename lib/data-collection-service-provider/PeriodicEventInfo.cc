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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "PeriodicEventInfo.h" already included by data-collection-sp/data-collection.h */
#include "PeriodicEventInfo-internal.h"
#include "openapi/model/PeriodicEventInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create(



)
{
    return reinterpret_cast<data_collection_model_periodic_event_info_t*>(new std::shared_ptr<PeriodicEventInfo>(new PeriodicEventInfo(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_copy(const data_collection_model_periodic_event_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_periodic_event_info_t*>(new std::shared_ptr<PeriodicEventInfo >(new PeriodicEventInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_move(data_collection_model_periodic_event_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PeriodicEventInfo > *obj = reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_copy(data_collection_model_periodic_event_info_t *periodic_event_info, const data_collection_model_periodic_event_info_t *other)
{
    if (periodic_event_info) {
        std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<PeriodicEventInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(other);
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
                const std::shared_ptr<PeriodicEventInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(other);
                if (other_obj) {
                    obj.reset(new PeriodicEventInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        periodic_event_info = data_collection_model_periodic_event_info_create_copy(other);
    }
    return periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_move(data_collection_model_periodic_event_info_t *periodic_event_info, data_collection_model_periodic_event_info_t *other)
{
    std::shared_ptr<PeriodicEventInfo > *other_ptr = reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(other);

    if (periodic_event_info) {
        std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                periodic_event_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_periodic_event_info_free(data_collection_model_periodic_event_info_t *periodic_event_info)
{
    if (!periodic_event_info) return;
    delete reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_periodic_event_info_toJSON(const data_collection_model_periodic_event_info_t *periodic_event_info, bool as_request)
{
    if (!periodic_event_info) return NULL;
    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(periodic_event_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_periodic_event_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_periodic_event_info_is_equal_to(const data_collection_model_periodic_event_info_t *first, const data_collection_model_periodic_event_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PeriodicEventInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PeriodicEventInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_amount(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    if (!obj_periodic_event_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PeriodicEventInfo::ReportingAmountType ResultFromType;
    const ResultFromType &result_from = obj->getReportingAmount();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const int32_t p_reporting_amount)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_amount;
    typedef typename PeriodicEventInfo::ReportingAmountType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingAmount(value)) return NULL;

    return obj_periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, int32_t p_reporting_amount)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_amount;
    typedef typename PeriodicEventInfo::ReportingAmountType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingAmount(std::move(value))) return NULL;

    return obj_periodic_event_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_interval(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    if (!obj_periodic_event_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PeriodicEventInfo::ReportingIntervalType ResultFromType;
    const ResultFromType &result_from = obj->getReportingInterval();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const int32_t p_reporting_interval)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_interval;
    typedef typename PeriodicEventInfo::ReportingIntervalType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingInterval(value)) return NULL;

    return obj_periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, int32_t p_reporting_interval)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_interval;
    typedef typename PeriodicEventInfo::ReportingIntervalType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingInterval(std::move(value))) return NULL;

    return obj_periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_periodic_event_info_has_reporting_infinite_ind(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    if (!obj_periodic_event_info) return false;

    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return false;

    return obj->isReportingInfiniteInd().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_periodic_event_info_is_reporting_infinite_ind(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    if (!obj_periodic_event_info) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename PeriodicEventInfo::ReportingInfiniteIndType ResultFromType;
    const ResultFromType &result_from = obj->isReportingInfiniteInd();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const bool p_reporting_infinite_ind)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_infinite_ind;
    typedef typename PeriodicEventInfo::ReportingInfiniteIndType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingInfiniteInd(value)) return NULL;

    return obj_periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, bool p_reporting_infinite_ind)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_infinite_ind;
    typedef typename PeriodicEventInfo::ReportingInfiniteIndType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingInfiniteInd(std::move(value))) return NULL;

    return obj_periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_periodic_event_info_has_reporting_interval_ms(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    if (!obj_periodic_event_info) return false;

    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return false;

    return obj->getReportingIntervalMs().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_interval_ms(const data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    if (!obj_periodic_event_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<const std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PeriodicEventInfo::ReportingIntervalMsType ResultFromType;
    const ResultFromType &result_from = obj->getReportingIntervalMs();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms(data_collection_model_periodic_event_info_t *obj_periodic_event_info, const int32_t p_reporting_interval_ms)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_interval_ms;
    typedef typename PeriodicEventInfo::ReportingIntervalMsType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingIntervalMs(value)) return NULL;

    return obj_periodic_event_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms_move(data_collection_model_periodic_event_info_t *obj_periodic_event_info, int32_t p_reporting_interval_ms)
{
    if (!obj_periodic_event_info) return NULL;

    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    if (!obj) return NULL;

    const auto &value_from = p_reporting_interval_ms;
    typedef typename PeriodicEventInfo::ReportingIntervalMsType ValueType;

    ValueType value(value_from);

    if (!obj->setReportingIntervalMs(std::move(value))) return NULL;

    return obj_periodic_event_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_periodic_event_info_make_lnode(data_collection_model_periodic_event_info_t *p_periodic_event_info)
{
    return data_collection_lnode_create(p_periodic_event_info, reinterpret_cast<void(*)(void*)>(data_collection_model_periodic_event_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_periodic_event_info_refcount(data_collection_model_periodic_event_info_t *obj_periodic_event_info)
{
    if (!obj_periodic_event_info) return 0l;
    std::shared_ptr<PeriodicEventInfo > &obj = *reinterpret_cast<std::shared_ptr<PeriodicEventInfo >*>(obj_periodic_event_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

