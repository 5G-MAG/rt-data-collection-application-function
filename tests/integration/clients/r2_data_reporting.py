"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""

from .http_client import request
from ..models.r2_data_reporting import DataReporting
from ..settings import settings

SESSIONS_URL = (
    f"{settings.dcaf_r2.base_url}"
    "/3gpp-ndcaf_data-reporting/v1/sessions"
)


def create_data_reporting(
    payload: DataReporting,
    data_reporting_session_id: str,
) -> int:
    report_url = f"{SESSIONS_URL}/{data_reporting_session_id}/report"
    status, _, _ = request("POST", report_url, payload)
    return status

