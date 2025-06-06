/**********************************************************************************************************************************
 * Usage - C interface to the Usage object
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

/*#include "Usage.h" already included by data-collection-sp/data-collection.h */
#include "Usage-internal.h"
#include "openapi/model/Usage.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_create()
{
    return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage>(new Usage()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_create_ref(const data_collection_model_usage_t *other)
{
    return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage>(*reinterpret_cast<const std::shared_ptr<Usage >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_create_copy(const data_collection_model_usage_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage >(new Usage(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_create_move(data_collection_model_usage_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Usage > *obj = reinterpret_cast<std::shared_ptr<Usage >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_copy(data_collection_model_usage_t *usage, const data_collection_model_usage_t *other)
{
    if (usage) {
        std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(usage);
        if (obj) {
            if (other) {
                const std::shared_ptr<Usage > &other_obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(other);
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
                const std::shared_ptr<Usage > &other_obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(other);
                if (other_obj) {
                    obj.reset(new Usage(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        usage = data_collection_model_usage_create_copy(other);
    }
    return usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_move(data_collection_model_usage_t *usage, data_collection_model_usage_t *other)
{
    std::shared_ptr<Usage > *other_ptr = reinterpret_cast<std::shared_ptr<Usage >*>(other);

    if (usage) {
        std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(usage);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                usage = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_usage_free(data_collection_model_usage_t *usage)
{
    if (!usage) return;
    delete reinterpret_cast<std::shared_ptr<Usage >*>(usage);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_usage_toJSON(const data_collection_model_usage_t *usage, bool as_request)
{
    if (!usage) return NULL;
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(usage);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_usage_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_usage_t*>(new std::shared_ptr<Usage >(new Usage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_equal_to(const data_collection_model_usage_t *first, const data_collection_model_usage_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Usage > &obj2 = *reinterpret_cast<const std::shared_ptr<Usage >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Usage > &obj1 = *reinterpret_cast<const std::shared_ptr<Usage >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_not_set(const data_collection_model_usage_t *obj_usage)
{
    if (!obj_usage) return true;
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    if (!obj) return true;
    return obj->getValue() == Usage::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_non_standard(const data_collection_model_usage_t *obj_usage)
{
    if (!obj_usage) return false;
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    if (!obj) return false;
    return obj->getValue() == Usage::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_e data_collection_model_usage_get_enum(const data_collection_model_usage_t *obj_usage)
{
    if (!obj_usage)
        return DCM_USAGE_NO_VAL;
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    if (!obj) return DCM_USAGE_NO_VAL;
    switch (obj->getValue()) {
    case Usage::Enum::NO_VAL:
        return DCM_USAGE_NO_VAL;
    case Usage::Enum::VAL_UNSUCCESS:
        return DCM_USAGE_VAL_UNSUCCESS;
    case Usage::Enum::VAL_SUCCESS_RESULTS_NOT_USED:
        return DCM_USAGE_VAL_SUCCESS_RESULTS_NOT_USED;
    case Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION:
        return DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION;
    case Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION:
        return DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION;
    case Usage::Enum::VAL_SUCCESS_METHOD_NOT_DETERMINED:
        return DCM_USAGE_VAL_SUCCESS_METHOD_NOT_DETERMINED;
    default:
        break;
    }
    return DCM_USAGE_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_usage_get_string(const data_collection_model_usage_t *obj_usage)
{
    if (!obj_usage) return NULL;
    const std::shared_ptr<Usage > &obj = *reinterpret_cast<const std::shared_ptr<Usage >*>(obj_usage);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_set_enum(data_collection_model_usage_t *obj_usage, data_collection_model_usage_e p_value)
{
    if (!obj_usage) return false;
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(obj_usage);
    if (!obj) return false;
    switch (p_value) {
    case DCM_USAGE_NO_VAL:
        *obj = Usage::Enum::NO_VAL;
        return true;
    case DCM_USAGE_VAL_UNSUCCESS:
        *obj = Usage::Enum::VAL_UNSUCCESS;
        return true;
    case DCM_USAGE_VAL_SUCCESS_RESULTS_NOT_USED:
        *obj = Usage::Enum::VAL_SUCCESS_RESULTS_NOT_USED;
        return true;
    case DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION:
        *obj = Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION;
        return true;
    case DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION:
        *obj = Usage::Enum::VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION;
        return true;
    case DCM_USAGE_VAL_SUCCESS_METHOD_NOT_DETERMINED:
        *obj = Usage::Enum::VAL_SUCCESS_METHOD_NOT_DETERMINED;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_set_string(data_collection_model_usage_t *obj_usage, const char *p_value)
{
    if (!obj_usage) return false;
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(obj_usage);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = Usage::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_usage_make_lnode(data_collection_model_usage_t *p_usage)
{
    return data_collection_lnode_create(p_usage, reinterpret_cast<void(*)(void*)>(data_collection_model_usage_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_usage_refcount(data_collection_model_usage_t *obj_usage)
{
    if (!obj_usage) return 0l;
    std::shared_ptr<Usage > &obj = *reinterpret_cast<std::shared_ptr<Usage >*>(obj_usage);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

