/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_LIFE_CYCLE_H
#define DATA_COLLECTION_LIFE_CYCLE_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "ogs-core.h"
#include "ogs-proto.h"
#include "ogs-sbi.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/** Library features flags
 *
 * Features can be disabled in the data_collection_configuration_t
 */

typedef enum {
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING_R1=0x00000001,
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING=0x00000001, /* R1 */
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R2=0x00000002,
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R3=0x00000004,
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R4=0x00000008,
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING=0x0000000E, /* R2+R3+R4 */
    DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R5=0x00000010,
    DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R6=0x00000020,
    DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE=0x00000030, /* R5+R6 */
    DATA_COLLECTION_FEATURE_SERVER_ALL=0x0000003F, /* All API server features */
} data_collection_feature_flags_e;

/***** Interface structures *****/

/** Library configuration
 *
 * Used when calling data_collection_initialise() to configure the run-time properties of the Data Collection Service Provider.
 * An AF can use this to tailor the library's operation to suit the AF.
 */
typedef struct data_collection_configuration_s {
    const char* configuration_section;
    int         disable_features;    /* ORed data_collection_feature_flags_e values of features to disable*/
    uint64_t    event_exposure_supported_features;       /* supported features bitmask for TS 29.517 event subscription */
    const char* af_name;
    const char* af_version;
    const char* af_type;
    const data_collection_data_report_handler_t* const *data_report_handlers; /* NULL terminated array of data report types implemented by the AF */
    data_collection_event_generation_cb event_generation_callback;      /* called to turn reports into events to expose via reference points R5 & R6 */
} data_collection_configuration_t;

/***** Library function API *****/

/** Get the library version string, e.g. "libspdc-1.2.3-alpha1" */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_version_full_string();
/** Get the library major version number */
DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_major();
/** Get the library minor version number */
DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_minor();
/** Get the library micro version number */
DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_micro();
/** Get the library version number as a string, e.g. "1.2.3-alpha1" */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_version_string();

/** Initialise the Data Collection Service Provider library */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_initialise(const data_collection_configuration_t* const configuration);

/** Set the NF Services in the AF's NF Instance */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_set_nf_services(void);

/** Stop using the Data Collection Service Provider library
 *
 * This will shutdown all network API endpoints the library opened, cease all sessions and tidy up resources managed by the library.
 */
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

#endif /* DATA_COLLECTION_LIFE_CYCLE_H */
