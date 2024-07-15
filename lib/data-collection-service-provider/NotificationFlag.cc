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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "NotificationFlag.h" already included by data-collection-sp/data-collection.h */
#include "NotificationFlag-internal.h"
#include "openapi/model/NotificationFlag.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_notification_flag_t *data_collection_model_notification_flag_create()
{
    return reinterpret_cast<data_collection_model_notification_flag_t*>(new std::shared_ptr<NotificationFlag>(new NotificationFlag()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_notification_flag_t *data_collection_model_notification_flag_create_copy(const data_collection_model_notification_flag_t *other)
{
    return reinterpret_cast<data_collection_model_notification_flag_t*>(new std::shared_ptr<NotificationFlag >(new NotificationFlag(**reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_notification_flag_t *data_collection_model_notification_flag_create_move(data_collection_model_notification_flag_t *other)
{
    return reinterpret_cast<data_collection_model_notification_flag_t*>(new std::shared_ptr<NotificationFlag >(std::move(*reinterpret_cast<std::shared_ptr<NotificationFlag >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_notification_flag_t *data_collection_model_notification_flag_copy(data_collection_model_notification_flag_t *notification_flag, const data_collection_model_notification_flag_t *other)
{
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(notification_flag);
    *obj = **reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(other);
    return notification_flag;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_notification_flag_t *data_collection_model_notification_flag_move(data_collection_model_notification_flag_t *notification_flag, data_collection_model_notification_flag_t *other)
{
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(notification_flag);
    obj = std::move(*reinterpret_cast<std::shared_ptr<NotificationFlag >*>(other));
    return notification_flag;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_notification_flag_free(data_collection_model_notification_flag_t *notification_flag)
{
    delete reinterpret_cast<std::shared_ptr<NotificationFlag >*>(notification_flag);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_notification_flag_toJSON(const data_collection_model_notification_flag_t *notification_flag, bool as_request)
{
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(notification_flag);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_notification_flag_t *data_collection_model_notification_flag_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_not_set(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    return obj->getValue() == NotificationFlag::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_non_standard(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    return obj->getValue() == NotificationFlag::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_e data_collection_model_notification_flag_get_enum(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_notification_flag_get_string(const data_collection_model_notification_flag_t *obj_notification_flag)
{
    const std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<const std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_set_enum(data_collection_model_notification_flag_t *obj_notification_flag, data_collection_model_notification_flag_e p_value)
{
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_set_string(data_collection_model_notification_flag_t *obj_notification_flag, const char *p_value)
{
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NotificationFlag::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_notification_flag_make_lnode(data_collection_model_notification_flag_t *p_notification_flag)
{
    return data_collection_lnode_create(p_notification_flag, reinterpret_cast<void(*)(void*)>(data_collection_model_notification_flag_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_notification_flag_refcount(data_collection_model_notification_flag_t *obj_notification_flag)
{
    std::shared_ptr<NotificationFlag > &obj = *reinterpret_cast<std::shared_ptr<NotificationFlag >*>(obj_notification_flag);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

