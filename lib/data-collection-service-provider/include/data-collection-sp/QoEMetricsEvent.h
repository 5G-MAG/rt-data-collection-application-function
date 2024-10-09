#ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_H_
#define _DATA_COLLECTION_QO_E_METRICS_EVENT_H_

/**********************************************************************************************************************************
 * QoEMetricsEvent - Public C interface to the QoEMetricsEvent object
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

#include "QoEMetricsEvent_allOf_samples.h"
#include "EventRecordType.h"
#include "LocationArea5G.h"
#include "Snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_qo_e_metrics_event_s data_collection_model_qo_e_metrics_event_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_create_copy(const data_collection_model_qo_e_metrics_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_create_move(data_collection_model_qo_e_metrics_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_copy(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const data_collection_model_qo_e_metrics_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, data_collection_model_qo_e_metrics_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_qo_e_metrics_event_free(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_qo_e_metrics_event_toJSON(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_is_equal_to(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const data_collection_model_qo_e_metrics_event_t *other_qo_e_metrics_event);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_qo_e_metrics_event_get_record_type(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_record_type(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const data_collection_model_event_record_type_t* p_record_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_record_type_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, data_collection_model_event_record_type_t* p_record_type);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_get_record_timestamp(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_record_timestamp(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const char* p_record_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_record_timestamp_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, char* p_record_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_get_app_id(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_app_id(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_app_id_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_has_provisioning_session_id(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_get_provisioning_session_id(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_provisioning_session_id(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_provisioning_session_id_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_has_session_id(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_get_session_id(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_session_id(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_session_id_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_has_ue_identification(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_get_ue_identification(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_ue_identification(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const char* p_ue_identification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_ue_identification_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, char* p_ue_identification);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_has_data_network_name(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_get_data_network_name(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_data_network_name(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_data_network_name_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_has_slice_id(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_qo_e_metrics_event_get_slice_id(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_slice_id(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const data_collection_model_snssai_t* p_slice_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_slice_id_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, data_collection_model_snssai_t* p_slice_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_has_ue_locations(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_qo_e_metrics_event_get_ue_locations(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_ue_locations(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const ogs_list_t* p_ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_ue_locations_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, ogs_list_t* p_ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_add_ue_locations(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, data_collection_model_location_area5_g_t* ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_remove_ue_locations(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const data_collection_model_location_area5_g_t* ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_qo_e_metrics_event_get_entry_ue_locations(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_clear_ue_locations(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_get_metric_type(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_metric_type(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const char* p_metric_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_metric_type_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, char* p_metric_type);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_has_samples(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_qo_e_metrics_event_get_samples(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_samples(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const ogs_list_t* p_samples);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_set_samples_move(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, ogs_list_t* p_samples);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_add_samples(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, data_collection_model_qo_e_metrics_event_all_of_samples_t* samples);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_remove_samples(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, const data_collection_model_qo_e_metrics_event_all_of_samples_t* samples);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_qo_e_metrics_event_all_of_samples_t* data_collection_model_qo_e_metrics_event_get_entry_samples(const data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_t *data_collection_model_qo_e_metrics_event_clear_samples(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

/* lnode helper for generating ogs_list_t nodes's of type QoEMetricsEvent */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_qo_e_metrics_event_make_lnode(data_collection_model_qo_e_metrics_event_t *qo_e_metrics_event);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_H_ */

