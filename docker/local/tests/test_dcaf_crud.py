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

from tests.clients.r1_provisioning import (
    create_provisioning_session,
    delete_provisioning_session,
    get_provisioning_session,
)
from tests.clients.r1_configuration import (
    create_data_reporting_configuration,
    delete_data_reporting_configuration,
    get_data_reporting_configuration,
)
from tests.models.r1_provisioning import CreateDataReportingProvisioningSessionRequest

from tests.models.r1_configuration import (
    DataReportingConfigurationRequest,
    DataAccessProfile,
    DataReportingCondition,
    DataSamplingRule,
    TimeAccessRestrictions,
)

from tests.clients.r2_data_reporting_session import (
    create_data_reporting_session,
    get_data_reporting_session,
    delete_data_reporting_session
)

from tests.models.r2_data_reporting_session import (
    DataReportingSession,
    DataReportingSessionResponse,
    DataReportingSessionResult
)

provisioning_session_request = CreateDataReportingProvisioningSessionRequest(
    asp_id="5G-MAGAspId",
    external_application_id="5G-MAGAppID",
    event_id="UE_COMM",
)

data_reporting_configuration_request = DataReportingConfigurationRequest(
    data_collection_client_type="DIRECT",
    data_sampling_rules=[
        DataSamplingRule(sampling_period=10.0),
    ],
    data_reporting_rules=[
        {},
    ],
    data_reporting_conditions=[
        DataReportingCondition(
            type="INTERVAL",
            period=60,
        ),
    ],
    data_access_profiles=[
        DataAccessProfile(
            data_access_profile_id="per_min_totals",
            target_event_consumer_types=[
                "NWDAF",
                "EVENT_CONSUMER_AF",
            ],
            parameters=[],
            time_access_restrictions=TimeAccessRestrictions(
                duration=60,
                aggregation_functions=["SUM"],
            ),
        ),
    ],
)

data_reporting_session_request = DataReportingSession(
    externalApplicationId = "MyAppID",
    supportedDomains= ["COMMUNICATION"]
)


def test_crud_data_reporting_AF() -> None:

    provisioning_session_id_from_location: str | None = None
    data_reporting_configuration_id: str | None = None
    data_reporting_session_id: str | None = None

    try:
        # ========================================================= #
        #        R1 - Data Reporting Provisioning Session
        # ========================================================= #
        # 1. POST: Create the Data reporting PS and validate its response.
        

        create_data_reporting_ps = create_provisioning_session(provisioning_session_request)
        assert create_data_reporting_ps.status == 201
        location = create_data_reporting_ps.headers.get("location")
        assert location, "Response does not contain a Location header"
        provisioning_session_id_from_location = location.rstrip("/").split("/")[-1]

        assert create_data_reporting_ps.body.data_reporting_configuration_ids == []
        assert create_data_reporting_ps.body.event_id == provisioning_session_request.event_id
        assert (
            create_data_reporting_ps.body.external_application_id
            == provisioning_session_request.external_application_id
        )
        assert (
            create_data_reporting_ps.body.provisioning_session_id
            == provisioning_session_id_from_location
        )

        # 2. GET: Data reporting PS 
        created_data_reporting_ps = get_provisioning_session(
            provisioning_session_id_from_location
        )
        assert created_data_reporting_ps.status == 201
        assert (
            created_data_reporting_ps.body.provisioning_session_id
            == provisioning_session_id_from_location
        )
        assert created_data_reporting_ps.body.asp_id == provisioning_session_request.asp_id
        assert (
            created_data_reporting_ps.body.external_application_id
            == provisioning_session_request.external_application_id
        )
        assert created_data_reporting_ps.body.event_id == provisioning_session_request.event_id
        assert created_data_reporting_ps.body.data_reporting_configuration_ids == []

        # ========================================================= #
        #        R1 - Data Reporting Configuration
        # ========================================================= #
        
        # Create a new Data Reporting Configuration
        created_configuration = create_data_reporting_configuration(
            data_reporting_configuration_request, 
            provisioning_session_id_from_location,
        )
        assert created_configuration.status == 201
        configuration = created_configuration.body
        assert (
            configuration.data_collection_client_type
            == data_reporting_configuration_request.data_collection_client_type
        )
        assert (
            configuration.data_sampling_rules
            == data_reporting_configuration_request.data_sampling_rules
        )
        assert (
            configuration.data_reporting_conditions
            == data_reporting_configuration_request.data_reporting_conditions
        )
        access_profile = configuration.data_access_profiles[0]
        expected_access_profile = data_reporting_configuration_request.data_access_profiles[0]
        assert access_profile == expected_access_profile
        data_reporting_configuration_id = configuration.data_reporting_configuration_id

        # GET: Retrieve the existing Data Reporting Configuration.
        get_configuration = get_data_reporting_configuration(
            provisioning_session_id_from_location,
            data_reporting_configuration_id,
        )
        assert get_configuration.status == 201 # 200
        configuration = get_configuration.body
        assert (
            configuration.data_collection_client_type
            == data_reporting_configuration_request.data_collection_client_type
        )
        assert (
            configuration.data_sampling_rules
            == data_reporting_configuration_request.data_sampling_rules
        )
        assert (
            configuration.data_reporting_conditions
            == data_reporting_configuration_request.data_reporting_conditions
        )
        assert (
            configuration.data_access_profiles
            == data_reporting_configuration_request.data_access_profiles
        )
        assert configuration.data_reporting_configuration_id == data_reporting_configuration_id
        
        # ========================================================= #
        #        R2 - Data Reporting Session
        # ========================================================= #
        # Create a new Data Reporting Session
        created_data_reporting_session = create_data_reporting_session(
            data_reporting_session_request
        )
        assert created_data_reporting_session.status == 201
        session = created_data_reporting_session.body
        assert session.session_id
        assert session.valid_until is None
        assert (
            session.external_application_id
            == data_reporting_session_request.external_application_id
        )
        assert session.supported_domains == data_reporting_session_request.supported_domains
        data_reporting_session_id = session.session_id
        expected_empty_rules = {
            domain: [] for domain in data_reporting_session_request.supported_domains
        }
        assert session.sampling_rules == expected_empty_rules
        assert session.reporting_conditions == expected_empty_rules
        assert session.reporting_rules == expected_empty_rules

        # Read the created Data Reporting Session.
        retrieved_data_reporting_session = get_data_reporting_session(
            data_reporting_session_id
        )
        assert retrieved_data_reporting_session.status == 200
        assert retrieved_data_reporting_session.body == session

    # ==============================================================================
    # Clean Up
    # ==============================================================================
    # R1 - Data Reporting Provisioning Session
    # DELETE
    finally:
        if data_reporting_session_id is not None:
            assert delete_data_reporting_session(data_reporting_session_id) == 204

        if data_reporting_configuration_id is not None:
            assert (
                delete_data_reporting_configuration(
                    provisioning_session_id_from_location,
                    data_reporting_configuration_id,
                )
                == 204
            )

        if provisioning_session_id_from_location is not None:
            assert delete_provisioning_session(provisioning_session_id_from_location) == 204
