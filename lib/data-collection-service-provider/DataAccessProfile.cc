/**********************************************************************************************************************************
 * DataAccessProfile - C interface to the DataAccessProfile object
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

/*#include "DataAccessProfile.h" already included by data-collection-sp/data-collection.h */
#include "DataAccessProfile-internal.h"
#include "openapi/model/DataAccessProfile.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create(





)
{
    return reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile>(new DataAccessProfile(





)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_ref(const data_collection_model_data_access_profile_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile>(*reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_copy(const data_collection_model_data_access_profile_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile >(new DataAccessProfile(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_move(data_collection_model_data_access_profile_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataAccessProfile > *obj = reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_copy(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_t *other)
{
    if (data_access_profile) {
        std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(data_access_profile);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataAccessProfile > &other_obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(other);
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
                const std::shared_ptr<DataAccessProfile > &other_obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(other);
                if (other_obj) {
                    obj.reset(new DataAccessProfile(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_access_profile = data_collection_model_data_access_profile_create_copy(other);
    }
    return data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_t *other)
{
    std::shared_ptr<DataAccessProfile > *other_ptr = reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(other);

    if (data_access_profile) {
        std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(data_access_profile);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_access_profile = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_free(data_collection_model_data_access_profile_t *data_access_profile)
{
    if (!data_access_profile) return;
    delete reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(data_access_profile);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_toJSON(const data_collection_model_data_access_profile_t *data_access_profile, bool as_request)
{
    if (!data_access_profile) return NULL;
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(data_access_profile);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_data_access_profile_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile >(new DataAccessProfile(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_is_equal_to(const data_collection_model_data_access_profile_t *first, const data_collection_model_data_access_profile_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataAccessProfile > &obj2 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataAccessProfile > &obj1 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_access_profile_get_data_access_profile_id(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DataAccessProfile::DataAccessProfileIdType ResultFromType;
    const ResultFromType &result_from = obj->getDataAccessProfileId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id(data_collection_model_data_access_profile_t *obj_data_access_profile, const char* p_data_access_profile_id)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_data_access_profile_id;
    typedef typename DataAccessProfile::DataAccessProfileIdType ValueType;

    ValueType value(value_from);

    if (!obj->setDataAccessProfileId(value)) return NULL;

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id_move(data_collection_model_data_access_profile_t *obj_data_access_profile, char* p_data_access_profile_id)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_data_access_profile_id;
    typedef typename DataAccessProfile::DataAccessProfileIdType ValueType;

    ValueType value(value_from);

    if (!obj->setDataAccessProfileId(std::move(value))) return NULL;
    ogs_free
(p_data_access_profile_id);

    return obj_data_access_profile;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_get_target_event_consumer_types(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataAccessProfile::TargetEventConsumerTypesType ResultFromType;
    const ResultFromType &result_from = obj->getTargetEventConsumerTypes();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_event_consumer_type_t *item_obj = reinterpret_cast<data_collection_model_event_consumer_type_t*>(item.has_value()?new std::shared_ptr<EventConsumerType >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_event_consumer_type_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile, const ogs_list_t* p_target_event_consumer_types)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_target_event_consumer_types;
    typedef typename DataAccessProfile::TargetEventConsumerTypesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setTargetEventConsumerTypes(value)) return NULL;

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types_move(data_collection_model_data_access_profile_t *obj_data_access_profile, ogs_list_t* p_target_event_consumer_types)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_target_event_consumer_types;
    typedef typename DataAccessProfile::TargetEventConsumerTypesType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setTargetEventConsumerTypes(std::move(value))) return NULL;
    data_collection_list_free
(p_target_event_consumer_types);

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_event_consumer_type_t* p_target_event_consumer_types)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    typedef typename DataAccessProfile::TargetEventConsumerTypesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_target_event_consumer_types;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_event_consumer_type_free
(p_target_event_consumer_types);
    obj->addTargetEventConsumerTypes(value);
    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_event_consumer_type_t* p_target_event_consumer_types)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    typedef typename DataAccessProfile::TargetEventConsumerTypesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_target_event_consumer_types;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeTargetEventConsumerTypes(value);
    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_consumer_type_t* data_collection_model_data_access_profile_get_entry_target_event_consumer_types(const data_collection_model_data_access_profile_t *obj_data_access_profile, size_t idx)
{
    if (!obj_data_access_profile) {
        const data_collection_model_event_consumer_type_t *result = NULL;

        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        const data_collection_model_event_consumer_type_t *result = NULL;

        return result;
    }

    const DataAccessProfile::TargetEventConsumerTypesType &container = obj->getTargetEventConsumerTypes();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_event_consumer_type_t *result = NULL;

        return result;
    }
    typedef typename DataAccessProfile::TargetEventConsumerTypesItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_event_consumer_type_t *result = reinterpret_cast<const data_collection_model_event_consumer_type_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    obj->clearTargetEventConsumerTypes();
    return obj_data_access_profile;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_get_parameters(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename DataAccessProfile::ParametersType ResultFromType;
    const ResultFromType &result_from = obj->getParameters();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile, const ogs_list_t* p_parameters)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_parameters;
    typedef typename DataAccessProfile::ParametersType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setParameters(value)) return NULL;

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters_move(data_collection_model_data_access_profile_t *obj_data_access_profile, ogs_list_t* p_parameters)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_parameters;
    typedef typename DataAccessProfile::ParametersType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setParameters(std::move(value))) return NULL;
    data_collection_list_free
(p_parameters);

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile, char* p_parameters)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    typedef typename DataAccessProfile::ParametersType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_parameters;

    ValueType value(value_from);

    ogs_free
(p_parameters);
    obj->addParameters(value);
    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile, const char* p_parameters)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    typedef typename DataAccessProfile::ParametersType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_parameters;
    ValueType value(value_from);

    obj->removeParameters(value);
    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_access_profile_get_entry_parameters(const data_collection_model_data_access_profile_t *obj_data_access_profile, size_t idx)
{
    if (!obj_data_access_profile) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const DataAccessProfile::ParametersType &container = obj->getParameters();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename DataAccessProfile::ParametersItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    obj->clearParameters();
    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_time_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) return false;

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return false;

    return obj->getTimeAccessRestrictions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_time_access_restrictions_t* data_collection_model_data_access_profile_get_time_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) {
        const data_collection_model_data_access_profile_time_access_restrictions_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        const data_collection_model_data_access_profile_time_access_restrictions_t *result = NULL;
        return result;
    }

    typedef typename DataAccessProfile::TimeAccessRestrictionsType ResultFromType;
    const ResultFromType &result_from = obj->getTimeAccessRestrictions();
    const data_collection_model_data_access_profile_time_access_restrictions_t *result = reinterpret_cast<const data_collection_model_data_access_profile_time_access_restrictions_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_time_access_restrictions;
    typedef typename DataAccessProfile::TimeAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTimeAccessRestrictions(value)) return NULL;

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions_move(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_time_access_restrictions;
    typedef typename DataAccessProfile::TimeAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTimeAccessRestrictions(std::move(value))) return NULL;
    data_collection_model_data_access_profile_time_access_restrictions_free
(p_time_access_restrictions);

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_user_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) return false;

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return false;

    return obj->getUserAccessRestrictions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_user_access_restrictions_t* data_collection_model_data_access_profile_get_user_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) {
        const data_collection_model_data_access_profile_user_access_restrictions_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        const data_collection_model_data_access_profile_user_access_restrictions_t *result = NULL;
        return result;
    }

    typedef typename DataAccessProfile::UserAccessRestrictionsType ResultFromType;
    const ResultFromType &result_from = obj->getUserAccessRestrictions();
    const data_collection_model_data_access_profile_user_access_restrictions_t *result = reinterpret_cast<const data_collection_model_data_access_profile_user_access_restrictions_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_user_access_restrictions;
    typedef typename DataAccessProfile::UserAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUserAccessRestrictions(value)) return NULL;

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions_move(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_user_access_restrictions;
    typedef typename DataAccessProfile::UserAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUserAccessRestrictions(std::move(value))) return NULL;
    data_collection_model_data_access_profile_user_access_restrictions_free
(p_user_access_restrictions);

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_location_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) return false;

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return false;

    return obj->getLocationAccessRestrictions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_location_access_restrictions_t* data_collection_model_data_access_profile_get_location_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) {
        const data_collection_model_data_access_profile_location_access_restrictions_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) {
        const data_collection_model_data_access_profile_location_access_restrictions_t *result = NULL;
        return result;
    }

    typedef typename DataAccessProfile::LocationAccessRestrictionsType ResultFromType;
    const ResultFromType &result_from = obj->getLocationAccessRestrictions();
    const data_collection_model_data_access_profile_location_access_restrictions_t *result = reinterpret_cast<const data_collection_model_data_access_profile_location_access_restrictions_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_location_access_restrictions;
    typedef typename DataAccessProfile::LocationAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocationAccessRestrictions(value)) return NULL;

    return obj_data_access_profile;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions_move(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions)
{
    if (!obj_data_access_profile) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    if (!obj) return NULL;

    const auto &value_from = p_location_access_restrictions;
    typedef typename DataAccessProfile::LocationAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocationAccessRestrictions(std::move(value))) return NULL;
    data_collection_model_data_access_profile_location_access_restrictions_free
(p_location_access_restrictions);

    return obj_data_access_profile;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_make_lnode(data_collection_model_data_access_profile_t *p_data_access_profile)
{
    return data_collection_lnode_create(p_data_access_profile, reinterpret_cast<void(*)(void*)>(data_collection_model_data_access_profile_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_access_profile_refcount(data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    if (!obj_data_access_profile) return 0l;
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

