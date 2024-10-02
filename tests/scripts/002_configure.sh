:

create_provisioning_session_configuration() {
  inc total_count
  http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id/configurations" '{"dataCollectionClientType": "DIRECT", "dataReportingConditions": [{"type": "INTERVAL", "period": 60}], "dataAccessProfiles": [{"targetEventConsumerTypes": ["NWDAF","EVENT_CONSUMER_AF"], "parameters": [], "timeAccessRestrictions": {"duration": 60, "aggregationFunctions": ["SUM"]}}]}'

  if [ "$resp_statuscode" = "200" ]; then
    inc ok_count
    configuration_id="${resp_location##*/}"
  else
    inc fail_count
    log_error "$response"
  fi
}

if [ -n "$provisioning_session_id" ]; then
    create_provisioning_session_configuration
else
    inc total_count
    log_error "Create configuration skipped due to missing provisioning session"
    inc skip_count
fi
