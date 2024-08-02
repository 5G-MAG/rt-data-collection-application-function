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
    if (!other) return NULL;
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_af_event_t*>(new std::shared_ptr<AfEvent >(new AfEvent(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_create_move(data_collection_model_af_event_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AfEvent > *obj = reinterpret_cast<std::shared_ptr<AfEvent >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_copy(data_collection_model_af_event_t *af_event, const data_collection_model_af_event_t *other)
{
    if (af_event) {
        std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(af_event);
        if (obj) {
            if (other) {
                const std::shared_ptr<AfEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(other);
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
                const std::shared_ptr<AfEvent > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(other);
                if (other_obj) {
                    obj.reset(new AfEvent(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        af_event = data_collection_model_af_event_create_copy(other);
    }
    return af_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_t *data_collection_model_af_event_move(data_collection_model_af_event_t *af_event, data_collection_model_af_event_t *other)
{
    std::shared_ptr<AfEvent > *other_ptr = reinterpret_cast<std::shared_ptr<AfEvent >*>(other);

    if (af_event) {
        std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(af_event);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                af_event = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return af_event;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_af_event_free(data_collection_model_af_event_t *af_event)
{
    if (!af_event) return;
    delete reinterpret_cast<std::shared_ptr<AfEvent >*>(af_event);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_af_event_toJSON(const data_collection_model_af_event_t *af_event, bool as_request)
{
    if (!af_event) return NULL;
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(af_event);
    if (!obj) return NULL;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_af_event_is_equal_to(const data_collection_model_af_event_t *first, const data_collection_model_af_event_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AfEvent > &obj2 = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AfEvent > &obj1 = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_is_not_set(const data_collection_model_af_event_t *obj_af_event)
{
    if (!obj_af_event) return true;
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    if (!obj) return true;
    return obj->getValue() == AfEvent::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_is_non_standard(const data_collection_model_af_event_t *obj_af_event)
{
    if (!obj_af_event) return false;
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    if (!obj) return false;
    return obj->getValue() == AfEvent::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_e data_collection_model_af_event_get_enum(const data_collection_model_af_event_t *obj_af_event)
{
    if (!obj_af_event)
        return DCM_AF_EVENT_NO_VAL;
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    if (!obj) return DCM_AF_EVENT_NO_VAL;
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
    if (!obj_af_event) return NULL;
    const std::shared_ptr<AfEvent > &obj = *reinterpret_cast<const std::shared_ptr<AfEvent >*>(obj_af_event);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_set_enum(data_collection_model_af_event_t *obj_af_event, data_collection_model_af_event_e p_value)
{
    if (!obj_af_event) return false;
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(obj_af_event);
    if (!obj) return false;
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
    if (!obj_af_event) return false;
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(obj_af_event);
    if (!obj) return false;
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
    if (!obj_af_event) return 0l;
    std::shared_ptr<AfEvent > &obj = *reinterpret_cast<std::shared_ptr<AfEvent >*>(obj_af_event);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

