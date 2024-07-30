/**********************************************************************************************************************************
 * ReportingInformation - C interface to the ReportingInformation object
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

/*#include "ReportingInformation.h" already included by data-collection-sp/data-collection.h */
#include "ReportingInformation-internal.h"
#include "openapi/model/ReportingInformation.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_create(










)
{
    return reinterpret_cast<data_collection_model_reporting_information_t*>(new std::shared_ptr<ReportingInformation>(new ReportingInformation(










)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_create_copy(const data_collection_model_reporting_information_t *other)
{
    return reinterpret_cast<data_collection_model_reporting_information_t*>(new std::shared_ptr<ReportingInformation >(new ReportingInformation(**reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_create_move(data_collection_model_reporting_information_t *other)
{
    return reinterpret_cast<data_collection_model_reporting_information_t*>(new std::shared_ptr<ReportingInformation >(std::move(*reinterpret_cast<std::shared_ptr<ReportingInformation >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_copy(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_reporting_information_t *other)
{
    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(reporting_information);
    *obj = **reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(other);
    return reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_reporting_information_t *other)
{
    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(reporting_information);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ReportingInformation >*>(other));
    return reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_reporting_information_free(data_collection_model_reporting_information_t *reporting_information)
{
    delete reinterpret_cast<std::shared_ptr<ReportingInformation >*>(reporting_information);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_reporting_information_toJSON(const data_collection_model_reporting_information_t *reporting_information, bool as_request)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(reporting_information);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_reporting_information_t*>(new std::shared_ptr<ReportingInformation >(new ReportingInformation(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_reporting_information_is_equal_to(const data_collection_model_reporting_information_t *first, const data_collection_model_reporting_information_t *second)
{
    const std::shared_ptr<ReportingInformation > &obj1 = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(first);
    const std::shared_ptr<ReportingInformation > &obj2 = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_reporting_information_is_imm_rep(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::ImmRepType ResultFromType;
    const ResultFromType result_from = obj->isImmRep();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_imm_rep(data_collection_model_reporting_information_t *obj_reporting_information, const bool p_imm_rep)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_imm_rep;
    typedef typename ReportingInformation::ImmRepType ValueType;

    ValueType value = value_from;
    if (!obj->setImmRep(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_imm_rep_move(data_collection_model_reporting_information_t *obj_reporting_information, bool p_imm_rep)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_imm_rep;
    typedef typename ReportingInformation::ImmRepType ValueType;

    ValueType value = value_from;
    
    if (!obj->setImmRep(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_notification_method_t* data_collection_model_reporting_information_get_notif_method(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::NotifMethodType ResultFromType;
    const ResultFromType result_from = obj->getNotifMethod();
    const data_collection_model_notification_method_t *result = reinterpret_cast<const data_collection_model_notification_method_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_method(data_collection_model_reporting_information_t *obj_reporting_information, const data_collection_model_notification_method_t* p_notif_method)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_notif_method;
    typedef typename ReportingInformation::NotifMethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNotifMethod(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_method_move(data_collection_model_reporting_information_t *obj_reporting_information, data_collection_model_notification_method_t* p_notif_method)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_notif_method;
    typedef typename ReportingInformation::NotifMethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNotifMethod(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_reporting_information_get_max_report_nbr(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::MaxReportNbrType ResultFromType;
    const ResultFromType result_from = obj->getMaxReportNbr();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_max_report_nbr(data_collection_model_reporting_information_t *obj_reporting_information, const int32_t p_max_report_nbr)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_max_report_nbr;
    typedef typename ReportingInformation::MaxReportNbrType ValueType;

    ValueType value = value_from;
    if (!obj->setMaxReportNbr(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_max_report_nbr_move(data_collection_model_reporting_information_t *obj_reporting_information, int32_t p_max_report_nbr)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_max_report_nbr;
    typedef typename ReportingInformation::MaxReportNbrType ValueType;

    ValueType value = value_from;
    
    if (!obj->setMaxReportNbr(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_reporting_information_get_mon_dur(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::MonDurType ResultFromType;
    const ResultFromType result_from = obj->getMonDur();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_mon_dur(data_collection_model_reporting_information_t *obj_reporting_information, const char* p_mon_dur)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_mon_dur;
    typedef typename ReportingInformation::MonDurType ValueType;

    ValueType value(value_from);
    if (!obj->setMonDur(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_mon_dur_move(data_collection_model_reporting_information_t *obj_reporting_information, char* p_mon_dur)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_mon_dur;
    typedef typename ReportingInformation::MonDurType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMonDur(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_reporting_information_get_rep_period(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::RepPeriodType ResultFromType;
    const ResultFromType result_from = obj->getRepPeriod();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_rep_period(data_collection_model_reporting_information_t *obj_reporting_information, const int32_t p_rep_period)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_rep_period;
    typedef typename ReportingInformation::RepPeriodType ValueType;

    ValueType value = value_from;
    if (!obj->setRepPeriod(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_rep_period_move(data_collection_model_reporting_information_t *obj_reporting_information, int32_t p_rep_period)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_rep_period;
    typedef typename ReportingInformation::RepPeriodType ValueType;

    ValueType value = value_from;
    
    if (!obj->setRepPeriod(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_reporting_information_get_samp_ratio(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::SampRatioType ResultFromType;
    const ResultFromType result_from = obj->getSampRatio();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_samp_ratio(data_collection_model_reporting_information_t *obj_reporting_information, const int32_t p_samp_ratio)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_samp_ratio;
    typedef typename ReportingInformation::SampRatioType ValueType;

    ValueType value = value_from;
    if (!obj->setSampRatio(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_samp_ratio_move(data_collection_model_reporting_information_t *obj_reporting_information, int32_t p_samp_ratio)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_samp_ratio;
    typedef typename ReportingInformation::SampRatioType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSampRatio(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_reporting_information_get_partition_criteria(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::PartitionCriteriaType ResultFromType;
    const ResultFromType result_from = obj->getPartitionCriteria();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_partitioning_criteria_t *item_obj = reinterpret_cast<data_collection_model_partitioning_criteria_t*>(new std::shared_ptr<PartitioningCriteria >(item));
        node = data_collection_model_partitioning_criteria_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_partition_criteria(data_collection_model_reporting_information_t *obj_reporting_information, const ogs_list_t* p_partition_criteria)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_partition_criteria;
    typedef typename ReportingInformation::PartitionCriteriaType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setPartitionCriteria(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_partition_criteria_move(data_collection_model_reporting_information_t *obj_reporting_information, ogs_list_t* p_partition_criteria)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_partition_criteria;
    typedef typename ReportingInformation::PartitionCriteriaType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_partition_criteria);
    if (!obj->setPartitionCriteria(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_add_partition_criteria(data_collection_model_reporting_information_t *obj_reporting_information, data_collection_model_partitioning_criteria_t* p_partition_criteria)
{
    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::PartitionCriteriaType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_partition_criteria;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addPartitionCriteria(value);
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_remove_partition_criteria(data_collection_model_reporting_information_t *obj_reporting_information, const data_collection_model_partitioning_criteria_t* p_partition_criteria)
{
    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::PartitionCriteriaType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_partition_criteria;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removePartitionCriteria(value);
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_clear_partition_criteria(data_collection_model_reporting_information_t *obj_reporting_information)
{   
    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    obj->clearPartitionCriteria();
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_reporting_information_get_grp_rep_time(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::GrpRepTimeType ResultFromType;
    const ResultFromType result_from = obj->getGrpRepTime();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_grp_rep_time(data_collection_model_reporting_information_t *obj_reporting_information, const int32_t p_grp_rep_time)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_grp_rep_time;
    typedef typename ReportingInformation::GrpRepTimeType ValueType;

    ValueType value = value_from;
    if (!obj->setGrpRepTime(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_grp_rep_time_move(data_collection_model_reporting_information_t *obj_reporting_information, int32_t p_grp_rep_time)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_grp_rep_time;
    typedef typename ReportingInformation::GrpRepTimeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setGrpRepTime(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_notification_flag_t* data_collection_model_reporting_information_get_notif_flag(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::NotifFlagType ResultFromType;
    const ResultFromType result_from = obj->getNotifFlag();
    const data_collection_model_notification_flag_t *result = reinterpret_cast<const data_collection_model_notification_flag_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag(data_collection_model_reporting_information_t *obj_reporting_information, const data_collection_model_notification_flag_t* p_notif_flag)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_notif_flag;
    typedef typename ReportingInformation::NotifFlagType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNotifFlag(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_move(data_collection_model_reporting_information_t *obj_reporting_information, data_collection_model_notification_flag_t* p_notif_flag)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_notif_flag;
    typedef typename ReportingInformation::NotifFlagType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNotifFlag(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_muting_exception_instructions_t* data_collection_model_reporting_information_get_notif_flag_instruct(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::NotifFlagInstructType ResultFromType;
    const ResultFromType result_from = obj->getNotifFlagInstruct();
    const data_collection_model_muting_exception_instructions_t *result = reinterpret_cast<const data_collection_model_muting_exception_instructions_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_instruct(data_collection_model_reporting_information_t *obj_reporting_information, const data_collection_model_muting_exception_instructions_t* p_notif_flag_instruct)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_notif_flag_instruct;
    typedef typename ReportingInformation::NotifFlagInstructType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNotifFlagInstruct(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_instruct_move(data_collection_model_reporting_information_t *obj_reporting_information, data_collection_model_muting_exception_instructions_t* p_notif_flag_instruct)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_notif_flag_instruct;
    typedef typename ReportingInformation::NotifFlagInstructType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNotifFlagInstruct(std::move(value))) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_muting_notifications_settings_t* data_collection_model_reporting_information_get_muting_setting(const data_collection_model_reporting_information_t *obj_reporting_information)
{
    const std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<const std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    typedef typename ReportingInformation::MutingSettingType ResultFromType;
    const ResultFromType result_from = obj->getMutingSetting();
    const data_collection_model_muting_notifications_settings_t *result = reinterpret_cast<const data_collection_model_muting_notifications_settings_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_muting_setting(data_collection_model_reporting_information_t *obj_reporting_information, const data_collection_model_muting_notifications_settings_t* p_muting_setting)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_muting_setting;
    typedef typename ReportingInformation::MutingSettingType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMutingSetting(value)) return NULL;
    return obj_reporting_information;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_muting_setting_move(data_collection_model_reporting_information_t *obj_reporting_information, data_collection_model_muting_notifications_settings_t* p_muting_setting)
{
    if (obj_reporting_information == NULL) return NULL;

    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    const auto &value_from = p_muting_setting;
    typedef typename ReportingInformation::MutingSettingType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMutingSetting(std::move(value))) return NULL;
    return obj_reporting_information;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_reporting_information_make_lnode(data_collection_model_reporting_information_t *p_reporting_information)
{
    return data_collection_lnode_create(p_reporting_information, reinterpret_cast<void(*)(void*)>(data_collection_model_reporting_information_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_reporting_information_refcount(data_collection_model_reporting_information_t *obj_reporting_information)
{
    std::shared_ptr<ReportingInformation > &obj = *reinterpret_cast<std::shared_ptr<ReportingInformation >*>(obj_reporting_information);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

