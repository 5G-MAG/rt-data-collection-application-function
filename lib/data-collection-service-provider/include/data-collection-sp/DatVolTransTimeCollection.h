#ifndef _DATA_COLLECTION_DAT_VOL_TRANS_TIME_COLLECTION_H_
#define _DATA_COLLECTION_DAT_VOL_TRANS_TIME_COLLECTION_H_

/**********************************************************************************************************************************
 * DatVolTransTimeCollection - Public C interface to the DatVolTransTimeCollection object
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

#include "AddrFqdn.h"
#include "TimeWindow.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_dat_vol_trans_time_collection_s data_collection_model_dat_vol_trans_time_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_copy(const data_collection_model_dat_vol_trans_time_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_move(data_collection_model_dat_vol_trans_time_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_copy(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_dat_vol_trans_time_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_dat_vol_trans_time_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dat_vol_trans_time_collection_free(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dat_vol_trans_time_collection_toJSON(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_is_equal_to(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_dat_vol_trans_time_collection_t *other_dat_vol_trans_time_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_app_id(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_dat_vol_trans_time_collection_get_app_server_inst(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_addr_fqdn_t* p_app_server_inst);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_addr_fqdn_t* p_app_server_inst);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_gpsi(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_supi(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const char* p_supi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, char* p_supi);

DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_dat_vol_trans_time_collection_get_ul_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const int64_t p_ul_trans_vol);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, int64_t p_ul_trans_vol);

DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_dat_vol_trans_time_collection_get_dl_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const int64_t p_dl_trans_vol);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, int64_t p_dl_trans_vol);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_ul_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_ul_trans_time_dur);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_time_window_t* p_ul_trans_time_dur);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_dl_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_dl_trans_time_dur);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_time_window_t* p_dl_trans_time_dur);

/* lnode helper for generating ogs_list_t nodes's of type DatVolTransTimeCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dat_vol_trans_time_collection_make_lnode(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DAT_VOL_TRANS_TIME_COLLECTION_H_ */
