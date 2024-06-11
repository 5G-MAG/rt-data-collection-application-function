/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORTING_CONFIGURATION_H
#define DATA_REPORTING_CONFIGURATION_H

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_data_sampling_rule_s data_collection_data_sampling_rule_t;
typedef struct data_collection_data_reporting_rule_s data_collection_data_reporting_rule_t;
typedef struct data_collection_data_reporting_condition_s data_collection_data_reporting_condition_t;
typedef struct data_collection_data_access_profile_s data_collection_data_access_profile_t;

void reporting_configuration_detach_session(data_collection_reporting_configuration_t *configuration);
OpenAPI_list_t *data_collection_get_user_ids_from_reporting_provisioning_session_configurations(char *event_type, char *external_application_id, OpenAPI_list_t *user_identifiers);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_CONFIGURATION_H */
