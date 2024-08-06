/**********************************************************************************************************************************
 * NotificationMethod - C interface to the NotificationMethod object
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

/*#include "NotificationMethod.h" already included by data-collection-sp/data-collection.h */
#include "NotificationMethod-internal.h"
#include "openapi/model/NotificationMethod.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_create()
{
    return reinterpret_cast<data_collection_model_notification_method_t*>(new std::shared_ptr<NotificationMethod>(new NotificationMethod()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_create_copy(const data_collection_model_notification_method_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_notification_method_t*>(new std::shared_ptr<NotificationMethod >(new NotificationMethod(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_create_move(data_collection_model_notification_method_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NotificationMethod > *obj = reinterpret_cast<std::shared_ptr<NotificationMethod >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_copy(data_collection_model_notification_method_t *notification_method, const data_collection_model_notification_method_t *other)
{
    if (notification_method) {
        std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<std::shared_ptr<NotificationMethod >*>(notification_method);
        if (obj) {
            if (other) {
                const std::shared_ptr<NotificationMethod > &other_obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(other);
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
                const std::shared_ptr<NotificationMethod > &other_obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(other);
                if (other_obj) {
                    obj.reset(new NotificationMethod(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        notification_method = data_collection_model_notification_method_create_copy(other);
    }
    return notification_method;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_move(data_collection_model_notification_method_t *notification_method, data_collection_model_notification_method_t *other)
{
    std::shared_ptr<NotificationMethod > *other_ptr = reinterpret_cast<std::shared_ptr<NotificationMethod >*>(other);

    if (notification_method) {
        std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<std::shared_ptr<NotificationMethod >*>(notification_method);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                notification_method = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return notification_method;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_notification_method_free(data_collection_model_notification_method_t *notification_method)
{
    if (!notification_method) return;
    delete reinterpret_cast<std::shared_ptr<NotificationMethod >*>(notification_method);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_notification_method_toJSON(const data_collection_model_notification_method_t *notification_method, bool as_request)
{
    if (!notification_method) return NULL;
    const std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(notification_method);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_notification_method_t*>(new std::shared_ptr<NotificationMethod >(new NotificationMethod(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_is_equal_to(const data_collection_model_notification_method_t *first, const data_collection_model_notification_method_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NotificationMethod > &obj2 = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NotificationMethod > &obj1 = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_is_not_set(const data_collection_model_notification_method_t *obj_notification_method)
{
    if (!obj_notification_method) return true;
    const std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(obj_notification_method);
    if (!obj) return true;
    return obj->getValue() == NotificationMethod::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_is_non_standard(const data_collection_model_notification_method_t *obj_notification_method)
{
    if (!obj_notification_method) return false;
    const std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(obj_notification_method);
    if (!obj) return false;
    return obj->getValue() == NotificationMethod::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_e data_collection_model_notification_method_get_enum(const data_collection_model_notification_method_t *obj_notification_method)
{
    if (!obj_notification_method)
        return DCM_NOTIFICATION_METHOD_NO_VAL;
    const std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(obj_notification_method);
    if (!obj) return DCM_NOTIFICATION_METHOD_NO_VAL;
    switch (obj->getValue()) {
    case NotificationMethod::Enum::NO_VAL:
        return DCM_NOTIFICATION_METHOD_NO_VAL;
    case NotificationMethod::Enum::VAL_PERIODIC:
        return DCM_NOTIFICATION_METHOD_VAL_PERIODIC;
    case NotificationMethod::Enum::VAL_ONE_TIME:
        return DCM_NOTIFICATION_METHOD_VAL_ONE_TIME;
    case NotificationMethod::Enum::VAL_ON_EVENT_DETECTION:
        return DCM_NOTIFICATION_METHOD_VAL_ON_EVENT_DETECTION;
    default:
        break;
    }
    return DCM_NOTIFICATION_METHOD_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_notification_method_get_string(const data_collection_model_notification_method_t *obj_notification_method)
{
    if (!obj_notification_method) return NULL;
    const std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<const std::shared_ptr<NotificationMethod >*>(obj_notification_method);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_set_enum(data_collection_model_notification_method_t *obj_notification_method, data_collection_model_notification_method_e p_value)
{
    if (!obj_notification_method) return false;
    std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<std::shared_ptr<NotificationMethod >*>(obj_notification_method);
    if (!obj) return false;
    switch (p_value) {
    case DCM_NOTIFICATION_METHOD_NO_VAL:
        *obj = NotificationMethod::Enum::NO_VAL;
        return true;
    case DCM_NOTIFICATION_METHOD_VAL_PERIODIC:
        *obj = NotificationMethod::Enum::VAL_PERIODIC;
        return true;
    case DCM_NOTIFICATION_METHOD_VAL_ONE_TIME:
        *obj = NotificationMethod::Enum::VAL_ONE_TIME;
        return true;
    case DCM_NOTIFICATION_METHOD_VAL_ON_EVENT_DETECTION:
        *obj = NotificationMethod::Enum::VAL_ON_EVENT_DETECTION;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_set_string(data_collection_model_notification_method_t *obj_notification_method, const char *p_value)
{
    if (!obj_notification_method) return false;
    std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<std::shared_ptr<NotificationMethod >*>(obj_notification_method);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NotificationMethod::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_notification_method_make_lnode(data_collection_model_notification_method_t *p_notification_method)
{
    return data_collection_lnode_create(p_notification_method, reinterpret_cast<void(*)(void*)>(data_collection_model_notification_method_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_notification_method_refcount(data_collection_model_notification_method_t *obj_notification_method)
{
    if (!obj_notification_method) return 0l;
    std::shared_ptr<NotificationMethod > &obj = *reinterpret_cast<std::shared_ptr<NotificationMethod >*>(obj_notification_method);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

