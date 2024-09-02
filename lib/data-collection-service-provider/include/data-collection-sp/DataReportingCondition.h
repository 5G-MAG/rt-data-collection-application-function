#ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_H_
#define _DATA_COLLECTION_DATA_REPORTING_CONDITION_H_

/**********************************************************************************************************************************
 * DataReportingCondition - Public C interface to the DataReportingCondition object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "DataReportingEventTrigger.h"
#include "DataReportingCondition_threshold.h"
#include "DataReportingConditionType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_reporting_condition_s data_collection_model_data_reporting_condition_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_copy(const data_collection_model_data_reporting_condition_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_create_move(data_collection_model_data_reporting_condition_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_copy(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_condition_free(data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_condition_toJSON(const data_collection_model_data_reporting_condition_t *data_reporting_condition, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_is_equal_to(const data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_t *other_data_reporting_condition);



DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_condition_get_context_ids(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_context_ids_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_add_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_remove_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_clear_context_ids(data_collection_model_data_reporting_condition_t *data_reporting_condition);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_type_t* data_collection_model_data_reporting_condition_get_type(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_type_t* p_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_type_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_type_t* p_type);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_period(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_data_reporting_condition_get_period(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period(data_collection_model_data_reporting_condition_t *data_reporting_condition, const int32_t p_period);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_period_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, int32_t p_period);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_parameter(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_condition_get_parameter(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter(data_collection_model_data_reporting_condition_t *data_reporting_condition, const char* p_parameter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_parameter_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, char* p_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_threshold(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_condition_threshold_t* data_collection_model_data_reporting_condition_get_threshold(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_condition_threshold_t* p_threshold);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_threshold_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_condition_threshold_t* p_threshold);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_report_when_below(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_data_reporting_condition_is_report_when_below(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below(data_collection_model_data_reporting_condition_t *data_reporting_condition, const bool p_report_when_below);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_report_when_below_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, bool p_report_when_below);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_has_event_trigger(const data_collection_model_data_reporting_condition_t *data_reporting_condition);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_event_trigger_t* data_collection_model_data_reporting_condition_get_event_trigger(const data_collection_model_data_reporting_condition_t *data_reporting_condition);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger(data_collection_model_data_reporting_condition_t *data_reporting_condition, const data_collection_model_data_reporting_event_trigger_t* p_event_trigger);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_t *data_collection_model_data_reporting_condition_set_event_trigger_move(data_collection_model_data_reporting_condition_t *data_reporting_condition, data_collection_model_data_reporting_event_trigger_t* p_event_trigger);

/* lnode helper for generating ogs_list_t nodes's of type DataReportingCondition */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_condition_make_lnode(data_collection_model_data_reporting_condition_t *data_reporting_condition);

/** Check if two DataReportingConditions are equal without checking the contextIds array */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_is_equal_to_sans_context_ids(const data_collection_model_data_reporting_condition_t *first, const data_collection_model_data_reporting_condition_t *second);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_H_ */

