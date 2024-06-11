/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORTING_PROVISIONING_H
#define DATA_REPORTING_PROVISIONING_H

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/******** Internal library functions ********/

/** Add a reporting configuration to the session */
int data_collection_reporting_provisioning_session_add_configuration(data_collection_reporting_provisioning_session_t *session,
                                                                     data_collection_reporting_configuration_t *configuration);

/** Remove a reporting configuration to the session */
int data_collection_reporting_provisioning_session_remove_configuration(data_collection_reporting_provisioning_session_t *session,
                                                                        data_collection_reporting_configuration_t *configuration);

/** Replace a reporting configuration in a session */
int data_collection_reporting_provisioning_session_replace_configuration(data_collection_reporting_provisioning_session_t *session,
                                                                         data_collection_reporting_configuration_t *configuration);

/** Get a reporting configuration by its id from the session */
data_collection_reporting_configuration_t *
data_collection_reporting_provisioning_session_get_configuration_by_id(data_collection_reporting_provisioning_session_t *session,
                                                                       const char *configuration_id);

char *data_collection_reporting_provisioning_session_get_af_event_type(data_collection_reporting_provisioning_session_t *session);
char *data_collection_reporting_provisioning_session_get_external_application_id(data_collection_reporting_provisioning_session_t *session);
ogs_hash_t *data_collection_reporting_provisioning_session_get_configurations(data_collection_reporting_provisioning_session_t *session);
//OpenAPI_list_t *data_collection_get_user_ids_from_reporting_provisioning_session(char *event_type, char *external_application_id, OpenAPI_list_t *user_identifiers);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_PROVISIONING_H */
