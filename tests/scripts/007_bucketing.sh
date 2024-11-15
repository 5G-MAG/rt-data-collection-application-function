:
#
# 5G-MAG Reference Tools: DCAF regression test 7: Bucketing
# ============================================================================
#
# Author(s): David Waring <david.waring2@bbc.co.uk>
# Copyright: ©2024 British Broadcasting Corporation
#   License: 5G-MAG Public License v1.0
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
#
# ============================================================================
# This script provides regression tests to test result bucketing for event
# exposure.
#

bucketing_app_id="MyAppId-buckets"

create_time_bucket_provisioning_session() {
  inc total_count
  if [ -n "$af_event_exposure_notif_url" ]; then
    http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions" '{"aspId": "MyASPId", "externalApplicationId": "'"$bucketing_app_id"'", "eventId": "UE_COMM"}'
    if [ "$resp_statuscode" = "200" ]; then
      bucketing_psid="${resp_location##*/}"
      http_post_file "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$bucketing_psid/configurations" 007_bucketing-10s_buckets.json
      if [ "$resp_statuscode" = "200" ]; then
        inc ok_count
        bucketing_config_id="${resp_location##*/}"
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

destroy_time_bucket_provisioning_session() {
  inc total_count
  if [ -n "$bucketing_psid" ]; then
    http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$bucketing_psid"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      bucketing_config_id=
      bucketing_psid=
    else
      log_bad_response
      inc fail_count
    fi
  else
    inc skip_count
  fi
}

check_time_bucketing_sampling_rules() {
  local json_path_prefix="$1"

  # check the samplingRules array for a DataReportingSession response for time bucketed tests

  return 0
}

check_time_bucketing_reporting_rules() {
  local json_path_prefix="$1"

  # check the reportingRules array for a DataReportingSession response for time bucketed tests

  return 0
}

check_time_bucketing_reporting_conditions() {
  local json_path_prefix="$1"

  # check the reportingConditions array for a DataReportingSession response for time bucketed tests

  return 0
}

create_time_bucketing_reporting_session() {
  inc total_count
  if [ -n "$bucketing_psid" ]; then
    http_post_json "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions" '{"externalApplicationId": "'"$bucketing_app_id"'", "supportedDomains": ["COMMUNICATION"]}'
    if [ "$resp_statuscode" = "201" ]; then
      if cmp_field_str 'sessionId' "${resp_location##*/}" && cmp_field_not_exists 'validUntil' && \
         cmp_field_str 'externalApplicationId' "$bucketing_app_id" && \
         cmp_field_array_str 'supportedDomains' 'COMMUNICATION' && \
         cmp_field_exists 'samplingRules' && check_time_bucketing_sampling_rules 'samplingRules.COMMUNICATION' && \
         cmp_field_exists 'reportingRules' && check_time_bucketing_reporting_rules 'reportingRules.COMMUNICATION' && \
         cmp_field_exists 'reportingConditions' && check_time_bucketing_reporting_conditions 'reportingConditions.COMMUNICATION'; \
      then
	inc ok_count
	bucketing_rsid="${resp_location##*/}"
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

destroy_time_bucketing_reporting_session() {
  inc total_count
  if [ -n "$bucketing_rsid" ]; then
    http_delete "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$bucketing_rsid"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      bucketing_rsid=
    else
      log_bad_response
      inc fail_count
    fi
  else
    inc skip_count
  fi 
}

add_time_bucketing_data_records() {
  inc total_count
  if [ -n "$bucketing_rsid" ]; then
    local now_ts=$(TZ=UTC date +'%s')
    local notification_window_ts="$(( now_ts - event_rep_period ))"
    local current_bucket_ts="$(( (notification_window_ts / bucketing_period) * bucketing_period))"
    local previous1_bucket_ts="$(( current_bucket_ts - bucketing_period ))"
    local previous2_bucket_ts="$(( previous1_bucket_ts - bucketing_period ))"
    local report_start="$(( previous2_bucket_ts + bucketing_period * 7 / 10 ))" # last 30% of one bucket...
    local report_end="$(( previous1_bucket_ts + bucketing_period * 7 / 10 ))"   # ...and the next 70% of the next
    local ts_now="$(TZ=UTC date --date="@$now_ts" $iso_datetime_format)"
    local ts_start="$(TZ=UTC date --date="@$report_start" $iso_datetime_format)"
    local ts_end="$(TZ=UTC date --date="@$report_end" $iso_datetime_format)"
    http_post_json "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$bucketing_rsid/report" '{"externalApplicationId": "'"$bucketing_app_id"'", "communicationRecords": [{"timestamp": "'"$ts_now"'", "contextIds": ["'"$bucketing_config_id"'"], "timeInterval": {"startTime": "'"$ts_start"'", "stopTime": "'"$ts_end"'"}, "uplinkVolume": 200, "downlinkVolume": 100}]}'
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

create_time_bucketing_event_exposure_subscription() {
  inc total_count
  http_post_json "$dcaf_eventConsumerApplicationFunctionEventExposure_address" "/naf-eventexposure/v1/subscriptions" '{"eventsSubs":[{"event": "UE_COMM", "eventFilter": {"appIds": ["'"$bucketing_app_id"'"]}}], "eventsRepInfo": {"immRep": true, "notifMethod": "PERIODIC", "repPeriod": '"$event_rep_period"'}, "notifUri": "'"$af_event_exposure_notif_url"'", "notifId": "events-notifications-id", "suppFeat": "04"}'

  if [ "$resp_statuscode" = "201" ]; then
    if cmp_field_str 'eventNotifs[0].event' "UE_COMM" && \
       cmp_field_array_size 'eventNotifs|map(.ueCommInfos[])' 2 && \
       cmp_field_str 'eventNotifs|map(.ueCommInfos[])|.[0].appId' "$bucketing_app_id" && \
       cmp_field_str 'eventNotifs|map(.ueCommInfos[])|.[1].appId' "$bucketing_app_id" && \
       cmp_field_array_size 'eventNotifs|map(.ueCommInfos[])|.[0].comms' 1 && \
       cmp_field_int 'eventNotifs|map(.ueCommInfos[])|.[0].comms[0].ulVol' 60 && \
       cmp_field_int 'eventNotifs|map(.ueCommInfos[])|.[0].comms[0].dlVol' 30 && \
       cmp_field_array_size 'eventNotifs|map(.ueCommInfos[])|.[1].comms' 1 && \
       cmp_field_int 'eventNotifs|map(.ueCommInfos[])|.[1].comms[0].ulVol' 140 && \
       cmp_field_int 'eventNotifs|map(.ueCommInfos[])|.[1].comms[0].dlVol' 70; \
    then
      inc ok_count
    else
      inc fail_count
      log_error "Expected two aggregated results with a 30%/70% split"
      log_error "$response"
    fi
    bucketing_event_exposure_subsc_etag="$resp_etag"
    bucketing_event_exposure_subsc_last_modified="$resp_last_modified"
    bucketing_event_exposure_subsc_id="${resp_location##*/}"
  else
    inc fail_count
    log_bad_response
  fi
}

destroy_time_bucketing_event_exposure_subscription() {
  inc total_count
  if [ -n "$bucketing_event_exposure_subsc_id" ]; then
    http_delete "$dcaf_eventConsumerApplicationFunctionEventExposure_address" "/naf-eventexposure/v1/subscriptions/$bucketing_event_exposure_subsc_id"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      bucketing_event_exposure_subsc_id=
    else
      inc fail_count
      log_bad_response
    fi
  else
    inc skip_count
    log_warn "Delete time bucketing AfEventExposureSubsc skipped due to missing bucketing afEventExposureSubscId"
  fi
}

create_time_bucket_provisioning_session
create_time_bucketing_reporting_session
add_time_bucketing_data_records
create_time_bucketing_event_exposure_subscription
destroy_time_bucketing_event_exposure_subscription
destroy_time_bucketing_reporting_session
destroy_time_bucket_provisioning_session
