/**********************************************************************************************************************************
 * TrafficProfile - C interface to the TrafficProfile object
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

/*#include "TrafficProfile.h" already included by data-collection-sp/data-collection.h */
#include "TrafficProfile-internal.h"
#include "openapi/model/TrafficProfile.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create()
{
    return reinterpret_cast<data_collection_model_traffic_profile_t*>(new std::shared_ptr<TrafficProfile>(new TrafficProfile()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create_copy(const data_collection_model_traffic_profile_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_traffic_profile_t*>(new std::shared_ptr<TrafficProfile >(new TrafficProfile(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create_move(data_collection_model_traffic_profile_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<TrafficProfile > *obj = reinterpret_cast<std::shared_ptr<TrafficProfile >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_copy(data_collection_model_traffic_profile_t *traffic_profile, const data_collection_model_traffic_profile_t *other)
{
    if (traffic_profile) {
        std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(traffic_profile);
        if (obj) {
            if (other) {
                const std::shared_ptr<TrafficProfile > &other_obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(other);
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
                const std::shared_ptr<TrafficProfile > &other_obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(other);
                if (other_obj) {
                    obj.reset(new TrafficProfile(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        traffic_profile = data_collection_model_traffic_profile_create_copy(other);
    }
    return traffic_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_move(data_collection_model_traffic_profile_t *traffic_profile, data_collection_model_traffic_profile_t *other)
{
    std::shared_ptr<TrafficProfile > *other_ptr = reinterpret_cast<std::shared_ptr<TrafficProfile >*>(other);

    if (traffic_profile) {
        std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(traffic_profile);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                traffic_profile = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return traffic_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_traffic_profile_free(data_collection_model_traffic_profile_t *traffic_profile)
{
    if (!traffic_profile) return;
    delete reinterpret_cast<std::shared_ptr<TrafficProfile >*>(traffic_profile);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_traffic_profile_toJSON(const data_collection_model_traffic_profile_t *traffic_profile, bool as_request)
{
    if (!traffic_profile) return NULL;
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(traffic_profile);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_traffic_profile_t*>(new std::shared_ptr<TrafficProfile >(new TrafficProfile(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_equal_to(const data_collection_model_traffic_profile_t *first, const data_collection_model_traffic_profile_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<TrafficProfile > &obj2 = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<TrafficProfile > &obj1 = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_not_set(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    if (!obj_traffic_profile) return true;
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    if (!obj) return true;
    return obj->getValue() == TrafficProfile::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_non_standard(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    if (!obj_traffic_profile) return false;
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    if (!obj) return false;
    return obj->getValue() == TrafficProfile::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_e data_collection_model_traffic_profile_get_enum(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    if (!obj_traffic_profile)
        return DCM_TRAFFIC_PROFILE_NO_VAL;
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    if (!obj) return DCM_TRAFFIC_PROFILE_NO_VAL;
    switch (obj->getValue()) {
    case TrafficProfile::Enum::NO_VAL:
        return DCM_TRAFFIC_PROFILE_NO_VAL;
    case TrafficProfile::Enum::VAL_SINGLE_TRANS_UL:
        return DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_UL;
    case TrafficProfile::Enum::VAL_SINGLE_TRANS_DL:
        return DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_DL;
    case TrafficProfile::Enum::VAL_DUAL_TRANS_UL_FIRST:
        return DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_UL_FIRST;
    case TrafficProfile::Enum::VAL_DUAL_TRANS_DL_FIRST:
        return DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_DL_FIRST;
    case TrafficProfile::Enum::VAL_MULTI_TRANS:
        return DCM_TRAFFIC_PROFILE_VAL_MULTI_TRANS;
    default:
        break;
    }
    return DCM_TRAFFIC_PROFILE_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_traffic_profile_get_string(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    if (!obj_traffic_profile) return NULL;
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_set_enum(data_collection_model_traffic_profile_t *obj_traffic_profile, data_collection_model_traffic_profile_e p_value)
{
    if (!obj_traffic_profile) return false;
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    if (!obj) return false;
    switch (p_value) {
    case DCM_TRAFFIC_PROFILE_NO_VAL:
        *obj = TrafficProfile::Enum::NO_VAL;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_UL:
        *obj = TrafficProfile::Enum::VAL_SINGLE_TRANS_UL;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_DL:
        *obj = TrafficProfile::Enum::VAL_SINGLE_TRANS_DL;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_UL_FIRST:
        *obj = TrafficProfile::Enum::VAL_DUAL_TRANS_UL_FIRST;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_DL_FIRST:
        *obj = TrafficProfile::Enum::VAL_DUAL_TRANS_DL_FIRST;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_MULTI_TRANS:
        *obj = TrafficProfile::Enum::VAL_MULTI_TRANS;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_set_string(data_collection_model_traffic_profile_t *obj_traffic_profile, const char *p_value)
{
    if (!obj_traffic_profile) return false;
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = TrafficProfile::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_traffic_profile_make_lnode(data_collection_model_traffic_profile_t *p_traffic_profile)
{
    return data_collection_lnode_create(p_traffic_profile, reinterpret_cast<void(*)(void*)>(data_collection_model_traffic_profile_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_traffic_profile_refcount(data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    if (!obj_traffic_profile) return 0l;
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

