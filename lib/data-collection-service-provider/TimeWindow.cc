/**********************************************************************************************************************************
 * TimeWindow - C interface to the TimeWindow object
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

/*#include "TimeWindow.h" already included by data-collection-sp/data-collection.h */
#include "TimeWindow-internal.h"
#include "openapi/model/TimeWindow.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_create(

)
{
    return reinterpret_cast<data_collection_model_time_window_t*>(new std::shared_ptr<TimeWindow>(new TimeWindow(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_create_copy(const data_collection_model_time_window_t *other)
{
    return reinterpret_cast<data_collection_model_time_window_t*>(new std::shared_ptr<TimeWindow >(new TimeWindow(**reinterpret_cast<const std::shared_ptr<TimeWindow >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_create_move(data_collection_model_time_window_t *other)
{
    return reinterpret_cast<data_collection_model_time_window_t*>(new std::shared_ptr<TimeWindow >(std::move(*reinterpret_cast<std::shared_ptr<TimeWindow >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_copy(data_collection_model_time_window_t *time_window, const data_collection_model_time_window_t *other)
{
    std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<std::shared_ptr<TimeWindow >*>(time_window);
    *obj = **reinterpret_cast<const std::shared_ptr<TimeWindow >*>(other);
    return time_window;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_move(data_collection_model_time_window_t *time_window, data_collection_model_time_window_t *other)
{
    std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<std::shared_ptr<TimeWindow >*>(time_window);
    obj = std::move(*reinterpret_cast<std::shared_ptr<TimeWindow >*>(other));
    return time_window;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_time_window_free(data_collection_model_time_window_t *time_window)
{
    delete reinterpret_cast<std::shared_ptr<TimeWindow >*>(time_window);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_time_window_toJSON(const data_collection_model_time_window_t *time_window, bool as_request)
{
    const std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<const std::shared_ptr<TimeWindow >*>(time_window);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_time_window_t*>(new std::shared_ptr<TimeWindow >(new TimeWindow(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_time_window_is_equal_to(const data_collection_model_time_window_t *first, const data_collection_model_time_window_t *second)
{
    const std::shared_ptr<TimeWindow > &obj1 = *reinterpret_cast<const std::shared_ptr<TimeWindow >*>(first);
    const std::shared_ptr<TimeWindow > &obj2 = *reinterpret_cast<const std::shared_ptr<TimeWindow >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_time_window_get_start_time(const data_collection_model_time_window_t *obj_time_window)
{
    const std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<const std::shared_ptr<TimeWindow >*>(obj_time_window);
    typedef typename TimeWindow::StartTimeType ResultFromType;
    const ResultFromType result_from = obj->getStartTime();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_set_start_time(data_collection_model_time_window_t *obj_time_window, const char* p_start_time)
{
    if (obj_time_window == NULL) return NULL;

    std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<std::shared_ptr<TimeWindow >*>(obj_time_window);
    const auto &value_from = p_start_time;
    typedef typename TimeWindow::StartTimeType ValueType;

    ValueType value(value_from);
    if (!obj->setStartTime(value)) return NULL;
    return obj_time_window;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_set_start_time_move(data_collection_model_time_window_t *obj_time_window, char* p_start_time)
{
    if (obj_time_window == NULL) return NULL;

    std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<std::shared_ptr<TimeWindow >*>(obj_time_window);
    const auto &value_from = p_start_time;
    typedef typename TimeWindow::StartTimeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setStartTime(std::move(value))) return NULL;
    return obj_time_window;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_time_window_get_stop_time(const data_collection_model_time_window_t *obj_time_window)
{
    const std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<const std::shared_ptr<TimeWindow >*>(obj_time_window);
    typedef typename TimeWindow::StopTimeType ResultFromType;
    const ResultFromType result_from = obj->getStopTime();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_set_stop_time(data_collection_model_time_window_t *obj_time_window, const char* p_stop_time)
{
    if (obj_time_window == NULL) return NULL;

    std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<std::shared_ptr<TimeWindow >*>(obj_time_window);
    const auto &value_from = p_stop_time;
    typedef typename TimeWindow::StopTimeType ValueType;

    ValueType value(value_from);
    if (!obj->setStopTime(value)) return NULL;
    return obj_time_window;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_time_window_t *data_collection_model_time_window_set_stop_time_move(data_collection_model_time_window_t *obj_time_window, char* p_stop_time)
{
    if (obj_time_window == NULL) return NULL;

    std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<std::shared_ptr<TimeWindow >*>(obj_time_window);
    const auto &value_from = p_stop_time;
    typedef typename TimeWindow::StopTimeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setStopTime(std::move(value))) return NULL;
    return obj_time_window;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_time_window_make_lnode(data_collection_model_time_window_t *p_time_window)
{
    return data_collection_lnode_create(p_time_window, reinterpret_cast<void(*)(void*)>(data_collection_model_time_window_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_time_window_refcount(data_collection_model_time_window_t *obj_time_window)
{
    std::shared_ptr<TimeWindow > &obj = *reinterpret_cast<std::shared_ptr<TimeWindow >*>(obj_time_window);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

