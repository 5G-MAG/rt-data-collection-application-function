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



class EventFilter(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    any_ue_ind: bool = Field(alias="anyUeInd")


class EventsSubs(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    event: str
    event_filter: EventFilter = Field(alias="eventFilter")


class EventsRepInfo(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    immediate_report: bool = Field(alias="immRep")
    notification_method: str = Field(alias="notifMethod")
    reporting_period: int = Field(alias="repPeriod")


class EventSubscription(BaseModel):
    model_config = ConfigDict(populate_by_name=True)

    events_subs: list[EventsSubs] = Field(alias="eventsSubs")
    events_rep_info: EventsRepInfo = Field(alias="eventsRepInfo")
    notification_uri: str = Field(alias="notifUri")
    notification_id: str = Field(alias="notifId")
    supported_features: str = Field(alias="suppFeat")

class EventSubscriptionResponse(EventSubscription):
    pass


class EventSubscriptionResult(BaseModel):
    status: int
    headers: dict[str, str]
    body: EventSubscriptionResponse