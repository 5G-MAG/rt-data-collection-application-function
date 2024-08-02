/**********************************************************************************************************************************
 * AfEventNotification - C interface to the AfEventNotification object
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

/*#include "AfEventNotification.h" already included by data-collection-sp/data-collection.h */
#include "AfEventNotification-internal.h"
#include "openapi/model/AfEventNotification.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create(





















)
{
    return reinterpret_cast<data_collection_model_af_event_notification_t*>(new std::shared_ptr<AfEventNotification>(new AfEventNotification(





















)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create_copy(const data_collection_model_af_event_notification_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_af_event_notification_t*>(new std::shared_ptr<AfEventNotification >(new AfEventNotification(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create_move(data_collection_model_af_event_notification_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AfEventNotification > *obj = reinterpret_cast<std::shared_ptr<AfEventNotification >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_copy(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_af_event_notification_t *other)
{
    if (af_event_notification) {
        std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(af_event_notification);
        if (obj) {
            if (other) {
                const std::shared_ptr<AfEventNotification > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(other);
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
                const std::shared_ptr<AfEventNotification > &other_obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(other);
                if (other_obj) {
                    obj.reset(new AfEventNotification(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        af_event_notification = data_collection_model_af_event_notification_create_copy(other);
    }
    return af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_move(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_af_event_notification_t *other)
{
    std::shared_ptr<AfEventNotification > *other_ptr = reinterpret_cast<std::shared_ptr<AfEventNotification >*>(other);

    if (af_event_notification) {
        std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(af_event_notification);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                af_event_notification = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_af_event_notification_free(data_collection_model_af_event_notification_t *af_event_notification)
{
    if (!af_event_notification) return;
    delete reinterpret_cast<std::shared_ptr<AfEventNotification >*>(af_event_notification);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_af_event_notification_toJSON(const data_collection_model_af_event_notification_t *af_event_notification, bool as_request)
{
    if (!af_event_notification) return NULL;
    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(af_event_notification);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_af_event_notification_t*>(new std::shared_ptr<AfEventNotification >(new AfEventNotification(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_af_event_notification_is_equal_to(const data_collection_model_af_event_notification_t *first, const data_collection_model_af_event_notification_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AfEventNotification > &obj2 = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AfEventNotification > &obj1 = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_af_event_t* data_collection_model_af_event_notification_get_event(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        const data_collection_model_af_event_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        const data_collection_model_af_event_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::EventType ResultFromType;
    const ResultFromType result_from = obj->getEvent();
    const data_collection_model_af_event_t *result = reinterpret_cast<const data_collection_model_af_event_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_event(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_af_event_t* p_event)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_event;
    typedef typename AfEventNotification::EventType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEvent(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_event_move(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_af_event_t* p_event)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_event;
    typedef typename AfEventNotification::EventType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEvent(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_af_event_notification_get_time_stamp(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::TimeStampType ResultFromType;
    const ResultFromType result_from = obj->getTimeStamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_time_stamp(data_collection_model_af_event_notification_t *obj_af_event_notification, const char* p_time_stamp)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_time_stamp;
    typedef typename AfEventNotification::TimeStampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimeStamp(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_time_stamp_move(data_collection_model_af_event_notification_t *obj_af_event_notification, char* p_time_stamp)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_time_stamp;
    typedef typename AfEventNotification::TimeStampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimeStamp(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_svc_exprc_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::SvcExprcInfosType ResultFromType;
    const ResultFromType result_from = obj->getSvcExprcInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_service_experience_info_per_app_t *item_obj = reinterpret_cast<data_collection_model_service_experience_info_per_app_t*>(new std::shared_ptr<ServiceExperienceInfoPerApp >(item));
        node = data_collection_model_service_experience_info_per_app_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_svc_exprc_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_svc_exprc_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exprc_infos;
    typedef typename AfEventNotification::SvcExprcInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setSvcExprcInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_svc_exprc_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_svc_exprc_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exprc_infos;
    typedef typename AfEventNotification::SvcExprcInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_svc_exprc_infos);
    if (!obj->setSvcExprcInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_svc_exprc_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_service_experience_info_per_app_t* p_svc_exprc_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::SvcExprcInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_svc_exprc_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addSvcExprcInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_svc_exprc_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_service_experience_info_per_app_t* p_svc_exprc_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::SvcExprcInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_svc_exprc_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeSvcExprcInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_svc_exprc_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearSvcExprcInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ue_mobility_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::UeMobilityInfosType ResultFromType;
    const ResultFromType result_from = obj->getUeMobilityInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ue_mobility_collection_t *item_obj = reinterpret_cast<data_collection_model_ue_mobility_collection_t*>(new std::shared_ptr<UeMobilityCollection >(item));
        node = data_collection_model_ue_mobility_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_mobility_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ue_mobility_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ue_mobility_infos;
    typedef typename AfEventNotification::UeMobilityInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setUeMobilityInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_mobility_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ue_mobility_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ue_mobility_infos;
    typedef typename AfEventNotification::UeMobilityInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ue_mobility_infos);
    if (!obj->setUeMobilityInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ue_mobility_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_ue_mobility_collection_t* p_ue_mobility_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::UeMobilityInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_mobility_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addUeMobilityInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ue_mobility_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_ue_mobility_collection_t* p_ue_mobility_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::UeMobilityInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_mobility_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeUeMobilityInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ue_mobility_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearUeMobilityInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ue_comm_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::UeCommInfosType ResultFromType;
    const ResultFromType result_from = obj->getUeCommInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ue_communication_collection_t *item_obj = reinterpret_cast<data_collection_model_ue_communication_collection_t*>(new std::shared_ptr<UeCommunicationCollection >(item));
        node = data_collection_model_ue_communication_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_comm_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ue_comm_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ue_comm_infos;
    typedef typename AfEventNotification::UeCommInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setUeCommInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_comm_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ue_comm_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ue_comm_infos;
    typedef typename AfEventNotification::UeCommInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ue_comm_infos);
    if (!obj->setUeCommInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ue_comm_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_ue_communication_collection_t* p_ue_comm_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::UeCommInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ue_comm_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addUeCommInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ue_comm_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_ue_communication_collection_t* p_ue_comm_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::UeCommInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ue_comm_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeUeCommInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ue_comm_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearUeCommInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_excep_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::ExcepInfosType ResultFromType;
    const ResultFromType result_from = obj->getExcepInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_exception_info_t *item_obj = reinterpret_cast<data_collection_model_exception_info_t*>(new std::shared_ptr<ExceptionInfo >(item));
        node = data_collection_model_exception_info_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_excep_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_excep_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_excep_infos;
    typedef typename AfEventNotification::ExcepInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setExcepInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_excep_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_excep_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_excep_infos;
    typedef typename AfEventNotification::ExcepInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_excep_infos);
    if (!obj->setExcepInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_excep_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_exception_info_t* p_excep_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::ExcepInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_excep_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addExcepInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_excep_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_exception_info_t* p_excep_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::ExcepInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_excep_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeExcepInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_excep_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearExcepInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_congestion_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::CongestionInfosType ResultFromType;
    const ResultFromType result_from = obj->getCongestionInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_user_data_congestion_collection_t *item_obj = reinterpret_cast<data_collection_model_user_data_congestion_collection_t*>(new std::shared_ptr<UserDataCongestionCollection >(item));
        node = data_collection_model_user_data_congestion_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_congestion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_congestion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_congestion_infos;
    typedef typename AfEventNotification::CongestionInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setCongestionInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_congestion_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_congestion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_congestion_infos;
    typedef typename AfEventNotification::CongestionInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_congestion_infos);
    if (!obj->setCongestionInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_congestion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_user_data_congestion_collection_t* p_congestion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::CongestionInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_congestion_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addCongestionInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_congestion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_user_data_congestion_collection_t* p_congestion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::CongestionInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_congestion_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeCongestionInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_congestion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearCongestionInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_perf_data_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::PerfDataInfosType ResultFromType;
    const ResultFromType result_from = obj->getPerfDataInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_performance_data_collection_t *item_obj = reinterpret_cast<data_collection_model_performance_data_collection_t*>(new std::shared_ptr<PerformanceDataCollection >(item));
        node = data_collection_model_performance_data_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_perf_data_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_perf_data_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_perf_data_infos;
    typedef typename AfEventNotification::PerfDataInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setPerfDataInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_perf_data_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_perf_data_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_perf_data_infos;
    typedef typename AfEventNotification::PerfDataInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_perf_data_infos);
    if (!obj->setPerfDataInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_perf_data_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_performance_data_collection_t* p_perf_data_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::PerfDataInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_perf_data_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addPerfDataInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_perf_data_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_performance_data_collection_t* p_perf_data_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::PerfDataInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_perf_data_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removePerfDataInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_perf_data_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearPerfDataInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_dispersion_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::DispersionInfosType ResultFromType;
    const ResultFromType result_from = obj->getDispersionInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_dispersion_collection_t *item_obj = reinterpret_cast<data_collection_model_dispersion_collection_t*>(new std::shared_ptr<DispersionCollection >(item));
        node = data_collection_model_dispersion_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dispersion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_dispersion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_dispersion_infos;
    typedef typename AfEventNotification::DispersionInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setDispersionInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dispersion_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_dispersion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_dispersion_infos;
    typedef typename AfEventNotification::DispersionInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_dispersion_infos);
    if (!obj->setDispersionInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_dispersion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_dispersion_collection_t* p_dispersion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::DispersionInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_dispersion_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addDispersionInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_dispersion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_dispersion_collection_t* p_dispersion_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::DispersionInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_dispersion_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeDispersionInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_dispersion_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearDispersionInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_coll_bhvr_infs(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::CollBhvrInfsType ResultFromType;
    const ResultFromType result_from = obj->getCollBhvrInfs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_collective_behaviour_info_t *item_obj = reinterpret_cast<data_collection_model_collective_behaviour_info_t*>(new std::shared_ptr<CollectiveBehaviourInfo >(item));
        node = data_collection_model_collective_behaviour_info_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_coll_bhvr_infs(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_coll_bhvr_infs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_coll_bhvr_infs;
    typedef typename AfEventNotification::CollBhvrInfsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setCollBhvrInfs(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_coll_bhvr_infs_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_coll_bhvr_infs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_coll_bhvr_infs;
    typedef typename AfEventNotification::CollBhvrInfsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_coll_bhvr_infs);
    if (!obj->setCollBhvrInfs(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_coll_bhvr_infs(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_collective_behaviour_info_t* p_coll_bhvr_infs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::CollBhvrInfsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_coll_bhvr_infs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addCollBhvrInfs(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_coll_bhvr_infs(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_collective_behaviour_info_t* p_coll_bhvr_infs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::CollBhvrInfsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_coll_bhvr_infs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeCollBhvrInfs(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_coll_bhvr_infs(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearCollBhvrInfs();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_qoe_metr_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsQoeMetrInfosType ResultFromType;
    const ResultFromType result_from = obj->getMsQoeMetrInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ms_qoe_metrics_collection_t *item_obj = reinterpret_cast<data_collection_model_ms_qoe_metrics_collection_t*>(new std::shared_ptr<MsQoeMetricsCollection >(item));
        node = data_collection_model_ms_qoe_metrics_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_qoe_metr_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_qoe_metr_infos;
    typedef typename AfEventNotification::MsQoeMetrInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsQoeMetrInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metr_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_qoe_metr_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_qoe_metr_infos;
    typedef typename AfEventNotification::MsQoeMetrInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_qoe_metr_infos);
    if (!obj->setMsQoeMetrInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_ms_qoe_metrics_collection_t* p_ms_qoe_metr_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsQoeMetrInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_qoe_metr_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsQoeMetrInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_ms_qoe_metrics_collection_t* p_ms_qoe_metr_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsQoeMetrInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_qoe_metr_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsQoeMetrInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsQoeMetrInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_qoe_metrics(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsQoeMetricsType ResultFromType;
    const ResultFromType result_from = obj->getMsQoeMetrics();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_qo_e_metrics_collection_t *item_obj = reinterpret_cast<data_collection_model_qo_e_metrics_collection_t*>(new std::shared_ptr<QoEMetricsCollection >(item));
        node = data_collection_model_qo_e_metrics_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metrics(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_qoe_metrics)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_qoe_metrics;
    typedef typename AfEventNotification::MsQoeMetricsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsQoeMetrics(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metrics_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_qoe_metrics)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_qoe_metrics;
    typedef typename AfEventNotification::MsQoeMetricsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_qoe_metrics);
    if (!obj->setMsQoeMetrics(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_qoe_metrics(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_qo_e_metrics_collection_t* p_ms_qoe_metrics)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsQoeMetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_qoe_metrics;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsQoeMetrics(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_qoe_metrics(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_qo_e_metrics_collection_t* p_ms_qoe_metrics)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsQoeMetricsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_qoe_metrics;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsQoeMetrics(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_qoe_metrics(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsQoeMetrics();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_consump_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsConsumpInfosType ResultFromType;
    const ResultFromType result_from = obj->getMsConsumpInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ms_consumption_collection_t *item_obj = reinterpret_cast<data_collection_model_ms_consumption_collection_t*>(new std::shared_ptr<MsConsumptionCollection >(item));
        node = data_collection_model_ms_consumption_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_consump_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_consump_infos;
    typedef typename AfEventNotification::MsConsumpInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsConsumpInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_consump_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_consump_infos;
    typedef typename AfEventNotification::MsConsumpInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_consump_infos);
    if (!obj->setMsConsumpInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_consump_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_ms_consumption_collection_t* p_ms_consump_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsConsumpInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_consump_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsConsumpInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_consump_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_ms_consumption_collection_t* p_ms_consump_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsConsumpInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_consump_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsConsumpInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_consump_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsConsumpInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_consump_rpts(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsConsumpRptsType ResultFromType;
    const ResultFromType result_from = obj->getMsConsumpRpts();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_consumption_reporting_units_collection_t *item_obj = reinterpret_cast<data_collection_model_consumption_reporting_units_collection_t*>(new std::shared_ptr<ConsumptionReportingUnitsCollection >(item));
        node = data_collection_model_consumption_reporting_units_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_rpts(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_consump_rpts)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_consump_rpts;
    typedef typename AfEventNotification::MsConsumpRptsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsConsumpRpts(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_rpts_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_consump_rpts)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_consump_rpts;
    typedef typename AfEventNotification::MsConsumpRptsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_consump_rpts);
    if (!obj->setMsConsumpRpts(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_consump_rpts(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_consumption_reporting_units_collection_t* p_ms_consump_rpts)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsConsumpRptsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_consump_rpts;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsConsumpRpts(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_consump_rpts(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_consumption_reporting_units_collection_t* p_ms_consump_rpts)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsConsumpRptsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_consump_rpts;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsConsumpRpts(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_consump_rpts(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsConsumpRpts();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_net_ass_inv_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsNetAssInvInfosType ResultFromType;
    const ResultFromType result_from = obj->getMsNetAssInvInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ms_net_ass_invocation_collection_t *item_obj = reinterpret_cast<data_collection_model_ms_net_ass_invocation_collection_t*>(new std::shared_ptr<MsNetAssInvocationCollection >(item));
        node = data_collection_model_ms_net_ass_invocation_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_net_ass_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_net_ass_inv_infos;
    typedef typename AfEventNotification::MsNetAssInvInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsNetAssInvInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_ass_inv_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_net_ass_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_net_ass_inv_infos;
    typedef typename AfEventNotification::MsNetAssInvInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_net_ass_inv_infos);
    if (!obj->setMsNetAssInvInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_ms_net_ass_invocation_collection_t* p_ms_net_ass_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsNetAssInvInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_net_ass_inv_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsNetAssInvInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_ms_net_ass_invocation_collection_t* p_ms_net_ass_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsNetAssInvInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_net_ass_inv_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsNetAssInvInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsNetAssInvInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_net_assist_invs(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsNetAssistInvsType ResultFromType;
    const ResultFromType result_from = obj->getMsNetAssistInvs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_network_assistance_invocations_collection_t *item_obj = reinterpret_cast<data_collection_model_network_assistance_invocations_collection_t*>(new std::shared_ptr<NetworkAssistanceInvocationsCollection >(item));
        node = data_collection_model_network_assistance_invocations_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_assist_invs(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_net_assist_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_net_assist_invs;
    typedef typename AfEventNotification::MsNetAssistInvsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsNetAssistInvs(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_assist_invs_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_net_assist_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_net_assist_invs;
    typedef typename AfEventNotification::MsNetAssistInvsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_net_assist_invs);
    if (!obj->setMsNetAssistInvs(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_net_assist_invs(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_network_assistance_invocations_collection_t* p_ms_net_assist_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsNetAssistInvsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_net_assist_invs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsNetAssistInvs(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_net_assist_invs(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_network_assistance_invocations_collection_t* p_ms_net_assist_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsNetAssistInvsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_net_assist_invs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsNetAssistInvs(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_net_assist_invs(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsNetAssistInvs();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_dyn_ply_inv_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsDynPlyInvInfosType ResultFromType;
    const ResultFromType result_from = obj->getMsDynPlyInvInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ms_dyn_policy_invocation_collection_t *item_obj = reinterpret_cast<data_collection_model_ms_dyn_policy_invocation_collection_t*>(new std::shared_ptr<MsDynPolicyInvocationCollection >(item));
        node = data_collection_model_ms_dyn_policy_invocation_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_dyn_ply_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_dyn_ply_inv_infos;
    typedef typename AfEventNotification::MsDynPlyInvInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsDynPlyInvInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_inv_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_dyn_ply_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_dyn_ply_inv_infos;
    typedef typename AfEventNotification::MsDynPlyInvInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_dyn_ply_inv_infos);
    if (!obj->setMsDynPlyInvInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_ms_dyn_policy_invocation_collection_t* p_ms_dyn_ply_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsDynPlyInvInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_dyn_ply_inv_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsDynPlyInvInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_ms_dyn_policy_invocation_collection_t* p_ms_dyn_ply_inv_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsDynPlyInvInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_dyn_ply_inv_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsDynPlyInvInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsDynPlyInvInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_dyn_ply_invs(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsDynPlyInvsType ResultFromType;
    const ResultFromType result_from = obj->getMsDynPlyInvs();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_dynamic_policy_invocations_collection_t *item_obj = reinterpret_cast<data_collection_model_dynamic_policy_invocations_collection_t*>(new std::shared_ptr<DynamicPolicyInvocationsCollection >(item));
        node = data_collection_model_dynamic_policy_invocations_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_dyn_ply_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_dyn_ply_invs;
    typedef typename AfEventNotification::MsDynPlyInvsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsDynPlyInvs(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_invs_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_dyn_ply_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_dyn_ply_invs;
    typedef typename AfEventNotification::MsDynPlyInvsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_dyn_ply_invs);
    if (!obj->setMsDynPlyInvs(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_dynamic_policy_invocations_collection_t* p_ms_dyn_ply_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsDynPlyInvsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_dyn_ply_invs;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsDynPlyInvs(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_dynamic_policy_invocations_collection_t* p_ms_dyn_ply_invs)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsDynPlyInvsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_dyn_ply_invs;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsDynPlyInvs(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsDynPlyInvs();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_acc_act_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsAccActInfosType ResultFromType;
    const ResultFromType result_from = obj->getMsAccActInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ms_access_activity_collection_t *item_obj = reinterpret_cast<data_collection_model_ms_access_activity_collection_t*>(new std::shared_ptr<MSAccessActivityCollection >(item));
        node = data_collection_model_ms_access_activity_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_acc_act_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_acc_act_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_acc_act_infos;
    typedef typename AfEventNotification::MsAccActInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsAccActInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_acc_act_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_acc_act_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_acc_act_infos;
    typedef typename AfEventNotification::MsAccActInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_acc_act_infos);
    if (!obj->setMsAccActInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_acc_act_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_ms_access_activity_collection_t* p_ms_acc_act_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsAccActInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_acc_act_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsAccActInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_acc_act_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_ms_access_activity_collection_t* p_ms_acc_act_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsAccActInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_acc_act_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsAccActInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_acc_act_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsAccActInfos();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_ms_accesses(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::MsAccessesType ResultFromType;
    const ResultFromType result_from = obj->getMsAccesses();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_media_streaming_accesses_collection_t *item_obj = reinterpret_cast<data_collection_model_media_streaming_accesses_collection_t*>(new std::shared_ptr<MediaStreamingAccessesCollection >(item));
        node = data_collection_model_media_streaming_accesses_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_accesses(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_ms_accesses)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_accesses;
    typedef typename AfEventNotification::MsAccessesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMsAccesses(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_accesses_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_ms_accesses)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_ms_accesses;
    typedef typename AfEventNotification::MsAccessesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_ms_accesses);
    if (!obj->setMsAccesses(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_accesses(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_media_streaming_accesses_collection_t* p_ms_accesses)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsAccessesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_accesses;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMsAccesses(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_accesses(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_media_streaming_accesses_collection_t* p_ms_accesses)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::MsAccessesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_accesses;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMsAccesses(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_accesses(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearMsAccesses();
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_gnss_assist_data_info_t* data_collection_model_af_event_notification_get_gnss_assist_data_info(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        const data_collection_model_gnss_assist_data_info_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        const data_collection_model_gnss_assist_data_info_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::GnssAssistDataInfoType ResultFromType;
    const ResultFromType result_from = obj->getGnssAssistDataInfo();
    const data_collection_model_gnss_assist_data_info_t *result = reinterpret_cast<const data_collection_model_gnss_assist_data_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_gnss_assist_data_info(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_gnss_assist_data_info_t* p_gnss_assist_data_info)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_gnss_assist_data_info;
    typedef typename AfEventNotification::GnssAssistDataInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setGnssAssistDataInfo(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_gnss_assist_data_info_move(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_gnss_assist_data_info_t* p_gnss_assist_data_info)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_gnss_assist_data_info;
    typedef typename AfEventNotification::GnssAssistDataInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setGnssAssistDataInfo(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_af_event_notification_get_dat_vol_trans_time_infos(const data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<const std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AfEventNotification::DatVolTransTimeInfosType ResultFromType;
    const ResultFromType result_from = obj->getDatVolTransTimeInfos();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_dat_vol_trans_time_collection_t *item_obj = reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection >(item));
        node = data_collection_model_dat_vol_trans_time_collection_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const ogs_list_t* p_dat_vol_trans_time_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_dat_vol_trans_time_infos;
    typedef typename AfEventNotification::DatVolTransTimeInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setDatVolTransTimeInfos(value)) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dat_vol_trans_time_infos_move(data_collection_model_af_event_notification_t *obj_af_event_notification, ogs_list_t* p_dat_vol_trans_time_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    const auto &value_from = p_dat_vol_trans_time_infos;
    typedef typename AfEventNotification::DatVolTransTimeInfosType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_dat_vol_trans_time_infos);
    if (!obj->setDatVolTransTimeInfos(std::move(value))) return NULL;

    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, data_collection_model_dat_vol_trans_time_collection_t* p_dat_vol_trans_time_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::DatVolTransTimeInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_dat_vol_trans_time_infos;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addDatVolTransTimeInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *obj_af_event_notification, const data_collection_model_dat_vol_trans_time_collection_t* p_dat_vol_trans_time_infos)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    typedef typename AfEventNotification::DatVolTransTimeInfosType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_dat_vol_trans_time_infos;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeDatVolTransTimeInfos(value);
    return obj_af_event_notification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return NULL;

    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    if (!obj) return NULL;

    obj->clearDatVolTransTimeInfos();
    return obj_af_event_notification;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_af_event_notification_make_lnode(data_collection_model_af_event_notification_t *p_af_event_notification)
{
    return data_collection_lnode_create(p_af_event_notification, reinterpret_cast<void(*)(void*)>(data_collection_model_af_event_notification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_af_event_notification_refcount(data_collection_model_af_event_notification_t *obj_af_event_notification)
{
    if (!obj_af_event_notification) return 0l;
    std::shared_ptr<AfEventNotification > &obj = *reinterpret_cast<std::shared_ptr<AfEventNotification >*>(obj_af_event_notification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

