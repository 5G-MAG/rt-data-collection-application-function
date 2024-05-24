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

/***** Opaque Types *****/

typedef struct dc_api_data_reporting_provisioning_configuration_s dc_api_data_reporting_provisioning_configuration_t;
typedef struct data_collection_reporting_provisioning_session_s data_collection_reporting_provisioning_session_t;

/***** Forward declarations *****/
typedef struct data_collection_reporting_configuration_s data_collection_reporting_configuration_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/**** Data Reporting Provisioning ****/
/** Create a new data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
    data_collection_reporting_provisioning_session_create(const char *asp_id, const char *external_application_id,
                                                          const char *internal_application_id, const char *event_type);

/** Create a new data reporting provisioning session from JSON tree */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
    data_collection_reporting_provisioning_session_parse_from_json(cJSON *json, const char **error_reason,
                                                                   const char **error_parameter);

/** Destroy a data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_provisioning_session_destroy(
            data_collection_reporting_provisioning_session_t *session);

/** Finding a Data Reporting Provisioning Session by Id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t *
    data_collection_reporting_provisioning_session_find(const char *session_id);

/** Get the Data Reporting Provisioning Session Id */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_id(
            const data_collection_reporting_provisioning_session_t *session);

/** Get the Data Reporting Provisioning Session last modified date-time */
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_reporting_provisioning_session_last_modified(
            const data_collection_reporting_provisioning_session_t *session);

/** Get the Data Reporting Provisioning Session entity instance tag */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_etag(
            const data_collection_reporting_provisioning_session_t *session);

/** Get the TS 26.532 DataReportingProvisioningSession JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_provisioning_session_json(
            const data_collection_reporting_provisioning_session_t *session);

/** List the active Data Reporting Provisioning Sessions */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_provisioning_session_list();

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_REPORTING_PROVISIONING_H */
