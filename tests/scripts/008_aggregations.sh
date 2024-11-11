:
#
# 5G-MAG Reference Tools: DCAF regression test 8: Aggregation
# ============================================================================
#
# Copyright: ©2024 British Broadcasting Corporation
#   License: 5G-MAG Public License v1.0
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
#
# ============================================================================
# This script provides regression tests to test Aggregation function results for event
# exposure.
#


app_id_aggregation="MyAppId_Aggregation"

create_provisioning_session_aggregation() {
  local config_json="$1"
  inc total_count

  if [ -n "$af_event_exposure_notif_url" ]; then
    http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions" '{"aspId": "MyASPId", "externalApplicationId": "'"$app_id_aggregation"'", "eventId": "UE_COMM"}'
    if [ "$resp_statuscode" = "200" ]; then
      psid_aggregation="${resp_location##*/}"
      http_post_file "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$psid_aggregation/configurations" $config_json
      if [ "$resp_statuscode" = "200" ]; then
        inc ok_count
        config_id_aggregation="${resp_location##*/}"
      else
        log_bad_response
        inc fail_count
      fi
    else
      log_bad_response
      inc fail_count
    fi  
  else
    inc skip_count
  fi
}

destroy_provisioning_session_aggregation() {
  inc total_count
  if [ -n "$psid_aggregation" ]; then
    http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$psid_aggregation"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      config_id_aggregation=
      psid_aggregation=
    else
      log_bad_response
      inc fail_count
    fi
  else
    inc skip_count
  fi
}

check_time_sampling_rules_aggregation() {
  local json_path_prefix="$1"

  # check the samplingRules array for a DataReportingSession response for aggregation function tests

  return 0
}

check_reporting_rules_aggregation() {
  local json_path_prefix="$1"

  # check the reportingRules array for a DataReportingSession response for aggregation function tests

  return 0
}

check_reporting_conditions_aggregation() {
  local json_path_prefix="$1"

  # check the reportingConditions array for a DataReportingSession response for aggregation function tests

  return 0
}

create_reporting_session_aggregation() {
  inc total_count
  if [ -n "$psid_aggregation" ]; then
    http_post_json "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions" '{"externalApplicationId": "'"$app_id_aggregation"'", "supportedDomains": ["COMMUNICATION"]}'
    if [ "$resp_statuscode" = "201" ]; then
      if cmp_field_str 'sessionId' "${resp_location##*/}" && cmp_field_not_exists 'validUntil' && \
         cmp_field_str 'externalApplicationId' "$app_id_aggregation" && \
         cmp_field_array_str 'supportedDomains' 'COMMUNICATION' && \
         cmp_field_exists 'samplingRules' && check_time_sampling_rules_aggregation 'samplingRules.COMMUNICATION' && \
         cmp_field_exists 'reportingRules' && check_reporting_rules_aggregation 'reportingRules.COMMUNICATION' && \
         cmp_field_exists 'reportingConditions' && check_reporting_conditions_aggregation 'reportingConditions.COMMUNICATION'; \
      then
	inc ok_count
	rsid_aggregation="${resp_location##*/}"
      else
        inc fail_count
      fi
    else
      log_bad_response
      inc fail_count
    fi
  else
    inc skip_count
  fi
}

destroy_reporting_session_aggregation() {
  inc total_count
  if [ -n "$rsid_aggregation" ]; then
    http_delete "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$rsid_aggregation"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      rsid_aggregation=
    else
      log_bad_response
      inc fail_count
    fi
  else
    inc skip_count
  fi 
}

submit_data_records_aggregation() {
  local timestart="$1"
  local uplink_vol="$2"
  local downlink_vol="$3"	
  inc total_count
  if [ -n "$rsid_aggregation" ]; then
    
    local now="$(TZ=UTC date $iso_datetime_format)"
    local timeend="$((timestart + 10))"
    local ts_start="$(TZ=UTC date --date="@$timestart" $iso_datetime_format)"
    local ts_end="$(TZ=UTC date --date="@$timeend" $iso_datetime_format)"
	  
    http_post_json "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$rsid_aggregation/report" '{"externalApplicationId": "'"$app_id_aggregation"'", "communicationRecords": [{"timestamp": "'"$now"'", "contextIds": ["'"$config_id_aggregation"'"], "timeInterval": {"startTime": "'"$ts_start"'", "stopTime": "'"$ts_end"'"}, "uplinkVolume": '"$uplink_vol"', "downlinkVolume": '"$downlink_vol"'}]}'
    if [ "$resp_statuscode" = "200" ]; then
      inc ok_count
    elif [ "$resp_statuscode" = "204" ]; then
      inc ok_count
    else
      log_bad_response
      inc fail_count
    fi
  else
    inc skip_count
  fi
}

