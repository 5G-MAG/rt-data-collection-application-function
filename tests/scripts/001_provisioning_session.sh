:

create_ue_comm_provisioning_session() {
  inc total_count
  http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions" '{"aspId": "MyASPId", "externalApplicationId": "MyAppId", "eventId": "UE_COMM"}'

  if [ "$resp_statuscode" = "200" ]; then
    inc ok_count
    provisioning_session_id="${resp_location##*/}"
  else
    log_bad_response create_ue_comm_provisioning_session
    inc fail_count
  fi
}

fetch_ue_comm_provisioning_session() {
  inc total_count
  if [ -n "$provisioning_session_id" ]; then
    http_get "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id"
    if [ "$resp_statuscode" = "200" ]; then
      if cmp_field_str provisioningSessionId "$provisioning_session_id" && \
         cmp_field_str aspId MyASPId && \
         cmp_field_str externalApplicationId MyAppId && \
         cmp_field_str eventId UE_COMM; then
         inc ok_count
      else
         log_error "fetch_ue_comm_provisioning_session: response did not match expected values"
         inc fail_count
      fi
    else
      log_bad_response fetch_ue_comm_provisioning_session
      inc fail_count
    fi
  else
    inc skip_count
  fi
}

delete_ue_comm_provisioning_session() {
  inc total_count
  if [ -n "$provisioning_session_id" ]; then
    http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id"

    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      provisioning_session_id=
    else
      log_bad_response delete_ue_comm_provisioning_session
      inc fail_count
    fi
  else
    inc skip_count
  fi
}

create_provisioning_session_expect_bad_request() {
  json_doc="$1"
  error_field="$2"
  inc total_count
  http_post_json "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions" "$json_doc"

  if [ "$resp_statuscode" = "400" ]; then
    if cmp_field_str 'invalidParams[0].param' "$error_field"; then
      inc ok_count
    else
      log_error "create_provisioning_session_expect_bad_request($error_field): Failed on unexpected field"
    fi
  elif [ "$resp_statuscode" = "200" ]; then
    declare -n psid="err_${error_field}_provisioning_session_id"
    inc ok_count
    log_warn "create_provisioning_session_expect_bad_request($error_field): expected failure, got success"
    psid="${resp_location##*/}"
  else
    log_bad_response create_custom_provisioning_session
    inc fail_count
  fi
}

fetch_err_provisioning_session() {
  declare -n psid="err_${1}_provisioning_session_id"
  asp_id="$2"
  ext_app_id="$3"
  evt_type="$4"
  if [ -n "$psid" ]; then
    inc total_count
    http_get "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$psid"
    if [ "$resp_statuscode" = "200" ]; then
      if cmp_field_str provisioningSessionId "$psid" && \
         cmp_field_str aspId "$asp_id" && \
         cmp_field_str externalApplicationId "$ext_app_id" && \
         cmp_field_str eventId "$evt_type"; then
         inc ok_count
      else
	 log_error "fetch_custom_provisioning_session: response does not match expected"
         inc fail_count
      fi
    else
      log_bad_response fetch_custom_provisioning_session
      inc fail_count
    fi
  fi
}

delete_err_provisioning_session() {
  declare -n psid="err_${1}_provisioning_session_id"
  if [ -n "$psid" ]; then
    inc total_count
    http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$psid"

    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      psid=
    else
      log_bad_response delete_custom_provisioning_session
      inc fail_count
    fi
  fi
}

create_custom_provisioning_session() {
  create_provisioning_session_expect_bad_request '{"aspId": "MyASPId", "externalApplicationId": "MyAppId", "eventId": "CUSTOM_EVENT"}' eventId
}

fetch_custom_provisioning_session() {
  fetch_err_provisioning_session eventId MyASPId MyAppId CUSTOM_EVENT
}

delete_custom_provisioning_session() {
  delete_err_provisioning_session eventId
}

create_bad_asp_id_provisioning_session() {
  create_provisioning_session_expect_bad_request '{"externalApplicationId": "MyAppId", "eventId": "UE_COMM"}' aspId
}

delete_bad_asp_id_provisioning_session() {
  delete_err_provisioning_session aspId
}

create_bad_ext_app_id_provisioning_session() {
  create_provisioning_session_expect_bad_request '{"aspId": "MyASPId", "eventId": "UE_COMM"}' externalApplicationId
}

delete_bad_ext_app_id_provisioning_session() {
  delete_err_provisioning_session externalApplicationId
}

# Basic operations for a single provisioning session
create_ue_comm_provisioning_session
fetch_ue_comm_provisioning_session
delete_ue_comm_provisioning_session

# Multiple provisioning sessions
create_ue_comm_provisioning_session
create_custom_provisioning_session
fetch_custom_provisioning_session
fetch_ue_comm_provisioning_session
delete_custom_provisioning_session
fetch_ue_comm_provisioning_session
create_bad_asp_id_provisioning_session
delete_bad_asp_id_provisioning_session
create_bad_ext_app_id_provisioning_session
delete_bad_ext_app_id_provisioning_session

