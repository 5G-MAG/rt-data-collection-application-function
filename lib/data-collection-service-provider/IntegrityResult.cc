/**********************************************************************************************************************************
 * IntegrityResult - C interface to the IntegrityResult object
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

/*#include "IntegrityResult.h" already included by data-collection-sp/data-collection.h */
#include "IntegrityResult-internal.h"
#include "openapi/model/IntegrityResult.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create(



)
{
    return reinterpret_cast<data_collection_model_integrity_result_t*>(new std::shared_ptr<IntegrityResult>(new IntegrityResult(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_copy(const data_collection_model_integrity_result_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_integrity_result_t*>(new std::shared_ptr<IntegrityResult >(new IntegrityResult(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_move(data_collection_model_integrity_result_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<IntegrityResult > *obj = reinterpret_cast<std::shared_ptr<IntegrityResult >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_copy(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_result_t *other)
{
    if (integrity_result) {
        std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(integrity_result);
        if (obj) {
            if (other) {
                const std::shared_ptr<IntegrityResult > &other_obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(other);
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
                const std::shared_ptr<IntegrityResult > &other_obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(other);
                if (other_obj) {
                    obj.reset(new IntegrityResult(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        integrity_result = data_collection_model_integrity_result_create_copy(other);
    }
    return integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_result_t *other)
{
    std::shared_ptr<IntegrityResult > *other_ptr = reinterpret_cast<std::shared_ptr<IntegrityResult >*>(other);

    if (integrity_result) {
        std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(integrity_result);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                integrity_result = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_result_free(data_collection_model_integrity_result_t *integrity_result)
{
    if (!integrity_result) return;
    delete reinterpret_cast<std::shared_ptr<IntegrityResult >*>(integrity_result);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_result_toJSON(const data_collection_model_integrity_result_t *integrity_result, bool as_request)
{
    if (!integrity_result) return NULL;
    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(integrity_result);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_integrity_result_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_integrity_result_t*>(new std::shared_ptr<IntegrityResult >(new IntegrityResult(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_is_equal_to(const data_collection_model_integrity_result_t *first, const data_collection_model_integrity_result_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<IntegrityResult > &obj2 = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<IntegrityResult > &obj1 = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_computing_entity(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) return false;

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return false;

    return obj->getComputingEntity().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_integrity_computing_entity_t* data_collection_model_integrity_result_get_computing_entity(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) {
        const data_collection_model_integrity_computing_entity_t *result = NULL;
        return result;
    }

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) {
        const data_collection_model_integrity_computing_entity_t *result = NULL;
        return result;
    }

    typedef typename IntegrityResult::ComputingEntityType ResultFromType;
    const ResultFromType &result_from = obj->getComputingEntity();
    const data_collection_model_integrity_computing_entity_t *result = reinterpret_cast<const data_collection_model_integrity_computing_entity_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity(data_collection_model_integrity_result_t *obj_integrity_result, const data_collection_model_integrity_computing_entity_t* p_computing_entity)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_computing_entity;
    typedef typename IntegrityResult::ComputingEntityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setComputingEntity(value)) return NULL;

    return obj_integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity_move(data_collection_model_integrity_result_t *obj_integrity_result, data_collection_model_integrity_computing_entity_t* p_computing_entity)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_computing_entity;
    typedef typename IntegrityResult::ComputingEntityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setComputingEntity(std::move(value))) return NULL;
    data_collection_model_integrity_computing_entity_free
(p_computing_entity);

    return obj_integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_protection_level(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) return false;

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return false;

    return obj->getProtectionLevel().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_integrity_protection_level_t* data_collection_model_integrity_result_get_protection_level(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) {
        const data_collection_model_integrity_protection_level_t *result = NULL;
        return result;
    }

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) {
        const data_collection_model_integrity_protection_level_t *result = NULL;
        return result;
    }

    typedef typename IntegrityResult::ProtectionLevelType ResultFromType;
    const ResultFromType &result_from = obj->getProtectionLevel();
    const data_collection_model_integrity_protection_level_t *result = reinterpret_cast<const data_collection_model_integrity_protection_level_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level(data_collection_model_integrity_result_t *obj_integrity_result, const data_collection_model_integrity_protection_level_t* p_protection_level)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_protection_level;
    typedef typename IntegrityResult::ProtectionLevelType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setProtectionLevel(value)) return NULL;

    return obj_integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level_move(data_collection_model_integrity_result_t *obj_integrity_result, data_collection_model_integrity_protection_level_t* p_protection_level)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_protection_level;
    typedef typename IntegrityResult::ProtectionLevelType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setProtectionLevel(std::move(value))) return NULL;
    data_collection_model_integrity_protection_level_free
(p_protection_level);

    return obj_integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_integrity_req_met_ind(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) return false;

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return false;

    return obj->isIntegrityReqMetInd().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_integrity_result_is_integrity_req_met_ind(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename IntegrityResult::IntegrityReqMetIndType ResultFromType;
    const ResultFromType &result_from = obj->isIntegrityReqMetInd();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind(data_collection_model_integrity_result_t *obj_integrity_result, const bool p_integrity_req_met_ind)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_integrity_req_met_ind;
    typedef typename IntegrityResult::IntegrityReqMetIndType ValueType;

    ValueType value(value_from);

    if (!obj->setIntegrityReqMetInd(value)) return NULL;

    return obj_integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind_move(data_collection_model_integrity_result_t *obj_integrity_result, bool p_integrity_req_met_ind)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_integrity_req_met_ind;
    typedef typename IntegrityResult::IntegrityReqMetIndType ValueType;

    ValueType value(value_from);

    if (!obj->setIntegrityReqMetInd(std::move(value))) return NULL;

    return obj_integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_achieved_tir(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) return false;

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return false;

    return obj->getAchievedTir().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_result_get_achieved_tir(const data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename IntegrityResult::AchievedTirType ResultFromType;
    const ResultFromType &result_from = obj->getAchievedTir();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir(data_collection_model_integrity_result_t *obj_integrity_result, const int32_t p_achieved_tir)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_achieved_tir;
    typedef typename IntegrityResult::AchievedTirType ValueType;

    ValueType value(value_from);

    if (!obj->setAchievedTir(value)) return NULL;

    return obj_integrity_result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir_move(data_collection_model_integrity_result_t *obj_integrity_result, int32_t p_achieved_tir)
{
    if (!obj_integrity_result) return NULL;

    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    if (!obj) return NULL;

    const auto &value_from = p_achieved_tir;
    typedef typename IntegrityResult::AchievedTirType ValueType;

    ValueType value(value_from);

    if (!obj->setAchievedTir(std::move(value))) return NULL;

    return obj_integrity_result;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_result_make_lnode(data_collection_model_integrity_result_t *p_integrity_result)
{
    return data_collection_lnode_create(p_integrity_result, reinterpret_cast<void(*)(void*)>(data_collection_model_integrity_result_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_integrity_result_refcount(data_collection_model_integrity_result_t *obj_integrity_result)
{
    if (!obj_integrity_result) return 0l;
    std::shared_ptr<IntegrityResult > &obj = *reinterpret_cast<std::shared_ptr<IntegrityResult >*>(obj_integrity_result);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

