/**********************************************************************************************************************************
 * BufferedNotificationsAction_anyOf - C interface to the BufferedNotificationsAction_anyOf object
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

/*#include "BufferedNotificationsAction_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "BufferedNotificationsAction_anyOf-internal.h"
#include "openapi/model/BufferedNotificationsAction_anyOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_buffered_notifications_action_any_of_t *data_collection_model_buffered_notifications_action_any_of_create()
{
    return reinterpret_cast<data_collection_model_buffered_notifications_action_any_of_t*>(new std::shared_ptr<BufferedNotificationsAction_anyOf>(new BufferedNotificationsAction_anyOf()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_buffered_notifications_action_any_of_t *data_collection_model_buffered_notifications_action_any_of_create_copy(const data_collection_model_buffered_notifications_action_any_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_buffered_notifications_action_any_of_t*>(new std::shared_ptr<BufferedNotificationsAction_anyOf >(new BufferedNotificationsAction_anyOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_buffered_notifications_action_any_of_t *data_collection_model_buffered_notifications_action_any_of_create_move(data_collection_model_buffered_notifications_action_any_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<BufferedNotificationsAction_anyOf > *obj = reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_buffered_notifications_action_any_of_t *data_collection_model_buffered_notifications_action_any_of_copy(data_collection_model_buffered_notifications_action_any_of_t *buffered_notifications_action_any_of, const data_collection_model_buffered_notifications_action_any_of_t *other)
{
    if (buffered_notifications_action_any_of) {
        std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(buffered_notifications_action_any_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<BufferedNotificationsAction_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(other);
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
                const std::shared_ptr<BufferedNotificationsAction_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(other);
                if (other_obj) {
                    obj.reset(new BufferedNotificationsAction_anyOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        buffered_notifications_action_any_of = data_collection_model_buffered_notifications_action_any_of_create_copy(other);
    }
    return buffered_notifications_action_any_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_buffered_notifications_action_any_of_t *data_collection_model_buffered_notifications_action_any_of_move(data_collection_model_buffered_notifications_action_any_of_t *buffered_notifications_action_any_of, data_collection_model_buffered_notifications_action_any_of_t *other)
{
    std::shared_ptr<BufferedNotificationsAction_anyOf > *other_ptr = reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(other);

    if (buffered_notifications_action_any_of) {
        std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(buffered_notifications_action_any_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                buffered_notifications_action_any_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return buffered_notifications_action_any_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_buffered_notifications_action_any_of_free(data_collection_model_buffered_notifications_action_any_of_t *buffered_notifications_action_any_of)
{
    if (!buffered_notifications_action_any_of) return;
    delete reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(buffered_notifications_action_any_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_buffered_notifications_action_any_of_toJSON(const data_collection_model_buffered_notifications_action_any_of_t *buffered_notifications_action_any_of, bool as_request)
{
    if (!buffered_notifications_action_any_of) return NULL;
    const std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(buffered_notifications_action_any_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_buffered_notifications_action_any_of_t *data_collection_model_buffered_notifications_action_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_buffered_notifications_action_any_of_t*>(new std::shared_ptr<BufferedNotificationsAction_anyOf >(new BufferedNotificationsAction_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_buffered_notifications_action_any_of_is_equal_to(const data_collection_model_buffered_notifications_action_any_of_t *first, const data_collection_model_buffered_notifications_action_any_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<BufferedNotificationsAction_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<BufferedNotificationsAction_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_buffered_notifications_action_any_of_is_not_set(const data_collection_model_buffered_notifications_action_any_of_t *buffered_notifications_action_any_of)
{
    if (!buffered_notifications_action_any_of) return true;
    const std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(buffered_notifications_action_any_of);
    if (!obj) return true;
    return obj->getValue() == BufferedNotificationsAction_anyOf::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_buffered_notifications_action_any_of_e data_collection_model_buffered_notifications_action_any_of_get_enum(const data_collection_model_buffered_notifications_action_any_of_t *obj_buffered_notifications_action_any_of)
{
    if (!obj_buffered_notifications_action_any_of)
        return DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_NO_VAL;
    const std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(obj_buffered_notifications_action_any_of);
    if (!obj) return DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_NO_VAL;
    switch (obj->getValue()) {
    case BufferedNotificationsAction_anyOf::Enum::NO_VAL:
        return DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_NO_VAL;
    case BufferedNotificationsAction_anyOf::Enum::VAL_SEND_ALL:
        return DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_VAL_SEND_ALL;
    case BufferedNotificationsAction_anyOf::Enum::VAL_DISCARD_ALL:
        return DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_VAL_DISCARD_ALL;
    case BufferedNotificationsAction_anyOf::Enum::VAL_DROP_OLD:
        return DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_VAL_DROP_OLD;
    default:
        break;
    }
    return (data_collection_model_buffered_notifications_action_any_of_e)-1;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_buffered_notifications_action_any_of_get_string(const data_collection_model_buffered_notifications_action_any_of_t *obj_buffered_notifications_action_any_of)
{
    if (!obj_buffered_notifications_action_any_of) return NULL;
    const std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<BufferedNotificationsAction_anyOf >*>(obj_buffered_notifications_action_any_of);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_buffered_notifications_action_any_of_set_enum(data_collection_model_buffered_notifications_action_any_of_t *obj_buffered_notifications_action_any_of, data_collection_model_buffered_notifications_action_any_of_e p_value)
{
    if (!obj_buffered_notifications_action_any_of) return false;
    std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(obj_buffered_notifications_action_any_of);
    if (!obj) return false;
    switch (p_value) {
    case DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_NO_VAL:
        *obj = BufferedNotificationsAction_anyOf::Enum::NO_VAL;
        return true;
    case DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_VAL_SEND_ALL:
        *obj = BufferedNotificationsAction_anyOf::Enum::VAL_SEND_ALL;
        return true;
    case DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_VAL_DISCARD_ALL:
        *obj = BufferedNotificationsAction_anyOf::Enum::VAL_DISCARD_ALL;
        return true;
    case DCM_BUFFERED_NOTIFICATIONS_ACTION_ANY_OF_VAL_DROP_OLD:
        *obj = BufferedNotificationsAction_anyOf::Enum::VAL_DROP_OLD;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_buffered_notifications_action_any_of_set_string(data_collection_model_buffered_notifications_action_any_of_t *obj_buffered_notifications_action_any_of, const char *p_value)
{
    if (!obj_buffered_notifications_action_any_of) return false;
    std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(obj_buffered_notifications_action_any_of);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = BufferedNotificationsAction_anyOf::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_buffered_notifications_action_any_of_make_lnode(data_collection_model_buffered_notifications_action_any_of_t *p_buffered_notifications_action_any_of)
{
    return data_collection_lnode_create(p_buffered_notifications_action_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_buffered_notifications_action_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_buffered_notifications_action_any_of_refcount(data_collection_model_buffered_notifications_action_any_of_t *obj_buffered_notifications_action_any_of)
{
    if (!obj_buffered_notifications_action_any_of) return 0l;
    std::shared_ptr<BufferedNotificationsAction_anyOf > &obj = *reinterpret_cast<std::shared_ptr<BufferedNotificationsAction_anyOf >*>(obj_buffered_notifications_action_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
