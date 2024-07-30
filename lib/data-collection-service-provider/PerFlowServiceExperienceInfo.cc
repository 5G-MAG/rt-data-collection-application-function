/**********************************************************************************************************************************
 * PerFlowServiceExperienceInfo - C interface to the PerFlowServiceExperienceInfo object
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

/*#include "PerFlowServiceExperienceInfo.h" already included by data-collection-sp/data-collection.h */
#include "PerFlowServiceExperienceInfo-internal.h"
#include "openapi/model/PerFlowServiceExperienceInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create(


)
{
    return reinterpret_cast<data_collection_model_per_flow_service_experience_info_t*>(new std::shared_ptr<PerFlowServiceExperienceInfo>(new PerFlowServiceExperienceInfo(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create_copy(const data_collection_model_per_flow_service_experience_info_t *other)
{
    return reinterpret_cast<data_collection_model_per_flow_service_experience_info_t*>(new std::shared_ptr<PerFlowServiceExperienceInfo >(new PerFlowServiceExperienceInfo(**reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create_move(data_collection_model_per_flow_service_experience_info_t *other)
{
    return reinterpret_cast<data_collection_model_per_flow_service_experience_info_t*>(new std::shared_ptr<PerFlowServiceExperienceInfo >(std::move(*reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_copy(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_per_flow_service_experience_info_t *other)
{
    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(per_flow_service_experience_info);
    *obj = **reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(other);
    return per_flow_service_experience_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_per_flow_service_experience_info_t *other)
{
    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(per_flow_service_experience_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(other));
    return per_flow_service_experience_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_per_flow_service_experience_info_free(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info)
{
    delete reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(per_flow_service_experience_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_per_flow_service_experience_info_toJSON(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, bool as_request)
{
    const std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(per_flow_service_experience_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_per_flow_service_experience_info_t*>(new std::shared_ptr<PerFlowServiceExperienceInfo >(new PerFlowServiceExperienceInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_per_flow_service_experience_info_is_equal_to(const data_collection_model_per_flow_service_experience_info_t *first, const data_collection_model_per_flow_service_experience_info_t *second)
{
    const std::shared_ptr<PerFlowServiceExperienceInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(first);
    const std::shared_ptr<PerFlowServiceExperienceInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_svc_experience_t* data_collection_model_per_flow_service_experience_info_get_service_experience(const data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info)
{
    const std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    typedef typename PerFlowServiceExperienceInfo::ServiceExperienceType ResultFromType;
    const ResultFromType result_from = obj->getServiceExperience();
    const data_collection_model_svc_experience_t *result = reinterpret_cast<const data_collection_model_svc_experience_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_service_experience(data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info, const data_collection_model_svc_experience_t* p_service_experience)
{
    if (obj_per_flow_service_experience_info == NULL) return NULL;

    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    const auto &value_from = p_service_experience;
    typedef typename PerFlowServiceExperienceInfo::ServiceExperienceType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setServiceExperience(value)) return NULL;
    return obj_per_flow_service_experience_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_service_experience_move(data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info, data_collection_model_svc_experience_t* p_service_experience)
{
    if (obj_per_flow_service_experience_info == NULL) return NULL;

    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    const auto &value_from = p_service_experience;
    typedef typename PerFlowServiceExperienceInfo::ServiceExperienceType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setServiceExperience(std::move(value))) return NULL;
    return obj_per_flow_service_experience_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_per_flow_service_experience_info_get_time_interval(const data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info)
{
    const std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    typedef typename PerFlowServiceExperienceInfo::TimeIntervalType ResultFromType;
    const ResultFromType result_from = obj->getTimeInterval();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_time_interval(data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info, const data_collection_model_time_window_t* p_time_interval)
{
    if (obj_per_flow_service_experience_info == NULL) return NULL;

    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    const auto &value_from = p_time_interval;
    typedef typename PerFlowServiceExperienceInfo::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTimeInterval(value)) return NULL;
    return obj_per_flow_service_experience_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_time_interval_move(data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info, data_collection_model_time_window_t* p_time_interval)
{
    if (obj_per_flow_service_experience_info == NULL) return NULL;

    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    const auto &value_from = p_time_interval;
    typedef typename PerFlowServiceExperienceInfo::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTimeInterval(std::move(value))) return NULL;
    return obj_per_flow_service_experience_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_addr_fqdn_t* data_collection_model_per_flow_service_experience_info_get_remote_endpoint(const data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info)
{
    const std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<const std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    typedef typename PerFlowServiceExperienceInfo::RemoteEndpointType ResultFromType;
    const ResultFromType result_from = obj->getRemoteEndpoint();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_remote_endpoint(data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info, const data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (obj_per_flow_service_experience_info == NULL) return NULL;

    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    const auto &value_from = p_remote_endpoint;
    typedef typename PerFlowServiceExperienceInfo::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRemoteEndpoint(value)) return NULL;
    return obj_per_flow_service_experience_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_remote_endpoint_move(data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info, data_collection_model_addr_fqdn_t* p_remote_endpoint)
{
    if (obj_per_flow_service_experience_info == NULL) return NULL;

    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    const auto &value_from = p_remote_endpoint;
    typedef typename PerFlowServiceExperienceInfo::RemoteEndpointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRemoteEndpoint(std::move(value))) return NULL;
    return obj_per_flow_service_experience_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_per_flow_service_experience_info_make_lnode(data_collection_model_per_flow_service_experience_info_t *p_per_flow_service_experience_info)
{
    return data_collection_lnode_create(p_per_flow_service_experience_info, reinterpret_cast<void(*)(void*)>(data_collection_model_per_flow_service_experience_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_per_flow_service_experience_info_refcount(data_collection_model_per_flow_service_experience_info_t *obj_per_flow_service_experience_info)
{
    std::shared_ptr<PerFlowServiceExperienceInfo > &obj = *reinterpret_cast<std::shared_ptr<PerFlowServiceExperienceInfo >*>(obj_per_flow_service_experience_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

