:
#
# 5G-MAG Reference Tools: DCAF regression test 3: Data Reporting Provisioning
# ===========================================================================
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
# This script provides regression tests to test provisioning of a data
# reporting session for a direct client.
#
# This will leave behind a single data reporting session and will record the
# following information about the data reporting session:
#  | Variable                              | Contents                                |
#  | ===================================== | ======================================= |
#  | $data_reporting_session_etag          | The ETag of the data reporting session. |
#  | $data_reporting_session_last_modified | Last modified time of the session.      |
#  | $data_reporting_session_id            | The ResourceId of the session.          |
#
# These tests will be skipped if the provisioning session failed and the
# variables above will remain unset.
#

data_reporting_session_timeout=130

create_data_reporting_session() {
  inc total_count
  http_post_json "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions" '{"externalApplicationId": "'"$external_app_id"'", "supportedDomains": ["COMMUNICATION", "BOGUS_DATA_DOMAIN"]}'

  if [ "$resp_statuscode" = "201" ]; then
    if cmp_field_str 'sessionId' "${resp_location##*/}" && cmp_field_not_exists 'validUntil' && \
       cmp_field_str 'externalApplicationId' "$external_app_id" && \
       cmp_field_array_str 'supportedDomains' 'COMMUNICATION' 'BOGUS_DATA_DOMAIN' && \
       cmp_field_exists 'samplingRules' && cmp_field_not_exists 'samplingRules.BOGUS_DATA_DOMAIN' && \
       check_sampling_rules 'samplingRules.COMMUNICATION' && \
       cmp_field_exists 'reportingRules' && cmp_field_not_exists 'reportingRules.BOGUS_DATA_DOMAIN' && \
       check_reporting_rules 'reportingRules.COMMUNICATION' && \
       cmp_field_exists 'reportingConditions' && cmp_field_not_exists 'reportingConditions.BOGUS_DATA_DOMAIN' && \
       check_reporting_rules 'reportingConditions.COMMUNICATION'; then
      inc ok_count
      data_reporting_session_etag="$resp_etag"
      data_reporting_session_last_modified="$resp_last_modified"
      data_reporting_session_id="${resp_location##*/}"
    else
      inc fail_count
      log_error "$response"
    fi
  else
    inc fail_count
    log_error "Unexpected response $resp_statuscode"
    log_error "$response"
  fi
}

fetch_data_reporting_session() {
  inc total_count
  if [ -n "$data_reporting_session_id" ]; then
    http_get "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$data_reporting_session_id" "$data_reporting_session_last_modified" "$data_reporting_session_etag"
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
      	  data_reporting_session_etag="$resp_etag"
          data_reporting_session_last_modified="$resp_last_modified"
          inc ok_count
        else
          inc fail_count
          log_error "$response"
	fi
    elif [ "$resp_statuscode" = "304" ]; then
      inc ok_count
      log_info "DataReportingSession unmodified"
    else
      inc fail_count
      log_error "Unexpected response $resp_statuscode"
      log_error "$response"
    fi
  else
    inc skip_count
    log_warn "skipping fetch_data_reporting_session due to missing DataReportingSession id"
  fi
}

fetch_bad_data_reporting_session() {
  inc total_count
  http_get "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/bogus-data-reporting-session"
  if [ "$resp_statuscode" = "404" ]; then
    inc ok_count
  else
    inc fail_count
    log_error "Unexpected response $resp_statuscode"
    log_error "$response"
  fi
}

fetch_expired_data_reporting_session() {
  inc total_count
  if [ -n "$data_reporting_session_id" ]; then
    sleep $((data_reporting_session_timeout + 5))
    http_get "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$data_reporting_session_id"
    if [ "$resp_statuscode" = "404" ]; then
      inc ok_count
      log_info "DataReportingSession has expired"
    else
      inc fail_count
      log_bad_response
    fi
  else
    inc skip_count
    log_warn "skipping fetch_expired_data_reporting_session due to missing DataReportingSession id"
  fi
}

delete_data_reporting_session() {
  inc total_count
  if [ -n "$data_reporting_session_id" ]; then
    http_delete "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$data_reporting_session_id"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      data_reporting_session_id=
    else
      inc fail_count
      log_error "Unexpected response $resp_statuscode"
      log_error "$response"
    fi
  else
    inc skip_count
    log_warn "skipping fetch_data_reporting_session due to missing DataReportingSession id"
  fi
}

create_data_reporting_session
fetch_data_reporting_session
fetch_bad_data_reporting_session
delete_data_reporting_session
create_data_reporting_session
fetch_expired_data_reporting_session
create_data_reporting_session
