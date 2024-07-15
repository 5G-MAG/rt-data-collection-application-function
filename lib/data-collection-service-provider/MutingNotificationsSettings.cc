/**********************************************************************************************************************************
 * MutingNotificationsSettings - C interface to the MutingNotificationsSettings object
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

/*#include "MutingNotificationsSettings.h" already included by data-collection-sp/data-collection.h */
#include "MutingNotificationsSettings-internal.h"
#include "openapi/model/MutingNotificationsSettings.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create(

)
{
    return reinterpret_cast<data_collection_model_muting_notifications_settings_t*>(new std::shared_ptr<MutingNotificationsSettings>(new MutingNotificationsSettings(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_copy(const data_collection_model_muting_notifications_settings_t *other)
{
    return reinterpret_cast<data_collection_model_muting_notifications_settings_t*>(new std::shared_ptr<MutingNotificationsSettings >(new MutingNotificationsSettings(**reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_move(data_collection_model_muting_notifications_settings_t *other)
{
    return reinterpret_cast<data_collection_model_muting_notifications_settings_t*>(new std::shared_ptr<MutingNotificationsSettings >(std::move(*reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_copy(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const data_collection_model_muting_notifications_settings_t *other)
{
    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
    *obj = **reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(other);
    return muting_notifications_settings;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, data_collection_model_muting_notifications_settings_t *other)
{
    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(other));
    return muting_notifications_settings;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_muting_notifications_settings_free(data_collection_model_muting_notifications_settings_t *muting_notifications_settings)
{
    delete reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_muting_notifications_settings_toJSON(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings, bool as_request)
{
    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_muting_notifications_settings_t*>(new std::shared_ptr<MutingNotificationsSettings >(new MutingNotificationsSettings(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_muting_notifications_settings_get_max_no_of_notif(const data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    typedef typename MutingNotificationsSettings::MaxNoOfNotifType ResultFromType;
    const ResultFromType result_from = obj->getMaxNoOfNotif();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, const int32_t p_max_no_of_notif)
{
    if (obj_muting_notifications_settings == NULL) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    const auto &value_from = p_max_no_of_notif;
    typedef typename MutingNotificationsSettings::MaxNoOfNotifType ValueType;

    ValueType value = value_from;
    if (!obj->setMaxNoOfNotif(value)) return NULL;
    return obj_muting_notifications_settings;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif_move(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, int32_t p_max_no_of_notif)
{
    if (obj_muting_notifications_settings == NULL) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    const auto &value_from = p_max_no_of_notif;
    typedef typename MutingNotificationsSettings::MaxNoOfNotifType ValueType;

    ValueType value = value_from;
    
    if (!obj->setMaxNoOfNotif(std::move(value))) return NULL;
    return obj_muting_notifications_settings;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_muting_notifications_settings_get_duration_buffered_notif(const data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    typedef typename MutingNotificationsSettings::DurationBufferedNotifType ResultFromType;
    const ResultFromType result_from = obj->getDurationBufferedNotif();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, const int32_t p_duration_buffered_notif)
{
    if (obj_muting_notifications_settings == NULL) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    const auto &value_from = p_duration_buffered_notif;
    typedef typename MutingNotificationsSettings::DurationBufferedNotifType ValueType;

    ValueType value = value_from;
    if (!obj->setDurationBufferedNotif(value)) return NULL;
    return obj_muting_notifications_settings;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif_move(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, int32_t p_duration_buffered_notif)
{
    if (obj_muting_notifications_settings == NULL) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    const auto &value_from = p_duration_buffered_notif;
    typedef typename MutingNotificationsSettings::DurationBufferedNotifType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDurationBufferedNotif(std::move(value))) return NULL;
    return obj_muting_notifications_settings;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_muting_notifications_settings_make_lnode(data_collection_model_muting_notifications_settings_t *p_muting_notifications_settings)
{
    return data_collection_lnode_create(p_muting_notifications_settings, reinterpret_cast<void(*)(void*)>(data_collection_model_muting_notifications_settings_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_muting_notifications_settings_refcount(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

