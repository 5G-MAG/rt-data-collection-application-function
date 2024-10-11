:
#
# 5G-MAG Reference Tools: DCAF regression test 5: Event Exposure Subscription
# ===========================================================================
#
# Author(s): David Waring <david.waring2@bbc.co.uk>
# Copyright: ©2024 British Broadcasting Corporation
#   License: 5G-MAG Public License v1.0
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
#
# ============================================================================
# This script provides regression tests to test subscription and
# unsubscription to event exposure.
#
# This will leave behind a single event exposure subscription and will record the
# following information about the subscription:
#  | Variable                     | Contents                                    |
#  | ============================ | =========================================== |
#  | $af_event_exposure_subsc_id  | The ResourceId of the afEventExposureSubsc. |
#  | $af_event_exposure_notif_url | The HTTP url for the notification server.   |
#  | $af_event_exposure_notif_pid | The process id of the notification server.  |
#

notification_path="/path/to/my/notification/handler"
event_rep_period=5

start_notification_server() {
  inc total_count
  notification_logfile=$(mktemp -p /tmp dcaf-regression-notif-log.XXXXXXXX)
  python3 "$script_dir/h2_svr.py" > "$notification_logfile" < /dev/null &
  af_event_exposure_notif_pid=$!
  # wait for the authority line to be output
  while ! [ -s "$notification_logfile" ]; do
    sleep 1
  done
  local authority="$(head -n 1 "$notification_logfile" | sed 's/^"//;s/"$//')"
  af_event_exposure_notif_url="http://${authority}${notification_path}"
  inc ok_count
}

stop_notification_server() {
  inc total_count
  if [ -n "$af_event_exposure_notif_pid" ]; then
    sleep $((event_rep_period + 5))
    kill "$af_event_exposure_notif_pid"
    #wait -f "$af_event_exposure_notif_pid"
    rm -f "$notification_logfile"
    af_event_exposure_notif_pid=
    inc ok_count
  else
    inc fail_count
  fi
}

create_event_exposure_subscription() {
  inc total_count
  http_post_json "$dcaf_eventConsumerApplicationFunctionEventExposure_address" "/naf-eventexposure/v1/subscriptions" '{"eventsSubs":[{"event": "UE_COMM", "eventFilter": {"anyUeInd": true}}], "eventsRepInfo": {"immRep": true, "notifMethod": "PERIODIC", "repPeriod": '"$event_rep_period"'}, "notifUri": "'"$af_event_exposure_notif_url"'", "notifId": "events-notifications-id", "suppFeat": "04"}'

  if [ "$resp_statuscode" = "201" ]; then
    if cmp_field_array_size 'eventNotifs' 1; then
      inc ok_count
      af_event_exposure_subsc_etag="$resp_etag"
      af_event_exposure_subsc_last_modified="$resp_last_modified"
      af_event_exposure_subsc_id="${resp_location##*/}"
    else
      inc fail_count
      log_error "Expected one immediate event notification"
      log_error "$response"
    fi
  else
    inc fail_count
    log_bad_response
  fi
}

delete_event_exposure_subscription() {
  inc total_count
  if [ -n "$af_event_exposure_subsc_id" ]; then
    http_delete "$dcaf_eventConsumerApplicationFunctionEventExposure_address" "/naf-eventexposure/v1/subscriptions/$af_event_exposure_subsc_id"
    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      af_event_exposure_subsc_id=
    else
      inc fail_count
      log_bad_response
    fi
  else
    inc skip_count
    log_warn "Delete AfEventExposureSubsc skipped due to missing afEventExposureSubscId"
  fi
}

start_notification_server
create_event_exposure_subscription
delete_event_exposure_subscription
create_event_exposure_subscription
submit_alt_communications_report
