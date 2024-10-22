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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "AppExpUeBehaviour.h" already included by data-collection-sp/data-collection.h */
#include "AppExpUeBehaviour-internal.h"
#include "openapi/model/AppExpUeBehaviour.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create(






)
{
    return reinterpret_cast<data_collection_model_app_exp_ue_behaviour_t*>(new std::shared_ptr<AppExpUeBehaviour>(new AppExpUeBehaviour(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_copy(const data_collection_model_app_exp_ue_behaviour_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_app_exp_ue_behaviour_t*>(new std::shared_ptr<AppExpUeBehaviour >(new AppExpUeBehaviour(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_move(data_collection_model_app_exp_ue_behaviour_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AppExpUeBehaviour > *obj = reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_copy(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_app_exp_ue_behaviour_t *other)
{
    if (app_exp_ue_behaviour) {
        std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
        if (obj) {
            if (other) {
                const std::shared_ptr<AppExpUeBehaviour > &other_obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(other);
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
                const std::shared_ptr<AppExpUeBehaviour > &other_obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(other);
                if (other_obj) {
                    obj.reset(new AppExpUeBehaviour(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        app_exp_ue_behaviour = data_collection_model_app_exp_ue_behaviour_create_copy(other);
    }
    return app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_app_exp_ue_behaviour_t *other)
{
    std::shared_ptr<AppExpUeBehaviour > *other_ptr = reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(other);

    if (app_exp_ue_behaviour) {
        std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                app_exp_ue_behaviour = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_app_exp_ue_behaviour_free(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour)
{
    if (!app_exp_ue_behaviour) return;
    delete reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_app_exp_ue_behaviour_toJSON(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, bool as_request)
{
    if (!app_exp_ue_behaviour) return NULL;
    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(app_exp_ue_behaviour);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_app_exp_ue_behaviour_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_is_equal_to(const data_collection_model_app_exp_ue_behaviour_t *first, const data_collection_model_app_exp_ue_behaviour_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AppExpUeBehaviour > &obj2 = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AppExpUeBehaviour > &obj1 = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_app_id(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return false;

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return false;

    return obj->getAppId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_app_id(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AppExpUeBehaviour::AppIdType ResultFromType;
    const ResultFromType &result_from = obj->getAppId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_app_id)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename AppExpUeBehaviour::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_app_id)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename AppExpUeBehaviour::AppIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAppId(std::move(value))) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_exp_pdu_ses_inac_tm(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return false;

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return false;

    return obj->getExpPduSesInacTm().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_app_exp_ue_behaviour_get_exp_pdu_ses_inac_tm(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    typedef typename AppExpUeBehaviour::ExpPduSesInacTmType ResultFromType;
    const ResultFromType &result_from = obj->getExpPduSesInacTm();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_exp_pdu_ses_inac_tm;
    typedef typename AppExpUeBehaviour::ExpPduSesInacTmType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setExpPduSesInacTm(value)) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_exp_pdu_ses_inac_tm;
    typedef typename AppExpUeBehaviour::ExpPduSesInacTmType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setExpPduSesInacTm(std::move(value))) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return false;

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return false;

    return obj->getFlowDescriptions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_app_exp_ue_behaviour_get_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AppExpUeBehaviour::FlowDescriptionsType ResultFromType;
    const ResultFromType &result_from = obj->getFlowDescriptions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const ogs_list_t* p_flow_descriptions)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_flow_descriptions;
    typedef typename AppExpUeBehaviour::FlowDescriptionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setFlowDescriptions(value)) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, ogs_list_t* p_flow_descriptions)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_flow_descriptions;
    typedef typename AppExpUeBehaviour::FlowDescriptionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_flow_descriptions);
    if (!obj->setFlowDescriptions(std::move(value))) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_add_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_flow_descriptions)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    typedef typename AppExpUeBehaviour::FlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_flow_descriptions;

    ValueType value(value_from);

    ogs_free(p_flow_descriptions);
    if (value) obj->addFlowDescriptions(value.value());
    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_remove_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_flow_descriptions)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    typedef typename AppExpUeBehaviour::FlowDescriptionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_flow_descriptions;
    ValueType value(value_from);

    obj->removeFlowDescriptions(value);
    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_entry_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, size_t idx)
{
    if (!obj_app_exp_ue_behaviour) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const AppExpUeBehaviour::FlowDescriptionsType &container = obj->getFlowDescriptions();
    if (!container.has_value()) {
        const char *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename AppExpUeBehaviour::FlowDescriptionsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_clear_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    obj->clearFlowDescriptions();
    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_confidence_level(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return false;

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return false;

    return obj->getConfidenceLevel().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_confidence_level(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AppExpUeBehaviour::ConfidenceLevelType ResultFromType;
    const ResultFromType &result_from = obj->getConfidenceLevel();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_confidence_level)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_confidence_level;
    typedef typename AppExpUeBehaviour::ConfidenceLevelType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidenceLevel(value)) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_confidence_level)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_confidence_level;
    typedef typename AppExpUeBehaviour::ConfidenceLevelType ValueType;

    ValueType value(value_from);

    
    if (!obj->setConfidenceLevel(std::move(value))) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_accuracy_level(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return false;

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return false;

    return obj->getAccuracyLevel().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_accuracy_level(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AppExpUeBehaviour::AccuracyLevelType ResultFromType;
    const ResultFromType &result_from = obj->getAccuracyLevel();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_accuracy_level)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_accuracy_level;
    typedef typename AppExpUeBehaviour::AccuracyLevelType ValueType;

    ValueType value(value_from);

    if (!obj->setAccuracyLevel(value)) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_accuracy_level)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_accuracy_level;
    typedef typename AppExpUeBehaviour::AccuracyLevelType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAccuracyLevel(std::move(value))) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_failure_code(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return false;

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return false;

    return obj->getFailureCode().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cp_failure_code_t* data_collection_model_app_exp_ue_behaviour_get_failure_code(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) {
        const data_collection_model_cp_failure_code_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        const data_collection_model_cp_failure_code_t *result = NULL;
        return result;
    }

    typedef typename AppExpUeBehaviour::FailureCodeType ResultFromType;
    const ResultFromType &result_from = obj->getFailureCode();
    const data_collection_model_cp_failure_code_t *result = reinterpret_cast<const data_collection_model_cp_failure_code_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const data_collection_model_cp_failure_code_t* p_failure_code)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_failure_code;
    typedef typename AppExpUeBehaviour::FailureCodeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setFailureCode(value)) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, data_collection_model_cp_failure_code_t* p_failure_code)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_failure_code;
    typedef typename AppExpUeBehaviour::FailureCodeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setFailureCode(std::move(value))) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_validity_time(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return false;

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return false;

    return obj->getValidityTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_validity_time(const data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<const std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AppExpUeBehaviour::ValidityTimeType ResultFromType;
    const ResultFromType &result_from = obj->getValidityTime();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, const char* p_validity_time)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_validity_time;
    typedef typename AppExpUeBehaviour::ValidityTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setValidityTime(value)) return NULL;

    return obj_app_exp_ue_behaviour;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time_move(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour, char* p_validity_time)
{
    if (!obj_app_exp_ue_behaviour) return NULL;

    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    if (!obj) return NULL;

    const auto &value_from = p_validity_time;
    typedef typename AppExpUeBehaviour::ValidityTimeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setValidityTime(std::move(value))) return NULL;

    return obj_app_exp_ue_behaviour;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_app_exp_ue_behaviour_make_lnode(data_collection_model_app_exp_ue_behaviour_t *p_app_exp_ue_behaviour)
{
    return data_collection_lnode_create(p_app_exp_ue_behaviour, reinterpret_cast<void(*)(void*)>(data_collection_model_app_exp_ue_behaviour_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_app_exp_ue_behaviour_refcount(data_collection_model_app_exp_ue_behaviour_t *obj_app_exp_ue_behaviour)
{
    if (!obj_app_exp_ue_behaviour) return 0l;
    std::shared_ptr<AppExpUeBehaviour > &obj = *reinterpret_cast<std::shared_ptr<AppExpUeBehaviour >*>(obj_app_exp_ue_behaviour);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

