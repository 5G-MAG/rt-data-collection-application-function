:

delete_ue_comm_provisioning_session() {
  inc total_count
  http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id"

  if [ "$resp_statuscode" = "204" ]; then
    inc ok_count
    provisioning_session_id=
  else
    inc fail_count
  fi
}

if [ -n "$provisioning_session_id" ]; then
  delete_ue_comm_provisioning_session
else
  inc total_count
  log_error "Skipping delete provisioning session due to no provisioning session id"
  inc skip_count
fi
