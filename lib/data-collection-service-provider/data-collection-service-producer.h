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

typedef struct data_collection_data_event_s {
    const char *event_type;     /** See TS 29.517 Table 5.6.3.3-1 for standard event types */
    struct timespec timestamp;     /** nano-second accurate UTC time when the event was observed */
    const char *event_attribute_name;     /** Attribute name to report the event data with */
    cJSON *event_data;     /** event data as a JSON object/array */
} data_collection_data_event_t;

//typedef data_collection_data_report_t* (*data_collection_data_report_cb)(const char *data_type, cJSON *data_objects, const char **parse_err);

typedef ogs_list_t* (*data_collection_event_generation_cb)(const ogs_list_t *reports /*,  filtering parameters from subscriptions - TBD*/);

typedef struct data_collection_configuration_s {
    const char* const configuration_section;
    int               disable_features;    /* ORed data_collection_feature_flags_e values of features to disable*/
    uint64_t          event_exposure_supported_features;       /* supported features bitmask for TS 29.517 event subscription */
    //data_collection_data_report_cb  data_report_callback;     /* called when the library needs a data report converting into an object */
    data_collection_event_generation_cb  event_generation_callback;      /* called to turn reports into events to expose via reference points R5 & R6 */
} data_collection_configuration_t;

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_initialise(const data_collection_configuration_t* const configuration);


DATA_COLLECTION_SVC_PRODUCER_API const ogs_list_t *data_collection_nf_services(void);

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
