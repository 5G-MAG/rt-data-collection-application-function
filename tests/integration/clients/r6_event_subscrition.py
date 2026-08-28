"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
"""

from .http_client import request
from ..models.r6_event_subscrition import (
    EventSubscription,
    EventSubscriptionResult,
    EventSubscriptionResponse
)
from ..settings import settings

SESSIONS_URL = (
    f"{settings.dcaf_r6.base_url}"
    "/naf-eventexposure/v1/subscriptions"
)


def create_event_subscription(payload: EventSubscription) -> EventSubscriptionResult:
    status, headers, body = request("POST", SESSIONS_URL, payload)
    return EventSubscriptionResult(
        status=status,
        headers=headers,
        body=EventSubscriptionResponse.model_validate(body),
    )


def get_event_subscription(
    event_subscription_id: str,
) -> EventSubscriptionResult:
    subscription_url = f"{SESSIONS_URL}/{event_subscription_id}"
    status, headers, body = request("GET", subscription_url, None)
    return EventSubscriptionResult(
        status=status,
        headers=headers,
        body=EventSubscriptionResponse.model_validate(body),
    )



def delete_event_subscription(event_subscription_id: str) -> int:
    subscription_url = f"{SESSIONS_URL}/{event_subscription_id}"
    status, _, _ = request("DELETE", subscription_url, None)
    return status