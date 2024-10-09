#ifndef _DATA_COLLECTION_UE_MOBILITY_COLLECTION_H_
#define _DATA_COLLECTION_UE_MOBILITY_COLLECTION_H_

/**********************************************************************************************************************************
 * UeMobilityCollection - Public C interface to the UeMobilityCollection object
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

#include "LocationArea5G.h"
#include "UeTrajectoryCollection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ue_mobility_collection_s data_collection_model_ue_mobility_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create_copy(const data_collection_model_ue_mobility_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_create_move(data_collection_model_ue_mobility_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_copy(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_ue_mobility_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, data_collection_model_ue_mobility_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_mobility_collection_free(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_mobility_collection_toJSON(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_is_equal_to(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_ue_mobility_collection_t *other_ue_mobility_collection);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_gpsi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_mobility_collection_get_gpsi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_gpsi(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_gpsi_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_supi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_mobility_collection_get_supi(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_supi(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const char* p_supi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_supi_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, char* p_supi);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_mobility_collection_get_app_id(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_app_id(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_app_id_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_all_app_ind(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_ue_mobility_collection_is_all_app_ind(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_all_app_ind(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const bool p_all_app_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_all_app_ind_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, bool p_all_app_ind);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ue_mobility_collection_get_ue_trajs(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const ogs_list_t* p_ue_trajs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_ue_trajs_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, ogs_list_t* p_ue_trajs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_add_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, data_collection_model_ue_trajectory_collection_t* ue_trajs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_remove_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_ue_trajectory_collection_t* ue_trajs);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_trajectory_collection_t* data_collection_model_ue_mobility_collection_get_entry_ue_trajs(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_clear_ue_trajs(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_mobility_collection_has_areas(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ue_mobility_collection_get_areas(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const ogs_list_t* p_areas);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_set_areas_move(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, ogs_list_t* p_areas);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_add_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, data_collection_model_location_area5_g_t* areas);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_remove_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection, const data_collection_model_location_area5_g_t* areas);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_ue_mobility_collection_get_entry_areas(const data_collection_model_ue_mobility_collection_t *ue_mobility_collection, size_t idx);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_mobility_collection_t *data_collection_model_ue_mobility_collection_clear_areas(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/* lnode helper for generating ogs_list_t nodes's of type UeMobilityCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_mobility_collection_make_lnode(data_collection_model_ue_mobility_collection_t *ue_mobility_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_MOBILITY_COLLECTION_H_ */

