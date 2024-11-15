:
#
# 5G-MAG Reference Tools: DCAF regression test 3: Data Reporting
# ==============================================================
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
# This script provides regression tests to test reporting data to the active
# data reporting session for a direct client.
#
# These tests will be skipped if the data reporting session provisioning failed.
#

iso_datetime_format='+%Y-%m-%dT%H:%M:%SZ'

submit_communications_report() {
  local timestart="$1"
  local uplink_vol="$2"
  local downlink_vol="$3"
  inc total_count
  if [ -n "$data_reporting_session_id" ]; then
    local now="$(TZ=UTC date $iso_datetime_format)"
    local timeend="$((timestart + 10))"
    local ts_start="$(TZ=UTC date --date="@$timestart" $iso_datetime_format)"
    local ts_end="$(TZ=UTC date --date="@$timeend" $iso_datetime_format)"
    http_post_json "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$data_reporting_session_id/report" '{"externalApplicationId": "'"$external_app_id"'", "communicationRecords": [{"timestamp": "'"$now"'", "contextIds": ["'"$configuration_id"'"], "timeInterval": {"startTime": "'"$ts_start"'", "stopTime": "'"$ts_end"'"}, "uplinkVolume": '"$uplink_vol"', "downlinkVolume": '"$downlink_vol"'}]}'

    if [ "$resp_statuscode" = "200" ]; then
      if cmp_field_str 'sessionId' "$data_reporting_session_id" && cmp_field_not_exists 'validUntil' && \
         cmp_field_str 'externalApplicationId' "$external_app_id" && \
         cmp_field_array_str 'supportedDomains' 'COMMUNICATION' 'BOGUS_DATA_DOMAIN' && \
         cmp_field_exists 'samplingRules' && cmp_field_not_exists 'samplingRules.BOGUS_DATA_DOMAIN' && \
         check_sampling_rules 'samplingRules.COMMUNICATION' && \
         cmp_field_exists 'reportingRules' && cmp_field_not_exists 'reportingRules.BOGUS_DATA_DOMAIN' && \
         check_reporting_rules 'reportingRules.COMMUNICATION' && \
         cmp_field_exists 'reportingConditions' && cmp_field_not_exists 'reportingConditions.BOGUS_DATA_DOMAIN' && \
         check_reporting_conditions 'reportingConditions.COMMUNICATION'; then
        inc ok_count
      else
        inc fail_count
        log_error "Bad DataReportingSession received"
        log_error "$response"
      fi
    elif [ "$resp_statuscode" = "204" ]; then
      inc ok_count
    else
      inc fail_count
      log_bad_response
    fi
  else
    inc skip_count
    log_warn "Skipped due to missing dataReportingSessionId"
  fi
}

submit_first_communications_report() {
    local current_event_window="$(( ($(date +'%s')/event_rep_period)*event_rep_period ))"
    submit_communications_report "$(( bucketing_period * (current_event_window/bucketing_period - 1) ))" 600 65536
}

submit_alt_communications_report() {
    local current_event_window="$(( ($(date +'%s')/event_rep_period)*event_rep_period ))"
    submit_communications_report "$(( bucketing_period * (current_event_window/bucketing_period - 1) ))" 1200 32768
}

submit_first_communications_report
