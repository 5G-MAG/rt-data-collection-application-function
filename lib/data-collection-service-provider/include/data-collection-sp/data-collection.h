/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_SVC_PRODUCER_H
#define DATA_COLLECTION_SVC_PRODUCER_H

#include <stdint.h>

#ifdef BUILD_DATA_COLLECTION_LIB
    #if defined _WIN32 || defined __CYGWIN__
        #ifdef __GNUC__
            #define DATA_COLLECTION_SVC_PRODUCER_API __attribute__ ((dllexport))
        #else
            #define DATA_COLLECTION_SVC_PRODUCER_API __declspec(dllexport)
        #endif
    #else
        #if __GNUC__ >= 4
            #define DATA_COLLECTION_SVC_PRODUCER_API __attribute__ ((visibility ("default")))
        #else
            #define DATA_COLLECTION_SVC_PRODUCER_API
        #endif
    #endif
#else
    #if defined _WIN32 || defined __CYGWIN__
        #ifdef __GNUC__
            #define DATA_COLLECTION_SVC_PRODUCER_API __attribute__ ((dllimport))
        #else
            #define DATA_COLLECTION_SVC_PRODUCER_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #else
        #define DATA_COLLECTION_SVC_PRODUCER_API
    #endif
#endif

#define DATA_COLLECTION_FEATURE_BIT(N) (UINT64_C(1)<<((N)-1))

#define INCLUDED_FROM_DATA_COLLECTION_H 1

#include "macros.h"
#include "event-exposure.h"
#include "aggregation-function.h"
#include "ogs-list-support.h"

