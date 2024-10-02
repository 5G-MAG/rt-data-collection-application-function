:

create_ue_comm_provisioning_session() {
  inc total_count
  http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions" '{"aspId": "MyASPId", "externalApplicationId": "MyAppId", "eventId": "UE_COMM"}'

  if [ "$resp_statuscode" = "200" ]; then
    inc ok_count
    provisioning_session_id="${resp_location##*/}"
  else
    inc fail_count
  fi
}

create_ue_comm_provisioning_session
