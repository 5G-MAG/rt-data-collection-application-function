/**********************************************************************************************************************************
 * UsageThreshold - C interface to the UsageThreshold object
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

/*#include "UsageThreshold.h" already included by data-collection-sp/data-collection.h */
#include "UsageThreshold-internal.h"
#include "openapi/model/UsageThreshold.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create(



)
{
    return reinterpret_cast<data_collection_model_usage_threshold_t*>(new std::shared_ptr<UsageThreshold>(new UsageThreshold(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create_copy(const data_collection_model_usage_threshold_t *other)
{
    return reinterpret_cast<data_collection_model_usage_threshold_t*>(new std::shared_ptr<UsageThreshold >(new UsageThreshold(**reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create_move(data_collection_model_usage_threshold_t *other)
{
    return reinterpret_cast<data_collection_model_usage_threshold_t*>(new std::shared_ptr<UsageThreshold >(std::move(*reinterpret_cast<std::shared_ptr<UsageThreshold >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_copy(data_collection_model_usage_threshold_t *usage_threshold, const data_collection_model_usage_threshold_t *other)
{
    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(usage_threshold);
    *obj = **reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(other);
    return usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_move(data_collection_model_usage_threshold_t *usage_threshold, data_collection_model_usage_threshold_t *other)
{
    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(usage_threshold);
    obj = std::move(*reinterpret_cast<std::shared_ptr<UsageThreshold >*>(other));
    return usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_usage_threshold_free(data_collection_model_usage_threshold_t *usage_threshold)
{
    delete reinterpret_cast<std::shared_ptr<UsageThreshold >*>(usage_threshold);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_usage_threshold_toJSON(const data_collection_model_usage_threshold_t *usage_threshold, bool as_request)
{
    const std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(usage_threshold);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_usage_threshold_t*>(new std::shared_ptr<UsageThreshold >(new UsageThreshold(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_usage_threshold_is_equal_to(const data_collection_model_usage_threshold_t *first, const data_collection_model_usage_threshold_t *second)
{
    const std::shared_ptr<UsageThreshold > &obj1 = *reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(first);
    const std::shared_ptr<UsageThreshold > &obj2 = *reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_usage_threshold_get_duration(const data_collection_model_usage_threshold_t *obj_usage_threshold)
{
    const std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    typedef typename UsageThreshold::DurationType ResultFromType;
    const ResultFromType result_from = obj->getDuration();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_duration(data_collection_model_usage_threshold_t *obj_usage_threshold, const int32_t p_duration)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_duration;
    typedef typename UsageThreshold::DurationType ValueType;

    ValueType value = value_from;
    if (!obj->setDuration(value)) return NULL;
    return obj_usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_duration_move(data_collection_model_usage_threshold_t *obj_usage_threshold, int32_t p_duration)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_duration;
    typedef typename UsageThreshold::DurationType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDuration(std::move(value))) return NULL;
    return obj_usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_usage_threshold_get_total_volume(const data_collection_model_usage_threshold_t *obj_usage_threshold)
{
    const std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    typedef typename UsageThreshold::TotalVolumeType ResultFromType;
    const ResultFromType result_from = obj->getTotalVolume();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_total_volume(data_collection_model_usage_threshold_t *obj_usage_threshold, const int64_t p_total_volume)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_total_volume;
    typedef typename UsageThreshold::TotalVolumeType ValueType;

    ValueType value = value_from;
    if (!obj->setTotalVolume(value)) return NULL;
    return obj_usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_total_volume_move(data_collection_model_usage_threshold_t *obj_usage_threshold, int64_t p_total_volume)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_total_volume;
    typedef typename UsageThreshold::TotalVolumeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setTotalVolume(std::move(value))) return NULL;
    return obj_usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_usage_threshold_get_downlink_volume(const data_collection_model_usage_threshold_t *obj_usage_threshold)
{
    const std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    typedef typename UsageThreshold::DownlinkVolumeType ResultFromType;
    const ResultFromType result_from = obj->getDownlinkVolume();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_downlink_volume(data_collection_model_usage_threshold_t *obj_usage_threshold, const int64_t p_downlink_volume)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_downlink_volume;
    typedef typename UsageThreshold::DownlinkVolumeType ValueType;

    ValueType value = value_from;
    if (!obj->setDownlinkVolume(value)) return NULL;
    return obj_usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_downlink_volume_move(data_collection_model_usage_threshold_t *obj_usage_threshold, int64_t p_downlink_volume)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_downlink_volume;
    typedef typename UsageThreshold::DownlinkVolumeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDownlinkVolume(std::move(value))) return NULL;
    return obj_usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_usage_threshold_get_uplink_volume(const data_collection_model_usage_threshold_t *obj_usage_threshold)
{
    const std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<const std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    typedef typename UsageThreshold::UplinkVolumeType ResultFromType;
    const ResultFromType result_from = obj->getUplinkVolume();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_uplink_volume(data_collection_model_usage_threshold_t *obj_usage_threshold, const int64_t p_uplink_volume)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_uplink_volume;
    typedef typename UsageThreshold::UplinkVolumeType ValueType;

    ValueType value = value_from;
    if (!obj->setUplinkVolume(value)) return NULL;
    return obj_usage_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_uplink_volume_move(data_collection_model_usage_threshold_t *obj_usage_threshold, int64_t p_uplink_volume)
{
    if (obj_usage_threshold == NULL) return NULL;

    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    const auto &value_from = p_uplink_volume;
    typedef typename UsageThreshold::UplinkVolumeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUplinkVolume(std::move(value))) return NULL;
    return obj_usage_threshold;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_usage_threshold_make_lnode(data_collection_model_usage_threshold_t *p_usage_threshold)
{
    return data_collection_lnode_create(p_usage_threshold, reinterpret_cast<void(*)(void*)>(data_collection_model_usage_threshold_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_usage_threshold_refcount(data_collection_model_usage_threshold_t *obj_usage_threshold)
{
    std::shared_ptr<UsageThreshold > &obj = *reinterpret_cast<std::shared_ptr<UsageThreshold >*>(obj_usage_threshold);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

