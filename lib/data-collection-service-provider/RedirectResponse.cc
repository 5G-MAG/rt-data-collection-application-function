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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_create(


)
{
    return reinterpret_cast<data_collection_model_redirect_response_t*>(new std::shared_ptr<RedirectResponse>(new RedirectResponse(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_copy(const data_collection_model_redirect_response_t *other)
{
    return reinterpret_cast<data_collection_model_redirect_response_t*>(new std::shared_ptr<RedirectResponse >(new RedirectResponse(**reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_move(data_collection_model_redirect_response_t *other)
{
    return reinterpret_cast<data_collection_model_redirect_response_t*>(new std::shared_ptr<RedirectResponse >(std::move(*reinterpret_cast<std::shared_ptr<RedirectResponse >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_copy(data_collection_model_redirect_response_t *redirect_response, const data_collection_model_redirect_response_t *other)
{
    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(redirect_response);
    *obj = **reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(other);
    return redirect_response;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_move(data_collection_model_redirect_response_t *redirect_response, data_collection_model_redirect_response_t *other)
{
    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(redirect_response);
    obj = std::move(*reinterpret_cast<std::shared_ptr<RedirectResponse >*>(other));
    return redirect_response;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_redirect_response_free(data_collection_model_redirect_response_t *redirect_response)
{
    delete reinterpret_cast<std::shared_ptr<RedirectResponse >*>(redirect_response);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_redirect_response_toJSON(const data_collection_model_redirect_response_t *redirect_response, bool as_request)
{
    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(redirect_response);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_redirect_response_get_cause(const data_collection_model_redirect_response_t *obj_redirect_response)
{
    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    typedef typename RedirectResponse::CauseType ResultFromType;
    const ResultFromType result_from = obj->getCause();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause(data_collection_model_redirect_response_t *obj_redirect_response, const char* p_cause)
{
    if (obj_redirect_response == NULL) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    const auto &value_from = p_cause;
    typedef typename RedirectResponse::CauseType ValueType;

    ValueType value(value_from);
    if (!obj->setCause(value)) return NULL;
    return obj_redirect_response;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause_move(data_collection_model_redirect_response_t *obj_redirect_response, char* p_cause)
{
    if (obj_redirect_response == NULL) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    const auto &value_from = p_cause;
    typedef typename RedirectResponse::CauseType ValueType;

    ValueType value(value_from);
    
    if (!obj->setCause(std::move(value))) return NULL;
    return obj_redirect_response;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_redirect_response_get_target_scp(const data_collection_model_redirect_response_t *obj_redirect_response)
{
    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    typedef typename RedirectResponse::TargetScpType ResultFromType;
    const ResultFromType result_from = obj->getTargetScp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp(data_collection_model_redirect_response_t *obj_redirect_response, const char* p_target_scp)
{
    if (obj_redirect_response == NULL) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    const auto &value_from = p_target_scp;
    typedef typename RedirectResponse::TargetScpType ValueType;

    ValueType value(value_from);
    if (!obj->setTargetScp(value)) return NULL;
    return obj_redirect_response;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp_move(data_collection_model_redirect_response_t *obj_redirect_response, char* p_target_scp)
{
    if (obj_redirect_response == NULL) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    const auto &value_from = p_target_scp;
    typedef typename RedirectResponse::TargetScpType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTargetScp(std::move(value))) return NULL;
    return obj_redirect_response;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_redirect_response_get_target_sepp(const data_collection_model_redirect_response_t *obj_redirect_response)
{
    const std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<const std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    typedef typename RedirectResponse::TargetSeppType ResultFromType;
    const ResultFromType result_from = obj->getTargetSepp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp(data_collection_model_redirect_response_t *obj_redirect_response, const char* p_target_sepp)
{
    if (obj_redirect_response == NULL) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    const auto &value_from = p_target_sepp;
    typedef typename RedirectResponse::TargetSeppType ValueType;

    ValueType value(value_from);
    if (!obj->setTargetSepp(value)) return NULL;
    return obj_redirect_response;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp_move(data_collection_model_redirect_response_t *obj_redirect_response, char* p_target_sepp)
{
    if (obj_redirect_response == NULL) return NULL;

    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    const auto &value_from = p_target_sepp;
    typedef typename RedirectResponse::TargetSeppType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTargetSepp(std::move(value))) return NULL;
    return obj_redirect_response;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_redirect_response_make_lnode(data_collection_model_redirect_response_t *p_redirect_response)
{
    return data_collection_lnode_create(p_redirect_response, reinterpret_cast<void(*)(void*)>(data_collection_model_redirect_response_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_redirect_response_refcount(data_collection_model_redirect_response_t *obj_redirect_response)
{
    std::shared_ptr<RedirectResponse > &obj = *reinterpret_cast<std::shared_ptr<RedirectResponse >*>(obj_redirect_response);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

