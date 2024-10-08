:

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
      data_reporting_session_id="${resp_location##*/}"
    else
      inc fail_count
      log_error "$response"
    fi
  else
    inc fail_count
    log_error "create_data_reporting_session: Unexpected response $resp_statuscode"
    log_error "$response"
  fi
}

fetch_data_reporting_session() {
  inc total_count
  if [ -n "$data_reporting_session_id" ]; then
    http_get "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$data_reporting_session_id"
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
          log_error "$response"
	fi
    else
      inc fail_count
      log_error "fetch_data_reporting_session: Unexpected response $resp_statuscode"
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
    log_error "fetch_data_reporting_session: Unexpected response $resp_statuscode"
    log_error "$response"
  fi
}

delete_data_reporting_session() {
  inc total_count
  if [ -n "$data_reporting_session_id" ]; then
    http_delete "$dcaf_directDataReporting_address" "/3gpp-ndcaf_data-reporting/v1/sessions/$data_reporting_session_id"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
    else
      inc fail_count
      log_error "fetch_data_reporting_session: Unexpected response $resp_statuscode"
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

