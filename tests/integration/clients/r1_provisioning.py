"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""

from .http_client import request
from ..models.r1_provisioning import (
    CreateDataReportingProvisioningSessionRequest,
    DataReportingProvisioningSessionResult,
    DataReportingProvisioningSessionResponse,
)
from ..settings import settings

SESSIONS_URL = (
    f"{settings.dcaf_r1.base_url}"
    "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions"
)


def create_provisioning_session(payload: CreateDataReportingProvisioningSessionRequest) -> DataReportingProvisioningSessionResult:
    status, headers, body = request("POST", SESSIONS_URL, payload)
    return DataReportingProvisioningSessionResult(
        status=status,
        headers=headers,
        body=DataReportingProvisioningSessionResponse.model_validate(body),
    )

def get_provisioning_session(provisioning_session_id: str) -> DataReportingProvisioningSessionResult:
    SESSIONS_URL_ID = SESSIONS_URL + "/" + provisioning_session_id
    status, headers, body = request("GET", SESSIONS_URL_ID , None)
    return DataReportingProvisioningSessionResult(
        status=status,
        headers=headers,
        body=DataReportingProvisioningSessionResponse.model_validate(body),
    )

def delete_provisioning_session(provisioning_session_id: str) -> int:
    SESSIONS_URL_ID = SESSIONS_URL + "/" + provisioning_session_id
    status, _, _ = request("DELETE", SESSIONS_URL_ID, None)
    return status