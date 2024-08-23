#ifndef _DATA_COLLECTION_EVENT_FILTER_H_
#define _DATA_COLLECTION_EVENT_FILTER_H_

/**********************************************************************************************************************************
 * EventFilter - Public C interface to the EventFilter object
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
#include "Exception.h"
#include "LocationArea5G.h"
#include "CollectiveBehaviourFilter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_event_filter_s data_collection_model_event_filter_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create_copy(const data_collection_model_event_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_create_move(data_collection_model_event_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_copy(data_collection_model_event_filter_t *event_filter, const data_collection_model_event_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_move(data_collection_model_event_filter_t *event_filter, data_collection_model_event_filter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_event_filter_free(data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_event_filter_toJSON(const data_collection_model_event_filter_t *event_filter, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_is_equal_to(const data_collection_model_event_filter_t *event_filter, const data_collection_model_event_filter_t *other_event_filter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_gpsis(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_gpsis(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_gpsis(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_gpsis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_gpsis_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_gpsis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_gpsis(data_collection_model_event_filter_t *event_filter, char* gpsis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_gpsis(data_collection_model_event_filter_t *event_filter, const char* gpsis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_gpsis(data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_supis(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_supis(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_supis(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_supis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_supis_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_supis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_supis(data_collection_model_event_filter_t *event_filter, char* supis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_supis(data_collection_model_event_filter_t *event_filter, const char* supis);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_supis(data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_exter_group_ids(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_exter_group_ids(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exter_group_ids(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_exter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exter_group_ids_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_exter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_exter_group_ids(data_collection_model_event_filter_t *event_filter, char* exter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_exter_group_ids(data_collection_model_event_filter_t *event_filter, const char* exter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_exter_group_ids(data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_inter_group_ids(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_inter_group_ids(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_inter_group_ids(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_inter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_inter_group_ids_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_inter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_inter_group_ids(data_collection_model_event_filter_t *event_filter, char* inter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_inter_group_ids(data_collection_model_event_filter_t *event_filter, const char* inter_group_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_inter_group_ids(data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_any_ue_ind(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_event_filter_is_any_ue_ind(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_any_ue_ind(data_collection_model_event_filter_t *event_filter, const bool p_any_ue_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_any_ue_ind_move(data_collection_model_event_filter_t *event_filter, bool p_any_ue_ind);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_ue_ip_addr(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_event_filter_get_ue_ip_addr(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_ue_ip_addr(data_collection_model_event_filter_t *event_filter, const data_collection_model_ip_addr_t* p_ue_ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_ue_ip_addr_move(data_collection_model_event_filter_t *event_filter, data_collection_model_ip_addr_t* p_ue_ip_addr);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_app_ids(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_app_ids(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_app_ids(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_app_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_app_ids_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_app_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_app_ids(data_collection_model_event_filter_t *event_filter, char* app_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_app_ids(data_collection_model_event_filter_t *event_filter, const char* app_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_app_ids(data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_loc_area(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_event_filter_get_loc_area(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_loc_area(data_collection_model_event_filter_t *event_filter, const data_collection_model_location_area5_g_t* p_loc_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_loc_area_move(data_collection_model_event_filter_t *event_filter, data_collection_model_location_area5_g_t* p_loc_area);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_coll_attrs(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_coll_attrs(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_coll_attrs(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_coll_attrs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_coll_attrs_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_coll_attrs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_coll_attrs(data_collection_model_event_filter_t *event_filter, data_collection_model_collective_behaviour_filter_t* coll_attrs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_coll_attrs(data_collection_model_event_filter_t *event_filter, const data_collection_model_collective_behaviour_filter_t* coll_attrs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_coll_attrs(data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_event_filter_has_exception_reqs(const data_collection_model_event_filter_t *event_filter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_event_filter_get_exception_reqs(const data_collection_model_event_filter_t *event_filter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exception_reqs(data_collection_model_event_filter_t *event_filter, const ogs_list_t* p_exception_reqs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_set_exception_reqs_move(data_collection_model_event_filter_t *event_filter, ogs_list_t* p_exception_reqs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_add_exception_reqs(data_collection_model_event_filter_t *event_filter, data_collection_model_exception_t* exception_reqs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_remove_exception_reqs(data_collection_model_event_filter_t *event_filter, const data_collection_model_exception_t* exception_reqs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_event_filter_t *data_collection_model_event_filter_clear_exception_reqs(data_collection_model_event_filter_t *event_filter);

/* lnode helper for generating ogs_list_t nodes's of type EventFilter */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_event_filter_make_lnode(data_collection_model_event_filter_t *event_filter);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EVENT_FILTER_H_ */

