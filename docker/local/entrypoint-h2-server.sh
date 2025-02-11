#!/bin/sh

notification_logfile=$(mktemp -p /logs dcaf-regression-notif-log.XXXXXXXX)
python3 /app/h2_svr.py > "$notification_logfile" < /dev/null &
af_event_exposure_notif_pid=$!
# wait for the authority line to be output
while ! [ -s "$notification_logfile" ]; do
  sleep 1
done
authority="$(head -n 1 "$notification_logfile" | sed 's/^"//;s/"$//')"
af_event_exposure_notif_url="http://${authority}${notification_path}"

# Keep the container running
tail -f /dev/null
