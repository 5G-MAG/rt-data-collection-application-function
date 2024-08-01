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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "IntegrityComputingEntity.h" already included by data-collection-sp/data-collection.h */
#include "IntegrityComputingEntity-internal.h"
#include "openapi/model/IntegrityComputingEntity.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create()
{
    return reinterpret_cast<data_collection_model_integrity_computing_entity_t*>(new std::shared_ptr<IntegrityComputingEntity>(new IntegrityComputingEntity()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create_copy(const data_collection_model_integrity_computing_entity_t *other)
{
    return reinterpret_cast<data_collection_model_integrity_computing_entity_t*>(new std::shared_ptr<IntegrityComputingEntity >(new IntegrityComputingEntity(**reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create_move(data_collection_model_integrity_computing_entity_t *other)
{
    return reinterpret_cast<data_collection_model_integrity_computing_entity_t*>(new std::shared_ptr<IntegrityComputingEntity >(std::move(*reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_copy(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, const data_collection_model_integrity_computing_entity_t *other)
{
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
    *obj = **reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(other);
    return integrity_computing_entity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_move(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, data_collection_model_integrity_computing_entity_t *other)
{
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
    obj = std::move(*reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(other));
    return integrity_computing_entity;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_integrity_computing_entity_free(data_collection_model_integrity_computing_entity_t *integrity_computing_entity)
{
    delete reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_integrity_computing_entity_toJSON(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity, bool as_request)
{
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(integrity_computing_entity);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_integrity_computing_entity_is_equal_to(const data_collection_model_integrity_computing_entity_t *first, const data_collection_model_integrity_computing_entity_t *second)
{
    const std::shared_ptr<IntegrityComputingEntity > &obj1 = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(first);
    const std::shared_ptr<IntegrityComputingEntity > &obj2 = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_not_set(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    return obj->getValue() == IntegrityComputingEntity::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_non_standard(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    return obj->getValue() == IntegrityComputingEntity::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_e data_collection_model_integrity_computing_entity_get_enum(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_integrity_computing_entity_get_string(const data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    const std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_set_enum(data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity, data_collection_model_integrity_computing_entity_e p_value)
{
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_set_string(data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity, const char *p_value)
{
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = IntegrityComputingEntity::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_integrity_computing_entity_make_lnode(data_collection_model_integrity_computing_entity_t *p_integrity_computing_entity)
{
    return data_collection_lnode_create(p_integrity_computing_entity, reinterpret_cast<void(*)(void*)>(data_collection_model_integrity_computing_entity_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_integrity_computing_entity_refcount(data_collection_model_integrity_computing_entity_t *obj_integrity_computing_entity)
{
    std::shared_ptr<IntegrityComputingEntity > &obj = *reinterpret_cast<std::shared_ptr<IntegrityComputingEntity >*>(obj_integrity_computing_entity);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

