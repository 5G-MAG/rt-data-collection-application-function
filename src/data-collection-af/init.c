/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2022-2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "context.h"
#include "sbi-path.h"
#include "dcaf-sm.h"
#include "init.h"
#include "utilities.h"
#include "data-collection.h"

static ogs_thread_t *thread;

static void dcaf_main(void *data);
static int dcaf_set_time(void);

static int initialized = 0;

int dcaf_initialize()
{
    int rv;
    const char* const configuration_section = "dataCollection";
    int data_collection_features_disabled = 0;
    uint64_t event_exposure_supported_features = 0;

    rv = dcaf_set_time();
    if (rv != 0) {
        ogs_debug("dcaf_set_time() failed");
        return OGS_ERROR;
    }

    ogs_sbi_context_init(OpenAPI_nf_type_AF);

    dcaf_context_init();

    rv = dcaf_context_parse_config();
    if (rv != OGS_OK) {
        ogs_debug("dcaf_context_parse_config() failed");
        return rv;
    }

    if (dcaf_self()->config.open5gsIntegration_flag) {
        rv = ogs_sbi_context_parse_config("dataCollection", "nrf", "scp");
        if (rv != OGS_OK) {
            ogs_debug("ogs_sbi_context_parse_config() failed");
            return rv;
        }
    }

    data_collection_features_disabled = DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING;
    event_exposure_supported_features = DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION;

     const data_collection_configuration_t conf = {
         configuration_section,
         data_collection_features_disabled,
	 event_exposure_supported_features
    };

    const data_collection_configuration_t* const configuration = &conf;

    data_collection_initialise(configuration);


    rv = ogs_log_config_domain(ogs_app()->logger.domain, ogs_app()->logger.level);
    if (rv != OGS_OK) {
        ogs_debug("ogs_log_config_domain failed");
        return rv;
    }

    rv = dcaf_sbi_open();
    if (rv != 0) {
        ogs_debug("dcaf_sbi_open() failed");
        return OGS_ERROR;
    }

    thread = ogs_thread_create(dcaf_main, NULL);
    if (!thread) {
        ogs_debug("ogs_thread_create() failed");
        return OGS_ERROR;
    }

    initialized = 1;

    return OGS_OK;
}

static ogs_timer_t *t_termination_holding = NULL;

static void event_termination(void)
{
    ogs_sbi_nf_instance_t *nf_instance = NULL;

    ogs_list_for_each(&ogs_sbi_self()->nf_instance_list, nf_instance)
        ogs_sbi_nf_fsm_fini(nf_instance);

    t_termination_holding = ogs_timer_add(ogs_app()->timer_mgr, NULL, NULL);
    ogs_assert(t_termination_holding);
#define TERMINATION_HOLDING_TIME ogs_time_from_msec(300)
    ogs_timer_start(t_termination_holding, TERMINATION_HOLDING_TIME);

    ogs_queue_term(ogs_app()->queue);
    ogs_pollset_notify(ogs_app()->pollset);
}

void dcaf_terminate(void)
{
    if (!initialized) return;

    event_termination();
    ogs_thread_destroy(thread);
    ogs_timer_delete(t_termination_holding);

    dcaf_sbi_close();

    dcaf_context_final();
    ogs_sbi_context_final();

    dcaf_free_agent_name();
}

static void dcaf_main(void *data)
{
    ogs_fsm_t dcaf_sm;
    int rv;

    ogs_fsm_init(&dcaf_sm, dcaf_state_initial, dcaf_state_final, 0);
    
    for ( ;; ) {
        ogs_pollset_poll(ogs_app()->pollset,
                ogs_timer_mgr_next(ogs_app()->timer_mgr));

        ogs_timer_mgr_expire(ogs_app()->timer_mgr);

        for ( ;; ) {
            dcaf_event_t *e = NULL;

            rv = ogs_queue_trypop(ogs_app()->queue, (void**)&e);
            ogs_assert(rv != OGS_ERROR);

            if (rv == OGS_DONE)
                goto done;

            if (rv == OGS_RETRY)
                break;

            ogs_assert(e);

            ogs_fsm_dispatch(&dcaf_sm, e);

            ogs_event_free(e);
        }
    }
done:
    
    ogs_fsm_fini(&dcaf_sm, 0);
  
}

static int dcaf_set_time(void)
{
    if(ogs_env_set("TZ", "GMT") != OGS_OK)
    {
        ogs_error("Failed to set TZ to GMT");
        return OGS_ERROR;
    }

    if(ogs_env_set("LC_TIME", "C") != OGS_OK)
    {
        ogs_error("Failed to set LC_TIME to C");
        return OGS_ERROR;
    }
    return OGS_OK;

}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
