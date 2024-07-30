#ifndef _DATA_COLLECTION_UE_TRAJECTORY_COLLECTION_H_
#define _DATA_COLLECTION_UE_TRAJECTORY_COLLECTION_H_

/**********************************************************************************************************************************
 * UeTrajectoryCollection - Public C interface to the UeTrajectoryCollection object
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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ue_trajectory_collection_s data_collection_model_ue_trajectory_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create_copy(const data_collection_model_ue_trajectory_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create_move(data_collection_model_ue_trajectory_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_copy(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const data_collection_model_ue_trajectory_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_move(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, data_collection_model_ue_trajectory_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_trajectory_collection_free(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_trajectory_collection_toJSON(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_trajectory_collection_is_equal_to(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const data_collection_model_ue_trajectory_collection_t *other_ue_trajectory_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_trajectory_collection_get_ts(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_ts(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const char* p_ts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_ts_move(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, char* p_ts);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_ue_trajectory_collection_get_loc_area(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_loc_area(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const data_collection_model_location_area5_g_t* p_loc_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_loc_area_move(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, data_collection_model_location_area5_g_t* p_loc_area);

/* lnode helper for generating ogs_list_t nodes's of type UeTrajectoryCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_trajectory_collection_make_lnode(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_TRAJECTORY_COLLECTION_H_ */

