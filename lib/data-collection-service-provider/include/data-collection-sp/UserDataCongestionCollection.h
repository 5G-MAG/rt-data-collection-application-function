#ifndef _DATA_COLLECTION_USER_DATA_CONGESTION_COLLECTION_H_
#define _DATA_COLLECTION_USER_DATA_CONGESTION_COLLECTION_H_

/**********************************************************************************************************************************
 * UserDataCongestionCollection - Public C interface to the UserDataCongestionCollection object
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

#include "FlowInfo.h"
#include "TimeWindow.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_user_data_congestion_collection_s data_collection_model_user_data_congestion_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create_copy(const data_collection_model_user_data_congestion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create_move(data_collection_model_user_data_congestion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_copy(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_user_data_congestion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, data_collection_model_user_data_congestion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_user_data_congestion_collection_free(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_user_data_congestion_collection_toJSON(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_app_id(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_app_id(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_app_id_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_user_data_congestion_collection_get_ip_traffic_filter(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_ip_traffic_filter(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_ip_traffic_filter_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, data_collection_model_flow_info_t* p_ip_traffic_filter);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_user_data_congestion_collection_get_time_interv(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_time_interv(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_time_window_t* p_time_interv);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_time_interv_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, data_collection_model_time_window_t* p_time_interv);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_ul(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_ul(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_ul_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_dl(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_dl(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_dl_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_dl);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_pk_ul(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_ul(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_pk_ul);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_ul_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_pk_ul);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_pk_dl(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_dl(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_pk_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_dl_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_pk_dl);

/* lnode helper for generating ogs_list_t nodes's of type UserDataCongestionCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_user_data_congestion_collection_make_lnode(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_USER_DATA_CONGESTION_COLLECTION_H_ */

