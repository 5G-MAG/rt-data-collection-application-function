/**********************************************************************************************************************************
 * UeCommunicationCollection - C interface to the UeCommunicationCollection object
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

/*#include "UeCommunicationCollection.h" already included by data-collection-sp/data-collection.h */
#include "UeCommunicationCollection-internal.h"
#include "openapi/model/UeCommunicationCollection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create(






)
{
    return reinterpret_cast<data_collection_model_ue_communication_collection_t*>(new std::shared_ptr<UeCommunicationCollection>(new UeCommunicationCollection(






)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create_copy(const data_collection_model_ue_communication_collection_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ue_communication_collection_t*>(new std::shared_ptr<UeCommunicationCollection >(new UeCommunicationCollection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create_move(data_collection_model_ue_communication_collection_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<UeCommunicationCollection > *obj = reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_copy(data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_ue_communication_collection_t *other)
{
    if (ue_communication_collection) {
        std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(ue_communication_collection);
        if (obj) {
            if (other) {
                const std::shared_ptr<UeCommunicationCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(other);
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
                const std::shared_ptr<UeCommunicationCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(other);
                if (other_obj) {
                    obj.reset(new UeCommunicationCollection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ue_communication_collection = data_collection_model_ue_communication_collection_create_copy(other);
    }
    return ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, data_collection_model_ue_communication_collection_t *other)
{
    std::shared_ptr<UeCommunicationCollection > *other_ptr = reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(other);

    if (ue_communication_collection) {
        std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(ue_communication_collection);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ue_communication_collection = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_communication_collection_free(data_collection_model_ue_communication_collection_t *ue_communication_collection)
{
    if (!ue_communication_collection) return;
    delete reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(ue_communication_collection);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_communication_collection_toJSON(const data_collection_model_ue_communication_collection_t *ue_communication_collection, bool as_request)
{
    if (!ue_communication_collection) return NULL;
    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(ue_communication_collection);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_ue_communication_collection_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ue_communication_collection_t*>(new std::shared_ptr<UeCommunicationCollection >(new UeCommunicationCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_is_equal_to(const data_collection_model_ue_communication_collection_t *first, const data_collection_model_ue_communication_collection_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<UeCommunicationCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<UeCommunicationCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_gpsi(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) return false;

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return false;

    return obj->getGpsi().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_gpsi(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UeCommunicationCollection::GpsiType ResultFromType;
    const ResultFromType &result_from = obj->getGpsi();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_gpsi(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const char* p_gpsi)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_gpsi;
    typedef typename UeCommunicationCollection::GpsiType ValueType;

    ValueType value(value_from);

    if (!obj->setGpsi(value)) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_gpsi_move(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, char* p_gpsi)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_gpsi;
    typedef typename UeCommunicationCollection::GpsiType ValueType;

    ValueType value(value_from);

    
    if (!obj->setGpsi(std::move(value))) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_supi(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) return false;

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return false;

    return obj->getSupi().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_supi(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UeCommunicationCollection::SupiType ResultFromType;
    const ResultFromType &result_from = obj->getSupi();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_supi(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const char* p_supi)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_supi;
    typedef typename UeCommunicationCollection::SupiType ValueType;

    ValueType value(value_from);

    if (!obj->setSupi(value)) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_supi_move(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, char* p_supi)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_supi;
    typedef typename UeCommunicationCollection::SupiType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSupi(std::move(value))) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_exter_group_id(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) return false;

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return false;

    return obj->getExterGroupId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_exter_group_id(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UeCommunicationCollection::ExterGroupIdType ResultFromType;
    const ResultFromType &result_from = obj->getExterGroupId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_exter_group_id(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const char* p_exter_group_id)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_exter_group_id;
    typedef typename UeCommunicationCollection::ExterGroupIdType ValueType;

    ValueType value(value_from);

    if (!obj->setExterGroupId(value)) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_exter_group_id_move(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, char* p_exter_group_id)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_exter_group_id;
    typedef typename UeCommunicationCollection::ExterGroupIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setExterGroupId(std::move(value))) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_inter_group_id(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) return false;

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return false;

    return obj->getInterGroupId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_inter_group_id(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UeCommunicationCollection::InterGroupIdType ResultFromType;
    const ResultFromType &result_from = obj->getInterGroupId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_inter_group_id(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const char* p_inter_group_id)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_inter_group_id;
    typedef typename UeCommunicationCollection::InterGroupIdType ValueType;

    ValueType value(value_from);

    if (!obj->setInterGroupId(value)) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_inter_group_id_move(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, char* p_inter_group_id)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_inter_group_id;
    typedef typename UeCommunicationCollection::InterGroupIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setInterGroupId(std::move(value))) return NULL;

    return obj_ue_communication_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_app_id(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UeCommunicationCollection::AppIdType ResultFromType;
    const ResultFromType &result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_app_id(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const char* p_app_id)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename UeCommunicationCollection::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_app_id_move(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, char* p_app_id)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename UeCommunicationCollection::AppIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAppId(std::move(value))) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_expected_ue_behave_para(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) return false;

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return false;

    return obj->getExpectedUeBehavePara().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cp_parameter_set_t* data_collection_model_ue_communication_collection_get_expected_ue_behave_para(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) {
        const data_collection_model_cp_parameter_set_t *result = NULL;
        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        const data_collection_model_cp_parameter_set_t *result = NULL;
        return result;
    }

    typedef typename UeCommunicationCollection::ExpectedUeBehaveParaType ResultFromType;
    const ResultFromType &result_from = obj->getExpectedUeBehavePara();
    const data_collection_model_cp_parameter_set_t *result = reinterpret_cast<const data_collection_model_cp_parameter_set_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_expected_ue_behave_para(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const data_collection_model_cp_parameter_set_t* p_expected_ue_behave_para)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_expected_ue_behave_para;
    typedef typename UeCommunicationCollection::ExpectedUeBehaveParaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setExpectedUeBehavePara(value)) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_expected_ue_behave_para_move(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, data_collection_model_cp_parameter_set_t* p_expected_ue_behave_para)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_expected_ue_behave_para;
    typedef typename UeCommunicationCollection::ExpectedUeBehaveParaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setExpectedUeBehavePara(std::move(value))) return NULL;

    return obj_ue_communication_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ue_communication_collection_get_comms(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename UeCommunicationCollection::CommsType ResultFromType;
    const ResultFromType &result_from = obj->getComms();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_communication_collection_t *item_obj = reinterpret_cast<data_collection_model_communication_collection_t*>(item.has_value()?new std::shared_ptr<CommunicationCollection >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_communication_collection_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_comms(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const ogs_list_t* p_comms)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_comms;
    typedef typename UeCommunicationCollection::CommsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setComms(value)) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_comms_move(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, ogs_list_t* p_comms)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    const auto &value_from = p_comms;
    typedef typename UeCommunicationCollection::CommsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_comms);
    if (!obj->setComms(std::move(value))) return NULL;

    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_add_comms(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, data_collection_model_communication_collection_t* p_comms)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    typedef typename UeCommunicationCollection::CommsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_comms;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_communication_collection_free(p_comms);
    obj->addComms(value);
    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_remove_comms(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, const data_collection_model_communication_collection_t* p_comms)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    typedef typename UeCommunicationCollection::CommsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_comms;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeComms(value);
    return obj_ue_communication_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_communication_collection_t* data_collection_model_ue_communication_collection_get_entry_comms(const data_collection_model_ue_communication_collection_t *obj_ue_communication_collection, size_t idx)
{
    if (!obj_ue_communication_collection) {
        const data_collection_model_communication_collection_t *result = NULL;

        return result;
    }

    const std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) {
        const data_collection_model_communication_collection_t *result = NULL;

        return result;
    }

    const UeCommunicationCollection::CommsType &container = obj->getComms();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_communication_collection_t *result = NULL;

        return result;
    }
    typedef typename UeCommunicationCollection::CommsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_communication_collection_t *result = reinterpret_cast<const data_collection_model_communication_collection_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_clear_comms(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) return NULL;

    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    if (!obj) return NULL;

    obj->clearComms();
    return obj_ue_communication_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_communication_collection_make_lnode(data_collection_model_ue_communication_collection_t *p_ue_communication_collection)
{
    return data_collection_lnode_create(p_ue_communication_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_ue_communication_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ue_communication_collection_refcount(data_collection_model_ue_communication_collection_t *obj_ue_communication_collection)
{
    if (!obj_ue_communication_collection) return 0l;
    std::shared_ptr<UeCommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<UeCommunicationCollection >*>(obj_ue_communication_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