create_event_exposure_subsc_aggregation() {
  inc total_count

  http_post_json "$dcaf_eventConsumerApplicationFunctionEventExposure_address" "/naf-eventexposure/v1/subscriptions" '{"eventsSubs":[{"event": "UE_COMM", "eventFilter": {"appIds": ["'"$app_id_aggregation"'"]}}], "eventsRepInfo": {"immRep": true, "notifMethod": "PERIODIC", "repPeriod": '"$event_rep_period"'}, "notifUri": "'"$af_event_exposure_notif_url"'", "notifId": "events-notifications-id", "suppFeat": "04"}'


  if [ "$resp_statuscode" = "201" ]; then
    inc ok_count
    event_exposure_subsc_etag_aggregation="$resp_etag"
    event_exposure_subsc_last_modified_aggregation="$resp_last_modified"
    event_exposure_subsc_id_aggregation="${resp_location##*/}"
  else
    inc fail_count
    log_bad_response
  fi
}

destroy_event_exposure_subscription_aggregation() {
  inc total_count
  if [ -n "$event_exposure_subsc_id_aggregation" ]; then
    http_delete "$dcaf_eventConsumerApplicationFunctionEventExposure_address" "/naf-eventexposure/v1/subscriptions/$event_exposure_subsc_id_aggregation"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      event_exposure_subsc_id_aggregation=
    else
      inc fail_count
      log_bad_response
    fi
  else
    inc skip_count
    log_warn "Delete AfEventExposureSubsc in aggregation functions test skipped due to missing afEventExposureSubscId"
  fi
}

check_logged_last_event_notification_ulVol_max() {
  ev_ul_field="$1"
  inc total_count
  if cmp_field_exists "$ev_ul_field" && cmp_field_array_size "$ev_ul_field" 1 && cmp_field_int "${ev_ul_field}[0].ulVol" 600; then
    inc ok_count
  else
    inc fail_count
    log_error "ulVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification_dlVol_max() {
  ev_dl_field="$1"
  inc total_count
  if cmp_field_exists "$ev_dl_field" && cmp_field_array_size "$ev_dl_field" 1 && cmp_field_int "${ev_dl_field}[0].dlVol" 5000; then
    inc ok_count
  else
    inc fail_count
    log_error "dlVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification_ulVol_min() {
  ev_ul_field="$1"
  inc total_count
  if cmp_field_exists "$ev_ul_field" && cmp_field_array_size "$ev_ul_field" 1 && cmp_field_int "${ev_ul_field}[0].ulVol" 300; then
    inc ok_count
  else
    inc fail_count
    log_error "ulVol of the last event notiication does not match the expected value"
  fi
}


check_logged_last_event_notification_dlVol_min() {
  ev_dl_field="$1"
  inc total_count
  if cmp_field_exists "$ev_dl_field" && cmp_field_array_size "$ev_dl_field" 1 && cmp_field_int "${ev_dl_field}[0].dlVol" 4000; then
    inc ok_count
  else
    inc fail_count
    log_error "dlVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification_min() {
  evField="eventNotifs[0].ueCommInfos[0].comms"
  response=$(jq -s '.[-1].body' "$notification_logfile")
  check_logged_last_event_notification_ulVol_min "$evField"
  check_logged_last_event_notification_dlVol_min "$evField"
}


check_logged_last_event_notification() {
  evField="eventNotifs[0].ueCommInfos[0].comms"
  response=$(jq -s '.[-1].body' "$notification_logfile")
  check_logged_last_event_notification_ulVol_max "$evField"
  check_logged_last_event_notification_dlVol_max "$evField"
}

check_logged_last_event_notification_ulVol_sum() {
  ev_ul_field="$1"
  inc total_count
  if cmp_field_exists "$ev_ul_field" && cmp_field_array_size "$ev_ul_field" 1 && cmp_field_int "${ev_ul_field}[0].ulVol" 900; then
    inc ok_count
  else
    inc fail_count
    log_error "ulVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification_dlVol_sum() {
  ev_dl_field="$1"
  inc total_count
  if cmp_field_exists "$ev_dl_field" && cmp_field_array_size "$ev_dl_field" 1 && cmp_field_int "${ev_dl_field}[0].dlVol" 9000; then
    inc ok_count
  else
    inc fail_count
    log_error "dlVol of the last event notiication does not match the expected value"
  fi
}


check_logged_last_event_notification_sum() {
  evField="eventNotifs[0].ueCommInfos[0].comms"
  response=$(jq -s '.[-1].body' "$notification_logfile")
  check_logged_last_event_notification_ulVol_sum "$evField"
  check_logged_last_event_notification_dlVol_sum "$evField"
}

check_logged_last_event_notification_ulVol_mean() {
  ev_ul_field="$1"
  inc total_count
  if cmp_field_exists "$ev_ul_field" && cmp_field_array_size "$ev_ul_field" 1 && cmp_field_int "${ev_ul_field}[0].ulVol" 450; then
    inc ok_count
  else
    inc fail_count
    log_error "ulVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification_dlVol_mean() {
  ev_dl_field="$1"
  inc total_count
  if cmp_field_exists "$ev_dl_field" && cmp_field_array_size "$ev_dl_field" 1 && cmp_field_int "${ev_dl_field}[0].dlVol" 4500; then
    inc ok_count
  else
    inc fail_count
    log_error "dlVol of the last event notiication does not match the expected value"
  fi
}


