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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create(

)
{
    return reinterpret_cast<data_collection_model_muting_notifications_settings_t*>(new std::shared_ptr<MutingNotificationsSettings>(new MutingNotificationsSettings(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_copy(const data_collection_model_muting_notifications_settings_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_muting_notifications_settings_t*>(new std::shared_ptr<MutingNotificationsSettings >(new MutingNotificationsSettings(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_move(data_collection_model_muting_notifications_settings_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MutingNotificationsSettings > *obj = reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_copy(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const data_collection_model_muting_notifications_settings_t *other)
{
    if (muting_notifications_settings) {
        std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
        if (obj) {
            if (other) {
                const std::shared_ptr<MutingNotificationsSettings > &other_obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(other);
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
                const std::shared_ptr<MutingNotificationsSettings > &other_obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(other);
                if (other_obj) {
                    obj.reset(new MutingNotificationsSettings(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        muting_notifications_settings = data_collection_model_muting_notifications_settings_create_copy(other);
    }
    return muting_notifications_settings;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, data_collection_model_muting_notifications_settings_t *other)
{
    std::shared_ptr<MutingNotificationsSettings > *other_ptr = reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(other);

    if (muting_notifications_settings) {
        std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                muting_notifications_settings = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return muting_notifications_settings;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_muting_notifications_settings_free(data_collection_model_muting_notifications_settings_t *muting_notifications_settings)
{
    if (!muting_notifications_settings) return;
    delete reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_muting_notifications_settings_toJSON(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings, bool as_request)
{
    if (!muting_notifications_settings) return NULL;
    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(muting_notifications_settings);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_notifications_settings_is_equal_to(const data_collection_model_muting_notifications_settings_t *first, const data_collection_model_muting_notifications_settings_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MutingNotificationsSettings > &obj2 = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MutingNotificationsSettings > &obj1 = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_notifications_settings_has_max_no_of_notif(const data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    if (!obj_muting_notifications_settings) return false;

    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) return false;

    return obj->getMaxNoOfNotif().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_muting_notifications_settings_get_max_no_of_notif(const data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    if (!obj_muting_notifications_settings) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename MutingNotificationsSettings::MaxNoOfNotifType ResultFromType;
    const ResultFromType result_from = obj->getMaxNoOfNotif();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, const int32_t p_max_no_of_notif)
{
    if (!obj_muting_notifications_settings) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) return NULL;

    const auto &value_from = p_max_no_of_notif;
    typedef typename MutingNotificationsSettings::MaxNoOfNotifType ValueType;

    ValueType value(value_from);

    if (!obj->setMaxNoOfNotif(value)) return NULL;

    return obj_muting_notifications_settings;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif_move(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, int32_t p_max_no_of_notif)
{
    if (!obj_muting_notifications_settings) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) return NULL;

    const auto &value_from = p_max_no_of_notif;
    typedef typename MutingNotificationsSettings::MaxNoOfNotifType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaxNoOfNotif(std::move(value))) return NULL;

    return obj_muting_notifications_settings;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_notifications_settings_has_duration_buffered_notif(const data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    if (!obj_muting_notifications_settings) return false;

    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) return false;

    return obj->getDurationBufferedNotif().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_muting_notifications_settings_get_duration_buffered_notif(const data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    if (!obj_muting_notifications_settings) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<const std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename MutingNotificationsSettings::DurationBufferedNotifType ResultFromType;
    const ResultFromType result_from = obj->getDurationBufferedNotif();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, const int32_t p_duration_buffered_notif)
{
    if (!obj_muting_notifications_settings) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) return NULL;

    const auto &value_from = p_duration_buffered_notif;
    typedef typename MutingNotificationsSettings::DurationBufferedNotifType ValueType;

    ValueType value(value_from);

    if (!obj->setDurationBufferedNotif(value)) return NULL;

    return obj_muting_notifications_settings;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif_move(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings, int32_t p_duration_buffered_notif)
{
    if (!obj_muting_notifications_settings) return NULL;

    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    if (!obj) return NULL;

    const auto &value_from = p_duration_buffered_notif;
    typedef typename MutingNotificationsSettings::DurationBufferedNotifType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDurationBufferedNotif(std::move(value))) return NULL;

    return obj_muting_notifications_settings;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_muting_notifications_settings_make_lnode(data_collection_model_muting_notifications_settings_t *p_muting_notifications_settings)
{
    return data_collection_lnode_create(p_muting_notifications_settings, reinterpret_cast<void(*)(void*)>(data_collection_model_muting_notifications_settings_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_muting_notifications_settings_refcount(data_collection_model_muting_notifications_settings_t *obj_muting_notifications_settings)
{
    if (!obj_muting_notifications_settings) return 0l;
    std::shared_ptr<MutingNotificationsSettings > &obj = *reinterpret_cast<std::shared_ptr<MutingNotificationsSettings >*>(obj_muting_notifications_settings);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

