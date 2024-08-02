/**********************************************************************************************************************************
 * PartitioningCriteria - C interface to the PartitioningCriteria object
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

/*#include "PartitioningCriteria.h" already included by data-collection-sp/data-collection.h */
#include "PartitioningCriteria-internal.h"
#include "openapi/model/PartitioningCriteria.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create()
{
    return reinterpret_cast<data_collection_model_partitioning_criteria_t*>(new std::shared_ptr<PartitioningCriteria>(new PartitioningCriteria()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create_copy(const data_collection_model_partitioning_criteria_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_partitioning_criteria_t*>(new std::shared_ptr<PartitioningCriteria >(new PartitioningCriteria(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create_move(data_collection_model_partitioning_criteria_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PartitioningCriteria > *obj = reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_copy(data_collection_model_partitioning_criteria_t *partitioning_criteria, const data_collection_model_partitioning_criteria_t *other)
{
    if (partitioning_criteria) {
        std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(partitioning_criteria);
        if (obj) {
            if (other) {
                const std::shared_ptr<PartitioningCriteria > &other_obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(other);
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
                const std::shared_ptr<PartitioningCriteria > &other_obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(other);
                if (other_obj) {
                    obj.reset(new PartitioningCriteria(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        partitioning_criteria = data_collection_model_partitioning_criteria_create_copy(other);
    }
    return partitioning_criteria;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_move(data_collection_model_partitioning_criteria_t *partitioning_criteria, data_collection_model_partitioning_criteria_t *other)
{
    std::shared_ptr<PartitioningCriteria > *other_ptr = reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(other);

    if (partitioning_criteria) {
        std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(partitioning_criteria);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                partitioning_criteria = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return partitioning_criteria;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_partitioning_criteria_free(data_collection_model_partitioning_criteria_t *partitioning_criteria)
{
    if (!partitioning_criteria) return;
    delete reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(partitioning_criteria);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_partitioning_criteria_toJSON(const data_collection_model_partitioning_criteria_t *partitioning_criteria, bool as_request)
{
    if (!partitioning_criteria) return NULL;
    const std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(partitioning_criteria);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_partitioning_criteria_t*>(new std::shared_ptr<PartitioningCriteria >(new PartitioningCriteria(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_partitioning_criteria_is_equal_to(const data_collection_model_partitioning_criteria_t *first, const data_collection_model_partitioning_criteria_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PartitioningCriteria > &obj2 = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PartitioningCriteria > &obj1 = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_not_set(const data_collection_model_partitioning_criteria_t *obj_partitioning_criteria)
{
    if (!obj_partitioning_criteria) return true;
    const std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(obj_partitioning_criteria);
    if (!obj) return true;
    return obj->getValue() == PartitioningCriteria::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_non_standard(const data_collection_model_partitioning_criteria_t *obj_partitioning_criteria)
{
    if (!obj_partitioning_criteria) return false;
    const std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(obj_partitioning_criteria);
    if (!obj) return false;
    return obj->getValue() == PartitioningCriteria::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_e data_collection_model_partitioning_criteria_get_enum(const data_collection_model_partitioning_criteria_t *obj_partitioning_criteria)
{
    if (!obj_partitioning_criteria)
        return DCM_PARTITIONING_CRITERIA_NO_VAL;
    const std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(obj_partitioning_criteria);
    if (!obj) return DCM_PARTITIONING_CRITERIA_NO_VAL;
    switch (obj->getValue()) {
    case PartitioningCriteria::Enum::NO_VAL:
        return DCM_PARTITIONING_CRITERIA_NO_VAL;
    case PartitioningCriteria::Enum::VAL_TAC:
        return DCM_PARTITIONING_CRITERIA_VAL_TAC;
    case PartitioningCriteria::Enum::VAL_SUBPLMN:
        return DCM_PARTITIONING_CRITERIA_VAL_SUBPLMN;
    case PartitioningCriteria::Enum::VAL_GEOAREA:
        return DCM_PARTITIONING_CRITERIA_VAL_GEOAREA;
    case PartitioningCriteria::Enum::VAL_SNSSAI:
        return DCM_PARTITIONING_CRITERIA_VAL_SNSSAI;
    case PartitioningCriteria::Enum::VAL_DNN:
        return DCM_PARTITIONING_CRITERIA_VAL_DNN;
    default:
        break;
    }
    return DCM_PARTITIONING_CRITERIA_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_partitioning_criteria_get_string(const data_collection_model_partitioning_criteria_t *obj_partitioning_criteria)
{
    if (!obj_partitioning_criteria) return NULL;
    const std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<const std::shared_ptr<PartitioningCriteria >*>(obj_partitioning_criteria);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_set_enum(data_collection_model_partitioning_criteria_t *obj_partitioning_criteria, data_collection_model_partitioning_criteria_e p_value)
{
    if (!obj_partitioning_criteria) return false;
    std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(obj_partitioning_criteria);
    if (!obj) return false;
    switch (p_value) {
    case DCM_PARTITIONING_CRITERIA_NO_VAL:
        *obj = PartitioningCriteria::Enum::NO_VAL;
        return true;
    case DCM_PARTITIONING_CRITERIA_VAL_TAC:
        *obj = PartitioningCriteria::Enum::VAL_TAC;
        return true;
    case DCM_PARTITIONING_CRITERIA_VAL_SUBPLMN:
        *obj = PartitioningCriteria::Enum::VAL_SUBPLMN;
        return true;
    case DCM_PARTITIONING_CRITERIA_VAL_GEOAREA:
        *obj = PartitioningCriteria::Enum::VAL_GEOAREA;
        return true;
    case DCM_PARTITIONING_CRITERIA_VAL_SNSSAI:
        *obj = PartitioningCriteria::Enum::VAL_SNSSAI;
        return true;
    case DCM_PARTITIONING_CRITERIA_VAL_DNN:
        *obj = PartitioningCriteria::Enum::VAL_DNN;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_set_string(data_collection_model_partitioning_criteria_t *obj_partitioning_criteria, const char *p_value)
{
    if (!obj_partitioning_criteria) return false;
    std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(obj_partitioning_criteria);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PartitioningCriteria::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_partitioning_criteria_make_lnode(data_collection_model_partitioning_criteria_t *p_partitioning_criteria)
{
    return data_collection_lnode_create(p_partitioning_criteria, reinterpret_cast<void(*)(void*)>(data_collection_model_partitioning_criteria_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_partitioning_criteria_refcount(data_collection_model_partitioning_criteria_t *obj_partitioning_criteria)
{
    if (!obj_partitioning_criteria) return 0l;
    std::shared_ptr<PartitioningCriteria > &obj = *reinterpret_cast<std::shared_ptr<PartitioningCriteria >*>(obj_partitioning_criteria);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

