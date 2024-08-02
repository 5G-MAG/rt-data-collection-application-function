/**********************************************************************************************************************************
 * ServiceExperienceInfoPerFlow - C interface to the ServiceExperienceInfoPerFlow object
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

/*#include "ServiceExperienceInfoPerFlow.h" already included by data-collection-sp/data-collection.h */
#include "ServiceExperienceInfoPerFlow-internal.h"
#include "openapi/model/ServiceExperienceInfoPerFlow.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create(




)
{
    return reinterpret_cast<data_collection_model_service_experience_info_per_flow_t*>(new std::shared_ptr<ServiceExperienceInfoPerFlow>(new ServiceExperienceInfoPerFlow(




)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create_copy(const data_collection_model_service_experience_info_per_flow_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_service_experience_info_per_flow_t*>(new std::shared_ptr<ServiceExperienceInfoPerFlow >(new ServiceExperienceInfoPerFlow(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create_move(data_collection_model_service_experience_info_per_flow_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > *obj = reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_copy(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_service_experience_info_per_flow_t *other)
{
    if (service_experience_info_per_flow) {
        std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(service_experience_info_per_flow);
        if (obj) {
            if (other) {
                const std::shared_ptr<ServiceExperienceInfoPerFlow > &other_obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(other);
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
                const std::shared_ptr<ServiceExperienceInfoPerFlow > &other_obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(other);
                if (other_obj) {
                    obj.reset(new ServiceExperienceInfoPerFlow(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        service_experience_info_per_flow = data_collection_model_service_experience_info_per_flow_create_copy(other);
    }
    return service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_service_experience_info_per_flow_t *other)
{
    std::shared_ptr<ServiceExperienceInfoPerFlow > *other_ptr = reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(other);

    if (service_experience_info_per_flow) {
        std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(service_experience_info_per_flow);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                service_experience_info_per_flow = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_service_experience_info_per_flow_free(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow)
{
    if (!service_experience_info_per_flow) return;
    delete reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(service_experience_info_per_flow);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_service_experience_info_per_flow_toJSON(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, bool as_request)
{
    if (!service_experience_info_per_flow) return NULL;
    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(service_experience_info_per_flow);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_service_experience_info_per_flow_t*>(new std::shared_ptr<ServiceExperienceInfoPerFlow >(new ServiceExperienceInfoPerFlow(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_service_experience_info_per_flow_is_equal_to(const data_collection_model_service_experience_info_per_flow_t *first, const data_collection_model_service_experience_info_per_flow_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj2 = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj1 = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_svc_experience_t* data_collection_model_service_experience_info_per_flow_get_svc_exprc(const data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow)
{
    if (!obj_service_experience_info_per_flow) {
        const data_collection_model_svc_experience_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) {
        const data_collection_model_svc_experience_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerFlow::SvcExprcType ResultFromType;
    const ResultFromType result_from = obj->getSvcExprc();
    const data_collection_model_svc_experience_t *result = reinterpret_cast<const data_collection_model_svc_experience_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_svc_exprc(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, const data_collection_model_svc_experience_t* p_svc_exprc)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exprc;
    typedef typename ServiceExperienceInfoPerFlow::SvcExprcType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSvcExprc(value)) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_svc_exprc_move(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, data_collection_model_svc_experience_t* p_svc_exprc)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exprc;
    typedef typename ServiceExperienceInfoPerFlow::SvcExprcType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSvcExprc(std::move(value))) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_service_experience_info_per_flow_get_time_intev(const data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow)
{
    if (!obj_service_experience_info_per_flow) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerFlow::TimeIntevType ResultFromType;
    const ResultFromType result_from = obj->getTimeIntev();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_time_intev(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, const data_collection_model_time_window_t* p_time_intev)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_time_intev;
    typedef typename ServiceExperienceInfoPerFlow::TimeIntevType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTimeIntev(value)) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_time_intev_move(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, data_collection_model_time_window_t* p_time_intev)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_time_intev;
    typedef typename ServiceExperienceInfoPerFlow::TimeIntevType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTimeIntev(std::move(value))) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_service_experience_info_per_flow_get_dnai(const data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow)
{
    if (!obj_service_experience_info_per_flow) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerFlow::DnaiType ResultFromType;
    const ResultFromType result_from = obj->getDnai();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_dnai(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, const char* p_dnai)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_dnai;
    typedef typename ServiceExperienceInfoPerFlow::DnaiType ValueType;

    ValueType value(value_from);
    if (!obj->setDnai(value)) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_dnai_move(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, char* p_dnai)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_dnai;
    typedef typename ServiceExperienceInfoPerFlow::DnaiType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDnai(std::move(value))) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_flow_info_t* data_collection_model_service_experience_info_per_flow_get_ip_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow)
{
    if (!obj_service_experience_info_per_flow) {
        const data_collection_model_flow_info_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) {
        const data_collection_model_flow_info_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerFlow::IpTrafficFilterType ResultFromType;
    const ResultFromType result_from = obj->getIpTrafficFilter();
    const data_collection_model_flow_info_t *result = reinterpret_cast<const data_collection_model_flow_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_ip_traffic_filter(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, const data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_ip_traffic_filter;
    typedef typename ServiceExperienceInfoPerFlow::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIpTrafficFilter(value)) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_ip_traffic_filter_move(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_ip_traffic_filter;
    typedef typename ServiceExperienceInfoPerFlow::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIpTrafficFilter(std::move(value))) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_eth_flow_description_t* data_collection_model_service_experience_info_per_flow_get_eth_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow)
{
    if (!obj_service_experience_info_per_flow) {
        const data_collection_model_eth_flow_description_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) {
        const data_collection_model_eth_flow_description_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerFlow::EthTrafficFilterType ResultFromType;
    const ResultFromType result_from = obj->getEthTrafficFilter();
    const data_collection_model_eth_flow_description_t *result = reinterpret_cast<const data_collection_model_eth_flow_description_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_eth_traffic_filter(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, const data_collection_model_eth_flow_description_t* p_eth_traffic_filter)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_eth_traffic_filter;
    typedef typename ServiceExperienceInfoPerFlow::EthTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEthTrafficFilter(value)) return NULL;

    return obj_service_experience_info_per_flow;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_eth_traffic_filter_move(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow, data_collection_model_eth_flow_description_t* p_eth_traffic_filter)
{
    if (!obj_service_experience_info_per_flow) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    if (!obj) return NULL;

    const auto &value_from = p_eth_traffic_filter;
    typedef typename ServiceExperienceInfoPerFlow::EthTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEthTrafficFilter(std::move(value))) return NULL;

    return obj_service_experience_info_per_flow;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_service_experience_info_per_flow_make_lnode(data_collection_model_service_experience_info_per_flow_t *p_service_experience_info_per_flow)
{
    return data_collection_lnode_create(p_service_experience_info_per_flow, reinterpret_cast<void(*)(void*)>(data_collection_model_service_experience_info_per_flow_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_service_experience_info_per_flow_refcount(data_collection_model_service_experience_info_per_flow_t *obj_service_experience_info_per_flow)
{
    if (!obj_service_experience_info_per_flow) return 0l;
    std::shared_ptr<ServiceExperienceInfoPerFlow > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerFlow >*>(obj_service_experience_info_per_flow);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

