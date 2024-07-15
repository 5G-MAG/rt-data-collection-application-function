/**********************************************************************************************************************************
 * DataReportingConditionType - C interface to the DataReportingConditionType object
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

/*#include "DataReportingConditionType.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingConditionType-internal.h"
#include "openapi/model/DataReportingConditionType.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_type_t *data_collection_model_data_reporting_condition_type_create()
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_type_t*>(new std::shared_ptr<DataReportingConditionType>(new DataReportingConditionType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_type_t *data_collection_model_data_reporting_condition_type_create_copy(const data_collection_model_data_reporting_condition_type_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_type_t*>(new std::shared_ptr<DataReportingConditionType >(new DataReportingConditionType(**reinterpret_cast<const std::shared_ptr<DataReportingConditionType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_type_t *data_collection_model_data_reporting_condition_type_create_move(data_collection_model_data_reporting_condition_type_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_type_t*>(new std::shared_ptr<DataReportingConditionType >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_type_t *data_collection_model_data_reporting_condition_type_copy(data_collection_model_data_reporting_condition_type_t *data_reporting_condition_type, const data_collection_model_data_reporting_condition_type_t *other)
{
    std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(data_reporting_condition_type);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingConditionType >*>(other);
    return data_reporting_condition_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_type_t *data_collection_model_data_reporting_condition_type_move(data_collection_model_data_reporting_condition_type_t *data_reporting_condition_type, data_collection_model_data_reporting_condition_type_t *other)
{
    std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(data_reporting_condition_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(other));
    return data_reporting_condition_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_condition_type_free(data_collection_model_data_reporting_condition_type_t *data_reporting_condition_type)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(data_reporting_condition_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_condition_type_toJSON(const data_collection_model_data_reporting_condition_type_t *data_reporting_condition_type, bool as_request)
{
    const std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConditionType >*>(data_reporting_condition_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_type_t *data_collection_model_data_reporting_condition_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_condition_type_t*>(new std::shared_ptr<DataReportingConditionType >(new DataReportingConditionType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_type_is_not_set(const data_collection_model_data_reporting_condition_type_t *obj_data_reporting_condition_type)
{
    const std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConditionType >*>(obj_data_reporting_condition_type);
    return obj->getValue() == DataReportingConditionType::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_type_is_non_standard(const data_collection_model_data_reporting_condition_type_t *obj_data_reporting_condition_type)
{
    const std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConditionType >*>(obj_data_reporting_condition_type);
    return obj->getValue() == DataReportingConditionType::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_type_e data_collection_model_data_reporting_condition_type_get_enum(const data_collection_model_data_reporting_condition_type_t *obj_data_reporting_condition_type)
{
    const std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConditionType >*>(obj_data_reporting_condition_type);
    switch (obj->getValue()) {
    case DataReportingConditionType::Enum::NO_VAL:
        return DCM_DATA_REPORTING_CONDITION_TYPE_NO_VAL;
    case DataReportingConditionType::Enum::VAL_INTERVAL:
        return DCM_DATA_REPORTING_CONDITION_TYPE_VAL_INTERVAL;
    case DataReportingConditionType::Enum::VAL_THRESHOLD:
        return DCM_DATA_REPORTING_CONDITION_TYPE_VAL_THRESHOLD;
    case DataReportingConditionType::Enum::VAL_EVENT:
        return DCM_DATA_REPORTING_CONDITION_TYPE_VAL_EVENT;
    default:
        break;
    }
    return DCM_DATA_REPORTING_CONDITION_TYPE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_data_reporting_condition_type_get_string(const data_collection_model_data_reporting_condition_type_t *obj_data_reporting_condition_type)
{
    const std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingConditionType >*>(obj_data_reporting_condition_type);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_type_set_enum(data_collection_model_data_reporting_condition_type_t *obj_data_reporting_condition_type, data_collection_model_data_reporting_condition_type_e p_value)
{
    std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(obj_data_reporting_condition_type);
    switch (p_value) {
    case DCM_DATA_REPORTING_CONDITION_TYPE_NO_VAL:
        *obj = DataReportingConditionType::Enum::NO_VAL;
        return true;
    case DCM_DATA_REPORTING_CONDITION_TYPE_VAL_INTERVAL:
        *obj = DataReportingConditionType::Enum::VAL_INTERVAL;
        return true;
    case DCM_DATA_REPORTING_CONDITION_TYPE_VAL_THRESHOLD:
        *obj = DataReportingConditionType::Enum::VAL_THRESHOLD;
        return true;
    case DCM_DATA_REPORTING_CONDITION_TYPE_VAL_EVENT:
        *obj = DataReportingConditionType::Enum::VAL_EVENT;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_type_set_string(data_collection_model_data_reporting_condition_type_t *obj_data_reporting_condition_type, const char *p_value)
{
    std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(obj_data_reporting_condition_type);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = DataReportingConditionType::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_condition_type_make_lnode(data_collection_model_data_reporting_condition_type_t *p_data_reporting_condition_type)
{
    return data_collection_lnode_create(p_data_reporting_condition_type, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_condition_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_condition_type_refcount(data_collection_model_data_reporting_condition_type_t *obj_data_reporting_condition_type)
{
    std::shared_ptr<DataReportingConditionType > &obj = *reinterpret_cast<std::shared_ptr<DataReportingConditionType >*>(obj_data_reporting_condition_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

