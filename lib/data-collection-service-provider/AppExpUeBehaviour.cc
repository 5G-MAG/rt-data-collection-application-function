/**********************************************************************************************************************************
 * AppExpUeBehaviour - C interface to the AppExpUeBehaviour object
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

/*#include "AppExpUeBehaviour.h" already included by data-collection-sp/data-collection.h */
#include "AppExpUeBehaviour-internal.h"
#include "openapi/model/AppExpUeBehaviour.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create(






)
{
    return reinterpret_cast<data_collection_model_app_exp_ue_behaviour_t*>(new std::shared_ptr<AppExpUeBehaviour>(new AppExpUeBehaviour(






)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_copy(const data_collection_model_app_exp_ue_behaviour_t *other)
{
    return reinterpret_cast<data_collection_model_app_exp_ue_behaviour_t*>(new std::shared_ptr<AppExpUeBehaviour >(new AppExpUeBehaviour(**reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_move(data_collection_model_app_exp_ue_behaviour_t *other)
{
    return reinterpret_cast<data_collection_model_app_exp_ue_behaviour_t*>(new std::shared_ptr<AppExpUeBehaviour >(std::move(*reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_copy(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_app_exp_ue_behaviour_t *other)
{
    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
    *obj = **reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(other);
    return app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_app_exp_ue_behaviour_t *other)
{
    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
    obj = std::move(*reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(other));
    return app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_app_exp_ue_behaviour_free(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour)
{
    delete reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_app_exp_ue_behaviour_toJSON(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, bool as_request)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_app_exp_ue_behaviour_t*>(new std::shared_ptr<AppExpUeBehaviour >(new AppExpUeBehaviour(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_app_exp_ue_behaviour_is_equal_to(const data_collection_model_app_exp_ue_behaviour_t *first, const data_collection_model_app_exp_ue_behaviour_t *second)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj1 = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(first);
    const std::shared_ptr<AppExpUeBehaviour > &obj2 = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_app_exp_ue_behaviour_get_app_id(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_app_id)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_app_id;
    typedef typename AppExpUeBehaviour::AppIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAppId(value)) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_app_id)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_app_id;
    typedef typename AppExpUeBehaviour::AppIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAppId(std::move(value))) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_app_exp_ue_behaviour_get_exp_pdu_ses_inac_tm(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::ExpPduSesInacTmType ResultFromType;
    const ResultFromType result_from = obj->getExpPduSesInacTm();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_exp_pdu_ses_inac_tm;
    typedef typename AppExpUeBehaviour::ExpPduSesInacTmType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setExpPduSesInacTm(value)) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_exp_pdu_ses_inac_tm;
    typedef typename AppExpUeBehaviour::ExpPduSesInacTmType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setExpPduSesInacTm(std::move(value))) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_app_exp_ue_behaviour_get_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::FlowDescriptionsType ResultFromType;
    const ResultFromType result_from = obj->getFlowDescriptions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const ogs_list_t* p_flow_descriptions)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_flow_descriptions;
    typedef typename AppExpUeBehaviour::FlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setFlowDescriptions(value)) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, ogs_list_t* p_flow_descriptions)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_flow_descriptions;
    typedef typename AppExpUeBehaviour::FlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_flow_descriptions);
    if (!obj->setFlowDescriptions(std::move(value))) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_add_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_flow_descriptions)
{
    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::FlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_flow_descriptions;

    ValueType value(value_from);

    obj->addFlowDescriptions(value);
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_remove_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_flow_descriptions)
{
    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::FlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_flow_descriptions;
    ValueType value(value_from);
    obj->removeFlowDescriptions(value);
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_clear_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{   
    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    obj->clearFlowDescriptions();
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_app_exp_ue_behaviour_get_confidence_level(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::ConfidenceLevelType ResultFromType;
    const ResultFromType result_from = obj->getConfidenceLevel();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_confidence_level)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_confidence_level;
    typedef typename AppExpUeBehaviour::ConfidenceLevelType ValueType;

    ValueType value(value_from);
    if (!obj->setConfidenceLevel(value)) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_confidence_level)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_confidence_level;
    typedef typename AppExpUeBehaviour::ConfidenceLevelType ValueType;

    ValueType value(value_from);
    
    if (!obj->setConfidenceLevel(std::move(value))) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_app_exp_ue_behaviour_get_accuracy_level(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::AccuracyLevelType ResultFromType;
    const ResultFromType result_from = obj->getAccuracyLevel();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_accuracy_level)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_accuracy_level;
    typedef typename AppExpUeBehaviour::AccuracyLevelType ValueType;

    ValueType value(value_from);
    if (!obj->setAccuracyLevel(value)) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_accuracy_level)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_accuracy_level;
    typedef typename AppExpUeBehaviour::AccuracyLevelType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAccuracyLevel(std::move(value))) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_cp_failure_code_t* data_collection_model_app_exp_ue_behaviour_get_failure_code(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::FailureCodeType ResultFromType;
    const ResultFromType result_from = obj->getFailureCode();
    const data_collection_model_cp_failure_code_t *result = reinterpret_cast<const data_collection_model_cp_failure_code_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const data_collection_model_cp_failure_code_t* p_failure_code)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_failure_code;
    typedef typename AppExpUeBehaviour::FailureCodeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setFailureCode(value)) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, data_collection_model_cp_failure_code_t* p_failure_code)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_failure_code;
    typedef typename AppExpUeBehaviour::FailureCodeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setFailureCode(std::move(value))) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_app_exp_ue_behaviour_get_validity_time(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    typedef typename AppExpUeBehaviour::ValidityTimeType ResultFromType;
    const ResultFromType result_from = obj->getValidityTime();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_validity_time)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_validity_time;
    typedef typename AppExpUeBehaviour::ValidityTimeType ValueType;

    ValueType value(value_from);
    if (!obj->setValidityTime(value)) return NULL;
    return obj_app_exp_ue_behaviour;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_validity_time)
{
    if (obj_app_exp_ue_behaviour == NULL) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    const auto &value_from = p_validity_time;
    typedef typename AppExpUeBehaviour::ValidityTimeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setValidityTime(std::move(value))) return NULL;
    return obj_app_exp_ue_behaviour;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_app_exp_ue_behaviour_make_lnode(data_collection_model_app_exp_ue_behaviour_t *p_app_exp_ue_behaviour)
{
    return data_collection_lnode_create(p_app_exp_ue_behaviour, reinterpret_cast<void(*)(void*)>(data_collection_model_app_exp_ue_behaviour_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_app_exp_ue_behaviour_refcount(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

