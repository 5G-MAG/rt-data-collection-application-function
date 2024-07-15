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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_create()
{
    return reinterpret_cast<data_collection_model_collective_behaviour_filter_type_t*>(new std::shared_ptr<CollectiveBehaviourFilterType>(new CollectiveBehaviourFilterType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_create_copy(const data_collection_model_collective_behaviour_filter_type_t *other)
{
    return reinterpret_cast<data_collection_model_collective_behaviour_filter_type_t*>(new std::shared_ptr<CollectiveBehaviourFilterType >(new CollectiveBehaviourFilterType(**reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_create_move(data_collection_model_collective_behaviour_filter_type_t *other)
{
    return reinterpret_cast<data_collection_model_collective_behaviour_filter_type_t*>(new std::shared_ptr<CollectiveBehaviourFilterType >(std::move(*reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_copy(data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type, const data_collection_model_collective_behaviour_filter_type_t *other)
{
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
    *obj = **reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(other);
    return collective_behaviour_filter_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_move(data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type, data_collection_model_collective_behaviour_filter_type_t *other)
{
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(other));
    return collective_behaviour_filter_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_collective_behaviour_filter_type_free(data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type)
{
    delete reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_collective_behaviour_filter_type_toJSON(const data_collection_model_collective_behaviour_filter_type_t *collective_behaviour_filter_type, bool as_request)
{
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(collective_behaviour_filter_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_collective_behaviour_filter_type_t *data_collection_model_collective_behaviour_filter_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_is_not_set(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    return obj->getValue() == CollectiveBehaviourFilterType::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_is_non_standard(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    return obj->getValue() == CollectiveBehaviourFilterType::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_type_e data_collection_model_collective_behaviour_filter_type_get_enum(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_collective_behaviour_filter_type_get_string(const data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    const std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_set_enum(data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type, data_collection_model_collective_behaviour_filter_type_e p_value)
{
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_type_set_string(data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type, const char *p_value)
{
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CollectiveBehaviourFilterType::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_collective_behaviour_filter_type_make_lnode(data_collection_model_collective_behaviour_filter_type_t *p_collective_behaviour_filter_type)
{
    return data_collection_lnode_create(p_collective_behaviour_filter_type, reinterpret_cast<void(*)(void*)>(data_collection_model_collective_behaviour_filter_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_collective_behaviour_filter_type_refcount(data_collection_model_collective_behaviour_filter_type_t *obj_collective_behaviour_filter_type)
{
    std::shared_ptr<CollectiveBehaviourFilterType > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilterType >*>(obj_collective_behaviour_filter_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

