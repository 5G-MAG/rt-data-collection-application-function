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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "DataAccessProfile.h" already included by data-collection-sp/data-collection.h */
#include "DataAccessProfile-internal.h"
#include "openapi/model/DataAccessProfile.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create(





)
{
    return reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile>(new DataAccessProfile(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_copy(const data_collection_model_data_access_profile_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile >(new DataAccessProfile(**reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_move(data_collection_model_data_access_profile_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_t*>(new std::shared_ptr<DataAccessProfile >(std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_copy(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_t *other)
{
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(data_access_profile);
    *obj = **reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(other);
    return data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_t *other)
{
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(data_access_profile);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(other));
    return data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_access_profile_free(data_collection_model_data_access_profile_t *data_access_profile)
{
    delete reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(data_access_profile);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_access_profile_toJSON(const data_collection_model_data_access_profile_t *data_access_profile, bool as_request)
{
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(data_access_profile);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_access_profile_is_equal_to(const data_collection_model_data_access_profile_t *first, const data_collection_model_data_access_profile_t *second)
{
    const std::shared_ptr<DataAccessProfile > &obj1 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(first);
    const std::shared_ptr<DataAccessProfile > &obj2 = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_data_access_profile_get_data_access_profile_id(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::DataAccessProfileIdType ResultFromType;
    const ResultFromType result_from = obj->getDataAccessProfileId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id(data_collection_model_data_access_profile_t *obj_data_access_profile, const char* p_data_access_profile_id)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_data_access_profile_id;
    typedef typename DataAccessProfile::DataAccessProfileIdType ValueType;

    ValueType value(value_from);
    if (!obj->setDataAccessProfileId(value)) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id_move(data_collection_model_data_access_profile_t *obj_data_access_profile, char* p_data_access_profile_id)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_data_access_profile_id;
    typedef typename DataAccessProfile::DataAccessProfileIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDataAccessProfileId(std::move(value))) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_access_profile_get_target_event_consumer_types(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::TargetEventConsumerTypesType ResultFromType;
    const ResultFromType result_from = obj->getTargetEventConsumerTypes();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_event_consumer_type_t *item_obj = reinterpret_cast<data_collection_model_event_consumer_type_t*>(new std::shared_ptr<EventConsumerType >(item));
        node = data_collection_model_event_consumer_type_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile, const ogs_list_t* p_target_event_consumer_types)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_target_event_consumer_types;
    typedef typename DataAccessProfile::TargetEventConsumerTypesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setTargetEventConsumerTypes(value)) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types_move(data_collection_model_data_access_profile_t *obj_data_access_profile, ogs_list_t* p_target_event_consumer_types)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_target_event_consumer_types;
    typedef typename DataAccessProfile::TargetEventConsumerTypesType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_target_event_consumer_types);
    if (!obj->setTargetEventConsumerTypes(std::move(value))) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_event_consumer_type_t* p_target_event_consumer_types)
{
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::TargetEventConsumerTypesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_target_event_consumer_types;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addTargetEventConsumerTypes(value);
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_event_consumer_type_t* p_target_event_consumer_types)
{
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::TargetEventConsumerTypesType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_target_event_consumer_types;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeTargetEventConsumerTypes(value);
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_target_event_consumer_types(data_collection_model_data_access_profile_t *obj_data_access_profile)
{   
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    obj->clearTargetEventConsumerTypes();
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_data_access_profile_get_parameters(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::ParametersType ResultFromType;
    const ResultFromType result_from = obj->getParameters();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile, const ogs_list_t* p_parameters)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_parameters;
    typedef typename DataAccessProfile::ParametersType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setParameters(value)) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters_move(data_collection_model_data_access_profile_t *obj_data_access_profile, ogs_list_t* p_parameters)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_parameters;
    typedef typename DataAccessProfile::ParametersType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_parameters);
    if (!obj->setParameters(std::move(value))) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile, char* p_parameters)
{
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::ParametersType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_parameters;

    ValueType value(value_from);

    obj->addParameters(value);
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile, const char* p_parameters)
{
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::ParametersType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_parameters;
    ValueType value(value_from);
    obj->removeParameters(value);
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_parameters(data_collection_model_data_access_profile_t *obj_data_access_profile)
{   
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    obj->clearParameters();
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_data_access_profile_time_access_restrictions_t* data_collection_model_data_access_profile_get_time_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::TimeAccessRestrictionsType ResultFromType;
    const ResultFromType result_from = obj->getTimeAccessRestrictions();
    const data_collection_model_data_access_profile_time_access_restrictions_t *result = reinterpret_cast<const data_collection_model_data_access_profile_time_access_restrictions_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_time_access_restrictions;
    typedef typename DataAccessProfile::TimeAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTimeAccessRestrictions(value)) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions_move(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_time_access_restrictions;
    typedef typename DataAccessProfile::TimeAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTimeAccessRestrictions(std::move(value))) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_data_access_profile_user_access_restrictions_t* data_collection_model_data_access_profile_get_user_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::UserAccessRestrictionsType ResultFromType;
    const ResultFromType result_from = obj->getUserAccessRestrictions();
    const data_collection_model_data_access_profile_user_access_restrictions_t *result = reinterpret_cast<const data_collection_model_data_access_profile_user_access_restrictions_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_user_access_restrictions;
    typedef typename DataAccessProfile::UserAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUserAccessRestrictions(value)) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions_move(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_user_access_restrictions;
    typedef typename DataAccessProfile::UserAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUserAccessRestrictions(std::move(value))) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_data_access_profile_location_access_restrictions_t* data_collection_model_data_access_profile_get_location_access_restrictions(const data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    const std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    typedef typename DataAccessProfile::LocationAccessRestrictionsType ResultFromType;
    const ResultFromType result_from = obj->getLocationAccessRestrictions();
    const data_collection_model_data_access_profile_location_access_restrictions_t *result = reinterpret_cast<const data_collection_model_data_access_profile_location_access_restrictions_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions(data_collection_model_data_access_profile_t *obj_data_access_profile, const data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_location_access_restrictions;
    typedef typename DataAccessProfile::LocationAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocationAccessRestrictions(value)) return NULL;
    return obj_data_access_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions_move(data_collection_model_data_access_profile_t *obj_data_access_profile, data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions)
{
    if (obj_data_access_profile == NULL) return NULL;

    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    const auto &value_from = p_location_access_restrictions;
    typedef typename DataAccessProfile::LocationAccessRestrictionsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocationAccessRestrictions(std::move(value))) return NULL;
    return obj_data_access_profile;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_access_profile_make_lnode(data_collection_model_data_access_profile_t *p_data_access_profile)
{
    return data_collection_lnode_create(p_data_access_profile, reinterpret_cast<void(*)(void*)>(data_collection_model_data_access_profile_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_access_profile_refcount(data_collection_model_data_access_profile_t *obj_data_access_profile)
{
    std::shared_ptr<DataAccessProfile > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile >*>(obj_data_access_profile);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

