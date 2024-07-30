/**********************************************************************************************************************************
 * DataReportingCondition_threshold - C interface to the DataReportingCondition_threshold object
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

/*#include "DataReportingCondition_threshold.h" already included by data-collection-sp/data-collection.h */
#include "DataReportingCondition_threshold-internal.h"
#include "openapi/model/DataReportingCondition_threshold.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create()
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_threshold_t*>(new std::shared_ptr<DataReportingCondition_threshold>(new DataReportingCondition_threshold()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create_copy(const data_collection_model_data_reporting_condition_threshold_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_threshold_t*>(new std::shared_ptr<DataReportingCondition_threshold >(new DataReportingCondition_threshold(**reinterpret_cast<const std::shared_ptr<DataReportingCondition_threshold >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create_move(data_collection_model_data_reporting_condition_threshold_t *other)
{
    return reinterpret_cast<data_collection_model_data_reporting_condition_threshold_t*>(new std::shared_ptr<DataReportingCondition_threshold >(std::move(*reinterpret_cast<std::shared_ptr<DataReportingCondition_threshold >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_copy(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, const data_collection_model_data_reporting_condition_threshold_t *other)
{
    std::shared_ptr<DataReportingCondition_threshold > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition_threshold >*>(data_reporting_condition_threshold);
    *obj = **reinterpret_cast<const std::shared_ptr<DataReportingCondition_threshold >*>(other);
    return data_reporting_condition_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_move(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, data_collection_model_data_reporting_condition_threshold_t *other)
{
    std::shared_ptr<DataReportingCondition_threshold > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition_threshold >*>(data_reporting_condition_threshold);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataReportingCondition_threshold >*>(other));
    return data_reporting_condition_threshold;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_reporting_condition_threshold_free(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold)
{
    delete reinterpret_cast<std::shared_ptr<DataReportingCondition_threshold >*>(data_reporting_condition_threshold);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_reporting_condition_threshold_toJSON(const data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, bool as_request)
{
    const std::shared_ptr<DataReportingCondition_threshold > &obj = *reinterpret_cast<const std::shared_ptr<DataReportingCondition_threshold >*>(data_reporting_condition_threshold);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_reporting_condition_threshold_t*>(new std::shared_ptr<DataReportingCondition_threshold >(new DataReportingCondition_threshold(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_data_reporting_condition_threshold_is_equal_to(const data_collection_model_data_reporting_condition_threshold_t *first, const data_collection_model_data_reporting_condition_threshold_t *second)
{
    const std::shared_ptr<DataReportingCondition_threshold > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition_threshold >*>(first);
    const std::shared_ptr<DataReportingCondition_threshold > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition_threshold >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_reporting_condition_threshold_make_lnode(data_collection_model_data_reporting_condition_threshold_t *p_data_reporting_condition_threshold)
{
    return data_collection_lnode_create(p_data_reporting_condition_threshold, reinterpret_cast<void(*)(void*)>(data_collection_model_data_reporting_condition_threshold_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_reporting_condition_threshold_refcount(data_collection_model_data_reporting_condition_threshold_t *obj_data_reporting_condition_threshold)
{
    std::shared_ptr<DataReportingCondition_threshold > &obj = *reinterpret_cast<std::shared_ptr<DataReportingCondition_threshold >*>(obj_data_reporting_condition_threshold);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

