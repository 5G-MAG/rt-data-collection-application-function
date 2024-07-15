#ifndef _DATA_COLLECTION_APP_EXP_UE_BEHAVIOUR_H_
#define _DATA_COLLECTION_APP_EXP_UE_BEHAVIOUR_H_

/**********************************************************************************************************************************
 * AppExpUeBehaviour - Public C interface to the AppExpUeBehaviour object
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

#include "TimeWindow.h"
#include "CpFailureCode.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_app_exp_ue_behaviour_s data_collection_model_app_exp_ue_behaviour_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_copy(const data_collection_model_app_exp_ue_behaviour_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_move(data_collection_model_app_exp_ue_behaviour_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_copy(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_app_exp_ue_behaviour_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_app_exp_ue_behaviour_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_app_exp_ue_behaviour_free(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_app_exp_ue_behaviour_toJSON(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_app_id(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_app_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_app_exp_ue_behaviour_get_exp_pdu_ses_inac_tm(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_app_exp_ue_behaviour_get_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const ogs_list_t* p_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, ogs_list_t* p_flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_add_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_remove_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* flow_descriptions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_clear_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_confidence_level(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_confidence_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_confidence_level);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_accuracy_level(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_accuracy_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_accuracy_level);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cp_failure_code_t* data_collection_model_app_exp_ue_behaviour_get_failure_code(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_cp_failure_code_t* p_failure_code);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_cp_failure_code_t* p_failure_code);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_validity_time(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_validity_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_validity_time);

/* lnode helper for generating ogs_list_t nodes's of type AppExpUeBehaviour */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_app_exp_ue_behaviour_make_lnode(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_APP_EXP_UE_BEHAVIOUR_H_ */

