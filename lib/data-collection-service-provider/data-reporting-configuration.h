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

typedef struct data_sampling_rule_lnode_s {
    ogs_lnode_t node;
    data_collection_data_sampling_rule_t *rule;
} data_sampling_rule_lnode_t;

typedef struct data_reporting_rule_lnode_s {
    ogs_lnode_t node;
    data_collection_data_reporting_rule_t *rule;
} data_reporting_rule_lnode_t;

typedef struct data_reporting_condition_lnode_s {
    ogs_lnode_t node;
    data_collection_data_reporting_condition_t *condition;
} data_reporting_condition_lnode_t;

typedef struct data_access_profile_lnode_s {
    ogs_lnode_t node;
    data_collection_data_access_profile_t *access_profile;
} data_access_profile_lnode_t;

typedef struct data_collection_reporting_configuration_s {
    char *id;
    data_collection_client_type_e client_type;
    char *auth_url;
    ogs_list_t *sampling_rules; /* data_sampling_rule_lnode_t */
    ogs_list_t *reporting_rules; /* data_reporting_rule_lnode_t */
    ogs_list_t *reporting_conditions; /* data_reporting_condition_lnode_t */
    ogs_list_t *access_profiles; /* data_access_profile_lnode_t */
    data_collection_reporting_provisioning_session_t *parent;
} data_collection_reporting_configuration_t;

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_CONFIGURATION_H */