check_logged_last_event_notification_mean() {
  evField="eventNotifs[0].ueCommInfos[0].comms"
  response=$(jq -s '.[-1].body' "$notification_logfile")
  check_logged_last_event_notification_ulVol_mean "$evField"
  check_logged_last_event_notification_dlVol_mean "$evField"
}

check_logged_last_event_notification_none() {
  inc total_count	
  response=$(jq -s '.[-1].body' "$notification_logfile")
  if cmp_field_array_size 'eventNotifs' 1 && \
    cmp_field_str 'eventNotifs[0].event' "UE_COMM" && \
    cmp_field_array_size 'eventNotifs[0].ueCommInfos' 1 && \
    cmp_field_str 'eventNotifs[0].ueCommInfos[0].appId' "$app_id_aggregation" && \
    cmp_field_array_size 'eventNotifs[0].ueCommInfos[0].comms' 2 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[0].ulVol' 60 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[0].dlVol' 30 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[1].ulVol' 140 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[1].dlVol' 70; \
  then
    inc ok_count
  else
    inc fail_count
    log_error "Expected one ueCommInfos with two comms"
    log_error "$response"
  fi
}

check_logged_last_event_notification_sum_mean() {
  inc total_count
  response=$(jq -s '.[-1].body' "$notification_logfile")
  if cmp_field_array_size 'eventNotifs' 1 && \
    cmp_field_str 'eventNotifs[0].event' "UE_COMM" && \
    cmp_field_array_size 'eventNotifs[0].ueCommInfos' 1 && \
    cmp_field_str 'eventNotifs[0].ueCommInfos[0].appId' "$app_id_aggregation" && \
    cmp_field_array_size 'eventNotifs[0].ueCommInfos[0].comms' 2 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[0].ulVol' 200 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[0].dlVol' 100 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[1].ulVol' 100 && \
    cmp_field_int 'eventNotifs[0].ueCommInfos[0].comms[1].dlVol' 50; \
  then
    inc ok_count
  else
    inc fail_count
    log_error "Expected one ueCommInfos with two comms"
    log_error "$response"
  fi
}


create_provisioning_session_aggregation 008_aggregation_sum_mean.json
create_reporting_session_aggregation
create_event_exposure_subsc_aggregation
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 60 30
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 140 70
sleep 20
check_logged_last_event_notification_sum_mean
destroy_event_exposure_subscription_aggregation
destroy_reporting_session_aggregation
destroy_provisioning_session_aggregation
#sleep 150
config_id_aggregation=
psid_aggregation=
rsid_aggregation=
event_exposure_subsc_id_aggregation=

create_provisioning_session_aggregation 008_aggregation_none.json
create_reporting_session_aggregation
create_event_exposure_subsc_aggregation
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 60 30
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 140 70
sleep 20
check_logged_last_event_notification_none
destroy_event_exposure_subscription_aggregation
destroy_reporting_session_aggregation
destroy_provisioning_session_aggregation
#sleep 150
config_id_aggregation=
psid_aggregation=
rsid_aggregation=
event_exposure_subsc_id_aggregation=


create_provisioning_session_aggregation 008_aggregation_sum.json
create_reporting_session_aggregation 
create_event_exposure_subsc_aggregation
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 600 5000
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 300 4000
sleep 20
check_logged_last_event_notification_sum
destroy_event_exposure_subscription_aggregation
destroy_reporting_session_aggregation
destroy_provisioning_session_aggregation
#sleep 150
config_id_aggregation=
psid_aggregation=
rsid_aggregation=
event_exposure_subsc_id_aggregation=
create_provisioning_session_aggregation 008_aggregation_mean.json
create_reporting_session_aggregation
create_event_exposure_subsc_aggregation
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 600 5000
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 300 4000
sleep 20
check_logged_last_event_notification_mean
destroy_event_exposure_subscription_aggregation
destroy_reporting_session_aggregation
destroy_provisioning_session_aggregation
#sleep 150
config_id_aggregation=
psid_aggregation=
rsid_aggregation=
event_exposure_subsc_id_aggregation=
create_provisioning_session_aggregation 008_aggregation_max.json
create_reporting_session_aggregation
create_event_exposure_subsc_aggregation
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 600 4000
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 300 5000
sleep 20
check_logged_last_event_notification
destroy_event_exposure_subscription_aggregation
destroy_reporting_session_aggregation
destroy_provisioning_session_aggregation
sleep 10
config_id_aggregation=
psid_aggregation=
rsid_aggregation=
event_exposure_subsc_id_aggregation=
create_provisioning_session_aggregation 008_aggregation_min.json
create_reporting_session_aggregation
create_event_exposure_subsc_aggregation
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 600 4000
submit_data_records_aggregation "$(echo "10*($(date +'%s')/10)-10" | bc)" 300 5000
sleep 20
check_logged_last_event_notification_min
destroy_event_exposure_subscription_aggregation
destroy_reporting_session_aggregation
destroy_provisioning_session_aggregation

