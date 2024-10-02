:

delete_configuration() {
  inc total_count
  http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id/configurations/$configuration_id"

  if [ "$resp_statuscode" = "204" ]; then
    inc ok_count
    configuration_id=
  else
    inc fail_count
  fi
}

if [ -n "$provisioning_session_id" ]; then
  if [ -n "$configuration_id" ]; then
    delete_configuration
  else
    inc total_count
    log_error "Skipping delete configuration due to no configuration id"
    inc skip_count
  fi
else
  inc total_count
  log_error "Skipping delete configuration due to no provisioning session id"
  inc skip_count
fi
