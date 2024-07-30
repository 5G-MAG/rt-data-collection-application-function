#ifndef _DATA_COLLECTION_DISPERSION_COLLECTION_H_
#define _DATA_COLLECTION_DISPERSION_COLLECTION_H_

/**********************************************************************************************************************************
 * DispersionCollection - Public C interface to the DispersionCollection object
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

#include "IpAddr.h"
#include "UsageThreshold.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_dispersion_collection_s data_collection_model_dispersion_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create_copy(const data_collection_model_dispersion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create_move(data_collection_model_dispersion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_copy(data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_dispersion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_move(data_collection_model_dispersion_collection_t *dispersion_collection, data_collection_model_dispersion_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dispersion_collection_free(data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dispersion_collection_toJSON(const data_collection_model_dispersion_collection_t *dispersion_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_is_equal_to(const data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_dispersion_collection_t *other_dispersion_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_gpsi(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_gpsi(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_gpsi_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_supi(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_supi(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_supi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_supi_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_supi);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_dispersion_collection_get_ue_addr(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_ue_addr(data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_ip_addr_t* p_ue_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_ue_addr_move(data_collection_model_dispersion_collection_t *dispersion_collection, data_collection_model_ip_addr_t* p_ue_addr);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_time_stamp(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_time_stamp(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_time_stamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_time_stamp_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_time_stamp);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_usage_threshold_t* data_collection_model_dispersion_collection_get_data_usage(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_data_usage(data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_usage_threshold_t* p_data_usage);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_data_usage_move(data_collection_model_dispersion_collection_t *dispersion_collection, data_collection_model_usage_threshold_t* p_data_usage);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_flow_desp(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_flow_desp(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_flow_desp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_flow_desp_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_flow_desp);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_app_id(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_id(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_id_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dispersion_collection_get_dnais(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_dnais(data_collection_model_dispersion_collection_t *dispersion_collection, const ogs_list_t* p_dnais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_dnais_move(data_collection_model_dispersion_collection_t *dispersion_collection, ogs_list_t* p_dnais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_add_dnais(data_collection_model_dispersion_collection_t *dispersion_collection, char* dnais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_remove_dnais(data_collection_model_dispersion_collection_t *dispersion_collection, const char* dnais);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_clear_dnais(data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_dispersion_collection_get_app_dur(const data_collection_model_dispersion_collection_t *dispersion_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_dur(data_collection_model_dispersion_collection_t *dispersion_collection, const int32_t p_app_dur);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_dur_move(data_collection_model_dispersion_collection_t *dispersion_collection, int32_t p_app_dur);

/* lnode helper for generating ogs_list_t nodes's of type DispersionCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dispersion_collection_make_lnode(data_collection_model_dispersion_collection_t *dispersion_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DISPERSION_COLLECTION_H_ */

