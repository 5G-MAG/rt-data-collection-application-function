#ifndef _DATA_COLLECTION_REPORTING_INFORMATION_H_
#define _DATA_COLLECTION_REPORTING_INFORMATION_H_

/**********************************************************************************************************************************
 * ReportingInformation - Public C interface to the ReportingInformation object
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

#include "NotificationFlag.h"
#include "MutingExceptionInstructions.h"
#include "PartitioningCriteria.h"
#include "NotificationMethod.h"
#include "MutingNotificationsSettings.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_reporting_information_s data_collection_model_reporting_information_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_create_copy(const data_collection_model_reporting_information_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_create_move(data_collection_model_reporting_information_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_copy(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_reporting_information_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_reporting_information_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_reporting_information_free(data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_reporting_information_toJSON(const data_collection_model_reporting_information_t *reporting_information, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_reporting_information_is_imm_rep(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_imm_rep(data_collection_model_reporting_information_t *reporting_information, const bool p_imm_rep);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_imm_rep_move(data_collection_model_reporting_information_t *reporting_information, bool p_imm_rep);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_notification_method_t* data_collection_model_reporting_information_get_notif_method(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_method(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_notification_method_t* p_notif_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_method_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_notification_method_t* p_notif_method);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_max_report_nbr(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_max_report_nbr(data_collection_model_reporting_information_t *reporting_information, const int32_t p_max_report_nbr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_max_report_nbr_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_max_report_nbr);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_reporting_information_get_mon_dur(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_mon_dur(data_collection_model_reporting_information_t *reporting_information, const char* p_mon_dur);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_mon_dur_move(data_collection_model_reporting_information_t *reporting_information, char* p_mon_dur);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_rep_period(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_rep_period(data_collection_model_reporting_information_t *reporting_information, const int32_t p_rep_period);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_rep_period_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_rep_period);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_samp_ratio(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_samp_ratio(data_collection_model_reporting_information_t *reporting_information, const int32_t p_samp_ratio);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_samp_ratio_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_samp_ratio);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_reporting_information_get_partition_criteria(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_partition_criteria(data_collection_model_reporting_information_t *reporting_information, const ogs_list_t* p_partition_criteria);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_partition_criteria_move(data_collection_model_reporting_information_t *reporting_information, ogs_list_t* p_partition_criteria);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_add_partition_criteria(data_collection_model_reporting_information_t *reporting_information, data_collection_model_partitioning_criteria_t* partition_criteria);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_remove_partition_criteria(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_partitioning_criteria_t* partition_criteria);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_clear_partition_criteria(data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_grp_rep_time(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_grp_rep_time(data_collection_model_reporting_information_t *reporting_information, const int32_t p_grp_rep_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_grp_rep_time_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_grp_rep_time);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_notification_flag_t* data_collection_model_reporting_information_get_notif_flag(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_notification_flag_t* p_notif_flag);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_notification_flag_t* p_notif_flag);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_muting_exception_instructions_t* data_collection_model_reporting_information_get_notif_flag_instruct(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_instruct(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_muting_exception_instructions_t* p_notif_flag_instruct);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_instruct_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_muting_exception_instructions_t* p_notif_flag_instruct);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_muting_notifications_settings_t* data_collection_model_reporting_information_get_muting_setting(const data_collection_model_reporting_information_t *reporting_information);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_muting_setting(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_muting_notifications_settings_t* p_muting_setting);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_muting_setting_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_muting_notifications_settings_t* p_muting_setting);

/* lnode helper for generating ogs_list_t nodes's of type ReportingInformation */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_reporting_information_make_lnode(data_collection_model_reporting_information_t *reporting_information);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_REPORTING_INFORMATION_H_ */

