from pydantic import BaseModel, ConfigDict, Field


class CreateDataReportingProvisioningSessionRequest(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    asp_id: str = Field(alias="aspId")
    external_application_id: str = Field(alias="externalApplicationId")
    event_id: str = Field(alias="eventId")


class DataReportingProvisioningSessionResponse(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    provisioning_session_id: str = Field(alias="provisioningSessionId")
    asp_id: str = Field(alias="aspId")
    external_application_id: str = Field(alias="externalApplicationId")
    event_id: str = Field(alias="eventId")
    data_reporting_configuration_ids: list[str] = Field(
        alias="dataReportingConfigurationIds"
    )


class DataReportingProvisioningSessionResult(BaseModel):
    status: int
    headers: dict[str, str]
    body: DataReportingProvisioningSessionResponse