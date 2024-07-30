/**********************************************************************************************************************************
 * AfEvent_anyOf - C interface to the AfEvent_anyOf object
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

/*#include "AfEvent_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "AfEvent_anyOf-internal.h"
#include "openapi/model/AfEvent_anyOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_any_of_t *data_collection_model_af_event_any_of_create()
{
    return reinterpret_cast<data_collection_model_af_event_any_of_t*>(new std::shared_ptr<AfEvent_anyOf>(new AfEvent_anyOf()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_any_of_t *data_collection_model_af_event_any_of_create_copy(const data_collection_model_af_event_any_of_t *other)
{
    return reinterpret_cast<data_collection_model_af_event_any_of_t*>(new std::shared_ptr<AfEvent_anyOf >(new AfEvent_anyOf(**reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_any_of_t *data_collection_model_af_event_any_of_create_move(data_collection_model_af_event_any_of_t *other)
{
    return reinterpret_cast<data_collection_model_af_event_any_of_t*>(new std::shared_ptr<AfEvent_anyOf >(std::move(*reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_any_of_t *data_collection_model_af_event_any_of_copy(data_collection_model_af_event_any_of_t *af_event_any_of, const data_collection_model_af_event_any_of_t *other)
{
    std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(af_event_any_of);
    *obj = **reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(other);
    return af_event_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_any_of_t *data_collection_model_af_event_any_of_move(data_collection_model_af_event_any_of_t *af_event_any_of, data_collection_model_af_event_any_of_t *other)
{
    std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(af_event_any_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(other));
    return af_event_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_af_event_any_of_free(data_collection_model_af_event_any_of_t *af_event_any_of)
{
    delete reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(af_event_any_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_af_event_any_of_toJSON(const data_collection_model_af_event_any_of_t *af_event_any_of, bool as_request)
{
    const std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(af_event_any_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_any_of_t *data_collection_model_af_event_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_af_event_any_of_t*>(new std::shared_ptr<AfEvent_anyOf >(new AfEvent_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_af_event_any_of_is_equal_to(const data_collection_model_af_event_any_of_t *first, const data_collection_model_af_event_any_of_t *second)
{
    const std::shared_ptr<AfEvent_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(first);
    const std::shared_ptr<AfEvent_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_any_of_is_not_set(const data_collection_model_af_event_any_of_t *af_event_any_of)
{
    const std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(af_event_any_of);
    return obj->getValue() == AfEvent_anyOf::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_any_of_e data_collection_model_af_event_any_of_get_enum(const data_collection_model_af_event_any_of_t *obj_af_event_any_of)
{
    const std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(obj_af_event_any_of);
    switch (obj->getValue()) {
    case AfEvent_anyOf::Enum::NO_VAL:
        return DCM_AF_EVENT_ANY_OF_NO_VAL;
    case AfEvent_anyOf::Enum::VAL_SVC_EXPERIENCE:
        return DCM_AF_EVENT_ANY_OF_VAL_SVC_EXPERIENCE;
    case AfEvent_anyOf::Enum::VAL_UE_MOBILITY:
        return DCM_AF_EVENT_ANY_OF_VAL_UE_MOBILITY;
    case AfEvent_anyOf::Enum::VAL_UE_COMM:
        return DCM_AF_EVENT_ANY_OF_VAL_UE_COMM;
    case AfEvent_anyOf::Enum::VAL_EXCEPTIONS:
        return DCM_AF_EVENT_ANY_OF_VAL_EXCEPTIONS;
    case AfEvent_anyOf::Enum::VAL_USER_DATA_CONGESTION:
        return DCM_AF_EVENT_ANY_OF_VAL_USER_DATA_CONGESTION;
    case AfEvent_anyOf::Enum::VAL_PERF_DATA:
        return DCM_AF_EVENT_ANY_OF_VAL_PERF_DATA;
    case AfEvent_anyOf::Enum::VAL_DISPERSION:
        return DCM_AF_EVENT_ANY_OF_VAL_DISPERSION;
    case AfEvent_anyOf::Enum::VAL_COLLECTIVE_BEHAVIOUR:
        return DCM_AF_EVENT_ANY_OF_VAL_COLLECTIVE_BEHAVIOUR;
    case AfEvent_anyOf::Enum::VAL_MS_QOE_METRICS:
        return DCM_AF_EVENT_ANY_OF_VAL_MS_QOE_METRICS;
    case AfEvent_anyOf::Enum::VAL_MS_CONSUMPTION:
        return DCM_AF_EVENT_ANY_OF_VAL_MS_CONSUMPTION;
    case AfEvent_anyOf::Enum::VAL_MS_NET_ASSIST_INVOCATION:
        return DCM_AF_EVENT_ANY_OF_VAL_MS_NET_ASSIST_INVOCATION;
    case AfEvent_anyOf::Enum::VAL_MS_DYN_POLICY_INVOCATION:
        return DCM_AF_EVENT_ANY_OF_VAL_MS_DYN_POLICY_INVOCATION;
    case AfEvent_anyOf::Enum::VAL_MS_ACCESS_ACTIVITY:
        return DCM_AF_EVENT_ANY_OF_VAL_MS_ACCESS_ACTIVITY;
    case AfEvent_anyOf::Enum::VAL_GNSS_ASSISTANCE_DATA:
        return DCM_AF_EVENT_ANY_OF_VAL_GNSS_ASSISTANCE_DATA;
    case AfEvent_anyOf::Enum::VAL_DATA_VOLUME_TRANSFER_TIME:
        return DCM_AF_EVENT_ANY_OF_VAL_DATA_VOLUME_TRANSFER_TIME;
    default:
        break;
    }
    return (data_collection_model_af_event_any_of_e)-1;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_af_event_any_of_get_string(const data_collection_model_af_event_any_of_t *obj_af_event_any_of)
{
    const std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent_anyOf >*>(obj_af_event_any_of);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_any_of_set_enum(data_collection_model_af_event_any_of_t *obj_af_event_any_of, data_collection_model_af_event_any_of_e p_value)
{
    std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(obj_af_event_any_of);
    switch (p_value) {
    case DCM_AF_EVENT_ANY_OF_NO_VAL:
        *obj = AfEvent_anyOf::Enum::NO_VAL;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_SVC_EXPERIENCE:
        *obj = AfEvent_anyOf::Enum::VAL_SVC_EXPERIENCE;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_UE_MOBILITY:
        *obj = AfEvent_anyOf::Enum::VAL_UE_MOBILITY;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_UE_COMM:
        *obj = AfEvent_anyOf::Enum::VAL_UE_COMM;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_EXCEPTIONS:
        *obj = AfEvent_anyOf::Enum::VAL_EXCEPTIONS;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_USER_DATA_CONGESTION:
        *obj = AfEvent_anyOf::Enum::VAL_USER_DATA_CONGESTION;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_PERF_DATA:
        *obj = AfEvent_anyOf::Enum::VAL_PERF_DATA;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_DISPERSION:
        *obj = AfEvent_anyOf::Enum::VAL_DISPERSION;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_COLLECTIVE_BEHAVIOUR:
        *obj = AfEvent_anyOf::Enum::VAL_COLLECTIVE_BEHAVIOUR;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_MS_QOE_METRICS:
        *obj = AfEvent_anyOf::Enum::VAL_MS_QOE_METRICS;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_MS_CONSUMPTION:
        *obj = AfEvent_anyOf::Enum::VAL_MS_CONSUMPTION;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_MS_NET_ASSIST_INVOCATION:
        *obj = AfEvent_anyOf::Enum::VAL_MS_NET_ASSIST_INVOCATION;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_MS_DYN_POLICY_INVOCATION:
        *obj = AfEvent_anyOf::Enum::VAL_MS_DYN_POLICY_INVOCATION;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_MS_ACCESS_ACTIVITY:
        *obj = AfEvent_anyOf::Enum::VAL_MS_ACCESS_ACTIVITY;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_GNSS_ASSISTANCE_DATA:
        *obj = AfEvent_anyOf::Enum::VAL_GNSS_ASSISTANCE_DATA;
        return true;
    case DCM_AF_EVENT_ANY_OF_VAL_DATA_VOLUME_TRANSFER_TIME:
        *obj = AfEvent_anyOf::Enum::VAL_DATA_VOLUME_TRANSFER_TIME;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_any_of_set_string(data_collection_model_af_event_any_of_t *obj_af_event_any_of, const char *p_value)
{
    std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(obj_af_event_any_of);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = AfEvent_anyOf::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_af_event_any_of_make_lnode(data_collection_model_af_event_any_of_t *p_af_event_any_of)
{
    return data_collection_lnode_create(p_af_event_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_af_event_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_af_event_any_of_refcount(data_collection_model_af_event_any_of_t *obj_af_event_any_of)
{
    std::shared_ptr<AfEvent_anyOf > &obj = *reinterpret_cast<std::shared_ptr<AfEvent_anyOf >*>(obj_af_event_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

