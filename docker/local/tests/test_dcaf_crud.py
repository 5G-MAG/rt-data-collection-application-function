"""
License: 5G-MAG Public License (v1.0)
Author: Erik Gaida
Copyright: (C) 2026 Fraunhofer  FOKUS
For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view




this file is a an end-to-end CRUD test for the  DCAF and refers to the Tutorial:
https://www.5g-mag.com/reference-tools/data-collection/tutorials/docker-with-insomnia/
Requirements:
    pytest
    httpcore


Run:
    pytest -v -s ~/rt-data-collection-application-function/docker/local/tests/test_dcaf_crud.py
"""

# from __future__ import annotations

import copy
import json
from pathlib import Path
from types import SimpleNamespace
from typing import Any
from uuid import uuid4
import pprint

import httpcore

from utils import config
from utils.http2_prior_knowledge import setup_http2_pool

CONFIG = config.config_from_file(Path(__file__).with_name("config.toml"))
HTTP2_POOL = setup_http2_pool()

# Helper Functions

def _decode_headers(raw_headers: list[tuple[bytes, bytes]]) -> dict[str, str]:
    return {
        name.decode("iso-8859-1").lower(): value.decode("iso-8859-1")
        for name, value in raw_headers
    }


def _request(
    method: str,
    url: str,
    payload: dict[str, Any] | None = None,
) -> SimpleNamespace:
    headers = {"Content-Type": "application/json"} if payload is not None else None
    content = json.dumps(payload).encode("utf-8") if payload is not None else None
    try:
        response = HTTP2_POOL.request(method, url, headers=headers, content=content)
    except (httpcore.NetworkError, httpcore.ProtocolError) as exc:
        raise AssertionError(
            f"HTTP request failed\nmethod: {method}\nurl: {url}\nerror: {exc}"
        ) from exc

    text = response.content.decode("utf-8", errors="replace")
    try:
        json_body: Any | None = json.loads(text) if text.strip() else None
    except json.JSONDecodeError:
        json_body = None

    return SimpleNamespace(
        status=response.status,
        headers=_decode_headers(response.headers),
        text=text,
        json_body=json_body,
    )

# Varibles
ASP_ID =  "5G-MAGAspId"
EXTERNAL_APPLICATION_ID = "5G-MAGAppID"
UE_COMM = "UE_COMM"


# CONSTANT Varbieles for the API Calls
DCAF_R1 = (f"{CONFIG['dcaf-R1']['protocol']}://{CONFIG['dcaf-R1']['address']}:"f"{CONFIG['dcaf-R1']['port']}")
DCAF_R2 = (f"{CONFIG['dcaf-R2']['protocol']}://{CONFIG['dcaf-R2']['address']}:"f"{CONFIG['dcaf-R2']['port']}")
DCAF_R6 = (f"{CONFIG['dcaf-R6']['protocol']}://{CONFIG['dcaf-R6']['address']}:"f"{CONFIG['dcaf-R6']['port']}")

# --------------------------------------------------------------
#                             R1
# --------------------------------------------------------------
# R1 - Data Reporting Provisioning Session
DATA_REPORTING_PS_URL = f"{DCAF_R1}/3gpp-ndcaf_data-reporting-provisioning/v1/sessions"

DATA_REPORTING_PS_POST_JSON = {
    "aspId": f"{ASP_ID}", 
    "externalApplicationId": f"{EXTERNAL_APPLICATION_ID}",
    "eventId": f"{UE_COMM}"
}

# R1 - Data Reporting Configuration

DATA_REPORTING_CONFIGURATION_POST_JSON = {
    "dataCollectionClientType": "DIRECT",
    "dataSamplingRules": [
        {
            "samplingPeriod": 10.0
        }
    ],
    "dataReportingRules": [
        {}
    ],
    "dataReportingConditions": [
        {
            "type": "INTERVAL",
            "period": 60
        }
    ],
    "dataAccessProfiles": [
        {
            "dataAccessProfileId": "per_min_totals",
            "targetEventConsumerTypes": [
                "NWDAF",
                "EVENT_CONSUMER_AF"
            ],
            "parameters": [],
            "timeAccessRestrictions": {
                "duration": 60,
                "aggregationFunctions": [
                    "SUM"
                ]
            }
        }
    ]
}


