/**********************************************************************************************************************************
 * DataReport - C interface to the DataReport object
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

/*#include "DataReport.h" already included by data-collection-sp/data-collection.h */
#include "DataReport-internal.h"
#include "openapi/model/DataReport.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_create(









)
{
    return reinterpret_cast<data_collection_model_data_report_t*>(new std::shared_ptr<DataReport>(new DataReport(









)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_create_copy(const data_collection_model_data_report_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_report_t*>(new std::shared_ptr<DataReport >(new DataReport(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_create_move(data_collection_model_data_report_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataReport > *obj = reinterpret_cast<std::shared_ptr<DataReport >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_copy(data_collection_model_data_report_t *data_report, const data_collection_model_data_report_t *other)
{
    if (data_report) {
        std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(data_report);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataReport > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(other);
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
                const std::shared_ptr<DataReport > &other_obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(other);
                if (other_obj) {
                    obj.reset(new DataReport(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_report = data_collection_model_data_report_create_copy(other);
    }
    return data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_move(data_collection_model_data_report_t *data_report, data_collection_model_data_report_t *other)
{
    std::shared_ptr<DataReport > *other_ptr = reinterpret_cast<std::shared_ptr<DataReport >*>(other);

    if (data_report) {
        std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(data_report);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_report = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_report_free(data_collection_model_data_report_t *data_report)
{
    if (!data_report) return;
    delete reinterpret_cast<std::shared_ptr<DataReport >*>(data_report);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_report_toJSON(const data_collection_model_data_report_t *data_report, bool as_request)
{
    if (!data_report) return NULL;
    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(data_report);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_report_t*>(new std::shared_ptr<DataReport >(new DataReport(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_report_is_equal_to(const data_collection_model_data_report_t *first, const data_collection_model_data_report_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReport > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReport >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReport > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReport >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_report_get_external_application_id(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataReport::ExternalApplicationIdType ResultFromType;
    const ResultFromType result_from = obj->getExternalApplicationId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_external_application_id(data_collection_model_data_report_t *obj_data_report, const char* p_external_application_id)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_external_application_id;
    typedef typename DataReport::ExternalApplicationIdType ValueType;

    ValueType value(value_from);
    if (!obj->setExternalApplicationId(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_external_application_id_move(data_collection_model_data_report_t *obj_data_report, char* p_external_application_id)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_external_application_id;
    typedef typename DataReport::ExternalApplicationIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setExternalApplicationId(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_data_report_is_expedite(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename DataReport::ExpediteType ResultFromType;
    const ResultFromType result_from = obj->isExpedite();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_expedite(data_collection_model_data_report_t *obj_data_report, const bool p_expedite)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_expedite;
    typedef typename DataReport::ExpediteType ValueType;

    ValueType value = value_from;
    if (!obj->setExpedite(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_expedite_move(data_collection_model_data_report_t *obj_data_report, bool p_expedite)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_expedite;
    typedef typename DataReport::ExpediteType ValueType;

    ValueType value = value_from;
    
    if (!obj->setExpedite(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_service_experience_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::ServiceExperienceRecordsType ResultFromType;
    const ResultFromType result_from = obj->getServiceExperienceRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_service_experience_record_t *item_obj = reinterpret_cast<data_collection_model_service_experience_record_t*>(new std::shared_ptr<ServiceExperienceRecord >(item));
        node = data_collection_model_service_experience_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_service_experience_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_service_experience_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_service_experience_records;
    typedef typename DataReport::ServiceExperienceRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setServiceExperienceRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_service_experience_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_service_experience_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_service_experience_records;
    typedef typename DataReport::ServiceExperienceRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_service_experience_records);
    if (!obj->setServiceExperienceRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_service_experience_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_service_experience_record_t* p_service_experience_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::ServiceExperienceRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_service_experience_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addServiceExperienceRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_service_experience_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_service_experience_record_t* p_service_experience_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::ServiceExperienceRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_service_experience_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeServiceExperienceRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_service_experience_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearServiceExperienceRecords();
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_location_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::LocationRecordsType ResultFromType;
    const ResultFromType result_from = obj->getLocationRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_location_record_t *item_obj = reinterpret_cast<data_collection_model_location_record_t*>(new std::shared_ptr<LocationRecord >(item));
        node = data_collection_model_location_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_location_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_location_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_location_records;
    typedef typename DataReport::LocationRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setLocationRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_location_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_location_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_location_records;
    typedef typename DataReport::LocationRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_location_records);
    if (!obj->setLocationRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_location_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_location_record_t* p_location_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::LocationRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_location_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addLocationRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_location_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_location_record_t* p_location_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::LocationRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_location_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeLocationRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_location_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearLocationRecords();
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_communication_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::CommunicationRecordsType ResultFromType;
    const ResultFromType result_from = obj->getCommunicationRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_communication_record_t *item_obj = reinterpret_cast<data_collection_model_communication_record_t*>(new std::shared_ptr<CommunicationRecord >(item));
        node = data_collection_model_communication_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_communication_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_communication_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_communication_records;
    typedef typename DataReport::CommunicationRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setCommunicationRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_communication_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_communication_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_communication_records;
    typedef typename DataReport::CommunicationRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_communication_records);
    if (!obj->setCommunicationRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_communication_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_communication_record_t* p_communication_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::CommunicationRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_communication_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addCommunicationRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_communication_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_communication_record_t* p_communication_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::CommunicationRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_communication_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeCommunicationRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_communication_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearCommunicationRecords();
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_performance_data_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::PerformanceDataRecordsType ResultFromType;
    const ResultFromType result_from = obj->getPerformanceDataRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_performance_data_record_t *item_obj = reinterpret_cast<data_collection_model_performance_data_record_t*>(new std::shared_ptr<PerformanceDataRecord >(item));
        node = data_collection_model_performance_data_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_performance_data_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_performance_data_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_performance_data_records;
    typedef typename DataReport::PerformanceDataRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setPerformanceDataRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_performance_data_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_performance_data_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_performance_data_records;
    typedef typename DataReport::PerformanceDataRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_performance_data_records);
    if (!obj->setPerformanceDataRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_performance_data_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_performance_data_record_t* p_performance_data_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::PerformanceDataRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_performance_data_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addPerformanceDataRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_performance_data_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_performance_data_record_t* p_performance_data_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::PerformanceDataRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_performance_data_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removePerformanceDataRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_performance_data_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearPerformanceDataRecords();
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_application_specific_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::ApplicationSpecificRecordsType ResultFromType;
    const ResultFromType result_from = obj->getApplicationSpecificRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_application_specific_record_t *item_obj = reinterpret_cast<data_collection_model_application_specific_record_t*>(new std::shared_ptr<ApplicationSpecificRecord >(item));
        node = data_collection_model_application_specific_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_application_specific_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_application_specific_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_application_specific_records;
    typedef typename DataReport::ApplicationSpecificRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setApplicationSpecificRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_application_specific_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_application_specific_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_application_specific_records;
    typedef typename DataReport::ApplicationSpecificRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_application_specific_records);
    if (!obj->setApplicationSpecificRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_application_specific_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_application_specific_record_t* p_application_specific_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::ApplicationSpecificRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_application_specific_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addApplicationSpecificRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_application_specific_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_application_specific_record_t* p_application_specific_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::ApplicationSpecificRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_application_specific_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeApplicationSpecificRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_application_specific_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearApplicationSpecificRecords();
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_trip_plan_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::TripPlanRecordsType ResultFromType;
    const ResultFromType result_from = obj->getTripPlanRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_trip_plan_record_t *item_obj = reinterpret_cast<data_collection_model_trip_plan_record_t*>(new std::shared_ptr<TripPlanRecord >(item));
        node = data_collection_model_trip_plan_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_trip_plan_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_trip_plan_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_trip_plan_records;
    typedef typename DataReport::TripPlanRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setTripPlanRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_trip_plan_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_trip_plan_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_trip_plan_records;
    typedef typename DataReport::TripPlanRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_trip_plan_records);
    if (!obj->setTripPlanRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_trip_plan_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_trip_plan_record_t* p_trip_plan_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::TripPlanRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_trip_plan_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addTripPlanRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_trip_plan_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_trip_plan_record_t* p_trip_plan_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::TripPlanRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_trip_plan_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeTripPlanRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_trip_plan_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearTripPlanRecords();
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_anbr_network_assistance_invocation_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::ANBRNetworkAssistanceInvocationRecordsType ResultFromType;
    const ResultFromType result_from = obj->getANBRNetworkAssistanceInvocationRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_anbr_network_assistance_invocation_record_t *item_obj = reinterpret_cast<data_collection_model_anbr_network_assistance_invocation_record_t*>(new std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >(item));
        node = data_collection_model_anbr_network_assistance_invocation_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_anbr_network_assistance_invocation_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_anbr_network_assistance_invocation_records;
    typedef typename DataReport::ANBRNetworkAssistanceInvocationRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setANBRNetworkAssistanceInvocationRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_anbr_network_assistance_invocation_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_anbr_network_assistance_invocation_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_anbr_network_assistance_invocation_records;
    typedef typename DataReport::ANBRNetworkAssistanceInvocationRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_anbr_network_assistance_invocation_records);
    if (!obj->setANBRNetworkAssistanceInvocationRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_anbr_network_assistance_invocation_record_t* p_anbr_network_assistance_invocation_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::ANBRNetworkAssistanceInvocationRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_anbr_network_assistance_invocation_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addANBRNetworkAssistanceInvocationRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_anbr_network_assistance_invocation_record_t* p_anbr_network_assistance_invocation_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::ANBRNetworkAssistanceInvocationRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_anbr_network_assistance_invocation_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeANBRNetworkAssistanceInvocationRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearANBRNetworkAssistanceInvocationRecords();
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_report_get_media_streaming_access_records(const data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataReport > &obj = *reinterpret_cast<const std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataReport::MediaStreamingAccessRecordsType ResultFromType;
    const ResultFromType result_from = obj->getMediaStreamingAccessRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_media_streaming_access_record_t *item_obj = reinterpret_cast<data_collection_model_media_streaming_access_record_t*>(new std::shared_ptr<MediaStreamingAccessRecord >(item));
        node = data_collection_model_media_streaming_access_record_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_media_streaming_access_records(data_collection_model_data_report_t *obj_data_report, const ogs_list_t* p_media_streaming_access_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_media_streaming_access_records;
    typedef typename DataReport::MediaStreamingAccessRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setMediaStreamingAccessRecords(value)) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_set_media_streaming_access_records_move(data_collection_model_data_report_t *obj_data_report, ogs_list_t* p_media_streaming_access_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    const auto &value_from = p_media_streaming_access_records;
    typedef typename DataReport::MediaStreamingAccessRecordsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_media_streaming_access_records);
    if (!obj->setMediaStreamingAccessRecords(std::move(value))) return NULL;

    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_add_media_streaming_access_records(data_collection_model_data_report_t *obj_data_report, data_collection_model_media_streaming_access_record_t* p_media_streaming_access_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::MediaStreamingAccessRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_media_streaming_access_records;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addMediaStreamingAccessRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_remove_media_streaming_access_records(data_collection_model_data_report_t *obj_data_report, const data_collection_model_media_streaming_access_record_t* p_media_streaming_access_records)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    typedef typename DataReport::MediaStreamingAccessRecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_media_streaming_access_records;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeMediaStreamingAccessRecords(value);
    return obj_data_report;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_report_t *data_collection_model_data_report_clear_media_streaming_access_records(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return NULL;

    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    if (!obj) return NULL;

    obj->clearMediaStreamingAccessRecords();
    return obj_data_report;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_report_make_lnode(data_collection_model_data_report_t *p_data_report)
{
    return data_collection_lnode_create(p_data_report, reinterpret_cast<void(*)(void*)>(data_collection_model_data_report_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_report_refcount(data_collection_model_data_report_t *obj_data_report)
{
    if (!obj_data_report) return 0l;
    std::shared_ptr<DataReport > &obj = *reinterpret_cast<std::shared_ptr<DataReport >*>(obj_data_report);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

