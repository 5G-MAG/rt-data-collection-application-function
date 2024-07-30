/**********************************************************************************************************************************
 * PduSetQosPara - C interface to the PduSetQosPara object
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

/*#include "PduSetQosPara.h" already included by data-collection-sp/data-collection.h */
#include "PduSetQosPara-internal.h"
#include "openapi/model/PduSetQosPara.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create(


)
{
    return reinterpret_cast<data_collection_model_pdu_set_qos_para_t*>(new std::shared_ptr<PduSetQosPara>(new PduSetQosPara(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create_copy(const data_collection_model_pdu_set_qos_para_t *other)
{
    return reinterpret_cast<data_collection_model_pdu_set_qos_para_t*>(new std::shared_ptr<PduSetQosPara >(new PduSetQosPara(**reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_create_move(data_collection_model_pdu_set_qos_para_t *other)
{
    return reinterpret_cast<data_collection_model_pdu_set_qos_para_t*>(new std::shared_ptr<PduSetQosPara >(std::move(*reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_copy(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, const data_collection_model_pdu_set_qos_para_t *other)
{
    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(pdu_set_qos_para);
    *obj = **reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(other);
    return pdu_set_qos_para;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_move(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, data_collection_model_pdu_set_qos_para_t *other)
{
    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(pdu_set_qos_para);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(other));
    return pdu_set_qos_para;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_pdu_set_qos_para_free(data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para)
{
    delete reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(pdu_set_qos_para);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_pdu_set_qos_para_toJSON(const data_collection_model_pdu_set_qos_para_t *pdu_set_qos_para, bool as_request)
{
    const std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(pdu_set_qos_para);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_pdu_set_qos_para_t*>(new std::shared_ptr<PduSetQosPara >(new PduSetQosPara(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_pdu_set_qos_para_is_equal_to(const data_collection_model_pdu_set_qos_para_t *first, const data_collection_model_pdu_set_qos_para_t *second)
{
    const std::shared_ptr<PduSetQosPara > &obj1 = *reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(first);
    const std::shared_ptr<PduSetQosPara > &obj2 = *reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_pdu_set_qos_para_get_pdu_set_delay_budget(const data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para)
{
    const std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    typedef typename PduSetQosPara::PduSetDelayBudgetType ResultFromType;
    const ResultFromType result_from = obj->getPduSetDelayBudget();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_delay_budget(data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para, const int32_t p_pdu_set_delay_budget)
{
    if (obj_pdu_set_qos_para == NULL) return NULL;

    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    const auto &value_from = p_pdu_set_delay_budget;
    typedef typename PduSetQosPara::PduSetDelayBudgetType ValueType;

    ValueType value = value_from;
    if (!obj->setPduSetDelayBudget(value)) return NULL;
    return obj_pdu_set_qos_para;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_delay_budget_move(data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para, int32_t p_pdu_set_delay_budget)
{
    if (obj_pdu_set_qos_para == NULL) return NULL;

    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    const auto &value_from = p_pdu_set_delay_budget;
    typedef typename PduSetQosPara::PduSetDelayBudgetType ValueType;

    ValueType value = value_from;
    
    if (!obj->setPduSetDelayBudget(std::move(value))) return NULL;
    return obj_pdu_set_qos_para;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_pdu_set_qos_para_get_pdu_set_err_rate(const data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para)
{
    const std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    typedef typename PduSetQosPara::PduSetErrRateType ResultFromType;
    const ResultFromType result_from = obj->getPduSetErrRate();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_err_rate(data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para, const char* p_pdu_set_err_rate)
{
    if (obj_pdu_set_qos_para == NULL) return NULL;

    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    const auto &value_from = p_pdu_set_err_rate;
    typedef typename PduSetQosPara::PduSetErrRateType ValueType;

    ValueType value(value_from);
    if (!obj->setPduSetErrRate(value)) return NULL;
    return obj_pdu_set_qos_para;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_err_rate_move(data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para, char* p_pdu_set_err_rate)
{
    if (obj_pdu_set_qos_para == NULL) return NULL;

    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    const auto &value_from = p_pdu_set_err_rate;
    typedef typename PduSetQosPara::PduSetErrRateType ValueType;

    ValueType value(value_from);
    
    if (!obj->setPduSetErrRate(std::move(value))) return NULL;
    return obj_pdu_set_qos_para;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_pdu_set_handling_info_t* data_collection_model_pdu_set_qos_para_get_pdu_set_handling_info(const data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para)
{
    const std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<const std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    typedef typename PduSetQosPara::PduSetHandlingInfoType ResultFromType;
    const ResultFromType result_from = obj->getPduSetHandlingInfo();
    const data_collection_model_pdu_set_handling_info_t *result = reinterpret_cast<const data_collection_model_pdu_set_handling_info_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_handling_info(data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para, const data_collection_model_pdu_set_handling_info_t* p_pdu_set_handling_info)
{
    if (obj_pdu_set_qos_para == NULL) return NULL;

    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    const auto &value_from = p_pdu_set_handling_info;
    typedef typename PduSetQosPara::PduSetHandlingInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPduSetHandlingInfo(value)) return NULL;
    return obj_pdu_set_qos_para;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_qos_para_t *data_collection_model_pdu_set_qos_para_set_pdu_set_handling_info_move(data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para, data_collection_model_pdu_set_handling_info_t* p_pdu_set_handling_info)
{
    if (obj_pdu_set_qos_para == NULL) return NULL;

    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    const auto &value_from = p_pdu_set_handling_info;
    typedef typename PduSetQosPara::PduSetHandlingInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPduSetHandlingInfo(std::move(value))) return NULL;
    return obj_pdu_set_qos_para;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_pdu_set_qos_para_make_lnode(data_collection_model_pdu_set_qos_para_t *p_pdu_set_qos_para)
{
    return data_collection_lnode_create(p_pdu_set_qos_para, reinterpret_cast<void(*)(void*)>(data_collection_model_pdu_set_qos_para_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_pdu_set_qos_para_refcount(data_collection_model_pdu_set_qos_para_t *obj_pdu_set_qos_para)
{
    std::shared_ptr<PduSetQosPara > &obj = *reinterpret_cast<std::shared_ptr<PduSetQosPara >*>(obj_pdu_set_qos_para);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

