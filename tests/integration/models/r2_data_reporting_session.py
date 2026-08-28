"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""


from typing import Any

from pydantic import BaseModel, ConfigDict, Field


class DataReportingSession(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    external_application_id: str = Field(alias="externalApplicationId")
    supported_domains: list[str] = Field(alias="supportedDomains")


class DataReportingSessionResponse(DataReportingSession):
    session_id: str = Field(alias="sessionId")
    valid_until: str | None = Field(default=None, alias="validUntil")
    sampling_rules: dict[str, list[Any]] = Field(alias="samplingRules")
    reporting_conditions: dict[str, list[Any]] = Field(
        alias="reportingConditions"
    )
    reporting_rules: dict[str, list[Any]] = Field(alias="reportingRules")


class DataReportingSessionResult(BaseModel):
    status: int
    headers: dict[str, str]
    body: DataReportingSessionResponse
