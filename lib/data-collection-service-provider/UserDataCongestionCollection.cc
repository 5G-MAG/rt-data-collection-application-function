/**********************************************************************************************************************************
 * UserDataCongestionCollection - C interface to the UserDataCongestionCollection object
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

/*#include "UserDataCongestionCollection.h" already included by data-collection-sp/data-collection.h */
#include "UserDataCongestionCollection-internal.h"
#include "openapi/model/UserDataCongestionCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create(






)
{
    return reinterpret_cast<data_collection_model_user_data_congestion_collection_t*>(new std::shared_ptr<UserDataCongestionCollection>(new UserDataCongestionCollection(






)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create_copy(const data_collection_model_user_data_congestion_collection_t *other)
{
    return reinterpret_cast<data_collection_model_user_data_congestion_collection_t*>(new std::shared_ptr<UserDataCongestionCollection >(new UserDataCongestionCollection(**reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create_move(data_collection_model_user_data_congestion_collection_t *other)
{
    return reinterpret_cast<data_collection_model_user_data_congestion_collection_t*>(new std::shared_ptr<UserDataCongestionCollection >(std::move(*reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_copy(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_user_data_congestion_collection_t *other)
{
    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(user_data_congestion_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(other);
    return user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, data_collection_model_user_data_congestion_collection_t *other)
{
    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(user_data_congestion_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(other));
    return user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_user_data_congestion_collection_free(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection)
{
    delete reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(user_data_congestion_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_user_data_congestion_collection_toJSON(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, bool as_request)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(user_data_congestion_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_user_data_congestion_collection_t*>(new std::shared_ptr<UserDataCongestionCollection >(new UserDataCongestionCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_user_data_congestion_collection_get_app_id(const data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    typedef typename UserDataCongestionCollection::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_app_id(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, const char* p_app_id)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_app_id;
    typedef typename UserDataCongestionCollection::AppIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAppId(value)) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_app_id_move(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, char* p_app_id)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_app_id;
    typedef typename UserDataCongestionCollection::AppIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAppId(std::move(value))) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_flow_info_t* data_collection_model_user_data_congestion_collection_get_ip_traffic_filter(const data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    typedef typename UserDataCongestionCollection::IpTrafficFilterType ResultFromType;
    const ResultFromType result_from = obj->getIpTrafficFilter();
    const data_collection_model_flow_info_t *result = reinterpret_cast<const data_collection_model_flow_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_ip_traffic_filter(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, const data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_ip_traffic_filter;
    typedef typename UserDataCongestionCollection::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIpTrafficFilter(value)) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_ip_traffic_filter_move(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, data_collection_model_flow_info_t* p_ip_traffic_filter)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_ip_traffic_filter;
    typedef typename UserDataCongestionCollection::IpTrafficFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIpTrafficFilter(std::move(value))) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_user_data_congestion_collection_get_time_interv(const data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    typedef typename UserDataCongestionCollection::TimeIntervType ResultFromType;
    const ResultFromType result_from = obj->getTimeInterv();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_time_interv(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, const data_collection_model_time_window_t* p_time_interv)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_time_interv;
    typedef typename UserDataCongestionCollection::TimeIntervType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTimeInterv(value)) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_time_interv_move(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, data_collection_model_time_window_t* p_time_interv)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_time_interv;
    typedef typename UserDataCongestionCollection::TimeIntervType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTimeInterv(std::move(value))) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_user_data_congestion_collection_get_thrput_ul(const data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    typedef typename UserDataCongestionCollection::ThrputUlType ResultFromType;
    const ResultFromType result_from = obj->getThrputUl();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_ul(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, const char* p_thrput_ul)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_ul;
    typedef typename UserDataCongestionCollection::ThrputUlType ValueType;

    ValueType value(value_from);
    if (!obj->setThrputUl(value)) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_ul_move(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, char* p_thrput_ul)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_ul;
    typedef typename UserDataCongestionCollection::ThrputUlType ValueType;

    ValueType value(value_from);
    
    if (!obj->setThrputUl(std::move(value))) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_user_data_congestion_collection_get_thrput_dl(const data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    typedef typename UserDataCongestionCollection::ThrputDlType ResultFromType;
    const ResultFromType result_from = obj->getThrputDl();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_dl(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, const char* p_thrput_dl)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_dl;
    typedef typename UserDataCongestionCollection::ThrputDlType ValueType;

    ValueType value(value_from);
    if (!obj->setThrputDl(value)) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_dl_move(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, char* p_thrput_dl)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_dl;
    typedef typename UserDataCongestionCollection::ThrputDlType ValueType;

    ValueType value(value_from);
    
    if (!obj->setThrputDl(std::move(value))) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_user_data_congestion_collection_get_thrput_pk_ul(const data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    typedef typename UserDataCongestionCollection::ThrputPkUlType ResultFromType;
    const ResultFromType result_from = obj->getThrputPkUl();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_ul(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, const char* p_thrput_pk_ul)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_pk_ul;
    typedef typename UserDataCongestionCollection::ThrputPkUlType ValueType;

    ValueType value(value_from);
    if (!obj->setThrputPkUl(value)) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_ul_move(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, char* p_thrput_pk_ul)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_pk_ul;
    typedef typename UserDataCongestionCollection::ThrputPkUlType ValueType;

    ValueType value(value_from);
    
    if (!obj->setThrputPkUl(std::move(value))) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_user_data_congestion_collection_get_thrput_pk_dl(const data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    const std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<const std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    typedef typename UserDataCongestionCollection::ThrputPkDlType ResultFromType;
    const ResultFromType result_from = obj->getThrputPkDl();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_dl(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, const char* p_thrput_pk_dl)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_pk_dl;
    typedef typename UserDataCongestionCollection::ThrputPkDlType ValueType;

    ValueType value(value_from);
    if (!obj->setThrputPkDl(value)) return NULL;
    return obj_user_data_congestion_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_dl_move(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection, char* p_thrput_pk_dl)
{
    if (obj_user_data_congestion_collection == NULL) return NULL;

    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    const auto &value_from = p_thrput_pk_dl;
    typedef typename UserDataCongestionCollection::ThrputPkDlType ValueType;

    ValueType value(value_from);
    
    if (!obj->setThrputPkDl(std::move(value))) return NULL;
    return obj_user_data_congestion_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_user_data_congestion_collection_make_lnode(data_collection_model_user_data_congestion_collection_t *p_user_data_congestion_collection)
{
    return data_collection_lnode_create(p_user_data_congestion_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_user_data_congestion_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_user_data_congestion_collection_refcount(data_collection_model_user_data_congestion_collection_t *obj_user_data_congestion_collection)
{
    std::shared_ptr<UserDataCongestionCollection > &obj = *reinterpret_cast<std::shared_ptr<UserDataCongestionCollection >*>(obj_user_data_congestion_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

