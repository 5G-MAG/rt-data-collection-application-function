/**********************************************************************************************************************************
 * NotificationFlag - C interface to the NotificationFlag object
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

/*#include "NotificationFlag.h" already included by data-collection-sp/data-collection.h */
#include "NotificationFlag-internal.h"
#include "openapi/model/NotificationFlag.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_create()
{
    return reinterpret_cast<data_collection_model_notification_flag_t*>(new std::shared_ptr<NotificationFlag>(new NotificationFlag()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_create_copy(const data_collection_model_notification_flag_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_notification_flag_t*>(new std::shared_ptr<NotificationFlag >(new NotificationFlag(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_create_move(data_collection_model_notification_flag_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NotificationFlag > *obj = reinterpret_cast<std::shared_ptr<NotificationFlag >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_copy(data_collection_model_notification_flag_t *notification_flag, const data_collection_model_notification_flag_t *other)
{
    if (notification_flag) {
        std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(notification_flag);
        if (obj) {
            if (other) {
                const std::shared_ptr<NotificationFlag > &other_obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(other);
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
                const std::shared_ptr<NotificationFlag > &other_obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(other);
                if (other_obj) {
                    obj.reset(new NotificationFlag(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        notification_flag = data_collection_model_notification_flag_create_copy(other);
    }
    return notification_flag;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_move(data_collection_model_notification_flag_t *notification_flag, data_collection_model_notification_flag_t *other)
{
    std::shared_ptr<NotificationFlag > *other_ptr = reinterpret_cast<std::shared_ptr<NotificationFlag >*>(other);

    if (notification_flag) {
        std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(notification_flag);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                notification_flag = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return notification_flag;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_notification_flag_free(data_collection_model_notification_flag_t *notification_flag)
{
    if (!notification_flag) return;
    delete reinterpret_cast<std::shared_ptr<NotificationFlag >*>(notification_flag);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_notification_flag_toJSON(const data_collection_model_notification_flag_t *notification_flag, bool as_request)
{
    if (!notification_flag) return NULL;
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(notification_flag);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_notification_flag_t*>(new std::shared_ptr<NotificationFlag >(new NotificationFlag(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_equal_to(const data_collection_model_notification_flag_t *first, const data_collection_model_notification_flag_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NotificationFlag > &obj2 = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NotificationFlag > &obj1 = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_not_set(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    if (!obj_notification_flag) return true;
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    if (!obj) return true;
    return obj->getValue() == NotificationFlag::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_non_standard(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    if (!obj_notification_flag) return false;
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    if (!obj) return false;
    return obj->getValue() == NotificationFlag::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_e data_collection_model_notification_flag_get_enum(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    if (!obj_notification_flag)
        return DCM_NOTIFICATION_FLAG_NO_VAL;
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    if (!obj) return DCM_NOTIFICATION_FLAG_NO_VAL;
    switch (obj->getValue()) {
    case NotificationFlag::Enum::NO_VAL:
        return DCM_NOTIFICATION_FLAG_NO_VAL;
    case NotificationFlag::Enum::VAL_ACTIVATE:
        return DCM_NOTIFICATION_FLAG_VAL_ACTIVATE;
    case NotificationFlag::Enum::VAL_DEACTIVATE:
        return DCM_NOTIFICATION_FLAG_VAL_DEACTIVATE;
    case NotificationFlag::Enum::VAL_RETRIEVAL:
        return DCM_NOTIFICATION_FLAG_VAL_RETRIEVAL;
    default:
        break;
    }
    return DCM_NOTIFICATION_FLAG_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_notification_flag_get_string(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    if (!obj_notification_flag) return NULL;
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_set_enum(data_collection_model_notification_flag_t *obj_notification_flag, data_collection_model_notification_flag_e p_value)
{
    if (!obj_notification_flag) return false;
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    if (!obj) return false;
    switch (p_value) {
    case DCM_NOTIFICATION_FLAG_NO_VAL:
        *obj = NotificationFlag::Enum::NO_VAL;
        return true;
    case DCM_NOTIFICATION_FLAG_VAL_ACTIVATE:
        *obj = NotificationFlag::Enum::VAL_ACTIVATE;
        return true;
    case DCM_NOTIFICATION_FLAG_VAL_DEACTIVATE:
        *obj = NotificationFlag::Enum::VAL_DEACTIVATE;
        return true;
    case DCM_NOTIFICATION_FLAG_VAL_RETRIEVAL:
        *obj = NotificationFlag::Enum::VAL_RETRIEVAL;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_set_string(data_collection_model_notification_flag_t *obj_notification_flag, const char *p_value)
{
    if (!obj_notification_flag) return false;
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NotificationFlag::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_notification_flag_make_lnode(data_collection_model_notification_flag_t *p_notification_flag)
{
    return data_collection_lnode_create(p_notification_flag, reinterpret_cast<void(*)(void*)>(data_collection_model_notification_flag_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_notification_flag_refcount(data_collection_model_notification_flag_t *obj_notification_flag)
{
    if (!obj_notification_flag) return 0l;
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

