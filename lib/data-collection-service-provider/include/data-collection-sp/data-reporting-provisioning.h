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

/** \addtogroup dcsp
 * @{
 */


#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/***** Opaque Types *****/

/** \cond FORWARD_DECL
 * \struct data_collection_reporting_provisioning_session_s lib/data-collection-service-provider/data-reporting-provisioning.c
 * Data Collection Library internal structure.
 * \see lib/data-collection-service-provider/data-reporting-provisioning.c
 */

typedef struct data_collection_reporting_provisioning_session_s data_collection_reporting_provisioning_session_t;
/** \endcond */

/***** Forward declarations *****/
/** \cond FORWARD_DECL
 * \struct data_collection_reporting_configuration_s lib/data-collection-service-provider/data-reporting-configuration.c
 * Data Collection Library internal structure.
 * \see lib/data-collection-service-provider/data-reporting-configuration.c
 */

typedef struct data_collection_reporting_configuration_s data_collection_reporting_configuration_t;
/** \endcond */

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/**** Data Reporting Provisioning ****/
/** Create a new data reporting provisioning session 
 * @param asp_id ID of the Application Provider.
 * @param external_application_id External Application Id associated with the Provisioning Session.
 * @param internal_application_id Internal Application Id associated with the Provisioning Session.
 * @param event_type Internal Event type/id of the Provisioning Session.
 * @return a new provisioning session object.
 */

DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
    data_collection_reporting_provisioning_session_create(const char *asp_id, const char *external_application_id,
                                                          const char *internal_application_id, const char *event_type);

/** Create a new data reporting provisioning session from JSON tree 
 *
 * Parses the JSON into a new Provisioning Session object and returns the object. If a parsing error occurs then `NULL` is
 * returned and the `char*` pointers referenced by @a error_reason and @a error_parameter will be set to either a new null
 * terminated string or `NULL` to indicate where the error occurred. It is up to the caller to use `ogs_free()` to free the three
 * error strings if they have been set due to a parsing error.
 *
 * @param json The JSON tree to parse.
 * @param[out] error_reason Filled in on error with a human readable error string.
 * @param[out] error_parameter Filled in on error with the parameter name of the parameter that caused the parsing error.
 * @return A new Provisioning Session object filled in from the JSON or `NULL` if there was a parsing error.
 */


DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
    data_collection_reporting_provisioning_session_parse_from_json(cJSON *json, char **error_reason /*[output, transfer]*/,
                                                                   char **error_parameter /*[output, transfer]*/);

/** Destroy a data reporting provisioning session
 *
 * @param session The Provisioning session to be deleted.
 */

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_provisioning_session_destroy(
            data_collection_reporting_provisioning_session_t *session);

/** Finding a Data Reporting Provisioning Session by Id 
 *
 * @param session_id The session id of the Provisioning Session.
 *
 * @return Provisioning Session.
 */

DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t *
    data_collection_reporting_provisioning_session_find(const char *session_id);

/** Get the Data Reporting Provisioning Session Id
 *
 * @param session The Provisioning Session for which the session id  needs to be obtained.
 *
 * @return Session id of the Provisioning Session.
 */

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_id(
            const data_collection_reporting_provisioning_session_t *session);

/** Get the Data Reporting Provisioning Session last modified date-time 
 *
 * @param session The Provisioning Session for which the last modified attribute needs to be obtained.
 *
 * @return Session's last modified time.
 */

DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_reporting_provisioning_session_last_modified(
            const data_collection_reporting_provisioning_session_t *session);

/** Get the Data Reporting Provisioning Session entity instance tag
 *
 * This tag will change when the Provisioning Session is changed.
 *
 * @param session The session to return the instance id tag for.
 *
 * @return An entity instance id tag suitable for an HTTP "ETag" header.
 */


DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_etag(
            const data_collection_reporting_provisioning_session_t *session);

/** Get the TS 26.532 DataReportingProvisioningSession JSON 
 *
 * @param session The Provisioning Session for which the TS 26.532 DataReportingProvisioningSession needs to be obtained.
 *
 * @return Returns JSON serialisation of the DataReportingProvisioningSession.
 *
 */


DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_provisioning_session_json(
            const data_collection_reporting_provisioning_session_t *session);

/** List the active Data Reporting Provisioning Sessions
 *
 * @return Set of provisioning sessions in the context of the library.
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_provisioning_session_list();

/** Get the external application id associated with the provisioning session 
 *
 * @param session The Provisioning Session for which the external application id needs to be obtained.
 *
 * @return Returns the external application id of the provisioning session.
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_external_application_id(
        const data_collection_reporting_provisioning_session_t *session);

/** Add a reporting configuration to the session 
 *
 * @param session The Provisioning Session to add reporting configuration.
 * @param configuration The reporting configuration to be added.
 *
 * @return Returns OGS_OK if the configuration is removed successfully, else returns OGS_ERROR.
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_add_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration);

/** Remove a reporting configuration to the session
 *
 * @param session The Provisioning Session to which the reporting configuration to be removed is associated with.
 * @param configuration The reporting configuration to be removed.
 *
 * @return Returns OGS_OK if the configuration is removed successfully, else returns OGS_ERROR.
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_remove_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration);

/** Replace a reporting configuration in a session
 *
 * @param session The Provisioning Session to which the reporting configuration to be replaced is associated with.
 * @param configuration The reporting configuration to be replaced.
 *
 * @return Returns OGS_OK if the configuration is replaced successfully, else returns OGS_ERROR.
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_reporting_provisioning_session_replace_configuration(
                                                            data_collection_reporting_provisioning_session_t *session,
                                                            data_collection_reporting_configuration_t *configuration);

/** Find a reporting configuration in the session by its id 
 *
 * @param session The Provisioning Session to look for the reporting configuration.
 * @param configuration_id The identifier of the reporting configuration.
 *
 * @return Returns reporting configuration. Returns NULL if session or configuration is NULL. 
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_provisioning_session_get_configuration_by_id(data_collection_reporting_provisioning_session_t *session,
                                                                       const char *configuration_id);


/** Get the AfEvent type for a provisioning session 
 *
 * @param session The Provisioning Session for which the handler needs to be obtained.
 *
 * @return The event type/id of the provisioning session.
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_get_af_event_type(
                const data_collection_reporting_provisioning_session_t *session);

/** Get the external app id for a provisioning session 
 *
 * @param session The Provisioning Session for which the handler needs to be obtained.
 *
 * @return The external application id of the session.
 *
 */


DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_get_external_application_id(
                const data_collection_reporting_provisioning_session_t *session);

/** Get the Data Report handler for a provisioning session 
 *
 * @param session The Provisioning Session for which the handler needs to be obtained.
 *
 * @return The Data Report handler associated with the session.
 *
 */

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_data_report_handler_t *
data_collection_reporting_provisioning_session_get_data_report_handler(const data_collection_reporting_provisioning_session_t *session);


/** Get the configurations map for a provisioning session 
 *
 * @param session The Provisioning Session to get the configurations map from.
 *
 * @return The set of configurations associated with the Provisioning Session.
 *
 */


DATA_COLLECTION_SVC_PRODUCER_API const ogs_hash_t *data_collection_reporting_provisioning_session_get_configurations(
                const data_collection_reporting_provisioning_session_t *session);

/** @} */

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_REPORTING_PROVISIONING_H */