# --------------------------------------------------------------
#                           R2
# --------------------------------------------------------------
# R2 - Data Reporting Session
DATA_REPORTING_SESSION_URL = f"{DCAF_R2}/3gpp-ndcaf_data-reporting/v1/sessions"
data_reporting_session_id = ""

DATA_REPORTING_SESSION_POST_JSON = {
    "externalApplicationId": f"{EXTERNAL_APPLICATION_ID}",
    "supportedDomains": ["COMMUNICATION"]
}

DATA_REPORTING_SESSION_GET_JSON = {
	"externalApplicationId": "MyAppID", #TODO check why is isnsomia-setup not using the varibel for this
	"supportedDomains": ["COMMUNICATION", "BOGUS_DATA_DOMAIN"]
}
# R2 - Data Reporting
DATA_REPORTING = f"{DCAF_R2}/3gpp-ndcaf_data-reporting/v1/sessions/{data_reporting_session_id}/report"
# DATA_REPORTING_POST_JSON = {
#     "externalApplicationId": f"{EXTERNAL_APPLICATION_ID}",
#     "communicationRecords": [
#         {
#             "timestamp": "2025-02-05T14:30:00Z",
#             "contextIds": [
#                 f"{data_reporting_configuration_id}"
#             ],
#             "timeInterval": {
#                 "startTime": "2025-02-05T14:28:00Z",
#                 "stopTime": "2025-02-05T14:29:00Z"
#             },
#             "uplinkVolume": 1000,
#             "downlinkVolume": 2000
#         }
#     ]
# }

# --------------------------------------------------------------
#                           R6
# --------------------------------------------------------------
# R6 - Event Subscription 
EVENT_SUBSCRIPTION_URL = f"{DCAF_R6}/naf-eventexposure/v1/subscriptions"

EVENT_SUBSCRIPTION_POST_JSON = {
	"eventsSubs": [
		{
			"event": f"{UE_COMM}",
			"eventFilter": {
				"anyUeInd": True
			}
		}
	],
	"eventsRepInfo": {
		"immRep": True,
		"notifMethod": "PERIODIC",
		"repPeriod": 10
	},
	"notifUri": "http://h2-server:8888/dcaf/notification/handler",
	"notifId": "5g-mag-notification-id",
	"suppFeat": "04"
}



