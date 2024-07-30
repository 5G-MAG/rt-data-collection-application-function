/**********************************************************************************************************************************
 * CommunicationRecord_allOf - C interface to the CommunicationRecord_allOf object
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

/*#include "CommunicationRecord_allOf.h" already included by data-collection-sp/data-collection.h */
#include "CommunicationRecord_allOf-internal.h"
#include "openapi/model/CommunicationRecord_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create(





)
{
    return reinterpret_cast<data_collection_model_communication_record_all_of_t*>(new std::shared_ptr<CommunicationRecord_allOf>(new CommunicationRecord_allOf(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create_copy(const data_collection_model_communication_record_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_communication_record_all_of_t*>(new std::shared_ptr<CommunicationRecord_allOf >(new CommunicationRecord_allOf(**reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_create_move(data_collection_model_communication_record_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_communication_record_all_of_t*>(new std::shared_ptr<CommunicationRecord_allOf >(std::move(*reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_copy(data_collection_model_communication_record_all_of_t *communication_record_all_of, const data_collection_model_communication_record_all_of_t *other)
{
    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(communication_record_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(other);
    return communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_move(data_collection_model_communication_record_all_of_t *communication_record_all_of, data_collection_model_communication_record_all_of_t *other)
{
    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(communication_record_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(other));
    return communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_communication_record_all_of_free(data_collection_model_communication_record_all_of_t *communication_record_all_of)
{
    delete reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(communication_record_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_communication_record_all_of_toJSON(const data_collection_model_communication_record_all_of_t *communication_record_all_of, bool as_request)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(communication_record_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_communication_record_all_of_t*>(new std::shared_ptr<CommunicationRecord_allOf >(new CommunicationRecord_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_communication_record_all_of_is_equal_to(const data_collection_model_communication_record_all_of_t *first, const data_collection_model_communication_record_all_of_t *second)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(first);
    const std::shared_ptr<CommunicationRecord_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_communication_record_all_of_get_time_interval(const data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::TimeIntervalType ResultFromType;
    const ResultFromType result_from = obj->getTimeInterval();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_time_interval(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, const data_collection_model_time_window_t* p_time_interval)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_time_interval;
    typedef typename CommunicationRecord_allOf::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTimeInterval(value)) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_time_interval_move(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, data_collection_model_time_window_t* p_time_interval)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_time_interval;
    typedef typename CommunicationRecord_allOf::TimeIntervalType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTimeInterval(std::move(value))) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_snssai_t* data_collection_model_communication_record_all_of_get_slice_info(const data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::SliceInfoType ResultFromType;
    const ResultFromType result_from = obj->getSliceInfo();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_slice_info(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, const data_collection_model_snssai_t* p_slice_info)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_slice_info;
    typedef typename CommunicationRecord_allOf::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSliceInfo(value)) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_slice_info_move(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, data_collection_model_snssai_t* p_slice_info)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_slice_info;
    typedef typename CommunicationRecord_allOf::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSliceInfo(std::move(value))) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_communication_record_all_of_get_data_network_name(const data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::DataNetworkNameType ResultFromType;
    const ResultFromType result_from = obj->getDataNetworkName();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_data_network_name(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, const char* p_data_network_name)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_data_network_name;
    typedef typename CommunicationRecord_allOf::DataNetworkNameType ValueType;

    ValueType value(value_from);
    if (!obj->setDataNetworkName(value)) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_data_network_name_move(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, char* p_data_network_name)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_data_network_name;
    typedef typename CommunicationRecord_allOf::DataNetworkNameType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_communication_record_all_of_get_location(const data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_location_area5_g_t*>(new std::shared_ptr<LocationArea5G >(item));
        node = data_collection_model_location_area5_g_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_location(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, const ogs_list_t* p_location)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_location;
    typedef typename CommunicationRecord_allOf::LocationType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setLocation(value)) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_location_move(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, ogs_list_t* p_location)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_location;
    typedef typename CommunicationRecord_allOf::LocationType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_location);
    if (!obj->setLocation(std::move(value))) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_add_location(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, data_collection_model_location_area5_g_t* p_location)
{
    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::LocationType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_location;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addLocation(value);
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_remove_location(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, const data_collection_model_location_area5_g_t* p_location)
{
    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::LocationType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_location;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeLocation(value);
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_clear_location(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{   
    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    obj->clearLocation();
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_communication_record_all_of_get_uplink_volume(const data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::UplinkVolumeType ResultFromType;
    const ResultFromType result_from = obj->getUplinkVolume();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_uplink_volume(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, const int64_t p_uplink_volume)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_uplink_volume;
    typedef typename CommunicationRecord_allOf::UplinkVolumeType ValueType;

    ValueType value = value_from;
    if (!obj->setUplinkVolume(value)) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_uplink_volume_move(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, int64_t p_uplink_volume)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_uplink_volume;
    typedef typename CommunicationRecord_allOf::UplinkVolumeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUplinkVolume(std::move(value))) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_communication_record_all_of_get_downlink_volume(const data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{
    const std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    typedef typename CommunicationRecord_allOf::DownlinkVolumeType ResultFromType;
    const ResultFromType result_from = obj->getDownlinkVolume();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_downlink_volume(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, const int64_t p_downlink_volume)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_downlink_volume;
    typedef typename CommunicationRecord_allOf::DownlinkVolumeType ValueType;

    ValueType value = value_from;
    if (!obj->setDownlinkVolume(value)) return NULL;
    return obj_communication_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_record_all_of_t *data_collection_model_communication_record_all_of_set_downlink_volume_move(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of, int64_t p_downlink_volume)
{
    if (obj_communication_record_all_of == NULL) return NULL;

    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    const auto &value_from = p_downlink_volume;
    typedef typename CommunicationRecord_allOf::DownlinkVolumeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDownlinkVolume(std::move(value))) return NULL;
    return obj_communication_record_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_communication_record_all_of_make_lnode(data_collection_model_communication_record_all_of_t *p_communication_record_all_of)
{
    return data_collection_lnode_create(p_communication_record_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_communication_record_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_communication_record_all_of_refcount(data_collection_model_communication_record_all_of_t *obj_communication_record_all_of)
{
    std::shared_ptr<CommunicationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<CommunicationRecord_allOf >*>(obj_communication_record_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

