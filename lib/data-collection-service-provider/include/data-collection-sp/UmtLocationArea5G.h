#ifndef _DATA_COLLECTION_UMT_LOCATION_AREA5_G_H_
#define _DATA_COLLECTION_UMT_LOCATION_AREA5_G_H_

/**********************************************************************************************************************************
 * UmtLocationArea5G - Public C interface to the UmtLocationArea5G object
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

#include "CivicAddress.h"
#include "GeographicArea.h"
#include "NetworkAreaInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_umt_location_area5_g_s data_collection_model_umt_location_area5_g_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_create_copy(const data_collection_model_umt_location_area5_g_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_create_move(data_collection_model_umt_location_area5_g_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_copy(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const data_collection_model_umt_location_area5_g_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_move(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, data_collection_model_umt_location_area5_g_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_umt_location_area5_g_free(data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_umt_location_area5_g_toJSON(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_umt_location_area5_g_is_equal_to(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const data_collection_model_umt_location_area5_g_t *other_umt_location_area5_g);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_umt_location_area5_g_get_geographic_areas(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_geographic_areas(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const ogs_list_t* p_geographic_areas);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_geographic_areas_move(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, ogs_list_t* p_geographic_areas);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_add_geographic_areas(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, data_collection_model_geographic_area_t* geographic_areas);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_remove_geographic_areas(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const data_collection_model_geographic_area_t* geographic_areas);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_clear_geographic_areas(data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_umt_location_area5_g_get_civic_addresses(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_civic_addresses(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const ogs_list_t* p_civic_addresses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_civic_addresses_move(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, ogs_list_t* p_civic_addresses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_add_civic_addresses(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, data_collection_model_civic_address_t* civic_addresses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_remove_civic_addresses(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const data_collection_model_civic_address_t* civic_addresses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_clear_civic_addresses(data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_area_info_t* data_collection_model_umt_location_area5_g_get_nw_area_info(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_nw_area_info(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const data_collection_model_network_area_info_t* p_nw_area_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_nw_area_info_move(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, data_collection_model_network_area_info_t* p_nw_area_info);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_umt_location_area5_g_get_umt_time(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_time(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const char* p_umt_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_time_move(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, char* p_umt_time);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_umt_location_area5_g_get_umt_duration(const data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_duration(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, const int32_t p_umt_duration);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_umt_location_area5_g_t *data_collection_model_umt_location_area5_g_set_umt_duration_move(data_collection_model_umt_location_area5_g_t *umt_location_area5_g, int32_t p_umt_duration);

/* lnode helper for generating ogs_list_t nodes's of type UmtLocationArea5G */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_umt_location_area5_g_make_lnode(data_collection_model_umt_location_area5_g_t *umt_location_area5_g);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UMT_LOCATION_AREA5_G_H_ */

