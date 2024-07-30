/**********************************************************************************************************************************
 * SubscriptionAction - C interface to the SubscriptionAction object
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

/*#include "SubscriptionAction.h" already included by data-collection-sp/data-collection.h */
#include "SubscriptionAction-internal.h"
#include "openapi/model/SubscriptionAction.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_subscription_action_t *data_collection_model_subscription_action_create()
{
    return reinterpret_cast<data_collection_model_subscription_action_t*>(new std::shared_ptr<SubscriptionAction>(new SubscriptionAction()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_subscription_action_t *data_collection_model_subscription_action_create_copy(const data_collection_model_subscription_action_t *other)
{
    return reinterpret_cast<data_collection_model_subscription_action_t*>(new std::shared_ptr<SubscriptionAction >(new SubscriptionAction(**reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_subscription_action_t *data_collection_model_subscription_action_create_move(data_collection_model_subscription_action_t *other)
{
    return reinterpret_cast<data_collection_model_subscription_action_t*>(new std::shared_ptr<SubscriptionAction >(std::move(*reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_subscription_action_t *data_collection_model_subscription_action_copy(data_collection_model_subscription_action_t *subscription_action, const data_collection_model_subscription_action_t *other)
{
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(subscription_action);
    *obj = **reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(other);
    return subscription_action;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_subscription_action_t *data_collection_model_subscription_action_move(data_collection_model_subscription_action_t *subscription_action, data_collection_model_subscription_action_t *other)
{
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(subscription_action);
    obj = std::move(*reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(other));
    return subscription_action;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_subscription_action_free(data_collection_model_subscription_action_t *subscription_action)
{
    delete reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(subscription_action);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_subscription_action_toJSON(const data_collection_model_subscription_action_t *subscription_action, bool as_request)
{
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(subscription_action);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_subscription_action_t *data_collection_model_subscription_action_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_subscription_action_t*>(new std::shared_ptr<SubscriptionAction >(new SubscriptionAction(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_subscription_action_is_equal_to(const data_collection_model_subscription_action_t *first, const data_collection_model_subscription_action_t *second)
{
    const std::shared_ptr<SubscriptionAction > &obj1 = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(first);
    const std::shared_ptr<SubscriptionAction > &obj2 = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_is_not_set(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    return obj->getValue() == SubscriptionAction::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_is_non_standard(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    return obj->getValue() == SubscriptionAction::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_e data_collection_model_subscription_action_get_enum(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    switch (obj->getValue()) {
    case SubscriptionAction::Enum::NO_VAL:
        return DCM_SUBSCRIPTION_ACTION_NO_VAL;
    case SubscriptionAction::Enum::VAL_CLOSE:
        return DCM_SUBSCRIPTION_ACTION_VAL_CLOSE;
    case SubscriptionAction::Enum::VAL_CONTINUE_WITH_MUTING:
        return DCM_SUBSCRIPTION_ACTION_VAL_CONTINUE_WITH_MUTING;
    case SubscriptionAction::Enum::VAL_CONTINUE_WITHOUT_MUTING:
        return DCM_SUBSCRIPTION_ACTION_VAL_CONTINUE_WITHOUT_MUTING;
    default:
        break;
    }
    return DCM_SUBSCRIPTION_ACTION_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_subscription_action_get_string(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_set_enum(data_collection_model_subscription_action_t *obj_subscription_action, data_collection_model_subscription_action_e p_value)
{
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    switch (p_value) {
    case DCM_SUBSCRIPTION_ACTION_NO_VAL:
        *obj = SubscriptionAction::Enum::NO_VAL;
        return true;
    case DCM_SUBSCRIPTION_ACTION_VAL_CLOSE:
        *obj = SubscriptionAction::Enum::VAL_CLOSE;
        return true;
    case DCM_SUBSCRIPTION_ACTION_VAL_CONTINUE_WITH_MUTING:
        *obj = SubscriptionAction::Enum::VAL_CONTINUE_WITH_MUTING;
        return true;
    case DCM_SUBSCRIPTION_ACTION_VAL_CONTINUE_WITHOUT_MUTING:
        *obj = SubscriptionAction::Enum::VAL_CONTINUE_WITHOUT_MUTING;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_set_string(data_collection_model_subscription_action_t *obj_subscription_action, const char *p_value)
{
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = SubscriptionAction::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_subscription_action_make_lnode(data_collection_model_subscription_action_t *p_subscription_action)
{
    return data_collection_lnode_create(p_subscription_action, reinterpret_cast<void(*)(void*)>(data_collection_model_subscription_action_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_subscription_action_refcount(data_collection_model_subscription_action_t *obj_subscription_action)
{
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

