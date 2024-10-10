:
#
# 5G-MAG Reference Tools: DCAF regression test 988: Tidy up Event Exposure
# ========================================================================
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
# This script tidies up the event exposure subscription and the notification
# server.
#
# These tests will be skipped if the notification server or event exposure
# subscription are not present.
#


delete_event_exposure_subscription
stop_notification_server
