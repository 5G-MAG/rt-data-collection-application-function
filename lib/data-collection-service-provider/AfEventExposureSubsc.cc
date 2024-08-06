/**********************************************************************************************************************************
 * AfEventExposureSubsc - C interface to the AfEventExposureSubsc object
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

/*#include "AfEventExposureSubsc.h" already included by data-collection-sp/data-collection.h */
#include "AfEventExposureSubsc-internal.h"
#include "openapi/model/AfEventExposureSubsc.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create(






)
{
    return reinterpret_cast<data_collection_model_af_event_exposure_subsc_t*>(new std::shared_ptr<AfEventExposureSubsc>(new AfEventExposureSubsc(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create_copy(const data_collection_model_af_event_exposure_subsc_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_af_event_exposure_subsc_t*>(new std::shared_ptr<AfEventExposureSubsc >(new AfEventExposureSubsc(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create_move(data_collection_model_af_event_exposure_subsc_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AfEventExposureSubsc > *obj = reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_copy(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_af_event_exposure_subsc_t *other)
{
    if (af_event_exposure_subsc) {
        std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);
        if (obj) {
            if (other) {
                const std::shared_ptr<AfEventExposureSubsc > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(other);
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
                const std::shared_ptr<AfEventExposureSubsc > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(other);
                if (other_obj) {
                    obj.reset(new AfEventExposureSubsc(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        af_event_exposure_subsc = data_collection_model_af_event_exposure_subsc_create_copy(other);
    }
    return af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_af_event_exposure_subsc_t *other)
{
    std::shared_ptr<AfEventExposureSubsc > *other_ptr = reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(other);

    if (af_event_exposure_subsc) {
        std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                af_event_exposure_subsc = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_exposure_subsc_free(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc)
{
    if (!af_event_exposure_subsc) return;
    delete reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_exposure_subsc_toJSON(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, bool as_request)
{
    if (!af_event_exposure_subsc) return NULL;
    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_af_event_exposure_subsc_t*>(new std::shared_ptr<AfEventExposureSubsc >(new AfEventExposureSubsc(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_subsc_is_equal_to(const data_collection_model_af_event_exposure_subsc_t *first, const data_collection_model_af_event_exposure_subsc_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AfEventExposureSubsc > &obj2 = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AfEventExposureSubsc > &obj1 = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_data_acc_prof_id(const data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AfEventExposureSubsc::DataAccProfIdType ResultFromType;
    const ResultFromType result_from = obj->getDataAccProfId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_data_acc_prof_id(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const char* p_data_acc_prof_id)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_data_acc_prof_id;
    typedef typename AfEventExposureSubsc::DataAccProfIdType ValueType;

    ValueType value(value_from);
    if (!obj->setDataAccProfId(value)) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_data_acc_prof_id_move(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, char* p_data_acc_prof_id)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_data_acc_prof_id;
    typedef typename AfEventExposureSubsc::DataAccProfIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDataAccProfId(std::move(value))) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_subsc_get_events_subs(const data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventExposureSubsc::EventsSubsType ResultFromType;
    const ResultFromType result_from = obj->getEventsSubs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_events_subs_t *item_obj = reinterpret_cast<data_collection_model_events_subs_t*>(new std::shared_ptr<EventsSubs >(item));
        node = data_collection_model_events_subs_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_subs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const ogs_list_t* p_events_subs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_events_subs;
    typedef typename AfEventExposureSubsc::EventsSubsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setEventsSubs(value)) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_subs_move(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, ogs_list_t* p_events_subs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_events_subs;
    typedef typename AfEventExposureSubsc::EventsSubsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_events_subs);
    if (!obj->setEventsSubs(std::move(value))) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_add_events_subs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, data_collection_model_events_subs_t* p_events_subs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    typedef typename AfEventExposureSubsc::EventsSubsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_events_subs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addEventsSubs(value);
    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_remove_events_subs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const data_collection_model_events_subs_t* p_events_subs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    typedef typename AfEventExposureSubsc::EventsSubsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_events_subs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeEventsSubs(value);
    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_clear_events_subs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    obj->clearEventsSubs();
    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_reporting_information_t* data_collection_model_af_event_exposure_subsc_get_events_rep_info(const data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) {
        const data_collection_model_reporting_information_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) {
        const data_collection_model_reporting_information_t *result = NULL;
        return result;
    }

    typedef typename AfEventExposureSubsc::EventsRepInfoType ResultFromType;
    const ResultFromType result_from = obj->getEventsRepInfo();
    const data_collection_model_reporting_information_t *result = reinterpret_cast<const data_collection_model_reporting_information_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_rep_info(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const data_collection_model_reporting_information_t* p_events_rep_info)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_events_rep_info;
    typedef typename AfEventExposureSubsc::EventsRepInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEventsRepInfo(value)) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_rep_info_move(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, data_collection_model_reporting_information_t* p_events_rep_info)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_events_rep_info;
    typedef typename AfEventExposureSubsc::EventsRepInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEventsRepInfo(std::move(value))) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_notif_uri(const data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AfEventExposureSubsc::NotifUriType ResultFromType;
    const ResultFromType result_from = obj->getNotifUri();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_uri(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const char* p_notif_uri)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_notif_uri;
    typedef typename AfEventExposureSubsc::NotifUriType ValueType;

    ValueType value(value_from);
    if (!obj->setNotifUri(value)) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_uri_move(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, char* p_notif_uri)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_notif_uri;
    typedef typename AfEventExposureSubsc::NotifUriType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNotifUri(std::move(value))) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_notif_id(const data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AfEventExposureSubsc::NotifIdType ResultFromType;
    const ResultFromType result_from = obj->getNotifId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_id(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const char* p_notif_id)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_notif_id;
    typedef typename AfEventExposureSubsc::NotifIdType ValueType;

    ValueType value(value_from);
    if (!obj->setNotifId(value)) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_id_move(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, char* p_notif_id)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_notif_id;
    typedef typename AfEventExposureSubsc::NotifIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNotifId(std::move(value))) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_subsc_get_event_notifs(const data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventExposureSubsc::EventNotifsType ResultFromType;
    const ResultFromType result_from = obj->getEventNotifs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_af_event_notification_t *item_obj = reinterpret_cast<data_collection_model_af_event_notification_t*>(new std::shared_ptr<AfEventNotification >(item));
        node = data_collection_model_af_event_notification_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_event_notifs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const ogs_list_t* p_event_notifs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_event_notifs;
    typedef typename AfEventExposureSubsc::EventNotifsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setEventNotifs(value)) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_event_notifs_move(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, ogs_list_t* p_event_notifs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_event_notifs;
    typedef typename AfEventExposureSubsc::EventNotifsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_event_notifs);
    if (!obj->setEventNotifs(std::move(value))) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_add_event_notifs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, data_collection_model_af_event_notification_t* p_event_notifs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    typedef typename AfEventExposureSubsc::EventNotifsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_event_notifs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addEventNotifs(value);
    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_remove_event_notifs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const data_collection_model_af_event_notification_t* p_event_notifs)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    typedef typename AfEventExposureSubsc::EventNotifsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_event_notifs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeEventNotifs(value);
    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_clear_event_notifs(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    obj->clearEventNotifs();
    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_supp_feat(const data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AfEventExposureSubsc::SuppFeatType ResultFromType;
    const ResultFromType result_from = obj->getSuppFeat();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_supp_feat(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, const char* p_supp_feat)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_supp_feat;
    typedef typename AfEventExposureSubsc::SuppFeatType ValueType;

    ValueType value(value_from);
    if (!obj->setSuppFeat(value)) return NULL;

    return obj_af_event_exposure_subsc;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_supp_feat_move(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc, char* p_supp_feat)
{
    if (!obj_af_event_exposure_subsc) return NULL;

    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    if (!obj) return NULL;

    const auto &value_from = p_supp_feat;
    typedef typename AfEventExposureSubsc::SuppFeatType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSuppFeat(std::move(value))) return NULL;

    return obj_af_event_exposure_subsc;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_exposure_subsc_make_lnode(data_collection_model_af_event_exposure_subsc_t *p_af_event_exposure_subsc)
{
    return data_collection_lnode_create(p_af_event_exposure_subsc, reinterpret_cast<void(*)(void*)>(data_collection_model_af_event_exposure_subsc_free));
}

/***** Internal library protected functions *****/


#include "openapi/model/AfEventExposureNotif.h"

/** Get the JSON for an AfEventExposureSubsc response which includes the given notifications
 *
 * If af_events_notifications is NULL then there are no event notifications to include and the JSON object will leave this part of
 * the response empty.
 * It is the callers responsibilty to call cJSON_Delete() on the returned cJSON object pointer.
 */
extern "C" cJSON *_model_af_event_exposure_subsc_generate_response(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t *af_events_notifications)
{
    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);

    /* copy AfEventExposureSubsc */
    std::shared_ptr<AfEventExposureSubsc > resp(new AfEventExposureSubsc(*obj));
    
    /* Add notifications */
    if (af_events_notifications && !ogs_list_empty(af_events_notifications)) {
        data_collection_lnode_t *node;
        ogs_list_for_each(af_events_notifications, node) {
            const AfEventExposureNotif::EventNotifsItemType &notif = *reinterpret_cast<const AfEventExposureNotif::EventNotifsItemType*>(node->object);
            resp->addEventNotifs(notif);
        }
    }

    /* return the JSON */
    fiveg_mag_reftools::CJson json(resp->toJSON(true));
    return json.exportCJSON();
}

/** Get the JSON for an AfEventExposureNotif callback request which includes the given notifications
 *
 * If af_events_notifications is NULL or empty then there are no event notifications to include and NULL will be returned.
 * It is the callers responsibilty to call cJSON_Delete() on the returned cJSON object pointer.
 */
extern "C" cJSON *_model_af_event_exposure_subsc_generate_notification(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t *af_events_notifications)
{
    if (!af_events_notifications || ogs_list_empty(af_events_notifications)) return NULL;

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);

    std::shared_ptr<AfEventExposureNotif> notif(new AfEventExposureNotif());

    notif->setNotifId(obj->getNotifId());

    data_collection_lnode_t *node;
    ogs_list_for_each(af_events_notifications, node) {
        notif->addEventNotifs(*reinterpret_cast<const AfEventExposureNotif::EventNotifsItemType*>(node->object));
    }

    fiveg_mag_reftools::CJson json(notif->toJSON(true));
    return json.exportCJSON();
}

extern "C" long _model_af_event_exposure_subsc_refcount(data_collection_model_af_event_exposure_subsc_t *obj_af_event_exposure_subsc)
{
    if (!obj_af_event_exposure_subsc) return 0l;
    std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<std::shared_ptr<AfEventExposureSubsc >*>(obj_af_event_exposure_subsc);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

