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

#ifndef DATA_COLLECTION_DATA_REPORTING_PROVISIONING_H
#define DATA_COLLECTION_DATA_REPORTING_PROVISIONING_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "ogs-core.h"
#include "ogs-sbi.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

typedef enum {
    DATA_COLLECTION_CLIENT_DIRECT = 1,
    DATA_COLLECTION_CLIENT_INDIRECT,
    DATA_COLLECTION_CLIENT_APPLICATION_SERVER
} data_collection_client_type_e;

/***** Opaque Types *****/

typedef struct dc_api_data_reporting_provisioning_configuration_s dc_api_data_reporting_provisioning_configuration_t;
typedef struct data_collection_reporting_provisioning_session_s data_collection_reporting_provisioning_session_t;
typedef struct data_collection_reporting_configuration_s data_collection_reporting_configuration_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

typedef struct data_collection_reporting_session_lnode_s {
    ogs_lnode_t node;
    data_collection_reporting_provisioning_session_t *provisioning_session;
} data_collection_reporting_session_lnode_t;

typedef struct data_collection_reporting_configuration_lnode_s {
    ogs_lnode_t node;
    data_collection_reporting_configuration_t *configuration;
} data_collection_reporting_configuration_lnode_t;

/***** Library function API *****/

/**** Data Reporting Provisioning ****/
/** Create a new data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
    data_collection_reporting_provisioning_session_create(/* TBD */);

/** Destroy a data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_provisioning_session_destroy(
        data_collection_reporting_provisioning_session_t *session);

/** Finding a Data Reporting Provisioning Session by Id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t *
    data_collection_reporting_provisioning_session_find(const char *session_id);

/** Get the Data Reporting Provisioning Session Id */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_id(
        const data_collection_reporting_provisioning_session_t *session);

/** Get the TS 26.532 DataReportingProvisioningSession JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_provisioning_session_json(
        const data_collection_reporting_provisioning_session_t *session);

/** List the active Data Reporting Provisioning Sessions */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_provisioning_session_list();

/**** Data Reporting Provisioning Configurations ****/
/** Create a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
    data_collection_reporting_configuration_create(data_collection_reporting_provisioning_session_t *session,
                                                                dc_api_data_reporting_provisioning_configuration_t *configuration);

/** Destroy a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_configuration_destroy(
        data_collection_reporting_configuration_t *configuration);

/** Find a Data Collection Reporting Provisioning Configuration by id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
    data_collection_reporting_configuration_find(data_collection_reporting_provisioning_session_t *session,
                                                              const char *configuration_id);

/** List the Configurations for a Data Collection Reporting Provisioning Session */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_configuration_list(
        data_collection_reporting_provisioning_session_t *session);

/** Get a Data Collection Reporting Provisioning Configuration as JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_configuration_json(
        const data_collection_reporting_configuration_t *configuration);

/** Get the Configuration Id for a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_id(
        const data_collection_reporting_configuration_t *configuration);

/** Serialise a Data Collection Reporting Provisioning Configuration for debugging purposes */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_serialise(
        const data_collection_reporting_configuration_t *configuration);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_DATA_REPORTING_PROVISIONING_H */