/**********************************************************************************************************************************
 * CacheStatus - C interface to the CacheStatus object
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

/*#include "CacheStatus.h" already included by data-collection-sp/data-collection.h */
#include "CacheStatus-internal.h"
#include "openapi/model/CacheStatus.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_create()
{
    return reinterpret_cast<data_collection_model_cache_status_t*>(new std::shared_ptr<CacheStatus>(new CacheStatus()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_create_ref(const data_collection_model_cache_status_t *other)
{
    return reinterpret_cast<data_collection_model_cache_status_t*>(new std::shared_ptr<CacheStatus>(*reinterpret_cast<const std::shared_ptr<CacheStatus >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_create_copy(const data_collection_model_cache_status_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_cache_status_t*>(new std::shared_ptr<CacheStatus >(new CacheStatus(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_create_move(data_collection_model_cache_status_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CacheStatus > *obj = reinterpret_cast<std::shared_ptr<CacheStatus >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_copy(data_collection_model_cache_status_t *cache_status, const data_collection_model_cache_status_t *other)
{
    if (cache_status) {
        std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(cache_status);
        if (obj) {
            if (other) {
                const std::shared_ptr<CacheStatus > &other_obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(other);
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
                const std::shared_ptr<CacheStatus > &other_obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(other);
                if (other_obj) {
                    obj.reset(new CacheStatus(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        cache_status = data_collection_model_cache_status_create_copy(other);
    }
    return cache_status;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_move(data_collection_model_cache_status_t *cache_status, data_collection_model_cache_status_t *other)
{
    std::shared_ptr<CacheStatus > *other_ptr = reinterpret_cast<std::shared_ptr<CacheStatus >*>(other);

    if (cache_status) {
        std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(cache_status);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                cache_status = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return cache_status;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_cache_status_free(data_collection_model_cache_status_t *cache_status)
{
    if (!cache_status) return;
    delete reinterpret_cast<std::shared_ptr<CacheStatus >*>(cache_status);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_cache_status_toJSON(const data_collection_model_cache_status_t *cache_status, bool as_request)
{
    if (!cache_status) return NULL;
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(cache_status);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_cache_status_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_t *data_collection_model_cache_status_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_cache_status_t*>(new std::shared_ptr<CacheStatus >(new CacheStatus(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_is_equal_to(const data_collection_model_cache_status_t *first, const data_collection_model_cache_status_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CacheStatus > &obj2 = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CacheStatus > &obj1 = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_is_not_set(const data_collection_model_cache_status_t *obj_cache_status)
{
    if (!obj_cache_status) return true;
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
    if (!obj) return true;
    return obj->getValue() == CacheStatus::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_is_non_standard(const data_collection_model_cache_status_t *obj_cache_status)
{
    if (!obj_cache_status) return false;
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
    if (!obj) return false;
    return obj->getValue() == CacheStatus::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_e data_collection_model_cache_status_get_enum(const data_collection_model_cache_status_t *obj_cache_status)
{
    if (!obj_cache_status)
        return DCM_CACHE_STATUS_NO_VAL;
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
    if (!obj) return DCM_CACHE_STATUS_NO_VAL;
    switch (obj->getValue()) {
    case CacheStatus::Enum::NO_VAL:
        return DCM_CACHE_STATUS_NO_VAL;
    case CacheStatus::Enum::VAL_HIT:
        return DCM_CACHE_STATUS_VAL_HIT;
    case CacheStatus::Enum::VAL_MISS:
        return DCM_CACHE_STATUS_VAL_MISS;
    case CacheStatus::Enum::VAL_EXPIRED:
        return DCM_CACHE_STATUS_VAL_EXPIRED;
    default:
        break;
    }
    return DCM_CACHE_STATUS_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_cache_status_get_string(const data_collection_model_cache_status_t *obj_cache_status)
{
    if (!obj_cache_status) return NULL;
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_set_enum(data_collection_model_cache_status_t *obj_cache_status, data_collection_model_cache_status_e p_value)
{
    if (!obj_cache_status) return false;
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(obj_cache_status);
    if (!obj) return false;
    switch (p_value) {
    case DCM_CACHE_STATUS_NO_VAL:
        *obj = CacheStatus::Enum::NO_VAL;
        return true;
    case DCM_CACHE_STATUS_VAL_HIT:
        *obj = CacheStatus::Enum::VAL_HIT;
        return true;
    case DCM_CACHE_STATUS_VAL_MISS:
        *obj = CacheStatus::Enum::VAL_MISS;
        return true;
    case DCM_CACHE_STATUS_VAL_EXPIRED:
        *obj = CacheStatus::Enum::VAL_EXPIRED;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_set_string(data_collection_model_cache_status_t *obj_cache_status, const char *p_value)
{
    if (!obj_cache_status) return false;
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(obj_cache_status);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CacheStatus::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_cache_status_make_lnode(data_collection_model_cache_status_t *p_cache_status)
{
    return data_collection_lnode_create(p_cache_status, reinterpret_cast<void(*)(void*)>(data_collection_model_cache_status_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_cache_status_refcount(data_collection_model_cache_status_t *obj_cache_status)
{
    if (!obj_cache_status) return 0l;
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(obj_cache_status);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

