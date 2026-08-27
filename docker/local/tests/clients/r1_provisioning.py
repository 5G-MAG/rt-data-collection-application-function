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

def get_provisioning_session(provisioning_session_id: str) -> DataReportingProvisioningSessionResponse:
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