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
#include "sbi/openapi/external/cJSON.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/***** Opaque Types *****/

typedef struct data_collection_reporting_configuration_s data_collection_reporting_configuration_t;

/***** Forward declarations *****/
typedef struct data_collection_reporting_provisioning_session_s data_collection_reporting_provisioning_session_t;
typedef struct data_collection_model_data_reporting_configuration_s data_collection_model_data_reporting_configuration_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/**** Data Reporting Configuration ****/

/** Create a new, empty configuration
 *
 * @return a new reporting configuration object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *data_collection_reporting_configuration_create();

/** Create a new reporting configuration object from a TS 26.532 DataReportingConfiguration object
 *
 * This will take ownership of the @a configuration object.
 *
 * @param configuration A TS 26.532 DataReportingConfiguration object to convert to a reporting configuration object.
 * @return a new reporting configuration object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *data_collection_reporting_configuration_create_from_model(data_collection_model_data_reporting_configuration_t *configuration);

/** Get the TS 26.532 DataReportingConfiguration object represented by this configuration
 *
 * @param config The configuration to derive the TS 26.532 DataReportingConfiguration object from.
 * @return A read-only TS 26.532 DataReportingConfiguration object.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_reporting_configuration_t *data_collection_reporting_configuration_model(const data_collection_reporting_configuration_t *config);

/** Create a new reporting configuration object from TS 26.532 DataReportingConfiguration JSON request representation
 *
 * Parses the JSON into a new reporting configuration object and returns the object. If a parsing error occurs then `NULL` is
 * returned and the `char*` pointers referenced by @a err_return, @a err_class and @a err_param will be set to either a new nul
 * terminated string or `NULL` to indicate where the error occurred. It is up to the caller to use `ogs_free()` to free the three
 * error strings if they have been set due to a parsing error.
 *
 * @param json The JSON tree to parse.
 * @param base An existing reporting configuration object to copy read-only fields from or `NULL`.
 * @param err_return Filled in on error with a human readable error string.
 * @param err_class Filled in on error with the classname of the class that generated the parsing error.
 * @param err_param Filled in on error with the parameter name of the parameter that caused the parsing error.
 * @return A new reporting configuration object filled in from the JSON or `NULL` if there was a parsing error.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *data_collection_reporting_configuration_parse_from_json(cJSON *json, data_collection_reporting_provisioning_session_t *parent_session, data_collection_reporting_configuration_t *base, char **err_return, char **err_class, char **err_param, char **err_code);

/** Replace an existing configuration with a new configuration
 *
 * The new configuration will be attached to the same data reporting provisioning session as the original @a old configuration.
 * @param old The configuration to replace.
 * @param replace_with The new configuration to use instead.
 * @return `true` if the replacement was successful or `false` if there was an error.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_reporting_configuration_update(data_collection_reporting_configuration_t *old, data_collection_reporting_configuration_t *replace_with);

/** Destroy a configuration
 *
 * This will remove the configuration from its parent data reporting provisioning session and free the configuration memory.
 *
 * @param configuration The configuration to destroy.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_configuration_destroy(data_collection_reporting_configuration_t*);

/** Set the parent data reporting provisioning session for a configuration
 *
 * This will detatch the configuration from its existing parent, if different from the @a parent_session, and attach it to
 * @a parent_session. Use a @a parent_session of `NULL` to detatch the configuration from all data reporting provisioning sessions.
 * This may fail if the configuration has an id matching an existing configuration in @a parent_session.
 *
 * @param config The configuration to change the parent for.
 * @param parent_session The data reporting provisioning session to set as parent, use `NULL` to detatch the configuration.
 * @return `true` if the configuration is attached to the parent, `false` if there was already another configuration withthe same
 *         id already attached to @a parent_session.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_reporting_configuration_set_session(data_collection_reporting_configuration_t *config, data_collection_reporting_provisioning_session_t *parent_session);

/** Get the TS 26.532 DataReportingConfiguration JSON representation response for this configuration
 *
 * It is the callers responsibility to call `cJSON_Delete()` on the returned object.
 *
 * @param config The configuration to convert to a JSON response.
 * @return The cJSON tree representing a TS 26.532 DataReportingConfiguration response object.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_configuration_json(data_collection_reporting_configuration_t *config);

/** Get reporting configuration id
 * @param config The configuration to return the id for.
 * @return The reporting configuration ID for this configuration.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_id(data_collection_reporting_configuration_t *config);

/** Get the date-time timestamp for the last modification of this configuration
 * @return The timestamp when this object was last modified.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_reporting_configuration_last_modified(data_collection_reporting_configuration_t *);

/** Get the instance id for the configuration
 *
 * This tag will change when the configuration is changed.
 *
 * @return An entity instance id tag suitable for an HTTP "ETag" header.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_etag(data_collection_reporting_configuration_t *);

/*** Get aggregation functions from the provisioned configurations***/
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_provisioning_configurations_aggregations_functions_get(const char *external_application_id, const char *event_type, ogs_list_t *context_ids, ogs_list_t *aggregation_functions);


#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_REPORTING_CONFIGURATION_H */
