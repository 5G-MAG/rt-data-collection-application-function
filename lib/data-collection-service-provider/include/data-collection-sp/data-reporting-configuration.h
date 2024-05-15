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

#ifndef DATA_COLLECTION_DATA_REPORTING_CONFIGURATION_H
#define DATA_COLLECTION_DATA_REPORTING_CONFIGURATION_H

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
typedef struct data_collection_reporting_configuration_s data_collection_reporting_configuration_t;

/***** Forward declarations *****/
typedef struct data_collection_reporting_provisioning_session_s data_collection_reporting_provisioning_session_t;
typedef struct data_collection_data_sampling_rule_s data_collection_data_sampling_rule_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/**** Data Reporting Provisioning Configurations ****/
/** Create a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_create(data_collection_reporting_provisioning_session_t *session,
                                               data_collection_client_type_e client_type,
                                               char *authorization_url,
                                               ogs_list_t *data_sampling_rules,
                                               ogs_list_t *data_reporting_conditions,
                                               ogs_list_t *data_reporting_rules,
                                               ogs_list_t *data_access_profiles);

/** Parse a Data Collection Reporting Provisioning Configuration from request JSON */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_parse_from_json(cJSON *json, const data_collection_reporting_configuration_t *base, const char **error_return);

/** Destroy a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API void
data_collection_reporting_configuration_destroy(data_collection_reporting_configuration_t *configuration);

/** Set the Data Collection Reporting Provisioning Session that a Data Collection Reporting Provisioning Configuration belongs to */
DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_reporting_configuration_set_session(data_collection_reporting_configuration_t *configuration,
                                                    data_collection_reporting_provisioning_session_t *session);

/** Get the Data Collection Reporting Provisioning Session that a Data Collection Reporting Provisioning Configuration belongs to */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t *
data_collection_reporting_configuration_get_session(data_collection_reporting_configuration_t *configuration);

/** Replace a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_reporting_configuration_replace(data_collection_reporting_configuration_t *old_configuration,
                                                data_collection_reporting_configuration_t *new_configuration);

/** Update a Data Collection Reporting Provisioning Configuration with new request parameters */
DATA_COLLECTION_SVC_PRODUCER_API bool
data_collection_reporting_configuration_update(data_collection_reporting_configuration_t *old_configuration,
                                               data_collection_reporting_configuration_t *new_configuration);

/** Find a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_find(data_collection_reporting_provisioning_session_t *session, const char *configuration_id);

/** Set the auth URL */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_set_auth_url(data_collection_reporting_configuration_t *config, const char *auth_url);

/** Add a sampling rule */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_add_sampling_rule(data_collection_reporting_configuration_t *config,
                                                          data_collection_data_sampling_rule_t *rule);

/** Remove a sampling rule */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_remove_sampling_rule(data_collection_reporting_configuration_t *config,
                                                             const data_collection_data_sampling_rule_t *rule);

/** Get a Data Collection Reporting Provisioning Configuration as JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_configuration_json(
        const data_collection_reporting_configuration_t *configuration);

/** Get the Configuration Id for a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_id(
        const data_collection_reporting_configuration_t *configuration);

/** Get the last update time for the Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_reporting_configuration_last_modified(
	const data_collection_reporting_configuration_t *configuration);

/** Get the Entity Tag for the Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_etag(
        const data_collection_reporting_configuration_t *configuration);

/** Serialise a Data Collection Reporting Provisioning Configuration for debugging purposes */
DATA_COLLECTION_SVC_PRODUCER_API char *data_collection_reporting_configuration_serialise(
        const data_collection_reporting_configuration_t *configuration);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_DATA_REPORTING_CONFIGURATION_H */
