from pydantic import BaseModel, ConfigDict, Field


class DataSamplingRule(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    sampling_period: float = Field(alias="samplingPeriod")


class DataReportingCondition(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    type: str
    period: int


class TimeAccessRestrictions(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    duration: int
    aggregation_functions: list[str] = Field(alias="aggregationFunctions")


class DataAccessProfile(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    data_access_profile_id: str = Field(alias="dataAccessProfileId")
    target_event_consumer_types: list[str] = Field(
        alias="targetEventConsumerTypes"
    )
    parameters: list[object]
    time_access_restrictions: TimeAccessRestrictions = Field(
        alias="timeAccessRestrictions"
    )

class DataReportingConfigurationRequest(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    data_collection_client_type: str = Field(alias="dataCollectionClientType")
    data_sampling_rules: list[DataSamplingRule] = Field(alias="dataSamplingRules")
    data_reporting_rules: list[dict] = Field(alias="dataReportingRules")
    data_reporting_conditions: list[DataReportingCondition] = Field(
        alias="dataReportingConditions"
    )
    data_access_profiles: list[DataAccessProfile] = Field(alias="dataAccessProfiles")


class DataReportingConfigurationResponse(DataReportingConfigurationRequest):
    data_reporting_configuration_id: str = Field(
        alias="dataReportingConfigurationId"
    )


class DataReportingConfigurationResult(BaseModel):
    status: int
    headers: dict[str, str]
    body: DataReportingConfigurationResponse