#include "AccessTokenErr.h"
#include "AccessTokenReq.h"
#include "AccuracyFulfilmentIndicator_anyOf.h"
#include "AccuracyFulfilmentIndicator.h"
#include "AddrFqdn.h"
#include "AfEvent_anyOf.h"
#include "AfEvent.h"
#include "AfEventExposureNotif.h"
#include "AfEventExposureSubsc.h"
#include "AfEventNotification.h"
#include "ANBRNetworkAssistanceInvocationRecord.h"
#include "AppExpUeBehaviour.h"
#include "ApplicationFlowDescription.h"
#include "ApplicationSpecificRecord_allOf.h"
#include "ApplicationSpecificRecord.h"
#include "BaseEventCollection.h"
#include "BaseEventRecord.h"
#include "BaseRecord_1.h"
#include "BaseRecord.h"
#include "BatteryIndication_anyOf.h"
#include "BatteryIndication.h"
#include "BufferedNotificationsAction_anyOf.h"
#include "BufferedNotificationsAction.h"
#include "CacheStatus_anyOf.h"
#include "CacheStatus.h"
#include "CellIdentifierType_anyOf.h"
#include "CellIdentifierType.h"
#include "CivicAddress.h"
#include "CollectiveBehaviourFilter.h"
#include "CollectiveBehaviourFilterType_anyOf.h"
#include "CollectiveBehaviourFilterType.h"
#include "CollectiveBehaviourInfo.h"
#include "CommunicationCollection.h"
#include "CommunicationIndicator_anyOf.h"
#include "CommunicationIndicator.h"
#include "CommunicationRecord_allOf.h"
#include "CommunicationRecord.h"
#include "ConsumptionReportingEvent_allOf.h"
#include "ConsumptionReportingEvent.h"
#include "ConsumptionReportingUnitsCollection_allOf.h"
#include "ConsumptionReportingUnitsCollection.h"
#include "CpFailureCode_anyOf.h"
#include "CpFailureCode.h"
#include "CpParameterSet.h"
#include "DataAccessProfile.h"
#include "DataAccessProfile_locationAccessRestrictions.h"
#include "DataAccessProfile_timeAccessRestrictions.h"
#include "DataAccessProfile_userAccessRestrictions.h"
#include "DataAccessProfile_userAccessRestrictions_userIds_inner.h"
#include "DataAggregationFunctionType_anyOf.h"
#include "DataAggregationFunctionType.h"
#include "DataCollectionClientType_anyOf.h"
#include "DataCollectionClientType.h"
#include "DataDomain_anyOf.h"
#include "DataDomain.h"
#include "DataProcessingType_anyOf.h"
#include "DataProcessingType.h"
#include "DataReport.h"
#include "DataReportingCondition.h"
#include "DataReportingCondition_threshold.h"
#include "DataReportingConditionType_anyOf.h"
#include "DataReportingConditionType.h"
#include "DataReportingConfiguration.h"
#include "DataReportingConfigurationPatch.h"
#include "DataReportingEventTrigger_anyOf.h"
#include "DataReportingEventTrigger.h"
#include "DataReportingProvisioningSession.h"
#include "DataReportingRule.h"
#include "DataReportingSession.h"
#include "DataSamplingRule.h"
#include "DatVolTransTimeCollection.h"
#include "Direction_anyOf.h"
#include "Direction.h"
#include "DispersionCollection.h"
#include "DynamicPolicy.h"
#include "DynamicPolicyInvocationEvent_allOf.h"
#include "DynamicPolicyInvocationEvent.h"
#include "DynamicPolicyInvocationsCollection_allOf.h"
#include "DynamicPolicyInvocationsCollection.h"
#include "Ecgi.h"
#include "EllipsoidArc_allOf.h"
#include "EllipsoidArc.h"
#include "EndpointAddress.h"
#include "EthFlowDescription.h"
#include "EventConsumerType_anyOf.h"
#include "EventConsumerType.h"
#include "EventFilter.h"
#include "EventRecordType_anyOf.h"
#include "EventRecordType.h"
#include "EventsSubs.h"
#include "Exception.h"
#include "ExceptionId_anyOf.h"
#include "ExceptionId.h"
#include "ExceptionInfo.h"
#include "ExceptionTrend_anyOf.h"
#include "ExceptionTrend.h"
#include "FixType_anyOf.h"
#include "FixType.h"
#include "FlowDirection_anyOf.h"
#include "FlowDirection.h"
#include "FlowInfo.h"
#include "GADShape.h"
#include "GeographicalCoordinates.h"
#include "GeographicArea.h"
#include "GlobalRanNodeId.h"
#include "GNbId.h"
#include "GNSSAssistDataInfo.h"
#include "GnssId_anyOf.h"
#include "GnssId.h"
#include "GnssPositioningMethodAndUsage.h"
#include "GNSSServArea.h"
#include "HighAccuracyGnssMetrics.h"
#include "HorizontalVelocity.h"
#include "HorizontalVelocityWithUncertainty.h"
#include "HorizontalWithVerticalVelocityAndUncertainty.h"
#include "HorizontalWithVerticalVelocity.h"
#include "IndoorOutdoorInd_anyOf.h"
#include "IndoorOutdoorInd.h"
#include "InvalidParam.h"
#include "IpAddr.h"
#include "IpPacketFilterSet.h"
#include "Ipv6Addr.h"
#include "Ipv6Prefix.h"
#include "Local2dPointUncertaintyEllipse_allOf.h"
#include "Local2dPointUncertaintyEllipse.h"
#include "Local3dPointUncertaintyEllipsoid_allOf.h"
#include "Local3dPointUncertaintyEllipsoid.h"
#include "LocalArea.h"
#include "LocalOrigin.h"
#include "LocationArea5G.h"
#include "LocationData.h"
#include "LocationRecord_allOf.h"
#include "LocationRecord.h"
#include "LosNlosMeasureInd_anyOf.h"
#include "LosNlosMeasureInd.h"
#include "M5BitRateSpecification.h"
#include "M5QoSSpecification.h"
#include "MediaStreamingAccess.h"
#include "MediaStreamingAccess_connectionMetrics.h"
#include "MediaStreamingAccessesCollection_allOf.h"
#include "MediaStreamingAccessesCollection.h"
#include "MediaStreamingAccessEvent.h"
#include "MediaStreamingAccessRecord.h"
#include "MediaStreamingAccess_requestMessage.h"
#include "MediaStreamingAccess_responseMessage.h"
#include "MediaStreamingBaseReportingRecord.h"
#include "MediaStreamingSessionIdentification.h"
#include "MediaTransportProto_anyOf.h"
#include "MediaTransportProto.h"
#include "MediaType_anyOf.h"
#include "MediaType.h"
#include "MinorLocationQoS.h"
#include "MlModelInterInd.h"
#include "MSAccessActivityCollection.h"
#include "MsConsumptionCollection.h"
#include "MsDynPolicyInvocationCollection.h"
#include "MsNetAssInvocationCollection.h"
#include "MsQoeMetricsCollection.h"
#include "MutingExceptionInstructions.h"
#include "MutingNotificationsSettings.h"
#include "Ncgi.h"
#include "NetworkAreaInfo.h"
#include "NetworkAssistanceInvocation.h"
#include "NetworkAssistanceInvocationEvent_allOf.h"
#include "NetworkAssistanceInvocationEvent.h"
#include "NetworkAssistanceInvocation_recommendedQoS.h"
#include "NetworkAssistanceInvocationsCollection_allOf.h"
#include "NetworkAssistanceInvocationsCollection.h"
#include "NetworkAssistanceSession.h"
#include "NetworkAssistanceType_anyOf.h"
#include "NetworkAssistanceType.h"
#include "NFType_anyOf.h"
#include "NFType.h"
#include "NoProfileMatchInfo.h"
#include "NoProfileMatchReason_anyOf.h"
#include "NoProfileMatchReason.h"
#include "NotificationFlag_anyOf.h"
#include "NotificationFlag.h"
#include "NotificationMethod_anyOf.h"
#include "NotificationMethod.h"
#include "NwdafEvent_anyOf.h"
#include "NwdafEvent.h"
#include "PartitioningCriteria_anyOf.h"
#include "PartitioningCriteria.h"
#include "PduSetHandlingInfo_anyOf.h"
#include "PduSetHandlingInfo.h"
#include "PduSetQosPara.h"
#include "PerFlowServiceExperienceInfo.h"
#include "PerformanceData.h"
#include "PerformanceDataCollection.h"
#include "PerformanceDataRecord_allOf.h"
#include "PerformanceDataRecord.h"
#include "PeriodicEventInfo.h"
#include "PerUeAttribute.h"
#include "PlmnId.h"
#include "PlmnIdNid.h"
#include "Point_allOf.h"
#include "PointAltitude_allOf.h"
#include "PointAltitude.h"
#include "PointAltitudeUncertainty_allOf.h"
#include "PointAltitudeUncertainty.h"
#include "Point.h"
#include "PointUncertaintyCircle_allOf.h"
#include "PointUncertaintyCircle.h"
#include "PointUncertaintyEllipse_allOf.h"
#include "PointUncertaintyEllipse.h"
#include "Polygon_allOf.h"
#include "Polygon.h"
#include "PositioningMethodAndUsage.h"
#include "PositioningMethod_anyOf.h"
#include "PositioningMethod.h"
#include "PositioningMode_anyOf.h"
#include "PositioningMode.h"
#include "ProblemDetails.h"
#include "ProtocolDescription.h"
#include "ProvisioningSessionType_anyOf.h"
#include "ProvisioningSessionType.h"
#include "QoEMetricsCollection_allOf.h"
#include "QoEMetricsCollection.h"
#include "QoEMetricsEvent_allOf.h"
#include "QoEMetricsEvent_allOf_metrics.h"
#include "QoEMetricsEvent_allOf_samples.h"
#include "QoEMetricsEvent.h"
#include "QueryParamCombination.h"
#include "QueryParameter.h"
#include "r_2DRelativeLocation.h"
#include "r_3DRelativeLocation.h"
#include "RangeDirection.h"
#include "RedirectResponse.h"
#include "RelativeCartesianLocation.h"
#include "RelativeDirection_anyOf.h"
#include "RelativeDirection.h"
#include "ReportingInformation.h"
#include "RtpHeaderExtInfo.h"
#include "RtpHeaderExtType_anyOf.h"
#include "RtpHeaderExtType.h"
#include "RtpPayloadFormat_anyOf.h"
#include "RtpPayloadFormat.h"
#include "RtpPayloadInfo.h"
#include "ScheduledCommunicationTime.h"
#include "ScheduledCommunicationType_anyOf.h"
#include "ScheduledCommunicationType.h"
#include "SdfMethod_anyOf.h"
#include "SdfMethod.h"
#include "ServiceExperienceInfoPerApp.h"
#include "ServiceExperienceInfoPerFlow.h"
#include "ServiceExperienceRecord_allOf.h"
#include "ServiceExperienceRecord.h"
#include "Snssai.h"
#include "StationaryIndication_anyOf.h"
#include "StationaryIndication.h"
#include "SubscriptionAction_anyOf.h"
#include "SubscriptionAction.h"
#include "SupportedGADShapes_anyOf.h"
#include "SupportedGADShapes.h"
#include "SvcExperience.h"
#include "Tai.h"
#include "TimeWindow.h"
#include "TrafficProfile_anyOf.h"
#include "TrafficProfile.h"
#include "TripPlanRecord_allOf.h"
#include "TripPlanRecord.h"
#include "TypedLocation.h"
#include "UeAreaIndication.h"
#include "UeCommunicationCollection.h"
#include "UeMobilityCollection.h"
#include "UeTrajectoryCollection.h"
#include "UmtLocationArea5G_allOf.h"
#include "UmtLocationArea5G.h"
#include "UncertaintyEllipse.h"
#include "UncertaintyEllipsoid.h"
#include "UnidirectionalQoSSpecification.h"
#include "Usage_anyOf.h"
#include "Usage.h"
#include "UsageThreshold.h"
#include "UserDataCongestionCollection.h"
#include "VelocityEstimate.h"
#include "VerticalDirection.h"

#include "data-reporting.h"
#include "data-reporting-provisioning.h"
#include "data-reporting-configuration.h"
#include "lifecycle.h"

#undef INCLUDED_FROM_DATA_COLLECTION_H

#endif /* DATA_COLLECTION_SVC_PRODUCER_H */
