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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cache_status_t *data_collection_model_cache_status_create()
{
    return reinterpret_cast<data_collection_model_cache_status_t*>(new std::shared_ptr<CacheStatus>(new CacheStatus()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cache_status_t *data_collection_model_cache_status_create_copy(const data_collection_model_cache_status_t *other)
{
    return reinterpret_cast<data_collection_model_cache_status_t*>(new std::shared_ptr<CacheStatus >(new CacheStatus(**reinterpret_cast<const std::shared_ptr<CacheStatus >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cache_status_t *data_collection_model_cache_status_create_move(data_collection_model_cache_status_t *other)
{
    return reinterpret_cast<data_collection_model_cache_status_t*>(new std::shared_ptr<CacheStatus >(std::move(*reinterpret_cast<std::shared_ptr<CacheStatus >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cache_status_t *data_collection_model_cache_status_copy(data_collection_model_cache_status_t *cache_status, const data_collection_model_cache_status_t *other)
{
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(cache_status);
    *obj = **reinterpret_cast<const std::shared_ptr<CacheStatus >*>(other);
    return cache_status;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cache_status_t *data_collection_model_cache_status_move(data_collection_model_cache_status_t *cache_status, data_collection_model_cache_status_t *other)
{
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(cache_status);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CacheStatus >*>(other));
    return cache_status;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_cache_status_free(data_collection_model_cache_status_t *cache_status)
{
    delete reinterpret_cast<std::shared_ptr<CacheStatus >*>(cache_status);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_cache_status_toJSON(const data_collection_model_cache_status_t *cache_status, bool as_request)
{
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(cache_status);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cache_status_t *data_collection_model_cache_status_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_cache_status_is_equal_to(const data_collection_model_cache_status_t *first, const data_collection_model_cache_status_t *second)
{
    const std::shared_ptr<CacheStatus > &obj1 = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(first);
    const std::shared_ptr<CacheStatus > &obj2 = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_is_not_set(const data_collection_model_cache_status_t *obj_cache_status)
{
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
    return obj->getValue() == CacheStatus::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_is_non_standard(const data_collection_model_cache_status_t *obj_cache_status)
{
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
    return obj->getValue() == CacheStatus::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cache_status_e data_collection_model_cache_status_get_enum(const data_collection_model_cache_status_t *obj_cache_status)
{
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_cache_status_get_string(const data_collection_model_cache_status_t *obj_cache_status)
{
    const std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<const std::shared_ptr<CacheStatus >*>(obj_cache_status);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_set_enum(data_collection_model_cache_status_t *obj_cache_status, data_collection_model_cache_status_e p_value)
{
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(obj_cache_status);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cache_status_set_string(data_collection_model_cache_status_t *obj_cache_status, const char *p_value)
{
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(obj_cache_status);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CacheStatus::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_cache_status_make_lnode(data_collection_model_cache_status_t *p_cache_status)
{
    return data_collection_lnode_create(p_cache_status, reinterpret_cast<void(*)(void*)>(data_collection_model_cache_status_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_cache_status_refcount(data_collection_model_cache_status_t *obj_cache_status)
{
    std::shared_ptr<CacheStatus > &obj = *reinterpret_cast<std::shared_ptr<CacheStatus >*>(obj_cache_status);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

