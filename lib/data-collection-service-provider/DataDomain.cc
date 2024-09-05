/**********************************************************************************************************************************
 * DataDomain - C interface to the DataDomain object
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

/*#include "DataDomain.h" already included by data-collection-sp/data-collection.h */
#include "DataDomain-internal.h"
#include "openapi/model/DataDomain.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_create()
{
    return reinterpret_cast<data_collection_model_data_domain_t*>(new std::shared_ptr<DataDomain>(new DataDomain()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_create_copy(const data_collection_model_data_domain_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_data_domain_t*>(new std::shared_ptr<DataDomain >(new DataDomain(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_create_move(data_collection_model_data_domain_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DataDomain > *obj = reinterpret_cast<std::shared_ptr<DataDomain >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_copy(data_collection_model_data_domain_t *data_domain, const data_collection_model_data_domain_t *other)
{
    if (data_domain) {
        std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(data_domain);
        if (obj) {
            if (other) {
                const std::shared_ptr<DataDomain > &other_obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(other);
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
                const std::shared_ptr<DataDomain > &other_obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(other);
                if (other_obj) {
                    obj.reset(new DataDomain(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        data_domain = data_collection_model_data_domain_create_copy(other);
    }
    return data_domain;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_move(data_collection_model_data_domain_t *data_domain, data_collection_model_data_domain_t *other)
{
    std::shared_ptr<DataDomain > *other_ptr = reinterpret_cast<std::shared_ptr<DataDomain >*>(other);

    if (data_domain) {
        std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(data_domain);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                data_domain = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return data_domain;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_domain_free(data_collection_model_data_domain_t *data_domain)
{
    if (!data_domain) return;
    delete reinterpret_cast<std::shared_ptr<DataDomain >*>(data_domain);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_domain_toJSON(const data_collection_model_data_domain_t *data_domain, bool as_request)
{
    if (!data_domain) return NULL;
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(data_domain);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_data_domain_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_domain_t*>(new std::shared_ptr<DataDomain >(new DataDomain(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_equal_to(const data_collection_model_data_domain_t *first, const data_collection_model_data_domain_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataDomain > &obj2 = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataDomain > &obj1 = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_not_set(const data_collection_model_data_domain_t *obj_data_domain)
{
    if (!obj_data_domain) return true;
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
    if (!obj) return true;
    return obj->getValue() == DataDomain::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_non_standard(const data_collection_model_data_domain_t *obj_data_domain)
{
    if (!obj_data_domain) return false;
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
    if (!obj) return false;
    return obj->getValue() == DataDomain::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_e data_collection_model_data_domain_get_enum(const data_collection_model_data_domain_t *obj_data_domain)
{
    if (!obj_data_domain)
        return DCM_DATA_DOMAIN_NO_VAL;
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
    if (!obj) return DCM_DATA_DOMAIN_NO_VAL;
    switch (obj->getValue()) {
    case DataDomain::Enum::NO_VAL:
        return DCM_DATA_DOMAIN_NO_VAL;
    case DataDomain::Enum::VAL_SERVICE_EXPERIENCE:
        return DCM_DATA_DOMAIN_VAL_SERVICE_EXPERIENCE;
    case DataDomain::Enum::VAL_LOCATION:
        return DCM_DATA_DOMAIN_VAL_LOCATION;
    case DataDomain::Enum::VAL_COMMUNICATION:
        return DCM_DATA_DOMAIN_VAL_COMMUNICATION;
    case DataDomain::Enum::VAL_PERFORMANCE:
        return DCM_DATA_DOMAIN_VAL_PERFORMANCE;
    case DataDomain::Enum::VAL_APPLICATION_SPECIFIC:
        return DCM_DATA_DOMAIN_VAL_APPLICATION_SPECIFIC;
    case DataDomain::Enum::VAL_MS_ANBR_NETWORK_ASSISTANCE:
        return DCM_DATA_DOMAIN_VAL_MS_ANBR_NETWORK_ASSISTANCE;
    case DataDomain::Enum::VAL_MS_ACCESS_ACTIVITY:
        return DCM_DATA_DOMAIN_VAL_MS_ACCESS_ACTIVITY;
    case DataDomain::Enum::VAL_PLANNED_TRIPS:
        return DCM_DATA_DOMAIN_VAL_PLANNED_TRIPS;
    default:
        break;
    }
    return DCM_DATA_DOMAIN_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_data_domain_get_string(const data_collection_model_data_domain_t *obj_data_domain)
{
    if (!obj_data_domain) return NULL;
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_set_enum(data_collection_model_data_domain_t *obj_data_domain, data_collection_model_data_domain_e p_value)
{
    if (!obj_data_domain) return false;
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(obj_data_domain);
    if (!obj) return false;
    switch (p_value) {
    case DCM_DATA_DOMAIN_NO_VAL:
        *obj = DataDomain::Enum::NO_VAL;
        return true;
    case DCM_DATA_DOMAIN_VAL_SERVICE_EXPERIENCE:
        *obj = DataDomain::Enum::VAL_SERVICE_EXPERIENCE;
        return true;
    case DCM_DATA_DOMAIN_VAL_LOCATION:
        *obj = DataDomain::Enum::VAL_LOCATION;
        return true;
    case DCM_DATA_DOMAIN_VAL_COMMUNICATION:
        *obj = DataDomain::Enum::VAL_COMMUNICATION;
        return true;
    case DCM_DATA_DOMAIN_VAL_PERFORMANCE:
        *obj = DataDomain::Enum::VAL_PERFORMANCE;
        return true;
    case DCM_DATA_DOMAIN_VAL_APPLICATION_SPECIFIC:
        *obj = DataDomain::Enum::VAL_APPLICATION_SPECIFIC;
        return true;
    case DCM_DATA_DOMAIN_VAL_MS_ANBR_NETWORK_ASSISTANCE:
        *obj = DataDomain::Enum::VAL_MS_ANBR_NETWORK_ASSISTANCE;
        return true;
    case DCM_DATA_DOMAIN_VAL_MS_ACCESS_ACTIVITY:
        *obj = DataDomain::Enum::VAL_MS_ACCESS_ACTIVITY;
        return true;
    case DCM_DATA_DOMAIN_VAL_PLANNED_TRIPS:
        *obj = DataDomain::Enum::VAL_PLANNED_TRIPS;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_set_string(data_collection_model_data_domain_t *obj_data_domain, const char *p_value)
{
    if (!obj_data_domain) return false;
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(obj_data_domain);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = DataDomain::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_domain_make_lnode(data_collection_model_data_domain_t *p_data_domain)
{
    return data_collection_lnode_create(p_data_domain, reinterpret_cast<void(*)(void*)>(data_collection_model_data_domain_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_domain_refcount(data_collection_model_data_domain_t *obj_data_domain)
{
    if (!obj_data_domain) return 0l;
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(obj_data_domain);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

