/**********************************************************************************************************************************
 * RedirectResponse - C interface to the RedirectResponse object
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

/*#include "RedirectResponse.h" already included by data-collection-sp/data-collection.h */
#include "RedirectResponse-internal.h"
#include "openapi/model/RedirectResponse.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create(


)
{
    return reinterpret_cast<data_collection_model_redirect_response_t*>(new std::shared_ptr<RedirectResponse>(new RedirectResponse(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_copy(const data_collection_model_redirect_response_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_redirect_response_t*>(new std::shared_ptr<RedirectResponse >(new RedirectResponse(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_move(data_collection_model_redirect_response_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RedirectResponse > *obj = reinterpret_cast<std::shared_ptr<RedirectResponse >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_copy(data_collection_model_redirect_response_t *redirect_response, const data_collection_model_redirect_response_t *other)
{
    if (redirect_response) {
        std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(redirect_response);
        if (obj) {
            if (other) {
                const std::shared_ptr<RedirectResponse > &other_obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(other);
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
                const std::shared_ptr<RedirectResponse > &other_obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(other);
                if (other_obj) {
                    obj.reset(new RedirectResponse(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        redirect_response = data_collection_model_redirect_response_create_copy(other);
    }
    return redirect_response;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_move(data_collection_model_redirect_response_t *redirect_response, data_collection_model_redirect_response_t *other)
{
    std::shared_ptr<RedirectResponse > *other_ptr = reinterpret_cast<std::shared_ptr<RedirectResponse >*>(other);

    if (redirect_response) {
        std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(redirect_response);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                redirect_response = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return redirect_response;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_redirect_response_free(data_collection_model_redirect_response_t *redirect_response)
{
    if (!redirect_response) return;
    delete reinterpret_cast<std::shared_ptr<RedirectResponse >*>(redirect_response);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_redirect_response_toJSON(const data_collection_model_redirect_response_t *redirect_response, bool as_request)
{
    if (!redirect_response) return NULL;
    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(redirect_response);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_redirect_response_t*>(new std::shared_ptr<RedirectResponse >(new RedirectResponse(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_redirect_response_is_equal_to(const data_collection_model_redirect_response_t *first, const data_collection_model_redirect_response_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RedirectResponse > &obj2 = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RedirectResponse > &obj1 = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_cause(const data_collection_model_redirect_response_t *obj_redirect_response)
{
    if (!obj_redirect_response) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename RedirectResponse::CauseType ResultFromType;
    const ResultFromType result_from = obj->getCause();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause(data_collection_model_redirect_response_t *obj_redirect_response, const char* p_cause)
{
    if (!obj_redirect_response) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) return NULL;

    const auto &value_from = p_cause;
    typedef typename RedirectResponse::CauseType ValueType;

    ValueType value(value_from);
    if (!obj->setCause(value)) return NULL;

    return obj_redirect_response;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause_move(data_collection_model_redirect_response_t *obj_redirect_response, char* p_cause)
{
    if (!obj_redirect_response) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) return NULL;

    const auto &value_from = p_cause;
    typedef typename RedirectResponse::CauseType ValueType;

    ValueType value(value_from);
    
    if (!obj->setCause(std::move(value))) return NULL;

    return obj_redirect_response;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_target_scp(const data_collection_model_redirect_response_t *obj_redirect_response)
{
    if (!obj_redirect_response) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename RedirectResponse::TargetScpType ResultFromType;
    const ResultFromType result_from = obj->getTargetScp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp(data_collection_model_redirect_response_t *obj_redirect_response, const char* p_target_scp)
{
    if (!obj_redirect_response) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) return NULL;

    const auto &value_from = p_target_scp;
    typedef typename RedirectResponse::TargetScpType ValueType;

    ValueType value(value_from);
    if (!obj->setTargetScp(value)) return NULL;

    return obj_redirect_response;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp_move(data_collection_model_redirect_response_t *obj_redirect_response, char* p_target_scp)
{
    if (!obj_redirect_response) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) return NULL;

    const auto &value_from = p_target_scp;
    typedef typename RedirectResponse::TargetScpType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTargetScp(std::move(value))) return NULL;

    return obj_redirect_response;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_target_sepp(const data_collection_model_redirect_response_t *obj_redirect_response)
{
    if (!obj_redirect_response) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename RedirectResponse::TargetSeppType ResultFromType;
    const ResultFromType result_from = obj->getTargetSepp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp(data_collection_model_redirect_response_t *obj_redirect_response, const char* p_target_sepp)
{
    if (!obj_redirect_response) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) return NULL;

    const auto &value_from = p_target_sepp;
    typedef typename RedirectResponse::TargetSeppType ValueType;

    ValueType value(value_from);
    if (!obj->setTargetSepp(value)) return NULL;

    return obj_redirect_response;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp_move(data_collection_model_redirect_response_t *obj_redirect_response, char* p_target_sepp)
{
    if (!obj_redirect_response) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    if (!obj) return NULL;

    const auto &value_from = p_target_sepp;
    typedef typename RedirectResponse::TargetSeppType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTargetSepp(std::move(value))) return NULL;

    return obj_redirect_response;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_redirect_response_make_lnode(data_collection_model_redirect_response_t *p_redirect_response)
{
    return data_collection_lnode_create(p_redirect_response, reinterpret_cast<void(*)(void*)>(data_collection_model_redirect_response_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_redirect_response_refcount(data_collection_model_redirect_response_t *obj_redirect_response)
{
    if (!obj_redirect_response) return 0l;
    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

