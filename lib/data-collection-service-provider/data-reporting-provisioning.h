/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation
Author: David Waring <david.waring2@bbc.co.uk>

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
/** Get the event type string from the provisioning session */
const char *_reporting_provisioning_session_get_af_event_type(const data_collection_reporting_provisioning_session_t *session);

/** Get the external application id from the provisioning session */
const char *_reporting_provisioning_session_get_external_application_id(const data_collection_reporting_provisioning_session_t *session);

/** Get the map of configuration id => data_collection_reporting_configuration_t for the provisioning session */
const ogs_hash_t *_reporting_provisioning_session_get_configurations(const data_collection_reporting_provisioning_session_t *session);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_PROVISIONING_H */
