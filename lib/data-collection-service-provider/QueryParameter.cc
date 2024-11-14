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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create(

)
{
    return reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter>(new QueryParameter(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_ref(const data_collection_model_query_parameter_t *other)
{
    return reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter>(*reinterpret_cast<const std::shared_ptr<QueryParameter >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_copy(const data_collection_model_query_parameter_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_query_parameter_t*>(new std::shared_ptr<QueryParameter >(new QueryParameter(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_move(data_collection_model_query_parameter_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<QueryParameter > *obj = reinterpret_cast<std::shared_ptr<QueryParameter >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_copy(data_collection_model_query_parameter_t *query_parameter, const data_collection_model_query_parameter_t *other)
{
    if (query_parameter) {
        std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(query_parameter);
        if (obj) {
            if (other) {
                const std::shared_ptr<QueryParameter > &other_obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(other);
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
                const std::shared_ptr<QueryParameter > &other_obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(other);
                if (other_obj) {
                    obj.reset(new QueryParameter(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        query_parameter = data_collection_model_query_parameter_create_copy(other);
    }
    return query_parameter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_move(data_collection_model_query_parameter_t *query_parameter, data_collection_model_query_parameter_t *other)
{
    std::shared_ptr<QueryParameter > *other_ptr = reinterpret_cast<std::shared_ptr<QueryParameter >*>(other);

    if (query_parameter) {
        std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(query_parameter);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                query_parameter = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return query_parameter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_query_parameter_free(data_collection_model_query_parameter_t *query_parameter)
{
    if (!query_parameter) return;
    delete reinterpret_cast<std::shared_ptr<QueryParameter >*>(query_parameter);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_query_parameter_toJSON(const data_collection_model_query_parameter_t *query_parameter, bool as_request)
{
    if (!query_parameter) return NULL;
    const std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(query_parameter);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_query_parameter_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_query_parameter_is_equal_to(const data_collection_model_query_parameter_t *first, const data_collection_model_query_parameter_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<QueryParameter > &obj2 = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<QueryParameter > &obj1 = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_query_parameter_get_name(const data_collection_model_query_parameter_t *obj_query_parameter)
{
    if (!obj_query_parameter) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename QueryParameter::NameType ResultFromType;
    const ResultFromType &result_from = obj->getName();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name(data_collection_model_query_parameter_t *obj_query_parameter, const char* p_name)
{
    if (!obj_query_parameter) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    if (!obj) return NULL;

    const auto &value_from = p_name;
    typedef typename QueryParameter::NameType ValueType;

    ValueType value(value_from);

    if (!obj->setName(value)) return NULL;

    return obj_query_parameter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name_move(data_collection_model_query_parameter_t *obj_query_parameter, char* p_name)
{
    if (!obj_query_parameter) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    if (!obj) return NULL;

    const auto &value_from = p_name;
    typedef typename QueryParameter::NameType ValueType;

    ValueType value(value_from);

    if (!obj->setName(std::move(value))) return NULL;
    ogs_free
(p_name);

    return obj_query_parameter;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_query_parameter_get_value(const data_collection_model_query_parameter_t *obj_query_parameter)
{
    if (!obj_query_parameter) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<const std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename QueryParameter::ValueType ResultFromType;
    const ResultFromType &result_from = obj->getValue();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value(data_collection_model_query_parameter_t *obj_query_parameter, const char* p_value)
{
    if (!obj_query_parameter) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    if (!obj) return NULL;

    const auto &value_from = p_value;
    typedef typename QueryParameter::ValueType ValueType;

    ValueType value(value_from);

    if (!obj->setValue(value)) return NULL;

    return obj_query_parameter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value_move(data_collection_model_query_parameter_t *obj_query_parameter, char* p_value)
{
    if (!obj_query_parameter) return NULL;

    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    if (!obj) return NULL;

    const auto &value_from = p_value;
    typedef typename QueryParameter::ValueType ValueType;

    ValueType value(value_from);

    if (!obj->setValue(std::move(value))) return NULL;
    ogs_free
(p_value);

    return obj_query_parameter;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_query_parameter_make_lnode(data_collection_model_query_parameter_t *p_query_parameter)
{
    return data_collection_lnode_create(p_query_parameter, reinterpret_cast<void(*)(void*)>(data_collection_model_query_parameter_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_query_parameter_refcount(data_collection_model_query_parameter_t *obj_query_parameter)
{
    if (!obj_query_parameter) return 0l;
    std::shared_ptr<QueryParameter > &obj = *reinterpret_cast<std::shared_ptr<QueryParameter >*>(obj_query_parameter);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

