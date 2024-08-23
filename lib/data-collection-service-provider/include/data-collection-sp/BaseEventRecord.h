#ifndef _DATA_COLLECTION_BASE_EVENT_RECORD_H_
#define _DATA_COLLECTION_BASE_EVENT_RECORD_H_

/**********************************************************************************************************************************
 * BaseEventRecord - Public C interface to the BaseEventRecord object
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

#include "EventRecordType.h"
#include "LocationArea5G.h"
#include "Snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_base_event_record_s data_collection_model_base_event_record_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_create_copy(const data_collection_model_base_event_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_create_move(data_collection_model_base_event_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_copy(data_collection_model_base_event_record_t *base_event_record, const data_collection_model_base_event_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_move(data_collection_model_base_event_record_t *base_event_record, data_collection_model_base_event_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_event_record_free(data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_event_record_toJSON(const data_collection_model_base_event_record_t *base_event_record, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_is_equal_to(const data_collection_model_base_event_record_t *base_event_record, const data_collection_model_base_event_record_t *other_base_event_record);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_base_event_record_get_record_type(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_type(data_collection_model_base_event_record_t *base_event_record, const data_collection_model_event_record_type_t* p_record_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_type_move(data_collection_model_base_event_record_t *base_event_record, data_collection_model_event_record_type_t* p_record_type);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_record_timestamp(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_timestamp(data_collection_model_base_event_record_t *base_event_record, const char* p_record_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_record_timestamp_move(data_collection_model_base_event_record_t *base_event_record, char* p_record_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_app_id(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_app_id(data_collection_model_base_event_record_t *base_event_record, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_app_id_move(data_collection_model_base_event_record_t *base_event_record, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_provisioning_session_id(const data_collection_model_base_event_record_t *base_event_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_provisioning_session_id(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_provisioning_session_id(data_collection_model_base_event_record_t *base_event_record, const char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_provisioning_session_id_move(data_collection_model_base_event_record_t *base_event_record, char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_session_id(const data_collection_model_base_event_record_t *base_event_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_session_id(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_session_id(data_collection_model_base_event_record_t *base_event_record, const char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_session_id_move(data_collection_model_base_event_record_t *base_event_record, char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_ue_identification(const data_collection_model_base_event_record_t *base_event_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_ue_identification(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_identification(data_collection_model_base_event_record_t *base_event_record, const char* p_ue_identification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_identification_move(data_collection_model_base_event_record_t *base_event_record, char* p_ue_identification);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_data_network_name(const data_collection_model_base_event_record_t *base_event_record);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_event_record_get_data_network_name(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_data_network_name(data_collection_model_base_event_record_t *base_event_record, const char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_data_network_name_move(data_collection_model_base_event_record_t *base_event_record, char* p_data_network_name);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_slice_id(const data_collection_model_base_event_record_t *base_event_record);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_base_event_record_get_slice_id(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_slice_id(data_collection_model_base_event_record_t *base_event_record, const data_collection_model_snssai_t* p_slice_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_slice_id_move(data_collection_model_base_event_record_t *base_event_record, data_collection_model_snssai_t* p_slice_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_event_record_has_ue_locations(const data_collection_model_base_event_record_t *base_event_record);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_event_record_get_ue_locations(const data_collection_model_base_event_record_t *base_event_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_locations(data_collection_model_base_event_record_t *base_event_record, const ogs_list_t* p_ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_set_ue_locations_move(data_collection_model_base_event_record_t *base_event_record, ogs_list_t* p_ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_add_ue_locations(data_collection_model_base_event_record_t *base_event_record, data_collection_model_location_area5_g_t* ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_remove_ue_locations(data_collection_model_base_event_record_t *base_event_record, const data_collection_model_location_area5_g_t* ue_locations);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_event_record_t *data_collection_model_base_event_record_clear_ue_locations(data_collection_model_base_event_record_t *base_event_record);

/* lnode helper for generating ogs_list_t nodes's of type BaseEventRecord */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_event_record_make_lnode(data_collection_model_base_event_record_t *base_event_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_BASE_EVENT_RECORD_H_ */

