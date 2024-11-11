:
#
# 5G-MAG Reference Tools: DCAF regression test 6: Event Exposure Notification
# ===========================================================================
#
# Copyright: ©2024 British Broadcasting Corporation
#   License: 5G-MAG Public License v1.0
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
#
# ============================================================================
# This script provides regression tests to test event exposure notification.
#

cr_uplink_vol=800
cr_downlink_vol=65533

notification_logfile_modified_timestamp() {
  if [[ -n "$notification_logfile" && -n "$iso_datetime_format" ]]; then
    # Get the last modified timestamp of the file in ISO 8601 format 
    timestamp=$(date -r "$notification_logfile" "$iso_datetime_format")
  fi
  echo "$timestamp"
}

check_if_modified_timestamp_has_changed() { 
  if [[ "$1" == "$2" ]]; then 
    return 0 
  else 
    return 1 
  fi 
}

check_modifed_timestamp() {
  last_modified_timestamp_after_report_submission=$(notification_logfile_modified_timestamp)
  check_if_modified_timestamp_has_changed "$1" "$last_modified_timestamp_after_report_submission"
  has_changed=$?
  inc total_count
  if [[ $has_changed == 1 ]]; then
    inc ok_count
    log_info "Received Event Exposure Notification"
  else
    inc fail_count
    log_error "Event Exposure Notification not received"
  fi
}

check_logged_last_event_notification_ulVol() {
  ev_ul_field="$1"
  inc total_count
  if cmp_field_exists "$ev_ul_field" && cmp_field_array_size "$ev_ul_field" 1 && cmp_field_int "${ev_ul_field}[0].ulVol" 800; then
    inc ok_count
  else
    inc fail_count
    log_error "ulVol of the last event notiication does not match the expected value"	  
  fi
}

check_logged_last_event_notification_dlVol() {
  ev_dl_field="$1"
  inc total_count
  if cmp_field_exists "$ev_dl_field" && cmp_field_array_size "$ev_dl_field" 1 && cmp_field_int "${ev_dl_field}[0].dlVol" 65533; then
    inc ok_count
  else
    inc fail_count
    log_error "dlVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification() {
  evField="eventNotifs[0].ueCommInfos[0].comms"
  response=$(jq -s '.[-1].body' "$notification_logfile")
  check_logged_last_event_notification_ulVol "$evField"
  check_logged_last_event_notification_dlVol "$evField"
}

last_modified_timestamp_current=$(notification_logfile_modified_timestamp)
for i in {1..2}; do
submit_communications_report "$(echo "10*($(date +'%s')/10)-10" | bc)" $cr_uplink_vol $cr_downlink_vol
sleep 5
check_modifed_timestamp "$last_modified_timestamp_current"
done
sleep 5
check_logged_last_event_notification

