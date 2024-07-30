/**********************************************************************************************************************************
 * DataAggregationFunctionType - C interface to the DataAggregationFunctionType object
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

/*#include "DataAggregationFunctionType.h" already included by data-collection-sp/data-collection.h */
#include "DataAggregationFunctionType-internal.h"
#include "openapi/model/DataAggregationFunctionType.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_aggregation_function_type_t *data_collection_model_data_aggregation_function_type_create()
{
    return reinterpret_cast<data_collection_model_data_aggregation_function_type_t*>(new std::shared_ptr<DataAggregationFunctionType>(new DataAggregationFunctionType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_aggregation_function_type_t *data_collection_model_data_aggregation_function_type_create_copy(const data_collection_model_data_aggregation_function_type_t *other)
{
    return reinterpret_cast<data_collection_model_data_aggregation_function_type_t*>(new std::shared_ptr<DataAggregationFunctionType >(new DataAggregationFunctionType(**reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_aggregation_function_type_t *data_collection_model_data_aggregation_function_type_create_move(data_collection_model_data_aggregation_function_type_t *other)
{
    return reinterpret_cast<data_collection_model_data_aggregation_function_type_t*>(new std::shared_ptr<DataAggregationFunctionType >(std::move(*reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_aggregation_function_type_t *data_collection_model_data_aggregation_function_type_copy(data_collection_model_data_aggregation_function_type_t *data_aggregation_function_type, const data_collection_model_data_aggregation_function_type_t *other)
{
    std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(data_aggregation_function_type);
    *obj = **reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(other);
    return data_aggregation_function_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_aggregation_function_type_t *data_collection_model_data_aggregation_function_type_move(data_collection_model_data_aggregation_function_type_t *data_aggregation_function_type, data_collection_model_data_aggregation_function_type_t *other)
{
    std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(data_aggregation_function_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(other));
    return data_aggregation_function_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_aggregation_function_type_free(data_collection_model_data_aggregation_function_type_t *data_aggregation_function_type)
{
    delete reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(data_aggregation_function_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_aggregation_function_type_toJSON(const data_collection_model_data_aggregation_function_type_t *data_aggregation_function_type, bool as_request)
{
    const std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(data_aggregation_function_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_aggregation_function_type_t *data_collection_model_data_aggregation_function_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_aggregation_function_type_t*>(new std::shared_ptr<DataAggregationFunctionType >(new DataAggregationFunctionType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_aggregation_function_type_is_equal_to(const data_collection_model_data_aggregation_function_type_t *first, const data_collection_model_data_aggregation_function_type_t *second)
{
    const std::shared_ptr<DataAggregationFunctionType > &obj1 = *reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(first);
    const std::shared_ptr<DataAggregationFunctionType > &obj2 = *reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_aggregation_function_type_is_not_set(const data_collection_model_data_aggregation_function_type_t *obj_data_aggregation_function_type)
{
    const std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(obj_data_aggregation_function_type);
    return obj->getValue() == DataAggregationFunctionType::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_aggregation_function_type_is_non_standard(const data_collection_model_data_aggregation_function_type_t *obj_data_aggregation_function_type)
{
    const std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(obj_data_aggregation_function_type);
    return obj->getValue() == DataAggregationFunctionType::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_aggregation_function_type_e data_collection_model_data_aggregation_function_type_get_enum(const data_collection_model_data_aggregation_function_type_t *obj_data_aggregation_function_type)
{
    const std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(obj_data_aggregation_function_type);
    switch (obj->getValue()) {
    case DataAggregationFunctionType::Enum::NO_VAL:
        return DCM_DATA_AGGREGATION_FUNCTION_TYPE_NO_VAL;
    case DataAggregationFunctionType::Enum::VAL_NONE:
        return DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_NONE;
    case DataAggregationFunctionType::Enum::VAL_COUNT:
        return DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_COUNT;
    case DataAggregationFunctionType::Enum::VAL_MEAN:
        return DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_MEAN;
    case DataAggregationFunctionType::Enum::VAL_MAXIMUM:
        return DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_MAXIMUM;
    case DataAggregationFunctionType::Enum::VAL_MINIMUM:
        return DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_MINIMUM;
    case DataAggregationFunctionType::Enum::VAL_SUM:
        return DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_SUM;
    default:
        break;
    }
    return DCM_DATA_AGGREGATION_FUNCTION_TYPE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_data_aggregation_function_type_get_string(const data_collection_model_data_aggregation_function_type_t *obj_data_aggregation_function_type)
{
    const std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<const std::shared_ptr<DataAggregationFunctionType >*>(obj_data_aggregation_function_type);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_aggregation_function_type_set_enum(data_collection_model_data_aggregation_function_type_t *obj_data_aggregation_function_type, data_collection_model_data_aggregation_function_type_e p_value)
{
    std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(obj_data_aggregation_function_type);
    switch (p_value) {
    case DCM_DATA_AGGREGATION_FUNCTION_TYPE_NO_VAL:
        *obj = DataAggregationFunctionType::Enum::NO_VAL;
        return true;
    case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_NONE:
        *obj = DataAggregationFunctionType::Enum::VAL_NONE;
        return true;
    case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_COUNT:
        *obj = DataAggregationFunctionType::Enum::VAL_COUNT;
        return true;
    case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_MEAN:
        *obj = DataAggregationFunctionType::Enum::VAL_MEAN;
        return true;
    case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_MAXIMUM:
        *obj = DataAggregationFunctionType::Enum::VAL_MAXIMUM;
        return true;
    case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_MINIMUM:
        *obj = DataAggregationFunctionType::Enum::VAL_MINIMUM;
        return true;
    case DCM_DATA_AGGREGATION_FUNCTION_TYPE_VAL_SUM:
        *obj = DataAggregationFunctionType::Enum::VAL_SUM;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_aggregation_function_type_set_string(data_collection_model_data_aggregation_function_type_t *obj_data_aggregation_function_type, const char *p_value)
{
    std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(obj_data_aggregation_function_type);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = DataAggregationFunctionType::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_aggregation_function_type_make_lnode(data_collection_model_data_aggregation_function_type_t *p_data_aggregation_function_type)
{
    return data_collection_lnode_create(p_data_aggregation_function_type, reinterpret_cast<void(*)(void*)>(data_collection_model_data_aggregation_function_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_aggregation_function_type_refcount(data_collection_model_data_aggregation_function_type_t *obj_data_aggregation_function_type)
{
    std::shared_ptr<DataAggregationFunctionType > &obj = *reinterpret_cast<std::shared_ptr<DataAggregationFunctionType >*>(obj_data_aggregation_function_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

