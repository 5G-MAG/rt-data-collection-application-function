/**********************************************************************************************************************************
 * AfEventExposureNotif - C interface to the AfEventExposureNotif object
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

/*#include "AfEventExposureNotif.h" already included by data-collection-sp/data-collection.h */
#include "AfEventExposureNotif-internal.h"
#include "openapi/model/AfEventExposureNotif.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create(

)
{
    return reinterpret_cast<data_collection_model_af_event_exposure_notif_t*>(new std::shared_ptr<AfEventExposureNotif>(new AfEventExposureNotif(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create_copy(const data_collection_model_af_event_exposure_notif_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_af_event_exposure_notif_t*>(new std::shared_ptr<AfEventExposureNotif >(new AfEventExposureNotif(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create_move(data_collection_model_af_event_exposure_notif_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AfEventExposureNotif > *obj = reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_copy(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const data_collection_model_af_event_exposure_notif_t *other)
{
    if (af_event_exposure_notif) {
        std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(af_event_exposure_notif);
        if (obj) {
            if (other) {
                const std::shared_ptr<AfEventExposureNotif > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(other);
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
                const std::shared_ptr<AfEventExposureNotif > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(other);
                if (other_obj) {
                    obj.reset(new AfEventExposureNotif(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        af_event_exposure_notif = data_collection_model_af_event_exposure_notif_create_copy(other);
    }
    return af_event_exposure_notif;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_move(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, data_collection_model_af_event_exposure_notif_t *other)
{
    std::shared_ptr<AfEventExposureNotif > *other_ptr = reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(other);

    if (af_event_exposure_notif) {
        std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(af_event_exposure_notif);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                af_event_exposure_notif = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return af_event_exposure_notif;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_exposure_notif_free(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif)
{
    if (!af_event_exposure_notif) return;
    delete reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(af_event_exposure_notif);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_exposure_notif_toJSON(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, bool as_request)
{
    if (!af_event_exposure_notif) return NULL;
    const std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(af_event_exposure_notif);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_af_event_exposure_notif_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_af_event_exposure_notif_t*>(new std::shared_ptr<AfEventExposureNotif >(new AfEventExposureNotif(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_notif_is_equal_to(const data_collection_model_af_event_exposure_notif_t *first, const data_collection_model_af_event_exposure_notif_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AfEventExposureNotif > &obj2 = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AfEventExposureNotif > &obj1 = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_notif_get_notif_id(const data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif)
{
    if (!obj_af_event_exposure_notif) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AfEventExposureNotif::NotifIdType ResultFromType;
    const ResultFromType &result_from = obj->getNotifId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_notif_id(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif, const char* p_notif_id)
{
    if (!obj_af_event_exposure_notif) return NULL;

    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) return NULL;

    const auto &value_from = p_notif_id;
    typedef typename AfEventExposureNotif::NotifIdType ValueType;

    ValueType value(value_from);

    if (!obj->setNotifId(value)) return NULL;

    return obj_af_event_exposure_notif;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_notif_id_move(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif, char* p_notif_id)
{
    if (!obj_af_event_exposure_notif) return NULL;

    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) return NULL;

    const auto &value_from = p_notif_id;
    typedef typename AfEventExposureNotif::NotifIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setNotifId(std::move(value))) return NULL;

    return obj_af_event_exposure_notif;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_notif_get_event_notifs(const data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif)
{
    if (!obj_af_event_exposure_notif) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventExposureNotif::EventNotifsType ResultFromType;
    const ResultFromType &result_from = obj->getEventNotifs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_af_event_notification_t *item_obj = reinterpret_cast<data_collection_model_af_event_notification_t*>(item.has_value()?new std::shared_ptr<AfEventNotification >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_af_event_notification_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_event_notifs(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif, const ogs_list_t* p_event_notifs)
{
    if (!obj_af_event_exposure_notif) return NULL;

    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) return NULL;

    const auto &value_from = p_event_notifs;
    typedef typename AfEventExposureNotif::EventNotifsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setEventNotifs(value)) return NULL;

    return obj_af_event_exposure_notif;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_event_notifs_move(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif, ogs_list_t* p_event_notifs)
{
    if (!obj_af_event_exposure_notif) return NULL;

    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) return NULL;

    const auto &value_from = p_event_notifs;
    typedef typename AfEventExposureNotif::EventNotifsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_event_notifs);
    if (!obj->setEventNotifs(std::move(value))) return NULL;

    return obj_af_event_exposure_notif;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_add_event_notifs(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif, data_collection_model_af_event_notification_t* p_event_notifs)
{
    if (!obj_af_event_exposure_notif) return NULL;

    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) return NULL;

    typedef typename AfEventExposureNotif::EventNotifsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_event_notifs;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    obj->addEventNotifs(value);
    return obj_af_event_exposure_notif;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_remove_event_notifs(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif, const data_collection_model_af_event_notification_t* p_event_notifs)
{
    if (!obj_af_event_exposure_notif) return NULL;

    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) return NULL;

    typedef typename AfEventExposureNotif::EventNotifsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_event_notifs;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeEventNotifs(value);
    return obj_af_event_exposure_notif;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_clear_event_notifs(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif)
{
    if (!obj_af_event_exposure_notif) return NULL;

    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    if (!obj) return NULL;

    obj->clearEventNotifs();
    return obj_af_event_exposure_notif;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_exposure_notif_make_lnode(data_collection_model_af_event_exposure_notif_t *p_af_event_exposure_notif)
{
    return data_collection_lnode_create(p_af_event_exposure_notif, reinterpret_cast<void(*)(void*)>(data_collection_model_af_event_exposure_notif_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_af_event_exposure_notif_refcount(data_collection_model_af_event_exposure_notif_t *obj_af_event_exposure_notif)
{
    if (!obj_af_event_exposure_notif) return 0l;
    std::shared_ptr<AfEventExposureNotif > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureNotif >*>(obj_af_event_exposure_notif);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