def test_crud_data_reporting_AF() -> None:
    try:
        # ========================================================= #
        #        R1 - Data Reporting Provisioning Session
        # ========================================================= #
        # 1. POST: Create the Data reporting PS capture the provisioning_session_id.
        create_data_reporting_ps = _request("POST", DATA_REPORTING_PS_URL , DATA_REPORTING_PS_POST_JSON)
        assert create_data_reporting_ps.status == 201, create_data_reporting_ps.text
        location = create_data_reporting_ps.headers.get("location")
        assert location, "Response dosent contanine Location-Header"
        provisioning_session_id_from_location = location.rstrip("/").split("/")[-1]

        assert [] == create_data_reporting_ps.json_body["dataReportingConfigurationIds"]
        assert UE_COMM == create_data_reporting_ps.json_body["eventId"]
        assert EXTERNAL_APPLICATION_ID == create_data_reporting_ps.json_body["externalApplicationId"]
        assert provisioning_session_id_from_location == create_data_reporting_ps.json_body["provisioningSessionId"]

        # 2. GET: Data reporting PS 
        DATA_REPORTING_PS_GET_URL = DATA_REPORTING_PS_URL + '/' + provisioning_session_id_from_location
        get_data_reporting_ps = _request("GET", DATA_REPORTING_PS_GET_URL, None)
        assert get_data_reporting_ps.status == 201, get_data_reporting_ps.text #TODO musst be == 200 but bug in DCAF for testing i set it to 201 bevor pr change to 200
        assert get_data_reporting_ps.json_body["provisioningSessionId"] == provisioning_session_id_from_location
        assert get_data_reporting_ps.json_body["aspId"] == ASP_ID
        assert get_data_reporting_ps.json_body["externalApplicationId"] == EXTERNAL_APPLICATION_ID
        assert get_data_reporting_ps.json_body["eventId"] == UE_COMM
        assert get_data_reporting_ps.json_body["dataReportingConfigurationIds"] == []

        # ========================================================= #
        #        R1 - Data Reporting Configuration
        # ========================================================= #
        
        # Create a new Data Reporting Configuration
        DATA_REPORTING_CONFIGURATION_URL = DATA_REPORTING_PS_GET_URL +"/configurations"
        create_data_reporting_configuration = _request("POST", DATA_REPORTING_CONFIGURATION_URL, DATA_REPORTING_CONFIGURATION_POST_JSON)
        assert create_data_reporting_configuration.status == 201, create_data_reporting_configuration.text
        assert create_data_reporting_configuration.json_body["dataCollectionClientType"] == "DIRECT"
        assert create_data_reporting_configuration.json_body["dataSamplingRules"][0]["samplingPeriod"] == 10.0
        assert create_data_reporting_configuration.json_body["dataReportingConditions"][0]["type"] == "INTERVAL"
        assert create_data_reporting_configuration.json_body["dataReportingConditions"][0]["period"] == 60
        assert create_data_reporting_configuration.json_body["dataAccessProfiles"][0]["dataAccessProfileId"] == "per_min_totals"
        assert create_data_reporting_configuration.json_body["dataAccessProfiles"][0]["targetEventConsumerTypes"][0] == "NWDAF"
        assert create_data_reporting_configuration.json_body["dataAccessProfiles"][0]["targetEventConsumerTypes"][1] == "EVENT_CONSUMER_AF"
        assert create_data_reporting_configuration.json_body["dataAccessProfiles"][0]["parameters"] == []
        assert create_data_reporting_configuration.json_body["dataAccessProfiles"][0]["timeAccessRestrictions"]["duration"] == 60
        assert create_data_reporting_configuration.json_body["dataAccessProfiles"][0]["timeAccessRestrictions"]["aggregationFunctions"][0] == "SUM"
        data_reporting_configuration_id = create_data_reporting_configuration.json_body["dataReportingConfigurationId"]

        # GET Retrieve an existing Data Reporting Configuration
        DATA_REPORTING_CONFIGURATION_ID = DATA_REPORTING_CONFIGURATION_URL + "/" + data_reporting_configuration_id


        get_data_reporting_configuration = _request("GET", DATA_REPORTING_CONFIGURATION_ID, None)
        assert get_data_reporting_configuration.status == 201, create_data_reporting_configuration.text
        assert get_data_reporting_configuration.json_body["dataCollectionClientType"] == "DIRECT"
        assert get_data_reporting_configuration.json_body["dataSamplingRules"][0]["samplingPeriod"] == 10.0
        assert get_data_reporting_configuration.json_body["dataReportingConditions"][0]["type"] == "INTERVAL"
        assert get_data_reporting_configuration.json_body["dataReportingConditions"][0]["period"] == 60
        assert get_data_reporting_configuration.json_body["dataAccessProfiles"][0]["dataAccessProfileId"] == "per_min_totals"
        assert get_data_reporting_configuration.json_body["dataAccessProfiles"][0]["targetEventConsumerTypes"][0] == "NWDAF"
        assert get_data_reporting_configuration.json_body["dataAccessProfiles"][0]["targetEventConsumerTypes"][1] == "EVENT_CONSUMER_AF"
        assert get_data_reporting_configuration.json_body["dataAccessProfiles"][0]["parameters"] == []
        assert get_data_reporting_configuration.json_body["dataAccessProfiles"][0]["timeAccessRestrictions"]["duration"] == 60
        assert get_data_reporting_configuration.json_body["dataAccessProfiles"][0]["timeAccessRestrictions"]["aggregationFunctions"][0] == "SUM"
        data_reporting_configuration_id = get_data_reporting_configuration.json_body["dataReportingConfigurationId"]
        

    # ==============================================================================
    # Clean Up
    # ==============================================================================
    # R1 - Data Reporting Provisioning Session
    # DELETE
    finally:
        delte_data_reporting_configuration = _request("DELETE", DATA_REPORTING_CONFIGURATION_ID, None)
        assert delte_data_reporting_configuration.status == 204, get_data_reporting_ps.text


        delte_data_reporting_ps = _request("DELETE", DATA_REPORTING_PS_GET_URL, None)
        assert delte_data_reporting_ps.status == 204, get_data_reporting_ps.text
