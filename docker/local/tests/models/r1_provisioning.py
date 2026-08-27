"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""


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