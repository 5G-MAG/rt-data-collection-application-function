#ifndef _DATA_COLLECTION_UE_COMMUNICATION_COLLECTION_H_
#define _DATA_COLLECTION_UE_COMMUNICATION_COLLECTION_H_

/**********************************************************************************************************************************
 * UeCommunicationCollection - Public C interface to the UeCommunicationCollection object
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

#include "CpParameterSet.h"
#include "CommunicationCollection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ue_communication_collection_s data_collection_model_ue_communication_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create_copy(const data_collection_model_ue_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create_move(data_collection_model_ue_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_copy(data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_ue_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, data_collection_model_ue_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_communication_collection_free(data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_communication_collection_toJSON(const data_collection_model_ue_communication_collection_t *ue_communication_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_is_equal_to(const data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_ue_communication_collection_t *other_ue_communication_collection);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_gpsi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_gpsi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_gpsi(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_gpsi_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_gpsi);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_supi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_supi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_supi(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_supi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_supi_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_supi);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_exter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_exter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_exter_group_id(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_exter_group_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_exter_group_id_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_exter_group_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_inter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_inter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_inter_group_id(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_inter_group_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_inter_group_id_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_inter_group_id);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_app_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_app_id(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_app_id_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_expected_ue_behave_para(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cp_parameter_set_t* data_collection_model_ue_communication_collection_get_expected_ue_behave_para(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_expected_ue_behave_para(data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_cp_parameter_set_t* p_expected_ue_behave_para);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_expected_ue_behave_para_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, data_collection_model_cp_parameter_set_t* p_expected_ue_behave_para);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ue_communication_collection_get_comms(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection, const ogs_list_t* p_comms);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_comms_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, ogs_list_t* p_comms);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_add_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection, data_collection_model_communication_collection_t* comms);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_remove_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_communication_collection_t* comms);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_clear_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection);

/* lnode helper for generating ogs_list_t nodes's of type UeCommunicationCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_communication_collection_make_lnode(data_collection_model_ue_communication_collection_t *ue_communication_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_COMMUNICATION_COLLECTION_H_ */

