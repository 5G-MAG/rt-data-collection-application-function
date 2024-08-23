#ifndef _DATA_COLLECTION_EVENTS_SUBS_H_
#define _DATA_COLLECTION_EVENTS_SUBS_H_

/**********************************************************************************************************************************
 * EventsSubs - Public C interface to the EventsSubs object
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

#include "EventFilter.h"
#include "ReportingInformation.h"
#include "AfEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_events_subs_s data_collection_model_events_subs_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create_copy(const data_collection_model_events_subs_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create_move(data_collection_model_events_subs_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_copy(data_collection_model_events_subs_t *events_subs, const data_collection_model_events_subs_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_move(data_collection_model_events_subs_t *events_subs, data_collection_model_events_subs_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_events_subs_free(data_collection_model_events_subs_t *events_subs);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_events_subs_toJSON(const data_collection_model_events_subs_t *events_subs, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_events_subs_is_equal_to(const data_collection_model_events_subs_t *events_subs, const data_collection_model_events_subs_t *other_events_subs);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_t* data_collection_model_events_subs_get_event(const data_collection_model_events_subs_t *events_subs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event(data_collection_model_events_subs_t *events_subs, const data_collection_model_af_event_t* p_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_move(data_collection_model_events_subs_t *events_subs, data_collection_model_af_event_t* p_event);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_filter_t* data_collection_model_events_subs_get_event_filter(const data_collection_model_events_subs_t *events_subs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter(data_collection_model_events_subs_t *events_subs, const data_collection_model_event_filter_t* p_event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter_move(data_collection_model_events_subs_t *events_subs, data_collection_model_event_filter_t* p_event_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_events_subs_has_event_rep_info(const data_collection_model_events_subs_t *events_subs);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_reporting_information_t* data_collection_model_events_subs_get_event_rep_info(const data_collection_model_events_subs_t *events_subs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info(data_collection_model_events_subs_t *events_subs, const data_collection_model_reporting_information_t* p_event_rep_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info_move(data_collection_model_events_subs_t *events_subs, data_collection_model_reporting_information_t* p_event_rep_info);

/* lnode helper for generating ogs_list_t nodes's of type EventsSubs */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_events_subs_make_lnode(data_collection_model_events_subs_t *events_subs);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EVENTS_SUBS_H_ */

