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

notification_logfile_modified_timestamp() {
  if [[ -z "$notification_logfile" ]]; then
    echo "0"
    return
  fi
  stat -c '%Y' "$notification_logfile"
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
  local has_changed=$?
  inc total_count
  if [[ $has_changed == 1 ]]; then
    inc ok_count
    #log_info "Received Event Exposure Notification"
  else
    inc fail_count
    log_error "Event Exposure Notification not received"
  fi
}

check_logged_last_event_notification_ulVol() {
  local ev_ul_field="$1"
  inc total_count
  if cmp_field_exists "$ev_ul_field" && cmp_field_array_size "$ev_ul_field" 1 && \
     cmp_field_int "${ev_ul_field}[0].ulVol" $cr_uplink_vol; then
    inc ok_count
  else
    inc fail_count
    log_error "ulVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification_dlVol() {
  local ev_dl_field="$1"
  inc total_count
  if cmp_field_exists "$ev_dl_field" && cmp_field_array_size "$ev_dl_field" 1 && \
     cmp_field_int "${ev_dl_field}[0].dlVol" $cr_downlink_vol; then
    inc ok_count
  else
    inc fail_count
    log_error "dlVol of the last event notiication does not match the expected value"
  fi
}

check_logged_last_event_notification() {
  local evField="eventNotifs[0].ueCommInfos[0].comms"
  response=$(jq -s '.[-1].body' "$notification_logfile")
  check_logged_last_event_notification_ulVol "$evField"
  check_logged_last_event_notification_dlVol "$evField"
}

create_event_notification_report() {
  local notification_window="$(( ($(date +'%s') / event_rep_period) * event_rep_period ))"
  submit_communications_report "$(( (notification_window / bucketing_period - 1) * bucketing_period ))" $cr_uplink_vol $cr_downlink_vol
}

wait_for_notification_since() {
  local timestamp="$1"
  local wait_timeout="${2:-5}"
  (tail -fn0 "$notification_logfile" | head -n1 > /dev/null) &
  local fileupdate_pid=$!
  local current_timestamp=$(notification_logfile_modified_timestamp)
  if [ "$timestamp" -lt "$current_timestamp" ]; then
    kill -INT "$fileupdate_pid"
    return 0
  fi
  waitpid -e -t "$wait_timeout" "$fileupdate_pid"
  if [ "$?" -eq 3 ]; then
    log_error "Timeout waiting for notification event"
    kill -INT "$fileupdate_pid"
    return 1
  fi
  sleep 1
  return 0
}

wait_for_notification_event() {
  local timeout="${1:-5}"
  (tail -fn0 "$notification_logfile" | head -n1 > /dev/null) &
  local fileupdate_pid=$!
  waitpid -e -t "$timeout" "$fileupdate_pid"
  if [ "$?" -eq 3 ]; then
    log_error "Timeout waiting for notification event"
    kill -INT "$fileupdate_pid"
    return 1
  fi
  # wait for write to finish
  sleep 1
  return 0
}

# For Debug
#reset_x_option="$(set +o | grep xtrace)"
#set -o xtrace

last_modified_timestamp_current=$(notification_logfile_modified_timestamp)
for i in {1..2}; do
  create_event_notification_report
  if wait_for_notification_event $event_rep_period; then
    check_modifed_timestamp "$last_modified_timestamp_current"
  fi
done
check_logged_last_event_notification

# For Debug
#eval "$reset_x_option"

