/**********************************************************************************************************************************
 * AccessTokenErr - C interface to the AccessTokenErr object
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

/*#include "AccessTokenErr.h" already included by data-collection-sp/data-collection.h */
#include "AccessTokenErr-internal.h"
#include "openapi/model/AccessTokenErr.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_create(


)
{
    return reinterpret_cast<data_collection_model_access_token_err_t*>(new std::shared_ptr<AccessTokenErr>(new AccessTokenErr(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_create_copy(const data_collection_model_access_token_err_t *other)
{
    return reinterpret_cast<data_collection_model_access_token_err_t*>(new std::shared_ptr<AccessTokenErr >(new AccessTokenErr(**reinterpret_cast<const std::shared_ptr<AccessTokenErr >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_create_move(data_collection_model_access_token_err_t *other)
{
    return reinterpret_cast<data_collection_model_access_token_err_t*>(new std::shared_ptr<AccessTokenErr >(std::move(*reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_copy(data_collection_model_access_token_err_t *access_token_err, const data_collection_model_access_token_err_t *other)
{
    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(access_token_err);
    *obj = **reinterpret_cast<const std::shared_ptr<AccessTokenErr >*>(other);
    return access_token_err;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_move(data_collection_model_access_token_err_t *access_token_err, data_collection_model_access_token_err_t *other)
{
    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(access_token_err);
    obj = std::move(*reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(other));
    return access_token_err;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_access_token_err_free(data_collection_model_access_token_err_t *access_token_err)
{
    delete reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(access_token_err);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_access_token_err_toJSON(const data_collection_model_access_token_err_t *access_token_err, bool as_request)
{
    const std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenErr >*>(access_token_err);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_access_token_err_t*>(new std::shared_ptr<AccessTokenErr >(new AccessTokenErr(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_err_get_error(const data_collection_model_access_token_err_t *obj_access_token_err)
{
    const std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    typedef typename AccessTokenErr::ErrorType ResultFromType;
    const ResultFromType result_from = obj->getError();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error(data_collection_model_access_token_err_t *obj_access_token_err, const char* p_error)
{
    if (obj_access_token_err == NULL) return NULL;

    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    const auto &value_from = p_error;
    typedef typename AccessTokenErr::ErrorType ValueType;

    ValueType value(value_from);
    if (!obj->setError(value)) return NULL;
    return obj_access_token_err;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_move(data_collection_model_access_token_err_t *obj_access_token_err, char* p_error)
{
    if (obj_access_token_err == NULL) return NULL;

    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    const auto &value_from = p_error;
    typedef typename AccessTokenErr::ErrorType ValueType;

    ValueType value(value_from);
    
    if (!obj->setError(std::move(value))) return NULL;
    return obj_access_token_err;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_err_get_error_description(const data_collection_model_access_token_err_t *obj_access_token_err)
{
    const std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    typedef typename AccessTokenErr::Error_descriptionType ResultFromType;
    const ResultFromType result_from = obj->getErrorDescription();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_description(data_collection_model_access_token_err_t *obj_access_token_err, const char* p_error_description)
{
    if (obj_access_token_err == NULL) return NULL;

    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    const auto &value_from = p_error_description;
    typedef typename AccessTokenErr::Error_descriptionType ValueType;

    ValueType value(value_from);
    if (!obj->setErrorDescription(value)) return NULL;
    return obj_access_token_err;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_description_move(data_collection_model_access_token_err_t *obj_access_token_err, char* p_error_description)
{
    if (obj_access_token_err == NULL) return NULL;

    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    const auto &value_from = p_error_description;
    typedef typename AccessTokenErr::Error_descriptionType ValueType;

    ValueType value(value_from);
    
    if (!obj->setErrorDescription(std::move(value))) return NULL;
    return obj_access_token_err;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_access_token_err_get_error_uri(const data_collection_model_access_token_err_t *obj_access_token_err)
{
    const std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<const std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    typedef typename AccessTokenErr::Error_uriType ResultFromType;
    const ResultFromType result_from = obj->getErrorUri();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_uri(data_collection_model_access_token_err_t *obj_access_token_err, const char* p_error_uri)
{
    if (obj_access_token_err == NULL) return NULL;

    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    const auto &value_from = p_error_uri;
    typedef typename AccessTokenErr::Error_uriType ValueType;

    ValueType value(value_from);
    if (!obj->setErrorUri(value)) return NULL;
    return obj_access_token_err;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_uri_move(data_collection_model_access_token_err_t *obj_access_token_err, char* p_error_uri)
{
    if (obj_access_token_err == NULL) return NULL;

    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    const auto &value_from = p_error_uri;
    typedef typename AccessTokenErr::Error_uriType ValueType;

    ValueType value(value_from);
    
    if (!obj->setErrorUri(std::move(value))) return NULL;
    return obj_access_token_err;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_access_token_err_make_lnode(data_collection_model_access_token_err_t *p_access_token_err)
{
    return data_collection_lnode_create(p_access_token_err, reinterpret_cast<void(*)(void*)>(data_collection_model_access_token_err_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_access_token_err_refcount(data_collection_model_access_token_err_t *obj_access_token_err)
{
    std::shared_ptr<AccessTokenErr > &obj = *reinterpret_cast<std::shared_ptr<AccessTokenErr >*>(obj_access_token_err);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

