:

create_provisioning_session_configuration() {
  inc total_count
  if [ -n "$provisioning_session_id" ]; then
    http_post_file "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id/configurations" 002_configure-good-configuration.json

    if [ "$resp_statuscode" = "200" ]; then
      inc ok_count
      configuration_id="${resp_location##*/}"
    else
      inc fail_count
      log_error "$response"
    fi
  else
    log_error "Create configuration skipped due to missing provisioning session"
    inc skip_count
  fi
}

check_sampling_rules() {
  field="$1"
  if cmp_field_exists "$field" && cmp_field_array_size "$field" 1 && \
     cmp_field_array_size "$field[0].contextIds" 1 && \
     cmp_field_float "${field}[0].samplingPeriod" 10.0; then
    return 0
  fi
  return 1
}

check_reporting_rules() {
  field="$1"
  if cmp_field_exists "$field" && cmp_field_array_size "$field" 1 && \
     cmp_field_array_size "$field[0].contextIds" 1; then
    return 0
  fi
  return 1
}

check_reporting_conditions() {
  field="$1"
  if cmp_field_exists "$field" && cmp_field_array_size "$field" 1 && cmp_field_str "${field}[0].type" 'INTERVAL' && \
     cmp_field_int "${field}[0].period" 60; then
    return 0
  fi
  return 1
}

create_provisioning_session_configuration_expect_error_field() {
  json_doc="$1"
  err_field="$2"
  inc total_count
  if [ -n "$provisioning_session_id" ]; then
    http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id/configurations" "$json_doc"
    if [ "$resp_statuscode" = "400" ] && cmp_field_str 'invalidParams[0].param' "$err_field"; then
      inc ok_count
    else
      inc fail_count
      log_error "Create configuration with bad ${err_field}: error in unexpected field"
      log_error "$response"
    fi
  else
    log_error "Create configuration with bad $err_field skipped due to missing provisioning session"
    inc skip_count
  fi
}

fetch_provisioning_session_configuration() {
  inc total_count
  if [ -n "$provisioning_session_id" -a -n "$configuration_id" ]; then
    if [ "$resp_statuscode" = "200" ]; then
      if cmp_field_str 'dataReportingConfigurationId' "$configuration_id" && \
         cmp_field_str 'dataCollectionClientType' 'DIRECT' && \
         cmp_field_not_exists 'authorizationURL' && \
         check_sampling_rules 'dataSamplingRules' && \
         check_reporting_rules 'dataReportingRules' && \
         check_reporting_conditions 'dataReportingConditions' && \
         cmp_field_array_size 'dataAccessProfiles' 1 && \
         cmp_field_str 'dataAccessProfiles[0].dataAccessProfileId' 'per_min_totals' && \
         cmp_field_array_str 'dataAccessProfiles[0].targetEventConsumerTypes' 'NWDAF' 'EVENT_CONSUMER_AF' && \
         cmp_field_array_size 'dataAccessProfiles[0].parameters' 0 && \
         cmp_field_int 'dataAccessProfiles[0].timeAccessRestrictions.duration' 60 && \
         cmp_field_array_str 'dataAccessProfiles[0].timeAccessRestrictions.aggregationFunctions' 'SUM'; then
        inc ok_count
      else
        inc fail_count
        log_error "Fetch configuration: unexpected fields in reponse"
        log_error "$response"
      fi
    else
      inc fail_count
      log_error "Fetch configuration: unexpected result code: $resp_statuscode"
      log_error "$response"
    fi
  else
    log_error "Fetch configuration skipped due to missing provisioning session or configuration"
  fi
}

create_provisioning_session_configuration_no_access_profile_id() {
  create_provisioning_session_configuration_expect_error_field '{"dataCollectionClientType": "DIRECT", "dataReportingConditions": [{"type": "INTERVAL", "period": 60}], "dataAccessProfiles": [{"targetEventConsumerTypes": ["NWDAF","EVENT_CONSUMER_AF"], "parameters": [], "timeAccessRestrictions": {"duration": 60, "aggregationFunctions": ["SUM"]}}]}' 'dataAccessProfiles[0].dataAccessProfileId'
}

create_provisioning_session_configuration_bad_access_profile_id() {
  create_provisioning_session_configuration_expect_error_field '{"dataCollectionClientType": "DIRECT", "dataReportingConditions": [{"type": "INTERVAL", "period": 60}], "dataAccessProfiles": [{"dataAccessProfileId": true, "targetEventConsumerTypes": ["NWDAF","EVENT_CONSUMER_AF"], "parameters": [], "timeAccessRestrictions": {"duration": 60, "aggregationFunctions": ["SUM"]}}]}' 'dataAccessProfiles[0].dataAccessProfileId'
}

create_provisioning_session_configuration
fetch_provisioning_session_configuration
create_provisioning_session_configuration_no_access_profile_id
create_provisioning_session_configuration_bad_access_profile_id

