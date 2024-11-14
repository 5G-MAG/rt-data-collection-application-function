/**********************************************************************************************************************************
 * IntegrityComputingEntity - C interface to the IntegrityComputingEntity object
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

/*#include "IntegrityComputingEntity.h" already included by data-collection-sp/data-collection.h */
#include "IntegrityComputingEntity-internal.h"
#include "openapi/model/IntegrityComputingEntity.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create()
{
    return reinterpret_cast<data_collection_model_integrity_computing_entity_t*>(new std::shared_ptr<IntegrityComputingEntity>(new IntegrityComputingEntity()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create_ref(const data_collection_model_integrity_computing_entity_t *other)
{
    return reinterpret_cast<data_collection_model_integrity_computing_entity_t*>(new std::shared_ptr<IntegrityComputingEntity>(*reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create_copy(const data_collection_model_integrity_computing_entity_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_integrity_computing_entity_t*>(new std::shared_ptr<IntegrityComputingEntity >(new IntegrityComputingEntity(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create_move(data_collection_model_integrity_computing_entity_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<IntegrityComputingEntity > *obj = reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_copy(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, const data_collection_model_integrity_computing_entity_t *other)
{
    if (integrity_computing_entity) {
        std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
        if (obj) {
            if (other) {
                const std::shared_ptr<IntegrityComputingEntity > &other_obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(other);
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
                const std::shared_ptr<IntegrityComputingEntity > &other_obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(other);
                if (other_obj) {
                    obj.reset(new IntegrityComputingEntity(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        integrity_computing_entity = data_collection_model_integrity_computing_entity_create_copy(other);
    }
    return integrity_computing_entity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_move(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, data_collection_model_integrity_computing_entity_t *other)
{
    std::shared_ptr<IntegrityComputingEntity > *other_ptr = reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(other);

    if (integrity_computing_entity) {
        std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                integrity_computing_entity = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return integrity_computing_entity;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_computing_entity_free(data_collection_model_integrity_computing_entity_t *integrity_computing_entity)
{
    if (!integrity_computing_entity) return;
    delete reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_computing_entity_toJSON(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity, bool as_request)
{
    if (!integrity_computing_entity) return NULL;
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_integrity_computing_entity_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_integrity_computing_entity_t*>(new std::shared_ptr<IntegrityComputingEntity >(new IntegrityComputingEntity(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_equal_to(const data_collection_model_integrity_computing_entity_t *first, const data_collection_model_integrity_computing_entity_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<IntegrityComputingEntity > &obj2 = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<IntegrityComputingEntity > &obj1 = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_not_set(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    if (!obj_integrity_computing_entity) return true;
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    if (!obj) return true;
    return obj->getValue() == IntegrityComputingEntity::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_non_standard(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    if (!obj_integrity_computing_entity) return false;
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    if (!obj) return false;
    return obj->getValue() == IntegrityComputingEntity::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_e data_collection_model_integrity_computing_entity_get_enum(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    if (!obj_integrity_computing_entity)
        return DCM_INTEGRITY_COMPUTING_ENTITY_NO_VAL;
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    if (!obj) return DCM_INTEGRITY_COMPUTING_ENTITY_NO_VAL;
    switch (obj->getValue()) {
    case IntegrityComputingEntity::Enum::NO_VAL:
        return DCM_INTEGRITY_COMPUTING_ENTITY_NO_VAL;
    case IntegrityComputingEntity::Enum::VAL_UE:
        return DCM_INTEGRITY_COMPUTING_ENTITY_VAL_UE;
    case IntegrityComputingEntity::Enum::VAL_LMF:
        return DCM_INTEGRITY_COMPUTING_ENTITY_VAL_LMF;
    case IntegrityComputingEntity::Enum::VAL_BOTH:
        return DCM_INTEGRITY_COMPUTING_ENTITY_VAL_BOTH;
    default:
        break;
    }
    return DCM_INTEGRITY_COMPUTING_ENTITY_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_integrity_computing_entity_get_string(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    if (!obj_integrity_computing_entity) return NULL;
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_set_enum(data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity, data_collection_model_integrity_computing_entity_e p_value)
{
    if (!obj_integrity_computing_entity) return false;
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    if (!obj) return false;
    switch (p_value) {
    case DCM_INTEGRITY_COMPUTING_ENTITY_NO_VAL:
        *obj = IntegrityComputingEntity::Enum::NO_VAL;
        return true;
    case DCM_INTEGRITY_COMPUTING_ENTITY_VAL_UE:
        *obj = IntegrityComputingEntity::Enum::VAL_UE;
        return true;
    case DCM_INTEGRITY_COMPUTING_ENTITY_VAL_LMF:
        *obj = IntegrityComputingEntity::Enum::VAL_LMF;
        return true;
    case DCM_INTEGRITY_COMPUTING_ENTITY_VAL_BOTH:
        *obj = IntegrityComputingEntity::Enum::VAL_BOTH;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_set_string(data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity, const char *p_value)
{
    if (!obj_integrity_computing_entity) return false;
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = IntegrityComputingEntity::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_computing_entity_make_lnode(data_collection_model_integrity_computing_entity_t *p_integrity_computing_entity)
{
    return data_collection_lnode_create(p_integrity_computing_entity, reinterpret_cast<void(*)(void*)>(data_collection_model_integrity_computing_entity_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_integrity_computing_entity_refcount(data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    if (!obj_integrity_computing_entity) return 0l;
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

