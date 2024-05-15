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

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_PROVISIONING_H */
