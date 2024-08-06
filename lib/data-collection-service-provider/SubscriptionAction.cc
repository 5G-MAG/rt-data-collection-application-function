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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_t *data_collection_model_subscription_action_create()
{
    return reinterpret_cast<data_collection_model_subscription_action_t*>(new std::shared_ptr<SubscriptionAction>(new SubscriptionAction()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_t *data_collection_model_subscription_action_create_copy(const data_collection_model_subscription_action_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_subscription_action_t*>(new std::shared_ptr<SubscriptionAction >(new SubscriptionAction(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_t *data_collection_model_subscription_action_create_move(data_collection_model_subscription_action_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<SubscriptionAction > *obj = reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_t *data_collection_model_subscription_action_copy(data_collection_model_subscription_action_t *subscription_action, const data_collection_model_subscription_action_t *other)
{
    if (subscription_action) {
        std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(subscription_action);
        if (obj) {
            if (other) {
                const std::shared_ptr<SubscriptionAction > &other_obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(other);
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
                const std::shared_ptr<SubscriptionAction > &other_obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(other);
                if (other_obj) {
                    obj.reset(new SubscriptionAction(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        subscription_action = data_collection_model_subscription_action_create_copy(other);
    }
    return subscription_action;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_t *data_collection_model_subscription_action_move(data_collection_model_subscription_action_t *subscription_action, data_collection_model_subscription_action_t *other)
{
    std::shared_ptr<SubscriptionAction > *other_ptr = reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(other);

    if (subscription_action) {
        std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(subscription_action);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                subscription_action = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return subscription_action;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_subscription_action_free(data_collection_model_subscription_action_t *subscription_action)
{
    if (!subscription_action) return;
    delete reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(subscription_action);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_subscription_action_toJSON(const data_collection_model_subscription_action_t *subscription_action, bool as_request)
{
    if (!subscription_action) return NULL;
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(subscription_action);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_t *data_collection_model_subscription_action_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_is_equal_to(const data_collection_model_subscription_action_t *first, const data_collection_model_subscription_action_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<SubscriptionAction > &obj2 = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<SubscriptionAction > &obj1 = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_is_not_set(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    if (!obj_subscription_action) return true;
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    if (!obj) return true;
    return obj->getValue() == SubscriptionAction::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_is_non_standard(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    if (!obj_subscription_action) return false;
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    if (!obj) return false;
    return obj->getValue() == SubscriptionAction::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_e data_collection_model_subscription_action_get_enum(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    if (!obj_subscription_action)
        return DCM_SUBSCRIPTION_ACTION_NO_VAL;
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    if (!obj) return DCM_SUBSCRIPTION_ACTION_NO_VAL;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_subscription_action_get_string(const data_collection_model_subscription_action_t *obj_subscription_action)
{
    if (!obj_subscription_action) return NULL;
    const std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<const std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_set_enum(data_collection_model_subscription_action_t *obj_subscription_action, data_collection_model_subscription_action_e p_value)
{
    if (!obj_subscription_action) return false;
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    if (!obj) return false;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_set_string(data_collection_model_subscription_action_t *obj_subscription_action, const char *p_value)
{
    if (!obj_subscription_action) return false;
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = SubscriptionAction::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_subscription_action_make_lnode(data_collection_model_subscription_action_t *p_subscription_action)
{
    return data_collection_lnode_create(p_subscription_action, reinterpret_cast<void(*)(void*)>(data_collection_model_subscription_action_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_subscription_action_refcount(data_collection_model_subscription_action_t *obj_subscription_action)
{
    if (!obj_subscription_action) return 0l;
    std::shared_ptr<SubscriptionAction > &obj = *reinterpret_cast<std::shared_ptr<SubscriptionAction >*>(obj_subscription_action);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

