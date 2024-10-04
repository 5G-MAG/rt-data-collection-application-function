:

create_provisioning_session_configuration() {
  inc total_count
  if [ -n "$provisioning_session_id" ]; then
    http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id/configurations" '{"dataCollectionClientType": "DIRECT", "dataReportingConditions": [{"type": "INTERVAL", "period": 60}], "dataAccessProfiles": [{"dataAccessProfileId": "per_min_totals", "targetEventConsumerTypes": ["NWDAF","EVENT_CONSUMER_AF"], "parameters": [], "timeAccessRestrictions": {"duration": 60, "aggregationFunctions": ["SUM"]}}]}'

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

create_provisioning_session_configuration_no_access_profile_id() {
  create_provisioning_session_configuration_expect_error_field '{"dataCollectionClientType": "DIRECT", "dataReportingConditions": [{"type": "INTERVAL", "period": 60}], "dataAccessProfiles": [{"targetEventConsumerTypes": ["NWDAF","EVENT_CONSUMER_AF"], "parameters": [], "timeAccessRestrictions": {"duration": 60, "aggregationFunctions": ["SUM"]}}]}' 'dataAccessProfiles[0].dataAccessProfileId'
}

create_provisioning_session_configuration_bad_access_profile_id() {
  create_provisioning_session_configuration_expect_error_field '{"dataCollectionClientType": "DIRECT", "dataReportingConditions": [{"type": "INTERVAL", "period": 60}], "dataAccessProfiles": [{"dataAccessProfileId": true, "targetEventConsumerTypes": ["NWDAF","EVENT_CONSUMER_AF"], "parameters": [], "timeAccessRestrictions": {"duration": 60, "aggregationFunctions": ["SUM"]}}]}' 'dataAccessProfiles[0].dataAccessProfileId'
}

create_provisioning_session_configuration
create_provisioning_session_configuration_no_access_profile_id
create_provisioning_session_configuration_bad_access_profile_id

