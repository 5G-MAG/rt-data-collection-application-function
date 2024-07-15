#ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_METRICS_H_
#define _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_METRICS_H_

/**********************************************************************************************************************************
 * QoEMetricsEvent_allOf_metrics - Public C interface to the QoEMetricsEvent_allOf_metrics object
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

#include "AnyType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_qo_e_metrics_event_all_of_metrics_s data_collection_model_qo_e_metrics_event_all_of_metrics_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_copy(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_copy(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_qo_e_metrics_event_all_of_metrics_free(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_qo_e_metrics_event_all_of_metrics_toJSON(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_metrics_get_key(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const char* p_key);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, char* p_key);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_any_type_t* data_collection_model_qo_e_metrics_event_all_of_metrics_get_value(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const data_collection_model_any_type_t* p_value);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, data_collection_model_any_type_t* p_value);

/* lnode helper for generating ogs_list_t nodes's of type QoEMetricsEvent_allOf_metrics */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_metrics_make_lnode(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_METRICS_H_ */

