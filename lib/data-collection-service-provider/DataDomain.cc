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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "DataDomain.h" already included by data-collection-sp/data-collection.h */
#include "DataDomain-internal.h"
#include "openapi/model/DataDomain.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_domain_t *data_collection_model_data_domain_create()
{
    return reinterpret_cast<data_collection_model_data_domain_t*>(new std::shared_ptr<DataDomain>(new DataDomain()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_domain_t *data_collection_model_data_domain_create_copy(const data_collection_model_data_domain_t *other)
{
    return reinterpret_cast<data_collection_model_data_domain_t*>(new std::shared_ptr<DataDomain >(new DataDomain(**reinterpret_cast<const std::shared_ptr<DataDomain >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_domain_t *data_collection_model_data_domain_create_move(data_collection_model_data_domain_t *other)
{
    return reinterpret_cast<data_collection_model_data_domain_t*>(new std::shared_ptr<DataDomain >(std::move(*reinterpret_cast<std::shared_ptr<DataDomain >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_domain_t *data_collection_model_data_domain_copy(data_collection_model_data_domain_t *data_domain, const data_collection_model_data_domain_t *other)
{
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(data_domain);
    *obj = **reinterpret_cast<const std::shared_ptr<DataDomain >*>(other);
    return data_domain;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_domain_t *data_collection_model_data_domain_move(data_collection_model_data_domain_t *data_domain, data_collection_model_data_domain_t *other)
{
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(data_domain);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataDomain >*>(other));
    return data_domain;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_domain_free(data_collection_model_data_domain_t *data_domain)
{
    delete reinterpret_cast<std::shared_ptr<DataDomain >*>(data_domain);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_domain_toJSON(const data_collection_model_data_domain_t *data_domain, bool as_request)
{
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(data_domain);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_domain_t *data_collection_model_data_domain_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_not_set(const data_collection_model_data_domain_t *obj_data_domain)
{
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
    return obj->getValue() == DataDomain::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_non_standard(const data_collection_model_data_domain_t *obj_data_domain)
{
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
    return obj->getValue() == DataDomain::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_e data_collection_model_data_domain_get_enum(const data_collection_model_data_domain_t *obj_data_domain)
{
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_data_domain_get_string(const data_collection_model_data_domain_t *obj_data_domain)
{
    const std::shared_ptr<DataDomain > &obj = *reinterpret_cast<const std::shared_ptr<DataDomain >*>(obj_data_domain);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_set_enum(data_collection_model_data_domain_t *obj_data_domain, data_collection_model_data_domain_e p_value)
{
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(obj_data_domain);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_set_string(data_collection_model_data_domain_t *obj_data_domain, const char *p_value)
{
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(obj_data_domain);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = DataDomain::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_domain_make_lnode(data_collection_model_data_domain_t *p_data_domain)
{
    return data_collection_lnode_create(p_data_domain, reinterpret_cast<void(*)(void*)>(data_collection_model_data_domain_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_domain_refcount(data_collection_model_data_domain_t *obj_data_domain)
{
    std::shared_ptr<DataDomain > &obj = *reinterpret_cast<std::shared_ptr<DataDomain >*>(obj_data_domain);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

