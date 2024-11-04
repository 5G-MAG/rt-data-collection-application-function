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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_create(





















)
{
    return reinterpret_cast<data_collection_model_access_token_req_t*>(new std::shared_ptr<AccessTokenReq>(new AccessTokenReq(





















)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_create_copy(const data_collection_model_access_token_req_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_access_token_req_t*>(new std::shared_ptr<AccessTokenReq >(new AccessTokenReq(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_create_move(data_collection_model_access_token_req_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AccessTokenReq > *obj = reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_copy(data_collection_model_access_token_req_t *access_token_req, const data_collection_model_access_token_req_t *other)
{
    if (access_token_req) {
        std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(access_token_req);
        if (obj) {
            if (other) {
                const std::shared_ptr<AccessTokenReq > &other_obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(other);
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
                const std::shared_ptr<AccessTokenReq > &other_obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(other);
                if (other_obj) {
                    obj.reset(new AccessTokenReq(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        access_token_req = data_collection_model_access_token_req_create_copy(other);
    }
    return access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_move(data_collection_model_access_token_req_t *access_token_req, data_collection_model_access_token_req_t *other)
{
    std::shared_ptr<AccessTokenReq > *other_ptr = reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(other);

    if (access_token_req) {
        std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(access_token_req);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                access_token_req = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_access_token_req_free(data_collection_model_access_token_req_t *access_token_req)
{
    if (!access_token_req) return;
    delete reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(access_token_req);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_access_token_req_toJSON(const data_collection_model_access_token_req_t *access_token_req, bool as_request)
{
    if (!access_token_req) return NULL;
    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(access_token_req);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_access_token_req_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_is_equal_to(const data_collection_model_access_token_req_t *first, const data_collection_model_access_token_req_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AccessTokenReq > &obj2 = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AccessTokenReq > &obj1 = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_grant_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::Grant_typeType ResultFromType;
    const ResultFromType &result_from = obj->getGrantType();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_grant_type(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_grant_type)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_grant_type;
    typedef typename AccessTokenReq::Grant_typeType ValueType;

    ValueType value(value_from);

    if (!obj->setGrantType(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_grant_type_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_grant_type)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_grant_type;
    typedef typename AccessTokenReq::Grant_typeType ValueType;

    ValueType value(value_from);

    if (!obj->setGrantType(std::move(value))) return NULL;
    ogs_free
(p_grant_type);

    return obj_access_token_req;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::NfInstanceIdType ResultFromType;
    const ResultFromType &result_from = obj->getNfInstanceId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_instance_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_nf_instance_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_nf_instance_id;
    typedef typename AccessTokenReq::NfInstanceIdType ValueType;

    ValueType value(value_from);

    if (!obj->setNfInstanceId(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_instance_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_nf_instance_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_nf_instance_id;
    typedef typename AccessTokenReq::NfInstanceIdType ValueType;

    ValueType value(value_from);

    if (!obj->setNfInstanceId(std::move(value))) return NULL;
    ogs_free
(p_nf_instance_id);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_nf_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getNfType().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nf_type_t* data_collection_model_access_token_req_get_nf_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const data_collection_model_nf_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_nf_type_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::NfTypeType ResultFromType;
    const ResultFromType &result_from = obj->getNfType();
    const data_collection_model_nf_type_t *result = reinterpret_cast<const data_collection_model_nf_type_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_type(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_nf_type_t* p_nf_type)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_nf_type;
    typedef typename AccessTokenReq::NfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setNfType(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_nf_type_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_nf_type_t* p_nf_type)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_nf_type;
    typedef typename AccessTokenReq::NfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setNfType(std::move(value))) return NULL;
    data_collection_model_nf_type_free
(p_nf_type);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetNfType().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nf_type_t* data_collection_model_access_token_req_get_target_nf_type(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const data_collection_model_nf_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_nf_type_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetNfTypeType ResultFromType;
    const ResultFromType &result_from = obj->getTargetNfType();
    const data_collection_model_nf_type_t *result = reinterpret_cast<const data_collection_model_nf_type_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_type(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_nf_type_t* p_target_nf_type)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_type;
    typedef typename AccessTokenReq::TargetNfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTargetNfType(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_type_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_nf_type_t* p_target_nf_type)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_type;
    typedef typename AccessTokenReq::TargetNfTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTargetNfType(std::move(value))) return NULL;
    data_collection_model_nf_type_free
(p_target_nf_type);

    return obj_access_token_req;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_scope(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::ScopeType ResultFromType;
    const ResultFromType &result_from = obj->getScope();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_scope(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_scope)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_scope;
    typedef typename AccessTokenReq::ScopeType ValueType;

    ValueType value(value_from);

    if (!obj->setScope(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_scope_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_scope)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_scope;
    typedef typename AccessTokenReq::ScopeType ValueType;

    ValueType value(value_from);

    if (!obj->setScope(std::move(value))) return NULL;
    ogs_free
(p_scope);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetNfInstanceId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_target_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetNfInstanceIdType ResultFromType;
    const ResultFromType &result_from = obj->getTargetNfInstanceId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_instance_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nf_instance_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_instance_id;
    typedef typename AccessTokenReq::TargetNfInstanceIdType ValueType;

    ValueType value(value_from);

    if (!obj->setTargetNfInstanceId(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_instance_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nf_instance_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_instance_id;
    typedef typename AccessTokenReq::TargetNfInstanceIdType ValueType;

    ValueType value(value_from);

    if (!obj->setTargetNfInstanceId(std::move(value))) return NULL;
    ogs_free
(p_target_nf_instance_id);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_plmn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getRequesterPlmn().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_requester_plmn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::RequesterPlmnType ResultFromType;
    const ResultFromType &result_from = obj->getRequesterPlmn();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_t* p_requester_plmn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_plmn;
    typedef typename AccessTokenReq::RequesterPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRequesterPlmn(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_t* p_requester_plmn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_plmn;
    typedef typename AccessTokenReq::RequesterPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRequesterPlmn(std::move(value))) return NULL;
    data_collection_model_plmn_id_free
(p_requester_plmn);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_plmn_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getRequesterPlmnList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_plmn_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::RequesterPlmnListType ResultFromType;
    const ResultFromType &result_from = obj->getRequesterPlmnList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_plmn_id_t *item_obj = reinterpret_cast<data_collection_model_plmn_id_t*>(item.has_value()?new std::shared_ptr<PlmnId >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_plmn_id_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_plmn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_plmn_list;
    typedef typename AccessTokenReq::RequesterPlmnListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterPlmnList(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_plmn_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_plmn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_plmn_list;
    typedef typename AccessTokenReq::RequesterPlmnListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterPlmnList(std::move(value))) return NULL;
    data_collection_list_free
(p_requester_plmn_list);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_t* p_requester_plmn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterPlmnListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_plmn_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_plmn_id_free
(p_requester_plmn_list);
    if (value) obj->addRequesterPlmnList(value.value());
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_t* p_requester_plmn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterPlmnListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_plmn_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeRequesterPlmnList(value);
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_entry_requester_plmn_list(const data_collection_model_access_token_req_t *obj_access_token_req, size_t idx)
{
    if (!obj_access_token_req) {
        const data_collection_model_plmn_id_t *result = NULL;

        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_plmn_id_t *result = NULL;

        return result;
    }

    const AccessTokenReq::RequesterPlmnListType &container = obj->getRequesterPlmnList();
    if (!container.has_value()) {
        const data_collection_model_plmn_id_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_plmn_id_t *result = NULL;

        return result;
    }
    typedef typename AccessTokenReq::RequesterPlmnListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_plmn_list(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    obj->clearRequesterPlmnList();
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getRequesterSnssaiList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::RequesterSnssaiListType ResultFromType;
    const ResultFromType &result_from = obj->getRequesterSnssaiList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_snssai_t *item_obj = reinterpret_cast<data_collection_model_snssai_t*>(item.has_value()?new std::shared_ptr<Snssai >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_snssai_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_snssai_list;
    typedef typename AccessTokenReq::RequesterSnssaiListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterSnssaiList(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snssai_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_snssai_list;
    typedef typename AccessTokenReq::RequesterSnssaiListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterSnssaiList(std::move(value))) return NULL;
    data_collection_list_free
(p_requester_snssai_list);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_snssai_t* p_requester_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterSnssaiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_snssai_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_snssai_free
(p_requester_snssai_list);
    if (value) obj->addRequesterSnssaiList(value.value());
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_snssai_t* p_requester_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterSnssaiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_snssai_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeRequesterSnssaiList(value);
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_access_token_req_get_entry_requester_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req, size_t idx)
{
    if (!obj_access_token_req) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }

    const AccessTokenReq::RequesterSnssaiListType &container = obj->getRequesterSnssaiList();
    if (!container.has_value()) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }
    typedef typename AccessTokenReq::RequesterSnssaiListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    obj->clearRequesterSnssaiList();
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_fqdn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getRequesterFqdn().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_requester_fqdn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::RequesterFqdnType ResultFromType;
    const ResultFromType &result_from = obj->getRequesterFqdn();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_fqdn(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_requester_fqdn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_fqdn;
    typedef typename AccessTokenReq::RequesterFqdnType ValueType;

    ValueType value(value_from);

    if (!obj->setRequesterFqdn(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_fqdn_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_requester_fqdn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_fqdn;
    typedef typename AccessTokenReq::RequesterFqdnType ValueType;

    ValueType value(value_from);

    if (!obj->setRequesterFqdn(std::move(value))) return NULL;
    ogs_free
(p_requester_fqdn);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_snpn_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getRequesterSnpnList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_snpn_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::RequesterSnpnListType ResultFromType;
    const ResultFromType &result_from = obj->getRequesterSnpnList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_plmn_id_nid_t *item_obj = reinterpret_cast<data_collection_model_plmn_id_nid_t*>(item.has_value()?new std::shared_ptr<PlmnIdNid >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_plmn_id_nid_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_snpn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_snpn_list;
    typedef typename AccessTokenReq::RequesterSnpnListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterSnpnList(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_snpn_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_snpn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_snpn_list;
    typedef typename AccessTokenReq::RequesterSnpnListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterSnpnList(std::move(value))) return NULL;
    data_collection_list_free
(p_requester_snpn_list);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_nid_t* p_requester_snpn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterSnpnListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_snpn_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_plmn_id_nid_free
(p_requester_snpn_list);
    if (value) obj->addRequesterSnpnList(value.value());
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_nid_t* p_requester_snpn_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterSnpnListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_snpn_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeRequesterSnpnList(value);
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_nid_t* data_collection_model_access_token_req_get_entry_requester_snpn_list(const data_collection_model_access_token_req_t *obj_access_token_req, size_t idx)
{
    if (!obj_access_token_req) {
        const data_collection_model_plmn_id_nid_t *result = NULL;

        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_plmn_id_nid_t *result = NULL;

        return result;
    }

    const AccessTokenReq::RequesterSnpnListType &container = obj->getRequesterSnpnList();
    if (!container.has_value()) {
        const data_collection_model_plmn_id_nid_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_plmn_id_nid_t *result = NULL;

        return result;
    }
    typedef typename AccessTokenReq::RequesterSnpnListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_plmn_id_nid_t *result = reinterpret_cast<const data_collection_model_plmn_id_nid_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_snpn_list(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    obj->clearRequesterSnpnList();
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_plmn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetPlmn().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_access_token_req_get_target_plmn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetPlmnType ResultFromType;
    const ResultFromType &result_from = obj->getTargetPlmn();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_plmn(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_t* p_target_plmn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_plmn;
    typedef typename AccessTokenReq::TargetPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTargetPlmn(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_plmn_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_t* p_target_plmn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_plmn;
    typedef typename AccessTokenReq::TargetPlmnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTargetPlmn(std::move(value))) return NULL;
    data_collection_model_plmn_id_free
(p_target_plmn);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_snpn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetSnpn().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_nid_t* data_collection_model_access_token_req_get_target_snpn(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const data_collection_model_plmn_id_nid_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_plmn_id_nid_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetSnpnType ResultFromType;
    const ResultFromType &result_from = obj->getTargetSnpn();
    const data_collection_model_plmn_id_nid_t *result = reinterpret_cast<const data_collection_model_plmn_id_nid_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snpn(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_plmn_id_nid_t* p_target_snpn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_snpn;
    typedef typename AccessTokenReq::TargetSnpnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTargetSnpn(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snpn_move(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_plmn_id_nid_t* p_target_snpn)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_snpn;
    typedef typename AccessTokenReq::TargetSnpnType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTargetSnpn(std::move(value))) return NULL;
    data_collection_model_plmn_id_nid_free
(p_target_snpn);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetSnssaiList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_target_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetSnssaiListType ResultFromType;
    const ResultFromType &result_from = obj->getTargetSnssaiList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_snssai_t *item_obj = reinterpret_cast<data_collection_model_snssai_t*>(item.has_value()?new std::shared_ptr<Snssai >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_snssai_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_target_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_snssai_list;
    typedef typename AccessTokenReq::TargetSnssaiListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setTargetSnssaiList(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_snssai_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_target_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_snssai_list;
    typedef typename AccessTokenReq::TargetSnssaiListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setTargetSnssaiList(std::move(value))) return NULL;
    data_collection_list_free
(p_target_snssai_list);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_snssai_t* p_target_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::TargetSnssaiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_target_snssai_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_snssai_free
(p_target_snssai_list);
    if (value) obj->addTargetSnssaiList(value.value());
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_snssai_t* p_target_snssai_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::TargetSnssaiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_target_snssai_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeTargetSnssaiList(value);
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_access_token_req_get_entry_target_snssai_list(const data_collection_model_access_token_req_t *obj_access_token_req, size_t idx)
{
    if (!obj_access_token_req) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }

    const AccessTokenReq::TargetSnssaiListType &container = obj->getTargetSnssaiList();
    if (!container.has_value()) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_snssai_t *result = NULL;

        return result;
    }
    typedef typename AccessTokenReq::TargetSnssaiListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_target_snssai_list(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    obj->clearTargetSnssaiList();
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nsi_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetNsiList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_target_nsi_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetNsiListType ResultFromType;
    const ResultFromType &result_from = obj->getTargetNsiList();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_target_nsi_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nsi_list;
    typedef typename AccessTokenReq::TargetNsiListType ValueType;

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

    if (!obj->setTargetNsiList(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nsi_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_target_nsi_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nsi_list;
    typedef typename AccessTokenReq::TargetNsiListType ValueType;

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

    if (!obj->setTargetNsiList(std::move(value))) return NULL;
    data_collection_list_free
(p_target_nsi_list);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nsi_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::TargetNsiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_target_nsi_list;

    ValueType value(value_from);

    ogs_free
(p_target_nsi_list);
    if (value) obj->addTargetNsiList(value.value());
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nsi_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::TargetNsiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_target_nsi_list;
    ValueType value(value_from);

    obj->removeTargetNsiList(value);
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_entry_target_nsi_list(const data_collection_model_access_token_req_t *obj_access_token_req, size_t idx)
{
    if (!obj_access_token_req) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const AccessTokenReq::TargetNsiListType &container = obj->getTargetNsiList();
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
    typedef typename AccessTokenReq::TargetNsiListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_target_nsi_list(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    obj->clearTargetNsiList();
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_set_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetNfSetId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_target_nf_set_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetNfSetIdType ResultFromType;
    const ResultFromType &result_from = obj->getTargetNfSetId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_set_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nf_set_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_set_id;
    typedef typename AccessTokenReq::TargetNfSetIdType ValueType;

    ValueType value(value_from);

    if (!obj->setTargetNfSetId(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_set_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nf_set_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_set_id;
    typedef typename AccessTokenReq::TargetNfSetIdType ValueType;

    ValueType value(value_from);

    if (!obj->setTargetNfSetId(std::move(value))) return NULL;
    ogs_free
(p_target_nf_set_id);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_target_nf_service_set_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getTargetNfServiceSetId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_target_nf_service_set_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::TargetNfServiceSetIdType ResultFromType;
    const ResultFromType &result_from = obj->getTargetNfServiceSetId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_service_set_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_target_nf_service_set_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_service_set_id;
    typedef typename AccessTokenReq::TargetNfServiceSetIdType ValueType;

    ValueType value(value_from);

    if (!obj->setTargetNfServiceSetId(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_target_nf_service_set_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_target_nf_service_set_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_target_nf_service_set_id;
    typedef typename AccessTokenReq::TargetNfServiceSetIdType ValueType;

    ValueType value(value_from);

    if (!obj->setTargetNfServiceSetId(std::move(value))) return NULL;
    ogs_free
(p_target_nf_service_set_id);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_hnrf_access_token_uri(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getHnrfAccessTokenUri().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_hnrf_access_token_uri(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::HnrfAccessTokenUriType ResultFromType;
    const ResultFromType &result_from = obj->getHnrfAccessTokenUri();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_hnrf_access_token_uri(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_hnrf_access_token_uri)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_hnrf_access_token_uri;
    typedef typename AccessTokenReq::HnrfAccessTokenUriType ValueType;

    ValueType value(value_from);

    if (!obj->setHnrfAccessTokenUri(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_hnrf_access_token_uri_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_hnrf_access_token_uri)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_hnrf_access_token_uri;
    typedef typename AccessTokenReq::HnrfAccessTokenUriType ValueType;

    ValueType value(value_from);

    if (!obj->setHnrfAccessTokenUri(std::move(value))) return NULL;
    ogs_free
(p_hnrf_access_token_uri);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_source_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getSourceNfInstanceId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_source_nf_instance_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::SourceNfInstanceIdType ResultFromType;
    const ResultFromType &result_from = obj->getSourceNfInstanceId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_source_nf_instance_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_source_nf_instance_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_source_nf_instance_id;
    typedef typename AccessTokenReq::SourceNfInstanceIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSourceNfInstanceId(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_source_nf_instance_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_source_nf_instance_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_source_nf_instance_id;
    typedef typename AccessTokenReq::SourceNfInstanceIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSourceNfInstanceId(std::move(value))) return NULL;
    ogs_free
(p_source_nf_instance_id);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_vendor_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getVendorId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_req_get_vendor_id(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::VendorIdType ResultFromType;
    const ResultFromType &result_from = obj->getVendorId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_vendor_id(data_collection_model_access_token_req_t *obj_access_token_req, const char* p_vendor_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_vendor_id;
    typedef typename AccessTokenReq::VendorIdType ValueType;

    ValueType value(value_from);

    if (!obj->setVendorId(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_vendor_id_move(data_collection_model_access_token_req_t *obj_access_token_req, char* p_vendor_id)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_vendor_id;
    typedef typename AccessTokenReq::VendorIdType ValueType;

    ValueType value(value_from);

    if (!obj->setVendorId(std::move(value))) return NULL;
    ogs_free
(p_vendor_id);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_analytics_ids(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getAnalyticsIds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_analytics_ids(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::AnalyticsIdsType ResultFromType;
    const ResultFromType &result_from = obj->getAnalyticsIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_nwdaf_event_t *item_obj = reinterpret_cast<data_collection_model_nwdaf_event_t*>(item.has_value()?new std::shared_ptr<NwdafEvent >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_nwdaf_event_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_analytics_ids)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_analytics_ids;
    typedef typename AccessTokenReq::AnalyticsIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setAnalyticsIds(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_analytics_ids_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_analytics_ids)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_analytics_ids;
    typedef typename AccessTokenReq::AnalyticsIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setAnalyticsIds(std::move(value))) return NULL;
    data_collection_list_free
(p_analytics_ids);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_nwdaf_event_t* p_analytics_ids)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::AnalyticsIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_analytics_ids;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_nwdaf_event_free
(p_analytics_ids);
    if (value) obj->addAnalyticsIds(value.value());
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_nwdaf_event_t* p_analytics_ids)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::AnalyticsIdsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_analytics_ids;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeAnalyticsIds(value);
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nwdaf_event_t* data_collection_model_access_token_req_get_entry_analytics_ids(const data_collection_model_access_token_req_t *obj_access_token_req, size_t idx)
{
    if (!obj_access_token_req) {
        const data_collection_model_nwdaf_event_t *result = NULL;

        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_nwdaf_event_t *result = NULL;

        return result;
    }

    const AccessTokenReq::AnalyticsIdsType &container = obj->getAnalyticsIds();
    if (!container.has_value()) {
        const data_collection_model_nwdaf_event_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_nwdaf_event_t *result = NULL;

        return result;
    }
    typedef typename AccessTokenReq::AnalyticsIdsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_nwdaf_event_t *result = reinterpret_cast<const data_collection_model_nwdaf_event_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_analytics_ids(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    obj->clearAnalyticsIds();
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_req_has_requester_inter_ind_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return false;

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return false;

    return obj->getRequesterInterIndList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_access_token_req_get_requester_inter_ind_list(const data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename AccessTokenReq::RequesterInterIndListType ResultFromType;
    const ResultFromType &result_from = obj->getRequesterInterIndList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_ml_model_inter_ind_t *item_obj = reinterpret_cast<data_collection_model_ml_model_inter_ind_t*>(item.has_value()?new std::shared_ptr<MlModelInterInd >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_ml_model_inter_ind_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req, const ogs_list_t* p_requester_inter_ind_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_inter_ind_list;
    typedef typename AccessTokenReq::RequesterInterIndListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterInterIndList(value)) return NULL;

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_set_requester_inter_ind_list_move(data_collection_model_access_token_req_t *obj_access_token_req, ogs_list_t* p_requester_inter_ind_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    const auto &value_from = p_requester_inter_ind_list;
    typedef typename AccessTokenReq::RequesterInterIndListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRequesterInterIndList(std::move(value))) return NULL;
    data_collection_list_free
(p_requester_inter_ind_list);

    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_add_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req, data_collection_model_ml_model_inter_ind_t* p_requester_inter_ind_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterInterIndListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_requester_inter_ind_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_ml_model_inter_ind_free
(p_requester_inter_ind_list);
    if (value) obj->addRequesterInterIndList(value.value());
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_remove_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req, const data_collection_model_ml_model_inter_ind_t* p_requester_inter_ind_list)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    typedef typename AccessTokenReq::RequesterInterIndListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_requester_inter_ind_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeRequesterInterIndList(value);
    return obj_access_token_req;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ml_model_inter_ind_t* data_collection_model_access_token_req_get_entry_requester_inter_ind_list(const data_collection_model_access_token_req_t *obj_access_token_req, size_t idx)
{
    if (!obj_access_token_req) {
        const data_collection_model_ml_model_inter_ind_t *result = NULL;

        return result;
    }

    const std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) {
        const data_collection_model_ml_model_inter_ind_t *result = NULL;

        return result;
    }

    const AccessTokenReq::RequesterInterIndListType &container = obj->getRequesterInterIndList();
    if (!container.has_value()) {
        const data_collection_model_ml_model_inter_ind_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_ml_model_inter_ind_t *result = NULL;

        return result;
    }
    typedef typename AccessTokenReq::RequesterInterIndListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_ml_model_inter_ind_t *result = reinterpret_cast<const data_collection_model_ml_model_inter_ind_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_req_t *data_collection_model_access_token_req_clear_requester_inter_ind_list(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return NULL;

    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    if (!obj) return NULL;

    obj->clearRequesterInterIndList();
    return obj_access_token_req;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_access_token_req_make_lnode(data_collection_model_access_token_req_t *p_access_token_req)
{
    return data_collection_lnode_create(p_access_token_req, reinterpret_cast<void(*)(void*)>(data_collection_model_access_token_req_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_access_token_req_refcount(data_collection_model_access_token_req_t *obj_access_token_req)
{
    if (!obj_access_token_req) return 0l;
    std::shared_ptr<AccessTokenReq > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenReq >*>(obj_access_token_req);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

