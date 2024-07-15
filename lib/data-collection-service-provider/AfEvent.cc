/**********************************************************************************************************************************
 * AfEvent - C interface to the AfEvent object
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

/*#include "AfEvent.h" already included by data-collection-sp/data-collection.h */
#include "AfEvent-internal.h"
#include "openapi/model/AfEvent.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_create()
{
    return reinterpret_cast<data_collection_model_af_event_t*>(new std::shared_ptr<AfEvent>(new AfEvent()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_create_copy(const data_collection_model_af_event_t *other)
{
    return reinterpret_cast<data_collection_model_af_event_t*>(new std::shared_ptr<AfEvent >(new AfEvent(**reinterpret_cast<const std::shared_ptr<AfEvent >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_create_move(data_collection_model_af_event_t *other)
{
    return reinterpret_cast<data_collection_model_af_event_t*>(new std::shared_ptr<AfEvent >(std::move(*reinterpret_cast<std::shared_ptr<AfEvent >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_copy(data_collection_model_af_event_t *af_event, const data_collection_model_af_event_t *other)
{
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(af_event);
    *obj = **reinterpret_cast<const std::shared_ptr<AfEvent >*>(other);
    return af_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_move(data_collection_model_af_event_t *af_event, data_collection_model_af_event_t *other)
{
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(af_event);
    obj = std::move(*reinterpret_cast<std::shared_ptr<AfEvent >*>(other));
    return af_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_af_event_free(data_collection_model_af_event_t *af_event)
{
    delete reinterpret_cast<std::shared_ptr<AfEvent >*>(af_event);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_af_event_toJSON(const data_collection_model_af_event_t *af_event, bool as_request)
{
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(af_event);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_af_event_t*>(new std::shared_ptr<AfEvent >(new AfEvent(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_is_not_set(const data_collection_model_af_event_t *obj_af_event)
{
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    return obj->getValue() == AfEvent::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_is_non_standard(const data_collection_model_af_event_t *obj_af_event)
{
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    return obj->getValue() == AfEvent::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_e data_collection_model_af_event_get_enum(const data_collection_model_af_event_t *obj_af_event)
{
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    switch (obj->getValue()) {
    case AfEvent::Enum::NO_VAL:
        return DCM_AF_EVENT_NO_VAL;
    case AfEvent::Enum::VAL_SVC_EXPERIENCE:
        return DCM_AF_EVENT_VAL_SVC_EXPERIENCE;
    case AfEvent::Enum::VAL_UE_MOBILITY:
        return DCM_AF_EVENT_VAL_UE_MOBILITY;
    case AfEvent::Enum::VAL_UE_COMM:
        return DCM_AF_EVENT_VAL_UE_COMM;
    case AfEvent::Enum::VAL_EXCEPTIONS:
        return DCM_AF_EVENT_VAL_EXCEPTIONS;
    case AfEvent::Enum::VAL_USER_DATA_CONGESTION:
        return DCM_AF_EVENT_VAL_USER_DATA_CONGESTION;
    case AfEvent::Enum::VAL_PERF_DATA:
        return DCM_AF_EVENT_VAL_PERF_DATA;
    case AfEvent::Enum::VAL_DISPERSION:
        return DCM_AF_EVENT_VAL_DISPERSION;
    case AfEvent::Enum::VAL_COLLECTIVE_BEHAVIOUR:
        return DCM_AF_EVENT_VAL_COLLECTIVE_BEHAVIOUR;
    case AfEvent::Enum::VAL_MS_QOE_METRICS:
        return DCM_AF_EVENT_VAL_MS_QOE_METRICS;
    case AfEvent::Enum::VAL_MS_CONSUMPTION:
        return DCM_AF_EVENT_VAL_MS_CONSUMPTION;
    case AfEvent::Enum::VAL_MS_NET_ASSIST_INVOCATION:
        return DCM_AF_EVENT_VAL_MS_NET_ASSIST_INVOCATION;
    case AfEvent::Enum::VAL_MS_DYN_POLICY_INVOCATION:
        return DCM_AF_EVENT_VAL_MS_DYN_POLICY_INVOCATION;
    case AfEvent::Enum::VAL_MS_ACCESS_ACTIVITY:
        return DCM_AF_EVENT_VAL_MS_ACCESS_ACTIVITY;
    case AfEvent::Enum::VAL_GNSS_ASSISTANCE_DATA:
        return DCM_AF_EVENT_VAL_GNSS_ASSISTANCE_DATA;
    case AfEvent::Enum::VAL_DATA_VOLUME_TRANSFER_TIME:
        return DCM_AF_EVENT_VAL_DATA_VOLUME_TRANSFER_TIME;
    default:
        break;
    }
    return DCM_AF_EVENT_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_af_event_get_string(const data_collection_model_af_event_t *obj_af_event)
{
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_set_enum(data_collection_model_af_event_t *obj_af_event, data_collection_model_af_event_e p_value)
{
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(obj_af_event);
    switch (p_value) {
    case DCM_AF_EVENT_NO_VAL:
        *obj = AfEvent::Enum::NO_VAL;
        return true;
    case DCM_AF_EVENT_VAL_SVC_EXPERIENCE:
        *obj = AfEvent::Enum::VAL_SVC_EXPERIENCE;
        return true;
    case DCM_AF_EVENT_VAL_UE_MOBILITY:
        *obj = AfEvent::Enum::VAL_UE_MOBILITY;
        return true;
    case DCM_AF_EVENT_VAL_UE_COMM:
        *obj = AfEvent::Enum::VAL_UE_COMM;
        return true;
    case DCM_AF_EVENT_VAL_EXCEPTIONS:
        *obj = AfEvent::Enum::VAL_EXCEPTIONS;
        return true;
    case DCM_AF_EVENT_VAL_USER_DATA_CONGESTION:
        *obj = AfEvent::Enum::VAL_USER_DATA_CONGESTION;
        return true;
    case DCM_AF_EVENT_VAL_PERF_DATA:
        *obj = AfEvent::Enum::VAL_PERF_DATA;
        return true;
    case DCM_AF_EVENT_VAL_DISPERSION:
        *obj = AfEvent::Enum::VAL_DISPERSION;
        return true;
    case DCM_AF_EVENT_VAL_COLLECTIVE_BEHAVIOUR:
        *obj = AfEvent::Enum::VAL_COLLECTIVE_BEHAVIOUR;
        return true;
    case DCM_AF_EVENT_VAL_MS_QOE_METRICS:
        *obj = AfEvent::Enum::VAL_MS_QOE_METRICS;
        return true;
    case DCM_AF_EVENT_VAL_MS_CONSUMPTION:
        *obj = AfEvent::Enum::VAL_MS_CONSUMPTION;
        return true;
    case DCM_AF_EVENT_VAL_MS_NET_ASSIST_INVOCATION:
        *obj = AfEvent::Enum::VAL_MS_NET_ASSIST_INVOCATION;
        return true;
    case DCM_AF_EVENT_VAL_MS_DYN_POLICY_INVOCATION:
        *obj = AfEvent::Enum::VAL_MS_DYN_POLICY_INVOCATION;
        return true;
    case DCM_AF_EVENT_VAL_MS_ACCESS_ACTIVITY:
        *obj = AfEvent::Enum::VAL_MS_ACCESS_ACTIVITY;
        return true;
    case DCM_AF_EVENT_VAL_GNSS_ASSISTANCE_DATA:
        *obj = AfEvent::Enum::VAL_GNSS_ASSISTANCE_DATA;
        return true;
    case DCM_AF_EVENT_VAL_DATA_VOLUME_TRANSFER_TIME:
        *obj = AfEvent::Enum::VAL_DATA_VOLUME_TRANSFER_TIME;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_set_string(data_collection_model_af_event_t *obj_af_event, const char *p_value)
{
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(obj_af_event);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = AfEvent::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_af_event_make_lnode(data_collection_model_af_event_t *p_af_event)
{
    return data_collection_lnode_create(p_af_event, reinterpret_cast<void(*)(void*)>(data_collection_model_af_event_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_af_event_refcount(data_collection_model_af_event_t *obj_af_event)
{
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(obj_af_event);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

