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
#include "sbi/openapi/external/cJSON.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/***** Opaque Types *****/

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
    data_collection_reporting_provisioning_session_parse_from_json(cJSON *json, char **error_reason /*[output, transfer]*/,
                                                                   char **error_parameter /*[output, transfer]*/);

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

/** Get the external application id associated with the provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_external_application_id(
        const data_collection_reporting_provisioning_session_t *session);

/** Add a reporting configuration to the session */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_add_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration);

/** Remove a reporting configuration to the session */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_remove_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration);

/** Replace a reporting configuration in a session */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_replace_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration);

/** Find a reporting configuration in the session by its id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_provisioning_session_get_configuration_by_id(data_collection_reporting_provisioning_session_t *session,
                                                                       const char *configuration_id);


/** Get the AfEvent type for a provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_get_af_event_type(
                const data_collection_reporting_provisioning_session_t *session);

/** Get the external app id for a provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_get_external_application_id(
                const data_collection_reporting_provisioning_session_t *session);

/** Get the Data Report handler for a provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_data_report_handler_t *
data_collection_reporting_provisioning_session_get_data_report_handler(const data_collection_reporting_provisioning_session_t *session);


/** Get the configurations map for a provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API const ogs_hash_t *data_collection_reporting_provisioning_session_get_configurations(
                const data_collection_reporting_provisioning_session_t *session);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_REPORTING_PROVISIONING_H */
