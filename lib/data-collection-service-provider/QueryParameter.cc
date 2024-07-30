/**********************************************************************************************************************************
 * QueryParameter - C interface to the QueryParameter object
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

/*#include "QueryParameter.h" already included by data-collection-sp/data-collection.h */
#include "QueryParameter-internal.h"
#include "openapi/model/QueryParameter.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_create(

)
{
    return reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter>(new QueryParameter(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_copy(const data_collection_model_query_parameter_t *other)
{
    return reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter >(new QueryParameter(**reinterpret_cast<const std::shared_ptr<QueryParameter >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_move(data_collection_model_query_parameter_t *other)
{
    return reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter >(std::move(*reinterpret_cast<std::shared_ptr<QueryParameter >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_copy(data_collection_model_query_parameter_t *query_parameter, const data_collection_model_query_parameter_t *other)
{
    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(query_parameter);
    *obj = **reinterpret_cast<const std::shared_ptr<QueryParameter >*>(other);
    return query_parameter;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_move(data_collection_model_query_parameter_t *query_parameter, data_collection_model_query_parameter_t *other)
{
    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(query_parameter);
    obj = std::move(*reinterpret_cast<std::shared_ptr<QueryParameter >*>(other));
    return query_parameter;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_query_parameter_free(data_collection_model_query_parameter_t *query_parameter)
{
    delete reinterpret_cast<std::shared_ptr<QueryParameter >*>(query_parameter);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_query_parameter_toJSON(const data_collection_model_query_parameter_t *query_parameter, bool as_request)
{
    const std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(query_parameter);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter >(new QueryParameter(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_query_parameter_is_equal_to(const data_collection_model_query_parameter_t *first, const data_collection_model_query_parameter_t *second)
{
    const std::shared_ptr<QueryParameter > &obj1 = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(first);
    const std::shared_ptr<QueryParameter > &obj2 = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_query_parameter_get_name(const data_collection_model_query_parameter_t *obj_query_parameter)
{
    const std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    typedef typename QueryParameter::NameType ResultFromType;
    const ResultFromType result_from = obj->getName();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name(data_collection_model_query_parameter_t *obj_query_parameter, const char* p_name)
{
    if (obj_query_parameter == NULL) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    const auto &value_from = p_name;
    typedef typename QueryParameter::NameType ValueType;

    ValueType value(value_from);
    if (!obj->setName(value)) return NULL;
    return obj_query_parameter;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name_move(data_collection_model_query_parameter_t *obj_query_parameter, char* p_name)
{
    if (obj_query_parameter == NULL) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    const auto &value_from = p_name;
    typedef typename QueryParameter::NameType ValueType;

    ValueType value(value_from);
    
    if (!obj->setName(std::move(value))) return NULL;
    return obj_query_parameter;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_query_parameter_get_value(const data_collection_model_query_parameter_t *obj_query_parameter)
{
    const std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    typedef typename QueryParameter::ValueType ResultFromType;
    const ResultFromType result_from = obj->getValue();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value(data_collection_model_query_parameter_t *obj_query_parameter, const char* p_value)
{
    if (obj_query_parameter == NULL) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    const auto &value_from = p_value;
    typedef typename QueryParameter::ValueType ValueType;

    ValueType value(value_from);
    if (!obj->setValue(value)) return NULL;
    return obj_query_parameter;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value_move(data_collection_model_query_parameter_t *obj_query_parameter, char* p_value)
{
    if (obj_query_parameter == NULL) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    const auto &value_from = p_value;
    typedef typename QueryParameter::ValueType ValueType;

    ValueType value(value_from);
    
    if (!obj->setValue(std::move(value))) return NULL;
    return obj_query_parameter;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_query_parameter_make_lnode(data_collection_model_query_parameter_t *p_query_parameter)
{
    return data_collection_lnode_create(p_query_parameter, reinterpret_cast<void(*)(void*)>(data_collection_model_query_parameter_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_query_parameter_refcount(data_collection_model_query_parameter_t *obj_query_parameter)
{
    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

