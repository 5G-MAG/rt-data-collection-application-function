"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""


from pydantic import BaseModel, ConfigDict, Field


class TimeWindow(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    start_time: str = Field(alias="startTime")
    stop_time: str = Field(alias="stopTime")


class CommunicationRecord(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    timestamp: str
    context_ids: list[str] = Field(alias="contextIds")
    time_interval: TimeWindow = Field(alias="timeInterval")
    uplink_volume: int = Field(alias="uplinkVolume")
    downlink_volume: int = Field(alias="downlinkVolume")


class DataReporting(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    external_application_id: str = Field(alias="externalApplicationId")
    communication_records: list[CommunicationRecord] = Field(
        alias="communicationRecords"
    )