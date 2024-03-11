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

#ifdef __cplusplus
extern "C" {
#endif

/******* Local prototypes ********/

static int _add_session_to_list(void *data, const void *key, int klen, const void *value);
static int _add_config_to_list(void *data, const void *key, int klen, const void *value);
static int _free_ogs_hash_entry(void *free_fn, const void *key, int klen, const void *value);

/******* Private structures ********/

typedef struct data_collection_reporting_provisioning_session_s {
    char *session_id;
    ogs_hash_t *configurations;
} data_collection_reporting_provisioning_session_t;

/******* Library API ********/

/** Create a new data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t*
data_collection_reporting_provisioning_session_create(/* TBD */)
{
    /* TODO: implement this */
    return NULL;
}

/** Destroy a data reporting provisioning session */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_provisioning_session_destroy(
        data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return;

    ogs_hash_set(data_collection_self()->data_reporting_provisioning_sessions, session->session_id, OGS_HASH_KEY_STRING, NULL);

    if (session->session_id) {
        ogs_free(session->session_id);
        session->session_id = NULL;
    }

    if (session->configurations) {
        ogs_hash_do(_free_ogs_hash_entry, (void*)data_collection_reporting_configuration_destroy, session->configurations);
        ogs_hash_destroy(session->configurations);
        session->configurations = NULL;
    }

    ogs_free(session);
}

/** Finding a Data Reporting Provisioning Session by Id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_provisioning_session_t *
data_collection_reporting_provisioning_session_find(const char *session_id)
{
    return ogs_hash_get(data_collection_self()->data_reporting_provisioning_sessions, session_id, OGS_HASH_KEY_STRING);
}

/** Get the Data Reporting Provisioning Session Id */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_provisioning_session_id(
        const data_collection_reporting_provisioning_session_t *session)
{
    if (!session) return NULL;
    return session->session_id;
}

/** Get the TS 26.532 DataReportingProvisioningSession JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_provisioning_session_json(
        const data_collection_reporting_provisioning_session_t *session)
{
    /* TODO: implement this */
    return NULL;
}

/** List the active Data Reporting Provisioning Sessions */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_provisioning_session_list()
{
    ogs_list_t *ret;

    ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    ogs_hash_do(_add_session_to_list, ret, data_collection_self()->data_reporting_provisioning_sessions);

    return ret;
}

/**** Data Reporting Provisioning Configurations ****/

/** Create a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_create(data_collection_reporting_provisioning_session_t *session,
                                               dc_api_data_reporting_provisioning_configuration_t *configuration)
{
    /* TODO: implement this */
    return NULL;
}

/** Destroy a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_reporting_configuration_destroy(
        data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return;

    if (configuration->parent) {
        data_collection_reporting_provisioning_session_t *session = configuration->parent;
        ogs_hash_set(session->configurations, configuration->id, OGS_HASH_KEY_STRING, NULL);
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
            dc_api_data_sampling_rule_free(dsr_node->rule);
            ogs_list_remove(configuration->sampling_rules, node);
            ogs_free(dsr_node);
        }
        configuration->sampling_rules = NULL;
    }

    if (configuration->reporting_rules) {
        ogs_lnode_t *node, *next;
        ogs_list_for_each_safe(configuration->reporting_rules, next, node) {
            data_reporting_rule_lnode_t *drr_node = (data_reporting_rule_lnode_t*)node;
            dc_api_data_reporting_rule_free(drr_node->rule);
            ogs_list_remove(configuration->reporting_rules, node);
            ogs_free(drr_node);
        }
        configuration->reporting_rules = NULL;
    }

    if (configuration->reporting_conditions) {
        ogs_lnode_t *node, *next;
        ogs_list_for_each_safe(configuration->reporting_conditions, next, node) {
            data_reporting_condition_lnode_t *drc_node = (data_reporting_condition_lnode_t*)node;
            dc_api_data_reporting_condition_free(drc_node->condition);
            ogs_list_remove(configuration->reporting_conditions, node);
            ogs_free(drc_node);
        }
        configuration->reporting_conditions = NULL;
    }

    if (configuration->access_profiles) {
        ogs_lnode_t *node, *next;
        ogs_list_for_each_safe(configuration->access_profiles, next, node) {
            data_access_profile_lnode_t *dap_node = (data_access_profile_lnode_t*)node;
            dc_api_data_access_profile_free(dap_node->access_profile);
            ogs_list_remove(configuration->access_profiles, node);
            ogs_free(dap_node);
        }
        configuration->access_profiles = NULL;
    }

    ogs_free(configuration);
}

/** Find a Data Collection Reporting Provisioning Configuration by id */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_configuration_t *
data_collection_reporting_configuration_find(data_collection_reporting_provisioning_session_t *session,
                                             const char *configuration_id)
{
    if (!session) return NULL;
    return (data_collection_reporting_configuration_t*)ogs_hash_get(session->configurations, configuration_id, OGS_HASH_KEY_STRING);
}

/** List the Configurations for a Data Collection Reporting Provisioning Session */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_reporting_configuration_list(
        data_collection_reporting_provisioning_session_t *session)
{
    ogs_list_t *ret;

    ret = ogs_calloc(1, sizeof(*ret));
    ogs_assert(ret);

    if (session) {
        ogs_hash_do(_add_config_to_list, ret, session->configurations);
    }

    return ret;
}

/** Get a Data Collection Reporting Provisioning Configuration as JSON */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_reporting_configuration_json(
        const data_collection_reporting_configuration_t *configuration)
{
    /* TODO: implement this */
    return NULL;
}

/** Get the Configuration Id for a Data Collection Reporting Provisioning Configuration */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_id(
        const data_collection_reporting_configuration_t *configuration)
{
    if (!configuration) return NULL;
    return configuration->id;
}

/** Serialise a Data Collection Reporting Provisioning Configuration for debugging purposes */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_reporting_configuration_serialise(
        const data_collection_reporting_configuration_t *configuration)
{
    /* TODO: implement this */
    return NULL;
}

/******* Local private functions ********/

static int _add_session_to_list(void *data, const void *key, int klen, const void *value)
{
    ogs_list_t *list = (ogs_list_t*)data;
    data_collection_reporting_session_lnode_t *node;

    node = ogs_calloc(1, sizeof(*node));
    ogs_assert(node);

    node->provisioning_session = (data_collection_reporting_provisioning_session_t*)value;
    ogs_list_add(list, node);

    return 1;
}

static int _add_config_to_list(void *data, const void *key, int klen, const void *value)
{
    ogs_list_t *list = (ogs_list_t*)data;
    data_collection_reporting_configuration_lnode_t *node;

    node = ogs_calloc(1, sizeof(*node));
    ogs_assert(node);

    node->configuration = (data_collection_reporting_configuration_t*)value;
    ogs_list_add(list, node);

    return 1;
}

static int _free_ogs_hash_entry(void *free_fn, const void *key, int klen, const void *value)
{
    void (*value_free_fn)(void *) = (void(*)(void*))free_fn;
    value_free_fn((void*)value);

    return 1;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
