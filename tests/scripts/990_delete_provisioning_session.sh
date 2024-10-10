:
#
# 5G-MAG Reference Tools: DCAF regression test 989: Tidy up Provisioning
# ======================================================================
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
# This script tidies up the active DataReportingProvisioningSession.
#
# This test will be skipped if the provisioning session failed in test 001.
#


delete_ue_comm_provisioning_session() {
  inc total_count
  if [ -n "$provisioning_session_id" ]; then
    http_delete "$dcaf_provisioning_address" "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions/$provisioning_session_id"

    if [ "$resp_statuscode" = "204" ]; then
      inc ok_count
      provisioning_session_id=
    else
      inc fail_count
    fi
  else
    log_error "Skipping delete provisioning session due to no provisioning session id"
    inc skip_count
  fi
}

delete_ue_comm_provisioning_session
