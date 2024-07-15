#ifndef _DATA_COLLECTION_PERIODIC_EVENT_INFO_H_
#define _DATA_COLLECTION_PERIODIC_EVENT_INFO_H_

/**********************************************************************************************************************************
 * PeriodicEventInfo - Public C interface to the PeriodicEventInfo object
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

typedef struct data_collection_model_periodic_event_info_s data_collection_model_periodic_event_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_copy(const data_collection_model_periodic_event_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_move(data_collection_model_periodic_event_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_copy(data_collection_model_periodic_event_info_t *periodic_event_info, const data_collection_model_periodic_event_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_move(data_collection_model_periodic_event_info_t *periodic_event_info, data_collection_model_periodic_event_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_periodic_event_info_free(data_collection_model_periodic_event_info_t *periodic_event_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_periodic_event_info_toJSON(const data_collection_model_periodic_event_info_t *periodic_event_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_amount(const data_collection_model_periodic_event_info_t *periodic_event_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount(data_collection_model_periodic_event_info_t *periodic_event_info, const int32_t p_reporting_amount);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount_move(data_collection_model_periodic_event_info_t *periodic_event_info, int32_t p_reporting_amount);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_interval(const data_collection_model_periodic_event_info_t *periodic_event_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval(data_collection_model_periodic_event_info_t *periodic_event_info, const int32_t p_reporting_interval);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_move(data_collection_model_periodic_event_info_t *periodic_event_info, int32_t p_reporting_interval);

DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_periodic_event_info_is_reporting_infinite_ind(const data_collection_model_periodic_event_info_t *periodic_event_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind(data_collection_model_periodic_event_info_t *periodic_event_info, const bool p_reporting_infinite_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind_move(data_collection_model_periodic_event_info_t *periodic_event_info, bool p_reporting_infinite_ind);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_interval_ms(const data_collection_model_periodic_event_info_t *periodic_event_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms(data_collection_model_periodic_event_info_t *periodic_event_info, const int32_t p_reporting_interval_ms);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms_move(data_collection_model_periodic_event_info_t *periodic_event_info, int32_t p_reporting_interval_ms);

/* lnode helper for generating ogs_list_t nodes's of type PeriodicEventInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_periodic_event_info_make_lnode(data_collection_model_periodic_event_info_t *periodic_event_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERIODIC_EVENT_INFO_H_ */

