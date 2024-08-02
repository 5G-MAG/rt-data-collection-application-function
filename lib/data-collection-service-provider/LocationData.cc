/**********************************************************************************************************************************
 * LocationData - C interface to the LocationData object
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

/*#include "LocationData.h" already included by data-collection-sp/data-collection.h */
#include "LocationData-internal.h"
#include "openapi/model/LocationData.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_create(






























)
{
    return reinterpret_cast<data_collection_model_location_data_t*>(new std::shared_ptr<LocationData>(new LocationData(






























)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_create_copy(const data_collection_model_location_data_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_location_data_t*>(new std::shared_ptr<LocationData >(new LocationData(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_create_move(data_collection_model_location_data_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<LocationData > *obj = reinterpret_cast<std::shared_ptr<LocationData >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_copy(data_collection_model_location_data_t *location_data, const data_collection_model_location_data_t *other)
{
    if (location_data) {
        std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(location_data);
        if (obj) {
            if (other) {
                const std::shared_ptr<LocationData > &other_obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(other);
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
                const std::shared_ptr<LocationData > &other_obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(other);
                if (other_obj) {
                    obj.reset(new LocationData(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        location_data = data_collection_model_location_data_create_copy(other);
    }
    return location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_move(data_collection_model_location_data_t *location_data, data_collection_model_location_data_t *other)
{
    std::shared_ptr<LocationData > *other_ptr = reinterpret_cast<std::shared_ptr<LocationData >*>(other);

    if (location_data) {
        std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(location_data);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                location_data = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_location_data_free(data_collection_model_location_data_t *location_data)
{
    if (!location_data) return;
    delete reinterpret_cast<std::shared_ptr<LocationData >*>(location_data);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_location_data_toJSON(const data_collection_model_location_data_t *location_data, bool as_request)
{
    if (!location_data) return NULL;
    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(location_data);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_location_data_t*>(new std::shared_ptr<LocationData >(new LocationData(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_location_data_is_equal_to(const data_collection_model_location_data_t *first, const data_collection_model_location_data_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<LocationData > &obj2 = *reinterpret_cast<const std::shared_ptr<LocationData >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<LocationData > &obj1 = *reinterpret_cast<const std::shared_ptr<LocationData >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographic_area_t* data_collection_model_location_data_get_location_estimate(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_geographic_area_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_geographic_area_t *result = NULL;
        return result;
    }

    typedef typename LocationData::LocationEstimateType ResultFromType;
    const ResultFromType result_from = obj->getLocationEstimate();
    const data_collection_model_geographic_area_t *result = reinterpret_cast<const data_collection_model_geographic_area_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_location_estimate(data_collection_model_location_data_t *obj_location_data, const data_collection_model_geographic_area_t* p_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_location_estimate;
    typedef typename LocationData::LocationEstimateType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocationEstimate(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_location_estimate_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_geographic_area_t* p_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_location_estimate;
    typedef typename LocationData::LocationEstimateType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocationEstimate(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_accuracy_fulfilment_indicator_t* data_collection_model_location_data_get_accuracy_fulfilment_indicator(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_accuracy_fulfilment_indicator_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_accuracy_fulfilment_indicator_t *result = NULL;
        return result;
    }

    typedef typename LocationData::AccuracyFulfilmentIndicatorType ResultFromType;
    const ResultFromType result_from = obj->getAccuracyFulfilmentIndicator();
    const data_collection_model_accuracy_fulfilment_indicator_t *result = reinterpret_cast<const data_collection_model_accuracy_fulfilment_indicator_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_accuracy_fulfilment_indicator(data_collection_model_location_data_t *obj_location_data, const data_collection_model_accuracy_fulfilment_indicator_t* p_accuracy_fulfilment_indicator)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_accuracy_fulfilment_indicator;
    typedef typename LocationData::AccuracyFulfilmentIndicatorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setAccuracyFulfilmentIndicator(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_accuracy_fulfilment_indicator_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_accuracy_fulfilment_indicator_t* p_accuracy_fulfilment_indicator)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_accuracy_fulfilment_indicator;
    typedef typename LocationData::AccuracyFulfilmentIndicatorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setAccuracyFulfilmentIndicator(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_location_data_get_age_of_location_estimate(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename LocationData::AgeOfLocationEstimateType ResultFromType;
    const ResultFromType result_from = obj->getAgeOfLocationEstimate();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_age_of_location_estimate(data_collection_model_location_data_t *obj_location_data, const int32_t p_age_of_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_age_of_location_estimate;
    typedef typename LocationData::AgeOfLocationEstimateType ValueType;

    ValueType value = value_from;
    if (!obj->setAgeOfLocationEstimate(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_age_of_location_estimate_move(data_collection_model_location_data_t *obj_location_data, int32_t p_age_of_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_age_of_location_estimate;
    typedef typename LocationData::AgeOfLocationEstimateType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAgeOfLocationEstimate(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_location_data_get_timestamp_of_location_estimate(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename LocationData::TimestampOfLocationEstimateType ResultFromType;
    const ResultFromType result_from = obj->getTimestampOfLocationEstimate();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_timestamp_of_location_estimate(data_collection_model_location_data_t *obj_location_data, const char* p_timestamp_of_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp_of_location_estimate;
    typedef typename LocationData::TimestampOfLocationEstimateType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestampOfLocationEstimate(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_timestamp_of_location_estimate_move(data_collection_model_location_data_t *obj_location_data, char* p_timestamp_of_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp_of_location_estimate;
    typedef typename LocationData::TimestampOfLocationEstimateType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestampOfLocationEstimate(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_velocity_estimate_t* data_collection_model_location_data_get_velocity_estimate(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_velocity_estimate_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_velocity_estimate_t *result = NULL;
        return result;
    }

    typedef typename LocationData::VelocityEstimateType ResultFromType;
    const ResultFromType result_from = obj->getVelocityEstimate();
    const data_collection_model_velocity_estimate_t *result = reinterpret_cast<const data_collection_model_velocity_estimate_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_velocity_estimate(data_collection_model_location_data_t *obj_location_data, const data_collection_model_velocity_estimate_t* p_velocity_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_velocity_estimate;
    typedef typename LocationData::VelocityEstimateType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setVelocityEstimate(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_velocity_estimate_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_velocity_estimate_t* p_velocity_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_velocity_estimate;
    typedef typename LocationData::VelocityEstimateType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setVelocityEstimate(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_civic_address_t* data_collection_model_location_data_get_civic_address(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_civic_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_civic_address_t *result = NULL;
        return result;
    }

    typedef typename LocationData::CivicAddressType ResultFromType;
    const ResultFromType result_from = obj->getCivicAddress();
    const data_collection_model_civic_address_t *result = reinterpret_cast<const data_collection_model_civic_address_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_civic_address(data_collection_model_location_data_t *obj_location_data, const data_collection_model_civic_address_t* p_civic_address)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_civic_address;
    typedef typename LocationData::CivicAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setCivicAddress(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_civic_address_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_civic_address_t* p_civic_address)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_civic_address;
    typedef typename LocationData::CivicAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setCivicAddress(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_local_area_t* data_collection_model_location_data_get_local_location_estimate(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_local_area_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_local_area_t *result = NULL;
        return result;
    }

    typedef typename LocationData::LocalLocationEstimateType ResultFromType;
    const ResultFromType result_from = obj->getLocalLocationEstimate();
    const data_collection_model_local_area_t *result = reinterpret_cast<const data_collection_model_local_area_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_local_location_estimate(data_collection_model_location_data_t *obj_location_data, const data_collection_model_local_area_t* p_local_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_local_location_estimate;
    typedef typename LocationData::LocalLocationEstimateType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocalLocationEstimate(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_local_location_estimate_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_local_area_t* p_local_location_estimate)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_local_location_estimate;
    typedef typename LocationData::LocalLocationEstimateType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocalLocationEstimate(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_location_data_get_positioning_data_list(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename LocationData::PositioningDataListType ResultFromType;
    const ResultFromType result_from = obj->getPositioningDataList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_positioning_method_and_usage_t *item_obj = reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage >(item));
        node = data_collection_model_positioning_method_and_usage_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_positioning_data_list(data_collection_model_location_data_t *obj_location_data, const ogs_list_t* p_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_positioning_data_list;
    typedef typename LocationData::PositioningDataListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setPositioningDataList(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_positioning_data_list_move(data_collection_model_location_data_t *obj_location_data, ogs_list_t* p_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_positioning_data_list;
    typedef typename LocationData::PositioningDataListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_positioning_data_list);
    if (!obj->setPositioningDataList(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_add_positioning_data_list(data_collection_model_location_data_t *obj_location_data, data_collection_model_positioning_method_and_usage_t* p_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    typedef typename LocationData::PositioningDataListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_positioning_data_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addPositioningDataList(value);
    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_remove_positioning_data_list(data_collection_model_location_data_t *obj_location_data, const data_collection_model_positioning_method_and_usage_t* p_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    typedef typename LocationData::PositioningDataListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_positioning_data_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removePositioningDataList(value);
    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_clear_positioning_data_list(data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    obj->clearPositioningDataList();
    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_location_data_get_gnss_positioning_data_list(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename LocationData::GnssPositioningDataListType ResultFromType;
    const ResultFromType result_from = obj->getGnssPositioningDataList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_gnss_positioning_method_and_usage_t *item_obj = reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage >(item));
        node = data_collection_model_gnss_positioning_method_and_usage_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_gnss_positioning_data_list(data_collection_model_location_data_t *obj_location_data, const ogs_list_t* p_gnss_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_gnss_positioning_data_list;
    typedef typename LocationData::GnssPositioningDataListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setGnssPositioningDataList(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_gnss_positioning_data_list_move(data_collection_model_location_data_t *obj_location_data, ogs_list_t* p_gnss_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_gnss_positioning_data_list;
    typedef typename LocationData::GnssPositioningDataListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_gnss_positioning_data_list);
    if (!obj->setGnssPositioningDataList(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_add_gnss_positioning_data_list(data_collection_model_location_data_t *obj_location_data, data_collection_model_gnss_positioning_method_and_usage_t* p_gnss_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    typedef typename LocationData::GnssPositioningDataListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_gnss_positioning_data_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addGnssPositioningDataList(value);
    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_remove_gnss_positioning_data_list(data_collection_model_location_data_t *obj_location_data, const data_collection_model_gnss_positioning_method_and_usage_t* p_gnss_positioning_data_list)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    typedef typename LocationData::GnssPositioningDataListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_gnss_positioning_data_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeGnssPositioningDataList(value);
    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_clear_gnss_positioning_data_list(data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    obj->clearGnssPositioningDataList();
    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ecgi_t* data_collection_model_location_data_get_ecgi(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_ecgi_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_ecgi_t *result = NULL;
        return result;
    }

    typedef typename LocationData::EcgiType ResultFromType;
    const ResultFromType result_from = obj->getEcgi();
    const data_collection_model_ecgi_t *result = reinterpret_cast<const data_collection_model_ecgi_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ecgi(data_collection_model_location_data_t *obj_location_data, const data_collection_model_ecgi_t* p_ecgi)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ecgi;
    typedef typename LocationData::EcgiType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setEcgi(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ecgi_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_ecgi_t* p_ecgi)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ecgi;
    typedef typename LocationData::EcgiType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setEcgi(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ncgi_t* data_collection_model_location_data_get_ncgi(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_ncgi_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_ncgi_t *result = NULL;
        return result;
    }

    typedef typename LocationData::NcgiType ResultFromType;
    const ResultFromType result_from = obj->getNcgi();
    const data_collection_model_ncgi_t *result = reinterpret_cast<const data_collection_model_ncgi_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ncgi(data_collection_model_location_data_t *obj_location_data, const data_collection_model_ncgi_t* p_ncgi)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ncgi;
    typedef typename LocationData::NcgiType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNcgi(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ncgi_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_ncgi_t* p_ncgi)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ncgi;
    typedef typename LocationData::NcgiType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNcgi(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_location_data_is_remote_ue_ind(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename LocationData::RemoteUeIndType ResultFromType;
    const ResultFromType result_from = obj->isRemoteUeInd();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_remote_ue_ind(data_collection_model_location_data_t *obj_location_data, const bool p_remote_ue_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_remote_ue_ind;
    typedef typename LocationData::RemoteUeIndType ValueType;

    ValueType value = value_from;
    if (!obj->setRemoteUeInd(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_remote_ue_ind_move(data_collection_model_location_data_t *obj_location_data, bool p_remote_ue_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_remote_ue_ind;
    typedef typename LocationData::RemoteUeIndType ValueType;

    ValueType value = value_from;
    
    if (!obj->setRemoteUeInd(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const double data_collection_model_location_data_get_altitude(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename LocationData::AltitudeType ResultFromType;
    const ResultFromType result_from = obj->getAltitude();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_altitude(data_collection_model_location_data_t *obj_location_data, const double p_altitude)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename LocationData::AltitudeType ValueType;

    ValueType value = value_from;
    if (!obj->setAltitude(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_altitude_move(data_collection_model_location_data_t *obj_location_data, double p_altitude)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_altitude;
    typedef typename LocationData::AltitudeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setAltitude(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_location_data_get_barometric_pressure(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename LocationData::BarometricPressureType ResultFromType;
    const ResultFromType result_from = obj->getBarometricPressure();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_barometric_pressure(data_collection_model_location_data_t *obj_location_data, const int32_t p_barometric_pressure)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_barometric_pressure;
    typedef typename LocationData::BarometricPressureType ValueType;

    ValueType value = value_from;
    if (!obj->setBarometricPressure(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_barometric_pressure_move(data_collection_model_location_data_t *obj_location_data, int32_t p_barometric_pressure)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_barometric_pressure;
    typedef typename LocationData::BarometricPressureType ValueType;

    ValueType value = value_from;
    
    if (!obj->setBarometricPressure(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_location_data_get_serving_lmf_identification(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename LocationData::ServingLMFIdentificationType ResultFromType;
    const ResultFromType result_from = obj->getServingLMFIdentification();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_serving_lmf_identification(data_collection_model_location_data_t *obj_location_data, const char* p_serving_lmf_identification)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_serving_lmf_identification;
    typedef typename LocationData::ServingLMFIdentificationType ValueType;

    ValueType value(value_from);
    if (!obj->setServingLMFIdentification(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_serving_lmf_identification_move(data_collection_model_location_data_t *obj_location_data, char* p_serving_lmf_identification)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_serving_lmf_identification;
    typedef typename LocationData::ServingLMFIdentificationType ValueType;

    ValueType value(value_from);
    
    if (!obj->setServingLMFIdentification(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const unsigned char* data_collection_model_location_data_get_ue_positioning_cap(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const unsigned char *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const unsigned char *result = NULL;
        return result;
    }

    typedef typename LocationData::UePositioningCapType ResultFromType;
    const ResultFromType result_from = obj->getUePositioningCap();
    const unsigned char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ue_positioning_cap(data_collection_model_location_data_t *obj_location_data, const unsigned char* p_ue_positioning_cap)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ue_positioning_cap;
    typedef typename LocationData::UePositioningCapType ValueType;

    ValueType value(value_from);
    if (!obj->setUePositioningCap(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ue_positioning_cap_move(data_collection_model_location_data_t *obj_location_data, unsigned char* p_ue_positioning_cap)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ue_positioning_cap;
    typedef typename LocationData::UePositioningCapType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUePositioningCap(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ue_area_indication_t* data_collection_model_location_data_get_ue_area_ind(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_ue_area_indication_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_ue_area_indication_t *result = NULL;
        return result;
    }

    typedef typename LocationData::UeAreaIndType ResultFromType;
    const ResultFromType result_from = obj->getUeAreaInd();
    const data_collection_model_ue_area_indication_t *result = reinterpret_cast<const data_collection_model_ue_area_indication_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ue_area_ind(data_collection_model_location_data_t *obj_location_data, const data_collection_model_ue_area_indication_t* p_ue_area_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ue_area_ind;
    typedef typename LocationData::UeAreaIndType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUeAreaInd(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ue_area_ind_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_ue_area_indication_t* p_ue_area_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ue_area_ind;
    typedef typename LocationData::UeAreaIndType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUeAreaInd(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_location_data_get_supported_features(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename LocationData::SupportedFeaturesType ResultFromType;
    const ResultFromType result_from = obj->getSupportedFeatures();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_supported_features(data_collection_model_location_data_t *obj_location_data, const char* p_supported_features)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_supported_features;
    typedef typename LocationData::SupportedFeaturesType ValueType;

    ValueType value(value_from);
    if (!obj->setSupportedFeatures(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_supported_features_move(data_collection_model_location_data_t *obj_location_data, char* p_supported_features)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_supported_features;
    typedef typename LocationData::SupportedFeaturesType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSupportedFeatures(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_minor_location_qo_s_t* data_collection_model_location_data_get_achieved_qos(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_minor_location_qo_s_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_minor_location_qo_s_t *result = NULL;
        return result;
    }

    typedef typename LocationData::AchievedQosType ResultFromType;
    const ResultFromType result_from = obj->getAchievedQos();
    const data_collection_model_minor_location_qo_s_t *result = reinterpret_cast<const data_collection_model_minor_location_qo_s_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_achieved_qos(data_collection_model_location_data_t *obj_location_data, const data_collection_model_minor_location_qo_s_t* p_achieved_qos)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_achieved_qos;
    typedef typename LocationData::AchievedQosType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setAchievedQos(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_achieved_qos_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_minor_location_qo_s_t* p_achieved_qos)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_achieved_qos;
    typedef typename LocationData::AchievedQosType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setAchievedQos(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_location_data_is_direct_report_ind(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename LocationData::DirectReportIndType ResultFromType;
    const ResultFromType result_from = obj->isDirectReportInd();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_direct_report_ind(data_collection_model_location_data_t *obj_location_data, const bool p_direct_report_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_direct_report_ind;
    typedef typename LocationData::DirectReportIndType ValueType;

    ValueType value = value_from;
    if (!obj->setDirectReportInd(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_direct_report_ind_move(data_collection_model_location_data_t *obj_location_data, bool p_direct_report_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_direct_report_ind;
    typedef typename LocationData::DirectReportIndType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDirectReportInd(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_indoor_outdoor_ind_t* data_collection_model_location_data_get_indoor_outdoor_ind(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_indoor_outdoor_ind_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_indoor_outdoor_ind_t *result = NULL;
        return result;
    }

    typedef typename LocationData::IndoorOutdoorIndType ResultFromType;
    const ResultFromType result_from = obj->getIndoorOutdoorInd();
    const data_collection_model_indoor_outdoor_ind_t *result = reinterpret_cast<const data_collection_model_indoor_outdoor_ind_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_indoor_outdoor_ind(data_collection_model_location_data_t *obj_location_data, const data_collection_model_indoor_outdoor_ind_t* p_indoor_outdoor_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_indoor_outdoor_ind;
    typedef typename LocationData::IndoorOutdoorIndType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIndoorOutdoorInd(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_indoor_outdoor_ind_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_indoor_outdoor_ind_t* p_indoor_outdoor_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_indoor_outdoor_ind;
    typedef typename LocationData::IndoorOutdoorIndType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIndoorOutdoorInd(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_periodic_event_info_t* data_collection_model_location_data_get_accepted_periodic_event_info(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_periodic_event_info_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_periodic_event_info_t *result = NULL;
        return result;
    }

    typedef typename LocationData::AcceptedPeriodicEventInfoType ResultFromType;
    const ResultFromType result_from = obj->getAcceptedPeriodicEventInfo();
    const data_collection_model_periodic_event_info_t *result = reinterpret_cast<const data_collection_model_periodic_event_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_accepted_periodic_event_info(data_collection_model_location_data_t *obj_location_data, const data_collection_model_periodic_event_info_t* p_accepted_periodic_event_info)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_accepted_periodic_event_info;
    typedef typename LocationData::AcceptedPeriodicEventInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setAcceptedPeriodicEventInfo(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_accepted_periodic_event_info_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_periodic_event_info_t* p_accepted_periodic_event_info)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_accepted_periodic_event_info;
    typedef typename LocationData::AcceptedPeriodicEventInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setAcceptedPeriodicEventInfo(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_high_accuracy_gnss_metrics_t* data_collection_model_location_data_get_ha_gnss_metrics(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_high_accuracy_gnss_metrics_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_high_accuracy_gnss_metrics_t *result = NULL;
        return result;
    }

    typedef typename LocationData::HaGnssMetricsType ResultFromType;
    const ResultFromType result_from = obj->getHaGnssMetrics();
    const data_collection_model_high_accuracy_gnss_metrics_t *result = reinterpret_cast<const data_collection_model_high_accuracy_gnss_metrics_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ha_gnss_metrics(data_collection_model_location_data_t *obj_location_data, const data_collection_model_high_accuracy_gnss_metrics_t* p_ha_gnss_metrics)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ha_gnss_metrics;
    typedef typename LocationData::HaGnssMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setHaGnssMetrics(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ha_gnss_metrics_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_high_accuracy_gnss_metrics_t* p_ha_gnss_metrics)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ha_gnss_metrics;
    typedef typename LocationData::HaGnssMetricsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setHaGnssMetrics(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_los_nlos_measure_ind_t* data_collection_model_location_data_get_los_nlos_measure_ind(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_los_nlos_measure_ind_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_los_nlos_measure_ind_t *result = NULL;
        return result;
    }

    typedef typename LocationData::LosNlosMeasureIndType ResultFromType;
    const ResultFromType result_from = obj->getLosNlosMeasureInd();
    const data_collection_model_los_nlos_measure_ind_t *result = reinterpret_cast<const data_collection_model_los_nlos_measure_ind_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_los_nlos_measure_ind(data_collection_model_location_data_t *obj_location_data, const data_collection_model_los_nlos_measure_ind_t* p_los_nlos_measure_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_los_nlos_measure_ind;
    typedef typename LocationData::LosNlosMeasureIndType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLosNlosMeasureInd(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_los_nlos_measure_ind_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_los_nlos_measure_ind_t* p_los_nlos_measure_ind)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_los_nlos_measure_ind;
    typedef typename LocationData::LosNlosMeasureIndType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLosNlosMeasureInd(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_location_data_get_related_applicationlayer_id(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename LocationData::RelatedApplicationlayerIdType ResultFromType;
    const ResultFromType result_from = obj->getRelatedApplicationlayerId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_related_applicationlayer_id(data_collection_model_location_data_t *obj_location_data, const char* p_related_applicationlayer_id)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_related_applicationlayer_id;
    typedef typename LocationData::RelatedApplicationlayerIdType ValueType;

    ValueType value(value_from);
    if (!obj->setRelatedApplicationlayerId(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_related_applicationlayer_id_move(data_collection_model_location_data_t *obj_location_data, char* p_related_applicationlayer_id)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_related_applicationlayer_id;
    typedef typename LocationData::RelatedApplicationlayerIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRelatedApplicationlayerId(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_range_direction_t* data_collection_model_location_data_get_distance_direction(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_range_direction_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_range_direction_t *result = NULL;
        return result;
    }

    typedef typename LocationData::DistanceDirectionType ResultFromType;
    const ResultFromType result_from = obj->getDistanceDirection();
    const data_collection_model_range_direction_t *result = reinterpret_cast<const data_collection_model_range_direction_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_distance_direction(data_collection_model_location_data_t *obj_location_data, const data_collection_model_range_direction_t* p_distance_direction)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_distance_direction;
    typedef typename LocationData::DistanceDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDistanceDirection(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_distance_direction_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_range_direction_t* p_distance_direction)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_distance_direction;
    typedef typename LocationData::DistanceDirectionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDistanceDirection(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_r_2_d_relative_location_t* data_collection_model_location_data_get_r2d_relative_location(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_r_2_d_relative_location_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_r_2_d_relative_location_t *result = NULL;
        return result;
    }

    typedef typename LocationData::r_2dRelativeLocationType ResultFromType;
    const ResultFromType result_from = obj->getR2dRelativeLocation();
    const data_collection_model_r_2_d_relative_location_t *result = reinterpret_cast<const data_collection_model_r_2_d_relative_location_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_r2d_relative_location(data_collection_model_location_data_t *obj_location_data, const data_collection_model_r_2_d_relative_location_t* p_r_2d_relative_location)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_r_2d_relative_location;
    typedef typename LocationData::r_2dRelativeLocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setR2dRelativeLocation(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_r2d_relative_location_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_r_2_d_relative_location_t* p_r_2d_relative_location)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_r_2d_relative_location;
    typedef typename LocationData::r_2dRelativeLocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setR2dRelativeLocation(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_r_3_d_relative_location_t* data_collection_model_location_data_get_r3d_relative_location(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_r_3_d_relative_location_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_r_3_d_relative_location_t *result = NULL;
        return result;
    }

    typedef typename LocationData::r_3dRelativeLocationType ResultFromType;
    const ResultFromType result_from = obj->getR3dRelativeLocation();
    const data_collection_model_r_3_d_relative_location_t *result = reinterpret_cast<const data_collection_model_r_3_d_relative_location_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_r3d_relative_location(data_collection_model_location_data_t *obj_location_data, const data_collection_model_r_3_d_relative_location_t* p_r_3d_relative_location)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_r_3d_relative_location;
    typedef typename LocationData::r_3dRelativeLocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setR3dRelativeLocation(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_r3d_relative_location_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_r_3_d_relative_location_t* p_r_3d_relative_location)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_r_3d_relative_location;
    typedef typename LocationData::r_3dRelativeLocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setR3dRelativeLocation(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_velocity_estimate_t* data_collection_model_location_data_get_relative_velocity(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_velocity_estimate_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_velocity_estimate_t *result = NULL;
        return result;
    }

    typedef typename LocationData::RelativeVelocityType ResultFromType;
    const ResultFromType result_from = obj->getRelativeVelocity();
    const data_collection_model_velocity_estimate_t *result = reinterpret_cast<const data_collection_model_velocity_estimate_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_relative_velocity(data_collection_model_location_data_t *obj_location_data, const data_collection_model_velocity_estimate_t* p_relative_velocity)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_relative_velocity;
    typedef typename LocationData::RelativeVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRelativeVelocity(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_relative_velocity_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_velocity_estimate_t* p_relative_velocity)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_relative_velocity;
    typedef typename LocationData::RelativeVelocityType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRelativeVelocity(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const unsigned char* data_collection_model_location_data_get_ranging_sl_capability(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const unsigned char *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const unsigned char *result = NULL;
        return result;
    }

    typedef typename LocationData::RangingSlCapabilityType ResultFromType;
    const ResultFromType result_from = obj->getRangingSlCapability();
    const unsigned char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ranging_sl_capability(data_collection_model_location_data_t *obj_location_data, const unsigned char* p_ranging_sl_capability)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ranging_sl_capability;
    typedef typename LocationData::RangingSlCapabilityType ValueType;

    ValueType value(value_from);
    if (!obj->setRangingSlCapability(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_ranging_sl_capability_move(data_collection_model_location_data_t *obj_location_data, unsigned char* p_ranging_sl_capability)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_ranging_sl_capability;
    typedef typename LocationData::RangingSlCapabilityType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRangingSlCapability(std::move(value))) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_integrity_result_t* data_collection_model_location_data_get_integrity_result(const data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) {
        const data_collection_model_integrity_result_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocationData > &obj = *reinterpret_cast<const std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) {
        const data_collection_model_integrity_result_t *result = NULL;
        return result;
    }

    typedef typename LocationData::IntegrityResultType ResultFromType;
    const ResultFromType result_from = obj->getIntegrityResult();
    const data_collection_model_integrity_result_t *result = reinterpret_cast<const data_collection_model_integrity_result_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_integrity_result(data_collection_model_location_data_t *obj_location_data, const data_collection_model_integrity_result_t* p_integrity_result)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_integrity_result;
    typedef typename LocationData::IntegrityResultType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIntegrityResult(value)) return NULL;

    return obj_location_data;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_data_t *data_collection_model_location_data_set_integrity_result_move(data_collection_model_location_data_t *obj_location_data, data_collection_model_integrity_result_t* p_integrity_result)
{
    if (!obj_location_data) return NULL;

    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    if (!obj) return NULL;

    const auto &value_from = p_integrity_result;
    typedef typename LocationData::IntegrityResultType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIntegrityResult(std::move(value))) return NULL;

    return obj_location_data;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_location_data_make_lnode(data_collection_model_location_data_t *p_location_data)
{
    return data_collection_lnode_create(p_location_data, reinterpret_cast<void(*)(void*)>(data_collection_model_location_data_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_location_data_refcount(data_collection_model_location_data_t *obj_location_data)
{
    if (!obj_location_data) return 0l;
    std::shared_ptr<LocationData > &obj = *reinterpret_cast<std::shared_ptr<LocationData >*>(obj_location_data);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

