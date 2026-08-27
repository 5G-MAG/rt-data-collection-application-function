from .http_client import request
from ..models.r1_confguration import (
    DataReportingConfigurationRequest, DataReportingConfigurationResult, DataReportingConfigurationResponse
)
from ..settings import settings

SESSIONS_URL = (
    f"{settings.dcaf_r1.base_url}"
    "/3gpp-ndcaf_data-reporting-provisioning/v1/sessions"
)




def create_data_reporting_configuration(payload: DataReportingConfigurationRequest, provisioning_session_id: str) -> DataReportingConfigurationResult:
    session_url_id_configuration = SESSIONS_URL + "/" + provisioning_session_id + "/configurations"
    status, headers, body = request("POST", session_url_id_configuration , payload)
    return DataReportingConfigurationResult(
            status=status,
            headers=headers,
            body=DataReportingConfigurationResponse.model_validate(body),
        )


def get_data_reporting_configuration(
    provisioning_session_id: str,
    data_reporting_configuration_id: str,
) -> DataReportingConfigurationResult:
    session_url_id_configuration = (
        f"{SESSIONS_URL}/{provisioning_session_id}/configurations/"
        f"{data_reporting_configuration_id}"
    )
    status, headers, body = request("GET", session_url_id_configuration , None)
    return DataReportingConfigurationResult(
        status=status,
        headers=headers,
        body=DataReportingConfigurationResponse.model_validate(body),
    )

def delete_data_reporting_configuration(
    provisioning_session_id: str,
    data_reporting_configuration_id: str,
) -> int:
    session_url_id_configuration = (
        f"{SESSIONS_URL}/{provisioning_session_id}/configurations/"
        f"{data_reporting_configuration_id}"
    )
    status, _, _ = request("DELETE", session_url_id_configuration, None)
    return status