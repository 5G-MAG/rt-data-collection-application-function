:
#
# 5G-MAG Reference Tools: DCAF regression test 989: Tidy up Configuration
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
# This script tidies up the DataReportingConfiguration in the provisioning
# session.
#
# This test will be skipped if the provisioning session or the configuration of
# the provisioning session failed.
#


delete_configuration() {
  inc total_count
  if [ -n "$provisioning_session_id" ]; then
    if [ -n "$configuration_id" ]; then
      http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id/configurations/$configuration_id"

      if [ "$resp_statuscode" = "204" ]; then
        inc ok_count
        configuration_id=
      else
        inc fail_count
      fi
    else
      log_error "Skipping delete configuration due to no configuration id"
      inc skip_count
    fi
  else
    log_error "Skipping delete configuration due to no provisioning session id"
    inc skip_count
  fi
}

delete_configuration
