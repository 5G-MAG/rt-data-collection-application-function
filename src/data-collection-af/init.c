/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "context.h"
#include "sbi-path.h"
#include "dcaf-sm.h"
#include "init.h"
#include "utilities.h"
#include "communication-record.h"
#include "event-notification.h"
#include "hash.h"
#include "data-collection-sp/data-collection.h"
#include "openapi/model/dcaf_api_data_report.h"

/* Local constants */
#define TERMINATION_HOLDING_TIME ogs_time_from_msec(300)

/* Local functions */
static void dcaf_main(void *data);
static int dcaf_set_time(void);
static void event_termination(void);

/* Event Exposure prototypes - should appear in event-exposure.h file when event exposure is added */
static ogs_list_t *event_exposure_generate_cb(data_collection_event_subscription_t *data_collection_event_subscription);

/* Example Data report type declaration - remove when proper report(s) implemented */
typedef struct foo_bar_report_s foo_bar_report_t;

/* File scope variables */
static ogs_thread_t *thread;
static int initialized = 0;
static ogs_timer_t *t_termination_holding = NULL;

/* Data Report Types defined by this AF */
static const data_collection_data_report_handler_t * const dc_config_report_types[] = {
    &communication_record_data_report_type,
    NULL
};

/* AF specific Data Collection library configuration */
static const data_collection_configuration_t dc_config = {
    "dataCollection",                /* configuration section */
    0,                               /* library feature disable flags */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION, /* event supported feature flags - when UE_comm implemented */
    dc_config_report_types,          /* data types to register */
    event_exposure_generate_cb       /* callback to generate events for event exposure */
};

/* Public functions */

int dcaf_initialize()
{
    int rv;
    const char *library_version;
    const char *library_version_string;
    unsigned int library_version_major;
    unsigned int library_version_minor;
    unsigned int library_version_micro;

    rv = dcaf_set_time();
    if (rv != 0) {
        ogs_debug("dcaf_set_time() failed");
        return OGS_ERROR;
    }

    ogs_sbi_context_init(OpenAPI_nf_type_AF);

    dcaf_context_init();

    rv = ogs_log_config_domain(ogs_app()->logger.domain, ogs_app()->logger.level);
    if (rv != OGS_OK) {
        ogs_debug("ogs_log_config_domain failed");
        return rv;
    }

    rv = dcaf_context_parse_config();
    if (rv != OGS_OK) {
        ogs_debug("dcaf_context_parse_config() failed");
        return rv;
    }

    rv = ogs_sbi_context_parse_config("dcaf", "nrf", "scp");
    if (rv != OGS_OK) {
        ogs_debug("ogs_sbi_context_parse_config() failed");
        return rv;
    }

    library_version = data_collection_version_full_string();
    library_version_string = data_collection_version_string();
    library_version_major = data_collection_version_major();
    library_version_minor = data_collection_version_minor();
    library_version_micro = data_collection_version_micro();

    ogs_info("Initialising library: \n\t Library Version: [%s] \n\t Version [%s] \n\t Major: [%d], \n\t Minor [%d] \n\t Micro: [%d]\n", library_version, library_version_string, library_version_major, library_version_minor, library_version_micro);

    rv = data_collection_initialise(&dc_config);
    if (rv != OGS_OK) {
        ogs_debug("data_collection_initialise() failed");
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

/* Private functions */

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

static void event_termination(void)
{
    ogs_sbi_nf_instance_t *nf_instance = NULL;

    ogs_list_for_each(&ogs_sbi_self()->nf_instance_list, nf_instance)
        ogs_sbi_nf_fsm_fini(nf_instance);

    t_termination_holding = ogs_timer_add(ogs_app()->timer_mgr, NULL, NULL);
    ogs_assert(t_termination_holding);
    ogs_timer_start(t_termination_holding, TERMINATION_HOLDING_TIME);

    ogs_queue_term(ogs_app()->queue);
    ogs_pollset_notify(ogs_app()->pollset);
}

/* Temporary event exposure callback until event-exposure.c is written */
static ogs_list_t *event_exposure_generate_cb(data_collection_event_subscription_t *data_collection_event_subscription)
{
    ogs_info("EVEX CB");
    ogs_list_t *data_reports;
    ogs_list_t *af_event_notifications = NULL;
    //data_collection_data_report_record_t *data_report;
    //void *report = NULL;

    data_reports = data_collection_reporting_report_find(NULL, data_collection_event_subscription, true);
    
    if(data_reports) {
        af_event_notifications = generate_af_event_notifications(data_reports, data_collection_event_subscription);
    }

    /*

    ogs_list_for_each(data_reports, data_report) {
        report = data_collection_reporting_data_report_get(data_report);
        if(report) {
	    generate_communication_collection_from_data_report(report);	

	}	
    	
    }
    */

    return af_event_notifications;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
