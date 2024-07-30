#ifndef _DATA_COLLECTION_AF_EVENT_NOTIFICATION_H_
#define _DATA_COLLECTION_AF_EVENT_NOTIFICATION_H_

/**********************************************************************************************************************************
 * AfEventNotification - Public C interface to the AfEventNotification object
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

#include "CollectiveBehaviourInfo.h"
#include "ServiceExperienceInfoPerApp.h"
#include "MsConsumptionCollection.h"
#include "QoEMetricsCollection.h"
#include "AfEvent.h"
#include "ConsumptionReportingUnitsCollection.h"
#include "PerformanceDataCollection.h"
#include "NetworkAssistanceInvocationsCollection.h"
#include "UeCommunicationCollection.h"
#include "DynamicPolicyInvocationsCollection.h"
#include "DispersionCollection.h"
#include "ExceptionInfo.h"
#include "MsQoeMetricsCollection.h"
#include "UserDataCongestionCollection.h"
#include "UeMobilityCollection.h"
#include "GNSSAssistDataInfo.h"
#include "MediaStreamingAccessesCollection.h"
#include "MsDynPolicyInvocationCollection.h"
#include "MsNetAssInvocationCollection.h"
#include "DatVolTransTimeCollection.h"
#include "MSAccessActivityCollection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_af_event_notification_s data_collection_model_af_event_notification_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create_copy(const data_collection_model_af_event_notification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create_move(data_collection_model_af_event_notification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_copy(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_af_event_notification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_move(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_af_event_notification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_notification_free(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_notification_toJSON(const data_collection_model_af_event_notification_t *af_event_notification, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_is_equal_to(const data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_af_event_notification_t *other_af_event_notification);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_t* data_collection_model_af_event_notification_get_event(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_event(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_af_event_t* p_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_event_move(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_af_event_t* p_event);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_notification_get_time_stamp(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_time_stamp(data_collection_model_af_event_notification_t *af_event_notification, const char* p_time_stamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_time_stamp_move(data_collection_model_af_event_notification_t *af_event_notification, char* p_time_stamp);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_svc_exprc_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_svc_exprc_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_svc_exprc_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_svc_exprc_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_service_experience_info_per_app_t* svc_exprc_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_service_experience_info_per_app_t* svc_exprc_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ue_mobility_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ue_mobility_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_mobility_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ue_mobility_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ue_mobility_collection_t* ue_mobility_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ue_mobility_collection_t* ue_mobility_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ue_comm_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ue_comm_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_comm_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ue_comm_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ue_communication_collection_t* ue_comm_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ue_communication_collection_t* ue_comm_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_excep_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_excep_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_excep_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_excep_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_excep_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_excep_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_exception_info_t* excep_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_excep_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_exception_info_t* excep_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_excep_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_congestion_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_congestion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_congestion_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_congestion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_user_data_congestion_collection_t* congestion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_user_data_congestion_collection_t* congestion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_perf_data_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_perf_data_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_perf_data_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_perf_data_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_performance_data_collection_t* perf_data_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_performance_data_collection_t* perf_data_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_dispersion_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_dispersion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dispersion_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_dispersion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_dispersion_collection_t* dispersion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_dispersion_collection_t* dispersion_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_coll_bhvr_infs(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_coll_bhvr_infs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_coll_bhvr_infs_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_coll_bhvr_infs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_collective_behaviour_info_t* coll_bhvr_infs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_collective_behaviour_info_t* coll_bhvr_infs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_qoe_metr_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_qoe_metr_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metr_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_qoe_metr_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_qoe_metrics_collection_t* ms_qoe_metr_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_qoe_metrics_collection_t* ms_qoe_metr_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_qoe_metrics(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_qoe_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metrics_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_qoe_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_qo_e_metrics_collection_t* ms_qoe_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_qo_e_metrics_collection_t* ms_qoe_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_consump_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_consump_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_consump_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_consumption_collection_t* ms_consump_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_consumption_collection_t* ms_consump_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_consump_rpts(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_consump_rpts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_rpts_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_consump_rpts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_consumption_reporting_units_collection_t* ms_consump_rpts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_consumption_reporting_units_collection_t* ms_consump_rpts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_net_ass_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_net_ass_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_ass_inv_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_net_ass_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_net_ass_invocation_collection_t* ms_net_ass_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_net_ass_invocation_collection_t* ms_net_ass_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_net_assist_invs(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_net_assist_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_assist_invs_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_net_assist_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_network_assistance_invocations_collection_t* ms_net_assist_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_network_assistance_invocations_collection_t* ms_net_assist_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_dyn_ply_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_dyn_ply_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_inv_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_dyn_ply_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_dyn_policy_invocation_collection_t* ms_dyn_ply_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_dyn_policy_invocation_collection_t* ms_dyn_ply_inv_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_dyn_ply_invs(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_dyn_ply_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_invs_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_dyn_ply_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_dynamic_policy_invocations_collection_t* ms_dyn_ply_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_dynamic_policy_invocations_collection_t* ms_dyn_ply_invs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_acc_act_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_acc_act_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_acc_act_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_acc_act_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_access_activity_collection_t* ms_acc_act_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_access_activity_collection_t* ms_acc_act_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_accesses(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_accesses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_accesses_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_accesses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_media_streaming_accesses_collection_t* ms_accesses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_media_streaming_accesses_collection_t* ms_accesses);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_assist_data_info_t* data_collection_model_af_event_notification_get_gnss_assist_data_info(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_gnss_assist_data_info(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_gnss_assist_data_info_t* p_gnss_assist_data_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_gnss_assist_data_info_move(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_gnss_assist_data_info_t* p_gnss_assist_data_info);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_dat_vol_trans_time_infos(const data_collection_model_af_event_notification_t *af_event_notification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_dat_vol_trans_time_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dat_vol_trans_time_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_dat_vol_trans_time_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_dat_vol_trans_time_collection_t* dat_vol_trans_time_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_dat_vol_trans_time_collection_t* dat_vol_trans_time_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification);

/* lnode helper for generating ogs_list_t nodes's of type AfEventNotification */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_notification_make_lnode(data_collection_model_af_event_notification_t *af_event_notification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_AF_EVENT_NOTIFICATION_H_ */

