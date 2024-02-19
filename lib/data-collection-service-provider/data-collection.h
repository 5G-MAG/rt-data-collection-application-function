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
#include "ogs-core.h"
#include "ogs-proto.h"
#include "ogs-sbi.h"

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

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE=0x00000001,
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING=0x00000002,
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING=0x00000004,
    DATA_COLLECTION_FEATURE_SERVER_ALL=0x00000007, /* All API server features */
} data_collection_feature_flags_e;

typedef enum {
    DATA_COLLECTION_DATA_REPORT_PROPERTY_SERVICE_EXPERIENCE,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_LOCATION,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_COMMUNICATION,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_PERFORMANCE,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_APP_SPECIFIC,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_TRIP_PLAN,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_MEDIA_STREAMING_ACCESS,
    DATA_COLLECTION_DATA_REPORT_PROPERTY_ANBR_NET_ASSIST_INVOCATION
} data_collection_data_report_property_e;

#define DATA_COLLECTION_FEATURE_BIT(N) (UINT64_C(1)<<((N)-1))

/* Event Exposure supported feature numbers from TS 29.517 v18.4.0 Table 5.8-1 */
typedef enum {
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE=DATA_COLLECTION_FEATURE_BIT(1),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_MOBILITY=DATA_COLLECTION_FEATURE_BIT(2),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION=DATA_COLLECTION_FEATURE_BIT(3),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_EXCEPTIONS=DATA_COLLECTION_FEATURE_BIT(4),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ES3XX=DATA_COLLECTION_FEATURE_BIT(5),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENHANCED_NA=DATA_COLLECTION_FEATURE_BIT(6),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_USER_DATA_CONGESTION=DATA_COLLECTION_FEATURE_BIT(7),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_PERFORMANCE_DATA=DATA_COLLECTION_FEATURE_BIT(8),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DISPERSION=DATA_COLLECTION_FEATURE_BIT(9),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_COLLECTIVE_BEHAVIOUR=DATA_COLLECTION_FEATURE_BIT(10),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE_EXT=DATA_COLLECTION_FEATURE_BIT(11),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_QOE_METRICS=DATA_COLLECTION_FEATURE_BIT(12),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_CONSUMPTION=DATA_COLLECTION_FEATURE_BIT(13),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_NET_ASSIST_INVOCN=DATA_COLLECTION_FEATURE_BIT(14),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_DYN_POLICY_INVOCN=DATA_COLLECTION_FEATURE_BIT(15),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_ACCESS_ACTIVITY=DATA_COLLECTION_FEATURE_BIT(16),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DATA_ACCESS_PROFILE_ID=DATA_COLLECTION_FEATURE_BIT(17),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ALL_APPLICATIONS=DATA_COLLECTION_FEATURE_BIT(18),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_GNSS_ASSIST_DATA=DATA_COLLECTION_FEATURE_BIT(19),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_PERFORMANCE_DATA_AIML=DATA_COLLECTION_FEATURE_BIT(20),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_MOBILITY_AIML=DATA_COLLECTION_FEATURE_BIT(21),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENH_PERFORMANCE_DATA=DATA_COLLECTION_FEATURE_BIT(22),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION_ENA=DATA_COLLECTION_FEATURE_BIT(23),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE_ENA=DATA_COLLECTION_FEATURE_BIT(24),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENH_DATA_MANAGEMENT=DATA_COLLECTION_FEATURE_BIT(25),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_EXTENDED_EVENT_FILTERS=DATA_COLLECTION_FEATURE_BIT(26),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DATA_VOL_TRANSFER_TIME=DATA_COLLECTION_FEATURE_BIT(27),
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_EVENT_EXPOSURE=DATA_COLLECTION_FEATURE_BIT(28)
} data_collection_supported_features_event_e;

typedef struct data_collection_data_event_s {
    const char *event_type;     /** See TS 29.517 Table 5.6.3.3-1 for standard event types */
    struct timespec timestamp;     /** nano-second accurate UTC time when the event was observed */
    const char *event_attribute_name;     /** Attribute name to report the event data with */
    cJSON *event_data;     /** event data as a JSON object/array */
} data_collection_data_event_t;

typedef struct data_collection_data_report_type_s {
    const char *type_name;
    data_collection_data_report_property_e data_report_property;
    const char *data_domain;      /* derived from data_report_property if NULL */
    void *(* const parse_report_data)(const data_collection_reporting_session_t *session, cJSON *json, const char **error_return);
    void *(* const clone_report_data)(const void *report_data);
    void (* const free_report_data)(void *report_data);
    cJSON *(* const json_for_report_data)(const void *report_data);
    struct timespec *(* const timestamp_for_report_data)(const void *report_data);
    char *(* const tag_for_report_data)(const void *report_data);
    char *(* const serialise_report_data)(const void *report_data);
} data_collection_data_report_type_t;

typedef struct data_collection_data_report_s data_collection_data_report_t;

typedef ogs_list_t* (*data_collection_event_generation_cb)(const ogs_list_t *reports  /* filtering parameters from subscriptions - TBD*/);

typedef struct data_collection_configuration_s {
    const char* configuration_section;
    int         disable_features;    /* ORed data_collection_feature_flags_e values of features to disable*/
    uint64_t    event_exposure_supported_features;       /* supported features bitmask for TS 29.517 event subscription */
    const data_collection_data_report_type_t * const *data_report_types; /* NULL terminated array of data report types implemented by the AF */
    data_collection_event_generation_cb  event_generation_callback;      /* called to turn reports into events to expose via reference points R5 & R6 */
} data_collection_configuration_t;

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_initialise(const data_collection_configuration_t* const configuration);

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_set_nf_services(void);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_finalise(void);

/**
 * Process an ogs_event_t
 *
 * Checks the ogs_event_t to see if it is an event associated with this service producer and serves it if it is.
 *
 * @param event The event to check.
 *
 * @return `true` if the service consumer has dealt with the event, no further processing should be done for this event. If the
 *         return value is `false` then the service consumer has not consumed the event and it should be processed by the
 *         application as normal.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_process_event(ogs_event_t *event);


#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_SVC_PRODUCER_H */
