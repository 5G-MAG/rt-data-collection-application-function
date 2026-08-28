"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""

from .http_client import request
from ..models.r2_data_reporting_session import (
    DataReportingSession,
    DataReportingSessionResponse,
    DataReportingSessionResult
)
from ..settings import settings

SESSIONS_URL = (
    f"{settings.dcaf_r2.base_url}"
    "/3gpp-ndcaf_data-reporting/v1/sessions"
)


def create_data_reporting_session(payload: DataReportingSession) -> DataReportingSessionResult:
    status, headers, body = request("POST", SESSIONS_URL, payload)
    return DataReportingSessionResult(
        status=status,
        headers=headers,
        body=DataReportingSessionResponse.model_validate(body),
    )

def get_data_reporting_session(data_reporting_session_id) -> DataReportingSessionResult:
    data_reporting_session_id_url = SESSIONS_URL + "/" + data_reporting_session_id
    status, headers, body = request("GET", data_reporting_session_id_url, None)
    return DataReportingSessionResult(
        status=status,
        headers=headers,
        body=DataReportingSessionResponse.model_validate(body),
    )


def delete_data_reporting_session(data_reporting_session_id: str) -> int:
    data_reporting_session_id_url = SESSIONS_URL + "/" + data_reporting_session_id
    status, _, _ = request("DELETE", data_reporting_session_id_url, None)
    return status