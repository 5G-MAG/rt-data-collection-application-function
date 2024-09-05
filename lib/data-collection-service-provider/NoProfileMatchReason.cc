/**********************************************************************************************************************************
 * NoProfileMatchReason - C interface to the NoProfileMatchReason object
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

/*#include "NoProfileMatchReason.h" already included by data-collection-sp/data-collection.h */
#include "NoProfileMatchReason-internal.h"
#include "openapi/model/NoProfileMatchReason.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_create()
{
    return reinterpret_cast<data_collection_model_no_profile_match_reason_t*>(new std::shared_ptr<NoProfileMatchReason>(new NoProfileMatchReason()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_create_copy(const data_collection_model_no_profile_match_reason_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_no_profile_match_reason_t*>(new std::shared_ptr<NoProfileMatchReason >(new NoProfileMatchReason(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_create_move(data_collection_model_no_profile_match_reason_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NoProfileMatchReason > *obj = reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_copy(data_collection_model_no_profile_match_reason_t *no_profile_match_reason, const data_collection_model_no_profile_match_reason_t *other)
{
    if (no_profile_match_reason) {
        std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(no_profile_match_reason);
        if (obj) {
            if (other) {
                const std::shared_ptr<NoProfileMatchReason > &other_obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(other);
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
                const std::shared_ptr<NoProfileMatchReason > &other_obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(other);
                if (other_obj) {
                    obj.reset(new NoProfileMatchReason(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        no_profile_match_reason = data_collection_model_no_profile_match_reason_create_copy(other);
    }
    return no_profile_match_reason;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_move(data_collection_model_no_profile_match_reason_t *no_profile_match_reason, data_collection_model_no_profile_match_reason_t *other)
{
    std::shared_ptr<NoProfileMatchReason > *other_ptr = reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(other);

    if (no_profile_match_reason) {
        std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(no_profile_match_reason);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                no_profile_match_reason = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return no_profile_match_reason;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_no_profile_match_reason_free(data_collection_model_no_profile_match_reason_t *no_profile_match_reason)
{
    if (!no_profile_match_reason) return;
    delete reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(no_profile_match_reason);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_no_profile_match_reason_toJSON(const data_collection_model_no_profile_match_reason_t *no_profile_match_reason, bool as_request)
{
    if (!no_profile_match_reason) return NULL;
    const std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(no_profile_match_reason);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_no_profile_match_reason_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_t *data_collection_model_no_profile_match_reason_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_no_profile_match_reason_t*>(new std::shared_ptr<NoProfileMatchReason >(new NoProfileMatchReason(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_is_equal_to(const data_collection_model_no_profile_match_reason_t *first, const data_collection_model_no_profile_match_reason_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NoProfileMatchReason > &obj2 = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NoProfileMatchReason > &obj1 = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_is_not_set(const data_collection_model_no_profile_match_reason_t *obj_no_profile_match_reason)
{
    if (!obj_no_profile_match_reason) return true;
    const std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(obj_no_profile_match_reason);
    if (!obj) return true;
    return obj->getValue() == NoProfileMatchReason::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_is_non_standard(const data_collection_model_no_profile_match_reason_t *obj_no_profile_match_reason)
{
    if (!obj_no_profile_match_reason) return false;
    const std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(obj_no_profile_match_reason);
    if (!obj) return false;
    return obj->getValue() == NoProfileMatchReason::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_no_profile_match_reason_e data_collection_model_no_profile_match_reason_get_enum(const data_collection_model_no_profile_match_reason_t *obj_no_profile_match_reason)
{
    if (!obj_no_profile_match_reason)
        return DCM_NO_PROFILE_MATCH_REASON_NO_VAL;
    const std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(obj_no_profile_match_reason);
    if (!obj) return DCM_NO_PROFILE_MATCH_REASON_NO_VAL;
    switch (obj->getValue()) {
    case NoProfileMatchReason::Enum::NO_VAL:
        return DCM_NO_PROFILE_MATCH_REASON_NO_VAL;
    case NoProfileMatchReason::Enum::VAL_REQUESTER_PLMN_NOT_ALLOWED:
        return DCM_NO_PROFILE_MATCH_REASON_VAL_REQUESTER_PLMN_NOT_ALLOWED;
    case NoProfileMatchReason::Enum::VAL_TARGET_NF_SUSPENDED:
        return DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_SUSPENDED;
    case NoProfileMatchReason::Enum::VAL_TARGET_NF_UNDISCOVERABLE:
        return DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_UNDISCOVERABLE;
    case NoProfileMatchReason::Enum::VAL_QUERY_PARAMS_COMBINATION_NO_MATCH:
        return DCM_NO_PROFILE_MATCH_REASON_VAL_QUERY_PARAMS_COMBINATION_NO_MATCH;
    case NoProfileMatchReason::Enum::VAL_TARGET_NF_TYPE_NOT_SUPPORTED:
        return DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_TYPE_NOT_SUPPORTED;
    case NoProfileMatchReason::Enum::VAL_UNSPECIFIED:
        return DCM_NO_PROFILE_MATCH_REASON_VAL_UNSPECIFIED;
    default:
        break;
    }
    return DCM_NO_PROFILE_MATCH_REASON_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_no_profile_match_reason_get_string(const data_collection_model_no_profile_match_reason_t *obj_no_profile_match_reason)
{
    if (!obj_no_profile_match_reason) return NULL;
    const std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<const std::shared_ptr<NoProfileMatchReason >*>(obj_no_profile_match_reason);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_set_enum(data_collection_model_no_profile_match_reason_t *obj_no_profile_match_reason, data_collection_model_no_profile_match_reason_e p_value)
{
    if (!obj_no_profile_match_reason) return false;
    std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(obj_no_profile_match_reason);
    if (!obj) return false;
    switch (p_value) {
    case DCM_NO_PROFILE_MATCH_REASON_NO_VAL:
        *obj = NoProfileMatchReason::Enum::NO_VAL;
        return true;
    case DCM_NO_PROFILE_MATCH_REASON_VAL_REQUESTER_PLMN_NOT_ALLOWED:
        *obj = NoProfileMatchReason::Enum::VAL_REQUESTER_PLMN_NOT_ALLOWED;
        return true;
    case DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_SUSPENDED:
        *obj = NoProfileMatchReason::Enum::VAL_TARGET_NF_SUSPENDED;
        return true;
    case DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_UNDISCOVERABLE:
        *obj = NoProfileMatchReason::Enum::VAL_TARGET_NF_UNDISCOVERABLE;
        return true;
    case DCM_NO_PROFILE_MATCH_REASON_VAL_QUERY_PARAMS_COMBINATION_NO_MATCH:
        *obj = NoProfileMatchReason::Enum::VAL_QUERY_PARAMS_COMBINATION_NO_MATCH;
        return true;
    case DCM_NO_PROFILE_MATCH_REASON_VAL_TARGET_NF_TYPE_NOT_SUPPORTED:
        *obj = NoProfileMatchReason::Enum::VAL_TARGET_NF_TYPE_NOT_SUPPORTED;
        return true;
    case DCM_NO_PROFILE_MATCH_REASON_VAL_UNSPECIFIED:
        *obj = NoProfileMatchReason::Enum::VAL_UNSPECIFIED;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_no_profile_match_reason_set_string(data_collection_model_no_profile_match_reason_t *obj_no_profile_match_reason, const char *p_value)
{
    if (!obj_no_profile_match_reason) return false;
    std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(obj_no_profile_match_reason);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NoProfileMatchReason::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_no_profile_match_reason_make_lnode(data_collection_model_no_profile_match_reason_t *p_no_profile_match_reason)
{
    return data_collection_lnode_create(p_no_profile_match_reason, reinterpret_cast<void(*)(void*)>(data_collection_model_no_profile_match_reason_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_no_profile_match_reason_refcount(data_collection_model_no_profile_match_reason_t *obj_no_profile_match_reason)
{
    if (!obj_no_profile_match_reason) return 0l;
    std::shared_ptr<NoProfileMatchReason > &obj = *reinterpret_cast<std::shared_ptr<NoProfileMatchReason >*>(obj_no_profile_match_reason);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

