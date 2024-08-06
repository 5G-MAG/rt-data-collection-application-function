/**********************************************************************************************************************************
 * CollectiveBehaviourFilterType - C interface to the CollectiveBehaviourFilterType object
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

/*#include "CollectiveBehaviourFilterType.h" already included by data-collection-sp/data-collection.h */
#include "CollectiveBehaviourFilterType-internal.h"
#include "openapi/model/CollectiveBehaviourFilterType.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_create()
{
    return reinterpret_cast<data_collection_model_collective_behaviour_filter_type_t*>(new std::shared_ptr<CollectiveBehaviourFilterType>(new CollectiveBehaviourFilterType()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_create_copy(const data_collection_model_collective_behaviour_filter_type_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_collective_behaviour_filter_type_t*>(new std::shared_ptr<CollectiveBehaviourFilterType >(new CollectiveBehaviourFilterType(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_create_move(data_collection_model_collective_behaviour_filter_type_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CollectiveBehaviourFilterType > *obj = reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_copy(data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type, const data_collection_model_collective_behaviour_filter_type_t *other)
{
    if (collective_behaviour_filter_type) {
        std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
        if (obj) {
            if (other) {
                const std::shared_ptr<CollectiveBehaviourFilterType > &other_obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(other);
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
                const std::shared_ptr<CollectiveBehaviourFilterType > &other_obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(other);
                if (other_obj) {
                    obj.reset(new CollectiveBehaviourFilterType(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        collective_behaviour_filter_type = data_collection_model_collective_behaviour_filter_type_create_copy(other);
    }
    return collective_behaviour_filter_type;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_move(data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type, data_collection_model_collective_behaviour_filter_type_t *other)
{
    std::shared_ptr<CollectiveBehaviourFilterType > *other_ptr = reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(other);

    if (collective_behaviour_filter_type) {
        std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                collective_behaviour_filter_type = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return collective_behaviour_filter_type;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_collective_behaviour_filter_type_free(data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type)
{
    if (!collective_behaviour_filter_type) return;
    delete reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_collective_behaviour_filter_type_toJSON(const data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type, bool as_request)
{
    if (!collective_behaviour_filter_type) return NULL;
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_collective_behaviour_filter_type_t*>(new std::shared_ptr<CollectiveBehaviourFilterType >(new CollectiveBehaviourFilterType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_is_equal_to(const data_collection_model_collective_behaviour_filter_type_t *first, const data_collection_model_collective_behaviour_filter_type_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj2 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj1 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_is_not_set(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    if (!obj_collective_behaviour_filter_type) return true;
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    if (!obj) return true;
    return obj->getValue() == CollectiveBehaviourFilterType::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_is_non_standard(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    if (!obj_collective_behaviour_filter_type) return false;
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    if (!obj) return false;
    return obj->getValue() == CollectiveBehaviourFilterType::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_e data_collection_model_collective_behaviour_filter_type_get_enum(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    if (!obj_collective_behaviour_filter_type)
        return DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_NO_VAL;
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    if (!obj) return DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_NO_VAL;
    switch (obj->getValue()) {
    case CollectiveBehaviourFilterType::Enum::NO_VAL:
        return DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_NO_VAL;
    case CollectiveBehaviourFilterType::Enum::VAL_COLLECTIVE_ATTRIBUTE:
        return DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_VAL_COLLECTIVE_ATTRIBUTE;
    case CollectiveBehaviourFilterType::Enum::VAL_DATA_PROCESSING:
        return DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_VAL_DATA_PROCESSING;
    default:
        break;
    }
    return DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_collective_behaviour_filter_type_get_string(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    if (!obj_collective_behaviour_filter_type) return NULL;
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_set_enum(data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type, data_collection_model_collective_behaviour_filter_type_e p_value)
{
    if (!obj_collective_behaviour_filter_type) return false;
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    if (!obj) return false;
    switch (p_value) {
    case DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_NO_VAL:
        *obj = CollectiveBehaviourFilterType::Enum::NO_VAL;
        return true;
    case DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_VAL_COLLECTIVE_ATTRIBUTE:
        *obj = CollectiveBehaviourFilterType::Enum::VAL_COLLECTIVE_ATTRIBUTE;
        return true;
    case DCM_COLLECTIVE_BEHAVIOUR_FILTER_TYPE_VAL_DATA_PROCESSING:
        *obj = CollectiveBehaviourFilterType::Enum::VAL_DATA_PROCESSING;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_set_string(data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type, const char *p_value)
{
    if (!obj_collective_behaviour_filter_type) return false;
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CollectiveBehaviourFilterType::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_collective_behaviour_filter_type_make_lnode(data_collection_model_collective_behaviour_filter_type_t *p_collective_behaviour_filter_type)
{
    return data_collection_lnode_create(p_collective_behaviour_filter_type, reinterpret_cast<void(*)(void*)>(data_collection_model_collective_behaviour_filter_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_collective_behaviour_filter_type_refcount(data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    if (!obj_collective_behaviour_filter_type) return 0l;
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

