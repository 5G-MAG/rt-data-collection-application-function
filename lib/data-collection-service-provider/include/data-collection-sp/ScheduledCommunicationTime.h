#ifndef _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TIME_H_
#define _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TIME_H_

/**********************************************************************************************************************************
 * ScheduledCommunicationTime - Public C interface to the ScheduledCommunicationTime object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_scheduled_communication_time_s data_collection_model_scheduled_communication_time_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_copy(const data_collection_model_scheduled_communication_time_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_create_move(data_collection_model_scheduled_communication_time_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_copy(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const data_collection_model_scheduled_communication_time_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, data_collection_model_scheduled_communication_time_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_scheduled_communication_time_free(data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_scheduled_communication_time_toJSON(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_is_equal_to(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const data_collection_model_scheduled_communication_time_t *other_scheduled_communication_time);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_days_of_week(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_scheduled_communication_time_get_days_of_week(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const ogs_list_t* p_days_of_week);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_days_of_week_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, ogs_list_t* p_days_of_week);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_add_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, int32_t days_of_week);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_remove_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const int32_t days_of_week);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_clear_days_of_week(data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_time_of_day_start(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_scheduled_communication_time_get_time_of_day_start(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const char* p_time_of_day_start);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_start_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, char* p_time_of_day_start);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_scheduled_communication_time_has_time_of_day_end(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_scheduled_communication_time_get_time_of_day_end(const data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, const char* p_time_of_day_end);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_scheduled_communication_time_t *data_collection_model_scheduled_communication_time_set_time_of_day_end_move(data_collection_model_scheduled_communication_time_t *scheduled_communication_time, char* p_time_of_day_end);

/* lnode helper for generating ogs_list_t nodes's of type ScheduledCommunicationTime */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_scheduled_communication_time_make_lnode(data_collection_model_scheduled_communication_time_t *scheduled_communication_time);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SCHEDULED_COMMUNICATION_TIME_H_ */

