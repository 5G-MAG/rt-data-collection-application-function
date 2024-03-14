/*
 * License: 5G-MAG Public License (v1.0)
 * Author: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "ogs-core.h"

#include "context.h"
#include "data-reporting-provisioning.h"
#include "utilities.h"

#include "data-reporting-configuration.h"

#ifdef __cplusplus
extern "C" {
#endif

/******* Local prototypes ********/

/******* Private structures ********/

/******* Library API ********/

/** Create a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_create(data_collection_reporting_provisioning_session_t *session,
                                               dc_api_data_reporting_provisioning_configuration_t *configuration)
{
    data_collection_reporting_configuration_t *ret;
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];

    ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    ret->id = data_collection_strdup(id);
    
    if (session) {
        ret->parent = session;
        data_collection_reporting_provisioning_session_add_configuration(session, ret);
    }

    return ret;
}

/** Destroy a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API void
data_collection_reporting_configuration_destroy(data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return;

    if (configuration->parent) {
        data_collection_reporting_provisioning_session_t *session = configuration->parent;
        data_collection_reporting_provisioning_session_remove_configuration(session, configuration);
    }

    if (configuration->id) {
        ogs_free(configuration->id);
        configuration->id = NULL;
    }

    if (configuration->auth_url) {
        ogs_free(configuration->auth_url);
        configuration->auth_url = NULL;
    }

    if (configuration->sampling_rules) {
        ogs_lnode_t *node, *next;
        ogs_list_for_each_safe(configuration->sampling_rules, next, node) {
            data_sampling_rule_lnode_t *dsr_node = (data_sampling_rule_lnode_t*)node;
            data_collection_data_sampling_rule_free(dsr_node->rule);
            ogs_list_remove(configuration->sampling_rules, node);
            ogs_free(dsr_node);
        }
        configuration->sampling_rules = NULL;
    }

    if (configuration->reporting_rules) {
        ogs_lnode_t *node, *next;
        ogs_list_for_each_safe(configuration->reporting_rules, next, node) {
            data_reporting_rule_lnode_t *drr_node = (data_reporting_rule_lnode_t*)node;
            data_collection_data_reporting_rule_free(drr_node->rule);
            ogs_list_remove(configuration->reporting_rules, node);
            ogs_free(drr_node);
        }
        configuration->reporting_rules = NULL;
    }

    if (configuration->reporting_conditions) {
        ogs_lnode_t *node, *next;
        ogs_list_for_each_safe(configuration->reporting_conditions, next, node) {
            data_reporting_condition_lnode_t *drc_node = (data_reporting_condition_lnode_t*)node;
            data_collection_data_reporting_condition_free(drc_node->condition);
            ogs_list_remove(configuration->reporting_conditions, node);
            ogs_free(drc_node);
        }
        configuration->reporting_conditions = NULL;
    }

    if (configuration->access_profiles) {
        ogs_lnode_t *node, *next;
        ogs_list_for_each_safe(configuration->access_profiles, next, node) {
            data_access_profile_lnode_t *dap_node = (data_access_profile_lnode_t*)node;
            data_collection_data_access_profile_free(dap_node->access_profile);
            ogs_list_remove(configuration->access_profiles, node);
            ogs_free(dap_node);
        }
        configuration->access_profiles = NULL;
    }

    ogs_free(configuration);
}

/** Set the auth URL */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_set_auth_url(data_collection_reporting_configuration_t *config, const char *auth_url)
{
    if (!config) return OGS_ERROR;

    if (config->auth_url) ogs_free(config->auth_url);
    config->auth_url = data_collection_strdup(auth_url);

    return OGS_OK;
}

/** Add a sampling rule */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_add_sampling_rule(data_collection_reporting_configuration_t *config,
                                                          data_collection_data_sampling_rule_t *rule)
{
    if (!config || !rule) return OGS_ERROR;

    data_sampling_rule_lnode_t *node = ogs_calloc(1, sizeof(*node));

    ogs_assert(node);

    node->rule = rule;

    ogs_list_add(config->sampling_rules, node);

    return OGS_OK;
}

/** Remove a sampling rule */
DATA_COLLECTION_SVC_PRODUCER_API int
data_collection_reporting_configuration_remove_sampling_rule(data_collection_reporting_configuration_t *config,
                                                             data_collection_data_sampling_rule_t *rule)
{
    data_sampling_rule_lnode_t *node = NULL;
    if (!config || !rule) return OGS_ERROR;
    
    ogs_list_for_each(config->sampling_rules, node) {
        if (node->rule == rule) {
            ogs_list_remove(config->sampling_rules, (ogs_lnode_t*)node);
            break;
        }
    }

    return OGS_OK;
}

/** Get a Data Collection Reporting Provisioning Configuration as JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *
data_collection_reporting_configuration_json(const data_collection_reporting_configuration_t *configuration)
{
    /* TODO: implement this */
    return NULL;
}

/** Get the Configuration Id for a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API const char *
data_collection_reporting_configuration_id(const data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return NULL;
    return configuration->id;
}

/** Serialise a Data Collection Reporting Provisioning Configuration for debugging purposes */
DATA_COLLECTION_SVC_PRODUCER_API const char *
data_collection_reporting_configuration_serialise(const data_collection_reporting_configuration_t *configuration)
{
    /* TODO: implement this */
    return NULL;
}

/******* Local private functions ********/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
