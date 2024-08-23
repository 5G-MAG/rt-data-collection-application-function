#ifndef _DATA_COLLECTION_TIME_WINDOW_H_
#define _DATA_COLLECTION_TIME_WINDOW_H_

/**********************************************************************************************************************************
 * TimeWindow - Public C interface to the TimeWindow object
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

typedef struct data_collection_model_time_window_s data_collection_model_time_window_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_create_copy(const data_collection_model_time_window_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_create_move(data_collection_model_time_window_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_copy(data_collection_model_time_window_t *time_window, const data_collection_model_time_window_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_move(data_collection_model_time_window_t *time_window, data_collection_model_time_window_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_time_window_free(data_collection_model_time_window_t *time_window);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_time_window_toJSON(const data_collection_model_time_window_t *time_window, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_time_window_is_equal_to(const data_collection_model_time_window_t *time_window, const data_collection_model_time_window_t *other_time_window);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_time_window_get_start_time(const data_collection_model_time_window_t *time_window);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_start_time(data_collection_model_time_window_t *time_window, const char* p_start_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_start_time_move(data_collection_model_time_window_t *time_window, char* p_start_time);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_time_window_get_stop_time(const data_collection_model_time_window_t *time_window);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_stop_time(data_collection_model_time_window_t *time_window, const char* p_stop_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_stop_time_move(data_collection_model_time_window_t *time_window, char* p_stop_time);

/* lnode helper for generating ogs_list_t nodes's of type TimeWindow */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_time_window_make_lnode(data_collection_model_time_window_t *time_window);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TIME_WINDOW_H_ */

