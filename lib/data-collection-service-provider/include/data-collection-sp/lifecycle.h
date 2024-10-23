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

/** \addtogroup dcsp 
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/** \enum data_collection_feature_flags_e
 * \brief Library features flags
 * \headerfile lifecycle.h <data-collection-sp/data-collection.h>
 *
 * Features can be disabled in the data_collection_configuration_t
 */
typedef enum {
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING_R1=0x00000001,/**< HTTP Provisioning API at R1 */
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING=0x00000001,   /**< HTTP Provisioning API on all interfaces (R1) */
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R2=0x00000002,             /**< HTTP Reporting API at R2 */
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R3=0x00000004,             /**< HTTP Reporting API at R3 */
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R4=0x00000008,             /**< HTTP Reporting API at R4 */
    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING=0x0000000E,                /**< HTTP Reporting API on all interfaces (R2+R3+R4) */
    DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R5=0x00000010,             /**< HTTP Event Exposure API at R5 */
    DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R6=0x00000020,             /**< HTTP Event Exposure API at R6 */
    DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE=0x00000030,                /**< HTTP Event Exposure API, all interfaces (R5+R6) */
    DATA_COLLECTION_FEATURE_SERVER_ALL=0x0000003F,                           /**< All HTTP API interfaces */
} data_collection_feature_flags_e;

/***** Interface structures *****/

/** \cond FORWARD_DECL
 * \struct ogs_event_s ogs-proto.h
 * Open5GS event structure.
 * \see ogs-proto.h
 */
typedef struct ogs_event_s ogs_event_t;
/** \endcond */


/** Library configuration
 *
 * Used when calling data_collection_initialise() to configure the run-time properties of the Data Collection Service Provider.
 * An AF can use this to tailor the library's operation to suit the AF.
 */
typedef struct data_collection_configuration_s {
    const char* configuration_section;             /**< The Open5GS configuration file section for data collection settings */
    int         disable_features;                  /**< ORed data_collection_feature_flags_e values of features to disable */
    uint64_t    event_exposure_supported_features; /**< supported features bitmask for TS 29.517 event subscription */
    const char* af_name;                           /**< The name of the AF for reporting in the HTTP Server header and NRF registration */
    const char* af_version;                        /**< The version number of the AF for reporting in the HTTP Server header and NRF registration */
    const char* af_type;                           /**< The AF type for NRF registration */
    const data_collection_data_report_handler_t* const *data_report_handlers; /**< NULL terminated array of data report types implemented by the AF */
    data_collection_event_generation_cb event_generation_callback; /**< called to turn reports into events to expose via reference points R5 & R6 */
} data_collection_configuration_t;

/***** Library function API *****/

/** Get the library version string
 * \headerfile data-collection-sp/lifecycle.h <data-collection-sp/data-collection.h>
 * Returns the library name and version string, e.g. "libspdc-1.2.3-alpha1"
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_version_full_string();

/** Get the library major version number
 * Returns the major version number, as an int, from the library version, e.g. 1 from "1.2.3-alpha1".
 */
DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_major();

/** Get the library minor version number
 * Returns the minor version number, as an int, from the library version, e.g. 2 from "1.2.3-alpha1".
 */
DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_minor();

/** Get the library micro version number
 * Returns the micro version number, as an int, from the library version, e.g. 3 from "1.2.3-alpha1".
 */
DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_micro();

/** Get the library version number as a string
 * Returns the library version, e.g. "1.2.3-alpha1"
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_version_string();

/** Initialise the Data Collection Service Provider library
 * The AF should call this function to initialise the Data Collection Service Provider library.
 *
 * @param configuration The configuration the library should use to initialise itself.
 *
 * @return OGS_OK if the library initialised correctly, or OGS_ERROR if there was a problem initialising the library.
 */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_initialise(const data_collection_configuration_t* const configuration);

/** Set the NF Services in the AF's NF Instance
 * The AF should call this function just before it is ready to register with the NRF to have the library add any enabled HTTP API
 * interfaces to the NFInstance description.
 *
 * @return OGS_OK if the library added the NF services and OGS_ERROR if it failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_set_nf_services(void);

/** Stop using the Data Collection Service Provider library
 *
 * This will shutdown all network API endpoints the library opened, cease all sessions and tidy up resources managed by the library.
 * This should be called by the AF after unregistering with the NRF.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_finalise(void);

/**
 * Process an ogs_event_t
 *
 * Checks the ogs_event_t to see if it is an event associated with this service producer and services it if it is.
 *
 * @param event The event to check.
 *
 * @return `true` if the service consumer has dealt with the event, no further processing should be done for this event. If the
 *         return value is `false` then the service consumer has not consumed the event and it should be processed by the
 *         Application Function as normal.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_process_event(ogs_event_t *event);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_LIFE_CYCLE_H */
