/**********************************************************************************************************************************
 * AccessTokenReq - C interface to the AccessTokenReq object
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

/*#include "AccessTokenReq.h" already included by data-collection-sp/data-collection.h */
#include "AccessTokenReq-internal.h"
#include "openapi/model/AccessTokenReq.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_create(





















)
{
    return reinterpret_cast<data_collection_model_access_token_req_t*>(new std::shared_ptr<AccessTokenReq>(new AccessTokenReq(





















)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_create_copy(const data_collection_model_access_token_req_t *other)
{
    return reinterpret_cast<data_collection_model_access_token_req_t*>(new std::shared_ptr<AccessTokenReq >(new AccessTokenReq(**reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_create_move(data_collection_model_access_token_req_t *other)
{
    return reinterpret_cast<data_collection_model_access_token_req_t*>(new std::shared_ptr<AccessTokenReq >(std::move(*reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_copy(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_access_token_req_t *other)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(access_token_req);
    *obj = **reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(other);
    return access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_access_token_req_t *other)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(access_token_req);
    obj = std::move(*reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(other));
    return access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_access_token_req_free(data_collection_model_access_token_req_t *access_token_req)
{
    delete reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(access_token_req);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_access_token_req_toJSON(const data_collection_model_access_token_req_t *access_token_req, bool as_request)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(access_token_req);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_access_token_req_t*>(new std::shared_ptr<AccessTokenReq >(new AccessTokenReq(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_access_token_req_is_equal_to(const data_collection_model_access_token_req_t *first, const data_collection_model_access_token_req_t *second)
{
    const std::shared_ptr<AccessTokenReq > &obj1 = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(first);
    const std::shared_ptr<AccessTokenReq > &obj2 = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_grant_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::Grant_typeType ResultFromType;
    const ResultFromType result_from = obj->getGrantType();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_grant_type(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_grant_type)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_grant_type;
    typedef typename AccessTokenReq::Grant_typeType ValueType;

    ValueType value(value_from);
    if (!obj->setGrantType(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_grant_type_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_grant_type)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_grant_type;
    typedef typename AccessTokenReq::Grant_typeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setGrantType(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::NfInstanceIdType ResultFromType;
    const ResultFromType result_from = obj->getNfInstanceId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_instance_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_nf_instance_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_nf_instance_id;
    typedef typename AccessTokenReq::NfInstanceIdType ValueType;

    ValueType value(value_from);
    if (!obj->setNfInstanceId(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_instance_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_nf_instance_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_nf_instance_id;
    typedef typename AccessTokenReq::NfInstanceIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNfInstanceId(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_nf_type_t* data_collection_model_access_token_req_get_nf_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::NfTypeType ResultFromType;
    const ResultFromType result_from = obj->getNfType();
    const data_collection_model_nf_type_t *result = reinterpret_cast<const data_collection_model_nf_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_type(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_nf_type_t* p_nf_type)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_nf_type;
    typedef typename AccessTokenReq::NfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNfType(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_type_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_nf_type_t* p_nf_type)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_nf_type;
    typedef typename AccessTokenReq::NfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNfType(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_nf_type_t* data_collection_model_access_token_req_get_target_nf_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetNfTypeType ResultFromType;
    const ResultFromType result_from = obj->getTargetNfType();
    const data_collection_model_nf_type_t *result = reinterpret_cast<const data_collection_model_nf_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_type(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_nf_type_t* p_target_nf_type)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_type;
    typedef typename AccessTokenReq::TargetNfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTargetNfType(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_type_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_nf_type_t* p_target_nf_type)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_type;
    typedef typename AccessTokenReq::TargetNfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTargetNfType(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_scope(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::ScopeType ResultFromType;
    const ResultFromType result_from = obj->getScope();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_scope(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_scope)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_scope;
    typedef typename AccessTokenReq::ScopeType ValueType;

    ValueType value(value_from);
    if (!obj->setScope(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_scope_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_scope)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_scope;
    typedef typename AccessTokenReq::ScopeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setScope(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_target_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetNfInstanceIdType ResultFromType;
    const ResultFromType result_from = obj->getTargetNfInstanceId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_instance_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nf_instance_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_instance_id;
    typedef typename AccessTokenReq::TargetNfInstanceIdType ValueType;

    ValueType value(value_from);
    if (!obj->setTargetNfInstanceId(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_instance_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nf_instance_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_instance_id;
    typedef typename AccessTokenReq::TargetNfInstanceIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTargetNfInstanceId(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_requester_plmn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterPlmnType ResultFromType;
    const ResultFromType result_from = obj->getRequesterPlmn();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_t* p_requester_plmn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_plmn;
    typedef typename AccessTokenReq::RequesterPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRequesterPlmn(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_t* p_requester_plmn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_plmn;
    typedef typename AccessTokenReq::RequesterPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRequesterPlmn(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_access_token_req_get_requester_plmn_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterPlmnListType ResultFromType;
    const ResultFromType result_from = obj->getRequesterPlmnList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_plmn_id_t *item_obj = reinterpret_cast<data_collection_model_plmn_id_t*>(new std::shared_ptr<PlmnId >(item));
        node = data_collection_model_plmn_id_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_plmn_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_plmn_list;
    typedef typename AccessTokenReq::RequesterPlmnListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRequesterPlmnList(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_plmn_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_plmn_list;
    typedef typename AccessTokenReq::RequesterPlmnListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_requester_plmn_list);
    if (!obj->setRequesterPlmnList(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_t* p_requester_plmn_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterPlmnListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_plmn_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRequesterPlmnList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_t* p_requester_plmn_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterPlmnListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_plmn_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRequesterPlmnList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req)
{   
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    obj->clearRequesterPlmnList();
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_access_token_req_get_requester_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterSnssaiListType ResultFromType;
    const ResultFromType result_from = obj->getRequesterSnssaiList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_snssai_t *item_obj = reinterpret_cast<data_collection_model_snssai_t*>(new std::shared_ptr<Snssai >(item));
        node = data_collection_model_snssai_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_snssai_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_snssai_list;
    typedef typename AccessTokenReq::RequesterSnssaiListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRequesterSnssaiList(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snssai_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_snssai_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_snssai_list;
    typedef typename AccessTokenReq::RequesterSnssaiListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_requester_snssai_list);
    if (!obj->setRequesterSnssaiList(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_snssai_t* p_requester_snssai_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterSnssaiListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_snssai_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRequesterSnssaiList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_snssai_t* p_requester_snssai_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterSnssaiListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_snssai_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRequesterSnssaiList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req)
{   
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    obj->clearRequesterSnssaiList();
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_requester_fqdn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterFqdnType ResultFromType;
    const ResultFromType result_from = obj->getRequesterFqdn();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_fqdn(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_requester_fqdn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_fqdn;
    typedef typename AccessTokenReq::RequesterFqdnType ValueType;

    ValueType value(value_from);
    if (!obj->setRequesterFqdn(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_fqdn_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_requester_fqdn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_fqdn;
    typedef typename AccessTokenReq::RequesterFqdnType ValueType;

    ValueType value(value_from);
    
    if (!obj->setRequesterFqdn(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_access_token_req_get_requester_snpn_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterSnpnListType ResultFromType;
    const ResultFromType result_from = obj->getRequesterSnpnList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_plmn_id_nid_t *item_obj = reinterpret_cast<data_collection_model_plmn_id_nid_t*>(new std::shared_ptr<PlmnIdNid >(item));
        node = data_collection_model_plmn_id_nid_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_snpn_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_snpn_list;
    typedef typename AccessTokenReq::RequesterSnpnListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRequesterSnpnList(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snpn_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_snpn_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_snpn_list;
    typedef typename AccessTokenReq::RequesterSnpnListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_requester_snpn_list);
    if (!obj->setRequesterSnpnList(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_nid_t* p_requester_snpn_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterSnpnListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_snpn_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRequesterSnpnList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_nid_t* p_requester_snpn_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterSnpnListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_snpn_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRequesterSnpnList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req)
{   
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    obj->clearRequesterSnpnList();
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_target_plmn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetPlmnType ResultFromType;
    const ResultFromType result_from = obj->getTargetPlmn();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_plmn(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_t* p_target_plmn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_plmn;
    typedef typename AccessTokenReq::TargetPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTargetPlmn(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_plmn_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_t* p_target_plmn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_plmn;
    typedef typename AccessTokenReq::TargetPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTargetPlmn(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_plmn_id_nid_t* data_collection_model_access_token_req_get_target_snpn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetSnpnType ResultFromType;
    const ResultFromType result_from = obj->getTargetSnpn();
    const data_collection_model_plmn_id_nid_t *result = reinterpret_cast<const data_collection_model_plmn_id_nid_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snpn(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_nid_t* p_target_snpn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_snpn;
    typedef typename AccessTokenReq::TargetSnpnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setTargetSnpn(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snpn_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_nid_t* p_target_snpn)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_snpn;
    typedef typename AccessTokenReq::TargetSnpnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setTargetSnpn(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_access_token_req_get_target_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetSnssaiListType ResultFromType;
    const ResultFromType result_from = obj->getTargetSnssaiList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_snssai_t *item_obj = reinterpret_cast<data_collection_model_snssai_t*>(new std::shared_ptr<Snssai >(item));
        node = data_collection_model_snssai_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_target_snssai_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_snssai_list;
    typedef typename AccessTokenReq::TargetSnssaiListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setTargetSnssaiList(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snssai_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_target_snssai_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_snssai_list;
    typedef typename AccessTokenReq::TargetSnssaiListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_target_snssai_list);
    if (!obj->setTargetSnssaiList(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_snssai_t* p_target_snssai_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetSnssaiListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_target_snssai_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addTargetSnssaiList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_snssai_t* p_target_snssai_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetSnssaiListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_target_snssai_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeTargetSnssaiList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req)
{   
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    obj->clearTargetSnssaiList();
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_access_token_req_get_target_nsi_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetNsiListType ResultFromType;
    const ResultFromType result_from = obj->getTargetNsiList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_target_nsi_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nsi_list;
    typedef typename AccessTokenReq::TargetNsiListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setTargetNsiList(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nsi_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_target_nsi_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nsi_list;
    typedef typename AccessTokenReq::TargetNsiListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_target_nsi_list);
    if (!obj->setTargetNsiList(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nsi_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetNsiListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_target_nsi_list;

    ValueType value(value_from);

    obj->addTargetNsiList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nsi_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetNsiListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_target_nsi_list;
    ValueType value(value_from);
    obj->removeTargetNsiList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req)
{   
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    obj->clearTargetNsiList();
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_target_nf_set_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetNfSetIdType ResultFromType;
    const ResultFromType result_from = obj->getTargetNfSetId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_set_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nf_set_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_set_id;
    typedef typename AccessTokenReq::TargetNfSetIdType ValueType;

    ValueType value(value_from);
    if (!obj->setTargetNfSetId(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_set_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nf_set_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_set_id;
    typedef typename AccessTokenReq::TargetNfSetIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTargetNfSetId(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_target_nf_service_set_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::TargetNfServiceSetIdType ResultFromType;
    const ResultFromType result_from = obj->getTargetNfServiceSetId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_service_set_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nf_service_set_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_service_set_id;
    typedef typename AccessTokenReq::TargetNfServiceSetIdType ValueType;

    ValueType value(value_from);
    if (!obj->setTargetNfServiceSetId(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_service_set_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nf_service_set_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_target_nf_service_set_id;
    typedef typename AccessTokenReq::TargetNfServiceSetIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTargetNfServiceSetId(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_hnrf_access_token_uri(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::HnrfAccessTokenUriType ResultFromType;
    const ResultFromType result_from = obj->getHnrfAccessTokenUri();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_hnrf_access_token_uri(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_hnrf_access_token_uri)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_hnrf_access_token_uri;
    typedef typename AccessTokenReq::HnrfAccessTokenUriType ValueType;

    ValueType value(value_from);
    if (!obj->setHnrfAccessTokenUri(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_hnrf_access_token_uri_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_hnrf_access_token_uri)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_hnrf_access_token_uri;
    typedef typename AccessTokenReq::HnrfAccessTokenUriType ValueType;

    ValueType value(value_from);
    
    if (!obj->setHnrfAccessTokenUri(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_source_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::SourceNfInstanceIdType ResultFromType;
    const ResultFromType result_from = obj->getSourceNfInstanceId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_source_nf_instance_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_source_nf_instance_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_source_nf_instance_id;
    typedef typename AccessTokenReq::SourceNfInstanceIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSourceNfInstanceId(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_source_nf_instance_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_source_nf_instance_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_source_nf_instance_id;
    typedef typename AccessTokenReq::SourceNfInstanceIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSourceNfInstanceId(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_req_get_vendor_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::VendorIdType ResultFromType;
    const ResultFromType result_from = obj->getVendorId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_vendor_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_vendor_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_vendor_id;
    typedef typename AccessTokenReq::VendorIdType ValueType;

    ValueType value(value_from);
    if (!obj->setVendorId(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_vendor_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_vendor_id)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_vendor_id;
    typedef typename AccessTokenReq::VendorIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setVendorId(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_access_token_req_get_analytics_ids(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::AnalyticsIdsType ResultFromType;
    const ResultFromType result_from = obj->getAnalyticsIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_nwdaf_event_t *item_obj = reinterpret_cast<data_collection_model_nwdaf_event_t*>(new std::shared_ptr<NwdafEvent >(item));
        node = data_collection_model_nwdaf_event_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_analytics_ids)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_analytics_ids;
    typedef typename AccessTokenReq::AnalyticsIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setAnalyticsIds(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_analytics_ids_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_analytics_ids)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_analytics_ids;
    typedef typename AccessTokenReq::AnalyticsIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_analytics_ids);
    if (!obj->setAnalyticsIds(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_nwdaf_event_t* p_analytics_ids)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::AnalyticsIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_analytics_ids;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addAnalyticsIds(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_nwdaf_event_t* p_analytics_ids)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::AnalyticsIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_analytics_ids;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeAnalyticsIds(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req)
{   
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    obj->clearAnalyticsIds();
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_access_token_req_get_requester_inter_ind_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterInterIndListType ResultFromType;
    const ResultFromType result_from = obj->getRequesterInterIndList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_ml_model_inter_ind_t *item_obj = reinterpret_cast<data_collection_model_ml_model_inter_ind_t*>(new std::shared_ptr<MlModelInterInd >(item));
        node = data_collection_model_ml_model_inter_ind_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_inter_ind_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_inter_ind_list;
    typedef typename AccessTokenReq::RequesterInterIndListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setRequesterInterIndList(value)) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_inter_ind_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_inter_ind_list)
{
    if (obj_access_token_req == NULL) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    const auto &value_from = p_requester_inter_ind_list;
    typedef typename AccessTokenReq::RequesterInterIndListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_requester_inter_ind_list);
    if (!obj->setRequesterInterIndList(std::move(value))) return NULL;
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_ml_model_inter_ind_t* p_requester_inter_ind_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterInterIndListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_inter_ind_list;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addRequesterInterIndList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_ml_model_inter_ind_t* p_requester_inter_ind_list)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    typedef typename AccessTokenReq::RequesterInterIndListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_inter_ind_list;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeRequesterInterIndList(value);
    return obj_access_token_req;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req)
{   
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    obj->clearRequesterInterIndList();
    return obj_access_token_req;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_access_token_req_make_lnode(data_collection_model_access_token_req_t *p_access_token_req)
{
    return data_collection_lnode_create(p_access_token_req, reinterpret_cast<void(*)(void*)>(data_collection_model_access_token_req_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_access_token_req_refcount(data_collection_model_access_token_req_t *obj_access_token_req)
{
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

